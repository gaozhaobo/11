clc;clear

q_sym = sym('q%d',[6,1],'real');
% alpha=[0,     pi/2,  pi,           pi,         pi/2,      -pi/2];
% a=    [0,     0,     -0.2435,      -0.211,    0,         0];
% d=    [0.1435, 0,     0,           0.086,    0.086,     0.0725];
% theta=[0,     -pi/2,  0,           -pi/2,     0,         0];

d = [300,0,0,300,0,0];
a = [0,100,290,85,0,0];
alpha = [0,pi/2,0,pi/2,-pi/2,pi/2];
theta=[0,0,0,0,0,0];
% theta=[0,     0,  0,           0,     0,         0];


dh = [alpha; a; d; theta];
dh=sym(dh);
alpha = dh(1,:);
a = dh(2,:);
d = dh(3,:);
theta = dh(4,:);
Z=[0;0;1];
%转换矩阵建立

Tn=sym(eye(4));T=sym(zeros(4,4,6));R=sym(zeros(3,3,6));P=sym(zeros(3,6));Jw=sym(zeros(3,6));Jv=sym(zeros(3,6));
% T=zeros(4,4,6);R=zeros(3,3,6);P=zeros(3,6);Tn=eye(4);Jw=zeros(3,6);Jv=zeros(3,6);
for i = 1:6
    %############### MDH参数 单个转移矩阵表示为
    %############### A=Rot(alpha)*Tran(a)*Tran(d)*Rot(theta)  
    Rot_theta_q=[cos(q_sym(i)) -sin(q_sym(i)) 0 0;sin(q_sym(i)) cos(q_sym(i)) 0 0;0 0 1 0;0 0 0 1];  
    Rot_theta=[cos(theta(i)) -sin(theta(i)) 0 0;sin(theta(i)) cos(theta(i)) 0 0;0 0 1 0;0 0 0 1];
    Tran_d=[1 0 0 0; 0 1 0 0; 0 0 1 d(i); 0 0 0 1];
    Tran_a=[1 0 0 a(i); 0 1 0 0; 0 0 1 0; 0 0 0 1];
    Rot_alpha=[1 0 0 0; 0 cos(alpha(i)) -sin(alpha(i)) 0; 0 sin(alpha(i)) cos(alpha(i)) 0; 0 0 0 1];
    T(:,:,i)=Rot_alpha*Tran_a*Tran_d*Rot_theta*Rot_theta_q; 
    R(:,:,i)=T(1:3,1:3,i);
    
    Tn=Tn*T(:,:,i);
    P(:,i)=Tn(1:3,4);
    Jw(:,i)=Tn(1:3,3);
end

r11 = Tn(1,1); r12 = Tn(1,2); r13 = Tn(1,3);
r21 = Tn(2,1); r22 = Tn(2,2); r23 = Tn(2,3);
r31 = Tn(3,1); r32 = Tn(3,2); r33 = Tn(3,3);

R_L0_L = [r11,r12,r13;
          r21,r22,r23;
          r31,r32,r33];
a=0;b=-500;c=0;      
P_L0_F = R_L0_L*[a,b,c]';

P_1 = P_L0_F(1,1);
P_2 = P_L0_F(2,1);
P_3 = P_L0_F(3,1);

J_L0_F_1 = [diff(P_1,q_sym(1)), diff(P_1,q_sym(2)),diff(P_1,q_sym(3)),diff(P_1,q_sym(4)),diff(P_1,q_sym(5)),diff(P_1,q_sym(6))];
J_L0_F_2 = [diff(P_2,q_sym(1)), diff(P_2,q_sym(2)),diff(P_2,q_sym(3)),diff(P_2,q_sym(4)),diff(P_2,q_sym(5)),diff(P_2,q_sym(6))];
J_L0_F_3 = [diff(P_3,q_sym(1)), diff(P_3,q_sym(2)),diff(P_3,q_sym(3)),diff(P_3,q_sym(4)),diff(P_3,q_sym(5)),diff(P_3,q_sym(6))];

J_L0_F = [J_L0_F_1;
          J_L0_F_2;
          J_L0_F_3];
J = subs(J_L0_F,q_sym,[0,0,0,0,0,0]')
      
% r11_diff = [diff(r11,q_sym(1)),diff(r11,q_sym(2)),diff(r11,q_sym(3)),diff(r11,q_sym(4)),diff(r11,q_sym(5)),diff(r11,q_sym(6))];
% r12_diff = [diff(r12,q_sym(1)),diff(r12,q_sym(2)),diff(r12,q_sym(3)),diff(r12,q_sym(4)),diff(r12,q_sym(5)),diff(r12,q_sym(6))];
% r13_diff = [diff(r13,q_sym(1)),diff(r13,q_sym(2)),diff(r13,q_sym(3)),diff(r13,q_sym(4)),diff(r13,q_sym(5)),diff(r13,q_sym(6))];
% r21_diff = [diff(r21,q_sym(1)),diff(r21,q_sym(2)),diff(r21,q_sym(3)),diff(r21,q_sym(4)),diff(r21,q_sym(5)),diff(r21,q_sym(6))];
% r22_diff = [diff(r22,q_sym(1)),diff(r22,q_sym(2)),diff(r22,q_sym(3)),diff(r22,q_sym(4)),diff(r22,q_sym(5)),diff(r22,q_sym(6))];
% r23_diff = [diff(r23,q_sym(1)),diff(r23,q_sym(2)),diff(r23,q_sym(3)),diff(r23,q_sym(4)),diff(r23,q_sym(5)),diff(r23,q_sym(6))];
% r31_diff = [diff(r31,q_sym(1)),diff(r31,q_sym(2)),diff(r31,q_sym(3)),diff(r31,q_sym(4)),diff(r31,q_sym(5)),diff(r31,q_sym(6))];
% r32_diff = [diff(r32,q_sym(1)),diff(r32,q_sym(2)),diff(r32,q_sym(3)),diff(r32,q_sym(4)),diff(r32,q_sym(5)),diff(r32,q_sym(6))];
% r33_diff = [diff(r33,q_sym(1)),diff(r33,q_sym(2)),diff(r33,q_sym(3)),diff(r33,q_sym(4)),diff(r33,q_sym(5)),diff(r33,q_sym(6))];


%以下为验证内容
% P_x = Tn(1,4);
% P_y = Tn(2,4);
% P_z = Tn(3,4);
% 
% Px_diff = [diff(P_x,q_sym(1)),diff(P_x,q_sym(2)),diff(P_x,q_sym(3)),diff(P_x,q_sym(4)),diff(P_x,q_sym(5)),diff(P_x,q_sym(6))];
% Py_diff = [diff(P_y,q_sym(1)),diff(P_y,q_sym(2)),diff(P_y,q_sym(3)),diff(P_y,q_sym(4)),diff(P_y,q_sym(5)),diff(P_y,q_sym(6))];
% Pz_diff = [diff(P_z,q_sym(1)),diff(P_z,q_sym(2)),diff(P_z,q_sym(3)),diff(P_z,q_sym(4)),diff(P_z,q_sym(5)),diff(P_z,q_sym(6))];
% 
% q0 = [0,0,0,0,0,0];
% X = subs(Px_diff,q_sym,q0');
% Y = subs(Py_diff,q_sym,q0');
% Z = subs(Pz_diff,q_sym,q0');
% % T_=subs(Tn,q_sym,q1')
% 
% Jl = [X;Y;Z]

for i=1:6
    if i==1
        Jv(:,i)=cross(Jw(:,i),(Tn(1:3,4)-[0 ; 0 ; 0]));
    else
        Jv(:,i)=cross(Jw(:,i),(Tn(1:3,4)-P(:,i)));
    end
end

J=[Jv;Jw];


% % 测试
%theta d a alpha
% L1=Link('d',0.1435,'a',0,'alpha',0,'modified');
% L2=Link('d',0,'a',0,'alpha',pi/2,'offset',-pi/2,'modified');
% L3=Link('d',0,'a',-0.2435,'alpha',pi,'modified');
% L4=Link('d',0.086,'a',-0.211,'alpha',pi,'offset',-pi/2,'modified');
% L5=Link('d',0.086,'a',0,'alpha',pi/2,'modified');
% L6=Link('d',0.0725,'a',0,'alpha',-pi/2,'modified');
% 
% % alpha=[0,     pi/2,  pi,           pi,         pi/2,      -pi/2];
% % a=    [0,     0,     -0.2435,      -0.211,    0,         0];
% % d=    [0.1435, 0,     0,           0.086,    0.086,     0.0725];
% % theta=[0,     -pi/2,  0,           -pi/2,     0,         0];
% 
% RDHeRob = SerialLink([L1 L2 L3 L4 L5 L6],'name','eRob3') ;%建立连杆机器人
% q1=[0 0 0 0 0 0];
% q1=[pi/3,pi/6,pi/4,pi/5,pi/2,pi/7];
% RDHeRob.teach(q1);
% T_=subs(Tn,q_sym,q1');T_=double(T_)
% % 提取旋转矩阵 R
% Tv=RDHeRob.fkine(q1);Tv=Tv.double;
% R = Tv(1:3, 1:3);
% % 创建旋转矩阵的块对角矩阵
% R_block = blkdiag(R, R);
% J1=RDHeRob.jacob0(q1)
% J2=subs(J,q_sym,q1');J2=double(J2)
% J1_=RDHeRob.jacobe(q1);
% Ja = R_block * J1;

% J1'*[1;2;3;4;5;6]

