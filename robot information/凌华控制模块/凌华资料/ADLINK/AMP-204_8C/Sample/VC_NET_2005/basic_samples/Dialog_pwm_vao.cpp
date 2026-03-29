// Dialog_pwm_vao.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "Dialog_pwm_vao.h"

HANDLE m_threadHandle_PWM;
DWORD  m_threadId_PWM;
DWORD WINAPI ThreadProc_PWM( LPVOID lpParameter );



// Dialog_pwm_vao dialog

IMPLEMENT_DYNAMIC(Dialog_pwm_vao, CDialog)

Dialog_pwm_vao::Dialog_pwm_vao(CWnd* pParent /*=NULL*/)
	: CDialog(Dialog_pwm_vao::IDD, pParent)
{

}

Dialog_pwm_vao::~Dialog_pwm_vao()
{
}

void Dialog_pwm_vao::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog_pwm_vao, CDialog)
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &Dialog_pwm_vao::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Dialog_pwm_vao::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Dialog_pwm_vao::OnBnClickedButton3)
END_MESSAGE_MAP()


// Dialog_pwm_vao message handlers






void Dialog_pwm_vao::Function_Result(int Ret)
{
	char MsgStr[256]="Error Code = ";
    char Buff[256];

	_itoa_s(Ret,Buff,10);     //將整數Ret之值轉成字串後存入Buff,且以10進制表示	
	strcat_s(MsgStr,Buff);   //將字串Buff接至字串MsgStr後面，然後回傳MsgStr字串參數

	if (Ret != 0)
	{
		MessageBox(MsgStr,NULL,MB_OK); //MessageBox(欲顯示之字串 , 標題 ,按鈕形式)	
	}
}

void Dialog_pwm_vao::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	I32 ret = 0;
	I32 Board_ID  = v_card_id;
	I32 CH        = 0; //Range is from 0 to 1
	I32 Frequency = 0; //Unit: Hz. Range is from 3 to 50000000.
	I32 Width     = 0; //Unit: ns. Range is from 20 to 335544300.
	I32 Status    = 0;
	CString str;



	for( CH = 0; CH < channel; CH++ )
	{
		Function_Result(APS_get_pwm_frequency( Board_ID,  CH, &Frequency ));
		SetDlgItemInt( EDIT_pwm_freq_0 + CH, Frequency );

		Function_Result(APS_get_pwm_width(  Board_ID, CH, &Width ));
		SetDlgItemInt( EDIT_pwm_width_0 + CH, Width );
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
	Function_Result(APS_get_vao_status( Board_ID, &Status ));
	str.Format("0x%x", Status);
	SetDlgItemText( IDC_EDIT1, str );



	CDialog::OnTimer(nIDEvent);
}

BOOL Dialog_pwm_vao::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	I32 i = 0;


	for( i = 0; i < 4; i++ )
	{
		p_show_pwm_freq[i] =  (CWnd*)GetDlgItem( EDIT_pwm_freq_0 + i  );
		p_show_pwm_freq[i] -> EnableWindow( FALSE );

		p_show_pwm_width[i] =  (CWnd*)GetDlgItem( EDIT_pwm_width_0 + i );
		p_show_pwm_width[i] -> EnableWindow( FALSE );
	}

	if( v_total_axis == 4 )
		channel = 2;
	else if( v_total_axis == 8 )
		channel = 4;

	for( i = 0; i < channel; i++ )
	{
		p_show_pwm_freq[i]  -> EnableWindow( TRUE );
		p_show_pwm_width[i] -> EnableWindow( TRUE );
	}

	p_Open  = NULL;
	p_Close = NULL; 

	SetTimer(1,1,NULL); // Enable Timer

	return TRUE;  
}

void Dialog_pwm_vao::OnClose()
{
	// TODO: Add your message handler code here and/or call default

	KillTimer(1);

	*p_Open  = NO;
	*p_Close = YES;

	p_bt_PWM_VAO ->EnableWindow( TRUE );

	CDialog::OnClose();
}

void Dialog_pwm_vao::OnBnClickedButton1()
{

	m_threadHandle_PWM = CreateThread(
				0,                // LPSECURITY_ATTRIBUTES lpThreadAttributes 
				0,                // initial stack size
				ThreadProc_PWM,   // thread function
				this,		      // thread argument
				0,                // creation option
				&m_threadId_PWM   // thread identifier
				);
			_ASSERT( m_threadHandle_PWM != NULL );		

}

DWORD WINAPI ThreadProc_PWM( LPVOID lpParameter )
{
	Dialog_pwm_vao *ptr = (Dialog_pwm_vao*) lpParameter;
	_ASSERT( ptr != NULL );

	I32 ret = 0;
	I32 Board_ID  = ptr->v_card_id;
	I32 CH        = 0; //Range is from 0 to 1
	I32 Frequency = 1000; //Unit: Hz. Range is from 3 to 50000000.
	I32 Width     = 1000; //Unit: ns. Range is from 20 to 335544300. 
	




	//Disable all PWM signals. 
	for( CH = 0; CH < 4; CH++ )
		ptr->Function_Result(APS_set_pwm_on(  Board_ID, CH, OFF ));

	//Set PWM parameters
	for( CH = 0; CH < ptr->channel; CH++ )
	{
		ptr->Function_Result(APS_set_pwm_frequency(  Board_ID, CH, Frequency ));
	    ptr->Function_Result(APS_set_pwm_width(  Board_ID, CH, Width ));
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
	for( CH = 0; CH < ptr->channel; CH++ )
		ptr->Function_Result(APS_set_pwm_on(  Board_ID, CH, ON ));

	//Wait about 1 sec to show PWM signal (about 1000 periods).
    Sleep(1000);

	//Disable all PWM signals. 
	for( CH = 0; CH < ptr->channel; CH++ )
		ptr->Function_Result(APS_set_pwm_on(  Board_ID, CH, OFF ));

	return 0;
}

void Dialog_pwm_vao::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	I32 ret = 0;
	I32 Board_ID  = v_card_id;

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
	Function_Result(APS_set_vao_param(  Board_ID, 0x0, 1 ));

    //****************************************************************
	// Set input reference of Table[0]
	//
	// 0: feedback speed. 
	// 1: command speed.  
	//****************************************************************
	Function_Result(APS_set_vao_param(  Board_ID, 0x1, 1 ));

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
	Function_Result(APS_set_vao_param(  Board_ID, 0x10, 1000 ));

	//Specify axisID for VAO Table[0].
	Function_Result(APS_set_vao_param(  Board_ID, 0x20, 0x1 ));


	//set Table[0] parameters
	Function_Result(APS_set_vao_table(  Board_ID,  Table_No,  MinVelocity,  VelInterval,  TotalPoints, MappingDataArray ));

	//check parameters of VAO Table[0]
	Function_Result(APS_check_vao_param(  Board_ID, Table_No, &Status ));

	if( Status == 0 )
		MessageBox( "VAO Setting Ok", NULL, MB_OK );
	else
		MessageBox( "VAO Setting Failed", NULL, MB_OK );


	//Specify which table be executed
	//if Table_No = -1 that disable all tables.
	Function_Result(APS_switch_vao_table(  Board_ID,  Table_No  ));

	//Enable outputs 
	Function_Result(APS_start_vao(  Board_ID, 0, ON ));
	Function_Result(APS_start_vao(  Board_ID, 1, ON ));		
}

void Dialog_pwm_vao::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	I32 Board_ID  = v_card_id;

	//VAO table number. Range is 0 ~ 7.
	I32 Table_No = -1;


	//Disable all tables.
	Function_Result(APS_switch_vao_table(  Board_ID,  Table_No  ));

	//Disable outputs
	Function_Result(APS_start_vao(  Board_ID, 0, OFF ));
	Function_Result(APS_start_vao(  Board_ID, 1, OFF ));	
	
	MessageBox( "VAO off", NULL, MB_OK );
}
