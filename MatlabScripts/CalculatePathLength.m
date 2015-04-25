function [ pathLength ] = CalculatePathLength( rawObservation )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
pathLength = 0;
for i=1:length(rawObservation)-1
    pathLength = pathLength + pdist2(rawObservation(i,:),rawObservation(i+1,:));
end
end

