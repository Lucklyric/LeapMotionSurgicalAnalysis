%Draw Data

%DiscreteForCase2 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case2\Output\RgithHand-2015-4-5-14-45-50.txt');
% DiscreteForCase3 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case3\Output\RgithHand-2015-4-10-12-54-55.txt');
% DiscreteForCase4 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case4\Output\RgithHand-2015-4-10-12-55-30.txt');
% DiscreteForCase5 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case5\Output\RgithHand-2015-4-10-12-55-56.txt');
% DiscreteForCase6 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case6\Output\RgithHand-2015-4-10-12-51-44.txt');
% DiscreteForCase7 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case7\Output\RgithHand-2015-4-10-12-56-45.txt');
% DiscreteForCase8 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case8\Output\RgithHand-2015-4-10-12-57-18.txt');
% DiscreteForCase9 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case9\Output\RgithHand-2015-4-10-12-57-42.txt');
% DiscreteForCase10 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case11\Output\RgithHand-2015-4-10-13-0-55.txt');
% %Test Train Part
DiscreteForCase1 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\E1\Rmotion.txt');
DiscreteForCase2 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\E2\Rmotion.txt');
DiscreteForCase3 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\E3\Rmotion.txt');
DiscreteForCase4 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\E4\Rmotion.txt');
DiscreteForCase5 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\E5\Rmotion.txt');
DiscreteForCase6 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\E6\Rmotion.txt');
DiscreteForCase7 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\N7\Rmotion.txt');
DiscreteForCase8 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\N8\Rmotion.txt');
DiscreteForCase9 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\N9\Rmotion.txt');


Case1_RawObserve = transp([DiscreteForCase1{1};DiscreteForCase1{2};DiscreteForCase1{4}]);
Case2_RawObserve = transp([DiscreteForCase2{1};DiscreteForCase2{2};DiscreteForCase2{4}]);
Case3_RawObserve = transp([DiscreteForCase3{1};DiscreteForCase3{2};DiscreteForCase3{4}]);
Case4_RawObserve = transp([DiscreteForCase4{1};DiscreteForCase4{2};DiscreteForCase4{4}]);
Case5_RawObserve = transp([DiscreteForCase5{1};DiscreteForCase5{2};DiscreteForCase5{4}]);
Case6_RawObserve = transp([DiscreteForCase6{1};DiscreteForCase6{2};DiscreteForCase6{4}]);
Case7_RawObserve = transp([DiscreteForCase7{1};DiscreteForCase7{2};DiscreteForCase7{4}]);
Case8_RawObserve = transp([DiscreteForCase8{1};DiscreteForCase8{2};DiscreteForCase8{4}]);
Case9_RawObserve = transp([DiscreteForCase9{1};DiscreteForCase9{2};DiscreteForCase9{4}]);


%Build HMM For Case3
Prior = zeros(1,6);
Prior(1) = 1;
TRANS = GetTransitionMatrix(10);
[EMIS,Case1_C] = GetObjservationMatrix(2,0,DiscreteForCase1);
Case1ObSequence = EstObservationSequence(Case1_RawObserve,Case1_C);
Case2ObSequence = EstObservationSequence(Case2_RawObserve,Case1_C);
Case3ObSequence = EstObservationSequence(Case3_RawObserve,Case1_C);
Case4ObSequence = EstObservationSequence(Case4_RawObserve,Case1_C);
Case5ObSequence = EstObservationSequence(Case5_RawObserve,Case1_C);
Case6ObSequence = EstObservationSequence(Case6_RawObserve,Case1_C);



Case7ObSequence = EstObservationSequence(Case7_RawObserve,Case1_C);
Case8ObSequence = EstObservationSequence(Case8_RawObserve,Case1_C);
Case9ObSequence = EstObservationSequence(Case9_RawObserve,Case1_C);



[TRANS,EMIS]=hmmtrain([Case1ObSequence,Case2ObSequence,Case3ObSequence],TRANS,EMIS);



Dis4 = CalCulateDistance(TRANS,EMIS,Case4ObSequence);
Dis5 = CalCulateDistance(TRANS,EMIS,Case5ObSequence);
Dis6 = CalCulateDistance(TRANS,EMIS,Case6ObSequence);
Dis7 = CalCulateDistance(TRANS,EMIS,Case7ObSequence);
Dis8 = CalCulateDistance(TRANS,EMIS,Case8ObSequence);
Dis9 = CalCulateDistance(TRANS,EMIS,Case9ObSequence);


DisArray = [Dis4,Dis5,Dis6,Dis7,Dis8,Dis9];
NorDis =  (DisArray-min(DisArray))/(max(DisArray)-min(DisArray));