Option Strict Off
Option Explicit On
Friend Class MainForm
	Inherits System.Windows.Forms.Form
	Dim CardID As Integer 'Card number for setting.
	Dim BusNo As Integer 'Bus number for setting,  Motion Net BusNo is 0.
	Dim MOD_No As Integer 'Arrcoding switch On Module.
	Dim Start_Axis_ID As Integer 'First Axis number in Motion Net bus.
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
	
	Private Sub Btn_BusConnect_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_BusConnect.Click
        Dim AxisNo As Integer
        Function_Result((APS_start_field_bus(CardID, BusNo, Start_Axis_ID)))

        If FunctionFail = False Then
            'Set Axis Parameter
            For AxisNo = Start_Axis_ID To 3
                'IO and Pulse Mode
                Function_Result((APS_set_axis_param(AxisNo, PRA_ALM_LOGIC, 0))) 'Set PRA_ALM_LOGIC
                Function_Result((APS_set_axis_param(AxisNo, PRA_PLS_IPT_MODE, 2))) 'Set PRA_PLS_IPT_MODE
                Function_Result((APS_set_axis_param(AxisNo, PRA_PLS_OPT_MODE, 1))) 'Set PRA_PLS_OPT_MODE
                Function_Result((APS_set_axis_param(AxisNo, PRA_PLS_IPT_LOGIC, 1))) 'Set PRA_PLS_IPT_LOGIC
                Function_Result((APS_set_axis_param(AxisNo, PRA_FEEDBACK_SRC, 1))) 'Select feedback conter


                'Single Move Parameter
                Function_Result((APS_set_axis_param(AxisNo, PRA_CURVE, 0))) 'Set PRA_CURVE  0:T-Curve 1:S-Curve
                Function_Result((APS_set_axis_param(AxisNo, PRA_ACC, 10000000))) 'Set PRA_ACC
                Function_Result((APS_set_axis_param(AxisNo, PRA_DEC, 10000000))) 'Set PRA_DEC
                Function_Result((APS_set_axis_param(AxisNo, PRA_VS, 0))) 'Set PRA_VS


                'Home Move Parameter
                Function_Result((APS_set_axis_param(AxisNo, PRA_HOME_MODE, 0))) 'Set PRA_HOME_MODE
                Function_Result((APS_set_axis_param(AxisNo, PRA_HOME_DIR, 1))) 'Set PRA_HOME_DIR   0:Positive 1:Negative
                Function_Result((APS_set_axis_param(AxisNo, PRA_HOME_VM, 10000))) 'Set PRA_HOME_VM
                Function_Result((APS_set_axis_param(AxisNo, PRA_HOME_EZA, 0))) 'Set PRA_HOME_EZA
                Function_Result((APS_set_axis_param(AxisNo, PRA_HOME_VO, 100))) 'Set PRA_HOME_VO
                Function_Result((APS_set_axis_param(AxisNo, PRA_HOME_OFFSET, 500))) 'Set PRA_HOME_OFFSET
            Next AxisNo

            MsgBox("Bus Connected!!")

        Else
            MsgBox("Connect Fail!!")
        End If
    End Sub
	
	Private Sub Btn_BusDisconnect_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_BusDisconnect.Click
		Function_Result((APS_stop_field_bus(CardID, BusNo)))
	End Sub
	
	Private Sub Btn_GetModuleInfo_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_GetModuleInfo.Click
		Dim Info As Integer
		Function_Result((APS_get_field_bus_device_info(CardID, BusNo, CInt(Edit_SetModuleID_ForModuleInfo.Text), &H21s, Info))) 'Get FPGA Version
		Edit_ShowModule_FPGAVer.Text = CStr(Info)
		
        Function_Result(APS_get_field_bus_device_info(CardID, BusNo, CLng(Edit_SetModuleID_ForModuleInfo.Text), &H30, Info))    'Get PCB Top Version
        Edit_ShowModule_PCBTopVer.Text = CStr(Info)

        Function_Result(APS_get_field_bus_device_info(CardID, BusNo, CLng(Edit_SetModuleID_ForModuleInfo.Text), &H31, Info))     'Get PCB Bottom Version
        Edit_ShowMaster_PCBBottomVer.Text = CStr(Info)

	End Sub
	
	Private Sub Btn_Linear_2Axes_AbsoluteBackward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_2Axes_AbsoluteBackward.Click
		Dim Dimension As Integer
        Dim Position_Array(2) As Integer
        Dim Max_Linear_Speed As Integer
		
		Dimension = 2
        Position_Array(0) = -10000
        Position_Array(1) = -20000

		Max_Linear_Speed = 50000
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
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
		'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
		
        Function_Result((APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed)))
    End Sub
	
	Private Sub Btn_Linear_Compare_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Linear_Compare.Click
		Dim StartPoint As Integer
		Dim RepeatTimes As Integer
		Dim Interval As Integer
		Dim LastIndex As Integer
		Dim Index As Integer
		
		StartPoint = 5000
		RepeatTimes = 100
		Interval = 100
		LastIndex = 4
		
		For Index = 0 To LastIndex - 1
			Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_CMP0_SRC + Index, 0))) 'Compare source is from command counter.
			Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_CMP0_TYPE + Index, 1))) 'Compare type is Linear.
			Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_TRG0_PWD + Index, 5))) 'Trigger Width is 60nS
			Function_Result((APS_set_field_bus_trigger_linear(CardID, BusNo, MOD_No, Index, StartPoint, RepeatTimes, Interval))) 'Set Linear Data
			Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_CMP0_EN + Index, 1))) 'Enable Linear compare
			If (FunctionFail) Then
                Exit For
				FunctionFail = False
			End If
			
		Next Index
		'
		Btn_Trigger_Count_Click(Btn_Trigger_Count, New System.EventArgs()) 'Reset Trigger Counter, it's not nerssery.
		Btn_ResetCounter_Click(Btn_ResetCounter, New System.EventArgs()) 'Reset Axis Counter Counter, it's not nerssery.
		Btn_Linear_4Axes_RelateiveForward_Click(Btn_Linear_4Axes_RelateiveForward, New System.EventArgs())
	End Sub
	
	Private Sub Btn_Manual_Compare_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Manual_Compare.Click
		Dim LastIndex As Integer
		Dim TrgCh As Integer
		LastIndex = 4
		For TrgCh = 0 To LastIndex - 1
			Function_Result((APS_set_field_bus_trigger_manual(CardID, BusNo, MOD_No, TrgCh)))
			If (FunctionFail) Then
				TrgCh = LastIndex + 1
				FunctionFail = False
			End If
		Next TrgCh
		
	End Sub
	
	Private Sub Btn_PointTable_MoveALL_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_PointTable_MoveALL.Click
		Dim Index As Integer
		Dim LastIndex As Integer
        Dim PointData As POINT_DATA2

		Index = 0
        LastIndex = 19
		
		Function_Result((APS_set_point_table_mode2(Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable), 1))) '0:Single 1:continue
		
		For Index = 0 To LastIndex
            PointData.i32_pos_0 = (Index + 1) * 1000 'Position data = Index * 10000;
            PointData.i32_pos_1 = (Index + 1) * 1000 'Position data = Index * 10000;
            PointData.i32_pos_2 = (Index + 1) * 1000 'Position data = Index * 10000;
            PointData.i32_pos_3 = (Index + 1) * 1000 'Position data = Index * 10000;

            If (Index = 0) Then 'If Index be first or last index, initSpeed be 0.
                PointData.i32_initSpeed = 0 ' Start velocity   ( pulse / s )
                PointData.i32_maxSpeed = 50000 ' Maximum velocity  ( pulse / s )
                PointData.i32_angle = 0
            Else 'Others index iniSpeed and maxSpeed are the same.
                PointData.i32_initSpeed = PointData.i32_maxSpeed ' Start velocity   ( pulse / s )
                PointData.i32_maxSpeed = 50000 ' Maximum velocity  ( pulse / s )
            End If

            If Index = LastIndex Then
                PointData.i32_opt = &H21 ' Option 0xABCD , D:0 absolute, 1:relative
            Else
                PointData.i32_opt = 1 ' Option 0xABCD , D:0 absolute, 1:relative
            End If

            PointData.u32_dwell = 0 ' Dwell times       ( unit: ms )

            Function_Result((APS_set_point_table2(Dimension_For_PointTable, Axis_ID_Array_For_PointTable, Index, PointData)))
            If (FunctionFail) Then
                Exit For
                FunctionFail = False
            End If
        Next Index
		
        Function_Result((APS_point_table_continuous_move2(Dimension_For_PointTable, Axis_ID_Array_For_PointTable)))
    End Sub
	
	Private Sub Btn_PointTable_SingleIndexMove_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_PointTable_SingleIndexMove.Click
        Function_Result((APS_point_table_single_move2(0, 10)))
	End Sub
	
	Private Sub Btn_PointTable_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_PointTable_Stop.Click
		Function_Result((APS_emg_stop(Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable))))
	End Sub
	
	Private Sub Btn_ResetCounter_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_ResetCounter.Click
		Dim LastIndex As Integer
		Dim AxisNo As Integer
		LastIndex = 4
		For AxisNo = Start_Axis_ID To 3
			Function_Result((APS_set_command(AxisNo, 0)))
			Function_Result((APS_set_position(AxisNo, 0)))
			If FunctionFail Then
                Exit For
				FunctionFail = False
			End If
		Next AxisNo
		
	End Sub
	
	Private Sub Btn_SetPointTable_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SetPointTable.Click
		Dim Index As Integer
		Dim LastIndex As Integer
        Dim PointData As POINT_DATA2

		Index = 0
        LastIndex = 19
		
		Function_Result((APS_set_point_table_mode2(Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable), 0))) '0:Single 1:continue
		
        For Index = 0 To LastIndex

            PointData.i32_pos_0 = (Index + 1) * 1000 'Position data = Index * 10000;
            PointData.i32_pos_1 = (Index + 1) * 1000 'Position data = Index * 10000;
            PointData.i32_pos_2 = (Index + 1) * 1000 'Position data = Index * 10000;
            PointData.i32_pos_3 = (Index + 1) * 1000 'Position data = Index * 10000;


            If (Index = 0) Then 'If Index be first or last index, initSpeed be 0.
                PointData.i32_initSpeed = 0 ' Start velocity   ( pulse / s )
                PointData.i32_maxSpeed = 50000 ' Maximum velocity  ( pulse / s )
                PointData.i32_angle = 0
            Else 'Others index iniSpeed and maxSpeed are the same.
                PointData.i32_initSpeed = PointData.i32_maxSpeed ' Start velocity   ( pulse / s )
                PointData.i32_maxSpeed = 50000 ' Maximum velocity  ( pulse / s )
            End If

            If Index = LastIndex Then
                PointData.i32_opt = &H21 ' Option 0xABCD , D:0 absolute, 1:relative
            Else
                PointData.i32_opt = 1 ' Option 0xABCD , D:0 absolute, 1:relative
            End If

            PointData.u32_dwell = 0 ' Dwell times       ( unit: ms )

            Function_Result((APS_set_point_table2(Dimension_For_PointTable, Axis_ID_Array_For_PointTable, Index, PointData)))
            If (FunctionFail) Then
                Exit For
                FunctionFail = False
            End If
        Next Index
		
	End Sub
	
	Private Sub Btn_SingleAbsoluteMove_Backward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleAbsoluteMove_Backward.Click
		Dim Position As Integer
		Dim Max_Speed As Integer
		
		Position = -10000
		Max_Speed = 50000
		'Others setting like ACC,Dec... are in the initial segmant.
		
		Function_Result(((APS_absolute_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleAbsoluteMove_Forward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleAbsoluteMove_Forward.Click
		Dim Position As Integer
		Dim Max_Speed As Integer
		
		Position = 10000
		Max_Speed = 50000
		'Others setting like ACC,Dec... are in the initial segmant.
		
		Function_Result(((APS_absolute_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleAbsoluteMove_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleAbsoluteMove_Stop.Click
		Function_Result((APS_emg_stop(AxisID_SingleAxis_ForAbsolute)))
	End Sub
	
	Private Sub Btn_SingleHomeMove_Backward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleHomeMove_Backward.Click
		Function_Result((APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1))) 'Set PRA_HOME_DIR   0:Positive 1:Negative
		'Others setting like ACC,Dec... are in the initial segmant.
		
		Function_Result((APS_home_move(AxisID_SingleAxis_ForHome)))
	End Sub
	
	Private Sub Btn_SingleHomeMove_Forward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleHomeMove_Forward.Click
		Function_Result((APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0))) 'Set PRA_HOME_DIR   0:Positive 1:Negative
		'Others setting like ACC,Dec... are in the initial segmant.
		
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
		'Others setting like ACC,Dec... are in the initial segmant.
		
		Function_Result(((APS_relative_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleRelativeMove_Forward_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleRelativeMove_Forward.Click
		Dim Position As Integer
		Dim Max_Speed As Integer
		
		Position = 10000
		Max_Speed = 50000
		'Others setting like ACC,Dec... are in the initial segmant.
		
		Function_Result(((APS_relative_move(AxisID_SingleAxis_ForAbsolute, Position, Max_Speed))))
	End Sub
	
	Private Sub Btn_SingleRelativeMove_Stop_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_SingleRelativeMove_Stop.Click
		Function_Result((APS_emg_stop(AxisID_SingleAxis_ForRelative)))
	End Sub
	
	
	
	Private Sub Btn_Table_Compare_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Table_Compare.Click
		Dim ArraySize As Integer
		Dim LastIndex As Integer
		Dim Index As Integer
		Dim TableIndex As Integer
		ArraySize = 100
		LastIndex = 4
		
		Dim DataArray(ArraySize) As Integer
		
		
		For Index = 0 To LastIndex - 1
			Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_CMP0_SRC + Index, 0))) 'Compare source is from command counter.
			Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_CMP0_TYPE + Index, 0))) 'Compare type is Table.
			Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_TRG0_PWD + Index, 5))) 'Trigger Width is 60nS
			
			For TableIndex = 0 To 99 'Create Table Data
				DataArray(TableIndex) = 5000 + (TableIndex * 100)
			Next TableIndex
			
            'Function_Result((APS_set_field_bus_trigger_table(CardID, BusNo, MOD_No, Index, DataArray(0), ArraySize))) 'Set Table Data
            Function_Result((APS_set_field_bus_trigger_table(CardID, BusNo, MOD_No, Index, DataArray, ArraySize))) 'Set Table Data
            Function_Result((APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, TG_CMP0_EN + Index, 1))) 'Enable Linear compare
			If (FunctionFail) Then
                Exit For
				FunctionFail = False
			End If
		Next Index
		
        System.Array.Clear(DataArray, 0, DataArray.Length)
		
		Btn_Trigger_Count_Click(Btn_Trigger_Count, New System.EventArgs()) 'Reset Trigger Counter, it's not nerssery.
		Btn_ResetCounter_Click(Btn_ResetCounter, New System.EventArgs()) 'Reset Axis Counter Counter, it's not nerssery.
		Btn_Linear_4Axes_RelateiveForward_Click(Btn_Linear_4Axes_RelateiveForward, New System.EventArgs())
	End Sub
	
	Private Sub Btn_Trigger_Count_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Btn_Trigger_Count.Click
		Dim LastIndex As Integer
		Dim TrgCh As Integer
		LastIndex = 4
		For TrgCh = 0 To LastIndex - 1
			Function_Result((APS_reset_field_bus_trigger_count(CardID, BusNo, MOD_No, TrgCh)))
			If (FunctionFail) Then
                Exit For
				FunctionFail = False
			End If
		Next TrgCh
	End Sub
	
	Private Sub MainForm_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
		CardID = 0 'Card number for setting.
		BusNo = 1 'Bus number for setting,  Motion Net BusNo is 0.
		Start_Axis_ID = 0 'First Axis number in Motion Net bus.
		AxisID_SingleAxis_ForAbsolute = 0
		AxisID_SingleAxis_ForRelative = 1
		AxisID_SingleAxis_ForHome = 2
		AxisID_FirstAxis_For_PointTable = 0
		Dimension_For_PointTable = 4
        'MOD_No = 0
        MOD_No = 7

		Axis_ID_Array_For_2Axes_Move(0) = 0
        Axis_ID_Array_For_2Axes_Move(1) = 1

        Axis_ID_Array_For_2Axes_ArcMove(0) = 0
        Axis_ID_Array_For_2Axes_ArcMove(1) = 1
		
		Axis_ID_Array_For_3Axes_Move(0) = 0
		Axis_ID_Array_For_3Axes_Move(1) = 1
		Axis_ID_Array_For_3Axes_Move(2) = 2
		
		Axis_ID_Array_For_4Axes_Move(0) = 0
		Axis_ID_Array_For_4Axes_Move(1) = 1
		Axis_ID_Array_For_4Axes_Move(2) = 2
		Axis_ID_Array_For_4Axes_Move(3) = 3
		
		Axis_ID_Array_For_PointTable(0) = 0
		Axis_ID_Array_For_PointTable(1) = 1
		Axis_ID_Array_For_PointTable(2) = 2
		Axis_ID_Array_For_PointTable(3) = 3
		
		FunctionFail = False
		
		'Initial+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		Dim DPAC_ID_Bits As Integer
		Dim Info As Integer
		If (APS_initial(DPAC_ID_Bits, 0) = 0) Then 'Initial Card, CardID is assigned by system.
			'Get Card information
			Function_Result((APS_get_device_info(CardID, &H10s, Info))) 'Get Driver Version
			Edit_ShowMaster_DriverVer.Text = CStr(Info)
			
			Edit_ShowMaster_DLLVer.Text = CStr(APS_version) 'Get DLL Version
			
			Function_Result((APS_get_device_info(CardID, &H20s, Info))) 'Get CPLD Version
			Edit_ShowMaster_CPLDVer.Text = CStr(Info)
			
			Function_Result((APS_get_device_info(CardID, &H30s, Info))) 'Get PCB Version
            Edit_ShowMaster_PCBBottomVer.Text = CStr(Info)
			
			'Set Motion Net Parameter
			Function_Result((APS_set_field_bus_param(CardID, BusNo, PRF_TRANSFER_RATE, 3))) 'Set PRF_TRANSFER_RATE: 3 (12M)
		Else
			MsgBox("Initial Fail, sample close!!", MsgBoxStyle.OKOnly)
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
        Dim TrgCnt As Integer
        Dim CmpVal As Integer
        Dim EncCnt As Integer
        Dim RunningPoint As Integer
        Dim DI_Value, DOdata As Long

        For Index = 0 To 3
            'Motion Segment
            APS_get_command(Start_Axis_ID + Index, Command_Renamed)
            Edit_ShowAxis_Command(Index).Text = CStr(Command_Renamed)

            APS_get_position(Start_Axis_ID + Index, Position)
            Edit_ShowAxis_Feedback(Index).Text = CStr(Position)

            IoSts = APS_motion_io_status(Start_Axis_ID + Index)
            Edit_ShowAxis_IOSts(Index).Text = CStr(IoSts)

            MotionSts = APS_motion_status(Start_Axis_ID + Index)
            Edit_ShowAxis_MSts(Index).Text = CStr(MotionSts)

            APS_get_running_point_index2(Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable), RunningPoint)
            Edit_Show_PointTable_CurrIndex.Text = CStr(RunningPoint)

            'Compare Segment
            APS_get_field_bus_trigger_count(CardID, BusNo, MOD_No, Index, TrgCnt)
            Edit_ShowTriggerCount(Index).Text = CStr(TrgCnt)

            APS_get_field_bus_encoder(CardID, BusNo, MOD_No, Index, EncCnt)
            Edit_ShowTriggerEnc(Index).Text = CStr(EncCnt)

            APS_get_field_bus_trigger_linear_cmp(CardID, BusNo, MOD_No, Index, CmpVal)
            Edit_ShowTrigger_LinearCMP_LinearCMP(Index).Text = CStr(CmpVal)

            'General DIO
            APS_get_field_bus_d_input(CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), DI_Value)
            Edit_ShowDIData.Text = Hex(DI_Value)

            APS_get_field_bus_d_output(CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), DOdata)
            Edit_GetDOData.Text = Hex(DOdata)
        Next Index

    End Sub

    Private Sub Btn_Arc_2Axes_Absolute_CCW_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Absolute_CCW.Click
        Dim Dimension As Long
        Dim Center_Pos_Array(2) As Integer
        Dim Max_Arc_Speed As Long
        Dim Angle As Long

        Dimension = 2
        Center_Pos_Array(0) = -20000
        Center_Pos_Array(1) = -20000

        Max_Arc_Speed = 50000
        Angle = 180
        'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

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
        Angle = 180
        'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

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
        Center_Pos_Array(0) = -20000
        Center_Pos_Array(1) = -20000

        Max_Arc_Speed = 50000
        Angle = 180
        'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

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
        Angle = 180
        'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

        Function_Result(APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle))
    End Sub

    Private Sub Btn_Arc_2Axes_Relateive_Stop_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Arc_2Axes_Relateive_Stop.Click
        Function_Result(APS_emg_stop(Axis_ID_Array_For_2Axes_ArcMove(0)))
    End Sub

    Private Sub Btn_Set_DOData_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_Set_DOData.Click
        Function_Result(APS_set_field_bus_d_output(CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), CLng(Edit_SetDOData.Text)))
    End Sub
End Class