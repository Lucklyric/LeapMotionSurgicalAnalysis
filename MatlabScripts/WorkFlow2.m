OneHandCase1 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\OneHandCase1\Motion.txt');
OneHandCase2 = DataProcessing('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\OneHandCase2\Motion.txt');
OneHandCase1_RawPosObserve = transp([OneHandCase1{8};OneHandCase1{9};OneHandCase1{10}]);
OneHandCase2_RawPosObserve = transp([OneHandCase2{8};OneHandCase2{9};OneHandCase2{10}]);

OneHandCase1_PathLength = CalculatePathLength(OneHandCase1_RawPosObserve);
OneHandCase2_PathLength = CalculatePathLength(OneHandCase1_RawPosObserve);

OneHandCase1_RawVelObserve = transp([OneHandCase1{1};OneHandCase1{2};OneHandCase1{3}]);
OneHandCase2_RawVelObserve = transp([OneHandCase2{1};OneHandCase2{2};OneHandCase2{3}]);

%OneHandCase1_NumOfMovs = CalculateNumOfMovements(OneHandCase1_RawVelObserve);

OneHandCase2_NumOfMovs = CalculateNumOfMovements(OneHandCase2_RawVelObserve);