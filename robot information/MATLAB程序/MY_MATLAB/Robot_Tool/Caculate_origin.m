function [My] = Caculate_origin(Mx1,Mx2,Mx3,Mx4,Mx5,Mx6)%参数1—6分别为棋盘格绕6轴旋转得到的采样点
%该函数用于计算DH参数以及初始位置偏差值

%获得六个轴的圆心坐标和轴线
My1 = Adjustment(Mx1)
My2 = Adjustment(Mx2)
My3 = Adjustment(Mx3)
My4 = Adjustment(Mx4)
My5 = Adjustment(Mx5)
My6 = Adjustment(Mx6)

%接下来计算轴线之间的距离，用来测试DH参数并验证该方法的准确性
distance1_2=Axis_distance(My1,My2);%轴1-2的距离和夹角
distance2_3=Axis_distance(My2,My3);
distance3_4=Axis_distance(My3,My4);
distance4_5=Axis_distance(My4,My5);
distance5_6=Axis_distance(My5,My6);

%计算轴1和连杆夹角
c1 = My1(:,1);
c2 = My2(:,1);
c3 = My3(:,1);
nv1 = My1(:,2);
nv2 = My2(:,2);
nv3 = My3(:,2);

vec2_3 = c3-c2;
angle = rad2deg(acos(dot(vec2_3,nv1)/(norm(vec2_3)*norm(nv1))))

k = dot((c2-c3),nv2)/dot(nv2,nv3)%计算k值，k越接近0越好
angle1 = acos(dot(c3+k*nv3-c2,nv1)/(norm(c3+k*nv3-c2)*norm(nv1)))
My = angle1;

plot3(c1(1,:),c1(2,:),c1(3,:), 'o');
hold on;
plot3(c2(1,:),c2(2,:),c2(3,:), '*');
hold on;
plot3(c3(1,:),c3(2,:),c3(3,:),'.');
% hold on;
% quiver3(c1(1), c1(2), c1(3), nv1(1), nv1(2), nv1(3));
% hold on;
% quiver3(c2(1), c2(2), c2(3), nv2(1), nv2(2), nv2(3));
% hold on;
% quiver3(c3(1), c3(2), c3(3), nv3(1), nv3(2), nv3(3));
end