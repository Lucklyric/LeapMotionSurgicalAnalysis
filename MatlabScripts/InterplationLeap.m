% Leap Motion Data Processing Script


% Load raw data from text (ASCII) file
format long; 
%Left hand raw data Sample1
Lraw = importdata('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case2\Output\RgithHand-2015-4-5-14-45-50.txt',' ',1); %imports data and ignores first row (headers)
%Left hand raw data Sample2

% Define the fixed timeinterval in microseconds
frequency = 60; %preset variable


LrawX = Lraw.data(1:end,10);
LrawX = (LrawX - LrawX(1,1));

LrawY = Lraw.data(1:end,11);
LrawY = (LrawY - LrawY(1,1));

LrawZ = Lraw.data(1:end,12);
LrawZ = (LrawZ - LrawZ(1,1));

LrawTime = Lraw.data(1:end,2);


interpX=[];
interpY=[];
interpZ=[];
interpTime=[];
index = 0;
currentTimeStamp = 0;
while currentTimeStamp < LrawTime(end)
   currentTimeStamp = LrawTime(1) + (index * (1/frequency) * 1000000); 
   interpX(index+1) = interp1(LrawTime,LrawX,currentTimeStamp,'spline');
   interpY(index+1) = interp1(LrawTime,LrawY,currentTimeStamp,'spline');
   interpZ(index+1) = interp1(LrawTime,LrawZ,currentTimeStamp,'spline');
   interpTime(index+1) = currentTimeStamp;
   index = index+1;
end

% Read coordinate data (PalmX, PalmY, PalmZ)
xL = interpX;   
yL = interpY;
zL = interpZ;


% Define time based on timestamp in microseconds

timemicro = interpTime;        %timestamp in first column          
time = (timemicro - interpTime(1,1))/1000000;   %subtracts first timestamp from subsequent and converts microseconds to seconds



% Plot x, y, z data
% figure; 
% plot(time, xL);  %PalmX vs time
% xlabel('time');
% ylabel('x position - unfiltered');
% 
% figure; 
% plot(time, yL);  %PalmY vs time
% xlabel('time');
% ylabel('y position - unfiltered');
% 
% figure; 
% plot(time, zL);  %PalmZ vs time
% xlabel('time');
% ylabel('z position - unfiltered');

%generate 3D plot of position data
% figure;
% plot3(xL,yL,zL);     
% grid on
% box on
% xlabel('x','rotation',0);
% ylabel('y','rotation',0);
% zlabel('z','rotation',0);
% title('3D position data');

% Filtering Algorithm
cutoff = 10;   %Frequency cutoff in Hz
samplerate = 60;  %Samplerate in Hz
Wn = cutoff / (samplerate/2);
[B,A] = butter (2,Wn);
xL_filtered = filtfilt (B,A,xL);
yL_filtered = filtfilt (B,A,yL);
zL_filtered = filtfilt (B,A,zL);

%Plot filtered data
figure;
subplot(2,2,1),plot(time, xL_filtered);
xlabel('time');
ylabel('x position - filtered');
title('X position data - filtered');

%figure;
subplot(2,2,2),plot(time, yL_filtered);
xlabel('time');
ylabel('y position - filtered');
title('Y position data - filtered');

%figure;
subplot(2,2,3),plot(time, zL_filtered);
xlabel('time');
ylabel('z position - filtered');
title('Z position data - filtered');

%Plot filterd 3D data
%figure;
subplot(2,2,4),
plot3(xL_filtered,yL_filtered,zL_filtered);     
grid on
box on
xlabel('x ','rotation',0);
ylabel('y','rotation',0);
zlabel('z','rotation',0);
title('3D position data - filtered');