#ifndef PARAMETER_TABLE_H
#define PARAMETER_TABLE_H
#include<iostream>
#include<vector>

extern long nums_1[6] ;//机械臂1的轴编号
extern double p2r_1[6] ;//弧度对于凌华控制数字
extern double offset_1[6];//0点位置补偿，因为机械臂1的编码器为相对位置编码器，每次重启都会将当前位置置为0，故不需要补偿
extern std::vector<double> tool_1;//工具坐标系偏移,x,y,z

extern long nums_2[6] ;//机械臂2的轴编号
extern double p2r_2[6] ;
extern double offset_2[6];//机械臂2的编码器为绝对值编码器，需要补偿0位
extern std::vector<double> tool_2 ;//工具坐标系偏移,x,y,z

//相机相对于机械臂1的位姿矩阵
extern std::vector<std::vector<double>> T_Robot2Camera ;//利用AX=XB第二次算出的值


//相机相对于机械臂2的位姿矩阵
extern std::vector<std::vector<double>> T_Robot2Camera2 ;



#endif // PARAMETER_TABLE_H
