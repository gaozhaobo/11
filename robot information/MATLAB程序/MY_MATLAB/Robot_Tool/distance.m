function [My] = distance(points1,points2)
% 假设点集为Nx3的矩阵，表示N个三维空间中的点
% points = [x1, y1, z1; 
%           x2, y2, z2; 
%           ... 
%           xn, yn, zn];


% 计算点的中心
center1 = mean(points1);

% 将点集居中
centered1 = points1 - center1;

% 进行奇异值分解
[~, ~, V] = svd(centered1);

% 提取最小的奇异值对应的奇异向量，即为平面法向量
normal1 = V(:,end);

% 输出平面方程
disp(['点集所在平面的法向量为: [', num2str(normal1'), ']']);

center2 = mean(points2);

% 将点集居中
centered2 = points2 - center2;

% 进行奇异值分解
[~, ~, V] = svd(centered2);

% 提取最小的奇异值对应的奇异向量，即为平面法向量
normal2 = V(:,end);

% 输出平面方程
disp(['点集所在平面的法向量为: [', num2str(normal2'), ']']);

line1_2 = center1-center2;

unit1 = normal1/ norm(normal1); % 计算B的单位向量
unit2 = normal2/ norm(normal2);

y1 = dot(line1_2, unit1); % 计算A在B方向上的投影
y2 = dot(line1_2, unit2);

My = [y1,y2];

end


