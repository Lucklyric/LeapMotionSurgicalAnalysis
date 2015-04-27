function [ numberOfMovements,meansArray,tangVel ] = CalculateNumOfMovements( rawObservation )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

tangVel = sqrt(rawObservation(1:end,1).^2 + rawObservation(1:end,2).^2+rawObservation(1:end,3).^2);
means = mean(tangVel);
[a,b]=findpeaks(tangVel);
numberOfMovements = length(find(a>means));

meansArray(1:length(tangVel))=means;

end

