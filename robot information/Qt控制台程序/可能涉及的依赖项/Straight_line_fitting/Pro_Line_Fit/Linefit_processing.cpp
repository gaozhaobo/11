#include"pch.h"
#include"Linefit_processing.h"
#include"Function.h"
bool Image_Processing_for_Linefit(cv::Mat imagesrc, cv::Mat& imagedst,//原图像
	double& k, double& k1, double& k2,//三条直线的斜率 
	std::vector<float>& centralpoint1,
	std::vector<float>& centralpoint2)//两条边缘线的中心点
{
	bool ret = Image_processing_Extract_all_paraments(imagesrc,imagedst , 
													  k , k1, k2,
													  centralpoint1,centralpoint2);
	if (ret) {
		return true;
	}
	return false;
}
