clc 
clear 
imaqreset 
delete(imaqfind) 
pause(2) 
% Create color and depth kinect videoinput objects. 
colorVid = videoinput('kinect', 1) 
depthVid = videoinput('kinect', 2) 
% Look at the device-specific properties on the depth source device, 
% which is the depth sensor on the Kinect V2. 
% Set 'EnableBodyTracking' to on, so that the depth sensor will 
% return body tracking metadata along with the depth frame. 
depthSource = getselectedsource(depthVid); 
depthSource.EnableBodyTracking = 'on'; 
% Acquire 100 color and depth frames.
framesPerTrig = 200; 
colorVid.FramesPerTrigger = framesPerTrig; 
depthVid.FramesPerTrigger = framesPerTrig; 
% Start the depth and color acquisition objects. 
% This begins acquisition, but does not start logging of acquired data. 
% pause(5); 
start([depthVid colorVid]); 
% Get images and metadata from the color and depth device objects. 
[colorImg] = getdata(colorVid); 
[~, ~, metadata] = getdata(depthVid); 
% Create skeleton connection map to link the joints. 
SkeletonConnectionMap = [ [4 3]; % Neck 
                          [3 21]; % Head 
                          [21 2]; % Right Leg 
                          [2 1]; 
                          [21 9]; 
                          [9 10]; % Hip 
                          [10 11]; 
                          [11 12]; % Left Leg 
                          [12 24]; 
                          [12 25]; 
                          [21 5]; % Spine 
                          [5 6]; 
                          [6 7]; % Left Hand 
                          [7 8]; 
                          [8 22]; 
                          [8 23]; 
                          [1 17]; 
                          [17 18]; 
                          [18 19]; % Right Hand 
                          [19 20]; 
                          [1 13]; 
                          [13 14]; 
                          [14 15]; 
                          [15 16]; ]; 
trackingIndex = []; 
trackingIncrement = 1; 
for i=1:framesPerTrig 
    if(sum(metadata(i).BodyTrackingID) ~= 0) 
        trackingIndex(trackingIncrement)=i; 
        trackingIncrement=trackingIncrement+1; 
    else 
        disp("yup") 
    end 
end 
metadata = metadata(trackingIndex); 
colorImg = colorImg(:,:,:,trackingIndex); 
colors = ['r';'g';'b';'c';'y';'m']; 
hfig = figure('units','normalized','outerposition',[0 0 1 1]) 
% % Overlay the skeleton on this RGB frame. 
for j=1:size(metadata) 
    anyBodiesTracked = any(metadata(j).IsBodyTracked ~= 0); 
trackedBodies = find(metadata(j).IsBodyTracked); 
nBodies = length(trackedBodies); 
colorJointIndices = metadata(j).ColorJointIndices(:, :, trackedBodies);
imshow(colorImg(:,:,:,j)); 
for i = 1:24 
    for body = 1:nBodies 
        X1 = [colorJointIndices(SkeletonConnectionMap(i,1),1,body) colorJointIndices(SkeletonConnectionMap(i,2),1,body)]; 
        Y1 = [colorJointIndices(SkeletonConnectionMap(i,1),2,body) colorJointIndices(SkeletonConnectionMap(i,2),2,body)]; 
        line(X1,Y1, 'LineWidth', 1.5, 'LineStyle', '-', 'Marker', '+', 'Color', colors(body)); 
    end 
    hold on; 
end 
drawnow 
tmp = getframe(hfig); 
colorImg2(:,:,:,j) = imresize(tmp.cdata,[1280 1920]); 
hold off; 
end 
mov=immovie(colorImg2); 
implay(mov);