% 清除环境

% 设置总的 epoch 数量
epochs = 1000;
x = 1:epochs;

% Total-Loss 参数设置（范围：3.2 ~ 0.2）
initial_total = 3.2;
final_total   = 0.2;
range_total   = initial_total - final_total;  % 3.0

% 计算 Total-Loss 指数衰减系数 k_total
k_total = log(range_total / 0.01) / epochs;
% 生成基础 Total-Loss 曲线
base_total = range_total * exp(-k_total * x) + final_total;

% Mask-Loss 参数设置（范围：1.6 ~ 0.08）
initial_mask = 1.6;
final_mask   = 0.08;
range_mask   = initial_mask - final_mask;  % 1.52

% 计算 Mask-Loss 指数衰减系数 k_mask，并使其收敛速度略快
k_mask = 1.5 * (log(range_mask / 0.01) / epochs);
% 生成基础 Mask-Loss 曲线
base_mask = range_mask * exp(-k_mask * x) + final_mask;

% 加入噪声
% 对 Total-Loss：在第 0 到 200 个 epoch 之间引入更多波动
noise_amp_total_normal = 0.03;  % 普通噪声幅度
noise_amp_total_high   = 0.08;   % 第 0-200 个 epoch 的较大噪声幅度
noise_amp_total_small  = 0.01;  % 第 700-1000 个 epoch 的较小噪声幅度
noise_amp_total_wave   = 0.03;  % 第 200-250 个 epoch 的波动幅度

% 生成总的噪声（初始为全局普通噪声）
noise_total = noise_amp_total_normal * (rand(1, epochs) - 0.5);
% 对第 0 到 200 个 epoch，增加噪声幅度
noise_total(1:200) = noise_amp_total_high * (rand(1, length(1:200)) - 0.5);
% 对第 700 到 1000 个 epoch，减少噪声幅度
noise_total(700:1000) = noise_amp_total_small * (rand(1, length(700:1000)) - 0.5);
% 对第 200 到 250 个 epoch，引入小范围波动
% noise_total(200:250) = noise_amp_total_wave * sin(2 * pi * (1:length(200:250)) / length(200:250));

% Total-Loss 带噪声序列
loss_total_noisy = base_total + noise_total;
% 限制 Total-Loss 数值在 [final_total, initial_total] 内
loss_total_noisy = min(max(loss_total_noisy, final_total), initial_total);

% 对 Mask-Loss，整体噪声幅度降低，并在第 700 到 1000 个 epoch 内进一步减少
noise_amp_mask = 0.01;  % 整体较小的噪声幅度
noise_amp_mask_small = 0.005;  % 第 700-1000 个 epoch 的更小噪声幅度

% 生成 Mask-Loss 的噪声
noise_mask = noise_amp_mask * (rand(1, epochs) - 0.5);
% 对第 700 到 1000 个 epoch，减少噪声幅度
noise_mask(700:1000) = noise_amp_mask_small * (rand(1, length(700:1000)) - 0.5);

% Mask-Loss 带噪声序列
loss_mask_noisy = base_mask + noise_mask;
% 限制 Mask-Loss 数值在 [final_mask, initial_mask] 内
loss_mask_noisy = min(max(loss_mask_noisy, final_mask), initial_mask);

% 绘制损失函数曲线
figure;
plot(x, loss_total_noisy, 'b-', 'LineWidth', 1.5); hold on;
plot(x, loss_mask_noisy,  'r-', 'LineWidth', 1.5);
xlabel('Epoch');
ylabel('损失值');
title('Mask-RCNN损失函数曲线');
legend('总损失', 'Mask损失 ', 'Location', 'northeast');
grid on;
hold off;
