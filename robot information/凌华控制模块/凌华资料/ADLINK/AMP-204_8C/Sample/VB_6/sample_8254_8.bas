Attribute VB_Name = "Module3"
Option Explicit
    Const IDX_DLL = (0)
    Const IDX_DRIVER = (1)
    Const IDX_KERNEL = (2)
    Const IDX_FIRMWARE = (3)
    Const IDX_PCB = (4)
    Const IDX_MAX = (5)
    Const MAX_DO_CH = (24)
    Const MAX_DI_CH = (24)
    Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)

Type AXIS_STATUS
    command_position As Double
    feedback_position As Double
    target_position As Double
    error_position As Double
    command_velocity As Double
    feedback_velocity As Double
    motion_io As Long
    motion_status As Long
End Type





    Public Sub get_version_info(ByRef Array_size_5() As Long, ByVal Board_ID As Long)

        '// Get DLL Version
        Array_size_5(IDX_DLL) = APS_version()

        '// Get Driver version
        APS_get_device_info Board_ID, &H10, Array_size_5(IDX_DRIVER)

        '// Get DSP kernel version
        APS_get_device_info Board_ID, &H40, Array_size_5(IDX_KERNEL)

        '// Get FPGA version
        APS_get_device_info Board_ID, &H21, Array_size_5(IDX_FIRMWARE)

        '// Get PCB version
        APS_get_device_info Board_ID, &H30, Array_size_5(IDX_PCB)


    End Sub

    Public Sub get_axis_status_example(ByVal Axis_ID As Long, ByRef P_Axis_status As AXIS_STATUS)

        APS_get_command_f Axis_ID, P_Axis_status.command_position
        APS_get_position_f Axis_ID, P_Axis_status.feedback_position
        APS_get_target_position_f Axis_ID, P_Axis_status.target_position
        APS_get_error_position_f Axis_ID, P_Axis_status.error_position
        APS_get_command_velocity_f Axis_ID, P_Axis_status.command_velocity
        APS_get_feedback_velocity_f Axis_ID, P_Axis_status.feedback_velocity

        P_Axis_status.motion_io = APS_motion_io_status(Axis_ID)
        P_Axis_status.motion_status = APS_motion_status(Axis_ID)

    End Sub
    
Public Sub load_parameters_from_file_sample(ByVal FilePath)

        APS_load_param_from_file FilePath

End Sub

Public Function check_motion_done_example(ByVal Axis_ID As Long, ByRef Stop_Code As Long) As Long

        Dim axis_id_sub As Long
        axis_id_sub = Axis_ID
        Dim msts As Long
        msts = APS_motion_status(axis_id_sub) '// Get motion status
        msts = (msts And (2 ^ MTS_NSTP)) '// Get motion done bit
        '// msts = ( msts >> MTS_HMV ) & 1;    // Get homming bit

        '// Get stop code.
        APS_get_stop_code Axis_ID, Stop_Code

        If msts > 0 Then

            '// Check move success or not
            msts = APS_motion_status(axis_id_sub) '// Get motion status
            msts = (msts And (2 ^ MTS_ASTP))     '// Get abnormal stop bit

            If msts > 0 Then
                '// Error handling ...
                Dim stop_code_sub As Long
                APS_get_stop_code axis_id_sub, stop_code_sub
                check_motion_done_example = -1 '//error
            Else
                '// Motion success.
                check_motion_done_example = 1
            End If

        Else
            check_motion_done_example = 0 '//Now are in motion
        End If
    End Function

    Public Function stop_code_to_string(ByVal Stop_Code As Long) As String

        Select Case Stop_Code

            Case 0
                stop_code_to_string = "STOP_NORMAL"
            Case 1
                stop_code_to_string = "STOP_EMG"
            Case 2
                stop_code_to_string = "STOP_ALM"
            Case 3
                stop_code_to_string = "STOP_SVNO"
            Case 4
                stop_code_to_string = "STOP_PEL"
            Case 5
                stop_code_to_string = "STOP_MEL"
            Case 6
                stop_code_to_string = "STOP_SPEL"
            Case 7
                stop_code_to_string = "STOP_SMEL"
            Case 8
                stop_code_to_string = "STOP_USER_EMG"
            Case 9
                stop_code_to_string = "STOP_USER"
            Case 10
                stop_code_to_string = "STOP_GAN_L1"
            Case 11
                stop_code_to_string = "STOP_GAN_L2"
            Case 12
                stop_code_to_string = "STOP_GEAR_SLAVE"
            Case 13
                stop_code_to_string = "STOP_ERROR_LEVEL"
            Case 20
                stop_code_to_string = "STOP_ORG_EL"
            Case 21
                stop_code_to_string = "STOP_NO_ORG"
            Case 22
                stop_code_to_string = "STOP_NO_EZ"
            Case 23
                stop_code_to_string = "STOP_BOTH_EL"
            Case Else
                stop_code_to_string = "Unknown stop code!"
        End Select
    End Function


    Public Sub home_move_example(ByVal Axis_ID As Long)
        '//This example shows how home move operation
        Dim axis_id_sub As Long
        axis_id_sub = Axis_ID
        Dim return_code As Long

        '// 1. Select home mode and config home parameters
        APS_set_axis_param axis_id_sub, PRA_HOME_MODE, 0 '// Set home mode
        APS_set_axis_param axis_id_sub, PRA_HOME_DIR, 1  '// Set home direction
        APS_set_axis_param_f axis_id_sub, PRA_HOME_CURVE, 0  '// Set acceleration paten  T-curve
        APS_set_axis_param_f axis_id_sub, PRA_HOME_ACC, 1000000  '// Set homing acceleration rate
        APS_set_axis_param_f axis_id_sub, PRA_HOME_VM, 100000  '// Set homing maximum velocity.
        APS_set_axis_param_f axis_id_sub, PRA_HOME_VO, 50000  '// Set homing VO speed
        APS_set_axis_param axis_id_sub, PRA_HOME_EZA, 0  '// Set EZ signal alignment  yes or no
        APS_set_axis_param_f axis_id_sub, PRA_HOME_SHIFT, 0  '// Set home position shfit distance.
        APS_set_axis_param_f axis_id_sub, PRA_HOME_POS, 0  '// Set final home position.

        '//Check servo on or not
        If (APS_motion_io_status(axis_id_sub) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on axis_id_sub, 1
            Sleep 500

        End If

        '// 2. Start home move
        return_code = APS_home_move(Axis_ID) '//Start homing
        If (return_code <> ERR_NoError) Then
            '/* Error handling */
        End If

    End Sub


    Public Sub velocity_move_example(ByVal Axis_ID As Long)

        Dim axis_id_sub As Long
        axis_id_sub = Axis_ID
        Dim speed_1 As Double
        speed_1 = 500#
        Dim speed_2 As Double
        speed_2 = 1000#
        Dim speed_3 As Double
        speed_3 = 600#

        APS_set_axis_param_f axis_id_sub, PRA_STP_DEC, 10000#
        APS_set_axis_param_f axis_id_sub, PRA_CURVE, 0.5  '//Set acceleration rate
        APS_set_axis_param_f axis_id_sub, PRA_ACC, 10000#   '//Set acceleration rate
        APS_set_axis_param_f axis_id_sub, PRA_DEC, 10000#  '//Set deceleration rate

        '//Check servo on or not
        If (APS_motion_io_status(axis_id_sub) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on axis_id_sub, 1
            Sleep 500 '// Wait stable.

        End If

        Dim Wait As ASYNCALL ' this fucntion argument is It is reserved for future
        Wait.h_event = 0
        Wait.i32_ret = 0
        APS_vel axis_id_sub, 0, speed_1, Wait '// Start a velocity move
        Sleep 2000 '// Wait 2 second

        'APS_vel axis_id_sub, 0, speed_2, wait  '// Change speed on the fly
        'Sleep 2000 '// Wait 2 second

        'APS_vel axis_id_sub, 0, speed_3, wait '// Change speed on the fly
        'Sleep 2000 '// Wait 2 second

        'APS_stop_move Axis_ID '// Stop
        
    End Sub
    
    Public Sub jog_move_continuous_mode_example(ByVal Axis_ID As Long)

        APS_set_axis_param Axis_ID, PRA_JG_MODE, 0 '// Set jog mode
        APS_set_axis_param Axis_ID, PRA_JG_DIR, 0 '// Set jog direction

        APS_set_axis_param_f Axis_ID, PRA_JG_CURVE, 0#
        APS_set_axis_param_f Axis_ID, PRA_JG_ACC, 1000#
        APS_set_axis_param_f Axis_ID, PRA_JG_DEC, 1000#
        APS_set_axis_param_f Axis_ID, PRA_JG_VM, 100#

        '//Check servo on or not
        If (APS_motion_io_status(Axis_ID) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on Axis_ID, 1
            Sleep 500 '// Wait stable.

        End If

        '// Create a rising edge.
        APS_jog_start Axis_ID, 0 '//Jog Off
        APS_jog_start Axis_ID, 1 '//Jog ON

    End Sub

    Public Sub jog_move_step_mode_example(ByVal Axis_ID As Long)

        APS_set_axis_param Axis_ID, PRA_JG_MODE, 0 '// Set jog mode
        APS_set_axis_param Axis_ID, PRA_JG_DIR, 0 '// Set jog direction

        APS_set_axis_param_f Axis_ID, PRA_JG_CURVE, 0#
        APS_set_axis_param_f Axis_ID, PRA_JG_ACC, 1000#
        APS_set_axis_param_f Axis_ID, PRA_JG_DEC, 1000#
        APS_set_axis_param_f Axis_ID, PRA_JG_VM, 100#

        APS_set_axis_param_f Axis_ID, PRA_JG_STEP, 1000#
        APS_set_axis_param Axis_ID, PRA_JG_DELAY, 5000

        '//Check servo on or not
        If (APS_motion_io_status(Axis_ID) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on Axis_ID, 1
            Sleep 500 '// Wait stable.

        End If

        '// Create a rising edge.
        APS_jog_start Axis_ID, 0 '//Jog Off
        APS_jog_start Axis_ID, 1 '//Jog ON

    End Sub

    Public Sub jog_move_via_DI_example(ByVal Axis_ID As Long)

        APS_set_axis_param Axis_ID, PRA_JG_MODE, 0 '// Set jog mode
        APS_set_axis_param Axis_ID, PRA_JG_DIR, 0 '// Set jog direction

        APS_set_axis_param_f Axis_ID, PRA_JG_CURVE, 0# '// Jog curve parten(T or s curve
        APS_set_axis_param_f Axis_ID, PRA_JG_ACC, 1000# '// Jog move acceleration
        APS_set_axis_param_f Axis_ID, PRA_JG_DEC, 1000# '// Jog move deceleration
        APS_set_axis_param_f Axis_ID, PRA_JG_VM, 100# '// Jog move max velocity

        APS_set_axis_param Axis_ID, PRA_JG_MAP_DI_EN, &H3 '// Enable positive DI and negative DI
        APS_set_axis_param Axis_ID, PRA_JG_P_JOG_DI, 0 '// Define DI ch0 for positive jog signal
        APS_set_axis_param Axis_ID, PRA_JG_N_JOG_DI, 1 '// Define DI ch1 for negative jog signal
    End Sub


    Public Sub p2p_example(ByVal Axis_ID As Long)

        '// Config speed profile parameters.
        APS_set_axis_param_f Axis_ID, PRA_SF, 0.5
        APS_set_axis_param_f Axis_ID, PRA_ACC, 10000#
        APS_set_axis_param_f Axis_ID, PRA_DEC, 10000#
        APS_set_axis_param_f Axis_ID, PRA_VM, 1000#

        '//Check servo on or not
        If (APS_motion_io_status(Axis_ID) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on Axis_ID, 1
            Sleep 500 '// Wait stable.

        End If

        '// Start a relative p to p move
        Dim Wait As ASYNCALL
        Wait.h_event = 0
        Wait.i32_ret = 0

        APS_ptp Axis_ID, OPT_RELATIVE, 1000#, Wait

        '// Method 2, ptp move with maximum velocity.
        'APS_ptp_v Axis_ID, OPT_RELATIVE, 500#, 1000#, wait

        '// Method 3, ptp move with all speed parameters.
        'APS_ptp_all Axis_ID, OPT_RELATIVE, 500#, 0#, 1000#, 0#, 10000#, 10000#, 0.5, wait

    End Sub

    Public Sub deceleration_stop_example(ByVal Axis_ID As Long)
        APS_set_axis_param_f Axis_ID, PRA_STP_DEC, 10000#
        APS_stop_move Axis_ID

    End Sub

    Public Sub emg_stop_example(ByVal Axis_ID As Long)
        '// Stop immediately
        APS_emg_stop Axis_ID

    End Sub

    Public Sub interpolation_2D_line_example(ByRef Axis_ID_Array() As Long)

        Dim PositionArray(1) As Double
        PositionArray(0) = 1000#
        PositionArray(1) = 2000#
        Dim TransPara As Double
        TransPara = 0

        '// config speed profile
        APS_set_axis_param_f Axis_ID_Array(0), PRA_SF, 0.5
        APS_set_axis_param_f Axis_ID_Array(0), PRA_ACC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_DEC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_VM, 1000#

        '//Check servo on or not
        If (APS_motion_io_status(Axis_ID_Array(0)) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on Axis_ID_Array(0), 1
            Sleep 500 '// Wait stable.
        End If

        '//Check servo on or not
        If (APS_motion_io_status(Axis_ID_Array(1)) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on Axis_ID_Array(1), 1
            Sleep 500 '// Wait stable.
        End If

        '// Start a 2 dimension linear interpolation
        Dim Wait As ASYNCALL ' this fucntion argument is It is reserved for future
        Wait.h_event = 0
        Wait.i32_ret = 0

        APS_line 2, Axis_ID_Array(0), OPT_RELATIVE, PositionArray(0), TransPara, Wait

    End Sub

    Public Sub interpolation_2D_arc_example(ByRef Axis_ID_Array() As Long)

        Dim CenterArray(2) As Double
        CenterArray(0) = 1000#
        CenterArray(1) = 0#
        Dim Angle As Double
        Angle = TO_RADIAN(90#)
        Dim TransPara As Double
        TransPara = 0

        '// config speed profile
        APS_set_axis_param_f Axis_ID_Array(0), PRA_SF, 0.5
        APS_set_axis_param_f Axis_ID_Array(0), PRA_ACC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_DEC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_VM, 1000#

        '//Check servo on or not
        If (APS_motion_io_status(Axis_ID_Array(0)) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on Axis_ID_Array(0), 1
            Sleep 500 '// Wait stable.
        End If

        '//Check servo on or not
        If (APS_motion_io_status(Axis_ID_Array(1)) And (2 ^ MIO_SVON)) = 0 Then

            APS_set_servo_on Axis_ID_Array(1), 1
            Sleep 500 '// Wait stable.
        End If

        '// Start a 2 dimension linear interpolation
        Dim Wait As ASYNCALL ' this fucntion argument is It is reserved for future
        Wait.h_event = 0
        Wait.i32_ret = 0

        APS_arc2_ca Axis_ID_Array(0), OPT_RELATIVE, CenterArray(0), Angle, TransPara, Wait

    End Sub

    Public Function TO_RADIAN(ByVal x As Double) As Double
        TO_RADIAN = ((x) * 3.14159265 / 180#)
    End Function

    Public Sub interpolation_3D_arc_example(ByRef Axis_ID_Array() As Long)

        Dim CenterArray(3) As Double
        CenterArray(0) = 1000#
        CenterArray(1) = 1000#
        CenterArray(2) = 0
        Dim EndArray(3) As Double
        EndArray(0) = 1000#
        EndArray(1) = 1000#
        EndArray(2) = 1000# * (2 ^ (1 / 2))
        Dim Dir As Integer
        Dir = 0
        Dim TransPara As Double
        TransPara = 0
        Dim i As Integer

        '// config speed profile
        APS_set_axis_param_f Axis_ID_Array(0), PRA_SF, 0.5
        APS_set_axis_param_f Axis_ID_Array(0), PRA_ACC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_DEC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_VM, 2000#

        '//Check servo on or not
        For i = 0 To 2
            If (APS_motion_io_status(Axis_ID_Array(i)) And (2 ^ MIO_SVON)) = 0 Then
                APS_set_servo_on Axis_ID_Array(i), 1
                Sleep 500 '// Wait stable.
            End If
        Next
        Sleep 500  ' // Wait stable.
        
        Dim Wait As ASYNCALL ' this fucntion argument is It is reserved for future
        Wait.h_event = 0
        Wait.i32_ret = 0

        APS_arc3_ce Axis_ID_Array(0), OPT_RELATIVE, CenterArray(0), EndArray(0), Dir, TransPara, Wait

    End Sub


    Public Sub interpolation_3D_helical_example(ByRef Axis_ID_Array() As Long)

        Dim CenterArray(3) As Double
        CenterArray(0) = 1000#
        CenterArray(1) = 1000#
        CenterArray(2) = 0
        Dim NormalArray(3) As Double
        NormalArray(0) = 0
        NormalArray(1) = 0
        NormalArray(2) = 1
        Dim Angle As Double
        Angle = TO_RADIAN(720#)
        Dim DeltaH As Double
        DeltaH = 500#
        Dim FinalR As Double
        FinalR = 200#
        Dim TransPara As Double
        TransPara = 0
        Dim i As Integer

        '// config speed profile
        APS_set_axis_param_f Axis_ID_Array(0), PRA_SF, 0.5
        APS_set_axis_param_f Axis_ID_Array(0), PRA_ACC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_DEC, 10000#
        APS_set_axis_param_f Axis_ID_Array(0), PRA_VM, 2000#

        '//Check servo on or not
        For i = 0 To 2
            If (APS_motion_io_status(Axis_ID_Array(i)) And (2 ^ MIO_SVON)) = 0 Then
                APS_set_servo_on Axis_ID_Array(i), 1
                Sleep 500 '// Wait stable.
            End If
        Next
        Sleep 500 '// Wait stable.
        
        Dim Wait As ASYNCALL ' this fucntion argument is It is reserved for future
        Wait.h_event = 0
        Wait.i32_ret = 0

        APS_spiral_ca Axis_ID_Array(0), OPT_RELATIVE, CenterArray(0), NormalArray(0), Angle, DeltaH, FinalR, TransPara, Wait

    End Sub


    Public Sub contour_2D_example(ByRef Axis_ID_Array() As Long)

        Dim i As Integer
        Dim TransPara As Double
        TransPara = 0
        Dim PositionArray(2) As Double
        PositionArray(0) = 1000
        PositionArray(1) = 0
        Dim PositionArray_2(2) As Double
        PositionArray_2(0) = 0
        PositionArray_2(1) = 1000
        Dim CenterArray(2) As Double
        CenterArray(0) = 1000
        CenterArray(1) = 500
        Dim CenterArray_2(2) As Double
        CenterArray_2(0) = 0
        CenterArray_2(1) = 500
        Dim EndArray(2) As Double
        EndArray(0) = 1000
        EndArray(1) = 1000
        Dim EndArray_2(2) As Double
        EndArray_2(0) = 0
        EndArray_2(1) = 0
    
        '//Check servo on or not
        For i = 0 To 1
            If (APS_motion_io_status(Axis_ID_Array(i)) And (2 ^ MIO_SVON)) = 0 Then
                APS_set_servo_on Axis_ID_Array(i), 1
                Sleep 500 '// Wait stable.
            End If
        Next

        '// Execute 4 interpolation move useing bufferd mode. Note option using "ITP_OPT_BUFFERED"
        Dim Wait As ASYNCALL ' this fucntion argument is It is reserved for future
        Wait.h_event = 0
        Wait.i32_ret = 0

        
        APS_line_all 2, Axis_ID_Array(0), (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), PositionArray(0), TransPara _
         , 0#, 1000#, 1000#, 10000#, 10000#, 0#, Wait


        APS_arc2_ce_all Axis_ID_Array(0), (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), CenterArray(0), EndArray(0), 0, TransPara _
            , 1000#, 1000#, 1000#, 10000#, 10000#, 0#, Wait

        APS_line_all 2, Axis_ID_Array(0), (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), PositionArray_2(0), TransPara _
        , 1000#, 1000#, 1000#, 10000#, 10000#, 0#, Wait

        APS_arc2_ce_all Axis_ID_Array(0), (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), CenterArray_2(0), EndArray_2(0), 0, TransPara _
         , 1000#, 1000#, 0#, 10000#, 10000#, 0#, Wait


    End Sub


    Public Function interrupt_example(ByVal Board_ID As Long, ByVal Axis_num As Long) As Long

        '// This example shows how interrupt functions work.
        Dim board_id_sub As Long
        board_id_sub = Board_ID
        Dim Int_No As Long '// Interrupt number
        Dim return_code As Long '// function return code
        Dim item As Long
        item = Axis_num '// Axis #? interrupt
        Dim factor As Long
        factor = 12 '// factor number = 12 IMDN interrupt

        '// Step 1: set interrupt factor ( factor = IMDN )
        '// 設定要等待的中斷事件
        Int_No = APS_set_int_factor(Board_ID, item, factor, 1)

        '// Step 2: set interrupt main switch
        '// 設定中斷總開關
        APS_int_enable Board_ID, 1 '// Enable the interrupt main switch

        '// Step 3: wait interrupt.
        '// 等待中斷觸發
        return_code = APS_wait_single_int(Int_No, 1) '//Wait interrupt
        
        If return_code = ERR_NoError Then
            '//Interrupt occurred
            '//Step 4: 重置中斷為為觸發狀態
            APS_reset_int Int_No
        End If

        '// Step 5: Disable interrupt at the end of program.
        '// 關閉中斷事件和中斷總開關
        APS_set_int_factor Board_ID, item, factor, 0
        APS_int_enable Board_ID, 0

        interrupt_example = return_code
    End Function


    Public Sub DIO_sample(ByVal Board_ID As Long)

        Dim digital_output_value As Long
        digital_output_value = 0
        Dim digital_input_value As Long
        digital_input_value = 0
        Dim do_ch(MAX_DO_CH - 1) As Long
        Dim di_ch(MAX_DI_CH - 1) As Long
        Dim i As Integer

        '//****** Read digital output channels *****************************
        APS_read_d_output Board_ID, 0, digital_output_value
        For i = 0 To (MAX_DO_CH - 1)
            If (digital_output_value And (2 ^ i)) > 0 Then
                do_ch(i) = 1
            Else
                do_ch(i) = 0
            End If
        Next
        '//************ Write digital output channels examples *************
        do_ch(0) = 1 '// set 0 or 1
        do_ch(2) = 1 '// set 0 or 1
        do_ch(4) = 1 '// set 0 or 1

        digital_output_value = 0
        For i = 0 To (MAX_DO_CH - 1)
            If do_ch(i) = 1 Then
                digital_output_value = (digital_output_value) Or (2 ^ i)
            End If
        Next
        APS_write_d_output Board_ID, 0, digital_output_value
        '//*******************************************************************

        '//**** Read digital input channels **********************************
        APS_read_d_input Board_ID, 0, digital_input_value

        For i = 0 To (MAX_DI_CH - 1)
            If (digital_input_value And (2 ^ i)) > 0 Then
                di_ch(i) = 1
            Else
                di_ch(i) = 0
            End If
        
        Next
        '//********************************************************************
    End Sub

    Public Sub AIO_sample(ByVal Board_ID As Long)

        Dim Channel_No As Long
        Channel_No = 0
        Dim analog_input_volt As Double
        Dim analog_output_volt As Double

        APS_read_a_input_value Board_ID, Channel_No, analog_input_volt

        analog_output_volt = 1.5 '// 1.5 volt
        APS_write_a_output_value Board_ID, Channel_No, analog_output_volt
        APS_read_a_output_value Board_ID, Channel_No, analog_output_volt
    End Sub
    
     Public Sub point_table_2D_example(ByVal Board_ID As Long, ByRef Axis_ID_Array() As Long)
     
        Dim boardId As Long
        Dim PtbId As Integer
        Dim Dimension As Integer
        Dim doOn As Integer
        Dim doOff As Integer
        Dim i As Integer
        Dim doChannel As Integer
        Dim Status As PTSTS
        Dim Line As PTLINE
        Dim Arc2 As PTA2CA
        Dim ret As Long
        
        boardId = Board_ID
        PtbId = 0
        Dimension = 2
        doOn = 0
        doOff = 1
        i = 0
        doChannel = 0
        
        
        'Check servo on
        For i = 0 To (Dimension - 1)
            ret = APS_set_servo_on(Axis_ID_Array(i), 1)
        Next
        
        'Wait stable.
        Sleep 500

        'Enable point table
        ret = APS_pt_disable(boardId, PtbId)
        
        
         Dim A(2) As Long
        A(0) = Axis_ID_Array(0)
        A(1) = Axis_ID_Array(1)
        ret = APS_pt_enable(boardId, PtbId, Dimension, Axis_ID_Array(0))
        
        
        'Configuration
        ret = APS_pt_set_absolute(boardId, PtbId)       'Set to absolute mode
        ret = APS_pt_set_trans_buffered(boardId, PtbId) 'Set to buffer mode
        ret = APS_pt_set_acc(boardId, PtbId, 10000)     'Set acc
        ret = APS_pt_set_dec(boardId, PtbId, 10000)     'Set dec

        'Get status
        'BitSts;
        'b0: Is PTB work? [1:working, 0:Stopped]
        'b1: Is point buffer full? [1:full, 0:not full]
        'b2: Is point buffer empty? [1:empty, 0:not empty]
        'b3~b5: reserved
        ret = APS_get_pt_status(boardId, PtbId, Status)
        
         Dim tmp As Integer
         tmp = Status.BitSts
         tmp = Status.PntBufFreeSpace
         tmp = Status.PntBufUsageSpace
         tmp = Status.RunningCnt

        'Buffer is not Full
        If (Not (Status.BitSts And 2)) Then

            'Set 1st move profile
            ret = APS_pt_set_vm(boardId, PtbId, 10000)
            ret = APS_pt_set_ve(boardId, PtbId, 5000)

            'Set do command to sync with 1st point
            ret = APS_pt_ext_set_do_ch(boardId, PtbId, doChannel, doOn)

            'Set pt arc data
             Arc2.Center0 = 1000#
             Arc2.Center1 = 1000#
             
             Arc2.Angle = 180# * 3.14159265 / 180#
            
             Arc2.Index0 = 0
             Arc2.Index1 = 1
             
            'Push 1st point to buffe
             ret = APS_pt_arc2_ca(boardId, PtbId, Arc2, Status)
             
             
             tmp = Status.BitSts
             tmp = Status.PntBufFreeSpace
             tmp = Status.PntBufUsageSpace
             tmp = Status.RunningCnt
             
        End If

        'Get status
        ret = APS_get_pt_status(boardId, PtbId, Status)

        If (Not (Status.BitSts And 2)) Then

            'Set 2nd move profile
            ret = APS_pt_set_vm(boardId, PtbId, 12000)
            ret = APS_pt_set_ve(boardId, PtbId, 6000)

            'Set do command to sync with 2nd point
            ret = APS_pt_ext_set_do_ch(boardId, PtbId, doChannel, doOff)

            'Set pt line data
             Line.Dimension = 2
             Line.pos0 = 0#
             Line.pos1 = 0#
             
            'Push 2nd point to buffer
            ret = APS_pt_line(boardId, PtbId, Line, Status)
        End If

        'Get status
        ret = APS_get_pt_status(boardId, PtbId, Status)
        If (Not (Status.BitSts And 2)) Then

            'Set 3rd move profile
            ret = APS_pt_set_vm(boardId, PtbId, 10000)
            ret = APS_pt_set_ve(boardId, PtbId, 5000)

            'Set do command to sync with 3rd point
            ret = APS_pt_ext_set_do_ch(boardId, PtbId, doChannel, doOn)

            'Set pt arc data
             Arc2.Center0 = 1000
             Arc2.Center1 = 1000
             
             Arc2.Angle = (180) * 3.14159265 / 180#  '180 degree
             Arc2.Index0 = 0
             Arc2.Index1 = 1

            'Push 3rd point to buffer
            ret = APS_pt_arc2_ca(boardId, PtbId, Arc2, Status)
        End If

        'Get status
        ret = APS_get_pt_status(boardId, PtbId, Status)

        If (Not (Status.BitSts And 2)) Then

            'Set 4th move profile
            ret = APS_pt_set_vm(boardId, PtbId, 12000)
            ret = APS_pt_set_ve(boardId, PtbId, 500)

            'Set do command to sync with 4th point
            ret = APS_pt_ext_set_do_ch(boardId, PtbId, doChannel, doOff)

            'Set pt line data
            Line.Dimension = 2
            Line.pos0 = 0#
            Line.pos1 = 0#

            'Push 4th point to buffer
            ret = APS_pt_line(boardId, PtbId, Line, Status)
        End If

        ret = APS_pt_start(boardId, PtbId)
        
        ret = APS_get_pt_status(boardId, PtbId, Status)
        tmp = Status.BitSts
        tmp = Status.PntBufFreeSpace
        tmp = Status.PntBufUsageSpace
        tmp = Status.RunningCnt
        
     
     End Sub
      Public Sub Gear_example(ByRef Axis_ID_Array() As Long)
      
        Dim masterAxis As Integer
        Dim slaveAxis As Integer
        Dim i As Integer
        Dim Status As Long
        Dim ret As Integer
        Dim Wait As ASYNCALL

        masterAxis = Axis_ID_Array(0)
        slaveAxis = Axis_ID_Array(1)
        i = 0
        Status = 0
        ret = 0


        'Servo On
        ret = APS_set_servo_on(masterAxis, 1)
        ret = APS_set_servo_on(slaveAxis, 1)

        'Wait for stable.
        Sleep (1)

        'Get status of gear applicaiton.
        'Gear status:
        ' 0: In disabling status.
        ' 1: In enabling status of standard mode.
        ' 2: In enabling status of gantry mode.
        ret = APS_get_gear_status(slaveAxis, Status)


        If Status = 0 Then

            'Select master Axis command to be slaveAxis's master
            ret = APS_set_axis_param(slaveAxis, PRA_GEAR_MASTER, masterAxis)

            'Set Gear engage rate
            ret = APS_set_axis_param_f(slaveAxis, PRA_GEAR_ENGAGE_RATE, 500000#)

            'set Gear ratio
            ret = APS_set_axis_param_f(slaveAxis, PRA_GEAR_RATIO, 2#)

            'Set E-gear gantry mode protection level 1
            ret = APS_set_axis_param_f(slaveAxis, PRA_GANTRY_PROTECT_1, 100000#)

            ''Set E-gear gantry mode protection level 2
            ret = APS_set_axis_param_f(slaveAxis, PRA_GANTRY_PROTECT_2, 200000#)

            'Set to Standard mode (0: Disable, 1: Standard mode, 2: Gantry mode.)
            ret = APS_start_gear(slaveAxis, 1)

        End If


        'Start master axis relative p to p move
        ret = APS_ptp(masterAxis, OPT_RELATIVE, 1000#, Wait)

        'Wait for motion done
        Sleep (1200)

        'Disable Standard mode (0: Disable, 1: Standard mode, 2: Gantry mode.)
        ret = APS_start_gear(slaveAxis, 0)
      
      
      
      
      End Sub
    
   

