function [ dataArray ] = CustomLoadfile( fileName )
%UNTITLED8 Summary of this function goes here
%   Detailed explanation goes here
filename = 'D:\Code\LeapMotionQt\LeapMotionQt\LeapMotionQt\SampleOutPut\Case2\Output\RgithHand-2015-4-5-14-45-50.txt';
delimiter = ' ';
startRow = 2;
formatSpec = '%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%[^\n\r]';
fileID = fopen(filename,'r');
dataArray = textscan(fileID, formatSpec, 'Delimiter', delimiter, 'MultipleDelimsAsOne', true, 'HeaderLines' ,startRow-1, 'ReturnOnError', false);
fclose(fileID);
end

