function [My] = Spatial_circle_fit2(Mx)%Mx为输入拟合点，My为输出轴线
[num,dim]=size(Mx);
L1 = ones(num,1);
A =((Mx'*Mx)\(Mx'*L1)); %求解平面法向量


B = zeros(num-1,2);
for i = 1:num-1
    B(i,1) = Mx(i+1,1)-Mx(i,1)-(Mx(i+1,3)-Mx(i,3))*A(1)/A(3);
    B(i,2) = Mx(i+1,2)-Mx(i,2)-(Mx(i+1,3)-Mx(i,3))*A(2)/A(3);
end

L2 = zeros(num-1,1);
for i=1:num-1
    L2(i) = (Mx(i+1,1)^2+Mx(i+1,2)^2+Mx(i+1,3)^2-Mx(i,1)^2-Mx(i,2)^2-Mx(i,3)^2)/2-(Mx(i+1,3)-Mx(i,3))/A(3);
end

%C1 = (B'*B)\(B'*L2)%不要用这个公式算圆心的最小二乘解
%D = [(B'*B);A';A';A';A';A';A';A';A';A';A'];      %将平面作为限制条件加入方程
%L3 = [B'*L2;1;1;1;1;1;1;1;1;1;1];
C0 = (B'*B)\B'*L2  %求解空间圆心坐标
C = [C0;(1-A(1)*C0(1)-A(2)*C0(2))/A(3)];
radius = 0;
for i=1:num
    tmp = Mx(i,:)-C';
    radius=radius+sqrt(tmp(1)^2+tmp(2)^2+tmp(3)^2);
end

r=radius/num           %  空间圆拟合半径

A = A/norm(A);
My = [C;A];    %输出结果，C为坐标，A为法向量

figure
h1=plot3(Mx(:,1),Mx(:,2),Mx(:,3),'*');
hold on;
plot3(C(1,1),C(2,1),C(3,1),'*');
%hold on;
%plot3(C1(1,1),C1(2,1),C1(3,1),'*');
% hold on;
% x = C(1,:)-100 : 1 : C(1,:)+100;
% y = C(2,:)-100 : 1 : C(2,:)+100;
% [X, Y] = meshgrid(x, y);
% Z = (1-A(1,:)*X-A(2,:)*Y)/A(3,:);
% surf(X,Y,Z)%该段代码观察平面位置，发现圆心偏离所求平面

%set(gca,'xlim',[11.4 11.7]);

%%%%   绘制空间圆  %%%%
n=A;
c=C;
 
theta=(0:2*pi/100:2*pi)';    %  theta角从0到2*pi
a=cross(n,[1 0 0]);          %  n与i叉乘，求取a向量
if ~any(a)                   %  如果a为零向量，将n与j叉乘
    a=cross(n,[0 1 0]);
end
b=cross(n,a);      % 求取b向量
a=a/norm(a);       % 单位化a向量
b=b/norm(b);       % 单位化b向量
c1=c(1)*ones(size(theta,1),1);
c2=c(2)*ones(size(theta,1),1);
c3=c(3)*ones(size(theta,1),1);
x=c1+r*a(1)*cos(theta)+r*b(1)*sin(theta);  % 圆上各点的x坐标
y=c2+r*a(2)*cos(theta)+r*b(2)*sin(theta);  % 圆上各点的y坐标
z=c3+r*a(3)*cos(theta)+r*b(3)*sin(theta);  % 圆上各点的z坐标
hold on;
h2=plot3(x,y,z,'-r');
xlabel('x轴')
ylabel('y轴')
zlabel('z轴')
legend([h1 h2],'控制点','拟合圆');
grid on
