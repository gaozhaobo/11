Option Strict Off
Option Explicit On
Imports System.Threading


Module Sample_code
    Const IDX_DLL = (0)
    Const IDX_SW = (1)
    Const IDX_MW = (2)
    Const IDX_EXE = (3)
    Const IDX_LIB = (4)
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

        '// Get FAMC SW version
        APS_get_device_info(Board_ID, &H0, Array_size_5(IDX_SW))

        '// Get FAMC MW version
        APS_get_device_info(Board_ID, &H1, Array_size_5(IDX_MW))

        '// Get FAMC Exe version
        APS_get_device_info(Board_ID, &H11, Array_size_5(IDX_EXE))

        '// Get FAMC Library version
        APS_get_device_info(Board_ID, &H100, Array_size_5(IDX_LIB))


    End Sub

    Public Sub get_axis_status_example(ByVal Axis_ID As Integer, ByRef P_Axis_status As AXIS_STATUS)

        APS_get_command(Axis_ID, P_Axis_status.command_position)
        APS_get_position(Axis_ID, P_Axis_status.feedback_position)
        APS_get_target_position(Axis_ID, P_Axis_status.target_position)
        APS_get_error_position(Axis_ID, P_Axis_status.error_position)
        APS_get_command_velocity(Axis_ID, P_Axis_status.command_velocity)
        APS_get_feedback_velocity(Axis_ID, P_Axis_status.feedback_velocity)

        P_Axis_status.motion_io = APS_motion_io_status(Axis_ID)
        P_Axis_status.motion_status = APS_motion_status(Axis_ID)

    End Sub

    Public Sub load_parameters_from_file_sample(ByVal FilePath)

        APS_load_param_from_file(FilePath)

    End Sub

    Public Sub home_move_example(ByVal Axis_ID As Integer)
        '//This example shows how home move operation
        Dim axis_id_sub As Integer = Axis_ID
        Dim return_code As Integer

        '// 1. Select home mode and config home parameters 
        APS_set_axis_param(axis_id_sub, PRA_HOME_MODE, 0) '// Set home mode
        APS_set_axis_param(axis_id_sub, PRA_HOME_DIR, 1) '// Set home direction
        APS_set_axis_param(axis_id_sub, PRA_HOME_ACC, 1000000) '// Set homing acceleration rate
        APS_set_axis_param(axis_id_sub, PRA_HOME_VM, 100000) '// Set homing maximum velocity.
        APS_set_axis_param(axis_id_sub, PRA_HOME_VO, 50000) '// Set homing VO speed
        APS_set_axis_param(axis_id_sub, PRA_HOME_EZA, 0) '// Set EZ signal alignment (yes or no)
        
        '//Check servo on or not
        If (((APS_motion_io_status(axis_id_sub) >> MIO_SVON) And 1) = 0) Then
            APS_set_servo_on(axis_id_sub, 1)
            Thread.Sleep(500)
        End If

        '// 2. Start home move
        return_code = APS_home_move(Axis_ID) '//Start homing 
        If (return_code <> ERR_NoError) Then
            Dim to_show As String
            to_show = "Error Code is " + CStr(return_code)
            MessageBox.Show(to_show, "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        End If

    End Sub

    Public Sub velocity_move_example(ByVal Axis_ID As Integer)

        Dim axis_id_sub As Integer = Axis_ID
        Dim speed_1 As Double = 500.0
        Dim speed_2 As Double = 1000.0
        Dim speed_3 As Double = 600.0

        APS_set_axis_param(axis_id_sub, PRA_ACC, 10000) '//Set acceleration rate
        APS_set_axis_param(axis_id_sub, PRA_DEC, 10000) '//Set deceleration rate

        '//Check servo on or not
        If (((APS_motion_io_status(axis_id_sub) >> MIO_SVON) And 1) = 0) Then

            APS_set_servo_on(axis_id_sub, 1)
            Thread.Sleep(500) '// Wait stable.

        End If

        Dim wait As ASYNCALL
        wait.h_event = 0
        wait.i32_ret = 0
        APS_velocity_move(axis_id_sub, 10000) '// Start a velocity move
        
    End Sub

    Public Sub jog_move_continuous_mode_example(ByVal Axis_ID As Integer)

        APS_set_axis_param(Axis_ID, PRA_JG_DIR, 0) '// Set jog direction
        APS_set_axis_param(Axis_ID, PRA_JG_ACC, 1000)
        APS_set_axis_param(Axis_ID, PRA_JG_DEC, 1000)
        APS_set_axis_param(Axis_ID, PRA_JG_VM, 100)

        '//Check servo on or not
        If (((APS_motion_io_status(Axis_ID) >> MIO_SVON) And 1) = 0) Then

            APS_set_servo_on(Axis_ID, 1)
            Thread.Sleep(500) '// Wait stable.

        End If
        APS_jog_start(Axis_ID, 1) '//Jog ON
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
        Dim ret As Integer = 0
        ret = APS_set_axis_param(Axis_ID, PRA_ACC, 10000.0)
        ret = APS_set_axis_param(Axis_ID, PRA_DEC, 10000.0)
        ret = APS_set_axis_param(Axis_ID, PRA_VM, 1000.0)

        '//Check servo on or not
        If (((APS_motion_io_status(Axis_ID) >> MIO_SVON) And 1) = 0) Then

            APS_set_servo_on(Axis_ID, 1)
            Thread.Sleep(500) '// Wait stable.
        End If

        '// Start a relative p to p move
        ret = APS_relative_move(Axis_ID, 30000, 5000)
    End Sub

    Public Sub deceleration_stop_example(ByVal Axis_ID As Integer)
        APS_set_axis_param_f(Axis_ID, PRA_STP_DEC, 10000.0)
        APS_stop_move(Axis_ID)

    End Sub

    Public Sub emg_stop_example(ByVal Axis_ID As Integer)
        '// Stop immediately
        APS_emg_stop(Axis_ID)

    End Sub

    Public Sub CMP_Trigger(ByVal Board_ID As Integer)
        Dim ret As Integer = 0
        ret = APS_set_trigger_param(Board_ID, &H0, 1) ' Set axis 0 to compare encoder or command position
        ret = APS_set_trigger_param(Board_ID, &H2, 2) ' Set axis 0 compare condition
        ret = APS_set_trigger_param(Board_ID, &H4, 100) ' Set axis 0 compare value
        ret = APS_set_trigger_param(Board_ID, &H6, 5) ' Set axis 0 output pulse width
        ret = APS_set_trigger_param(Board_ID, &H8, 0) '  Set axis 0 output negative pulse
        ret = APS_set_trigger_param(Board_ID, &HA, 1) '  Enable axis 0 compare trigger function; The output signal is generated via TRG1 pin when compare condition is true
    End Sub


    Public Sub DIO_sample(ByVal Board_ID As Integer)

        Dim digital_output_value As Integer = 0
        Dim digital_input_value As Integer = 0

        '****** Read digital output by group *****************************
        APS_read_d_output(Board_ID, 0, digital_output_value)
        APS_read_d_output(Board_ID, 1, digital_output_value)
        '****** Read digital output by group *****************************
        APS_read_d_input(Board_ID, 0, digital_input_value)
        APS_read_d_input(Board_ID, 1, digital_input_value)
        APS_read_d_input(Board_ID, 2, digital_input_value)
        APS_read_d_input(Board_ID, 3, digital_input_value)

        '************ Write digital output by group examples *************
        APS_write_d_output(Board_ID, 0, 255)
        APS_write_d_output(Board_ID, 1, 63)
        
    End Sub

End Module
