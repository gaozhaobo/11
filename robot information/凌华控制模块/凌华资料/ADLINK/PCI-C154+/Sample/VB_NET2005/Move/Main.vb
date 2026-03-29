Option Strict Off
Option Explicit On
Friend Class MainForm
	Inherits System.Windows.Forms.Form

	Dim BusNo As Integer 'Bus number for setting,  Motion Net BusNo is 0.
	Dim MOD_No As Integer 'Arrcoding switch On Module.
    Dim AxisID_SingleAxis_ForAbsolute As Integer
	Dim AxisID_SingleAxis_ForRelative As Integer
	Dim AxisID_SingleAxis_ForHome As Integer
	Dim AxisID_FirstAxis_For_PointTable As Integer
	Dim Dimension_For_PointTable As Integer
    Dim Axis_ID_Array_For_2Axes_Move(2) As Integer
    Dim Axis_ID_Array_For_2Axes_ArcMove(2) As Integer
	Dim Axis_ID_Array_For_3Axes_Move(3) As Integer
    Dim Axis_ID_Array_For_4Axes_Move(3) As Integer
    Dim Axis_ID_Array_For_PointTable(3) As Integer

    Dim CardID As Integer
    Dim TotalCard As Long
    Dim Start_Axis_ID As Integer

	'
	Dim FunctionFail As Boolean
    Dim CurrectSelAxis As Integer
	
	Private Sub Function_Result(ByRef Ret As Integer)
		If (Ret <> 0) Then
			MsgBox("Function Fail, ErrorCode  " & CStr(Ret))
            FunctionFail = True
        Else
            FunctionFail = False
        End If
	End Sub
	Private Sub Command1_Click()
		
	End Sub
	
	Private Sub Btn_Linear_2Axes_AbsoluteBackward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_2Axes_AbsoluteBackward.Click
		Dim Dimension As Integer
        Dim Position_Array(2) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 2
        Position_Array(0) = -10000
        Position_Array(1) = -20000

		Max_Linear_Speed = 50000

        Function_Result((APS_absolute_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_2Axes_AbsoluteForward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_2Axes_AbsoluteForward.Click
		Dim Dimension As Integer
        Dim Position_Array(2) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 2
        Position_Array(0) = 10000
        Position_Array(1) = 20000

		Max_Linear_Speed = 50000

        Function_Result((APS_absolute_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_2Axes_AbsoluteStop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_2Axes_AbsoluteStop.Click
		Function_Result(((APS_emg_stop(Axis_ID_Array_For_2Axes_Move(0)))))
	End Sub
	
	Private Sub Btn_Linear_2Axes_Relateive_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_2Axes_Relateive_Stop.Click
		Function_Result((APS_emg_stop(Axis_ID_Array_For_2Axes_Move(0))))
	End Sub
	
	Private Sub Btn_Linear_2Axes_RelateiveBackward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_2Axes_RelateiveBackward.Click
		Dim Dimension As Integer
        Dim Position_Array(2) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 2
        Position_Array(0) = -10000
        Position_Array(1) = -20000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_2Axes_RelateiveForward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_2Axes_RelateiveForward.Click
		Dim Dimension As Integer
        Dim Position_Array(2) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 2
        Position_Array(0) = 10000
        Position_Array(1) = 20000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_3Axes_AbsoluteBackward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_3Axes_AbsoluteBackward.Click
		Dim Dimension As Integer
        Dim Position_Array(3) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 3
        Position_Array(0) = -10000
        Position_Array(1) = -20000
        Position_Array(2) = -30000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_absolute_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_3Axes_AbsoluteForward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_3Axes_AbsoluteForward.Click
		Dim Dimension As Integer
        Dim Position_Array(3) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 3
        Position_Array(0) = 10000
        Position_Array(1) = 20000
        Position_Array(2) = 30000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_absolute_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_3Axes_AbsoluteStop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_3Axes_AbsoluteStop.Click
		Function_Result((APS_emg_stop(Axis_ID_Array_For_3Axes_Move(0))))
	End Sub
	
	Private Sub Btn_Linear_3Axes_Relateive_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_3Axes_Relateive_Stop.Click
		Function_Result((APS_emg_stop(Axis_ID_Array_For_3Axes_Move(0))))
	End Sub
	
	Private Sub Btn_Linear_3Axes_RelateiveBackward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_3Axes_RelateiveBackward.Click
		Dim Dimension As Integer
        Dim Position_Array(3) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 3
        Position_Array(0) = -10000
        Position_Array(1) = -20000
        Position_Array(2) = -30000

        Max_Linear_Speed = 50000
		
        Function_Result((APS_relative_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_3Axes_RelateiveForward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_3Axes_RelateiveForward.Click
		Dim Dimension As Integer
        Dim Position_Array(3) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 3
        Position_Array(0) = 10000
        Position_Array(1) = 20000
        Position_Array(2) = 30000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_relative_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_4Axes_AbsoluteBackward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_4Axes_AbsoluteBackward.Click
		Dim Dimension As Integer
        Dim Position_Array(4) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 4
        Position_Array(0) = -10000
        Position_Array(1) = -20000
        Position_Array(2) = -30000
        Position_Array(3) = -40000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_4Axes_AbsoluteForward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_4Axes_AbsoluteForward.Click
		Dim Dimension As Integer
        Dim Position_Array(4) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 4
        Position_Array(0) = 10000
        Position_Array(1) = 20000
        Position_Array(2) = 30000
        Position_Array(3) = 40000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_4Axes_AbsoluteStop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_4Axes_AbsoluteStop.Click
		Function_Result((APS_emg_stop(Axis_ID_Array_For_4Axes_Move(0))))
	End Sub
	
	Private Sub Btn_Linear_4Axes_Relateive_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_4Axes_Relateive_Stop.Click
		Function_Result((APS_emg_stop(Axis_ID_Array_For_4Axes_Move(0))))
	End Sub
	
	Private Sub Btn_Linear_4Axes_RelateiveBackward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_4Axes_RelateiveBackward.Click
		Dim Dimension As Integer
        Dim Position_Array(4) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 4
        Position_Array(0) = -10000
        Position_Array(1) = -20000
        Position_Array(2) = -30000
        Position_Array(3) = -40000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_4Axes_RelateiveForward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_4Axes_RelateiveForward.Click
		Dim Dimension As Integer
        Dim Position_Array(4) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 4
        Position_Array(0) = 10000
        Position_Array(1) = 20000
        Position_Array(2) = 30000
        Position_Array(3) = 40000

		Max_Linear_Speed = 50000

		
        Function_Result((APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub

    Private Sub Btn_ResetCounter_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_ResetCounter.Click

        Dim LastIndex As Integer
        Dim AxisNo As Integer
        LastIndex = 4

        For AxisNo = Start_Axis_ID To Start_Axis_ID + 3

            Function_Result((APS_set_command(AxisNo, 0)))
            Function_Result((APS_set_position(AxisNo, 0)))

        Next AxisNo

    End Sub
	
   
	
	Private Sub Btn_SingleAbsoluteMove_Backward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleAbsoluteMove_Backward.Click
		Dim Position As Integer
		Dim Max_Speed As Integer
		
		Position = -10000
		Max_Speed = 50000

		
		Function_Result(((APS_absolute_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleAbsoluteMove_Forward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleAbsoluteMove_Forward.Click
		Dim Position As Integer
		Dim Max_Speed As Integer
		
		Position = 10000
        Max_Speed = 50000
		Function_Result(((APS_absolute_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleAbsoluteMove_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleAbsoluteMove_Stop.Click
		Function_Result((APS_emg_stop(AxisID_SingleAxis_ForAbsolute)))
	End Sub
	
	Private Sub Btn_SingleHomeMove_Backward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleHomeMove_Backward.Click
		Function_Result((APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1))) 'Set PRA_HOME_DIR   0:Positive 1:Negative
        Function_Result((APS_home_move(AxisID_SingleAxis_ForHome)))
	End Sub
	
	Private Sub Btn_SingleHomeMove_Forward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleHomeMove_Forward.Click
		Function_Result((APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0))) 'Set PRA_HOME_DIR   0:Positive 1:Negative
        Function_Result((APS_home_move(AxisID_SingleAxis_ForHome)))
	End Sub
	
	Private Sub Btn_SingleHomeMove_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleHomeMove_Stop.Click
		Function_Result((APS_emg_stop(AxisID_SingleAxis_ForHome)))
	End Sub
	
	Private Sub Btn_SingleRelativeMove_Backward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleRelativeMove_Backward.Click
		Dim Position As Integer
		Dim Max_Speed As Integer
		
		Position = -10000
        Max_Speed = 50000
        Function_Result(((APS_relative_move(AxisID_SingleAxis_ForRelative, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleRelativeMove_Forward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleRelativeMove_Forward.Click
		Dim Position As Integer
		Dim Max_Speed As Integer
		
		Position = 10000
        Max_Speed = 50000
        Function_Result(((APS_relative_move(AxisID_SingleAxis_ForRelative, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleRelativeMove_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleRelativeMove_Stop.Click
		Function_Result((APS_emg_stop(AxisID_SingleAxis_ForRelative)))
	End Sub
		
	Private Sub MainForm_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load


        BusNo = 1 'Bus number for setting,  Motion Net BusNo is 0.
        MOD_No = 7


        CardID = 0
        Start_Axis_ID = 0

        AxisID_SingleAxis_ForAbsolute = Start_Axis_ID
        AxisID_SingleAxis_ForRelative = Start_Axis_ID
        AxisID_SingleAxis_ForHome = Start_Axis_ID

        Axis_ID_Array_For_2Axes_Move(0) = Start_Axis_ID
        Axis_ID_Array_For_2Axes_Move(1) = Start_Axis_ID + 1

        Axis_ID_Array_For_2Axes_ArcMove(0) = Start_Axis_ID
        Axis_ID_Array_For_2Axes_ArcMove(1) = Start_Axis_ID + 1
		
        Axis_ID_Array_For_3Axes_Move(0) = Start_Axis_ID
        Axis_ID_Array_For_3Axes_Move(1) = Start_Axis_ID + 1
        Axis_ID_Array_For_3Axes_Move(2) = Start_Axis_ID + 2
		
        Axis_ID_Array_For_4Axes_Move(0) = Start_Axis_ID
        Axis_ID_Array_For_4Axes_Move(1) = Start_Axis_ID + 1
        Axis_ID_Array_For_4Axes_Move(2) = Start_Axis_ID + 2
        Axis_ID_Array_For_4Axes_Move(3) = Start_Axis_ID + 3
		
        
		
		FunctionFail = False
		
		'Initial+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        Dim DPAC_ID_Bits As Integer
        Dim AxisNo As Long
        Dim Info As Integer
        Dim i, ret As Integer
        Dim card_name As Integer

        TotalCard = 0

        If (APS_initial(DPAC_ID_Bits, 0) = 0) Then 'Initial Card, CardID is assigned by system.


            For i = 0 To 15 Step 1
                If (DPAC_ID_Bits And (2 ^ i)) Then
                    APS_get_card_name(i, card_name)
                    If (card_name = DEVICE_NAME_PCI_C154_PLUS) Then
                        TotalCard = TotalCard + 1
                        Exit For
                    End If
                End If
            Next i


            'Get Card information
            Function_Result((APS_get_device_info(CardID, &H10S, Info))) 'Get Driver Version
            Edit_ShowMaster_DriverVer.Text = CStr(Info)

            Edit_ShowMaster_DLLVer.Text = CStr(APS_version) 'Get DLL Version

            Function_Result((APS_get_device_info(CardID, &H20S, Info))) 'Get CPLD Version
            Edit_ShowMaster_CPLDVer.Text = CStr(Info)


            '****************************************************************************************************************************
            For AxisNo = 0 To (4 * TotalCard - 1) Step 1

                Function_Result(APS_set_servo_on(AxisNo, 1))                  'servo ON

                Function_Result(APS_set_axis_param(AxisNo, 0, 0))             'PEL/MEL input logic
                Function_Result(APS_set_axis_param(AxisNo, 4, 0))             'Set PRA_ALM_LOGIC

                Function_Result(APS_set_axis_param(AxisNo, 128, 3))           'Set PRA_PLS_IPT_MODE(The user must make change based on actual conditions)
                Function_Result(APS_set_axis_param(AxisNo, 129, 4))           'Set PRA_PLS_OPT_MODE(The user must make change based on actual conditions)


                'Set Single Move Parameter
                Function_Result(APS_set_axis_param(AxisNo, 33, 1000000))      'Set Acceleration rate
                Function_Result(APS_set_axis_param(AxisNo, 34, 1000000))      'Set Deceleration rate
                Function_Result(APS_set_axis_param(AxisNo, 35, 0))            'Set Start velocity
                Function_Result(APS_set_axis_param(AxisNo, 32, 1))            'Set S-Curve


                'Set Home Move Parameter
                Function_Result(APS_set_axis_param(AxisNo, 16, 0))             'Set Home mode (Home search 1st mode)

                Function_Result(APS_set_axis_param(AxisNo, 21, 10000))         'Set Homing maximum Velocity (Unit:pulse/sec)

                Function_Result(APS_set_axis_param(AxisNo, 25, 152))           'Set Homing leave home Velocity (Unit:pulse/sec)

                Function_Result(APS_set_axis_param(AxisNo, 24, 0))             'Set Specify the EZ count up Value

                Function_Result(APS_set_axis_param(AxisNo, 26, 100))           'Set Homing leave home distance.Specify ORG Offset (Unit:pulse)


                'Set EMG logic
                Function_Result(APS_set_axis_param(AxisNo, 561, 0))   'Select gpio input
                'Function_Result(APS_set_axis_param(AxisNo, 562, 1))  'Set EMG logic (0:Active Low /1:Active High)

            Next AxisNo

            '*******************************************************************************************************************************
            MsgBox("Initial Success!!")

        Else

            MsgBox("Initial Fail, sample close!!", MsgBoxStyle.OkOnly)
            APS_close()

        End If
		'++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	End Sub
	
    Private Sub Timer1_Tick(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Timer1.Tick

        Dim Command_Renamed As Integer
        Dim Position As Integer
        Dim MotionSts As Integer
        Dim IoSts As Integer
        Dim Index As Integer
        

        For Index = 0 To 3

            'Motion Segment
            APS_get_command(Start_Axis_ID + Index, Command_Renamed)
            Edit_ShowAxis_Command(Index).Text = CStr(Command_Renamed)

            APS_get_position(Start_Axis_ID + Index, Position)
            Edit_ShowAxis_Feedback(Index).Text = CStr(Position)

            IoSts = APS_motion_io_status(Start_Axis_ID + Index)
            Edit_ShowAxis_IOSts(Index).Text = CStr(Hex(IoSts))

            MotionSts = APS_motion_status(Start_Axis_ID + Index)
            Edit_ShowAxis_MSts(Index).Text = CStr(Hex(MotionSts))

        Next Index

    End Sub

    Private Sub Btn_Arc_2Axes_Absolute_CCW_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Absolute_CCW.Click
        Dim Dimension As Long
        Dim Center_Pos_Array(2) As Integer
        Dim Max_Arc_Speed As Long
        Dim Angle As Long

        Dimension = 2
        Center_Pos_Array(0) = 20000
        Center_Pos_Array(1) = 20000

        Max_Arc_Speed = 50000
        Angle = 180


        Function_Result(APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle))
    End Sub

    Private Sub Btn_Arc_2Axes_Absolute_CW_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Absolute_CW.Click
        Dim Dimension As Long
        Dim Center_Pos_Array(2) As Integer
        Dim Max_Arc_Speed As Long
        Dim Angle As Long

        Dimension = 2
        Center_Pos_Array(0) = 20000
        Center_Pos_Array(1) = 20000

        Max_Arc_Speed = 50000
        Angle = (-180)


        Function_Result(APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle))
    End Sub

    Private Sub Btn_Arc_2Axes_Absolute_Stop2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Absolute_Stop2.Click
        Function_Result(APS_emg_stop(Axis_ID_Array_For_2Axes_ArcMove(0)))
    End Sub

    Private Sub Btn_Arc_2Axes_Relative_CCW_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Relative_CCW.Click
        Dim Dimension As Long
        Dim Center_Pos_Array(2) As Integer
        Dim Max_Arc_Speed As Long
        Dim Angle As Long

        Dimension = 2
        Center_Pos_Array(0) = 20000
        Center_Pos_Array(1) = 20000

        Max_Arc_Speed = 50000
        Angle = 180


        Function_Result(APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle))
    End Sub

    Private Sub Btn_Arc_2Axes_Relative_CW_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Relative_CW.Click
        Dim Dimension As Long
        Dim Center_Pos_Array(2) As Integer
        Dim Max_Arc_Speed As Long
        Dim Angle As Long

        Dimension = 2
        Center_Pos_Array(0) = 20000
        Center_Pos_Array(1) = 20000

        Max_Arc_Speed = 50000
        Angle = (-180)


        Function_Result(APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle))
    End Sub

    Private Sub Btn_Arc_2Axes_Relateive_Stop_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Relateive_Stop.Click
        Function_Result(APS_emg_stop(Axis_ID_Array_For_2Axes_ArcMove(0)))
    End Sub

    

    Private Sub Label26_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label26.Click

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click


        CardID = CLng(MaskedTextBox1.Text)

        Start_Axis_ID = CardID * 4



        AxisID_SingleAxis_ForAbsolute = Start_Axis_ID
        AxisID_SingleAxis_ForRelative = Start_Axis_ID
        AxisID_SingleAxis_ForHome = Start_Axis_ID

        Axis_ID_Array_For_2Axes_Move(0) = Start_Axis_ID
        Axis_ID_Array_For_2Axes_Move(1) = Start_Axis_ID + 1

        Axis_ID_Array_For_2Axes_ArcMove(0) = Start_Axis_ID
        Axis_ID_Array_For_2Axes_ArcMove(1) = Start_Axis_ID + 1

        Axis_ID_Array_For_3Axes_Move(0) = Start_Axis_ID
        Axis_ID_Array_For_3Axes_Move(1) = Start_Axis_ID + 1
        Axis_ID_Array_For_3Axes_Move(2) = Start_Axis_ID + 2

        Axis_ID_Array_For_4Axes_Move(0) = Start_Axis_ID
        Axis_ID_Array_For_4Axes_Move(1) = Start_Axis_ID + 1
        Axis_ID_Array_For_4Axes_Move(2) = Start_Axis_ID + 2
        Axis_ID_Array_For_4Axes_Move(3) = Start_Axis_ID + 3



    End Sub


End Class