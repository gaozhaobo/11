function Ty = Trans_Robot_Camera(T2,T1)%T1,T2分别相机和机器人坐标系下的点集，为n行3列的矩阵，该接口准备废弃
%计算相机坐标系相对于机器人坐标系的位姿变换矩阵
mean_pts1 = mean(T1,1);
mean_pts2 = mean(T2,1);

% 将点集根据中心点进行中心化
centered_pts1 = T1 - mean_pts1;
centered_pts2 = T2 - mean_pts2;

% 计算两组中心化点集之间的协方差矩阵
H = centered_pts1' * centered_pts2;

% 对协方差矩阵进行奇异值分解（SVD）
[U,~,V] = svd(H);

% 计算旋转矩阵 R
Ry = V*U';
ty = -Ry * mean_pts1' + mean_pts2';

% 将旋转矩阵 R 和平移矩阵 t 合并为变换矩阵
Ty = [Ry, ty; 0, 0, 0, 1];

end