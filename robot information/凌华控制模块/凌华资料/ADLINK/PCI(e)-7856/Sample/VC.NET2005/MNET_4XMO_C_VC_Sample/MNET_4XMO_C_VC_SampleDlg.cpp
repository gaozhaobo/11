// MNET_4XMO_C_VC_SampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MNET_4XMO_C_VC_Sample.h"
#include "MNET_4XMO_C_VC_SampleDlg.h"
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
//I32 MOD_No =0;		  //Arrcoding switch On Module. 	
I32 MOD_No =7;		  //Arrcoding switch On Module. 	
I32 Start_Axis_ID=0;  //First Axis number in Motion Net bus.
I32 AxisID_SingleAxis_ForAbsolute= 0;
I32 AxisID_SingleAxis_ForRelative= 1;
I32 AxisID_SingleAxis_ForHome= 2;
I32 AxisID_FirstAxis_For_PointTable=0;
I32 Dimension_For_PointTable=4;; 
I32 Axis_ID_Array_For_2Axes_Move[2]={0,1};
I32 Axis_ID_Array_For_2Axes_ArcMove[2]={0,1};
I32 Axis_ID_Array_For_3Axes_Move[3]={0,1,2};
I32 Axis_ID_Array_For_4Axes_Move[4]={0,1,2,3};
I32 Axis_ID_Array_For_PointTable[4]={0,1,2,3};

bool FunctionFail=false;
bool bIsConnected=false;
I32 CurrectSelAxis=0;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

void CMNET_4XMO_C_VC_SampleDlg::Function_Result(int Ret)
{
	//char MsgStr[]="Error Code = ";
	//char Buff[256];
	//itoa(Ret,Buff,10);
	//strcat(MsgStr,Buff);
	if (Ret != 0){
		//MessageBox(MsgStr,NULL,MB_OK);
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
// CMNET_4XMO_C_VC_SampleDlg dialog

CMNET_4XMO_C_VC_SampleDlg::CMNET_4XMO_C_VC_SampleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMNET_4XMO_C_VC_SampleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMNET_4XMO_C_VC_SampleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMNET_4XMO_C_VC_SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMNET_4XMO_C_VC_SampleDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMNET_4XMO_C_VC_SampleDlg, CDialog)
	//{{AFX_MSG_MAP(CMNET_4XMO_C_VC_SampleDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Btn_BusConnect, OnBusConnect)
	ON_BN_CLICKED(Btn_BusDisconnect, OnBusDisconnect)
	ON_BN_CLICKED(Btn_GetModuleInfo, OnGetModuleInfo)
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
	ON_BN_CLICKED(Btn_SetPointTable, OnSetPointTable)
	ON_BN_CLICKED(Btn_PointTable_SingleIndexMove, OnPointTableSingleIndexMove)
	ON_WM_TIMER()
	ON_BN_CLICKED(Btn_ResetCounter, OnResetCounter)
	ON_BN_CLICKED(Btn_PointTable_MoveALL, OnPointTableMoveALL)
	ON_BN_CLICKED(Btn_PointTable_Stop, OnPointTableStop)
	ON_BN_CLICKED(Btn_Linear_Compare, OnLinearCompare)
	ON_BN_CLICKED(Btn_Trigger_Count, OnTriggerCount)
	ON_BN_CLICKED(Btn_Table_Compare, OnTableCompare)
	ON_BN_CLICKED(Btn_Manual_Compare, OnManualCompare)
	ON_BN_CLICKED(Btn_Arc_2Axes_Absolute_CCW, OnArc2AxesAbsoluteCCW)
	ON_BN_CLICKED(Btn_Arc_2Axes_Absolute_CW, OnArc2AxesAbsoluteCW)
	ON_BN_CLICKED(Btn_Arc_2Axes_Absolute_Stop2, OnArc2AxesAbsoluteStop2)
	ON_BN_CLICKED(Btn_Arc_2Axes_Relateive_Stop, OnArc2AxesRelateiveStop)
	ON_BN_CLICKED(Btn_Arc_2Axes_Relative_CCW, OnArc2AxesRelativeCCW)
	ON_BN_CLICKED(Btn_Arc_2Axes_Relative_CW, OnArc2AxesRelativeCW)
	ON_BN_CLICKED(Btn_Set_DOData, OnSetDOData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMNET_4XMO_C_VC_SampleDlg message handlers

BOOL CMNET_4XMO_C_VC_SampleDlg::OnInitDialog()
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
	
	//Initial++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	I32 DPAC_ID_Bits;
	I32 Info;
	if (APS_initial(&DPAC_ID_Bits, 0)==0){      //Initial Card, CardID is assigned by system.
		//Get Card information
		APS_get_device_info( CardID, 0x10, &Info );		//Get Driver Version
		SetDlgItemInt(Edit_ShowMaster_DriverVer, Info);

		SetDlgItemInt(Edit_ShowMaster_DLLVer, APS_version());  //Get DLL Version

		APS_get_device_info( CardID, 0x20, &Info );		//Get CPLD Version
		SetDlgItemInt(Edit_ShowMaster_CPLDVer, Info);	
		
		APS_get_device_info( CardID, 0x30, &Info );		//Get PCB Version
		CC.Format ("%x", Info);
		SetDlgItemText(Edit_ShowMaster_PCBVer, CC);

		//Set Motion Net Parameter
		Function_Result (APS_set_field_bus_param (CardID, BusNo, PRF_TRANSFER_RATE, 3));     //Set PRF_TRANSFER_RATE: 3 (12M)
		
		SetTimer(0,50,NULL);
	}else{
		MessageBox("Initial Fail, sample close!!",NULL,64);
	}
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	//Dialog conponment initial++++++++++++++++++++++++++++++++++++++++++++++++
	SetDlgItemInt(Edit_SetModuleID_ForModuleInfo,0);
	SetDlgItemInt(Edit_SetTargetIndex_ForSinglePointMove,10);
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

void CMNET_4XMO_C_VC_SampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMNET_4XMO_C_VC_SampleDlg::OnPaint() 
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
HCURSOR CMNET_4XMO_C_VC_SampleDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMNET_4XMO_C_VC_SampleDlg::OnBusConnect() 
{
	Function_Result (APS_start_field_bus(CardID, BusNo, Start_Axis_ID));   	

	if (!FunctionFail){
		//Set Axis Parameter
		for (int AxisNo=Start_Axis_ID; AxisNo<4 ; AxisNo++){
			//IO and Pulse Mode
			Function_Result (APS_set_axis_param(AxisNo, PRA_ALM_LOGIC, 0));       //Set PRA_ALM_LOGIC
			Function_Result (APS_set_axis_param(AxisNo, PRA_PLS_IPT_MODE, 2));    //Set PRA_PLS_IPT_MODE
			Function_Result (APS_set_axis_param(AxisNo, PRA_PLS_OPT_MODE, 1));    //Set PRA_PLS_OPT_MODE
			Function_Result (APS_set_axis_param(AxisNo, PRA_PLS_IPT_LOGIC, 1));   //Set PRA_PLS_IPT_LOGIC
			Function_Result (APS_set_axis_param(AxisNo, PRA_FEEDBACK_SRC, 1));   //Select feedback conter
								
	
			//Single Move Parameter
			Function_Result (APS_set_axis_param(AxisNo, PRA_CURVE, 0));			  //Set PRA_CURVE  0:T-Curve 1:S-Curve
			Function_Result (APS_set_axis_param(AxisNo, PRA_ACC, 10000000));		  //Set PRA_ACC 
			Function_Result (APS_set_axis_param(AxisNo, PRA_DEC, 10000000));		  //Set PRA_DEC
			Function_Result (APS_set_axis_param(AxisNo, PRA_VS, 0));			  //Set PRA_VS

	
			//Home Move Parameter
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_MODE, 0));		  //Set PRA_HOME_MODE
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_VM, 10000));	  //Set PRA_HOME_VM
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_EZA, 0));		  //Set PRA_HOME_EZA 
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_VO, 100));		  //Set PRA_HOME_VO
			Function_Result (APS_set_axis_param(AxisNo, PRA_HOME_OFFSET, 500));	  //Set PRA_HOME_OFFSET 
		}

		MessageBox("Bus Connected!!");
			
	}else{
		MessageBox( "Connect Fail!!" ,NULL, 64);
	}
}

void CMNET_4XMO_C_VC_SampleDlg::OnBusDisconnect() 
{
	Function_Result (APS_stop_field_bus(CardID, BusNo));
}

void CMNET_4XMO_C_VC_SampleDlg::OnGetModuleInfo() 
{
	I32 Info;
	Function_Result (APS_get_field_bus_device_info( CardID,		//Get FPGA Version
												 BusNo, 
												 GetDlgItemInt(Edit_SetModuleID_ForModuleInfo),
												 0x21, 
												 &Info ));
	SetDlgItemInt(Edit_ShowModule_FPGAVer,Info);

	Function_Result (APS_get_field_bus_device_info( CardID,		//Get PCB Top Version
												 BusNo, 
												 GetDlgItemInt(Edit_SetModuleID_ForModuleInfo),
												 0x30, 
												 &Info ));

	SetDlgItemInt(Edit_ShowModule_PCBTopVer,Info);

	Function_Result (APS_get_field_bus_device_info( CardID,		//Get PCB Bottom Version
												 BusNo, 
												 GetDlgItemInt(Edit_SetModuleID_ForModuleInfo),
												 0x31, 
												 &Info ));
	SetDlgItemInt(Edit_ShowMaster_PCBBottomVer,Info);
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleAbsoluteMoveBackward() 
{
	I32 Position = -10000;
	I32 Max_Speed = 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleAbsoluteMoveForward() 
{
	I32 Position = 10000;
	I32 Max_Speed = 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result ((APS_absolute_move( AxisID_SingleAxis_ForAbsolute, Position, Max_Speed )));	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleAbsoluteMoveStop() 
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForAbsolute ));	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleRelativeMoveBackward() 
{
	I32 Distance = -10000;
	I32 Max_Speed = 50000;
	//Others setting like ACC,Dec... are  in the initial segmant.

	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleRelativeMoveForward() 
{
	I32 Distance = 10000;
	I32 Max_Speed = 50000;
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result ((APS_relative_move( AxisID_SingleAxis_ForRelative, Distance, Max_Speed )));	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleRelativeMoveStop() 
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForRelative ));		
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleHomeMoveBackward() 
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleHomeMoveForward() 
{
	Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0));		  //Set PRA_HOME_DIR   0:Positive 1:Negative
	//Others setting like ACC,Dec... are in the initial segmant.

	Function_Result (APS_home_move( AxisID_SingleAxis_ForHome ));		
}

void CMNET_4XMO_C_VC_SampleDlg::OnSingleHomeMoveStop() 
{
	Function_Result (APS_emg_stop( AxisID_SingleAxis_ForHome ));		
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear2AxesAbsoluteBackward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={-10000,-20000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));		
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear2AxesAbsoluteForward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result ((APS_absolute_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));			
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear2AxesAbsoluteStop() 
{
	Function_Result ((APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0])));	
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear2AxesRelateiveBackward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={-10000,-20000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result ((APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed )));		
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear2AxesRelateiveForward() 
{
	I32 Dimension=2;
 	I32 Position_Array[2]={10000,20000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed ));		
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear2AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_2Axes_Move[0]));
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear3AxesAbsoluteBackward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={-10000,-20000,-30000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));			
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear3AxesAbsoluteForward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));		
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear3AxesAbsoluteStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear3AxesRelateiveBackward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={-10000,-20000,-30000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));			
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear3AxesRelateiveForward() 
{
	I32 Dimension=3;
 	I32 Position_Array[3]={10000,20000,30000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_3Axes_Move, Position_Array, Max_Linear_Speed ));	
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear3AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_3Axes_Move[0]));
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear4AxesAbsoluteBackward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));			
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear4AxesAbsoluteForward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_absolute_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));	
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear4AxesAbsoluteStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear4AxesRelateiveBackward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={-10000,-20000,-30000,-40000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));			
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear4AxesRelateiveForward() 
{
	I32 Dimension=4;
 	I32 Position_Array[4]={10000,20000,30000,40000};
 	I32 Max_Linear_Speed=50000;
 	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
 
 	Function_Result (APS_relative_linear_move( Dimension, Axis_ID_Array_For_4Axes_Move, Position_Array, Max_Linear_Speed ));			
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnLinear4AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_4Axes_Move[0]));
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSetPointTable() 
{
	I32 Index=0;
	I32 LastIndex=20;
	POINT_DATA2 PointData;

	Function_Result (APS_set_point_table_mode2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 0 ));	//0:Single 1:continue

	for (Index =0; Index < LastIndex; Index++){
		for (int AxisNo=0; AxisNo<4 ; AxisNo++){
				PointData.i32_pos[AxisNo]= (Index+1) * 1000;	//Position data = Index * 10000;
		}

		if (Index==0){				//If Index be first or last index, initSpeed be 0.
			PointData.i32_initSpeed=0;						// Start velocity	( pulse / s ) 
			PointData.i32_maxSpeed=50000;					// Maximum velocity  ( pulse / s ) 	
			PointData.i32_angle=0;
		}else{												//Others index iniSpeed and maxSpeed are the same.
			PointData.i32_initSpeed=PointData.i32_maxSpeed;	// Start velocity	( pulse / s ) 
			PointData.i32_maxSpeed=50000;				    // Maximum velocity  ( pulse / s ) 
		}

		if (Index==(LastIndex-1)){
				PointData.i32_opt=0x21; // Option //0xABCD , D:0 absolute, 1:relative
		}else{
				PointData.i32_opt=0x1; // Option //0xABCD , D:0 absolute, 1:relative
		}
		
		Function_Result (APS_set_point_table2( Dimension_For_PointTable, 
											   Axis_ID_Array_For_PointTable, 
											   Index, 
											   &PointData ));	
		if (FunctionFail){
			break;
		}

	}

}

void CMNET_4XMO_C_VC_SampleDlg::OnPointTableSingleIndexMove() 
{
	Function_Result (APS_point_table_single_move2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], GetDlgItemInt(Edit_SetTargetIndex_ForSinglePointMove) ));	
}

void CMNET_4XMO_C_VC_SampleDlg::OnTimer(UINT_PTR nIDEvent) 
{
	CString CC;
	I32 Command;
	I32 Position;
	I32 MotionSts;
	I32 IoSts;
	I32 TrgCnt;
	I32 CmpVal;
	I32 EncCnt;
	I32 RunningPoin;
	I32 DI_Value,DOData;

	for (int index=0; index<4; index++){
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

		APS_get_running_point_index2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], &RunningPoin );
		SetDlgItemInt(Edit_Show_PointTable_CurrIndex , RunningPoin);
	
		//Compare Segment
	    APS_get_field_bus_trigger_count( CardID, BusNo, MOD_No, index, &TrgCnt );
		SetDlgItemInt(Edit_ShowTriggerCount_0 + index, TrgCnt);

		APS_get_field_bus_encoder( CardID, BusNo, MOD_No, index, &EncCnt );
		SetDlgItemInt(Edit_ShowTriggerEnc_0 + index, EncCnt);

		APS_get_field_bus_trigger_linear_cmp( CardID, BusNo, MOD_No, index, &CmpVal );
		SetDlgItemInt(Edit_ShowTrigger_LinearCMP_LinearCMP_0 + index, CmpVal);

		//General DIO
		APS_get_field_bus_d_input( CardID, BusNo, GetDlgItemInt(Edit_SetModuleID_ForGeneralDIO), &DI_Value );
		CC.Format("%x",DI_Value);
		SetDlgItemText(Edit_ShowDIData,CC);

		APS_get_field_bus_d_output(  CardID, BusNo, GetDlgItemInt(Edit_SetModuleID_ForGeneralDIO), &DOData   );
		CC.Format("%x",DOData);
		SetDlgItemText(Edit_GetDOData,CC);
	}


	
	CDialog::OnTimer(nIDEvent);
}

void CMNET_4XMO_C_VC_SampleDlg::OnResetCounter() 
{
	I32 LastIndex=4;
	for (int AxisNo = Start_Axis_ID; AxisNo <LastIndex; AxisNo++){
		Function_Result (APS_set_command( AxisNo, 0));
		Function_Result (APS_set_position( AxisNo, 0 ));
		if (FunctionFail){
			break;
		}
	}
}

void CMNET_4XMO_C_VC_SampleDlg::OnPointTableMoveALL() 
{
	I32 Index=0;
	I32 LastIndex=20;
	POINT_DATA2 PointData;

	Function_Result (APS_set_point_table_mode2( Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable], 1 ));	//0:Single 1:continue

	for (Index =0; Index < LastIndex; Index++){
		for (int AxisNo=0; AxisNo<4 ; AxisNo++){
				PointData.i32_pos[AxisNo]= (Index+1) * 2000;	//Position data = Index * 10000;
		}

		if (Index==0){				//If Index be first or last index, initSpeed be 0.
			PointData.i32_initSpeed=0;						// Start velocity	( pulse / s ) 
			PointData.i32_maxSpeed=50000;					// Maximum velocity  ( pulse / s ) 	
			PointData.i32_angle=0;
		}else{												//Others index iniSpeed and maxSpeed are the same.
			PointData.i32_initSpeed=PointData.i32_maxSpeed;	// Start velocity	( pulse / s ) 
			PointData.i32_maxSpeed=50000;				    // Maximum velocity  ( pulse / s ) 
		}

		if (Index==(LastIndex-1)){
				PointData.i32_opt=0x21; // Option //0xABCD , D:0 absolute, 1:relative
		}else{
				PointData.i32_opt=0x1; // Option //0xABCD , D:0 absolute, 1:relative
		}

		PointData.u32_dwell=0;								// Dwell times       ( unit: ms ) 
	
		//In Continue mode, absolute is useless. 
		
		Function_Result (APS_set_point_table2( Dimension_For_PointTable, 
											   Axis_ID_Array_For_PointTable, 
											   Index, 
											   &PointData ));	
		if (FunctionFail){
			break;
		}

	}

	Function_Result (APS_point_table_continuous_move2( Dimension_For_PointTable, Axis_ID_Array_For_PointTable ));
}

void CMNET_4XMO_C_VC_SampleDlg::OnPointTableStop() 
{
	Function_Result (APS_emg_stop(Axis_ID_Array_For_PointTable[AxisID_FirstAxis_For_PointTable]));
	
}


void CMNET_4XMO_C_VC_SampleDlg::OnLinearCompare() 
{
	I32 StartPoint=5000;
	I32 RepeatTimes=100;
	I32 Interval=100;
	I32 LastIndex=4;
	
	for (int Index=0; Index<LastIndex ;Index++){
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_SRC  +  Index,  0 ));		//Compare source is from command counter.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_TYPE +  Index,  1 ));		//Compare type is Linear.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_TRG0_PWD  +  Index , 5 ));		//Trigger Width is 60nS
		Function_Result (APS_set_field_bus_trigger_linear( CardID, BusNo, MOD_No, Index, StartPoint, RepeatTimes, Interval ));   //Set Linear Data
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_EN   +  Index , 1 ));		//Enable Linear compare
		if (FunctionFail){
			break;
		}

	}

	OnTriggerCount() ;		//Reset Trigger Counter, it's not nerssery.
	OnResetCounter() ;		//Reset Axis Counter Counter, it's not nerssery.
	OnLinear4AxesRelateiveForward() ;

}

void CMNET_4XMO_C_VC_SampleDlg::OnTriggerCount() 
{
	I32 LastIndex=4;
	for (int TrgCh=0; TrgCh<LastIndex ;TrgCh++){
		Function_Result (APS_reset_field_bus_trigger_count( CardID, BusNo, MOD_No, TrgCh ));
		if (FunctionFail){
			break;
		}
	}
}

void CMNET_4XMO_C_VC_SampleDlg::OnTableCompare() 
{
	I32 ArraySize = 100;
	I32 *DataArray = new I32 [ArraySize];
	I32 LastIndex=4;

	for (int Index=0; Index<LastIndex ;Index++){
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_SRC  +  Index,  0 ));		//Compare source is from command counter.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_CMP0_TYPE +  Index,  0 ));		//Compare type is Table.
		Function_Result (APS_set_field_bus_trigger_param(  CardID, BusNo, MOD_No, TG_TRG0_PWD  +  Index , 5 ));		//Trigger Width is 60nS

		for (int TableIndex=0; TableIndex<100; TableIndex++){														//Create Table Data
			DataArray[TableIndex] = 5000 + (TableIndex * 100);
		}

		Function_Result (APS_set_field_bus_trigger_table( CardID, BusNo, MOD_No, Index, DataArray, ArraySize));		//Set Table Data
		Function_Result (APS_set_field_bus_trigger_param( CardID, BusNo, MOD_No, TG_CMP0_EN   +  Index ,  1 ));		//Enable Linear compare
		if (FunctionFail){
			break;
		}
	}

	delete DataArray;

	OnTriggerCount() ;		//Reset Trigger Counter, it's not nerssery.
	OnResetCounter() ;		//Reset Axis Counter Counter, it's not nerssery.
	OnLinear4AxesRelateiveForward() ;	
}

void CMNET_4XMO_C_VC_SampleDlg::OnManualCompare() 
{
	I32 LastIndex=4;
	for (int TrgCh=0; TrgCh<LastIndex ;TrgCh++){
		Function_Result (APS_set_field_bus_trigger_manual( CardID, BusNo, MOD_No, TrgCh ));
		if (FunctionFail){
			break;
		}
	}
	
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnArc2AxesAbsoluteCCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={-20000,-20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result(APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
}

void CMNET_4XMO_C_VC_SampleDlg::OnArc2AxesAbsoluteCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result(APS_absolute_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnArc2AxesAbsoluteStop2() 
{
	Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));	
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnArc2AxesRelativeCCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={-20000,-20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result(APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnArc2AxesRelativeCW() 
{
	I32 Dimension=2;
	I32 Center_Pos_Array[2]={20000,20000};
	I32 Max_Arc_Speed=50000; 
	I32 Angle=180;
	//Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

	Function_Result(APS_relative_arc_move( Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array,  Max_Arc_Speed,  Angle ));
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnArc2AxesRelateiveStop() 
{
	Function_Result (APS_emg_stop( Axis_ID_Array_For_2Axes_ArcMove[0] ));	
	
}

void CMNET_4XMO_C_VC_SampleDlg::OnSetDOData() 
{
	Function_Result (APS_set_field_bus_d_output(  CardID, 
												  BusNo, 
												  GetDlgItemInt(Edit_SetModuleID_ForGeneralDIO), 
											      GetDlgItemInt(Edit_SetDOData)  ));
}


