#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <chrono>
#include <thread> // 仅用于演示中的 sleep_for
#include <cmath> 

constexpr double PI = 3.14159;
using namespace std;
using namespace cv;

bool Fit_line2(cv::Mat imagesrc, cv::Mat& imagedst, double& k, std::vector<float>& point);//根据二值化的图像拟合一条直线
bool Fit_line3(std::vector<cv::Point> points, double& k, std::vector<float>& centralpoint);//根据边缘检测结果的点组拟合一条直线
bool Connectivity_domain_filtering2(cv::Mat imagesrc, cv::Mat& imagedst);
bool Connectivity_domain_filtering(cv::Mat imagesrc, cv::Mat& imagedst, int num);
bool Gauss_Lap_procesing(cv::Mat image, cv::Mat& dst);
bool RGB_split(cv::Mat image, cv::Mat& green, cv::Mat& blue, cv::Mat& red);
bool canny_detect(cv::Mat src, cv::Mat& dst);

bool Image_processing_Extract_line(cv::Mat imageorg, cv::Mat& dst);//二值化提取线

bool Image_processing_Extract_paraments(cv::Mat imageorg, cv::Mat& dst,
    double& k1, double& k2,
    std::vector<float>& centralpoint1,
    std::vector<float>& centralpoint2);//提取二值化的轮廓，并求两条边缘直线参数

bool Image_processing_Extract_all_paraments(cv::Mat imageorg, cv::Mat& dst,
    double& k, double& k1, double& k2,
    std::vector<float>& centralpoint1,
    std::vector<float>& centralpoint2);////提取二值化的轮廓，并提取全部参数