// basic_samplesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "basic_samplesDlg.h"
#include "sample_emx100.h"
#include "dialogDataExchange.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
 HANDLE forUpdate =NULL ;
bool bClosethread = false;
I32 repeatRet = 0;

I32 delayTime;
CDialog_axis_monitor *mondlg;
Cbasic_samplesDlg *self;

UINT TriggerRun(LPVOID test)
{
	I32 ret,cc=0;
	I32 axis;


	Cbasic_samplesDlg *pDlg = (Cbasic_samplesDlg *)test;

	axis=pDlg->v_test_axis_id;

	do{

		//Check servo on or not
		if( ( APS_motion_status( axis ) >> MTS_NSTP ) & 1 )  
		{
			if(cc%2)
				ret=p2p_example( axis, -10000 );
			else
				ret=p2p_example( axis, 10000 );

			SetI32( pDlg, IDC_EDIT1, ret );


			Sleep( 10 );
			cc++;
		}
		
	} while (cc<40);
	return 0;
}


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
	ON_WM_TIMER()
END_MESSAGE_MAP()


// Cbasic_samplesDlg dialog




Cbasic_samplesDlg::Cbasic_samplesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cbasic_samplesDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	v_is_card_initialed = _NOT_INITIAL;
	self = this;
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
	ON_BN_CLICKED(IDC_BUTTON1, &Cbasic_samplesDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cbasic_samplesDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cbasic_samplesDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cbasic_samplesDlg::OnBnClickedButton4)
//	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON5, &Cbasic_samplesDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &Cbasic_samplesDlg::OnBnClickedButton6)
	//ON_BN_CLICKED(IDC_BUTTON7, &Cbasic_samplesDlg::OnBnClickedButton7)
	//ON_BN_CLICKED(IDC_BUTTON8, &Cbasic_samplesDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &Cbasic_samplesDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Cbasic_samplesDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON12, &Cbasic_samplesDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &Cbasic_samplesDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &Cbasic_samplesDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &Cbasic_samplesDlg::OnBnClickedButton14)
	//ON_BN_CLICKED(IDC_BUTTON15, &Cbasic_samplesDlg::OnBnClickedButton15)
	//ON_BN_CLICKED(IDC_BUTTON16, &Cbasic_samplesDlg::OnBnClickedButton16)
	//ON_BN_CLICKED(IDC_BUTTON17, &Cbasic_samplesDlg::OnBnClickedButton17)
	//ON_BN_CLICKED(IDC_BUTTON18, &Cbasic_samplesDlg::OnBnClickedButton18)
	//ON_BN_CLICKED(IDC_BUTTON19, &Cbasic_samplesDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &Cbasic_samplesDlg::OnBnClickedButton20)
	//ON_BN_CLICKED(IDC_BUTTON21, &Cbasic_samplesDlg::OnBnClickedButton21)
//	ON_CBN_EDITCHANGE(IDC_COMBO1, &Cbasic_samplesDlg::OnCbnEditchangeCombo1)
	
	ON_CBN_SELCHANGE(IDC_COMBO1, &Cbasic_samplesDlg::OnCbnSelchangeCombo1)
	//ON_BN_CLICKED(IDC_BUTTON23, &Cbasic_samplesDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON25, &Cbasic_samplesDlg::OnBnClickedButton25)
	

	//ON_BN_CLICKED(IDC_BUTTON26, &Cbasic_samplesDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON7, &Cbasic_samplesDlg::OnBnClickedButton7)
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

	SetI32( this, IDC_EDIT2,1000);
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
void Cbasic_samplesDlg::OnTimer(UINT_PTR nIDEvent)
{
	

}
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
}
void Cbasic_samplesDlg::updateUI()
{
	GetDlgItem(IDC_BUTTON14)->EnableWindow(true);
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

	// Register EMX products
	ret = APS_register_emx(1,0);
	if(ret)
		MessageBox( "Register EMX fail" );

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

				//if( card_name == DEVICE_NAME_PCI_825458 || card_name == DEVICE_NAME_AMP_20408C )
				if( card_name == 23 ) //23:EMX-100
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
		AfxGetMainWnd()->SetWindowText(_T("Sample Program   EMX-100"));


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

		//ret = APS_load_param_from_file("C://Program Files (x86)//ADLINK//EMX-100//Sample//VC_NET_2005//basic_samples//Debug//MCP2param.xml");

		MessageBox( "initial ok" );
	}else
	{
		Function_Result( ret );
	}
}

void Cbasic_samplesDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	 DWORD exitCode;
	bClosethread = true;
	if( forUpdate != NULL )
	{
		DWORD err = WaitForSingleObject( forUpdate, INFINITE );

		if( err == WAIT_OBJECT_0 )
		{
			CloseHandle( forUpdate );
			forUpdate = NULL;
			MessageBox("3. close thread ok");
			updateUI();
			//GetDlgItem(IDC_BUTTON14)->EnableWindow(true);
		}
	}
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
	AfxGetMainWnd()->SetWindowText(_T("Sample Program"));
	APS_close();
	v_is_card_initialed = _NOT_INITIAL;
	MessageBox( "Close ok" );
}

#define _CHECK_CARD_INITIAL() \
if( v_is_card_initialed == _NOT_INITIAL ) \
{\
	MessageBox( "Card has not be initialed." ); \
	return; \
}


void Cbasic_samplesDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	_CHECK_CARD_INITIAL()

	CDialog_version dlg;
	dlg.v_card_id = v_card_id;
	dlg.DoModal();
}


void Cbasic_samplesDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	_CHECK_CARD_INITIAL()

	/*
	CDialog_axis_monitor dlg;
	dlg.v_card_id = v_card_id;
	dlg.DoModal();
	*/

	CDialog_axis_monitor *v_dlg_axis_mon;
	v_dlg_axis_mon = new CDialog_axis_monitor( this );
	v_dlg_axis_mon->v_card_id = v_card_id;
	v_dlg_axis_mon->Create( IDD_DLG_AXIS_MONITOR, GetDesktopWindow() );

	mondlg = v_dlg_axis_mon;
	v_dlg_axis_mon->ShowWindow( SW_SHOW );

}


void Cbasic_samplesDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here

	_CHECK_CARD_INITIAL()
	I32 ret = 0;
	I32 MinDis =0 ;
	Speed_profile myprofile;
	Speed_profile Pmyprofile2;	
	
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
	// TODO: Add your control notification handler code here
	
	home_move_example( v_test_axis_id );
}


void Cbasic_samplesDlg::OnBnClickedButton9()
{
	DWORD exitCode;
	_CHECK_CARD_INITIAL()
	// TODO: Add your control notification handler code here

	bClosethread = true;
	if( forUpdate != NULL )
	{
		DWORD err = WaitForSingleObject( forUpdate, INFINITE );

		if( err == WAIT_OBJECT_0 )
		{
			CloseHandle( forUpdate );
			forUpdate = NULL;
			MessageBox("1. close thread ok");
			updateUI();
			//GetDlgItem(IDC_BUTTON14)->EnableWindow(true);
		}
		else
		{
			MessageBox("1. close thread okXXX");
		}
	}

	deceleration_stop_example( v_test_axis_id );
}

void Cbasic_samplesDlg::OnBnClickedButton10()
{
	_CHECK_CARD_INITIAL()
	// TODO: Add your control notification handler code here
	 DWORD exitCode;
	bClosethread = true;
	if( forUpdate != NULL )
	{
		DWORD err = WaitForSingleObject( forUpdate, INFINITE );

		if( err == WAIT_OBJECT_0 )
		{
			CloseHandle( forUpdate );
			forUpdate = NULL;
			MessageBox("2. close thread ok");
			updateUI();
			//GetDlgItem(IDC_BUTTON14)->EnableWindow(true);
		}
	}
	emg_stop_example( v_test_axis_id );



}

void Cbasic_samplesDlg::OnBnClickedButton12()
{
	
	_CHECK_CARD_INITIAL()
		I32 ret;
	// TODO: Add your control notification handler code here

	ret = APS_relative_move( v_test_axis_id, 30000, 5000 );
	//ret = APS_absolute_move( v_test_axis_id, 80000, 50000 );

	SetI32( this, IDC_EDIT1, ret );

}

void Cbasic_samplesDlg::OnBnClickedButton11()
{
	_CHECK_CARD_INITIAL()
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
	//APS_jog_start( v_test_axis_id, 1 );
	APS_jog_start( v_test_axis_id, 0 );
}
DWORD  WINAPI Cbasic_samplesDlg::thread_p2p2( LPVOID lpParameter )
{
	return 1;
}

I32 v_id ;
DWORD  WINAPI thread_p2p( LPVOID lpParameter )
{
	I32 i,ret,command1=0, command2=0;
	 DWORD exitCode;
	 bool bEven = false;
	while(1)
	{

		if(bClosethread)
			break;
		ret = APS_motion_status( v_id);
		if(ret < 0 )
		{
			break;
		}
		else if((ret  >> MTS_NSTP) & 1)
		{//motion done
			bEven = !bEven;
			Sleep(delayTime) ;
			if(bEven == true)
			{
				ret = APS_relative_move( v_id, 1000, 20000 );
			}
			else
			{
				ret = APS_relative_move( v_id, -1000, 20000 );
			}
			if(ret < 0)
			{
				emg_stop_example( v_id );
				repeatRet = ret;
			//	mondlg->updateDate(ret);
				self->MessageBox("APS_relative_Move -912 ",NULL,MB_OK);
				self->updateUI();
			
				//self->OnBnClickedButton9();
				//self->MessageBox();

				
				break;
			}
		}

	}
	return 0;
}

void Cbasic_samplesDlg::OnBnClickedButton14()
{
	_CHECK_CARD_INITIAL()


		
	if( forUpdate != NULL )
	{
		MessageBox("A");
		DWORD err = WaitForSingleObject( forUpdate, INFINITE );
		MessageBox("B");

		if( err == WAIT_OBJECT_0 )
		{
			CloseHandle( forUpdate );
			forUpdate = NULL;
			MessageBox("C");
		}
	}

	// TODO: Add your control notification handler code here
	bClosethread = false;

	I32 Axis_ID_Array[2];
	Axis_ID_Array[0] = v_test_axis_id;
	v_id= v_test_axis_id;

	GetDlgItem(IDC_BUTTON14)->EnableWindow(false);

	CString sWindowText;
    (GetDlgItem(IDC_EDIT2))->GetWindowText(sWindowText);
	delayTime = _ttoi(sWindowText);
	if(delayTime < 1)
	{
		MessageBox("delay time must be >= 1 ms");
		return;
	}


	LPVOID lpParameter;
	bClosethread = false;
		forUpdate = CreateThread( 0, 0,thread_p2p, 0, 0, 0 );
		if(forUpdate == NULL)
			MessageBox("create fail");
		else
			printf("%p\n",forUpdate);

}




void Cbasic_samplesDlg::OnBnClickedButton20()
{
	_CHECK_CARD_INITIAL()
	// TODO: Add your control notification handler code here
	DIO_sample( v_card_id );
}




void Cbasic_samplesDlg::OnCbnSelchangeCombo1()
{
	_CHECK_CARD_INITIAL()
	// TODO: Add your control notification handler code here

	CComboBox *pComb = (CComboBox *)GetDlgItem( IDC_COMBO1 );
	v_test_axis_id = v_first_axis_id + pComb->GetCurSel();
}



void Cbasic_samplesDlg::OnBnClickedButton25()
{
	_CHECK_CARD_INITIAL()
	Compare_trigger_example(v_card_id);
}





void Cbasic_samplesDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	_CHECK_CARD_INITIAL()
	vel_example( v_test_axis_id );
}
