mdl_ur5; % 加载RVCTools的UR5模型
% p560 = ur5; 
% p5602 = ur5; 
L(1) = Link([0,300,0,0],'modified');
L(2) = Link([0,0,100,pi/2],'modified');
L(3) = Link([0,0,290,0],'modified');
L(4) = Link([0,300,85,pi/2],'modified');
L(5) = Link([0,0,0,-pi/2],'modified');
L(6) = Link([0,0,0,pi/2],'modified');

p560 = SerialLink(L,'name','p560');
p5602 = SerialLink(L,'name','p5602');
% 定义初始和目标末端执行器位姿（笛卡尔空间中的位置）
% T1 = transl(0.3, 0.2, 0.1) * trotx(pi/4);  % 初始位姿
% T2 = transl(0.6, -0.1, 0.4) * trotx(-pi/6); % 目标位姿
% T1=p560.fkine([0,pi/2,0,0,0,0]);
T1= [0         0         1       400
         0        -1         0         0
         1         0         0       675
         0         0         0         1];
% T2 = p560.fkine([0,pi/2-pi/3,pi/6,0,0,0]);
% T2 = p560.fkine([-0.540419500270584,0.803144779258192,0.048518912844657,0,-0.851663692102787,-0.540419500270312]);
T2=[1     0     0   500
     0    -1     0  -450
     0     0    -1   275
     0     0     0     1];

% 计算初始和终点的关节角度（利用逆解）
q1 = p560.ikine(T1);  % 初始关节角度
q2 = p560.ikine(T2);  % 目标关节角度

% 轨迹参数
t_total = 5;  % 总运动时间
Ts = 0.01;    % 采样周期
T = 0:Ts:t_total;  % 时间向量

% 计算末端执行器的直线轨迹（笛卡尔空间插补）
P1 = transl(T1); % 初始点位置 (x, y, z)
P2 = transl(T2); % 目标点位置 (x, y, z)

R1 = T1(1:3, 1:3); % 初始姿态旋转矩阵
R2 = T2(1:3, 1:3); % 目标姿态旋转矩阵
q1_rot = rotm2quat(R1); % 初始姿态四元数
q2_rot = rotm2quat(R2); % 目标姿态四元数

% 生成末端执行器在笛卡尔空间上的直线轨迹
P = zeros(length(T), 3);
R = zeros(3, 3, length(T));
for i = 1:length(T)
    alpha = i / length(T);
    
    % 线性插值位置
    P(i, :) = P1 + alpha * (P2 - P1);
    
    % 四元数插值计算旋转
    q_rot = quatinterp(q1_rot, q2_rot, alpha);  % 使用四元数插值（SLERP）
    R(:, :, i) = quat2rotm(q_rot);  % 将四元数转回旋转矩阵
end

% 使用逆运动学计算每个时刻的关节角度
q = zeros(length(T), 6);
for i = 1:length(T)
    % 构造当前时刻的完整末端执行器位姿（位置+旋转）
    T_current = [R(:, :, i), P(i, :)'; 0, 0, 0, 1];
    
    % 求解逆运动学
    if i>1
        q(i, :) = p560.ikine(T_current,'q0',q(i-1,:));  % 求解逆运动学
    else
        q(i, :) = p560.ikine(T_current);  % 求解逆运动学
    end
    
end
% % 生成末端执行器在笛卡尔空间上的直线轨迹
% P = zeros(length(T), 3);
% for i = 1:length(T)
%     alpha = i / length(T);
%     P(i, :) = P1 + alpha*(P2-P1);  % 线性插值
% end
% 
% % 使用逆运动学计算每个时刻的关节角度
% q = zeros(length(T), 6);
% for i = 1:length(T)
%     T_current = transl(P(i, :));  % 当前末端执行器的位置
%     q(i, :) = p560.ikine(T_current);  % 求解逆运动学
% end

% 生成七段S型轨迹（位移、速度、加速度）——关节空间插补
[s, v, a] = jtraj(q1, q2, T);

% 绘制机械臂末端执行器轨迹
% figure;
% plot3(P(:,1), P(:,2), P(:,3), 'b', 'LineWidth', 2);
% xlabel('X'); ylabel('Y'); zlabel('Z');
% grid on;
% title('机械臂末端执行器直线轨迹');

% 绘制关节角度曲线
figure;
subplot(3,1,1);
plot(T, s);
xlabel('时间 (s)');
ylabel('关节角度 (rad)');
title('关节角度变化曲线');
grid on;
legend('q1', 'q2', 'q3', 'q4', 'q5', 'q6');

% 绘制关节速度曲线
subplot(3,1,2);
plot(T, v);
xlabel('时间 (s)');
ylabel('关节速度 (rad/s)');
title('关节速度变化曲线');
grid on;
legend('q1', 'q2', 'q3', 'q4', 'q5', 'q6');

% 绘制关节加速度曲线
subplot(3,1,3);
plot(T, a);
xlabel('时间 (s)');
ylabel('关节加速度 (rad/s^2)');
title('关节加速度变化曲线');
grid on;
legend('q1', 'q2', 'q3', 'q4', 'q5', 'q6');

% 显示机械臂动画
figure;
p560.plot(q1);
hold on;
p5602.plot(q2);
hold on;
plot3(P(:,1), P(:,2), P(:,3), 'b', 'LineWidth', 2);
