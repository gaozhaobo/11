% 指定图像文件夹路径
folderPath = 'E://Gif'; % 将此更改为您的图像文件夹路径
imageFiles = dir(fullfile(folderPath, '*.png')); % 读取文件夹中的所有 PNG 图像文件

% 检查是否有图像文件
if isempty(imageFiles)
    error('没有找到任何 PNG 图像文件。');
end

% 创建 GIF 文件
gifFileName = 'output.gif';

% 设置图像处理所需的参数
frameDelay = 0.1; % 每帧之间的延迟时间，单位为秒

% 遍历所有图像文件
for i = 1:length(imageFiles)
    % 读取图像
    img = imread(fullfile(folderPath, imageFiles(i).name));

    % 确保图像是 2D 或 3D
    if size(img, 3) == 3
        % 对于 RGB 图像，直接使用
        [imgIndexed, map] = rgb2ind(img, 256); % 使用 256 色
    else
        imgIndexed = img; % 如果是灰度图像，保留
        map = gray(256);  % 使用灰度调色板
    end

    % 将图像写入 GIF 文件
    if i == 1
        % 创建 GIF，设定为第一帧
        imwrite(imgIndexed, map, gifFileName, 'gif', 'LoopCount', Inf, 'DelayTime', frameDelay);
    else
        % 创建 GIF，添加后续帧
        imwrite(imgIndexed, map, gifFileName, 'gif', 'WriteMode', 'append', 'DelayTime', frameDelay);
    end
end

disp(['GIF文件已生成：', gifFileName]);
