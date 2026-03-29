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
    Label15: TLabel;
    Label19: TLabel;
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
    Timer1: TTimer;
    GroupBox19: TGroupBox;
    Btn_Arc_2Axes_Absolute_CCW: TButton;
    Btn_Arc_2Axes_Absolute_CW: TButton;
    Btn_Arc_2Axes_Absolute_Stop2: TButton;
    GroupBox20: TGroupBox;
    Btn_Arc_2Axes_Relative_CCW: TButton;
    Btn_Arc_2Axes_Relative_CW: TButton;
    Btn_Arc_2Axes_Relateive_Stop: TButton;
    GroupBox1: TGroupBox;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Edit_ShowMaster_DriverVer: TEdit;
    Edit_ShowMaster_DLLVer: TEdit;
    Edit_ShowMaster_CPLDVer: TEdit;
    Edit1: TEdit;
    Button1: TButton;
    Label4: TLabel;
    Label5: TLabel;

    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Function_Result(Ret:Longint);
    procedure ResetCounterClick(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);



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
    procedure Btn_Arc_2Axes_Absolute_CCWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Absolute_CWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Relative_CCWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Relative_CWClick(Sender: TObject);
    procedure Btn_Arc_2Axes_Absolute_Stop2Click(Sender: TObject);
    procedure Btn_Arc_2Axes_Relateive_StopClick(Sender: TObject);

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
TotalCard:Smallint =0;
CardID:Smallint =0;	      //Card number for setting.
BusNo:Smallint  =1;        //Bus number for setting,  Motion Net BusNo is 0.
MOD_No:Smallint =0;		  //Arrcoding switch On Module.
Start_Axis_ID:Longint=0;  //First Axis number in Motion Net bus.

AxisID_SingleAxis_ForAbsolute:Longint= 0;
AxisID_SingleAxis_ForRelative:Longint= 0;
AxisID_SingleAxis_ForHome:Longint= 0;

Axis_ID_Array_For_2Axes_Move:array [0..1] of Longint=(0,1);
Axis_ID_Array_For_2Axes_ArcMove:array [0..1] of Longint=(0,1);
Axis_ID_Array_For_3Axes_Move:array [0..2] of Longint=(0,1,2);
Axis_ID_Array_For_4Axes_Move:array [0..3] of Longint=(0,1,2,3);

FunctionFail:bool =false;       



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
  AxisNo:Longint;
  i:Longint;
  a:Longint;
  card_name:Longint;

begin

    CardID := 0;
    Start_Axis_ID := 0;

    AxisID_SingleAxis_ForAbsolute := Start_Axis_ID;
    AxisID_SingleAxis_ForRelative := Start_Axis_ID;
    AxisID_SingleAxis_ForHome := Start_Axis_ID;

    Axis_ID_Array_For_2Axes_Move[0] := Start_Axis_ID;
    Axis_ID_Array_For_2Axes_Move[1] := Start_Axis_ID +1;

    Axis_ID_Array_For_2Axes_ArcMove[0] := Start_Axis_ID;
    Axis_ID_Array_For_2Axes_ArcMove[1] := Start_Axis_ID +1;

    Axis_ID_Array_For_3Axes_Move[0] := Start_Axis_ID;
    Axis_ID_Array_For_3Axes_Move[1] := Start_Axis_ID +1;
    Axis_ID_Array_For_3Axes_Move[2] := Start_Axis_ID +2;

    Axis_ID_Array_For_4Axes_Move[0] := Start_Axis_ID;
    Axis_ID_Array_For_4Axes_Move[1] := Start_Axis_ID +1;
    Axis_ID_Array_For_4Axes_Move[2] := Start_Axis_ID +2;
    Axis_ID_Array_For_4Axes_Move[3] := Start_Axis_ID +3;

  //Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


	if (APS_initial(DPAC_ID_Bits, 0)=0)then	begin     //Initial Card, CardID is assigned by system.
    for i := 0 to 15 do begin
		a := DPAC_ID_Bits and (1 shl i);
		if( a=1 )then begin
			APS_get_card_name(CardID,card_name);
			if( card_name = 18 )then begin
				TotalCard := TotalCard + 1;
				break;
			end
		end;
    end;

		//Get Card information
		APS_get_device_info( CardID, $10, Info );		//Get Driver Version
		Edit_ShowMaster_DriverVer.Text := IntToStr(Info);

		Edit_ShowMaster_DLLVer.Text :=IntToStr(APS_version());  //Get DLL Version

		APS_get_device_info( CardID, $20, Info );		//Get CPLD Version
		Edit_ShowMaster_CPLDVer.Text := IntToStr(Info);

    //*****************************************************************************
       for AxisNo := 0 to (4*TotalCard-1) do
       begin
              Function_Result (APS_set_servo_on(AxisNo, 1));                  //servo ON
              Function_Result (APS_set_axis_param(AxisNo, 0, 0));             //PEL/MEL input logic
              Function_Result (APS_set_axis_param(AxisNo, 4, 0));             //Set PRA_ALM_LOGIC

              Function_Result (APS_set_axis_param(AxisNo, 128, 3));           //Set PRA_PLS_IPT_MODE(The user must make change based on actual conditions)
              Function_Result (APS_set_axis_param(AxisNo, 129, 4));           //Set PRA_PLS_OPT_MODE(The user must make change based on actual conditions)


              //Set Single Move Parameter
              Function_Result (APS_set_axis_param(AxisNo, 33, 1000000));      //Set Acceleration rate
              Function_Result (APS_set_axis_param(AxisNo, 34, 1000000));      //Set Deceleration rate
              Function_Result (APS_set_axis_param(AxisNo, 35, 0));            //Set Start velocity
              Function_Result (APS_set_axis_param(AxisNo, 32, 1));            //Set S-Curve

            
              //Set Home Move Parameter
              Function_Result (APS_set_axis_param(AxisNo, 16, 0));             //Set Home mode (Home search 1st mode)
              Function_Result (APS_set_axis_param(AxisNo, 21, 10000));         //Set Homing maximum Velocity (Unit:pulse/sec)
              Function_Result (APS_set_axis_param(AxisNo, 25, 152));           //Set Homing leave home Velocity (Unit:pulse/sec)
              Function_Result (APS_set_axis_param(AxisNo, 24, 0));             //Set Specify the EZ count up Value
            
              Function_Result (APS_set_axis_param(AxisNo, 26, 100));           //Set Homing leave home distance.Specify ORG Offset (Unit:pulse)


              //Set EMG logic
              Function_Result (APS_set_axis_param(AxisNo, 561, 0));            //Set EMG input
              
       end;
    //*****************************************************************************
     ShowMessage('Initial Success!!');
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

   AxisNo:Longint;
begin


	for AxisNo := Start_Axis_ID to (Start_Axis_ID+3) do
  begin
		Function_Result (APS_set_command( AxisNo, 0));
		Function_Result (APS_set_position( AxisNo, 0 ));

  end;

end;

procedure TForm1.Timer1Timer(Sender: TObject);
  var
    Command:Longint;
  	Position:Longint;
  	MotionSts:Longint;
  	IoSts:Longint;
  	Index:Longint;

    CommandArray:array[0..3] of TEdit;
    Feedback:array[0..3] of TEdit;
    IOStsArray:array[0..3] of TEdit;
    MSts:array[0..3] of TEdit;


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
		MSts[index].Text := IntToHex(MotionSts,8);

   end;

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

procedure TForm1.Button1Click(Sender: TObject);
begin

    CardID := StrToInt(Edit1.Text);
    Start_Axis_ID := CardID*4;

    AxisID_SingleAxis_ForAbsolute := Start_Axis_ID;
    AxisID_SingleAxis_ForRelative := Start_Axis_ID;
    AxisID_SingleAxis_ForHome := Start_Axis_ID;

    Axis_ID_Array_For_2Axes_Move[0] := Start_Axis_ID;
    Axis_ID_Array_For_2Axes_Move[1] := Start_Axis_ID +1;

    Axis_ID_Array_For_2Axes_ArcMove[0] := Start_Axis_ID;
    Axis_ID_Array_For_2Axes_ArcMove[1] := Start_Axis_ID +1;

    Axis_ID_Array_For_3Axes_Move[0] := Start_Axis_ID;
    Axis_ID_Array_For_3Axes_Move[1] := Start_Axis_ID +1;
    Axis_ID_Array_For_3Axes_Move[2] := Start_Axis_ID +2;

    Axis_ID_Array_For_4Axes_Move[0] := Start_Axis_ID;
    Axis_ID_Array_For_4Axes_Move[1] := Start_Axis_ID +1;
    Axis_ID_Array_For_4Axes_Move[2] := Start_Axis_ID +2;
    Axis_ID_Array_For_4Axes_Move[3] := Start_Axis_ID +3;

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



















procedure TForm1.Btn_Arc_2Axes_Absolute_CCWClick(Sender: TObject);
var
  Dimension:Longint;
	Center_Pos_Array:array[0..1] of Longint;
	Max_Arc_Speed:Longint;
	Angle:Longint;
begin
  Dimension:=2;
	Center_Pos_Array[0]:= 20000;
  Center_Pos_Array[1]:= 20000;
	Max_Arc_Speed:=50000;
	Angle:=180;


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
	Angle:=(-180);


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
	Center_Dis_Array[0]:= 20000;
  Center_Dis_Array[1]:= 20000;
	Max_Arc_Speed:=50000;
	Angle:=180;
	

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
	Angle:=(-180);
	

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



end.
