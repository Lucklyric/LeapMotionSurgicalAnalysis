function [ transitionProbability ] = GetTransitionMatrix(flag)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
transitionProbability = zeros(6);
% state: 1:Idle 2:Droping 3:Grasping 4:Elevating 5:Translating 6:Releasing |
% 7:Droping+Grasping 8:Elevating+Releasing
switch flag
    case 1 %1->7->4->5->2->6->8->1
        transitionProbability = [
            %1 2 3 4 5 6 7 8
            0 0 0 0 0 0 1 0; %1
            0 0 0 0 0 1 0 0; %2
            0 0 0 0 0 0 0 0; %3
            0 0 0 0 1 0 0 0; %4
            0 1 0 0 0 0 0 0; %5
            0 0 0 0 0 0 0 1; %6
            0 0 0 1 0 0 0 0; %7
            1 0 0 0 0 0 0 0; %8
            ];
    case 2 %1->2->3->4->5->2->6->4->1
        transitionProbability = [
            %1 2 3 4 5 6 7 8
            0 1 0 0 0 0 0 0; %1
            0 0 0.5 0 0 0.5 0 0; %2
            0 0 0 1 0 0 0 0; %3
            0 0 0 0 1 0 0 0; %4
            0 1 0 0 0 0 0 0; %5
            0 0 0 1 0 0 0 0; %6
            0 0 0 0 0 0 0 0; %7
            0 0 0 0 0 0 0 0; %8
            ];
    case 3 %1->2->1->3->4->5->2->6->1->4->1
        transitionProbability = [
            %1 2 3 4 5 6 7 8
            0 0.33 0.33 0.33 0 0 0 0; %1
            0.5 0 0 0 0 0.5 0 0; %2
            0 0 0 1 0 0 0 0; %3
            0 0 0 0 1 0 0 0; %4
            0 1 0 0 0 0 0 0; %5
            1 0 0 0 0 0 0 0; %6
            0 0 0 0 0 0 0 0; %7
            0 0 0 0 0 0 0 0; %8
            ];
    otherwise
        for row=1:6
            for col=1:6
                transitionProbability(row,col)=1/8;
            end
        end
end

end

