// DlgGetCardIssueVer.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgGetCardIssueVer.h"
#include "Language.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgGetCardIssueVer dialog


CDlgGetCardIssueVer::CDlgGetCardIssueVer(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgGetCardIssueVer::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgGetCardIssueVer)
        // NOTE: the ClassWizard will add member initialization here
    m_csDevName = _T("");
    m_csSerialNO = _T("");
    m_csSoftwareVer = _T("");
    //}}AFX_DATA_INIT
}


void CDlgGetCardIssueVer::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgGetCardIssueVer)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_STA_DEV_NAME, m_csDevName);
    DDX_Text(pDX, IDC_STA_SERIAL_NO, m_csSerialNO);
    DDX_Text(pDX, IDC_STA_SOFTWARE_VER, m_csSoftwareVer);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgGetCardIssueVer, CDialog)
    //{{AFX_MSG_MAP(CDlgGetCardIssueVer)
    ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgGetCardIssueVer message handlers

BOOL CDlgGetCardIssueVer::OnInitDialog()
{
    CDialog::OnInitDialog();

    UpdateData(FALSE);

    return TRUE;
}

void CDlgGetCardIssueVer::OnBtnGet() 
{
    // TODO: Add your control notification handler code here

    UpdateData(TRUE);

    USB_CARD_ISSUE_VERSION struHairpinVer = {0};
    struHairpinVer.dwSize = sizeof(struHairpinVer);

    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};

    struConfigOutputInfo.dwOutBufferSize = sizeof(struHairpinVer);
    struConfigOutputInfo.lpOutBuffer = &struHairpinVer;

    if (USB_GetDeviceConfig(m_lUserID, USB_GET_CARD_ISSUE_VERSION, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig() Command = USB_GET_HAIRPIN_VERSION");

        m_csDevName = struHairpinVer.szDeviceName;
        m_csSerialNO = struHairpinVer.szSerialNumber;
        //增加了日期和语言，新的版本显示成类似V1.0.1_build20190618_ZH,V1.0.1_build20190618_EN
        //老的还是显示成0x1000001
        //大于等于V2.1.2版本的就可以显示编译时期和语言了
        if (struHairpinVer.dwSoftwareVersion < 0x02010002)
        {
            m_csSoftwareVer.Format("0x%X", struHairpinVer.dwSoftwareVersion);
        }
        else
        {
            int dwVersion = struHairpinVer.dwSoftwareVersion;
            CString csVer;
            csVer.Format("V%d.%d.%d_build%d%02d%02d", (0xff000000 & dwVersion) >> 24, (0x00ff0000 & dwVersion) >> 16, (0x0000ffff & dwVersion),
                struHairpinVer.wYear, struHairpinVer.byMonth, struHairpinVer.byDay);

            if (struHairpinVer.byLanguage == 0)
            {
                csVer += "_ZH";
            }
            else if (struHairpinVer.byLanguage == 1)
            {
                csVer += "_EN";
            }
            m_csSoftwareVer = csVer;
        }
        UpdateData(FALSE);
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_HAIRPIN_VERSION");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }

    return;	
}



void CDlgGetCardIssueVer::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_GET_CARD_ISSUE_VER);
	SET_CONTROL_LAN(IDD_DLG_GET_CARD_ISSUE_VER, IDC_STATIC_CARD_DEVICE_NAME);
	SET_CONTROL_LAN(IDD_DLG_GET_CARD_ISSUE_VER, IDC_STATIC_CARD_DEVICE_SERIVAL);
	SET_CONTROL_LAN(IDD_DLG_GET_CARD_ISSUE_VER, IDC_STATIC_SOFTWARE_VERSION);
	SET_CONTROL_LAN(IDD_DLG_GET_CARD_ISSUE_VER, IDC_BTN_GET);
}