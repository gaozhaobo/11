function [My] = double_arms_corporate_func(t_total,t_samples)
%建立两机械臂模型
L(1) = Link([0,300,0,0],'modified');
L(2) = Link([0,0,100,pi/2],'modified');
L(3) = Link([0,0,290,0],'modified');
L(4) = Link([0,300,85,pi/2],'modified');
L(5) = Link([0,0,0,-pi/2],'modified');
L(6) = Link([0,0,0,pi/2],'modified');

L2(1) = Link([0,0,0,0],'modified');
L2(2) = Link([0,98,0,pi/2],'modified');
L2(3) = Link([0,0,243.5,pi],'modified');
L2(4) = Link([0,-11.5,211,pi],'modified');
L2(5) = Link([0,86,0,-pi/2],'modified');
L2(6) = Link([0,0,0,pi/2],'modified');

L3(1) = Link([0,300,0,0],'modified');
L3(2) = Link([0,0,100,pi/2],'modified');
L3(3) = Link([0,0,290,0],'modified');
L3(4) = Link([0,300,85,pi/2],'modified');
L3(5) = Link([0,0,0,-pi/2],'modified');
L3(6) = Link([0,0,0,pi/2],'modified');

Robot1 = SerialLink(L,'name','Robot1');
Robot2 = SerialLink(L2,'name','Robot2');
Robot3 = SerialLink(L3,'name','Robot3');
Robot3.tool = transl([0,500,0]);
T_R12R2 = [0,-1,0,821.743187414267;
                   1,0,0,-649.716451921158;
                   0,0,1,361.403566579465;
                   0,0,0,1];
Robot2.base = T_R12R2;
t_target = [0,500,0];
%设置主臂初始点和终止点以及从臂初始点
test_ql_0 = [-0.1198723   1.146691-pi/2   0.2785613 0 -1.4252519  -0.1198723]+[0,pi/2,0,0,0,0];
test_qf_0 = [pi/2,pi/2-pi/2,pi/2-pi/2,-pi/2+pi/2,pi/2,-pi/2]+[0,pi/2,pi/2,-pi/2,0,0];

test_ql_end = [-0.6592547  -0.1305564+pi/2  -0.9870618   0.0000006  -0.4531778  -0.9092553];
%设置时间频率
% t_total = 1;       % 总时间(秒)
% t_samples = 0:0.1:t_total; % 时间采样点
num_joints = 6;    % 关节数量

%生成主臂关节运动曲线
Q = zeros(length(t_samples), num_joints);
QD = zeros(size(Q));
QDD = zeros(size(Q));

for j = 1:num_joints
    [Q(:,j), QD(:,j), QDD(:,j)] = quintic_poly(...
        test_ql_0(j), test_ql_end(j), t_samples, t_total);
end

% %设置衡量误差值
test_ql_next = test_ql_0;
test_qf_next = test_qf_0;
% table_error = zeros(3,100);
% L_error = zeros(1,100);
% T1 = Robot1.fkine(test_ql_next+[0,pi/2,0,0,0,0]);
% T2 = Robot2.fkine(test_qf_next+[0,pi/2,pi/2,-pi/2,0,0]);
% t_offset = (T2.t-T1.t);
% table_error(1,1) = t_offset(1,1);
% table_error(2,1) = t_offset(2,1);
% table_error(3,1) = t_offset(3,1);
% L = sqrt(t_offset(1,1)^2+t_offset(2,1)^2+t_offset(3,1)^2);
% L_error(1,1) = L;

QD_f = zeros(length(t_samples),6);
points_1 = zeros(3,length(t_samples));%记录机械臂1轨迹点
points_2 = zeros(3,length(t_samples));%记录机械臂2轨迹点
Error = zeros(1,length(t_samples));
%开始迭代计算
for i=1:length(t_samples)

   %计算时刻雅可比
   Jf = Robot2.jacob0(test_qf_next);
   Jl = Robot1.jacob0(test_ql_next);
   Jl_a = Jl(4:6,:);
   
   Jl = Robot3.jacob0(test_ql_next);
   Jl_l = Jl(1:3,:);
   Jl = [Jl_l;Jl_a];

%    Robot3.plot(test_ql_next);
%    hold on;
%    Robot2.plot(test_qf_next);
%    hold on;
   
   %计算速度
   v_ql = QD(i,:)';
   v_qf = Jf\Jl*v_ql;
   QD_f(i,:) = v_qf';
   
   test_qf_next = test_qf_next+(1/(length(t_samples)-1))*v_qf';
%    test_ql_next = test_ql_next+v_ql';
   test_ql_next =Q(i,:);
   points_1(:,i) = Robot1.fkine(test_ql_next).t;
   points_2(:,i) = Robot2.fkine(test_qf_next).t;
   
   Error(1,i) = (sqrt((points_1(1,i)-points_2(1,i))^2+(points_1(2,i)-points_2(2,i))^2+(points_1(3,i)-points_2(3,i))^2)-500)/500;
 
end
My = Error;
%绘制轨迹点
figure;
plot3(points_1(1,:), points_1(2,:), points_1(3,:), 'b.', 'MarkerSize', 5);
xlabel('X轴');
ylabel('Y轴');
zlabel('Z轴');
hold on;
plot3(points_2(1,:), points_2(2,:), points_2(3,:), 'r.', 'MarkerSize', 5);

figure
plot(t_samples, Error);

end
