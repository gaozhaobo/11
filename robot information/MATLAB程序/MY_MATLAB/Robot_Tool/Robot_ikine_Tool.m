function [My] = Robot_ikine_Tool(Mx,q0,index,tool)%Mx为输入位姿矩阵，My为输出的各个关节角度，1行6列,index为索引,tool为（x,y,z）
%用于计算机器人运动学逆解
L(1) = Link([0,300,0,0],'modified');
L(2) = Link([0,0,100,pi/2],'modified');
L(3) = Link([0,0,290,-0.2406*pi/180],'modified');
L(4) = Link([0,300,85,pi/2],'modified');
L(5) = Link([0,0,0,((-pi/2)+(0.407*pi/180))],'modified');
L(6) = Link([0,0,0,(pi/2)],'modified');

L2(1) = Link([0,0,0,0],'modified');
L2(2) = Link([0,98,0,pi/2],'modified');
L2(3) = Link([0,0,243.5,pi],'modified');
L2(4) = Link([0,-11.5,211,pi],'modified');
L2(5) = Link([0,86,0,-pi/2],'modified');
L2(6) = Link([0,0,0,pi/2],'modified');

L(1).qlim = [-pi/2,pi/2];
L(2).qlim = [-pi/6,(90+45)*pi/180];
L(3).qlim = [-60*pi/180,pi/2];
L(4).qlim = [-pi,pi];
L(5).qlim = [-135*pi/180,135*pi/180];

L2(1).qlim = [-pi,pi];
L2(2).qlim = [0,pi];
L2(3).qlim = [-150*pi/180,150*pi/180];
L2(4).qlim = [-250*pi/180,80*pi/180];

Robot = SerialLink(L);
Robot2 = SerialLink(L2);
if index == 1
    Robot.tool = transl(tool);%工具位置定义
    q0(1,2) = q0(1,2)+pi/2;
    qn = Robot.ikine(Mx,'q0',q0);
    qn = wrapToPi(qn);
    qn(1,2) = qn(1,2)-pi/2;
    %qn = wrapToPi(qn);
    My = qn;
elseif index == 2
    Robot2.tool = transl(tool);%工具位置定义
    q0(1,2) = q0(1,2)+pi/2;
    q0(1,3) = q0(1,3)+pi/2;
    q0(1,4) = q0(1,4)-pi/2;
    qn = Robot2.ikine(Mx,'q0',q0)
    qn = wrapToPi(qn);
    qn(1,2) = qn(1,2)-pi/2;
    qn(1,3) = qn(1,3)-pi/2;
    qn(1,4) = qn(1,4)+pi/2;
    %qn = wrapToPi(qn);
    My = qn;
end
%Robot.ikine6s(Mx)%该函数只能由标准DH参数调用
end
