#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qlabel.h"
#include "robot_function.h"
#include<QThread>
#include<string>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/opencv.hpp"
#include"mycamera.h"
#include<vector>
#include<portcommunicate.h>
//#include<callpython.h>
#include"minicamera.h"
#include"Parameter_table.h"

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//class My_thread_work :public QObject//这里用于记录单开线程的工作，持续读取编码器位置功能在此定义
//{
//    Q_OBJECT
//public:
//    My_thread_work();

//    bool Read_position_flag;//读取编码器功能执行标志，放在线程中，置1为读取位置，置0为停止读取，退出线程时会使用

//signals:
//    void Signal_Updatelabels(int labelindex);

//public slots:
//    void Read_position(Robot_Function *myrobot, QLabel **label);//传入类的参数，将类中轴的方位参数显示在label上
//};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //MainWindow(QWidget *parent = nullptr);
    MainWindow(int chose,int index_1 = 1, I32 *nums_1_ =nums_1 , double *p2r_1_ = p2r_1, double *offset_1_ = offset_1, std::vector<double> tool_1_ = tool_1,
               int index_2 = 2, I32 *nums_2_ = nums_2, double *p2r_2_ = p2r_2, double *offset_2_ = offset_2, std::vector<double> tool_2_ = tool_2,
               QWidget *parent = nullptr);
    ~MainWindow();
    QImage qimage1,qimage2;//在主界面上显示图像
    QImage qimage_pre1,qimage_pre2;//保存预测的结果

    C_Dual_arm_robots myrobots;

    QLabel *mylabel_grop[12];//记录轴的编码器值

    Mycamera_Group Mycameras;

    MyPort Modbusport;//定义一个串口，用于实现modbus串口通信
    MiniCamera Myminicamera;
    //PythonModel Mypython_model;//定义一个python类，用于调用python脚本

signals:
    //void Signals_read_position(Robot_Function *myrobot,QLabel **label);//读取编码器功能启动信号
    void Signal_show_pic();//在UI界面上显示相机画面
    void Signal_show_pre_pic(cv::Mat pic , QLabel *label);

private slots:
    void show_pic();//在UI界面上显示相机画面

    void show_pre_pic(cv::Mat pic , QLabel *label);//在UI上显示预测获得的图片,pic为传入的图像，label为要显示的位置

    void on_robotswitch_toggled(bool checked);//开关按钮，实现反转开关，同时控制所有电机的通断，以及编码器位置的读取

 /***************以下为：-，+调试机械臂运动按钮***************/
    void on_pushButton_pressed();//轴1按钮+，保持按下实现正转

    void on_pushButton_released();//轴1按钮+，松开停止

    void on_pushButton_2_pressed();//轴1按钮-，保持按下实现反转

    void on_pushButton_2_released();//轴1按钮-，松开停止

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_5_pressed();

    void on_pushButton_5_released();

    void on_pushButton_6_pressed();

    void on_pushButton_6_released();

    void on_pushButton_23_pressed();

    void on_pushButton_23_released();

    void on_pushButton_24_pressed();

    void on_pushButton_24_released();

    void on_pushButton_9_pressed();

    void on_pushButton_9_released();

    void on_pushButton_10_pressed();

    void on_pushButton_10_released();

    void on_pushButton_11_pressed();

    void on_pushButton_11_released();

    void on_pushButton_12_pressed();

    void on_pushButton_12_released();

    void on_pushButton_35_pressed();

    void on_pushButton_35_released();

    void on_pushButton_36_pressed();

    void on_pushButton_36_released();

    void on_pushButton_27_pressed();

    void on_pushButton_27_released();

    void on_pushButton_28_pressed();

    void on_pushButton_28_released();

    void on_pushButton_33_pressed();

    void on_pushButton_33_released();

    void on_pushButton_34_pressed();

    void on_pushButton_34_released();

    void on_pushButton_25_pressed();

    void on_pushButton_25_released();

    void on_pushButton_26_pressed();

    void on_pushButton_26_released();

    void on_pushButton_31_pressed();

    void on_pushButton_31_released();

    void on_pushButton_32_pressed();

    void on_pushButton_32_released();

    void on_pushButton_29_pressed();

    void on_pushButton_29_released();

    void on_pushButton_30_pressed();

    void on_pushButton_30_released();

    void on_matlabtest_clicked();//测试matlab库连接的正确性
 /***************以上为：-，+调试机械臂运动按钮***************/

    //void on_pushButton_40_clicked();//正向运动学的按钮

    //void on_pushButton_42_clicked();//逆运动学解的按钮，机器人将运动到该位置

    void on_cameraswitch_toggled(bool checked);//相机开关

    //void on_pushButton_46_clicked();//原中文测试

    void on_showpic_clicked();//显示两个图像,该函数可以废弃了

    void on_getposition_clicked();//测试从图像中取出像素坐标

    void on_show2D_clicked();//该按钮为在界面上显示两张图像目标像素点的图像坐标

    void on_calculate3D_clicked();//该按钮为根据两图像的像素坐标计算物体的空间坐标并且显示

    void on_checkaccuracy_clicked();//利用棋盘格角点来测试双目三维坐标的准确性

    //void on_pushButton_52_clicked();//计算相机到机器人的位姿变换矩阵


    void on_showtool_clicked();//将机器人工具位置投影到图像中显示

    void on_robotkine1_clicked();//机器人正运动学调试1

    void on_robotikine1_clicked();//机器人逆运动学调试1

    //void on_CalibrateC_R_clicked();//计算相机到机械臂的位姿变换矩阵

    void on_port_turnon_clicked();//打开串口

    void on_sent_telegram_clicked();//向串口发送报文

    //void on_horizontalSlider_valueChanged(int value);//滑轨控制夹钳1


    //void on_horizontalSlider_2_valueChanged(int value);//滑轨控制夹钳2

    void on_stop_button_clicked();//紧急停止按钮

    void on_robotkine2_clicked();//机器人2正运动学解调试

    void on_robotikine2_clicked();//机器人2逆运动学调试

    void on_CalibrateC_R2_clicked();//Ax=xB来求解手眼标定问题

    void on_Robot_move_clicked();//选择机械臂，移动到标记点的位置

    //void on_Py_initialize_clicked();//初始化Py环境

    //void on_Model_predict_clicked();//进行模型预测

    void on_test_new_robot_clicked();

    void on_pushButton_38_toggled(bool checked);

    void on_pushButton_39_clicked();

    void on_pushButton_41_clicked();

    void on_pushButton_42_clicked();

    void on_stop_button_2_clicked();

    bool Adjust_theta_z();//调整相机绕z轴旋转角度

    bool Adjust_delt_z_y();//调整相机的z和y方向进给距离

    bool Adjust_theta_y();//调整相机绕y轴的旋转角度

    void Operat_tool(int value , int index);


    void on_horizontalSlider_2_sliderMoved(int position);

    void on_horizontalSlider_1_sliderMoved(int position);

    void extracted(std::vector<std::vector<double>> &vec_V_qF);
    void on_pushButton_37_clicked();

    void on_pushButton_43_clicked();

    void on_pushButton_44_clicked();//自动化步骤1

    void on_pushButton_51_clicked();//自动化步骤2

    void on_pushButton_45_clicked();//自动化步骤3

    void on_pushButton_46_clicked();//自动化步骤4

    void on_pushButton_47_clicked();//自动化步骤5

    void on_pushButton_48_clicked();//自动化步骤6

    void on_pushButton_50_clicked();//自动化步骤7

    void on_pushButton_58_clicked();//自动化步骤8

    void on_pushButton_52_clicked();//夹钳1打开


    void on_pushButton_53_clicked();//夹钳1半闭合

    void on_pushButton_54_clicked();//夹钳1闭合

    void on_pushButton_55_clicked();//夹钳2打开

    void on_pushButton_57_clicked();//夹钳2半闭合

    void on_pushButton_56_clicked();//夹钳2闭合



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

