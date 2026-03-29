// 2D_triggerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "2D_trigger.h"
#include "2D_triggerDlg.h"

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


// CMy2D_triggerDlg dialog




CMy2D_triggerDlg::CMy2D_triggerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy2D_triggerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2D_triggerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy2D_triggerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CMy2D_triggerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy2D_triggerDlg::OnBnClickedButton2)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMy2D_triggerDlg message handlers

BOOL CMy2D_triggerDlg::OnInitDialog()
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
	I32 ret = 0;
	I32 BoardID_InBits;
	I32 Mode = 0; //By system assigned


	ret = APS_initial( &BoardID_InBits, Mode);
	if(ret) 
	{
		MessageBox(TEXT("APS initial fail\n"));
		//goto TEST_END;
	}

	// Set axes servo ON
	ret = APS_set_servo_on( 0, 1 );
	if(ret) 
	{
		printf("Servo on fail\n");
		//goto TEST_END;
	}
	ret = APS_set_servo_on( 1, 1 );
	if(ret) 
	{
		printf("Servo on fail\n");
		//goto TEST_END;
	}


	BoardID = 0;
	dimension = 2;


	SetTimer(1, 100, NULL); 

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy2D_triggerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy2D_triggerDlg::OnPaint()
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
HCURSOR CMy2D_triggerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy2D_triggerDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	I32 ret;
	U32 i = 0;
	//I32 BoardID = 0;
	I32 msts; // Motion status
	MCMP_POINT DataArr[10];
	MCMP_POINT Arr;
	I32 data = 0;
	U32 totalPoint = 10;
	U32 window = 10;

	ret = APS_set_trigger_param( BoardID, TGR_MCMP0_SRC, 0 );
	ret = APS_set_trigger_param( BoardID, TGR_MCMP1_SRC, 1 );

	ret = APS_get_trigger_param( BoardID, TGR_MCMP0_SRC, &data );
	SetDlgItemInt(IDC_EDIT1, data);
	ret = APS_get_trigger_param( BoardID, TGR_MCMP1_SRC, &data );
	SetDlgItemInt(IDC_EDIT2, data);

	// Set PWM output channel 0
	ret = APS_set_trigger_param( BoardID, TGR_TRG0_SRC, 0x40 );
	if(ret) 
	{
		printf("APS_set_trigger_param fail\n");
		//goto TEST_END;
	}
	ret = APS_get_trigger_param( BoardID, TGR_TRG0_SRC, &data );
	SetDlgItemInt(IDC_EDIT3, data);

	ret = APS_set_trigger_param( BoardID, 0x06, 0x01);

	// Reset PWM channel 0 trigger count
	ret = APS_reset_trigger_count( BoardID, 0 );
	if(ret) 
	{
		printf("APS_reset_trigger_count fail\n");
		//goto TEST_END;
	}

	// Reset command
	//ret = APS_set_command( 0, 0 );
	ret = APS_set_command_f( 0, 0 );
	if(ret) 
	{
		printf("APS_set_command fail\n");
		//goto TEST_END;
	}
	//ret = APS_set_command( 1, 0 );
	ret = APS_set_command_f( 1, 0 );
	if(ret) 
	{
		printf("APS_set_command fail\n");
		//goto TEST_END;
	}

	for(i=0; i<totalPoint; i++)
	{
		DataArr[i].axisX = i * 1000 + 1000;
		DataArr[i].axisY = i * 2000 + 2000;
		DataArr[i].axisZ = 0;
		DataArr[i].axisU = 0;
		DataArr[i].chInBit = 1;

	}

	// Set compare points into queue
	ret = APS_set_multi_trigger_table( BoardID, dimension, DataArr, totalPoint, window );
	if(ret) 
	{
		printf("APS_set_multi_trigger_table fail\n");
		//goto TEST_END;
	}

}

void CMy2D_triggerDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	I32 ret;
	I32 Axis_ID_Array[2] = {0, 1};
	I32 Distance_Array[2] = {10000, 20000 };
	I32 Max_Linear_Speed = 2000;

	ret = APS_relative_linear_move( dimension, Axis_ID_Array, Distance_Array, Max_Linear_Speed );
	if(ret) 
	{
		printf("APS_relative_linear_move fail\n");
		//goto TEST_END;
	}

}

void CMy2D_triggerDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	I32 ret;
	I32 data;
	I32 cmd, pos;
	MCMP_POINT Point;

	ret = APS_get_command(0, &cmd);
	SetDlgItemInt(IDC_EDIT5, cmd);
	ret = APS_get_command(1, &cmd);
	SetDlgItemInt(IDC_EDIT6, cmd);
	ret = APS_get_position(0, &pos);
	SetDlgItemInt(IDC_EDIT7, pos);
	ret = APS_get_position(1, &pos);
	SetDlgItemInt(IDC_EDIT8, pos);

	// Check comparator data
	ret = APS_get_multi_trigger_table_cmp( BoardID, dimension, &Point );
	SetDlgItemInt(IDC_EDIT3, Point.axisX);
	SetDlgItemInt(IDC_EDIT4, Point.axisY);
	ret = APS_get_trigger_count( BoardID, 0, &data );
	SetDlgItemInt(IDC_EDIT9, data);

	CDialog::OnTimer(nIDEvent);
}

