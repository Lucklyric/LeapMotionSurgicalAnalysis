OneHandCase1 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Version2\R2\Case2\OneHand\Motions.txt');
OneHandCase2 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Version2\Staff\Case3\OneHand\Motions.txt');
TwoHandCase1 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Version2\R2\Case2\TwoHand\Motions.txt');
TwoHandCase2 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Version2\Staff\Case3\TwoHands\Motions.txt');


OneHandCase1_RawPosObserve = transp([OneHandCase1{8};OneHandCase1{9};OneHandCase1{10}]);
OneHandCase2_RawPosObserve = transp([OneHandCase2{8};OneHandCase2{9};OneHandCase2{10}]);
TwoHandCase1_RawPosObserve = transp([TwoHandCase1{8};TwoHandCase1{9};TwoHandCase1{10}]);
TwoHandCase2_RawPosObserve = transp([TwoHandCase2{8};TwoHandCase2{9};TwoHandCase2{10}]);

OneHandCase1_Time = OneHandCase1{5}(end)- OneHandCase1{5}(1);
OneHandCase2_Time = OneHandCase2{5}(end)- OneHandCase2{5}(1);
TwoHandCase1_Time = TwoHandCase1{5}(end)- TwoHandCase1{5}(1);
TwoHandCase2_Time = TwoHandCase2{5}(end)- TwoHandCase2{5}(1);


OneHandCase1_PathLength = CalculatePathLength(OneHandCase1_RawPosObserve);
OneHandCase2_PathLength = CalculatePathLength(OneHandCase2_RawPosObserve);
TwoHandCase1_PathLength = CalculatePathLength(TwoHandCase1_RawPosObserve);
TwoHandCase2_PathLength = CalculatePathLength(TwoHandCase2_RawPosObserve);

OneHandCase1_RawVelObserve = transp([OneHandCase1{1};OneHandCase1{2};OneHandCase1{3}]);
OneHandCase2_RawVelObserve = transp([OneHandCase2{1};OneHandCase2{2};OneHandCase2{3}]);
TwoHandCase1_RawVelObserve = transp([TwoHandCase1{1};TwoHandCase1{2};TwoHandCase1{3}]);
TwoHandCase2_RawVelObserve = transp([TwoHandCase2{1};TwoHandCase2{2};TwoHandCase2{3}]);

[OneHandCase1_NumOfMovs,OneHandCase1_MeanArray,OneHandCase1_TangV] = CalculateNumOfMovements(OneHandCase1_RawVelObserve);
[OneHandCase2_NumOfMovs,OneHandCase2_MeanArray,OneHandCase2_TangV] = CalculateNumOfMovements(OneHandCase2_RawVelObserve);
[TwoHandCase1_NumOfMovs,TwoHandCase1_MeanArray,TwoHandCase1_TangV]= CalculateNumOfMovements(TwoHandCase1_RawVelObserve);
[TwoHandCase2_NumOfMovs,TwoHandCase2_MeanArray,TwoHandCase2_TangV] = CalculateNumOfMovements(TwoHandCase2_RawVelObserve);
% % figure;
% subplot(1,2,1),
% plot(TwoHandCase1_MeanArray,'DisplayName','OneHandCase1_MeanArray');hold on;plot(TwoHandCase1_TangV,'DisplayName','OneHandCase1_TangV');hold off;
% subplot(1,2,2),
% plot(TwoHandCase2_MeanArray,'DisplayName','OneHandCase1_MeanArray');hold on;plot(TwoHandCase2_TangV,'DisplayName','OneHandCase1_TangV');hold off;

