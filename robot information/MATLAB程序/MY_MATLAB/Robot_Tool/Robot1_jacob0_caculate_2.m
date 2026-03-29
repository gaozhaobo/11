function[My,V_q] = Robot1_jacob0_caculate_2(Mx,T_tool,V_end)
%实时计算机械臂雅可比矩阵以及主臂各个关节实时速度
%Mx输入参数1为关节角度，注意初始角度的变化
%参数2为工具坐标系相对于机器人末端的位姿变换矩阵包含平移和旋转，是一个4x4矩阵
%输入参数为末端移动的速度，相对于世界坐标系
%输出参数为雅可比矩阵，一般为6行6矩阵,第二个为各个轴的角速度

% L(1) = Link([0,300,0,0],'modified');
% L(2) = Link([0,0,100,pi/2],'modified');
% L(3) = Link([0,0,290,-0.2406*pi/180],'modified');
% L(4) = Link([0,300,85,pi/2],'modified');
% L(5) = Link([0,0,0,((-pi/2)+(0.407*pi/180))],'modified');
% L(6) = Link([0,0,0,(pi/2)],'modified');
L(1) = Link([0,300,0,0],'modified');
L(2) = Link([0,0,100,pi/2],'modified');
L(3) = Link([0,0,290,0],'modified');
L(4) = Link([0,300,85,pi/2],'modified');
L(5) = Link([0,0,0,-pi/2],'modified');
L(6) = Link([0,0,0,pi/2],'modified');

% L(1).qlim = [-pi/2,pi/2];
% L(2).qlim = [-pi/6,(90+45)*pi/180];
% L(3).qlim = [-60*pi/180,pi/2];
% L(4).qlim = [-pi,pi];
% L(5).qlim = [-135*pi/180,135*pi/180];

Robot1 = SerialLink(L);
Robot1.tool = T_tool;

%补偿初始位姿
Mx(1,2) = Mx(1,2)+pi/2;

My = Robot1.jacob0(Mx);
V_q = My\V_end;
end
