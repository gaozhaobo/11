// 8102_Sync_Function_cDlg.cpp : implementation file
//

#include "stdafx.h"
#include "8102_Sync_Function_c.h"
#include "8102_Sync_Function_cDlg.h"
//#include "pci_8102.h"
#include "APS168.h"
#include "APS_Define.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


	I32 CardNo ;
    I32 AxisNo ;
    I32 TotalCard ;

I16 intTemp;
I32 uintTemp;
I32 lngTemp;
I32 dblTemp;
CString strTemp;




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
// CMy8102_Sync_Function_cDlg dialog

CMy8102_Sync_Function_cDlg::CMy8102_Sync_Function_cDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy8102_Sync_Function_cDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy8102_Sync_Function_cDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy8102_Sync_Function_cDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy8102_Sync_Function_cDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy8102_Sync_Function_cDlg, CDialog)
	//{{AFX_MSG_MAP(CMy8102_Sync_Function_cDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK7, OnOk7)
	ON_BN_CLICKED(IDOK8, OnOk8)
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_BN_CLICKED(IDOK3, OnOk3)
	ON_BN_CLICKED(IDOK4, OnOk4)
	ON_BN_CLICKED(IDOK5, OnOk5)
	ON_BN_CLICKED(IDOK6, OnOk6)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8102_Sync_Function_cDlg message handlers

BOOL CMy8102_Sync_Function_cDlg::OnInitDialog()
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
	

    SetDlgItemText(PTP_AXIS,"0");
    SetDlgItemText(PTP_CMD,"150000");
    SetDlgItemText(LINE_CMD_0,"40000");
    SetDlgItemText(LINE_CMD_1,"20000");
    SetDlgItemText(ARC_CMD_0,"40000");
    SetDlgItemText(ARC_CMD_1,"20000");



        I16 i,j ;
		I32 RET=0;

        //_8102_initial(&TotalCard, 0);

        //TotalCard = CARDS_Status(TotalCard, MAX_CARDS_PCI_8102, &CARDS_PCI_8102_Status[16]);

		TotalCard = 0;
		//_8102_initial(&TotalCard, 0);
		RET = APS_initial(&TotalCard, 0);     			// Initial PCI-8102 card


        if (TotalCard == 0)
		{
            AfxMessageBox("No PCI-8102 Found!");
			
			//MsgBox("No PCI-8102 Found!")
            //_8102_close();
			APS_close();
            //End;
        }

        CardNo = 0;
		i=0;


		U16 test1 ;
		U16 test2 ;
		

        for (i = 0;i<= 15;i++)
		{
            test1=1;
			test1=test1 << i;
			test2=TotalCard & test1;
			
			if (test2!=0)
			{
                //_8102_set_pls_outmode(2 * i, 4);
                //_8102_set_pls_iptmode(2 * i, 3, 0);
                //_8102_set_feedback_src(2 * i, 1);

                //_8102_set_pls_outmode((2 * i) + 1, 4);
                //_8102_set_pls_iptmode((2 * i) + 1, 3, 0);
                //_8102_set_feedback_src((2 * i) + 1, 1);

				I32 StartAxisID = 0;
				I32 TotalAxisNum = 0;


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
	                  
				}
	        
			//*******************************************************************************************************************************


			}
            
		}
		//AfxMessageBox(SErr);
	SetTimer(1,80,NULL);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy8102_Sync_Function_cDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy8102_Sync_Function_cDlg::OnPaint() 
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
HCURSOR CMy8102_Sync_Function_cDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}





void CMy8102_Sync_Function_cDlg::OnOk7() 
{
	// TODO: Add your control notification handler code here
		I32 AxisArray[2] = {0, 1};
        I32 distArray[2] = {8000, 12000};

        //F64 strvelArray[2] = {0.0, 0.0};
        //F64 maxvelArray[2] = {4000, 6000};
        //F64 TaccArray[2] = {0.04, 0.06};
        //F64 TdecArray[2] = {0.04, 0.06};

        //_8102_set_tr_move_all(2, AxisArray, distArray, strvelArray, maxvelArray, TaccArray, TdecArray);
        //_8102_start_move_all(AxisArray[0]);

		APS_relative_linear_move(2, AxisArray, distArray, 4000);


}

void CMy8102_Sync_Function_cDlg::OnOk8() 
{
	// TODO: Add your control notification handler code here
	//_8102_stop_move_all(0);

	I32 i ;
	i=0;

    APS_emg_stop(2 * i);
    APS_emg_stop((2 * i) + 1);
}

void CMy8102_Sync_Function_cDlg::OnOk2() 
{
	// TODO: Add your control notification handler code here
	
	//F64 CompTable[4000];
      //  F64 i ;
        I16 Err ;

        I16 AxisNo ;

      //  for (i = 0;i<=1000;i++)
      //  {
	//		CompTable[i] = 30000 + (100 * i);
     //   }

		char text[32];
		CEdit * p;
        
		p = (CEdit *)GetDlgItem(PTP_AXIS);
		p->GetWindowText(text,sizeof(text));
		AxisNo = atoi(text);

		


		CButton *ContiB=(CButton *)GetDlgItem(IDC_CHECK1);



        if( (AxisNo == 0 || AxisNo == 1) && (ContiB->GetCheck()))
		{
              //Err = _8102_set_trigger_comparator(AxisNo, 0, 1, 30000);

            APS_set_axis_param(AxisNo, 550, 5);     //'PRA_GCMP_EN  0x226
            APS_set_axis_param(AxisNo, 551, 30000); //'PRA_GCMP_POS 0x227
            APS_set_axis_param(AxisNo, 552, 0);     //'PRA_GCMP_SRC 0x228

        }


		

		p = (CEdit *)GetDlgItem(PTP_CMD);
		p->GetWindowText(text,sizeof(text));
		dblTemp = _atoi64(text);


        //_8102_start_tr_move(AxisNo, dblTemp, 0, 200000, 0.1, 0.1);

		APS_set_axis_param( AxisNo, PRA_VS, 0 );
		APS_set_axis_param( AxisNo, PRA_ACC, 50000 );
		APS_set_axis_param( AxisNo, PRA_DEC, 50000 );

		APS_relative_move( AxisNo, dblTemp, 200000 );
}

void CMy8102_Sync_Function_cDlg::OnOk3() 
{
	// TODO: Add your control notification handler code here

		I32 dblTemp1;
		I32 dblTemp2;
	
		char text[32];
		CEdit * p;

		I32 AxisArray[2] = {0, 1};
        I32 distArray[2] ;

		p = (CEdit *)GetDlgItem(LINE_CMD_0);
		p->GetWindowText(text,sizeof(text));
		dblTemp1 = (I32)_atoi64(text);

		p = (CEdit *)GetDlgItem(LINE_CMD_1);
		p->GetWindowText(text,sizeof(text));
		dblTemp2 = (I32)_atoi64(text);

        distArray[0] = dblTemp1;
        distArray[1] = dblTemp2;

 		APS_relative_linear_move(2, AxisArray, distArray, 4000);

		//_8102_start_tr_move_xy(CardNo, dblTemp1, dblTemp2, 0, 200000, 0.1, 0.1);

}

void CMy8102_Sync_Function_cDlg::OnOk4() 
{
	// TODO: Add your control notification handler code here

		I32 dblTemp1;
		I32 dblTemp2;
	
		char text[32];
		CEdit * p;

		I32 AxisArray[2] = {0, 1};
        I32 distArray[2] ;

		p = (CEdit *)GetDlgItem(ARC_CMD_0);
		p->GetWindowText(text,sizeof(text));
		dblTemp1 = (I32)_atoi64(text);

		p = (CEdit *)GetDlgItem(ARC_CMD_1);
		p->GetWindowText(text,sizeof(text));
		dblTemp2 = (I32)_atoi64(text);
	
        distArray[0] = dblTemp1;
        distArray[1] = dblTemp2;


		//_8102_start_tr_arc_xy(CardNo, dblTemp1, dblTemp2, 0, 0, 1, 0, 200000, 0.1, 0.1);

		APS_relative_arc_move(2, AxisArray, distArray, 200000, 180);

}

void CMy8102_Sync_Function_cDlg::OnOk5() 
{
	// TODO: Add your control notification handler code here
	I16 i ;
	i=0;
//        for (i = 0;i<=MAX_CARDS_PCI_8102;i++)
//		{
            APS_emg_stop(2 * i);
            APS_emg_stop((2 * i) + 1);

 //       }
}

void CMy8102_Sync_Function_cDlg::OnOk6() 
{
	// TODO: Add your control notification handler code here
	
	I16 i ;
	i=0;

//        for (i = 0 ;i<=MAX_CARDS_PCI_8102;i++)
//		{

//            if (CARDS_PCI_8102_Status[i] == 1)
//			{

                APS_set_position(2 * i, 0);
                APS_set_command(2 * i, 0);

                APS_set_position((2 * i) + 1, 0);
                APS_set_command((2 * i) + 1, 0);
//			}
//		}
}

void CMy8102_Sync_Function_cDlg::OnTimer(UINT_PTR nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	

	//CDialog::OnInitDialog();
	//char text[4];
	//CEdit * p;

	//itoa(m_nred, text, 10);
	//p = (CEdit*)GetDlgItem(IDC_RED);
	//p->SetWindowText(text);






I32 i ;
I32 CurPos ;
I32 CurSpeed ;

        I32 io_sts ;
		I32 MOT_STS ;
        F64 Ckp ;
        I32 PCMD ;

        
		//SetDlgItemInt(IDC_INT,int_counter[AxisNo]);
		//SetDlgItemInt(IDC_POS,(int)pos[AxisNo]);
		//sprintf(string,"0x%x",io_sts);
		//SetDlgItemText(IDC_IOSTS,string);
		//SetDlgItemInt(IDC_MSTS,m_sts);

i=0;

        //for (i = 0;i<=MAX_CARDS_PCI_8102;i++)
		//{
        //    if (CARDS_PCI_8102_Status[i] == 1)
		//	{


                APS_get_position(2 * i, &dblTemp);
 				SetDlgItemInt(Pos0,dblTemp);
		
                APS_get_position((2 * i) + 1, &dblTemp);
                SetDlgItemInt(Pos1,dblTemp);
		


//SetDlgItemInt(IDC_INT,int_counter[AxisNo]);
		//SetDlgItemInt(IDC_POS,(int)pos[AxisNo]);
		//sprintf(strTemp,"0x%x",dblTemp);
				//SetDlgItemText(Pos0,strTemp);
		//SetDlgItemInt(IDC_MSTS,m_sts);

                APS_get_command_velocity(2 * i, &dblTemp);
				SetDlgItemInt(Speed0,dblTemp);

                APS_get_command_velocity((2 * i) + 1, &dblTemp);
                SetDlgItemInt(Speed1,dblTemp);



                uintTemp = APS_motion_io_status(2 * i);
				SetDlgItemInt(IOSts0,uintTemp);
                
                uintTemp = APS_motion_io_status((2 * i) + 1);
				SetDlgItemInt(IOSts1,uintTemp);
                

                intTemp = APS_motion_status(2 * i);
				SetDlgItemInt(MotSts0,intTemp);
                
                intTemp = APS_motion_status((2 * i) + 1);
                SetDlgItemInt(MotSts1,intTemp);
                
                APS_get_command(2 * i, &lngTemp);
				SetDlgItemInt(CMD0,lngTemp);

                APS_get_command((2 * i) + 1, &lngTemp);
                SetDlgItemInt(CMD1,lngTemp);
       //     }
       // }


        I16 AxisNo ;
		char text[32];
		CEdit * p;
        
		p = (CEdit *)GetDlgItem(PTP_AXIS);
		p->GetWindowText(text,sizeof(text));
		AxisNo = atoi(text);


		CButton *ContiB=(CButton *)GetDlgItem(IDC_CHECK1);



        if( (AxisNo == 0 || AxisNo == 1) && (ContiB->GetCheck()))
		{
              //Err = _8102_set_trigger_comparator(AxisNo, 0, 1, 30000);
			I32 get_status ;
            APS_get_axis_param(AxisNo, 554, &get_status);     //'PRA_GCMP_STS 0x22A

			SetDlgItemInt(CMP_STS,get_status);
        }


 
	CDialog::OnTimer(nIDEvent);
}
