// DlgDetectCard.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgDetectCard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDetectCard dialog


CDlgDetectCard::CDlgDetectCard(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDetectCard::IDD, pParent)
{
	m_dwWaitSecond = 5;
    m_csResult = _T("");
}


void CDlgDetectCard::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_WAIT_SECOND, m_dwWaitSecond);
    DDX_Text(pDX, IDC_EDIT_WAIT_SECOND2, m_csResult);
}


BEGIN_MESSAGE_MAP(CDlgDetectCard, CDialog)
	//{{AFX_MSG_MAP(CDlgDetectCard)
	ON_BN_CLICKED(IDC_BTN_DETECT, OnBtnDetect)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDetectCard message handlers

void CDlgDetectCard::OnBtnDetect() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    if (m_dwWaitSecond < 0 || m_dwWaitSecond > 255)
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("Operate wait time range:0(include)-255(include),0 present wait until read card");        
#else
        MessageBox("操作等待时间的范围为0(含)-255(含), 0表示一直执行，直到检测到卡");        
#endif
        return;
    }
    
    USB_DETECT_CARD_COND struDetectCardCond = {0};
    struDetectCardCond.dwSize = sizeof(USB_DETECT_CARD_COND);
    struDetectCardCond.byWait = (BYTE)m_dwWaitSecond;
    
    USB_DETECT_CARD_CFG struDetectCardCfg = {0};
    struDetectCardCfg.dwSize = sizeof(USB_DETECT_CARD_CFG);
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struDetectCardCond);
    struInput.lpInBuffer = &struDetectCardCond;
    
    USB_CONFIG_OUTPUT_INFO struOutput = {0};
    struOutput.dwOutBufferSize = sizeof(struDetectCardCfg);
    struOutput.lpOutBuffer = &struDetectCardCfg;
    
    if (USB_GetDeviceConfig(m_lUserID, USB_DETECT_CARD, &struInput, &struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_DETECT_CARD");
        if (struDetectCardCfg.byCardStatus == 0)
        {
#ifdef SWITCH_ENGLISH_US
            m_csResult = "Not detect card";            
#else
            m_csResult = "未检测到卡片";            
#endif
        }
        else
        {
#ifdef SWITCH_ENGLISH_US
            m_csResult = "Already detect card";            
#else
            m_csResult = "检测到卡片";           
#endif
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_DETECT_CARD");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }

    UpdateData(FALSE);
}


void CDlgDetectCard::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_DETECT_CARD);
    SET_CONTROL_LAN(IDD_DLG_DETECT_CARD, IDC_STATIC);
    SET_CONTROL_LAN(IDD_DLG_DETECT_CARD, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_DETECT_CARD, IDC_BTN_DETECT);
}
