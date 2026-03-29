figure;
title('关节运动曲线图', 'FontSize', 12);
for j = 1:6
    subplot(6, 1, j);    % 第j个子图
    
    % 绘制数组A（实线）
    plot(t_A, A(:, j), '-', 'LineWidth', 1.5, 'DisplayName', '关节运动轨迹');
    hold on;
    
    % 绘制数组B（虚线）
    plot(t_B, B(:, j), '--', 'LineWidth', 1.5, 'DisplayName', '避障调整曲线');
    hold off;

    ylabel('角度 (rad)','FontSize', 12);
    title(['关节 ', num2str(j)],'FontSize', 12)
    grid on;
    
    % 设置x轴范围（可选）
    xlim([0, 10]);        % 显示完整的时间范围
end
    % 添加标签和标题

    xlabel('时间 (s)','FontSize', 12);
    legend('Location', 'best','FontSize', 12);

% 调整子图间距
set(gcf, 'Position', [100, 100, 1200, 800]);  % 调整窗口大小