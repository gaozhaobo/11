function center = fitCircleCenterToPoints(pointset)
    % 定义拟合函数
    fun = @(x) (pointset(:,1) - x(1)).^2 + (pointset(:,2) - x(2)).^2 + (pointset(:,3) - x(3)).^2 - x(4)^2;
    
    % 初始参数猜测（可以根据实际情况选择一个合理的初始值）
    initialGuess = [0, 0, 0, 1];
    
    % 调用lsqnonlin进行最小二乘拟合
    solution = lsqnonlin(fun, initialGuess);
    
    % 圆心坐标即为拟合得到的x(1), x(2), x(3)
    center = solution(1:3);
end