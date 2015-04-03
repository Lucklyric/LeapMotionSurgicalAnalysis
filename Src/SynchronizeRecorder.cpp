#include "..\Include\SynchronizeRecorder.h"
#include <iostream>

SynchronizeRecorder::SynchronizeRecorder()
{
	mMotiontFileRecorder = new DataRecorder();
	myEncoder = new QVideoEncoder();
	isRecording = false;
}


SynchronizeRecorder::~SynchronizeRecorder()
{
	delete mMotiontFileRecorder;
	delete myEncoder;
}

void SynchronizeRecorder::parseOneMotionFrame(Leap::Frame mFrame){
	if (!isRecording) return;
	mMotiontFileRecorder->ParseCurrentFrametoFile(mFrame);
}


void SynchronizeRecorder::parseOneVideoFrame(QImage mImage){
	if (!isRecording) return;
	myEncoder->encodeImage(mImage);
}

void SynchronizeRecorder::stopRecording(){
	mMotiontFileRecorder->EndReocrding();
	myEncoder->close();
	isRecording = false;
}

void  SynchronizeRecorder::startVideoRecording(QImage mImage){
	myEncoder->createFile("../test.avi", mImage.width(), mImage.height(), 1000, 10, 60);
	isRecording = true;
}

