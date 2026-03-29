% 假设您有六组起点和终点坐标，分别存储在 start_points 和 end_points 矩阵中
% start_points = [x1, y1, z1;  % 第一组起点坐标
%                 x2, y2, z2;  % 第二组起点坐标
%                 ...           % 其他组的起点坐标
%                 xn, yn, zn];  % 第n组起点坐标
start_points = zeros(6,3);
start_points = Robot_axis(1:3,1:6)';
directions = Robot_axis(4:6,:)';
% end_points = [u1, v1, w1;    % 第一组终点坐标
%               u2, v2, w2;    % 第二组终点坐标
%               ...             % 其他组的终点坐标
%               un, vn, wn];    % 第n组终点坐标

vector_length = 1000; % 假设长度为 5

% 计算终点坐标
end_points = start_points + vector_length * directions;

% 绘制六组向量
figure;
hold on;
quiver3(start_points(:,1),start_points(:,2),start_points(:,3),directions(:,1),directions(:,2),directions(:,3),'AutoScale', true);
% quiver3(start_points(:, 1), start_points(:, 2), start_points(:, 3), ...
%         directions(:, 1), directions(:, 2), directions(:, 3), 0);

% 添加标签和标题
xlabel('X');
ylabel('Y');
zlabel('Z');
title('Six Vectors');

% 显示图例
%legend('Vector 1', 'Vector 2', 'Vector 3', 'Vector 4', 'Vector 5', 'Vector 6');
