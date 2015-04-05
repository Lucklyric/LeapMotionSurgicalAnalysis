
#include "..\Include\LeapQtGl.h"
#include <iostream>
#include <QtWidgets\QFileDialog>
#include "leapmotionqt.h"

#define __BONES__
using namespace Leap;

LeapQtGl::LeapQtGl(QWidget *parent) : QGLWidget(parent),fRotationX(0.0f),
fRotationY(0.0f),
fRotationZ(0.0f),
fMoveUpDown(0.0f),
fMoveLeftRight(0.0f),
fMoveInOut(-15.0f){	
}


void LeapQtGl::initializeGL(){


	std::cout << "initialized" << std::endl;

	isRecording = false;
	isReplaying = false;
	mStaticOrientHand = false;
	mStaticPosHand = false;

	mScale = 1;
	mRecordingFrameIndex = 0;
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
	myTimer.start((1/60)*1000);
}

void LeapQtGl::updateGL(){
	QGLWidget::updateGL();
	if (isReplaying){
		mFrame = deserializedFrames[mRecordingFrameIndex];
		QString labelTex = "MotionFrame:" + QString::number(mRecordingFrameIndex + 1) + "/" + QString::number(deserializedFrames.size());
		emit setFrameLabelTex(labelTex);
		//std::cout << "current frame id:" << mFrame.id() << std::endl;
	}else{
		emit callCameraUpdate();
		emit sendOneMotionFrame(mFrame);
		//cout << mRecordingFrameIndex<<endl;
		//mRecordingFrameIndex++;
		mLeap->update();
	}
	updateGenearlInfo();
}

void LeapQtGl::paintGL(){

	// Clear window
	
	gl::clear(ColorA(0, 0, 0, 0.0));

	
	gl::pushMatrices();



	glPushAttrib(GL_ALL_ATTRIB_BITS);
	drawHands();

	gl::popMatrices();
	glPopAttrib();

	gl::color(ColorA(0, 0, 0, 1));
}

void LeapQtGl::drawHands(){
	
	
	gl::setMatrices(mCamera);
	//gl::translate(mTranslate);
	//gl::rotate(mObjOrientation);
	glTranslatef(fMoveLeftRight, fMoveUpDown, fMoveInOut);
	glRotatef(fRotationX/5000.0f, 1.0f, 0.0f, 0.0f);
	glRotatef(fRotationY/5000.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(fRotationZ/5000.0f, 0.0f, 0.0f, 1.0f);

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
	std::ifstream in(fileName, std::fstream::in | std::fstream::binary);
	std::string contents;
	if (in)
	{
		long l, m;
		in.seekg(0, std::ios::beg);
		long nextBlockSize = 0;
		in >> nextBlockSize;
		std::cout << "Start Load File.." << std::endl;
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

	}
	isReplaying = true;
	mRecordingFrameIndex = 0;
	std::cout << "Loaded File No. of frame "<<deserializedFrames.size() << std::endl;
	emit loadedFrame(0,deserializedFrames.size()-1);
	//emit setFrameLabelTex("aaaaaa");
}

void LeapQtGl::lastFrame(){
	if (mRecordingFrameIndex >= 0){
		mRecordingFrameIndex--;
		emit buttonChangedFrame(mRecordingFrameIndex);
	}
}

void LeapQtGl::nextFrame(){
	if (mRecordingFrameIndex <= deserializedFrames.size()-1){
		mRecordingFrameIndex++;
		emit buttonChangedFrame(mRecordingFrameIndex);
	}
}

void LeapQtGl::changeToFrame(int index){
	mRecordingFrameIndex = index;
}

void LeapQtGl::updateGenearlInfo(){
	LeapMotionQt* thisParent = dynamic_cast<LeapMotionQt*>(this->mParent);
	thisParent->ui.dFps->setText(QString::number(mLeap->returnDeviceFrequency()));
	//QString labelTex = "MotionFrame:" + QString::number(mRecordingFrameIndex + 1) + "/" + QString::number(deserializedFrames.size());
	//thisParent->ui.motionFrame->setText("aaaaa");
}
void LeapQtGl::resizeGL(int w, int h){
	glViewport(0, 0, w, h);
}

void LeapQtGl::onFrame(Leap::Frame frame){
	mFrame = frame;
}

//==============================================================================	mouse Press Event
void LeapQtGl::mousePressEvent(QMouseEvent *pEvent)
{
	lastPos = pEvent->pos();
}



//==============================================================================	mouse Move Event
void LeapQtGl::mouseMoveEvent(QMouseEvent *pEvent)
{
	GLfloat dx = (GLfloat)(pEvent->x() - lastPos.x()) / viewport_size.width();
	GLfloat dy = (GLfloat)(pEvent->y() - lastPos.y()) / viewport_size.height();

	qDebug() << dx;
	qDebug() << dy << "\n";

	if (pEvent->buttons() & Qt::LeftButton)
	{
		setRotation(180 * dy, 180 * dx, 0.0);
	}
	else if (pEvent->buttons() & Qt::RightButton)
	{
		setRotation(180 * dy, 0.0, 180 * dx);
	}
	else
	{
	} // do nothing //

	lastPos = pEvent->pos();
}



//==============================================================================	set Rotation
void LeapQtGl::setRotation(GLfloat _x, GLfloat _y, GLfloat _z)
{
	fRotationX += _x;
	fRotationY += _y;
	fRotationZ += _z;
}



//==============================================================================	wheel Event
void LeapQtGl::wheelEvent(QWheelEvent * pEvent)
{
	fMoveInOut -= (GLfloat)pEvent->delta() / 80.0;
	
}



//==============================================================================	key Press Event
void LeapQtGl::keyPressEvent(QKeyEvent *pEvent)
{
	switch (pEvent->key())
	{
	/*case Qt::Key_Escape:
		exit(0);
		break;*/

	case Qt::Key_R:
		fRotationX = 0.0f;
		fRotationY = 0.0f;
		fRotationZ = 0.0f;
		fMoveUpDown = 0.0f;
		fMoveLeftRight = 0.0f;
		fMoveInOut = -15.0f;
		break;

	case Qt::Key_Up:
	case Qt::Key_W:
		fMoveUpDown += 0.6;
		break;

	case Qt::Key_Down:
	case Qt::Key_S:
		fMoveUpDown -= 0.6;
		break;

	case Qt::Key_Left:
	case Qt::Key_A:
		fMoveLeftRight -= 0.6;
		break;

	case Qt::Key_Right:
	case Qt::Key_D:
		fMoveLeftRight += 0.6;
		break;

	default:
		break;
		//LeapQtGl::keyPressEvent(pEvent);
	}
	
}