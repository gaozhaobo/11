function [vec_V_qF,vec_V_qL] = Caculate_Robot2_V_with_Robot1_continue(q1,q2,tool1,tool2,V1,T_offset,single_time,step_nums)
%用于计算双臂紧协调操作
%根据机械臂1的6关节实时速度、位置以及机械臂2各个关节的实时位置计算机械臂2的速度
%参数1：机械臂1的各个关节位置
%参数2：机械臂2的各个关节位置
%参数3：机械臂1的工具坐标系偏移
%参数4：机械臂2的工具坐标系偏移
%参数5：机械臂1末端相对于世界坐标系的速度
%参数6：被加持刚体两个被加持点的相对位姿,包括频移和旋转
%参数7：单次步长的持续时间，单位ms
%参数8：步长总数
%输出：输出1为从臂各个关节速度，输出2为主臂各个关节速度

T_Robot12Robot2 = [0,-1,0,821.743187414267;
                   1,0,0,-649.716451921158;
                   0,0,1,361.403566579465;
                   0,0,0,1];%机械臂2相对于机械臂1的基坐标系的位姿变换矩阵（需要手动更新）

vec_V_qF = zeros(6,step_nums);  
vec_V_qL = zeros(6,step_nums); 
    T_tool1 = [1,0,0,0;
               0,1,0,0;
               0,0,1,0;
               0,0,0,1];
    T_tool1(1,4) = tool1(1,1);
    T_tool1(2,4) = tool1(1,2);
    T_tool1(3,4) = tool1(1,3);

    T_offset_end = T_tool1*T_offset;
for i = 1:step_nums%
    J2 = Robot2_jacob0_caculate(q2,tool2,T_Robot12Robot2);%机械臂2（即从臂）的雅可比矩阵

    [JL,V_qL] = Robot1_jacob0_caculate(q1,tool1,V1);%第二个值为主臂各个关节的移动速度
    JL_a = JL(4:6,:);


    [JL,~] = Robot1_jacob0_caculate_2(q1,T_offset_end,V1);
    JL_l = JL(1:3,:);

    J1 = [JL_l;JL_a];%构成机械臂1的雅可比

    V_2 = J2\J1*V_qL;%从臂各个关节的速度
    V_qF = V_2;
    
    vec_V_qF(:,i) =V_qF;
    vec_V_qL(:,i) =V_qL;
    %更新参数
    q1 = q1 + (single_time/1000)*V_qL';
    q2 = q2 + (single_time/1000)*V_qF';
end


end