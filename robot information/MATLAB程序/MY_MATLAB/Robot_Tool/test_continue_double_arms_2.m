L(1) = Link([0,300,0,0],'modified');
L(2) = Link([0,0,100,pi/2],'modified');
L(3) = Link([0,0,290,0],'modified');
L(4) = Link([0,300,85,pi/2],'modified');
L(5) = Link([0,0,0,-pi/2],'modified');
L(6) = Link([0,0,0,pi/2],'modified');

%((-pi/2)-(0.4*pi/180))
% q1_lim = [-pi/2,pi/2];
% q2_lim = [-pi/6,(90+45)*pi/180];
% q3_lim = [-60*pi/180,pi/2];
% q4_lim = [-pi,pi];
% q5_lim = [-135*pi/180,135*pi/180];
% q6_lim = [-pi,pi];
% L(1).qlim = [-pi/2,pi/2];
% L(2).qlim = [-pi/6,(90+45)*pi/180];
% L(3).qlim = [-60*pi/180,pi/2];
% L(4).qlim = [-pi,pi];
% L(5).qlim = [-135*pi/180,135*pi/180];

L2(1) = Link([0,0,0,0],'modified');
L2(2) = Link([0,98,0,pi/2],'modified');
L2(3) = Link([0,0,243.5,pi],'modified');
L2(4) = Link([0,-11.5,211,pi],'modified');
L2(5) = Link([0,86,0,-pi/2],'modified');
L2(6) = Link([0,0,0,pi/2],'modified');

% q2_1_lim = [-pi,pi];
% q2_2_lim = [0,pi];
% q2_3_lim = [-150*pi/180,150*pi/180];
% q2_4_lim = [-250*pi/180,80*pi/180];
% q2_5_lim = [-pi,pi];
% q2_6_lim = [-pi,pi];
% L2(1).qlim = [-pi,pi];
% L2(2).qlim = [0,pi];
% L2(3).qlim = [-150*pi/180,150*pi/180];
% L2(4).qlim = [-250*pi/180,80*pi/180];

 Robot1 = SerialLink(L,'name','Robot1');
 Robot2 = SerialLink(L2,'name','Robot2');
 T_R12R2 = [0,-1,0,821.743187414267;
                   1,0,0,-649.716451921158;
                   0,0,1,361.403566579465;
                   0,0,0,1];
Robot2.base = T_R12R2;

t = [1:10];
test_ql_0 = [0,pi/3-pi/2,0,0,-pi/3,0];
%test_ql_0 = [-0.6311    0.3908-pi/2    0.7892   -0.0000   -1.1800   -0.6311];

test_qf_0 = [ 1.3517   -0.1604-pi/2   -0.9667-pi/2    0.7645+pi/2   -1.5708    1.3517];
%test_qf_0 = [1.351740644131647  -0.160407390557782-pi/2  -0.966728538207128-pi/2   0.764475179145552+pi/2  -1.570796326794896   1.875339419710480];
%test_qf_0 = [1.0678   -0.1389-pi/2   -0.3641-pi/2    1.3456+pi/2   -1.5708    1.0678];

test_V_end = [0,-15,0,0,0,0.025]';

test_ql_next = test_ql_0;
test_qf_next = test_qf_0;
%t_offset = [0,-500,0];
% t_offset = [1,0,0,0;
%             0,1,0,0;
%             0,0,1,0;
%             0,0,0,1];
% T_rotz = [0.866025403784439  -0.500000000000000                   0                   0
%             0.500000000000000   0.866025403784439                   0                   0
%                    0                   0   1.000000000000000                   0
%                    0                   0                   0   1.000000000000000];
 T_rotz = [1,0,0,0;
           0,1,0,0;
           0,0,1,0;
           0,0,0,1];         
% T_offset = t_offset*T_rotz;
L_error = zeros(1,100);
T1 = Robot1.fkine(test_ql_next+[0,pi/2,0,0,0,0]);
T2 = Robot2.fkine(test_qf_next+[0,pi/2,pi/2,-pi/2,0,0]);
t_offset = (T2.t-T1.t);
table_error(1,1) = t_offset(1,1);
table_error(2,1) = t_offset(2,1);
table_error(2,1) = t_offset(2,1);
L = sqrt(t_offset(1,1)^2+t_offset(2,1)^2+t_offset(3,1)^2);
L_error(1,1) = L;

% [vec_V_qF,vec_V_qL]=Caculate_Robot2_V_with_Robot1_continue(test_ql_next,test_qf_next,[0,0,0],[0,0,0],test_V_end,T_rotz,100,100);
% for i=1:100
%     Robot1.plot(test_ql_next+[0,pi/2,0,0,0,0]);
%     hold on;
%     Robot2.plot(test_qf_next+[0,pi/2,pi/2,-pi/2,0,0]);
%     
%     test_ql_next = test_ql_next+0.1*vec_V_qL(:,i)';
%     test_qf_next = test_qf_next+0.1*vec_V_qF(:,i)';
% end
% T1 = Robot1.fkine(test_ql_next+[0,pi/2,0,0,0,0]);
% T2 = Robot2.fkine(test_qf_next+[0,pi/2,pi/2,-pi/2,0,0]);
% t_offset = T2.t-T1.t;
% L = sqrt(t_offset(1,1)^2+t_offset(2,1)^2+t_offset(3,1)^2);
for i=t

    [V_f,V_l] = Caculate_Robot2_V_with_Robot1_2(test_ql_next,test_qf_next,[0,0,0],[0,0,0],test_V_end,T_rotz);%求得时刻主从臂关节速度
    
    %来验证主臂末端速度是不是始终为设定值
%     [check_JL,check_V_L] = Robot1_jacob0_caculate(test_ql_next,[0,0,0],test_V_end);
%     disp(check_V_L);
    %验证从臂速度值的大小
    check_JF = Robot2_jacob0_caculate(test_qf_next,[0,0,0],T_R12R2);

    check_end_f = check_JF*V_f;
    disp(check_end_f);
    
    test_ql_next = test_ql_next+1*V_l';
    test_qf_next = test_qf_next+1*V_f';
    
    Robot1.plot(test_ql_next+[0,pi/2,0,0,0,0]);
    hold on;
    Robot2.plot(test_qf_next+[0,pi/2,pi/2,-pi/2,0,0]);
      
    T1 = Robot1.fkine(test_ql_next+[0,pi/2,0,0,0,0]);
    T2 = Robot2.fkine(test_qf_next+[0,pi/2,pi/2,-pi/2,0,0]);
    t_offset = T2.t-T1.t;
    
    table_error(1,i) = t_offset(1,1);
    table_error(2,i) = t_offset(2,1);
    table_error(2,i) = t_offset(2,1);
    L = sqrt(t_offset(1,1)^2+t_offset(2,1)^2+t_offset(3,1)^2);
    L_error(1,i) = L;
    %保存图像
    filename = sprintf('image_%d.png', i);
    saveas(gcf, filename); % 保存当前图形为文件
    % 关闭图形窗口（可选）
    %close(gcf); % 关闭当前图形窗口，防止窗口被打开过多
end

points = 1:10;  % 横坐标（点的索引）

% 3. 绘制数据
figure;  % 打开一个新图形窗口
hold on;  % 保持当前图形，允许在同一图形中绘制多条线

plot(points, table_error(1,:), 'b-', 'LineWidth', 2, 'DisplayName', 'X Values');  % 绘制 x 值的线
plot(points, table_error(2,:), 'r-', 'LineWidth', 2, 'DisplayName', 'Y Values');  % 绘制 y 值的线
plot(points, table_error(3,:), 'g-', 'LineWidth', 2, 'DisplayName', 'Z Values');  % 绘制 z 值的线

% 4. 添加标签和图例
xlabel('点数');  % 横坐标标签
ylabel('值');    % 纵坐标标签
title('X, Y, Z Values vs. Point Index');  % 标题
legend show;     % 显示图例
grid on;        % 显示网格

hold off;  % 释放图形保持状态

figure;  % 打开一个新图形窗口
plot(points, L_error, 'b-', 'LineWidth', 2);  % 绘制 B 值的线

% 4. 添加标签和标题
xlabel('点数');  % 横坐标标签
ylabel('值');    % 纵坐标标签
title('值与点索引的关系');  % 图形标题
grid on;        % 显示网格
