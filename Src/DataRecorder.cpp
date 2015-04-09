//
//  DataRecorder.cpp
//  LeapMotion
//
//  Created by Alvin Sun on 2015-01-28.
//
//

#include "DataRecorder.h"
#include "Leap.h"
#include "Cinder-LeapMotion.h"
#include <functional>
#include <Windows.h>
#include <filesystem>
#include <boost\filesystem.hpp>

using namespace std;
std::string string_To_UTF8(const std::string & str)
{
	int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t * pwBuf = new wchar_t[nwLen + 1];//һ��Ҫ��1����Ȼ�����β��  
	ZeroMemory(pwBuf, nwLen * 2 + 2);

	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);

	int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);

	char * pBuf = new char[nLen + 1];
	ZeroMemory(pBuf, nLen + 1);

	::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);

	std::string retStr(pBuf);

	delete[]pwBuf;
	delete[]pBuf;

	pwBuf = NULL;
	pBuf = NULL;

	return retStr;
}


DataRecorder::DataRecorder(){
    this->isWriting = false;
    this->currentFileName = "";
    this->currentFrameIndex = 0;
	this->leftHandId = 0;
	this->rightHandId = 0;
}

void DataRecorder::ParseCurrentFrametoFile(Leap::Frame currentFrame,int flag){
	//lock_guard<mutex> lock(mMutex);
	//cout <<"recording id"<<std::this_thread::get_id() << endl;
	if (!isWriting){
		if (flag == 0)
		{
			boost::filesystem::create_directory(boost::filesystem::current_path() / "FixedOutput");
		}else if(flag == 1){
			boost::filesystem::create_directory(boost::filesystem::current_path() / "Output");
		}
		else if (flag == 2){
			boost::filesystem::create_directory(boost::filesystem::current_path() / "ReOutput");
		}
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
		if (flag == 0)
		{
			ssLeapData << path << "/FixedOutput/" << ss.str() << ".data";
			ssLeftHandData << path << "/FixedOutput/" << "LeftHand-" << ss.str() << ".txt";
			ssRightHandData << path << "/FixedOutput/" << "RgithHand-" << ss.str() << ".txt";
		}else if(flag == 1){
			ssLeapData << path << "/Output/" << ss.str() << ".data";
			ssLeftHandData << path << "/Output/" << "LeftHand-" << ss.str() << ".txt";
			ssRightHandData << path << "/Output/" << "RgithHand-" << ss.str() << ".txt";
			cout << "out put else"<< endl;
		}
		else if (flag == 2){
			ssLeapData << path << "/ReOutput/" << ss.str() << ".data";
			ssLeftHandData << path << "/ReOutput/" << "LeftHand-" << ss.str() << ".txt";
			ssRightHandData << path << "/ReOutput/" << "RgithHand-" << ss.str() << ".txt";
			cout << "Re out put motion data" << endl;
		}
        currentFileName = ssLeapData.str();
        currentLeftHandFileName = ssLeftHandData.str();
        currentRighthandFileName = ssRightHandData.str();
        InitHandMotionTxtFile(currentLeftHandFileName);
        InitHandMotionTxtFile(currentRighthandFileName);
        isWriting = true;
        currentFrameIndex = 0;
    }
	std::fstream out(currentFileName, std::ios_base::app | std::ios_base::out |std::ios::binary);

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
	/*
	*Check if has some hand lost 
	*/
	bool hasLeft = false;
	bool hasRight = false;
	for (Leap::HandList::const_iterator handIter = hands.begin(); handIter != hands.end(); ++handIter) {
		Leap::Hand hand = *handIter;
		if (hand.isLeft())
		{
			hasLeft = true;
		}
		else
		{
			hasRight = true;
		}
	}
	if (!hasLeft)
	{
		this->leftHandId = 0;
	}
	
	if (!hasRight)
	{
		this->rightHandId = 0;
	}
	


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
	cinder::Vec3f sphereCenter  = LeapMotion::toVec3f( hand.sphereCenter() );
	float sphereRadius = hand.sphereRadius();


	

    std::stringstream oneRowString;
    oneRowString << handDir.x << " " << handDir.y << " " << handDir.z 
		<< " " << palmNorm.x << " " << palmNorm.y << " " << palmNorm.z 
		<< " " << palmPos.x << " " << palmPos.y << " " << palmPos.z 
		<< " " << palmVel.x << " " << palmVel.y << " " << palmVel.z 
		<< " " << sphereRadius << " " << hand.confidence();
    

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
        out << time <<"  " <<leftHand.frame().timestamp() <<"  "<< leftHand.frame().id() 
			<< "  "<< ParseOneRowHandInformation(leftHand) << std::endl;
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
		out << time << " " << rightHand.frame().timestamp() << "  " << rightHand.frame().id() 
			<< "  " << ParseOneRowHandInformation(rightHand) << std::endl;
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
        out << "SoftwareTimeStamp" << " "<<"LeapTimeStamp" <<"  "<< "FrameID" 
			<< "  "<< "HandDirection:X" << " " << "HandDirection:Y" << " "<<"HandDirection:Z" 
			<< "  "<< "PalmNorm:X" << " " << "PalmNorm:Y" << " "<<"PalmNorm:Z"<< "  "<< "PalmPos:X" 
			<< " " << "PalmPos:Y" << " "<<"PalmPos:Z"<<  "  "<< "PalmVel:X" << " " << "PalmVel:Y" 
			<< " "<<"PalmVel:Z" << " " <<"SphereRadius"<< " "<< "Confidence" << std::endl;
        out.flush();
        out.close();
    }
    else if(errno) {
        std::cout << "Error: " << errno << std::endl;
        std::cout << "Couldn't open " << currentFileName << " for writing." << std::endl;
    }

}
