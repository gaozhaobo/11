// DlgCPUCardReset.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgCPUCardReset.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardReset dialog


CDlgCPUCardReset::CDlgCPUCardReset(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgCPUCardReset::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgCPUCardReset)
        // NOTE: the ClassWizard will add member initialization here
    m_dwDataLen = 0;
    //}}AFX_DATA_INIT
}


void CDlgCPUCardReset::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgCPUCardReset)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Text(pDX, IDC_STA_DATA_LEN, m_dwDataLen);
    DDX_Control(pDX, IDC_EDT_DATA, m_edtData);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCPUCardReset, CDialog)
    //{{AFX_MSG_MAP(CDlgCPUCardReset)
    ON_BN_CLICKED(IDC_BTN_RESET, OnBtnReset)
    //}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardReset message handlers

BOOL CDlgCPUCardReset::OnInitDialog()
{
    CDialog::OnInitDialog();
    
    UpdateData(FALSE);
    
    return TRUE;	
}

void CDlgCPUCardReset::OnBtnReset() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    USB_CPU_CARD_RESET_RES struCpuCardResetRes = {0};
    struCpuCardResetRes.dwSize = sizeof(struCpuCardResetRes);

    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    struConfigOutputInfo.dwOutBufferSize = sizeof(struCpuCardResetRes);
    struConfigOutputInfo.lpOutBuffer = &struCpuCardResetRes;
    
    if (USB_GetDeviceConfig(m_lUserID, USB_GET_CPU_CARD_RESET, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_GET_CPU_CARD_RESET");
        m_dwDataLen = struCpuCardResetRes.byBufLen;
        UpdateData(FALSE);
        PrintData((char*)struCpuCardResetRes.byBuf, m_dwDataLen);	
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_CPU_CARD_RESET");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgCPUCardReset::PrintData(char* pBuffer, const DWORD dwSize)
{
    GetDlgItem(IDC_EDT_DATA)->SetWindowText(_T(""));

    {
        CString csTemp;
        CString csInfo;
        
        csInfo = _T("");
        
        for (DWORD i = 1; i < dwSize+1; i++)
        {
            csTemp.Format("%02X", (unsigned char)pBuffer[i-1]);
            
            if(i % 8 == 0)
            {
                csInfo += csTemp + _T("   ");
            }
            else if(i % 4 == 0)
            {
                csInfo += csTemp + _T("  ");
            }
            else
            {
                csInfo += csTemp + _T(" ");
            }
            
            if (i % 16 == 0)
            {
                csInfo += _T("\r\n");
                m_edtData.SetSel(-1);
                m_edtData.ReplaceSel(csInfo);
                csInfo = _T("");
            }
        }
        if (csInfo.GetLength() != 0)
        {
            csInfo += _T("\r\n");
            m_edtData.SetSel(-1);
            m_edtData.ReplaceSel(csInfo);
            csInfo = _T("");
        }
    }
}

void CDlgCPUCardReset::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_CPU_CARD_RESET);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_RESET, IDC_STATIC);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_RESET, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_RESET, IDC_BTN_RESET);
}
