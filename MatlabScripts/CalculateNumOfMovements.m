function [ numberOfMovements ] = CalculateNumOfMovements( rawObservation )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
numberOfMovements = 0;
startmovement = 1;
tmpIndex= 0;
while startmovement < length(rawObservation)
    tangVel = sqrt(rawObservation(startmovement:end,1).^2 + rawObservation(startmovement:end,2).^2);
    startmovement = find(tangVel >0.05*max(tangVel),1)+tmpIndex;
    passedhalf = find(tangVel > 0.5 * max(tangVel),1);
    endmovement = find(tangVel(passedhalf:end,:) < 0.05*max(tangVel),1) + passedhalf - 1+tmpIndex; 
    startmovement = endmovement;
    tmpIndex = endmovement;
    display(startmovement);
    numberOfMovements = numberOfMovements + 1;
end

end

