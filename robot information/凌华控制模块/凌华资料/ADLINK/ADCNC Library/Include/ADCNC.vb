Option Strict Off
Option Explicit On


Module ADCNC



Structure  VP_CVL
        Dim radius As UInteger  '// radius (pulse), [1,4294967295], 0:disable
        Dim vmax As UInteger    '// maximum velocity (pulse/s), [1,2147483647], 0:disable
End Structure

Structure VP_CONFIG
    Dim     vmax As UInteger       '// maximum velocity (pulse/s), [1,2147483647]
    Dim     vmin As UInteger       '// minimum velocity (pulse/s), [0,2147483647]
    Dim     acc As UInteger        '// acceleration rate (pulse/ss), [1,2147483647]
    Dim     dec As UInteger        '// deceleration rate (pulse/ss), [1,2147483647]
    Dim     rvmax As UInteger      '// rapid, maximum velocity (pulse/s), [1,2147483647]
    Dim     rvmin As UInteger      '// rapid, minimum velocity (pulse/s), [0,2147483647]
    Dim     racc As UInteger       '// rapid, acceleration rate (pulse/ss), [1,2147483647]
    Dim     rdec As UInteger       '// rapid, deceleration rate (pulse/ss), [1,2147483647]
    Dim     dmin As UInteger       '// parameter, minimum distance (pulse), [0,4294967295]
    Dim     omax As UInteger       '// parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
    Dim     omin As UInteger       '// parameter, minimum angular velocity (0.001 degree/s), [0,180000]
    Dim     opt As UInteger        '// extra, option, [0,0xFFFFFFFF]
    Dim     vi As UInteger         '// extra, initial velocity (pulse/s), [0,2147483647]
    Dim     ve As UInteger         '// extra, ending velocity (pulse/s), [0,2147483647]
    Dim     avr As UInteger        '// extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
    Dim     avln As UInteger       '// extra, arc velocity limiter, array count, [1,2147483647], 0:disable
    Dim     avlp As VP_CVL         '// extra, arc velocity limiter, array start pointer, 0:disable
End Structure

Structure VP_CONFIG_EXT
    Dim     vmax As UInteger       '// maximum velocity (pulse/s), [1,2147483647]
    Dim     vmin As UInteger       '// minimum velocity (pulse/s), [0,2147483647]
    Dim     acc As UInteger        '// acceleration rate (pulse/ss), [1,2147483647]
    Dim     dec As UInteger        '// deceleration rate (pulse/ss), [1,2147483647]
    Dim     rvmax As UInteger      '// rapid, maximum velocity (pulse/s), [1,2147483647]
    Dim     rvmin As UInteger      '// rapid, minimum velocity (pulse/s), [0,2147483647]
    Dim     racc As UInteger       '// rapid, acceleration rate (pulse/ss), [1,2147483647]
    Dim     rdec As UInteger       '// rapid, deceleration rate (pulse/ss), [1,2147483647]
    Dim     dmin As UInteger       '// parameter, minimum distance (pulse), [0,4294967295]
    Dim     omax As UInteger       '// parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
    Dim     omin As UInteger       '// parameter, minimum angular velocity (0.001 degree/s), [0,180000]
    Dim     opt As UInteger        '// extra, option, [0,0xFFFFFFFF]
    Dim     vi As UInteger         '// extra, initial velocity (pulse/s), [0,2147483647]
    Dim     ve As UInteger         '// extra, ending velocity (pulse/s), [0,2147483647]
    Dim     avr As UInteger        '// extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
    Dim     avln As UInteger       '// extra, arc velocity limiter, array count, [1,2147483647], 0:disable
    Dim     avlp As VP_CVL         '// extra, arc velocity limiter, array start pointer, 0:disable
	  Dim		  sfactor As Double	     '// s-curve factor, added in 2013.7.22
End Structure

    Public Const VP_OPT_VI = &H1
    Public Const VP_OPT_VE = &H2
    Public Const VP_OPT_AVR = &H4
    Public Const VP_OPT_AVL = &H10
    Public Const VP_OPT_DBG = &H80000000
    Public Const VP_OPT_DBGR = &H40000000
    Public Const VP_OPT_DBGW = &H20000000
Public Const  __Driver_Magnification_Rate		=(20)


Structure VP_CONFIG_SP
    Dim  size As UInteger      '// [IN ] special configuration, byte count, [0,sizeof(VP_CONFIG_SP)]
    Dim  x0 As Integer         '// [IN ] initial position x, [-2147483648,2147483647]
    Dim  y0 As Integer         '// [IN ] initial position y, [-2147483648,2147483647]
    Dim  nano As UInteger      '// [IN ] cycle time (nano s), [1,4294967295], 0:disable
    End Structure

    Structure POS_DATA_2D_RPS
        Dim u32_opt As UInteger       '// option, [0x00000000, 0xFFFFFFFF]
        Dim i32_x As Integer           '// x-axis component (pulse), [-2147483648, 2147483647]
        Dim i32_y As Integer           '// y-axis component (pulse), [-2147483648, 2147483647]
        Dim i32_theta As Integer       '// x-y plane arc move angle (0.000001 degree), [-360000, 360000]
        Dim crpi As UInteger        '// current reading point index
    End Structure

    Structure POS_DATA_2D_F64
        Dim u32_opt As UInteger       '// option, [0x00000000, 0xFFFFFFFF]
        Dim f64_x As Double         '// x-axis component (pulse), [-9223372036854775808, 9223372036854775807]
        Dim f64_y As Double          '// y-axis component (pulse), [-9223372036854775808, 9223372036854775807]
        Dim f64_theta As Double      '// x-y plane arc move angle (0.000001 degree), [-360000, 360000]
    End Structure

    Structure POS_DATA_2D_F64_RPS		
        Dim u32_opt As UInteger        '// option, [0x00000000, 0xFFFFFFFF]
        Dim f64_x As Double          '// x-axis component (pulse), [-2147483648, 2147483647]
        Dim f64_y As Double          '// y-axis component (pulse), [-2147483648, 2147483647]
        Dim f64_theta As Double      '// x-y plane arc move angle (0.000001 degree), [-360000, 360000]
        Dim crpi As UInteger           '// current reading point index
    End Structure

    Structure PNT_DATA_2D_F64
        Dim u32_opt As UInteger       '// option, [0x00000000,0xFFFFFFFF]
        Dim f64_x As Double           '// x-axis component (pulse), [-2147483648,2147484647]
        Dim f64_y As Double           '// y-axis component (pulse), [-2147483648,2147484647]
        Dim f64_theta As Double       '// x-y plane arc move angle (0.000001 degree), [-360000,360000]
        Dim f64_acc As Double         '// acceleration rate (pulse/ss), [0,2147484647]
        Dim f64_dec As Double         '// deceleration rate (pulse/ss), [0,2147484647]
        Dim f64_vi As Double         '// initial velocity (pulse/s), [0,2147484647]
        Dim f64_vm As Double          '// maximum velocity (pulse/s), [0,2147484647]
        Dim f64_ve As Double          '// ending velocity (pulse/s), [0,2147484647]
        Dim f64_sf As Double            '// s-factor [0.0 ~ 1.0]
    End Structure

    Declare Function PathOptimize Lib "ADCNC.dll" (ByVal pointnumber As UInteger, ByRef PosArrayI As POS_DATA_2D, ByVal ToleranceError As Double, ByRef reducepointnumber As UInteger, ByRef PosArrayR As POS_DATA_2D_RPS, ByRef df_tolerr As Double) As Integer
    Declare Function PathOptimize_F64 Lib "ADCNC.dll" (ByVal pointnumber As UInteger, ByRef PosArrayI As POS_DATA_2D_F64, ByVal ToleranceError As Double, ByRef reducepointnumber As UInteger, ByRef PosArrayR As POS_DATA_2D_F64_RPS, ByRef df_tolerr As Double) As Integer
    Declare Function PathSmooth Lib "ADCNC.dll" (ByVal PosCountI As UInteger, ByRef PosArrayI As POS_DATA_2D, ByVal Tolerance As UInteger, ByRef PosCountO As UInteger, ByRef PosArrayO As POS_DATA_2D) As Integer
    Declare Function VelocityPlanning Lib "ADCNC.dll" (ByRef VpConfig As VP_CONFIG, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D, ByRef PntArray As PNT_DATA_2D) As Integer
    Declare Function VelocityPlanningEx Lib "ADCNC.dll" (ByRef VpConfig As VP_CONFIG, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D, ByRef PntArray As PNT_DATA_2D, ByVal InitialX As Integer, ByVal InitialY As Integer) As Integer
    Declare Function VelocityPlanningSp Lib "ADCNC.dll" (ByRef VpConfig As VP_CONFIG, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D, ByRef PntArray As PNT_DATA_2D, ByRef SpConfig As VP_CONFIG_SP) As Integer
    Declare Function VelocityPlanningSp_F64 Lib "ADCNC.dll" (ByRef VpConfig As VP_CONFIG_EXT, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D_F64, ByRef PntArray As PNT_DATA_2D_F64, ByRef SpConfig As VP_CONFIG_SP) As Integer
    Declare Function VelocityPlanning_Clean Lib "ADCNC.dll" () As Integer
    Declare Function VelocityPlanning_IsEmpty Lib "ADCNC.dll" () As Integer
    Declare Function VelocityPlanning_PreAlloc Lib "ADCNC.dll" (ByVal PosCount As UInteger, ByVal CfgCount As UInteger) As Integer
    Declare Function VelocityPlanning_PushBack Lib "ADCNC.dll" (ByRef VpConfig As VP_CONFIG, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D, ByVal IsFinish As Integer) As Integer
    Declare Function VelocityPlanning_PopFront Lib "ADCNC.dll" (ByRef PntCount As UInteger, ByRef PntArray As PNT_DATA_2D, ByRef IsFinish As UInteger) As Integer
    Declare Function VelocityPlanning_Lock Lib "ADCNC.dll" (ByVal Interval As UInteger, ByRef LockName As String) As Integer
    Declare Function PosData2_FileLoad Lib "ADCNC.dll" (ByRef FileName As String, ByRef PosCount As UInteger, ByRef PosArray As POS_DATA_2D) As Integer
    Declare Function PosData2_FileLoad_F64 Lib "ADCNC.dll" (ByRef FileName As String, ByRef PosCount As UInteger, ByRef PosArray As POS_DATA_2D_F64) As Integer
    Declare Function PosData2_FileSave Lib "ADCNC.dll" (ByRef FileName As String, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D) As Integer
    Declare Function PosData2_FileSave_F64 Lib "ADCNC.dll" (ByRef FileName As String, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D_F64) As Integer
    Declare Function PosData2_FileSav_LR Lib "ADCNC.dll" (ByRef FileName As String, ByVal PosCount As UInteger, ByRef PosArray As POS_DATA_2D_RPS) As Integer
    Declare Function PntData2_FileLoad Lib "ADCNC.dll" (ByRef FileName As String, ByRef PntCount As UInteger, ByRef PntArray As PNT_DATA_2D) As Integer
    Declare Function PntData2_FileLoad_F64 Lib "ADCNC.dll" (ByRef FileName As String, ByRef PntCount As UInteger, ByRef PntArray As PNT_DATA_2D_F64) As Integer
    Declare Function PntData2_FileSave Lib "ADCNC.dll" (ByRef FileName As String, ByVal PntCount As UInteger, ByRef PntArray As PNT_DATA_2D) As Integer
    Declare Function PntData2_FileSave_F64 Lib "ADCNC.dll" (ByRef FileName As String, ByVal PntCount As UInteger, ByRef PntArray As PNT_DATA_2D_F64) As Integer
    Declare Function PntDataX_FileLoad Lib "ADCNC.dll" (ByRef FileName As String, ByRef PntCount As UInteger, ByRef PntArray As POINT_DATA) As Integer
    Declare Function PntDataX_FileSave Lib "ADCNC.dll" (ByRef FileName As String, ByVal PntCount As UInteger, ByRef PntArray As POINT_DATA) As Integer
    Declare Function ADCNC_Version Lib "ADCNC.dll" () As Integer


    Public Const ERR_CNC_NOERR = (0)    '// no error
    Public Const ERR_CNC_INVALID_ARGUMENT = (-10001)    '// invalid argument
    Public Const ERR_CNC_INVALID_CONFIG = (-10002)    '// invalid config
    Public Const ERR_CNC_WAIT_FAILED = (-10003)    '// internal resource lock wait failed
    Public Const ERR_CNC_LOCK_FAILED = (-10004)    '// lock operation is illegal or failed
    Public Const ERR_CNC_MEMORY_FAILED = (-10005)    '// memory operation is illegal, failed or insufficient
    Public Const ERR_CNC_FILING_FAILED = (-10006)    '// file operation is illegal or failed
    Public Const ERR_CNC_REMAINED = (-10007)    '// internal databank still remained data


End Module




    
    
    
	





    
    

