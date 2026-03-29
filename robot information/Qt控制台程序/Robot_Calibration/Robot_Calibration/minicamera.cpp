#include "minicamera.h"
#include <cmath>

const double PI = 3.1415926;
MiniCamera::MiniCamera()
{
    imagesrc = cv::Mat(400,400,CV_8UC3);
    is_turn_on = false;
    R = (cv::Mat_<double>(3,3)<<1,0,0,
                                0,1,0,
                                0,0,1);
}

bool MiniCamera::Turn_on_camera()
{
    if(is_turn_on){
        std::cout<<"The camera has been turned on"<<std::endl;
    }else{
        cap = cv::VideoCapture(0);
        if(!cap.isOpened()){
            return false;
        }
        is_turn_on = true;
    }

    return true;
}

bool MiniCamera::Turn_off_camera()
{
    if(!is_turn_on)
    {
        return false;
    }
    cap.release();
    imagesrc.release();
    imagesrc = cv::Mat();//设置为空

    image_line_fit.release();
    image_line_fit = cv::Mat();//置空

    is_turn_on = false;

    return true;
}

bool MiniCamera::Capture_frame()
{
    if(!is_turn_on){
        std::cout<<"The camera has NOT been turned on"<<std::endl;
        return false;
    }

    mtx.lock();
    cap.read(imagesrc);
    mtx.unlock();
    return true;
}

bool MiniCamera::Image_processing_for_Fitline(double &k1 ,double &k2,
                                              std::vector<float>& centralpoint1,
                                              std::vector<float>& centralpoint2)
{
    if(!is_turn_on){
        std::cout<<"The camera has NOT been turned on"<<std::endl;
        return false;
    }
    if(imagesrc.empty()){
        std::cout<<"The imagesrc is empty"<<std::endl;
        return false;
    }
    double k;
    mtx.lock();
    cv::Mat src = imagesrc.clone();
    mtx.unlock();
    static cv::Mat dst;
    bool ret = Image_Processing_for_Linefit(src,dst,k,k1,k2,centralpoint1,centralpoint2);
    if(!ret){
        if(dst.empty()){
            std::cout<<"dst为空"<<std::endl;
        }
        return false;
    }
    mtx_line.lock();
    image_line_fit = dst.clone();
    mtx_line.unlock();
    double theta =atan(k);//直线绕z轴旋转的角度（弧度制）
    //std::cout<<"k="<<k<<"     theta = "<<theta<<std::endl;
    R = (cv::Mat_<double>(3,3)<<cos(theta),-sin(theta),0,
         sin(theta),cos(theta),0,
         0,0,1);//直线相对于相机的位姿变换矩阵

    return true;
}

cv::Mat MiniCamera::Show_R()
{
    if(!is_turn_on){
        return cv::Mat();
    }
    return R;
}

bool MiniCamera::Calculation_distance_z_y(double &z , double &y)//返回的是线相对于夹具的变化，要注意坐标系转化
{
    double k1=0,k2=0;
    std::vector<float> centralpoint1(2),centralpoint2(2);
    bool ret = Image_processing_for_Fitline(k1,k2,centralpoint1,centralpoint2);
    if(!ret){
        std::cout<<"直线拟合失败，请重试"<<std::endl;
        z = 0.0 , y = 0.0;
        return false;//返回固定值，使得夹具不移动
    }
    double L0 = 21.0;//模版线宽像素距离为
    double Z0 = 10.0;//，模版图像时，光纤距离微型相机距离

    std::cout<<""<<centralpoint1[0]<<","<<centralpoint1[1]<<"   "<<centralpoint2[0]<<","<<centralpoint2[1]<<std::endl;
    double l = abs(centralpoint1[1]-centralpoint2[1]);//现在线的宽度
    //std::cout<<"l="<<l<<std::endl;
    std::cout<<"l = "<<l<<std::endl;
    z = Z0*L0/l;
    //计算中心点偏移,直接用结论公式
    double delt_V_mid = (centralpoint1[1]+centralpoint2[1])/2.0 - 67.0;//中心点位置偏移
    double Y = (delt_V_mid*0.83)/l;

    z=z-Z0;//把z变为delt_z
    y = -Y;

    std::cout<<"distance_y:"<<y<<std::endl;

    return true;
}

bool MiniCamera::Calculation_theta(double &theta)
{
    double k1=0,k2=0;
    std::vector<float> centralpoint1(2),centralpoint2(2);
    bool ret = Image_processing_for_Fitline(k1,k2,centralpoint1,centralpoint2);
    if(!ret){
        std::cout<<"直线拟合失败，请重试"<<std::endl;
        return false;
    }

    double k = 0.00;
    if(centralpoint1[1]<centralpoint2[1]){
        //说明第一个点为上方直线
        k = k1;
    }else{
        k = k2;
    }

    double w = 0.83 , Z0 = 10.0;
    theta = -atan(-2*k*Z0/w);//注意小孔成像和最后图像的区别

    return true;
}






