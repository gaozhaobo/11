// Dialog_cmp_trig.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "Dialog_cmp_trig.h"


// Dialog_cmp_trig dialog

IMPLEMENT_DYNAMIC(Dialog_cmp_trig, CDialog)

Dialog_cmp_trig::Dialog_cmp_trig(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_cmp_trig::IDD, pParent)
{
	

}

Dialog_cmp_trig::~Dialog_cmp_trig()
{
}

void Dialog_cmp_trig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog_cmp_trig, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog_cmp_trig::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &Dialog_cmp_trig::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Dialog_cmp_trig::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Dialog_cmp_trig::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Dialog_cmp_trig::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Dialog_cmp_trig::OnBnClickedButton7)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// Dialog_cmp_trig message handlers




BOOL Dialog_cmp_trig::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	I32 i    = 0;



	for( i = 0; i < 4; i++ )
	{
		p_ShowTrigCnt[i] =  (CWnd*)GetDlgItem( EDIT_TrigCnt_0 + i  );
		p_ShowTrigCnt[i] -> EnableWindow( FALSE );
	}

	if( v_total_axis == 4 )       channel = 2;
	else if( v_total_axis == 8 )  channel = 4;

	for( i = 0; i < channel; i++ )
		p_ShowTrigCnt[i] -> EnableWindow( TRUE );

	p_Open  = NULL;
	p_Close = NULL; 
	


	this->SetTimer(1,1,NULL); // Enable Timer
	return TRUE;  
}

void Dialog_cmp_trig::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	I32 ret      = 0;
	I32 Board_ID = v_card_id; 
	I32 CH       = 0;
	
	
	// Enable trigger output
	if( channel == 2 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0x3 );
	else if( channel == 4 )
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
	for( CH = 0; CH < channel; CH++ )
		ret = APS_set_trigger_manual( Board_ID, CH );
	
	// Disable TRG 0 ~ 3
    ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0 );

	//Disable all CMP
	ret = APS_set_trigger_param( Board_ID, TGR_TRG0_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG1_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG2_SRC, 0 );
	ret = APS_set_trigger_param( Board_ID, TGR_TRG3_SRC, 0 );
}

void Dialog_cmp_trig::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	I32 Board_ID = v_card_id;
	I32 CH       = 0;
	I32 CH_num   = channel;
	I32 TrgCnt   = 0;
	I32 ret      = 0;
	I32 line_value   = 0;
	I32 Table_value  = 0;
	I32 Cnt          = 0;


	for( CH = 0; CH < CH_num; CH++ )
	{
		ret = APS_get_trigger_count( Board_ID, CH, &TrgCnt );
		SetDlgItemInt( EDIT_TrigCnt_0 + CH, TrgCnt );
	}

	for( CH = 0; CH < 2; CH++ )
	{
		ret = APS_get_trigger_linear_cmp(  Board_ID, CH, &line_value );
		SetDlgItemInt( EDIT_cmp_value_0 + CH, line_value );

		ret = APS_get_trigger_table_cmp(  Board_ID, CH, &Table_value );
		SetDlgItemInt( EDIT_table_0 + CH, Table_value );
	}

	ret = APS_get_timer_counter(  Board_ID, 0, &Cnt );
	SetDlgItemInt( IDC_EDIT1, Cnt );

	CDialog::OnTimer(nIDEvent);
}

void Dialog_cmp_trig::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	I32 ret      = 0;
	I32 Board_ID = v_card_id;
	I32 CH       = 0;

	for( CH = 0; CH < channel; CH++ )
		ret = APS_reset_trigger_count(  Board_ID, CH );
}

void Dialog_cmp_trig::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
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
	if( channel == 2 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0x3 );
	else if( channel == 4 )
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
void Dialog_cmp_trig::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	I32 ret      = 0;
	I32 Board_ID = v_card_id;

	//Stop Timer
	ret = APS_set_trigger_param( Board_ID, TIMR_EN   , 0 );
}

void Dialog_cmp_trig::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here

	I32 ret      = 0;
	I32 Board_ID = v_card_id;

	//Clear timer
	ret = APS_set_timer_counter(  Board_ID, 0, 0 );
}

void Dialog_cmp_trig::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here

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
	if( channel == 2 )
		ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0x3 );
	else if( channel == 4 )	
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

void Dialog_cmp_trig::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	I32 ret      = 0;
	I32 Board_ID = v_card_id;

	KillTimer(1);
	
	// Disable TRG 0 ~ 3
    ret = APS_set_trigger_param( Board_ID, TGR_TRG_EN, 0 );

	*p_Open  = NO;
	*p_Close = YES;

	p_bt_CmpTrig ->EnableWindow( TRUE );

	CDialog::OnClose();
}
