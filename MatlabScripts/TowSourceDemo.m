% Leap Motion Data Processing Script


% Load raw data from text (ASCII) file
 
%Left hand raw data Sample1
Lraw = importdata('L3.txt',' ',1); %imports data and ignores first row (headers)
%Left hand raw data Sample2

%Left hand raw data Sample1
Lraw2 = importdata('L4.txt',' ',1); %imports data and ignores first row (headers)
%Left hand raw data Sample2

% Define the fixed timeinterval in microseconds
frequency = 50; %preset variable


LrawX = Lraw.data(1:end,10);
LrawX = (LrawX - LrawX(1,1));

LrawY = Lraw.data(1:end,11);
LrawY = (LrawY - LrawY(1,1));

LrawZ = Lraw.data(1:end,12);
LrawZ = (LrawZ - LrawZ(1,1));

LrawTime = Lraw.data(1:end,2);


LrawX2 = Lraw2.data(1:end,10);
LrawX2 = (LrawX2 - LrawX2(1,1));

LrawY2 = Lraw2.data(1:end,11);
LrawY2 = (LrawY2 - LrawY2(1,1));

LrawZ2 = Lraw2.data(1:end,12);
LrawZ2 = (LrawZ2 - LrawZ2(1,1));

LrawTime2 = Lraw2.data(1:end,2);

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


interpX2=[];
interpY2=[];
interpZ2=[];
interpTime2=[];
index = 0;
currentTimeStamp = 0;
while currentTimeStamp < LrawTime2(end)
   currentTimeStamp = LrawTime2(1) + (index * (1/frequency) * 1000000); 
   interpX2(index+1) = interp1(LrawTime2,LrawX2,currentTimeStamp,'spline');
   interpY2(index+1) = interp1(LrawTime2,LrawY2,currentTimeStamp,'spline');
   interpZ2(index+1) = interp1(LrawTime2,LrawZ2,currentTimeStamp,'spline');
   interpTime2(index+1) = currentTimeStamp;
   index = index+1;
end




% Read coordinate data (PalmX, PalmY, PalmZ)
xL = interpX;   
yL = interpY;
zL = interpZ;

xL2 = interpX2;   
yL2 = interpY2;
zL2 = interpZ2;


% Define time based on timestamp in microseconds

timemicro = interpTime;        %timestamp in first column          
time = (timemicro - interpTime(1,1))/1000000;   %subtracts first timestamp from subsequent and converts microseconds to seconds

timemicro2 = interpTime2;        %timestamp in first column          
time2 = (timemicro2 - interpTime2(1,1))/1000000; 


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
samplerate = 50;  %Samplerate in Hz
Wn = cutoff / (samplerate/2);
[B,A] = butter (2,Wn);
xL_filtered = filtfilt (B,A,xL);
yL_filtered = filtfilt (B,A,yL);
zL_filtered = filtfilt (B,A,zL);

xL_filtered2 = filtfilt (B,A,xL2);
yL_filtered2 = filtfilt (B,A,yL2);
zL_filtered2 = filtfilt (B,A,zL2);

%Plot filtered data
figure;
subplot(2,2,1),plot(time, xL_filtered, time2,xL_filtered2);
xlabel('time');
ylabel('x position - filtered');
title('X position data - filtered');

%figure;
subplot(2,2,2),plot(time, yL_filtered,time2,yL_filtered2);
xlabel('time');
ylabel('y position - filtered');
title('Y position data - filtered');

%figure;
subplot(2,2,3),plot(time, zL_filtered,time2,zL_filtered2);
xlabel('time');
ylabel('z position - filtered');
title('Z position data - filtered');

%Plot filterd 3D data
%figure;
subplot(2,2,4),
plot3(xL_filtered,yL_filtered,zL_filtered,xL_filtered2,yL_filtered2,zL_filtered2);     
grid on
box on
xlabel('x ','rotation',0);
ylabel('y','rotation',0);
zlabel('z','rotation',0);
title('3D position data - filtered');