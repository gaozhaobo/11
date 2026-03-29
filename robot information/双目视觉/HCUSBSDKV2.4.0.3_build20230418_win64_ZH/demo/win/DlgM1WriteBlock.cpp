// DlgM1WriteBlock.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgM1WriteBlock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CSTRING_TO_CHARS(str,sz) memcpy((sz),str.GetBuffer(str.GetLength()),str.GetLength())

/////////////////////////////////////////////////////////////////////////////
// CDlgM1WriteBlock dialog


CDlgM1WriteBlock::CDlgM1WriteBlock(CWnd* pParent /*=NULL*/)
    : CDialog(CDlgM1WriteBlock::IDD, pParent)
{
    //{{AFX_DATA_INIT(CDlgM1WriteBlock)
        // NOTE: the ClassWizard will add member initialization here
    m_dwBlockAddr = 0;
    m_bHex = FALSE;
    m_nDataLen = 0;
    memset(m_szData, 0, sizeof(m_szData)); //这是真正的数据
    //}}AFX_DATA_INIT
}


void CDlgM1WriteBlock::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CDlgM1WriteBlock)
        // NOTE: the ClassWizard will add DDX and DDV calls here
    DDX_Control(pDX, IDC_EDT_BLOCK_DATA, m_edtData);
    DDX_Text(pDX, IDC_EDT_BLOCK_ADDR, m_dwBlockAddr);
    DDX_Text(pDX, IDC_EDT_BLOCK_DATA, m_csData);
    //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgM1WriteBlock, CDialog)
    //{{AFX_MSG_MAP(CDlgM1WriteBlock)
    ON_BN_CLICKED(IDC_BTN_WRITE, OnBtnWrite)
    ON_BN_CLICKED(IDC_RAD_HEX, OnBtnHex)
    ON_BN_CLICKED(IDC_RAD_TEXT, OnBtnText)
    //}}AFX_MSG_MAP
	ON_WM_PAINT()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgM1WriteBlock message handlers

BOOL CDlgM1WriteBlock::OnInitDialog()
{
    CDialog::OnInitDialog();

    ((CButton *)GetDlgItem(IDC_RAD_TEXT))->SetCheck(TRUE);

    //char szBuffer[16] = {0};
    //PrintData(szBuffer, 16);

    
    return TRUE;	
}

void CDlgM1WriteBlock::OnBtnHex()
{
    char    szDataShow[512] = {0}; //这是真正的数据
    DWORD   dwDataShowLen = 0;

    if (!m_bHex)
    {
        UpdateData(TRUE);
        memset(m_szData, 0, sizeof(m_szData));
        CSTRING_TO_CHARS(m_csData, m_szData);
        m_nDataLen = strlen(m_szData); 
    }

    m_bHex = TRUE;

    //十六进制显示
    if(!ConvertTextToHex(m_szData, m_nDataLen, szDataShow, &dwDataShowLen))
    {
		if (g_bEnglish)
		{
			MessageBox("Error in hex present，parameter error!");
		}
		else
		{
			MessageBox("以十六进制显示时出错，传递的参数有误!");
		}
    }
    else
    {
        m_csData = szDataShow;
        UpdateData(FALSE);
    }
}

void CDlgM1WriteBlock::OnBtnText()
{
    m_bHex = FALSE;

    //文本显示
    m_csData = m_szData;
    UpdateData(FALSE);
}

void CDlgM1WriteBlock::OnBtnWrite() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    if (m_dwBlockAddr < 0 || m_dwBlockAddr > 65535)
    {
		if (g_bEnglish)
		{
			MessageBox("Addr range:0(include)-65535(include)");
		}
		else
		{
			MessageBox("块地址范围为0(含)-65535(含)");
		}
        return;
    }

	if ((m_dwBlockAddr % 4) == 3)
	{
		if (g_bEnglish)
		{
			MessageBox("This control block do not allow write data!");
		}
		else
		{
			MessageBox("该块为控制块，控制块不允许写入数据!");
		}
        return;
    }

    char szBuffer[256] = {0};
    
   
        
    BYTE byData[64] = {0};
    DWORD dwDataLen = 0;

    CSTRING_TO_CHARS(m_csData, szBuffer);
    
    if (((CButton *)GetDlgItem(IDC_RAD_HEX))->GetCheck())
    {
        
        //十六进制输入
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
    }
    else
    {
        //文本输入
        if (strlen((char*)szBuffer) > 18)
        {
			if (g_bEnglish)
			{
				MessageBox("Text should not exceed 16 bytes!");
			}
			else
			{
				MessageBox("文本大小不能超过16字节!");
			}
            return;
        }
        else
        {
            dwDataLen = strlen((char*)szBuffer);
            memcpy((char*)byData, (char*)szBuffer, dwDataLen);
        }
    }

    memset(m_szData, 0, sizeof(m_szData));
    memcpy((char*)m_szData, (char*)byData, dwDataLen);

    m_nDataLen = dwDataLen;

    USB_M1_BLOCK_WRITE_DATA struWriteBlockData = {0};
    struWriteBlockData.dwSize = sizeof(struWriteBlockData);
    struWriteBlockData.wAddr = static_cast<WORD>(m_dwBlockAddr);
    struWriteBlockData.byDataLen = (BYTE)dwDataLen;
    memcpy(struWriteBlockData.byData, byData, struWriteBlockData.byDataLen);
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struWriteBlockData);
    struInput.lpInBuffer = &struWriteBlockData;
        
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_M1_WRITE_BLOCK, &struInput, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_M1_WRITE_BLOCK");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_M1_WRITE_BLOCK");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgM1WriteBlock::PrintData(char* pBuffer, const DWORD dwSize)
{

    if (!((CButton *)GetDlgItem(IDC_RAD_HEX))->GetCheck())
    {
        //文本输入模式
        return;
    }

    m_csData = _T("");
    UpdateData(FALSE);
    
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

void CDlgM1WriteBlock::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DLG_M1_WRITE_BLOCK);
	SET_CONTROL_LAN(IDD_DLG_M1_WRITE_BLOCK, IDC_STATIC_BLOCK_ADDRESS);
	SET_CONTROL_LAN(IDD_DLG_M1_WRITE_BLOCK, IDC_RAD_HEX);
	SET_CONTROL_LAN(IDD_DLG_M1_WRITE_BLOCK, IDC_RAD_TEXT);
	SET_CONTROL_LAN(IDD_DLG_M1_WRITE_BLOCK, IDC_STATIC_BLOCK_DATA);
	SET_CONTROL_LAN(IDD_DLG_M1_WRITE_BLOCK, IDC_BTN_WRITE);
}