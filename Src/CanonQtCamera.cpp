#include "..\Include\CanonQtCamera.h"
#include "EDSDKcpp.h"
#include <iostream>
#include <boost\filesystem.hpp>
#include <QPainter>
#include <QFileDialog>

CanonQtCamera::CanonQtCamera(QWidget *parent) : QLabel(parent){
	
	std::cout << "initialized camera widget" << std::endl;
	std::cout << this->thread() << "curThread" << QThread::currentThread << std::endl;
	myWorker = new CameraWorker;
	myWorker->moveToThread(&workerThread);
	myWorker->myTimer.moveToThread(&workerThread);
	connect(&workerThread, &QThread::finished, myWorker, &QObject::deleteLater, Qt::QueuedConnection);
	connect(myWorker, &CameraWorker::killedTheTimer, &workerThread, &QThread::quit, Qt::QueuedConnection);
	connect(this, SIGNAL(startWorker()), myWorker, SLOT(startWorking()),Qt::QueuedConnection);
	//connect(this, &QWidget::closeEvent, myWorker, &CameraWorker::killTheTimer, Qt::QueuedConnection);
	connect(this, SIGNAL(killWorkerTimer()), myWorker, SLOT(killTheTimer()), Qt::QueuedConnection);

	workerThread.start();
	std::cout << "BeforeStart" << QThread::currentThread() << std::endl;
	isRecording = false;
	isReplaying = false;
	emit startWorker();
	//emit killWorkerTimer();
	recordingindex = 0;
	replayingindex = 0;
	currentImagesCount = 0;
	this->setScaledContents(true);
}

CanonQtCamera::~CanonQtCamera(){
	workerThread.quit();
	workerThread.wait();
}
void CanonQtCamera::closeEvent(){
	std::cout << "close event" <<std::endl;
	emit killWorkerTimer();
}
void CanonQtCamera::killWokerTimer(){
	std::cout << "stop camera" << std::endl;
	emit killWorkerTimer();
}

void CanonQtCamera::updateCamera(){

	if (isReplaying)
	{
		QString labelTex = "MotionFrame:" + QString::number(replayingindex + 1) + "/" + QString::number(currentImagesCount);
		emit setFrameLabelTex(labelTex);
		mImage = QImage(replayImagesFolder+"/"+QString::number(replayingindex)+".jpeg");
		
	}
	else
	{
		mImage = myWorker->lastFrameImage();
	}
	
	
	if (isRecording)
	{
		//std::cout << "outFrame Size:" << encode.encodeImage(mImage) << std::endl;
		//QString filename = "Images/test" + QString::number(recordingindex)+".png";
		//if (!QDir("Folder").exists()) QDir().mkdir("Images");
		//mImage.save(filename);
		//encode.encodeImage(mImage);
		emit sendOneVideoFrame(mImage);
		recordingindex++;
	}

	

	this->setPixmap(QPixmap::fromImage(mImage));
}

void CanonQtCamera::toggleRecording(){
	if (myWorker->mCamera == NULL) return;
	if (isRecording){
		isRecording = false;
		//encode.close();
		
		emit callSynVideoStop();
	}else{
		/*std::cout << "Start Recording" <<std::endl;
		isRecording = true;
		encode.createFile("../test.avi", mImage.width(), mImage.height(), 1000, 10, 60);
		std::cout << "succes creat file Recording" << std::endl;*/
		isRecording = true;
		emit callSynVideoStart(mImage);
	}
}

void CanonQtCamera::importVideo(){
	QString qName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
		"../",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	replayImagesFolder = QString::QString(qName);

	isReplaying = true;
	replayingindex = 0;
	QDir countFiled;
	countFiled.setPath(qName);
	//std::string fileName = qName.toUtf8().constData();
	//std::cout << countFiled.count()  << std::endl;
	currentImagesCount = countFiled.count();
	emit loadedFrame(0, currentImagesCount-1);
}

void CanonQtCamera::changeReaplyingIndex(int index){
	replayingindex = index;
}




