// SubDlgCpuPsamCardInterface.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "SubDlgCpuPsamCardInterface.h"
//#include "DlgPSAMSeatCfg.h"
#include "DlgCardParamCfg.h"
#include "DlgCPUCardReset.h"
#include "DlgCPUCardPack.h"
#include "DlgCPUCardEncryptCfg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubDlgCpuPsamCardInterface dialog


CSubDlgCpuPsamCardInterface::CSubDlgCpuPsamCardInterface(CWnd* pParent /*=NULL*/)
    : CDialog(CSubDlgCpuPsamCardInterface::IDD, pParent)
{
    //{{AFX_DATA_INIT(CSubDlgCpuPsamCardInterface)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void CSubDlgCpuPsamCardInterface::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CSubDlgCpuPsamCardInterface)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubDlgCpuPsamCardInterface, CDialog)
    //{{AFX_MSG_MAP(CSubDlgCpuPsamCardInterface)
    ON_BN_CLICKED(IDC_BTN_PSAM_SOCK_SEL, OnBtnPsamSockSel)
    ON_BN_CLICKED(IDC_BTN_CARD_PARAM_CFG, OnBtnCardParamCfg)
    ON_BN_CLICKED(IDC_BTN_CPU_CARD_DATA, OnBtnCpuCardData)
    ON_BN_CLICKED(IDC_BTN_RESET_CPU_CARD, OnBtnResetCpuCard)
	ON_BN_CLICKED(IDC_BTN_CPU_CARD_ENCRYPT_CFG, OnBtnCpuCardEncryptCfg)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubDlgCpuPsamCardInterface message handlers

void CSubDlgCpuPsamCardInterface::OnBtnPsamSockSel() 
{
    // TODO: Add your control notification handler code here
    //CDlgPSAMSeatCfg dlg;
    //dlg.m_lUserID = m_lUserID;
    //dlg.DoModal(); 
}

void CSubDlgCpuPsamCardInterface::OnBtnCardParamCfg() 
{
    // TODO: Add your control notification handler code here
    CDlgCardParamCfg dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal(); 
}

void CSubDlgCpuPsamCardInterface::OnBtnResetCpuCard() 
{
    // TODO: Add your control notification handler code here
    CDlgCPUCardReset dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal(); 
}

void CSubDlgCpuPsamCardInterface::OnBtnCpuCardData() 
{
    // TODO: Add your control notification handler code here
    CDlgCPUCardPack dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal(); 

}


void CSubDlgCpuPsamCardInterface::OnBtnCpuCardEncryptCfg() 
{
	// TODO: Add your control notification handler code here
    CDlgCPUCardEncryptCfg dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal(); 
}


void CSubDlgCpuPsamCardInterface::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_CONTROL_LAN(IDD_SUBDLG_CPU_PSAM_CARD_INTERFACE, IDC_BTN_PSAM_SOCK_SEL);
    SET_CONTROL_LAN(IDD_SUBDLG_CPU_PSAM_CARD_INTERFACE, IDC_BTN_CARD_PARAM_CFG);
    SET_CONTROL_LAN(IDD_SUBDLG_CPU_PSAM_CARD_INTERFACE, IDC_BTN_RESET_CPU_CARD);
    SET_CONTROL_LAN(IDD_SUBDLG_CPU_PSAM_CARD_INTERFACE, IDC_BTN_CPU_CARD_DATA);
    SET_CONTROL_LAN(IDD_SUBDLG_CPU_PSAM_CARD_INTERFACE, IDC_BTN_CPU_CARD_EN);
}
