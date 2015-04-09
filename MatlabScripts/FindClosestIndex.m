function [ index ] = FindClosestIndex( DataArray,FrameID )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[~, index]=min(abs(transp(DataArray{7})-DataArray{5}((find(DataArray{6}==FrameID)))));

end

