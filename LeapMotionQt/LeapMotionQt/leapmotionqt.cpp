#include "leapmotionqt.h"
#include <QMainWindow>
#include <boost\filesystem.hpp>
#include "Leap.h"
#include <QProgressDialog>
#include <QDate>
Q_DECLARE_METATYPE(QCameraInfo)
Q_DECLARE_METATYPE(Leap::Frame)
LeapMotionQt::LeapMotionQt(QWidget *parent)
	: QMainWindow(parent)
{
	qRegisterMetaType<Leap::Frame>("Leap::Frame");
	ui.setupUi(this);
	ui.mLeapWidget->mParent = this;
	connect(ui.mLeapWidget, &LeapQtGl::callCameraUpdate, ui.mCamera, &CanonQtCamera::updateCamera);
	myRecorderThread = new QThread();
	mySynchronizeRecorder = new SynchronizeRecorder();
	mySynchronizeRecorder->moveToThread(myRecorderThread);
	connect(ui.mCamera, SIGNAL(callSynVideoStart(QImage)), mySynchronizeRecorder, SLOT(startVideoRecording(QImage)),Qt::QueuedConnection);
	connect(ui.mCamera, SIGNAL(sendOneVideoFrame(QImage)), mySynchronizeRecorder, SLOT(parseOneVideoFrame(QImage)), Qt::QueuedConnection);
	connect(ui.mCamera, SIGNAL(callSynVideoStop()), mySynchronizeRecorder, SLOT(stopRecording()), Qt::QueuedConnection);
	connect(ui.mLeapWidget, SIGNAL(sendOneMotionFrame(Leap::Frame)), mySynchronizeRecorder, SLOT(parseOneMotionFrame(Leap::Frame)), Qt::QueuedConnection);
	//connect(ui.mLeapWidget, SIGNAL(callSynVideoStop()), mySynchronizeRecorder, SLOT(stopRecording()), Qt::QueuedConnection);
	connect(mySynchronizeRecorder, SIGNAL(startExportingVideoSequence(QVector<QImage>*)), this, SLOT(exportingTheVideoSequence(QVector<QImage>*)), Qt::QueuedConnection);

	connect(myRecorderThread, &QThread::finished, mySynchronizeRecorder, &QObject::deleteLater,Qt::QueuedConnection);
	myRecorderThread->start();
}



LeapMotionQt::~LeapMotionQt()
{
	myRecorderThread->quit();
	myRecorderThread->wait();
}


void LeapMotionQt::exportingTheVideoSequence(QVector<QImage>* imageSequence){
	if (!ui.radioCheckForVideo->isChecked())return;
	if (!QDir("VideoStreams").exists()) QDir().mkdir("VideoStreams/");
	QProgressDialog progress("Exporting Video Sequences", "Abort Export", 0, imageSequence->size());
	progress.setWindowModality(Qt::WindowModal);

	for (int i = 0; i < imageSequence->size(); i++) {
		progress.setValue(i);
		QString filename = "VideoStreams/" + QString::number(i) + ".jpeg";
		imageSequence->at(i).save(filename,"jpeg");
		if (progress.wasCanceled())
			break;
		//... copy one file
	}
	progress.setValue(imageSequence->size());
	imageSequence->clear();
}