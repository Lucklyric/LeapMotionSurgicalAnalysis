//
//  main.cpp
//  LeapMotion
//
//  Created by Alvin Sun on 2015-01-23.
//  Copyright (c) 2015 Alvin Sun. All rights reserved.
//

#include "cinder/app/AppBasic.h"
#include "cinder/app/AppNative.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/Quaternion.h"
#include "../include/CanonView.h"
#include "Leap.h"
#include "../Cinder-Leap/Cinder-LeapMotion.h"
#include "cinder/Thread.h"
#include "cinder/params/Params.h"
#include "AntTweakBar.h"
#include "cinder/gl/TextureFont.h"
#include "cinder/app/FileDropEvent.h"
#include <fstream>
#include <functional>


//Windows header files used
#define WINVER 0x0500
#include <iostream>
#include <time.h>

using namespace LeapMotion;
using namespace Leap;
using namespace ci;
using namespace ci::app;
using namespace std;

#define __BONES__

class LeapMotionMain : public ci::app::AppBasic
{
public:
    Font mFont;
    gl::TextureFontRef mTextureFont;

	void virtualizationDraw();
	void cameraDraw();
    void drawHand(Leap::Hand &hand, Vec3f position);
    void drawHands();
    void setup();
    void shutdown();
    void setupGui();
    void update();
    void CallDeviceUpdate();
    void StartRecording();
    void prepareSettings(Settings *settings);
    void fileDrop (FileDropEvent event);
    void keyDown( KeyEvent event );
	void connectWindow(ci::app::WindowRef window);
    std::shared_ptr<std::thread>		mThread;
private:
    
    Frame                   mFrame;
    LeapMotion::DeviceRef	mLeap;
    void 					onFrame( Leap::Frame frame );
    
    ci::CameraPersp			mCamera;
    ci::params::InterfaceGlRef	mParams;
    ci::params::InterfaceGlRef	mLeftHandInfo;
    ci::params::InterfaceGlRef	mRightHandInfo;
    //Recording Parameters
    std::vector<Leap::Frame> deserializedFrames;

    long int recordingFrameIndex;
    bool isPause;
    
    bool showParams;
    
    bool isPlayingRecording; // IF the state is playing the recorded frames data
    
    
    Quatf mObjOrientation;
    float mScale;
    Vec3f mTranslate;
    
    bool mStaticPosHand, mStaticOrientHand;
    
    Vec3f hand1PalmPosition, hand2PalmPostion;
    Vec3f hand1Velocity, hand2Velocity;
    
	WindowRef cameraWindow;
	CanonViewRef mCanonView;
    
};
void LeapMotionMain::prepareSettings( Settings *settings){
    //setting the window size and the frame rate for processing
    settings->setWindowSize ( 1000, 750);
    settings->setFrameRate (100.0f);

}

void LeapMotionMain::shutdown()
{

}

void LeapMotionMain::drawHand(Leap::Hand &hand, Vec3f position)
{
    Vec3f handPalm = LeapMotion::toVec3f(hand.palmPosition());

    Vec3f handVelocity = LeapMotion::toVec3f(hand.palmVelocity());

    float confiLevel = hand.confidence();
    std::stringstream string1;string1 << "Label='Position X:" << handPalm.x << " Y:"<<handPalm.y << " Z:"<<handPalm.z<<"' ";
    std::stringstream stringV;stringV << "Label='Velocity X:" << handVelocity.x << " Y:"<<handVelocity.y << " Z:"<<handVelocity.z<<"' ";
    std::stringstream stringCL;stringCL << "Label='ConfidenceLevel:" << confiLevel << "' ";
    
    
    if (hand.isLeft()) {

        mLeftHandInfo->setOptions("LeftHandPosition",string1.str());
        mLeftHandInfo->setOptions("LeftHandV",stringV.str());
        mLeftHandInfo->setOptions("Confidence",stringCL.str());
        
    }else{
        mRightHandInfo->setOptions("RightHandPosition",string1.str());
        mRightHandInfo->setOptions("RightHandV",stringV.str());
        mRightHandInfo->setOptions("Confidence",stringCL.str());
    }
    


    
    
    
    
    gl::translate(position);
    gl::scale(mScale, mScale, mScale);
    

    
    Leap::Matrix handTransform = hand.basis();
    
    if (!mStaticOrientHand)
    {
        handTransform = handTransform.rigidInverse();
        gl::pushMatrices();
        
        gl::multModelView(LeapMotion::toMatrix44f(handTransform));
    }
    
    gl::drawColorCube(Vec3f(0,0,0), Vec3f( 40, 10, 40 ) );
    
    
    
    if (!mStaticOrientHand)
        gl::popMatrices();
    else
    {
        gl::pushMatrices();
        gl::multModelView(LeapMotion::toMatrix44f(handTransform));
    }
    
    const Leap::FingerList& fingers = hand.fingers();
    for ( Leap::FingerList::const_iterator pointIter = fingers.begin(); pointIter != fingers.end(); ++pointIter ) {
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
        
        
        fingerTipOrigin =  tipBone.center();
        fingerPipPos = pipBone.center();
        fingerDipPos = dipBone.center();
        fingerMcpPos = mcpBone.center();
        
        fingerPipPos -= hand.palmPosition();
        fingerDipPos -= hand.palmPosition();
        fingerMcpPos -= hand.palmPosition();
        
#else
        fingerTipOrigin =  finger.tipPosition();
#endif
        
        fingerTipOrigin -= hand.palmPosition();
        
        Leap::Matrix fingerTransform;
        
        gl::color( ColorAf::gray( 0.8f ) );
        
#ifdef __BONES__
        
        gl::drawSphere(LeapMotion::toVec3f(fingerMcpPos), 10);
        gl::drawSphere(LeapMotion::toVec3f(fingerPipPos), 10);
        gl::drawSphere(LeapMotion::toVec3f(fingerDipPos), 10);
        gl::drawSphere(LeapMotion::toVec3f(fingerTipOrigin), 10);
        gl::drawLine(LeapMotion::toVec3f(fingerMcpPos), LeapMotion::toVec3f(fingerPipPos) );
        gl::drawLine(LeapMotion::toVec3f(fingerPipPos), LeapMotion::toVec3f(fingerDipPos) );
        gl::drawLine(LeapMotion::toVec3f(fingerDipPos), LeapMotion::toVec3f(fingerTipOrigin) );
        
        fingerTransform = tipBone.basis().rigidInverse();
        gl::pushMatrices();
        gl::translate(LeapMotion::toVec3f(fingerTipOrigin));
        gl::multModelView(LeapMotion::toMatrix44f(fingerTransform));
        gl::drawColorCube(Vec3f(0,0,0), Vec3f( 10, 10, tipBone.length() ) );
        gl::popMatrices();
        
        fingerTransform = pipBone.basis().rigidInverse();
        gl::pushMatrices();
        gl::translate(LeapMotion::toVec3f(fingerPipPos));
        gl::multModelView(LeapMotion::toMatrix44f(fingerTransform));
        gl::drawColorCube(Vec3f(0,0,0), Vec3f( 10, 10, pipBone.length() ) );
        gl::popMatrices();
        
        fingerTransform = dipBone.basis().rigidInverse();
        gl::pushMatrices();
        gl::translate(LeapMotion::toVec3f(fingerDipPos));
        gl::multModelView(LeapMotion::toMatrix44f(fingerTransform));
        gl::drawColorCube(Vec3f(0,0,0), Vec3f( 10, 10, dipBone.length() ) );
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
        gl::drawColorCube(Vec3f(0,0,0), Vec3f( 10, 10, finger.length() ) );
        gl::popMatrices();
#endif
        
    }
    if (mStaticOrientHand)
        gl::popMatrices();
}

void LeapMotionMain::drawHands()
{
    gl::setMatrices( mCamera );
    
    gl::translate(mTranslate);
    gl::rotate(mObjOrientation);
    float headLength = 6.0f;
    float headRadius = 3.0f;
    Leap::Frame currentFrame;
    if (isPlayingRecording) {
        currentFrame = deserializedFrames[recordingFrameIndex];
    }else{
        currentFrame = mFrame;
    }
    const Leap::HandList& hands = currentFrame.hands();
    
    // Iterate through hands
        for ( Leap::HandList::const_iterator handIter = hands.begin(); handIter != hands.end(); ++handIter ) {
        
        Leap::Hand hand = *handIter;
        
        // Get hand data
        Vec3f handDir		= LeapMotion::toVec3f( hand.direction() );
        Vec3f palmNorm		= LeapMotion::toVec3f( hand.palmNormal() );
        Vec3f palmPos		= LeapMotion::toVec3f( hand.palmPosition() );
        Vec3f palmVel		= LeapMotion::toVec3f( hand.palmVelocity() );
        Vec3f sphereCenter	= LeapMotion::toVec3f( hand.sphereCenter() );
        float sphereRadius	= hand.sphereRadius();
        if (hand.isLeft()) {
           hand1PalmPosition = LeapMotion::toVec3f( hand.palmPosition());

        }
        //mParams->setOptions()
//        // Hand sphere
//        gl::enableWireframe();
//        gl::color( ColorAf( Colorf::gray( 0.9f ), 0.5f ) );
//        gl::drawSphere( sphereCenter, sphereRadius, 16 );
//        gl::disableWireframe();
//        
//        // Hand plane
//        gl::color( ColorAf( 0.75f, 0.0f, 0.75f, 0.25f ) );
//        gl::pushMatrices();
//        gl::translate( palmPos );
//        gl::rotate( Quatf( palmPos, handDir ) );
//        for ( float i = 0.25f; i <= 1.0f; i += 0.25f ) {
//            gl::drawStrokedCircle( Vec2f::zero(), sphereRadius * i, 16 );
//        }
//        gl::popMatrices();
//        
//        // Hand direction
//        gl::color( 1.0f, 0.0f, 1.0f, 0.5f );
//        gl::drawVector( palmPos, palmPos + handDir * 30.0f, headLength, headRadius );
        
        // Hand normal
        gl::color( 1.0f, 1.0f, 1.0f, 1.0f );
      
        gl::drawVector( palmPos, palmPos + palmNorm * 30.0f, headLength, headRadius );
        
//        // Hand velocity
//        gl::color( 0.0f, 1.0f, 0.0f, 0.5f );
//        gl::drawVector( palmPos, palmPos + palmVel * 0.05f, headLength, headRadius );

        
        
        gl::pushMatrices();
        
        if (mStaticPosHand)
        {
            if (hands.count() > 1)
            {
                if (hand.id() == hands.leftmost().id())
                    gl::translate(Vec3f(-100,0,0)*mScale);
                else
                    gl::translate(Vec3f(100,0,0)*mScale);
            }
        }
        else
            gl::translate(LeapMotion::toVec3f(hand.palmPosition()*mScale));
        
        drawHand(hand, Vec3f(0,0,0));
        
        gl::popMatrices();
    }
}
/*
void LeapMotionMain::draw(){
	gl::setViewport(getWindowBounds());
	gl::clear(ColorA(0, 0, 0, 0.0));


	glPushAttrib(GL_ALL_ATTRIB_BITS);
	gl::pushMatrices();

	drawHands();

	gl::popMatrices();
	glPopAttrib();

	gl::color(ColorA(0, 0, 0, 1));
	if (!showParams)
		return;
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	mParams->draw();
	glPopAttrib();

}
*/
void LeapMotionMain::virtualizationDraw()
{
    
    
    // Clear window
    gl::setViewport( getWindowBounds() );
    gl::clear( ColorA(0, 0, 0, 0.0) );
    
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    gl::pushMatrices();
    
    drawHands();
    
    gl::popMatrices();
    glPopAttrib();
    
    gl::color(ColorA(0, 0, 0,1));
    if (!showParams)
        return;
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    mParams->draw();
    glPopAttrib();

}

void LeapMotionMain::cameraDraw(){

}
void LeapMotionMain::update()
{
    if (isPause) {
        return;
    }
    if (isPlayingRecording) {
        std::cout << "CurrentIndex :" << recordingFrameIndex <<std::endl;
        if (recordingFrameIndex >= deserializedFrames.size()-1) {
            recordingFrameIndex =  0;
        }else{
            recordingFrameIndex++;
        }
    }else{
       mLeap->update();
    }
    //std::cout << "frame" <<std::endl;
    
}

void LeapMotionMain::onFrame( Leap::Frame frame )
{
    mFrame = frame;
    
	//Update Frequency
	std::stringstream string1; string1 << "Label='DeviceFrequency:" << mLeap->returnDeviceFrequency() << "'";
	mParams->setOptions("DeviceFrequency",string1.str());

    //std::cout << "calback" <<std::endl;
    
    
    if (!frame.hands().isEmpty()) {
        // Get the first hand
        const Hand hand = frame.hands()[0];
        const Hand hand2 = frame.hands()[1];
        
        // Get the hand's normal vector and direction
        const Vector normal = hand.palmNormal();
        const Vector direction = hand.direction();
        const Vector position = hand.palmPosition();
        
        const Vector normal2 = hand2.palmNormal();
        const Vector direction2 = hand2.direction();
        const Vector position2 = hand2.palmPosition();
    }
    
    
    
}

void LeapMotionMain::setupGui()
{
    std::cout << "Init GUI" <<std::endl;
    mParams = cinder::params::InterfaceGl::create(getWindowIndex(0),"Parameters", Vec2i(300,250));

	mParams->addText("DeviceFrequency","Lable='DeviceFrequency:'");
    mParams->addParam ("Scene Rotation", &mObjOrientation);
    mParams->addParam ("Hand Translation", &mTranslate);
    mParams->addParam ("Hand Scale", &mScale);
    mParams->addParam ("Static Hand Orientation", &mStaticOrientHand);
    mParams->addParam ("Static Hand Position", &mStaticPosHand);
    mParams->addSeparator();
    mParams->addButton("StartRecording", std::bind(&LeapMotionMain::StartRecording,this));
    
    
	mLeftHandInfo = cinder::params::InterfaceGl::create(getWindowIndex(0),"Left Hand Information", Vec2i(300, 200));
    mLeftHandInfo->addText("LeftHandPosition","Label='Position:'");
    mLeftHandInfo->addText("LeftHandV","Label='Velocity:'");
    mLeftHandInfo->addText("Confidence","Label='ConfidenceLevel:'");
    
	mRightHandInfo = cinder::params::InterfaceGl::create(getWindowIndex(0),"Right Hand Information", Vec2i(300, 200));
    mRightHandInfo->addText("RightHandPosition","Label='Position:'");
    mRightHandInfo->addText("RightHandV","Label='Velocity:'");
    mRightHandInfo->addText("Confidence","Label='ConfidenceLevel:'");
    
    //TwDefine(" Parameters color='0 128 255' alpha=255 ");
    TwDefine(" Parameters/'Scene Rotation' opened=true ");
    TwDefine(" Parameters/'Hand Translation' opened=false ");
    TwDefine(" Parameters position='10 10'");
    TwDefine(" 'Left Hand Information' position='10 260'");
    TwDefine(" 'Right Hand Information' position='10 460'");
	
}


void LeapMotionMain::setup()
{
	//setUpCamera Window
	//cameraWindow = createWindow(Window::Format().size(600, 600));
	//cameraWindow->setPos(getWindowIndex(0)->getPos() - Vec2i(630, 0));
	//cameraWindow->connectDraw(&LeapMotionMain::cameraDraw, this);
	//mCanonView = CanonView::create(CanonView::Settings().height(600).width(600).window(cameraWindow));

	//cameraWindow->connectDraw(&LeapMotionMain::draw, this);
	getWindowIndex(0)->connectDraw(&LeapMotionMain::virtualizationDraw, this);
	
    recordingFrameIndex = 0;
    isPlayingRecording = false;
    isPause = false;
    
    mStaticOrientHand = false;
    mStaticPosHand = false;
    
    mScale = 1;
    mTranslate.set(0,200,0);
    
    showParams = TRUE;
    // Set up OpenGL
    gl::enableAlphaBlending();
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
    // Set up camera
    mCamera = CameraPersp( getWindowWidth(), getWindowHeight(), 60.0f, 0.01f, 5000.0f );
    mCamera.lookAt( Vec3f( 0.0f, 500.0f, 500.0f ), Vec3f( 0.0f, 250.0f, 0.0f ) );
    setupGui();
    // Start device
    mLeap = LeapMotion::Device::create();
    mLeap->connectEventHandler( &LeapMotionMain::onFrame, this );
    
}

void LeapMotionMain::CallDeviceUpdate(){
    mLeap->update();
}

void LeapMotionMain::StartRecording(){
    //mLeap->outPutRecordingFile();
    if ((mLeap->isRecording())) {
        mLeap->outPutRecordingFile();
        mParams->setOptions("StartRecording","Label='StartRecording'");
    }else{
        mLeap->startRecording();
        mParams->setOptions("StartRecording","Label='StopRecording'");
    }
}

void LeapMotionMain::keyDown( KeyEvent event )
{
    if(event.getChar() == 'g')
    {
        showParams = !showParams;
    }else if(event.getChar() == 'q'){
        App::get()->quit();
    }else if(event.getChar() == 'R'){
        StartRecording();
    }else if(event.getChar() == 'p'){
        isPause = !isPause;
    }else if(event.getCode() == KeyEvent::KEY_LEFT){
        std::cout << "left press"<<std::endl;
        recordingFrameIndex --; if(recordingFrameIndex < 0) recordingFrameIndex = 0;
    }else if(event.getCode() == KeyEvent::KEY_RIGHT){
        recordingFrameIndex ++; if(recordingFrameIndex > deserializedFrames.size()-1) recordingFrameIndex = deserializedFrames.size()-1;
    }
}

void LeapMotionMain::fileDrop(cinder::app::FileDropEvent event){
    deserializedFrames.clear();
    std::string inFilename = event.getFile(0).string();
	//FILE* fp = fopen(inFilename.c_str(), "rb");
	//if (fp) {
	//	long frame_size;
	//	while (fread(&frame_size, sizeof(long), 1, fp) == 1) {
	//		char* data = (char*)malloc(frame_size*sizeof(char));
	//		Leap::Frame newFrame;
	//		newFrame.deserialize(std::string(data, frame_size));
	//		deserializedFrames.push_back(newFrame);
	//	}

	//	fclose(fp);
	//	
	//}
	//else {

	//}
	
    std::ifstream in(inFilename, std::fstream::in);
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
            if(newFrame.isValid()) deserializedFrames.push_back(newFrame);
            in >> nextBlockSize;
        }
        in.close();
    }
    else if(errno){
        std::cout << "Error: " << errno << std::endl;
        std::cout << "Couldn't open " << inFilename << " for reading." << std::endl;
    }
    std::cout << deserializedFrames.size() << std::endl;
	_RPT1(_CRT_WARN, "\n Size---%s", deserializedFrames.size());
    isPause = true;
    isPlayingRecording = true;
}

void LeapMotionMain::connectWindow(ci::app::WindowRef window)
{

}

CINDER_APP_BASIC( LeapMotionMain, RendererGl )


