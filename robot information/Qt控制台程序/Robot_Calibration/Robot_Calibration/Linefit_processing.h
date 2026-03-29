#pragma once
#ifdef LINE_FIT_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#include<opencv2/opencv.hpp>

DLL_API bool Image_Processing_for_Linefit(cv::Mat imagesrc,cv::Mat &imagedst,//原图像
										  double &k,double &k1 , double &k2,//三条直线的斜率 
										  std::vector<float>& centralpoint1,
										  std::vector<float>& centralpoint2);//两条边缘线的中心点
