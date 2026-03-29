//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm5::FormCreate(TObject *Sender)
{
        Timer2->Enabled = true;
        
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
        Timer2->Enabled = false;

}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
        I32 ret      = 0;
	I32 Board_ID = v_card_id;
	I32 CH       = 0;

	for( CH = 0; CH < v_channel; CH++ )
		ret = APS_reset_trigger_count(  Board_ID, CH );
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
        I32 ret      = 0;
	I32 Board_ID = v_card_id;

	//Stop Timer
	ret = APS_set_trigger_param( Board_ID, TIMR_EN   , 0 );
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button3Click(TObject *Sender)
{
        I32 ret      = 0;
	I32 Board_ID = v_card_id;

	//Clear timer
	ret = APS_set_timer_counter(  Board_ID, 0, 0 );
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button4Click(TObject *Sender)
{
        I32 ret      = 0;
	I32 Board_ID = v_card_id;
	I32 CH       = 0;
	
	
	// Enable trigger output
	if( v_channel == 2 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0x3 );
	else if( v_channel == 4 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0xf );
	
	//Trigger output TRG0 ~ TRG3 source
	//Bit 0: Manual 
	//Bit 1: Reserved
	//Bit 2: FCMP0 
	//Bit 3: FCMP1 
	//Bit 4: LCMP0 
	//Bit 5: LCMP1
	ret = APS_set_trigger_param( Board_ID, TGR_TRG0_SRC, 0x1 );
        ret = APS_set_trigger_param( Board_ID, TGR_TRG1_SRC, 0x1 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG2_SRC, 0x1 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG3_SRC, 0x1 );

	//Start manual trigger
	for( CH = 0; CH < v_channel; CH++ )
		ret = APS_set_trigger_manual( Board_ID, CH );
	
	// Disable TRG 0 ~ 3
         ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0 );

	//Disable all CMP
	ret = APS_set_trigger_param( Board_ID, TGR_TRG0_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG1_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG2_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG3_SRC, 0 );
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button5Click(TObject *Sender)
{
        I32 ret      = 0;
	I32 Board_ID = v_card_id;
	I32 CH       = 0;
	I32 StartPoint  = 0;
	I32 RepeatTimes = 10;
	I32 Interval    = 1000;


	//Stop Timer
	ret = APS_set_trigger_param( Board_ID, TIMR_EN   , 0 );

	//Clear timer
	ret = APS_set_timer_counter(  Board_ID, 0, 0 );

	// Disable TRG 0 ~ 3
        ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0 );

        // Disable all CMP
	ret = APS_set_trigger_param( Board_ID, TGR_TRG0_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG1_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG2_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG3_SRC, 0 );

	//-----------------------------------------------------------

	// Enable TRG 0 ~ 3
	if( v_channel == 2 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0x3 );
	else if( v_channel == 4 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0xf );

	//Linear compare source: Timer counter 
	ret = APS_set_trigger_param( Board_ID, TGR_LCMP0_SRC, 8 );
	ret = APS_set_trigger_param( Board_ID, TGR_LCMP1_SRC, 8 );

	//Trigger output TRG0 ~ TRG3 source
	//Trigger output 0 source: LCMP0 
	//Trigger output 1 source: LCMP0 
	//Trigger output 2 source: LCMP1 
	//Trigger output 3 source: LCMP1
	ret = APS_set_trigger_param( Board_ID, TGR_TRG0_SRC, 0x10 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG1_SRC, 0x10 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG2_SRC, 0x20 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG3_SRC, 0x20 );
	
	//Start linear CMP
	for( CH = 0; CH < 2; CH++ )
		ret = APS_set_trigger_linear(  Board_ID, CH,  StartPoint,  RepeatTimes,  Interval );

	//Timer Interval: 1ms
	ret = APS_set_trigger_param( Board_ID, TIMR_ITV , 10000 );

	//TIMR DIR: Positive count
	ret = APS_set_trigger_param( Board_ID, TIMR_DIR  , 0 );

	//Start Timer
	ret = APS_set_trigger_param( Board_ID, TIMR_EN   , 1 );
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button6Click(TObject *Sender)
{
        I32 ret      = 0;
	I32 Board_ID = v_card_id;
	I32 CH       = 0;
	I32 i        = 0;
	I32 DataArr[10] = {0};
	I32 ArraySize = 10;

	//Stop Timer
	ret = APS_set_trigger_param( Board_ID, TIMR_EN   , 0 );

	//Clear timer
	ret = APS_set_timer_counter(  Board_ID, 0, 0 );

	// Disable TRG 0 ~ 3
         ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0 );

	//Disable all CMP
	ret = APS_set_trigger_param( Board_ID, TGR_TRG0_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG1_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG2_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG3_SRC, 0 );

	//------------------------------------------------------------

	// Enable trigger output
	if( v_channel == 2 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0x3 );
	else if( v_channel == 4 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0xf );

	//Linear compare source: Timer counter 
	ret = APS_set_trigger_param( Board_ID, TGR_TCMP0_SRC, 8 );
	ret = APS_set_trigger_param( Board_ID, TGR_TCMP1_SRC, 8 );

	//Table compare direction: Bi-direction(No direction)
	ret = APS_set_trigger_param( Board_ID, TGR_TCMP0_DIR , 2 );
	ret = APS_set_trigger_param( Board_ID, TGR_TCMP1_DIR , 2 );

	//Trigger output TRG0 ~ TRG3 source
	//Trigger output 0 source: FCMP0 
	//Trigger output 1 source: FCMP0 
	//Trigger output 2 source: FCMP1 
	//Trigger output 3 source: FCMP1
	ret = APS_set_trigger_param( Board_ID, TGR_TRG0_SRC, 0x4 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG1_SRC, 0x4 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG2_SRC, 0x8 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG3_SRC, 0x8 );

         for( i = 0; i < 10; i++ )
		*(DataArr+i) = i * 1000;

	//Start Table CMP
	for( CH = 0; CH < 2; CH++ )
		ret = APS_set_trigger_table(  Board_ID, CH, DataArr, ArraySize ); 

	//Timer Interval: 1ms
	ret = APS_set_trigger_param( Board_ID, TIMR_ITV , 10000 );

	//TIMR DIR: Positive count
	ret = APS_set_trigger_param( Board_ID, TIMR_DIR  , 0 );

	//Start Timer
	ret = APS_set_trigger_param( Board_ID, TIMR_EN   , 1 );
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Timer2Timer(TObject *Sender)
{
        I32 Board_ID = v_card_id;
	I32 CH       = 0;
	I32 CH_num   = v_channel;
	I32 TrgCnt   = 0;
	I32 ret      = 0;
	I32 line_value     = 0;
	I32 Table_value    = 0;
	I32 Cnt            = 0;


         ret = APS_get_trigger_count( Board_ID, 0, &TrgCnt );
         Label2->Caption = TrgCnt;
         ret = APS_get_trigger_count( Board_ID, 1, &TrgCnt );
         Label3->Caption = TrgCnt;

         if(CH_num==4)
         {
                ret = APS_get_trigger_count( Board_ID, 2, &TrgCnt );
                Label4->Caption = TrgCnt;
                ret = APS_get_trigger_count( Board_ID, 3, &TrgCnt );
                Label5->Caption = TrgCnt;
         }

         ret = APS_get_trigger_linear_cmp(  Board_ID, 0, &line_value );
         Label7->Caption = line_value;
         ret = APS_get_trigger_linear_cmp(  Board_ID, 1, &line_value );
         Label8->Caption = line_value;

         ret = APS_get_trigger_table_cmp(  Board_ID, 0, &Table_value );
         Label13->Caption = Table_value;
         ret = APS_get_trigger_table_cmp(  Board_ID, 1, &Table_value );
         Label9->Caption = Table_value;

	 ret = APS_get_timer_counter(  Board_ID, 0, &Cnt );
	 Label19->Caption = Cnt;
}
//---------------------------------------------------------------------------
