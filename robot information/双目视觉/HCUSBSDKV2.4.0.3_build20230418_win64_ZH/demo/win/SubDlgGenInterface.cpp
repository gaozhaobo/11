// SubDlgGenInterface.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "SubDlgGenInterface.h"
#include "DlgCardProtoCfg.h"
#include "DlgActivateCard.h"
#include "DlgStopCardOper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SubDlgGenInterface dialog


SubDlgGenInterface::SubDlgGenInterface(CWnd* pParent /*=NULL*/)
    : CDialog(SubDlgGenInterface::IDD, pParent)
{
    //{{AFX_DATA_INIT(SubDlgGenInterface)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void SubDlgGenInterface::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(SubDlgGenInterface)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SubDlgGenInterface, CDialog)
    //{{AFX_MSG_MAP(SubDlgGenInterface)
    ON_BN_CLICKED(IDC_BTN_SET_CARD_PROTO, OnBtnSetCardProto)
    ON_BN_CLICKED(IDC_BTN_ACTIVATE_CARD, OnBtnActivateCard)
	ON_BN_CLICKED(IDC_BTN_STOP_CARD_OPER, OnBtnStopCardOper)
	//}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SubDlgGenInterface message handlers

void SubDlgGenInterface::OnBtnSetCardProto() 
{
    // TODO: Add your control notification handler code here
    CDlgCardProtoCfg  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgGenInterface::OnBtnActivateCard() 
{
    // TODO: Add your control notification handler code here
    CDlgActivateCard  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgGenInterface::OnBtnStopCardOper() 
{
	// TODO: Add your control notification handler code here
    CDlgStopCardOper  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgGenInterface::OnPaint()
{
	CPaintDC dc(this);
	SET_CONTROL_LAN(IDD_SUBDLG_GEN_INTERFACE, IDC_BTN_SET_CARD_PROTO);
	SET_CONTROL_LAN(IDD_SUBDLG_GEN_INTERFACE, IDC_BTN_ACTIVATE_CARD);
	SET_CONTROL_LAN(IDD_SUBDLG_GEN_INTERFACE, IDC_BTN_STOP_CARD_OPER);
}
