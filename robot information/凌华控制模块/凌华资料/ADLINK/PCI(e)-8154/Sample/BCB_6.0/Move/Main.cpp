//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "APS168.h"
#include "APS_Define.h"
#include "ErrorCodeDef.h"
#include "type_def.h"
#include "Main.h"


I16 CardID =0;	      //Card number for setting.
I16 BusNo  =1;        //Bus number for setting,  Motion Net BusNo is 1.
I32 MOD_No =0;		  //Arrcoding switch On Module.
I32 Start_Axis_ID=0;  //First Axis number in Motion Net bus.
I32 TotalCard=0;

I32 AxisID_SingleAxis_ForAbsolute= 0;
I32 AxisID_SingleAxis_ForRelative= 0;
I32 AxisID_SingleAxis_ForHome= 0;

I32 AxisID_FirstAxis_For_PointTable=0;
I32 Dimension_For_PointTable=4;;

I32 Axis_ID_Array_For_2Axes_Move[2]={0,1};
I32 Axis_ID_Array_For_2Axes_ArcMove[2]={0,1};
I32 Axis_ID_Array_For_3Axes_Move[3]={0,1,2};
I32 Axis_ID_Array_For_4Axes_Move[4]={0,1,2,3};
I32 Axis_ID_Array_For_PointTable[4]={0,1,2,3};

bool FunctionFail=false;
bool bIsConnected=false;
I32 CurrectSelAxis=0;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

//---------------------------------------------------------------------------
void __fastcall TForm1::Function_Result(int Ret)
{
    char MsgStr[]="Error Code = ";
    char Buff[256];
    itoa(Ret,Buff,10);
    strcat(MsgStr,Buff);

    if (Ret != 0)
    {
       ShowMessage(MsgStr);
       FunctionFail=true;
    }
    else
    {
       FunctionFail=false;
    }

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

        CardID =0;
        Start_Axis_ID=0;

        AxisID_SingleAxis_ForAbsolute= Start_Axis_ID;
        AxisID_SingleAxis_ForRelative= Start_Axis_ID;
        AxisID_SingleAxis_ForHome= Start_Axis_ID;

        Axis_ID_Array_For_2Axes_Move[0]=Start_Axis_ID;
        Axis_ID_Array_For_2Axes_Move[1]=Start_Axis_ID+1;

        Axis_ID_Array_For_2Axes_ArcMove[0]=Start_Axis_ID;
        Axis_ID_Array_For_2Axes_ArcMove[1]=Start_Axis_ID+1;

        Axis_ID_Array_For_3Axes_Move[0]=Start_Axis_ID;
        Axis_ID_Array_For_3Axes_Move[1]=Start_Axis_ID+1;
        Axis_ID_Array_For_3Axes_Move[2]=Start_Axis_ID+2;

        Axis_ID_Array_For_4Axes_Move[0]=Start_Axis_ID;
        Axis_ID_Array_For_4Axes_Move[1]=Start_Axis_ID+1;
        Axis_ID_Array_For_4Axes_Move[2]=Start_Axis_ID+2;
        Axis_ID_Array_For_4Axes_Move[3]=Start_Axis_ID+3;

	//Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	I32 DPAC_ID_Bits;
	I32 Info;
        I32 AxisNo;
        I32 i;

	if (APS_initial(&DPAC_ID_Bits, 0)==0)
        {
                 for(i=0; i<16; i++)
                {
                  if( DPAC_ID_Bits & (1<<i) )
                  TotalCard = TotalCard + 1;
                }

		APS_get_device_info( CardID, 0x10, &Info );		//Get Driver Version
		Edit_ShowMaster_DriverVer->Text = IntToStr(Info);

		Edit_ShowMaster_DLLVer->Text =IntToStr(APS_version());  //Get DLL Version

		APS_get_device_info( CardID, 0x20, &Info );		//Get CPLD Version
		Edit_ShowMaster_CPLDVer->Text = IntToStr(Info);


                ///Set Axis Parameter//////////////////////////////////////////////////////
                for(AxisNo=0; AxisNo<(4*TotalCard); AxisNo++)
                {
                    Function_Result (APS_set_servo_on(AxisNo, 1));         //servo ON

                    Function_Result (APS_set_axis_param(AxisNo, 0, 0));    //PEL/MEL input logic
                    Function_Result (APS_set_axis_param(AxisNo, 4, 0));    //Set PRA_ALM_LOGIC

                    Function_Result (APS_set_axis_param(AxisNo, 128, 3));   //Set PRA_PLS_IPT_MODE(The user must make change based on actual conditions)
                    Function_Result (APS_set_axis_param(AxisNo, 129, 4));   //Set PRA_PLS_OPT_MODE(The user must make change based on actual conditions)


                    Function_Result (APS_set_axis_param(AxisNo, 33, 1000000));   //Set Acceleration rate
                    Function_Result (APS_set_axis_param(AxisNo, 34, 1000000));   //Set Deceleration rate
                    Function_Result (APS_set_axis_param(AxisNo, 35, 0));         //Set Start velocity
                    Function_Result (APS_set_axis_param(AxisNo, 32, 1));         //Set S-Curve

                    Function_Result (APS_set_axis_param(AxisNo, 16, 0));         //Set Home mode (Home search 1st mode)
                    Function_Result (APS_set_axis_param(AxisNo, 21, 10000));     //Set Homing maximum Velocity (Unit:pulse/sec)
                    Function_Result (APS_set_axis_param(AxisNo, 25, 152));       //Set Homing leave home Velocity (Unit:pulse/sec)
                    Function_Result (APS_set_axis_param(AxisNo, 24, 0));         //Set Specify the EZ count up Value
                    Function_Result (APS_set_axis_param(AxisNo, 26, 100));       //Set Homing leave home distance.Specify ORG Offset (Unit:pulse)

                    Function_Result (APS_set_axis_param(AxisNo, 561, 0));        //Select gpio input
                  //Function_Result (APS_set_axis_param(AxisNo, 562, 1));        //Set EMG logic (0:Active Low /1:Active High)
                }
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                ShowMessage("Initial Success!!");
                
	}
        else
        {
		ShowMessage("Initial Fail");
		APS_close();
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetCounterClick(TObject *Sender)
{

        I32 AxisNo;


	for (AxisNo = Start_Axis_ID; AxisNo <=(Start_Axis_ID+3); AxisNo++)
        {
           Function_Result (APS_set_command( AxisNo, 0));
           Function_Result (APS_set_position( AxisNo, 0 ));

	}
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleAbsoluteMove_BackwardClick(
      TObject *Sender)
{
	I32 Position = -10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleAbsoluteMove_ForwardClick(
      TObject *Sender)
{
	I32 Position = 10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleAbsoluteMove_StopClick(TObject *Sender)
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForAbsolute ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleRelativeMove_BackwardClick(
      TObject *Sender)
{
        I32 Distance = -10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleRelativeMove_ForwardClick(
      TObject *Sender)
{
	I32 Distance = 10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleRelativeMove_StopClick(TObject *Sender)
{
        Function_Result (APS_emg_stop( AxisID_SingleAxis_ForRelative ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleHomeMove_BackwardClick(TObject *Sender)
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1));   //Set PRA_HOME_DIR   0:Positive 1:Negative
	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleHomeMove_ForwardClick(TObject *Sender)
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleHomeMove_StopClick(TObject *Sender)
{
        Function_Result (APS_emg_stop( AxisID_SingleAxis_ForHome ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_AbsoluteBackwardClick(
      TObject *Sender)
{
	I32 Dimension=2;
 	I32 Position_Array[2]={-10000,-20000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_AbsoluteForwardClick(
      TObject *Sender)
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result ((APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_AbsoluteStopClick(TObject *Sender)
{
	Function_Result ((APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0])));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_RelateiveBackwardClick(
      TObject *Sender)
{
        I32 Dimension=2;
 	I32 Position_Array[2]={-10000,-20000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result ((APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_RelateiveForwardClick(
      TObject *Sender)
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_Relateive_StopClick(
      TObject *Sender)
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0]));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_AbsoluteBackwardClick(
      TObject *Sender)
{
	I32 Dimension=3;
 	I32 Position_Array[3]={-10000,-20000,-30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_AbsoluteForwardClick(
      TObject *Sender)
{
	I32 Dimension=3;
 	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_AbsoluteStopClick(TObject *Sender)
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_RelateiveBackwardClick(
      TObject *Sender)
{
	I32 Dimension=3;
 	I32 Position_Array[3]={-10000,-20000,-30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_RelateiveForwardClick(
      TObject *Sender)
{
        I32 Dimension=3;
	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_Relateive_StopClick(
      TObject *Sender)
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_AbsoluteBackwardClick(
      TObject *Sender)
{
	I32 Dimension=4;
 	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_AbsoluteForwardClick(
      TObject *Sender)
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_AbsoluteStopClick(TObject *Sender)
{
        Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_RelateiveBackwardClick(
      TObject *Sender)
{
	I32 Dimension=4;
 	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_RelateiveForwardClick(
      TObject *Sender)
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_Relateive_StopClick(
      TObject *Sender)
{
        Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        I32 Command;
	I32 Position;
	I32 MotionSts;
	I32 IoSts;
	I32 Index;

        TEdit *CommandArray[4] = {Edit_ShowAxis_Command_0,Edit_ShowAxis_Command_1,Edit_ShowAxis_Command_2,Edit_ShowAxis_Command_3};
        TEdit *Feedback[4] =     {Edit_ShowAxis_Feedback_0,Edit_ShowAxis_Feedback_1,Edit_ShowAxis_Feedback_2,Edit_ShowAxis_Feedback_3};
        TEdit *IOSts[4] =        {Edit_ShowAxis_IOSts_0,Edit_ShowAxis_IOSts_1,Edit_ShowAxis_IOSts_2,Edit_ShowAxis_IOSts_3};
        TEdit *MSts[4] =         {Edit_ShowAxis_MSts_0,Edit_ShowAxis_MSts_1,Edit_ShowAxis_MSts_2,Edit_ShowAxis_MSts_3};


	for (int index=0; index<4; index++)
        {
		//Motion Segment
		APS_get_command( Start_Axis_ID + index, &Command );
		CommandArray[index]->Text = IntToStr(Command);

		APS_get_position( Start_Axis_ID + index, &Position );
		Feedback[index]->Text = IntToStr(Position);

		IoSts=APS_motion_io_status( Start_Axis_ID + index );
		IOSts[index]->Text = IntToHex((int)IoSts,8);

		MotionSts=APS_motion_status( Start_Axis_ID + index );

                MSts[index]->Text =IntToHex((int)MotionSts,8);

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Absolute_CCWClick(TObject *Sender)
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle= 180;
	Function_Result (APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Absolute_CWClick(TObject *Sender)
{
        I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000;
	I32 Angle=(-180);
	Function_Result (APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Absolute_Stop2Click(TObject *Sender)
{
        Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));	        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Relative_CCWClick(TObject *Sender)
{
	I32 Dimension=2;
	I32 Center_Dis_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle= 180;
	Function_Result (APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Dis_Array,  Max_Arc_Speed,  Angle ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Relative_CWClick(TObject *Sender)
{
       	I32 Dimension=2;
	I32 Center_Dis_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle= (-180);
	Function_Result (APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Dis_Array,  Max_Arc_Speed,  Angle ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Relateive_StopClick(TObject *Sender)
{
       Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  CardID = Edit1->Text.ToInt();
  Start_Axis_ID = CardID*4;

  AxisID_SingleAxis_ForAbsolute= Start_Axis_ID;
  AxisID_SingleAxis_ForRelative= Start_Axis_ID;
  AxisID_SingleAxis_ForHome= Start_Axis_ID;

  Axis_ID_Array_For_2Axes_Move[0]=Start_Axis_ID;
  Axis_ID_Array_For_2Axes_Move[1]=Start_Axis_ID+1;

  Axis_ID_Array_For_2Axes_ArcMove[0]=Start_Axis_ID;
  Axis_ID_Array_For_2Axes_ArcMove[1]=Start_Axis_ID+1;

  Axis_ID_Array_For_3Axes_Move[0]=Start_Axis_ID;
  Axis_ID_Array_For_3Axes_Move[1]=Start_Axis_ID+1;
  Axis_ID_Array_For_3Axes_Move[2]=Start_Axis_ID+2;

  Axis_ID_Array_For_4Axes_Move[0]=Start_Axis_ID;
  Axis_ID_Array_For_4Axes_Move[1]=Start_Axis_ID+1;
  Axis_ID_Array_For_4Axes_Move[2]=Start_Axis_ID+2;
  Axis_ID_Array_For_4Axes_Move[3]=Start_Axis_ID+3;
}
//---------------------------------------------------------------------------

