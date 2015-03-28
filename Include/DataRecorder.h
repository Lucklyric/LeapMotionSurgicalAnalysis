//
//  DataRecorder.h
//  LeapMotion
//
//  Created by Alvin Sun on 2015-01-28.
//
//

#ifndef LeapMotion_DataRecorder_h
#define LeapMotion_DataRecorder_h

#include <iostream>
#include <fstream>
#include "Leap.h"
#include <functional>
using namespace std;
class DataRecorder{
public:
    bool isWriting;
    string currentFileName;
    string currentLeftHandFileName;
    string currentRighthandFileName;
    long int currentFrameIndex;
	long int leftHandId;
	long int rightHandId;
    DataRecorder();
    void ParseCurrentFrametoFile(Leap::Frame currentFrame);
    void EndReocrding();
    void WriteToLeftHandFile(Leap::Hand leftHand);
    void WriteToRightHandFile(Leap::Hand rightHand);
    void InitHandMotionTxtFile(string filename);
    string ParseOneRowHandInformation(Leap::Hand hand);
};

#endif
