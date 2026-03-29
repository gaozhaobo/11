
#include "StdAfx.h"

#include <windows.h>


#include "GlobalCtrl.h"



//CEdit* LogInfo::s_pEdit = NULL;

CListCtrl* LogInfo::s_pListLog = NULL;

CDialog* LogInfo::s_pDlg = NULL;

LogInfo* LogInfo::s_pInstance = NULL;


BOOL CheckIsNum(char c)
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

//'F'->16
int GetNumValue(char c)
{
    if (c >= '0' && c <= '9')
    {
        return (c - '0');
    }
    
    if (c >= 'A' && c <= 'F')
    {
        return 10 + (c-'A');
    }
    
    if (c >= 'a' && c <= 'f')
    {
        return 10 + (c - 'a');
    }
    
    return 0;
}

// "FF"->255
BYTE NumToByte(char *pBuffer, int len)
{
    if (len > 2)
    {
        assert(FALSE);
    }
    if (len < 1)
    {
        return 0;
    }

    if (len == 1)
    {
        return GetNumValue(pBuffer[0]);
    }
    else if (len == 2)
    {
        int a = GetNumValue(pBuffer[0]);
        int b = GetNumValue(pBuffer[1]);
        return (BYTE)(a*16 + b);
    }
    return 0;
}

BOOL ConvertCStringToArray(CString& csData, BYTE* pData, DWORD* pDataLen)
{
    if (pData == NULL || pDataLen == NULL)
    {
        return FALSE;
    }

    char *szBuffer = new char[1024];
    memset(szBuffer, 0, 1024);
    memcpy(szBuffer, csData.GetBuffer(csData.GetLength()), csData.GetLength());
    int nBufferLen = strlen(szBuffer);

    char szValue[3] = {0};
    char *pValue = &szValue[0];
    BOOL bValue = FALSE;
    BYTE byValue = 0;
    for (int i = 0; i < nBufferLen; i++)
    {
        if (szBuffer[i] == ' ' || szBuffer[i] == '\0')
        {
            if (bValue)
            {
                byValue = NumToByte(szValue, strlen(szValue));
                *pData = byValue;
                pData++;
                *pDataLen += 1;

                memset(szValue, 0, sizeof(szValue));
                pValue = &szValue[0];

                bValue = FALSE;
            }
            else
            {
                continue;
            }
        }
        else if (szBuffer[i] == '\t' || szBuffer[i] == '\r'|| szBuffer[i] == '\n')
        {
            continue;
        }
        else
        {
            if (strlen(szValue) > 2)
            {
                delete[] szBuffer;
                return FALSE;
            }

            if (CheckIsNum(szBuffer[i]))
            {
                *pValue = szBuffer[i];
                pValue++;
                bValue = TRUE;
            }
            else
            {
                delete[] szBuffer;
                return FALSE;
            }
        }
    }

    delete[] szBuffer;
    return TRUE;
}

BOOL ConvertTextToHex(char* pBuffer, DWORD dwBufferLen, char* pData, DWORD* pDataLen)
{
    if (pBuffer == NULL || pData == NULL || pDataLen == NULL)
    {
        return FALSE;
    }

    char* szHexMap = "0123456789ABCDEF";

    int index = 0;
    
    for (int i = 1; i <= dwBufferLen; i++)
    {
        BYTE byData = (BYTE)(pBuffer + i - 1);
        BYTE byHigh = byData / 16;
        BYTE byLow  = byData % 16;

        pData[index++] = szHexMap[byHigh];
        pData[index++] = szHexMap[byLow];

        pData[index++] = ' ';

        if (i % 15 == 0)
        {
            pData[index++] = '\r';
            pData[index++] = '\n'; 
        }
        else if (i % 8 == 0)
        {
            pData[index++] = '  ';    
        }
        else if (i % 4 == 0)
        {
            pData[index++] = ' ';    
        }
    }

    *pDataLen = index;
    
    return TRUE;
}


BOOL ConvertHexBufToByteBuf(char* pBuffer, DWORD dwBufferLen, BYTE* pData, DWORD* pDataLen)
{
    if (pBuffer == NULL || pDataLen == NULL)
    {
        return FALSE;
    }
    
    char szValue[3] = {0};
    char *pValue = &szValue[0];
    BOOL bValue = FALSE;
    BYTE byValue = 0;
    for (DWORD i = 0; i < dwBufferLen; i++)
    {
        if (pBuffer[i] == ' ' || pBuffer[i] == '\0')
        {
            if (bValue)
            {
                byValue = NumToByte(szValue, strlen(szValue));
                *pData = byValue;
                pData++;
                *pDataLen += 1;
                
                memset(szValue, 0, sizeof(szValue));
                pValue = &szValue[0];
                
                bValue = FALSE;
            }
            else
            {
                continue;
            }
        }
        else if (pBuffer[i] == '\t' || pBuffer[i] == '\r'|| pBuffer[i] == '\n')
        {
            continue;
        }
        else
        {
            if (strlen(szValue) > 2)
            {
                return FALSE;
            }
            
            if (CheckIsNum(pBuffer[i]))
            {
                *pValue = pBuffer[i];
                pValue++;
                bValue = TRUE;
            }
            else
            {
                return FALSE;
            }
        }
    }
    
    return TRUE;
}

void g_StringLanType(char *szDstLan, char *szLanCn, char *szLanEn)
{
#ifdef SWITCH_ENGLISH_US
    sprintf(szDstLan, "%s", szLanCn);
#else	
    sprintf(szDstLan, "%s", szLanEn);
#endif
    return;
    WORD wLangID = (WORD)(PRIMARYLANGID(::GetSystemDefaultLangID()));
    switch (wLangID)
    {
    case LANG_ENGLISH:
        sprintf(szDstLan, "%s", szLanEn);
        break;
    case LANG_CHINESE:
        sprintf(szDstLan, "%s", szLanCn);
        break;
    default:
        sprintf(szDstLan, "%s", szLanEn);
        break;
    }
}

