// SubDlgCertificateInfoInterface.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "SubDlgCertificateInfoInterface.h"
#include "DlgTransConfig.h"
#include "DlgOnlineCapture.h"
#include "DlgOfflineCapture.h"
#include "DlgHealthCode.h"
#include "DlgCertificateInfo.h"
#include "DlgCertificateAddAddrInfo.h"
#include "DlgCertificateMac.h"
#include "DlgICCardNo.h"
#include "DlgDetectCard.h"
#include "DlgExternalDev.h"
#include "DlgFingerPrintOper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubDlgCertificateInfoInterface dialog


CSubDlgCertificateInfoInterface::CSubDlgCertificateInfoInterface(CWnd* pParent /*=NULL*/)
	: CDialog(CSubDlgCertificateInfoInterface::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubDlgCertificateInfoInterface)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSubDlgCertificateInfoInterface::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubDlgCertificateInfoInterface)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubDlgCertificateInfoInterface, CDialog)
	//{{AFX_MSG_MAP(CSubDlgCertificateInfoInterface)
	ON_BN_CLICKED(IDC_BTN_GET_CERTIFICATE_INFO, OnBtnGetCertificateInfo)
	ON_BN_CLICKED(IDC_BTN_GET_CERTIFICATE_ADD_ADDR_INFO, OnBtnGetCertificateAddAddrInfo)
	ON_BN_CLICKED(IDC_BTN_GET_CERTIFICATE_MAC, OnBtnGetCertificateMac)
	ON_BN_CLICKED(IDC_BTN_GET_IC_CARD_NO, OnBtnGetIcCardNo)
	ON_BN_CLICKED(IDC_BTN_DETECT_CARD, OnBtnDetectCard)
	ON_BN_CLICKED(IDC_BTN_GET_EXTERNAL_DEV_INFO, OnBtnGetExternalDevInfo)
	ON_BN_CLICKED(IDC_BTN_FINGER_CFG, OnBtnFingerCfg)
	//ON_BN_CLICKED(IDC_BTN_STATE_SECRET_PUBLISH, OnBtnStateSecretPublish)
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BTN_ISAPI_TRANSCONFIG, &CSubDlgCertificateInfoInterface::OnBnClickedBtnIsapiTransconfig)
    ON_BN_CLICKED(IDC_BTN_ONLINECOLLECTION, &CSubDlgCertificateInfoInterface::OnBnClickedBtnOnlinecollection)
    ON_BN_CLICKED(IDC_BTN_OFFLINECOLLECTION2, &CSubDlgCertificateInfoInterface::OnBnClickedBtnOfflinecollection2)
    ON_WM_PAINT()
    ON_BN_CLICKED(IDC_BTN_HEALTH_CODE, &CSubDlgCertificateInfoInterface::OnBnClickedBtnHealthCode)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubDlgCertificateInfoInterface message handlers

void CSubDlgCertificateInfoInterface::OnBtnGetCertificateInfo() 
{
	// TODO: Add your control notification handler code here
    CDlgCertificateInfo dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();	
}

void CSubDlgCertificateInfoInterface::OnBtnGetCertificateAddAddrInfo() 
{
	// TODO: Add your control notification handler code here
    CDlgCertificateAddAddrInfo dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnBtnGetCertificateMac() 
{
	// TODO: Add your control notification handler code here
    CDlgCertificateMac dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();	
}

void CSubDlgCertificateInfoInterface::OnBtnGetIcCardNo() 
{
	// TODO: Add your control notification handler code here
    CDlgICCardNo dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnBtnDetectCard() 
{
	// TODO: Add your control notification handler code here
    CDlgDetectCard dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnBtnGetExternalDevInfo() 
{
	// TODO: Add your control notification handler code here
    CDlgExternalDev dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnBtnFingerCfg() 
{
	// TODO: Add your control notification handler code here
    CDlgFingerPrintOper dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

//#include "DlgStateSecretPublish.h"
//void CSubDlgCertificateInfoInterface::OnBtnStateSecretPublish() 
//{
//	// TODO: Add your control notification handler code here
//    CDlgStateSecretPublish dlg;
//    dlg.m_lUserID = m_lUserID;
//    dlg.DoModal();
//}

void CSubDlgCertificateInfoInterface::OnBnClickedBtnIsapiTransconfig()
{
    // TODO:  在此添加控件通知处理程序代码
    CDlgTransConfig dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnBnClickedBtnOnlinecollection()
{
    // TODO:  在此添加控件通知处理程序代码
    CDlgOnlineCapture dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnBnClickedBtnOfflinecollection2()
{
    // TODO:  在此添加控件通知处理程序代码
    CDlgOfflineCapture dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnBnClickedBtnHealthCode()
{
    // TODO:  在此添加控件通知处理程序代码
    CDlgHealthCode dlg;
    dlg.m_lUserID = m_lUserID;
    dlg.DoModal();
}

void CSubDlgCertificateInfoInterface::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_GET_CERTIFICATE_INFO);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_GET_CERTIFICATE_ADD_ADDR_INFO);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_GET_CERTIFICATE_MAC);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_GET_IC_CARD_NO);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_DETECT_CARD);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_GET_EXTERNAL_DEV_INFO);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_FINGER_CFG);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_ISAPI_TRANSCONFIG);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_ONLINECOLLECTION);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_OFFLINECOLLECTION2);
    SET_CONTROL_LAN(IDD_SUBDLG_CERTIFICATE_INTERFACE, IDC_BTN_HEALTH_CODE);
}



