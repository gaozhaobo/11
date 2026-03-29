// SubDlgDevInterface.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "SubDlgDevInterface.h"
#include "DlgBeepAndFlickerCtrl.h"
#include "DlgGetCardIssueVer.h"
#include "DlgRFCReset.h"
#include "DlgDeviceReg.h"
#include "DlgSetDeviceKey.h"
#include "DlgUpgrade.h"
#include "Language.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SubDlgDevInterface dialog

SubDlgDevInterface::SubDlgDevInterface(CWnd* pParent /*=NULL*/)
    : CDialog(SubDlgDevInterface::IDD, pParent)
{
    //{{AFX_DATA_INIT(SubDlgDevInterface)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void SubDlgDevInterface::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(SubDlgDevInterface)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SubDlgDevInterface, CDialog)
    //{{AFX_MSG_MAP(SubDlgDevInterface)
    ON_BN_CLICKED(IDC_BTN_BEEP_AND_FLICKER, OnBtnBeepAndFlicker)
    ON_BN_CLICKED(IDC_BTN_GET_HAIRPIN_VER, OnBtnGetHairpinVer)
    ON_BN_CLICKED(IDC_BTN_RESET_RFC, OnBtnResetRfc)
    ON_BN_CLICKED(IDC_BTN_REG_DEVICE, OnBtnRegDevice)
    ON_BN_CLICKED(IDC_BTN_SET_DEV_KEY, OnBtnSetDevKey)
	ON_BN_CLICKED(IDC_BTN_UPGRADE, OnBtnUpgrade)
	//}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SubDlgDevInterface message handlers

void SubDlgDevInterface::OnBtnBeepAndFlicker() 
{
    // TODO: Add your control notification handler code here
    CDlgBeepAndFlickerCtrl dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();    
}

void SubDlgDevInterface::OnBtnGetHairpinVer() 
{
    // TODO: Add your control notification handler code here
    CDlgGetCardIssueVer dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();  
}

void SubDlgDevInterface::OnBtnResetRfc() 
{
    // TODO: Add your control notification handler code here
    CDlgRFCReset  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgDevInterface::OnBtnRegDevice() 
{
    // TODO: Add your control notification handler code here
    CDlgDeviceReg  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
    
}

void SubDlgDevInterface::OnBtnSetDevKey() 
{
    // TODO: Add your control notification handler code here
    CDlgSetDeviceKey  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgDevInterface::OnBtnUpgrade() 
{
	// TODO: Add your control notification handler code here
    CDlgUpgrade  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgDevInterface::OnPaint()
{
	CPaintDC dc(this);
	SET_CONTROL_LAN(IDD_SUBDLG_DEV_INTERFACE, IDC_BTN_BEEP_AND_FLICKER);
	SET_CONTROL_LAN(IDD_SUBDLG_DEV_INTERFACE, IDC_BTN_GET_HAIRPIN_VER);
	SET_CONTROL_LAN(IDD_SUBDLG_DEV_INTERFACE, IDC_BTN_RESET_RFC);
	SET_CONTROL_LAN(IDD_SUBDLG_DEV_INTERFACE, IDC_BTN_UPGRADE);
	SET_CONTROL_LAN(IDD_SUBDLG_DEV_INTERFACE, IDC_BTN_REG_DEVICE);
	SET_CONTROL_LAN(IDD_SUBDLG_DEV_INTERFACE, IDC_BTN_SET_DEV_KEY);
}
