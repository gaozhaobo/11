// CmpTrig.cpp : implementation file
//

#include "stdafx.h"
#include "basic_sample.h"
#include "CmpTrig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCmpTrig dialog


CCmpTrig::CCmpTrig(CWnd* pParent /*=NULL*/)
	: CDialog(CCmpTrig::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCmpTrig)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCmpTrig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCmpTrig)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCmpTrig, CDialog)
	//{{AFX_MSG_MAP(CCmpTrig)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, reset)
	ON_BN_CLICKED(IDC_BUTTON26, stop)
	ON_BN_CLICKED(IDC_BUTTON27, clear)
	ON_BN_CLICKED(IDC_BUTTON2, manual)
	ON_BN_CLICKED(IDC_BUTTON25, linear)
	ON_BN_CLICKED(IDC_BUTTON3, table)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCmpTrig message handlers

int CCmpTrig::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	SetTimer( 0, 1, NULL );
	
	return 0;
}

void CCmpTrig::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	KillTimer(0);
	
	CDialog::OnClose();
}

void CCmpTrig::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	I32 Board_ID = v_board_id;
	I32 CH       = 0;
	I32 CH_num   = v_channel;
	I32 TrgCnt   = 0;
	I32 ret      = 0;
	I32 line_value   = 0;
	I32 Table_value  = 0;
	I32 Cnt          = 0;


	for( CH = 0; CH < CH_num; CH++ )
	{
		ret = APS_get_trigger_count( Board_ID, CH, &TrgCnt );
		SetDlgItemInt( EDIT_Trig_Cnt_0 + CH, TrgCnt );
	}

	for( CH = 0; CH < 2; CH++ )
	{
		ret = APS_get_trigger_linear_cmp(  Board_ID, CH, &line_value );
		SetDlgItemInt( EDIT_line_value_0 + CH, line_value );

		ret = APS_get_trigger_table_cmp(  Board_ID, CH, &Table_value );
		SetDlgItemInt( EDIT_table_value_0 + CH, Table_value );
	}

	ret = APS_get_timer_counter(  Board_ID, 0, &Cnt );
	SetDlgItemInt( EDIT_timer, Cnt );


	CDialog::OnTimer(nIDEvent);
}

void CCmpTrig::reset() 
{
	// TODO: Add your control notification handler code here
	

	I32 ret      = 0;
	I32 Board_ID = v_board_id;
	I32 CH       = 0;

	for( CH = 0; CH < v_channel; CH++ )
		ret = APS_reset_trigger_count(  Board_ID, CH );
}

void CCmpTrig::stop() 
{
	// TODO: Add your control notification handler code here

	I32 ret      = 0;
	I32 Board_ID = v_board_id;

	//Stop Timer
	ret = APS_set_trigger_param( Board_ID, TIMR_EN   , 0 );
	
}

void CCmpTrig::clear() 
{
	// TODO: Add your control notification handler code here
	

	I32 ret      = 0;
	I32 Board_ID = v_board_id;

	//Clear timer
	ret = APS_set_timer_counter(  Board_ID, 0, 0 );
}

void CCmpTrig::manual() 
{
	// TODO: Add your control notification handler code here

	I32 ret      = 0;
	I32 Board_ID = v_board_id; 
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

void CCmpTrig::linear() 
{
	// TODO: Add your control notification handler code here

	I32 ret      = 0;
	I32 Board_ID = v_board_id;
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

void CCmpTrig::table() 
{
	// TODO: Add your control notification handler code here

	I32 ret      = 0;
	I32 Board_ID = v_board_id;
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
