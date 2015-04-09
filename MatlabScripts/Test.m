sum = 0;
for n=1:length(Case7ObSequence)
    autoGenerage = hmmgenerate(n,TRANS,EMIS);
    [~,loglikLL] =  hmmdecode(autoGenerage,TRANS,EMIS);
    sum = sum + loglikLL;
end
sum = sum/length(Case7ObSequence);

[~,loglik7] = hmmdecode(Case7ObSequence,TRANS,EMIS);

Euqation = 0;
for n=1:length(Case7ObSequence)
    autoGenerage = hmmgenerate(n,TRANS,EMIS);
    [~,loglikLL] =  hmmdecode(autoGenerage,TRANS,EMIS);
    Euqation = Euqation + abs(loglikLL - sum);
end
Euqation = Euqation/length(Case7ObSequence);

Sm = abs(loglik7-sum)/Euqation;