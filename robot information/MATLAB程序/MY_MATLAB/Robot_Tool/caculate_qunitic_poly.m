function [Q,QDD] = caculate_qunitic_poly(QD,dt,num_points)
% 数据初始化
% 假设已知条件：
velocity_data = QD; % 100x6速度数组(示例数据)
initial_angles = [0,0,0,0,0,0]; % 初始关节角度(根据实际情况修改)
% dt = 1/20; % 采样时间间隔(s)
t = 0:dt:(size(velocity_data,1)-1)*dt; % 时间向量

% 关节位置计算(梯形积分法)
position_data = zeros(size(velocity_data));
for i = 1:6
    position_data(:,i) = initial_angles(i) + cumtrapz(t, velocity_data(:,i));
end

% 加速度计算(中心差分法)
acceleration_data = zeros(size(velocity_data));
for j = 1:6
    % 内部点使用中心差分
    acceleration_data(2:end-1,j) = (velocity_data(3:end,j) - velocity_data(1:end-2,j)) / (2*dt);
    % 边界点使用前/后向差分
    acceleration_data(1,j) = (velocity_data(2,j) - velocity_data(1,j)) / dt;
    acceleration_data(end,j) = (velocity_data(end,j) - velocity_data(end-1,j)) / dt;
end

% 五次样条插值生成连续曲线
% num_points = 100; % 插值点数
t_interp = linspace(t(1), t(end), num_points);

% 预分配存储空间
q_interp = zeros(num_points, 6);
Q = q_interp;
v_interp = zeros(num_points, 6);
a_interp = zeros(num_points, 6);
QDD = a_interp;

for joint = 1:6
    % 创建五次样条(阶数=6)
    spline_position = spapi(6, t, position_data(:,joint));
    
    % 计算导数样条
    spline_velocity = fnder(spline_position, 1); % 一阶导(速度)
    spline_acceleration = fnder(spline_position, 2); % 二阶导(加速度)
    
    % 评估样条
    q_interp(:,joint) = fnval(spline_position, t_interp);
    v_interp(:,joint) = fnval(spline_velocity, t_interp);
    a_interp(:,joint) = fnval(spline_acceleration, t_interp);
end

% % 可视化配置
% % 定义颜色映射(6种不同颜色)
% colors = lines(6); 
% joint_labels = {'Joint 1', 'Joint 2', 'Joint 3', 'Joint 4', 'Joint 5', 'Joint 6'};
% 
% % 创建综合运动曲线图
% figure('Position', [100 100 1200 900])
% 
% % ================= 位置曲线 =================
% subplot(3,1,1)
% hold on; grid on;
% for j = 1:6
%     plot(t_interp, q_interp(:,j), 'Color', colors(j,:), 'LineWidth', 1.5)
% end
% % scatter(t, position_data, 30, repmat(colors, [length(t),1]), 'filled', 'MarkerEdgeColor','k')
% % scatter(t, position_data, 30, repmat(colors, [length(t),1]));
% title('Joint Position Profiles', 'FontSize', 12, 'FontWeight','bold');
% xlabel('Time (s)','FontSize',10)
% ylabel('Position (rad)','FontSize',10)
% xlim([t(1) t(end)])
% legend(joint_labels, 'Location','eastoutside')
% 
% % ================= 速度曲线 =================
% subplot(3,1,2)
% hold on; grid on;
% for j = 1:6
%     plot(t_interp, v_interp(:,j), 'Color', colors(j,:), 'LineWidth', 1.5)
% end
% % scatter(t, velocity_data, 30, repmat(colors, [length(t),1]), 'filled', 'MarkerEdgeColor','k')
% title('Joint Velocity Profiles', 'FontSize', 12, 'FontWeight','bold')
% xlabel('Time (s)','FontSize',10)
% ylabel('Velocity (rad/s)','FontSize',10)
% xlim([t(1) t(end)])
% 
% % ================= 加速度曲线 =================
% subplot(3,1,3)
% hold on; grid on;
% for j = 1:6
%     plot(t_interp, a_interp(:,j), 'Color', colors(j,:), 'LineWidth', 1.5)
% end
% % scatter(t, acceleration_data, 30, repmat(colors, [length(t),1]), 'filled', 'MarkerEdgeColor','k')
% title('Joint Acceleration Profiles', 'FontSize', 12, 'FontWeight','bold')
% xlabel('Time (s)','FontSize',10)
% ylabel('Acceleration (rad/s²)','FontSize',10)
% xlim([t(1) t(end)])
% 
% % 设置公共属性
% set(findall(gcf,'Type','axes'), 'FontName','Arial', 'Box','on')
% sgtitle('Six-Axis Manipulator Motion Profiles', 'FontSize',14, 'FontWeight','bold')

% 保存图表(可选)
% exportgraphics(gcf, 'Full_Joint_Profiles.png', 'Resolution',300)
end