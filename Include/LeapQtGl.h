#pragma once 

#ifdef __GL_H__
#undef __GL_H__
#endif

#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Quaternion.h"
#include <QGLWidget>
#include "Cinder-LeapMotion.h"
#include <QTimer>
#include <cinder\Camera.h>
#include <QtWidgets/QPushButton>
#include <vector>
#include <boost/filesystem.hpp>
#include <QMouseEvent>
#include <QWheelEvent>

using namespace ci;
class LeapQtGl :
	public QGLWidget
{
	Q_OBJECT
public:
	explicit LeapQtGl(QWidget* parent = 0);

	void initializeGL();
	void paintGL();
	void resizeGL(int w, int h);
	void updateGL();
	void drawHands();
	void drawHand(Leap::Hand &hand, Vec3f position);
	void updateGenearlInfo();
	void 					onFrame(Leap::Frame frame);
	LeapMotion::DeviceRef	mLeap;
	Leap::Frame				mFrame;
	ci::CameraPersp			mCamera;
	QWidget*				mParent;
	Quatf mObjOrientation;
	float mScale;
	long int mRecordingFrameIndex;
	Vec3f mTranslate;
	vector<Leap::Frame> deserializedFrames;
	bool mStaticPosHand, mStaticOrientHand;
	bool isRecording, isReplaying, isSynchMode,isAutoPlaying;
	/** Handles mouse press events on the QGLWidget. */
	void mousePressEvent(QMouseEvent *pEvent);

	/** Handles mouse move events on the QGLWidget. */
	void mouseMoveEvent(QMouseEvent *pEvent);

	/** Zoomin in and out of the cube */
	void wheelEvent(QWheelEvent * pEvent);

	/** reaction on a key press */
	void keyPressEvent(QKeyEvent *pEvent);

	private slots:
	void startRecording();
	void importFile();
	void lastFrame();
	void nextFrame();
	void convertFile();
	public slots:
	void changeToFrame(int index);
	void synchroMode(bool flag);
	void autoPlayMode();
	void reOutPutDataFile();
signals:
	void callCameraUpdate();
	void sendOneMotionFrame(Leap::Frame mFrame);
	void loadedFrame(int start,int end);
	void buttonChangedFrame(int index);
	void changeCameraIndex(int index);
	void setFrameLabelTex(QString mString);
private:
	QTimer myTimer;
	GLfloat fRotationX;
	GLfloat fRotationY;
	GLfloat fRotationZ;

	GLfloat fMoveUpDown;
	GLfloat fMoveLeftRight;
	GLfloat fMoveInOut;
	
	QSize viewport_size;					//< current size of the viewport.
	QPoint lastPos;							//< last mose position

	/** Change settings for rendering. */
	void setRotation(GLfloat _x, GLfloat _y, GLfloat _z);

};
