function MY = deg_vec(v1,v2)
% 给定两个二维向量v1和v2

% 计算向量v1和v2的点积
dotProduct = dot(v1, v2);

% 计算向量v1和v2的模长
normV1 = norm(v1)
normV2 = norm(v2)

% 计算夹角的余弦值
cosineAngle = dotProduct / (normV1 * normV2);

% 计算夹角（弧度）
angleRad = acos(cosineAngle);

% 将弧度转换为角度
angleDeg = rad2deg(angleRad);
MY = angleRad;
end
