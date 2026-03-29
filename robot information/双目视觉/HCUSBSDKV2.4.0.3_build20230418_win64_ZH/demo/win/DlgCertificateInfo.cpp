// DlgCertificateInfo.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgCertificateInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateInfo dialog


CDlgCertificateInfo::CDlgCertificateInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCertificateInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCertificateInfo)
		// NOTE: the ClassWizard will add member initialization here
    m_csWordInfo = _T("");
    m_csPicInfo = _T("");
    m_csFingerPrintInfo = _T("");
	//}}AFX_DATA_INIT
}


void CDlgCertificateInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCertificateInfo)
    DDX_Text(pDX, IDC_EDIT_WORD_INFO, m_csWordInfo);
    DDX_Text(pDX, IDC_EDIT_PIC_INFO, m_csPicInfo);
    DDX_Text(pDX, IDC_EDIT_FINGER_PRINT_INFO, m_csFingerPrintInfo);
    DDX_Control(pDX,IDC_COM_CERTIFICATE_TYPE,m_comboCertificateType);
	//}}AFX_DATA_MAP

    if (g_bEnglish)
    {
        m_comboCertificateType.InsertString(0, _T("ID Card"));
        m_comboCertificateType.InsertString(1, _T("Green Card"));
    }
    else
    {
        m_comboCertificateType.InsertString(0, _T("身份证"));
        m_comboCertificateType.InsertString(1, _T("中国绿卡"));
    }
}


BEGIN_MESSAGE_MAP(CDlgCertificateInfo, CDialog)
	//{{AFX_MSG_MAP(CDlgCertificateInfo)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCertificateInfo message handlers

void CDlgCertificateInfo::OnBtnGet() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    USB_CERTIFICATE_INFO struCertificateInfo = {0};
    struCertificateInfo.dwSize = sizeof(struCertificateInfo);
    
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    struConfigOutputInfo.dwOutBufferSize = sizeof(struCertificateInfo);
    struConfigOutputInfo.lpOutBuffer = &struCertificateInfo;
    
    if (!USB_GetDeviceConfig(m_lUserID, USB_GET_CERTIFICATE_INFO, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_INFO");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;        
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_CERTIFICATE_INFO");

    m_csWordInfo = struCertificateInfo.byWordInfo;
    m_csPicInfo = struCertificateInfo.byPicInfo;
    m_csFingerPrintInfo = struCertificateInfo.byFingerPrintInfo;
    m_comboCertificateType.SetCurSel(struCertificateInfo.byCertificateType);

    UpdateData(FALSE);
}

void CDlgCertificateInfo::OnBtnSet() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	USB_IDENTITY_INFO_CFG struIdentifyInfo = {0};
    struIdentifyInfo.dwSize = sizeof(struIdentifyInfo);
	int iPicSize = m_csPicInfo.GetLength();
	int iFingerPrintSize = m_csFingerPrintInfo.GetLength();

    struIdentifyInfo.wPicInfoSize = iPicSize > PIC_LEN ? PIC_LEN:iPicSize;
    struIdentifyInfo.wFingerPrintInfoSize = iFingerPrintSize > FINGER_PRINT_LEN ? FINGER_PRINT_LEN:iFingerPrintSize;

    memcpy(struIdentifyInfo.byPicInfo, m_csPicInfo.GetBuffer(0),struIdentifyInfo.wPicInfoSize);
    memcpy(struIdentifyInfo.byFingerPrintInfo, m_csFingerPrintInfo.GetBuffer(0),struIdentifyInfo.wFingerPrintInfoSize);

    USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
	struConfigInputInfo.dwInBufferSize = sizeof(struIdentifyInfo);
    struConfigInputInfo.lpInBuffer = &struIdentifyInfo;


	if (!USB_SetDeviceConfig(m_lUserID, USB_SET_IDENTITY_INFO, &struConfigInputInfo, NULL))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_IDENTITY_INFO");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;        
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_IDENTITY_INFO");

	UpdateData(FALSE);
}


void CDlgCertificateInfo::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_CERTIFICATE_INFO);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_INFO, IDC_STATIC);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_INFO, IDC_STATIC2);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_INFO, IDC_STATIC3);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_INFO, IDC_STATIC4);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_INFO, IDC_BTN_GET);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_INFO, IDC_BTN_SET);
    SET_CONTROL_LAN(IDD_DLG_CERTIFICATE_INFO, IDC_STATIC5);
}
