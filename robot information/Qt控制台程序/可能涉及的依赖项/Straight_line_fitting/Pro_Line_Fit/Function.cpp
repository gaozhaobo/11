#include"pch.h"
#include"Function.h"

bool Image_processing_Extract_line(cv::Mat imageorg, cv::Mat& dst)//滤波-边缘增强(gas_laplas)-二值化-连通域筛选
{
    cv::Mat image;
    if (imageorg.channels() != 3)
    {
        //std::cout << "不是RGB图像" << std::endl;
        image = imageorg.clone();
    }
    else {
        cv::cvtColor(imageorg, image, cv::COLOR_BGR2GRAY);
    }

    /*************畸变校正******************/
    cv::Mat cameramatrix = (cv::Mat_<double>(3, 3) <<
        191.05, 0, 215.5,
        0, 190.91, 204.86,
        0, 0, 1);
    cv::Mat distcoeffs = (cv::Mat_<double>(5, 1) <<
        -0.0042, -0.1937, 0.000297, -0.0013, 0.0986);  // 示例值，根据实际情况调整
    cv::Mat undistortedimage;
    cv::undistort(image, undistortedimage, cameramatrix, distcoeffs);

    /********************剪裁图像******************/
    cv::Mat croppedImage = undistortedimage(cv::Rect(18, 130, image.cols - 36, image.rows - 130)).clone();

    /*******************双值滤波********************/
    int diameter = 11; // 邻域直径
    double sigmaColor = 9; // 颜色标准差
    double sigmaSpace = 100; // 空间标准差

    cv::Mat filteredImage;
    //auto start = std::chrono::high_resolution_clock::now();

    cv::bilateralFilter(croppedImage, filteredImage, diameter, sigmaColor, sigmaSpace);//双边滤波
    /********************高斯拉普拉斯滤波，用于增强边缘同时消除噪声***************/
    cv::Mat gas_lap_image = filteredImage;
    //Gauss_Lap_procesing(filteredImage, gas_lap_image);

    /*******************将小于0的像素设置为0***********************/

    threshold(gas_lap_image, gas_lap_image, 0, 255, THRESH_TOZERO);

    Mat normalizedImage;
    normalize(gas_lap_image, normalizedImage, 0, 255, NORM_MINMAX, CV_32F);

    // 2. 转换为8位图像（灰度图）
    Mat grayImage;
    filteredImage.convertTo(grayImage, CV_8UC1);


    Scalar meanValue = mean(grayImage);
    Mat binaryImage, binaryImage2, binaryImage3, binaryImage4;
    threshold(grayImage, binaryImage, 1.4 * meanValue[0], 255, THRESH_BINARY);

    /***************保留最大连通域*************/
    cv::Mat resultimage;
    Connectivity_domain_filtering(binaryImage, resultimage, 1);

    /********************闭运算*********************/
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); // 选择形状和大小
    Mat kernel2 = getStructuringElement(MORPH_RECT, Size(3, 3));
    // 5. 执行闭运算
    Mat closedImage;
    morphologyEx(resultimage, closedImage, MORPH_CLOSE, kernel);

    cv::Mat openedImage;
    cv::morphologyEx(closedImage, openedImage, cv::MORPH_OPEN, kernel2);

    //morphologyEx(resultimage, closedImage, MORPH_CLOSE, kernel);

    dst = closedImage.clone();
    return true;
}

bool Image_processing_Extract_paraments(cv::Mat imageorg, cv::Mat& dst,
    double& k1, double& k2,
    std::vector<float>& centralpoint1,
    std::vector<float>& centralpoint2)//对二值化图像做分割，用于func3之后的图像处理
{
    if (imageorg.channels() != 1)
    {
        cv::cvtColor(imageorg, imageorg, cv::COLOR_BGR2GRAY);
    }
    cv::Mat edges;
    cv::Canny(imageorg, edges, 10, 20); // 100和200是低阈值和高阈值

    cv::Mat flag_labels;
    int flag = cv::connectedComponents(edges, flag_labels, 8); // 8是连接模式

    // 执行闭运算,连通断续的边界
    cv::Mat closedImage;
    if (flag > 3)
    {
        cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
        cv::morphologyEx(edges, closedImage, cv::MORPH_CLOSE, kernel);
    }
    else {
        closedImage = edges;
    }

    cv::Mat labels;
    int numLabels = cv::connectedComponents(closedImage, labels, 8); // 8是连接模式

    if (numLabels < 3) {
        std::cout << "识别轮廓连通域过少" << std::endl;
        return false;
    }
    // 准备用于存储边界点的坐标
    std::vector<std::vector<cv::Point>> boundaryPoints(numLabels);

    // 遍历每个标签，提取其边界点
    for (int y = 0; y < closedImage.rows; ++y) {
        for (int x = 0; x < closedImage.cols; ++x) {
            if (labels.at<int>(y, x) > 0) { // 仅考虑前景区域
                int label = labels.at<int>(y, x);
                boundaryPoints[label].emplace_back(x, y); // 存储边界点

            }
        }
    }
    bool ret = Fit_line3(boundaryPoints[1], k1, centralpoint1);
    if (!ret) {
        std::cout << "centralpoint1_fit_line error" << std::endl;
        return false;
    }
    ret = Fit_line3(boundaryPoints[2], k2, centralpoint2);
    if (!ret) {
        std::cout << "centralpoint2_fit_line error" << std::endl;
        return false;
    }

    // 打印每个连通域的边界点坐标
    //for (int i = 1; i < numLabels; ++i) { // label 0 是背景
    //    std::cout << "Boundary points for component " << i << ":\n";
    //    for (const auto& point : boundaryPoints[i]) {
    //        std::cout << "(" << point.x << ", " << point.y << ")\n";
    //    }
    //}

    // 可视化边界检测结果
    cv::Mat outputImage = cv::Mat::zeros(edges.size(), CV_8UC3);
    //for (int i = 1; i < numLabels; ++i) { // 不绘制背景
    //    // 将边界点绘制为红色
    //    for (const auto& point : boundaryPoints[i]) {
    //        outputImage.at<cv::Vec3b>(point.y, point.x) = cv::Vec3b(0, 0, 255); // 红色
    //    }
    //}
    int line_length = 500;
    cv::Point midpoint1(centralpoint1[0], centralpoint1[1]), midpoint2(centralpoint2[0], centralpoint2[1]);
    float dx_1 = line_length / std::sqrt(1 + k1 * k1), dx_2 = line_length / std::sqrt(1 + k2 * k2);  // 求得 x 方向的增量
    float dy_1 = k1 * dx_1, dy_2 = k2 * dx_2;                           // 根据斜率求得 y 方向的增量
    cv::Point pt1_1(midpoint1.x - dx_1 / 2, midpoint1.y - dy_1 / 2), pt1_2(midpoint1.x + dx_1 / 2, midpoint1.y + dy_1 / 2);
    cv::Point pt2_1(midpoint2.x - dx_2 / 2, midpoint2.y - dy_2 / 2), pt2_2(midpoint2.x + dx_2 / 2, midpoint2.y + dy_2 / 2);

    cv::line(outputImage, pt1_1, pt1_2, cv::Scalar(0, 0, 255), 1);
    cv::line(outputImage, pt2_1, pt2_2, cv::Scalar(0, 0, 255), 1);
    cv::circle(outputImage, cv::Point(centralpoint1[0], centralpoint1[1]), 3, cv::Scalar(0, 255, 0), -1); // 绿色点
    cv::circle(outputImage, cv::Point(centralpoint2[0], centralpoint2[1]), 3, cv::Scalar(0, 255, 0), -1); // 绿色点
    dst = outputImage.clone();
    return true;
}

bool canny_detect(cv::Mat src, cv::Mat& dst)
{
    if (src.empty()) {
        return false;
    }
    /********************canny边缘检测**********************/
    //自动计算低阈值和高阈值
    Mat gradX, gradY, absGradX, absGradY, gradientMagnitude;
    Sobel(src, gradX, CV_16S, 1, 0, 3);
    Sobel(src, gradY, CV_16S, 0, 1, 3);

    // 计算gradientMagnitude并转换为8位图像
    convertScaleAbs(gradX, absGradX);
    convertScaleAbs(gradY, absGradY);
    addWeighted(absGradX, 0.5, absGradY, 0.5, 0, gradientMagnitude);

    // 5. 使用Otsu方法获取阈值
    // 首先将梯度图二值化（为了获得合适的Otsu阈值）
    cv::Mat test;
    double otsuThreshold = threshold(gradientMagnitude, test, 0, 255, THRESH_BINARY | THRESH_OTSU);

    // 根据Otsu阈值设置Canny阈值
    double lowerThreshold1 = 0.5 * otsuThreshold;  // 下限
    double upperThreshold1 = 1.5 * otsuThreshold;  // 上限
    //cout << lowerThreshold1 << " " << upperThreshold1 << endl;
    double lowerThreshold = 10;  // 以下的阈值
    double upperThreshold = 15;   // 以上的阈值
    Canny(src, dst, lowerThreshold1, upperThreshold1);
    return true;
}

bool RGB_split(cv::Mat image, cv::Mat& green, cv::Mat& blue, cv::Mat& red)
{
    std::vector<Mat> channels;
    split(image, channels); // channels[0] = Blue, channels[1] = Green, channels[2] = Red

    // 3. 创建全黑图像用于显示每个通道
    Mat blueChannel = Mat::zeros(image.size(), CV_8UC1);  // 为蓝色通道创建全黑图像
    Mat greenChannel = Mat::zeros(image.size(), CV_8UC1); // 为绿色通道创建全黑图像
    Mat redChannel = Mat::zeros(image.size(), CV_8UC1);   // 为红色通道创建全黑图像

    // 将各通道赋值为对应颜色
    blueChannel = channels[0]; // 将蓝色通道放入
    greenChannel = channels[1]; // 将绿色通道放入
    redChannel = channels[2];   // 将红色通道放入
    green = greenChannel.clone();
    blue = blueChannel.clone();
    red = redChannel.clone();
    return true;
}

bool Gauss_Lap_procesing(cv::Mat image, cv::Mat& dst)
{
    /*******************提高图像锐度????*****************/
    Mat sharpeningKernel = (Mat_<float>(5, 5) <<
        -2, -4, -4, -4, -2,
        -4, 0, 8, 0, -4,
        -4, 8, 24, 8, -4,
        -4, 0, 8, 0, -4,
        -2, -4, -4, -4, -2);

    Mat sharpeningKernel2 = (Mat_<float>(3, 3) <<
        0, -1, 0,
        -1, 4, -1,
        0, -1, 0);
    // 4. 应用卷积操作进行锐化
    Mat sharpenedImage;
    filter2D(image, sharpenedImage, CV_32F, sharpeningKernel);

    dst = sharpenedImage.clone();
    return true;
}

bool Connectivity_domain_filtering(cv::Mat imagesrc, cv::Mat& imagedst, int num)//连通域筛选
{
    if (imagesrc.channels() != 1) {
        return false;
    }
    Mat labels;
    int numLabels = connectedComponents(imagesrc, labels, 8); // 8连接

     // 5. 计算每个连通域的面积
    std::vector<int> area(numLabels, 0); // 初始化面积向量
    for (int y = 0; y < labels.rows; y++) {
        for (int x = 0; x < labels.cols; x++) {
            int label = labels.at<int>(y, x); // 获取当前像素的标签
            area[label]++; // 增加对应标签的面积计数
        }
    }

    // 6. 找到最大两个连通域
    std::vector<std::pair<int, int>> areaIndex; // <面积, 标签索引>
    for (int i = 1; i < numLabels; i++) { // 从1开始，0是背景
        areaIndex.emplace_back(area[i], i);
    }

    // 按面积排序，降序
    std::sort(areaIndex.begin(), areaIndex.end(), std::greater<std::pair<int, int>>());

    // 7. 创建一个全黑的输出图像
    Mat outputImage = Mat::zeros(imagesrc.size(), CV_8UC3);

    // 8. 绘制最大的两个连通域到输出图像中
    for (int i = 0; i < num && i < areaIndex.size(); i++) {
        int component = areaIndex[i].second; // 获取连通域标签
        outputImage.setTo(Scalar(255, 255, 255), labels == component); // 绘制白色区域
    }

    imagedst = outputImage.clone();

    return true;
}

bool Connectivity_domain_filtering2(cv::Mat imagesrc, cv::Mat& imagedst)
{
    if (imagesrc.channels() != 1) {
        return false;
    }

    Mat labels;
    int numLabels = connectedComponents(imagesrc, labels, 8); // 8连通性

    // 5. 过滤连通域
    // 创建输出图像 (单通道)
    Mat outputImage = Mat::zeros(imagesrc.size(), CV_8UC1);
    std::vector<int> area(numLabels, 0); // 用于存储每个连通域的面积

    // 计算每个连通域的面积
    for (int y = 0; y < labels.rows; y++) {
        for (int x = 0; x < labels.cols; x++) {
            int label = labels.at<int>(y, x); // 获取当前像素的标签
            area[label]++; // 增加对应标签的连通域面积计数
        }
    }

    // 筛选并保留面积大于100的连通域
    for (int i = 1; i < numLabels; i++) { // 从1开始，0是背景
        if (area[i] > 50) { // 仅保留面积大于100的连通域
            outputImage.setTo(255, labels == i); // 将符合条件的连通域设置为白色
        }
    }

    imagedst = outputImage.clone();

    return true;
}

bool Fit_line2(cv::Mat imagesrc, cv::Mat& imagedst, double& k, std::vector<float>& point)
{
    if (imagesrc.channels() != 1) {
        //std::cout << "通道数：" << imagesrc.channels() << endl;
        cv::cvtColor(imagesrc, imagesrc, cv::COLOR_BGR2GRAY);
        //std::cout << "通道数：" << imagesrc.channels() << endl;
    }

    // 找到所有白色（255）点的坐标
    std::vector<cv::Point> whitePoints;
    for (int y = 0; y < imagesrc.rows; y++) {
        for (int x = 0; x < imagesrc.cols; x++) {
            if (imagesrc.at<uchar>(y, x) == 255) { // 白色像素
                whitePoints.emplace_back(x, y);
            }
        }
    }

    // 检查是否获得足够的白色点以进行拟合
    if (whitePoints.size() < 2) {
        std::cerr << "Not enough white points to fit a line!" << std::endl;
        return false;
    }


    // 拟合直线
    cv::Mat line;
    cv::fitLine(whitePoints, line, cv::DIST_L2, 0, 0.01, 0.01);

    // 提取线的参数
    float vx = line.at<float>(0); // 方向向量的 x 分量
    float vy = line.at<float>(1); // 方向向量的 y 分量
    float x0 = line.at<float>(2); // 直线上某点的 x 坐标
    float y0 = line.at<float>(3); // 直线上某点的 y 坐标

    if (vx < 0.000001) {
        //斜率接近于垂直，这样算得的k会趋近于无穷
        //std::cout << "vy:" << vy << "   vx:" << vx << std::endl;
        k = 5729.5;//反求是89.99°
        point[0] = x0;
        point[1] = y0;
    }
    else {
        //std::cout << "vy:" << vy << "   vx:" << vx << std::endl;
        k = vy / vx;
        point[0] = x0;
        point[1] = y0;
    }


    // 计算直线的两个端点
    cv::Point2f pt1(x0 - 200 * vx, y0 - 200 * vy); // 一端
    cv::Point2f pt2(x0 + 200 * vx, y0 + 200 * vy); // 另一端

    // 创建图像用于可视化
    cv::Mat outputImage = cv::Mat::zeros(imagesrc.size(), CV_8UC3);
    cv::cvtColor(imagesrc, outputImage, cv::COLOR_GRAY2BGR); // 转换成3通道图像

    // 绘制拟合的直线
    cv::line(outputImage, pt1, pt2, cv::Scalar(0, 0, 255), 1); // 用红色绘制直线

    imagedst = outputImage.clone();
    return true;

}

bool Fit_line3(std::vector<cv::Point> points, double& k, std::vector<float>& centralpoint)//输出拟合直线的斜率K和中心点坐标
{
    cv::Mat line;

    // 拟合直线
    cv::fitLine(points, line, cv::DIST_L2, 0, 0.01, 0.01);

    // 提取直线参数
    float vx = line.at<float>(0); // 直线的 x 方向向量
    float vy = line.at<float>(1); // 直线的 y 方向向量
    float x0 = line.at<float>(2); // 直线上的一个点的 x 坐标
    float y0 = line.at<float>(3); // 直线上的一个点的 y 坐标
    if (x0 == 0 && y0 == 0) {
        return false;
    }

    if (vx < 0.000001) {
        k = 5729.5;
        //std::cout << "vy:" << vy << "   vx:" << vx << std::endl;
        centralpoint[0] = x0;
        centralpoint[1] = y0;
    }
    else {
        k = vy / vx;
        //std::cout << "vy:" <<vy << "   vx:" << vx << std::endl;
        centralpoint[0] = 197.0;
        //centralpoint[0] = x0;
        centralpoint[1] = y0+k*(197.0-x0);
    }

    return true;
}

bool Image_processing_Extract_all_paraments(cv::Mat imageorg, cv::Mat& dst,
    double& k, double& k1, double& k2,
    std::vector<float>& centralpoint1,
    std::vector<float>& centralpoint2)
{
    cv::Mat outimage, green, blue, red;
    RGB_split(imageorg, green, blue, red);

    cv::Mat  result3;
    Image_processing_Extract_line(green, result3);//线的二值化图像

    cv::Mat fitline1, fitline2;
    vector<float> point(2);
    Fit_line2(result3, fitline1, k, point);//计算二值化图像拟合的一条线

    bool ret = Image_processing_Extract_paraments(result3, fitline2, k1, k2, centralpoint1, centralpoint2);//计算边缘拟合的两条线
    if (!ret) {
        return false;
    }
    cv::Mat outputimage = fitline2;
    //cv::add(fitline1, fitline2, outputimage);
    if (!outputimage.empty()) {
        dst = outputimage.clone();
    }

    return true;
}


