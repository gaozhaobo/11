% 假设 points1 和 points2 是3行101列的矩阵，格式如下：
% points1 = [x1; y1; z1] （共101列，每列是一个三维点）
% points2 = [x2; y2; z2]

% 提取坐标
x1 = points1_avoid_final(1, :);
y1 = points1_avoid_final(2, :);
z1 = points1_avoid_final(3, :);
x2 = points1(1, :);
y2 = points1(2, :);
z2 = points1(3, :);

% 绘制三维散点图
figure;
hold on; % 保持图形，叠加绘图

% 绘制 points1（红色圆圈）
scatter3(x1, y1, z1, 'r','filled', 'DisplayName', '避障轨迹点'); 

% 绘制 points2（蓝色叉号）
scatter3(x2, y2, z2, 'g', 'filled','DisplayName', '原始轨迹点'); 

% 添加图例
legend('Location', 'best'); 

% 添加坐标轴标签和标题
xlabel('X轴','FontSize', 12);
ylabel('Y轴','FontSize', 12);
zlabel('Z轴','FontSize', 12);
title('避障前后轨迹对比图','FontSize', 12);

% 调整视角（可选）
% view(45, 30); % 设置视角角度
grid on;      % 显示网格
hold off;
 hold on;
plot3(x1, y1, z1, 'r-', 'LineWidth',1,'DisplayName', '避障轨迹线');
hold on;
hold on;
plot3(x2, y2, z2, 'g-', 'LineWidth', 1,'DisplayName', '原始轨迹线');