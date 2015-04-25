%Draw Data

%DiscreteForCase2 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case2\Output\RgithHand-2015-4-5-14-45-50.txt');
DiscreteForCase3 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case3\Output\RgithHand-2015-4-10-12-54-55.txt');
DiscreteForCase4 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case4\Output\RgithHand-2015-4-10-12-55-30.txt');
DiscreteForCase5 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case5\Output\RgithHand-2015-4-10-12-55-56.txt');
DiscreteForCase6 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case6\Output\RgithHand-2015-4-10-12-51-44.txt');
DiscreteForCase7 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case7\Output\RgithHand-2015-4-10-12-56-45.txt');
DiscreteForCase8 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case8\Output\RgithHand-2015-4-10-12-57-18.txt');
DiscreteForCase9 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case9\Output\RgithHand-2015-4-10-12-57-42.txt');
DiscreteForCase10 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case11\Output\RgithHand-2015-4-10-13-0-55.txt');
%Test Train Part
%Case2_RawObserve = transp([DiscreteForCase2{1};DiscreteForCase2{2};DiscreteForCase2{4}]);
Case3_RawObserve = transp([DiscreteForCase3{1};DiscreteForCase3{2};DiscreteForCase3{4}]);
Case4_RawObserve = transp([DiscreteForCase4{1};DiscreteForCase4{2};DiscreteForCase4{4}]);
Case5_RawObserve = transp([DiscreteForCase5{1};DiscreteForCase5{2};DiscreteForCase5{4}]);
Case6_RawObserve = transp([DiscreteForCase6{1};DiscreteForCase6{2};DiscreteForCase6{4}]);
Case7_RawObserve = transp([DiscreteForCase7{1};DiscreteForCase7{2};DiscreteForCase7{4}]);
Case8_RawObserve = transp([DiscreteForCase8{1};DiscreteForCase8{2};DiscreteForCase8{4}]);
Case9_RawObserve = transp([DiscreteForCase9{1};DiscreteForCase9{2};DiscreteForCase9{4}]);
Case10_RawObserve = transp([DiscreteForCase10{1};DiscreteForCase10{2};DiscreteForCase10{4}]);

%Build HMM For Case3
Prior = zeros(1,8);
Prior(1) = 1;
TRANS = GetTransitionMatrix(10);
[EMIS,Case3_C] = GetObjservationMatrix(3,0,DiscreteForCase3);
Case3ObSequence = EstObservationSequence(Case3_RawObserve,Case3_C);
Case4ObSequence = EstObservationSequence(Case4_RawObserve,Case3_C);
Case5ObSequence = EstObservationSequence(Case5_RawObserve,Case3_C);
Case6ObSequence = EstObservationSequence(Case6_RawObserve,Case3_C);
Case7ObSequence = EstObservationSequence(Case7_RawObserve,Case3_C);


%Case2ObSequence = EstObservationSequence(Case2_RawObserve,Case3_C);
Case8ObSequence = EstObservationSequence(Case8_RawObserve,Case3_C);
Case9ObSequence = EstObservationSequence(Case9_RawObserve,Case3_C);
Case10ObSequence = EstObservationSequence(Case10_RawObserve,Case3_C);

%  Case3ObSequence = [Case3ObSequence,];
%  Case4ObSequence = [Case4ObSequence,Case4ObSequence,Case4ObSequence];
%  Case5ObSequence = [Case5ObSequence,Case5ObSequence,Case5ObSequence];
%  Case6ObSequence = [Case6ObSequence,Case6ObSequence,Case6ObSequence];
%  Case7ObSequence = [Case7ObSequence,Case7ObSequence,Case7ObSequence];
%  Case8ObSequence = [Case8ObSequence,Case8ObSequence,Case8ObSequence];
%  Case9ObSequence = [Case9ObSequence,Case9ObSequence,Case9ObSequence];
%  Case10ObSequence = [Case10ObSequence,Case10ObSequence,Case10ObSequence];


[TRANS,EMIS]=hmmtrain([Case3ObSequence,Case4ObSequence,Case5ObSequence,Case6ObSequence],TRANS,EMIS);
%[LL1,Prior,TRANS,EMIS]=learn_dhmm([Case4ObSequence,Case5ObSequence,Case6ObSequence],Prior,TRANS,EMIS,5);
%[LL2,Prior,TRANS,EMIS]=learn_dhmm(Case5ObSequence,Prior,TRANS,EMIS,5);
%[LL3,Prior,TRANS,EMIS]=learn_dhmm(Case6ObSequence,Prior,TRANS,EMIS,5);
% [LL, Prior, TRANS, EMIS] = dhmm_em([Case4ObSequence,Case5ObSequence,Case6ObSequence], Prior, TRANS, EMIS, 'max_iter', 1000);
Dis5 = CalCulateDistance(TRANS,EMIS,Case5ObSequence);
%Dis6 = CalCulateDistance(TRANS,EMIS,Case6ObSequence);
Dis7 = CalCulateDistance(TRANS,EMIS,Case7ObSequence);
Dis8 = CalCulateDistance(TRANS,EMIS,Case8ObSequence);
Dis9 = CalCulateDistance(TRANS,EMIS,Case9ObSequence);
Dis10 = CalCulateDistance(TRANS,EMIS,Case10ObSequence);

DisArray = [Dis5,Dis7,Dis8,Dis9,Dis10];
NorDis =  (DisArray-min(DisArray))/(max(DisArray)-min(DisArray));