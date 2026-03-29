// basic_samplesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "basic_samplesDlg.h"
#include "sample_main.h"
#include "SDO_TEST.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cbasic_samplesDlg dialog




Cbasic_samplesDlg::Cbasic_samplesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cbasic_samplesDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	v_is_card_initialed = _NOT_INITIAL;
	v_is_FieldBus_Start = _NOT_START_FIELD_BUS;
}

void Cbasic_samplesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cbasic_samplesDlg, CDialog)

	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP



	
	
	ON_BN_CLICKED(IDC_BUTTON30, &Cbasic_samplesDlg::OnBnClickedButton30)



	ON_BN_CLICKED(IDC_BUTTON1, &Cbasic_samplesDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cbasic_samplesDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cbasic_samplesDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cbasic_samplesDlg::OnBnClickedButton4)
//	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON5, &Cbasic_samplesDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cbasic_samplesDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Cbasic_samplesDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Cbasic_samplesDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Cbasic_samplesDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cbasic_samplesDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &Cbasic_samplesDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &Cbasic_samplesDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &Cbasic_samplesDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &Cbasic_samplesDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &Cbasic_samplesDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &Cbasic_samplesDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &Cbasic_samplesDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &Cbasic_samplesDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &Cbasic_samplesDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &Cbasic_samplesDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &Cbasic_samplesDlg::OnBnClickedButton21)
//	ON_CBN_EDITCHANGE(IDC_COMBO1, &Cbasic_samplesDlg::OnCbnEditchangeCombo1)
	
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cbasic_samplesDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON23, &Cbasic_samplesDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON24, &Cbasic_samplesDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &Cbasic_samplesDlg::OnBnClickedButton25)
	

	ON_BN_CLICKED(IDC_BUTTON26, &Cbasic_samplesDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &Cbasic_samplesDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON28, &Cbasic_samplesDlg::OnBnClickedButton28)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON22, &Cbasic_samplesDlg::OnBnClickedButton22)
END_MESSAGE_MAP()


// Cbasic_samplesDlg message handlers

BOOL Cbasic_samplesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
//	for( int i = 0; i < MAX_AXIS_MON_DLG; i++ )
//		v_dlg_axis_mon[i] = NULL;


	p_bt_CmpTrig = (CButton *)GetDlgItem( IDC_BUTTON25 );
	p_bt_PWM_VAO = (CButton *)GetDlgItem( IDC_BUTTON26 );
	
	Is_Open_CmpTrig = NO;
	Is_Open_PWM_VAO = NO;

	Is_Close_CmpTrig = YES;
	Is_Close_PWM_VAO = YES;

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cbasic_samplesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cbasic_samplesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cbasic_samplesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cbasic_samplesDlg::Function_Result( I32 Ret )
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

//#define __DEBUG_USING_VIRTUAL






void Cbasic_samplesDlg::UI_Initial()
{
	p_bt_CmpTrig ->EnableWindow( TRUE );
	p_bt_PWM_VAO ->EnableWindow( TRUE );
}






void Cbasic_samplesDlg::OnBnClickedButton30()
{
	//Creat New Diolog
	SDO_TEST *p = new SDO_TEST;
	p->Create( IDD_DIALOG3, GetDesktopWindow() );
	p->ShowWindow (SW_SHOW);

	//Pass information to SDO_TEST diolog frist
	p->pMainForm = this;
	p->v_is_card_initialed = v_is_card_initialed;
	p->v_is_FieldBus_Start = v_is_FieldBus_Start;


	//
	p->SetDlgItemInt( IDC_EDIT8, 1001 );
	p->SetDlgItemInt( IDC_EDIT12, 5000 );
	p->SetDlgItemInt( IDC_EDIT13, 0 );
	//
}





void Cbasic_samplesDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	I32 boardID_InBits = 0;
	I32 mode           = INIT_AUTO_CARD_ID;
	I32 ret            = 0;
	I32 board_ID       = -1;
	I32 i;
	I32 card_name;
	

	// UI protection
	if( v_is_card_initialed == _INITIALED )
	{
		MessageBox( "initial ok" );
		return;
	}

	// Card(Board) initial
	ret = APS_initial( &boardID_InBits, mode );
	
	// Search card's ID
	if( ret == ERR_NoError )
	{
		for( i = 0; i < 16; i++ )
		{  
			if( ( boardID_InBits >> i ) & 1 )
			{
				APS_get_card_name( i, &card_name );

				if((card_name == DEVICE_NAME_PCIE_8334)||(card_name == DEVICE_NAME_PCIE_8338))					
				{
					v_card_name = card_name;
					board_ID = i;
					break;
				}
			}
		}

		if( board_ID == -1 )
		{
			MessageBox( "BoardId search error!" );
			return;
		}	

		v_is_card_initialed = _INITIALED;
		v_card_id           = board_ID;
		
		I32 total_axes;
		APS_get_first_axisId( board_ID, &v_first_axis_id, &total_axes );
		v_test_axis_id = v_first_axis_id;
		v_total_axis   = total_axes;

		//Show main form caption
		if( v_card_name == DEVICE_NAME_PCI_825458 && v_total_axis == 8 )
			AfxGetMainWnd()->SetWindowText(_T("Sample Program   PCI-8258"));
		else if( v_card_name == DEVICE_NAME_PCI_825458 && v_total_axis == 4 )
			AfxGetMainWnd()->SetWindowText(_T("Sample Program   PCI-8254"));
		else if( v_card_name == DEVICE_NAME_AMP_20408C && v_total_axis == 8 )
			AfxGetMainWnd()->SetWindowText(_T("Sample Program   AMP-208C"));
		else if( v_card_name == DEVICE_NAME_AMP_20408C && v_total_axis == 4 )
			AfxGetMainWnd()->SetWindowText(_T("Sample Program   AMP-204C"));

		// Setup combol box
		CString str;
		CComboBox *pComb = (CComboBox *)this->GetDlgItem( IDC_COMBO1 );
		pComb->ResetContent();

		for( i = 0; i < total_axes; i++ )
		{
			str.Format( "%d", i + v_first_axis_id );
			pComb->AddString( str );
		}

		pComb->SetCurSel( 0 );

		UI_Initial();

		MessageBox( "initial ok" );
	}else
	{
		Function_Result( ret );
	}
}

void Cbasic_samplesDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	if( Is_Open_CmpTrig == NO && Is_Open_PWM_VAO == NO )
	{
		Close_Process();
		return;
	}

	if( Is_Close_CmpTrig == YES && Is_Close_PWM_VAO == YES )
		Close_Process();
	else
		MessageBox( "Close Failed, Please close all forms first" );
}

void Cbasic_samplesDlg::Close_Process()
{
	I32 BUS_No = 0;
	I32 ret;
	AfxGetMainWnd()->SetWindowText(_T("Sample Program"));
	ret = APS_stop_field_bus( v_card_id, BUS_No);
	APS_close();
	v_is_card_initialed = _NOT_INITIAL;
	v_is_FieldBus_Start = _NOT_START_FIELD_BUS;
	MessageBox( "Close ok" );
}

#define _CHECK_CARD_INITIAL() \
if( v_is_card_initialed == _NOT_INITIAL ) \
{\
	MessageBox( "Card has not be initialed." ); \
	return; \
}

#define _CHECK_FIELDBUS_START() \
	if( v_is_FieldBus_Start == _NOT_START_FIELD_BUS ) \
{\
	MessageBox( "Field Bus doesn't start !!." ); \
	return; \
}



void Cbasic_samplesDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	_CHECK_CARD_INITIAL()
	//_CHECK_FIELDBUS_START() 

	CDialog_version dlg;
	dlg.v_card_id = v_card_id;
	dlg.DoModal();
}


void Cbasic_samplesDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	/*
	CDialog_axis_monitor dlg;
	dlg.v_card_id = v_card_id;
	dlg.DoModal();
	*/

	CDialog_axis_monitor *v_dlg_axis_mon;
	v_dlg_axis_mon = new CDialog_axis_monitor( this );
	v_dlg_axis_mon->v_card_id = v_card_id;
	v_dlg_axis_mon->Create( IDD_DLG_AXIS_MONITOR, GetDesktopWindow() );
	v_dlg_axis_mon->ShowWindow( SW_SHOW );

}


void Cbasic_samplesDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here

	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	char strFilter[] = { "xml Files (*.xml)|*.xml|All Files (*.*)|*.*||" };

	CFileDialog FileDlg(TRUE, ".xml", NULL, 0, strFilter);

	if( FileDlg.DoModal() == IDOK )
	{
		CString str;
		str = FileDlg.GetFileName();
		load_parameters_from_file_sample( str );
	}
}

void Cbasic_samplesDlg::OnBnClickedButton6()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here
	
	home_move_example( v_test_axis_id );
}

void Cbasic_samplesDlg::OnBnClickedButton7()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here
	I32 ret;
	I32 stop_code;
	CString str;


	ret = check_motion_done_example( v_test_axis_id, &stop_code );
	
	// Display motion done status
	switch( ret )
	{
	case 0:
		MessageBox( "In motion" );
		break;
	case 1:
		MessageBox( "Motion done" );
		break;
	case -1:
		str.Format( "Error stop! stop code:%d(%s)", stop_code, stop_code_to_string( stop_code ) );

		MessageBox( str );
		break;
	}
}

void Cbasic_samplesDlg::OnBnClickedButton8()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	velocity_move_example( v_test_axis_id );
}

void Cbasic_samplesDlg::OnBnClickedButton9()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	deceleration_stop_example( v_test_axis_id );
}

void Cbasic_samplesDlg::OnBnClickedButton10()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	emg_stop_example( v_test_axis_id );
}

void Cbasic_samplesDlg::OnBnClickedButton12()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	p2p_example( v_test_axis_id );

}

void Cbasic_samplesDlg::OnBnClickedButton11()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	jog_move_continuous_mode_example( v_test_axis_id );

	/**** Following are another two samples *********/
	// jog_move_step_mode_example( v_test_axis_id );   
	// jog_move_via_DI_example( v_test_axis_id );
}

void Cbasic_samplesDlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	// Create a falling edge.
	APS_jog_start( v_test_axis_id, 1 );
	APS_jog_start( v_test_axis_id, 0 );
}

void Cbasic_samplesDlg::OnBnClickedButton14()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;


	interpolation_2D_line_example( Axis_ID_Array );
}

void Cbasic_samplesDlg::OnBnClickedButton15()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	interpolation_2D_arc_example( Axis_ID_Array );
}

void Cbasic_samplesDlg::OnBnClickedButton16()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	I32 Axis_ID_Array[3];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;
	Axis_ID_Array[2] = v_test_axis_id + 2;

	interpolation_3D_arc_example( Axis_ID_Array );
}

void Cbasic_samplesDlg::OnBnClickedButton17()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	I32 Axis_ID_Array[3];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;
	Axis_ID_Array[2] = v_test_axis_id + 2;

	interpolation_3D_helical_example( Axis_ID_Array );
}

void Cbasic_samplesDlg::OnBnClickedButton18()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here
	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	contour_2D_example( Axis_ID_Array );
}

int g_is_thread_created = 0;
I32 g_board_id;
I32 g_axis_num;
DWORD WINAPI wait_interrupt_thread( LPVOID lpParameter )
{
	if( interrupt_example( g_board_id, g_axis_num ) == 0 )
		AfxMessageBox( "interrupt occur" );

	g_is_thread_created = 0;
	return 0;
}

void Cbasic_samplesDlg::OnBnClickedButton19()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here
	DWORD id;

	if( g_is_thread_created == 0 )
	{
		I32 tmp;
		g_is_thread_created = 1;
		APS_get_axis_info( v_test_axis_id, &g_board_id, &g_axis_num, &tmp, &tmp );
		CreateThread( 0, 0, wait_interrupt_thread, 0, 0, &id );
		MessageBox( "Wait motion done thread is created.\n You can start a \"p2p\" move." );
	}else
	{
		MessageBox( "Thread already created" );
	}
		
}

void Cbasic_samplesDlg::OnBnClickedButton20()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here
	DIO_sample( v_card_id );
}

void Cbasic_samplesDlg::OnBnClickedButton21()
{
	I32 card_name = 0;

	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	
	APS_get_card_name( 0, &card_name );

	if( card_name == DEVICE_NAME_PCI_825458 )
	{
		AIO_sample( v_card_id );
	}	
}




void Cbasic_samplesDlg::OnCbnSelchangeCombo1()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here

	CComboBox *pComb = (CComboBox *)GetDlgItem( IDC_COMBO1 );
	v_test_axis_id = v_first_axis_id + pComb->GetCurSel();
}

void Cbasic_samplesDlg::OnBnClickedButton23()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here
	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	point_table_2D_example( v_card_id, Axis_ID_Array );
}

void Cbasic_samplesDlg::OnBnClickedButton24()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	// TODO: Add your control notification handler code here
	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	Axis_ID_Array[1] = v_test_axis_id + 1;

	gear_example( Axis_ID_Array );
}

void Cbasic_samplesDlg::OnBnClickedButton25()
{
	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	Dialog_cmp_trig *v_dlg_CmpTrig;
	v_dlg_CmpTrig = new Dialog_cmp_trig( this );

	v_dlg_CmpTrig -> v_card_id     = v_card_id;
	v_dlg_CmpTrig -> p_bt_CmpTrig  = p_bt_CmpTrig;
	v_dlg_CmpTrig -> v_card_name   = v_card_name;
	v_dlg_CmpTrig -> v_total_axis  = v_total_axis;

	v_dlg_CmpTrig->Create( IDD_DLG_CmpTrig, GetDesktopWindow() );
	v_dlg_CmpTrig->ShowWindow( SW_SHOW );


	v_dlg_CmpTrig->p_Open  = &Is_Open_CmpTrig;
	v_dlg_CmpTrig->p_Close = &Is_Close_CmpTrig;

	Is_Open_CmpTrig  = YES;
	Is_Close_CmpTrig = NO;

	p_bt_CmpTrig ->EnableWindow( FALSE );
}


void Cbasic_samplesDlg::OnBnClickedButton26()
{
	// TODO: Add your control notification handler code here

	_CHECK_CARD_INITIAL()
	_CHECK_FIELDBUS_START() 
	Dialog_pwm_vao *p;
	p = new Dialog_pwm_vao( this );

	p -> v_card_id    = v_card_id;
	p -> p_bt_PWM_VAO = p_bt_PWM_VAO;
	p -> v_total_axis = v_total_axis;


	p->Create( IDD_DLG_PWM_VAO, GetDesktopWindow() );
	p->ShowWindow( SW_SHOW );

	p->p_Open  = &Is_Open_PWM_VAO;
	p->p_Close = &Is_Close_PWM_VAO;

	Is_Open_PWM_VAO  = YES;
	Is_Close_PWM_VAO = NO;

	p_bt_PWM_VAO ->EnableWindow( FALSE );	
}

void Cbasic_samplesDlg::OnBnClickedButton27()
{
	// TODO: Add your control notification handler code here
	_CHECK_CARD_INITIAL()
		
	I32 startingAxisId = 0; //Startin axis ID of the filed bus.
	I32 BUS_No = 0;
	I32 ret;
	ret = APS_start_field_bus( v_card_id, BUS_No, startingAxisId );
	if (ret==0){
		MessageBox( "Field Bus Start ok !" );
		v_is_FieldBus_Start = _START_FIELD_BUS;
	}
	else {
		Function_Result( ret );
	}
}

void Cbasic_samplesDlg::OnBnClickedButton28()
{
	// TODO: Add your control notification handler code here
	_CHECK_CARD_INITIAL()
	
	I32 BUS_No = 0;
	I32 ret;
	ret = APS_stop_field_bus( v_card_id, BUS_No);
	if (ret==0){
		MessageBox( "Field Bus Stop ok !" );
		v_is_FieldBus_Start = _NOT_START_FIELD_BUS;
	}
	else {
		Function_Result( ret );
	}
}

void Cbasic_samplesDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	I32 BUS_No = 0;
	I32 ret;
	ret = APS_stop_field_bus( v_card_id, BUS_No);
	APS_close();
	CDialog::OnClose();
}

void Cbasic_samplesDlg::OnBnClickedButton22()
{
	// TODO: Add your control notification handler code here

	_CHECK_CARD_INITIAL()

	I32 ret = 0;
	I32 Board_ID = v_card_id;
	I32 BUS_No   = 0;


	ret = APS_scan_field_bus(  Board_ID,  BUS_No );

	if( ret == 0 )
	{
		MessageBox( "Scan Bus ok !" );
	}
	else
	{
		Function_Result( ret );
	}
}
