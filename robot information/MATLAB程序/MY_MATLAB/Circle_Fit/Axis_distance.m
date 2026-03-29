function [distance,Deg] = Axis_distance(M1,M2)%计算两个轴线的距离M为6行1列向量，前三行为点，后三行法向量
point1 = M1(1:3,:);%轴线1上的一点
point2 = M2(1:3,:);%轴线2上的一点
nv1 = M1(4:6,:);%轴线1的法向量
nv2 = M2(4:6,:);%轴线2的法向量
point1_2 = point1-point2;

ret = dot(cross(nv1,nv2),point1_2);
nv = cross(nv1,nv2);
Deg = acosd(dot(nv1,nv2)/(sqrt(dot(nv1,nv1))*sqrt(dot(nv2,nv2))));
if Deg<1.5
    Axis_average = [(nv1(1,:)+nv2(1,:))/2;(nv1(2,:)+nv2(2,:))/2;(nv1(3,:)+nv2(3,:))/2];%假如两个轴线几乎平行,取中值轴线
    pp = point1+dot(point1_2,Axis_average)*Axis_average;
    distance = sqrt(dot((point2 - pp),(point2 - pp)));
else
    distance =abs(dot(cross(nv1,nv2),point1_2))/sqrt(dot(nv,nv));
end

end

