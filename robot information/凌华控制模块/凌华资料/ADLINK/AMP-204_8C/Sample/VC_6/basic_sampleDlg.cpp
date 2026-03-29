// basic_sampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "basic_sample.h"
#include "basic_sampleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


HANDLE m_threadHandle_ini;
DWORD  m_threadId_ini;
DWORD WINAPI ThreadProc_ini( LPVOID lpParameter );

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
// CBasic_sampleDlg dialog

CBasic_sampleDlg::CBasic_sampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBasic_sampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBasic_sampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	
}

void CBasic_sampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBasic_sampleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBasic_sampleDlg, CDialog)
	//{{AFX_MSG_MAP(CBasic_sampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, Initial)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, Close)
	ON_BN_CLICKED(IDC_BUTTON3, Get_Version)
	ON_BN_CLICKED(IDC_BUTTON4, Axis_Monitor)
	ON_BN_CLICKED(IDC_BUTTON5, Load_Param)
	ON_BN_CLICKED(IDC_BUTTON6, motion_done)
	ON_BN_CLICKED(IDC_BUTTON7, homing)
	ON_BN_CLICKED(IDC_BUTTON8, velocity_move)
	ON_BN_CLICKED(IDC_BUTTON9, Jog)
	ON_BN_CLICKED(IDC_BUTTON10, Jog_off)
	ON_BN_CLICKED(IDC_BUTTON11, p2p)
	ON_BN_CLICKED(IDC_BUTTON12, stop_move)
	ON_BN_CLICKED(IDC_BUTTON13, EMG_stop)
	ON_BN_CLICKED(IDC_BUTTON14, Line_2D)
	ON_BN_CLICKED(IDC_BUTTON15, Arc_2D)
	ON_BN_CLICKED(IDC_BUTTON16, Arc_3D)
	ON_BN_CLICKED(IDC_BUTTON17, Helical_3D)
	ON_BN_CLICKED(IDC_BUTTON18, Contour_2D)
	ON_BN_CLICKED(IDC_BUTTON19, Point_table)
	ON_BN_CLICKED(IDC_BUTTON20, Gear_Gantry)
	ON_BN_CLICKED(IDC_BUTTON21, Interrupt)
	ON_BN_CLICKED(IDC_BUTTON22, Digital_IO)
	ON_BN_CLICKED(IDC_BUTTON23, Analog_IO)
	ON_BN_CLICKED(IDC_BUTTON24, CMP_Trigger)
	ON_BN_CLICKED(IDC_BUTTON28, pwm_vao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBasic_sampleDlg message handlers

BOOL CBasic_sampleDlg::OnInitDialog()
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

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBasic_sampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBasic_sampleDlg::OnPaint() 
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
HCURSOR CBasic_sampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBasic_sampleDlg::Initial() 
{
	// TODO: Add your control notification handler code here

			I32 boardID_InBits = 0;
			I32 mode           = 0;
			I32 ret          = 0;
			I32 i            = 0;
			I32 card_name    = 0;
			I32 tamp         = 0;
			I32 StartAxisID  = 0;
			I32 TotalAxisNum = 0;


			// UI protection
			if (v_is_card_initialed == YES)
			{
				MessageBox( "initial ok" );
				return;
			}

			// Card(Board) initial
			ret = APS_initial( &boardID_InBits, mode);

			if( ret == ERR_NoError )
			{
				for (i = 0; i < 16; i++)
				{
					tamp = (boardID_InBits >> i) & 1;

					if( tamp == 1 )
					{
						ret = APS_get_card_name(i, &card_name);

						if (   card_name == DEVICE_NAME_PCI_825458 
							|| card_name == DEVICE_NAME_AMP_20408C )
						{
							ret = APS_get_first_axisId(i, &StartAxisID, &TotalAxisNum);

							//----------------------------------------------------
							v_card_name         = card_name;
							v_board_id          = i;
							v_total_axis        = TotalAxisNum;
							v_is_card_initialed = YES;

							if      (v_total_axis == 4) v_channel = 2;
							else if (v_total_axis == 8) v_channel = 4;
							//----------------------------------------------------

							Is_thread_creat = NO;
							SetDlgItemInt( EDIT_1st_axis, 0);
						
							MessageBox("Initial ok !");

							//Show main form title text
							if (card_name == DEVICE_NAME_PCI_825458 && TotalAxisNum  == 8 ) AfxGetMainWnd()->SetWindowText(_T("PCI-8258 Basic Sample"));
							if (card_name == DEVICE_NAME_PCI_825458 && TotalAxisNum  == 4 ) AfxGetMainWnd()->SetWindowText(_T("PCI-8254 Basic Sample"));
							if (card_name == DEVICE_NAME_AMP_20408C && TotalAxisNum == 8 ) AfxGetMainWnd()->SetWindowText(_T("AMP-208C Basic Sample"));
							if (card_name == DEVICE_NAME_AMP_20408C && TotalAxisNum == 4 ) AfxGetMainWnd()->SetWindowText(_T("AMP-204C Basic Sample"));

							break;
						}
					}
				}

				if (v_board_id == -1)
				{
					v_is_card_initialed = NO;
				    MessageBox("Board Id search error !");
				}	
			}
			else
			{
				v_is_card_initialed = NO;
				MessageBox("Initial fail");
				Function_Result(ret);
			}
}

int CBasic_sampleDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	v_card_name         = 0;
    v_board_id          = -1;
    v_channel           = 0;
    v_total_axis        = 0; 
    v_is_card_initialed = NO;

	Is_thread_creat = NO;

	AfxGetMainWnd()->SetWindowText(_T("Basic Sample"));

	return 0;
}

void CBasic_sampleDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

			I32 Axis_ID  = 0;
            I32 ret      = 0;

            if (v_is_card_initialed == YES)
            {
                for (Axis_ID = 0; Axis_ID < v_total_axis; Axis_ID++)
                {
                    ret = APS_set_servo_on(Axis_ID, OFF);
                }

                ret = APS_close();
            }

	CDialog::OnClose();
}

void CBasic_sampleDlg::Function_Result( I32 Ret )
{
	char MsgStr[256]="Error Code = ";
    char Buff[256];

	_itoa(Ret,Buff,10);     //將整數Ret之值轉成字串後存入Buff,且以10進制表示	
	strcat(MsgStr,Buff);   //將字串Buff接至字串MsgStr後面，然後回傳MsgStr字串參數

	if (Ret != 0)
	{
		MessageBox(MsgStr,NULL,MB_OK); //MessageBox(欲顯示之字串 , 標題 ,按鈕形式)	
	}
}

void CBasic_sampleDlg::Close() 
{
	// TODO: Add your control notification handler code here

	 APS_close();
     v_is_card_initialed = NO;
     MessageBox("Close OK");
	 AfxGetMainWnd()->SetWindowText(_T("Basic Sample"));
}

void CBasic_sampleDlg::Get_Version() 
{
	// TODO: Add your control notification handler code here

	 if( Is_CARD_INITIAL() == NO ) return;
	 
	 CGet_Version *p;
	 p = new CGet_Version( this );

	 p->v_card_name         = v_card_name;
     p->v_board_id          = v_board_id;     
     p->v_channel           = v_channel;        
     p->v_total_axis        = v_total_axis;      
     p->v_is_card_initialed = v_is_card_initialed;


	 //Method 1 (Can't lock main form )
     /*
		p->Create( IDD_Get_Version, GetDesktopWindow() );
		p->ShowWindow( SW_SHOW );
     */

	 //Method 2 (Can lock main form )
	 p->DoModal();
}

I32 CBasic_sampleDlg::Is_CARD_INITIAL(void)
{
	if (v_is_card_initialed == NO)
    {
		MessageBox("Not initialed.");
        return NO;
    }
    else
    {
		return YES;
    }
}

void CBasic_sampleDlg::Axis_Monitor() 
{
	// TODO: Add your control notification handler code here

	 if( Is_CARD_INITIAL() == NO ) return;
	 
	 CAxis_Monitor *p;
	 p = new CAxis_Monitor( this );

	 p->v_card_name         = v_card_name;
     p->v_board_id          = v_board_id;     
     p->v_channel           = v_channel;        
     p->v_total_axis        = v_total_axis;      
     p->v_is_card_initialed = v_is_card_initialed;


	 //Method 1 (Can't lock main form )
     
	 p->Create( IDD_axis_monitor, GetDesktopWindow() );
	 p->ShowWindow( SW_SHOW );
     

	 //Method 2 (Can lock main form )
	 //p->DoModal();	
}

void CBasic_sampleDlg::Load_Param() 
{
	// TODO: Add your control notification handler code here
	I32 ret = 0;
	CString str;


	if( Is_CARD_INITIAL() == NO ) return;

	char strFilter[] = { "xml Files (*.xml)|*.xml|All Files (*.*)|*.*||" };

	CFileDialog FileDlg(TRUE, ".xml", NULL, 0, strFilter);

	if( FileDlg.DoModal() == IDOK )
	{
		str = FileDlg.GetPathName();

		ret = load_parameters_from_file_sample( str );

		if( ret == ERR_NoError )
			MessageBox("Load File OK");
		else
		{
			MessageBox("Load File Failed");
			Function_Result(ret);
		}
	}
}

void CBasic_sampleDlg::motion_done() 
{
	// TODO: Add your control notification handler code here

	if( Is_CARD_INITIAL() == NO ) return;

    I32 ret        = 0;
    I32 Axis_ID    = GetDlgItemInt( EDIT_1st_axis );
    I32 Stop_Code  = 0;
	CString str;



    if (Is_axis_err(Axis_ID) == YES) return;

    ret = check_motion_done_example( Axis_ID, &Stop_Code);


    // Display motion done status
    switch (ret)
    {
		case 0:
			str.Format( "In Motion at Axis: %d", Axis_ID );
			MessageBox(str);
				break;
        case 1:
			str.Format("Motion done at Axis: %d ", Axis_ID );
			MessageBox(str);
                break;
        case -1:
		    str.Format("Error stop at Axis: %d ", Axis_ID );
			MessageBox(str);
                break;
    }
}

I32 CBasic_sampleDlg::Is_axis_err(I32 Axis_ID)
{
	if (Axis_ID < 0 || Axis_ID >= v_total_axis)
    {
		MessageBox("User Input Axis_ID Error !");
		return YES; 
	}
	else
		return NO; 
}

void CBasic_sampleDlg::homing() 
{
	// TODO: Add your control notification handler code here
	if( Is_CARD_INITIAL() == NO ) return;
	I32 ret = 0;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	home_move_example( Axis_ID );
}

void CBasic_sampleDlg::velocity_move() 
{
	// TODO: Add your control notification handler code here
	
	if( Is_CARD_INITIAL() == NO ) return;
	
	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;
	
	velocity_move_example(  Axis_ID );
}

void CBasic_sampleDlg::Jog() 
{
	// TODO: Add your control notification handler code here
	if( Is_CARD_INITIAL() == NO ) return;
	
	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	jog_move_continuous_mode_example(  Axis_ID );
}

void CBasic_sampleDlg::Jog_off() 
{
	// TODO: Add your control notification handler code here
	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	APS_jog_start( Axis_ID, 1 );
	APS_jog_start( Axis_ID, 0 );
	
}

void CBasic_sampleDlg::p2p() 
{
	// TODO: Add your control notification handler code here

	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	p2p_example(  Axis_ID );
	
}

void CBasic_sampleDlg::stop_move() 
{
	// TODO: Add your control notification handler code here
	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;
	
	deceleration_stop_example(  Axis_ID );
	
}

void CBasic_sampleDlg::EMG_stop() 
{
	// TODO: Add your control notification handler code here
	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	emg_stop_example(  Axis_ID );
	
}

void CBasic_sampleDlg::Line_2D() 
{
	// TODO: Add your control notification handler code here
	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	I32 Axis_ID_Array[2] = {0};

	if( Axis_ID == 7 )
	{
		Axis_ID_Array[0] = 7;
		Axis_ID_Array[1] = 0;
	}
	else
	{
		Axis_ID_Array[0] = Axis_ID;
		Axis_ID_Array[1] = Axis_ID + 1;
	}

	interpolation_2D_line_example( Axis_ID_Array );
}

void CBasic_sampleDlg::Arc_2D() 
{
	// TODO: Add your control notification handler code here

    if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	I32 Axis_ID_Array[2] = {0};

	if( Axis_ID == 7 )
	{
		Axis_ID_Array[0] = 7;
		Axis_ID_Array[1] = 0;
	}
	else
	{
		Axis_ID_Array[0] = Axis_ID;
		Axis_ID_Array[1] = Axis_ID + 1;
	}
	
    interpolation_2D_arc_example( Axis_ID_Array );
}

void CBasic_sampleDlg::Arc_3D() 
{
	// TODO: Add your control notification handler code here

	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	I32 Axis_ID_Array[3] = {0};

	if( Axis_ID == 7 )
	{
		Axis_ID_Array[0] = 7;
		Axis_ID_Array[1] = 0;
		Axis_ID_Array[2] = 1;
	}
	else
	{
		Axis_ID_Array[0] = Axis_ID;
		Axis_ID_Array[1] = Axis_ID + 1;
		Axis_ID_Array[2] = Axis_ID + 2;
	}
	
	 interpolation_3D_arc_example( Axis_ID_Array );
}

void CBasic_sampleDlg::Helical_3D() 
{
	// TODO: Add your control notification handler code here

	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	I32 Axis_ID_Array[3] = {0};

	if( Axis_ID == 7 )
	{
		Axis_ID_Array[0] = 7;
		Axis_ID_Array[1] = 0;
		Axis_ID_Array[2] = 1;
	}
	else
	{
		Axis_ID_Array[0] = Axis_ID;
		Axis_ID_Array[1] = Axis_ID + 1;
		Axis_ID_Array[2] = Axis_ID + 2;
	}
	
	interpolation_3D_helical_example( Axis_ID_Array );
}

void CBasic_sampleDlg::Contour_2D() 
{
	// TODO: Add your control notification handler code here

	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	I32 Axis_ID_Array[2] = {0};

	if( Axis_ID == 7 )
	{
		Axis_ID_Array[0] = 7;
		Axis_ID_Array[1] = 0;
	}
	else
	{
		Axis_ID_Array[0] = Axis_ID;
		Axis_ID_Array[1] = Axis_ID + 1;
	}
	
	contour_2D_example( Axis_ID_Array );
}

void CBasic_sampleDlg::Point_table() 
{
	// TODO: Add your control notification handler code here

	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	I32 Axis_ID_Array[2] = {0};

	if( Axis_ID == 7 )
	{
		Axis_ID_Array[0] = 7;
		Axis_ID_Array[1] = 0;
	}
	else
	{
		Axis_ID_Array[0] = Axis_ID;
		Axis_ID_Array[1] = Axis_ID + 1;
	}

	point_table_2D_example(  v_board_id, Axis_ID_Array );
	
}

void CBasic_sampleDlg::Gear_Gantry() 
{
	// TODO: Add your control notification handler code here

	if( Is_CARD_INITIAL() == NO ) return;

	I32 Axis_ID = GetDlgItemInt( EDIT_1st_axis );
	if (Is_axis_err(Axis_ID) == YES) return;

	I32 Axis_ID_Array[2] = {0};

	if( Axis_ID == 7 )
	{
		Axis_ID_Array[0] = 7;
		Axis_ID_Array[1] = 0;
	}
	else
	{
		Axis_ID_Array[0] = Axis_ID;
		Axis_ID_Array[1] = Axis_ID + 1;
	}
	
	gear_example( Axis_ID_Array );
}

void CBasic_sampleDlg::Interrupt() 
{
	// TODO: Add your control notification handler code here
	
	if( Is_CARD_INITIAL() == NO ) return;
	if( Is_axis_err( GetDlgItemInt( EDIT_1st_axis ) ) == YES ) return;

	if( Is_thread_creat == NO )
	{
		Is_thread_creat = YES;

		//Initial ok. Do some things...
	    //Creat Thread to do some things...

			m_threadHandle_ini = CreateThread(
				0,                // LPSECURITY_ATTRIBUTES lpThreadAttributes 
				0,                // initial stack size
				ThreadProc_ini,   // thread function
				this,		      // thread argument
				0,                // creation option
				&m_threadId_ini   // thread identifier
				);
			_ASSERT( m_threadHandle_ini != NULL );
			
			MessageBox( "Wait motion done thread is created.\n You can start a \"p2p\" move." );
	}
	else
	{
		MessageBox( "Thread already created" );
	}	
}

DWORD WINAPI ThreadProc_ini( LPVOID lpParameter )
{
	CBasic_sampleDlg *p = (CBasic_sampleDlg*)lpParameter;

    I32 Board_ID = p->v_board_id;
	I32 Axis_num = p->GetDlgItemInt( EDIT_1st_axis );
	
	if( interrupt_example( Board_ID, Axis_num ) == 0 )
		p->MessageBox( "Interrupt Occur" );

	p->Is_thread_creat = NO;

	return 0;
}

void CBasic_sampleDlg::Digital_IO() 
{
	// TODO: Add your control notification handler code here
	
	if( Is_CARD_INITIAL() == NO ) return;

	DIO_sample( v_board_id );
}

void CBasic_sampleDlg::Analog_IO() 
{
	// TODO: Add your control notification handler code here
	if( Is_CARD_INITIAL() == NO ) return;

	if( v_card_name == DEVICE_NAME_PCI_825458 )
		AIO_sample(  v_board_id );
	else
		MessageBox( "AMP-204/8C Not Support this function" );
}

void CBasic_sampleDlg::CMP_Trigger() 
{
	// TODO: Add your control notification handler code here

	 if( Is_CARD_INITIAL() == NO ) return;
	 
	 CCmpTrig *p;
	 p = new CCmpTrig( this );

	 p->v_card_name         = v_card_name;
     p->v_board_id          = v_board_id;     
     p->v_channel           = v_channel;        
     p->v_total_axis        = v_total_axis;      
     p->v_is_card_initialed = v_is_card_initialed;


	 //Method 1 (Can't lock main form )
     
	 //p->Create( IDD_Cmp_Trig, GetDesktopWindow() );
	 //p->ShowWindow( SW_SHOW );
     
	 //Method 2 (Can lock main form )
	 p->DoModal();
}

void CBasic_sampleDlg::pwm_vao() 
{
	// TODO: Add your control notification handler code here


	 if( Is_CARD_INITIAL() == NO ) return;
	 
	 CPWM_VAO *p;
	 p = new CPWM_VAO( this );

	 p->v_card_name         = v_card_name;
     p->v_board_id          = v_board_id;     
     p->v_channel           = v_channel;        
     p->v_total_axis        = v_total_axis;      
     p->v_is_card_initialed = v_is_card_initialed;


	 //Method 1 (Can't lock main form )
     
	 //p->Create( IDD_Cmp_Trig, GetDesktopWindow() );
	 //p->ShowWindow( SW_SHOW );
     
	 //Method 2 (Can lock main form )
	 p->DoModal();

}
