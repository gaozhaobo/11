// 8144_MotionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "8144_Motion.h"
#include "8144_MotionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

I16 TotalCard = 0;
I16 CardID = 0;
I16 Card_Pci_8144_Status[16];
I16 Now_Max_Card_Pci_8144=0;
I16 ALL_Max_PCI_8144_Card=16;
I16 Do_Status, DI_Status, Rtn_Msg, Motion_Counter;
bool Int_Flag = false;
I32 Int_No;

UINT Motion_Interrupt(LPVOID pParam)
{
	CMy8144_MotionDlg *thread = (CMy8144_MotionDlg*) pParam;

	if (Int_Flag == true)
	{
		//Rtn_Msg = _8144_wait_single_motion_interrupt(thread->GetDlgItemInt(IDC_Tbox_AxisNO), 0, 10000);
		Rtn_Msg = APS_wait_single_int( Int_No, 10000 );

		if(Rtn_Msg == 0)	
			Motion_Counter = Motion_Counter + 1;

		APS_reset_int( Int_No );
	}
	return 0;
}

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
// CMy8144_MotionDlg dialog

CMy8144_MotionDlg::CMy8144_MotionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy8144_MotionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy8144_MotionDlg)
	m_TvStr = 0.0;
	m_TvMaxVel = 0.0;
	m_TvTacc = 0.0;
	m_TrDis = 0;
	m_TrMaxVel = 0.0;
	m_TrStr = 0;
	m_TrTacc = 0.0f;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMy8144_MotionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy8144_MotionDlg)
	DDX_Text(pDX, IDC_Tbox_TvStr, m_TvStr);
	DDX_Text(pDX, IDC_Tbox_TvMaxVel, m_TvMaxVel);
	DDX_Text(pDX, IDC_Tbox_TvTacc, m_TvTacc);
	DDX_Text(pDX, IDC_Tbox_TrDis, m_TrDis);
	DDX_Text(pDX, IDC_Tbox_TrMaxVel, m_TrMaxVel);
	DDX_Text(pDX, IDC_Tbox_TrStr, m_TrStr);
	DDX_Text(pDX, IDC_Tbox_TrTacc, m_TrTacc);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy8144_MotionDlg, CDialog)
	//{{AFX_MSG_MAP(CMy8144_MotionDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnExit, OnBtnExit)
	ON_BN_CLICKED(IDC_BtnStop, OnBtnStop)
	ON_BN_CLICKED(IDC_BtnTv_Start, OnBtnTvStart)
	ON_BN_CLICKED(IDC_BtnTr_Start, OnBtnTrStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnBtn_SetInt)
	ON_BN_CLICKED(IDC_BUTTON2, OnBtn_StopInterrupt)
	ON_BN_CLICKED(IDC_BUTTON3, OnBtn_WaitInterrupt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8144_MotionDlg message handlers

BOOL CMy8144_MotionDlg::OnInitDialog()
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

	I32 CardID_InBit;				
	I16 RET=0;
	I16 i=0;
	I16 AxisNum=0, AxisNO_start, AxisNO_end;
	TotalCard=0;
	I32 GetData;

	RET = APS_initial(&CardID_InBit, 0);     			// Initial PCI-8144 card
	//RET = _8144_initial(&CardID_InBit, 0);			// Initial PCI-8144 card
	
	for (i = 0; i < ALL_Max_PCI_8144_Card; i++)     // Check how many card on PC
	{
		if (CardID_InBit & (1<<i))
		{
			TotalCard = TotalCard+1;
			Card_Pci_8144_Status[i] = true;
			Now_Max_Card_Pci_8144 = i+1;
			CardID = i;
		}
		else
			Card_Pci_8144_Status[i] = false;
	}

	if (TotalCard == 0)                            // If PCI-8144 is not exist, then close program 
	{
		APS_close();
		MessageBox("No PCI - 8144 Card Exist", "ERROR");
		CDialog::OnOK();
	}

    AxisNO_start = 4 * CardID;

    AxisNO_end = AxisNO_start + 3;
    
	SetDlgItemInt(IDC_Tbox_AxisStart, AxisNO_start);

	SetDlgItemInt(IDC_Tbox_AxisEnd, AxisNO_end);

	SetDlgItemInt(IDC_Tbox_AxisNO, AxisNO_start);
	SetDlgItemInt(IDC_EDIT6, 0);

	//_8144_set_remaining_pulse(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), 0);
	APS_set_command( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), 0 );

	APS_get_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_VS, &GetData );
	SetDlgItemInt(IDC_Tbox_TvStr, UINT(GetData));
	SetDlgItemInt(IDC_Tbox_TrStr, UINT(GetData));

	APS_get_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_ACC, &GetData );
	SetDlgItemInt(IDC_Tbox_TvTacc, UINT(GetData));
	SetDlgItemInt(IDC_Tbox_TrTacc, UINT(GetData));

	SetTimer(1, 100, NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy8144_MotionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy8144_MotionDlg::OnPaint() 
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
HCURSOR CMy8144_MotionDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy8144_MotionDlg::OnBtnExit() 
{
	// TODO: Add your control notification handler code here
	APS_close();

	CDialog::OnOK();	
}

void CMy8144_MotionDlg::OnBtnStop() 
{
	// TODO: Add your control notification handler code here
	
	//_8144_set_gpio_output(CardID, 0);

	//_8144_emg_stop(I16(GetDlgItemInt(IDC_Tbox_AxisNO)));
	APS_emg_stop(I32(GetDlgItemInt(IDC_Tbox_AxisNO)));
}

void CMy8144_MotionDlg::OnBtnTvStart() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	//_8144_set_gpio_output(CardID, 9);

	//_8144_set_limit_logic(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), 1);

	//_8144_tv_move(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), m_TvStr, m_TvMaxVel, m_TvTacc);

	APS_set_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_EL_LOGIC, 1 );
	APS_set_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_VS, m_TvStr );
	APS_set_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_ACC, m_TvTacc );

	APS_velocity_move( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), m_TvMaxVel );
}	

void CMy8144_MotionDlg::OnBtnTrStart() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	//_8144_set_gpio_output(CardID, 9);

	//_8144_set_limit_logic(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), 1);

	//_8144_start_tr_move(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), m_TrDis, m_TrStr, m_TrMaxVel, m_TrTacc);
	
	APS_set_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_EL_LOGIC, 1 );
	APS_set_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_VS, m_TrStr );
	APS_set_axis_param( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), PRA_ACC, m_TrTacc );

	APS_relative_move( I32(GetDlgItemInt(IDC_Tbox_AxisNO)), m_TrDis, m_TrMaxVel );
}

void CMy8144_MotionDlg::OnTimer(UINT_PTR nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CWnd *pWnd, *pWnd1;

	CDC *pDC, *pDC1;

	CRect Rect, Rect1;

	I32 Remain_Pulse;

	I16 i;
	I32 MotionIO_Status, Motion_Status;

	//_8144_get_mio_status(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), &MotionIO_Status);
	MotionIO_Status = APS_motion_io_status(I32(GetDlgItemInt(IDC_Tbox_AxisNO)));

	//_8144_motion_status(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), &Motion_Status);
	Motion_Status = APS_motion_status(I32(GetDlgItemInt(IDC_Tbox_AxisNO)));

	//if( MotionIO_Status & 0x80 == 128 )
	//	MotionIO_Status = MotionIO_Status - 128;

	if ( MotionIO_Status & 0x4 )
	{
		pWnd = GetDlgItem(IDC_LightNEL+0);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0xff00);
		ReleaseDC(pDC);
	}
	else
	{
		pWnd = GetDlgItem(IDC_LightNEL+0);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0x00);
		ReleaseDC(pDC);
	}

	if ( MotionIO_Status & 0x2 )
	{
		pWnd = GetDlgItem(IDC_LightNEL+1);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0xff00);
		ReleaseDC(pDC);
	}
	else
	{
		pWnd = GetDlgItem(IDC_LightNEL+1);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0x00);
		ReleaseDC(pDC);
	}

	if ( MotionIO_Status & 0x8 )
	{
		pWnd = GetDlgItem(IDC_LightNEL+2);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0xff00);
		ReleaseDC(pDC);
	}
	else
	{
		pWnd = GetDlgItem(IDC_LightNEL+2);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0x00);
		ReleaseDC(pDC);
	}

	if ( MotionIO_Status & 0x10 )
	{
		pWnd = GetDlgItem(IDC_LightNEL+3);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0xff00);
		ReleaseDC(pDC);
	}
	else
	{
		pWnd = GetDlgItem(IDC_LightNEL+3);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0x00);
		ReleaseDC(pDC);
	}

	if ( MotionIO_Status & 0x8000 )
	{
		pWnd = GetDlgItem(IDC_LightNEL+4);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0xff00);
		ReleaseDC(pDC);
	}
	else
	{
		pWnd = GetDlgItem(IDC_LightNEL+4);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0x00);
		ReleaseDC(pDC);
	}

	if ( MotionIO_Status & 0x10000 )
	{
		pWnd = GetDlgItem(IDC_LightNEL+5);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0xff00);
		ReleaseDC(pDC);
	}
	else
	{
		pWnd = GetDlgItem(IDC_LightNEL+5);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0x00);
		ReleaseDC(pDC);
	}

	if ( MotionIO_Status & 0x20000 )
	{
		pWnd = GetDlgItem(IDC_LightNEL+6);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0xff00);
		ReleaseDC(pDC);
	}
	else
	{
		pWnd = GetDlgItem(IDC_LightNEL+6);
		pDC = pWnd->GetDC();
		pWnd->GetClientRect(&Rect);
		pDC->FillSolidRect(Rect, 0x00);
		ReleaseDC(pDC);
	}

	//for (i = 0; i < 7; i++)
	//{
	//	if ( MotionIO_Status & (1<<i) )
	//	{
	//		pWnd = GetDlgItem(IDC_LightNEL+i);
	//		pDC = pWnd->GetDC();
	//		pWnd->GetClientRect(&Rect);
	//		pDC->FillSolidRect(Rect, 0xff00);
	//		ReleaseDC(pDC);
	//	}
	//	else
	//	{
	//		pWnd = GetDlgItem(IDC_LightNEL+i);
	//		pDC = pWnd->GetDC();
	//		pWnd->GetClientRect(&Rect);
	//		pDC->FillSolidRect(Rect, 0x00);
	//		ReleaseDC(pDC);
	//	}
	//}

	if ( Motion_Status & 0x1 )
	{
		pWnd1 = GetDlgItem(IDC_EDIT1);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0xff00);
		ReleaseDC(pDC1);
	}
	else
	{
		pWnd1 = GetDlgItem(IDC_EDIT1);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0x00);
		ReleaseDC(pDC1);
	}
	
	if ( Motion_Status & 0x10 )
	{
		pWnd1 = GetDlgItem(IDC_EDIT2);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0xff00);
		ReleaseDC(pDC1);
	}
	else
	{
		pWnd1 = GetDlgItem(IDC_EDIT2);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0x00);
		ReleaseDC(pDC1);
	}

	if ( Motion_Status & 0x40 )
	{
		pWnd1 = GetDlgItem(IDC_EDIT3);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0xff00);
		ReleaseDC(pDC1);
	}
	else
	{
		pWnd1 = GetDlgItem(IDC_EDIT3);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0x00);
		ReleaseDC(pDC1);
	}

	if ( Motion_Status & 0x4 )
	{
		pWnd1 = GetDlgItem(IDC_EDIT4);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0xff00);
		ReleaseDC(pDC1);
	}
	else
	{
		pWnd1 = GetDlgItem(IDC_EDIT4);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0x00);
		ReleaseDC(pDC1);
	}

	if ( Motion_Status & 0x8 )
	{
		pWnd1 = GetDlgItem(IDC_EDIT5);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0xff00);
		ReleaseDC(pDC1);
	}
	else
	{
		pWnd1 = GetDlgItem(IDC_EDIT5);
		pDC1 = pWnd1->GetDC();
		pWnd1->GetClientRect(&Rect1);
		pDC1->FillSolidRect(Rect1, 0x00);
		ReleaseDC(pDC1);
	}

	//for (i = 0; i < 3; i++)
	//{
	//	if ( Motion_Status & (4<<i) )
	//	{
	//		pWnd1 = GetDlgItem(IDC_EDIT3+i);
	//		pDC1 = pWnd1->GetDC();
	//		pWnd1->GetClientRect(&Rect1);
	//		pDC1->FillSolidRect(Rect1, 0xff00);
	//		ReleaseDC(pDC1);
	//	}
	//	else
	//	{
	//		pWnd1 = GetDlgItem(IDC_EDIT3+i);
	//		pDC1 = pWnd1->GetDC();
	//		pWnd1->GetClientRect(&Rect1);
	//		pDC1->FillSolidRect(Rect1, 0x00);
	//		ReleaseDC(pDC1);
	//	}
	//}

	//_8144_get_remaining_pulse(GetDlgItemInt(IDC_Tbox_AxisNO), &Remain_Pulse);
	APS_get_command(I32(GetDlgItemInt(IDC_Tbox_AxisNO)), &Remain_Pulse);

	SetDlgItemInt(IDC_EDIT7, int(Remain_Pulse));

	SetDlgItemInt(IDC_EDIT6, Motion_Counter);

	CDialog::OnTimer(nIDEvent);
}

void CMy8144_MotionDlg::OnBtn_SetInt() 
{
	// TODO: Add your control notification handler code here
	//_8144_set_motion_interrupt_factor(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), 1);

	Int_No = APS_set_int_factor(I32(GetDlgItemInt(IDC_Tbox_AxisNO)/4), I32(GetDlgItemInt(IDC_Tbox_AxisNO)), 0, 1);
	APS_int_enable(I32(GetDlgItemInt(IDC_Tbox_AxisNO)/4), 1);
}

void CMy8144_MotionDlg::OnBtn_StopInterrupt() 
{
	// TODO: Add your control notification handler code here

	Int_Flag = false;
	//_8144_set_motion_interrupt_factor(I16(GetDlgItemInt(IDC_Tbox_AxisNO)), 0);

	APS_set_int_factor(I32(GetDlgItemInt(IDC_Tbox_AxisNO)/4), I32(GetDlgItemInt(IDC_Tbox_AxisNO)), 0, 0);
	APS_int_enable(I32(GetDlgItemInt(IDC_Tbox_AxisNO)/4), 0);	
}

void CMy8144_MotionDlg::OnBtn_WaitInterrupt() 
{
	// TODO: Add your control notification handler code here
	
	Int_Flag = true;

	AfxBeginThread(Motion_Interrupt, this);
}
