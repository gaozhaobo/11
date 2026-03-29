function [pos_norm, vel_norm, acc_norm] = generate_s_curve(T, dt)
    % 运动约束参数
    j_max = 4;     % 最大加加速度 [m/s³]
    a_max = 2;      % 最大加速度 [m/s²]
    v_max = 0.5;    % 最大速度 [m/s]
    
    % 时间参数计算
    t1 = a_max/j_max;          % 加加速段时间
    t2 = (v_max - 0.5*j_max*t1^2)/a_max + t1; % 匀加速段时间
    t3 = t1 + t2;              % 减加速段时间
    t7 = T - t3;               % 匀速段时间
    
    % 初始化输出
    t = 0:dt:T;
    jerk = zeros(size(t));
    accel = zeros(size(t));
    vel = zeros(size(t));
    pos = zeros(size(t));
    
    % 分段生成曲线
    for i = 1:length(t)
        if t(i) < t1
            % 加加速段
            jerk(i) = j_max;
            accel(i) = j_max*t(i);
        elseif t(i) < t2
            % 匀加速段
            jerk(i) = 0;
            accel(i) = a_max;
        elseif t(i) < t3
            % 减加速段
            jerk(i) = -j_max;
            accel(i) = a_max - j_max*(t(i)-t2);
        elseif t(i) < t7
            % 匀速段
            jerk(i) = 0;
            accel(i) = 0;
        else
            % 对称减速段（代码略）
        end
        
        % 积分计算速度和位置
        vel(i) = trapz(t(1:i), accel(1:i));
        pos(i) = trapz(t(1:i), vel(1:i));
    end
    
    % 归一化处理
    pos_norm = pos/max(pos);
    vel_norm = vel/max(vel);
    acc_norm = accel/max(accel);
end