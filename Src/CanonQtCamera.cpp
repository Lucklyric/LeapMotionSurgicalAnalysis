#include "..\Include\CanonQtCamera.h"
#include "EDSDKcpp.h"
#include <iostream>
#include <boost\filesystem.hpp>
#include <QPainter>
#include "QVideoEncoder.h"

QVideoEncoder encode;
CanonQtCamera::CanonQtCamera(QWidget *parent) : QLabel(parent){
	
	std::cout << "initialized camera widget" << std::endl;
	std::cout << "curThread" << this->thread() <<std::endl;
	myWorker = new CameraWorker;
	myWorker->moveToThread(&workerThread);
	myWorker->myTimer.moveToThread(&workerThread);
	connect(&workerThread, &QThread::finished, myWorker, &QObject::deleteLater,Qt::QueuedConnection);
	connect(this, SIGNAL(startWorker()), myWorker, SLOT(startWorking()),Qt::QueuedConnection);
	std::cout << "BeforeStart" << QThread::currentThread() << std::endl;
	workerThread.start();
	isRecording = false;
	emit startWorker();
	recordingindex = 0;
	this->setScaledContents(true);
}

CanonQtCamera::~CanonQtCamera(){
	std::cout << "CanonQtTimerStop" << this->thread() << std::endl;
	workerThread.quit();
	workerThread.wait();
	std::cout << "workerThreadKilled" << this->thread() << std::endl;
}


void CanonQtCamera::updateCamera(){
	mImage= myWorker->lastFrameImage();
	////mImage.scaledToWidth(this->width());

	//std::cout << "Get One Frame" << std::endl;
	if (isRecording)
	{
		//std::cout << "outFrame Size:" << encode.encodeImage(mImage) << std::endl;
		//QString filename = "Images/test" + QString::number(recordingindex)+".png";
		//if (!QDir("Folder").exists()) QDir().mkdir("Images");
		//mImage.save(filename);
		encode.encodeImage(mImage);
		recordingindex++;
	}

	this->setPixmap(QPixmap::fromImage(mImage));
}

void CanonQtCamera::toggleRecording(){
	if (myWorker->mCamera == NULL) return;
	if (isRecording){
		isRecording = false;
		encode.close();
	}else{
		std::cout << "Start Recording" <<std::endl;
		isRecording = true;
		encode.createFile("../test.avi", mImage.width(), mImage.height(), 1000, 10, 60);
		std::cout << "succes creat file Recording" << std::endl;
	}
}




