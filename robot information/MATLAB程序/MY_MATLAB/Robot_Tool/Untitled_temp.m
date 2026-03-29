%% 初始化环境
clear; clc; close all;
startup_rvc; % 加载RVCTools工具箱
mdl_puma560; % 加载PUMA560模型

%% 定义轨迹参数
t_total = 5;       % 总时间(秒)
t_samples = 0:0.05:t_total; % 时间采样点
num_joints = 6;    % 关节数量

% 初始和目标关节角（示例值）
q_start = p560.qz; % 零位姿态
q_end = [0.5, -1.2, 1.8, 0, 0.5, 0]; 

%% 五次多项式轨迹生成函数
% function [q, qd, qdd] = quintic_poly(q0, qf, t, T)
%     % 五次多项式系数计算
%     a0 = q0;
%     a1 = 0; % 初始速度设为0
%     a2 = 0; % 初始加速度设为0
%     a3 = (10*(qf - q0)) / T^3;
%     a4 = (-15*(qf - q0)) / T^4;
%     a5 = (6*(qf - q0)) / T^5;
%     
%     % 计算轨迹
%     tau = t / T;
%     q = a0 + a1*tau + a2*tau.^2 + a3*tau.^3 + a4*tau.^4 + a5*tau.^5;
%     qd = (a1 + 2*a2*tau + 3*a3*tau.^2 + 4*a4*tau.^3 + 5*a5*tau.^4) / T;
%     qdd = (2*a2 + 6*a3*tau + 12*a4*tau.^2 + 20*a5*tau.^3) / T^2;
% end

%% 生成各关节轨迹数据
Q = zeros(length(t_samples), num_joints);
QD = zeros(size(Q));
QDD = zeros(size(Q));

for j = 1:num_joints
    [Q(:,j), QD(:,j), QDD(:,j)] = quintic_poly(...
        q_start(j), q_end(j), t_samples, t_total);
end

%% 可视化机械臂运动
% figure('Name','Robot Motion', 'Position', [100 100 1200 600])
% 
% % 绘制初始和终止位形
% subplot(1,2,1);
% p560.plot(q_start, 'floorlevel', 0, 'trail', 'r-');
% title('Initial Configuration');
% view(135, 30)
% 
% % 绘制轨迹动画
% subplot(1,2,2);
% p560.plot(Q, 'trail', 'b-', 'movie', 'robotmove.gif');
% title('Trajectory Animation');
% view(45, 30)
%%
plot3(pos(:,1), pos(:,2), pos(:,3), 'r-', 'LineWidth', 1.5, 'DisplayName', 'Trajectory');

% 添加红色离散点（每5个采样点显示一个）
scatter3(pos(1:5:end,1), pos(1:5:end,2), pos(1:5:end,3),...
    40, 'r', 'filled', 'MarkerEdgeColor','k', 'DisplayName', 'Sampled Points');

% 标注起点终点
scatter3(pos(1,1), pos(1,2), pos(1,3), 100, 'g', 'pentagram', 'filled', 'DisplayName', 'Start');
scatter3(pos(end,1), pos(end,2), pos(end,3), 100, 'm', 'diamond', 'filled', 'DisplayName', 'Goal');

% 绘制机械臂初始位形
p560.plot(q_start, 'nobase', 'notiles', 'noname', 'floorlevel', 0);

% 图形美化
title('End-Effector Trajectory (Red)');
xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)');
legend('Location','best');
view(45,30);
set(gca, 'FontSize', 10);

%% 修改后的动画代码（替换原动画部分）
figure('Name','Robot Motion', 'Position', [100 100 1200 600])

% 初始位形（左视图）
subplot(1,2,1);
p560.plot(q_start);
title('Initial Configuration');
view(135, 30)

% 轨迹动画（红色轨迹线）
subplot(1,2,2);
p560.plot(Q,...
    'trail', {'r-', 'LineWidth', 2},...    % 红色轨迹线
    'movie', 'robotmove_red.gif',...      % 保存动画
    'path', pos,...                       % 显示笛卡尔路径
    'shadow', true);                      % 开启阴影效果
title('Trajectory Animation with Red Path');
view(45, 30)
%% 绘制末端轨迹
% T = p560.fkine(Q); % 正运动学计算
% pos = transl(T);    % 提取末端位置
% 
% figure('Name','End-Effector Path');
% plot3(pos(:,1), pos(:,2), pos(:,3), 'LineWidth', 2);
% hold on; grid on;
% p560.plot(q_start);
% title('End-Effector Cartesian Trajectory');
% xlabel('X (m)'); ylabel('Y (m)'); zlabel('Z (m)');

%% 绘制关节状态曲线
figure('Name','Joint States', 'Position', [100 100 1000 800])

% 位置曲线
subplot(3,1,1);
plot(t_samples, Q);
ylabel('Position (rad)');
title('Joint Position');
legend({'q1','q2','q3','q4','q5','q6'}, 'Location','northwest');

% 速度曲线
subplot(3,1,2);
plot(t_samples, QD);
ylabel('Velocity (rad/s)');
title('Joint Velocity');

% 加速度曲线
subplot(3,1,3);
plot(t_samples, QDD);
ylabel('Acceleration (rad/s²)');
title('Joint Acceleration');
xlabel('Time (s)');

%% 导出数据到CSV
joint_data = [t_samples' Q QD QDD];
header = {'Time',...
          'q1','q2','q3','q4','q5','q6',...
          'qd1','qd2','qd3','qd4','qd5','qd6',...
          'qdd1','qdd2','qdd3','qdd4','qdd5','qdd6'};
          
csvwrite_with_headers('joint_trajectory.csv', joint_data, header);

%% 辅助函数：带标题的CSV写入
function csvwrite_with_headers(filename, data, headers)
    fid = fopen(filename, 'w'); 
    fprintf(fid, '%s,', headers{1:end-1});
    fprintf(fid, '%s\n', headers{end});
    fclose(fid);
    dlmwrite(filename, data, '-append'); 
end

function [q, qd, qdd] = quintic_poly(q0, qf, t, T)
    % 五次多项式系数计算
    a0 = q0;
    a1 = 0; % 初始速度设为0
    a2 = 0; % 初始加速度设为0
    a3 = (10*(qf - q0)) / T^3;
    a4 = (-15*(qf - q0)) / T^4;
    a5 = (6*(qf - q0)) / T^5;
    
    % 计算轨迹
    tau = t / T;
    q = a0 + a1*tau + a2*tau.^2 + a3*tau.^3 + a4*tau.^4 + a5*tau.^5;
    qd = (a1 + 2*a2*tau + 3*a3*tau.^2 + 4*a4*tau.^3 + 5*a5*tau.^4) / T;
    qdd = (2*a2 + 6*a3*tau + 12*a4*tau.^2 + 20*a5*tau.^3) / T^2;
end