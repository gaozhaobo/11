#ifndef ROBOT_FUNCTION_H
#define ROBOT_FUNCTION_H

#include "APS168.h"
#include"APS_Define.h"
#include"ErrorCodeDef.h"
#include<QString>
#include"Robot_kine.h"
//以下是初始化轴时，需要用到的一些定义（移植过来的，懒得改）。
/*************************这一段区域为一些宏定义和对轴初始化时状态的记录******************************/
#define _NOT_INITIAL  (0)              //
#define _INITIALED    (1)              //
                                       //
#define _NOT_START_FIELD_BUS  (0)      //
#define _START_FIELD_BUS    (1)        //
             //
/*************************这一段区域为一些宏定义和对轴初始化时状态的记录******************************/


extern int Axis_num;

class AXIS_STATUS//定义一个类记录轴的信息
{
public:
    I32 encoder_position;
    F64 command_position;
    F64 feedback_position;//计算时，用没计算零点偏移值-零点偏移值
    F64 target_position;
    F64 error_position;
    F64 command_velocity;
    F64 feedback_velocity;
    F64 origin_position;//零点偏移量
    F64 feedback_origin_position;//没有计算零点偏移的反馈值
    //I32 motion_io;
    //I32 motion_status;//没啥用的注释掉
};

void Massage(QString str);

void Get_axis_status(I32 Axis_ID, AXIS_STATUS *P_Axis_status);//获取轴的状态，包括位置信息，速度信息等
/*参数1：轴的ID编号，参数二：轴状态类地址*/

void Initial_axis();//初始化伺服驱动器
void offline_axis();//关闭凌华板子
void Serv_on();//打开全部伺服电机

void Serv_off();//关闭全部伺服电机

void Axis_start_motion(I32 Axis_ID, F64 Position, F64 Vs, F64 Vm,
                       F64 Ve, F64 Acc, F64 Dec, F64 Sfac=0,I32 Option = 0);//单轴运动
/*1:轴ID，2：目标位置，3：开始速度，4：最大速度，5：结束速度，6：加速度，7：减速度，8：速度曲线，默认为T型曲线，9：设置模式，默认为绝对运动*/

void Axis_start_motion(I32 Axis_ID,F64 Position);//简易单轴运动,以默认设置进行单轴运动

void Axis_stop_motion(I32 Axis_ID);//停止单轴运动

void Axis_get_info(I32 Axis_ID,AXIS_STATUS *axis_info);//获取轴的信息,反馈位置，速度，命令位置等


class Axis
{
public:
    Axis();
    Axis(I32 index ,double nums_p2r,double offset);//设置数字信号到轴旋转角度的映射，必须设置！！！
    I32 Axis_ID;
    double position_to_rad;
    AXIS_STATUS Axis_info;

    void Set_Paraments(I32 index,double nums_p2r,double offset);//设置轴的参数包括索引和角度映射零点偏移量等

    void Axis_start_motion(F64 Position);
    void Axis_start_motion(F64 Position, F64 Vs, F64 Vm,
                           F64 Ve, F64 Acc, F64 Dec, F64 Sfac=0,I32 Option = 0);//单轴运动
    void Axis_start_motion(F64 Position,F64 Vm, F64 Sfac=1,I32 Option=0);//单轴运动，粗略控制速度和加速度
    void Axis_get_info();
    void Axis_stop_motion();
    void Axis_start_motion_v(F64 V,I32 option);//以速度V持续运动,参数二指定运动方向。0：正向，1：反向
    void Axis_start_motion_S(F64 Position,F64 Vm, F64 Sfac=0.5,I32 Option=0);
    void Axis_turn_on();//开启一个轴
    void Axis_turn_off();//关闭一个轴
};


//class Robot_Function
//{
//public:
//    Robot_Function();

//    Axis Axis_Group[12];//创建12个轴的数组
//    //I32 Axis_ID[12] = {0,1,2,3,4,5,6,7,8,9,10,11};//十二个轴的编号为0到11
//    //AXIS_STATUS Axis_info[12];//一共十二个轴,记录其状态
//    double tool_transl_1[3] = {0.0,0.0,90.0};//夹具坐标相对于末端偏移量{205,0,130}
//    double tool_transl_2[3] = {0.0,195.0,210.0};//{0,195,140}

//    mwArray mwTool(int Robot_index);//将机器人坐标系转换成mwArray类型
//    mwArray Get_hand_position(int robot_index);//获取夹具的世界坐标系

//    void Robot_get_info();//获取全部轴的全部信息

//    void Robot_stop();//所有轴停止运动

//    void Robot_servo_on();//打开所有伺服电机

//    void Robot_servo_off();//关闭所有伺服电机

//    void Robot_motion_ikine(int Robot_index,const mwArray &T);//机械臂运动到T位姿处,参数一为机械臂索引，从1开始

//    void Robot_motion_ikine_t(int Robot_index,const mwArray &T , double time);//机械臂逆解，指定时间

//};

class C_Robot_Arm//定义一个机械臂
{
public:
    C_Robot_Arm()=delete;
    C_Robot_Arm(int index,//机器人编号索引,从1开始
                I32 nums[6],//轴编号
                double p2r[6] ,//每个轴数字对应角度映射比例
                double offset[6],//每个轴零点偏移量
                std::vector<double> tool= {0,0,0}//机械臂的末端工具坐标偏移
                );//为该机械臂分配6个轴

    void Robot_get_info();//获取全部轴的全部信息

    void Robot_stop();//所有轴停止运动

    void Robot_servo_on();//打开所有伺服电机

    void Robot_servo_off();//关闭所有伺服电机

    void Robot_motion_kine(const double qn_from_ui[6],double time);//正运动学解算,输入指定角度，驱动机械臂各个关节运动到该位置,用时time秒

    void Robot_motion_ikine(const mwArray &T , double time);//机械臂运动到T位姿处,用时time秒

    bool Get_tool_trans(std::vector<double> &robot_tool_transl);//参数返回机器人工具坐标偏移

    mwArray Get_hand_position();//获取夹具的世界坐标系

    bool Get_encoder_position(std::vector<double> &nums);//参数返回6个轴的编码器位置

    bool Get_angle_position(std::vector<double> &nums);//参数返回6个轴角度信息

    bool Single_axis_motion(int index , double speed);//单个关节运动,注意这里速度的单位是国际单位，不再是凌华板卡的单位
    bool Single_axis_motion(int index , double speed , int direction);//单个关节运动,参数3为方向：0正向，1反向，注意，这里的单位是凌华板卡的单位

    bool Single_axis_stop_motion(int axis_index);


private:
    bool is_turn_on;//上电标志位

    int Robot_index;//机械臂编号

    Axis Axis_Group[6];//6轴机械臂,拥有6个轴

    double tool_transl[3];//定义工具坐标相对于机械臂末端偏移量（一般没有旋转，故只有平移）
};


class C_Dual_arm_robots //定义一个双臂机器人 类
{
public:
    C_Dual_arm_robots() = delete;
    C_Dual_arm_robots(int index_1,//机器人编号索引,从1开始
                      I32 nums_1[6],//轴编号
                      double p2r_1[6] ,//每个轴数字对应角度映射比例
                      double offset_1[6],//每个轴零点偏移量
                      std::vector<double> tool_1,
                      int index_2, I32 nums_2[6] , double p2r_2[6] , double offset_2[6] , std::vector<double> tool_2);


    bool Turn_on();//打开电源
    bool Turn_off();//关闭电源
    bool Get_info();//获取各个机械臂信息
    bool Emergency_stop();//紧急停止
    bool Robot_kine(int index , const double qn_from_ui[6],double time);//正运动学
    bool Robot_ikine(int index ,const mwArray &T , double time);//逆运动学解
    bool Get_encoder_position(int index,std::vector<double> &nums);//编码器读值,参数1：机械臂标识，参数2：返回该机械臂各个轴编码器的值

    bool Get_switch_status();//获取开关状态

    bool Get_hand_position(int index ,mwArray &tool_status);//获取工具坐标系末端姿态,参数1：机械臂索引（1,2），参数2：输出位姿
    bool Get_hand_position(int index ,std::vector<std::vector<double>> &tool_status);//获取工具坐标系末端姿态,参数1：机械臂索引（1,2），参数2：输出位姿

    bool Get_hand_transl(int index ,mwArray &robot_tool_transl);//获取末端坐标系偏移量

    bool Get_axises_position(int Robot_index , double axises_position[6]);//获取机械臂各个关节的角度

    bool Single_axis_motion(int robot_index , int axis_index , double speed , int direction = 0);
       //参数1：机械臂索引 ， 参数2：轴索引 ， 参数3：速度 ， 参数4：速度方向（0正向，1反向）
    bool Single_axis_stop_motion(int robot_index , int axis_index);//单轴停止运动

    bool Robot_kine_v(int Robot_index,std::vector<std::vector<double>> &speed_nums , int continue_time);
    //根据各个关节的速度曲线实现机械臂正运动学
    //参数1：机械臂索引 ； 参数2：一般为6行N列矩阵，记录各个关节的速度 ； 参数3：每个关节节点速度的持续时间(单位：ms)
    //注意：这里的速度单位为国际单位，不是凌华板卡的单位

private:
    bool is_turn_on;//电源开关
    C_Robot_Arm Robot_1;
    C_Robot_Arm Robot_2;


};


#endif // ROBOT_FUNCTION_H
