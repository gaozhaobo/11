// SERVODlg.cpp : implementation file
//

#include "stdafx.h"
#include "SERVO.h"
#include "SERVODlg.h"
//#include "pci_8102.h"
#include "APS168.h"
#include "APS_Define.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#define TotalAxis 32

I32 pos[TotalAxis];
I16 bstop=0,ISR_ON=0;
I32 int_counter[TotalAxis]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
I16 AxisNo=0;
//HANDLE hEvent[TotalAxis];
CWinThread *pThread[TotalAxis];

//I16 CardNo ;
//I16 AxisNo ;
I32 TotalCard ;

I16 CardID = 0;
I16 Card_Pci_8102_Status[16];
I16 Now_Max_Card_Pci_8102=0;
I16 ALL_Max_PCI_8102_Card=16;

I16 intTemp;
U16 uintTemp;
I32 lngTemp;
F64 dblTemp;
CString strTemp;
I32 Int_No[TotalAxis];


UINT IntThreadProc( LPVOID lpParam )
{
	int n;
	I16 Rtn_Msg;

	n=(int)lpParam;

	while( ISR_ON )
	{

		//WaitForSingleObject(hEvent[n],INFINITE);
		
		//_8102_wait_motion_interrupt(0, 0, INFINITE );
		Rtn_Msg = APS_wait_single_int( Int_No[n], INFINITE );

		int_counter[n]++;

		//ResetEvent(hEvent[n]);
		APS_reset_int( Int_No[n] );
		Sleep(0);
	}
	
	return TRUE;
}

void DoEvents(void)
{
	MSG message;

	while( :: PeekMessage(&message,NULL,0,0,PM_REMOVE) )
	{
		::TranslateMessage(&message);
		::DispatchMessage(&message);
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
// CSERVODlg dialog

CSERVODlg::CSERVODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSERVODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSERVODlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSERVODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSERVODlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSERVODlg, CDialog)
	//{{AFX_MSG_MAP(CSERVODlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SVON, OnSvon)
	ON_BN_CLICKED(IDC_SVOFF, OnSvoff)
	ON_BN_CLICKED(IDC_PRMOVE, OnPrmove)
	ON_BN_CLICKED(IDC_MRMOVE, OnMrmove)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_HOME, OnHome)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_CUT, OnCut)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CSERVODlg::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSERVODlg message handlers

BOOL CSERVODlg::OnInitDialog()
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
	
	//I16 TotalCard,Err;
    I16 Err;
	CString SErr;

	I16 i,j ;
	//I32 CardID_InBit;				
	I32 RET=0;

	TotalCard = 0;
	//_8102_initial(&TotalCard, 0);
	RET = APS_initial(&TotalCard, 0);     			// Initial PCI-8102 card

        //TotalCard = CARDS_Status(TotalCard, MAX_CARDS_PCI_8102, &CARDS_PCI_8102_Status[16]);

	for (i = 0; i < ALL_Max_PCI_8102_Card; i++)     // Check how many card on PC
	{
		if (TotalCard & (1<<i))
		{

			I32 StartAxisID = 0;
			I32 TotalAxisNum = 0;

			//TotalCard = TotalCard+1;
			Card_Pci_8102_Status[i] = true;
			Now_Max_Card_Pci_8102 = i+1;
			CardID = i;

        //****************************************************************************************************************************
         
         
            APS_get_first_axisId(i, &StartAxisID, &TotalAxisNum);
         
         	for (j = StartAxisID;j<= (StartAxisID + TotalAxisNum - 1);j++)
			{

       
				APS_set_servo_on(j, 1);                  //servo ON
            
				APS_set_axis_param(j, 0, 0);             //PEL/MEL input logic
				APS_set_axis_param(j, 4, 0);             //Set PRA_ALM_LOGIC
				APS_set_axis_param(j, 128, 3);           //Set PRA_PLS_IPT_MODE
				APS_set_axis_param(j, 129, 5);           //Set PRA_PLS_OPT_MODE

				APS_set_axis_param(j, 513, 1);           //Set PRA_FEEDBACK_SRC
                        
				//Set Single Move Parameter
				APS_set_axis_param(j, 33, 1000000);      //Set Acceleration rate
				APS_set_axis_param(j, 34, 1000000);      //Set Deceleration rate
				APS_set_axis_param(j, 35, 0);            //Set Start velocity
				APS_set_axis_param(j, 32, 1);            //Set S-Curve
            
            
				//Set Home Move Parameter
				APS_set_axis_param(j, 16, 0);             //Set Home mode (Home search 1st mode)
           
				APS_set_axis_param(j, 21, 10000);         //Set Homing maximum Velocity (Unit:pulse/sec)
            
				APS_set_axis_param(j, 25, 152);           //Set Homing leave home Velocity (Unit:pulse/sec)
            
				APS_set_axis_param(j, 24, 0);             //Set Specify the EZ count up Value
            
				APS_set_axis_param(j, 26, 100);           //Set Homing leave home distance.Specify ORG Offset (Unit:pulse)
          
            
				//Set EMG logic
				APS_set_axis_param(j, 561, 5);  //Set EMG input
				APS_set_axis_param(j, 562, 0);  //Set EMG logic (0: Active high / 1: Active-Low)
                  
                APS_set_position(j, 0);
                APS_set_command(j, 0);

			}
        
        //*******************************************************************************************************************************


		}
		else
			Card_Pci_8102_Status[i] = false;
	}


    if (TotalCard == 0)
	{
        AfxMessageBox("No PCI-8102 Found!");
			
	    //MsgBox("No PCI-8102 Found!")
        //_8102_close();
		APS_close();
        //End;
    }

    //CardNo = 0;




	//char SysDir[1024];
	//CString FullPath;
	//CString ConfigFile="\\8102.ini";
	//GetWindowsDirectory(SysDir,1024);
	//FullPath=SysDir;
	//FullPath+=ConfigFile;

	//// Get The INI file from Motion Creator
	//Err=_8102_config_from_file();
	//if( Err )
	//{
	//	SErr.Format("8102.ini file not found!");
	//	AfxMessageBox(SErr);
	//}


	//_8102_set_motion_int_factor(0, 1 );

	//_8102_int_enable(0,hEvent);
	//_8102_int_control(0,1);

	ISR_ON=1;

	U16 test1 ;
	U16 test2 ;
		

	for (i = 0;i<= 15;i++)
	{
        test1=1;
	    test1=test1 << i;
		test2=TotalCard & test1;
			
		if (test2!=0)
		{
               
			pThread[(2 * i)]=AfxBeginThread(IntThreadProc,(LPVOID)(2 * i),THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
			ASSERT( pThread[(2 * i)] );
			pThread[(2 * i)]->m_bAutoDelete=FALSE;
			pThread[(2 * i)]->ResumeThread();

			Int_No[(2 * i)] = APS_set_int_factor(0, (2*(2 * i))+1, 0, 1);
		
			APS_reset_int( Int_No[(2 * i)] );
			int_counter[(2 * i)]=0;

			//B_8102_set_continuous_move(AxisNo, 1)
			APS_set_axis_param((2 * i), 0x250, 1); //PRA_CONTI_MODE

			pThread[(2 * i)+1]=AfxBeginThread(IntThreadProc,(LPVOID)((2 * i)+1),THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
			ASSERT( pThread[(2 * i)+1] );
			pThread[(2 * i)+1]->m_bAutoDelete=FALSE;
			pThread[(2 * i)+1]->ResumeThread();

			Int_No[(2 * i)+1] = APS_set_int_factor(0, (2*((2 * i)+1))+1, 0, 1);

			APS_reset_int( Int_No[(2 * i)+1] );
			int_counter[(2 * i)+1]=0;

			//B_8102_set_continuous_move(AxisNo, 1)
			APS_set_axis_param((2 * i)+1, 0x250, 1); //PRA_CONTI_MODE
      	
			APS_int_enable(i, 1);
		}
	}


	//Int_No = APS_set_int_factor(0, 1, 0, 1);
	//APS_int_enable(0, 1);

	SetTimer(1,200,NULL);

	CComboBox *pCombo;
	pCombo=(CComboBox *)GetDlgItem(IDC_COMBO1);

	pCombo->SetCurSel(0);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSERVODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSERVODlg::OnPaint() 
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
HCURSOR CSERVODlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CSERVODlg::OnSvon() 
{
	//_8102_set_servo(AxisNo,0);	
	APS_set_servo_on(AxisNo,1);	
}

void CSERVODlg::OnSvoff() 
{
	//_8102_set_servo(AxisNo,1);	
	APS_set_servo_on(AxisNo,0);	
}

void CSERVODlg::OnPrmove() 
{
	//_8102_start_tr_move(AxisNo,1000000,1000,500000,0.1,0.2);

	APS_set_axis_param( AxisNo, PRA_VS, 10 );
	APS_set_axis_param( AxisNo, PRA_ACC, 50000 );
	APS_set_axis_param( AxisNo, PRA_DEC, 10000000 );

	APS_relative_move( AxisNo, 100000, 50000 );


	APS_set_axis_param( AxisNo, PRA_VS, 500 );
	APS_set_axis_param( AxisNo, PRA_ACC, 50000 );
	APS_set_axis_param( AxisNo, PRA_DEC, 50000 );

	APS_relative_move( AxisNo, 200000, 100000 );
	

	APS_set_axis_param( AxisNo, PRA_VS, 10 );
	APS_set_axis_param( AxisNo, PRA_ACC, 10000000 );
	APS_set_axis_param( AxisNo, PRA_DEC, 50000 );

	APS_relative_move( AxisNo, 150000, 50000 );

}

void CSERVODlg::OnMrmove() 
{
	//_8102_start_tr_move(AxisNo,-1000000,1000,500000,0.1,0.2);

	APS_set_axis_param( AxisNo, PRA_VS, 10 );
	APS_set_axis_param( AxisNo, PRA_ACC, 50000 );
	APS_set_axis_param( AxisNo, PRA_DEC, 10000000 );

	APS_relative_move( AxisNo, -100000, 50000 );


	APS_set_axis_param( AxisNo, PRA_VS, 500 );
	APS_set_axis_param( AxisNo, PRA_ACC, 50000 );
	APS_set_axis_param( AxisNo, PRA_DEC, 50000 );

	APS_relative_move( AxisNo, -200000, 100000 );
	

	APS_set_axis_param( AxisNo, PRA_VS, 10 );
	APS_set_axis_param( AxisNo, PRA_ACC, 10000000 );
	APS_set_axis_param( AxisNo, PRA_DEC, 50000 );

	APS_relative_move( AxisNo, -150000, 50000 );
}

void CSERVODlg::OnTimer(UINT_PTR nIDEvent) 
{
		
	I32 io_sts;
	I32 m_sts;
	I32 Contibuf=0;
	char string[64];

	//_8102_get_position(AxisNo,&pos[AxisNo]);
	//_8102_get_io_status(AxisNo,&io_sts);
	//m_sts=_8102_motion_done(AxisNo);

	io_sts = APS_motion_io_status(AxisNo);

	m_sts = APS_motion_status(AxisNo);

	APS_get_position(AxisNo, &pos[AxisNo]);

	APS_get_axis_param( AxisNo, 0x251, &Contibuf );// Continuous Buffer


	SetDlgItemInt(IDC_INT,int_counter[AxisNo]);
	SetDlgItemInt(IDC_POS,(int)pos[AxisNo]);
	sprintf(string,"0x%x(0x%x)",io_sts,Contibuf);
	SetDlgItemText(IDC_IOSTS,string);
	SetDlgItemInt(IDC_MSTS,m_sts);

	CDialog::OnTimer(nIDEvent);
}

void CSERVODlg::OnOK() 
{

	ISR_ON=0;


	U16 test1 ;
	U16 test2 ;
		

	for (int i = 0;i<= 15;i++)
	{
        test1=1;
	    test1=test1 << i;
		test2=TotalCard & test1;
			
		if (test2!=0)
		{
               
			//SetEvent(hEvent[(2*i)]);
			//WaitForSingleObject(pThread[(2*i)]->m_hThread,INFINITE);
			delete pThread[(2*i)];
			
			//_8102_set_servo(AxisNo,1);
			APS_set_servo_on((2*i),0);	

			//B_8102_set_continuous_move(AxisNo, 1)
			APS_set_axis_param((2 * i), 0x250, 0); //PRA_CONTI_MODE


			//SetEvent(hEvent[(2*i)+1]);
			//WaitForSingleObject(pThread[(2*i)+1]->m_hThread,INFINITE);
			delete pThread[(2*i)+1];

			//_8102_set_servo(AxisNo,1);
			APS_set_servo_on((2*i)+1,0);	

			//B_8102_set_continuous_move(AxisNo, 1)
			APS_set_axis_param((2 * i)+1, 0x250, 0); //PRA_CONTI_MODE

		}      
		APS_int_enable(i, 0);
	}
	
	//_8102_close();
	APS_close();

	CDialog::OnOK();
}

void CSERVODlg::OnHome() 
{
/*
#define PRA_HOME_DIR        (0x11)  // homing direction
#define PRA_HOME_CURVE      (0x12)  // homing curve parten(T or s curve)
#define PRA_HOME_ACC        (0x13)  // Acceleration deceleration rate
#define PRA_HOME_VS         (0x14)  // homing start velocity
#define PRA_HOME_VM         (0x15)  // homing max velocity
#define PRA_HOME_VA         (0x16)  // homing approach velocity [PCI-8253/56 only]
#define PRA_HOME_EZA        (0x18)  // EZ alignment enable
#define PRA_HOME_VO         (0x19)  // Homing leave ORG velocity
*/

	//_8102_home_move(AxisNo,-1000,-5000,0.2);

    APS_set_axis_param(AxisNo, PRA_HOME_DIR, 0);   //Set Home Move Positive Direction
    APS_set_axis_param(AxisNo, PRA_HOME_VS,  1000);   
    APS_set_axis_param(AxisNo, PRA_HOME_VM,  5000);   
    APS_set_axis_param(AxisNo, PRA_HOME_ACC, 0.2);   
       
    APS_home_move(AxisNo);
}

void CSERVODlg::OnStop() 
{
	//_8102_sd_stop(AxisNo,0.1);	
	
	APS_set_axis_param( AxisNo, PRA_DEC, 0.1 );

	APS_stop_move(AxisNo);
	bstop=1;
}

void CSERVODlg::OnCut() 
{
	int flag=0;

	bstop=0;
	for(int i=0;i<1;i++)						// Loop counts
	{
		flag=1;
		//_8102_start_tr_move(AxisNo,100000,0,80000,0.01,0.01);	// Forward motion

		APS_set_axis_param( AxisNo, PRA_VS, 0 );
		APS_set_axis_param( AxisNo, PRA_ACC, 50000 );
		APS_set_axis_param( AxisNo, PRA_DEC, 50000 );

		APS_relative_move( AxisNo, 100000, 80000 );

		while( (APS_motion_status(AxisNo) & 0x1) != 0x1 )				// Wait for done
		{
			if( pos[AxisNo] > 60000 && flag==1 )		// If moves to
			{									//   60000 counts
			  //_8102_v_change(AxisNo,10000,0.1);			// Change speed
			  flag=0;
			}
			DoEvents();							// Deal other
		}										//   process

		if( bstop ) break;						// Break when
												//   stop command
		//_8102_start_tr_move(AxisNo,-100000,0,80000,0.01,0.01);   // Reverse motion

		APS_set_axis_param( AxisNo, PRA_VS, 0 );
		APS_set_axis_param( AxisNo, PRA_ACC, 50000 );
		APS_set_axis_param( AxisNo, PRA_DEC, 50000 );

		APS_relative_move( AxisNo, -100000, 80000 );

		while( (APS_motion_status(AxisNo) & 0x1) != 0x1 )				// Wait for done
			DoEvents();

		if( bstop ) break;
		
	}
	bstop=0;
}


void CSERVODlg::OnSelchangeCombo1() 
{
	
	AxisNo=GetDlgItemInt(IDC_COMBO1);

	//Int_No = APS_set_int_factor(0, AxisNo*2+1, 0, 1);


}


void CSERVODlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	OnOK();
}
