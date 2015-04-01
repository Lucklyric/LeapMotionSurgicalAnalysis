#pragma once

#ifdef __GL_H__
#undef __GL_H__
#endif

#include <QWidget>
#include "EDSDKcpp.h"
#include <QTimer>
#include <QLabel>
#include <QThread>
#include "CameraWorker.h"

class CanonQtCamera : public QLabel
{
	Q_OBJECT
public:
	QThread workerThread;
	explicit CanonQtCamera(QWidget* parent = 0);
	~CanonQtCamera();
	private slots:

	void updateCamera();

private:
	QTimer myTimer;
	CameraWorker* myWorker;
signals:
	void startWorker();
	void killWorkerTimer();
};

