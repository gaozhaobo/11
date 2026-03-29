
L(1) = Link([0,300,0,0],'modified','plotopt', {'FaceColor', [0.9 0.6 0.6], 'FaceAlpha', 0.5});
L(2) = Link([0,0,100,pi/2],'modified','plotopt', {'FaceColor', [0.9 0.6 0.6], 'FaceAlpha', 0.5});
L(3) = Link([0,0,290,0],'modified','plotopt', {'FaceColor', [0.9 0.6 0.6], 'FaceAlpha', 0.5});
L(4) = Link([0,300,85,pi/2],'modified','plotopt', {'FaceColor', [0.9 0.6 0.6], 'FaceAlpha', 0.5});
L(5) = Link([0,0,0,-pi/2],'modified','plotopt', {'FaceColor', [0.9 0.6 0.6], 'FaceAlpha', 0.5});
L(6) = Link([0,0,0,pi/2],'modified','plotopt', {'FaceColor', [0.9 0.6 0.6], 'FaceAlpha', 0.5});

Robot1 = SerialLink(L,'name','Robot1');
Robot2 = SerialLink(L,'name','Robot2');

q_start = [0,pi/2,0,0,0,0];
q_end = [-0.628796286415433   0.233196143548855   0.761940601463779   0.000000000000080  -0.995136745011994  -0.628796286415513];

%轨迹参数
t_total = 1;       % 总时间(秒)
t_samples = 0:0.01:1; % 时间采样点
num_joints = 6;    % 关节数量

%生成轨迹
Q = zeros(length(t_samples), num_joints);
QD = zeros(size(Q));
QDD = zeros(size(Q));

Q2 = zeros(length(t_samples), num_joints);
QD2 = zeros(size(Q));
QDD2 = zeros(size(Q));
v0=[0,0,0,0,0,0];
a0=[0,0,0,0,0,0];

v_end = [0,0,0,0,0,0];
a_end = [0,0,0,0,0,0];

[~,~,Q2,QD2,QDD2] = quintic_traj(q_start,v0,a0,q_end,v_end,a_end,t_total,0.01);


for j = 1:num_joints
    [Q(:,j), QD(:,j), QDD(:,j)] = quintic_poly(...
        q_start(j), q_end(j), t_samples, t_total);
end

points = zeros(3,100);
points_2 = zeros(3,100);
q_next = q_start;
for i=0:100
    points(:,i+1)=Robot1.fkine(q_start+0.01*i*(q_end-q_start)).t;
    q_next = Q(i+1,:);
    points_2(:,i+1) = Robot1.fkine(q_next).t;
end

Robot1.plot(q_end);
hold on;
% 假设 points 是 3×100 的矩阵
%figure;
plot3(points(1,:), points(2,:), points(3,:), 'b.', 'MarkerSize', 5);
xlabel('X轴');
ylabel('Y轴');
zlabel('Z轴');
hold on;
plot3(points_2(1,:), points_2(2,:), points_2(3,:), 'r.', 'MarkerSize', 5)
%grid on;



hold on;
Robot2.plot([0,pi/2,0,0,0,0]);

% figure('Name','Joint States', 'Position', [100 100 1000 800])
% 
% % 位置曲线
% subplot(3,1,1);
% Q(:,2)=Q(:,2)-pi/2;
% plot(t_samples, Q);
% % ylabel('Position (rad)');
% % title('Joint Position');
% xlabel('时间 (s)');
% ylabel('关节角度 (rad)');
% title('关节角度变化曲线');
% legend({'q1','q2','q3','q4','q5','q6'}, 'Location','northwest');
% 
% % 速度曲线
% subplot(3,1,2);
% plot(t_samples, QD);
% % ylabel('Velocity (rad/s)');
% % title('Joint Velocity');
% xlabel('时间 (s)');
% ylabel('关节角度 (rad)');
% title('关节角度变化曲线');
% % 加速度曲线
% subplot(3,1,3);
% plot(t_samples, QDD);
% % ylabel('Acceleration (rad/s²)');
% % title('Joint Acceleration');
% % xlabel('Time (s)');
% xlabel('时间 (s)');
% ylabel('关节加速度 (rad/s^2)');
% title('关节加速度变化曲线');
% T_end = [1.0000    0.0000   -0.0000       550
%          0.0000   -1.0000    0.0000      -400
%          -0.0000   -0.0000   -1.0000       275
%          0         0         0         1]

figure('Name','Joint States 2', 'Position', [100 100 1000 800])

% 位置曲线
subplot(3,1,1);
Q2(:,2)=Q2(:,2)-pi/2;
plot(t_samples, Q2);
% ylabel('Position (rad)');
% title('Joint Position');
xlabel('时间 (s)');
ylabel('关节角度 (rad)');
title('关节角度变化曲线');
legend({'q1','q2','q3','q4','q5','q6'}, 'Location','northwest');

% 速度曲线
subplot(3,1,2);
plot(t_samples, QD2);
% ylabel('Velocity (rad/s)');
% title('Joint Velocity');
xlabel('时间 (s)');
ylabel('关节角度 (rad)');
title('关节角度变化曲线');
% 加速度曲线
subplot(3,1,3);
plot(t_samples, QDD2);
% ylabel('Acceleration (rad/s²)');
% title('Joint Acceleration');
% xlabel('Time (s)');
xlabel('时间 (s)');
ylabel('关节加速度 (rad/s^2)');
title('关节加速度变化曲线');
