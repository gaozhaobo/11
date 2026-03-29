%该函数用于确定凌华控制卡position对应的角度
function [My] = Axis_Deg(Mx,Central)%Mx为一个轴的圆形拟合点（10个）

deg_total = 0;
for i = 1:13
    V1 = Mx(i,:) - Central;
    V2 = Mx(i+1,:) - Central;
    deg = acos(dot(V1,V2)/(sqrt(dot(V1,V1))*sqrt(dot(V2,V2))))%这里应该是弧度，写错了
    
    deg_total =deg_total+deg;
end

My = deg_total/13;


