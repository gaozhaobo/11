%double_arms_test
% L(1) = Link([0,300,0,0],'modified');
% L(2) = Link([0,0,100,pi/2],'modified');
% L(3) = Link([0,0,290,0],'modified');
% L(4) = Link([0,300,85,pi/2],'modified');
% L(5) = Link([0,0,0,-pi/2],'modified');
% L(6) = Link([0,0,0,pi/2],'modified');
% %((-pi/2)-(0.4*pi/180))
% q1_lim = [-pi/2,pi/2];
% q2_lim = [-pi/6,(90+45)*pi/180];
% q3_lim = [-60*pi/180,pi/2];
% q4_lim = [-pi,pi];
% q5_lim = [-135*pi/180,135*pi/180];
% q6_lim = [-pi,pi];
% L(1).qlim = [-pi/2,pi/2];
% L(2).qlim = [-pi/6,(90+45)*pi/180];
% L(3).qlim = [-60*pi/180,pi/2];
% L(4).qlim = [-pi,pi];
% L(5).qlim = [-135*pi/180,135*pi/180];
% 
% L2(1) = Link([0,0,0,0],'modified');
% L2(2) = Link([0,98,0,pi/2],'modified');
% L2(3) = Link([0,0,243.5,pi],'modified');
% L2(4) = Link([0,-11.5,211,pi],'modified');
% L2(5) = Link([0,86,0,-pi/2],'modified');
% L2(6) = Link([0,0,0,pi/2],'modified');
% 
% q2_1_lim = [-pi,pi];
% q2_2_lim = [0,pi];
% q2_3_lim = [-150*pi/180,150*pi/180];
% q2_4_lim = [-250*pi/180,80*pi/180];
% q2_5_lim = [-pi,pi];
% q2_6_lim = [-pi,pi];
% L2(1).qlim = [-pi,pi];
% L2(2).qlim = [0,pi];
% L2(3).qlim = [-150*pi/180,150*pi/180];
% L2(4).qlim = [-250*pi/180,80*pi/180];
% 
%  Robot1 = SerialLink(L,'name','Robot1');
%  Robot2 = SerialLink(L2,'name','Robot2');
%  
 T_Robot2Camera = [0.9280, -0.0158, -0.3723, 1008.2;
                   -0.0629, -0.9914, -0.1146, 16.1310;
                   -0.3672, 0.1297, -0.9210, 954.8813;
                   0, 0, 0, 1  ];
               
T_Robot2Camera2 = [-0.0022, -0.9974, -0.0719, 634.5334;
                   -0.9140, -0.0272, 0.4049, -185.0396;
                   -0.4058, 0.0666, -0.9115, 627.2335;
                   0, 0, 0, 1 ];
               
%机械臂2相对于机械臂1的位姿变换矩阵
T_R12R2 =  T_Robot2Camera/T_Robot2Camera2;
  Robot2.base = (T_R12R2);
 
 %qf_0 = [0,pi/2,pi/3,-2*pi/3,0,0];
 qf_0 = [0.9627,0.0596-pi/2,-0.6040-pi/2,-2.1652+pi/2,1.5429,-1.6956];
 %qf_0 = [-1.5892,-0.1825-pi/2,-1.9901-pi/2,-1.8460+pi/2,1.6297,1.6325];
 J_qf = Robot2_jacob0_caculate(qf_0,[0,0,0],T_R12R2);
 
 ql_0 = [-pi/6,pi/3-pi/2,0,0,-pi/3,0];
 %ql_0 = [0,pi/3-pi/2,0,0,pi/6,0];
 JL_ql = Robot1_jacob0_caculate(ql_0,[0,0,0]);
 JL_ql = JL_ql(1:3,:);
 
 L_ql = Robot1_jacob0_caculate(ql_0,[0,0,0]);
 L_ql = L_ql(1:3,:);
 
 JA_ql = Robot1_jacob0_caculate(ql_0,[0,0,0]);
 JA_ql = JA_ql(4:6,:);
 
 J_ql = [JL_ql + L_ql;JA_ql];
 
 V_l = [1,0,0,0,0,0];
 V_f = inv(J_qf)*J_ql*V_l'
%这里放入要计算的
