function [coeffs, t, theta, velocity, acceleration] = quintic_traj(theta0, v0, a0_initial, thetaT, vT, aT_final, T, dt)
    % 输入参数说明：
    % theta0: 初始角度数组（1×6）
    % v0: 初始速度数组（1×6）
    % a0_initial: 初始加速度数组（1×6）
    % thetaT: 终止角度数组（1×6）
    % vT: 终止速度数组（1×6）
    % aT_final: 终止加速度数组（1×6）
    % T: 总时间
    % dt: 时间步长
    
    % 检查输入维度
    assert(all(size(theta0) == [1,6]), 'theta0应为1×6数组');
    assert(all(size(thetaT) == [1,6]), 'thetaT应为1×6数组');
    assert(all(size(v0) == [1,6]), 'v0应为1×6数组');
    assert(all(size(vT) == [1,6]), 'vT应为1×6数组');
    assert(all(size(a0_initial) == [1,6]), 'a0_initial应为1×6数组');
    assert(all(size(aT_final) == [1,6]), 'aT_final应为1×6数组');
    
    % 预分配系数矩阵（6×6，每行对应一个关节的系数a0~a5）
    coeffs = zeros(6, 6); 
    
    % 时间序列
    t = 0:dt:T;
    n = length(t);
    
    % 预分配轨迹数据（位置、速度、加速度）
    theta = zeros(n, 6);
    velocity = zeros(n, 6);
    acceleration = zeros(n, 6);
    
    % 对每个关节单独计算五次多项式
    for j = 1:6
        % 提取当前关节的初始/终止条件
        q0 = theta0(j);
        qT = thetaT(j);
        v0j = v0(j);
        vTj = vT(j);
        a0j = a0_initial(j);
        aTj = aT_final(j);
        
        % 计算基础系数
        a0 = q0;
        a1 = v0j;
        a2 = a0j / 2;
        
        % 构造矩阵A和向量b
        A = [T^3, T^4, T^5;
             3*T^2, 4*T^3, 5*T^4;
             6*T, 12*T^2, 20*T^3];
        b = [qT - a0 - a1*T - a2*T^2;
             vTj - a1 - 2*a2*T;
             aTj - 2*a2];
        
        % 求解线性方程组
        x = A \ b;
        a3 = x(1);
        a4 = x(2);
        a5 = x(3);
        
        % 存储系数
        coeffs(j, :) = [a0, a1, a2, a3, a4, a5];
        
        % 计算轨迹
        theta(:, j) = a0 + a1*t' + a2*t'.^2 + a3*t'.^3 + a4*t'.^4 + a5*t'.^5;
        velocity(:, j) = a1 + 2*a2*t' + 3*a3*t'.^2 + 4*a4*t'.^3 + 5*a5*t'.^4;
        acceleration(:, j) = 2*a2 + 6*a3*t' + 12*a4*t'.^2 + 20*a5*t'.^3;
    end
end