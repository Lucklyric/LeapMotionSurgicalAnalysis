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
#include <QDir>

class CanonQtCamera : public QLabel
{
	Q_OBJECT
public:
	QThread workerThread;
	explicit CanonQtCamera(QWidget* parent = 0);
	~CanonQtCamera();
	public slots:
	void updateCamera();
	void toggleRecording();

private:
	bool isRecording;
	//QTimer myTimer;
	int recordingindex;
	CameraWorker* myWorker;
	//QVideoEncoder* myQVideoEncoder;
	QImage mImage;
signals:
	void startWorker();
	void killWorkerTimer();
};

