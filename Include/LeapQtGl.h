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

	void 					onFrame(Leap::Frame frame);
	LeapMotion::DeviceRef	mLeap;
	Leap::Frame				mFrame;
	ci::CameraPersp			mCamera;
	Quatf mObjOrientation;
	float mScale;
	Vec3f mTranslate;
	vector<Leap::Frame> deserializedFrames;
	bool mStaticPosHand, mStaticOrientHand;
	bool isRecording;


private slots:
	void startRecording();
	void importFile();
private:
	QTimer myTimer;
};

