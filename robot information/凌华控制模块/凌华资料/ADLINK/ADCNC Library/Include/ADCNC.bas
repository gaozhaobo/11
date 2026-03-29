Attribute VB_Name = "Module4"
'  Copyright (C) 2013 Adlink Technology INC.
'  All rights reserved.


Option Explicit



Type VP_AVL
     radius As Currency     '// radius (pulse), [1,4294967295], 0:disable
     vmax As Currency       '// maximum velocity (pulse/s), [1,2147483647], 0:disable
End Type


Type VP_CONFIG
     vmax As Currency       '// maximum velocity (pulse/s), [1,2147483647]
     vmin As Currency       '//minimum velocity (pulse/s), [0,2147483647]
     acc As Currency        '// acceleration rate (pulse/ss), [1,2147483647]
     dec As Currency        '// deceleration rate (pulse/ss), [1,2147483647]
     rvmax As Currency      '// rapid, maximum velocity (pulse/s), [1,2147483647]
     rvmin As Currency      '// rapid, minimum velocity (pulse/s), [0,2147483647]
     racc As Currency       '// rapid, acceleration rate (pulse/ss), [1,2147483647]
     rdec As Currency       '// rapid, deceleration rate (pulse/ss), [1,2147483647]
     dmin As Currency       '// parameter, minimum distance (pulse), [0,4294967295]
     omax As Currency       '// parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
     omin As Currency       '// parameter, minimum angular velocity (0.001 degree/s), [0,180000]
     opt As Currency        '// extra, option, [0,0xFFFFFFFF]
     vi As Currency         '// extra, initial velocity (pulse/s), [0,2147483647]
     ve As Currency         '// extra, ending velocity (pulse/s), [0,2147483647]
     avr As Currency        '// extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
     avln As Currency       '// extra, arc velocity limiter, array count, [1,2147483647], 0:disable
     avlp As VP_AVL         '// extra, arc velocity limiter, array start pointer, 0:disable
End Type

Type VP_CONFIG_EXT
     vmax As Currency       '// maximum velocity (pulse/s), [1,2147483647]
     vmin As Currency       '// minimum velocity (pulse/s), [0,2147483647]
     acc  As Currency       '// acceleration rate (pulse/ss), [1,2147483647]
     dec As Currency        '// deceleration rate (pulse/ss), [1,2147483647]
     rvmax As Currency      '// rapid, maximum velocity (pulse/s), [1,2147483647]
     rvmin As Currency      '// rapid, minimum velocity (pulse/s), [0,2147483647]
     racc As Currency       '// rapid, acceleration rate (pulse/ss), [1,2147483647]
     rdec As Currency       '// rapid, deceleration rate (pulse/ss), [1,2147483647]
     dmin As Currency       '// parameter, minimum distance (pulse), [0,4294967295]
     omax As Currency       '// parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
     omin As Currency       '// parameter, minimum angular velocity (0.001 degree/s), [0,180000]
     opt As Currency        '// extra, option, [0,0xFFFFFFFF]
     vi As Currency         '// extra, initial velocity (pulse/s), [0,2147483647]
     ve As Currency         '// extra, ending velocity (pulse/s), [0,2147483647]
     avr As Currency        '// extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
     avln As Currency       '// extra, arc velocity limiter, array count, [1,2147483647], 0:disable
     avlp As VP_AVL         '// extra, arc velocity limiter, array start pointer, 0:disable
           sfactor As Double        '// s-curve factor, added in 2013.7.22
End Type

Public Const VP_OPT_VI = &H1
Public Const VP_OPT_VE = &H2
Public Const VP_OPT_AVR = &H4
Public Const VP_OPT_AVL = &H10
Public Const VP_OPT_DBG = &H80000000
Public Const VP_OPT_DBGR = &H40000000
Public Const VP_OPT_DBGW = &H20000000
Public Const Driver_Magnification_Rate = &O20

Type VP_CONFIG_SP
                size As Currency   '// [IN ] special configuration, byte count, [0,sizeof(VP_CONFIG_SP)]
    x0 As Long         '// [IN ] initial position x, [-2147483648,2147483647]
    y0 As Long         '// [IN ] initial position y, [-2147483648,2147483647]
    nano As Currency   '// [IN ] cycle time (nano s), [1,4294967295], 0:disable
End Type

Type POS_DATA_2D
    u32_opt As Long ';        // option, [0x00000000,0xFFFFFFFF]
    i32_x As Long ';          // x-axis component (pulse), [-2147483648,2147484647]
    i32_y As Long ';          // y-axis component (pulse), [-2147483648,2147484647]
    i32_theta As Long ';      // x-y plane arc move angle (0.000001 degree), [-360000,360000]
End Type


Type POS_DATA_2D_RPS

'/* This structure adds another variable to record what point was be saved */

     u32_opt As Long         '// option, [0x00000000, 0xFFFFFFFF]
           i32_x As Long           '// x-axis component (pulse), [-2147483648, 2147483647]
     i32_y As Long           '// y-axis component (pulse), [-2147483648, 2147483647]
     i32_theta As Long       '// x-y plane arc move angle (0.000001 degree), [-360000, 360000]
           crpi As Long                              '// current reading point index

End Type

Type POS_DATA_2D_F64


    'This structure extends original point data contents from "I32" to "F64"
                'for internal computation. It's important to prevent data overflow.

     u32_opt As Long          '// option, [0x00000000, 0xFFFFFFFF]
     f64_x As Double          '// x-axis component (pulse), [-9223372036854775808, 9223372036854775807]
     f64_y As Double          '// y-axis component (pulse), [-9223372036854775808, 9223372036854775807]
     f64_theta As Double      '// x-y plane arc move angle (0.000001 degree), [-360000, 360000]

End Type

Type POS_DATA_2D_F64_RPS

 '/* This structure adds another variable to record what point was be saved */
 
     u32_opt As Long          '// option, [0x00000000, 0xFFFFFFFF]
     f64_x As Double          '// x-axis component (pulse), [-2147483648, 2147483647]
     f64_y As Double          '// y-axis component (pulse), [-2147483648, 2147483647]
     f64_theta As Double      '// x-y plane arc move angle (0.000001 degree), [-360000, 360000]
           crpi As Long                             '// current reading point index

End Type

Type PNT_DATA_2D_F64

     u32_opt As Long        '// option, [0x00000000,0xFFFFFFFF
     f64_x As Double         '    // x-axis component (pulse), [-2147483648,2147484647]
     f64_y As Double         ' // y-axis component (pulse), [-2147483648,2147484647]
     f64_theta As Double      '// x-y plane arc move angle (0.000001 degree), [-360000,360000]
     f64_acc As Double        '// acceleration rate (pulse/ss), [0,2147484647]
     f64_dec As Double        '// deceleration rate (pulse/ss), [0,2147484647]
     f64_vi As Double         '// initial velocity (pulse/s), [0,2147484647]
     f64_vm As Double         '// maximum velocity (pulse/s), [0,2147484647]
     f64_ve As Double         '// ending velocity (pulse/s), [0,2147484647]
           f64_sf As Double                     '// s-factor [0.0 ~ 1.0]
End Type


Declare Function PathOptimize Lib "ADCNC.dll" (ByVal pointnumber As Currency, PosArrayI As POS_DATA_2D, ByVal ToleranceError As Double, reducepointnumber As Currency, PosArrayR As POS_DATA_2D_RPS, df_tolerr As Double) As Long
Declare Function PathOptimize_F64 Lib "ADCNC.dll" (ByVal pointnumber As Currency, PosArrayI As POS_DATA_2D_F64, ByVal ToleranceError As Double, reducepointnumber As Currency, PosArrayR As POS_DATA_2D_F64_RPS, df_tolerr As Double) As Long
Declare Function PathSmooth Lib "ADCNC.dll" (ByVal PosCountI As Long, PosArrayI As POS_DATA_2D, ByVal Tolerance As Currency, PosCountO As Currency, PosArrayO As POS_DATA_2D) As Long
Declare Function VelocityPlanning Lib "ADCNC.dll" (VpConfig As VP_CONFIG, PosCount As Currency, PosArray As POS_DATA_2D, PntArray As PNT_DATA_2D) As Long
Declare Function VelocityPlanningEx Lib "ADCNC.dll" (VpConfig As VP_CONFIG, ByVal PosCount As Currency, PosArray As POS_DATA_2D, PntArray As PNT_DATA_2D, ByVal InitialX As Long, ByVal InitialY As Long) As Long
Declare Function VelocityPlanningSp Lib "ADCNC.dll" (VpConfig As VP_CONFIG, ByVal PosCount As Currency, PosArray As POS_DATA_2D, PntArray As PNT_DATA_2D, SpConfig As VP_CONFIG_SP) As Long
Declare Function VelocityPlanningSp_F64 Lib "ADCNC.dll" (VpConfig As VP_CONFIG_EXT, ByVal PosCount As Currency, PosArray As POS_DATA_2D_F64, PntArray As PNT_DATA_2D_F64, SpConfig As VP_CONFIG_SP) As Long
Declare Function VelocityPlanning_Clean Lib "ADCNC.dll" () As Long
Declare Function VelocityPlanning_PreAlloc Lib "ADCNC.dll" (ByVal PosCount As Currency, ByVal CfgCount As Currency) As Long
Declare Function VelocityPlanning_PushBack Lib "ADCNC.dll" (VpConfig As VP_CONFIG, ByVal PosCount As Currency, PosArray As POS_DATA_2D, ByVal IsFinish As Long) As Long
Declare Function VelocityPlanning_PopFront Lib "ADCNC.dll" (PntCount As Currency, PntArray As PNT_DATA_2D, IsFinish As Long) As Long
Declare Function VelocityPlanning_Lock Lib "ADCNC.dll" (Interval As Currency, LockName As Byte) As Long
Declare Function PosData2_FileLoad Lib "ADCNC.dll" (FileName As Byte, PosCount As Currency, PosArray As POS_DATA_2D) As Long
Declare Function PosData2_FileLoad_F64 Lib "ADCNC.dll" (FileName As Byte, PosCount As Currency, PosArray As POS_DATA_2D_F64) As Long
Declare Function PosData2_FileSave Lib "ADCNC.dll" (FileName As Byte, ByVal PosCount As Currency, PosArray As POS_DATA_2D) As Long
Declare Function PosData2_FileSave_F64 Lib "ADCNC.dll" (FileName As Byte, ByVal PosCount As Currency, PosArray As POS_DATA_2D_F64) As Long
Declare Function PosData2_FileSav_LR Lib "ADCNC.dll" (FileName As Byte, ByVal PosCount As Currency, PosArray As POS_DATA_2D_RPS) As Long
Declare Function PntData2_FileLoad Lib "ADCNC.dll" (FileName As Byte, PntCount As Currency, PntArray As PNT_DATA_2D) As Long
Declare Function PntData2_FileLoad_F64 Lib "ADCNC.dll" (FileName As Byte, PntCount As Currency, PntArray As PNT_DATA_2D_F64) As Long
Declare Function PntData2_FileSave Lib "ADCNC.dll" (FileName As Byte, PntCount As Currency, PntArray As PNT_DATA_2D) As Long
Declare Function PntData2_FileSave_F64 Lib "ADCNC.dll" (FileName As Byte, ByVal PntCount As Currency, PntArray As PNT_DATA_2D_F64) As Long
Declare Function PntDataX_FileLoad Lib "ADCNC.dll" (FileName As Byte, PntCount As Currency, PntArray As POINT_DATA) As Long
Declare Function PntDataX_FileSave Lib "ADCNC.dll" (FileName As Byte, ByVal PntCount As Currency, PntArray As POINT_DATA) As Long
Declare Function ADCNC_Version Lib "ADCNC.dll" () As Long


Public Const ERR_CNC_NOERR = (0)                      '// no error
Public Const ERR_CNC_INVALID_ARGUMENT = (-10001)      '// invalid argument
Public Const ERR_CNC_INVALID_CONFIG = (-10002)        '// invalid config
Public Const ERR_CNC_WAIT_FAILED = (-10003)           '// internal resource lock wait failed
Public Const ERR_CNC_LOCK_FAILED = (-10004)           '// lock operation is illegal or failed
Public Const ERR_CNC_MEMORY_FAILED = (-10005)         '// memory operation is illegal, failed or insufficient
Public Const ERR_CNC_FILING_FAILED = (-10006)         '// file operation is illegal or failed
Public Const ERR_CNC_REMAINED = (-10007)              '// internal databank still remained data



