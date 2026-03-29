// DlgCardParamCfg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgCardParamCfg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCardParamCfg dialog


CDlgCardParamCfg::CDlgCardParamCfg(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgCardParamCfg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgCardParamCfg)
        // NOTE: the ClassWizard will add member initialization here
    //m_dwDelay = 0;
    //}}AFX_DATA_INIT
}


void CDlgCardParamCfg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgCardParamCfg)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_COM_CARD_TYPE, m_comCardType);
    DDX_Control(pDX, IDC_COM_CARD_PROTO_TYPE, m_comCardProtoType);
    //DDX_Text(pDX, IDC_EDT_DELAY, m_dwDelay);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCardParamCfg, CDialog)
    //{{AFX_MSG_MAP(CDlgCardParamCfg)
    ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_CBN_SELCHANGE(IDC_COM_CARD_TYPE, OnSelchangeComCardType)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCardParamCfg message handlers

BOOL CDlgCardParamCfg::OnInitDialog()
{
    CDialog::OnInitDialog();

    if (g_bEnglish)
    {
        m_comCardType.InsertString(0, _T("0-13.56HZ CPU Card"));
        m_comCardType.InsertString(1, _T("1-PSAM 1"));
        m_comCardType.InsertString(2, _T("2-PSAM 2"));
        m_comCardType.InsertString(3, _T("3-PSAM 3"));
        m_comCardType.InsertString(4, _T("4-PSAM 4"));
    }
    else
    {
        m_comCardType.InsertString(0, _T("0-13.56射频CPU卡"));
        m_comCardType.InsertString(1, _T("1-PSAM卡座1"));
        m_comCardType.InsertString(2, _T("2-PSAM卡座2"));
        m_comCardType.InsertString(3, _T("3-PSAM卡座3"));
        m_comCardType.InsertString(4, _T("4-PSAM卡座4"));
    }

    m_comCardType.SetCurSel(0);

    m_comCardProtoType.EnableWindow(FALSE);
    
    m_comCardProtoType.InsertString(0, _T("0-T=0"));
    m_comCardProtoType.InsertString(1, _T("1-T=1"));
    m_comCardProtoType.SetCurSel(0);
    
    UpdateData(FALSE);
    
    return TRUE;
}

void CDlgCardParamCfg::OnBtnSet() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

//     if (m_dwDelay < 0 || m_dwDelay > 255)
//     {
//         MessageBox("延迟时间的范围为0(含)-255(不含)");
//         return;
//     }
    
    USB_CARD_PARAM struCardParam = {0};
    struCardParam.dwSize = sizeof(struCardParam);
    struCardParam.byCardType = m_comCardType.GetCurSel();
    struCardParam.byCardProto = m_comCardProtoType.GetCurSel();
    //struCardParam.byDelay = (BYTE)m_dwDelay;

    USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
    
    struConfigInputInfo.dwInBufferSize = sizeof(struCardParam);
    struConfigInputInfo.lpInBuffer = &struCardParam;
    
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_CARD_PARAM, &struConfigInputInfo, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_CARD_PARAM");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_CARD_PARAM");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }   
}

void CDlgCardParamCfg::OnSelchangeComCardType() 
{
	// TODO: Add your control notification handler code here
    if (m_comCardType.GetCurSel() == 0)
    {
        m_comCardProtoType.SetCurSel(0);
        m_comCardProtoType.EnableWindow(FALSE);
    }
    else
    {
        m_comCardProtoType.EnableWindow(TRUE);
    }
}


void CDlgCardParamCfg::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_CARD_PARAM_CFG);
    SET_CONTROL_LAN(IDD_DLG_CARD_PARAM_CFG, IDC_STATIC3);
    SET_CONTROL_LAN(IDD_DLG_CARD_PARAM_CFG, IDC_STATIC);
    SET_CONTROL_LAN(IDD_DLG_CARD_PARAM_CFG, IDC_BTN_SET);
}
