function [A_new, B_new] = extend_line_segment(A, B, L)
    % 输入：
    %   A: 原始端点A的坐标，形如 [x, y] 或 [x, y, z]
    %   B: 原始端点B的坐标，与A同维度
    %   L: 目标长度
    % 输出：
    %   A_new: 固定端点A（与原A相同）
    %   B_new: 延长后的新端点B
    
    A_new = A;  % A点保持不动
    
    % 计算方向向量
    AB = B - A;
    l = norm(AB);
    
    if l == 0
        error('线段AB退化为点，无法确定方向');
    end
    
    % 单位化方向向量
    unit_vector = AB / l;
    
    % 计算新端点B
    B_new = A + unit_vector * L;
end