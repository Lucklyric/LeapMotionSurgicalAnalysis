#include "..\Include\CanonQtCamera.h"
#include "EDSDKcpp.h"
#include <iostream>
#include <stdio.h>
#include <boost\filesystem.hpp>
#include <QPainter>


CanonQtCamera::CanonQtCamera(QWidget *parent) : QLabel(parent){
	
	std::cout << "initialized camera widget" << std::endl;
	myWorker = new CameraWorker;
	myWorker->moveToThread(&workerThread);
	connect(&workerThread, &QThread::finished, myWorker, &QObject::deleteLater);
	connect(&myTimer, SIGNAL(timeout()), this, SLOT(updateCamera()));
	workerThread.start();
	myWorker->startWorking();
	myTimer.start(10);
}

CanonQtCamera::~CanonQtCamera(){
	myTimer.stop();
	myWorker->killTheTimer();
	workerThread.quit();
	workerThread.wait();
}

void CanonQtCamera::updateCamera(){
	QImage img= myWorker->lastFrameImage();
	this->setPixmap(QPixmap::fromImage(img));
}


