#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MvCameraControl.h"
#include <iostream>
#include<vector>
#include<time.h>
#include "opencv2/opencv.hpp"
#include<math.h>
#include <cmath>
#include<Eigen/Dense>
#include"Robot_kine.h"
#include<thread>
#include <string>
#include <codecvt>
#include <locale>
#include <QDebug>
#include <QtGlobal>
using namespace std;

double constexpr PI = 3.1415926;
//#define Axis_num 12

void setLED(QLabel* label, int color, int size);

MainWindow::MainWindow(int chose,int index_1, I32 *nums_1, double *p2r_1, double *offset_1 , std::vector<double> tool_1,
                       int index_2, I32 *nums_2, double *p2r_2, double *offset_2 , std::vector<double> tool_2,
                       QWidget *parent)
    : QMainWindow(parent)
    ,myrobots(index_1,nums_1,p2r_1,offset_1,tool_1,index_2,nums_2,p2r_2,offset_2,tool_2)
    , ui(new Ui::MainWindow)  
{
    ui->setupUi(this);
    questRobotClient = new QuestRobotApiClient(this);
    QString bridgeServer = qEnvironmentVariable("QUEST_ROBOT_SERVER");
    if (bridgeServer.isEmpty())
    {
        bridgeServer = "http://127.0.0.1:5555";
    }
    questRobotClient->setServer(bridgeServer);
    questRobotClient->setPollingIntervalMs(50); // 20Hz
    connect(questRobotClient, &QuestRobotApiClient::commandReceived,
            this, &MainWindow::onQuestRobotCommandReceived);
    connect(questRobotClient, &QuestRobotApiClient::statusMessage,
            this, [](const QString &message){ qDebug() << message; });
    questRobotClient->start();

    setLED(ui->label_37,1,16);//机械臂开关指示灯
    setLED(ui->label_43,1,16);//相机开关指示灯
    /*              标签数组映射用于显示编码器数值            */
    mylabel_grop[0] = ui->axisposition1;
    mylabel_grop[1] = ui->axisposition2;
    mylabel_grop[2] = ui->axisposition3;
    mylabel_grop[3] = ui->axisposition4;
    mylabel_grop[4] = ui->axisposition5;
    mylabel_grop[5] = ui->axisposition6;
    mylabel_grop[6] = ui->axisposition7;
    mylabel_grop[7] = ui->axisposition8;
    mylabel_grop[8] = ui->axisposition9;
    mylabel_grop[9] = ui->axisposition10;
    mylabel_grop[10] = ui->axisposition11;
    mylabel_grop[11] = ui->axisposition12;
    /*              标签数组映射用于显示编码器数值            */
    for(int i = 0 ; i<12 ; i++)
    {
        mylabel_grop[i]->setNum(0);
    }
}

//I32 MainWindow::nums[6] = {0,1,2,3,4,5};
//double MainWindow::p2r[6] = {0.016/20000,0.024/40000,0.016/20000,0.1198/100000,0.0239/20000,0.1917/100000};
//double MainWindow::offset[6]={0};

//I32 MainWindow::nums_2[6] = {6,7,8,9,10,11};
//double MainWindow::p2r_2[6] = {0.06/5000,0.06/5000,0.06/5000,0.06/5000,0.06/5000,0.06/5000};
//double MainWindow::offset_2[6]={111458,206375,214858,160000,-100964,85206};



MainWindow::~MainWindow()
{
    if (questRobotClient)
    {
        questRobotClient->stop();
    }
    delete ui;
}

// 该函数将label控件变成一个圆形指示灯，需要指定颜色color以及直径size
// color 0:grey 1:red 2:green 3:yellow
// size  单位是像素
void setLED(QLabel* label, int color, int size)
{
    // 将label中的文字清空
    label->setText("");
    // 先设置矩形大小
    // 如果ui界面设置的label大小比最小宽度和高度小，矩形将被设置为最小宽度和最小高度；
    // 如果ui界面设置的label大小比最小宽度和高度大，矩形将被设置为最大宽度和最大高度；
    QString min_width = QString("min-width: %1px;").arg(size);              // 最小宽度：size
    QString min_height = QString("min-height: %1px;").arg(size);            // 最小高度：size
    QString max_width = QString("max-width: %1px;").arg(size);              // 最小宽度：size
    QString max_height = QString("max-height: %1px;").arg(size);            // 最小高度：size
    // 再设置边界形状及边框
    QString border_radius = QString("border-radius: %1px;").arg(size/2);    // 边框是圆角，半径为size/2
    QString border = QString("border:1px solid black;");                    // 边框为1px黑色
    // 最后设置背景颜色
    QString background = "background-color:";
    switch (color) {
    case 0:
        // 灰色
        background += "rgb(190,190,190)";
        break;
    case 1:
        // 红色
        background += "rgb(255,0,0)";
        break;
    case 2:
        // 绿色
        background += "rgb(0,255,0)";
        break;
    case 3:
        // 黄色
        background += "rgb(255,255,0)";
        break;
    default:
        break;
    }

    const QString SheetStyle = min_width + min_height + max_width + max_height + border_radius + border + background;
    label->setStyleSheet(SheetStyle);
}

void MainWindow::show_pic()
{
//    if(Mycameras.mycamera[0]==NULL||Mycameras.mycamera[1]==NULL)
//    {
//        return;
//    }
//    if(Mycameras.mycamera[0]->cv_image.data == NULL||Mycameras.mycamera[1]->cv_image.data == NULL)
//    {
//        return;
//    }
    qimage1 = QImage((const unsigned char*)Mycameras.mycamera[0]->cv_image.data,
                     Mycameras.mycamera[0]->cv_image.cols,
                     Mycameras.mycamera[0]->cv_image.rows,
                     Mycameras.mycamera[0]->cv_image.step,
                     QImage::Format_BGR888).copy();
    qimage2 = QImage((const unsigned char*)Mycameras.mycamera[1]->cv_image.data,
                     Mycameras.mycamera[0]->cv_image.cols,
                     Mycameras.mycamera[0]->cv_image.rows,
                     Mycameras.mycamera[0]->cv_image.step,
                     QImage::Format_BGR888).copy();
    ui->phoframe1->setPixmap(QPixmap::fromImage(qimage1.scaled(ui->phoframe1->size(),Qt::KeepAspectRatio)));
    ui->phoframe2->setPixmap(QPixmap::fromImage(qimage2.scaled(ui->phoframe2->size(),Qt::KeepAspectRatio)));
}

void MainWindow::show_pre_pic(cv::Mat pic , QLabel *label)//将pic显示到label上
{
    QImage qimage =  QImage((const unsigned char*)pic.data,
                           pic.cols,
                           pic.rows,
                           pic.step,
                           QImage::Format_BGR888).copy();
    label->setPixmap(QPixmap::fromImage(qimage.scaled(label->size(),Qt::KeepAspectRatio)));
}

void MainWindow::on_robotswitch_toggled(bool checked)
{
    bool status = checked;
    if(status == true)
    {
        Initial_axis();//初始化板卡
        setLED(ui->label_37,2,16);
        myrobots.Turn_on();
        std::thread thread_read_position([this](){
            std::vector<double> nums_1(6) ,nums_2(6);
            while(myrobots.Get_switch_status()){
                myrobots.Get_info();
                myrobots.Get_encoder_position(1,nums_1);
                myrobots.Get_encoder_position(2,nums_2);
                for(int i=0 ; i<6 ; i++){
                    mylabel_grop[i]->setNum(int(nums_1[i]));
                }
                for(int i=0 ; i<6 ;i++){
                    mylabel_grop[6+i]->setNum(int(nums_2[i]));
                }
                Sleep(500);
            }

            return;
        });

        thread_read_position.detach();

        Massage("电机已经全部打开，请确保机械臂刹车处于打开状态");
    }else{
        setLED(ui->label_37,1,16);
        Massage("电机即将全部关闭，请确保机械臂刹车处于闭合状态");
        myrobots.Turn_off();

        offline_axis();
    }
}


void MainWindow::on_pushButton_pressed()//轴1按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(1,0,50000,0);
    //Myrobot.Axis_Group[0].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_released()//轴1按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(1,1);
    //Myrobot.Axis_Group[0].Axis_stop_motion();
}

void MainWindow::on_pushButton_2_pressed()//轴1按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(1,0,50000,1);
    //Myrobot.Axis_Group[0].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_2_released()//轴1按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(1,1);
    //Myrobot.Axis_Group[0].Axis_stop_motion();
}

void MainWindow::on_pushButton_3_pressed()//轴2按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(1,1,50000,0);
    //Myrobot.Axis_Group[1].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_3_released()//轴2按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(1,2);
    //Myrobot.Axis_Group[1].Axis_stop_motion();
}

void MainWindow::on_pushButton_4_pressed()//轴2按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(1,1,50000,1);
    //Myrobot.Axis_Group[1].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_4_released()//轴2按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(1,2);
    //Myrobot.Axis_Group[1].Axis_stop_motion();
}

void MainWindow::on_pushButton_5_pressed()//轴3按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(1,2,50000,0);
    //Myrobot.Axis_Group[2].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_5_released()//轴3按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(1,3);
    //Myrobot.Axis_Group[2].Axis_stop_motion();
}

void MainWindow::on_pushButton_6_pressed()//轴3按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(1,2,50000,1);
    //Myrobot.Axis_Group[2].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_6_released()//轴3按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(1,3);
    //Myrobot.Axis_Group[2].Axis_stop_motion();
}

void MainWindow::on_pushButton_23_pressed()//轴4按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(1,3,50000,0);
    //Myrobot.Axis_Group[3].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_23_released()//轴4按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(1,4);
    //Myrobot.Axis_Group[3].Axis_stop_motion();
}

void MainWindow::on_pushButton_24_pressed()//轴4按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(1,3,50000,1);
    //Myrobot.Axis_Group[3].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_24_released()//轴4按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(1,4);
    //Myrobot.Axis_Group[3].Axis_stop_motion();
}

void MainWindow::on_pushButton_9_pressed()//轴5按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(1,4,50000,0);
   //Myrobot.Axis_Group[4].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_9_released()//轴5按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(1,5);
    //Myrobot.Axis_Group[4].Axis_stop_motion();
}

void MainWindow::on_pushButton_10_pressed()//轴5按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(1,4,50000,1);
    //Myrobot.Axis_Group[4].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_10_released()//轴5按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(1,5);
    //Myrobot.Axis_Group[4].Axis_stop_motion();
}

void MainWindow::on_pushButton_11_pressed()//轴6按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(1,5,50000,0);
    //Myrobot.Axis_Group[5].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_11_released()//轴6按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(1,6);
    //Myrobot.Axis_Group[5].Axis_stop_motion();
}

void MainWindow::on_pushButton_12_pressed()//轴6按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(1,5,50000,1);
    //Myrobot.Axis_Group[5].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_12_released()//轴6按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(1,6);
    //Myrobot.Axis_Group[5].Axis_stop_motion();
}

void MainWindow::on_pushButton_35_pressed()//轴7按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(2,0,10000,0);
    //Myrobot.Axis_Group[6].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_35_released()//轴7按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(2,1);
    //Myrobot.Axis_Group[6].Axis_stop_motion();
}

void MainWindow::on_pushButton_36_pressed()//轴7按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(2,0,10000,1);
    //Myrobot.Axis_Group[6].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_36_released()//轴7按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(2,1);
    //Myrobot.Axis_Group[6].Axis_stop_motion();
}

void MainWindow::on_pushButton_27_pressed()//轴8按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(2,1,10000,0);
    //Myrobot.Axis_Group[7].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_27_released()//轴8按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(2,2);
    //Myrobot.Axis_Group[7].Axis_stop_motion();
}

void MainWindow::on_pushButton_28_pressed()//轴8按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(2,1,10000,1);
    //Myrobot.Axis_Group[7].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_28_released()//轴8按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(2,2);
    //Myrobot.Axis_Group[7].Axis_stop_motion();
}

void MainWindow::on_pushButton_33_pressed()//轴9按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(2,2,10000,0);
    //Myrobot.Axis_Group[8].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_33_released()//轴9按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(2,3);
    //Myrobot.Axis_Group[8].Axis_stop_motion();
}

void MainWindow::on_pushButton_34_pressed()//轴9按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(2,2,10000,1);
    //Myrobot.Axis_Group[8].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_34_released()//轴9按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(2,3);
    //Myrobot.Axis_Group[8].Axis_stop_motion();
}

void MainWindow::on_pushButton_25_pressed()//轴10按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(2,3,10000,0);
    //Myrobot.Axis_Group[9].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_25_released()//轴10按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(2,4);
    //Myrobot.Axis_Group[9].Axis_stop_motion();
}

void MainWindow::on_pushButton_26_pressed()//轴10按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(2,3,10000,1);
    //Myrobot.Axis_Group[9].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_26_released()//轴10按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(2,4);
    //Myrobot.Axis_Group[9].Axis_stop_motion();
}

void MainWindow::on_pushButton_31_pressed()//轴11按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(2,4,10000,0);
    //Myrobot.Axis_Group[10].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_31_released()//轴11按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(2,5);
    //Myrobot.Axis_Group[10].Axis_stop_motion();
}

void MainWindow::on_pushButton_32_pressed()//轴11按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(2,4,10000,1);
    //Myrobot.Axis_Group[10].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_32_released()//轴11按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(2,5);
    //Myrobot.Axis_Group[10].Axis_stop_motion();
}

void MainWindow::on_pushButton_29_pressed()//轴12按钮+，保持按下实现正转
{
    myrobots.Single_axis_motion(2,5,10000,0);
    //Myrobot.Axis_Group[11].Axis_start_motion_v(10000,0);
}

void MainWindow::on_pushButton_29_released()//轴12按钮+，松开停止
{
    myrobots.Single_axis_stop_motion(2,6);
    //Myrobot.Axis_Group[11].Axis_stop_motion();
}

void MainWindow::on_pushButton_30_pressed()//轴12按钮-，保持按下实现反转
{
    myrobots.Single_axis_motion(2,5,10000,1);
    //Myrobot.Axis_Group[11].Axis_start_motion_v(10000,1);
}

void MainWindow::on_pushButton_30_released()//轴12按钮-，松开停止
{
    myrobots.Single_axis_stop_motion(2,6);
    //Myrobot.Axis_Group[11].Axis_stop_motion();
}



void MainWindow::on_matlabtest_clicked()//测试matlab库连接的正确性
{
    if (Robot_kineInitialize())
    {
        cout << "Initial OK !" << endl;
        //system("pause");
    }
    else {
        cout << "Initial Fail !" << endl;
        //system("pause");
        exit(EXIT_FAILURE);
    }

    mwArray* array_b = new mwArray(1, 6, mxDOUBLE_CLASS);
    double arraytemp_b[6] = { 0,0,0,0,0,0 };
    array_b->SetData(arraytemp_b, 6);
    for (int col = 1; col <= 6; col++)
    {
        cout << (*array_b)(1, col) << " " ;
    }
    cout << endl;

    mwArray result = mwArray(4,4, mxDOUBLE_CLASS);

    Robot_kine(1,result,*array_b,mwArray(1));
    cout << result << endl;
    cout <<"矩阵中元素的个数为："<< int(result.NumberOfElements()) << endl;
    cout << "阵列维数为：" << result.NumberOfDimensions() << endl;
    system("pause");
    cout << endl;
//    int num[4][4];
//    for (int row = 1; row <= 4; row++)
//    {
//        for (int col = 1; col <= 4; col++)
//        {
//            num[row - 1][col - 1] = float((*result)(row, col))*100;
//            cout << float((*result)(row, col))<<"\t" << " ";
//        }
//        cout << endl;
//    }

//    cout << endl;

//    for (int row = 0; row < 4; row++)
//    {
//        for (int col = 0; col < 4; col++)
//        {
//            cout << (num[row][col] / 100) << "\t" << " ";
//        }
//        cout << endl;
//    }

    cout << "接下来测试计算逆解" << endl;
    system("pause");

    mwArray* T = new mwArray(4,4,mxDOUBLE_CLASS);

    //mwArray* qn = new mwArray;

    mwArray* q0 = new mwArray(1,6,mxDOUBLE_CLASS);

    double temp[16] = {0,0,1.0000,0,
                       0,-1.0000,0,0,
                       1.0000,0,0,0,
                       400.0000,0,675.0000,1.0000};
    double temp_q0[6] = {0,0,0,0,0,0};

    T->SetData(temp, 16);
    q0->SetData(temp_q0,6);

    /*LARGE_INTEGER t1, t2, tc;
    QueryPerformanceFrequency(&tc);
    QueryPerformanceCounter(&t1);*/
    clock_t start, end;
    start = clock();

    //Robot_ikine(1,*qn,*T,*q0);

    end = clock();//结束时间
    cout << CLOCKS_PER_SEC << endl;
    cout << "time = " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
    //QueryPerformanceCounter(&t2);
    //double time = (double)(t2.QuadPart - t1.QuadPart) / (double)tc.QuadPart;
    //cout << "time = " << time << endl;  //输出时间（单位：ｓ）

    //cout << *qn << endl;
}


//void MainWindow::on_pushButton_40_clicked()//正向运动学的按钮
//{
//    double qn[6],Vm[6];
//    qn[0] = ui->lineEdit->text().toDouble();
//    qn[1] = ui->lineEdit_2->text().toDouble();
//    qn[2] = ui->lineEdit_3->text().toDouble();
//    qn[3] = ui->lineEdit_4->text().toDouble();
//    qn[4] = ui->lineEdit_5->text().toDouble();
//    qn[5] = ui->lineEdit_6->text().toDouble();

//    for(int i = 0 ; i<6 ; i++)
//    {
//        std::cout<<i<<"弧度位置："<<qn[i]<<endl;
//        qn[i] = qn[i]/Myrobot.Axis_Group[i].position_to_rad;
//        Vm[i] = (qn[i]-Myrobot.Axis_Group[i].Axis_info.feedback_position)/2;//Vm注意一下
//        if(Vm[i]<0.0)
//        {
//            Vm[i] = -1*Vm[i];
//        }
//        std::cout<<i<<"position位置："<<qn[i]<<std::endl;
//        std::cout<<i<<"速度为："<<Vm[i]<<endl;
//    }

//    bool status = ui->pushButton_38->isChecked();
//    if(status == false)
//    {
//        Massage("伺服驱动器未开启");
//        return;
//    }else{
//        for(int i = 0 ; i<Axis_num ; i++)//这个仅仅用于测试，注意速度控制，预计行程在2s左右走完
//        {
//            Myrobot.Axis_Group[i].Axis_start_motion(qn[i],Vm[i]);//这里速度要注意
//        }

//    }


//}

//void MainWindow::on_pushButton_42_clicked()//逆运动学解的按钮
//{
//    double T[16];//记录输入的位姿
//    T[0] = ui->lineEdit_13->text().toDouble();
//    T[1] = ui->lineEdit_14->text().toDouble();
//    T[2] = ui->lineEdit_15->text().toDouble();
//    T[3] = ui->lineEdit_16->text().toDouble();

//    T[4] = ui->lineEdit_17->text().toDouble();
//    T[5] = ui->lineEdit_20->text().toDouble();
//    T[6] = ui->lineEdit_23->text().toDouble();
//    T[7] = ui->lineEdit_26->text().toDouble();

//    T[8] = ui->lineEdit_18->text().toDouble();
//    T[9] = ui->lineEdit_21->text().toDouble();
//    T[10] = ui->lineEdit_24->text().toDouble();
//    T[11] = ui->lineEdit_27->text().toDouble();

//    T[12] = ui->lineEdit_19->text().toDouble();
//    T[13] = ui->lineEdit_22->text().toDouble();
//    T[14] = ui->lineEdit_25->text().toDouble();
//    T[15] = ui->lineEdit_28->text().toDouble();

//    double temp_q0[6] = {0,0,0,0,0,0};

//    mwArray *T_to_matlab = new mwArray(4,4,mxDOUBLE_CLASS);//存储向matlab输入的位姿
//    mwArray *qn_from_matlab = new mwArray(1,6,mxDOUBLE_CLASS);//存储matlab返回的数据
//    mwArray *q0 = new mwArray(1,6,mxDOUBLE_CLASS);
//    double qn[6];//存储转换后的关节转角
//    double Vm[6];//存储速度
//    T_to_matlab->SetData(T,16);
//    q0->SetData(temp_q0,6);

//    std::cout<<*T_to_matlab<<std::endl;
//    std::cout<<*q0<<std::endl;
//    Robot_ikine(1,*qn_from_matlab,*T_to_matlab,*q0);//matlab计算逆运动学解

//    for(int i = 0 ; i<6 ; i++)
//    {
//        qn[i] = qn_from_matlab->Get(1,i+1);
//        std::cout<<i+1<<"轴转角："<<qn[i]*180/3.1415926<<std::endl;
//        if(qn[i]<0.00001&&qn[i]>-0.00001) qn[i] = 0.0;

//        qn[i] =int(qn[i]/Myrobot.Axis_Group[i].position_to_rad);//将弧度值转换成position的值

//        Vm[i] = (qn[i]-Myrobot.Axis_Group[i].Axis_info.feedback_position)/3;//3s走完该路程
//        if(Vm[i]<0.0)
//        {
//            Vm[i] = -1*Vm[i];
//        }
//        std::cout<<i+1<<"轴转角position："<<qn[i]<<std::endl;
//    }

//    bool status = ui->pushButton_38->isChecked();
//    if(status == false)
//    {
//        Massage("伺服驱动器未开启");
//        return;
//    }else{
//        for(int i = 0 ; i<6 ; i++)//这个仅仅用于测试，注意速度控制，预计行程在2s左右走完
//        {
//            Myrobot.Axis_Group[i].Axis_start_motion(qn[i],Vm[i]);//这里速度要注意
//        }

//    }

//    delete T_to_matlab;
//    delete qn_from_matlab;
//}


void MainWindow::on_cameraswitch_toggled(bool checked)//相机开关
{
    bool status = checked;
    static std::thread thread_showpic;
    static bool show_pic_flag = true;//设置向UI连续显示图像的标志位
    if(status == true)
    {
        show_pic_flag = true;
/******************这里完成相机取流工作，并保存取到的图像**************/
        Mycameras.Thread_Init();//线程初始化
        if(Mycameras.EnumDevices()!=0)
        {
            std::cout<<"Camera group Enum Failed !!!"<<std::endl;
            return;
        }
        if(Mycameras.Open_cameras()!=0)
        {
            std::cout<<"Camera group Open Failed !!!"<<std::endl;
            return;
        }
        emit Mycameras.Signal_Camera_turnon("");
/***************************************************************/
        Sleep(500);
/***************下面将图像不停刷新在主界面UI上***********************/
        connect(this,&MainWindow::Signal_show_pic,this,&MainWindow::show_pic);
        thread_showpic = std::thread([this](){
            while(1)
            {
                if(show_pic_flag){
                    Mycameras.mycamera[0]->mycamera_picture_lock.lock();
                    Mycameras.mycamera[1]->mycamera_picture_lock.lock();
                    emit this->Signal_show_pic();
                    Mycameras.mycamera[0]->mycamera_picture_lock.unlock();
                    Mycameras.mycamera[1]->mycamera_picture_lock.unlock();
                    Sleep(40);
                }else{
                    break;
                }
            }
            return;
        });
        setLED(ui->label_43,2,16);

    }else{
        show_pic_flag = false;
        while(thread_showpic.joinable())
        {
            cout<<"waiting for the progress"<<endl;
            thread_showpic.join();
        }
        disconnect(this,&MainWindow::Signal_show_pic,this,&MainWindow::show_pic);
        for(int i = 0; i<2 ; i++)
        {
            Mycameras.mycamera[i]->Camera_is_grab_flag = false;
            Mycameras.mycamerathread[i]->exit();
            Mycameras.mycamerathread[i]->wait();
            delete Mycameras.mycamerathread[i];
        }
        for(int i = 0 ; i<2 ; i++)
        {
            Mycameras.mycamera[i]->Stop_get_pictures();
            delete Mycameras.mycamera[i];
        }

        delete Mycameras.mycamera;
        delete Mycameras.mycamerathread;




        setLED(ui->label_43,1,16);

    }
}


//void MainWindow::on_pushButton_46_clicked()
//{
//    std::cout<<"it is a test !!!!"<<std::endl;
//    std::cout<<"中文测试!!!!"<<std::endl;
//    std::cout<<std::endl;
//}


void MainWindow::on_showpic_clicked()//显示两个图像,该函数可以废弃了
{
    QImage qimage1,qimage2;
    qimage1 = QImage((const unsigned char*)Mycameras.mycamera[0]->cv_image.data,
                     Mycameras.mycamera[0]->cv_image.cols,
                     Mycameras.mycamera[0]->cv_image.rows,
                     Mycameras.mycamera[0]->cv_image.step,
                     QImage::Format_BGR888);
    qimage2 = QImage((const unsigned char*)Mycameras.mycamera[1]->cv_image.data,
                     Mycameras.mycamera[0]->cv_image.cols,
                     Mycameras.mycamera[0]->cv_image.rows,
                     Mycameras.mycamera[0]->cv_image.step,
                     QImage::Format_BGR888);
    ui->phoframe1->setPixmap(QPixmap::fromImage(qimage1.scaled(ui->phoframe1->size(),Qt::KeepAspectRatio)));
    ui->phoframe2->setPixmap(QPixmap::fromImage(qimage2.scaled(ui->phoframe2->size(),Qt::KeepAspectRatio)));
}

void MainWindow::on_getposition_clicked()//测试从图像中取出像素坐标
{
    cv::namedWindow("Pix position of camera 1:",cv::WINDOW_NORMAL|cv::WINDOW_KEEPRATIO);
    cv::imshow("Pix position of camera 1:",Mycameras.mycamera[0]->cv_image);
    setMouseCallback("Pix position of camera 1:",Mycameras.Get_pix_position,reinterpret_cast<void*>(&Mycameras.mycamera[0]->cv_image));
    waitKey(0);
    cv::destroyWindow("Pix position of camera 1:");
    Mycameras.mycamera[0]->cv_image_position_x = Mycameras.position_x;
    Mycameras.mycamera[0]->cv_image_position_y = Mycameras.position_y;//传递坐标信息保存下来

    cv::namedWindow("Pix position of camera 2:",cv::WINDOW_NORMAL|cv::WINDOW_KEEPRATIO);
    cv::imshow("Pix position of camera 2:",Mycameras.mycamera[1]->cv_image);
    setMouseCallback("Pix position of camera 2:",Mycameras.Get_pix_position,reinterpret_cast<void*>(&Mycameras.mycamera[1]->cv_image));
    waitKey(0);
    cv::destroyWindow("Pix position of camera 2:");
    Mycameras.mycamera[1]->cv_image_position_x = Mycameras.position_x;
    Mycameras.mycamera[1]->cv_image_position_y = Mycameras.position_y;//传递坐标信息保存下来


    return ;

}


void MainWindow::on_show2D_clicked()//该按钮为在界面上显示两张图像目标像素点的图像坐标
{
    ui->label_46->setNum(Mycameras.mycamera[0]->cv_image_position_x);
    ui->label_48->setNum(Mycameras.mycamera[0]->cv_image_position_y);
    ui->label_49->setNum(Mycameras.mycamera[1]->cv_image_position_x);
    ui->label_50->setNum(Mycameras.mycamera[1]->cv_image_position_y);
}


void MainWindow::on_calculate3D_clicked()//该按钮为根据两图像的像素坐标计算物体的空间坐标并且显示
{
    Mycameras.Caculate_3D();
    ui->label_55->setNum(Mycameras.Position_3D_x);
    ui->label_56->setNum(Mycameras.Position_3D_y);
    ui->label_57->setNum(Mycameras.Position_3D_z);
    Eigen::Matrix<double,4,1> Point_Camera;//点相对于相机的坐标
    Eigen::Matrix<double,4,1> Point_Robot;//点相对于机器人的坐标
    Eigen::Matrix<double,4,4> T_r_c;//相机相对于机器人的位姿变换矩阵

    Point_Camera<<Mycameras.Position_3D_x,Mycameras.Position_3D_y,Mycameras.Position_3D_z,1;
    std::cout<<Point_Camera<<std::endl;

    T_r_c<< T_Robot2Camera[0][0],T_Robot2Camera[0][1],T_Robot2Camera[0][2],T_Robot2Camera[0][3],
            T_Robot2Camera[1][0],T_Robot2Camera[1][1],T_Robot2Camera[1][2],T_Robot2Camera[1][3],
            T_Robot2Camera[2][0],T_Robot2Camera[2][1],T_Robot2Camera[2][2],T_Robot2Camera[2][3],
            T_Robot2Camera[3][0],T_Robot2Camera[3][1],T_Robot2Camera[3][2],T_Robot2Camera[3][3];
    Point_Robot = T_r_c*Point_Camera;
    std::cout<<"机器人1坐标系下的位置为："<<Point_Robot<<std::endl;

    T_r_c<< T_Robot2Camera2[0][0],T_Robot2Camera2[0][1],T_Robot2Camera2[0][2],T_Robot2Camera2[0][3],
            T_Robot2Camera2[1][0],T_Robot2Camera2[1][1],T_Robot2Camera2[1][2],T_Robot2Camera2[1][3],
            T_Robot2Camera2[2][0],T_Robot2Camera2[2][1],T_Robot2Camera2[2][2],T_Robot2Camera2[2][3],
            T_Robot2Camera2[3][0],T_Robot2Camera2[3][1],T_Robot2Camera2[3][2],T_Robot2Camera2[3][3];
    Point_Robot = T_r_c*Point_Camera;
    std::cout<<"机器人2坐标系下的位置为："<<Point_Robot<<std::endl;
}


void MainWindow::on_checkaccuracy_clicked()//利用棋盘格角点来测试双目三维坐标的准确性
{
    //获取两个棋盘图像
    cv::Mat board_picture_1 = Mycameras.mycamera[0]->cv_image;
    cv::Mat board_picture_2 = Mycameras.mycamera[1]->cv_image;
    cv::cvtColor(board_picture_1,board_picture_1,cv::COLOR_BGR2GRAY);
    cv::cvtColor(board_picture_2,board_picture_2,cv::COLOR_BGR2GRAY);
    cv::Mat undis_board_picture_1,undis_board_picture_2 ;//保存矫正后的图像
    cv::undistort(board_picture_1,undis_board_picture_1,Mycameras.IntrinMatrix_camera1,Mycameras.camera1_dis);
    cv::undistort(board_picture_2,undis_board_picture_2,Mycameras.IntrinMatrix_camera2,Mycameras.camera2_dis);

    cv::namedWindow("1",WINDOW_NORMAL);
    cv::namedWindow("2",WINDOW_NORMAL);
    cv::namedWindow("undis_1",WINDOW_NORMAL);
    cv::namedWindow("undis_2",WINDOW_NORMAL);
    cv::imshow("1",board_picture_1);
    cv::imshow("2",board_picture_2);
    cv::imshow("undis_1",undis_board_picture_1);
    cv::imshow("undis_2",undis_board_picture_2);
    cv::waitKey(0);
    cv::destroyWindow("1");
    cv::destroyWindow("2");
    cv::destroyWindow("undis_1");
    cv::destroyWindow("undis_2");



    cv::Size boardsize;
    boardsize.width = 11;//棋盘格宽度
    boardsize.height = 8;//棋盘格长度
    std::vector<cv::Point2f> point1,point2;//记录角点的数组

    bool ret1 = findChessboardCornersSB(undis_board_picture_1, boardsize, point1 ,
                                       CALIB_CB_EXHAUSTIVE | CALIB_CB_ACCURACY);
    if(ret1==true)
    {
        std::cout<<"The first pcture corner :"<<std::endl<<point1<<std::endl;
        drawChessboardCorners(undis_board_picture_1, boardsize, point1, ret1);//画出角点
    }else{
        std::cout<<"find chess board corner failed!!!"<<std::endl;
        return ;
    }

    bool ret2 = findChessboardCornersSB(undis_board_picture_2, boardsize, point2 ,
                                  CALIB_CB_EXHAUSTIVE | CALIB_CB_ACCURACY);
    if(ret2 == true)
    {
        std::cout<<"The second pcture corner :"<<std::endl<<point2<<std::endl;
        drawChessboardCorners(undis_board_picture_2, boardsize, point2, ret2);//画出角点
    }else{
        std::cout<<"The second pcture corner find failed :"<<std::endl;
        return;
    }

    //这里开始计算比例因子
    float scale_factor  = 0.0;//比例因子
    std::vector<cv::Point3f> corner_3D_position;//记录角点三维坐标
    cv::Mat position_4D(4,point1.size(),CV_32F);//记录三角测量的结果
    vector<float> distance;//记录各个角点的距离
    //cv::Mat camera_position = Mat(2,point1.size(),CV_32F),
            //camera_position2 = Mat(2,point1.size(),CV_32F);


    cv::triangulatePoints(Mycameras.projMatrix_1,Mycameras.projMatrix_2,
                          point1,point2,position_4D);
    //std::cout<<"mark!!!"<<std::endl;
    //std::cout<<position_4D.cols<<std::endl;



    for(int i = 0 ; i<position_4D.cols ; i++)
    {
        float x=0,y=0,z=0;
        x = position_4D.at<float>(0,i)/position_4D.at<float>(3,i);
        y = position_4D.at<float>(1,i)/position_4D.at<float>(3,i);
        z = position_4D.at<float>(2,i)/position_4D.at<float>(3,i);
        corner_3D_position.push_back(cv::Point3f(x,y,z));
        //std::cout<<x<<","<<y<<","<<z<<std::endl;
        //std::cout<<corner_3D_position<<std::endl;
    }
    std::cout<<"角点的三维坐标为:"<<corner_3D_position<<std::endl;

    std::cout<<"各个角点的距离为:"<<std::endl;
    for(int i = 0 ; i<(corner_3D_position.size()-1);i++)
    {
        float temp_distance = sqrt(pow((corner_3D_position[i].x - corner_3D_position[i+1].x),2)+
                                   pow((corner_3D_position[i].y - corner_3D_position[i+1].y),2)+
                                   pow((corner_3D_position[i].z - corner_3D_position[i+1].z),2));
        distance.push_back(temp_distance);
        std::cout<<temp_distance<<std::endl;
    }

    for(int i = 0 ; i<distance.size() ; i++)
    {
        if(distance[i]<30)
        {
            scale_factor += distance[i];
        }
    }
    scale_factor = scale_factor/80/15;



    std::cout<<"比例因子为:"<<scale_factor<<std::endl;

    //这里重新计算角点坐标和角点距离
    for(int i = 0 ; i<corner_3D_position.size() ; i++)
    {
        corner_3D_position[i].x = corner_3D_position[i].x/scale_factor;
        corner_3D_position[i].y = corner_3D_position[i].y/scale_factor;
        corner_3D_position[i].z = corner_3D_position[i].z/scale_factor;
    }
    std::cout<<"角点的三维坐标为:"<<corner_3D_position<<std::endl;
    std::cout<<"角点之间的距离为(算上比例因子后):"<<std::endl;
    for(int i = 0; i<distance.size();i++)
    {
        distance[i] = distance[i]/scale_factor;
        std::cout<<distance[i]<<std::endl;
    }


//    Mycameras.mycamera[0]->cv_image_position_x = point1[1].x;
//    Mycameras.mycamera[0]->cv_image_position_y = point1[1].y;
//    Mycameras.mycamera[1]->cv_image_position_x = point2[1].x;
//    Mycameras.mycamera[1]->cv_image_position_y = point2[1].y;

//    std::cout<<"对应的点对为："<<"point1:"<<point1[1].x<<","<<point1[1].y<<std::endl
//                            <<"point2:"<<point2[1].x<<","<<point2[1].y<<std::endl;

    cv::namedWindow("chessboard corner 1",WINDOW_NORMAL);
    cv::namedWindow("chessboard corner 2",WINDOW_NORMAL);
    cv::resizeWindow("chessboard corner 1",800,600);
    cv::resizeWindow("chessboard corner 2",800,600);

    cv::imshow("chessboard corner 1",undis_board_picture_1);
    cv::imshow("chessboard corner 2",undis_board_picture_2);
    cv::waitKey(0);
    cv::destroyWindow("chessboard corner 1");
    cv::destroyWindow("chessboard corner 2");


}


//void MainWindow::on_pushButton_52_clicked()//计算相机到机器人的位姿变换矩阵
//{
//    /*首先计算出机器人坐标系下棋盘格的位姿*/
//    double Robot_position[6];
//    for(int i = 0 ; i<6 ; i++)
//    {
//        //获取每个轴的弧度值
//        Robot_position[i] = Myrobot.Axis_Group[i].Axis_info.feedback_position * Myrobot.Axis_Group[i].position_to_rad;
//    }
//    double Tool_transl[3] = {33,53,275};//棋盘格原点的工具坐标变换

//    mwArray temp_result(1,3, mxDOUBLE_CLASS);//保存临时的结果
//    mwArray array_rad(1, 6, mxDOUBLE_CLASS);
//    array_rad.SetData(Robot_position,6);
//    mwArray array_tool(1,3,mxDOUBLE_CLASS);
//    vector<mwArray> result;//保存多组结果
//    mwArray Position_to_Robot(88,3,mxDOUBLE_CLASS);//88组点

//    for(int i = 0 ; i < 8 ; i++)//生成该处棋盘格各个角点位姿
//    {
//        for(int j = 0 ; j<11 ; j++)
//        {
//            array_tool.SetData(Tool_transl,3);
//            Robot_kine_Tool(1,temp_result,array_rad,array_tool);
//            result.push_back(temp_result);
//            Tool_transl[2]-=15.0;//z轴每次减去15
//        }
//        Tool_transl[2] += 15.0*11;//把z轴拉回到原来的数据
//        Tool_transl[1] -= 15;//y轴每次-15
//    }

//    for(int i = 0 ; i < result.size() ; i++)//查看result的坐标并且将其保存
//    {
//        Position_to_Robot(i+1,1) = result[i](1,1);
//        Position_to_Robot(i+1,2) = result[i](1,2);
//        Position_to_Robot(i+1,3) = result[i](1,3);
//        std::cout<<result[i]<<std::endl;
//    }

//    std::cout<<"查看传向matlab的数据"<<std::endl<<Position_to_Robot<<std::endl;



//    //return ;
//    /*至此，棋盘格角点在机器人坐标系的位置已经确定(注意棋盘格原点的位置调整上述遍历的方向)*/

//    /*下面来测量棋盘格在相机坐标系下的位置坐标*/
//    cv::Mat board_picture_1 = Mycameras.mycamera[0]->cv_image;
//    cv::Mat board_picture_2 = Mycameras.mycamera[1]->cv_image;//两个相机的图像
//    cv::cvtColor(board_picture_1,board_picture_1,cv::COLOR_BGR2GRAY);
//    cv::cvtColor(board_picture_2,board_picture_2,cv::COLOR_BGR2GRAY);
//    cv::Mat undis_board_picture_1,undis_board_picture_2 ;//保存矫正后的图像
//    cv::undistort(board_picture_1,undis_board_picture_1,Mycameras.IntrinMatrix_camera1,Mycameras.camera1_dis);
//    cv::undistort(board_picture_2,undis_board_picture_2,Mycameras.IntrinMatrix_camera2,Mycameras.camera2_dis);
//    cv::Size boardsize;
//    boardsize.width = 11;//棋盘格宽度
//    boardsize.height = 8;//棋盘格长度
//    std::vector<cv::Point2f> point1,point2;//记录角点的数组

//    bool ret1 = findChessboardCornersSB(undis_board_picture_1, boardsize, point1 ,
//                                        CALIB_CB_EXHAUSTIVE | CALIB_CB_ACCURACY);
//    if(ret1!=0)
//    {
//        std::cout<<"The first pcture corner :"<<std::endl<<point1<<std::endl;
//        drawChessboardCorners(undis_board_picture_1, boardsize, point1, ret1);//画出角点
//    }else{
//        std::cout<<"find chess board corner failed!!!"<<std::endl;
//        return ;
//    }

//    bool ret2 = findChessboardCornersSB(undis_board_picture_2, boardsize, point2 ,
//                                        CALIB_CB_EXHAUSTIVE | CALIB_CB_ACCURACY);
//    if(ret2!=0)
//    {
//        std::cout<<"The second pcture corner :"<<std::endl<<point2<<std::endl;
//        drawChessboardCorners(undis_board_picture_2, boardsize, point2, ret2);//画出角点
//    }

//    std::vector<cv::Point3f> corner_3D_position;//记录角点三维坐标
//    cv::Mat position_4D(4,point1.size(),CV_32F);//记录三角测量的结果

//    cv::triangulatePoints(Mycameras.projMatrix_1,Mycameras.projMatrix_2,
//                          point1,point2,position_4D);

//    for(int i = 0 ; i<position_4D.cols ; i++)
//    {
//        float x=0,y=0,z=0;
//        x = position_4D.at<float>(0,i)/position_4D.at<float>(3,i);
//        y = position_4D.at<float>(1,i)/position_4D.at<float>(3,i);
//        z = position_4D.at<float>(2,i)/position_4D.at<float>(3,i);
//        corner_3D_position.push_back(cv::Point3f(x,y,z));
//        //std::cout<<x<<","<<y<<","<<z<<std::endl;
//        //std::cout<<corner_3D_position<<std::endl;
//    }
//    std::cout<<"角点的三维坐标为:"<<corner_3D_position<<std::endl;
//    cv::namedWindow("chessboard corner 1",WINDOW_NORMAL);
//    cv::namedWindow("chessboard corner 2",WINDOW_NORMAL);
//    cv::resizeWindow("chessboard corner 1",800,600);
//    cv::resizeWindow("chessboard corner 2",800,600);

//    cv::imshow("chessboard corner 1",undis_board_picture_1);
//    cv::imshow("chessboard corner 2",undis_board_picture_2);
//    cv::waitKey(0);
//    cv::destroyWindow("chessboard corner 1");
//    cv::destroyWindow("chessboard corner 2");

//    mwArray Position_to_Camera(88,3,mxDOUBLE_CLASS);//角点相对于相机的坐标（传递向matlab）

//    //std::cout<<"阵列行数"<<Position_to_Camera.GetDimensions()[0]<<std::endl;
//    for(int i = 0 ; i<88 ; i++)//复制过来
//    {
//        //std::cout<<corner_3D_position[i].x<<" "<<corner_3D_position[i].y<<" "<<corner_3D_position[i].z<<std::endl;
//        Position_to_Camera(i+1,1) =corner_3D_position[i].x/1.03 ;
//        Position_to_Camera(i+1,2) =corner_3D_position[i].y/1.03 ;
//        Position_to_Camera(i+1,3) =corner_3D_position[i].z/1.03 ;
//    }

//    std::cout<<"mark!!!"<<std::endl;
//    /*至此，棋盘格相对于相机的坐标已经知道*/
//    mwArray Result_Robot_Camera(4,4,mxDOUBLE_CLASS);//相机坐标相对于机器人坐标的位姿变换矩阵
//    std::cout<<"查看传入参数"<<std::endl<<Position_to_Robot<<std::endl<<"查看下一个"<<std::endl<<Position_to_Camera<<std::endl;
//    Trans_Robot_Camera(1,Result_Robot_Camera,Position_to_Robot,Position_to_Camera);//求出相机相对于机器人的变换矩阵
//    std::cout<<Result_Robot_Camera<<std::endl;

//    for(int i = 0 ;i<4; i++)//将结果保存
//    {
//        T_Robot2Camera[i][0] = Result_Robot_Camera(i+1,1);
//        T_Robot2Camera[i][1] = Result_Robot_Camera(i+1,2);
//        T_Robot2Camera[i][2] = Result_Robot_Camera(i+1,3);
//        T_Robot2Camera[i][3] = Result_Robot_Camera(i+1,4);
//    }

//    std::cout<<"保存后的变换矩阵"<<std::endl;
//    for(auto i:T_Robot2Camera)
//    {
//        for(auto j : i)
//        {
//            std::cout<<j<<" ";
//        }
//        std::cout<<std::endl;
//    }
//    return;
//}



void MainWindow::on_showtool_clicked()//将机器人工具位置投影到图像中显示
{
    //先得到机器人工具坐标
    mwArray tool_position(4,4,mxDOUBLE_CLASS);
    //tool_position = Myrobot.Get_hand_position(1);
    myrobots.Get_hand_position(1,tool_position);
    std::cout<<"Robot1 tool position:"<<std::endl<<tool_position<<std::endl;
    //tool_position = Myrobot.Get_hand_position(2);
    myrobots.Get_hand_position(2,tool_position);
    std::cout<<"Robot2 tool position:"<<std::endl<<tool_position<<std::endl;
//    //实现机器人坐标到相机坐标再到图像坐标的转换
//    Eigen::Matrix<double,1,4> tool_position_matrix;//夹具相对机器人基座标系坐标
//    for(int i = 0 ; i < 1 ; i++)
//    {
//        for(int j = 0 ; j < 3 ; j++)
//        {
//            tool_position_matrix(i,j) = tool_position(i+1,j+1);
//        }
//    }
//    tool_position_matrix(0,3) = 1;

//    std::cout<<tool_position_matrix<<std::endl;

//    Eigen::Matrix<double,4,4> T_R2C;//记录机器人基座标系相对于相机坐标系的位姿变化矩阵
//    for(int i = 0 ; i < 4 ; i++)
//    {
//        for(int j = 0 ; j < 4 ;j++)
//        {
//            T_R2C(i,j) = T_Robot2Camera[i][j];
//        }
//    }

//    Eigen::Matrix<double,4,1> tool2camera_position_matrix;//夹具相对于相机坐标系的位置
//    tool2camera_position_matrix = T_R2C.inverse()*tool_position_matrix.transpose();

//    std::cout<<"相对相机的位姿为："<<tool2camera_position_matrix<<std::endl;
    return;

}

void MainWindow::on_robotkine1_clicked()//机器人正运动学调试1
{
    double qn[6]={0.0};
    qn[0] = ui->lineEdit->text().toDouble();
    qn[1] = ui->lineEdit_2->text().toDouble();
    qn[2] = ui->lineEdit_3->text().toDouble();
    qn[3] = ui->lineEdit_4->text().toDouble();
    qn[4] = ui->lineEdit_5->text().toDouble();
    qn[5] = ui->lineEdit_6->text().toDouble();

//    for(int i = 0 ; i<6 ; i++)
//    {
//        std::cout<<i<<"弧度位置："<<qn[i]<<endl;
//        qn[i] = qn[i]/Myrobot.Axis_Group[i].position_to_rad;
//        Vm[i] = (qn[i]-Myrobot.Axis_Group[i].Axis_info.feedback_position)/2;//Vm注意一下
//        if(Vm[i]<0.0)
//        {
//            Vm[i] = -1*Vm[i];
//        }
//        std::cout<<i<<"position位置："<<qn[i]<<std::endl;
//        std::cout<<i<<"速度为："<<Vm[i]<<endl;
//    }

    bool status = ui->robotswitch->isChecked();
    if(status == false)
    {
        Massage("伺服驱动器未开启");
        return;
    }else{
//        for(int i = 0 ; i<Axis_num ; i++)//这个仅仅用于测试，注意速度控制，预计行程在2s左右走完
//        {
//            Myrobot.Axis_Group[i].Axis_start_motion(qn[i],Vm[i]);//这里速度要注意
//        }
        myrobots.Robot_kine(1,qn,5);
    }


}


void MainWindow::on_robotikine1_clicked()//机器人逆运动学调试1
{
    double T[16];//记录输入的位姿
    T[0] = ui->lineEdit_13->text().toDouble();
    T[1] = ui->lineEdit_14->text().toDouble();
    T[2] = ui->lineEdit_15->text().toDouble();
    T[3] = ui->lineEdit_16->text().toDouble();

    T[4] = ui->lineEdit_17->text().toDouble();
    T[5] = ui->lineEdit_20->text().toDouble();
    T[6] = ui->lineEdit_23->text().toDouble();
    T[7] = ui->lineEdit_26->text().toDouble();

    T[8] = ui->lineEdit_18->text().toDouble();
    T[9] = ui->lineEdit_21->text().toDouble();
    T[10] = ui->lineEdit_24->text().toDouble();
    T[11] = ui->lineEdit_27->text().toDouble();

    T[12] = ui->lineEdit_19->text().toDouble();
    T[13] = ui->lineEdit_22->text().toDouble();
    T[14] = ui->lineEdit_25->text().toDouble();
    T[15] = ui->lineEdit_28->text().toDouble();

//    double temp_q0[6] = {0,0,0,0,0,0};

    mwArray *T_to_matlab = new mwArray(4,4,mxDOUBLE_CLASS);//存储向matlab输入的位姿
//    mwArray *qn_from_matlab = new mwArray(1,6,mxDOUBLE_CLASS);//存储matlab返回的数据
//    mwArray *q0 = new mwArray(1,6,mxDOUBLE_CLASS);
//    double qn[6];//存储转换后的关节转角
//    double Vm[6];//存储速度
    T_to_matlab->SetData(T,16);
//    q0->SetData(temp_q0,6);

//    std::cout<<*T_to_matlab<<std::endl;
//    std::cout<<*q0<<std::endl;

//    Robot_ikine_Tool(1,*qn_from_matlab,*T_to_matlab,*q0,mwArray(1),Myrobot.mwTool(1));//matlab计算逆运动学解

//    for(int i = 0 ; i<6 ; i++)
//    {
//        qn[i] = qn_from_matlab->Get(1,i+1);
//        std::cout<<i+1<<"轴转角："<<qn[i]*180/3.1415926<<std::endl;
//        if(qn[i]<0.00001&&qn[i]>-0.00001) qn[i] = 0.0;

//        qn[i] =int(qn[i]/Myrobot.Axis_Group[i].position_to_rad);//将弧度值转换成position的值

//        Vm[i] = (qn[i]-Myrobot.Axis_Group[i].Axis_info.feedback_position)/3;//3s走完该路程
//        if(Vm[i]<0.0)
//        {
//            Vm[i] = -1*Vm[i];
//        }
//        std::cout<<i+1<<"轴转角position："<<qn[i]<<std::endl;
//    }

    bool status = ui->robotswitch->isChecked();
    if(status == false)
    {
        Massage("伺服驱动器未开启");
        return;
    }else{
        //Myrobot.Robot_motion_ikine(1,*T_to_matlab);
//        for(int i = 0 ; i<6 ; i++)//这个仅仅用于测试，注意速度控制，预计行程在2s左右走完
//        {
//            Myrobot.Axis_Group[i].Axis_start_motion(qn[i],Vm[i]);//这里速度要注意
//        }
        myrobots.Robot_ikine(1,*T_to_matlab,5);
    }

    delete T_to_matlab;
//    delete qn_from_matlab;
}

void MainWindow::on_port_turnon_clicked()//打开串口，进行串口通信测试
{

    Modbusport.getparament("COM5",115200);
    if(Modbusport.initial_port())
    {
        std::cout<<"串口初始化成功"<<std::endl;
    }

    return;
}

void MainWindow::on_sent_telegram_clicked()//向串口发送报文
{
    if(Modbusport.Myport == INVALID_HANDLE_VALUE)
    {
        std::cout<<"请先打开串口"<<std::endl;
        return ;
    }

    std::string str_in = ui->tabWidget->currentWidget()->findChild<QLineEdit*>("telegram_Edit")->text().toStdString();
    std::uint8_t *buffer = new std::uint8_t[30];
    std::string str_out;
    int telegram_length = 0;

    if(!Modbusport.writeport(str_in)) return;

    if(!Modbusport.readport(buffer,telegram_length)) return;

    hex_to_string(buffer,telegram_length,str_out);//将串口读到的16进制数据变成字符串的形式

    ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText("报文应答:");
    ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText(QString::fromStdString(str_out)+'\n'+'\n');

    //setText(QString::fromStdString(str_out));

    Modbusport.cleanbuff();
    delete[] buffer;

}


//void MainWindow::on_horizontalSlider_valueChanged(int value)//滑轨直接控制夹钳1
//{
//    if(Modbusport.Myport == INVALID_HANDLE_VALUE) return;//判断是否打开串口
//    //夹钳1 的夹具行程我80——220-340
//    if((value-80)%26 == 0)//最小步进为26，判断是否走过n个26
//    {
//        /***********处理滑轨数据，将其变成发送报文**************/
//        std::string hexString = "01060002";
//        std::stringstream stream;
//        stream << std::setfill('0') << std::setw(4)<<std::hex << value; // 将十进制转换为十六进制,最小长度为2位，不足的用0补齐
//        hexString += stream.str();
//        /**************************************************/

//        /********************读写串口的操作流程********************/
//        std::uint8_t *buffer = new std::uint8_t[30];
//        std::string str_out;
//        int telegram_length = 0;
//        if(!Modbusport.writeport(hexString)) return;//向串口发送数据
//        if(!Modbusport.readport(buffer,telegram_length)) return;//接受报文
//        hex_to_string(buffer,telegram_length,str_out);//将串口读到的16进制数据变成字符串的形式
//        /*********************************************************/

//        //显示报文应答
//        ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText("报文应答:");
//        ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText(QString::fromStdString(str_out)+'\n'+'\n');

//        std::cout << "16进制数值为: 0x" << hexString << std::endl; // 打印十六进制数值
//        std::cout<<"it is:"<<std::dec<<value<<std::endl;
//    }

//}



//void MainWindow::on_horizontalSlider_2_valueChanged(int value)//滑轨直接控制夹钳1
//{
//    if(Modbusport.Myport == INVALID_HANDLE_VALUE) return;//判断是否打开串口
//    //夹钳1 的夹具行程我80——220-340
//    if((value-80)%12 == 0)//最小步进为12，判断是否走过n个12
//    {
//        /***********处理滑轨数据，将其变成发送报文**************/
//        std::string hexString = "02060002";
//        std::stringstream stream;
//        stream << std::setfill('0') << std::setw(4)<<std::hex << value; // 将十进制转换为十六进制,最小长度为2位，不足的用0补齐
//        hexString += stream.str();
//        /**************************************************/

//        /********************读写串口的操作流程********************/
//        std::uint8_t *buffer = new std::uint8_t[30];
//        std::string str_out;
//        int telegram_length = 0;
//        if(!Modbusport.writeport(hexString)) return;//向串口发送数据
//        if(!Modbusport.readport(buffer,telegram_length)) return;//接受报文
//        hex_to_string(buffer,telegram_length,str_out);//将串口读到的16进制数据变成字符串的形式
//        /*********************************************************/

//        //显示报文应答
//        ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText("报文应答:");
//        ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText(QString::fromStdString(str_out)+'\n'+'\n');

//        std::cout << "16进制数值为: 0x" << hexString << std::endl; // 打印十六进制数值
//                std::cout<<"it is:"<<std::dec<<value<<std::endl;
//    }

//}


void MainWindow::on_stop_button_clicked()
{

    for(int i=0;i<12;i++)
    {
        APS_stop_move(i);
    }
    myrobots.Emergency_stop();
    //Myrobot.Robot_stop();
}

void MainWindow::on_robotkine2_clicked()//机器人2正运动学解调试
{
    double qn[6] = {0.0};
    qn[0] = ui->lineEdit_7->text().toDouble();
    qn[1] = ui->lineEdit_8->text().toDouble();
    qn[2] = ui->lineEdit_9->text().toDouble();
    qn[3] = ui->lineEdit_10->text().toDouble();
    qn[4] = ui->lineEdit_11->text().toDouble();
    qn[5] = ui->lineEdit_12->text().toDouble();

//    for(int i = 6 ; i<12 ; i++)//控制2号机械臂的运动
//    {
//        std::cout<<i<<"弧度位置："<<qn[i]<<endl;
//        qn[i-6] = qn[i-6]/Myrobot.Axis_Group[i].position_to_rad;
//        Vm[i-6] = (qn[i-6]-Myrobot.Axis_Group[i].Axis_info.feedback_position)/5;//Vm注意一下
//        if(Vm[i-6]<0.0)
//        {
//            Vm[i-6] = -1*Vm[i-6];
//        }
//        std::cout<<i<<"position位置："<<qn[i-6]<<std::endl;
//        std::cout<<i<<"速度为："<<Vm[i-6]<<endl;
//    }

    bool status = ui->robotswitch->isChecked();
    if(status == false)
    {
        Massage("伺服驱动器未开启");
        return;
    }else{
        myrobots.Robot_kine(2,qn,5);//5秒运动完毕
//        for(int i = 6 ; i<Axis_num ; i++)//这个仅仅用于测试，注意速度控制，预计行程在2s左右走完
//        {
//            Myrobot.Axis_Group[i].Axis_start_motion(qn[i-6],Vm[i-6]);//这里速度要注意
//        }
    }

}


void MainWindow::on_robotikine2_clicked()//机器人2逆运动学调试
{
    double T[16];//记录输入的位姿
    T[0] = ui->lineEdit_13->text().toDouble();
    T[1] = ui->lineEdit_14->text().toDouble();
    T[2] = ui->lineEdit_15->text().toDouble();
    T[3] = ui->lineEdit_16->text().toDouble();

    T[4] = ui->lineEdit_17->text().toDouble();
    T[5] = ui->lineEdit_20->text().toDouble();
    T[6] = ui->lineEdit_23->text().toDouble();
    T[7] = ui->lineEdit_26->text().toDouble();

    T[8] = ui->lineEdit_18->text().toDouble();
    T[9] = ui->lineEdit_21->text().toDouble();
    T[10] = ui->lineEdit_24->text().toDouble();
    T[11] = ui->lineEdit_27->text().toDouble();

    T[12] = ui->lineEdit_19->text().toDouble();
    T[13] = ui->lineEdit_22->text().toDouble();
    T[14] = ui->lineEdit_25->text().toDouble();
    T[15] = ui->lineEdit_28->text().toDouble();

//    double temp_q0[6] = {0,0,0,0,0,0};

    mwArray T_to_matlab = mwArray(4,4,mxDOUBLE_CLASS);//存储向matlab输入的位姿
//    mwArray *qn_from_matlab = new mwArray(1,6,mxDOUBLE_CLASS);//存储matlab返回的数据
//    mwArray *q0 = new mwArray(1,6,mxDOUBLE_CLASS);
//    double qn[6];//存储转换后的关节转角
//    double Vm[6];//存储速度
    T_to_matlab.SetData(T,16);
//    q0->SetData(temp_q0,6);

//    std::cout<<*T_to_matlab<<std::endl;
//    std::cout<<*q0<<std::endl;
//    mwArray index = mwArray(1,1,mxINT32_CLASS);
//    index(1,1) = 2;
//    std::cout<<index<<std::endl;
//    std::cout<<mwArray(2)<<std::endl;
//    std::cout<<Myrobot.mwTool(2)<<std::endl;
//    Robot_ikine_Tool(1,*qn_from_matlab,*T_to_matlab,*q0,index,Myrobot.mwTool(2));//matlab计算逆运动学解

//    for(int i = 6 ; i<12 ; i++)//机器人2的轴关节选择
//    {
//        qn[i-6] = qn_from_matlab->Get(1,i+1-6);
//        std::cout<<i+1<<"轴转角："<<qn[i-6]*180/3.1415926<<std::endl;
//        if(qn[i-6]<0.00001&&qn[i-6]>-0.00001) qn[i-6] = 0.0;

//        qn[i-6] =int(qn[i-6]/Myrobot.Axis_Group[i].position_to_rad);//将弧度值转换成position的值

//        Vm[i-6] = (qn[i-6]-Myrobot.Axis_Group[i].Axis_info.feedback_position)/3;//3s走完该路程
//        if(Vm[i-6]<0.0)
//        {
//            Vm[i-6] = -1*Vm[i-6];
//        }
//        std::cout<<i+1<<"轴转角position："<<qn[i-6]<<std::endl;
//    }

    bool status = ui->robotswitch->isChecked();
    if(status == false)
    {
        Massage("伺服驱动器未开启");
        return;
    }else{
        myrobots.Robot_ikine(2,T_to_matlab,5);//5s走完
        //Myrobot.Robot_motion_ikine(2,T_to_matlab);
//        for(int i = 6 ; i<12 ; i++)//这个仅仅用于测试，注意速度控制，预计行程在3s左右走完
//        {
//            Myrobot.Axis_Group[i].Axis_start_motion(qn[i-6],Vm[i-6]);//这里速度要注意
//        }

    }

    //delete qn_from_matlab;
}


void MainWindow::on_CalibrateC_R2_clicked()//Ax=xB来求解手眼标定问题
{
    //std::cout<<ui->tabWidget->currentWidget()->findChild<QComboBox*>("Robot_select")->currentIndex();
    int Robot_index = ui->Robot_select->currentIndex();
    std::cout<<Robot_index<<std::endl;
    /*************1.首先求出标定板相对于相机的位姿******************/
    const int corner_nums = 88;//棋盘格角点的数量
    cv::Mat objectPoints(corner_nums, 3, CV_64F);
    cv::Mat imagePoints(corner_nums, 2, CV_64F);

    //start 导入棋盘格世界坐标系，以棋盘格为世界坐标系
    vector<vector<double>> platepoints(88,vector<double>(3));//定义标定板坐标系
    vector<double> point0 = {0,0,0};

    for(int i = 0 ; i < 8 ; i++)//生成该处棋盘格各个角点位姿
    {
        for(int j = 0 ; j<11 ; j++)
        {
            platepoints[i*11+j] = point0;
            point0[0]-=15.0;//x轴每次-15
        }
        point0[0] += 15.0*11;//把x轴拉回到原来的数据
        point0[1] += 15;//y轴每次+15
    }

    for(int i = 0 ; i<88 ; i++)
    {
        objectPoints.at<double>(i,0)= platepoints[i][0];
        objectPoints.at<double>(i,1)= platepoints[i][1];
        objectPoints.at<double>(i,2)= platepoints[i][2];
    }

    std::vector<cv::Point3d> outputVec;//把棋盘格坐标系坐标变成Point3d类型
    for (const auto& vec : platepoints) {
        if (vec.size() != 3) {
            std::cerr << "Error: Inner vector size must be 3 for conversion to cv::Point3f." << std::endl;
            return ;
        }
        outputVec.emplace_back(cv::Point3d(vec[0], vec[1], vec[2]));
    }

    //start 下面来获取棋盘格角点坐标（相对于相机而言），注意棋盘格交点坐标需要和上述标定板坐标对应
    //获取两个棋盘图像
    cv::Mat board_picture_1 = Mycameras.mycamera[0]->cv_image;
    cv::Mat board_picture_1_rgb = Mycameras.mycamera[0]->cv_image.clone();
    cv::cvtColor(board_picture_1,board_picture_1,cv::COLOR_BGR2GRAY);
    cv::Mat undis_board_picture_1;//保存矫正后的图像
    cv::Mat undis_board_picture_1_rgb;
    cv::undistort(board_picture_1,undis_board_picture_1,Mycameras.IntrinMatrix_camera1,Mycameras.camera1_dis);
    cv::undistort(board_picture_1_rgb,undis_board_picture_1_rgb,Mycameras.IntrinMatrix_camera1,Mycameras.camera1_dis);
    cv::namedWindow("1",WINDOW_NORMAL);
    cv::namedWindow("undis_1",WINDOW_NORMAL);
    cv::imshow("1",board_picture_1);
    cv::imshow("undis_1",undis_board_picture_1);
    cv::waitKey(0);
    cv::destroyWindow("1");
    cv::destroyWindow("undis_1");

    cv::Size boardsize;
    boardsize.width = 11;//棋盘格宽度
    boardsize.height = 8;//棋盘格长度
    std::vector<cv::Point2f> point1;//记录角点的数组

    bool ret1 = findChessboardCornersSB(undis_board_picture_1, boardsize, point1 ,
                                        CALIB_CB_EXHAUSTIVE | CALIB_CB_ACCURACY);
    if(ret1==true)
    {
        std::cout<<"The first pcture corner :"<<std::endl<<point1<<std::endl;
        drawChessboardCorners(undis_board_picture_1, boardsize, point1, ret1);//画出角点
    }else{
        std::cout<<"find chess board corner failed!!!"<<std::endl;
        return ;
    }
    cv::namedWindow("undis_board_picture_1",cv::WINDOW_NORMAL);
    //cv::resizeWindow("undis_board_picture_1",800,600);

    cv::imshow("undis_board_picture_1",undis_board_picture_1);
    cv::waitKey(0);
    cv::destroyWindow("undis_board_picture_1");
    //end
    //imagePoints = cv::Mat(corner_nums,2,CV_64F,point1.data()).clone();
    for(int i = 0 ;i<88 ; i++)
    {
        imagePoints.at<double>(i,0) = point1[i].x;
        imagePoints.at<double>(i,1) = point1[i].y;
    }

    //cout<<imagePoints<<endl;

    cv::Mat cameraMatrix(3,3,CV_64F);
    cameraMatrix = Mycameras.IntrinMatrix_camera1;//相机1的内参矩阵
    cv::Mat distCoeffs(1,5,CV_64F);
    distCoeffs= Mycameras.camera1_dis;//相机1的畸变系数

    cv::Mat rvec(3, 1, CV_64F);//用于保存结果，旋转分量,是三行一列的旋转分量并非旋转矩阵
    cv::Mat tvec(3, 1, CV_64F);//用于保存结果，平移分量

    if(!cv::solvePnP(objectPoints,imagePoints, cameraMatrix, distCoeffs, rvec, tvec))//利用solvepnp求解相机姿态
    {
        cout<<"solvePnP Failed!!!"<<endl;
        return;
    }

    cout<<rvec<<endl;
    /*画一下图来验证下*/
    std::vector<cv::Point3f> axis_points = { {0,0,0},{15,0,0},{0,15,0},{0,0,15}};//坐标轴
    //cv::Mat img_points;
    vector<cv::Point2f> img_points;

    cv::projectPoints(
        axis_points,
        rvec,
        tvec,
        cameraMatrix,
        distCoeffs,
        img_points);//投影映射函数

    cv::line(undis_board_picture_1_rgb, img_points[0], img_points[1], cv::Scalar(0, 0, 255), 10); // 红色 X 轴
    cv::line(undis_board_picture_1_rgb, img_points[0], img_points[2], cv::Scalar(0, 255, 0), 10); // 绿色 Y 轴
    cv::line(undis_board_picture_1_rgb, img_points[0], img_points[3], cv::Scalar(255, 0, 0), 10); // 蓝色 Z 轴

    cv::namedWindow("test_axis",cv::WINDOW_NORMAL);
    cv::imshow("test_axis",undis_board_picture_1_rgb);
    cv::waitKey(0);

    cv::Mat rotation_matrix; // 用于存储旋转矩阵
    cv::Rodrigues(rvec, rotation_matrix); // 将旋转向量转换为旋转矩阵

    mwArray transP2R(4,4,mxDOUBLE_CLASS);//定义标定板相对于棋盘格的位姿
    for(int i = 0 ; i <rotation_matrix.rows ; i++)
    {
        for(int j = 0 ; j <rotation_matrix.cols ; j++)
        {
            transP2R(i+1,j+1) = rotation_matrix.at<double>(i,j);
        }
    }

    transP2R(1,4) = tvec.at<double>(0,0);
    transP2R(2,4) = tvec.at<double>(1,0);
    transP2R(3,4) = tvec.at<double>(2,0);
    transP2R(4,4) = 1;
    cout<<tvec.at<double>(0,0)<<" "<<tvec.at<double>(1,0)<<" "<<tvec.at<double>(2,0)<<" "<<endl;
    cout<<"棋盘格位姿为"<<transP2R<<endl;

    /********************************************************/

    /*******************2.获取机械臂末端位姿************************/
    mwArray robot_status(4,4,mxDOUBLE_CLASS);//机器人末端坐标的位姿

    myrobots.Get_hand_position(Robot_index+1,robot_status);
    cout<<robot_status<<endl;
    /************************************************************/

}


void MainWindow::on_Robot_move_clicked()
{
//    //获取物体相对于相机的坐标
//    Eigen::Matrix<double,4,1> position2camera={Mycameras.Position_3D_x,Mycameras.Position_3D_y,Mycameras.Position_3D_z,1};
//    //选择机械臂索引,并计算机器人坐标系下的坐标
//    Eigen::Matrix<double,4,4> T_r_c;
//    double position2Robot1[16]={1,  0,  0,  0,
//                                0,  -1, 0,  0,
//                                0,  0,  -1, 0,
//                                0,  0,  0,  1};

//    double position2Robot2[16]={0,  1,  0,  0,
//                                1,  0,  0,  0,
//                                0,  0,  -1, 0,
//                                0,  0,  0,  1};
//    mwArray position2Robot_mwarray(4,4,mxDOUBLE_CLASS);
//    Eigen::Matrix<double,4,1>position2Robot;
//    switch(ui->Robot_select->currentIndex())
//    {
//    case 0:

//        T_r_c<< T_Robot2Camera[0][0],T_Robot2Camera[0][1],T_Robot2Camera[0][2],T_Robot2Camera[0][3],
//                T_Robot2Camera[1][0],T_Robot2Camera[1][1],T_Robot2Camera[1][2],T_Robot2Camera[1][3],
//                T_Robot2Camera[2][0],T_Robot2Camera[2][1],T_Robot2Camera[2][2],T_Robot2Camera[2][3],
//                T_Robot2Camera[3][0],T_Robot2Camera[3][1],T_Robot2Camera[3][2],T_Robot2Camera[3][3];
//        position2Robot = T_r_c*position2camera;
//        position2Robot1[3] = position2Robot(0,0);
//        position2Robot1[7] = position2Robot(1,0);
//        position2Robot1[11] = position2Robot(2,0);
//        position2Robot_mwarray.SetData(position2Robot1,16);

//        break;

//    case 1:
//        T_r_c<< T_Robot2Camera2[0][0],T_Robot2Camera2[0][1],T_Robot2Camera2[0][2],T_Robot2Camera2[0][3],
//                T_Robot2Camera2[1][0],T_Robot2Camera2[1][1],T_Robot2Camera2[1][2],T_Robot2Camera2[1][3],
//                T_Robot2Camera2[2][0],T_Robot2Camera2[2][1],T_Robot2Camera2[2][2],T_Robot2Camera2[2][3],
//                T_Robot2Camera2[3][0],T_Robot2Camera2[3][1],T_Robot2Camera2[3][2],T_Robot2Camera2[3][3];
//        position2Robot = T_r_c*position2camera;
//        position2Robot2[3] = position2Robot(0,0);
//        position2Robot2[7] = position2Robot(1,0);
//        position2Robot2[11] = position2Robot(2,0);
//        position2Robot_mwarray.SetData(position2Robot2,16);
//        break;

//    default:
//        return;
//    }

//    bool status = ui->robotswitch->isChecked();
//    if(status == false)
//    {
//        Massage("伺服驱动器未开启");
//        return;
//    }else{
//        Myrobot.Robot_motion_ikine(ui->Robot_select->currentIndex()+1,position2Robot_mwarray);
//    }
}


//void MainWindow::on_Py_initialize_clicked()//初始化Py环境
//{
//    std::cout<<"successfully to Initialize!"<<std::endl;
//    ui->Model_predict->setEnabled(true);//设置模型触发可预测
////    const wchar_t* str1 = L"D://Anaconda//envs//TF2_HLH";
////    const char* str2 = "D://call_python";
////    if(Mypython_model.InitialPyhton(str1,str2))
////    {
////        ui->Model_predict->setEnabled(true);//设置模型触发可预测
////        std::cout<<"successfully to Initialize!"<<std::endl;
////    }
////    Mypython_model.Setfunction();//设置python运行文件和函数
//}


//void MainWindow::on_Model_predict_clicked()//进行模型预测
//{

//    connect(this,&MainWindow::Signal_show_pre_pic,this,&MainWindow::show_pre_pic);
//    static std::thread thread1([this](){
//        static PythonModel Mypython_model2;
//        const wchar_t* str1 = L"D://Anaconda//envs//TF2_HLH";
//        const char* str2 = "D:/call_python";
//        Mypython_model2.InitialPyhton(str1, str2);

//        Mypython_model2.Setfunction("callpython", "predict_image");
//        while(1)
//        {
//            Mycameras.mycamera[0]->mycamera_picture_lock.lock();
//            Mycameras.mycamera[1]->mycamera_picture_lock.lock();
//            cv::Mat picsrc1 = Mycameras.mycamera[0]->cv_image.clone();
//            cv::Mat picsrc2 = Mycameras.mycamera[1]->cv_image.clone();
//            Mycameras.mycamera[0]->mycamera_picture_lock.unlock();
//            Mycameras.mycamera[1]->mycamera_picture_lock.unlock();
//            cv::Mat picdet1,picdet2;
//            cv::resize(picsrc1,picsrc1,cv::Size(),0.2,0.2);
//            cv::resize(picsrc2,picsrc2,cv::Size(),0.2,0.2);

//            Mypython_model2.trans_img2func(picsrc1,picdet1);
//            Mypython_model2.trans_img2func(picsrc2,picdet2);
//            cv::resize(picdet1,picdet1,cv::Size(),5,5);
//            cv::resize(picdet2,picdet2,cv::Size(),5,5);
//            emit Signal_show_pre_pic(picdet1,ui->phoframe1);
//            emit Signal_show_pre_pic(picdet2,ui->phoframe2);
//            Sleep(40);
//        }
//    });

//    return ;

//}

void MainWindow::on_test_new_robot_clicked()
{
//    static I32 nums[6] = {6,7,8,9,10,11};
//    static double p2r[6] = {0.06/5000,0.06/5000,0.06/5000,0.06/5000,0.06/5000,0.06/5000};
//    static double offset[6]={111458,206375,214858,160000,-100964,85206};
//    static C_Robot_Arm test_robot(nums,p2r,offset);
//    test_robot.Robot_index=2;
//    test_robot.Robot_servo_on();
//    double qn[6];
//    qn[0] = ui->lineEdit_7->text().toDouble();
//    qn[1] = ui->lineEdit_8->text().toDouble();
//    qn[2] = ui->lineEdit_9->text().toDouble();
//    qn[3] = ui->lineEdit_10->text().toDouble();
//    qn[4] = ui->lineEdit_11->text().toDouble();
//    qn[5] = ui->lineEdit_12->text().toDouble();
//    test_robot.Robot_get_info();


////    bool status = ui->robotswitch->isChecked();
////    if(status == false)
////    {
////        Massage("伺服驱动器未开启");
////        return;
////    }else{

////        test_robot.Robot_motion_kine(qn);
////    }
//    test_robot.Robot_motion_kine(qn);
//    Sleep(10000);
//    double qn2[6] = {0.0,0.0,0.0,0.0,0.0,0.0};
//    test_robot.Robot_motion_kine(qn2);
//    Sleep(10000);
//    test_robot.Robot_servo_off();
}


void MainWindow::on_pushButton_38_toggled(bool checked)
{
    std::cout<<"...."<<std::endl;
    bool status = checked;
    if(status == true){
        bool ret = Myminicamera.Turn_on_camera();
        if(ret)
        {
            std::cout<<"相机已经打开"<<std::endl;
        }else{
            std::cout<<"未检测到相机"<<std::endl;
        }
    }else{
        Myminicamera.Turn_off_camera();
        std::cout<<"相机已经关闭"<<std::endl;
    }

    return;
}


void MainWindow::on_pushButton_39_clicked()
{
    static QImage qimage_minicamera_src;
    static QImage qimage_minicamera_linfit;
    std::thread mythread([this](){
        while(1)
        {
            bool ret=Myminicamera.Capture_frame();
            if(!ret){
                std::cout<<"未取到流"<<std::endl;
                break;
            }
            if(Myminicamera.imagesrc.empty()){
                continue;
            }
            double k1=0,k2=0;
            std::vector<float> centralpoints1(2), centralpoints2(2);
            ret = Myminicamera.Image_processing_for_Fitline(k1,k2,centralpoints1,centralpoints2);
            if(!ret)
            {
                std::cout<<"wait a moment"<<std::endl;
                Sleep(500);
                continue;
            }
            qimage_minicamera_src = QImage((const unsigned char*)Myminicamera.imagesrc.data,
                                                  Myminicamera.imagesrc.cols,
                                                  Myminicamera.imagesrc.rows,
                                                  Myminicamera.imagesrc.step,
                                                  QImage::Format_BGR888).copy();
            qimage_minicamera_linfit = QImage((const unsigned char*)Myminicamera.image_line_fit.data,
                                                     Myminicamera.image_line_fit.cols,
                                                     Myminicamera.image_line_fit.rows,
                                                     Myminicamera.image_line_fit.step,
                                                     QImage::Format_BGR888).copy();
            ui->miniCamera_label1->setPixmap(QPixmap::fromImage(qimage_minicamera_src.scaled(ui->phoframe1->size(),Qt::KeepAspectRatioByExpanding)));
            ui->miniCamera_label2->setPixmap(QPixmap::fromImage(qimage_minicamera_linfit.scaled(ui->phoframe1->size(),Qt::KeepAspectRatioByExpanding)));
            Sleep(30);
        }
        return;
    });

    mythread.detach();
    return;
}


void MainWindow::on_pushButton_41_clicked()//显示线相对于相机的姿态
{
    std::cout<<"线相对于相机的姿态："<<Myminicamera.Show_R()<<std::endl;
    cv::Mat R_line = Myminicamera.Show_R();
    mwArray R_tool_mw(4,4,mxDOUBLE_CLASS);
    myrobots.Get_hand_position(2,R_tool_mw);
    cv::Mat R_tool = (cv::Mat_<double>(3,3)<<R_tool_mw(1,1),R_tool_mw(1,2),R_tool_mw(1,3),
                                             R_tool_mw(2,1),R_tool_mw(2,2),R_tool_mw(2,3),
                                             R_tool_mw(3,1),R_tool_mw(3,2),R_tool_mw(3,3));

    cv::Mat R_obj = R_tool*R_line;
    std::cout<<R_obj<<std::endl;
    return;
}


void MainWindow::on_pushButton_42_clicked()//校正姿态
{
    std::thread temp_thread([this](){
        Operat_tool(260,2);//打开夹钳
        //调整绕z轴旋转角度
        bool ret = Adjust_theta_z();
        if(!ret){
            std::cout<<"调整theta_z失败"<<std::endl;
            return;
        }
        Sleep(5000);
        //调整y，z距离
        ret = Adjust_delt_z_y();
        if(!ret){
            std::cout<<"调整distance_z_y失败"<<std::endl;
            return ;
        }
        Sleep(5000);
        //再调整一遍z
        ret = Adjust_theta_z();
        if(!ret){
            std::cout<<"调整theta_z失败"<<std::endl;
                return;
        }
        Sleep(5000);
        //计算绕Y轴旋转的角度
        ret = Adjust_theta_y();
        if(!ret){
            std::cout<<"调整theta_y失败"<<std::endl;
            return ;
        }
        Sleep(5000);
        ret = Adjust_theta_z();
        if(!ret){
            std::cout<<"调整theta_z失败"<<std::endl;
            return;
        }
        Sleep(5000);
        mwArray R_tool_mw(4,4,mxDOUBLE_CLASS);
        myrobots.Get_hand_position(2,R_tool_mw);
        double a12 = R_tool_mw(1,2);
        double a13 = R_tool_mw(1,3);
        double a22 = R_tool_mw(2,2);
        double a23 = R_tool_mw(2,3);
        double a32 = R_tool_mw(3,2);
        double a33 = R_tool_mw(3,3);
        double org_x = R_tool_mw(1,4);//x的原值
        double org_y = R_tool_mw(2,4);//y的原值
        double org_z = R_tool_mw(3,4);//z的原值
        std::cout<<"R_tool_mw(3,4)为"<<R_tool_mw(3,4)<<std::endl;
            //std::cout<<"需要向下移动："<<(Myminicamera.Show_z()-10.5)<<std::endl;
        double z=15.0,y=-9.0;
//        ret = Myminicamera.Calculation_distance_z_y(z,y);
//        if(!ret){
//            return ;
//        }
        //特别注意这里的位置变换的参考坐标系！！！！！
        R_tool_mw(1,4) = a12*y+a13*z+org_x;
        R_tool_mw(2,4) = a22*y+a23*z+org_y;
        R_tool_mw(3,4) = a32*y+a33*z+org_z;
        std::cout<<"Now the namber of R_tool_mw is: "<<std::endl;
        std::cout<<R_tool_mw<<std::endl;
        Sleep(1000);
        //Myrobot.Robot_motion_ikine(2,R_tool_mw);//末端夹具校正位姿
        myrobots.Robot_ikine(2,R_tool_mw,5);
        Sleep(5000);
        Operat_tool(344,2);//关闭夹钳
        Sleep(2000);
        return ;
    });


    temp_thread.detach();//分离线程

    return;
}


void MainWindow::on_stop_button_2_clicked()//第二个急停按钮
{
    for(int i=0;i<12;i++)
    {
        APS_stop_move(i);
    }
    myrobots.Emergency_stop();
    //Myrobot.Robot_stop();
}

bool MainWindow::Adjust_theta_z()
{
    cv::Mat R_line = Myminicamera.Show_R();
    mwArray R_tool_mw (4,4,mxDOUBLE_CLASS);
    myrobots.Get_hand_position(2,R_tool_mw);
    cv::Mat R_tool = (cv::Mat_<double>(3,3)<<R_tool_mw(1,1),R_tool_mw(1,2),R_tool_mw(1,3),
                      R_tool_mw(2,1),R_tool_mw(2,2),R_tool_mw(2,3),
                      R_tool_mw(3,1),R_tool_mw(3,2),R_tool_mw(3,3));

    cv::Mat R_obj = R_tool*R_line;

    R_tool_mw(1,1)=R_obj.at<double>(0,0);
    R_tool_mw(1,2)=R_obj.at<double>(0,1);
    R_tool_mw(1,3)=R_obj.at<double>(0,2);
    R_tool_mw(2,1)=R_obj.at<double>(1,0);
    R_tool_mw(2,2)=R_obj.at<double>(1,1);
    R_tool_mw(2,3)=R_obj.at<double>(1,2);
    R_tool_mw(3,1)=R_obj.at<double>(2,0);
    R_tool_mw(3,2)=R_obj.at<double>(2,1);
    R_tool_mw(3,3)=R_obj.at<double>(2,2);

    std::cout<<"校正后的末端位置："<<R_tool_mw<<std::endl;
    myrobots.Robot_ikine(2,R_tool_mw,5);
    //Myrobot.Robot_motion_ikine(2,R_tool_mw);//末端夹具校正位姿

    return true;
}

bool MainWindow::Adjust_delt_z_y()
{
    mwArray R_tool_mw (4,4,mxDOUBLE_CLASS);
    myrobots.Get_hand_position(2,R_tool_mw);
    double a12 = R_tool_mw(1,2);
    double a13 = R_tool_mw(1,3);
    double a22 = R_tool_mw(2,2);
    double a23 = R_tool_mw(2,3);
    double a32 = R_tool_mw(3,2);
    double a33 = R_tool_mw(3,3);
    double org_x = R_tool_mw(1,4);//x的原值
    double org_y = R_tool_mw(2,4);//y的原值
    double org_z = R_tool_mw(3,4);//z的原值
    std::cout<<"R_tool_mw(3,4)为"<<R_tool_mw(3,4)<<std::endl;
        //std::cout<<"需要向下移动："<<(Myminicamera.Show_z()-10.5)<<std::endl;
    double z=0,y=0;
    bool ret = Myminicamera.Calculation_distance_z_y(z,y);
    if(!ret){
        return false;
    }
    //特别注意这里的位置变换的参考坐标系！！！！！
    R_tool_mw(1,4) = a12*y+a13*z+org_x;
    R_tool_mw(2,4) = a22*y+a23*z+org_y;
    R_tool_mw(3,4) = a32*y+a33*z+org_z;
    std::cout<<"Now the namber of R_tool_mw is: "<<std::endl;
    std::cout<<R_tool_mw<<std::endl;
    //Sleep(1000);
    //Myrobot.Robot_motion_ikine(2,R_tool_mw);//末端夹具校正位姿
    myrobots.Robot_ikine(2,R_tool_mw,5);
    return true;
}

bool MainWindow::Adjust_theta_y()
{
    double theta = 0.00;
    bool ret = Myminicamera.Calculation_theta(theta);
    if(!ret){
        return false;
    }

    cv::Mat R_Y = (cv::Mat_<double>(3,3)<<cos(theta),0.00,sin(theta),
                   0.00,      1.00,0.00,
                   -sin(theta),0.00,cos(theta));

    std::cout<<"末端相机需要绕Y轴旋转的角度为"<<theta<<std::endl;
    std::cout<<"将其换算成R_Y"<<R_Y<<std::endl;
    mwArray  R_tool_mw (4,4,mxDOUBLE_CLASS);
    myrobots.Get_hand_position(2,R_tool_mw);
    //double org_y = R_tool_mw(2,4);//y的原值
    //double org_z = R_tool_mw(3,4);//z的原值
    cv::Mat R_tool = (cv::Mat_<double>(3,3)<<R_tool_mw(1,1),R_tool_mw(1,2),R_tool_mw(1,3),
                                             R_tool_mw(2,1),R_tool_mw(2,2),R_tool_mw(2,3),
                                             R_tool_mw(3,1),R_tool_mw(3,2),R_tool_mw(3,3));
    cv::Mat R_obj = R_tool*R_Y;

    R_tool_mw(1,1)=R_obj.at<double>(0,0);
    R_tool_mw(1,2)=R_obj.at<double>(0,1);
    R_tool_mw(1,3)=R_obj.at<double>(0,2);
    R_tool_mw(2,1)=R_obj.at<double>(1,0);
    R_tool_mw(2,2)=R_obj.at<double>(1,1);
    R_tool_mw(2,3)=R_obj.at<double>(1,2);
    R_tool_mw(3,1)=R_obj.at<double>(2,0);
    R_tool_mw(3,2)=R_obj.at<double>(2,1);
    R_tool_mw(3,3)=R_obj.at<double>(2,2);

    //R_tool_mw(2,4) = org_y+2.0;
    //R_tool_mw(3,4) = org_z + 3.0;
    std::cout<<"校正后的末端位置："<<R_tool_mw<<std::endl;
    //Myrobot.Robot_motion_ikine(2,R_tool_mw);//末端夹具校正位姿
    myrobots.Robot_ikine(2,R_tool_mw,5);
    return true;
}

void MainWindow::Operat_tool(int value ,int index)//value取值380-260 对应关闭和打开
{
    if(Modbusport.Myport == INVALID_HANDLE_VALUE){
        cout<<"Failed to turn on the port"<<endl;
        return;//判断是否打开串口
    }

    if((value-80)%12 == 0)//最小步进为12，判断是否走过n个12
    {
        /***********处理滑轨数据，将其变成发送报文**************/
        std::string hexString ;
        if(index == 1){
            hexString = "01060002";
        }else if(index==2){
            hexString = "02060002";
        }else{
            std::cout<<"The tool index error !!!"<<std::endl;
            return;
        }

        std::stringstream stream;
        stream << std::setfill('0') << std::setw(4)<<std::hex << value; // 将十进制转换为十六进制,最小长度为2位，不足的用0补齐
        hexString += stream.str();
        /**************************************************/

        /********************读写串口的操作流程********************/
        std::uint8_t *buffer = new std::uint8_t[30];
        std::string str_out;
        int telegram_length = 0;
        std::cout<<hexString<<std::endl;
        if(!Modbusport.writeport(hexString)) return;//向串口发送数据
        if(!Modbusport.readport(buffer,telegram_length)) return;//接受报文
        hex_to_string(buffer,telegram_length,str_out);//将串口读到的16进制数据变成字符串的形式
        /*********************************************************/

        //显示报文应答
        //ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText("报文应答:");
        //ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText(QString::fromStdString(str_out)+'\n'+'\n');

        std::cout << "16进制数值为: 0x" << hexString << std::endl; // 打印十六进制数值
        std::cout<<"it is:"<<std::dec<<value<<std::endl;
        delete[] buffer;
    }

    return ;
}





void MainWindow::on_horizontalSlider_2_sliderMoved(int position)//夹钳2:380-260，对应关和开
{
    if(Modbusport.Myport == INVALID_HANDLE_VALUE) return;//判断是否打开串口

    if((position-80)%12 == 0)//最小步进为12，判断是否走过n个12
    {
        /***********处理滑轨数据，将其变成发送报文**************/
        std::string hexString = "02060002";
        std::stringstream stream;
        stream << std::setfill('0') << std::setw(4)<<std::hex << position; // 将十进制转换为十六进制,最小长度为2位，不足的用0补齐
        hexString += stream.str();
        /**************************************************/

        /********************读写串口的操作流程********************/
        std::uint8_t *buffer = new std::uint8_t[30];
        std::string str_out;
        int telegram_length = 0;
        if(!Modbusport.writeport(hexString)) return;//向串口发送数据
        if(!Modbusport.readport(buffer,telegram_length)) return;//接受报文
        hex_to_string(buffer,telegram_length,str_out);//将串口读到的16进制数据变成字符串的形式
        /*********************************************************/

        //显示报文应答
        ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText("报文应答:");
        ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText(QString::fromStdString(str_out)+'\n'+'\n');

        std::cout << "16进制数值为: 0x" << hexString << std::endl; // 打印十六进制数值
        std::cout<<"it is:"<<std::dec<<position<<std::endl;
    }
}


void MainWindow::on_horizontalSlider_1_sliderMoved(int position)
{
    if(Modbusport.Myport == INVALID_HANDLE_VALUE) return;//判断是否打开串口

    if((position-80)%12 == 0)//最小步进为12，判断是否走过n个12
    {
                /***********处理滑轨数据，将其变成发送报文**************/
                std::string hexString = "01060002";
                std::stringstream stream;
                stream << std::setfill('0') << std::setw(4)<<std::hex << position; // 将十进制转换为十六进制,最小长度为2位，不足的用0补齐
                hexString += stream.str();
                /**************************************************/

                /********************读写串口的操作流程********************/
                std::uint8_t *buffer = new std::uint8_t[30];
                std::string str_out;
                int telegram_length = 0;
                if(!Modbusport.writeport(hexString)) return;//向串口发送数据
                if(!Modbusport.readport(buffer,telegram_length)) return;//接受报文
                hex_to_string(buffer,telegram_length,str_out);//将串口读到的16进制数据变成字符串的形式
                /*********************************************************/

                //显示报文应答
                ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText("报文应答:");
                ui->tabWidget->currentWidget()->findChild<QTextEdit*>("readport_text")->insertPlainText(QString::fromStdString(str_out)+'\n'+'\n');

                std::cout << "16进制数值为: 0x" << hexString << std::endl; // 打印十六进制数值
                std::cout<<"it is:"<<std::dec<<position<<std::endl;
    }
}

void MainWindow::extracted(std::vector<std::vector<double>> &vec_V_qF) {
    for (auto it : vec_V_qF) {
                        for (auto it2 : it) {
            std::cout << it2 << std::endl;
                        }
    }
}
void MainWindow::on_pushButton_37_clicked() // 测试两机械臂紧协调运动
{
    //    mwArray V_qF(6,1,mxDOUBLE_CLASS),V_qL(6,1,mxDOUBLE_CLASS);
    //    mwArray qL1(1,6,mxDOUBLE_CLASS),qF1(1,6,mxDOUBLE_CLASS);
    //    mwArray tool1(1,3,mxDOUBLE_CLASS),tool2(1,3,mxDOUBLE_CLASS);
    //    mwArray V_end(6,1,mxDOUBLE_CLASS);
    //    mwArray t_offset(1,3,mxDOUBLE_CLASS);

    //    double vec_qL1[6] = {0,PI/3-PI/2,0,0,-PI/3,0};
    //    qL1.SetData(vec_qL1,6);

    //    double vec_qF1[6] =
    //    {1.3517,-0.1604-PI/2,-0.9667-PI/2,0.7645+PI/2,-1.5708,1.3517};
    //    qF1.SetData(vec_qF1,6);

    //    double vec_tool1[3] = {0,0,0};
    //    tool1.SetData(vec_tool1,3);

    //    double vec_tool2[3] = {0,0,0};
    //    tool2.SetData(vec_tool2,3);

    //    double vec_V_end[6] = {0,-1.5,0,0,0,0.0025};
    //    V_end.SetData(vec_V_end,6);

    //    double vec_t_offset[3] = {0,-500,0};
    //    t_offset.SetData(vec_t_offset,3);

    //    Caculate_Robot2_V_with_Robot1(2,V_qF,V_qL,qL1,qF1,tool1,tool2,V_end,t_offset);

    //    std::cout<<"V_qF:"<<V_qF<<std::endl;
    //    std::cout<<"V_qL"<<V_qL<<std::endl;
    mwArray qL1(1,6,mxDOUBLE_CLASS);
    mwArray qF1(1,6,mxDOUBLE_CLASS);
    mwArray tool1(1,3,mxDOUBLE_CLASS);
    mwArray tool2(1,3,mxDOUBLE_CLASS);
    mwArray V_end(6,1,mxDOUBLE_CLASS);
    mwArray t_offset(4,4,mxDOUBLE_CLASS);
    double axises_position[6] = {0};
    double vec_V_end[6] = {0,15,0,0,0,0};

    myrobots.Get_axises_position(1,axises_position);
    qL1.SetData(axises_position,6);
    myrobots.Get_axises_position(2,axises_position);
    qF1.SetData(axises_position,6);

    myrobots.Get_hand_transl(1,tool1);
    myrobots.Get_hand_transl(2,tool2);
    V_end.SetData(vec_V_end,6);

    std::vector<std::vector<double>> vec_tool1(4,std::vector<double>(4));
    std::vector<std::vector<double>> vec_tool2(4,std::vector<double>(4));
    myrobots.Get_hand_position(1,vec_tool1);
    myrobots.Get_hand_position(2,vec_tool2);
    Eigen::Matrix4d tool1_end;
    Eigen::Matrix4d tool2_end;
    Eigen::Matrix4d R1_2_R2;//机械臂基坐标的相对位姿矩阵
    R1_2_R2<<0,-1,0,821.743187414267,
             1,0,0,-649.716451921158,
             0,0,1,361.403566579465,
             0,0,0,1;
    for(int i=0 ;i<4 ; i++)
    {
        for(int j=0 ;j<4 ;j++)
        {
            tool1_end(i,j) = vec_tool1[i][j];
            tool2_end(i,j) = vec_tool2[i][j];
        }
    }

    //计算T_offset,即夹具末端的相对位姿
    Eigen::Matrix4d T_offset = tool1_end.inverse()*R1_2_R2*tool2_end;

    for(int i=0 ;i<4 ; i++)
    {
        for(int j=0 ;j<4 ;j++)
        {
            t_offset(i+1,j+1) = T_offset(i,j);
        }
    }

    //计算主臂和从臂各个关节角速度
    //持续计算，等导出所有数据后再向机械臂传输，共计100个速度点，每个速度点持续100ms
    std::vector<std::vector<double>> vec_V_qF(6,std::vector<double>(20));//记录从臂的速度曲线
    std::vector<std::vector<double>> vec_V_qL(6,std::vector<double>(20));
    mwArray V_qF(6,1,mxDOUBLE_CLASS),V_qL(6,1,mxDOUBLE_CLASS),V_qFs(6,1,mxDOUBLE_CLASS),V_qLs(6,1,mxDOUBLE_CLASS);

    mwArray single_time(1,1,mxDOUBLE_CLASS);
    mwArray step_nums(1,1,mxDOUBLE_CLASS);
    single_time(1,1) = 500;//单步持续时间0.1s
    step_nums(1,1) = 20;//步长100

    Caculate_Robot2_V_with_Robot1_continue(2,V_qFs,V_qLs,qL1,qF1,tool1,tool2,V_end,t_offset,single_time,step_nums);
    std::cout<<"V_qFs:"<<std::endl;
    std::cout<<V_qFs<<std::endl;

    std::cout<<"V_qLs:"<<std::endl;
    std::cout<<V_qLs<<std::endl;
    for(int i=0 ;i<6;i++)
    {
        for(int j=0 ;j<20;j++)
        {
            vec_V_qF[i][j] = V_qFs(i+1,j+1);
            vec_V_qL[i][j] = V_qLs(i+1,j+1);
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    myrobots.Robot_kine_v(1,vec_V_qL,500);
    auto end = std::chrono::high_resolution_clock::now();

    // 计算时间差
    std::chrono::duration<double, std::milli> duration = end - start; // 以毫秒为单位

    // 输出结果
    std::cout << "Execution Time: " << duration.count() << " ms" << std::endl;

    //myrobots.Robot_kine_v(2,vec_V_qF,100);


//    for(int i=0 ;i<100; i++)
//    {
//        Caculate_Robot2_V_with_Robot1_2(2,V_qF,V_qL,qL1,qF1,tool1,tool2,V_end,t_offset);

//        //向容器填充数据
//        vec_V_qF[0][i] = V_qF(1,1);        vec_V_qL[0][i] = V_qL(1,1);
//        vec_V_qF[1][i] = V_qF(2,1);        vec_V_qL[1][i] = V_qL(2,1);
//        vec_V_qF[2][i] = V_qF(3,1);        vec_V_qL[2][i] = V_qL(3,1);
//        vec_V_qF[3][i] = V_qF(4,1);        vec_V_qL[3][i] = V_qL(4,1);
//        vec_V_qF[4][i] = V_qF(5,1);        vec_V_qL[4][i] = V_qL(5,1);
//        vec_V_qF[5][i] = V_qF(6,1);        vec_V_qL[5][i] = V_qL(6,1);

//        //更新参数
//        qL1(1,1) = double(qL1(1,1)) + 0.1*double(V_qL(1,1));
//        qL1(1,2) = double(qL1(1,2)) + 0.1*double(V_qL(2,1));
//        qL1(1,3) = double(qL1(1,3)) + 0.1*double(V_qL(3,1));
//        qL1(1,4) = double(qL1(1,4)) + 0.1*double(V_qL(4,1));
//        qL1(1,5) = double(qL1(1,5)) + 0.1*double(V_qL(5,1));
//        qL1(1,6) = double(qL1(1,6)) + 0.1*double(V_qL(6,1));

//        qF1(1,1) = double(qF1(1,1)) + 0.1*double(V_qF(1,1));
//        qF1(1,2) = double(qF1(1,2)) + 0.1*double(V_qF(2,1));
//        qF1(1,3) = double(qF1(1,3)) + 0.1*double(V_qF(3,1));
//        qF1(1,4) = double(qF1(1,4)) + 0.1*double(V_qF(4,1));
//        qF1(1,5) = double(qF1(1,5)) + 0.1*double(V_qF(5,1));
//        qF1(1,6) = double(qF1(1,6)) + 0.1*double(V_qF(6,1));
//    }

//    std::cout<<"vec_V_qF:"<<std::endl;
//    for(int i=0;i<6;i++)
//    {
//        for(int j=0 ;j<100 ;j++)
//        {
//            std::cout<<vec_V_qF[i][j]<<" ";
//        }
//        std::cout<<std::endl;
//    }

    return;
}

void MainWindow::on_pushButton_43_clicked()//测试速度曲线控制
{
    std::vector<std::vector<double>> vec_v_nums(6,std::vector<double>(2));
    for(int i=0 ;i<6; i++)
    {
        vec_v_nums[i][0] = 10000;
        vec_v_nums[i][1] = -10000;
    }
    myrobots.Robot_kine_v(1,vec_v_nums,1000);

}


void MainWindow::on_pushButton_44_clicked()//自动化步骤1，移动分光器
{
    //移动机械臂2到指定位置，此时机械臂2夹具应该夹取了分光器
    //定义目标位置,mwArray填充是列优先！！！
    mwArray target_position_2(4,4,mxDOUBLE_CLASS);
    double target_position_org_2[16] ={-0.6048,0.7964,0,0,
                                       0.7964,0.6048,0,0,
                                       0,0,-1,0,
                                       617,-19,-101,1};
    target_position_2.SetData(target_position_org_2,16);

    myrobots.Robot_ikine(2,target_position_2,5);
    Sleep(5000);
    //定义机械臂1的指定位置，机械臂1并不夹取分光器，而是等待2移动完毕后运动到指定位置
    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.5693,-0.8221,0,0,
                                       -0.8221,-0.5693,0,0,
                                       0,0,-1,0,
                                       525,-27,465,1};
    target_position_1.SetData(target_position_org_1,16);

    myrobots.Robot_ikine(1,target_position_1,4);

}

void MainWindow::on_pushButton_51_clicked()//自动化步骤2，机械臂2夹取分光器运动到指定位置上方，机械臂1配合夹取
{
    mwArray target_position_2(4,4,mxDOUBLE_CLASS);
    double target_position_org_2[16] ={-0.6471,0.8842,0,0,
                                        0.8842,0.4671,0,0,
                                        0,0,-1,0,
                                        500,150,-80,1};
    target_position_2.SetData(target_position_org_2,16);
    myrobots.Robot_ikine(2,target_position_2,5);

    //机械臂1运动到指定位置
    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.5693,-0.8221,0,0,
                                        -0.8221,-0.5693,0,0,
                                        0,0,-1,0,
                                        525,-27,375,1};
    target_position_1.SetData(target_position_org_1,16);
    myrobots.Robot_ikine(1,target_position_1,5);
}

void MainWindow::on_pushButton_45_clicked()//3 下压分光器
{
    //定义两机械臂的目标位置，同时驱动
    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.5693,-0.8221,0,0,
                                        -0.8221,-0.5693,0,0,
                                        0,0,-1,0,
                                        525,-27,357,1};
    target_position_1.SetData(target_position_org_1,16);

    mwArray target_position_2(4,4,mxDOUBLE_CLASS);
    double target_position_org_2[16] ={-0.6471,0.8842,0,0,
                                        0.8842,0.4671,0,0,
                                        0,0,-1,0,
                                        500,150,-102,1};
    target_position_2.SetData(target_position_org_2,16);

    myrobots.Robot_ikine(1,target_position_1,6);
    myrobots.Robot_ikine(2,target_position_2,6);
}

void MainWindow::on_pushButton_46_clicked()//4 机械臂1找初始线，机械臂2移动到预夹取位置
{
    //机械臂1先上去
    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.5693,-0.8221,0,0,
                                        -0.8221,-0.5693,0,0,
                                        0,0,-1,0,
                                        525,-27,375,1};
    target_position_1.SetData(target_position_org_1,16);
    myrobots.Robot_ikine(1,target_position_1,3);
    Sleep(3000);
    //机械臂1再下来夹线
    double target_position_org_1_2[16] ={0.5693,-0.8221,0,0,
                                        -0.8221,-0.5693,0,0,
                                        0,0,-1,0,
                                        515,-33,360,1};
    target_position_1.SetData(target_position_org_1_2,16);
    myrobots.Robot_ikine(1,target_position_1,3);

    //机械臂2移动到指定位置
    mwArray target_position_2(4,4,mxDOUBLE_CLASS);
    double target_position_org_2[16] ={-0.6471,0.8842,0,0,
                                        0.8842,0.4671,0,0,
                                        0,0,-1,0,
                                        500,150,-80,1};
    target_position_2.SetData(target_position_org_2,16);

    myrobots.Robot_ikine(2,target_position_2,5);
    return;
}

void MainWindow::on_pushButton_47_clicked()//自动化步骤5，机械臂1和机械臂2运动到合适位置，等待自动化找线
{
//    std::thread temp_thread([this](){
//        Operat_tool(260,2);//打开夹钳
//        //调整绕z轴旋转角度
//        bool ret = Adjust_theta_z();
//        if(!ret){
//            std::cout<<"调整theta_z失败"<<std::endl;
//                return;
//        }
//        Sleep(5000);
//        //调整y，z距离
//        ret = Adjust_delt_z_y();
//        if(!ret){
//            std::cout<<"调整distance_z_y失败"<<std::endl;
//                return ;
//        }
//        Sleep(5000);
//        //再调整一遍z
//        ret = Adjust_theta_z();
//        if(!ret){
//            std::cout<<"调整theta_z失败"<<std::endl;
//                return;
//        }
//        Sleep(5000);
//        //计算绕Y轴旋转的角度
//        ret = Adjust_theta_y();
//        if(!ret){
//            std::cout<<"调整theta_y失败"<<std::endl;
//                return ;
//        }
//        Sleep(5000);
//        ret = Adjust_theta_z();
//        if(!ret){
//            std::cout<<"调整theta_z失败"<<std::endl;
//                return;
//        }
//        Sleep(5000);
//        mwArray R_tool_mw(4,4,mxDOUBLE_CLASS);
//        myrobots.Get_hand_position(2,R_tool_mw);
//        double a12 = R_tool_mw(1,2);
//        double a13 = R_tool_mw(1,3);
//        double a22 = R_tool_mw(2,2);
//        double a23 = R_tool_mw(2,3);
//        double a32 = R_tool_mw(3,2);
//        double a33 = R_tool_mw(3,3);
//        double org_x = R_tool_mw(1,4);//x的原值
//        double org_y = R_tool_mw(2,4);//y的原值
//        double org_z = R_tool_mw(3,4);//z的原值
//        std::cout<<"R_tool_mw(3,4)为"<<R_tool_mw(3,4)<<std::endl;
//            //std::cout<<"需要向下移动："<<(Myminicamera.Show_z()-10.5)<<std::endl;
//            double z=15.0,y=-9.0;
//        //        ret = Myminicamera.Calculation_distance_z_y(z,y);
//        //        if(!ret){
//        //            return ;
//        //        }
//        //特别注意这里的位置变换的参考坐标系！！！！！
//        R_tool_mw(1,4) = a12*y+a13*z+org_x;
//        R_tool_mw(2,4) = a22*y+a23*z+org_y;
//        R_tool_mw(3,4) = a32*y+a33*z+org_z;
//        std::cout<<"Now the namber of R_tool_mw is: "<<std::endl;
//        std::cout<<R_tool_mw<<std::endl;
//        Sleep(1000);
//        //Myrobot.Robot_motion_ikine(2,R_tool_mw);//末端夹具校正位姿
//        myrobots.Robot_ikine(2,R_tool_mw,5);
//        Sleep(5000);
//        Operat_tool(368,2);//关闭夹钳
//        Sleep(2000);
//        return ;
//    });


//    temp_thread.detach();//分离线程

//    return;

    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.5693,-0.8221,0,0,
                                        -0.8221,-0.5693,0,0,
                                        0,0,-1,0,
                                        500,-40,370,1};
    target_position_1.SetData(target_position_org_1,16);
    myrobots.Robot_ikine(1,target_position_1,3);
    Sleep(3000);

    double target_position_org_1_2[16] ={0.5693,-0.8221,0,0,
                                        -0.8221,-0.5693,0,0,
                                        0,0,-1,0,
                                        400,-100,370,1};
    target_position_1.SetData(target_position_org_1_2,16);
    myrobots.Robot_ikine(1,target_position_1,5);

    mwArray target_position_2(4,4,mxDOUBLE_CLASS);
    double target_position_org_2[16] ={-0.5331,0.8461,0,0,
                                        0.8461,0.5331,0,0,
                                        0,0,-1,0,
                                        430,280,-75,1};
    target_position_2.SetData(target_position_org_2,16);

    myrobots.Robot_ikine(2,target_position_2,5);

}


void MainWindow::on_pushButton_48_clicked()//自动化步骤6，两臂加持光纤移动到指定位置,限位槽上方
{
    //定义两个机械臂目标位置
    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.3070,-0.9517,0,0,
                                       -0.9517,-0.3070,0,0,
                                       0,0,-1,0,
                                       512,-18,375,1};
    target_position_1.SetData(target_position_org_1,16);

    mwArray target_position_2(4,4,mxDOUBLE_CLASS);
    double target_position_org_2[16] ={-0.5331,0.8461,0,0,
                                       0.8461,0.5331,0,0,
                                       0,0,-1,0,
                                       464,234,-85,1};
    target_position_2.SetData(target_position_org_2,16);

    //机械臂移动
    myrobots.Robot_ikine(1,target_position_1,5);
    myrobots.Robot_ikine(2,target_position_2,4);

    return ;
}


void MainWindow::on_pushButton_50_clicked()//自动化步骤7，插入光纤
{
    //定义两个机械臂目标位置
    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.3070,-0.9517,0,0,
                                        -0.9517,-0.3070,0,0,
                                        0,0,-1,0,
                                        512,-18,355,1};
    target_position_1.SetData(target_position_org_1,16);

    mwArray target_position_2(4,4,mxDOUBLE_CLASS);
    double target_position_org_2[16] ={-0.5331,0.8461,0,0,
                                        0.8461,0.5331,0,0,
                                        0,0,-1,0,
                                        464,234,-105,1};
    target_position_2.SetData(target_position_org_2,16);

    //机械臂移动
    myrobots.Robot_ikine(1,target_position_1,4);
    myrobots.Robot_ikine(2,target_position_2,4);

    return ;
}


void MainWindow::on_pushButton_58_clicked()//8
{
    mwArray target_position_1(4,4,mxDOUBLE_CLASS);
    double target_position_org_1[16] ={0.3070,-0.9517,0,0,
                                        -0.9517,-0.3070,0,0,
                                        0,0,-1,0,
                                        512,-8,370,1};
    target_position_1.SetData(target_position_org_1,16);

    myrobots.Robot_ikine(1,target_position_1,4);

//    double target_position_org_1_2[16] ={0.3070,-0.9517,0,0,
//                                        -0.9517,-0.3070,0,0,
//                                        0,0,-1,0,
//                                        512,-8,370,1};
    return;
}


void MainWindow::on_pushButton_52_clicked()//夹钳1打开
{
    Operat_tool(260,1);//380-260对应关闭-打开,最小步进12
    return;
}


void MainWindow::on_pushButton_53_clicked()//夹钳1半闭合
{
    Operat_tool(308,1);
    return;
}


void MainWindow::on_pushButton_54_clicked()//夹钳1闭合
{
    Operat_tool(368,1);
    return ;
}


void MainWindow::on_pushButton_55_clicked()//夹钳2打开
{
    Operat_tool(260,2);//380-260对应关闭-打开,最小步进12
    return;
}


void MainWindow::on_pushButton_57_clicked()//夹钳2半闭合
{
    Operat_tool(308,2);
    return;
}


void MainWindow::on_pushButton_56_clicked()//夹钳2闭合
{
    Operat_tool(368,2);
    return ;
}

void MainWindow::onQuestRobotCommandReceived(int robotIndex,
                                             double x, double y, double z,
                                             double qx, double qy, double qz, double qw,
                                             qint64 timestamp)
{
    if (timestamp <= lastQuestCommandTimestamp)
    {
        return;
    }
    lastQuestCommandTimestamp = timestamp;

    // 防止高频请求直接灌入控制卡（桥接20Hz时这里约12.5Hz执行）。
    static qint64 lastAppliedTs = 0;
    if (timestamp - lastAppliedTs < 80)
    {
        return;
    }
    lastAppliedTs = timestamp;

    if (!myrobots.Get_switch_status())
    {
        qDebug() << "[QuestRobotBridge] robot power is off, command ignored.";
        return;
    }

    if (robotIndex != 1 && robotIndex != 2)
    {
        robotIndex = 1;
    }

    double norm = std::sqrt(qx*qx + qy*qy + qz*qz + qw*qw);
    if (norm < 1e-8)
    {
        qDebug() << "[QuestRobotBridge] invalid quaternion, command ignored.";
        return;
    }

    qx /= norm;
    qy /= norm;
    qz /= norm;
    qw /= norm;

    // Quaternion -> rotation matrix.
    const double r11 = 1.0 - 2.0 * (qy*qy + qz*qz);
    const double r12 = 2.0 * (qx*qy - qz*qw);
    const double r13 = 2.0 * (qx*qz + qy*qw);
    const double r21 = 2.0 * (qx*qy + qz*qw);
    const double r22 = 1.0 - 2.0 * (qx*qx + qz*qz);
    const double r23 = 2.0 * (qy*qz - qx*qw);
    const double r31 = 2.0 * (qx*qz - qy*qw);
    const double r32 = 2.0 * (qy*qz + qx*qw);
    const double r33 = 1.0 - 2.0 * (qx*qx + qy*qy);

    // 和现有代码风格一致，直接构造4x4位姿矩阵给 MATLAB IK DLL。
    mwArray targetPose(4,4,mxDOUBLE_CLASS);
    double targetPoseData[16] =
    {
        r11, r12, r13, 0.0,
        r21, r22, r23, 0.0,
        r31, r32, r33, 0.0,
        x,   y,   z,   1.0
    };
    targetPose.SetData(targetPoseData, 16);

    // time参数给一个保守值（秒），避免突然大幅动作。
    myrobots.Robot_ikine(robotIndex, targetPose, 0.25);

    qDebug() << "[QuestRobotBridge] cmd ts=" << timestamp
             << "robot=" << robotIndex
             << "pose(mm)=(" << x << y << z << ")";
}
