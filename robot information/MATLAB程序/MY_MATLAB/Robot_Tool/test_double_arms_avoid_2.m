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
Robot2.base = [0,-1,0,821.743187414267;1,0,0,-649.716451921158;0,0,1,361.403566579465;0,0,0,1];
Robot1.tool = transl([0,0,300]);
Robot2.tool = transl([0,200,0]);

%q1_start = [0,pi/2,0,0,0,0];
q1_start = [0,1.610262243421289,-0.267034048627577,0,0.227568132000441,0];
q1_end=[ -1.570796326752570   1.610262243421326  -0.267034048628329  0  0.227568132002475 0];
q1_end2=[-1.570796326794897   1.565759112037387  -0.563851485575185  0  0.568888700318562 0];
q1_end3=[-pi/2+pi/12   1.461970168199024  -0.556363179923939 0 0.665189338484507 0];

q2_start = [0,pi/2,pi/2,-pi/2,0,0];
q2_end = [pi/2,pi/2,pi/2,-pi/2,0,0];
% q2_end2 = [pi/2,pi/3,pi/2,-pi/3,0,0];%1.570796326796074   0.576045001137809   0.302152957656782   2.670393307026293   0.000000000003545   1.768103629882338


T=1;
t_samples = 0:0.1:10;
q1 = zeros(length(t_samples), 6);
qd1 = zeros(size(q1));
qdd1 = zeros(size(q1));

q2 = zeros(length(t_samples), 6);
qd2 = zeros(size(q2));
qdd2 = zeros(size(q2));

[~,t_sample,q1, qd1, qdd1] = quintic_traj(q1_start,[0,0,0,0,0,0],[0,0,0,0,0,0],...
        q1_end3,[0,0,0,0,0,0],[0,0,0,0,0,0],10,0.1);
[~,t2_sample,q2, qd2, qdd2] = quintic_traj(q2_start,[0,0,0,0,0,0],[0,0,0,0,0,0],...
        q2_end,[0,0,0,0,0,0],[0,0,0,0,0,0],10,0.1);
% for j = 1:6
%     [q1(:,j), qd1(:,j), qdd1(:,j)] = quintic_poly(...
%         q1_start(j), q1_end2(j), t_samples, T);  
%     [q2(:,j), qd2(:,j), qdd2(:,j)] = quintic_poly(...
%         q2_start(j), q2_end(j), t_samples, T); 
% end

points1 = zeros(3,101);
points2 = zeros(3,101);
for i=1:101
    points1(:,i)=Robot1.fkine(q1(i,:)).t;
    points2(:,i)=Robot2.fkine(q2(i,:)).t;
    
    Robot1.plot(q1(i,:));
    hold on;
    Robot2.plot(q2(i,:));
    hold on;
%     filename = sprintf('image_%d.png', i);
%     saveas(gcf, filename); % 保存当前图形为文件
end
hold on;
plot3(points1(1,:),points1(2,:),points1(3,:), 'g.', 'MarkerSize', 5);
hold on;
plot3(points2(1,:),points2(2,:),points2(3,:), 'b.', 'MarkerSize', 5);

%%避障区间计算
safe_distance = 10;
%计算几个关键点
T1_tool = zeros(4,4);
T2_tool = zeros(4,4);

distance = zeros(101,2);
distance2 = zeros(101,2);
distance3 = zeros(101,1);
distance4 = zeros(101,2);
P_chuizu = zeros(3,101);
for i=1:101
    joint_positions1 = compute_joint_positions(Robot1, q1(i,:));%计算各个关节的位置
    joint_positions2 = compute_joint_positions(Robot2, q2(i,:));%计算各个关节的位置
    
    %取出机械臂1末端点位置
    point1_tool = Robot1.fkine(q1(i,:)).t';
    point1_6 = joint_positions1(7,:);
    point1_5 = joint_positions1(6,:);
    %取出机械臂2末端两个关节以及工具坐标的位置
    point2_6 = joint_positions2(7,:);
    point2_5 = joint_positions2(6,:);
    point2_tool = Robot2.fkine(q2(i,:)).t';
    
    %计算机械臂1末端点距离机械臂2三个关键点连杆的最小距离
    [distance(i,1),P_chuizu(:,i)] = point_to_segment_dist(point1_tool, point2_6, point2_tool);
    
    [distance(i,2),~] = point_to_segment_dist(point1_tool, point2_5, point2_6);
    
    [distance2(i,1),~] = point_to_segment_dist(point1_6, point2_6, point2_tool);
    [distance2(i,2),~] = point_to_segment_dist(point1_6, point2_5, point2_6);
    
    distance3(i,1) = point_to_segment_dist(point2_tool, point1_6, point1_tool);
    
    distance4(i,1) = segment_to_segment_dist(point2_6, point2_tool, point1_6, point1_tool);
    distance4(i,2)= segment_to_segment_dist(point2_5, point2_6, point1_6, point1_tool);
    distance4(i,3)= segment_to_segment_dist(point2_6, point2_tool, point1_5, point1_6);
    distance4(i,4)= segment_to_segment_dist(point2_5, point2_6, point1_5, point1_6); 
    
    %tip：这种情况下，只用考虑机械臂1末端相对于机械臂2工具连杆即可满足要求（安全距离设为130）
end


%创建调整后的点
point1 = zeros(3,18);%机械臂1工具坐标点
point2 = zeros(3,18);%机械臂2垂足所在点

P1_new = zeros(3,18);
P2_new = zeros(3,18);%调整后的垂足点，注意这里还不是末端点
P2_new_tool = zeros(3,18);%在这里定义调整后的末端点

for i=26:51
    point1(:,i-25) = points1(:,i);
    point2(:,i-25) = P_chuizu(:,i);%机械臂2垂足所在点
    
    %调整后的机械臂1工具位置
    [P2_new(:,i-25),P1_new(:,i-25)] = extend_line_segment(point2(:,i-25),point1(:,i-25),130);
%     plot3(point1(1,i-25),point1(2,i-25),point1(3,i-25),'o','MarkerFaceColor', 'r');
%     hold on;
%     plot3(P1_new(1,i-25),P1_new(2,i-25),P1_new(3,i-25),'o','MarkerFaceColor', 'b');
%     hold on;
end

%针对调整后的坐标重新生成轨迹
New_q1 = q1;
for i=27:50
    T_end = Robot1.fkine(q1(i,:));
    T_end.t = P1_new(:,i-25);
    
    New_q1(i,:) = Robot1.ikine(T_end,'q0',New_q1(i-1,:));
end

points1_avoid = zeros(3,101);
points2_avoid = zeros(3,101);
for i=1:101
    points1_avoid(:,i)=Robot1.fkine(New_q1(i,:)).t;
    points2_avoid(:,i)=Robot2.fkine(q2(i,:)).t;
    
    Robot1.plot(New_q1(i,:));
    hold on;
    Robot2.plot(q2(i,:));
    hold on;
%     filename = sprintf('avoid_image_%d.png', i);
%     saveas(gcf, filename); % 保存当前图形为文件
end
plot3(points1_avoid(1,:), points1_avoid(2,:), points1_avoid(3,:), 'r.', 'MarkerSize', 5);
xlabel('X轴');
ylabel('Y轴');
zlabel('Z轴');
% hold on;
% plot3(points2_avoid(1,:), points2_avoid(2,:), points2_avoid(3,:), 'r.', 'MarkerSize', 5)



%%%从这里开始，下面的方法感觉不行。一直注释到底
%线先画出原始的运动曲线图
figure;
colors1 = lines(6);
subplot(3,1,1);
for j=1:6
    plot(t_sample,q1(:,j),'Color', colors1(j, :),'LineWidth', 1.5);
    hold on;
end
title('所有关节角度轨迹'); 
xlabel('时间 (s)'); ylabel('角度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');
subplot(3,1,2);
for j = 1:6
    plot(t_sample, qd1(:, j), 'Color', colors1(j, :), 'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('速度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

subplot(3,1,3);
for j = 1:6
    plot(t_sample,qdd1(:, j),'Color', colors1(j, :),  'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('加速度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');



%计算调整阶段的速度和加速度，用曲线拟合的方式，假设取6个采样点（采样点并不是越多越好）
%以6个采样点为例
% q1_fit_org = zeros(6,6);
% for i=1:6
%     q1_fit_org(i,:) = New_q1(27+3*(i-1),:);
% end
q1_fit_org = New_q1(27:50,:);%取出要调整的片段

t_fit = 2.7:0.1:5.0;%时间序列一定要和原始轨迹规划时间序列保持一致，不然影响速度和加速度

[q1_fit,qd1_fit,qdd1_fit,t_fine]=cubic_spline_joints(q1_fit_org,t_fit);%生成个插值点


figure;
colors = lines(6);
subplot(3,1,1);
for j = 1:6
    plot(t_fine,q1_fit(:, j),'Color', colors(j, :),'LineWidth', 1.5);
     hold on;
%     plot(t_fit, q1_fit_org(:,j), 'ko');
end
title('所有关节角度轨迹'); 
xlabel('时间 (s)'); ylabel('角度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

subplot(3,1,2);
for j = 1:6
    plot( t_fine,qd1_fit(:, j), 'Color', colors(j, :), 'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('速度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

subplot(3,1,3);
for j = 1:6
    plot(t_fine,qdd1_fit(:, j),'Color', colors(j, :),  'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('加速度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');


%对前面一段优化轨迹从20-28
q1_optimize_20 = q1(20,:);%取第10处
q1_optimize_v_20 = qd1(20,:);
q1_optimize_a_20 = qdd1(17,:);

q1_optimize_28 = q1_fit(2,:);
q1_optimize_v_28 = qd1_fit(2,:);
q1_optimize_a_28 = qdd1_fit(2,:);
%对后面一段轨迹进行优化50-60
q1_optimize_50 = q1_fit(24,:);
q1_optimize_v_50 = qd1_fit(24,:);
q1_optimize_a_50 = qdd1_fit(24,:);

q1_optimize_60 = q1(60,:);
q1_optimize_v_60 = qd1(60,:);
q1_optimize_a_60 = qdd1(60,:);

%计算优化后的结果
New_q1_20_28 = zeros(9,6);
New_qd1_20_28 = zeros(9,6);
New_qdd1_20_28 = zeros(9,6);
% [~,~,New_q1_20_28,New_qd1_20_28,New_qdd1_20_28]=quintic_traj(...
% q1_optimize_20,q1_optimize_v_20,q1_optimize_a_20,...
% q1_optimize_28,q1_optimize_v_28,q1_optimize_a_28,0.8,0.1);
t_20_28 = 0:0.1:0.8;
[New_q1_20_28,New_qd1_20_28,New_qdd1_20_28] = cubicInterpolation(q1_optimize_20,q1_optimize_v_20,...
                                                  q1_optimize_28,q1_optimize_v_28,0.8,t_20_28);

New_q1_50_60 = zeros(11,6);
New_qd1_50_60 = zeros(11,6);
New_qdd1_50_60 = zeros(11,6);
% [~,~,New_q1_41_50,New_qd1_41_50,New_qdd1_42_60]=quintic_traj(...
% q1_optimize_41,q1_optimize_v_41,q1_optimize_a_41,...
% q1_optimize_50,q1_optimize_v_50,q1_optimize_a_50,0.9,0.1);
t_50_60 = 0:0.1:1;
[New_q1_50_60,New_qd1_50_60,New_qdd1_50_60] = cubicInterpolation(q1_optimize_50,q1_optimize_v_50,...
                                                  q1_optimize_60,q1_optimize_v_60,0.9,t_50_60);

%创建最终的运动曲线
q1_final = q1;
qd1_final = qd1;
qdd1_final = qdd1;

q1_final(20:28,:) = New_q1_20_28;
qd1_final(20:28,:) = New_qd1_20_28;
qdd1_final(20:28,:) = New_qdd1_20_28;
for j=28:50
    q1_final(j,:)=q1_fit(j-26,:);
    qd1_final(j,:)=qd1_fit(j-26,:);
    qdd1_final(j,:)=qdd1_fit(j-26,:);
end
q1_final(50:60,:) = New_q1_50_60;
qd1_final(50:60,:) = New_qd1_50_60;
qdd1_final(50:60,:) = New_qdd1_50_60;

figure;
colors = lines(6);
subplot(3,1,1);
for j = 1:6
    plot(q1_final(:, j),'Color', colors(j, :),'LineWidth', 1.5);
     hold on;
%     plot(t_fit, q1_fit_org(:,j), 'ko');
end
title('所有关节角度轨迹'); 
xlabel('时间 (s)'); ylabel('角度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

subplot(3,1,2);
for j = 1:6
    plot( qd1_final(:, j), 'Color', colors(j, :), 'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('速度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

subplot(3,1,3);
for j = 1:6
    plot(qdd1_final(:, j),'Color', colors(j, :),  'LineWidth', 1.5);
    hold on;
end
xlabel('时间 (s)'); ylabel('加速度 (rad)');
legend('关节1', '关节2', '关节3', '关节4', '关节5', '关节6', 'Location', 'best');

% figure;
% for i=1:101   
%     Robot1.plot(q1_final(i,:));
%     hold on;
%     Robot2.plot(q2(i,:));
%     hold on;
%     filename = sprintf('final_avoid_image%d.png', i);
%     saveas(gcf, filename); % 保存当前图形为文件
% end
% % figure;
% % T=0:1:100;
% % plot(T, distance4(:,1), 'b-', 'LineWidth', 1.5); 
% % hold on;
% % plot(T,distance4(:,2),'r-', 'LineWidth', 1.5);
% % hold on;
% % plot(T, distance4(:,3), 'g-', 'LineWidth', 1.5);
% % hold on;
% % plot(T, distance4(:,4), 'y-', 'LineWidth', 1.5);
% % hold on;
% % yline(130, 'k--', 'LineWidth', 1.5);
% % 
% % figure;
% % plot(T, distance(:,1), 'b-', 'LineWidth', 1.5); 
% % hold on;
% % plot(T,distance(:,2),'r-', 'LineWidth', 1.5);
% % hold on;
% % plot(T, distance2(:,1), 'g-', 'LineWidth', 1.5);
% % hold on;
% % plot(T, distance2(:,2), 'y-', 'LineWidth', 1.5);
% % hold on;
% % plot(T,distance3(:,1),'k-', 'LineWidth', 1.5);
% % hold on;
% % yline(130, 'k--', 'LineWidth', 1.5);
% 
points1_avoid_final = zeros(3,101);
points2_avoid_final = zeros(3,101);
for i=1:101
    points1_avoid_final(:,i)=Robot1.fkine(q1_final(i,:)).t;
    points2_avoid_final(:,i)=Robot2.fkine(q2(i,:)).t;
    
%     Robot1.plot(New_q1(i,:));
%     hold on;
%     Robot2.plot(q2(i,:));
%     hold on;
%     filename = sprintf('avoid_image_%d.png', i);
%     saveas(gcf, filename); % 保存当前图形为文件
end