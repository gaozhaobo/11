unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, StdCtrls ,APS168, APS_Define ;


type
  TForm1 = class(TForm)
    GroupBox3: TGroupBox;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    Label15: TLabel;
    Label16: TLabel;
    Label17: TLabel;
    Label18: TLabel;
    Label19: TLabel;
    Label20: TLabel;
    Label21: TLabel;
    Label22: TLabel;
    Edit_ShowAxis_Command_0: TEdit;
    Edit_ShowAxis_Feedback_0: TEdit;
    Edit_ShowAxis_IOSts_0: TEdit;
    Edit_ShowAxis_MSts_0: TEdit;
    Edit_ShowAxis_Command_1: TEdit;
    Edit_ShowAxis_Feedback_1: TEdit;
    Edit_ShowAxis_IOSts_1: TEdit;
    Edit_ShowAxis_MSts_1: TEdit;
    Edit_ShowAxis_Command_2: TEdit;
    Edit_ShowAxis_Feedback_2: TEdit;
    Edit_ShowAxis_IOSts_2: TEdit;
    Edit_ShowAxis_MSts_2: TEdit;
    Edit_ShowAxis_Command_3: TEdit;
    Edit_ShowAxis_Feedback_3: TEdit;
    Edit_ShowAxis_IOSts_3: TEdit;
    Edit_ShowAxis_MSts_3: TEdit;
    ResetCounter: TButton;
    GroupBox4: TGroupBox;
    Btn_BusConnect: TButton;
    Btn_BusDisconnect: TButton;
    GroupBox5: TGroupBox;
    Label23: TLabel;
    Edit_SetModuleID_ForModuleInfo: TEdit;
    Btn_GetModuleInfo: TButton;
    GroupBox6: TGroupBox;
    Btn_SingleAbsoluteMove_Backward: TButton;
    Btn_SingleAbsoluteMove_Forward: TButton;
    Btn_SingleAbsoluteMove_Stop: TButton;
    GroupBox7: TGroupBox;
    Btn_SingleRelativeMove_Backward: TButton;
    Btn_SingleRelativeMove_Forward: TButton;
    Btn_SingleRelativeMove_Stop: TButton;
    GroupBox8: TGroupBox;
    Btn_SingleHomeMove_Backward: TButton;
    Btn_SingleHomeMove_Forward: TButton;
    Btn_SingleHomeMove_Stop: TButton;
    GroupBox9: TGroupBox;
    Btn_Linear_2Axes_AbsoluteBackward: TButton;
    Btn_Linear_2Axes_AbsoluteForward: TButton;
    Btn_Linear_2Axes_AbsoluteStop: TButton;
    GroupBox10: TGroupBox;
    Btn_Linear_2Axes_RelateiveBackward: TButton;
    Btn_Linear_2Axes_RelateiveForward: TButton;
    Btn_Linear_2Axes_Relateive_Stop: TButton;
    GroupBox11: TGroupBox;
    Btn_Linear_3Axes_AbsoluteBackward: TButton;
    Btn_Linear_3Axes_AbsoluteForward: TButton;
    Btn_Linear_3Axes_AbsoluteStop: TButton;
    GroupBox12: TGroupBox;
    Btn_Linear_3Axes_RelateiveBackward: TButton;
    Btn_Linear_3Axes_RelateiveForward: TButton;
    Btn_Linear_3Axes_Relateive_Stop: TButton;
    GroupBox13: TGroupBox;
    Btn_Linear_4Axes_AbsoluteBackward: TButton;
    Btn_Linear_4Axes_AbsoluteForward: TButton;
    Btn_Linear_4Axes_AbsoluteStop: TButton;
    GroupBox14: TGroupBox;
    Btn_Linear_4Axes_RelateiveBackward: TButton;
    Btn_Linear_4Axes_RelateiveForward: TButton;
    Btn_Linear_4Axes_Relateive_Stop: TButton;
    GroupBox15: TGroupBox;
    Label24: TLabel;
    Edit_Show_PointTable_CurrIndex: TEdit;
    GroupBox17: TGroupBox;
    Label25: TLabel;
    Btn_SetPointTable: TButton;
    Edit_SetTargetIndex_ForSinglePointMove: TEdit;
    Btn_PointTable_SingleIndexMove: TButton;
    GroupBox18: TGroupBox;
    Btn_PointTable_MoveALL: TButton;
    Btn_PointTable_Stop: TButton;
    GroupBox16: TGroupBox;
    Label26: TLabel;
    Label27: TLabel;
    Label28: TLabel;
    Label29: TLabel;
    Label30: TLabel;
    Label31: TLabel;
    Label32: TLabel;
    Label33: TLabel;
    Label34: TLabel;
    Label35: TLabel;
    Label36: TLabel;
    Label37: TLabel;
    Edit_ShowTriggerCount_0: TEdit;
    Edit_ShowTriggerCount_1: TEdit;
    Edit_ShowTriggerCount_2: TEdit;
    Edit_ShowTriggerCount_3: TEdit;
    Edit_ShowTriggerEnc_0: TEdit;
    Edit_ShowTriggerEnc_1: TEdit;
    Edit_ShowTriggerEnc_2: TEdit;
    Edit_ShowTriggerEnc_3: TEdit;
    Edit_ShowTrigger_LinearCMP_LinearCMP_0: TEdit;
    Edit_ShowTrigger_LinearCMP_LinearCMP_1: TEdit;
    Edit_ShowTrigger_LinearCMP_LinearCMP_2: TEdit;
    Edit_ShowTrigger_LinearCMP_LinearCMP_3: TEdit;
    Btn_Linear_Compare: TButton;
    Btn_Table_Compare: TButton;
    Btn_Manual_Compare: TButton;
    Btn_Trigger_Count: TButton;
    Timer1: TTimer;
    GroupBox19: TGroupBox;
    Btn_Arc_2Axes_Absolute_CCW: TButton;
    Btn_Arc_2Axes_Absolute_CW: TButton;
    Btn_Arc_2Axes_Absolute_Stop2: TButton;
    GroupBox20: TGroupBox;
    Btn_Arc_2Axes_Relative_CCW: TButton;
    Btn_Arc_2Axes_Relative_CW: TButton;
    Btn_Arc_2Axes_Relateive_Stop: TButton;
    GroupBox21: TGroupBox;
    Label38: TLabel;
    Label39: TLabel;
    Label40: TLabel;
    Label41: TLabel;
    Edit_SetModuleID_ForGeneralDIO: TEdit;
    Edit_ShowDIData: TEdit;
    Edit_SetDOData: TEdit;
    Btn_Set_DOData: TButton;
    Edit_GetDOData: TEdit;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Edit_ShowMaster_DriverVer: TEdit;
    Edit_ShowMaster_DLLVer: TEdit;
    Edit_ShowMaster_CPLDVer: TEdit;
    GroupBox2: TGroupBox;
    Label5: TLabel;
    Label6: TLabel;
    Label4: TLabel;
    Edit_ShowModule_FPGAVer: TEdit;
    Edit_ShowModule_PCBTopVer: TEdit;
    Edit_ShowMaster_PCBBottomVer: TEdit;
    procedure FormCreate(Sender: TObject);
    procedure Function_Result(Ret:Longint);
    procedure ResetCounterClick(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure Btn_BusConnectClick(Sender: TObject);
    procedure Btn_BusDisconnectClick(Sender: TObject);
    procedure Btn_GetModuleInfoClick(Sender: TObject);
    procedure Btn_SingleAbsoluteMove_BackwardClick(Sender: TObject);
    procedure Btn_SingleAbsoluteMove_ForwardClick(Sender: TObject);
    procedure Btn_SingleAbsoluteMove_StopClick(Sender: TObject);
    procedure Btn_SingleRelativeMove_BackwardClick(Sender: TObject);
    procedure Btn_SingleRelativeMove_ForwardClick(Sender: TObject);
    procedure Btn_SingleRelativeMove_StopClick(Sender: TObject);
    procedure Btn_SingleHomeMove_BackwardClick(Sender: TObject);
    procedure Btn_SingleHomeMove_StopClick(Sender: TObject);
    procedure Btn_SingleHomeMove_ForwardClick(Sender: TObject);
    procedure Btn_Linear_2Axes_AbsoluteBackwardClick(Sender: TObject);
    procedure Btn_Linear_2Axes_AbsoluteForwardClick(Sender: TObject);
    procedure Btn_Linear_2Axes_AbsoluteStopClick(Sender: TObject);
    procedure Btn_Linear_2Axes_RelateiveBackwardClick(Sender: TObject);
    procedure Btn_Linear_2Axes_RelateiveForwardClick(Sender: TObject);
    procedure Btn_Linear_2Axes_Relateive_StopClick(Sender: TObject);
    procedure Btn_Linear_3Axes_AbsoluteBackwardClick(Sender: TObject);
    procedure Btn_Linear_3Axes_AbsoluteForwardClick(Sender: TObject);
    procedure Btn_Linear_3Axes_AbsoluteStopClick(Sender: TObject);
    procedure Btn_Linear_3Axes_RelateiveBackwardClick(Sender: TObject);
    procedure Btn_Linear_3Axes_RelateiveForwardClick(Sender: TObject);
    procedure Btn_Linear_4Axes_AbsoluteStopClick(Sender: TObject);
    procedure Btn_Linear_4Axes_RelateiveBackwardClick(Sender: TObject);
    procedure Btn_Linear_4Axes_RelateiveForwardClick(Sender: TObject);
    procedure Btn_Linear_4Axes_AbsoluteBackwardClick(Sender: TObject);
    procedure Btn_Linear_4Axes_AbsoluteForwardClick(Sender: TObject);
    procedure Btn_Linear_4Axes_Relateive_StopClick(Sender: TObject);
    procedure Btn_Linear_3Axes_Relateive_StopClick(Sender: TObject);
    procedure Btn_PointTable_StopClick(Sender: TObject);
    procedure Btn_SetPointTableClick(Sender: TObject);
    procedure Btn_PointTable_SingleIndexMoveClick(Sender: TObject);
    procedure Btn_PointTable_MoveALLClick(Sender: TObject);
    procedure Btn_Linear_CompareClick(Sender: TObject);
    procedure Btn_Trigger_CountClick(Sender: TObject);
    procedure Btn_Table_CompareClick(Sender: TObject);
    procedure Btn_Manual_CompareClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Absolute_CCWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Absolute_CWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Relative_CCWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Relative_CWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Absolute_Stop2Click(Sender: TObject);
    procedure Btn_Arc_2Axes_Relateive_StopClick(Sender: TObject);
    procedure Btn_Set_DODataClick(Sender: TObject);
  private
    { Private declarations }

  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation
var
//My Value+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CardID:Smallint =0;	      //Card number for setting.
BusNo:Smallint  =1;        //Bus number for setting,  Motion Net BusNo is 0.
MOD_No:Smallint =0;		  //Arrcoding switch On Module.
Start_Axis_ID:Longint=0;  //First Axis number in Motion Net bus.
AxisID_SingleAxis_ForAbsolute:Longint= 0;
AxisID_SingleAxis_ForRelative:Longint= 1;
AxisID_SingleAxis_ForHome:Longint= 2;
AxisID_FirstAxis_For_PointTable:Longint=0;
Dimension_For_PointTable:Longint=4;
Axis_ID_Array_For_2Axes_Move:array [0..1] of Longint=(0,1);
Axis_ID_Array_For_2Axes_ArcMove:array [0..1] of Longint=(0,1);
Axis_ID_Array_For_3Axes_Move:array [0..2] of Longint=(0,1,2);
Axis_ID_Array_For_4Axes_Move:array [0..3] of Longint=(0,1,2,3);
Axis_ID_Array_For_PointTable:array [0..3] of Longint=(0,1,2,3);

FunctionFail:bool =false;
bIsConnected:bool =false;
CurrectSelAxis:Longint=0;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

{$R *.dfm}
procedure TForm1.Function_Result(Ret:Longint);
begin
    if (Ret <> 0)  then
    begin
    	ShowMessage('Error Code = ' + CurrToStr(Ret));
    	FunctionFail:=true;
    end
    else
    begin
      FunctionFail:=false;
    end;
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  DPAC_ID_Bits:Longint;
  Info:Longint;
begin
  //Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	if (APS_initial(DPAC_ID_Bits, 0)=0)then      //Initial Card, CardID is assigned by system.
  begin
		//Get Card information
		APS_get_device_info( CardID, $10, Info );		//Get Driver Version
		Edit_ShowMaster_DriverVer.Text := IntToStr(Info);

		Edit_ShowMaster_DLLVer.Text :=IntToStr(APS_version());  //Get DLL Version

		APS_get_device_info( CardID, $20, Info );		//Get CPLD Version
		Edit_ShowMaster_CPLDVer.Text := IntToStr(Info);

		//Set Motion Net Parameter
		Function_Result (APS_set_field_bus_param (CardID, BusNo, PRF_TRANSFER_RATE, 3));     //Set PRF_TRANSFER_RATE: 3 (12M)
  end
	else
  begin
		ShowMessage('Initial Fail');
		APS_close();
  end;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
end;

procedure TForm1.ResetCounterClick(Sender: TObject);
var
   LastIndex:Longint;
   AxisNo:Longint;
begin
  LastIndex := Start_Axis_ID + 3;

	for AxisNo := Start_Axis_ID to LastIndex do
  begin
		Function_Result (APS_set_command( AxisNo, 0));
		Function_Result (APS_set_position( AxisNo, 0 ));
		if (FunctionFail) then
    begin
      Break;
		end;
  end;

end;

procedure TForm1.Timer1Timer(Sender: TObject);
  var
    Command:Longint;
  	Position:Longint;
  	MotionSts:Longint;
  	IoSts:Longint;
  	Index:Longint;
  	TrgCnt:Longint;
  	CmpVal:Longint;
  	EncCnt:Longint;
  	RunningPoint:Longint;
    DI_Value:Longint;
    DOdada:Longint;
    CommandArray:array[0..3] of TEdit;
    Feedback:array[0..3] of TEdit;
    IOStsArray:array[0..3] of TEdit;
    MSts:array[0..3] of TEdit;
    TriggerCount:array[0..3] of TEdit;
    TriggerEnc:array[0..3] of TEdit;
    TriggerVal:array[0..3] of TEdit;

begin
    CommandArray[0]:=Edit_ShowAxis_Command_0;
    CommandArray[1]:=Edit_ShowAxis_Command_1;
    CommandArray[2]:=Edit_ShowAxis_Command_2;
    CommandArray[3]:=Edit_ShowAxis_Command_3;

    Feedback[0]:=Edit_ShowAxis_Feedback_0;
    Feedback[1]:=Edit_ShowAxis_Feedback_1;
    Feedback[2]:=Edit_ShowAxis_Feedback_2;
    Feedback[3]:=Edit_ShowAxis_Feedback_3;

    IOStsArray[0]:=Edit_ShowAxis_IOSts_0;
    IOStsArray[1]:=Edit_ShowAxis_IOSts_1;
    IOStsArray[2]:=Edit_ShowAxis_IOSts_2;
    IOStsArray[3]:=Edit_ShowAxis_IOSts_3;

    MSts[0]:=Edit_ShowAxis_MSts_0;
    MSts[1]:=Edit_ShowAxis_MSts_1;
    MSts[2]:=Edit_ShowAxis_MSts_2;
    MSts[3]:=Edit_ShowAxis_MSts_3;

    TriggerCount[0]:=Edit_ShowTriggerCount_0;
    TriggerCount[1]:=Edit_ShowTriggerCount_1;
    TriggerCount[2]:=Edit_ShowTriggerCount_2;
    TriggerCount[3]:=Edit_ShowTriggerCount_3;

    TriggerEnc[0]:=Edit_ShowTriggerEnc_0;
    TriggerEnc[1]:=Edit_ShowTriggerEnc_1;
    TriggerEnc[2]:=Edit_ShowTriggerEnc_2;
    TriggerEnc[3]:=Edit_ShowTriggerEnc_3;

    TriggerVal[0]:=Edit_ShowTrigger_LinearCMP_LinearCMP_0;
    TriggerVal[1]:=Edit_ShowTrigger_LinearCMP_LinearCMP_1;
    TriggerVal[2]:=Edit_ShowTrigger_LinearCMP_LinearCMP_2;
    TriggerVal[3]:=Edit_ShowTrigger_LinearCMP_LinearCMP_3;

	for index:=0 to 3 do
  begin
		//Motion Segment
		APS_get_command( Start_Axis_ID + index, Command );
		CommandArray[index].Text := IntToStr(Command);

		APS_get_position( Start_Axis_ID + index, Position );
		Feedback[index].Text := IntToStr(Position);

		IoSts:=APS_motion_io_status( Start_Axis_ID + index );
		IOStsArray[index].Text := IntToHex(IoSts,8);

		MotionSts:=APS_motion_status( Start_Axis_ID + index );
		MSts[index].Text := IntToStr(MotionSts);

		APS_get_running_point_index2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], RunningPoint );
		Edit_Show_PointTable_CurrIndex.Text := IntToStr(RunningPoint);

		//Compare Segment
    APS_get_field_bus_trigger_count( CardID, BusNo, MOD_No, index, TrgCnt );
		TriggerCount[index].Text := IntToStr(TrgCnt);

		APS_get_field_bus_encoder( CardID, BusNo, MOD_No, index, EncCnt );
		TriggerEnc[index].Text := IntToStr(EncCnt);

		APS_get_field_bus_trigger_linear_cmp( CardID, BusNo, MOD_No, index, CmpVal );
		TriggerVal[index].Text := IntToStr(CmpVal);

    //General DIO
    APS_get_field_bus_d_input( CardID, BusNo, StrToInt(Edit_SetModuleID_ForGeneralDIO.Text) , DI_Value );
    Edit_ShowDIData.Text := IntToHex(DI_Value,2);

    APS_get_field_bus_d_output(  CardID, BusNo, StrToInt(Edit_SetModuleID_ForGeneralDIO.Text), DOdada   );
    Edit_GetDOData.Text := IntToHex(DOdada,2);
   end;

end;

procedure TForm1.Btn_BusConnectClick(Sender: TObject);
var
  AxisNo:Longint;
  LastAxisNo:Longint;
begin
  Function_Result (APS_start_field_bus(CardID, BusNo, Start_Axis_ID));

	if (not FunctionFail) then
  begin
		//Set Axis Parameter
    LastAxisNo:=Start_Axis_ID+3;
		for AxisNo:= Start_Axis_ID to LastAxisNo do
    begin
			//IO and Pulse Mode
      Function_Result (APS_set_axis_param(AxisNo, PRA_ALM_LOGIC, 0));       //Set PRA_ALM_LOGIC
			Function_Result (APS_set_axis_param(AxisNo, PRA_PLS_IPT_MODE, 2));    //Set PRA_PLS_IPT_MODE
			Function_Result (APS_set_axis_param(AxisNo, PRA_PLS_OPT_MODE, 1));    //Set PRA_PLS_OPT_MODE
			Function_Result (APS_set_axis_param(AxisNo, PRA_PLS_IPT_LOGIC, 1));   //Set PRA_PLS_IPT_LOGIC
			Function_Result (APS_set_axis_param(AxisNo, PRA_FEEDBACK_SRC, 1));   //Select feedback conter
								
	
			//Single Move Parameter
			Function_Result (APS_set_axis_param(AxisNo, PRA_CURVE, 0));			  //Set PRA_CURVE  0:T-Curve 1:S-Curve
			Function_Result (APS_set_axis_param(AxisNo, PRA_ACC, 10000000));		  //Set PRA_ACC 
			Function_Result (APS_set_axis_param(AxisNo, PRA_DEC, 10000000));		  //Set PRA_DEC
			Function_Result (APS_set_axis_param(AxisNo, PRA_VS, 0));			  //Set PRA_VS

	
			//Home Move Parameter
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_MODE, 0));		  //Set PRA_HOME_MODE
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_VM, 10000));	  //Set PRA_HOME_VM
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_EZA, 0));		  //Set PRA_HOME_EZA 
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_VO, 100));		  //Set PRA_HOME_VO
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_OFFSET, 500));	  //Set PRA_HOME_OFFSET
		end;

		ShowMessage('Bus Connected!!');
		bIsConnected:=true;
  end
	else
  begin
		ShowMessage( 'Connect Fail!!');
	end;
end;

procedure TForm1.Btn_BusDisconnectClick(Sender: TObject);
begin
  Function_Result (APS_stop_field_bus(CardID, BusNo));

	if (not FunctionFail) then
  begin
		ShowMessage('Bus Disconnect!!');
  end
	else
  begin
		ShowMessage('Disonnect Fail!!');
	end;
end;

procedure TForm1.Btn_GetModuleInfoClick(Sender: TObject);
var
	Info:Longint;
begin

	Function_Result (APS_get_field_bus_device_info( CardID,		//Get FPGA Version
                                                  BusNo,
                                                  StrToInt(Edit_SetModuleID_ForModuleInfo.Text),
                                                  $21,
                                                  Info ));
	Edit_ShowModule_FPGAVer.Text:=IntToStr(Info);


	Function_Result (APS_get_field_bus_device_info( CardID,		//Get PCB Top Version
                                                  BusNo,
                                                  StrToInt(Edit_SetModuleID_ForModuleInfo.Text),
						                                      $30,
							                                    Info ));

	Edit_ShowModule_PCBTopVer.Text := IntToStr(Info);

	Function_Result (APS_get_field_bus_device_info( CardID,		//Get PCB Bottom Version
                                                  BusNo,
                                                  StrToInt(Edit_SetModuleID_ForModuleInfo.Text),
							                                    $31,
							                                    Info ));
  Edit_ShowMaster_PCBBottomVer.Text := IntToStr(Info);
end;

procedure TForm1.Btn_SingleAbsoluteMove_BackwardClick(Sender: TObject);
var
 	Position:Longint;
	Max_Speed:Longint;
begin
  Position:= -10000;
	Max_Speed:= 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
end;

procedure TForm1.Btn_SingleAbsoluteMove_ForwardClick(Sender: TObject);
var
 	Position:Longint;
	Max_Speed:Longint;
begin
  Position:= 10000;
	Max_Speed:= 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
end;

procedure TForm1.Btn_SingleAbsoluteMove_StopClick(Sender: TObject);
begin
  Function_Result (APS_emg_stop( AxisID_SingleAxis_ForAbsolute ));	 
end;

procedure TForm1.Btn_SingleRelativeMove_BackwardClick(Sender: TObject);
var
  Distance:Longint;
	Max_Speed:Longint;
begin
  Distance := -10000;
	Max_Speed := 50000;
	//Others setting like ACC,Dec... are  in the initial segmant.

	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
end;

procedure TForm1.Btn_SingleRelativeMove_ForwardClick(Sender: TObject);
var
  Distance:Longint;
	Max_Speed:Longint;
begin
  Distance := 10000;
	Max_Speed := 50000;
	//Others setting like ACC,Dec... are  in the initial segmant.

	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
end;


procedure TForm1.Btn_SingleRelativeMove_StopClick(Sender: TObject);
begin
    Function_Result (APS_emg_stop( AxisID_SingleAxis_ForRelative ));
end;

procedure TForm1.Btn_SingleHomeMove_BackwardClick(Sender: TObject);
begin
  Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));
end;

procedure TForm1.Btn_SingleHomeMove_ForwardClick(Sender: TObject);
begin
    Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));
end;

procedure TForm1.Btn_SingleHomeMove_StopClick(Sender: TObject);
begin
   Function_Result (APS_emg_stop( AxisID_SingleAxis_ForHome ));
end;

procedure TForm1.Btn_Linear_2Axes_AbsoluteBackwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Position_Array:array[0..1] of Longint;
 	Max_Linear_Speed:Longint;

begin
  Dimension:=2;
 	Position_Array[0]:=-10000;
 	Position_Array[1]:=-20000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move[0], Position_Array[0], Max_Linear_Speed ));
end;

procedure TForm1.Btn_Linear_2Axes_AbsoluteForwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Position_Array:array[0..1] of Longint;
 	Max_Linear_Speed:Longint;

begin
  Dimension:=2;
 	Position_Array[0]:=10000;
 	Position_Array[1]:=20000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move[0], Position_Array[0], Max_Linear_Speed ));
end;


procedure TForm1.Btn_Linear_2Axes_AbsoluteStopClick(Sender: TObject);
begin
  Function_Result ((APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0])));
end;

procedure TForm1.Btn_Linear_2Axes_RelateiveBackwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Distance_Array:array[0..1] of Longint;
 	Max_Linear_Speed:Longint;
begin
  Dimension:=2;
 	Distance_Array[0]:=-10000;
 	Distance_Array[1]:=-20000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result ((APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move[0], Distance_Array[0], Max_Linear_Speed )));
end;

procedure TForm1.Btn_Linear_2Axes_RelateiveForwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Distance_Array:array[0..1] of Longint;
 	Max_Linear_Speed:Longint;
begin
  Dimension:=2;
 	Distance_Array[0]:=10000;
 	Distance_Array[1]:=20000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result ((APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move[0], Distance_Array[0], Max_Linear_Speed )));

end;

procedure TForm1.Btn_Linear_2Axes_Relateive_StopClick(Sender: TObject);
begin
	Function_Result (APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0]));    
end;

procedure TForm1.Btn_Linear_3Axes_AbsoluteBackwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Position_Array:array[0..2] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=3;
 	Position_Array[0]:=-10000;
 	Position_Array[1]:=-20000;
	Position_Array[2]:=-30000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move[0], Position_Array[0], Max_Linear_Speed ));
end;

procedure TForm1.Btn_Linear_3Axes_AbsoluteForwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Position_Array:array[0..2] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=3;
 	Position_Array[0]:=10000;
 	Position_Array[1]:=20000;
	Position_Array[2]:=30000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move[0], Position_Array[0], Max_Linear_Speed ));

end;

procedure TForm1.Btn_Linear_3Axes_AbsoluteStopClick(Sender: TObject);
begin
  Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
end;

procedure TForm1.Btn_Linear_3Axes_RelateiveBackwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Distance_Array:array[0..2] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=3;
 	Distance_Array[0]:=-10000;
 	Distance_Array[1]:=-20000;
	Distance_Array[2]:=-30000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move[0], Distance_Array[0], Max_Linear_Speed ));
end;

procedure TForm1.Btn_Linear_3Axes_RelateiveForwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Distance_Array:array[0..2] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=3;
 	Distance_Array[0]:=10000;
 	Distance_Array[1]:=20000;
	Distance_Array[2]:=30000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move[0], Distance_Array[0], Max_Linear_Speed ));
end;

procedure TForm1.Btn_Linear_3Axes_Relateive_StopClick(Sender: TObject);
begin
  Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
end;

procedure TForm1.Btn_Linear_4Axes_AbsoluteBackwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Position_Array:array[0..3] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=4;
 	Position_Array[0]:=-10000;
 	Position_Array[1]:=-20000;
	Position_Array[2]:=-30000;
  Position_Array[3]:=-40000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move[0], Position_Array[0], Max_Linear_Speed ));

end;

procedure TForm1.Btn_Linear_4Axes_AbsoluteForwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Position_Array:array[0..3] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=4;
 	Position_Array[0]:=10000;
 	Position_Array[1]:=20000;
	Position_Array[2]:=30000;
  Position_Array[3]:=40000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move[0], Position_Array[0], Max_Linear_Speed ));

end;

procedure TForm1.Btn_Linear_4Axes_AbsoluteStopClick(Sender: TObject);
begin
  Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
end;

procedure TForm1.Btn_Linear_4Axes_RelateiveBackwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Distance_Array:array[0..3] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=4;
 	Distance_Array[0]:=-10000;
 	Distance_Array[1]:=-20000;
	Distance_Array[2]:=-30000;
  Distance_Array[3]:=-40000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move[0], Distance_Array[0], Max_Linear_Speed ));

end;

procedure TForm1.Btn_Linear_4Axes_RelateiveForwardClick(Sender: TObject);
var
  Dimension:Longint;
 	Distance_Array:array[0..3] of Longint;
 	Max_Linear_Speed:Longint;
begin
	Dimension:=4;
 	Distance_Array[0]:=10000;
 	Distance_Array[1]:=20000;
	Distance_Array[2]:=30000;
  Distance_Array[3]:=40000;
 	Max_Linear_Speed:=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move[0], Distance_Array[0], Max_Linear_Speed ));

end;

procedure TForm1.Btn_Linear_4Axes_Relateive_StopClick(Sender: TObject);
begin
  Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
end;



procedure TForm1.Btn_PointTable_StopClick(Sender: TObject);
begin
  Function_Result (APS_emg_stop(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable]));        
end;

procedure TForm1.Btn_SetPointTableClick(Sender: TObject);
var
	Index:Longint;
	LastIndex:Longint;
  AxisNo:Longint;
  PointData:POINT_DATA2;
begin
  Index:=0;
	LastIndex:=20;

	Function_Result (APS_set_point_table_mode2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 0 ));	//0:Single 1:continue

	for Index :=Index to (LastIndex-1) do
  begin
		for AxisNo:=0 to 3 do
    begin
				PointData.i32_pos[AxisNo]:= (Index+1) * 1000;	//Position data = Index * 10000;
    end;
  

  	if ((Index=0) or (Index=LastIndex)) then				//If Index be first or last index, initSpeed be 0.
    begin
			PointData.i32_initSpeed:=0;						// Start velocity	( pulse / s )
			PointData.i32_maxSpeed:=50000;					// Maximum velocity  ( pulse / s )
			PointData.i32_angle:=0;
    end
    else												//Others index iniSpeed and maxSpeed are the same.
    begin
			PointData.i32_initSpeed:=PointData.i32_maxSpeed;	// Start velocity	( pulse / s )
			PointData.i32_maxSpeed:=50000;				    // Maximum velocity  ( pulse / s )
		end;
		PointData.u32_dwell:=0;								// Dwell times       ( unit: ms )
		PointData.i32_opt:=1; // Option //0xABCD , D:0 absolute, 1:relative

		Function_Result (APS_set_point_table2( Dimension_For_PointTable,
											   Axis_ID_Array_For_PointTable[0],
											   Index,
											   PointData ));
		if FunctionFail=true then
    begin
			Break;
		end;

  end;
end;

procedure TForm1.Btn_PointTable_SingleIndexMoveClick(Sender: TObject);
begin
  Function_Result (APS_point_table_single_move2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], StrToInt(Edit_SetTargetIndex_ForSinglePointMove.Text)  ));
end;

procedure TForm1.Btn_PointTable_MoveALLClick(Sender: TObject);
var
   	Index:Longint;
	  LastIndex:Longint;
    AxisNo:Longint;
    PointData:POINT_DATA2;
begin
    Index:=0;
	  LastIndex:=20;

	  Function_Result (APS_set_point_table_mode2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 1 ));	//0:Single 1:continue

	  for Index := Index to (LastIndex-1) do
    begin
		  for AxisNo:=0 to 3 do
      begin
  				PointData.i32_pos[AxisNo]:= (Index+1) * 2000;	//Position data = Index * 10000;
  		end;

	  	if ((Index=0) or (Index=LastIndex))	then			//If Index be first or last index, initSpeed be 0.
      begin
  			  PointData.i32_initSpeed:=0;						// Start velocity	( pulse / s )
  		  	PointData.i32_maxSpeed:=50000;					// Maximum velocity  ( pulse / s )
  	  		PointData.i32_angle:=0;
      end
    	else												//Others index iniSpeed and maxSpeed are the same.
      begin
  			  PointData.i32_initSpeed:=PointData.i32_maxSpeed;	// Start velocity	( pulse / s )
    			PointData.i32_maxSpeed:=50000;				    // Maximum velocity  ( pulse / s )
  		end;

 	  	if (Index=(LastIndex-1)) then
      begin
         PointData.i32_opt:=$21; // Option //0xABCD , D:0 absolute, 1:relative
      end
      else
      begin
         PointData.i32_opt:=$01;    // Option //0xABCD , D:0 absolute, 1:relative
      end;

      PointData.u32_dwell:=0;								// Dwell times       ( unit: ms )

	  	Function_Result (APS_set_point_table2( Dimension_For_PointTable,
                       Axis_ID_Array_For_PointTable[0],
											 Index,
											 PointData ));
		  if FunctionFail= true then
      begin
  			Break;
  		end;

	 end;

	Function_Result (APS_point_table_continuous_move2( Dimension_For_PointTable, Axis_ID_Array_For_PointTable[0] ));
end;

procedure TForm1.Btn_Linear_CompareClick(Sender: TObject);
var
  StartPoint:Longint;
	RepeatTimes:Longint;
	Interval:Longint;
	LastIndex:Longint;
  Index:Longint;
begin
  StartPoint:=5000;
	RepeatTimes:=100;
	Interval:=100;
	LastIndex:=3;

	for Index:= 0 to LastIndex do
  begin
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_SRC  +  Index,  0 ));		//Compare source is from command counter.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_TYPE +  Index,  1 ));		//Compare type is Linear.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_TRG0_PWD  +  Index , 5 ));		//Trigger Width is 60nS
		Function_Result (APS_set_field_bus_trigger_linear( CardID, BusNo, MOD_No, Index, StartPoint, RepeatTimes, Interval ));   //Set Linear Data
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_EN   +  Index , 1 ));		//Enable Linear compare
		if (FunctionFail) then
    begin
			Break;
    end;

	end;

	Btn_Trigger_CountClick(Sender) ;		//Reset Trigger Counter, it's nt nerssery.
	ResetCounterClick(Sender) ;		        //Reset Axis Counter Counter, it's not nerssery.
	Btn_Linear_4Axes_RelateiveForwardClick(Sender) ;
end;

procedure TForm1.Btn_Trigger_CountClick(Sender: TObject);
var
  LastIndex:Longint;
  TrgCh:Longint;
begin
  LastIndex:= 3;

	for TrgCh:= 0 to LastIndex do
  begin
		Function_Result (APS_reset_field_bus_trigger_count( CardID, BusNo, MOD_No, TrgCh ));
		if (FunctionFail) then
    begin
			Break;
		end;
	end;
end;

procedure TForm1.Btn_Table_CompareClick(Sender: TObject);
var
  ArraySize:Longint;
	DataArray:array of Longint;
	LastIndex:Longint;
  Index:Longint;
  TableIndex:Longint;
begin
	ArraySize := 100;
  LastIndex:=3;
	SetLength(DataArray,ArraySize);


	for Index:= 0 to LastIndex do
  begin
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_SRC  +  Index,  0 ));		//Compare source is from command counter.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_TYPE +  Index,  0 ));		//Compare type is Table.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_TRG0_PWD  +  Index , 5 ));		//Trigger Width is 60nS

		for TableIndex:= 0 to 99 do														//Create Table Data
    begin
			DataArray[TableIndex] := 5000 + (TableIndex * 100);
		end;

		Function_Result (APS_set_field_bus_trigger_table( CardID, BusNo, MOD_No, Index, DataArray[0], ArraySize));		//Set Table Data
		Function_Result (APS_set_field_bus_trigger_param( CardID, BusNo, MOD_No, TG_CMP0_EN   +  Index ,  1 ));		//Enable Linear compare
		if (FunctionFail) then
    begin
			Break;
		end;
	end;

	Btn_Trigger_CountClick(Sender) ;		   //Reset Trigger Counter, it's not nerssery.
	ResetCounterClick(Sender) ;		        //Reset Axis Counter Counter, it's not nerssery.
	Btn_Linear_4Axes_RelateiveForwardClick(Sender) ;
end;

procedure TForm1.Btn_Manual_CompareClick(Sender: TObject);
var
  LastIndex:Longint;
  TrgCh:Longint;
begin
	LastIndex:=3;
	for TrgCh:= 0 to LastIndex do
  begin
		Function_Result (APS_set_field_bus_trigger_manual( CardID, BusNo, MOD_No, TrgCh ));
		if (FunctionFail) then
    begin
			Break;
		end;
	end;
end;

procedure TForm1.Btn_Arc_2Axes_Absolute_CCWClick(Sender: TObject);
var
  Dimension:Longint;
	Center_Pos_Array:array[0..1] of Longint;
	Max_Arc_Speed:Longint;
	Angle:Longint;
begin
  Dimension:=2;
	Center_Pos_Array[0]:=-20000;
  Center_Pos_Array[1]:=-20000;
	Max_Arc_Speed:=50000;
	Angle:=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result (APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove[0], Center_Pos_Array[0],  Max_Arc_Speed,  Angle ));
end;

procedure TForm1.Btn_Arc_2Axes_Absolute_CWClick(Sender: TObject);
var
  Dimension:Longint;
	Center_Pos_Array:array[0..1] of Longint;
	Max_Arc_Speed:Longint;
	Angle:Longint;
begin
  Dimension:=2;
	Center_Pos_Array[0]:=20000;
  Center_Pos_Array[1]:=20000;
	Max_Arc_Speed:=50000;
	Angle:=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result (APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove[0], Center_Pos_Array[0],  Max_Arc_Speed,  Angle ));

end;

procedure TForm1.Btn_Arc_2Axes_Relative_CCWClick(Sender: TObject);
var
  Dimension:Longint;
	Center_Dis_Array:array[0..1] of Longint;
	Max_Arc_Speed:Longint;
	Angle:Longint;
begin
  Dimension:=2;
	Center_Dis_Array[0]:=-20000;
  Center_Dis_Array[1]:=-20000;
	Max_Arc_Speed:=50000;
	Angle:=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result (APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove[0], Center_Dis_Array[0],  Max_Arc_Speed,  Angle ));

end;

procedure TForm1.Btn_Arc_2Axes_Relative_CWClick(Sender: TObject);
var
  Dimension:Longint;
	Center_Dis_Array:array[0..1] of Longint;
	Max_Arc_Speed:Longint;
	Angle:Longint;
begin
  Dimension:=2;
	Center_Dis_Array[0]:=20000;
  Center_Dis_Array[1]:=20000;
	Max_Arc_Speed:=50000;
	Angle:=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result (APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove[0], Center_Dis_Array[0],  Max_Arc_Speed,  Angle ));

end;

procedure TForm1.Btn_Arc_2Axes_Absolute_Stop2Click(Sender: TObject);
begin
  Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));
end;

procedure TForm1.Btn_Arc_2Axes_Relateive_StopClick(Sender: TObject);
begin
  Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));
end;

procedure TForm1.Btn_Set_DODataClick(Sender: TObject);
begin
  Function_Result (APS_set_field_bus_d_output(  CardID,
                                                BusNo,
                                                StrToInt(Edit_SetModuleID_ForGeneralDIO.Text),
                                                StrToInt(Edit_SetDOData.Text) ));
end;

end.
