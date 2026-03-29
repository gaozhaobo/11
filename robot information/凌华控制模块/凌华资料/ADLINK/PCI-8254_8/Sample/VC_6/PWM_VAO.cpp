// PWM_VAO.cpp : implementation file
//

#include "stdafx.h"
#include "basic_sample.h"
#include "PWM_VAO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



HANDLE m_threadHandle_pwm;
DWORD  m_threadId_pwm;
DWORD WINAPI ThreadProc_pwm( LPVOID lpParameter );

/////////////////////////////////////////////////////////////////////////////
// CPWM_VAO dialog


CPWM_VAO::CPWM_VAO(CWnd* pParent /*=NULL*/)
	: CDialog(CPWM_VAO::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPWM_VAO)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPWM_VAO::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPWM_VAO)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPWM_VAO, CDialog)
	//{{AFX_MSG_MAP(CPWM_VAO)
	ON_WM_CLOSE()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, pwm)
	ON_BN_CLICKED(IDC_BUTTON2, VAO_ON)
	ON_BN_CLICKED(IDC_BUTTON25, VAO_OFF)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPWM_VAO message handlers

void CPWM_VAO::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(0);
	
	CDialog::OnClose();
}

int CPWM_VAO::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	Is_thread_ON = NO;
	SetTimer( 0, 1, NULL );
	
	return 0;
}

void CPWM_VAO::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	I32 ret = 0;
	I32 Board_ID  = v_board_id;
	I32 CH        = 0; //Range is from 0 to 1
	I32 Frequency = 0; //Unit: Hz. Range is from 3 to 50000000.
	I32 Width     = 0; //Unit: ns. Range is from 20 to 335544300.
	I32 Status    = 0;
	I32 TrgCnt   = 0;
	CString str;



	for( CH = 0; CH < v_channel; CH++ )
	{
		ret = APS_get_pwm_frequency( Board_ID,  CH, &Frequency );
		SetDlgItemInt( EDIT_freq_0 + CH, Frequency );

		ret = APS_get_pwm_width(  Board_ID, CH, &Width );
		SetDlgItemInt( EDIT_pwm_width_0 + CH, Width );

		ret = APS_get_trigger_count( Board_ID, CH, &TrgCnt );
		SetDlgItemInt( EDIT_cnt_0 + CH, TrgCnt );
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
	ret = APS_get_vao_status( Board_ID, &Status );
	str.Format("0x%x", Status);
	SetDlgItemText( EDIT_vao_sts, str );
	
	CDialog::OnTimer(nIDEvent);
}

void CPWM_VAO::pwm() 
{
	// TODO: Add your control notification handler code here

	if( Is_thread_ON == NO )
	{
		Is_thread_ON = YES;

		MessageBox( "Thread is created.\n PWM signal will output." );

		//Initial ok. Do some things...
	    //Creat Thread to do some things...

			m_threadHandle_pwm = CreateThread(
				0,                // LPSECURITY_ATTRIBUTES lpThreadAttributes 
				0,                // initial stack size
				ThreadProc_pwm,   // thread function
				this,		      // thread argument
				0,                // creation option
				&m_threadId_pwm   // thread identifier
				);
			_ASSERT( m_threadHandle_pwm != NULL );		
	}
	else
	{
		MessageBox( "Thread already created" );
	}
}

DWORD WINAPI ThreadProc_pwm( LPVOID lpParameter )
{
	CPWM_VAO *p = (CPWM_VAO*)lpParameter;

	I32 ret = 0;
	I32 Board_ID  = p->v_board_id;
	I32 CH        = 0; //Range is from 0 to 1
	I32 Frequency = 1000; //Unit: Hz. Range is from 3 to 50000000.
	I32 Width     = 1000; //Unit: ns. Range is from 20 to 335544300. 
	

	//Disable all PWM signals. 
	for( CH = 0; CH < 4; CH++ )
		APS_set_pwm_on(  Board_ID, CH, OFF );

	//Set PWM parameters
	for( CH = 0; CH < p->v_channel; CH++ )
	{
		APS_set_pwm_frequency(  Board_ID, CH, Frequency );
	    APS_set_pwm_width(  Board_ID, CH, Width );
	}

	//Wait for stable
	Sleep(1);

	/*
	Note:
	   The PWM output (TG) is used by two function APIs, that are APS_set_pwm_on() and APS_start_vao(). 
	   Don't use them at the same time.
	   Be sure that only one of them is enabled, specified PWM channel could rightly work. 
	*/

	//start output PWM signal.
	for( CH = 0; CH <  p->v_channel; CH++ )
		APS_set_pwm_on(  Board_ID, CH, ON );

	//Wait about 1 sec to show PWM signal (about 1000 periods).
    Sleep(1000);

	//Disable all PWM signals. 
	for( CH = 0; CH < p->v_channel; CH++ )
		APS_set_pwm_on(  Board_ID, CH, OFF );

	p->Is_thread_ON = NO;

	return 0;
}

void CPWM_VAO::VAO_ON() 
{
	// TODO: Add your control notification handler code here
	

	I32 ret = 0;
	I32 Board_ID  = v_board_id;

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
		MessageBox( "VAO Setting Ok", NULL, MB_OK );
	else
		MessageBox( "VAO Setting Failed", NULL, MB_OK );


	//Specify which table be executed
	//if Table_No = -1 that disable all tables.
	APS_switch_vao_table(  Board_ID,  Table_No  );

	//Enable outputs 
	APS_start_vao(  Board_ID, 0, ON );
	APS_start_vao(  Board_ID, 1, ON );	
}

void CPWM_VAO::VAO_OFF() 
{
	// TODO: Add your control notification handler code here

	I32 Board_ID  = v_board_id;

	//VAO table number. Range is 0 ~ 7.
	I32 Table_No = -1;


	//Disable all tables.
	APS_switch_vao_table(  Board_ID,  Table_No  );

	//Disable outputs
	APS_start_vao(  Board_ID, 0, OFF );
	APS_start_vao(  Board_ID, 1, OFF );	
	
	MessageBox( "VAO off", NULL, MB_OK );	
}
