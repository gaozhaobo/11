// DlgM1MifarePack.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgM1MifarePack.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgM1MifarePack dialog





CDlgM1MifarePack::CDlgM1MifarePack(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1MifarePack::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1MifarePack)
        // NOTE: the ClassWizard will add member initialization here
    m_dwDataLen = 0;
    m_dwDelay   = 0;
    m_bChange   = TRUE;
    //}}AFX_DATA_INIT
}

void CDlgM1MifarePack::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1MifarePack)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_EDT_DATA, m_edtData);
    DDX_Text(pDX, IDC_EDT_DATA, m_csData);

    DDX_Text(pDX, IDC_EDT_DATA_LEN, m_dwDataLen);
    DDX_Text(pDX, IDC_EDT_DELAY, m_dwDelay);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1MifarePack, CDialog)
    //{{AFX_MSG_MAP(CDlgM1MifarePack)
    ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
    ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
    ON_EN_KILLFOCUS(IDC_EDT_DATA_LEN, OnKillfocusEdtDataLen)
	//}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1MifarePack message handlers

BOOL CDlgM1MifarePack::OnInitDialog()
{
    CDialog::OnInitDialog();

    memset(m_szBuf, 0, sizeof(m_szBuf));

    return TRUE;
}

void CDlgM1MifarePack::OnBtnGet() 
{
    // TODO: Add your control notification handler code here

    UpdateData(TRUE);
}

void CDlgM1MifarePack::OnBtnSet() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    char szBuffer[1024] = {0};
    
    CSTRING_TO_CHARS(m_csData, szBuffer);
    
    BYTE byData[256] = {0};
    DWORD dwDataLen = 0;
    
    if (!ConvertHexBufToByteBuf(szBuffer, strlen(szBuffer)+1, byData, &dwDataLen))
    {
		if (g_bEnglish)
		{
			MessageBox("Transfer data failed!");
		}
		else
		{
			MessageBox("转换数据失败!");
		}
        return;
    }
    
    USB_M1_MF_PACK struM1Pack = {0};
    struM1Pack.dwSize = sizeof(struM1Pack);
    
    struM1Pack.byBufLen = (BYTE)m_dwDataLen;
    memcpy(struM1Pack.byBuf, byData, struM1Pack.byBufLen);
    
    USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
    struConfigInputInfo.dwInBufferSize = sizeof(struM1Pack);
    struConfigInputInfo.lpInBuffer = &struM1Pack;

    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    struConfigOutputInfo.dwOutBufferSize = sizeof(struM1Pack);
    struConfigOutputInfo.lpOutBuffer = &struM1Pack;
    
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_M1_MF_PACK, &struConfigInputInfo, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_M1_MF_PACK");
        m_dwDataLen = struM1Pack.byBufLen;
        m_dwDelay = struM1Pack.byDelay;
        UpdateData(FALSE);
        PrintData(&struM1Pack.byBuf[0], struM1Pack.byBufLen);
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_M1_MIFARE_PACK");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}


BOOL CDlgM1MifarePack::CheckIsNum(char c)
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

void CDlgM1MifarePack::PrintData(BYTE* pBuffer, const DWORD dwSize)
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

void CDlgM1MifarePack::OnKillfocusEdtDataLen() 
{
    // TODO: Add your control notification handler code here

    UpdateData(TRUE);
    
    if (m_dwDataLen < 0 || m_dwDataLen > 255)
    {
		if (g_bEnglish)
		{
			MessageBox("Data length is wrong!(0-255)");
		}
		else
		{
			MessageBox("输入的数据长度不正确!(0-255)");
		}
        return;
    }
    
    BYTE szData[256] = {0};

    m_bChange = FALSE;
    PrintData(szData, m_dwDataLen);

    memset(m_szBuf, 0, sizeof(m_szBuf));

    UpdateData(TRUE);
    CSTRING_TO_CHARS(m_csData, m_szBuf);

    m_bChange = TRUE;
}

BOOL CDlgM1MifarePack::PreTranslateMessage(MSG* pMsg)
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

BOOL CDlgM1MifarePack::DoNumberInput(int nKey)
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

BOOL CDlgM1MifarePack::DoCtrlV()
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


char CDlgM1MifarePack::ConvertKey(int nKey)
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

void CDlgM1MifarePack::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_MIFARE_PACK);
	SET_CONTROL_LAN(IDD_DLG_M1_MIFARE_PACK, IDC_STATIC_DATA_LEN);
	SET_CONTROL_LAN(IDD_DLG_M1_MIFARE_PACK, IDC_STATIC_TIMEOUT);
	SET_CONTROL_LAN(IDD_DLG_M1_MIFARE_PACK, IDC_BTN_GET);
	SET_CONTROL_LAN(IDD_DLG_M1_MIFARE_PACK, IDC_BTN_SET);
}

