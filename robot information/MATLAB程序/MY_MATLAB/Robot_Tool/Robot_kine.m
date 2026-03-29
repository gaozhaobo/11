function [My] = Robot_kine(Mx,index)%Mx为各个关节运动角度从轴0到5（末端为5）,index为机器人索引
%该函数根据机器人的DH参数建立机器人模型，实现其运动学正解
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

if index==1
    Mx(1,2) = Mx(1,2)+pi/2;%初始姿态调整
    My1 = Robot.fkine(Mx);
    My = zeros(4,4);
    My(1:3,1) = My1.n;
    My(1:3,2) = My1.o;
    My(1:3,3) = My1.a;
    My(1:3,4)= My1.t;
    My(4,:) = [0,0,0,1];
elseif index==2
    Mx(1,2) = Mx(1,2)+pi/2;%初始姿态调整
    Mx(1,3) = Mx(1,3)+pi/2;
    Mx(1,4) = Mx(1,4)-pi/2;
    My1 = Robot2.fkine(Mx);
    My = zeros(4,4);
    My(1:3,1) = My1.n;
    My(1:3,2) = My1.o;
    My(1:3,3) = My1.a;
    My(1:3,4)= My1.t;
    My(4,:) = [0,0,0,1];
end
    

end

