function [V_qf] = Caculate_V_qf_with_ql(ql,qf,V_ql)

T_Robot12Robot2 = [0,-1,0,821.743187414267;
                   1,0,0,-649.716451921158;
                   0,0,1,361.403566579465;
                   0,0,0,1];%机械臂2相对于机械臂1的基坐标系的位姿变换矩阵（需要手动更新）
               
J2 = Robot2_jacob0_caculate(q2,tool2,T_Robot12Robot2);%机械臂2（即从臂）的雅可比矩阵



end