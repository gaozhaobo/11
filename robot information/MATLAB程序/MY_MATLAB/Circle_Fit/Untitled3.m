figure; % 创建新的图形窗口
hold on; % 保持图形

% 生成10组随机点集，每一列代表一个点集
points = [points1;points2;points3;points4;points5;points6;points7;points8;points9;points10;points11];
color = hsv(11);
% 对每一组点集进行绘制
for i = 1:11
    scatter3(points(:,1,i), points(:,2,i), points(:,3,i), 'filled');
end

xlabel('X'); % 设置X轴标签
ylabel('Y轴'); % 设置Y轴标签
zlabel('Z轴'); % 设置Z轴标签
title('多组三维点集示例'); % 设置标题

hold off; % 关闭"保持"状态，可以将额外的绘制添加到同一图形中
