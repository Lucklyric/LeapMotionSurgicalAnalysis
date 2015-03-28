% Leap Motion Data Processing Script


% Load raw data from text (ASCII) file
 
%Left hand raw data
Lraw = importdata('L3N',' ',1); %imports data and ignores first row (headers)

% Read coordinate data (PalmX, PalmY, PalmZ)
xL = Lraw.data(2000:3000,9);   
yL = Lraw.data(2000:3000,10);
zL = Lraw.data(2000:3000,11);

% Define time based on timestamp in microseconds

timemicro = Lraw.data(2000:3000,1);        %timestamp in first column          
time = (timemicro - Lraw.data(1,1))/1000000;   %subtracts first timestamp from subsequent and converts microseconds to seconds

% Plot x, y, z data
figure; 
plot(time, xL);  %PalmX vs time
xlabel('time');
ylabel('x position - unfiltered');

figure; 
plot(time, yL);  %PalmY vs time
xlabel('time');
ylabel('y position - unfiltered');

figure; 
plot(time, zL);  %PalmZ vs time
xlabel('time');
ylabel('z position - unfiltered');

%generate 3D plot of position data
figure;
plot3(xL,yL,zL);     
grid on
box on
xlabel('x','rotation',0);
ylabel('y','rotation',0);
zlabel('z','rotation',0);
title('3D position data');

% Filtering Algorithm
cutoff = 10;   %Frequency cutoff in Hz
samplerate = 120;  %Samplerate in Hz
Wn = cutoff / (samplerate/2);
[B,A] = butter (2,Wn);
xL_filtered = filtfilt (B,A,xL);
yL_filtered = filtfilt (B,A,yL);
zL_filtered = filtfilt (B,A,zL);

%Plot filtered data
figure;
plot(time, xL_filtered);
xlabel('time');
ylabel('x position - filtered');

figure;
plot(time, yL_filtered);
xlabel('time');
ylabel('y position - filtered');

figure;
plot(time, zL_filtered);
xlabel('time');
ylabel('z position - filtered');

%Plot filterd 3D data
figure;
plot3(xL_filtered,yL_filtered,zL_filtered);     
grid on
box on
xlabel('x ','rotation',0);
ylabel('y','rotation',0);
zlabel('z','rotation',0);
title('3D position data - filtered');











