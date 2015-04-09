#include "..\Include\SynchronizeRecorder.h"
#include <iostream>
#include <QDir>
#include <QProgressDialog>

SynchronizeRecorder::SynchronizeRecorder()
{
	mMotiontFileRecorder = new DataRecorder();
	myEncoder = new QVideoEncoder();
	imageSequence = new QVector<QImage>();
	isRecording = false;
	recordingIndex = 0;
}


SynchronizeRecorder::~SynchronizeRecorder()
{
	delete mMotiontFileRecorder;
	delete myEncoder;
	delete imageSequence;
}

void SynchronizeRecorder::parseOneMotionFrame(Leap::Frame mFrame){
	if (!isRecording) return;
	//std::cout << "parse one motion" <<std::endl;
	mMotiontFileRecorder->ParseCurrentFrametoFile(mFrame);
}


void SynchronizeRecorder::parseOneVideoFrame(QImage mImage){
	if (!isRecording) return;
	//cout << "parse one video" <<endl;
	imageSequence->push_back(mImage);
}

void SynchronizeRecorder::stopRecording(){
	mMotiontFileRecorder->EndReocrding();
	//std::cout << "emit call Synvideostop" << std::endl;
	//myEncoder->close();
	isRecording = false;
	recordingIndex = 0;
	emit startExportingVideoSequence(imageSequence);
}

void  SynchronizeRecorder::startVideoRecording(QImage mImage){
	//myEncoder->createFile("test.mp4", mImage.width(), mImage.height(), 1000, 10, 60);
	isRecording = true;
}

