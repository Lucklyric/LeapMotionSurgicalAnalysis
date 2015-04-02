#pragma once
#include <QObject>
#include <Qimage>
#include "EDSDKcpp.h"
#include <QTimer>
#include <QPixmap>
#include <QMutex>
using namespace EDSDK;
class CameraWorker : public QObject
{
	Q_OBJECT
public:
    CameraWorker();
	~CameraWorker();
	QImage lastFrameImage();
	bool isNewFrame;

public:
	CameraRef mCamera;
	void browserDidAddCamera(CameraRef camera);
	void browserDidRemoveCamera(CameraRef camera);
	void browserDidEnumerateCameras();
	void didRemoveCamera(CameraRef camera);
	void didAddFile(CameraRef camera, CameraFileRef file);
	
	QImage lastImage;
public:
	QTimer myTimer;
	QMutex myLock;
	public slots :
	void startWorking();
	void updateImage();
	void killTheTimer();
signals:
	//void cameraStarted();
};

