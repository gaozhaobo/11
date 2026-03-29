#include "mycamera.h"

CMycamera::CMycamera()
{
    //Camera_is_grab_flag = true;
    my_CameraHandle = NULL;
    pstDevInfo = NULL;
}

CMycamera::~CMycamera()
{

}

int CMycamera::OpenCamera()
{
    if (0 == pstDevInfo)//判断设备参数是否有误
    {
        return MV_E_PARAMETER;
    }

    if (my_CameraHandle)//判断句柄是否已经被创建，如果在此之前被创建则错误
    {
        std::cout<<"句柄已经创建，无需再次创建"<<std::endl;
        return MV_E_CALLORDER;
    }

    unsigned int nRet  = MV_CC_CreateHandle(&my_CameraHandle,pstDevInfo);//参数一是二重指针
    if (MV_OK != nRet)//判断句柄是否创建成功
    {
        std::cout<<"句柄创建失败"<<std::endl;
            return nRet;
    }else{
            std::cout<< pstDevInfo<<" 的 "<<"my_CameraHandle address:"<<my_CameraHandle<<std::endl;
    }

    nRet = MV_CC_OpenDevice(my_CameraHandle);//打开设备,成功返回MV_OK
    if (0 != nRet)
    {
        std::cout<<"设备打开失败"<<std::endl;
        MV_CC_DestroyHandle(my_CameraHandle);
        my_CameraHandle = 0;
    }else{
        std::cout<<pstDevInfo<<" 的 my_CameraHandle Adress:"<<my_CameraHandle<<" open successfully"<<std::endl;
    }
    Camera_is_grab_flag = true;
    return nRet;
}

int CMycamera::CloseCamera()
{
    if(my_CameraHandle == 0)
    {
        std::cout<<"错误句柄"<<std::endl;
        return MV_E_HANDLE;//错误或者无效的句柄
    }

    int nRet = MV_CC_CloseDevice(my_CameraHandle);
    if(nRet != 0)
    {
        std::cout<<"设备关闭失败"<<std::endl;
            return nRet;
    }

    nRet = MV_CC_DestroyHandle(my_CameraHandle);
    if(nRet != 0)
    {
        std::cout<<"句柄销毁失败"<<std::endl;
            return nRet;
    }
    my_CameraHandle = NULL;
    std::cout<<my_CameraHandle<<std::endl;
    return nRet;
}

int CMycamera::StartGrabbing()//需要在回调函数之后调用，或者用实时读取的方式取图
{
    return MV_CC_StartGrabbing(my_CameraHandle);
}

int CMycamera::StopGrabbing()//关闭抓图
{
    if(my_CameraHandle == NULL)
    {
            std::cout<<"句柄已经释放，无需重复释放"<<std::endl;
            return 0;
    }
    return MV_CC_StopGrabbing(my_CameraHandle);
}

int CMycamera::GetImageBuffer(MV_FRAME_OUT* pFrame, int nMsec)//主动获取一帧图像
{
    return MV_CC_GetImageBuffer(my_CameraHandle,pFrame,nMsec);
    //需要在启用抓图函数后使用，要与FreeImageBuffer配合使用，在处理完数据后要释放指针
}

int CMycamera::FreeImageBuffer(MV_FRAME_OUT* pFrame)//释放图像缓存
{
    return  MV_CC_FreeImageBuffer(my_CameraHandle,pFrame);
}

int CMycamera::setTriggerMode(unsigned int TriggerModeNum)
{
    int tempValue= MV_CC_SetEnumValue(my_CameraHandle,"TriggerMode", TriggerModeNum);
    if(tempValue!=0)
    {
        std::cout<<"mode set failed !!!"<<std::endl;
        return -1;
    }else{
        std::cout<<"mode set successfully !!!"<<std::endl;
        return 0;
    }
}

int CMycamera::Get_a_picture(std::string str)//相机获取一帧图像，并将其存储在对象CV_image中
{
    std::cout<<"Camera"<<Camera_index<<"start!!!"<<std::endl;

    MV_FRAME_OUT image_temp;

    while(1)
    {
        if(Camera_is_grab_flag == false)
        {
            std::cout<<"相机停止连续取流！！！"<<std::endl;
            break;
        }


        unsigned int ret = GetImageBuffer(&image_temp,1000);
        if(ret!=0)
        {
            std::cout<<"Get buffer failed !!!"<<std::endl;
            std::cout<<"failed code:"<<ret<<std::endl;
            return -1;
        }

        cv::Mat cv_image_temp = cv::Mat(image_temp.stFrameInfo.nHeight,
                           image_temp.stFrameInfo.nWidth,
                           CV_8UC3,
                           image_temp.pBufAddr);

        mycamera_picture_lock.lock();
        cv::cvtColor(cv_image_temp,cv_image,cv::COLOR_RGB2BGR);
        mycamera_picture_lock.unlock();
//        cv::namedWindow("Camera"+std::to_string(Camera_index),cv::WINDOW_NORMAL);
//        cv::imshow("Camera"+std::to_string(Camera_index),cv_image);
//        cv::waitKey(10);
        ret = FreeImageBuffer(&image_temp);
        if(ret!=0)
        {
            std::cout<<"Free buffer failed !!!"<<std::endl;
            return -1;
        }

        QThread::msleep(40);
    }

    return 0;
}

int CMycamera::Stop_get_pictures()
{
    if(StopGrabbing()!=0)
    {
        std::cout<<"Stop grab failed !!!"<<std::endl;
        return -1;
    }
    if(CloseCamera()!=0)
    {
        std::cout<<"Close failed !!!"<<std::endl;
        return -1;
    }
    return 0;
}


Mycamera_Group::Mycamera_Group()
{

    pstDevList = new MV_CC_DEVICE_INFO_LIST;

//    mycamera = new CMycamera *[2];
//    mycamerathread = new QThread *[2];
//    for(int i = 0; i<2 ; i++)
//    {
//        mycamera[i] = new CMycamera;
//        mycamerathread[i] = new QThread;
//    }

}

int Mycamera_Group::position_x = 0;
int Mycamera_Group::position_y = 0;

int Mycamera_Group::EnumDevices(unsigned int nTLayerType)
{
    int ret = MV_CC_EnumDevices(nTLayerType,pstDevList);
    if(ret!=0)
    {
            std::cout<<"设备枚举失败"<<std::endl;
            return -1;
    }
    if(pstDevList->nDeviceNum == 0)
    {
        std::cout<<"设备枚举失败"<<std::endl;
        return -1;
    }
    std::cout<<"当前有"<<pstDevList->nDeviceNum<<"个设备"<<std::endl;
    for(int i = 0 ; i<pstDevList->nDeviceNum ; i++)
    {
        mycamera[i]->pstDevInfo = pstDevList->pDeviceInfo[i];
        mycamera[i]->Camera_index = i;//相机索引编号
        std::cout<<mycamera[i]->pstDevInfo<<std::endl;
    }

    return 0;
    //pstDevInfo是结构体pstDevList的成员，记录着相机信息，pstDevList的另外一个成员是相机数量
}

int Mycamera_Group::Open_cameras()
{
    for(int i = 0 ; i<2 ; i++)
    {
        if(mycamera[i]->OpenCamera()!=0)
        {
            std::cout<<"Camera"<<i<<" :open failed !!!"<<std::endl;
            return -1;
        }
        if(mycamera[i]->setTriggerMode()!=0)
        {
            std::cout<<"Camera"<<i<<" :set mode failed !!!"<<std::endl;
            return -1;
        }
        if(mycamera[i]->StartGrabbing()!=0)
        {
            std::cout<<"Camera"<<i<<" :start grab failed !!!"<<std::endl;
            return -1;
        }
//        cv::namedWindow("Camera"+std::to_string(mycamera[i]->Camera_index),0);
//        cv::resizeWindow("Camera"+std::to_string(mycamera[i]->Camera_index),918,768);
    }

    return 0;
}

int Mycamera_Group::Thread_Init()
{
    mycamera = new CMycamera *[2];
    mycamerathread = new QThread *[2];
    for(int i = 0; i<2 ; i++)
    {
        mycamera[i] = new CMycamera;
        mycamerathread[i] = new QThread;
    }

    for(int i = 0 ; i<2 ; i++)//将每个相机放入单独的线程
    {
        mycamera[i]->moveToThread(mycamerathread[i]);
        //connect(mycamerathread[i],&QThread::finished,mycamera[i],&QObject::deleteLater);
        connect(this,&Mycamera_Group::Signal_Camera_turnon,mycamera[i],&CMycamera::Get_a_picture);//信号绑定工作函数
        mycamerathread[i]->start();//线程开启
    }

    return 0;
}

void Mycamera_Group::Get_pix_position(int event,int x ,int y ,int flags ,void *param)
{

    Mat* im = reinterpret_cast<Mat*>(param);
    switch (event) {
    case EVENT_LBUTTONDBLCLK://双击
        position_x = x;
        position_y = y;//这里只能利用静态成员变量传递值
        std::cout<<"at "<<x<<" , "<<y<<std::endl;
        break;
    default:
        break;
    }
}

cv::Mat Mycamera_Group::Caculate_3D()
{
    std::cout<<"当前相机1的投影矩阵："<<projMatrix_1<<std::endl;
    std::cout<<"当前相机2的投影矩阵："<<projMatrix_2<<std::endl;
    cv::Mat camera_position1 = (cv::Mat_<float>(2,1)<<mycamera[0]->cv_image_position_x,mycamera[0]->cv_image_position_y),
            camera_position2 = (cv::Mat_<float>(2,1)<<mycamera[1]->cv_image_position_x,mycamera[1]->cv_image_position_y);
    //将两个相机的图像坐标导入数组
    std::cout<<"相机一坐标为："<<camera_position1<<std::endl;
    std::cout<<"相机二坐标为："<<camera_position2<<std::endl;
    cv::Mat position_4D(4,1,CV_32F);//记录投影变换的结果，是一个4xN的矩阵(在本次项目中，目前N通常为1)，每一列代表一个其次坐标（x,y,z,w）w通常为0；

    cv::triangulatePoints(projMatrix_1,projMatrix_2,camera_position1,camera_position2,position_4D);

    std::cout<<"三维坐标为："<<position_4D<<std::endl;

        if(position_4D.at<float>(3.0)>0.000001||position_4D.at<float>(3,0)<0.000001)
    {
        Position_3D_x = position_4D.at<float>(0,0)/position_4D.at<float>(3,0)/scale_ration;
        Position_3D_y = position_4D.at<float>(1,0)/position_4D.at<float>(3,0)/scale_ration;
        Position_3D_z = position_4D.at<float>(2,0)/position_4D.at<float>(3,0)/scale_ration;//将求解得到的坐标复制过去
        std::cout<<"x,y,z的坐标为:"<<Position_3D_x<<","<<Position_3D_y<<","<<Position_3D_z<<std::endl;
    }



    return position_4D;

}
















