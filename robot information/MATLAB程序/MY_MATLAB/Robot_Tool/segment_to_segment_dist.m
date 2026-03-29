function d = segment_to_segment_dist(A, B, C, D)
    % 输入：线段AB的端点A, B；线段CD的端点C, D
    % 输出：两线段之间的最短距离d
    
    % 计算向量
    AB = B - A;
    CD = D - C;
    AC = C - A;
    
    % 计算分母（避免除零）
    e = dot(AB, AB);
    f = dot(CD, CD);
    g = dot(AB, CD);
    denom = e*f - g^2;
    
    % 处理平行或退化的线段
    if denom < 1e-10
        % 退化为点或平行线段，直接比较端点距离
        d1 = point_to_segment_dist(A, C, D);
        d2 = point_to_segment_dist(B, C, D);
        d3 = point_to_segment_dist(C, A, B);
        d4 = point_to_segment_dist(D, A, B);
        d = min([d1, d2, d3, d4]);
        return;
    end
    
    % 计算参数s和t
    h = dot(AB, AC);
    k = dot(CD, AC);
    s = (h*f - k*g) / denom;
    t = (k*e - h*g) / denom;
    
    % 约束s和t在[0,1]范围内
    s = max(0, min(1, s));
    t = max(0, min(1, t));
    
    % 计算最近点
    P = A + s * AB;
    Q = C + t * CD;
    d = norm(P - Q);
    
    % 若内部点最近，直接返回；否则检查端点组合
    if s > 0 && s < 1 && t > 0 && t < 1
        return;
    else
        % 重新计算端点组合的最小距离
        d1 = point_to_segment_dist(A, C, D);
        d2 = point_to_segment_dist(B, C, D);
        d3 = point_to_segment_dist(C, A, B);
        d4 = point_to_segment_dist(D, A, B);
        d = min([d, d1, d2, d3, d4]);
    end
end

% 辅助函数：点到线段的距离
function d = point_to_segment_dist(P, A, B)
    AP = P - A;
    AB = B - A;
    t = dot(AP, AB) / dot(AB, AB);
    t = max(0, min(1, t));
    closest = A + t * AB;
    d = norm(P - closest);
end