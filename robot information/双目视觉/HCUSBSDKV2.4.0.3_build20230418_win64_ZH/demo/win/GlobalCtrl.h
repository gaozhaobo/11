#ifndef __GLOBAL_CTRL_H__
#define __GLOBAL_CTRL_H__


#pragma once

#include "HCUsbSDK.h"

#include <ASSERT.H>

#define WM_ADD_LOG			WM_USER + 1 	//add log 

#define LOG_SNPRINTF		_snprintf
#define LOG_VSNPRINTF		_vsnprintf

#define MAX_PRINT_BYTES		1024				//一次打印最大字节数

#define DISABLE_LEVEL   0
#define ERR_LEVEL       1
#define DBG_LEVEL       2
#define INF_LEVEL       3

#define DLL_DECLARE_PREFIXNAME(api, ret, prefixname, name, args)    \
    typedef ret (api * __dll_##name##_t)args;                       \
static __dll_##name##_t prefixname = NULL

#define DLL_DECLARE_PREFIXNAME_NO_STATIC(api, ret, prefixname, name, args)    \
    typedef ret (api * __dll_##name##_t)args;                       \
__dll_##name##_t prefixname = NULL

#ifndef _WIN32_WCE
#define DLL_STRINGIFY(dll) #dll
#define DLL_GET_MODULE_HANDLE(dll) GetModuleHandleA(DLL_STRINGIFY(dll))
#define DLL_LOAD_LIBRARY(dll) LoadLibraryA(DLL_STRINGIFY(dll))
#else
#define DLL_STRINGIFY(dll) L#dll
#define DLL_GET_MODULE_HANDLE(dll) GetModuleHandle(DLL_STRINGIFY(dll))
#define DLL_LOAD_LIBRARY(dll) LoadLibrary(DLL_STRINGIFY(dll))
#endif

#define DLL_LOAD_PREFIXNAME(dll, prefixname, name, ret_on_failure) \
    do {                                                           \
    HMODULE h = DLL_GET_MODULE_HANDLE(dll);                        \
    if (!h)                                                        \
    h = DLL_LOAD_LIBRARY(dll);                                     \
    if (!h) {                                                      \
    return ret_on_failure;                                         \
    }                                                              \
    prefixname = (__dll_##name##_t)GetProcAddress(h,               \
    DLL_STRINGIFY(name));                  \
    if (prefixname) break;                                         \
    prefixname = (__dll_##name##_t)GetProcAddress(h,               \
    DLL_STRINGIFY(name) DLL_STRINGIFY(A)); \
    if (prefixname) break;                                         \
    prefixname = (__dll_##name##_t)GetProcAddress(h,               \
    DLL_STRINGIFY(name) DLL_STRINGIFY(W)); \
    if (prefixname) break;                                         \
    } while(0)

#define DLL_DECLARE(api, ret, name, args)   DLL_DECLARE_PREFIXNAME(api, ret, name, name, args)

#define DLL_LOAD(dll, name, ret_on_failure) DLL_LOAD_PREFIXNAME(dll, name, name, ret_on_failure)
#define DLL_DECLARE_PREFIXED(api, ret, prefix, name, args)   DLL_DECLARE_PREFIXNAME(api, ret, prefix##name, name, args)
#define DLL_LOAD_PREFIXED(dll, prefix, name, ret_on_failure) DLL_LOAD_PREFIXNAME(dll, prefix##name, name, ret_on_failure)


//the structure of the log information
typedef struct tagLOCAL_LOG_INFO 
{
    int  iLogType;
    char szTime[64];
    char szLogInfo[512];
    tagLOCAL_LOG_INFO ()
    {
        iLogType = 0;
        szTime[0] = '\0';
        szLogInfo[0] = '\0';
    }
} LOCAL_LOG_INFO, *LPLOCAL_LOG_INFO;


//日志级别名称字符串
static const char *gLEVEL_TEXT[4] = {"DISABLE", "ERR", "DBG", "INF"};

class LogInfo
{
public:
    //static CEdit  *s_pEdit;

    static CListCtrl* s_pListLog;
    static CDialog  * s_pDlg;

    LogInfo(){m_nLogIndex = 0;};

    ~LogInfo(){};

    static LogInfo* GetInstance()
    {
        if (s_pInstance == NULL)
        {
            s_pInstance = new LogInfo();
        }
        return s_pInstance;
    }

    static void Destroy()
    {
        if (s_pInstance != NULL)
        {
            delete s_pInstance;
            s_pInstance = NULL;
        }
    }

    int WriteLog(DWORD level, char const *content, ...)
    {
        LOCAL_LOG_INFO* pLogInfo = new LOCAL_LOG_INFO;
        memset(pLogInfo, 0, sizeof(LOCAL_LOG_INFO));

        if (pLogInfo == NULL)
        {
            return -3;
		}

        pLogInfo->iLogType = level;

        int length = 0;
        
        va_list args;
        va_start(args, content);
        int valen = LOG_VSNPRINTF(pLogInfo->szLogInfo + length, (sizeof(pLogInfo->szLogInfo) - 1) - (unsigned int)length, content, args);
        va_end(args);
        if (valen == -1)
        {
            delete pLogInfo;
            pLogInfo = NULL;
            return -2;
        }
        length += valen;
        //最后要追加双字节换行符和结束符
        pLogInfo->szLogInfo[length ++] = '\r';
        pLogInfo->szLogInfo[length ++] = '\n';
	    pLogInfo->szLogInfo[length ++] = 0;

        FormatTime(pLogInfo->szTime, 64);

        //::PostMessage(s_pDlg->m_hWnd, WM_ADD_LOG, level, (LONG)pLogInfo);

        //::SendMessage(s_pDlg->m_hWnd, WM_ADD_LOG, level, (LONG)pLogInfo);

        if (s_pListLog->GetItemCount() >= 1024)
        {
            s_pListLog->DeleteAllItems();
        }
        
        CString csInfoTemp;
        
        csInfoTemp.Format("%d", m_nLogIndex);
        
        int nRow = s_pListLog->InsertItem(m_nLogIndex, csInfoTemp);//插入行
        
        csInfoTemp = pLogInfo->szTime;
        
        s_pListLog->SetItemText(nRow, 1, csInfoTemp);
        
        csInfoTemp = gLEVEL_TEXT[pLogInfo->iLogType];
        s_pListLog->SetItemText(nRow, 2, csInfoTemp);
        
        csInfoTemp = pLogInfo->szLogInfo;
        s_pListLog->SetItemText(nRow, 3, csInfoTemp);
        
        int nCount =s_pListLog->GetItemCount();
        if (nCount > 0)
        {
            s_pListLog->EnsureVisible(nCount-1, FALSE); 
        }
        
        if (pLogInfo != NULL)
        {
            delete pLogInfo;
            pLogInfo = NULL;
        }
        
        m_nLogIndex++;
        
        return 0;
    }

    void CleanLog()
    {
        if (s_pListLog != NULL)
        {
            m_nLogIndex = 0;
            s_pListLog->DeleteAllItems();
        }
    }

    /*
    void PrintData(char* pBuffer, const DWORD dwSize)
    {
        if (s_pEdit != NULL)
        {
            CString csTemp;
            CString csInfo;
            
            csInfo = _T("");
            
            for (DWORD i = 1; i < dwSize+1; i++)
            {
                csTemp.Format("%02X", (unsigned char)pBuffer[i-1]);
                if (i % 16 == 0)
                {
                    csInfo += csTemp + _T("     ");
                }
                else if(i % 8 == 0)
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
                
                if (i % 32 == 0)
                {
                    csInfo += _T("\r\n");
                    s_pEdit->SetSel(-1);
                    s_pEdit->ReplaceSel(csInfo);
                    csInfo = _T("");
                }
            }
            if (csInfo.GetLength() != 0)
            {
                csInfo += _T("\r\n");
                s_pEdit->SetSel(-1);
                s_pEdit->ReplaceSel(csInfo);
                csInfo = _T("");
            }
        }
    }
    */

private:

    int FormatTime(char *buffer, unsigned int size)
    {
        SYSTEMTIME  SysTime;
        GetLocalTime(&SysTime);
        return LOG_SNPRINTF(buffer, size, "[%02u:%02u:%02u.%03u]"\
            , SysTime.wHour, SysTime.wMinute, SysTime.wSecond, SysTime.wMilliseconds
		    );
    }

    int m_nLogIndex;

    
    static LogInfo *s_pInstance;

};

#define LOGIN_INFO LogInfo::GetInstance()

#define CSTRING_TO_CHARS(str,sz) memcpy((sz),str.GetBuffer(str.GetLength()),str.GetLength())

//将文本转换成16进制输出
BOOL ConvertTextToHex(char* pBuffer, DWORD dwBufferLen, char* pData, DWORD* pDataLen);


BOOL ConvertHexBufToByteBuf(char* pBuffer, DWORD dwBufferLen, BYTE* pData, DWORD* pDataLen);

BOOL ConvertHexBufContToByteBuf(char* pBuffer, DWORD dwBufferLen, BYTE* pData, DWORD* pDataLen);

void g_StringLanType(char *szDstLan, char *szLanCn, char *szLanEn);

#endif