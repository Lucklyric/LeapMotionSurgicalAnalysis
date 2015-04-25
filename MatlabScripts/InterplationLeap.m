% Leap Motion Data Processing Script


% Load raw data from text (ASCII) file
format long; 
%Left hand raw data Sample1
Lraw = importdata('D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case3\Output\RgithHand-2015-4-10-12-54-55.txt',' ',1); %imports data and ignores first row (headers)
%Left hand raw data Sample2

% Define the fixed timeinterval in microseconds
frequency = 60; %preset variable


LrawX = Lraw.data(2:end,13);
%LrawX = (LrawX - LrawX(1,1));

LrawY = Lraw.data(2:end,14);
%LrawY = (LrawY - LrawY(1,1));

LrawZ = Lraw.data(2:end,15);
%LrawZ = (LrawZ - LrawZ(1,1));

LrawTime = Lraw.data(1:end,2);

LrawSphereSize = Lraw.data(1:end,16);

LrawSphere=zeros(numel(LrawSphereSize)-1,1);

for index=2:numel(LrawSphereSize)
    LrawSphere(index-1) = 1000000*(LrawSphereSize(index)-LrawSphereSize(index-1))/(LrawTime(index)-LrawTime(index-1));
    %LrawSphere(index-1) = LrawSphereSize(index);
end





LrawTime = LrawTime(2:end);

interpX=[];
interpY=[];
interpZ=[];
interpS=[];
interpTime=[];
index = 0;
currentTimeStamp = 0;
while currentTimeStamp < LrawTime(end)
   currentTimeStamp = LrawTime(2) + (index * (1/frequency) * 1000000); 
   interpX(index+1) = interp1(LrawTime,LrawX,currentTimeStamp,'pchip');
   interpY(index+1) = interp1(LrawTime,LrawY,currentTimeStamp,'pchip');
   interpZ(index+1) = interp1(LrawTime,LrawZ,currentTimeStamp,'pchip');
   interpS(index+1) = interp1(LrawTime,LrawSphere,currentTimeStamp,'pchip');
   interpTime(index+1) = currentTimeStamp;
   index = index+1;
end

% Read coordinate data (PalmX, PalmY, PalmZ)
xL = interpX;   
yL = interpY;
zL = interpZ;
zS = interpS;

% Define time based on timestamp in microseconds

timemicro = interpTime;        %timestamp in first column          
time = (timemicro - interpTime(1,1))/1000000;   %subtracts first timestamp from subsequent and converts microseconds to seconds


% Filtering Algorithm
cutoff = 1;   %Frequency cutoff in Hz
samplerate = 60;  %Samplerate in Hz
Wn = cutoff / (samplerate/2);
[B,A] = butter (2,Wn);
xL_filtered = filtfilt (B,A,xL);
yL_filtered = filtfilt (B,A,yL);
zL_filtered = filtfilt (B,A,zL);
sL_filtered = filtfilt (B,A,zS);

%Plot filtered data
figure;
subplot(2,2,1),plot(time, xL_filtered);
xlabel('time');
ylabel('x velocity - filtered');
title('X velocity data - filtered');

%figure;
subplot(2,2,2),plot(time, yL_filtered);
xlabel('time');
ylabel('y velocity - filtered');
title('Y velocity data - filtered');

%figure;
subplot(2,2,3),plot(time, zL_filtered);
xlabel('time');
ylabel('z velocity - filtered');
title('Z velocity data - filtered');

%Plot filterd 3D data
%figure;

subplot(2,2,4),plot(time, sL_filtered);
xlabel('time');
ylabel('Sphere velocity - filtered');
title('Sphere velocity data - filtered');
% subplot(2,2,4),
% plot3(xL_filtered,yL_filtered,zL_filtered);     
% grid on
% box on
% xlabel('x ','rotation',0);
% ylabel('y','rotation',0);
% zlabel('z','rotation',0);
% title('3D position data - filtered');
