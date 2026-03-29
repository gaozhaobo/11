function [q_fit, qd_fit, qdd_fit, t_fine] = cubic_spline_joints(theta, t, t_fine)
% 输入参数：
%   theta: N×6矩阵，每列为单个关节的角度序列，行对应时间节点
%   t: N×1向量（可选），原始时间节点，默认从0开始等间隔
%   t_fine: M×1向量（可选），插值后的时间节点，默认生成100个点
% 输出参数：
%   theta_fit: M×6矩阵，插值后的关节角度
%   velocity_fit: M×6矩阵，各关节速度
%   acceleration_fit: M×6矩阵，各关节加速度
%   t_fine: 插值时间节点

% 检查输入参数
if nargin < 2 || isempty(t)
    t = (0:size(theta,1)-1)'; % 默认时间从0开始，步长1
end

if nargin < 3 || isempty(t_fine)
    t_fine = linspace(t(1), t(end), 24)'; % 默认151个插值点
end

% 预分配输出矩阵
num_joints = size(theta, 2);
q_fit = zeros(length(t_fine), num_joints);
qd_fit = zeros(length(t_fine), num_joints);
qdd_fit = zeros(length(t_fine), num_joints);

% 对每个关节单独处理
for j = 1:num_joints
    % 提取当前关节的角度序列
    theta_j = theta(:, j);
    
    % 三次样条插值（自然样条边界条件）
    pp = spline(t, theta_j);
    
    % 计算插值角度
    q_fit(:, j) = ppval(pp, t_fine);
    
    % 计算速度（一阶导数）
    pp_der1 = fnder(pp, 1);
    qd_fit(:, j) = ppval(pp_der1, t_fine);
    
    % 计算加速度（二阶导数）
    pp_der2 = fnder(pp, 2);
    qdd_fit(:, j) = ppval(pp_der2, t_fine);
end
end