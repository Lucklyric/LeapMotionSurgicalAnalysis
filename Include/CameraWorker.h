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
	explicit CameraWorker(QObject *parent = 0);

	QImage lastFrameImage();
	bool isNewFrame;
	public slots :
		void startWorking();
		void updateImage();
public:
	CameraRef mCamera;
	void browserDidAddCamera(CameraRef camera);
	void browserDidRemoveCamera(CameraRef camera);
	void browserDidEnumerateCameras();
	void didRemoveCamera(CameraRef camera);
	void didAddFile(CameraRef camera, CameraFileRef file);
	void killTheTimer();
	QImage lastImage;
private:
	QTimer myTimer;
	QMutex myLock;
};

