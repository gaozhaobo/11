
t_total = 1;       % 总时间(秒)
t_samples = 0:0.01:t_total; % 时间采样点
Error1 = double_arms_corporate_func(t_total,t_samples);

t_samples = 0:0.005:t_total; % 时间采样点
Error2 = double_arms_corporate_func(t_total,t_samples);

t_samples = 0:0.002:t_total; % 时间采样点
Error3 = double_arms_corporate_func(t_total,t_samples);

t_samples = 0:0.001:t_total; % 时间采样点
Error4 = double_arms_corporate_func(t_total,t_samples);

% 生成示例数据（实际使用时替换为你的数据）
% Error1 = rand(1,10);       % 1x10 矩阵（精度0.1）
% Error2 = rand(1,100);      % 1x100 矩阵（精度0.01）
% Error3 = rand(1,1000);     % 1x1000 矩阵（精度0.001）

% 创建对应的横坐标向量
x1 = linspace(0, 1, 101);     % 
x2 = linspace(0, 1, 201);    % 
x3 = linspace(0, 1, 501);    % 
x4 = linspace(0, 1, 1001);   % 

% 绘制图形
figure;
hold on;

% 绘制 Error1（用圆圈标记突显稀疏数据）
plot(x1, Error1, '-', 'LineWidth', 1.2, 'MarkerSize', 8, 'DisplayName', 'Error1 (fs=100)');

% 绘制 Error2（用虚线区分中等密度数据）
plot(x2, Error2, '-', 'LineWidth', 1.2, 'DisplayName', 'Error2 (fs=200)');

plot(x3, Error3, '-', 'LineWidth', 1.2, 'DisplayName', 'Error2 (fs=500)');

% 绘制 Error3（实线表示高密度数据）
plot(x4, Error4, '-', 'LineWidth', 1.2, 'DisplayName', 'Error3 (fs=1000)');

hold off;

% 图形修饰
xlabel('归一化时间 (0-1)', 'FontSize', 12);
ylabel('误差', 'FontSize', 12);
title('不同采样频率下误差对比', 'FontSize', 12);
legend('Location', 'best');
grid on;

% 设置坐标轴范围
xlim([0 1]);