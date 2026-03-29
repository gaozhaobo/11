function result = euclideanTransform(T2, T3)
    % 定义目标函数
    function error = objectiveFunction(params)
        R = reshape(params(1:9), 3, 3);
        t = params(10:12);
        T1 = [R, t; 0, 0, 0, 1]; % 构建T1矩阵
        
        % 应用变换并计算误差
        transformed_T2 = (R * T2' + t)';
        error = sum(sum((transformed_T2 - T3).^2));
    end

    % 随机初始化R和t参数值
    %initial_params = randn(12, 1);
    initial_params = [1; 0; 0; 
                      0; 1; 0; 
                      0; 0; 1;
                      0; 0; 0];
                      
    
    % 最小化目标函数
    options = optimoptions('lsqnonlin','MaxFunctionEvaluations',400000);
    optimized_params = lsqnonlin(@objectiveFunction, initial_params,[],[],options);
    
    % 从优化后的参数中解构T1矩阵
    R = reshape(optimized_params(1:9), 3, 3);
    t = optimized_params(10:12);
    result = [R, t; 0, 0, 0, 1];
end
