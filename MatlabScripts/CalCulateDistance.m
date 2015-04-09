function [ Distance ] = CalCulateDistance( Trans,Emis,ObserveSequence )
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
sum = 0;
for n=1:length(ObserveSequence)
    autoGenerage = hmmgenerate(n,Trans,Emis);
    [~,loglikLL] =  hmmdecode(autoGenerage,Trans,Emis);
    sum = sum + loglikLL;
end
sum = sum/length(ObserveSequence);

[~,loglik] = hmmdecode(ObserveSequence,Trans,Emis);

Euqation = 0;
for n=1:length(ObserveSequence)
    autoGenerage = hmmgenerate(n,Trans,Emis);
    [~,loglikLL] =  hmmdecode(autoGenerage,Trans,Emis);
    Euqation = Euqation + abs(loglikLL - sum);
end
Euqation = Euqation/length(ObserveSequence);

Distance = abs(loglik-sum)/Euqation;

end

