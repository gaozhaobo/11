Option Strict Off
Option Explicit On
Imports System.Threading


Module sample_8254_8
    Const IDX_DLL = (0)
    Const IDX_DRIVER = (1)
    Const IDX_KERNEL = (2)
    Const IDX_FIRMWARE = (3)
    Const IDX_PCB = (4)
    Const IDX_MAX = (5)
    Const __MAX_DO_CH = (24)
    Const __MAX_DI_CH = (24)

    Structure AXIS_STATUS
        Dim command_position As Double
        Dim feedback_position As Double
        Dim target_position As Double
        Dim error_position As Double
        Dim command_velocity As Double
        Dim feedback_velocity As Double
        Dim motion_io As Integer
        Dim motion_status As Integer
    End Structure

    Public Sub get_version_info(ByRef Array_size_5() As Integer, ByVal Board_ID As Integer)

        '// Get DLL Version
        Array_size_5(IDX_DLL) = APS_version()

        '// Get Driver version
        APS_get_device_info(Board_ID, &H10, Array_size_5(IDX_DRIVER))

        '// Get DSP kernel version
        APS_get_device_info(Board_ID, &H40, Array_size_5(IDX_KERNEL))

        '// Get FPGA version
        APS_get_device_info(Board_ID, &H21, Array_size_5(IDX_FIRMWARE))

        '// Get PCB version
        APS_get_device_info(Board_ID, &H30, Array_size_5(IDX_PCB))


    End Sub

    Public Sub get_axis_status_example(ByVal Axis_ID As Integer, ByRef P_Axis_status As AXIS_STATUS)

        APS_get_command_f(Axis_ID, P_Axis_status.command_position)
        APS_get_position_f(Axis_ID, P_Axis_status.feedback_position)
        APS_get_target_position_f(Axis_ID, P_Axis_status.target_position)
        APS_get_error_position_f(Axis_ID, P_Axis_status.error_position)
        APS_get_command_velocity_f(Axis_ID, P_Axis_status.command_velocity)
        APS_get_feedback_velocity_f(Axis_ID, P_Axis_status.feedback_velocity)

        P_Axis_status.motion_io = APS_motion_io_status(Axis_ID)
        P_Axis_status.motion_status = APS_motion_status(Axis_ID)

    End Sub

    Public Sub load_parameters_from_file_sample(ByVal FilePath)

        APS_load_param_from_file(FilePath)

    End Sub

    Public Function check_motion_done_example(ByVal Axis_ID As Integer, ByRef Stop_Code As Integer) As Integer

        Dim axis_id_sub As Integer = Axis_ID
        Dim msts As Integer
        msts = APS_motion_status(axis_id_sub) '// Get motion status
        msts = (msts >> MTS_NSTP) And 1 '// Get motion done bit
        '// msts = ( msts >> MTS_HMV ) & 1;    // Get homming bit

        '// Get stop code.
        APS_get_stop_code(Axis_ID, Stop_Code)

        If msts = 1 Then

            '// Check move success or not
            msts = APS_motion_status(axis_id_sub) '// Get motion status
            msts = (msts >> MTS_ASTP) And 1     '// Get abnormal stop bit

            If msts = 1 Then
                '// Error handling ...
                Dim stop_code_sub As Integer
                APS_get_stop_code(axis_id_sub, stop_code_sub)
                Return -1 '//error
            Else
                '// Motion success.
                Return 1
            End If

        End If
            Return 0 '//Now are in motion
    End Function

    Public Function stop_code_to_string(ByVal Stop_Code As Integer) As String

        Select Case Stop_Code

            Case 0
                Return "STOP_NORMAL"
            Case 1
                Return "STOP_EMG"
            Case 2
                Return "STOP_ALM"
            Case 3
                Return "STOP_SVNO"
            Case 4
                Return "STOP_PEL"
            Case 5
                Return "STOP_MEL"
            Case 6
                Return "STOP_SPEL"
            Case 7
                Return "STOP_SMEL"
            Case 8
                Return "STOP_USER_EMG"
            Case 9
                Return "STOP_USER"
            Case 10
                Return "STOP_GAN_L1"
            Case 11
                Return "STOP_GAN_L2"
            Case 12
                Return "STOP_GEAR_SLAVE"
            Case 13
                Return "STOP_ERROR_LEVEL"
            Case 20
                Return "STOP_ORG_EL"
            Case 21
                Return "STOP_NO_ORG"
            Case 22
                Return "STOP_NO_EZ"
            Case 23
                Return "STOP_BOTH_EL"
            Case Else
                Return "Unknown stop code!"
        End Select
    End Function

    Public Sub home_move_example(ByVal Axis_ID As Integer)
        '//This example shows how home move operation
        Dim axis_id_sub As Integer = Axis_ID
        Dim return_code As Integer

        '// 1. Select home mode and config home parameters 
        APS_set_axis_param(axis_id_sub, PRA_HOME_MODE, 0) '// Set home mode
        APS_set_axis_param(axis_id_sub, PRA_HOME_DIR, 1) '// Set home direction
        APS_set_axis_param_f(axis_id_sub, PRA_HOME_CURVE, 0) '// Set acceleration paten (T-curve)
        APS_set_axis_param_f(axis_id_sub, PRA_HOME_ACC, 1000000) '// Set homing acceleration rate
        APS_set_axis_param_f(axis_id_sub, PRA_HOME_VM, 100000) '// Set homing maximum velocity.
        APS_set_axis_param_f(axis_id_sub, PRA_HOME_VO, 50000) '// Set homing VO speed
        APS_set_axis_param(axis_id_sub, PRA_HOME_EZA, 0) '// Set EZ signal alignment (yes or no)
        APS_set_axis_param_f(axis_id_sub, PRA_HOME_SHIFT, 0) '// Set home position shfit distance. 
        APS_set_axis_param_f(axis_id_sub, PRA_HOME_POS, 0) '// Set final home position.

        '//Check servo on or not
        If (Not ((APS_motion_io_status(axis_id_sub) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(axis_id_sub, 1)
            Thread.Sleep(500)

        End If

        '// 2. Start home move
        return_code = APS_home_move(Axis_ID) '//Start homing 
        If (return_code <> ERR_NoError) Then
            '/* Error handling */ 
        End If

    End Sub

    Public Sub velocity_move_example(ByVal Axis_ID As Integer)

        Dim axis_id_sub As Integer = Axis_ID
        Dim speed_1 As Double = 500.0
        Dim speed_2 As Double = 1000.0
        Dim speed_3 As Double = 600.0

        APS_set_axis_param_f(axis_id_sub, PRA_STP_DEC, 10000.0)
        APS_set_axis_param_f(axis_id_sub, PRA_CURVE, 0.5) '//Set acceleration rate
        APS_set_axis_param_f(axis_id_sub, PRA_ACC, 10000.0) '//Set acceleration rate
        APS_set_axis_param_f(axis_id_sub, PRA_DEC, 10000.0) '//Set deceleration rate

        '//Check servo on or not
        If (Not ((APS_motion_io_status(axis_id_sub) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(axis_id_sub, 1)
            Thread.Sleep(500) '// Wait stable.

        End If

        Dim wait As ASYNCALL
        wait.h_event = 0
        wait.i32_ret = 0
        APS_vel(axis_id_sub, 0, speed_1, Nothing) '// Start a velocity move
        '// Thread.Sleep( 2000 ) '// Wait 2 second

        '// APS_vel( axis_id_sub, 0, speed_2, 0 ) '// Change speed on the fly
        '// Thread.Sleep( 2000 ) '// Wait 2 second

        '// APS_vel( axis_id_sub, 0, speed_3, 0 ) '// Change speed on the fly
        '// Thread.Sleep( 2000 ) '// Wait 2 second

        '// APS_stop_move( axis_id ) '// Stop
    End Sub

    Public Sub jog_move_continuous_mode_example(ByVal Axis_ID As Integer)

        APS_set_axis_param(Axis_ID, PRA_JG_MODE, 0) '// Set jog mode
        APS_set_axis_param(Axis_ID, PRA_JG_DIR, 0) '// Set jog direction

        APS_set_axis_param_f(Axis_ID, PRA_JG_CURVE, 0.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_ACC, 1000.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_DEC, 1000.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_VM, 100.0)

        '//Check servo on or not
        If (Not ((APS_motion_io_status(Axis_ID) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(Axis_ID, 1)
            Thread.Sleep(500) '// Wait stable.

        End If

        '// Create a rising edge.
        APS_jog_start(Axis_ID, 0) '//Jog Off
        APS_jog_start(Axis_ID, 1) '//Jog ON

        '// Thread.Sleep( 200 )

        '// APS_jog_start( I32 Axis_ID, I32 On ) '// Jog off

    End Sub

    Public Sub jog_move_step_mode_example(ByVal Axis_ID As Integer)

        APS_set_axis_param(Axis_ID, PRA_JG_MODE, 0) '// Set jog mode
        APS_set_axis_param(Axis_ID, PRA_JG_DIR, 0) '// Set jog direction

        APS_set_axis_param_f(Axis_ID, PRA_JG_CURVE, 0.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_ACC, 1000.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_DEC, 1000.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_VM, 100.0)

        APS_set_axis_param_f(Axis_ID, PRA_JG_STEP, 1000.0)
        APS_set_axis_param(Axis_ID, PRA_JG_DELAY, 5000)

        '//Check servo on or not
        If (Not ((APS_motion_io_status(Axis_ID) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(Axis_ID, 1)
            Thread.Sleep(500) '// Wait stable.
        End If

        '// Create a rising edge.
        APS_jog_start(Axis_ID, 0) '//Jog Off
        APS_jog_start(Axis_ID, 1) '//Jog ON

    End Sub

    Public Sub jog_move_via_DI_example(ByVal Axis_ID As Integer)

        APS_set_axis_param(Axis_ID, PRA_JG_MODE, 0) '// Set jog mode
        APS_set_axis_param(Axis_ID, PRA_JG_DIR, 0) '// Set jog direction

        APS_set_axis_param_f(Axis_ID, PRA_JG_CURVE, 0.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_ACC, 1000.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_DEC, 1000.0)
        APS_set_axis_param_f(Axis_ID, PRA_JG_VM, 100.0)

        APS_set_axis_param(Axis_ID, PRA_JG_MAP_DI_EN, &H3S) '// Enable positive DI and negative DI
        APS_set_axis_param(Axis_ID, PRA_JG_P_JOG_DI, 0) '// Define DI ch0 for positive jog signal
        APS_set_axis_param(Axis_ID, PRA_JG_N_JOG_DI, 1) '// Define DI ch1 for negative jog signal
    End Sub

    Public Sub p2p_example(ByVal Axis_ID As Integer)

        '// Config speed profile parameters.
        APS_set_axis_param_f(Axis_ID, PRA_SF, 0.5)
        APS_set_axis_param_f(Axis_ID, PRA_ACC, 10000.0)
        APS_set_axis_param_f(Axis_ID, PRA_DEC, 10000.0)
        APS_set_axis_param_f(Axis_ID, PRA_VM, 1000.0)

        '//Check servo on or not
        If (Not ((APS_motion_io_status(Axis_ID) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(Axis_ID, 1)
            Thread.Sleep(500) '// Wait stable.
        End If

        '// Start a relative p to p move
        APS_ptp(Axis_ID, OPT_RELATIVE, 1000.0, Nothing)



        '// Method 2, ptp move with maximum velocity.
        'APS_ptp_v(Axis_ID, OPT_RELATIVE, 500.0, 1000.0, Nothing)

        '// Method 3, ptp move with all speed parameters.
        'APS_ptp_all(Axis_ID, OPT_RELATIVE, 500.0, 0.0, 1000.0, 0.0, 10000.0, 10000.0, 0.5, Nothing)

    End Sub

    Public Sub deceleration_stop_example(ByVal Axis_ID As Integer)
        APS_set_axis_param_f(Axis_ID, PRA_STP_DEC, 10000.0)
        APS_stop_move(Axis_ID)

    End Sub

    Public Sub emg_stop_example(ByVal Axis_ID As Integer)
        '// Stop immediately
        APS_emg_stop(Axis_ID)

    End Sub

    Public Sub interpolation_2D_line_example(ByVal Axis_ID_Array() As Integer)

        Dim PositionArray(2) As Double
        PositionArray(0) = 1000.0
        PositionArray(1) = 2000.0
        Dim TransPara As Double = 0

        '// config speed profile
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_SF, 0.5)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_ACC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_DEC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_VM, 1000.0)

        '//Check servo on or not
        If (Not ((APS_motion_io_status(Axis_ID_Array(0)) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(Axis_ID_Array(0), 1)
            Thread.Sleep(500) '// Wait stable.
        End If

        '//Check servo on or not
        If (Not ((APS_motion_io_status(Axis_ID_Array(1)) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(Axis_ID_Array(1), 1)
            Thread.Sleep(500) '// Wait stable.
        End If

        '// Start a 2 dimension linear interpolation
        APS_line(2, Axis_ID_Array, OPT_RELATIVE, PositionArray, TransPara, Nothing)

    End Sub
    Public Sub point_table_2D_example(ByVal Board_ID As Integer, ByVal Axis_ID_Array() As Integer)

        Dim boardId As Integer = Board_ID
        Dim ptbId As Integer = 0
        Dim dimension As Integer = 2
        Dim doOn As Integer = 0
        Dim doOff As Integer = 1
        Dim i As Integer = 0
        Dim doChannel As Integer = 0
        Dim Status As PTSTS
        Dim Line As PTLINE
        Dim Arc2 As PTA2CA



        'Check servo on 
        For i = 0 To (dimension - 1)
            APS_set_servo_on(Axis_ID_Array(i), 1)
        Next

        'Enable point table
        APS_pt_disable(boardId, ptbId)
        APS_pt_enable(boardId, ptbId, dimension, Axis_ID_Array)

        'Configuration
        APS_pt_set_absolute(boardId, ptbId)       'Set to absolute mode
        APS_pt_set_trans_buffered(boardId, ptbId) 'Set to buffer mode
        APS_pt_set_acc(boardId, ptbId, 10000)     'Set acc
        APS_pt_set_dec(boardId, ptbId, 10000)     'Set dec

        'Get status
        'BitSts;	
        'b0: Is PTB work? [1:working, 0:Stopped]
        'b1: Is point buffer full? [1:full, 0:not full]
        'b2: Is point buffer empty? [1:empty, 0:not empty]
        'b3~b5: reserved
        APS_get_pt_status(boardId, ptbId, Status)

        'Buffer is not Full
        If (Not (Status.BitSts And 2)) Then

            'Set 1st move profile
            APS_pt_set_vm(boardId, ptbId, 10000)
            APS_pt_set_ve(boardId, ptbId, 5000)

            'Set do command to sync with 1st point
            APS_pt_ext_set_do_ch(boardId, ptbId, doChannel, doOn)

            'Set pt arc data
            Arc2.Center_0 = 0
            Arc2.Center_1 = 5000
            Arc2.Angle = -180.0 * 3.14159265 / 100.0
            Arc2.Index_0 = 0
            Arc2.Index_1 = 1

            'Push 1st point to buffe
            APS_pt_arc2_ca(boardId, ptbId, Arc2, Status)

        End If

        'Get status
        APS_get_pt_status(boardId, ptbId, Status)

        If (Not (Status.BitSts And 2)) Then

            'Set 2nd move profile
            APS_pt_set_vm(boardId, ptbId, 12000)
            APS_pt_set_ve(boardId, ptbId, 6000)

            'Set do command to sync with 2nd point
            APS_pt_ext_set_do_ch(boardId, ptbId, doChannel, doOff)

            'Set pt line data
            Line.Dimension = 2
            Line.Pos_0 = 10000.0
            Line.Pos_1 = 10000.0

            'Push 2nd point to buffer
            APS_pt_line(boardId, ptbId, Line, Status)
        End If

        'Get status
        APS_get_pt_status(boardId, ptbId, Status)
        If (Not (Status.BitSts And 2)) Then

            'Set 3rd move profile
            APS_pt_set_vm(boardId, ptbId, 10000)
            APS_pt_set_ve(boardId, ptbId, 5000)

            'Set do command to sync with 3rd point
            APS_pt_ext_set_do_ch(boardId, ptbId, doChannel, doOn)

            'Set pt arc data
            Arc2.Center_0 = 10000
            Arc2.Center_1 = 5000
            Arc2.Angle = 180 * 3.14159265 / 100.0
            Arc2.Index_0 = 0
            Arc2.Index_1 = 1

            'Push 3rd point to buffer
            APS_pt_arc2_ca(boardId, ptbId, Arc2, Status)
        End If

        'Get status
        APS_get_pt_status(boardId, ptbId, Status)

        If (Not (Status.BitSts And 2)) Then

            'Set 4th move profile
            APS_pt_set_vm(boardId, ptbId, 12000)
            APS_pt_set_ve(boardId, ptbId, 500)

            'Set do command to sync with 4th point
            APS_pt_ext_set_do_ch(boardId, ptbId, doChannel, doOff)

            'Set pt line data
            Line.Dimension = 2
            Line.Pos_0 = 0.0
            Line.Pos_1 = 0.0

            'Push 4th point to buffer
            APS_pt_line(boardId, ptbId, Line, Status)
        End If

        APS_pt_start(boardId, ptbId)

    End Sub

    Public Sub interpolation_2D_arc_example(ByVal Axis_ID_Array() As Integer)

        Dim CenterArray(2) As Double
        CenterArray(0) = 1000.0
        CenterArray(1) = 0.0
        Dim Angle As Double = __TO_RADIAN(90.0)
        Dim TransPara As Double = 0

        '// config speed profile
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_SF, 0.5)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_ACC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_DEC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_VM, 1000.0)

        '//Check servo on or not
        If (Not ((APS_motion_io_status(Axis_ID_Array(0)) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(Axis_ID_Array(0), 1)
            Thread.Sleep(500) '// Wait stable.
        End If

        '//Check servo on or not
        If (Not ((APS_motion_io_status(Axis_ID_Array(1)) >> MIO_SVON) And 1)) Then

            APS_set_servo_on(Axis_ID_Array(1), 1)
            Thread.Sleep(500) '// Wait stable.
        End If

        '// Start a 2 dimension linear interpolation
        APS_arc2_ca(Axis_ID_Array, OPT_RELATIVE, CenterArray, Angle, TransPara, Nothing)

    End Sub

    Public Function __TO_RADIAN(ByVal _x_ As Double) As Double
        Return ((_x_) * 3.14159265 / 180.0)
    End Function

    Public Sub interpolation_3D_arc_example(ByVal Axis_ID_Array() As Integer)

        Dim CenterArray(3) As Double
        CenterArray(0) = 1000.0
        CenterArray(1) = 1000.0
        CenterArray(2) = 0
        Dim EndArray(3) As Double
        EndArray(0) = 1000.0
        EndArray(1) = 1000.0
        EndArray(2) = 1000.0 * Math.Sqrt(2)
        Dim Dir As Short = 0
        Dim TransPara As Double = 0
        Dim i As Integer

        '// config speed profile
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_SF, 0.5)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_ACC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_DEC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_VM, 2000.0)

        '//Check servo on or not
        For i = 0 To 2

            If (Not ((APS_motion_io_status(Axis_ID_Array(i)) >> MIO_SVON) And 1)) Then
                APS_set_servo_on(Axis_ID_Array(i), 1)
            End If
        Next
        Thread.Sleep(500) ' // Wait stable.

        APS_arc3_ce(Axis_ID_Array, OPT_RELATIVE, CenterArray, EndArray, Dir, TransPara, Nothing)

    End Sub

    Public Sub interpolation_3D_helical_example(ByVal Axis_ID_Array() As Integer)

        Dim CenterArray(3) As Double
        CenterArray(0) = 1000.0
        CenterArray(1) = 1000.0
        CenterArray(2) = 0
        Dim NormalArray(3) As Double
        NormalArray(0) = 0
        NormalArray(1) = 0
        NormalArray(2) = 1
        Dim Angle As Double = __TO_RADIAN(720.0)
        Dim DeltaH As Double = 500.0
        Dim FinalR As Double = 200.0
        Dim TransPara As Double = 0
        Dim i As Integer

        '// config speed profile
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_SF, 0.5)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_ACC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_DEC, 10000.0)
        APS_set_axis_param_f(Axis_ID_Array(0), PRA_VM, 2000.0)

        '//Check servo on or not
        For i = 0 To 3
            If (Not ((APS_motion_io_status(Axis_ID_Array(i)) >> MIO_SVON) And 1)) Then
                APS_set_servo_on(Axis_ID_Array(i), 1)
            End If
	    next
        Thread.Sleep(500) '// Wait stable.

        APS_spiral_ca(Axis_ID_Array, OPT_RELATIVE, CenterArray, NormalArray, Angle, DeltaH, FinalR, TransPara, Nothing)

    End Sub

    Public Sub contour_2D_example(ByVal Axis_ID_Array() As Integer)

        Dim i As Integer
        Dim TransPara As Double = 0
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
            If (Not ((APS_motion_io_status(Axis_ID_Array(i)) >> MIO_SVON) And 1)) Then
                APS_set_servo_on(Axis_ID_Array(i), 1)
            End If
        Next
        Thread.Sleep(500) '// Wait stable.

        '// Execute 4 interpolation move useing bufferd mode. Note option using "ITP_OPT_BUFFERED"

        APS_line_all(2, Axis_ID_Array, (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), PositionArray, TransPara _
         , 0.0, 1000.0, 1000.0, 10000.0, 10000.0, 0.0, Nothing)


        APS_arc2_ce_all(Axis_ID_Array, (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), CenterArray, EndArray, 0, TransPara _
            , 1000.0, 1000.0, 1000.0, 10000.0, 10000.0, 0.0, Nothing)

        APS_line_all(2, Axis_ID_Array, (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), PositionArray_2, TransPara _
        , 1000.0, 1000.0, 1000.0, 10000.0, 10000.0, 0.0, Nothing)

        APS_arc2_ce_all(Axis_ID_Array, (OPT_ABSOLUTE Or ITP_OPT_BUFFERED), CenterArray_2, EndArray_2, 0, TransPara _
         , 1000.0, 1000.0, 0.0, 10000.0, 10000.0, 0.0, Nothing)


    End Sub

    Public Function interrupt_example(ByVal Board_ID As Integer, ByVal Axis_num As Integer) As Integer

        '// This example shows how interrupt functions work.
        Dim board_id_sub As Integer = Board_ID
        Dim int_no As Integer '// Interrupt number
        Dim return_code As Integer '// function return code
        Dim item As Integer = Axis_num '// Axis #? interrupt
        Dim factor As Integer = 12 '// factor number = 12 IMDN interrupt

        '// Step 1: set interrupt factor ( factor = IMDN )
        '// 設定要等待的中斷事件
        int_no = APS_set_int_factor(Board_ID, item, factor, 1)

        '// Step 2: set interrupt main switch 
        '// 設定中斷總開關
        APS_int_enable(Board_ID, 1) '// Enable the interrupt main switch

        '// Step 3: wait interrupt.
        '// 等待中斷觸發
        return_code = APS_wait_single_int(int_no, -1) '//Wait interrupt

        If return_code = ERR_NoError Then
            '//Interrupt occurred	
            '//Step 4: 重置中斷為為觸發狀態
            APS_reset_int(int_no)
        End If

        '// Step 5: Disable interrupt at the end of program.
        '// 關閉中斷事件和中斷總開關
        APS_set_int_factor(Board_ID, item, factor, 0)
        APS_int_enable(Board_ID, 0)

        Return return_code
    End Function

    Public Sub DIO_sample(ByVal Board_ID As Integer)

        Dim digital_output_value As Integer = 0
        Dim digital_input_value As Integer = 0
        Dim do_ch(__MAX_DO_CH) As Integer
        Dim di_ch(__MAX_DI_CH) As Integer
        Dim i As Integer

        '//****** Read digital output channels *****************************
        APS_read_d_output(Board_ID, 0, digital_output_value)

        For i = 0 To (__MAX_DO_CH - 1)
            do_ch(i) = ((digital_output_value >> i) And 1)
        Next
        '//************ Write digital output channels examples *************
        do_ch(0) = 1 '// set 0 or 1
        do_ch(2) = 1 '// set 0 or 1
        do_ch(4) = 1 '// set 0 or 1

        digital_output_value = 0
        For i = 0 To (__MAX_DO_CH - 1)
            digital_output_value = (digital_output_value) Or (do_ch(i) << i)
        Next

        APS_write_d_output(Board_ID, 0, digital_output_value)
        '//*******************************************************************

        '//**** Read digital input channels **********************************
        APS_read_d_input(Board_ID, 0, digital_input_value)

        For i = 0 To (__MAX_DI_CH - 1)
            di_ch(i) = ((digital_input_value >> i) And 1)
        Next
        '//********************************************************************
    End Sub


    Public Sub AIO_sample(ByVal Board_ID As Integer)

        Dim Channel_No As Integer = 0
        Dim analog_input_volt As Double
        Dim analog_output_volt As Double

        APS_read_a_input_value(Board_ID, Channel_No, analog_input_volt)

        analog_output_volt = 1.5 '// 1.5 volt
        APS_write_a_output_value(Board_ID, Channel_No, analog_output_volt)
        APS_read_a_output_value(Board_ID, Channel_No, analog_output_volt)
    End Sub

    Public Sub E_Gear_example(ByVal Axis_ID_Array() As Integer)

        Dim masterAxis As Integer = Axis_ID_Array(0)
        Dim slaveAxis As Integer = Axis_ID_Array(1)
        Dim i As Integer = 0
        Dim status As Integer = 0
        Dim ret As Integer = 0
        Dim Wait As APS168.ASYNCALL



        
        'Servo On 
        ret = APS_set_servo_on(masterAxis, 1)
        ret = APS_set_servo_on(slaveAxis, 1)

        'Wait for stable.
        Thread.Sleep(1)

        'Get status of gear applicaiton.
        'Gear status:
        ' 0: In disabling status.
        ' 1: In enabling status of standard mode.
        ' 2: In enabling status of gantry mode.
        ret = APS_get_gear_status(slaveAxis, status)


        If status = 0 Then

            'Select axis 0 position command to be axis 1's master
            ret = APS_set_axis_param(slaveAxis, PRA_GEAR_MASTER, 0)

            'Set Gear engage rate
            ret = APS_set_axis_param_f(slaveAxis, PRA_GEAR_ENGAGE_RATE, 10000.0)

            'set Gear ratio
            ret = APS_set_axis_param_f(slaveAxis, PRA_GEAR_RATIO, 2.0)

            'Set E-gear gantry mode protection level 1
            ret = APS_set_axis_param_f(slaveAxis, PRA_GANTRY_PROTECT_1, 10000.0)

            ''Set E-gear gantry mode protection level 2
            ret = APS_set_axis_param_f(slaveAxis, PRA_GANTRY_PROTECT_2, 20000.0)

            'Set to Standard mode (0: Disable, 1: Standard mode, 2: Gantry mode.)
            ret = APS_start_gear(slaveAxis, 1)

        End If


        'Start master axis relative p to p move
        ret = APS_ptp(masterAxis, OPT_RELATIVE, 1000.0, Wait)

        'Wait for motion done
        Thread.Sleep(1200)

        'Disable Standard mode (0: Disable, 1: Standard mode, 2: Gantry mode.)
        ret = APS_start_gear(slaveAxis, 0)


        

    End Sub

    Public Sub PWM_example(ByVal v_card_id As Integer, ByVal channel As Integer)

        Dim ret As Integer = 0
        Dim Board_ID As Integer = v_card_id
        Dim CH As Integer = 0               'Range is from 0 to 1
        Dim Frequency As Integer = 1000     'Unit: Hz. Range is from 3 to 50000000.
        Dim Width As Integer = 1000         'Unit: ns. Range is from 20 to 335544300.



        'Disable all PWM signals. 
        For CH = 0 To 3
            ret = APS_set_pwm_on(Board_ID, CH, 0)
        Next

        'Set PWM parameters
        For CH = 0 To (channel - 1)
            ret = APS_set_pwm_frequency(Board_ID, CH, Frequency)
            ret = APS_set_pwm_width(Board_ID, CH, Width)
        Next

        'Wait for stable.
        Thread.Sleep(1)

        'Note:
        'The PWM output (TG) is used by two function APIs, that are APS_set_pwm_on() and APS_start_vao(). 
        'Don() 't use them at the same time.
        'Be sure that only one of them is enabled, specified PWM channel could rightly work. 

        'start output PWM signal.
        For CH = 0 To (channel - 1)
            ret = APS_set_pwm_on(Board_ID, CH, 1)
        Next

        'Wait about 1 sec to show PWM signal (about 1000 periods).
        Thread.Sleep(1000)

        'Disable all PWM signals. 
        For CH = 0 To (channel - 1)
            ret = APS_set_pwm_on(Board_ID, CH, 0)
        Next

    End Sub


End Module
