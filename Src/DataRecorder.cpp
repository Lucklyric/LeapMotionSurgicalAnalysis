//
//  DataRecorder.cpp
//  LeapMotion
//
//  Created by Alvin Sun on 2015-01-28.
//
//

#include <stdio.h>
#include "DataRecorder.h"
#include "Leap.h"
#include "Cinder-LeapMotion.h"
#include <functional>
#include <Windows.h>
#include <filesystem>
#include <boost\filesystem.hpp>
using namespace std;

DataRecorder::DataRecorder(){
    this->isWriting = false;
    this->currentFileName = "";
    this->currentFrameIndex = 0;
	this->leftHandId = 0;
	this->rightHandId = 0;
}

void DataRecorder::ParseCurrentFrametoFile(Leap::Frame currentFrame){
	if (!isWriting){
	
		boost::filesystem::create_directory(boost::filesystem::current_path() / "Output");
        time_t t = time(0);   // get time now
		struct tm now;
		localtime_s( &now,& t );
        stringstream ss;
        stringstream ssLeapData;
        stringstream ssLeftHandData;
        stringstream ssRightHandData;
        ss << (now.tm_year + 1900) << '-'
        << (now.tm_mon + 1) << '-'
        <<  now.tm_mday << '-' << now.tm_hour << '-' << now.tm_min << '-' << now.tm_sec;
		string path = boost::filesystem::current_path().string();
        ssLeapData <<path<<"/Output/"<<ss.str()<<".data";
		ssLeftHandData <<path<< "/Output/" << "LeftHand-" << ss.str() << ".txt";
		ssRightHandData <<path<< "/Output/" << "RgithHand-" << ss.str() << ".txt";
        currentFileName = ssLeapData.str();
        currentLeftHandFileName = ssLeftHandData.str();
        currentRighthandFileName = ssRightHandData.str();
        InitHandMotionTxtFile(currentLeftHandFileName);
        InitHandMotionTxtFile(currentRighthandFileName);
        isWriting = true;
        currentFrameIndex = 0;
    }
    fstream out(currentFileName, std::ios_base::app | std::ios_base::out);
    if(out)
    {
        Leap::Frame frameToSerialize = currentFrame;
        std::string serialized = frameToSerialize.serialize();
		out << (long)serialized.length() << serialized;
        out.flush();
        out.close();
    }
    else if(errno) {
        std::cout << "Error: " << errno << std::endl;
        std::cout << "Couldn't open " << currentFileName << " for writing." << std::endl;
    }
    const Leap::HandList& hands = currentFrame.hands();
    for ( Leap::HandList::const_iterator handIter = hands.begin(); handIter != hands.end(); ++handIter ) {
        Leap::Hand hand = *handIter;
        if (hand.isLeft()){
			if (this->leftHandId == 0){
				this->leftHandId = hand.id();
				WriteToLeftHandFile(hand);
			}
			else{
				if (this->leftHandId == hand.id()){
					WriteToLeftHandFile(hand);
				}
			}
        }else{
			if (this->rightHandId == 0){
				this->rightHandId = hand.id();
				WriteToRightHandFile(hand);
			}
			else{
				if (this->rightHandId == hand.id()){
					WriteToRightHandFile(hand);
				}
			}
        }
    }
}

void DataRecorder::EndReocrding(){
    this->isWriting = false;
	this->leftHandId = 0;
	this->rightHandId = 0;
}

string DataRecorder::ParseOneRowHandInformation(Leap::Hand hand){
    cinder::Vec3f handDir		= LeapMotion::toVec3f( hand.direction() );
    cinder::Vec3f palmNorm		= LeapMotion::toVec3f( hand.palmNormal() );
    cinder::Vec3f palmPos		= LeapMotion::toVec3f( hand.palmPosition() );
    cinder::Vec3f palmVel		= LeapMotion::toVec3f( hand.palmVelocity() );



    std::stringstream oneRowString;
    oneRowString << handDir.x << " " << handDir.y << " " << handDir.z << " " << palmNorm.x << " " << palmNorm.y << " " << palmNorm.z << " " << palmPos.x << " " << palmPos.y << " " << palmPos.z <<" " << palmVel.x << " " << palmVel.y << " " << palmVel.z << " " << hand.confidence();
    

    return oneRowString.str();
    
}

void DataRecorder::WriteToLeftHandFile(Leap::Hand leftHand){
	FILETIME filetime;
	GetSystemTimeAsFileTime(&filetime);
	ULONGLONG time;
	time = ((((ULONGLONG)filetime.dwHighDateTime) << 32) + filetime.dwLowDateTime) / 10000;
    fstream out(currentLeftHandFileName, std::ios_base::app | std::ios_base::out);
    if(out)
    {
        out << time <<"  " <<leftHand.frame().timestamp() <<"  "<< leftHand.frame().id() << "  "<< ParseOneRowHandInformation(leftHand) << std::endl;
        out.flush();
        out.close();
    }
    else if(errno) {
        std::cout << "Error: " << errno << std::endl;
        std::cout << "Couldn't open " << currentFileName << " for writing." << std::endl;
    }

}

void DataRecorder::WriteToRightHandFile(Leap::Hand rightHand){
	FILETIME filetime;
	GetSystemTimeAsFileTime(&filetime);
	ULONGLONG time;
	time = ((((ULONGLONG)filetime.dwHighDateTime) << 32) + filetime.dwLowDateTime)/10000;
    fstream out(currentRighthandFileName, std::ios_base::app | std::ios_base::out);
    if(out)
    {
		out << time << " " << rightHand.frame().timestamp() << "  " << rightHand.frame().id() << "  " << ParseOneRowHandInformation(rightHand) << std::endl;
        out.flush();
        out.close();
    }
    else if(errno) {
        std::cout << "Error: " << errno << std::endl;
        std::cout << "Couldn't open " << currentFileName << " for writing." << std::endl;
    }
}

void DataRecorder::InitHandMotionTxtFile(string filename){
    fstream out(filename, std::ios_base::app | std::ios_base::out);
    if(out)
    {
        out << "SoftwareTimeStamp" << " "<<"LeapTimeStamp" <<"  "<< "FrameID" << "  "<< "HandDirection:X" << " " << "HandDirection:Y" << " "<<"HandDirection:Z" << "  "<< "PalmNorm:X" << " " << "PalmNorm:Y" << " "<<"PalmNorm:Z"<< "  "<< "PalmPos:X" << " " << "PalmPos:Y" << " "<<"PalmPos:Z"<<  "  "<< "PalmVel:X" << " " << "PalmVel:Y" << " "<<"PalmVel:Z" << " " << "Confidence" << std::endl;
        out.flush();
        out.close();
    }
    else if(errno) {
        std::cout << "Error: " << errno << std::endl;
        std::cout << "Couldn't open " << currentFileName << " for writing." << std::endl;
    }

}
