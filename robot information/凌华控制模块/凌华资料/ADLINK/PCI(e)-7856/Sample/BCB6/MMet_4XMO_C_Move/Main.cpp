//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "APS168.h"
#include "APS_Define.h"

I16 CardID =0;	      //Card number for setting.
I16 BusNo  =1;        //Bus number for setting,  Motion Net BusNo is 0.
I32 MOD_No =0;		  //Arrcoding switch On Module.
I32 Start_Axis_ID=0;  //First Axis number in Motion Net bus.
I32 AxisID_SingleAxis_ForAbsolute= 0;
I32 AxisID_SingleAxis_ForRelative= 1;
I32 AxisID_SingleAxis_ForHome= 2;
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
    if (Ret != 0){
       ShowMessage(MsgStr);
       FunctionFail=true;
    }else{
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
	//Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	I32 DPAC_ID_Bits;
	I32 Info;
	if (APS_initial(&DPAC_ID_Bits, 0)==0){      //Initial Card, CardID is assigned by system.
		//Get Card information

		APS_get_device_info( CardID, 0x10, &Info );		//Get Driver Version
		Edit_ShowMaster_DriverVer->Text = IntToStr(Info);

		Edit_ShowMaster_DLLVer->Text =IntToStr(APS_version());  //Get DLL Version

		APS_get_device_info( CardID, 0x20, &Info );		//Get CPLD Version
		Edit_ShowMaster_CPLDVer->Text = IntToStr(Info);

        this->Timer1->Enabled = true ;

		//Set Motion Net Parameter
		Function_Result (APS_set_field_bus_param (CardID, BusNo, PRF_TRANSFER_RATE, 3));     //Set PRF_TRANSFER_RATE: 3 (12M)

	}else{
		ShowMessage("Initial Fail");
		APS_close();
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ResetCounterClick(TObject *Sender)
{
        I32 LastIndex=4;
	for (int AxisNo = Start_Axis_ID; AxisNo <LastIndex; AxisNo++){
           Function_Result (APS_set_command( AxisNo, 0));
           Function_Result (APS_set_position( AxisNo, 0 ));
           if (FunctionFail){
              break;
           }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_BusConnectClick(TObject *Sender)
{
Function_Result (APS_start_field_bus(CardID, BusNo, Start_Axis_ID));   	

	if (!FunctionFail){
		//Set Axis Parameter
		for (int AxisNo=Start_Axis_ID; AxisNo<4 ; AxisNo++){
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
		}

		ShowMessage("Bus Connected!!");
		bIsConnected=true;
		
	}else{
		FunctionFail=false;
		bIsConnected=false;
		ShowMessage( "Connect Fail!!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_BusDisconnectClick(TObject *Sender)
{
	Function_Result (APS_stop_field_bus(CardID, BusNo));

	if (!FunctionFail){
		ShowMessage("Bus Disconnect!!");
	}else{
		FunctionFail=false;
		ShowMessage("Disonnect Fail!!");
	}        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_GetModuleInfoClick(TObject *Sender)
{
	I32 Info;
	Function_Result (APS_get_field_bus_device_info( CardID,		//Get FPGA Version
                                                        BusNo,
                                                        Edit_SetModuleID_ForModuleInfo->Text.ToInt(),
                                                        0x21,
                                                        &Info ));
	Edit_ShowModule_FPGAVer->Text=IntToStr(Info);


	Function_Result (APS_get_field_bus_device_info( CardID,		//Get PCB Top Version
                                                        BusNo,
                                                        Edit_SetModuleID_ForModuleInfo->Text.ToInt(),
							0x30,
							&Info ));

	Edit_ShowModule_PCBTopVer->Text = IntToStr(Info);

	Function_Result (APS_get_field_bus_device_info( CardID,		//Get PCB Bottom Version
							BusNo,
                                                        Edit_SetModuleID_ForModuleInfo->Text.ToInt(),
							0x31,
							&Info ));
        Edit_ShowMaster_PCBBottomVer->Text = IntToStr(Info);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleAbsoluteMove_BackwardClick(
      TObject *Sender)
{
	I32 Position = -10000;
	I32 Max_Speed = 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleAbsoluteMove_ForwardClick(
      TObject *Sender)
{
	I32 Position = 10000;
	I32 Max_Speed = 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

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
	//Others setting like ACC,Dec... are  in the initial segmant.

	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleRelativeMove_ForwardClick(
      TObject *Sender)
{
	I32 Distance = 10000;
	I32 Max_Speed = 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

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
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));	        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SingleHomeMove_ForwardClick(TObject *Sender)
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	//Others setting like ACC,Dec... are in the initial segmant.

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
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));		        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_AbsoluteForwardClick(
      TObject *Sender)
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
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
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result ((APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));		        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_2Axes_RelateiveForwardClick(
      TObject *Sender)
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
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
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));		        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_AbsoluteForwardClick(
      TObject *Sender)
{
	I32 Dimension=3;
 	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
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
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_3Axes_RelateiveForwardClick(
      TObject *Sender)
{
        I32 Dimension=3;
	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
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
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_AbsoluteForwardClick(
      TObject *Sender)
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
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
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_RelateiveForwardClick(
      TObject *Sender)
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_4Axes_Relateive_StopClick(
      TObject *Sender)
{
        Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_SetPointTableClick(TObject *Sender)
{
	I32 Index=0;
	I32 LastIndex=20;
	POINT_DATA2 PointData;

	//I32 FNTYPE APS_set_point_table_mode2( I32 Axis_ID, I32 Mode );
	Function_Result (APS_set_point_table_mode2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 0 ));	//0:Single 1:continue

	for (Index =0; Index < LastIndex; Index++){
		for (int AxisNo=0; AxisNo<4 ; AxisNo++){
				PointData.i32_pos[AxisNo]= (Index+1) * 1000;	//Position data = Index * 10000;
		}

		if (Index==0) {				//If Index be first or last index, initSpeed be 0.
			PointData.i32_initSpeed=0;						// Start velocity	( pulse / s )
			PointData.i32_maxSpeed=50000;					// Maximum velocity  ( pulse / s )
			PointData.i32_angle=0;
		}else{												//Others index iniSpeed and maxSpeed are the same.
			PointData.i32_initSpeed=PointData.i32_maxSpeed;	// Start velocity	( pulse / s )
			PointData.i32_maxSpeed=50000;				    // Maximum velocity  ( pulse / s )
		}


                if (Index==(LastIndex-1)){
                        PointData.i32_opt=0x11; // Option //0xABCD , D:0 absolute, 1:relative
                }else{
                        PointData.i32_opt=1; // Option //0xABCD , D:0 absolute, 1:relative
		}

                PointData.u32_dwell=0;								// Dwell times       ( unit: ms )
                
		Function_Result (APS_set_point_table2( Dimension_For_PointTable, 
											   Axis_ID_Array_For_PointTable, 
											   Index, 
											   &PointData ));
		if (FunctionFail){
                    break;
		}

	}        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_PointTable_SingleIndexMoveClick(
      TObject *Sender)
{
	Function_Result (APS_point_table_single_move2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], Edit_SetTargetIndex_ForSinglePointMove->Text.ToInt()  ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_PointTable_StopClick(TObject *Sender)
{
        Function_Result (APS_emg_stop(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable]));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_PointTable_MoveALLClick(TObject *Sender)
{
	I32 Index=0;
	I32 LastIndex=20;
	POINT_DATA2 PointData;

	Function_Result (APS_set_point_table_mode2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 1 ));	//0:Single 1:continue

	for (Index =0; Index < LastIndex; Index++){
	    for (int AxisNo=0; AxisNo<4 ; AxisNo++){
	    	PointData.i32_pos[AxisNo]= (Index+1) * 2000;	//Position data = Index * 10000;
	    }

	    if (Index==0){				//If Index be first or last index, initSpeed be 0.
                PointData.i32_initSpeed=0;						// Start velocity	( pulse / s )
	        PointData.i32_maxSpeed=50000;					// Maximum velocity  ( pulse / s )
		PointData.i32_angle=0;
	    }else{												//Others index iniSpeed and maxSpeed are the same.
	        PointData.i32_initSpeed=PointData.i32_maxSpeed;	// Start velocity	( pulse / s )
	        PointData.i32_maxSpeed=50000;				    // Maximum velocity  ( pulse / s )
	    }

	    if (Index==(LastIndex-1)){
                PointData.i32_opt=0x21; // Option //0xABCD , D:0 absolute, 1:relative
            }else{
                PointData.i32_opt=0x01;    // Option //0xABCD , D:0 absolute, 1:relative
	    }

            PointData.u32_dwell=0;								// Dwell times       ( unit: ms )
		
	    Function_Result (APS_set_point_table2( Dimension_For_PointTable,
	    				           Axis_ID_Array_For_PointTable,
		        			   Index,
						   &PointData ));
            if (FunctionFail){
               break;
            }
	}
	Function_Result (APS_point_table_continuous_move2( Dimension_For_PointTable, Axis_ID_Array_For_PointTable ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Linear_CompareClick(TObject *Sender)
{
        I32 StartPoint=5000;
	I32 RepeatTimes=100;
	I32 Interval=100;
	I32 LastIndex=4;
	
	for (int Index=0; Index<LastIndex ;Index++){
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_SRC  +  Index,  0 ));		//Compare source is from command counter.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_TYPE +  Index,  1 ));		//Compare type is Linear.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_TRG0_PWD  +  Index , 5 ));		//Trigger Width is 60nS
		Function_Result (APS_set_field_bus_trigger_linear( CardID, BusNo, MOD_No, Index, StartPoint, RepeatTimes, Interval ));   //Set Linear Data
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_EN   +  Index , 1 ));		//Enable Linear compare
		if (FunctionFail){
                    break;
		}

	}

	Btn_Trigger_CountClick(Sender) ;		//Reset Trigger Counter, it's not nerssery.
	ResetCounterClick(Sender) ;		        //Reset Axis Counter Counter, it's not nerssery.
	Btn_Linear_4Axes_RelateiveForwardClick(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Trigger_CountClick(TObject *Sender)
{
        I32 LastIndex=4;
	for (int TrgCh=0; TrgCh<LastIndex ;TrgCh++){
		Function_Result (APS_reset_field_bus_trigger_count( CardID, BusNo, MOD_No, TrgCh ));
		if (FunctionFail){
			TrgCh=LastIndex+1;
			FunctionFail=false;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Table_CompareClick(TObject *Sender)
{
	I32 ArraySize = 100;
	I32 *DataArray = new I32 [ArraySize];
	I32 LastIndex=4;

	for (int Index=0; Index<LastIndex ;Index++){
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_SRC  +  Index,  0 ));		//Compare source is from command counter.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_TYPE +  Index,  0 ));		//Compare type is Table.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_TRG0_PWD  +  Index , 5 ));		//Trigger Width is 60nS

		for (int TableIndex=0; TableIndex<100; TableIndex++){														//Create Table Data
			DataArray[TableIndex] = 5000 + (TableIndex * 100);
		}

		Function_Result (APS_set_field_bus_trigger_table( CardID, BusNo, MOD_No, Index, DataArray, ArraySize));		//Set Table Data
		Function_Result (APS_set_field_bus_trigger_param( CardID, BusNo, MOD_No, TG_CMP0_EN   +  Index ,  1 ));		//Enable Linear compare
		if (FunctionFail){
                    break;
		}
	}

	delete DataArray;

	Btn_Trigger_CountClick(Sender) ;		//Reset Trigger Counter, it's not nerssery.
	ResetCounterClick(Sender) ;		        //Reset Axis Counter Counter, it's not nerssery.
	Btn_Linear_4Axes_RelateiveForwardClick(Sender) ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Manual_CompareClick(TObject *Sender)
{
	I32 LastIndex=4;
	for (int TrgCh=0; TrgCh<LastIndex ;TrgCh++){
		Function_Result (APS_set_field_bus_trigger_manual( CardID, BusNo, MOD_No, TrgCh ));
		if (FunctionFail){
                    break;;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    I32 Command;
	I32 Position;
	I32 MotionSts;
	I32 IoSts;
	I32 Index;
	I32 TrgCnt;
	I32 CmpVal;
	I32 EncCnt;
	I32 RunningPoint;
        I32 DOdada;
        I32 DI_Value;
        TEdit *CommandArray[4] = {Edit_ShowAxis_Command_0,Edit_ShowAxis_Command_1,Edit_ShowAxis_Command_2,Edit_ShowAxis_Command_3};
        TEdit *Feedback[4] =     {Edit_ShowAxis_Feedback_0,Edit_ShowAxis_Feedback_1,Edit_ShowAxis_Feedback_2,Edit_ShowAxis_Feedback_3};
        TEdit *IOSts[4] =        {Edit_ShowAxis_IOSts_0,Edit_ShowAxis_IOSts_1,Edit_ShowAxis_IOSts_2,Edit_ShowAxis_IOSts_3};
        TEdit *MSts[4] =         {Edit_ShowAxis_MSts_0,Edit_ShowAxis_MSts_1,Edit_ShowAxis_MSts_2,Edit_ShowAxis_MSts_3};
        TEdit *TriggerCount[4] = {Edit_ShowTriggerCount_0,Edit_ShowTriggerCount_1,Edit_ShowTriggerCount_2,Edit_ShowTriggerCount_3};
        TEdit *TriggerEnc[4] =   {Edit_ShowTriggerEnc_0,Edit_ShowTriggerEnc_1,Edit_ShowTriggerEnc_2,Edit_ShowTriggerEnc_3};
        TEdit *TriggerVal[4] =   {Edit_ShowTrigger_LinearCMP_LinearCMP_0,Edit_ShowTrigger_LinearCMP_LinearCMP_1,Edit_ShowTrigger_LinearCMP_LinearCMP_2,Edit_ShowTrigger_LinearCMP_LinearCMP_3};

	for (int index=0; index<4; index++){
		//Motion Segment
		APS_get_command( Start_Axis_ID + index, &Command );
		CommandArray[index]->Text = IntToStr(Command);

		APS_get_position( Start_Axis_ID + index, &Position );
		Feedback[index]->Text = IntToStr(Position);

		IoSts=APS_motion_io_status( Start_Axis_ID + index );
		IOSts[index]->Text = IntToHex((int)IoSts,8);

		MotionSts=APS_motion_status( Start_Axis_ID + index );
		MSts[index]->Text = IntToStr(MotionSts);

		APS_get_running_point_index2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], &RunningPoint );
		Edit_Show_PointTable_CurrIndex->Text = IntToStr(RunningPoint);

		//Compare Segment
	        APS_get_field_bus_trigger_count( CardID, BusNo, MOD_No, index, &TrgCnt );
		TriggerCount[index]->Text = IntToStr(TrgCnt);

		APS_get_field_bus_encoder( CardID, BusNo, MOD_No, index, &EncCnt );
		TriggerEnc[index]->Text = IntToStr(EncCnt);

		APS_get_field_bus_trigger_linear_cmp( CardID, BusNo, MOD_No, index, &CmpVal );
		TriggerVal[index]->Text = IntToStr(CmpVal);

                //General DIO
                APS_get_field_bus_d_input( CardID, BusNo, Edit_SetModuleID_ForGeneralDIO->Text.ToInt() , &DI_Value );
                Edit_ShowDIData->Text = IntToHex((int)DI_Value,2);

                APS_get_field_bus_d_output(  CardID, BusNo, Edit_SetModuleID_ForGeneralDIO->Text.ToInt(), &DOdada   );
                Edit_GetDOData->Text = IntToHex((int)DOdada,2);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Absolute_CCWClick(TObject *Sender)
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={-20000,-20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result (APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Absolute_CWClick(TObject *Sender)
{
        I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

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
	I32 Center_Dis_Array[2]={-20000,-20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result (APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Dis_Array,  Max_Arc_Speed,  Angle ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Relative_CWClick(TObject *Sender)
{
       	I32 Dimension=2;
	I32 Center_Dis_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result (APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Dis_Array,  Max_Arc_Speed,  Angle ));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Arc_2Axes_Relateive_StopClick(TObject *Sender)
{
       Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] )); 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Btn_Set_DODataClick(TObject *Sender)
{
       Function_Result (APS_set_field_bus_d_output(  CardID,
                                                     BusNo,
                                                     Edit_SetModuleID_ForGeneralDIO->Text.ToInt()  ,
                                                     Edit_SetDOData->Text.ToInt()   ));
}
//---------------------------------------------------------------------------

