//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
        Timer1->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
        Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Timer1Timer(TObject *Sender)
{
	I32 Board_ID  = v_card_id;
	I32 CH        = 0; //Range is from 0 to 1
	I32 Frequency = 0; //Unit: Hz. Range is from 3 to 50000000.
	I32 Width     = 0; //Unit: ns. Range is from 20 to 335544300.
	I32 Status    = 0;
        I32 tmp       = 0;


        APS_get_pwm_frequency( Board_ID,  0, &Frequency );
        Label3->Caption = Frequency;
        APS_get_pwm_frequency( Board_ID,  1, &Frequency );
        Label11->Caption = Frequency;

        if( v_channel == 4 )
        {
                APS_get_pwm_frequency( Board_ID,  2, &Frequency );
                Label10->Caption = Frequency;
                APS_get_pwm_frequency( Board_ID,  3, &Frequency );
                Label9->Caption = Frequency;
        }


        APS_get_pwm_width(  Board_ID, 0, &Width );
        Label8->Caption = Width;
        APS_get_pwm_width(  Board_ID, 1, &Width );
        Label7->Caption = Width;

         if( v_channel == 4 )
         {
                APS_get_pwm_width(  Board_ID, 2, &Width );
                Label6->Caption = Width;
                APS_get_pwm_width(  Board_ID, 3, &Width );
                Label5->Caption = Width;
         }

         APS_get_trigger_count(Board_ID, 0, &tmp );
         Label19->Caption = tmp;
         APS_get_trigger_count(Board_ID, 1, &tmp );
         Label20->Caption = tmp;

         if( v_channel == 4 )
         {
                APS_get_trigger_count(Board_ID, 2, &tmp );
                Label21->Caption = tmp;
                APS_get_trigger_count(Board_ID, 3, &tmp );
                Label22->Caption = tmp;
         }

	//---------------------------
	// Get VAO status by bit
	//
	// Bit 0~7: Table 0~7 is active.   
        // Bit 8~15: Reserved
        // Bit 16: PWM 0 is enabling.
        // Bit 17: PWM 1 is enabling.
        // Bit 18~: Reserved
	//---------------------------
	APS_get_vao_status( Board_ID, &Status );
        Label16->Caption = Status;


}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button4Click(TObject *Sender)
{
        I32 ret      = 0;
	I32 Board_ID = v_card_id;
	I32 CH       = 0;

	for( CH = 0; CH < v_channel; CH++ )
		ret = APS_reset_trigger_count(  Board_ID, CH );
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{

                ShowMessage( "Thread be created.\n PWM will output." );
                pWaitInt = new TWaitInt_pwm(this);
                pWaitInt->v_card_id = v_card_id;
                pWaitInt->v_channel = v_channel;
                pWaitInt->Resume();
}
//---------------------------------------------------------------------------
__fastcall TWaitInt_pwm::TWaitInt_pwm(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TWaitInt_pwm::Execute()
{
        //---- Place thread code here ----
        I32 board_id = this->v_card_id;
        I32 channel  = this->v_channel;

        ThreadProc_PWM(  board_id,  channel );
}

void __fastcall TForm4::Button2Click(TObject *Sender)
{
        I32 ret = 0;
	I32 Board_ID  = v_card_id;
        I32 ON  = 1;
        I32 OFF = 0;

	//VAO table number. Range is 0 ~ 7.
	I32 Table_No = 0;

	//Minimum linear speed
	I32 MinVelocity = 1000;

	//Minimum linear speed
	I32 VelInterval = 1000;

	//Total points. Range is 1 ~ 32
	I32 TotalPoints = 2;

	//Output data array
	// 500  -> 25% duty
	// 1000 -> 50% duty
	I32 MappingDataArray[2] = {500,1000};

	I32 Status = 0;


	//****************************************************************
	// Set output type of Table[0]
	//
	// 0: output voltage.(reserved)
	// 1: Fix frequency, change duty ratio.  
	// 2: Fix pulse width, change frequency. 
	// 3: Fix duty ratio, change frequency.  
	//****************************************************************
	APS_set_vao_param(  Board_ID, 0x0, 1 );

    //****************************************************************
	// Set input reference of Table[0]
	//
	// 0: feedback speed. 
	// 1: command speed.  
	//****************************************************************
	APS_set_vao_param(  Board_ID, 0x1, 1 );

    //****************************************************************
	// Configure PWM according to output type in Table[0]. 
	//
	// If you set output type as voltage mode.(output type = 0)
	//		This value is don't care.
	//
	// If output type = 1 (Fix frequency, change duty ratio.  )
	//      frequency Range: 3 ~ 50M Hz
	//      
	// If output type = 2 (Fix pulse width, change frequency. )
	//		pulse width Range: 20 ~ 335544300 ns
	//
	// If output type = 3 (Fix duty ratio, change frequency.  )
	//		duty cycle Range:   1 ~ 2000 (0%~100%)
	//
	//****************************************************************
	APS_set_vao_param(  Board_ID, 0x10, 1000 );

	//Specify axisID for VAO Table[0].
	APS_set_vao_param(  Board_ID, 0x20, 0x1 );


	//set Table[0] parameters
	APS_set_vao_table(  Board_ID,  Table_No,  MinVelocity,  VelInterval,  TotalPoints, MappingDataArray );

	//check parameters of VAO Table[0]
	APS_check_vao_param(  Board_ID, Table_No, &Status );

	if( Status == 0 )
		ShowMessage( "VAO Setting Ok" );
	else
		ShowMessage( "VAO Setting Failed" );

	//Specify which table be executed
	//if Table_No = -1 that disable all tables.
	APS_switch_vao_table(  Board_ID,  Table_No  );

	//Enable outputs
        APS_start_vao(  Board_ID, 0, ON );
	APS_start_vao(  Board_ID, 1, ON );
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
        I32 Board_ID  = v_card_id;
        I32 ON  = 1;
        I32 OFF = 0;

	//VAO table number. Range is 0 ~ 7.
	I32 Table_No = -1;


	//Disable all tables.
	APS_switch_vao_table(  Board_ID,  Table_No  );

	//Disable outputs
	APS_start_vao(  Board_ID, 0, OFF );
	APS_start_vao(  Board_ID, 1, OFF );
	
	ShowMessage( "VAO off" );

}
//---------------------------------------------------------------------------

