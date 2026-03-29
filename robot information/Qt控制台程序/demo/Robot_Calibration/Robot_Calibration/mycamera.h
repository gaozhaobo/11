#ifndef MYCAMERA_H
#define MYCAMERA_H

#include<QObject>
#include"MvCameraControl.h"
#include<iostream>
#include<string>
#include <vector>
#include<QThread>
#include<mutex>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"
using namespace cv;

class CMycamera :public QObject
{
    Q_OBJECT

private:

    void *  my_CameraHandle ;//句柄，用于保存相机各个参数

public:
    std::mutex mycamera_picture_lock;//相机锁

    MV_CC_DEVICE_INFO* pstDevInfo;//相机信息,枚举相机时传入

    int Camera_index;//相机索引编号

    bool Camera_is_grab_flag;//取图标志，判断相机是否在连续取流

    cv::Mat cv_image;//用于传递图像
    cv::Mat cv_image_pre;//保存预测的结果

    int cv_image_position_x;//用于保存图像中鼠标所处像素的x坐标

    int cv_image_position_y;//用于保存图像中鼠标所处像素的y坐标

    CMycamera();
    ~CMycamera();
    /*    相机开启流程：
                    1.枚举设备
                    2.判断句柄是否创建成功（或者是否已经被创建）
                    3.打开设备
                    4.开启抓图（每个相机需要单独的线程）
                    5.取出图像存入buffer
                    6.释放图像buffer
                    7.停止抓图
                    8.关闭相机*/

    //判断设备是否可达
    static bool IsDeviceAccessible(MV_CC_DEVICE_INFO* pstDevInfo, unsigned int nAccessMode);

    //打开设备
    int OpenCamera();

    //关闭设备
    int CloseCamera();

    //判断相机是否处于链接状态
    //bool IsDeviceConnected();

    //开启抓图
    int StartGrabbing();

    //关闭抓图
    int StopGrabbing();

    //主动获取一帧图像数据
    int GetImageBuffer(MV_FRAME_OUT* pFrame, int nMsec=1000);

    //释放图像缓存
    int FreeImageBuffer(MV_FRAME_OUT* pFrame);

    //设置模式
    int setTriggerMode(unsigned int TriggerModeNum = 0);

 public slots:

    //相机获取一帧图片(确保在此之前已经开启相机并开始取流)。外部直接调用此接口
    int Get_a_picture(std::string str);

    //停止取流，关闭相机，如果相机在循环线程中，要先置位取流标志位停止线程再执行此函数。
    int Stop_get_pictures();

};

class Mycamera_Group : public QObject//定义相机组，操作两组相机
{
    Q_OBJECT
public:

    MV_CC_DEVICE_INFO_LIST* pstDevList ;//记录设备信息

    CMycamera **mycamera;

    QThread **mycamerathread;

    static int position_x;//这里依次记录相机读取到的坐标，将其传递给对应的每个相机
    static int position_y;

    float Position_3D_x = 0;
    float Position_3D_y = 0;
    float Position_3D_z = 0;
    //这里记录目标物体的3D坐标

//    float matrix1_from_matlab[3][4] = { {6543.4616, 0,          0,          0},
//                                        {0,         6539.8977,  0,          0},
//                                        {2149.8017, 1551.4638,  1,          0}};



    float matrix1_from_matlab[3][4] = {{6500.3816,	0,          2238.3555,  0},
                                       {0,          6493.9721,	1545.4219,  0},
                                       {0,          0,          1,          0}};//投影矩阵



//    float matrix2_from_matlab[3][4] = { {6564.3249, -21.6688,   -150.3682,  -504187.6918},
//                                        {22.9707,   6558.4630,  66.2869,    -3649.0598},
//                                        {2002.7897, 1571.8158,  -28.7976,   -154282.2657}};//从matlab处获得的投影矩阵

    float matrix2_from_matlab[3][4] = {{6196.7019,	-201.7410,	-2967.8253,	3875489.5078},
                                       {1309.8608,	6496.7582,	1211.4423,	350374.1644},
                                       {0.68149,	-0.03384,	0.73103,	218.2210}};//从matlab处获得的投影矩阵，等于2的内参矩阵乘位姿变换矩阵

//    float camera1_distCoeffs[5] = {0.0056,-3.3106,-0.0018,-0.0009103,69.1383};//k1,k2,p1,p2,k3:K为径向畸变，P为切向畸变

//    float camera2_distCoeffs[5] = {-0.0573,0.0279,-0.00062887,-0.00096735,-1.7512};

    //记录两个相机的畸变系数
    cv::Mat camera1_dis = (cv::Mat_<float>(1,5)<<-0.0551,-0.6403,-0.000931,0.0016,0.1497);//k1,k2,p1,p2,k3:K为径向畸变，P为切向畸变
    cv::Mat camera2_dis = (cv::Mat_<float>(1,5)<<-0.0942,1.6454,-0.00073,0.0026,-26.2689);

    cv::Mat IntrinMatrix_camera1 = (cv::Mat_<double>(3,3)<<6500.3816,	0,          2238.3555,
                                                          0,            6493.9721,	1545.4219,
                                                          0,            0,          1           );//相机1的内参矩阵

    cv::Mat IntrinMatrix_camera2 = (cv::Mat_<float>(3,3)<<6557.6669,	0,          2060.2929,
                                                          0,            6554.5798,	1558.4217,
                                                          0,            0,          1           );//相机二的内参矩阵

    cv::Mat projMatrix_1 = cv::Mat(3,4,CV_32FC1,matrix1_from_matlab);//相机1投影矩阵，记录内参和外参
    cv::Mat projMatrix_2 = cv::Mat(3,4,CV_32FC1,matrix2_from_matlab);//相机2投影矩阵，记录内参和外参

    float scale_ration = 1.01;//比例因子

    Mycamera_Group();

    //枚举设备
    int EnumDevices(unsigned int nTLayerType = MV_USB_DEVICE);

    int Open_cameras();//打开相机阵列所有相机并开始取流

    int Thread_Init();//线程初始化

    static void Get_pix_position(int event,int x ,int y ,int flags ,void *param);
    //evnet:鼠标事件类型 x,y:鼠标坐标 flags：鼠标哪个键
    //该函数定义当鼠标点击时，会执行的操作

    cv::Mat Caculate_3D();
    //根据相机组2d坐标计算3d坐标，前提是相机的投影矩阵已经由外部标定


signals:
    void Signal_Camera_turnon(std::string str );

};

#endif // MYCAMERA_H
