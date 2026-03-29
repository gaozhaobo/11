

for i=1:101
    points1_final(:,i)=Robot1.fkine(New_q1(i,:)).t;
    points2_final(:,i)=Robot2.fkine(q2(i,:)).t;
    
    Robot1.plot(q1_final(i,:));
    hold on;
    Robot2.plot(q2(i,:));
    hold on;
    filename = sprintf('avoid_image_final%d.png', i);
    saveas(gcf, filename); % 保存当前图形为文件
end

plot3(points1_final(1,:), points1_final(2,:), points1_final(3,:), 'b.', 'MarkerSize', 5);
xlabel('X轴');
ylabel('Y轴');
zlabel('Z轴');
hold on;
plot3(points2_final(1,:), points2_final(2,:), points2_final(3,:), 'r.', 'MarkerSize', 5)