%用于计算6轴机械臂的关节轴线，M为6组每组10个拟合点
function [My] = Robot_axis_fit(M)
[num,dim] = size(M);%计算数据维度
per_grop = num/6;%每一个轴的数据维度
M1 = M(1:per_grop,:);
M2 = M(1+per_grop:2*per_grop,:);
M3 = M(1+2*per_grop:3*per_grop,:);
M4 = M(1+3*per_grop:4*per_grop,:);
M5 = M(1+4*per_grop:5*per_grop,:);
M6 = M(1+5*per_grop:6*per_grop,:); %从M中提取6组点，用于拟合圆

My1 = Spatial_circle_fit2(M1);
My2 = Spatial_circle_fit2(M2);
My3 = Spatial_circle_fit2(M3);
My4 = Spatial_circle_fit2(M4);
My5 = Spatial_circle_fit2(M5);
My6 = Spatial_circle_fit2(M6); %计算出6组数据的轴线

My = [My1,My2,My3,My4,My5,My6];
