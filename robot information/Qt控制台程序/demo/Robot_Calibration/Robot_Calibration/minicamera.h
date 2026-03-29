#ifndef MINICAMERA_H
#define MINICAMERA_H

#include"opencv2/opencv.hpp"
#include"Linefit_processing.h"
#include<thread>
class MiniCamera
{
public:
    MiniCamera();
    bool Turn_on_camera();//打开相机并开始取流
    bool Capture_frame();//获取一帧图像
    bool Turn_off_camera();//关闭相机
    bool Image_processing_for_Fitline(double &k1 ,double &k2,
                                      std::vector<float>& centralpoint1,
                                      std::vector<float>& centralpoint2);//将图像中的直线拟合
    cv::Mat Show_R();
    cv::Mat imagesrc;//存储微型相机原图像
    cv::Mat image_line_fit;//存储图像的直线拟合

    bool Calculation_distance_z_y(double &z , double &y);//当中心线与x轴平行时，计算需要变化的z和y
    bool Calculation_theta(double &theta);//计算角度，参数为光纤绕Y轴旋转角度
private:
    std::mutex mtx;
    std::mutex mtx_line;
    cv::VideoCapture cap;

    bool is_turn_on;//相机是否打开的标志
    cv::Mat R;//直线相对于相机的位姿变换矩阵(仅仅绕z轴旋转)
};

#endif // MINICAMERA_H
