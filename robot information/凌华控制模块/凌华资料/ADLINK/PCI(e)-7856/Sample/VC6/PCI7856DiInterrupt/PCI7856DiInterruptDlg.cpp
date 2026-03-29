// PCI7856DiInterruptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PCI7856DiInterrupt.h"
#include "PCI7856DiInterruptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CPCI7856DiInterruptDlg dialog

CPCI7856DiInterruptDlg::CPCI7856DiInterruptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPCI7856DiInterruptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPCI7856DiInterruptDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	mState  = STA_CLOSED;
	mCardId = 0;
	mHslBus = 1;
	mModule = 1;  //若ID有變更請在此修改。(If Slave ID is changed, please set the right ID of slave DI module)
	
	mIntHandle = 0; 
	
	mThreadHandle = NULL;
	mThreadId = 0;
}

void CPCI7856DiInterruptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPCI7856DiInterruptDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPCI7856DiInterruptDlg, CDialog)
	//{{AFX_MSG_MAP(CPCI7856DiInterruptDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPCI7856DiInterruptDlg message handlers

BOOL CPCI7856DiInterruptDlg::OnInitDialog()
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
	mUIChange();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPCI7856DiInterruptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPCI7856DiInterruptDlg::OnPaint() 
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
HCURSOR CPCI7856DiInterruptDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPCI7856DiInterruptDlg::mSetState( I32 State )
{
	switch( State )
	{
	case STA_CLOSED:     //	(0x00) //0x0000?
		mState = 0;		 // if system close, all sub status must be close.
		break;

	case STA_INIT:	     //	(0x01) //0x0000?
		mState |= (1 << BIT_INIT);
		break;

	case STA_CONNECT:    //	(0x10) //0x000?0
		mState |= (1 << BIT_CONNECT);
		break;

	case STA_DISCONNECT: // (0x00) //0x000?0
		mState &= ~((I32)(1 << BIT_CONNECT));
		break;

	case STA_INTEN:
		mState |= (1 << BIT_ENABLE);
		break;

	case STA_INTDIS:
		mState &= ~((I32)(1 << BIT_ENABLE));
		break;

	case STA_CFG:
		mState |= (1 << BIT_CFG);
		break;

	case STA_NOTCFG:
		mState &= ~((I32)(1 << BIT_CFG));
		break;
		
	case STA_WAIT:
		mState |= (1 << BIT_WAIT);
		break;

	case STA_WAITDONE:
		mState &= ~((I32)(1 << BIT_WAIT));
		break;
	}

	mUIChange();
}

int  CPCI7856DiInterruptDlg::mIsInitial()
{
	if( ( mState >> BIT_INIT ) & 1) 
		return 1;

	return 0;
}

int  CPCI7856DiInterruptDlg::mIsConnect()
{
	if( ( mState >> BIT_CONNECT ) & 1) 
		return 1;

	return 0;
}

int  CPCI7856DiInterruptDlg::mIsEnable()
{
	if( ( mState >> BIT_ENABLE ) & 1) 
		return 1;

	return 0;
}

int  CPCI7856DiInterruptDlg::mIsConfig()
{
	if( ( mState >> BIT_CFG ) & 1) 
		return 1;

	return 0;
}

int  CPCI7856DiInterruptDlg::mIsWait()
{
	if( ( mState >> BIT_WAIT ) & 1) 
		return 1;

	return 0;
}

void CPCI7856DiInterruptDlg::mUIChange()
{
#ifndef __DEBUG

	CButton *pBt_in = (CButton *)GetDlgItem( IDC_BUTTON1 );
	CButton *pBt_cn = (CButton *)GetDlgItem( IDC_BUTTON2 );
	CButton *pBt_en = (CButton *)GetDlgItem( IDC_BUTTON4 );
	CButton *pBt_wt = (CButton *)GetDlgItem( IDC_BUTTON5 );
	CButton *pBt_fc = (CButton *)GetDlgItem( IDC_BUTTON6 );

	ASSERT( pBt_in != NULL );
	ASSERT( pBt_cn != NULL );
	ASSERT( pBt_en != NULL );
	ASSERT( pBt_wt != NULL );

	if( mIsInitial() )
	{  //Device is initialed
		pBt_in->SetWindowText( "Close" );
		pBt_cn->EnableWindow();
		pBt_en->EnableWindow();

		if( mIsEnable() )
			pBt_en->SetWindowText( "Disable" );
		else
			pBt_en->SetWindowText( "Enable" );
		

		if( mIsConnect() )
		{
			pBt_cn->SetWindowText( "Disconnect" );
			pBt_fc->EnableWindow();
			
			if( mIsConfig() )
			{
				pBt_fc->SetWindowText( "Clear Factor" );

				if( mIsWait() )
					pBt_wt->EnableWindow(FALSE);
				else
					pBt_wt->EnableWindow();

			}else
			{
				pBt_fc->SetWindowText( "Set Factor" );
				pBt_wt->EnableWindow(FALSE);
			}
	
		}else
		{ // Disconnect HSL
			pBt_cn->SetWindowText( "Connect" );
			pBt_en->EnableWindow(FALSE);
			pBt_wt->EnableWindow(FALSE);
			pBt_fc->EnableWindow(FALSE);
		}

		

	}else
	{ // Device is close.
		pBt_in->SetWindowText( "Initial" );
		pBt_cn->EnableWindow(FALSE);
		pBt_en->EnableWindow(FALSE);
		pBt_wt->EnableWindow(FALSE);
		pBt_fc->EnableWindow(FALSE);
	}

#endif	
}

void CPCI7856DiInterruptDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here

	//***********************************************************************
	// ADLINK SAMPLE CODE 
	//***********************************************************************
	I32 ret;				// Return code. [函式回傳值]
	I32 boardID_InBits = 0; // Return board ID in bit format. [控制卡的ID回傳值,用Bit格式表示]
	I32 mode		   = 0;	// Initail mode [初始化模式]
	I32 cardId		   = 0;	// Device ID [控制卡的ID]
	I32 ver			   = 0; // Return APS library version. [取得APS版本編號]
	I32 cardName       = 0; // Return card name.
	
	// User close device.
	// 使用者關閉控裝置
	if( mIsInitial() )
	{
		APS_close();

		// UI setting (人機介面設定)
		mSetState( STA_CLOSED );
		return;
	}

	// Initial control card.
	// 初始化控制卡
	ret = APS_initial( &boardID_InBits, mode );

	if( ret != ERR_NoError )
	{
		MessageBox( "APS initial failed." );

		// UI setting (人機介面設定)
		mSetState( STA_CLOSED );
		return;
	}

	APS_get_card_name( cardId, &cardName );
	if( cardName != 5 ) //5:PCI-7856
	{
		MessageBox( "PCI-7856 not found." );

		// UI setting (人機介面設定)
		mSetState( STA_CLOSED );
		return;
	}

	// Check APS library version.
	ver = APS_version();
	if( ver < 100721 ) //If library version not match. 
	{ // Interrupt function does not supported. 
		MessageBox( "The device does not support DI interrupt functions." );
		MessageBox( "Device closed." );
		
		APS_close();

		// UI setting (人機介面設定)
		mSetState( STA_CLOSED );
		return;
	}

	mCardId = cardId;

	// UI setting (人機介面設定)
	mSetState( STA_INIT );
}

void CPCI7856DiInterruptDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	I32 ret;

	// Check HSL fieldbus connection is established.
	// 檢查是否已經連線
	if( mIsConnect() )
	{
		// User want to break the connection of fieldbus (HSL).
		// 使用者斷線
		ret = APS_stop_field_bus( mCardId, mHslBus);

		// UI setting (人機介面設定)
		mSetState( STA_DISCONNECT );
		return;
	}

	// PCI-7856 HSL fieldbus ID
	mHslBus = 0;

	// User want to establish the connection of fieldbus.
	// 使用者連線
	ret = APS_start_field_bus( mCardId, mHslBus, 0 );
	if( ret != ERR_NoError )
	{
		MessageBox( "Start HSL fieldbus failed." );
		return;
	}

	// UI setting (人機介面設定)
	mSetState( STA_CONNECT );;
}


void CPCI7856DiInterruptDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	
	// Check the interrupt factor is set or not
	if( mIsConfig() )
	{ // User want to clear interrupt factors.

		if( mIsWait() )
		{
			// Force trigger interrupt, let wait thread pass.
			// 強制觸發中斷訊號,讓wait函式能返回.
			APS_set_int( mIntHandle );
		}

		// Clear interrupt factor on the module.
		// 清除模組上數位輸入變換和中斷的關連
		mIntHandle = APS_set_field_bus_int_factor_di( 
						mCardId, 
						mHslBus,
						mModule, 
						0	// Disable all di factors in the module. 
						);

		// UI setting (人機介面設定)
		mSetState( STA_NOTCFG );
		return;
	}

	// Set DI interrupt factor (Source), which means which DI cause interrupt.
	mIntHandle = APS_set_field_bus_int_factor_di( 
		mCardId,
		mHslBus,
		mModule, 
		0x000000FF	// DI Ch0 to CH7 will cause interrupt 
		);

	// UI setting (人機介面設定)
	mSetState( STA_CFG );
}

void CPCI7856DiInterruptDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here

	I32 ret;

	// Check user want to "Enable" or "Disable" interrupt main switch
	// 判斷使用者要打開或關閉中斷總開關
	if( mIsEnable() )
	{
		// User disable interrupt main switch
		// 使用關閉中斷的總開關
		ret = APS_int_enable( mCardId, 0 ); //Disable Interrupt main switch
		
		// Error check
		// 錯誤檢查, 有錯誤跳出警告視窗
		if( ret != ERR_NoError )
		{
			MessageBox( "APS_int_enable() failed." );
			return;
		}

		// UI setting (人機介面設定)
		mSetState( STA_INTDIS );
		return;
	}

	// User enable interrupt main switch
	// 使用者欲啟動中斷總開關
	ret = APS_int_enable( mCardId, 1 ); //Enable Interrupt main switch
	
	// Error check
	// 錯誤檢查, 有錯誤跳出警告視窗
	if( ret != ERR_NoError )
	{
		MessageBox( "APS_int_enable() failed." );
		return;
	}

	// UI setting (人機介面設定)
	mSetState( STA_INTEN );
}

// Thread function, for DI interrupt waiting
// 執行緒程式，用來等待HSL數位輸入(DI)中斷
DWORD WINAPI ThreadProc( LPVOID lpParameter )
{
	I32		ret;

	CPCI7856DiInterruptDlg *pDlg = (CPCI7856DiInterruptDlg *)lpParameter;
	if( pDlg->mIntHandle == NULL ) return 1;

	// Wait DI interrupt, Set 10 second timeout.
	// If interrupt factor(s) doesn't change state in 10 second. this function will return timeout
	ret = APS_wait_single_int( pDlg->mIntHandle, 10000 ); //Wait 10 second.

	if( ret == ERR_NoError )
	{
		AfxMessageBox( "DI interrupt is occured!" );

		// Users must manual reset the interrupt state to non-triggered state.
		// 你必須在中斷發生後，解除中斷出發狀態
		APS_reset_int( pDlg->mIntHandle );

		// Do interrupt operation here ...
		// Do interrupt operation here ...
		// Do interrupt operation here ...

	}else
	{
		CString str;
		str.Format( "Timeout or wait faild. ERR: %d", ret );
		AfxMessageBox( str );
	}


	pDlg->mSetState( STA_WAITDONE );
	CloseHandle( pDlg->mThreadHandle );
	pDlg->mThreadHandle = NULL;

	return 0;
}


void CPCI7856DiInterruptDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here

	if( mThreadHandle == NULL )
	{
		mThreadHandle = CreateThread(
			0,  // LPSECURITY_ATTRIBUTES lpThreadAttributes, // SD
			0,  // initial stack size
			ThreadProc,    // thread function
			this,		   // thread argument
			0,             // creation option
			&mThreadId // thread identifier
			);

		_ASSERT( mThreadHandle != NULL );

		mSetState( STA_WAIT );
	}
}

