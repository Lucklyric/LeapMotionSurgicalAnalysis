function [ ObservationDistribution,Data_c ] = GetObjservationMatrix( flag_case,flag_ifTrain,DataArray )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

%k-means clustering classficiation
Data_RawObserve = transp([DataArray{1};DataArray{2};DataArray{4}]);
[Data_idx,Data_c] = kmeans(Data_RawObserve,80);

ObservationDistribution = zeros(8,80);
if flag_ifTrain == 1
    switch flag_case
        case 1
            for row=1:8
                for col=1:80
                    %                 if col <= 10
                    %                     ObservationDistribution(row,col) = 1/10;
                    %                 else
                    %                     ObservationDistribution(row,col) = 0;
                    %                 end
                    ObservationDistribution(row,col) = 1/80;
                end
            end
        case 2
            %ObservationDistribution =
        otherwise
            disp('Somthing Wrong');
    end
elseif flag_ifTrain == 0
   
    switch flag_case
        case 1
        case 2
        case 3
            %idle [250616~250761] [251304~251414]
            %dropping+grasping [250762~250859]
            %evaluating [250860~250972]
            %translating [250973~251110]
            %dropping [251111~251224]
            %evaluating+releasing [251225~251303]
            for row=1:8
                ObservationArray = zeros(1,80);
                switch row
                    case 1
                        ObservationArray = [Data_idx(1:FindClosestIndex(DataArray,250761));Data_idx(FindClosestIndex(DataArray,251304):FindClosestIndex(DataArray,251414))];
                    case 2
                        ObservationArray = Data_idx(FindClosestIndex(DataArray,251111):FindClosestIndex(DataArray,251224));
                    case 3
                        %ObservationArray = [];
                    case 4
                        ObservationArray = Data_idx(FindClosestIndex(DataArray,250860):FindClosestIndex(DataArray,250972));
                    case 5
                        ObservationArray = Data_idx(FindClosestIndex(DataArray,250973):FindClosestIndex(DataArray,251110));
                    case 6
                        %ObservationArray = [];
                    case 7
                        ObservationArray = Data_idx(FindClosestIndex(DataArray,250762):FindClosestIndex(DataArray,251224));
                    case 8
                        ObservationArray = Data_idx(FindClosestIndex(DataArray,251225):FindClosestIndex(DataArray,251303));
                end
                for col=1:80
                    %                 if col <= 10
                    %                     ObservationDistribution(row,col) = 1/10;
                    %                 else
                    %                     ObservationDistribution(row,col) = 0;
                    %                 end
                    ObservationDistribution(row,col) = numel(find(ObservationArray==col))/numel(ObservationArray);
                end
            end
    end
end
end

