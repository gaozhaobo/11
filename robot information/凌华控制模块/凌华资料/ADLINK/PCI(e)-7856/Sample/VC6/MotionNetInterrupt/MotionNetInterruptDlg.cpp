// MotionNetInterruptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MotionNetInterrupt.h"
#include "MotionNetInterruptDlg.h"
#include <afxdlgs.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define TIMER_1		(1)
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMotionNetInterruptDlg dialog

CMotionNetInterruptDlg::CMotionNetInterruptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMotionNetInterruptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMotionNetInterruptDlg)
	m_edit_cmd = 0;
	m_edit_pos = 0;
	m_edit_sts = 0;
	m_edit_io = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//Initialize
	m_totalSlave      = 0;
	m_totalMotionAxes = 0;
	m_axisId          = 0;

	m_threadHandle = NULL;
	m_threadId     = 0;

	m_intNum       = 0;

	m_isInitial     = __NO;
	m_isConnect     = __NO;
	m_isIntEnable   = __NO;
	m_isLeaveThread = __YES;
	m_isSetFactor   = __NO;

}

void CMotionNetInterruptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMotionNetInterruptDlg)
	DDX_Text(pDX, IDC_EDIT2, m_edit_cmd);
	DDX_Text(pDX, IDC_EDIT3, m_edit_pos);
	DDX_Text(pDX, IDC_EDIT4, m_edit_sts);
	DDX_Text(pDX, IDC_EDIT5, m_edit_io);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMotionNetInterruptDlg, CDialog)
	//{{AFX_MSG_MAP(CMotionNetInterruptDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMotionNetInterruptDlg message handlers

BOOL CMotionNetInterruptDlg::OnInitDialog()
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

	// ADLINK SAMPLE CODE 
	m_InterfaceCtrl();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMotionNetInterruptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMotionNetInterruptDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMotionNetInterruptDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//****************************************************************************************
// ADLINK SAMPLE CODE 
//****************************************************************************************
void CMotionNetInterruptDlg::m_InterfaceCtrl()
{
	CButton *pBt_in = (CButton *)GetDlgItem( IDC_BUTTON1 );	// Initial / Close
	CButton *pBt_cn = (CButton *)GetDlgItem( IDC_BUTTON2 ); // Connect / Disconnect
	CButton *pBt_en = (CButton *)GetDlgItem( IDC_BUTTON5 ); // Enable / Disable interrupt button
	CButton *pBt_sf = (CButton *)GetDlgItem( IDC_BUTTON3 ); // Set factor.
	CButton *pBt_rs = (CButton *)GetDlgItem( IDC_BUTTON4 ); // Reset interrupt factor.
	CButton *pBt_wt = (CButton *)GetDlgItem( IDC_BUTTON8 ); // wait interrupt button.

	ASSERT( pBt_in != NULL );
	ASSERT( pBt_cn != NULL );
	ASSERT( pBt_en != NULL );
	ASSERT( pBt_sf != NULL );
	ASSERT( pBt_rs != NULL );
	ASSERT( pBt_wt != NULL );


	if( m_isInitial == __NO )
	{
		pBt_in->SetWindowText( "Initial" );
		pBt_cn->EnableWindow( FALSE );
		pBt_en->EnableWindow( FALSE );
		pBt_sf->EnableWindow( FALSE );
		pBt_rs->EnableWindow( FALSE );
		pBt_wt->EnableWindow( FALSE );
		return;
	}

	// Card be initialed.
	pBt_in->SetWindowText( "Close" );
	pBt_cn->EnableWindow( TRUE );

	if( m_isConnect == __NO )
	{
		pBt_cn->SetWindowText( "Connect" );
		pBt_en->EnableWindow( FALSE );
		pBt_sf->EnableWindow( FALSE );
		pBt_rs->EnableWindow( FALSE );
		pBt_wt->EnableWindow( FALSE );
	}else
	{
		pBt_cn->SetWindowText( "Disconnect" );
		pBt_en->EnableWindow( TRUE );
		pBt_sf->EnableWindow( TRUE );
		pBt_rs->EnableWindow( TRUE );
		pBt_wt->EnableWindow( TRUE  );
	}

	if( m_isSetFactor == __YES )
	{
		pBt_sf->SetWindowText( "Clear Factor" );
	}else
	{
		pBt_sf->SetWindowText( "Set Factor" );
	}


	if( m_isIntEnable == __YES )
	{
		pBt_en->SetWindowText( "Disable" );
	}else
	{
		pBt_en->SetWindowText( "Enable" );
	}

	if( m_threadHandle == NULL )
	{
		pBt_wt->SetWindowText( "CreateThread" );
	}else
	{
		pBt_wt->SetWindowText( "StopThread" );
	}

}

void CMotionNetInterruptDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	
	I32 ret;				// Return code. [函式回傳值]
	I32 boardID_InBits = 0; // Return board ID in bit format. [控制卡的ID回傳值,用Bit格式表示]
	I32 mode		   = 0 | (1 << 6 );	// Initail mode [初始化模式]
	I32 cardId		   = 0;	// Device ID [控制卡的ID]
	I32 ver			   = 0; // Return APS library version. [取得APS版本編號]
	I32 cardName       = 0; // Return card name.
	
	// User close device.
	// 使用者關閉控裝置
	if( m_isInitial == __YES )
	{
		APS_close();

		m_isInitial   = __NO;
		m_isConnect   = __NO;
		m_isIntEnable = __NO;

		// UI setting (人機介面設定)
		m_InterfaceCtrl();
		return;
	}

	// Initial control card. You must enable the interrupt mode (Bit 6)
	// 初始化控制卡, 此處必須注意Interrupt mode 必須致能 (Bit 6)
	ret = APS_initial( &boardID_InBits, mode );

	if( ret != ERR_NoError )
	{
		MessageBox( "APS initial failed." );
		goto INIT_FAILED;

	}

	APS_get_card_name( cardId, &cardName );
	if( cardName != 5 ) //5:PCI-7856
	{
		MessageBox( "PCI-7856 not found." );
		goto CHECK_CARD_NAME_FAILED;
	}

	// Check APS library version.
	ver = APS_version();
	if( ver < 100721 ) //If library version not match. 
	{ // Interrupt function does not supported. 
		MessageBox( "The device does not support MNet interrupt functions." );
		MessageBox( "Device closed." );
		
		goto CHECK_VERSION_FAILED;
		return;
	}

	m_cardId = cardId;
	m_isInitial = __YES;
	m_isConnect = __NO;
	m_InterfaceCtrl();
	return;


CHECK_VERSION_FAILED:
CHECK_CARD_NAME_FAILED:
	APS_close();

INIT_FAILED:
	m_isInitial = __NO;
	m_isConnect = __NO;

	// UI setting (人機介面設定)
	m_InterfaceCtrl();
}

void CMotionNetInterruptDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	I32 ret; 

	// Check HSL fieldbus connection is established.
	// 檢查是否已經連線
	if( m_isConnect == __YES )
	{
		// User want to break the connection of fieldbus (HSL).
		// 使用者斷線
		ret = APS_stop_field_bus( m_cardId, _MNET_BUS_NUM );

		if( ret != ERR_NoError )
		{	
			MessageBox( "Stop MNet fieldbus failed." );
		}

		m_isConnect       = __NO;
		m_totalSlave      = 0;
		m_totalMotionAxes = 0;

		KillTimer( TIMER_1 );

		// UI setting (人機介面設定)
		m_InterfaceCtrl();
		return;
	}


	// User want to establish the connection of fieldbus.
	// 使用者連線
	ret = APS_start_field_bus( m_cardId, _MNET_BUS_NUM, _START_AXIS_ID );

	if( ret != ERR_NoError )
	{
		MessageBox( "Start MNet fieldbus failed." );
		return;
	}


	// To obtain the information recorded in last scan.
	#define __SIZE (2)
	I32 infoArray[__SIZE];
	I32 infoCount;

	ret = APS_get_field_bus_last_scan_info( m_cardId, _MNET_BUS_NUM, 
		infoArray, __SIZE, &infoCount );

	m_axisId = _START_AXIS_ID + 0;; 
	
	SetTimer( TIMER_1, 200, NULL );
	
	m_isConnect = __YES;
	// UI setting (人機介面設定)
	m_InterfaceCtrl();

}

void CMotionNetInterruptDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	
	// 當中斷來源(factor)被選擇並啟動後，當中斷條件發生，
	// Motion Net模組會開始發出中斷訊號到主控制卡
	// 本例設定"正常停止"(Normal stop,NSTP)訊號為中斷來源(Interrupt factor)

	// This button will enable the interrupt factor.
	// When interrupt factor is enable, the slave will output interrupt 
	// signal to master card when interrupt event (factor) occured.


	I32 ret;
	I32 axisId;
	I32 factor;

	axisId = m_axisId;
	factor = 0; // (INSTP)

	if( m_isSetFactor == __NO )
	{
		// 當使用者尚未設定中斷因子(Interrupt factors)
		// 使用下列函數(function)設定，返回中斷等待號碼(INT number)

#ifdef _VIRTUAL_FUNCTIONS
		ret = 0;
#else
		ret = APS_set_field_bus_int_factor_motion( 
				axisId, // I32 Item_No
				factor, // I32 Factor_No, 
				1      // I32 Enable 
				);
#endif

		if( ret < ERR_NoError )
		{
			MessageBox( "APS_7856_set_field_bus_int_factor_mnet() failed." );
			return;
		}

		m_intNum      = ret;
		m_isSetFactor = __YES;
	}else
	{ //清除中斷因子(interrupt factor),讓該事件不會發生中斷

#ifdef _VIRTUAL_FUNCTIONS
		ret = 0;
#else
		ret = APS_set_field_bus_int_factor_motion(
				axisId, // I32 Item_No
				factor, // I32 Factor_No, 
				0      // I32 Enable 
				);
#endif

		if( ret < ERR_NoError )
		{
			MessageBox( "APS_7856_set_field_bus_int_factor_mnet() failed." );
			return;
		}

		m_intNum      = ret;
		m_axisId      = axisId; 
		m_isSetFactor = __NO;
	}

	// UI setting (人機介面設定)
	m_InterfaceCtrl();
}

void CMotionNetInterruptDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	I32 ret;

	//這個步驟是打開(或關閉)中斷的總開關,當開關打開後中斷訊號才會通知作業系統
	//產生中斷事件，當不再使用中斷功能時,請關閉開關,以節省效能,避免系統接收不必要的中斷訊號

	// This step is to enable (or disable) interupt main switch,
	// When switch is turned on, the interrupt signal will be pass to operation system,
	// then creates the interrupt event.
	// When you no longer to use the interrupt event, please turn off the interrupt switch to
	// keep OS performance.

	// Check user want to "Enable" or "Disable" interrupt main switch
	// 判斷使用者要打開或關閉中斷總開關
	if( m_isIntEnable == __YES )
	{
		// User disable interrupt main switch
		// 使用關閉中斷的總開關
		ret = APS_int_enable( m_cardId, 0 ); //Disable Interrupt main switch
		
		// Error check
		// 錯誤檢查, 有錯誤跳出警告視窗
		if( ret != ERR_NoError )
		{
			MessageBox( "APS_int_enable() failed." );
			return;
		}


		m_isIntEnable = __NO;
		// UI setting (人機介面設定)
		m_InterfaceCtrl();
		return;
	}

	// User enable interrupt main switch
	// 使用者欲啟動中斷總開關
	ret = APS_int_enable( m_cardId, 1 ); //Enable Interrupt main switch
	
	// Error check
	// 錯誤檢查, 有錯誤跳出警告視窗
	if( ret != ERR_NoError )
	{
		MessageBox( "APS_int_enable() failed." );
		return;
	}

	m_isIntEnable = __YES;

	// UI setting (人機介面設定)
	m_InterfaceCtrl();
}

void CMotionNetInterruptDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	I32 ret;

	if( m_isSetFactor == __NO )
	{
		MessageBox( """Set Factor"" first please." );
		return;
	}

#ifdef _VIRTUAL_FUNCTIONS
	ret = 0;
#else
	ret = APS_reset_field_bus_int_motion( 
			m_axisId   // I32 Item_No
			);
#endif
	// Error check
	// 錯誤檢查, 有錯誤跳出警告視窗
	if( ret != ERR_NoError )
	{
		MessageBox( "APS_7856_reset_field_bus_int_mnet() failed." );
		return;
	}
}

// Thread function, for motion net(MNet) interrupt waiting
// 執行緒程式，用來等待Motion-Net中斷,並做中斷後的處理工作
DWORD WINAPI ThreadProc( LPVOID lpParameter )
{
	CMotionNetInterruptDlg *dlg = (CMotionNetInterruptDlg*)lpParameter;
	const I32 intNum = dlg->m_intNum;
	CString str;
	I32 ret;

//	dlg->f_resetText();
	
	//使用interrupt event 前，先確保其為非觸發狀態
	// Reset it to non-signaled state.
	APS_reset_int( intNum );

	while( dlg->m_leave() == __NO )
	{
		ret = APS_wait_single_int( intNum, -1 ); 
		
		if( ret == ERR_NoError )
		{
			if( dlg->m_leave() == __YES )
			{
				str = "Thread will be stopped.";
				break;
			}else
				str = "Int occure! (Motion done!)";
			
			dlg->f_addText( str );
		}else
		{
			str = "Int failed!";
			dlg->f_addText( str );
			Sleep(100);
		}

		APS_reset_int( intNum );
	}

	return 0;
}

void CMotionNetInterruptDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	if( m_threadHandle == NULL )
	{
		if( m_isSetFactor == __NO )
		{
			MessageBox( """Set Factor"" first please." );
			return;
		}

		if( m_isIntEnable == __NO )
		{
			MessageBox( """Enable INT"" first please." );
			return;
		}

		// Set the flag.
		m_isLeaveThread = __NO;

		m_threadHandle = CreateThread(
			0,            // LPSECURITY_ATTRIBUTES lpThreadAttributes, // SD
			0,            // initial stack size
			ThreadProc,   // thread function
			this,		  // thread argument
			0,            // creation option
			&m_threadId   // thread identifier
			);

		_ASSERT( m_threadHandle != NULL );

		f_resetText();
		f_addText( CString("Start wait thread.") );

		//mSetState( STA_WAIT );
	}else
	{ // 當使用者想要中止中斷事件處理,所必要處理的程序
	  // The following process must be done when users want to stop interrupt operation.
		
		DWORD r;

		//Set the flag.
		m_isLeaveThread = __YES;

		// 強制使中斷發生
		// Force the interrupt event occured.
		APS_set_int( m_intNum );
		
		// 等待使用者執行緒(Thread)返回
		// Wait the thread that user created returned.
		r = WaitForSingleObject( m_threadHandle, -1 );
		f_addText( CString("Wait thread stopped.") );

		// 釋放資源
		// Release handle.
		CloseHandle( m_threadHandle );
		
		// 變數從新設定初始化
		// Reset variables to initial state.
		m_threadHandle = NULL;
		m_threadId     = 0;
	}

	m_InterfaceCtrl();
}

void CMotionNetInterruptDlg::f_resetText()
{
	CListBox *list = (CListBox *)GetDlgItem( IDC_LIST1 );
	list->ResetContent();
}

void CMotionNetInterruptDlg::f_addText( CString &Str )
{
	CListBox *list = (CListBox *)GetDlgItem( IDC_LIST1 );
	list->AddString( Str );
}

void CMotionNetInterruptDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	I32 distance    = 1000;
	I32 maxVelocity = 10000;
	I32 ret; 

	ret = APS_relative_move( m_axisId, distance, maxVelocity );

	if( ret != ERR_NoError )
	{
		MessageBox( "APS_relative_move() failed." );
		return;
	}
}

void CMotionNetInterruptDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	I32 distance    = -1000;
	I32 maxVelocity = 10000;
	I32 ret;

	ret = APS_relative_move( m_axisId, distance, maxVelocity );

	if( ret != ERR_NoError )
	{
		MessageBox( "APS_relative_move() failed." );
		return;
	}
}

void CMotionNetInterruptDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	I32 ret;
	
	static char BASED_CODE szFilter[] = "Config Files (*.xml)|*.xml|All Files (*.*)|*.*||";
 

	CFileDialog fileOpen(
		TRUE, 
		NULL, // LPCTSTR lpszDefExt = NULL, 
		NULL, // LPCTSTR lpszFileName = NULL, 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, //DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
		szFilter, // LPCTSTR lpszFilter = NULL, 
		NULL );   // CWnd* pParentWnd = NULL );

	fileOpen.DoModal();


	ret = APS_load_param_from_file( fileOpen.GetPathName() );
	
	if( ret != ERR_NoError )
	{
		MessageBox( "APS_load_param_from_file() failed." );
		return;
	}
}

void CMotionNetInterruptDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	I32 axid = m_axisId;

	if( m_isConnect == __YES )
	{
		APS_get_command( axid, &m_edit_cmd );
		APS_get_position( axid, &m_edit_pos );
		m_edit_sts = APS_motion_status( axid );
		m_edit_io  = APS_motion_io_status( axid );

		UpdateData(FALSE);
	}

	CDialog::OnTimer(nIDEvent);
}
