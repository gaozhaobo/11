figure; % 创建新的图形窗口
% 假设M1到M6是六个3维向量
V1 = Robot_axis_after_doubleR(4:6,1);
V2 = Robot_axis_after_doubleR(4:6,2);
V3 = Robot_axis_after_doubleR(4:6,3);
V4 = Robot_axis_after_doubleR(4:6,4);
V5 = Robot_axis_after_doubleR(4:6,5);
V6 = Robot_axis_after_doubleR(4:6,6);
C1 = Robot_axis_after_doubleR(1:3,1);
C2 =Robot_axis_after_doubleR(1:3,2);
C3 = Robot_axis_after_doubleR(1:3,3);
C4 = Robot_axis_after_doubleR(1:3,4);
C5 = Robot_axis_after_doubleR(1:3,5);
C6 = Robot_axis_after_doubleR(1:3,6);
V1 = V1/norm(V1);
V2 = V2/norm(V2);
V3 = V3/norm(V3);
V4 = V4/norm(V4);
V5 = V5/norm(V5);
V6 = V6/norm(V6);
% 假设start_points是起点坐标矩阵，norm_vectors是法向量矩阵
start_points = [C1';C2';C3';C4';C5';C6']; % 以此类推
norm_vectors = [V1'; V2'; V3';V4';V5';V6']; % 以此类推

% 计算终点坐标
end_points = start_points + 1000*norm_vectors;

% 绘制向量和法向量
quiver3(start_points(:,1), start_points(:,2), start_points(:,3), norm_vectors(:,1), norm_vectors(:,2), norm_vectors(:,3), 'Autoscale', 'off');
hold on; % 保持图形，以便在同一图中绘制终点
colors = hsv(6);
for i =1:6
    quiver3(start_points(i,1), start_points(i,2), start_points(i,3), end_points(i,1)-start_points(i,1), end_points(i,2)-start_points(i,2), end_points(i,3)-start_points(i,3),'color',colors(i,:), 'Autoscale', 'off');
end


% 绘制x轴
line([0 1000], [0 0], [0 0], 'Color', 'r', 'LineWidth', 2);
text(1, 0, 0, 'X', 'FontSize', 14);

% 绘制y轴
line([0 0], [0 1000], [0 0], 'Color', 'g', 'LineWidth', 2);
text(0, 1, 0, 'Y', 'FontSize', 14);

% 绘制z轴
line([0 0], [0 0], [0 1000], 'Color', 'b', 'LineWidth', 2);
text(0, 0, 1, 'Z', 'FontSize', 14); 

axis equal;