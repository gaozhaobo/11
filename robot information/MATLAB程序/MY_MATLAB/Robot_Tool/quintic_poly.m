function [q, qd, qdd] = quintic_poly(q0, qf, t, T)%归一化后的，时间T必须为1
    % 五次多项式系数计算
    a0 = q0;
    a1 = 0; % 初始速度设为0
    a2 = 0; % 初始加速度设为0
    a3 = (10*(qf - q0)) / T^3;
    a4 = (-15*(qf - q0)) / T^4;
    a5 = (6*(qf - q0)) / T^5;
    
    % 计算轨迹
    tau = t / T;
    q = a0 + a1*tau + a2*tau.^2 + a3*tau.^3 + a4*tau.^4 + a5*tau.^5;
    qd = (a1 + 2*a2*tau + 3*a3*tau.^2 + 4*a4*tau.^3 + 5*a5*tau.^4) / T;
    qdd = (2*a2 + 6*a3*tau + 12*a4*tau.^2 + 20*a5*tau.^3) / T^2;
end