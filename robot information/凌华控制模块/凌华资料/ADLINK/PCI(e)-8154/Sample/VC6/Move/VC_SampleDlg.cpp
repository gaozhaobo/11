// VC_SampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VC_Sample.h"
#include "VC_SampleDlg.h"

#include "APS168.h"
#include "APS_Define.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString CC;			  //For data transfer.
I16 CardID =0;	      //Card number for setting.
I16 BusNo  =1;        //Bus number for setting,  Motion Net BusNo is 0.
I32 MOD_No =0;		  //Arrcoding switch On Module. 	
I32 Start_Axis_ID=0;  //First Axis number in Motion Net bus.

I32 AxisID_SingleAxis_ForAbsolute= 0;
I32 AxisID_SingleAxis_ForRelative= 0;
I32 AxisID_SingleAxis_ForHome= 0;
 
I32 Axis_ID_Array_For_2Axes_Move[2]={0,1};
I32 Axis_ID_Array_For_2Axes_ArcMove[2]={0,1};
I32 Axis_ID_Array_For_3Axes_Move[3]={0,1,2};
I32 Axis_ID_Array_For_4Axes_Move[4]={0,1,2,3};
I32 Axis_ID_Array_For_PointTable[4]={0,1,2,3};

bool FunctionFail=false;
bool bIsConnected=false;
I32 CurrectSelAxis=0;

I32 TotalCard=0;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

void CVC_SampleDlg::Function_Result(int Ret)
{
	char MsgStr[]="Error Code = ";
	char Buff[256];
	itoa(Ret,Buff,10);
	strcat(MsgStr,Buff);
	if (Ret != 0){
		MessageBox(MsgStr,NULL,MB_OK);
		FunctionFail=true;
	}else{
		FunctionFail=false;
	}
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
// CVC_SampleDlg dialog

CVC_SampleDlg::CVC_SampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVC_SampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVC_SampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVC_SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVC_SampleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVC_SampleDlg, CDialog)
	//{{AFX_MSG_MAP(CVC_SampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Btn_SingleAbsoluteMove_Backward, OnSingleAbsoluteMoveBackward)
	ON_BN_CLICKED(Btn_SingleAbsoluteMove_Forward, OnSingleAbsoluteMoveForward)
	ON_BN_CLICKED(Btn_SingleAbsoluteMove_Stop, OnSingleAbsoluteMoveStop)
	ON_BN_CLICKED(Btn_SingleRelativeMove_Backward, OnSingleRelativeMoveBackward)
	ON_BN_CLICKED(Btn_SingleRelativeMove_Forward, OnSingleRelativeMoveForward)
	ON_BN_CLICKED(Btn_SingleRelativeMove_Stop, OnSingleRelativeMoveStop)
	ON_BN_CLICKED(Btn_SingleHomeMove_Backward, OnSingleHomeMoveBackward)
	ON_BN_CLICKED(Btn_SingleHomeMove_Forward, OnSingleHomeMoveForward)
	ON_BN_CLICKED(Btn_SingleHomeMove_Stop, OnSingleHomeMoveStop)
	ON_BN_CLICKED(Btn_Linear_2Axes_AbsoluteBackward, OnLinear2AxesAbsoluteBackward)
	ON_BN_CLICKED(Btn_Linear_2Axes_AbsoluteForward, OnLinear2AxesAbsoluteForward)
	ON_BN_CLICKED(Btn_Linear_2Axes_AbsoluteStop, OnLinear2AxesAbsoluteStop)
	ON_BN_CLICKED(Btn_Linear_2Axes_RelateiveBackward, OnLinear2AxesRelateiveBackward)
	ON_BN_CLICKED(Btn_Linear_2Axes_RelateiveForward, OnLinear2AxesRelateiveForward)
	ON_BN_CLICKED(Btn_Linear_2Axes_Relateive_Stop, OnLinear2AxesRelateiveStop)
	ON_BN_CLICKED(Btn_Linear_3Axes_AbsoluteBackward, OnLinear3AxesAbsoluteBackward)
	ON_BN_CLICKED(Btn_Linear_3Axes_AbsoluteForward, OnLinear3AxesAbsoluteForward)
	ON_BN_CLICKED(Btn_Linear_3Axes_AbsoluteStop, OnLinear3AxesAbsoluteStop)
	ON_BN_CLICKED(Btn_Linear_3Axes_RelateiveBackward, OnLinear3AxesRelateiveBackward)
	ON_BN_CLICKED(Btn_Linear_3Axes_RelateiveForward, OnLinear3AxesRelateiveForward)
	ON_BN_CLICKED(Btn_Linear_3Axes_Relateive_Stop, OnLinear3AxesRelateiveStop)
	ON_BN_CLICKED(Btn_Linear_4Axes_AbsoluteBackward, OnLinear4AxesAbsoluteBackward)
	ON_BN_CLICKED(Btn_Linear_4Axes_AbsoluteForward, OnLinear4AxesAbsoluteForward)
	ON_BN_CLICKED(Btn_Linear_4Axes_AbsoluteStop, OnLinear4AxesAbsoluteStop)
	ON_BN_CLICKED(Btn_Linear_4Axes_RelateiveBackward, OnLinear4AxesRelateiveBackward)
	ON_BN_CLICKED(Btn_Linear_4Axes_RelateiveForward, OnLinear4AxesRelateiveForward)
	ON_BN_CLICKED(Btn_Linear_4Axes_Relateive_Stop, OnLinear4AxesRelateiveStop)
	ON_WM_TIMER()
	ON_BN_CLICKED(Btn_ResetCounter, OnResetCounter)
	ON_BN_CLICKED(Btn_Arc_2Axes_Absolute_CCW, OnArc2AxesAbsoluteCCW)
	ON_BN_CLICKED(Btn_Arc_2Axes_Absolute_CW, OnArc2AxesAbsoluteCW)
	ON_BN_CLICKED(Btn_Arc_2Axes_Absolute_Stop2, OnArc2AxesAbsoluteStop2)
	ON_BN_CLICKED(Btn_Arc_2Axes_Relateive_Stop, OnArc2AxesRelateiveStop)
	ON_BN_CLICKED(Btn_Arc_2Axes_Relative_CCW, OnArc2AxesRelativeCCW)
	ON_BN_CLICKED(Btn_Arc_2Axes_Relative_CW, OnArc2AxesRelativeCW)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVC_SampleDlg message handlers

BOOL CVC_SampleDlg::OnInitDialog()
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



//-----------------------------------------------------------------------------
    CardID=0;            
    Start_Axis_ID=0;

	AxisID_SingleAxis_ForAbsolute = Start_Axis_ID;
    AxisID_SingleAxis_ForRelative = Start_Axis_ID;
    AxisID_SingleAxis_ForHome = Start_Axis_ID;

    Axis_ID_Array_For_2Axes_Move[0] = Start_Axis_ID;
    Axis_ID_Array_For_2Axes_Move[1] = Start_Axis_ID + 1;
    
    Axis_ID_Array_For_2Axes_ArcMove[0] = Start_Axis_ID;
    Axis_ID_Array_For_2Axes_ArcMove[1] = Start_Axis_ID + 1;

    Axis_ID_Array_For_3Axes_Move[0] = Start_Axis_ID;
    Axis_ID_Array_For_3Axes_Move[1] = Start_Axis_ID + 1;
    Axis_ID_Array_For_3Axes_Move[2] = Start_Axis_ID + 2;
    
    Axis_ID_Array_For_4Axes_Move[0] = Start_Axis_ID;
    Axis_ID_Array_For_4Axes_Move[1] = Start_Axis_ID + 1;
    Axis_ID_Array_For_4Axes_Move[2] = Start_Axis_ID + 2;
    Axis_ID_Array_For_4Axes_Move[3] = Start_Axis_ID + 3;
    
    Axis_ID_Array_For_PointTable[0] = Start_Axis_ID;
    Axis_ID_Array_For_PointTable[1] = Start_Axis_ID + 1;
    Axis_ID_Array_For_PointTable[2] = Start_Axis_ID + 2;
    Axis_ID_Array_For_PointTable[3] = Start_Axis_ID + 3;
//-----------------------------------------------------------------------------



	
	//Card Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	I32 DPAC_ID_Bits;
    I32 AxisNo;
	I32 Info;
	I32 i;

	TotalCard=0;


	if (APS_initial(&DPAC_ID_Bits, 0)==0)      //Initial Card, CardID is assigned by system.
	{      
		
		for(i=0;i<=15;i++)                     //Find total card's numbers
		{
			if( DPAC_ID_Bits & (1<<i) )
			{ TotalCard = TotalCard + 1; }
		}
		

		//Get Card information
		Function_Result(APS_get_device_info( CardID, 0x10, &Info ));    //Get Driver Version
		SetDlgItemInt(Edit_ShowMaster_DriverVer, Info);

		SetDlgItemInt(Edit_ShowMaster_DLLVer, APS_version());           //Get DLL Version

		Function_Result(APS_get_device_info( CardID, 0x20, &Info ));    //Get CPLD Version
		SetDlgItemInt(Edit_ShowMaster_CPLDVer, Info);
		
		SetTimer(0,50,NULL);


        
		//***************************************************************************************************************************
		for( AxisNo=0; AxisNo<=(4*TotalCard-1); AxisNo++ )
		{
			Function_Result (APS_set_servo_on(AxisNo, 1));               //servo ON 
            Function_Result (APS_set_axis_param(AxisNo, 0, 0));          //PEL/MEL input logic
            Function_Result (APS_set_axis_param(AxisNo, 4, 0));          //Set PRA_ALM_LOGIC
            Function_Result (APS_set_axis_param(AxisNo, 128, 3));        //Set PRA_PLS_IPT_MODE(The user must make change based on actual conditions)
            Function_Result (APS_set_axis_param(AxisNo, 129, 4));        //Set PRA_PLS_OPT_MODE(The user must make change based on actual conditions)
            
            
            //Set Single Move Parameter
            Function_Result (APS_set_axis_param(AxisNo, 33, 1000000));   //Set Acceleration rate
            Function_Result (APS_set_axis_param(AxisNo, 34, 1000000));   //Set Deceleration rate
            Function_Result (APS_set_axis_param(AxisNo, 35, 0));         //Set Start velocity
            Function_Result (APS_set_axis_param(AxisNo, 32, 1));         //Set S-Curve
            
            
            //Set Home Move Parameter
            Function_Result (APS_set_axis_param(AxisNo, 16, 0));         //Set Home mode (Home search 1st mode) 
            Function_Result (APS_set_axis_param(AxisNo, 21, 10000));     //Set Homing maximum Velocity (Unit:pulse/sec)  
            Function_Result (APS_set_axis_param(AxisNo, 25, 152));       //Set Homing leave home Velocity (Unit:pulse/sec) 
            Function_Result (APS_set_axis_param(AxisNo, 24, 0));         //Set Specify the EZ count up Value 
            Function_Result (APS_set_axis_param(AxisNo, 26, 100));       //Set Homing leave home distance.Specify ORG Offset (Unit:pulse)
          
            
            //Set EMG logic
            Function_Result (APS_set_axis_param(AxisNo, 561, 0));        //Select gpio input
          
		}
        //***************************************************************************************************************************
          
		MessageBox("Initial Success!!",NULL,64);
         

	}
	else
	{
		MessageBox("Initial Fail!!",NULL,64);
		APS_close();
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Card Initial End



	//Dialog conponment initial++++++++++++++++++++++++++++++++++++++++++++++++
	SetDlgItemInt(IDC_EDIT1,0);
	SetDlgItemInt(Edit_SetModuleID_ForModuleInfo,0);
	SetDlgItemText(Edit_ShowModule_FPGAVer,      "No Data");
	SetDlgItemText(Edit_ShowModule_PCBTopVer,    "No Data");
	SetDlgItemText(Edit_ShowMaster_PCBBottomVer, "No Data");
	SetDlgItemInt(Edit_SetModuleID_ForGeneralDIO, 0);
	SetDlgItemInt(Edit_SetDOData, 0);
	SetDlgItemText(Edit_ShowDIData, "No Data");
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}








void CVC_SampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVC_SampleDlg::OnPaint() 
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
HCURSOR CVC_SampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CVC_SampleDlg::OnSingleAbsoluteMoveBackward() 
{
	I32 Position = -10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
}

void CVC_SampleDlg::OnSingleAbsoluteMoveForward() 
{
	I32 Position = 10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));	
}

void CVC_SampleDlg::OnSingleAbsoluteMoveStop() 
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForAbsolute ));	
}

void CVC_SampleDlg::OnSingleRelativeMoveBackward() 
{
	I32 Distance = -10000;
	I32 Max_Speed = 50000;	
	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
	
}

void CVC_SampleDlg::OnSingleRelativeMoveForward() 
{
	I32 Distance = 10000;
	I32 Max_Speed = 50000;	
	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));	
}

void CVC_SampleDlg::OnSingleRelativeMoveStop() 
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForRelative ));		
}

void CVC_SampleDlg::OnSingleHomeMoveBackward() 
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));	
}

void CVC_SampleDlg::OnSingleHomeMoveForward() 
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative	
	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));		
}

void CVC_SampleDlg::OnSingleHomeMoveStop() 
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForHome ));		
}

void CVC_SampleDlg::OnLinear2AxesAbsoluteBackward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={-10000,-20000};
 	I32 Max_Linear_Speed=50000; 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));		
}

void CVC_SampleDlg::OnLinear2AxesAbsoluteForward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000; 
 	Function_Result ((APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));			
}

void CVC_SampleDlg::OnLinear2AxesAbsoluteStop() 
{
	Function_Result ((APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0])));	
}

void CVC_SampleDlg::OnLinear2AxesRelateiveBackward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={-10000,-20000};
 	I32 Max_Linear_Speed=50000; 
 	Function_Result ((APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));		
}

void CVC_SampleDlg::OnLinear2AxesRelateiveForward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000; 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));		
}

void CVC_SampleDlg::OnLinear2AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0]));
}

void CVC_SampleDlg::OnLinear3AxesAbsoluteBackward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={-10000,-20000,-30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));			
}

void CVC_SampleDlg::OnLinear3AxesAbsoluteForward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));		
}

void CVC_SampleDlg::OnLinear3AxesAbsoluteStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}

void CVC_SampleDlg::OnLinear3AxesRelateiveBackward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={-10000,-20000,-30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));			
	
}

void CVC_SampleDlg::OnLinear3AxesRelateiveForward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));	
}

void CVC_SampleDlg::OnLinear3AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}

void CVC_SampleDlg::OnLinear4AxesAbsoluteBackward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));			
}

void CVC_SampleDlg::OnLinear4AxesAbsoluteForward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));	
	
}

void CVC_SampleDlg::OnLinear4AxesAbsoluteStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
	
}

void CVC_SampleDlg::OnLinear4AxesRelateiveBackward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));			
	
}

void CVC_SampleDlg::OnLinear4AxesRelateiveForward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));			
	
}

void CVC_SampleDlg::OnLinear4AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));	
}


void CVC_SampleDlg::OnTimer(UINT nIDEvent) 
{
	CString CC;
	I32 Command;
	I32 Position;
	I32 MotionSts;
	I32 IoSts;

	for (int index=0; index<4; index++)
	{
		//Motion Segment
		APS_get_command( Start_Axis_ID + index, &Command );
		SetDlgItemInt(Edit_ShowAxis_Command_0 + index, Command);

		APS_get_position( Start_Axis_ID + index, &Position );
		SetDlgItemInt(Edit_ShowAxis_Feedback_0 + index, Position);

		IoSts=APS_motion_io_status( Start_Axis_ID + index );
		CC.Format("%x",IoSts);
		SetDlgItemText(Edit_ShowAxis_IOSts_0 + index,CC);

		MotionSts=APS_motion_status( Start_Axis_ID + index );
		CC.Format("%x",MotionSts);
		SetDlgItemText(Edit_ShowAxis_MSts_0 + index,CC);
		
	}
	
	CDialog::OnTimer(nIDEvent);
}


void CVC_SampleDlg::OnResetCounter() 
{

	for (int AxisNo = Start_Axis_ID; AxisNo <=(Start_Axis_ID+3); AxisNo++)
	{
		Function_Result (APS_set_command( AxisNo, 0));
		Function_Result (APS_set_position( AxisNo, 0 ));

		if (FunctionFail)
		{
			break;
		}
	}
}

void CVC_SampleDlg::OnArc2AxesAbsoluteCCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	Function_Result(APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}

void CVC_SampleDlg::OnArc2AxesAbsoluteCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=(-180);
	Function_Result(APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
	
}

void CVC_SampleDlg::OnArc2AxesAbsoluteStop2() 
{
	Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));	
	
}

void CVC_SampleDlg::OnArc2AxesRelativeCCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	Function_Result(APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
	
}

void CVC_SampleDlg::OnArc2AxesRelativeCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=(-180);
	Function_Result(APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));	
}

void CVC_SampleDlg::OnArc2AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));	
}





void CVC_SampleDlg::OnButton1() 
{
	
	CardID = GetDlgItemInt(IDC_EDIT1);
    Start_Axis_ID = CardID * 4;

	//--Reset Axis ID----------------------------------------
	AxisID_SingleAxis_ForAbsolute = Start_Axis_ID;
    AxisID_SingleAxis_ForRelative = Start_Axis_ID;
    AxisID_SingleAxis_ForHome = Start_Axis_ID;

    Axis_ID_Array_For_2Axes_Move[0] = Start_Axis_ID;
    Axis_ID_Array_For_2Axes_Move[1] = Start_Axis_ID + 1;
    
    Axis_ID_Array_For_2Axes_ArcMove[0] = Start_Axis_ID;
    Axis_ID_Array_For_2Axes_ArcMove[1] = Start_Axis_ID + 1;

    Axis_ID_Array_For_3Axes_Move[0] = Start_Axis_ID;
    Axis_ID_Array_For_3Axes_Move[1] = Start_Axis_ID + 1;
    Axis_ID_Array_For_3Axes_Move[2] = Start_Axis_ID + 2;
    
    Axis_ID_Array_For_4Axes_Move[0] = Start_Axis_ID;
    Axis_ID_Array_For_4Axes_Move[1] = Start_Axis_ID + 1;
    Axis_ID_Array_For_4Axes_Move[2] = Start_Axis_ID + 2;
    Axis_ID_Array_For_4Axes_Move[3] = Start_Axis_ID + 3;
    
    Axis_ID_Array_For_PointTable[0] = Start_Axis_ID;
    Axis_ID_Array_For_PointTable[1] = Start_Axis_ID + 1;
    Axis_ID_Array_For_PointTable[2] = Start_Axis_ID + 2;
    Axis_ID_Array_For_PointTable[3] = Start_Axis_ID + 3;
	//--------------------------------------------------------
	
}

