#include "robot_function.h"
#include <iostream>
#include<qlabel.h>


int Axis_num = 12;

int _is_card_initialed = _NOT_INITIAL;                //0:未初始化，1:初始化
long _card_id;                         //
long _test_axis_id;                    //
long _first_axis_id;                   //
long _card_name;                       //
long _total_axis;                      //板卡最多能容下的轴数
long _is_FieldBus_Start = _NOT_START_FIELD_BUS;
int Num_of_Axis = 0;//定义目前的轴数
void Massage(QString str)//弹窗显示信息
{
    QLabel *label = new QLabel;
    label->setFixedSize(400,50);
    label->setAlignment(Qt::AlignCenter);
    label->setWindowFlags(Qt::WindowStaysOnTopHint);//设置弹窗在最顶层
    label->setText(str);
    label->show();

}

void Initial_axis()
{
    if(_is_card_initialed == _NOT_INITIAL)
    {
        long boardID_InBits = 0;
        long mode           = INIT_AUTO_CARD_ID;
        int ret = 0;
        long board_ID       = -1;
        long i;
        long card_name;

        ret = APS_initial( &boardID_InBits, mode );

        if( ret == ERR_NoError )
        {
            for( i = 0; i < 16; i++ )
            {
                if( ( boardID_InBits >> i ) & 1 )
                {
                    APS_get_card_name( i, &card_name );

                    if((card_name == DEVICE_NAME_PCIE_8332)||(card_name == DEVICE_NAME_PCIE_8338))
                    {
                        _card_name = card_name;
                        board_ID = i;
                        break;
                    }
                }
            }
        }

        if( board_ID == -1 )
        {
            QLabel *label = new QLabel;
            label->setText("BoardID search error !");
            label->show();
            std::cout<<"BoardID search error !"<<std::endl;

            return;
        }

        _is_card_initialed = _INITIALED;
        _card_id           = board_ID;

        long total_axes;
        APS_get_first_axisId( board_ID, &_first_axis_id, &total_axes );
        _test_axis_id = _first_axis_id;
        _total_axis   = total_axes;
    }else{
        std::cout<<"_is_card_initialed is invalid"<<std::endl;
    }

    if(_is_FieldBus_Start==_NOT_START_FIELD_BUS){
        I32 RET = APS_start_field_bus(_card_id,0,0);
        if(RET == 0){
            std::cout<<"Field Bus Start ok !"<<std::endl;
            _is_FieldBus_Start=_START_FIELD_BUS;
        }else{
            std::cout<<"Field Bus Start failed !"<<std::endl;
        }
    }

    return;
}

void offline_axis()
{
    if(_is_card_initialed == _NOT_INITIAL)
    {
        std::cout<<"Card has not be initialed !"<<std::endl;
        return ;
    }

    bool ret = APS_stop_field_bus(_card_id,0);
    if(!ret){
        std::cout<<"Field Bus Stop ok !"<<std::endl;
        _is_FieldBus_Start = _NOT_START_FIELD_BUS;
    }else{
        std::cout<<"Field Bus Stop error !"<<std::endl;
    }

//    ret = APS_close();
//    if(!ret){
//        std::cout<<"The device is successfully shut down"<<std::endl;
//    }else{
//        std::cout<<"The device is unsuccessfully shut down"<<std::endl;
//    }

    return;
}

void Get_axis_status(I32 Axis_ID, AXIS_STATUS *P_Axis_status)//获取指定轴的信息
{

    APS_get_position_f(Axis_ID,&P_Axis_status->feedback_position);//获取轴的编码器位置信息
    APS_get_command_f(Axis_ID,&P_Axis_status->command_position);//获取轴的命令位置信息
    APS_get_target_position_f(   Axis_ID, &P_Axis_status->target_position );//获取目标位置，和上一个意义相同
    APS_get_error_position_f(    Axis_ID, &P_Axis_status->error_position  );//获取误差，为命令位置减去反馈位置
    APS_get_command_velocity_f(  Axis_ID, &P_Axis_status->command_velocity);//获取命令速度
    APS_get_feedback_velocity_f( Axis_ID, &P_Axis_status->feedback_velocity );//获取反馈速度

}


void Serv_on()//打开全部伺服电机电源
{
    if( _is_card_initialed == _NOT_INITIAL )
    {
        Massage("Card has not be initialed.");
        return;
    }
    I32 startingAxisId = 0; //Startin axis ID of the filed bus.
    I32 BUS_No = 0;
    I32 ret;
    ret = APS_start_field_bus( _card_id, BUS_No, startingAxisId );
    if(ret == 0)
    {
        //Massage("Field Bus Start ok !");
        I32 axis_id = startingAxisId;

        for (int i=0; i < Axis_num ; i++)
        {
            if (!((APS_motion_io_status(axis_id+i) >> MIO_SVON) & 1))
            {
                APS_set_servo_on(axis_id+i, 1);

                std::cout<<"轴编号为："<<axis_id+i<<"已经打开"<<std::endl;
                Sleep(500); // Wait stable.
            }
        }
        for (int i = 0; i < 12; i++)
        {
            APS_set_position_f(axis_id + i, 0.0);//设置反馈位置为0
        }
    }
}

void Serv_off()//关闭所有伺服电机电源
{
    if( _is_card_initialed == _NOT_INITIAL )
    {
        Massage("Card has not be initialed !");
        return;
    }

    I32 BUS_No = 0;
    I32 ret;
    ret = APS_stop_field_bus( _card_id, BUS_No);
    if(ret == 0)
    {
        Massage("Field Bus Stop ok !");
        _is_FieldBus_Start = _NOT_START_FIELD_BUS;
        I32 axis_id = 0;

        for (int i = 0; i < Axis_num ; i++)
        {
            if ((APS_motion_io_status(axis_id + i) >> MIO_SVON) & 1)
            {
                APS_set_servo_on(axis_id + i, 0);
                std::cout<<"轴编号为："<<axis_id+i<<"已经关闭"<<std::endl;
                //printf("轴编号为：%d已经关闭\n", axis_id + i);//
                Sleep(500); // Wait stable.
            }
        }
    }
    else{
        Massage("error !");
        return;
    }
}

void Axis_start_motion(I32 Axis_ID, F64 Position, F64 Vs, F64 Vm,
                       F64 Ve, F64 Acc, F64 Dec, F64 Sfac,I32 Option)//点到点单轴运动，默认T形速度曲线
{
    APS_ptp_all(Axis_ID,Option,Position,Vs,Vm,Ve,Acc,Dec,Sfac,0);
}

void Axis_start_motion(I32 Axis_ID,F64 Position)
{
    APS_ptp(Axis_ID,OPT_ABSOLUTE,Position,0);//绝对运动到position处
}

void Axis_stop_motion(I32 Axis_ID)//停止单轴运动
{
    APS_stop_move(Axis_ID);
}

void Axis_get_info(I32 Axis_ID,AXIS_STATUS *axis_info)//获取对应轴的信息，保存在轴的状态类中
{
    APS_get_command_f(Axis_ID, &axis_info->command_position );
    APS_get_position_f(Axis_ID, &axis_info->feedback_position  );
    APS_get_target_position_f(Axis_ID, &axis_info->target_position );
    APS_get_error_position_f(Axis_ID, &axis_info->error_position  );
    APS_get_command_velocity_f(Axis_ID, &axis_info->command_velocity);
    APS_get_feedback_velocity_f(Axis_ID, &axis_info->feedback_velocity );
    //APS_get_encoder(Axis_ID, axis_info->encoder_position);
}

Axis::Axis()
{

}

Axis::Axis(I32 index ,double nums_p2r,double offset)
{
    Axis_ID = index;//分配轴编号
    position_to_rad = nums_p2r;//默认设置为0
    Axis_info.origin_position = (F64)offset;//设置0点偏移量
}

void Axis::Set_Paraments(I32 index ,double nums_p2r,double offset)
{
    Axis_ID = index;//分配轴编号
    position_to_rad = nums_p2r;//默认设置为0
    Axis_info.origin_position = (F64)offset;//设置0点偏移量

}

void Axis::Axis_start_motion(F64 Position)
{
    APS_ptp(Axis_ID,OPT_ABSOLUTE,Position+Axis_info.origin_position,0);//绝对运动到position处
}

void Axis::Axis_start_motion(F64 Position, F64 Vs, F64 Vm,
                             F64 Ve, F64 Acc, F64 Dec, F64 Sfac,I32 Option)//点到点单轴运动，默认T形速度曲线
/*1:轴ID，2：目标位置，3：开始速度，4：最大速度，5：结束速度，6：加速度，7：减速度，8：速度曲线，默认为T型曲线，9：设置模式，默认为绝对运动*/
{

    APS_ptp_all(Axis_ID,Option,Position+Axis_info.origin_position,Vs,Vm,Ve,Acc,Dec,Sfac,0);
}

void Axis::Axis_start_motion(F64 Position,F64 Vm, F64 Sfac,I32 Option)//点到点单轴运动，默认T形速度曲线
/*1:轴ID，2：目标位置，3：开始速度，4：最大速度，5：结束速度，6：加速度，7：减速度，8：速度曲线，默认为T型曲线，9：设置模式，默认为绝对运动*/
{
    F64 Vs = 0;//开始速度
    F64 Ve = 0;//结束速度
    F64 Acc = Vm;//加速度，为最大速度
    F64 Dec = Acc;//减速度与加速度相等
    APS_ptp_all(Axis_ID,Option,Position+Axis_info.origin_position,Vs,Vm,Ve,Acc,Dec,Sfac,0);
}

void Axis::Axis_get_info()//获取单轴信息
{
    //int ret=0;
    APS_get_command_f(Axis_ID, &Axis_info.command_position );
    APS_get_position_f(Axis_ID,&Axis_info.feedback_origin_position  );
    APS_get_target_position_f(Axis_ID, &Axis_info.target_position );
    APS_get_error_position_f(Axis_ID, &Axis_info.error_position  );
    APS_get_command_velocity_f(Axis_ID, &Axis_info.command_velocity);
    APS_get_feedback_velocity_f(Axis_ID, &Axis_info.feedback_velocity );
    Axis_info.feedback_position = Axis_info.feedback_origin_position-Axis_info.origin_position;
}

void Axis::Axis_stop_motion()
{
    APS_stop_move(Axis_ID);
}

void Axis::Axis_start_motion_v(F64 V,I32 option)//以速度V持续运动,参数二指定运动方向。0：正向，1：反向
{
    auto start = std::chrono::high_resolution_clock::now();
    APS_vel(Axis_ID,option,V,0);
    auto end = std::chrono::high_resolution_clock::now();

    // 计算时间差
    std::chrono::duration<double, std::milli> duration = end - start; // 以毫秒为单位

    // 输出结果
    std::cout << "Execution Time: " << duration.count() << " ms" << std::endl;
}

void Axis::Axis_start_motion_S(F64 Position,F64 Vm, F64 Sfac,I32 Option)
{
    F64 Vs = 0;//开始速度
    F64 Ve = 0;//结束速度
    F64 Acc = 10*Vm;//加速度，为最大速度的10倍
    F64 Dec = Acc;//减速度与加速度相等
    APS_ptp_all(Axis_ID,Option,Position+Axis_info.origin_position,Vs,Vm,Ve,Acc,Dec,Sfac,0);
}

void Axis::Axis_turn_on()
{
    if(!((APS_motion_io_status(Axis_ID) >> MIO_SVON) & 1)){
        APS_set_servo_on(Axis_ID, 1);
        //++Num_of_Axis;
        std::cout<<"There are "<<++Num_of_Axis<<" axises"<<std::endl;
    }else{
        //APS_set_servo_on(Axis_ID, 0);
        std::cout<<"Axis_ID"<<Axis_ID<<" : Error status"<<std::endl;
        //APS_set_servo_on(Axis_ID,1);
        ++Num_of_Axis;
    }
}

void Axis::Axis_turn_off()
{
    APS_set_servo_on(Axis_ID, 0);
    std::cout<<"There are "<<--Num_of_Axis<<" axises"<<std::endl;
//    if ((APS_motion_io_status(Axis_ID) >> MIO_SVON) & 1)
//    {
//        std::cout<<"turn off"<<std::endl;
//        APS_set_servo_on(Axis_ID, 0);
//        Num_of_Axis--;
//    }
}

//Robot_Function::Robot_Function()//构造函数，在此将轴参数ID初始化
//{
//    for(int i = 0 ; i<Axis_num ; i++)
//    {
//        Axis_Group[i].Axis_ID = i;
//    }
////    Axis_Group[0].position_to_rad = 0.03196/40000;
////    Axis_Group[1].position_to_rad = 0.03597/60000;
////    Axis_Group[2].position_to_rad = 0.03194/40000;//方向相反
////    Axis_Group[3].position_to_rad = 0.11977/100000;
////    Axis_Group[4].position_to_rad = 0.07309/60000;
////    Axis_Group[5].position_to_rad = 0.19174/100000;
//    Axis_Group[0].position_to_rad = 0.016/20000;
//    Axis_Group[1].position_to_rad = 0.024/40000;
//    Axis_Group[2].position_to_rad = 0.016/20000;//方向相反
//    Axis_Group[3].position_to_rad = 0.1198/100000;
//    Axis_Group[4].position_to_rad = 0.0239/20000;
//    Axis_Group[5].position_to_rad = 0.1917/100000;

//    Axis_Group[6].position_to_rad = 0.06/5000;
//    Axis_Group[7].position_to_rad = 0.06/5000;
//    Axis_Group[8].position_to_rad = 0.06/5000;
//    Axis_Group[9].position_to_rad = 0.06/5000;
//    Axis_Group[10].position_to_rad = 0.06/5000;
//    Axis_Group[11].position_to_rad = 0.06/5000;

//    //初始化零点偏移量
//    Axis_Group[0].Axis_info.origin_position = 0;
//    Axis_Group[1].Axis_info.origin_position = 0;
//    Axis_Group[2].Axis_info.origin_position = 0;
//    Axis_Group[3].Axis_info.origin_position = 0;
//    Axis_Group[4].Axis_info.origin_position = 0;
//    Axis_Group[5].Axis_info.origin_position = 0;
//    Axis_Group[6].Axis_info.origin_position = 111458;
//    Axis_Group[7].Axis_info.origin_position = 206375;
//    Axis_Group[8].Axis_info.origin_position = 214858;
//    Axis_Group[9].Axis_info.origin_position = 160000;
//    Axis_Group[10].Axis_info.origin_position = -100964;
//    Axis_Group[11].Axis_info.origin_position = 85206;


//}

//mwArray Robot_Function::mwTool(int index)//将机器人坐标系转换为mwArray类型
//{
//    switch(index)
//    {
//    case 1:
//        static mwArray *tool_trans_1 =new mwArray(1,3,mxDOUBLE_CLASS);
//        tool_trans_1->SetData(tool_transl_1,3);
//        return *tool_trans_1;
//        break;
//    case 2:
//        static mwArray *tool_trans_2 =new mwArray(1,3,mxDOUBLE_CLASS);
//        tool_trans_2->SetData(tool_transl_2,3);
//        return *tool_trans_2;
//        break;
//    default:
//        std::cout<<"The Robot Index Error!!!"<<std::endl;
//        std::cout<<"About to be converted to run as a default coordinates(0,0,0)"<<std::endl;
//        std::cerr<<"The Robot Index Error!!!"<<std::endl;
//        break;
//    }

//    mwArray defaulttool = mwArray(1,3,mxDOUBLE_CLASS);
//    for(int i = 0 ; i < 3 ;i++)
//    {
//        defaulttool(1,i+1) = 0.0;
//    }

//    return defaulttool;
//}

//mwArray Robot_Function::Get_hand_position(int robot_index)//获取夹具的坐标
//{
//    double axis_angle[6];
//    mwArray tool_status(4,4,mxDOUBLE_CLASS);
//    mwArray axis_angle_matlab(1,6,mxDOUBLE_CLASS);
//    //mwArray tool_trans_matlab(3,1,mxDOUBLE_CLASS);

//    switch (robot_index) {
//    case 1:
//        for(int i = 0 ; i < 6 ; i++)
//        {
//            axis_angle[i] = Axis_Group[i].Axis_info.feedback_position *
//                            Axis_Group[i].position_to_rad;
//        }
//        //tool_trans_matlab.SetData(tool_transl_1,3);
//        break;
//    case 2:
//        for(int i = 0 ; i < 6 ; i++)
//        {
//            axis_angle[i] = Axis_Group[i+6].Axis_info.feedback_position*
//                            Axis_Group[i+6].position_to_rad;
//        }
//        //tool_trans_matlab.SetData(tool_transl_2,3);
//        break;
//    default:
//        std::cout<<"The Robot Tool Index Error !!!"<<std::endl;
//        return mwArray();
//    }
//    axis_angle_matlab.SetData(axis_angle,6);
//    Robot_kine_Tool(1,tool_status,axis_angle_matlab,mwArray(robot_index),mwTool(robot_index));
//    //得到夹具在机器人坐标系下的姿态
//    //std::cout<<"The Robot Tool "<<robot_index<<" :"<<std::endl<<tool_status<<std::endl;
//    return tool_status;
//}

//void Robot_Function::Robot_get_info()
//{
//    for(int i=0 ; i<Axis_num; i++)
//    {
//        Axis_Group[i].Axis_get_info();
//        //Axis_get_info(Axis_ID[i],&Axis_info[i]);
//    }

//}

//void Robot_Function::Robot_stop()//所有轴停止运动
//{
//    for(int i = 0 ; i<Axis_num ; i++)
//    {
//        Axis_Group[i].Axis_stop_motion();
//        //APS_stop_move(i);
//    }
//}

//void Robot_Function::Robot_servo_on()//初始化所有伺服电机并且打开
//{
//    Initial_axis();
//    if( _is_card_initialed == _NOT_INITIAL )
//    {
//        Massage("Card has not be initialed.");
//        return;
//    }
//    I32 startingAxisId = 0; //Startin axis ID of the filed bus.
//    I32 BUS_No = 0;
//    I32 ret;
//    ret = APS_start_field_bus( _card_id, BUS_No, startingAxisId );
//    if(ret == 0)
//    {
//        //Massage("Field Bus Start ok !");
//        I32 axis_id = startingAxisId;

//        for (int i=0; i < Axis_num; i++)
//        {
//            if (!((APS_motion_io_status(axis_id+i) >> MIO_SVON) & 1))
//            {
//                APS_set_servo_on(axis_id+i, 1);

//                std::cout<<"轴编号为："<<axis_id+i<<"已经打开"<<std::endl;
//                Sleep(500); // Wait stable.
//            }
//        }
////        for (int i = 0; i < 12; i++)
////        {
////            APS_set_position_f(axis_id + i, 0.0);//设置反馈位置为0
////        }
//    }
//}

//void Robot_Function::Robot_servo_off()//关闭所有电机
//{
//    if( _is_card_initialed == _NOT_INITIAL )
//    {
//        Massage("Card has not be initialed !");
//        return;
//    }

//    I32 BUS_No = 0;
//    I32 ret;

//    I32 axis_id = 0;

//    for (int i = 0; i < Axis_num; i++)
//    {
//        if ((APS_motion_io_status(axis_id + i) >> MIO_SVON) & 1)
//        {
//            APS_set_servo_on(axis_id + i, 0);
//            std::cout<<"轴编号为："<<axis_id+i<<"已经关闭"<<std::endl;
//            //printf("轴编号为：%d已经关闭\n", axis_id + i);//
//            Sleep(500); // Wait stable.
//        }
//    }

//    ret = APS_stop_field_bus( _card_id, BUS_No);

//    if(ret == 0)
//    {
//        Massage("Field Bus Stop ok !");
//        _is_FieldBus_Start = _NOT_START_FIELD_BUS;
//        I32 axis_id = 0;

//        for (int i = 0; i < Axis_num; i++)
//        {
//            if ((APS_motion_io_status(axis_id + i) >> MIO_SVON) & 1)
//            {
//                APS_set_servo_on(axis_id + i, 0);
//                std::cout<<"轴编号为："<<axis_id+i<<"已经关闭"<<std::endl;
//                //printf("轴编号为：%d已经关闭\n", axis_id + i);//
//                Sleep(500); // Wait stable.
//            }
//        }
//    }
//    else{
//        Massage("error !");
//        return;
//    }
//}

//void Robot_Function::Robot_motion_ikine(int Robot_index,const mwArray &T)//机械臂运动到T位姿处
//{
//    mwArray q0(1,6,mxDOUBLE_CLASS);//初始位姿
//    mwArray qn(1,6,mxDOUBLE_CLASS);//运动角度
//    double Vm[6] = {0};

//    for(int i = 0+6*(Robot_index-1) ; i<6+6*(Robot_index-1) ; i++)
//    {
//        q0(1,i-6*(Robot_index-1)+1)=Axis_Group[i].Axis_info.feedback_position*Axis_Group[i].position_to_rad;
//    }
//    std::cout<<q0<<std::endl;
//    Robot_ikine_Tool(1,qn,T,q0,mwArray(Robot_index),mwTool(Robot_index));

//    for(int i = 0+6*(Robot_index-1) ; i<6+6*(Robot_index-1) ; i++)
//    {
//        qn(1,i-6*(Robot_index-1)+1) = int(double(qn(1,i-6*(Robot_index-1)+1))/Axis_Group[i].position_to_rad);
//    }

//    for(int i = 0 ; i <6 ; i++)
//    {
//        Vm[i] = (int(qn(1,i+1))-Axis_Group[i+6*(Robot_index-1)].Axis_info.feedback_position)/5;//6s走完该路程
//        if(Vm[i]<0.0)
//        {
//            Vm[i] = -1*Vm[i];
//        }
//    }

//    for(int i = 0+6*(Robot_index-1) ; i<6+6*(Robot_index-1) ; i++)//这个仅仅用于测试，注意速度控制，预计行程在3s左右走完
//    {
//        Axis_Group[i].Axis_start_motion(qn(1,i-6*(Robot_index-1)+1),Vm[i-6*(Robot_index-1)]);//这里速度要注意
//    }

//    return;
//}

//void Robot_Function::Robot_motion_ikine_t(int Robot_index,const mwArray &T , double time)
//{
//    mwArray q0(1,6,mxDOUBLE_CLASS);//初始位姿
//    mwArray qn(1,6,mxDOUBLE_CLASS);//运动角度
//    double Vm[6] = {0};

//    for(int i = 0+6*(Robot_index-1) ; i<6+6*(Robot_index-1) ; i++)
//    {
//        q0(1,i-6*(Robot_index-1)+1)=Axis_Group[i].Axis_info.feedback_position*Axis_Group[i].position_to_rad;
//    }
//    std::cout<<q0<<std::endl;
//    Robot_ikine_Tool(1,qn,T,q0,mwArray(Robot_index),mwTool(Robot_index));

//    for(int i = 0+6*(Robot_index-1) ; i<6+6*(Robot_index-1) ; i++)
//    {
//        qn(1,i-6*(Robot_index-1)+1) = int(double(qn(1,i-6*(Robot_index-1)+1))/Axis_Group[i].position_to_rad);
//    }

//    for(int i = 0 ; i <6 ; i++)
//    {
//        Vm[i] = (int(qn(1,i+1))-Axis_Group[i+6*(Robot_index-1)].Axis_info.feedback_position)/(time-1);//time s走完该路程
//        if(Vm[i]<0.0)
//        {
//            Vm[i] = -1*Vm[i];
//        }
//    }

//    for(int i = 0+6*(Robot_index-1) ; i<6+6*(Robot_index-1) ; i++)//这个仅仅用于测试，注意速度控制，预计行程在3s左右走完
//    {
//        Axis_Group[i].Axis_start_motion(qn(1,i-6*(Robot_index-1)+1),Vm[i-6*(Robot_index-1)]);//这里速度要注意
//    }

//    return;
//}

C_Robot_Arm::C_Robot_Arm(int index,I32 nums[6], double p2r[6] ,double offset[6], std::vector<double> tool)
{

    Robot_index = index;
    for(int i=0 ; i<6 ;i++)
    {
        Axis_Group[i].Set_Paraments(nums[i],p2r[i],offset[i]);
    }

    for(int i=0 ; i<3 ;i++)
    {
        tool_transl[i] = tool[i];
    }

    is_turn_on = false;

}

void C_Robot_Arm::Robot_get_info()
{
    for(int i=0 ; i<6; i++)
    {
        Axis_Group[i].Axis_get_info();
        //Axis_get_info(Axis_ID[i],&Axis_info[i]);
    }
}

void C_Robot_Arm::Robot_stop()
{
    for(int i = 0 ; i<6 ; i++)
    {
        Axis_Group[i].Axis_stop_motion();
        //APS_stop_move(i);
    }
}

void C_Robot_Arm::Robot_servo_on()
{
    if(is_turn_on==false)
    {
        for(int i=0 ; i<6 ;i++)
        {
            Axis_Group[i].Axis_turn_on();
            //Sleep(100);
        }
        is_turn_on = true;
    }else{
        return ;
    }

}

void C_Robot_Arm::Robot_servo_off()
{
    if(is_turn_on==true)
    {
        is_turn_on = false;
        for(int i=0 ; i<6 ;i++)
        {
            Axis_Group[i].Axis_turn_off();
            //Sleep(100);
        }

    }else{
        return ;
    }
}

void C_Robot_Arm::Robot_motion_ikine(const mwArray &T , double time)
{
    if(is_turn_on!=true){
        std::cout<<"Not Turn on!!!"<<std::endl;
        return;
    }
    mwArray q0(1,6,mxDOUBLE_CLASS);//初始位姿
    mwArray qn(1,6,mxDOUBLE_CLASS);//运动角度
    double Vm[6] = {0};

    for(int i = 0; i<6 ; i++)
    {
        q0(1,i+1)=Axis_Group[i].Axis_info.feedback_position*Axis_Group[i].position_to_rad;
    }
    std::cout<<q0<<std::endl;

    mwArray mwTool(1,3,mxDOUBLE_CLASS);
    mwTool.SetData(tool_transl,3);

    Robot_ikine_Tool(1,qn,T,q0,mwArray(Robot_index),mwTool);

    for(int i = 0 ; i<6; i++)
    {
        qn(1,i+1) = int(double(qn(1,i+1))/Axis_Group[i].position_to_rad);
    }

    for(int i = 0 ; i <6 ; i++)
    {
        Vm[i] = (int(qn(1,i+1))-Axis_Group[i].Axis_info.feedback_position)/(time-1);//time s走完该路程
        if(Vm[i]<0.0)
        {
            Vm[i] = -1*Vm[i];
        }
    }

    for(int i = 0 ; i<6 ; i++)//这个仅仅用于测试，注意速度控制，预计行程在time s左右走完
    {
        Axis_Group[i].Axis_start_motion(qn(1,i+1),Vm[i]);//这里速度要注意
    }
}

bool C_Robot_Arm::Get_tool_trans(std::vector<double> &robot_tool_transl)
{
    if(robot_tool_transl.size()!=3)
    {
        std::cout<<"The size of paraments is invalid!"<<std::endl;
        return false;
    }

    for(int i=0 ;i<3 ;i++)
    {
        robot_tool_transl[i] = tool_transl[i];
    }

    return true;
}

mwArray C_Robot_Arm:: Get_hand_position()
{
    double axis_angle[6];
    mwArray tool_status(4,4,mxDOUBLE_CLASS);
    mwArray axis_angle_matlab(1,6,mxDOUBLE_CLASS);
    mwArray mwTool(1,3,mxDOUBLE_CLASS);
    mwTool.SetData(tool_transl,3);
    //mwArray tool_trans_matlab(3,1,mxDOUBLE_CLASS);

    for(int i=0 ; i<6 ;i++)
    {
        axis_angle[i] = Axis_Group[i].Axis_info.feedback_position *
                        Axis_Group[i].position_to_rad;
    }

    axis_angle_matlab.SetData(axis_angle,6);
    Robot_kine_Tool(1,tool_status,axis_angle_matlab,mwArray(Robot_index),mwTool);
    return tool_status;
}

void C_Robot_Arm::Robot_motion_kine(const double qn_from_ui[6],double time)
{
    if(is_turn_on!=true){
        std::cout<<"Not Turn on!!!"<<std::endl;
        return;
    }
    double qn[6];
    double Vm[6]={0};
    for(int i = 0 ; i<6 ; i++)//控制2号机械臂的运动
    {
        std::cout<<i+6*(Robot_index-1)<<"弧度位置："<<qn_from_ui[i]<<std::endl;

        qn[i] = qn_from_ui[i]/Axis_Group[i].position_to_rad;
        Vm[i] = (qn[i]-Axis_Group[i].Axis_info.feedback_position)/(time-1);//Vm注意一下
        if(Vm[i]<0.0)
        {
            Vm[i] = -1*Vm[i];
        }
        std::cout<<i+(Robot_index-1)*6<<"position位置："<<qn[i]<<std::endl;
        std::cout<<i+(Robot_index-1)*6<<"速度为："<<Vm[i]<<std::endl;
    }


    for(int i = 0 ; i<6 ; i++)//这个仅仅用于测试，注意速度控制，预计行程在2s左右走完
    {
        Axis_Group[i].Axis_start_motion(qn[i],Vm[i]);//这里速度要注意
    }
    return;
}

bool C_Robot_Arm::Get_encoder_position(std::vector<double> &nums)
{
    if(!is_turn_on){
        return false;
    }
    if(nums.size()!=6){
        std::cout<<"The paraments is invalid,the nums' size must be 6 !!!"<<std::endl;
        return false;
    }
    for(int i=0 ; i<6 ; i++){
        nums[i] = Axis_Group[i].Axis_info.feedback_position;
    }

    return true;
}

bool C_Robot_Arm::Get_angle_position(std::vector<double>&nums)
{
    if(!is_turn_on){
        return false;
    }
    if(nums.size()!=6){
        std::cout<<"The paraments is invalid,the nums' size must be 6 !!!"<<std::endl;
        return false;
    }
    for(int i=0 ; i<6 ; i++){
        Axis_Group[i].Axis_get_info();//最好保证此时是刷新的
        nums[i] = Axis_Group[i].Axis_info.feedback_position*Axis_Group[i].position_to_rad;
    }
    return true;
}

bool C_Robot_Arm::Single_axis_motion(int axis_index ,double speed)
{
    if(axis_index>=6||axis_index<0){
        std::cout<<"The axis index error it can be 0~5 !"<<std::endl;
        return false;
    }
    if(speed>=0){
        speed = speed/Axis_Group[axis_index].position_to_rad;
        Axis_Group[axis_index].Axis_start_motion_v(speed,0);
    }else{
        speed = speed/Axis_Group[axis_index].position_to_rad;
        Axis_Group[axis_index].Axis_start_motion_v(-1*speed,1);
    }

    return true;
}

bool C_Robot_Arm::Single_axis_motion(int axis_index ,double speed ,int direction)
{
    if(axis_index>=6||axis_index<0){
        std::cout<<"The axis index error it can be 0~5 !"<<std::endl;
        return false;
    }

    if(direction!=0&&direction!=1)
    {
        std::cout<<"The parament direction is invalid "<<std::endl;
        return false;
    }

    Axis_Group[axis_index].Axis_start_motion_v(speed,direction);
    return true;
}

bool C_Robot_Arm::Single_axis_stop_motion(int axis_index)
{
    if(axis_index>6 || axis_index <=0){
        std::cout<<"The axis_index is invalid it can be 1~6"<<std::endl;
        return false;
    }
    Axis_Group[axis_index-1].Axis_stop_motion();
    return true;
}

C_Dual_arm_robots::C_Dual_arm_robots(int index_1,//机器人编号索引,从1开始
                                     I32 nums_1[6],//轴编号
                                     double p2r_1[6] ,//每个轴数字对应角度映射比例
                                     double offset_1[6],//每个轴零点偏移量
                                     std::vector<double> tool_1,
                                     int index_2, I32 nums_2[6] , double p2r_2[6] , double offset_2[6] , std::vector<double> tool_2):
    Robot_1(index_1,nums_1,p2r_1,offset_1,tool_1) ,
    Robot_2(index_2,nums_2,p2r_2,offset_2,tool_2)
{
    is_turn_on = false;
}

bool C_Dual_arm_robots::Turn_on()
{
    if(!is_turn_on){
        Robot_1.Robot_servo_on();
        Robot_2.Robot_servo_on();
        is_turn_on = true;
    }else{
        std::cout<<"The power has been turned on!"<<std::endl;
    }
    return true;
}

bool C_Dual_arm_robots::Turn_off()
{
    if(is_turn_on){
        is_turn_on = false;
        Robot_1.Robot_servo_off();
        Robot_2.Robot_servo_off();

    }else{
        std::cout<<"The power has not been turned on!"<<std::endl;
    }

    return true;
}

bool C_Dual_arm_robots::Get_info()
{
    if(is_turn_on){
        Robot_1.Robot_get_info();
        Robot_2.Robot_get_info();
    }else{
        std::cout<<"The power has not been turned on!"<<std::endl;
        return false;
    }

    return true;
}

bool C_Dual_arm_robots::Emergency_stop()//这里做特殊处理
{
    for(int i=0 ; i<12 ; i++){
        APS_stop_move(i);
    }
    return true;
}

bool C_Dual_arm_robots::Robot_kine(int index , const double qn_from_ui[6],double time)//弧度制
{
    if(!is_turn_on){
        std::cout<<"The power has not been turned on!"<<std::endl;
        return false;
    }
    if(index==1){
        Robot_1.Robot_motion_kine(qn_from_ui,time);
    }else if(index==2){
        Robot_2.Robot_motion_kine(qn_from_ui,time);
    }else{
        std::cout<<"The index is invalid, it can be 1 or 2"<<std::endl;
        return false;
    }

    return true;

}

bool C_Dual_arm_robots::Robot_ikine(int index ,const mwArray &T , double time)
{
    if(!is_turn_on){
        std::cout<<"The power has not been turned on!"<<std::endl;
        return false;
    }
    if(index==1){
        Robot_1.Robot_motion_ikine(T,time);
    }else if(index==2){
        Robot_2.Robot_motion_ikine(T,time);
    }else{
        std::cout<<"The index is invalid, it can be 1 or 2"<<std::endl;
        return false;
    }
    return true;
}


bool C_Dual_arm_robots::Get_encoder_position(int index,std::vector<double> &nums)
{
    if(!is_turn_on){
        std::cout<<"The power has not been turned on!"<<std::endl;
        return false;
    }
    if(index==1){
        Robot_1.Get_encoder_position(nums);
    }else if(index==2){
        Robot_2.Get_encoder_position(nums);
    }else{
        std::cout<<"C_Dual_arm_robots::Show_position error !!!"<<std::endl;
        std::cout<<"The index is invalid, it must be 1 or 2 !!!"<<std::endl;
        return false;
    }

    return true;
}

bool C_Dual_arm_robots::Get_switch_status()
{
    return is_turn_on;
}

bool C_Dual_arm_robots::Get_hand_position(int index,mwArray &tool_status)
{
    switch (index){
    case 1:
        tool_status = Robot_1.Get_hand_position().Clone();//进行一次深拷贝
        break;
    case 2:
        tool_status = Robot_2.Get_hand_position().Clone();
        break;
    default:
        std::cout<<"The index error，it can be 1 or 2"<<std::endl;
        break;
    }

    return true;
}

bool C_Dual_arm_robots::Get_hand_position(int index,std::vector<std::vector<double>> &tool_status)
{
    if(tool_status.size()!=4){
        std::cout<<"The paraments is invalid"<<std::endl;
        return false;
    }else if(tool_status[0].size()!=4){
        std::cout<<"The paraments is invalid"<<std::endl;
        return false;
    }
    mwArray temp(4,4,mxDOUBLE_CLASS);
    switch (index){
    case 1:
        temp = Robot_1.Get_hand_position().Clone();//进行一次深拷贝
        break;
    case 2:
        temp = Robot_2.Get_hand_position().Clone();
        break;
    default:
        std::cout<<"The index error，it can be 1 or 2"<<std::endl;
        return false;
    }

    for(int i=0 ; i<4 ;i++)
    {
        for(int j=0 ;j<4 ; j++)
        {
            tool_status[i][j] = temp(i+1,j+1);
        }
    }


    return true;
}


bool C_Dual_arm_robots::Get_hand_transl(int index ,mwArray &robot_tool_transl)
{
    std::vector<double> vec_tool_transl(3);
    switch(index)
    {
    case 1:
        Robot_1.Get_tool_trans(vec_tool_transl);
        break;
    case 2:
        Robot_2.Get_tool_trans(vec_tool_transl);
        break;
    default:
        std::cout<<"The index error，it can be 1 or 2"<<std::endl;
        return false;
    }

    robot_tool_transl.SetData(vec_tool_transl.data(),3);
    return true;
}

bool C_Dual_arm_robots::Get_axises_position(int Robot_index , double axises_position[6])
{
    std::vector<double> positions(6);
    switch(Robot_index)
    {
    case 1:
        Robot_1.Get_angle_position(positions);
        break;
    case 2:
        Robot_2.Get_angle_position(positions);
        break;
    default:
        std::cout<<"The Robot_index is error!!!"<<std::endl;
        return false;
    }

    for(int i=0 ;i<6 ; i++)
    {
        axises_position[i] = positions[i];
    }

    return true;
}

bool C_Dual_arm_robots::Single_axis_motion(int robot_index , int axis_index , double speed , int direction)
{
    if(axis_index>=6 ||axis_index<0){
        std::cout<<"The axis_index invalid, it can be 0~5"<<std::endl;
        return true;
    }

    switch(robot_index){
    case 1:
        Robot_1.Single_axis_motion(axis_index,speed,direction);
        break;
    case 2:
        Robot_2.Single_axis_motion(axis_index,speed,direction);
        break;
    default:
        std::cout<<"The robot_index invalid, it can be 1 or 2"<<std::endl;
        return false;
    }


    return true;
}

bool C_Dual_arm_robots::Single_axis_stop_motion(int robot_index , int axis_index)
{
    if(axis_index>6 || axis_index <0){
        std::cout<<"The axis_index is invalid it can be 0~5"<<std::endl;
        return false;
    }

    switch(robot_index){
    case 1:
        Robot_1.Single_axis_stop_motion(axis_index);
        break;
    case 2:
        Robot_2.Single_axis_stop_motion(axis_index);
        break;
    default:
        std::cout<<"The robot_index invalid, it can be 1 or 2"<<std::endl;
        return false;
    }

    return true;
}


bool C_Dual_arm_robots::Robot_kine_v(int Robot_index,std::vector<std::vector<double>> &speed_nums , int continue_time)
{
    switch(Robot_index)
    {
    case 1:
        for(int i=0 ; i<speed_nums[0].size() ; i++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            Robot_1.Single_axis_motion(0,speed_nums[0][i]);
            Robot_1.Single_axis_motion(1,speed_nums[1][i]);
            Robot_1.Single_axis_motion(2,speed_nums[2][i]);
            Robot_1.Single_axis_motion(3,speed_nums[3][i]);
            Robot_1.Single_axis_motion(4,speed_nums[4][i]);
            Robot_1.Single_axis_motion(5,speed_nums[5][i]);

            auto end = std::chrono::high_resolution_clock::now();

            // 计算时间差
            std::chrono::duration<double, std::milli> duration = end - start; // 以毫秒为单位

            // 输出结果
            std::cout << "ppp_Execution Time: " << duration.count() << " ms" << std::endl;
            Sleep(continue_time);
        }

        for(int i=0 ;i<6 ;i++)
        {
            Robot_1.Single_axis_stop_motion(i);
        }
        break;
    case 2:
        for(int i=0 ; i<speed_nums[0].size() ; i++)
        {
            Robot_2.Single_axis_motion(0,speed_nums[0][i]);
            Robot_2.Single_axis_motion(1,speed_nums[1][i]);
            Robot_2.Single_axis_motion(2,speed_nums[2][i]);
            Robot_2.Single_axis_motion(3,speed_nums[3][i]);
            Robot_2.Single_axis_motion(4,speed_nums[4][i]);
            Robot_2.Single_axis_motion(5,speed_nums[5][i]);
            Sleep(continue_time);
        }

        for(int i=0 ;i<6 ;i++)
        {
            Robot_2.Single_axis_stop_motion(i);
        }
        break;
    default:
        std::cout<<"The parament Robot_index is invalid!"<<std::endl;
        return false;
    }

    return true;
}
















