function [ ObservationDistribution,Data_c ] = GetObjservationMatrix( flag_case,flag_ifTrain,DataArray )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here

%k-means clustering classficiation
Data_RawObserve = transp([DataArray{1};DataArray{2};DataArray{4}]);
[Data_idx,Data_c] = kmeans(Data_RawObserve,60);

ObservationDistribution = zeros(6,60);
if flag_ifTrain == 1
    switch flag_case
        case 1
            for row=1:6
                for col=1:60
                    %                 if col <= 10
                    %                     ObservationDistribution(row,col) = 1/10;
                    %                 else
                    %                     ObservationDistribution(row,col) = 0;
                    %                 end
                    ObservationDistribution(row,col) = 1/60;
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
            %idle [77218~250761] [251304~251414]
            %dropping+grasping [250762~250859]
            %evaluating [250860~250972]
            %translating [250973~251110]
            %dropping [251111~251224]
            %evaluating+releasing [251225~251303]
            for row=1:6
                ObservationArray = zeros(1,60);
                switch row
                    case 1
                        ObservationArray = [Data_idx(1:FindClosestIndex(DataArray,77210));Data_idx(FindClosestIndex(DataArray,79826):FindClosestIndex(DataArray,79954))];
                    case 2
                        ObservationArray = [Data_idx(FindClosestIndex(DataArray,77211):FindClosestIndex(DataArray,77296));...
                            Data_idx(FindClosestIndex(DataArray,77487):FindClosestIndex(DataArray,77572));...
                            Data_idx(FindClosestIndex(DataArray,77694):FindClosestIndex(DataArray,77779));...
                            Data_idx(FindClosestIndex(DataArray,77979):FindClosestIndex(DataArray,78030));...
                            Data_idx(FindClosestIndex(DataArray,78177):FindClosestIndex(DataArray,78237));...
                            Data_idx(FindClosestIndex(DataArray,78410):FindClosestIndex(DataArray,78474));...
                            Data_idx(FindClosestIndex(DataArray,78600):FindClosestIndex(DataArray,78660));...
                            Data_idx(FindClosestIndex(DataArray,78842):FindClosestIndex(DataArray,78910));...
                            Data_idx(FindClosestIndex(DataArray,79032):FindClosestIndex(DataArray,79074));...
                            Data_idx(FindClosestIndex(DataArray,79239):FindClosestIndex(DataArray,79307));...
                            Data_idx(FindClosestIndex(DataArray,79437):FindClosestIndex(DataArray,79471));...
                            Data_idx(FindClosestIndex(DataArray,79636):FindClosestIndex(DataArray,79712));...
                            ];
                    case 3
                         ObservationArray = [Data_idx(FindClosestIndex(DataArray,77297):FindClosestIndex(DataArray,77339));...
                            Data_idx(FindClosestIndex(DataArray,77780):FindClosestIndex(DataArray,77823));...
                            Data_idx(FindClosestIndex(DataArray,78238):FindClosestIndex(DataArray,78280));...
                            Data_idx(FindClosestIndex(DataArray,78661):FindClosestIndex(DataArray,78703));...
                            Data_idx(FindClosestIndex(DataArray,79075):FindClosestIndex(DataArray,79126));...
                            Data_idx(FindClosestIndex(DataArray,79472):FindClosestIndex(DataArray,79523));...
                            ];
                    case 4
                         ObservationArray = [Data_idx(FindClosestIndex(DataArray,77340):FindClosestIndex(DataArray,77400));...
                            Data_idx(FindClosestIndex(DataArray,77608):FindClosestIndex(DataArray,77693));...
                            Data_idx(FindClosestIndex(DataArray,77824):FindClosestIndex(DataArray,77892));...
                            Data_idx(FindClosestIndex(DataArray,78100):FindClosestIndex(DataArray,78176));...
                            Data_idx(FindClosestIndex(DataArray,78281):FindClosestIndex(DataArray,78332));...
                            Data_idx(FindClosestIndex(DataArray,78548):FindClosestIndex(DataArray,78599));...
                            Data_idx(FindClosestIndex(DataArray,78704):FindClosestIndex(DataArray,78772));...
                            Data_idx(FindClosestIndex(DataArray,78954):FindClosestIndex(DataArray,79031));...
                            Data_idx(FindClosestIndex(DataArray,79127):FindClosestIndex(DataArray,79177));...
                            Data_idx(FindClosestIndex(DataArray,79308):FindClosestIndex(DataArray,79436));...
                            Data_idx(FindClosestIndex(DataArray,79524):FindClosestIndex(DataArray,79566));...
                            Data_idx(FindClosestIndex(DataArray,79765):FindClosestIndex(DataArray,79825));...
                            ];
                    case 5
                        ObservationArray = [Data_idx(FindClosestIndex(DataArray,77401):FindClosestIndex(DataArray,77486));...
                            Data_idx(FindClosestIndex(DataArray,77893):FindClosestIndex(DataArray,77978));...
                            Data_idx(FindClosestIndex(DataArray,78333):FindClosestIndex(DataArray,78409));...
                            Data_idx(FindClosestIndex(DataArray,78773):FindClosestIndex(DataArray,78841));...
                            Data_idx(FindClosestIndex(DataArray,79178):FindClosestIndex(DataArray,79238));...
                            Data_idx(FindClosestIndex(DataArray,79567):FindClosestIndex(DataArray,79635));...
                            ];
                    case 6
                        ObservationArray = [Data_idx(FindClosestIndex(DataArray,77573):FindClosestIndex(DataArray,77607));...
                            Data_idx(FindClosestIndex(DataArray,78031):FindClosestIndex(DataArray,78099));...
                            Data_idx(FindClosestIndex(DataArray,78475):FindClosestIndex(DataArray,78547));...
                            Data_idx(FindClosestIndex(DataArray,78911):FindClosestIndex(DataArray,78953));...
                            Data_idx(FindClosestIndex(DataArray,79713):FindClosestIndex(DataArray,79764));...
                            ];
                end
                for col=1:60
                    %                 if col <= 10
                    %                     ObservationDistribution(row,col) = 1/10;
                    %                 else
                    %                     ObservationDistribution(row,col) = 0;
                    %                 end
                    ObservationDistribution(row,col) = numel(find(ObservationArray==col))/numel(ObservationArray);
                end
            end
        case 3
            
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

