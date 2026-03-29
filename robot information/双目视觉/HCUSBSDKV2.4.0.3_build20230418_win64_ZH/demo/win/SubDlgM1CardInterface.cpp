// SubDlgM1CardInterface.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "SubDlgM1CardInterface.h"
#include "DlgM1PwdVerify.h"
#include "DlgM1ReadBlock.h"
#include "DlgM1WriteBlock.h"
#include "DlgM1ModifySCB.h"
#include "DlgM1BlockAdd.h"
#include "DlgM1BlockMinus.h"
#include "DlgM1BlockToReg.h"
#include "DlgM1RegToBlock.h"
#include "DlgM1MifarePack.h"
#include "DlgM1SectionEncrypt.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SubDlgM1CardInterface dialog


SubDlgM1CardInterface::SubDlgM1CardInterface(CWnd* pParent /*=NULL*/)
    : CDialog(SubDlgM1CardInterface::IDD, pParent)
{
    //{{AFX_DATA_INIT(SubDlgM1CardInterface)
        // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
}


void SubDlgM1CardInterface::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(SubDlgM1CardInterface)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SubDlgM1CardInterface, CDialog)
    //{{AFX_MSG_MAP(SubDlgM1CardInterface)
    ON_BN_CLICKED(IDC_BTN_M1_PWD_VERIFY, OnBtnM1PwdVerify)
    ON_BN_CLICKED(IDC_BTN_READ_BLOCK, OnBtnReadBlock)
    ON_BN_CLICKED(IDC_BTN_MOD_BLOCK, OnBtnModBlock)
    ON_BN_CLICKED(IDC_BTN_BLOCK_ADD, OnBtnBlockAdd)
    ON_BN_CLICKED(IDC_BTN_BLOCK_MINUS, OnBtnBlockMinus)
    ON_BN_CLICKED(IDC_BTN_EEPROM_TO_REG, OnBtnEepromToReg)
    ON_BN_CLICKED(IDC_BTN_REG_TO_EEPROM, OnBtnRegToEeprom)
    ON_BN_CLICKED(IDC_BTN_MIFARE_PACK, OnBtnMifarePack)
    ON_BN_CLICKED(IDC_BTN_WRITE_BLOCK, OnBtnWriteBlock)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
    ON_BN_CLICKED(IDC_BTN_M1_SECTION_ENCRYPT, &SubDlgM1CardInterface::OnBnClickedBtnM1SectionEncrypt)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SubDlgM1CardInterface message handlers

void SubDlgM1CardInterface::OnBtnM1PwdVerify() 
{
    // TODO: Add your control notification handler code here
    CDlgM1PwdVerify  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgM1CardInterface::OnBtnReadBlock() 
{
    // TODO: Add your control notification handler code here
    CDlgM1ReadBlock  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgM1CardInterface::OnBtnWriteBlock() 
{
    // TODO: Add your control notification handler code here
    CDlgM1WriteBlock dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgM1CardInterface::OnBtnModBlock() 
{
    // TODO: Add your control notification handler code here
    CDlgM1ModifySCB dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();   
}

void SubDlgM1CardInterface::OnBtnBlockAdd() 
{
    // TODO: Add your control notification handler code here
    CDlgM1BlockAdd dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();  
}

void SubDlgM1CardInterface::OnBtnBlockMinus() 
{
    // TODO: Add your control notification handler code here
    CDlgM1BlockMinus dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();   
}

void SubDlgM1CardInterface::OnBtnEepromToReg() 
{
    // TODO: Add your control notification handler code here
    CDlgM1BlockToReg  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgM1CardInterface::OnBtnRegToEeprom() 
{
    // TODO: Add your control notification handler code here
    CDlgM1RegToBlock  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void SubDlgM1CardInterface::OnBtnMifarePack() 
{
    // TODO: Add your control notification handler code here
    CDlgM1MifarePack  dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
    
}

void SubDlgM1CardInterface::OnBnClickedBtnM1SectionEncrypt()
{
    // TODO:  在此添加控件通知处理程序代码
    CDlgM1SectionEncrypt dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}


void SubDlgM1CardInterface::OnPaint()
{
	CPaintDC dc(this);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_M1_PWD_VERIFY);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_READ_BLOCK);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_WRITE_BLOCK);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_MOD_BLOCK);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_BLOCK_ADD);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_BLOCK_MINUS);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_EEPROM_TO_REG);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_REG_TO_EEPROM);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_MIFARE_PACK);
	SET_CONTROL_LAN(IDD_SUBDLG_M1_CARD_INTERFACE, IDC_BTN_M1_SECTION_ENCRYPT);
}