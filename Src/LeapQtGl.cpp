#include "..\Include\LeapQtGl.h"
#include <stdio.h>
#include <iostream>
#include <QtWidgets\QFileDialog>
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Quaternion.h"
#define __BONES__
using namespace Leap;
LeapQtGl::LeapQtGl(QWidget *parent) : QGLWidget(parent){
	
}

void LeapQtGl::initializeGL(){
	std::cout << "initialized" << std::endl;

	isRecording = false;
	mStaticOrientHand = false;
	mStaticPosHand = false;

	mScale = 1;
	mTranslate.set(0, 200, 0);
	// Set up OpenGL
	gl::enableAlphaBlending();
	gl::enableDepthRead();
	gl::enableDepthWrite();

	// Set up camera
	mCamera = CameraPersp(this->frameSize().width(), this->frameSize().height(), 60.0f, 0.01f, 5000.0f);
	mCamera.lookAt(Vec3f(0.0f, 500.0f, 500.0f), Vec3f(0.0f, 250.0f, 0.0f));

	// Start device
	mLeap = LeapMotion::Device::create();
	mLeap->connectEventHandler(&LeapQtGl::onFrame, this);
	connect(&myTimer, SIGNAL(timeout()), this, SLOT(updateGL()));
	myTimer.start(16);
}

void LeapQtGl::updateGL(){
	QGLWidget::updateGL();
	mLeap->update();
}

void LeapQtGl::paintGL(){

	// Clear window
	
	gl::clear(ColorA(0, 0, 0, 0.0));


	glPushAttrib(GL_ALL_ATTRIB_BITS);
	gl::pushMatrices();

	
	drawHands();

	gl::popMatrices();
	glPopAttrib();

	gl::color(ColorA(0, 0, 0, 1));
}

void LeapQtGl::drawHands(){
	
	
	gl::setMatrices(mCamera);
	gl::translate(mTranslate);
	gl::rotate(mObjOrientation);

	float headLength = 6.0f;
	float headRadius = 3.0f;
	Leap::Frame currentFrame;
	currentFrame = mFrame;
	
	const Leap::HandList& hands = currentFrame.hands();
	
	// Iterate through hands
	for (Leap::HandList::const_iterator handIter = hands.begin(); handIter != hands.end(); ++handIter) {

		Leap::Hand hand = *handIter;

		// Get hand data
		Vec3f handDir = LeapMotion::toVec3f(hand.direction());
		Vec3f palmNorm = LeapMotion::toVec3f(hand.palmNormal());
		Vec3f palmPos = LeapMotion::toVec3f(hand.palmPosition());
		Vec3f palmVel = LeapMotion::toVec3f(hand.palmVelocity());
		Vec3f sphereCenter = LeapMotion::toVec3f(hand.sphereCenter());
		float sphereRadius = hand.sphereRadius();
		

		// Hand normal
		gl::color(1.0f, 1.0f, 1.0f, 1.0f);

		
		gl::drawVector(palmPos, palmPos + palmNorm * 30.0f, headLength, headRadius);


		gl::pushMatrices();
		if (mStaticPosHand)
		{
			if (hands.count() > 1)
			{
				if (hand.id() == hands.leftmost().id())
					gl::translate(Vec3f(-100, 0, 0)*mScale);
				else
					gl::translate(Vec3f(100, 0, 0)*mScale);
			}
		}
		else
			gl::translate(LeapMotion::toVec3f(hand.palmPosition()*mScale));
		
		drawHand(hand, Vec3f(0, 0, 0));

		gl::popMatrices();
	}
}

void LeapQtGl::drawHand(Leap::Hand &hand, Vec3f position){
	
	Vec3f handPalm = LeapMotion::toVec3f(hand.palmPosition());

	Vec3f handVelocity = LeapMotion::toVec3f(hand.palmVelocity());



	gl::translate(position);

	gl::scale(mScale, mScale, mScale);



	Leap::Matrix handTransform = hand.basis();

	if (!mStaticOrientHand)
	{
		handTransform = handTransform.rigidInverse();
		gl::pushMatrices();

		gl::multModelView(LeapMotion::toMatrix44f(handTransform));
	}

	gl::drawColorCube(Vec3f(0, 0, 0), Vec3f(40, 10, 40));



	if (!mStaticOrientHand)
		gl::popMatrices();
	else
	{
		gl::pushMatrices();
		gl::multModelView(LeapMotion::toMatrix44f(handTransform));
	}



	const Leap::FingerList& fingers = hand.fingers();
	for (Leap::FingerList::const_iterator pointIter = fingers.begin(); pointIter != fingers.end(); ++pointIter) {
		const Leap::Finger& finger = *pointIter;

		Leap::Vector fingerTipOrigin;

#ifdef __BONES__

		Leap::Vector fingerPipPos;
		Leap::Vector fingerDipPos;
		Leap::Vector fingerMcpPos;


		Leap::Bone tipBone = finger.bone(Bone::Type::TYPE_DISTAL);
		Leap::Bone pipBone = finger.bone(Bone::Type::TYPE_INTERMEDIATE);
		Leap::Bone dipBone = finger.bone(Bone::Type::TYPE_PROXIMAL);
		Leap::Bone mcpBone = finger.bone(Bone::Type::TYPE_METACARPAL);


		fingerTipOrigin = tipBone.center();
		fingerPipPos = pipBone.center();
		fingerDipPos = dipBone.center();
		fingerMcpPos = mcpBone.center();

		fingerPipPos -= hand.palmPosition();
		fingerDipPos -= hand.palmPosition();
		fingerMcpPos -= hand.palmPosition();

#else
		fingerTipOrigin = finger.tipPosition();
#endif

		fingerTipOrigin -= hand.palmPosition();

		Leap::Matrix fingerTransform;

		gl::color(ColorAf::gray(0.8f));

#ifdef __BONES__

		gl::drawSphere(LeapMotion::toVec3f(fingerMcpPos), 10);
		gl::drawSphere(LeapMotion::toVec3f(fingerPipPos), 10);
		gl::drawSphere(LeapMotion::toVec3f(fingerDipPos), 10);
		gl::drawSphere(LeapMotion::toVec3f(fingerTipOrigin), 10);
		gl::drawLine(LeapMotion::toVec3f(fingerMcpPos), LeapMotion::toVec3f(fingerPipPos));
		gl::drawLine(LeapMotion::toVec3f(fingerPipPos), LeapMotion::toVec3f(fingerDipPos));
		gl::drawLine(LeapMotion::toVec3f(fingerDipPos), LeapMotion::toVec3f(fingerTipOrigin));

		fingerTransform = tipBone.basis().rigidInverse();
		gl::pushMatrices();
		gl::translate(LeapMotion::toVec3f(fingerTipOrigin));
		gl::multModelView(LeapMotion::toMatrix44f(fingerTransform));
		gl::drawColorCube(Vec3f(0, 0, 0), Vec3f(10, 10, tipBone.length()));
		gl::popMatrices();

		fingerTransform = pipBone.basis().rigidInverse();
		gl::pushMatrices();
		gl::translate(LeapMotion::toVec3f(fingerPipPos));
		gl::multModelView(LeapMotion::toMatrix44f(fingerTransform));
		gl::drawColorCube(Vec3f(0, 0, 0), Vec3f(10, 10, pipBone.length()));
		gl::popMatrices();

		fingerTransform = dipBone.basis().rigidInverse();
		gl::pushMatrices();
		gl::translate(LeapMotion::toVec3f(fingerDipPos));
		gl::multModelView(LeapMotion::toMatrix44f(fingerTransform));
		gl::drawColorCube(Vec3f(0, 0, 0), Vec3f(10, 10, dipBone.length()));
		gl::popMatrices();

#else
		float mag = finger.direction().dot(-hand.palmNormal());
		Leap::Vector right = finger.direction().cross(-hand.palmNormal());
		if (mag < -0.45 || mag > 0.45)
			right = finger.direction().cross(hand.direction());

		right = right.normalized();
		Leap::Vector down = finger.direction().cross(right).normalized();
		Leap::Vector up = -down;

		fingerTransform = Leap::Matrix(right, up, finger.direction()).rigidInverse();
		gl::pushMatrices();
		gl::translate(LeapMotion::toVec3f(fingerTipOrigin*0.5));
		gl::multModelView(LeapMotion::toMatrix44f(fingerTransform));
		gl::drawColorCube(Vec3f(0, 0, 0), Vec3f(10, 10, finger.length()));
		gl::popMatrices();
#endif

	}
	if (mStaticOrientHand)
		gl::popMatrices();
}

void LeapQtGl::startRecording(){
	QPushButton* pushButton = dynamic_cast<QPushButton*>(sender());
	if (isRecording){
		pushButton->setText("StartRecording");
		isRecording = false;
		cout << "OutputFile" <<endl;
		mLeap->outPutRecordingFile();
	}else{
		pushButton->setText("StopRecording");
		isRecording = true;
		cout << "StartRecoridng" << endl;
		mLeap->startRecording();
	}
}

void LeapQtGl::importFile(){
	deserializedFrames.clear();

	QString qName = QFileDialog::getOpenFileName();
	std::string fileName = qName.toUtf8().constData();
	cout << fileName<< endl;
	std::ifstream in(fileName, std::fstream::in);
	std::string contents;
	if (in)
	{
		in.seekg(0, std::ios::beg);
		long nextBlockSize = 0;
		in >> nextBlockSize;
		std::cout << nextBlockSize << std::endl;
		while (!in.eof())
		{
			contents.resize(nextBlockSize);
			in.read(&contents[0], nextBlockSize);
			Leap::Frame newFrame;
			newFrame.deserialize(contents);
			if (newFrame.isValid()) deserializedFrames.push_back(newFrame);
			in >> nextBlockSize;
		}
		in.close();
	}
	else if (errno){
		std::cout << "Error: " << errno << std::endl;
		//std::cout << "Couldn't open " << fileName.toStdWString() << " for reading." << std::endl;
	}
	std::cout << deserializedFrames.size() << std::endl;
}

void LeapQtGl::resizeGL(int w, int h){
	glViewport(0, 0, w, h);
}

void LeapQtGl::onFrame(Leap::Frame frame){
	mFrame = frame;
}