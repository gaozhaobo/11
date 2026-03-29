function [theta_interp, velocity_interp, acceleration_interp, t_interp] = cubicInterpolation(...
    points1, points1_v, points2, points2_v, total_time, varargin)
% CUBICINTERPOLATION 多轴三次多项式轨迹插值
% 输入参数:
%   points1: 1x6 起始点角度 (rad)
%   points1_v: 1x6 起始点速度 (rad/s)
%   points2: 1x6 终止点角度 (rad)
%   points2_v: 1x6 终止点速度 (rad/s)
%   total_time: 标量，运动总时间 (s)
%   varargin: 可选参数，可指定插值时间向量
%
% 输出参数:
%   theta_interp: Nx6 插值角度 (rad)
%   velocity_interp: Nx6 插值速度 (rad/s)
%   acceleration_interp: Nx6 插值加速度 (rad/s²)
%   t_interp: Nx1 插值时间向量 (s)

% ================== 参数检查与预处理 ==================
% 验证输入维度
assert(isequal(size(points1), [1 6]), 'points1应为1x6矩阵');
assert(isequal(size(points1_v), [1 6]), 'points1_v应为1x6矩阵');
assert(isequal(size(points2), [1 6]), 'points2应为1x6矩阵');
assert(isequal(size(points2_v), [1 6]), 'points2_v应为1x6矩阵');
assert(isscalar(total_time) && total_time > 0, 'total_time应为正标量');

% 生成插值时间向量
if nargin > 5
    t_interp = varargin{1}(:); % 强制转为列向量
else
    % 默认生成100个等间隔点
    t_interp = linspace(0, total_time, 100)';
end

% ================== 预分配内存 ==================
num_samples = length(t_interp);
theta_interp = zeros(num_samples, 6);
velocity_interp = zeros(num_samples, 6);
acceleration_interp = zeros(num_samples, 6);

% ================== 逐轴计算三次多项式 ==================
for axis = 1:6
    % 提取当前轴参数
    q0 = points1(axis);         % 初始位置
    v0 = points1_v(axis);       % 初始速度
    qT = points2(axis);         % 终止位置
    vT = points2_v(axis);       % 终止速度
    T = total_time;             % 总时间
    
    % 计算三次多项式系数
    A = [T^2    T^3;
         2*T    3*T^2];
    b = [qT - q0 - v0*T;
         vT - v0];
    
    % 解线性方程组 (矩阵求逆)
    x = A \ b;
    a2 = x(1);
    a3 = x(2);
    
    % 生成轨迹
    t = t_interp;  % 当前轴的插值时间
    theta_interp(:, axis) = q0 + v0*t + a2*t.^2 + a3*t.^3;
    velocity_interp(:, axis) = v0 + 2*a2*t + 3*a3*t.^2;
    acceleration_interp(:, axis) = 2*a2 + 6*a3*t;
end

% ================== 可视化验证 (可选) ==================
% 取消注释以下代码查看第一个轴的轨迹
% figure;
% subplot(3,1,1); plot(t_interp, theta_interp(:,1)); title('位置'); ylabel('rad');
% subplot(3,1,2); plot(t_interp, velocity_interp(:,1)); title('速度'); ylabel('rad/s');
% subplot(3,1,3); plot(t_interp, acceleration_interp(:,1)); title('加速度'); ylabel('rad/s²');
% xlabel('时间 (s)');
end