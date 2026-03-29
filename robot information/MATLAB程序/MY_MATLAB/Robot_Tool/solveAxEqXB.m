function X_ls = solveAxEqXB(A, B)
    % A 和 B 均为 N x 4 的矩阵，N 是 4 的倍数
    [N_row, n_columns] = size(A);
    assert(N_row == size(B, 1));
    assert(n_columns == 4);
    
    num_poses = N_row / 4; % 每个 4x4 位姿变换矩阵的数量
    
    % 初始化用于最小二乘解的参数
    A_sys = []; % 系统方程的左侧
    B_sys = []; % 系统方程的右侧
    
    % 遍历每个位姿
    for i = 1:num_poses
        % 提取 4x4 位姿变换矩阵
        Ai = reshape(A((i-1)*4+1:i*4, :), [4, 4]);
        Bi = reshape(B((i-1)*4+1:i*4, :), [4, 4]);

        % 将 Ai^-1 作为左侧，Bi 作为右侧进行变换
        Ai_inv = inv(Ai); 
        A_sys = [A_sys; Ai_inv(1:3, :)*Bi(1:3, 1:3)]; % 相应的变换
        B_sys = [B_sys; Ai_inv(1:3, 4) - Bi(1:3, 4)]; % 平移部分
    end
    
    % 使用最小二乘法求解 A_sys * x = B_sys
    % x = (A_sys' * A_sys) \ (A_sys' * B_sys);
    x = A_sys \ B_sys; % 等效于求解最小二乘问题

    % 组织输出
    % 构造最终的位姿变换矩阵
    R = reshape(x(1:9), [3, 3]); % 提取旋转部分
    t = x(10:12); % 提取平移部分
    
    % 确保R为正交矩阵
    [Q, ~] = qr(R);
    
    % 整合成 4x4 位姿变换矩阵
    X_ls = [Q, t; 0, 0, 0, 1]; % 最终输出的位姿变换矩阵
end

