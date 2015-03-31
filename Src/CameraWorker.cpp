#include "..\Include\CameraWorker.h"


CameraWorker::CameraWorker(QObject *parent) :
QObject(parent)
{
	isNewFrame = false;
	CameraBrowser::instance()->connectAddedHandler(&CameraWorker::browserDidAddCamera, this);
	CameraBrowser::instance()->connectRemovedHandler(&CameraWorker::browserDidRemoveCamera, this);
	CameraBrowser::instance()->connectEnumeratedHandler(&CameraWorker::browserDidEnumerateCameras, this);
	CameraBrowser::instance()->start();
}


void CameraWorker::updateImage(){
	QImage img;
	if (mCamera != NULL && mCamera->hasOpenSession() && mCamera->isLiveViewing()) {
		mCamera->requestDownloadEvfData(img);
		//std::cout << "QImage: " << img.width() << " x " << img.height() << std::endl;
	}
	lastImage = img;
	isNewFrame = true;
}

QImage CameraWorker::lastFrameImage(){
	return lastImage;
}

void CameraWorker::killTheTimer(){
	myLock.lock();
	myTimer.stop();
	myLock.unlock();
}


void CameraWorker::startWorking(){
	mCamera->toggleLiveView();
	connect(&myTimer, SIGNAL(timeout()), this, SLOT(updateImage()),Qt::DirectConnection);
	myTimer.start(10);
}

#pragma mark - CAMERA BROWSER

void  CameraWorker::browserDidAddCamera(CameraRef camera) {
	std::cout << "added a camera: " << camera->getName() << std::endl;
	if (mCamera != NULL) {
		return;
	}

	mCamera = camera;
	mCamera->connectRemovedHandler(&CameraWorker::didRemoveCamera,this);
	mCamera->connectFileAddedHandler(&CameraWorker::didAddFile,this);
	std::cout << "grabbing camera: " << camera->getName() << std::endl;

	EDSDK::Camera::Settings settings = EDSDK::Camera::Settings();
	//    settings.setPictureSaveLocation(kEdsSaveTo_Both);
	settings.setShouldKeepAlive(false);
	EdsError error = mCamera->requestOpenSession(settings);
	if (error == EDS_ERR_OK) {
		std::cout << "session opened" << std::endl;
	}
}

void  CameraWorker::browserDidRemoveCamera(CameraRef camera) {
	// NB - somewhat redundant as the camera will notify handler first
	std::cout << "removed a camera: " << camera->getName() << std::endl;
	if (camera != mCamera) {
		return;
	}

	std::cout << "our camera was disconnected" << std::endl;
	mCamera = NULL;
}

void  CameraWorker::browserDidEnumerateCameras() {
	std::cout << "enumerated cameras" << std::endl;
}

#pragma mark - CAMERA

void  CameraWorker::didRemoveCamera(CameraRef camera) {
	std::cout << "removed a camera: " << camera->getName() << std::endl;
	if (camera != mCamera) {
		return;
	}

	std::cout << "our camera was disconnected" << std::endl;
	mCamera = NULL;
}


void  CameraWorker::didAddFile(CameraRef camera, CameraFileRef file)
{
	/*boost::filesystem::path destinationFolderPath = boost::filesystem::path("/Users/zhao.he/Desktop/Captures");
	camera->requestDownloadFile(file, destinationFolderPath, [&](EdsError error, boost::filesystem::path outputFilePath) {
	if (error == EDS_ERR_OK) {
	std::cout << "image downloaded to '" << outputFilePath << "'" << std::endl;
	}
	});*/

	//    camera->requestReadFile(file, [&](EdsError error, ci::Surface surface) {
	//        if (error == EDS_ERR_OK) {
	//            mPhotoTexture = gl::Texture(surface);
	//        }
	//    });
}