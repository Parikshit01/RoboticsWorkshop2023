%plotting kinect pointcloud manually with extraction of data
clear all;
clc;
load('pointCloudData2.mat');
%pcshow(ptCloud);
a=ptCloud.Location;
c=reshape(ptCloud.Color, [], 3);
d=single(c)/255;
b=reshape(a, [], 3);
%scatter3(b(:,1),b(:,2),b(:,3),1,'.')
scatter3(b(:,1),b(:,2),b(:,3),1,d,'.')
view([0 0 90])

set (gcf, 'WindowButtonDownFcn', @callBack);
function callBack(~,~)
    for i=1:1
    C = get (gca, 'CurrentPoint');
    disp(['(X,Y,Z) = (', num2str((C(1,1))), ',', num2str((C(1,2))), ',', num2str((C(1,3))), ')']);   
%     x=419; y=597;
    end
    disp('hi');
    %X = [-0.22684,-0.082216,0.571; -0.03606,0.10146,0.571]; distance =(pdist(X,'euclidean'))
end