function [d,P_new] = point_to_segment_dist(P, A, B)
    AP = P - A;
    AB = B - A;
    t = dot(AP, AB) / dot(AB, AB);%定义投影参数t
    t = max(0, min(1, t));%投影参数t，位于0,1区间
    closest = A + t * AB;%计算最近点
    d = norm(P - closest);%计算最近距离
    
    P_new = A+t*(B-A);%/最短距离对应的点
end