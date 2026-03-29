errors = cameraParams.ReprojectionErrors;
rmse = squeeze(sqrt(mean(errors.^2, [1 2]))); % 每个图像的RMS误差

% 绘制条形图
figure;
bar(rmse);
xlabel('图像序号', 'FontSize', 14);
ylabel('重投影误差（像素）', 'FontSize', 14);
title('像素误差图', 'FontSize', 14);

% 绘制水平线并显示平均像素误差
lineObj = yline(0.108, '--r');
legend(lineObj, '平均像素误差', 'Location', 'best', 'FontSize', 14);

% 在纵坐标轴左侧显示平均像素误差的数值
text(-0.5, 0.108, sprintf('%.3f', 0.108), ...
    'HorizontalAlignment', 'right', ...
    'VerticalAlignment', 'middle', ...
    'Color', 'r', ...
    'FontSize', 14);

% 调整坐标轴字体大小
ax = gca;
ax.FontSize = 14;

% 调整坐标轴范围以确保文本不被分割
ylim([0, max(rmse) * 1.1]); % 确保纵坐标轴范围足够