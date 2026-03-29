// DlgDeviceReg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgDeviceReg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDeviceReg dialog


CDlgDeviceReg::CDlgDeviceReg(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgDeviceReg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgDeviceReg)
        // NOTE: the ClassWizard will add member initialization here
    m_dwRetLen = 0;
    //}}AFX_DATA_INIT
}


void CDlgDeviceReg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgDeviceReg)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_STA_RET_LEN, m_dwRetLen);
    DDX_Text(pDX, IDC_STA_RET_DATA, m_csRetData);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDeviceReg, CDialog)
    //{{AFX_MSG_MAP(CDlgDeviceReg)
    ON_BN_CLICKED(IDC_BTN_REG, OnBtnReg)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDeviceReg message handlers

BOOL CDlgDeviceReg::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;
}

void CDlgDeviceReg::OnBtnReg() 
{
    // TODO: Add your control notification handler code here
    UpdateData(FALSE);
    
 
    return;	
}

void CDlgDeviceReg::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_DEVICE_REG);
	SET_CONTROL_LAN(IDD_DLG_DEVICE_REG, IDC_STATIC_DATA_LEN);
	SET_CONTROL_LAN(IDD_DLG_DEVICE_REG, IDC_STATIC_DATA);
	SET_CONTROL_LAN(IDD_DLG_DEVICE_REG, IDC_BTN_REG);
}
