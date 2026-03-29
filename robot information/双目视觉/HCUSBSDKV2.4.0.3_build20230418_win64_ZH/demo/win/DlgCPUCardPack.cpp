// DlgCPUCardPack.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgCPUCardPack.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardPack dialog



CDlgCPUCardPack::CDlgCPUCardPack(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgCPUCardPack::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgCPUCardPack)
        // NOTE: the ClassWizard will add member initialization here
    m_dwDataLen = 0;
    m_dwDelay   = 0;
    m_bChange   = TRUE;
    //}}AFX_DATA_INIT
}


void CDlgCPUCardPack::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgCPUCardPack)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_EDT_DATA, m_edtData);
    DDX_Text(pDX, IDC_EDT_DATA, m_csData);

    DDX_Text(pDX, IDC_EDT_DATA_LEN, m_dwDataLen);
    DDX_Text(pDX, IDC_EDT_DELAY, m_dwDelay);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCPUCardPack, CDialog)
    //{{AFX_MSG_MAP(CDlgCPUCardPack)
    ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
    ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
    ON_EN_KILLFOCUS(IDC_EDT_DATA_LEN, OnKillfocusEdtDataLen)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardPack message handlers

BOOL CDlgCPUCardPack::OnInitDialog()
{
    CDialog::OnInitDialog();

    memset(m_szBuf, 0, sizeof(m_szBuf));

    return TRUE;
}

void CDlgCPUCardPack::OnBtnGet() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
}

void CDlgCPUCardPack::OnBtnSet() 
{
    // TODO: Add your control notification handler code here


    UpdateData(TRUE);

    if (m_dwDataLen < 1 || m_dwDataLen > 255)
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("Data length should range:0(not include)-255(include)");        
#else
        MessageBox("数据长度应为0(不含)-255(含)");        
#endif
        return;
    }

    if (m_dwDelay < 0 || m_dwDelay > 255)
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("Delay time should range:0(include)-255(include)");       
#else
        MessageBox("延时时间应为0(含)-255(含)");        
#endif
        return;
    }
    
    char szBuffer[1024] = {0};
    
    CSTRING_TO_CHARS(m_csData, szBuffer);
        
    BYTE byData[256] = {0};
    DWORD dwDataLen = 0;
    
    if (!ConvertHexBufToByteBuf(szBuffer, strlen(szBuffer)+1, byData, &dwDataLen))
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("Transfer data failed!");      
#else
        MessageBox("转换数据失败!");        
#endif
        return;
    }
    
    USB_CPU_CARD_PACK struCPUPack = {0};
    struCPUPack.dwSize = sizeof(USB_CPU_CARD_PACK);
    struCPUPack.byDelay = (BYTE)m_dwDelay;
    struCPUPack.byBufLen = (BYTE)m_dwDataLen;
    memcpy(struCPUPack.byBuf, byData, struCPUPack.byBufLen);
    
    USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
    struConfigInputInfo.dwInBufferSize = sizeof(struCPUPack);
    struConfigInputInfo.lpInBuffer = &struCPUPack;

    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    struConfigOutputInfo.dwOutBufferSize = sizeof(struCPUPack);
    struConfigOutputInfo.lpOutBuffer = &struCPUPack;
    
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_CPU_CARD_PACK, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_CPU_CARD_PACK");
        m_dwDataLen = struCPUPack.byBufLen;
        m_dwDelay = struCPUPack.byDelay;
        UpdateData(FALSE);
        PrintData(&struCPUPack.byBuf[0], struCPUPack.byBufLen);
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_CPU_CARD_PACK");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

BOOL CDlgCPUCardPack::CheckIsNum(char c)
{
    if (c >= '0' && c <= '9')
    {
        return TRUE;
    }
    
    if (c >= 'A' && c <= 'F')
    {
        return TRUE;
    }
    
    if (c >= 'a' && c <= 'f')
    {
        return TRUE;
    }
    
    return FALSE;
}

void CDlgCPUCardPack::PrintData(BYTE* pBuffer, const DWORD dwSize)
{
    m_csData = _T("");
    UpdateData(FALSE);
    
    {
        CString csTemp;
        CString csInfo;
        
        csInfo = _T("");
        
        for (DWORD i = 1; i < dwSize+1; i++)
        {
            csTemp.Format("%02X", (unsigned char)pBuffer[i-1]);
            
            csInfo += csTemp + _T(" ");

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

void CDlgCPUCardPack::OnKillfocusEdtDataLen() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    if (m_dwDataLen < 0 || m_dwDataLen > 255)
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("Data length is wrong!(0-255)");        
#else
        MessageBox("输入的数据长度不正确!(0-255)");        
#endif
    }
    
    BYTE szData[256] = {0};
    m_bChange = FALSE;
    PrintData(szData, m_dwDataLen);
    m_bChange = TRUE;

    memset(m_szBuf, 0, sizeof(m_szBuf));
    
    UpdateData(TRUE);
    CSTRING_TO_CHARS(m_csData, m_szBuf);
}

BOOL CDlgCPUCardPack::PreTranslateMessage(MSG* pMsg)
{
    CWnd * pWnd2   =   GetDlgItem(IDC_EDT_DATA); 
    if(GetFocus() == pWnd2)//限制输入
    {
        if (pMsg-> message == WM_CHAR)
        {
            int   nKey   =   (int)pMsg-> wParam;
            if (!DoNumberInput((char)nKey))
            {
                //::TranslateMessage(pMsg);
                //::DispatchMessage(pMsg);
            }
            return(TRUE);
        }
        else if(pMsg-> message ==  WM_KEYDOWN) 
        { 
            int   nKey   =   (int)pMsg-> wParam;
            
            if ((nKey == _T('V')) && (::GetKeyState(VK_CONTROL) & 0x8000) )
            {
                if (!DoCtrlV())
                {
                    //::TranslateMessage(pMsg);
                    //::DispatchMessage(pMsg);
                }
            }
            else
            {
                ::TranslateMessage(pMsg);
                ::DispatchMessage(pMsg);
            }
            
            return(TRUE);
        }
    }
    return CDialog::PreTranslateMessage(pMsg);;
}

BOOL CDlgCPUCardPack::DoNumberInput(int nKey)
{
    char cKey = ConvertKey(nKey);

    if (cKey == 0)
    {
        return TRUE;
    }
  
    int pot_x = 0;
    int pot_y = 0;
    int nOffset = 0;
    m_edtData.GetSel(pot_x, pot_y);

    int len = m_dwDataLen/16 * 2 + m_dwDataLen * 3;
    if ((m_dwDataLen % 16) != 0)
    {
        len += 2;
    }

    if (pot_x >= (len - 3))
    {
        return TRUE;
    }
    
    if (m_szBuf[pot_x] == ' ')
    {
        if (m_szBuf[pot_x+1] != '\r')
        {
            m_szBuf[pot_x+1] = nKey;
            nOffset = 2;
        }
        else
        {
            m_szBuf[pot_x+3] = nKey;
            nOffset = 4;
        }
    }
    else if (m_szBuf[pot_x] == '\r')
    {
        m_szBuf[pot_x+2] = nKey;
        nOffset = 3;
    }
    else
    {
        m_szBuf[pot_x] = nKey;
        if (m_szBuf[pot_x+1] == ' ')
        {
            nOffset = 2;
        }
        else
        {
            nOffset = 1;
        }    
    }
    
    
    UpdateData(TRUE);
    m_csData = m_szBuf;
    UpdateData(FALSE);
    
    m_edtData.SetSel(pot_x + nOffset, pot_y + nOffset);

    return TRUE;

}

BOOL CDlgCPUCardPack::DoCtrlV()
{
    char * buffer = NULL;
    if ( OpenClipboard() ) 
    {
        int len = m_dwDataLen/16 * 2 + m_dwDataLen * 3;

        if ((m_dwDataLen % 16) != 0)
        {
            len += 2;
        }

        HANDLE hData = GetClipboardData( CF_TEXT );
        char * buffer = (char*)GlobalLock( hData );
        int nBufLen = strlen(buffer);

        int pot_x = 0;
        int pot_y = 0;
        int nOffset = 0;
        m_edtData.GetSel(pot_x, pot_y);

        for (int i = 0; i < nBufLen; i++)
        {
            if (!CheckIsNum(buffer[i]))
            {
                continue;
            }

            if (m_szBuf[pot_x] == ' ')
            {
                if (m_szBuf[pot_x+1] == '\r')
                {
                    pot_x += 3;  
                }
                else
                {
                    pot_x++;
                }
            }
            else if (m_szBuf[pot_x] == '\r')
            {
                pot_x += 2;
            }

            
            if (pot_x >= (len - 3))
            {
                break;
            }

            m_szBuf[pot_x] = buffer[i];

            pot_x++;
 
        }

        UpdateData(TRUE);
        m_csData = m_szBuf;
        UpdateData(FALSE);

        m_edtData.SetSel(pot_x, pot_x);

        CloseClipboard();

        return TRUE;
    }
    return FALSE;
}


char CDlgCPUCardPack::ConvertKey(int nKey)
{
    BYTE byKey = (BYTE)nKey;
    char cKey = (char)nKey;

    if (nKey >= _T('0')  && nKey <= _T('9'))
    {
        return nKey;
    }
    
    if (nKey >= _T('A') && nKey <= _T('F'))
    {
        return nKey;
    }
    
    if (nKey >= _T('a') && nKey <= _T('f'))
    {
        return nKey;
    }
    
    return 0;
}


void CDlgCPUCardPack::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_CPU_CARD_PACK);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_PACK, IDC_STATIC);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_PACK, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_PACK, IDC_BTN_GET);
    SET_CONTROL_LAN(IDD_DLG_CPU_CARD_PACK, IDC_BTN_SET);
}
