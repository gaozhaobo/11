% 假设数据矩阵为data（101行6列）
data = q1_final; % 这里替换为你的实际数据

% 定义时间向量
t = 0:0.1:10; % 时间从0到10秒，间隔0.1秒


% 对每个轴进行处理
velocity = zeros(101,6);
acceleration = zeros(101,6);
for axis = 1:6
    % 提取当前轴的角度数据
    theta_temp = data(:, axis);
    
    % 使用梯度法计算速度和加速度
    dt = 0.1; % 时间间隔
    velocity(:,axis) = gradient(theta_temp, dt); % 速度（一阶导数）
    acceleration(:,axis) = gradient(velocity(:,axis), dt); % 加速度（二阶导数）
end

figure;
set(gcf, 'Position', [100 100 1200 900]); % 设置窗口大小
colors1 = lines(6);
subplot(3,1,1);
for axis =1:6    
    % 绘制三条曲线
    plot(t, data(:,axis),'Color', colors1(axis, :),'LineWidth', 1.5);
    hold on;
end
title('所有关节角度轨迹'); 
xlabel('时间 (s)'); ylabel('角度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

subplot(3,1,2);
for axis = 1:6
    plot(t, velocity(:,axis),'Color', colors1(axis, :),'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('速度 (rad/s)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

subplot(3,1,3);
for axis=1:6
    plot(t, acceleration(:,axis), 'Color', colors1(axis, :),'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('加速度 (rad/s^2)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

% 调整子图间距
set(gcf, 'Position', [100 100 1200 900]);