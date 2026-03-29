
% 定义常数（可自行修改a和b的值）
a = 0.3;
b = 0.096;

% 定义变量范围（x > 0, y > 10）
x = linspace(0, 50, 100);    % x范围：0到20，100个点
y = linspace(10, 30, 100);   % y范围：10到30，100个点（满足y > 10）

% 生成网格坐标
[X, Y] = meshgrid(x, y);

% 计算函数值（注意元素级运算）
%Z = ((a .* X ./ Y) - (b .* X ./ (Y.^3)))/0.0015;
Z = ((b .* X ./ (Y.^3)))/0.0015;
% -------------------------------
% 绘制三维曲面图（x > 0, y > 10）
% -------------------------------
figure('Name', '3D Surface Plot (y > 10)', 'Position', [100 100 800 600]);
surf(X, Y, Z, 'EdgeColor', 'none');
colormap(parula);            % 颜色映射
xlabel('Y (Y > 0)', 'FontSize', 14);
ylabel('Z (Z > 10)', 'FontSize', 14);
zlabel('像素误差值', 'FontSize', 14);
title('像素误差曲面图/pixels', 'FontSize', 14);
colorbar;
view(30, 30);                % 调整视角

% -------------------------------
% 绘制等高线图（x > 0, y > 10）
% -------------------------------
figure('Name', 'Contour Plot (Z > 10)', 'Position', [200 200 800 600]);
contourf(X, Y, Z, 20, 'LineWidth', 1.5);  % 20条等高线
colormap(jet);               % 颜色映射
xlabel('Y (Y > 0)','FontSize', 18);
ylabel('Z (Z > 10)','FontSize', 18);
title('等高线图（Z > 10）','FontSize', 18);
colorbar;
axis tight;