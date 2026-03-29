L(1) = Link([0,300,0,0],'modified');
L(2) = Link([0,0,100,pi/2],'modified');
L(3) = Link([0,0,290,0],'modified');
L(4) = Link([0,300,85,pi/2],'modified');
L(5) = Link([0,0,0,-pi/2],'modified');
L(6) = Link([0,0,0,pi/2],'modified');

L2(1) = Link([0,0,0,0],'modified');
L2(2) = Link([0,98,0,pi/2],'modified');
L2(3) = Link([0,0,243.5,pi],'modified');
L2(4) = Link([0,-11.5,211,pi],'modified');
L2(5) = Link([0,86,0,-pi/2],'modified');
L2(6) = Link([0,0,0,pi/2],'modified');

 Robot1 = SerialLink(L,'name','Robot1');
 Robot2 = SerialLink(L2,'name','Robot2');
 T_R12R2 = [0,-1,0,821.743187414267;
            1,0,0,-649.716451921158;
            0,0,1,361.403566579465;
            0,0,0,1];
Robot2.base = T_R12R2;

t = [1:100];
test_ql_0 = [0,pi/3-pi/2,0,0,-pi/3,0];%主臂初始角度

test_qf_0 = [ 1.3517   -0.1604-pi/2   -0.9667-pi/2    0.7645+pi/2   -1.5708    1.3517];%从臂初始角度

test_V_end = [0,-1.5,0,0,0,0]';%刚体相对于世界坐标系移动速度

t_offset = [0,-500,0];
for i=t
    [JL,V_ql] = Robot1_jacob0_caculate(test_ql_0,[0,0,0],test_V_end);%计算主臂的雅可比以及各个轴的角速度
    
    JF = Robot2_jacob0_caculate(test_qf_0,[0,0,0],T_R12R2);%计算从臂的雅可比
    
    V_qf = JF\test_V_end;%计算从臂的各个轴的角速度
    
    test_ql_0 = test_ql_0 + 1*V_ql';%主臂关节角度变化
    test_qf_0 = test_qf_0 +V_qf';%从臂关节角度变化
    
    
    %画图
    Robot1.plot(test_ql_0+[0,pi/2,0,0,0,0]);
    hold on;
    Robot2.plot(test_qf_0+[0,pi/2,pi/2,-pi/2,0,0]);
    
    %测试每个阶段，机械臂末端相对距离
    T1 = Robot1.fkine(test_ql_0+[0,pi/2,0,0,0,0]);
    T2 = Robot2.fkine(test_qf_0+[0,pi/2,pi/2,-pi/2,0,0]);
    t_offset = T2.t-T1.t
    
end




