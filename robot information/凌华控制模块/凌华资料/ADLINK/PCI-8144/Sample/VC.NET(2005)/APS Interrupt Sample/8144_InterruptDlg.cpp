// 8144_InterruptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "8144_Interrupt.h"
#include "8144_InterruptDlg.h"

#include "APS168.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

I16 TotalCard = 0;

//I16 CardID = 0;
I32 Board_ID = 0;

I32 Int_No_F[8]={0};
I32 Int_No_R[8]={0};



I16 Card_Pci_8144_Status[16];
I16 Now_Max_Card_Pci_8144=0;
I16 ALL_Max_PCI_8144_Card=16;


I16 IntNO;
I32 DI_Status;

bool Int_Flag[16] = {false, false, false, false, false, false, false, false, false, false,
                      false, false, false, false, false, false};

//I16 Rtn_Msg[16] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
I32 Rtn_Msg[16] = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
                     
I16 Gpio_Counter[16];

UINT Gpio_Int0(LPVOID pParam)
{
	
		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[0] == true)
		{

			I32 Time_Out = 60000;  //Unit:msec
	        
			
			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
			Rtn_Msg[0] = APS_wait_single_int( Int_No_R[0], Time_Out );
			
			
			//Rtn_Msg[0] = _8144_wait_single_gpio_interrupt(CardID, 0, 10000);



			if(Rtn_Msg[0] == 0)
			{
				APS_reset_int( Int_No_R[0] );
				Gpio_Counter[0] = Gpio_Counter[0] + 1;
            }
				
		}
	
	return 0;
}

UINT Gpio_Int1(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[1] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec
	        
			
			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[1] = APS_wait_single_int( Int_No_R[1], Time_Out );
			
			
			//Rtn_Msg[1] = _8144_wait_single_gpio_interrupt(CardID, 1, 10000);


			if(Rtn_Msg[1] == 0)
			{
				APS_reset_int( Int_No_R[1] );
				Gpio_Counter[1] = Gpio_Counter[1] + 1;
			}

		}
	
	return 0;
}

UINT Gpio_Int2(LPVOID pParam)
{
	
		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[2] == true)
		{
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[2] = APS_wait_single_int( Int_No_R[2], Time_Out );
			
			
			
			//Rtn_Msg[2] = _8144_wait_single_gpio_interrupt(CardID, 2, 10000);


			if(Rtn_Msg[2] == 0)
			{
				APS_reset_int( Int_No_R[2] );
				Gpio_Counter[2] = Gpio_Counter[2] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int3(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[3] == true)
		{
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[3] = APS_wait_single_int( Int_No_R[3], Time_Out );
			
			
			//Rtn_Msg[3] = _8144_wait_single_gpio_interrupt(CardID, 3,10000);


			if(Rtn_Msg[3] == 0)
			{
				APS_reset_int( Int_No_R[3] );
				Gpio_Counter[3] = Gpio_Counter[3] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int4(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[4] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[4] = APS_wait_single_int( Int_No_R[4], Time_Out );
			
			
			
			//Rtn_Msg[4] = _8144_wait_single_gpio_interrupt(CardID, 4, 10000);

			if(Rtn_Msg[4] == 0)
			{
				APS_reset_int( Int_No_R[4] );
				Gpio_Counter[4] = Gpio_Counter[4] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int5(LPVOID pParam)
{
	
		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[5] == true)
		{
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[5] = APS_wait_single_int( Int_No_R[5], Time_Out );
			
			//Rtn_Msg[5] = _8144_wait_single_gpio_interrupt(CardID, 5, 10000);

			if(Rtn_Msg[5] == 0)
			{
				APS_reset_int( Int_No_R[5] );
				Gpio_Counter[5] = Gpio_Counter[5] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int6(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[6] == true)
		{
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[6] = APS_wait_single_int( Int_No_R[6], Time_Out );
			
			
			
			//Rtn_Msg[6] = _8144_wait_single_gpio_interrupt(CardID, 6, 10000);

			if(Rtn_Msg[6] == 0)
			{	
				APS_reset_int( Int_No_R[6] );
				Gpio_Counter[6] = Gpio_Counter[6] + 1;
			}
		}

	return 0;
}

UINT Gpio_Int7(LPVOID pParam)
{
	
		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[7] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[7] = APS_wait_single_int( Int_No_R[7], Time_Out );
			
			
			
			//Rtn_Msg[7] = _8144_wait_single_gpio_interrupt(CardID, 7, 10000);

			if(Rtn_Msg[7] == 0)
			{
				APS_reset_int( Int_No_R[7] );
				Gpio_Counter[7] = Gpio_Counter[7] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int8(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[8] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[8] = APS_wait_single_int( Int_No_F[0], Time_Out );
			
			
			
			//Rtn_Msg[8] = _8144_wait_single_gpio_interrupt(CardID, 8, 10000);

			if(Rtn_Msg[8] == 0)
			{	
				APS_reset_int( Int_No_F[0] );
				Gpio_Counter[8] = Gpio_Counter[8] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int9(LPVOID pParam)
{
	
		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[9] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[9] = APS_wait_single_int( Int_No_F[1], Time_Out );
			
			//Rtn_Msg[9] = _8144_wait_single_gpio_interrupt(CardID, 9, 10000);

			if(Rtn_Msg[9] == 0)
			{
				APS_reset_int( Int_No_F[1] );
				Gpio_Counter[9] = Gpio_Counter[9] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int10(LPVOID pParam)
{
	
		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[10] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[10] = APS_wait_single_int( Int_No_F[2], Time_Out );
			
			
			//Rtn_Msg[10] = _8144_wait_single_gpio_interrupt(CardID, 10, 10000);


			if(Rtn_Msg[10] == 0)
			{	
				APS_reset_int( Int_No_F[2] );
				Gpio_Counter[10] = Gpio_Counter[10] + 1;
			}
		}

	return 0;
}

UINT Gpio_Int11(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[11] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[11] = APS_wait_single_int( Int_No_F[3], Time_Out );
			
			
			
			//Rtn_Msg[11] = _8144_wait_single_gpio_interrupt(CardID, 11, 10000);
			
			if(Rtn_Msg[11] == 0)
			{	
				APS_reset_int( Int_No_F[3] );
				Gpio_Counter[11] = Gpio_Counter[11] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int12(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[12] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[12] = APS_wait_single_int( Int_No_F[4], Time_Out );
			
			
			
			//Rtn_Msg[12] = _8144_wait_single_gpio_interrupt(CardID, 12, 10000);
			if(Rtn_Msg[12] == 0)
			{	
                APS_reset_int( Int_No_F[4] );
				Gpio_Counter[12] = Gpio_Counter[12] + 1;
			}
		}

	return 0;
}

UINT Gpio_Int13(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[13] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[13] = APS_wait_single_int( Int_No_F[5], Time_Out );
			
			
			
			//Rtn_Msg[13] = _8144_wait_single_gpio_interrupt(CardID, 13, 10000);
			
			if(Rtn_Msg[13] == 0)
			{
				APS_reset_int( Int_No_F[5] );
				Gpio_Counter[13] = Gpio_Counter[13] + 1;
			}
		}
	
	return 0;
}

UINT Gpio_Int14(LPVOID pParam)
{

		CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
		if (Int_Flag[14] == true)
		{
			
			I32 Time_Out = 60000;  //Unit:msec

			//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
            Rtn_Msg[14] = APS_wait_single_int( Int_No_F[6], Time_Out );
			
			
			
			
			
			//Rtn_Msg[14] = _8144_wait_single_gpio_interrupt(CardID, 14, 10000);
			
			if(Rtn_Msg[14] == 0)
			{
				APS_reset_int( Int_No_F[6] );
				Gpio_Counter[14] = Gpio_Counter[14] + 1;
			}
		}

	return 0;
}

UINT Gpio_Int15(LPVOID pParam)
{
	CMy8144_InterruptDlg *thread = (CMy8144_InterruptDlg*) pParam;
	if (Int_Flag[15] == true)
	{
		
		
		I32 Time_Out = 60000;  //Unit:msec

		//I32 FNTYPE APS_wait_single_int( I32 Int_No, I32 Time_Out );
        Rtn_Msg[15] = APS_wait_single_int( Int_No_F[7], Time_Out );
		
		
		
		//Rtn_Msg[15] = _8144_wait_single_gpio_interrupt(CardID, 15, 10000);
		
		if(Rtn_Msg[15] == 0)
		{
			APS_reset_int( Int_No_F[7] );
			Gpio_Counter[15] = Gpio_Counter[15] + 1;
		}
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
// CMy8144_InterruptDlg dialog

CMy8144_InterruptDlg::CMy8144_InterruptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy8144_InterruptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy8144_InterruptDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMy8144_InterruptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy8144_InterruptDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy8144_InterruptDlg, CDialog)
	//{{AFX_MSG_MAP(CMy8144_InterruptDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, OnBtnExit)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnBtn_SetFactor)
	ON_BN_CLICKED(IDC_BUTTON2, OnBtn_ResetFactor)
	ON_BN_CLICKED(IDC_BUTTON3, OnBtn_ResetCounter)
	ON_BN_CLICKED(IDC_BUTTON4, OnBtn_WaitInterrupt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8144_InterruptDlg message handlers

BOOL CMy8144_InterruptDlg::OnInitDialog()
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

//	I32 CardID_InBit;
    I32 BoardID_InBits;

	//I16 RET=0;
	I32 RET=0;

	I32 Mode=0;


	I16 i=0;
	I16 AxisNum=0;
	TotalCard=0;



	//RET = _8144_initial(&CardID_InBit, 0);			// Initial PCI-8144 card

	//I32 FNTYPE APS_initial( I32 *BoardID_InBits, I32 Mode );
	RET = APS_initial(  &BoardID_InBits , Mode );




	
	for (i = 0; i < ALL_Max_PCI_8144_Card; i++)     // Check how many card on PC
	{
		if (BoardID_InBits & (1<<i))
		{
			TotalCard = TotalCard+1;
			Card_Pci_8144_Status[i] = true;
			Now_Max_Card_Pci_8144 = i+1;
			Board_ID = i;
		}
		else
			Card_Pci_8144_Status[i] = false;
	}

	if (TotalCard == 0)                            // If PCI-8144 is not exist, then close program 
	{
		
		APS_close();
		//_8144_close();

		MessageBox("No PCI-8144 Card Exist", "ERROR");
		CDialog::OnOK();
	}
	
	for ( int j = 0; j < 16; j++ )
		SetDlgItemInt(IDC_EDIT9+j, Gpio_Counter[j]);

	SetTimer(1, 50, NULL);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy8144_InterruptDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy8144_InterruptDlg::OnPaint() 
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
HCURSOR CMy8144_InterruptDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy8144_InterruptDlg::OnBtnExit() 
{
	// TODO: Add your control notification handler code here

	
	APS_close();  //Device close

	CDialog::OnOK();

}

void CMy8144_InterruptDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	I16 i;

	CWnd *pwnd;

	CDC *pdc;

	CRect Rect;

    I32 DI_Group=0;



	//_8144_get_gpio_input(CardID, &DI_Status);

    //I32 FNTYPE APS_read_d_input(I32 Board_ID, I32 DI_Group, I32 *DI_Data);
    APS_read_d_input(Board_ID, DI_Group,&DI_Status);



	for (i=0; i<8; i++)
	{
		if (DI_Status&(1<<i))
		{
			pwnd = GetDlgItem(IDC_EDIT1+i);
			pdc = pwnd->GetDC();
			pwnd->GetClientRect(&Rect);
			pdc->FillSolidRect(Rect, 0xff00);
			ReleaseDC(pdc);
		}
		else
		{
			pwnd = GetDlgItem(IDC_EDIT1+i);
			pdc = pwnd->GetDC();
			pwnd->GetClientRect(&Rect);
			pdc->FillSolidRect(Rect, 0x00);
			ReleaseDC(pdc);
		}
	}


	
	Check_Counter();

	CDialog::OnTimer(nIDEvent);	
}

void CMy8144_InterruptDlg::OnBtn_SetFactor() 
{
	// TODO: Add your control notification handler code here

	I16 i;
	I16 State_F=0;
    I16 j;
	I16 State_R=0;
    I32 returnCode=0;

	
    for (j=0; j < 8; j++)                                       //Set Rising edge
	{
		CButton *pCheck = (CButton *)GetDlgItem(IDC_RADIO1+j);
		State_R = pCheck->GetCheck();
		
		if (State_R==1)
		{
			//I32 FNTYPE APS_set_int_factor( I32 Board_ID, I32 Item_No, I32 Factor_No, I32 Enable );
            Int_No_R[j] = APS_set_int_factor(  Board_ID,  5 ,  j , 1 );    //Board_ID; Digital input interrupt (Rising edge); Set Interrupt Bit; Enable the interrupt factor 
		}
    }



	for (i=0; i < 8; i++)                                       //Set Falling edge 
	{
		CButton *pCheck = (CButton *)GetDlgItem(IDC_RADIO9+i);
		State_F = pCheck->GetCheck();
		
		if (State_F==1)
		{
			//I32 FNTYPE APS_set_int_factor( I32 Board_ID, I32 Item_No, I32 Factor_No, I32 Enable );
            Int_No_F[i] = APS_set_int_factor(  Board_ID,  4 ,  i , 1 );    //Board_ID; Digital input interrupt (Falling edge); Set Interrupt Bit; Enable the interrupt factor
		}
    }


	
    //I32 FNTYPE APS_int_enable( I32 Board_ID, I32 Enable );
	returnCode = APS_int_enable(  Board_ID , 1 );   //Board_ID; Enable interrupt


}

void CMy8144_InterruptDlg::OnBtn_ResetFactor() 
{
	// TODO: Add your control notification handler code here

	for (int i=0; i < 16; i++)
	{
		CButton *pCheck = (CButton *)GetDlgItem(IDC_RADIO1+i);
		pCheck->SetCheck (0);
		Int_Flag[i] = false;
	}


	
}

void CMy8144_InterruptDlg::OnBtn_ResetCounter() 
{
	// TODO: Add your control notification handler code here

	for(int i = 0; i < 16; i++)
	
	Gpio_Counter[i] = 0;	

}

void CMy8144_InterruptDlg::OnBtn_WaitInterrupt() 
{
	// TODO: Add your control notification handler code here
	
	for( int i = 0; i < 16; i++ )
	{
		CButton *pCheck = (CButton *)GetDlgItem(IDC_RADIO1+i);
		long State = pCheck->GetCheck();
		if (State)
		{
			switch(i)
			{
				case 0:
					Int_Flag[0] = true;
					AfxBeginThread(Gpio_Int0, this);
					break;
				case 1:
					Int_Flag[1] = true;
					AfxBeginThread(Gpio_Int1, this);
					break;
				case 2:
					Int_Flag[2] = true;
					AfxBeginThread(Gpio_Int2, this);
					break;
				case 3:
					Int_Flag[3] = true;
					AfxBeginThread(Gpio_Int3, this);
					break;
				case 4:
					Int_Flag[4] = true;
					AfxBeginThread(Gpio_Int4, this);
					break;
				case 5:
					Int_Flag[5] = true;
					AfxBeginThread(Gpio_Int5, this);
					break;
				case 6:
					Int_Flag[6] = true;
					AfxBeginThread(Gpio_Int6, this);
					break;
				case 7:
					Int_Flag[7] = true;
					AfxBeginThread(Gpio_Int7, this);
					break;
				case 8:
					Int_Flag[8] = true;
					AfxBeginThread(Gpio_Int8, this);
					break;
				case 9:
					
					Int_Flag[9] = true;
					AfxBeginThread(Gpio_Int9, this);
					break;
				case 10:
					Int_Flag[10] = true;
					AfxBeginThread(Gpio_Int10, this);
					break;
				case 11:
					Int_Flag[11] = true;
					AfxBeginThread(Gpio_Int11, this);
					break;
				case 12:
					Int_Flag[12] = true;
					AfxBeginThread(Gpio_Int12, this);
					break;
				case 13:
					Int_Flag[13] = true;
					AfxBeginThread(Gpio_Int13, this);
					break;
				case 14:
					Int_Flag[14] = true;
					AfxBeginThread(Gpio_Int14, this);
					break;
				case 15:
					Int_Flag[15] = true;
					AfxBeginThread(Gpio_Int15, this);
					break;
			}
		}
	}	
}

void CMy8144_InterruptDlg::Check_Counter()
{
	for ( int j = 0; j < 16; j++ )
		SetDlgItemInt(IDC_EDIT9+j, Gpio_Counter[j]);		
}
