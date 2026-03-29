
%%%%通过直接对q曲线进行插值生成新的q线以及v和a，要在其他命令后运行。
% 假设 points1 和 points2 已定义为行向量
% points1: 1×100
% points2: 1×16

% ==== 1. 数据替换 ====
points1_new = q1; 
points1_new(27:42,:) = q1_fit; % 将points2替换到位置11-26（共16个点）

% ==== 时间向量定义 ====
t1 = (0:0.1:10)';           % 原始时间轴（100×1）
t_fine = linspace(0, 10, 1001)'; % 密集插值时间轴（1000×1）

% ==== 预存储各轴的插值结果 ====
num_axes = 6;  % 6个轴
positions_fit = zeros(length(t_fine), num_axes);
velocity = zeros(length(t_fine), num_axes);
acceleration = zeros(length(t_fine), num_axes);

% ==== 对每个轴单独处理 ====
for axis = 1:num_axes
    % 提取当前轴数据
    y_axis = points1_new(:, axis);
    
    % 三次样条插值
    pp = spline(t1, y_axis);
    positions_fit(:, axis) = ppval(pp, t_fine);
    
    % 计算速度（一阶导数）
    pp_velocity = fnder(pp, 1);
    velocity(:, axis) = ppval(pp_velocity, t_fine);
    
    % 计算加速度（二阶导数）
    pp_acceleration = fnder(pp, 2);
    acceleration(:, axis) = ppval(pp_acceleration, t_fine);
end

% 创建图形窗口
figure;
set(gcf, 'Position', [100, 100, 1200, 800]);

% 对每个轴绘制子图
for axis = 1:num_axes
    % ==== 位置曲线 ====
    subplot(num_axes, 1, axis);
    plot(t1, points1_new(:, axis),'LineWidth', 1.5,'DisplayName', '直接插值');
%     plot(t1, points1_new(:, axis), 'o', 'MarkerSize', 4, 'DisplayName', '替换后数据');
    hold on;
%     plot(t_fine, positions_fit(:, axis), 'LineWidth', 1.5, 'DisplayName', '样条插值');
%     hold off;

    ylabel('角度');
    legend;
    grid on;
end
    xlabel('时间');
    title(['轴 ', num2str(axis), ' - 位置']);

figure;
for axis = 1:num_axes
    subplot(num_axes, 1, axis);
    % ==== 速度曲线 ====
    plot(t_fine, velocity(:, axis), 'LineWidth', 1.5, 'Color', [0.8 0.2 0.2]);


    ylabel('速度');
    grid on;
end
    xlabel('时间');
    title(['轴 ', num2str(axis), ' - 速度']);

figure;
for axis = 1:num_axes
    % ==== 加速度曲线 ====
    subplot(num_axes, 1,axis );
    plot(t_fine, acceleration(:, axis), 'LineWidth', 1.5, 'Color', [0.2 0.6 0.2]);

    ylabel('加速度');
    grid on;
end
    title(['轴 ', num2str(axis), ' - 加速度']);
    xlabel('时间');

% 调整子图间距
set(gcf, 'Position', [100, 100, 1200, 800]);