function [ EstObsequence ] = EstObservationSequence( RawObserve,TargetCenters )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
DisTable = pdist2(RawObserve,TargetCenters,'euclidean');
EstObsequence = zeros(1,length(RawObserve));
for idx=1:length(RawObserve)
    [~,EstObsequence(idx)] = min(DisTable(idx,:));
end
end

