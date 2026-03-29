function [My] = Robot_axis_distance(Mx_grop)
Mx1 = Mx_grop(:,1);
Mx2 = Mx_grop(:,2);
Mx3 = Mx_grop(:,3);
Mx4 = Mx_grop(:,4);
Mx5 = Mx_grop(:,5);
Mx6 = Mx_grop(:,6);%分解6个轴的轴线

[distance1_2,Deg1_2] = Axis_distance(Mx1,Mx2);
[distance2_3,Deg2_3] = Axis_distance(Mx2,Mx3);
[distance3_4,Deg3_4] = Axis_distance(Mx3,Mx4);
[distance4_5,Deg4_5] = Axis_distance(Mx4,Mx5);
[distance5_6,Deg5_6] = Axis_distance(Mx5,Mx6);%连杆长度

[distance1_3,Deg1_3] = Axis_distance(Mx1,Mx3);
[distance1_6,Deg2_6] = Axis_distance(Mx1,Mx6);
[distance3_5,Deg3_5] = Axis_distance(Mx3,Mx5);
[distance2_5,Deg2_5] = Axis_distance(Mx2,Mx5);
distance4_6 = Axis_distance(Mx4,Mx6);
distance2_6 = Axis_distance(Mx2,Mx6);%等效连杆偏距


My = [distance1_2,Deg1_2;distance2_3,Deg2_3;distance3_4,Deg3_4;distance4_5,Deg4_5;distance5_6,Deg5_6;
      distance1_3,Deg1_3;distance2_6,Deg2_6;distance3_5,Deg3_5;distance2_5,Deg2_5;distance4_6,0;distance1_6,0];
end