%Draw Data
DiscreteForCase3 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case3\Output\RgithHand-2015-4-5-14-49-1.txt');
DiscreteForCase2 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case2\Output\RgithHand-2015-4-5-14-45-50.txt');
DiscreteForCase4 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case4\Output\RgithHand-2015-4-8-14-44-53.txt');
DiscreteForCase5 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case5\Output\RgithHand-2015-4-8-14-47-2.txt');
DiscreteForCase6 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case6\Output\RgithHand-2015-4-8-14-48-23.txt');
DiscreteForCase7 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case7\Output\RgithHand-2015-4-8-14-49-46.txt');
DiscreteForCase8 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case8\Output\RgithHand-2015-4-8-14-51-11.txt');
DiscreteForCase9 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case9\Output\RgithHand-2015-4-8-14-52-20.txt');
DiscreteForCase10 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case10\Output\RgithHand-2015-4-8-14-54-49.txt');
%Test Train Part
Case2_RawObserve = transp([DiscreteForCase2{1};DiscreteForCase2{2};DiscreteForCase2{4}]);
Case3_RawObserve = transp([DiscreteForCase3{1};DiscreteForCase3{2};DiscreteForCase3{4}]);
Case4_RawObserve = transp([DiscreteForCase4{1};DiscreteForCase4{2};DiscreteForCase4{4}]);
Case5_RawObserve = transp([DiscreteForCase5{1};DiscreteForCase5{2};DiscreteForCase5{4}]);
Case6_RawObserve = transp([DiscreteForCase6{1};DiscreteForCase6{2};DiscreteForCase6{4}]);
Case7_RawObserve = transp([DiscreteForCase7{1};DiscreteForCase7{2};DiscreteForCase7{4}]);
Case8_RawObserve = transp([DiscreteForCase8{1};DiscreteForCase8{2};DiscreteForCase8{4}]);
Case9_RawObserve = transp([DiscreteForCase9{1};DiscreteForCase9{2};DiscreteForCase9{4}]);
Case10_RawObserve = transp([DiscreteForCase10{1};DiscreteForCase10{2};DiscreteForCase10{4}]);
%index=min(abs(transp(DiscreteForCase3{7})-DiscreteForCase3{5}((find(DiscreteForCase3{6}==251224)))));
%Case3_RawObserve = transp([DiscreteForCase3{1};DiscreteForCase3{2}]);
% Case2_RawObserve = transp([DiscreteForCase2{1};DiscreteForCase2{2}]);
%[Case3_idx,Case3_C] = kmeans(Case3_RawObserve,80);
% Trans_guess = GetTransitionMatrix(1);
% Emis_guess = GetObjservationMatrix(1);
% [Trans_est,Emis_est]=hmmtrain(Case3_idx,Trans_guess,Emis_guess);

%Build HMM For Case3
Prior = zeros(1,8);
Prior(1) = 1;
TRANS = GetTransitionMatrix(10);
[EMIS,Case3_C] = GetObjservationMatrix(3,0,DiscreteForCase3);
Case3ObSequence = EstObservationSequence(Case3_RawObserve,Case3_C);
Case4ObSequence = EstObservationSequence(Case4_RawObserve,Case3_C);
%[TRANS,EMIS]=hmmtrain(Case4ObSequence,TRANS,EMIS);
Case5ObSequence = EstObservationSequence(Case5_RawObserve,Case3_C);
%[TRANS,EMIS]=hmmtrain(Case5ObSequence,TRANS,EMIS);
Case6ObSequence = EstObservationSequence(Case6_RawObserve,Case3_C);
%[TRANS,EMIS]=hmmtrain(Case6ObSequence,TRANS,EMIS);
[TRANS,EMIS]=hmmtrain([Case3ObSequence,Case4ObSequence,Case5ObSequence,Case6ObSequence],TRANS,EMIS);
Case2ObSequence = EstObservationSequence(Case2_RawObserve,Case3_C);
Case7ObSequence = EstObservationSequence(Case7_RawObserve,Case3_C);
Case8ObSequence = EstObservationSequence(Case8_RawObserve,Case3_C);
Case9ObSequence = EstObservationSequence(Case9_RawObserve,Case3_C);
Case10ObSequence = EstObservationSequence(Case10_RawObserve,Case3_C);

%[LL1,Prior,TRANS,EMIS]=learn_dhmm([Case4ObSequence,Case5ObSequence,Case6ObSequence],Prior,TRANS,EMIS,5);
%[LL2,Prior,TRANS,EMIS]=learn_dhmm(Case5ObSequence,Prior,TRANS,EMIS,5);
%[LL3,Prior,TRANS,EMIS]=learn_dhmm(Case6ObSequence,Prior,TRANS,EMIS,5);
% [LL, Prior, TRANS, EMIS] = dhmm_em([Case4ObSequence,Case5ObSequence,Case6ObSequence], Prior, TRANS, EMIS, 'max_iter', 1000);
Dis5 = CalCulateDistance(TRANS,EMIS,Case6ObSequence);
Dis6 = CalCulateDistance(TRANS,EMIS,Case6ObSequence);
Dis7 = CalCulateDistance(TRANS,EMIS,Case7ObSequence);
Dis8 = CalCulateDistance(TRANS,EMIS,Case8ObSequence);
Dis9 = CalCulateDistance(TRANS,EMIS,Case9ObSequence);
Dis10 = CalCulateDistance(TRANS,EMIS,Case10ObSequence);

DisArray = [Dis5,Dis6,Dis7,Dis8,Dis9,Dis10];
NorDis =  (DisArray-min(DisArray))/(max(DisArray)-min(DisArray));