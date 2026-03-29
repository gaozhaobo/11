// DIODlg.cpp : implementation file
//

#include "stdafx.h"
#include "DIO.h"
#include "DIODlg.h"

///// ADLINK define //////
#include "APS168.h"
#include "APS_Define.h"
#include "ErrorCodeDef.h"
#include "type_def.h"
//////////////////////////

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

I32 CardId =0;
I32 m_IsInitial = 0;
I32 DO_Group = 1;
//I32 DO_Group = 0;
I32 ret = 0;

void CDIODlg::Function_Result(int Ret)
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


// CDIODlg dialog




CDIODlg::CDIODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDIODlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon( IDI_ICON_ADLINK );
}

void CDIODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDIODlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_initial, &CDIODlg::OnBnClickedinitial)
	ON_BN_CLICKED(IDC_select_all, &CDIODlg::OnBnClickedselectall)
	ON_BN_CLICKED(IDC_clear, &CDIODlg::OnBnClickedclear)
	ON_BN_CLICKED(BUTTON_SetDo, &CDIODlg::OnBnClickedSetdo)
	ON_BN_CLICKED(IDC_BUTTON1, &CDIODlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDIODlg message handlers

BOOL CDIODlg::OnInitDialog()
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
	CardId = 0;
	m_IsInitial = _NO;
	m_InterfaceIni();
	m_InterfaceCtr();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDIODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDIODlg::OnPaint()
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
HCURSOR CDIODlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDIODlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	I32 Velocity ;
	F64 Velocity_f ; 
	I32 DO, DI;

	Channel = GetDlgItemInt(IDC_EDIT1);


	//Read extension digital output
	__ReadDo();

	//Read extension digital input
	__ReadDi();

	Function_Result(APS_read_d_channel_output(CardId, DO_Group, Channel, &DO));
	SetDlgItemInt(IDC_EDIT3, DO);
	Function_Result(APS_read_d_channel_input(CardId, DO_Group, Channel, &DI));
	SetDlgItemInt(IDC_EDIT4, DI);

	
	//ret = APS_get_command_velocity(0 ,&Velocity); // ret = 0 ,
	//Function_Result( ret );
	//SetDlgItemInt(IDC_EDIT1, Velocity);
	//ret = APS_get_command_velocity_f(0 ,&Velocity_f); // ret = 0 ,
	//Function_Result( ret );
	//SetDlgItemInt(IDC_EDIT2, Velocity_f);
	

	CDialog::OnTimer(nIDEvent);
}

void CDIODlg::OnBnClickedinitial()
{
	// TODO: Add your control notification handler code here
	//Card Initial Start/////////////////////////////////////////////////////////////////////////////
	
	I32 BoardID_InBits = 0,Mode=1,Board_ID = 0;
	I16 Manual_ID    = 0;
	I32 i = 0,Info=0;
	
	CString str;
	

	if( m_IsInitial == _NO ) // User want to initial card
	{

		// Initial card
		ret = APS_initial( &BoardID_InBits,  Mode );

		if( ret == ERR_NoError )
		{

			for( i = 0; i < 16; i++ )
			{
				if(  (BoardID_InBits & ( 1 << i )) != 0  )
				{
					CardId = i;
					break;
				}
			}


			// Get Driver version
			Function_Result( APS_get_device_info( CardId, 0x10, &Info ) );
			SetDlgItemInt( EDIT_driver_ver, Info );

			// Get PCB version
			//Function_Result( APS_get_device_info( Board_ID, 0x30, &Info ) ); 
			//str.Format( "0x%x", Info );
			//SetDlgItemText( EDIT_PCB_ver, str );
			Info = APS_device_driver_version(CardId);
			SetDlgItemInt( EDIT_PCB_ver, Info );

			// Get FPGA version
			Function_Result( APS_get_device_info( CardId, 0x20, &Info ) );
			str.Format( "0x%x", Info );
			SetDlgItemText( EDIT_FPGA_ver, str );

			// Get DLL Version
			SetDlgItemInt( EDIT_DLL_ver, APS_version() );


			

			m_IsInitial = _YES;  // Enable user interface
			m_InterfaceCtr();
			SetTimer(1,1,NULL); // Enable Timer
			MessageBox( "Initial OK", NULL,MB_OK );
			pInitial->SetWindowText( "Close" );
		}
		else
		{
			KillTimer(1);       // Disable Timer
			APS_close();       // Closed Card
		    m_IsInitial = _NO; // Disable user interface
		    m_InterfaceCtr();
		    MessageBox( "Initial Failed", NULL,MB_OK );
		}
	}
	else if( m_IsInitial == _YES ) // User want to close card
	{
		for( i = 0; i < MAXCHANNEL; i++ )
		{
			pCheck[i]->SetCheck(0);
		}

		KillTimer(1);      // Disable Timer
		APS_close();      // Closed Card
		m_IsInitial = _NO; // Disable user interface
		m_InterfaceCtr();
		MessageBox( "Card Be Closed", NULL,MB_OK );
		pInitial->SetWindowText( "Initial" );
	}
    /////////Card Initial End/////////////////////////////////////////////////////////////
}

void CDIODlg::OnBnClickedselectall()
{
	// TODO: Add your control notification handler code here
	I32 i = 0;
	
	for( i = 0; i < MAXCHANNEL; i++ )
	{
		pCheck[i]->SetCheck(1);
	}
}

void CDIODlg::OnBnClickedclear()
{
	// TODO: Add your control notification handler code here
	I32 i = 0;

	for( i = 0; i < MAXCHANNEL; i++ )
	{
		pCheck[i]->SetCheck(0);
	}	
}

void CDIODlg::__ReadDo()
{
	
	I32 DO_Data = 0;
	I32 i = 0;
	CDC  *pDC;
	CRect Rect;


	// Read DO value
	//ret = c154_get_gpio_output_ex( CardId, &DO_Data );
	ret = APS_read_d_output(CardId,DO_Group,&DO_Data);
	Function_Result( ret );


	if( ret == ERR_NoError )
	{
		// The corresponding bit status is "1"  -> corresponding edit component's background color is green
		// The corresponding bit status is "0"  -> corresponding edit component's background color is black 
		for( i = 0; i < MAXCHANNEL; i++ )
		{
			if( DO_Data & ( 1 << i ) )
			{
				pDC = pDo_status[i]->GetDC();
				pDo_status[i]->GetClientRect(&Rect);
				pDC->FillSolidRect(Rect, 0xff00); //green
				ReleaseDC(pDC);
			}
			else
			{
				pDC = pDo_status[i]->GetDC();
				pDo_status[i]->GetClientRect(&Rect);
				pDC->FillSolidRect(Rect, 0x0); //black
				ReleaseDC(pDC);
			}
		}
	}
}

void CDIODlg::__SetDo()
{
	I32 CheckBoxStatus = 0;
	I32 i              = 0;
	I32 DO_Data = 0;
	
	

	// Check DO value setting of user.
	for( i = 0; i < MAXCHANNEL; i++ )
	{
		CheckBoxStatus = pCheck[i]->GetState();

		if( CheckBoxStatus == 1 )
			DO_Data = DO_Data | ( 1 << i );
	}

	// Set DO value
	//ret =  c154_set_gpio_output_ex( CardId, DO_Data );
	ret = APS_write_d_output( CardId, DO_Group, DO_Data );
	Function_Result(ret);
}

void CDIODlg::__ReadDi()
{
	
	I32 DI_Data = 0;
	I32 i = 0;
	CDC  *pDC;
	CRect Rect;


	// Read DI value
	//ret = c154_get_gpio_input_ex( CardId, &DI_Data );
    ret  = APS_read_d_input(CardId,DO_Group,&DI_Data);
	Function_Result( ret );

	if( ret == ERR_NoError )
	{
		// The corresponding bit status is "1"  -> corresponding edit component's background color is green
		// The corresponding bit status is "0"  -> corresponding edit component's background color is black 
		for( i = 0; i < MAXCHANNEL; i++ )
		{
			if( DI_Data & ( 1 << i ) )
			{
				pDC = pDi_status[i]->GetDC();
				pDi_status[i]->GetClientRect(&Rect);
				pDC->FillSolidRect(Rect, 0xff00); //green
				ReleaseDC(pDC);
			}
			else
			{
				pDC = pDi_status[i]->GetDC();
				pDi_status[i]->GetClientRect(&Rect);
				pDC->FillSolidRect(Rect, 0x0); //black
				ReleaseDC(pDC);
			}
		}
	}
}

void CDIODlg::m_InterfaceIni()
{
	I32 i = 0;

	//Button
	pInitial      = (CButton *)GetDlgItem( IDC_initial    );
	pSelect_all   = (CButton *)GetDlgItem( IDC_select_all ); 
	pClear        = (CButton *)GetDlgItem( IDC_clear      );
	pSetDo        = (CButton *)GetDlgItem(  BUTTON_SetDo  );
   
	for( i = 0; i < MAXCHANNEL; i++ )
	{
		pCheck[i]      = (CButton *)GetDlgItem( CheckBox_d0_0 + i );
		pDo_status[i]  = (CButton *)GetDlgItem( EDIT_do_0 + i     );
	    pDi_status[i]  = (CButton *)GetDlgItem( EDIT_di_0 + i     );
	}

	//Edit
	pDriver_Ver   = (CWnd*)GetDlgItem( EDIT_driver_ver );
	pPCB_Ver      = (CWnd*)GetDlgItem( EDIT_PCB_ver    );
	pFPGA_Ver     = (CWnd*)GetDlgItem( EDIT_FPGA_ver   );
	pDLL_Ver      = (CWnd*)GetDlgItem( EDIT_DLL_ver    );


	pDriver_Ver   ->EnableWindow( 0 );
	pPCB_Ver      ->EnableWindow( 0 );
	pFPGA_Ver     ->EnableWindow( 0 );
	pDLL_Ver      ->EnableWindow( 0 );
	pSelect_all   ->EnableWindow( 0 );
	pClear        ->EnableWindow( 0 );
	
	for( i = 0; i < MAXCHANNEL; i++ )
	{
		pCheck[i]     ->EnableWindow( 0 );
		pDo_status[i] ->EnableWindow( 0 );
	    pDi_status[i] ->EnableWindow( 0 );
	}
}

void CDIODlg::m_InterfaceCtr()
{
	I32 value = 0;
	I32 i     = 0;

	if( m_IsInitial == _YES )
		value = TRUE;
	else
		value = FALSE;

	pDriver_Ver      ->EnableWindow( value );
	pPCB_Ver         ->EnableWindow( value );
	pFPGA_Ver        ->EnableWindow( value );
	pDLL_Ver         ->EnableWindow( value );
	pSelect_all      ->EnableWindow( value );
	pClear           ->EnableWindow( value );
	pSetDo           ->EnableWindow( value );
	
	for( i = 0; i < MAXCHANNEL; i++ )
	{
		pCheck[i]     ->EnableWindow( value );
		pDo_status[i] ->EnableWindow( value );
	    pDi_status[i] ->EnableWindow( value );
	}
}

void CDIODlg::OnBnClickedSetdo()
{
	// TODO: Add your control notification handler code here

	//Write extension digital output
	__SetDo();
}


void CDIODlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	I16 ret;
	U16 value;
	value = GetDlgItemInt(IDC_EDIT2);
	ret = APS_write_d_channel_output(CardId, DO_Group, Channel, value);
}
