// VCNET_SampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "VCNET_Sample.h"
#include "VCNET_SampleDlg.h"
#include "APS168.h"
#include "APS_define.h"
#include "ErrorCodeDef.h"
#include "type_def.h"


#ifdef _DEBUG
#define new DEBUG_NEW
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

void CVCNET_SampleDlg::Function_Result(int Ret)
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


// CVCNET_SampleDlg dialog




CVCNET_SampleDlg::CVCNET_SampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVCNET_SampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVCNET_SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVCNET_SampleDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ResetCounter, &CVCNET_SampleDlg::OnBnClickedResetcounter)
	
	
	ON_BN_CLICKED(SingleAbsoluteMove_Forward, &CVCNET_SampleDlg::OnSingleAbsoluteMoveForward)
	ON_BN_CLICKED(SingleAbsoluteMove_Stop, &CVCNET_SampleDlg::OnSingleAbsoluteMoveStop)
	ON_BN_CLICKED(IDC_SingleRelativeMove_Backward, &CVCNET_SampleDlg::OnBnClickedSinglerelativemoveBackward)
	ON_BN_CLICKED(IDC_SingleRelativeMove_Forward, &CVCNET_SampleDlg::OnBnClickedSinglerelativemoveForward)
	ON_BN_CLICKED(IDC_SingleRelativeMove_Stop, &CVCNET_SampleDlg::OnBnClickedSinglerelativemoveStop)
	ON_BN_CLICKED(IDC_SingleAbsoluteMove_Backward, &CVCNET_SampleDlg::OnBnClickedSingleabsolutemoveBackward)
	ON_BN_CLICKED(IDC_SingleHomeMove_Backward, &CVCNET_SampleDlg::OnBnClickedSinglehomemoveBackward)
	ON_BN_CLICKED(IDC_SingleHomeMove_Forward, &CVCNET_SampleDlg::OnBnClickedSinglehomemoveForward)
	ON_BN_CLICKED(IDC_SingleHomeMove_Stop, &CVCNET_SampleDlg::OnBnClickedSinglehomemoveStop)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_Linear_2Axes_AbsoluteForward, &CVCNET_SampleDlg::OnBnClickedLinear2axesAbsoluteforward)
	ON_BN_CLICKED(IDC_Linear_2Axes_AbsoluteBackward, &CVCNET_SampleDlg::OnBnClickedLinear2axesAbsolutebackward)
	ON_BN_CLICKED(IDC_Linear_2Axes_AbsoluteStop, &CVCNET_SampleDlg::OnBnClickedLinear2axesAbsolutestop)
	ON_BN_CLICKED(IDC_Arc_2Axes_Absolute_CCW, &CVCNET_SampleDlg::OnBnClickedArc2axesAbsoluteCcw)	
	ON_BN_CLICKED(IDC_Arc_2Axes_Absolute_CW, &CVCNET_SampleDlg::OnBnClickedArc2axesAbsoluteCw)
	ON_BN_CLICKED(IDC_Arc_2Axes_Absolute_Stop2, &CVCNET_SampleDlg::OnBnClickedArc2axesAbsoluteStop2)
	ON_BN_CLICKED(IDC_Arc_2Axes_Relative_CCW, &CVCNET_SampleDlg::OnBnClickedArc2axesRelativeCcw)
	ON_BN_CLICKED(IDC_Arc_2Axes_Relative_CW, &CVCNET_SampleDlg::OnBnClickedArc2axesRelativeCw)
	ON_BN_CLICKED(IDC_Arc_2Axes_Relateive_Stop, &CVCNET_SampleDlg::OnBnClickedArc2axesRelateiveStop)
	ON_BN_CLICKED(IDC_Linear_3Axes_AbsoluteBackward, &CVCNET_SampleDlg::OnBnClickedLinear3axesAbsolutebackward)
	ON_BN_CLICKED(IDC_Linear_3Axes_AbsoluteForward, &CVCNET_SampleDlg::OnBnClickedLinear3axesAbsoluteforward)
	ON_BN_CLICKED(IDC_Linear_3Axes_AbsoluteStop, &CVCNET_SampleDlg::OnBnClickedLinear3axesAbsolutestop)
	ON_BN_CLICKED(IDC_Linear_3Axes_RelateiveBackward, &CVCNET_SampleDlg::OnBnClickedLinear3axesRelateivebackward)
	ON_BN_CLICKED(IDC_Linear_3Axes_RelateiveForward, &CVCNET_SampleDlg::OnBnClickedLinear3axesRelateiveforward)
	ON_BN_CLICKED(IDC_Linear_3Axes_Relateive_Stop, &CVCNET_SampleDlg::OnBnClickedLinear3axesRelateiveStop)
	ON_BN_CLICKED(IDC_Linear_4Axes_AbsoluteBackward, &CVCNET_SampleDlg::OnBnClickedLinear4axesAbsolutebackward)
	ON_BN_CLICKED(IDC_Linear_4Axes_AbsoluteForward, &CVCNET_SampleDlg::OnBnClickedLinear4axesAbsoluteforward)
	ON_BN_CLICKED(IDC_Linear_4Axes_AbsoluteStop, &CVCNET_SampleDlg::OnBnClickedLinear4axesAbsolutestop)
	ON_BN_CLICKED(IDC_Linear_4Axes_RelateiveBackward, &CVCNET_SampleDlg::OnBnClickedLinear4axesRelateivebackward)
	ON_BN_CLICKED(IDC_Linear_4Axes_RelateiveForward, &CVCNET_SampleDlg::OnBnClickedLinear4axesRelateiveforward)
	ON_BN_CLICKED(IDC_Linear_4Axes_Relateive_Stop, &CVCNET_SampleDlg::OnBnClickedLinear4axesRelateiveStop)
	ON_BN_CLICKED(IDC_BUTTON1, &CVCNET_SampleDlg::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDC_Linear_2Axes_RelateiveBackward, &CVCNET_SampleDlg::OnBnClickedLinear2axesRelateivebackward)
	
	ON_BN_CLICKED(IDC_Linear_2Axes_RelateiveForward, &CVCNET_SampleDlg::OnBnClickedLinear2axesRelateiveforward)
	ON_BN_CLICKED(IDC_Linear_2Axes_Relateive_Stop, &CVCNET_SampleDlg::OnBnClickedLinear2axesRelateiveStop)
	ON_BN_CLICKED(IDC_PulserEAEBEnble, &CVCNET_SampleDlg::OnBnClickedPulsereaebenble)
	ON_BN_CLICKED(IDC_PulserRelativeMove, &CVCNET_SampleDlg::OnBnClickedPulserrelativemove)
	ON_BN_CLICKED(IDC_PulserVelocityMove, &CVCNET_SampleDlg::OnBnClickedPulservelocitymove)
	ON_BN_CLICKED(IDC_PulserHomeMove, &CVCNET_SampleDlg::OnBnClickedPulserhomemove)
END_MESSAGE_MAP()


// CVCNET_SampleDlg message handlers

BOOL CVCNET_SampleDlg::OnInitDialog()
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
	I32 i,ret;
	I32 card_name = 0;

	TotalCard=0;


	if (APS_initial(&DPAC_ID_Bits, 0)==0)      //Initial Card, CardID is assigned by system.
	{      
		for(i=0;i<=15;i++)                     //Find total card's numbers
		{
			if( DPAC_ID_Bits & (1<<i) )
			{
				ret = APS_get_card_name(i, &card_name);
				if (card_name==DEVICE_NAME_PCI_C154_PLUS)
				{
					TotalCard = TotalCard + 1;
					break;
				}				 
			}
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
          //Function_Result (APS_set_axis_param(AxisNo, 562, 1));        //Set EMG logic (0:Active Low /1:Active High)
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVCNET_SampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVCNET_SampleDlg::OnPaint()
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
HCURSOR CVCNET_SampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVCNET_SampleDlg::OnBnClickedResetcounter()
{
	// TODO: Add your control notification handler code here
	for (int AxisNo = Start_Axis_ID; AxisNo <=(Start_Axis_ID+3); AxisNo++)
	{
		Function_Result (APS_set_command( AxisNo, 0));
		Function_Result (APS_set_position( AxisNo, 0 ));
		Function_Result (APS_emg_stop( AxisNo));
		if (FunctionFail)
		{
			break;
		}
	}
}



void CVCNET_SampleDlg::OnBnClickedSingleabsolutemoveBackward()
{	
	I32 Position = -10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
}

void CVCNET_SampleDlg::OnSingleAbsoluteMoveForward()
{
	I32 Position = 10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
}

void CVCNET_SampleDlg::OnSingleAbsoluteMoveStop()
{	
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForAbsolute ));
}


void CVCNET_SampleDlg::OnBnClickedSinglerelativemoveBackward()
{	
	I32 Distance = -10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
}

void CVCNET_SampleDlg::OnBnClickedSinglerelativemoveForward()
{
	I32 Distance = 10000;
	I32 Max_Speed = 50000;
	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
}

void CVCNET_SampleDlg::OnBnClickedSinglerelativemoveStop()
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForRelative ));
}

void CVCNET_SampleDlg::OnBnClickedSinglehomemoveBackward()
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));
}

void CVCNET_SampleDlg::OnBnClickedSinglehomemoveForward()
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));
}

void CVCNET_SampleDlg::OnBnClickedSinglehomemoveStop()
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForHome ));
}



void CVCNET_SampleDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
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


void CVCNET_SampleDlg::OnBnClickedLinear2axesAbsolutebackward()
{
	I32 Dimension=2;
	I32 Position_Array[2]={-10000,-20000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));
}
void CVCNET_SampleDlg::OnBnClickedLinear2axesAbsoluteforward()
{
	I32 Dimension=2;
	I32 Position_Array[2]={10000,20000};
	I32 Max_Linear_Speed=50000;
	

	Function_Result ((APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));	
}


void CVCNET_SampleDlg::OnBnClickedLinear2axesAbsolutestop()
{
	Function_Result ((APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0])));
}

void CVCNET_SampleDlg::OnBnClickedLinear2axesRelateivebackward()
{
	I32 Dimension=2;
	I32 Position_Array[2]={-10000,-20000};
	I32 Max_Linear_Speed=50000;	
	Function_Result ((APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));	
}



void CVCNET_SampleDlg::OnBnClickedLinear2axesRelateiveforward()
{
	I32 Dimension=2;
	I32 Position_Array[2]={10000,20000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear2axesRelateiveStop()
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0]));
}
void CVCNET_SampleDlg::OnBnClickedArc2axesAbsoluteCcw()
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	Function_Result(APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}

void CVCNET_SampleDlg::OnBnClickedArc2axesAbsoluteCw()
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=(-180);
	
	Function_Result(APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}

void CVCNET_SampleDlg::OnBnClickedArc2axesAbsoluteStop2()
{
		Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));	
}


void CVCNET_SampleDlg::OnBnClickedArc2axesRelativeCcw()
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	Function_Result(APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}

void CVCNET_SampleDlg::OnBnClickedArc2axesRelativeCw()
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=(-180);	
	Function_Result(APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}



void CVCNET_SampleDlg::OnBnClickedArc2axesRelateiveStop()
{
	Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));	
}

void CVCNET_SampleDlg::OnBnClickedLinear3axesAbsolutebackward()
{
	I32 Dimension=3;
	I32 Position_Array[3]={-10000,-20000,-30000};
	I32 Max_Linear_Speed=50000;	
	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear3axesAbsoluteforward()
{
	I32 Dimension=3;
	I32 Position_Array[3]={10000,20000,30000};
	I32 Max_Linear_Speed=50000;	
	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear3axesAbsolutestop()
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}

void CVCNET_SampleDlg::OnBnClickedLinear3axesRelateivebackward()
{
	I32 Dimension=3;
	I32 Position_Array[3]={-10000,-20000,-30000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear3axesRelateiveforward()
{
	I32 Dimension=3;
	I32 Position_Array[3]={10000,20000,30000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear3axesRelateiveStop()
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}

void CVCNET_SampleDlg::OnBnClickedLinear4axesAbsolutebackward()
{
	I32 Dimension=4;
	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear4axesAbsoluteforward()
{
	I32 Dimension=4;
	I32 Position_Array[4]={10000,20000,30000,40000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear4axesAbsolutestop()
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
}

void CVCNET_SampleDlg::OnBnClickedLinear4axesRelateivebackward()
{
	I32 Dimension=4;
	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear4axesRelateiveforward()
{
	I32 Dimension=4;
	I32 Position_Array[4]={10000,20000,30000,40000};
	I32 Max_Linear_Speed=50000;
	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));
}

void CVCNET_SampleDlg::OnBnClickedLinear4axesRelateiveStop()
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
}

void CVCNET_SampleDlg::OnBnClickedButton1()
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
}


void CVCNET_SampleDlg::OnBnClickedPulsereaebenble()
{
	I32 Enable = 0;
	I32 ret = 0;
	Enable = GetDlgItemInt(IDC_PulserEAEB);
	ret = APS_manual_pulser_start( 0, Enable );
}

void CVCNET_SampleDlg::OnBnClickedPulserrelativemove()
{
	I32 MaxVelocityI32 = 0;
	F64 MaxVelocityF64 = 0;
	I32 DistanceI32 = 0;
	F64 DistanceF64 = 0;
	I32 Axis_ID = 0;
	I32 ret = 0;

	Axis_ID = GetDlgItemInt(IDC_PulserRelativeMoveAxis);
	DistanceI32 = GetDlgItemInt(IDC_PulserRelativeMoveDistance);
	DistanceF64 = (F64)DistanceI32;
	MaxVelocityI32 = GetDlgItemInt(IDC_PulserRelativeMoveSpeed);
	MaxVelocityF64 = (F64)MaxVelocityI32;

	Function_Result( APS_manual_pulser_relative_move( Axis_ID, DistanceF64, MaxVelocityF64 ) );
}

void CVCNET_SampleDlg::OnBnClickedPulservelocitymove()
{
	I32 MaxVelocityI32 = 0;
	F64 MaxVelocityF64 = 0;
	I32 Axis_ID = 0;
	I32 ret = 0;

	Axis_ID = GetDlgItemInt(IDC_PulserVelocityMoveAixs);
	MaxVelocityI32 = GetDlgItemInt(IDC_PulserVelocityMoveSpeed);
	MaxVelocityF64 = (F64)MaxVelocityI32;

	Function_Result(APS_manual_pulser_velocity_move( Axis_ID, MaxVelocityF64 ));
}

void CVCNET_SampleDlg::OnBnClickedPulserhomemove()
{
	I32 Axis_ID = 0;

	Axis_ID = GetDlgItemInt(IDC_PulserHomeMoveAxis);
	Function_Result( APS_manual_pulser_home_move( Axis_ID ));	
}
