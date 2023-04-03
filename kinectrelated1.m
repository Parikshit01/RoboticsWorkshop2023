%pointcloud generation of terrain from Kinectv2 Camera
colorDevice=imaq.VideoDevice('kinect', 1);
depthDevice=imaq.VideoDevice('kinect', 2);
%% 
step(colorDevice);
step(depthDevice);

colorImage=step(colorDevice);
depthImage=step(depthDevice);
ptCloud=pcfromkinect(depthDevice,depthImage, colorImage);
%ptCloud=pcfromkinect(depthDevice,depthImage);

%% 
for i=1:1
colorImage=step(colorDevice);
depthImage=step(depthDevice);
ptCloud=pcfromkinect(depthDevice,depthImage, colorImage);
%ptCloud=pcfromkinect(depthDevice,depthImage);
end
pcshow(ptCloud);
save pointCloudData2;

%info:-
%pointCloudData1:- without color
%pointCloudData2:- with color
