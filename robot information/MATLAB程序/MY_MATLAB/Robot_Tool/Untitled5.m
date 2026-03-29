% 初始化UR5机械臂模型（RVCTools）
mdl_ur5; % 加载RVCTools的UR5模型
robot = ur5; 
q0 = [0, -pi/3, pi/3, -pi/2, -pi/2, 0]; % 初始关节角
T0 = robot.fkine(q0); % 初始末端位姿（齐次变换矩阵）

% 轨迹参数设置
p_start = T0.t; % 起始位置[x; y; z]
p_goal = p_start + [0.3, -0.2, 0.1]'; % 目标位置
T_total = 2; % 总时间[s]
dt = 0.01; % 时间步长
t = 0:dt:T_total; % 时间向量
N = length(t);

% 七段S型速度曲线生成（位置归一化）
[pos_norm, vel_norm, acc_norm] = generate_s_curve(T_total, dt);

% 笛卡尔空间直线插补
X_des = zeros(6, N); % 笛卡尔轨迹[位置; 姿态角速度]
for k = 1:N
    % 位置插补
    X_des(1:3, k) = p_start + pos_norm(k)*(p_goal - p_start);
    
    % 姿态保持恒定（可扩展为SLERP插值）
    X_des(4:6, k) = [0; 0; 0]; % 无角速度
end

% 逆运动学求解（RVCTools方法）
q = zeros(N, 6); % 关节角度
qd = zeros(N, 6); % 关节速度
qdd = zeros(N, 6); % 关节加速度

% 逆运动学选项配置
ik_options = {'tol', 1e-6, 'alpha', 0.5, 'maxiter', 1000};

for k = 1:N
    % 目标位姿（保持姿态不变）
    T_des = transl(X_des(1:3, k)') * T0.R; % 构造齐次矩阵
    
    % 逆运动学求解（使用阻尼最小二乘法）
    [q(k,:), exitflag] = robot.ikine(T_des, 'q0', q0, ik_options{:});
    
    if exitflag ~= 1
        warning('逆运动学求解失败于k=%d', k);
        q(k,:) = q(k-1,:); % 使用上一时刻解
    end
    
    % 更新初始猜测
    q0 = q(k,:);
    
    % 计算雅可比矩阵
    J = robot.jacob0(q(k,:));
    
    if k > 1
        % 关节速度计算（差分法）
        qd(k,:) = (q(k,:) - q(k-1,:))/dt;
        
        % 精确速度计算（雅可比伪逆）
        % xd = (X_des(1:3,k)-X_des(1:3,k-1))/dt;
        % qd(k,:) = pinv(J(1:3,:)) * xd;
        
        if k > 2
            % 关节加速度计算（二次差分）
            qdd(k,:) = (qd(k,:) - qd(k-1,:))/dt;
        end
    end
end

% 可视化结果
figure('Name','Joint Motion Profile','Position',[100 100 1000 800])
for jnt = 1:6
    subplot(3,2,jnt);
    
    % 位置曲线
    yyaxis left
    plot(t, q(:,jnt));
    hold on;
    ylabel(['q_',num2str(jnt),' (rad)'])
    
    % 速度曲线
    yyaxis right
    plot(t(2:end), qd(2:end,jnt), '--')
    plot(t(3:end), qdd(3:end,jnt), ':')
    ylabel('qd/qdd (rad/s)')
    
    title(['关节 ',num2str(jnt),' 运动曲线'])
    xlabel('时间 (s)')
    legend('位置','速度','加速度')
    grid on
end

% % S型曲线生成函数（RVCTools兼容版）
% function [pos_norm, vel_norm, acc_norm] = generate_s_curve(T, dt)
%     % 运动约束参数
%     j_max = 4;     % 最大加加速度 [m/s³]
%     a_max = 2;      % 最大加速度 [m/s²]
%     v_max = 0.5;    % 最大速度 [m/s]
%     
%     % 时间参数计算
%     t1 = a_max/j_max;          % 加加速段时间
%     t2 = (v_max - 0.5*j_max*t1^2)/a_max + t1; % 匀加速段时间
%     t3 = t1 + t2;              % 减加速段时间
%     t7 = T - t3;               % 匀速段时间
%     
%     % 初始化输出
%     t = 0:dt:T;
%     jerk = zeros(size(t));
%     accel = zeros(size(t));
%     vel = zeros(size(t));
%     pos = zeros(size(t));
%     
%     % 分段生成曲线
%     for i = 1:length(t)
%         if t(i) < t1
%             % 加加速段
%             jerk(i) = j_max;
%             accel(i) = j_max*t(i);
%         elseif t(i) < t2
%             % 匀加速段
%             jerk(i) = 0;
%             accel(i) = a_max;
%         elseif t(i) < t3
%             % 减加速段
%             jerk(i) = -j_max;
%             accel(i) = a_max - j_max*(t(i)-t2);
%         elseif t(i) < t7
%             % 匀速段
%             jerk(i) = 0;
%             accel(i) = 0;
%         else
%             % 对称减速段（代码略）
%         end
%         
%         % 积分计算速度和位置
%         vel(i) = trapz(t(1:i), accel(1:i));
%         pos(i) = trapz(t(1:i), vel(1:i));
%     end
%     
%     % 归一化处理
%     pos_norm = pos/max(pos);
%     vel_norm = vel/max(vel);
%     acc_norm = accel/max(accel);
% end