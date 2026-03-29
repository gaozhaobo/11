// PCI_8144_DIODlg.cpp : implementation file
//


//Before user use the sample code with the following wiring connections.
// "<-->" Indicates the connection symbol


/**********************************************************************

Pin No   Name          Pin No   Name  
----------------------------------------------
  23     DIN0  <-->    57       DOUT0
  24     DIN1  <-->    58       DOUT1
  25     DIN2  <-->    59       DOUT2
  26     DIN3  <-->    60       DOUT3
  27     DIN4  <-->    61       DOUT4
  28     DIN5  <-->    62       DOUT5
  29     DIN6  <-->    63       DOUT6
  30     DIN7  <-->    64       DOUT7

 
  Pin No   Name             Pin No   Name  
----------------------------------------------
  67       EGND     <-->    68       Ex+24V
  22       STP/EMG  <-->    33       EGND
  65       DO_COM   <-->    67       EGND
  2        EGND     <-->    7        PEL0
  8        MEL0     <-->    12       EGND

***********************************************************************/





#include "stdafx.h"
#include "PCI_8144_DIO.h"
#include "PCI_8144_DIODlg.h"

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


I16 Card_Pci_8144_Status[16];
I16 Now_Max_Card_Pci_8144=0;
I16 ALL_Max_PCI_8144_Card=16;

//I16 Do_Status, DI_Status;
I32 DO_Data , DI_Data;

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
// CPCI_8144_DIODlg dialog

CPCI_8144_DIODlg::CPCI_8144_DIODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPCI_8144_DIODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPCI_8144_DIODlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPCI_8144_DIODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPCI_8144_DIODlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPCI_8144_DIODlg, CDialog)
	//{{AFX_MSG_MAP(CPCI_8144_DIODlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnGetDI, OnBtnGetDI)
	ON_BN_CLICKED(IDC_BtnSetDO, OnBtnSetDO)
	ON_BN_CLICKED(IDC_BtnExit, OnBtnExit)
	ON_BN_CLICKED(IDC_BtnGetDO, OnBtnGetDO)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPCI_8144_DIODlg message handlers

BOOL CPCI_8144_DIODlg::OnInitDialog()
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

	//I32 CardID_InBit;
    I32 BoardID_InBits;

	//I16 RET=0;
	I32 RET=0;


	I16 i=0;
	I16 AxisNum=0;
	TotalCard=0;

	
	
	
	


    //I32 FNTYPE APS_initial( I32 *BoardID_InBits, I32 Mode );
    RET = APS_initial( &BoardID_InBits, 0 );   // Initial PCI-8144 card



	
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
		
          APS_close();//Device close


	//	MessageBox("No PCI-8144 Card Exist", "ERROR");
		CDialog::OnOK();
	}	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPCI_8144_DIODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPCI_8144_DIODlg::OnPaint() 
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
HCURSOR CPCI_8144_DIODlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPCI_8144_DIODlg::OnBtnGetDI() 
{
	// TODO: Add your control notification handler code here
	I16 i;

	CWnd *pwnd;

	CDC *pdc;

	CRect Rect;

	I32 DI_Group=0;

	
    //I32 FNTYPE APS_read_d_input(I32 Board_ID, I32 DI_Group, I32 *DI_Data);
    APS_read_d_input(Board_ID, DI_Group, &DI_Data);  //Board_ID; Set digit input group number; Returned digit input data



	for (i=0; i<8; i++)
	{
		if (DI_Data&(1<<i))
		{
			pwnd = GetDlgItem(IDC_EDIT9+i);
			pdc = pwnd->GetDC();
			pwnd->GetClientRect(&Rect);
			pdc->FillSolidRect(Rect, 0xff00);
			ReleaseDC(pdc);
		}
		else
		{
			pwnd = GetDlgItem(IDC_EDIT9+i);
			pdc = pwnd->GetDC();
			pwnd->GetClientRect(&Rect);
			pdc->FillSolidRect(Rect, 0x00);
			ReleaseDC(pdc);
		}
	}
}

void CPCI_8144_DIODlg::OnBtnSetDO() 
{
	// TODO: Add your control notification handler code here
	I16 state;

	I32 do_value=0;

	I16 i;

	I32 DO_Group=0;

	
	for (i=0; i<8; i++)
	{
		CButton *pCheck = (CButton *)GetDlgItem(IDC_Bit_0+i);
		state = pCheck->GetState();
		
		if (state==1)
		{
		 do_value = do_value | (1<<i);
		}
	}
	
    
    //I32 FNTYPE APS_write_d_output(I32 Board_ID, I32 DO_Group, I32 DO_Data);
    APS_write_d_output( Board_ID, DO_Group, do_value);   //Board_ID; Set digit output group number; Set digit output data (Data type is bit type).

}


void CPCI_8144_DIODlg::OnBtnExit() 
{
	// TODO: Add your control notification handler code here
	
    APS_close();   //Devices close

	CDialog::OnOK();
}

void CPCI_8144_DIODlg::OnBtnGetDO() 
{
	// TODO: Add your control notification handler code here

	CWnd *pWnd;

	CDC *pDC;

	CRect Rect;

	I16 i;

	I32 DO_Group=0;
	
	
	//I32 FNTYPE APS_read_d_output(I32 Board_ID, I32 DO_Group, I32 *DO_Data);
    APS_read_d_output(Board_ID, DO_Group, &DO_Data); //Board_ID; Set digit output group number; The digit output data (Data type is bit type).

	
	for (i=0; i<8; i++)
	{
		if (DO_Data&(1<<i))
		{
			pWnd = GetDlgItem(IDC_EDIT1+i);
			pDC = pWnd->GetDC();
			pWnd->GetClientRect(&Rect);
			pDC->FillSolidRect(Rect, 0xff00);
			ReleaseDC(pDC);
		}
		else
		{
			pWnd = GetDlgItem(IDC_EDIT1+i);
			pDC = pWnd->GetDC();
			pWnd->GetClientRect(&Rect);
			pDC->FillSolidRect(Rect, 0x00);
			ReleaseDC(pDC);
		}
	}
	
}	
