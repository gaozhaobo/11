function[My] = Robot2_jacob0_caculate(Mx,tool,T_Robot1_2_Robot2)
%实时计算机械臂雅可比矩阵
%Mx输入参数1为关节角度，注意初始角度的变化
%参数2为工具坐标系相对于机器人末端的偏移量
%输出参数为雅可比矩阵，一般为6行6矩阵,
%注意这里是第二个机械臂的雅可比，可能会涉及到坐标系的转换
L2(1) = Link([0,0,0,0],'modified');
L2(2) = Link([0,98,0,pi/2],'modified');
L2(3) = Link([0,0,243.5,pi],'modified');
L2(4) = Link([0,-11.5,211,pi],'modified');
L2(5) = Link([0,86,0,-pi/2],'modified');
L2(6) = Link([0,0,0,pi/2],'modified');
% 
% L2(1).qlim = [-pi,pi];
% L2(2).qlim = [0,pi];
% L2(3).qlim = [-150*pi/180,150*pi/180];
% L2(4).qlim = [-250*pi/180,80*pi/180];

Robot2=SerialLink(L2);
Robot2.tool = transl(tool);
Robot2.base = T_Robot1_2_Robot2;
%补偿初始位姿
Mx(1,2) = Mx(1,2)+pi/2;
Mx(1,3) = Mx(1,3)+pi/2;
Mx(1,4) = Mx(1,4)-pi/2;
My = Robot2.jacob0(Mx);

end