#include "..\Include\CanonQtCamera.h"
#include "EDSDKcpp.h"
#include <iostream>
#include <stdio.h>
#include <boost\filesystem.hpp>
#include <QPainter>


CanonQtCamera::CanonQtCamera(QWidget *parent) : QLabel(parent){
	
	std::cout << "initialized camera widget" << std::endl;
	std::cout << "curThread" << this->thread() <<std::endl;
	myWorker = new CameraWorker;
	myWorker->moveToThread(&workerThread);
	myWorker->myTimer.moveToThread(&workerThread);
	connect(&workerThread, &QThread::finished, myWorker, &QObject::deleteLater);
	connect(&myTimer, SIGNAL(timeout()), this, SLOT(updateCamera()));
	connect(this, SIGNAL(startWorker()), myWorker, SLOT(startWorking()),Qt::QueuedConnection);
	connect(this, SIGNAL(killWorkerTimer()), myWorker, SLOT(killTheTimer()),Qt::QueuedConnection);
	workerThread.start();
	emit startWorker();
	myTimer.start(10);
}

CanonQtCamera::~CanonQtCamera(){
	myTimer.stop();
	emit killWorkerTimer();
	workerThread.quit();
	workerThread.wait();
}

void CanonQtCamera::updateCamera(){
	QImage img= myWorker->lastFrameImage();
	this->setPixmap(QPixmap::fromImage(img));
}


