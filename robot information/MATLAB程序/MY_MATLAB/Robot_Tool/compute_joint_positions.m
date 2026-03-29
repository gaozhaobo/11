function joint_positions = compute_joint_positions(robot, q)%计算关节位置
%输入参数1：机器人
%参数2：关节状态
    T = robot.base;
    n = robot.n;
    joint_positions = zeros(n+1, 3);
    joint_positions(1, :) = transl(T)';
    for i = 1:n
        A = robot.A(i, q);%表示在给定的角度下，指定关节的位姿。
        T = T * A;
        joint_positions(i+1, :) = transl(T)';
    end
end