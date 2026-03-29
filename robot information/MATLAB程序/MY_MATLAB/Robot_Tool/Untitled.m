L(1) = Link([0,300,0,0],'modified');
L(2) = Link([0,0,100,pi/2],'modified');
L(3) = Link([0,0,290,0],'modified');
L(4) = Link([0,300,85,pi/2],'modified');
L(5) = Link([0,0,0,-pi/2],'modified');
L(6) = Link([0,0,0,pi/2],'modified');
%((-pi/2)-(0.4*pi/180))
q1_lim = [-pi/2,pi/2];
q2_lim = [-pi/6,(90+45)*pi/180];
q3_lim = [-60*pi/180,pi/2];
q4_lim = [-pi,pi];
q5_lim = [-135*pi/180,135*pi/180];
q6_lim = [-pi,pi];
L(1).qlim = [-pi/2,pi/2];
L(2).qlim = [-pi/6,(90+45)*pi/180];
L(3).qlim = [-60*pi/180,pi/2];
L(4).qlim = [-pi,pi];
L(5).qlim = [-135*pi/180,135*pi/180];

L2(1) = Link([0,0,0,0],'modified');
L2(2) = Link([0,98,0,pi/2],'modified');
L2(3) = Link([0,0,243.5,pi],'modified');
L2(4) = Link([0,-11.5,211,pi],'modified');
L2(5) = Link([0,86,0,-pi/2],'modified');
L2(6) = Link([0,0,0,pi/2],'modified');

q2_1_lim = [-pi,pi];
q2_2_lim = [0,pi];
q2_3_lim = [-150*pi/180,150*pi/180];
q2_4_lim = [-250*pi/180,80*pi/180];
q2_5_lim = [-pi,pi];
q2_6_lim = [-pi,pi];
L2(1).qlim = [-pi,pi];
L2(2).qlim = [0,pi];
L2(3).qlim = [-150*pi/180,150*pi/180];
L2(4).qlim = [-250*pi/180,80*pi/180];

% L2(1) = Link([0,0,0,0],'modified');
% L2(2) = Link([0,98,0,-pi/2],'modified');
% L2(3) = Link([0,0,243.5,0],'modified');
% L2(4) = Link([0,-11.5,211,0],'modified');
% L2(5) = Link([0,86,0,-pi/2],'modified');
% L2(6) = Link([0,0,0,pi/2],'modified');
% L(1) = Link([0,300,0,0],'modified');
% L(2) = Link([0,0,100,pi/2],'modified');
% L(3) = Link([0,0,290,-0.2433*pi/180],'modified');
% L(4) = Link([0,300,85,pi/2],'modified');
% L(5) = Link([0,0,0,((-pi/2)+(0.4*pi/180))],'modified');
% L(6) = Link([0,0,0,((pi/2)+(0*pi/180))],'modified');

% L(1) = Link([0,300,0,0],'modified');
% L(2) = Link([0,0,100,pi/2],'modified');
% L(3) = Link([0,0,290,0.2433*pi/180],'modified');
% L(4) = Link([0,300,85,pi/2],'modified');
% L(5) = Link([0,0,0,((-pi/2)-(0.4*pi/180))],'modified');
% L(6) = Link([0,0,0,pi/2],'modified');
 Robot1 = SerialLink(L,'name','Robot1');
 Robot2 = SerialLink(L2,'name','Robot2');
Robot2.base = T_R12R2;
N=6000;                                               %随机次数
theta1=q1_lim(1)+diff(q1_lim)*rand(N,1); %关节1限制
theta2=q2_lim(1)+diff(q2_lim)*rand(N,1); %关节2限制
theta3=q3_lim(1)+diff(q3_lim)*rand(N,1); %关节3限制
theta4=q4_lim(1)+diff(q4_lim)*rand(N,1); %关节4限制
theta5=q5_lim(1)+diff(q5_lim)*rand(N,1); %关节5限制
theta6=q6_lim(1)+diff(q6_lim)*rand(N,1); %关节6限制
pos = {1,N};

% % 正运动学求解
% for i=1:N
%     pos{i}=Robot1.fkine([theta1(i) theta2(i) theta3(i) theta4(i),theta5(i),theta6(i)]);
% end
% % 绘图
% figure
% Robot1.plot([0 pi/2 0 0 0 0],'jointdiam',1)
% axis equal;
% hold on;
% for i=1:N
%     plot3(pos{i}.t(1),pos{i}.t(2),pos{i}.t(3),'r.');
%     hold on;
% end
% grid off
% 
% hold on;
% Robot2.base = transl([821,-648,319]);
% Robot2.plot([pi/2 pi/2 0 -pi/2 0 0],'jointdiam',1)
% N=3000;                                               %随机次数
% theta2_1=q2_1_lim(1)+diff(q2_1_lim)*rand(N,1); %关节1限制
% theta2_2=q2_2_lim(1)+diff(q2_2_lim)*rand(N,1); %关节2限制
% theta2_3=q2_3_lim(1)+diff(q2_3_lim)*rand(N,1); %关节3限制
% theta2_4=q2_4_lim(1)+diff(q2_4_lim)*rand(N,1); %关节4限制
% theta2_5=q2_5_lim(1)+diff(q2_5_lim)*rand(N,1); %关节5限制
% theta2_6=q2_6_lim(1)+diff(q2_6_lim)*rand(N,1); %关节6限制
% pos = {1,N};
% % 正运动学求解
% for i=1:N
%     pos{i}=Robot2.fkine([theta2_1(i) theta2_2(i) theta2_3(i) theta2_4(i),theta2_5(i),theta2_6(i)]);
% end
% % 绘图
% axis equal;
% hold on;
% for i=1:N
%     plot3(pos{i}.t(1),pos{i}.t(2),pos{i}.t(3),'b.');
%     hold on;
% end
% grid off

% L(1) = Link([0,0,100,-pi/2]);
% L(2) = Link([0,0,290,0]);
% L(3) = Link([0,0,85,-pi/2]);
% L(4) = Link([0,300,0,pi/2]);
% L(5) = Link([0,0,0,-pi/2]);
% L(6) = Link([0,0,0,0]);
% 
% Robot_stand = SerialLink(L);

