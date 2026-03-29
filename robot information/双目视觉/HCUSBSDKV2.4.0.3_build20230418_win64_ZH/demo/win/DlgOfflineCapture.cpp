// DlgOfflineCapture.cpp : 实现文件
//

#include "stdafx.h"
#include "ClientDemo.h"
#include "DlgOfflineCapture.h"
#include "afxdialogex.h"
#include "xml/XmlBase.h"
#include "HCUsbSDK.h"

// CDlgOfflineCapture 对话框

IMPLEMENT_DYNAMIC(CDlgOfflineCapture, CDialog)

#define DATA_INFO_FILE_PATH "dataInfo"

CDlgOfflineCapture::CDlgOfflineCapture(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOfflineCapture::IDD, pParent)
    , m_lUserID(USB_INVALID_USERID)
    , m_pInBuf(NULL)
    , m_pOutBuf(NULL)
    , m_bIsSupportOfflineCapture(false)
{
    memset(m_szExePath, 0, MAX_PATH);
}

CDlgOfflineCapture::~CDlgOfflineCapture()
{
    if (m_pInBuf!=NULL)
    {
        delete[]m_pInBuf;
        m_pInBuf = NULL;
    }

    if (m_pOutBuf!=NULL)
    {
        delete []m_pOutBuf;
        m_pOutBuf = NULL;
    }

    if (m_pDataBuf1 != NULL)
    {
        delete[]m_pDataBuf1;
        m_pDataBuf1 = NULL;
    }

    if (m_pDataBuf2 != NULL)
    {
        delete[]m_pDataBuf2;
        m_pDataBuf2 = NULL;
    }
}

void CDlgOfflineCapture::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BOOL CDlgOfflineCapture::OnInitDialog()
{
    if (m_lUserID == USB_INVALID_USERID)
    {
        MessageBox("请先登录");
        return TRUE;
    }
    m_pInBuf = new(std::nothrow) char[m_dwMaxBufLen];
    m_pOutBuf = new(std::nothrow) char[m_dwMaxBufLen];
    m_pDataBuf1 = new(std::nothrow) char[m_dwMaxBufLen];;
    m_pDataBuf2 = new(std::nothrow) char[m_dwMaxBufLen];;
    if (m_pOutBuf == NULL || m_pInBuf == NULL || m_pDataBuf1 == NULL || m_pDataBuf2 == NULL)
    {
        MessageBox("系统资源不足");
        return FALSE;
    }
    GetModuleFileName(NULL, m_szExePath, MAX_PATH);
    char *pTemp = strrchr(m_szExePath, '\\');
    if (pTemp != NULL)
    {
        memset(pTemp, 0, 1);
    }
    char szFilePath[MAX_PATH] = { 0 };
    sprintf_s(szFilePath, "%s\\%s", m_szExePath, DATA_INFO_FILE_PATH);
    if (!PathIsDirectory(szFilePath))  // 是否有重名文件夹
    {
        if (!CreateDirectory(szFilePath, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d],CDlgOfflineCapture::OnInitDialog Create directory failed.", GetLastError());
        }
    }
    GetAccessControlCapabilities();

    return TRUE;
}

bool CDlgOfflineCapture::ParseResponseStatus(string &strLogInfo, bool &bResponseStatus)
{
    if (strlen(m_pOutBuf) == 0)
    {
        return false;
    }
    CXmlBase xmlBase;
    xmlBase.Parse(m_pOutBuf);
    if (!xmlBase.Error())
    {
        if (xmlBase.FindElem("ResponseStatus") && xmlBase.IntoElem())
        {
            if (xmlBase.FindElem("statusCode"))
            {
                strLogInfo.assign("statusCode[");
                strLogInfo = strLogInfo + xmlBase.GetData() + "]";
                if (xmlBase.GetData() == "0" || xmlBase.GetData() == "1")
                {
                    //成功无需进一步解析
                    bResponseStatus = true;
                    return true;
                }
            }
            if (xmlBase.FindElem("statusString"))
            {
                strLogInfo = strLogInfo + ", statusString[";
                strLogInfo = strLogInfo + xmlBase.GetData() + "]";
            }
            if (xmlBase.FindElem("subStatusCode"))
            {
                strLogInfo = strLogInfo + ", subStatusCode[";
                strLogInfo = strLogInfo + xmlBase.GetData() + "]";
            }
            bResponseStatus = false;
            return true;
        }
        else
        {
            //说明返回的不是状态
            return false;
        }
    }
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        return false;
    }
    cJSON *pstatusCode = cJSON_GetObjectItem(pRoot, "statusCode");
    if (pstatusCode != NULL)
    {
        char szBuf[128] = { 0 };
        itoa(pstatusCode->valueint, szBuf, 10);
        strLogInfo = "statusCode[";
        strLogInfo = strLogInfo + szBuf + "]";
        if (pstatusCode->valueint == 1)
        {
            //成功无需进一步解析
            cJSON_Delete(pRoot);
            bResponseStatus = true;
            return true;
        }
    }
    else
    {
        //说明返回的不是状态
        cJSON_Delete(pRoot);
        return false;
    }
    cJSON *pstatusString = cJSON_GetObjectItem(pRoot, "statusString");
    if (pstatusString != NULL && pstatusString->valuestring != NULL)
    {
        strLogInfo = strLogInfo + ", statusString[" + pstatusString->valuestring + "]";
    }
    cJSON *psubStatusCode = cJSON_GetObjectItem(pRoot, "subStatusCode");
    if (psubStatusCode != NULL && psubStatusCode->valuestring != NULL)
    {
        strLogInfo = strLogInfo + ", subStatusCode[" + psubStatusCode->valuestring + "]";
    }
    cJSON *perrorCode = cJSON_GetObjectItem(pRoot, "errorCode");
    if (perrorCode != NULL)
    {
        char szBuf[128] = { 0 };
        itoa(perrorCode->valueint, szBuf, 10);
        strLogInfo = strLogInfo + ", errorCode[" + szBuf + "]";
    }
    cJSON *perrorMsg = cJSON_GetObjectItem(pRoot, "errorMsg");
    if (perrorMsg != NULL && perrorMsg->valuestring != NULL)
    {
        strLogInfo = strLogInfo + ", errorMsg[" + perrorMsg->valuestring + "]";
    }
    cJSON_Delete(pRoot);
    bResponseStatus = false;
    return true;
}

void CDlgOfflineCapture::GetAccessControlCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/capabilities";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pInBuffer = NULL;                        //输入数据
    struPtParam.dwInSize = 0;                            //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        if (g_bEnglish)
        {
            MessageBox("Get capabilities failed");
        }
        else
        {
            MessageBox("获取门禁总能力失败");
        }
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        if (g_bEnglish)
        {
            MessageBox("Get capabilities failed");
        }
        else
        {
            MessageBox("获取门禁总能力失败");
        }
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        if (g_bEnglish)
        {
            MessageBox("Get capabilities failed");
        }
        else
        {
            MessageBox("获取门禁总能力失败");
        }
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    CXmlBase xmlBase;
    xmlBase.Parse(m_pOutBuf);
    if (xmlBase.Error())
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "%s Parse fail.", strRequest.GetBuffer());
        if (g_bEnglish)
        {
            MessageBox("Get capabilities failed");
        }
        else
        {
            MessageBox("获取门禁总能力失败");
        }
        return;
    }
    if (xmlBase.FindElem("AccessControl") && xmlBase.IntoElem())
    {
        if (xmlBase.FindElem("isSupportOfflineCapture"))
        {
            m_bIsSupportOfflineCapture = true;
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse capabilities.", strRequest.GetBuffer());
}

void CDlgOfflineCapture::GetAccessControlOfflineCaptureCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/OfflineCapture/capabilities?format=json";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("获取离线采集能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取离线采集能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取离线采集能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "%s Parse fail.", strRequest.GetBuffer());
        MessageBox("获取离线采集能力失败");
        return;
    }
    cJSON *pOfflineCaptureCapNode = cJSON_GetObjectItem(pRoot, "OfflineCaptureCap");
    if (pOfflineCaptureCapNode != NULL)
    {
        cJSON *pisSuportDownloadOfflineCaptureInfoTemplateNode = cJSON_GetObjectItem(pRoot, "isSuportDownloadOfflineCaptureInfoTemplate");
        if (pisSuportDownloadOfflineCaptureInfoTemplateNode != NULL && pisSuportDownloadOfflineCaptureInfoTemplateNode->type == cJSON_True)
        {
            m_bIsSuportDownloadOfflineCaptureInfoTemplate = true;
        }
        cJSON *pisSuportUploadOfflineCaptureInfoNode = cJSON_GetObjectItem(pRoot, "isSuportUploadOfflineCaptureInfo");
        if (pisSuportUploadOfflineCaptureInfoNode != NULL && pisSuportUploadOfflineCaptureInfoNode->type == cJSON_True)
        {
            m_bIsSuportUploadOfflineCaptureInfo = true;
        }
        cJSON *pisSupportDownloadCaptureDataNode = cJSON_GetObjectItem(pRoot, "isSupportDownloadCaptureData");
        if (pisSupportDownloadCaptureDataNode != NULL && pisSupportDownloadCaptureDataNode->type == cJSON_True)
        {
            m_bIsSupportDownloadCaptureData = true;
        }
        cJSON *pisSupportDeleteAllDataNode = cJSON_GetObjectItem(pRoot, "isSupportDeleteAllData");
        if (pisSupportDeleteAllDataNode != NULL && pisSupportDeleteAllDataNode->type == cJSON_True)
        {
            m_bIsSupportDeleteAllData = true;
        }
        cJSON *pisSupportDeleteTheDataNode = cJSON_GetObjectItem(pRoot, "isSupportDeleteTheData");
        if (pisSupportDeleteTheDataNode != NULL && pisSupportDeleteTheDataNode->type == cJSON_True)
        {
            m_bIsSupportDeleteTheData = true;
        }
        cJSON *pSearchTaskNode = cJSON_GetObjectItem(pRoot, "SearchTask");
        if (pSearchTaskNode != NULL && pSearchTaskNode->type == cJSON_True)
        {
            m_bIsSupportSearchTask = true;
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse capabilities.", strRequest.GetBuffer());
}

void CDlgOfflineCapture::CurrentTimeToString(char *pTimeBuf, const int iBufLen)
{
    //获取系统时间
    time_t rawtime;
    struct tm *ptminfo;
    time(&rawtime);
    ptminfo = localtime(&rawtime);
    sprintf_s(pTimeBuf, iBufLen - 1, "%04d%02d%02d%02d%02d%02d",
        ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
        ptminfo->tm_hour, ptminfo->tm_min, ptminfo->tm_sec);
}

bool CDlgOfflineCapture::SaveData(const char *pFilePath, const char *pFileName, const void *pContent, const unsigned int dwLength)
{
    char szFileName[MAX_PATH] = { 0 };
    sprintf_s(szFileName, "%s\\%s", pFilePath, pFileName);
    HANDLE hFile = CreateFile(szFileName, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOfflineCapture::SaveData CreateFile failed.", GetLastError());
        CloseHandle(hFile);
        return false;
    }
    DWORD dwBytesWritten = 0;
    if (!WriteFile(hFile, pContent, dwLength, &dwBytesWritten, NULL))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOfflineCapture::SaveData WriteFile failed.", GetLastError());
        CloseHandle(hFile);
        return false;
    }
    CloseHandle(hFile);
    return true;
}

void CDlgOfflineCapture::PostAccessControlOfflineCaptureInfoFileTemplateDownload()
{
    CString strRequest = "POST /ISAPI/AccessControl/OfflineCapture/InfoFileTemplateDownload?format=json";
    memset(m_pInBuf, 0, m_dwMaxBufLen);
    memset(m_pOutBuf, 0, m_dwMaxBufLen);
    sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "{\r\n"
        "\"InfoFileTemplateCond\": {\r\n"
        "\"dataType\": \"binary\",\r\n"
        "}\r\n"
        "}\r\n");

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pInBuffer = m_pInBuf;                        //输入数据
    struPtParam.dwInSize = strlen(m_pInBuf);                 //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 


    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("离线采集用户列表模板下载失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("离线采集用户列表模板下载失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("离线采集用户列表模板下载失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    
    //解析获取的数据
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("离线采集用户列表模板下载失败");
        return;
    }
    cJSON_Delete(pRoot);
    if (1)
    {
        //创建文件夹
        char szCurrtenTime[128] = { 0 };
        CurrentTimeToString(szCurrtenTime, sizeof(szCurrtenTime));
        char szInfoFileTemplate[MAX_PATH] = { 0 };
        sprintf_s(szInfoFileTemplate, "%s\\%s\\InfoFileTemplate[%s]", m_szExePath, DATA_INFO_FILE_PATH, szCurrtenTime);
        if (!PathIsDirectory(szInfoFileTemplate))  // 是否有重名文件夹
        {
            if (!CreateDirectory(szInfoFileTemplate, NULL))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOfflineCapture::PostAccessControlOfflineCaptureInfoFileTemplateDownload Create directory failed.", GetLastError());
                MessageBox("保存模板失败");
                return;
            }
        }
        if (SaveData(szInfoFileTemplate, "infoFileTemplate.jpg", NULL, 0))
        {
            ShellExecute(NULL, _T("open"), _T(szInfoFileTemplate), NULL, NULL, SW_SHOWNORMAL);
        }
        else
        {
            MessageBox("保存模板失败");
            return;
        }
    }
    else
    {
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("没有模板数据");
    }
}

void CDlgOfflineCapture::PostAccessControlOfflineCaptureInfoFile()
{

}

void CDlgOfflineCapture::GetAccessControlOfflineCaptureRuleInfo()
{

    CString strRequest = "GET /ISAPI/AccessControl/CaptureRule/capabilities?format=json";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("获取离线采集规则失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取离线采集规则失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取离线采集规则失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("获取离线采集规则失败");
        return;
    }
    cJSON *pRuleInfoNode = cJSON_GetObjectItem(pRoot, "RuleInfo");
    if (pRuleInfoNode!=NULL)
    {
        cJSON *pReqAdminRightsNode = cJSON_GetObjectItem(pRuleInfoNode, "reqAdminRights");
        if (pReqAdminRightsNode!=NULL)
        {
            if (pReqAdminRightsNode->type==cJSON_True)
            {
            }
            else if (pReqAdminRightsNode->type == cJSON_False)
            {
            }
        }
        cJSON *pEnableCardNoLenAutoNode = cJSON_GetObjectItem(pRuleInfoNode, "enableCardNoLenAuto");
        if (pEnableCardNoLenAutoNode!=NULL)
        {
            if (pEnableCardNoLenAutoNode->type == cJSON_True)
            {
            }
            else if (pEnableCardNoLenAutoNode->type == cJSON_False)
            {
            }
        }
        cJSON *pRuleListNode = cJSON_GetObjectItem(pRuleInfoNode, "RuleList");
        if (pRuleListNode!=NULL && pRuleListNode->type==cJSON_Array)
        {
            int iSize = cJSON_GetArraySize(pRuleListNode);
            for (int i = 0; i < iSize; i++)
            {
                cJSON *pRuleList = cJSON_GetArrayItem(pRuleListNode, iSize);
                if (pRuleList!=NULL)
                {
                    ParseRuleList(pRuleList);
                }
            }
        }
    }
    else
    {
        cJSON_Delete(pRoot);
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    cJSON_Delete(pRoot);
    return;
}

void CDlgOfflineCapture::PutAccessControlOfflineCaptureRuleInfo()
{

}

void CDlgOfflineCapture::ParseRuleList(cJSON *pList)
{
    int iIndex = -1;
    cJSON *pDataTypeNode = cJSON_GetObjectItem(pList, "dataType");
    if (pDataTypeNode != NULL && pDataTypeNode->valuestring != NULL)
    {
        if (strcmp(pDataTypeNode->valuestring, "name") == 0)
        {
            iIndex = 0;
        }
        else if (strcmp(pDataTypeNode->valuestring, "employeeNo") == 0)
        {
            iIndex = 1;
        }
        else if (strcmp(pDataTypeNode->valuestring, "IDCardNo") == 0)
        {
            iIndex = 2;
        }
        else if (strcmp(pDataTypeNode->valuestring, "IDCardSerialNo") == 0)
        {
            iIndex = 3;
        }
        else if (strcmp(pDataTypeNode->valuestring, "IDCardDetails") == 0)
        {
            iIndex = 4;
        }
        else if (strcmp(pDataTypeNode->valuestring, "card") == 0)
        {
            iIndex = 5;
        }
        else if (strcmp(pDataTypeNode->valuestring, "fingprint") == 0)
        {
            iIndex = 6;
        }
        else if (strcmp(pDataTypeNode->valuestring, "face") == 0)
        {
             iIndex = 7;
        }
        else
        {
        }
    }
    if (iIndex == -1)
    {
        return;
    }
    cJSON *penableNode = cJSON_GetObjectItem(pList, "enable");
    if (penableNode!=NULL)
    {
        CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_NAME + iIndex);
        pWnd->EnableWindow(TRUE);
        if (penableNode->type == cJSON_True)
        {
            pWnd->SetCurSel(0);
        }
        else
        {
            pWnd->SetCurSel(1);
        }
    }
    else
    {
        CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_NAME + iIndex);
        pWnd->EnableWindow(FALSE);

    }
    cJSON *puniqueCheckNode = cJSON_GetObjectItem(pList, "uniqueCheck");
    if (puniqueCheckNode != NULL)
    {
        if (puniqueCheckNode->type == cJSON_True)
        {
            if (iIndex == 0)
            {
                CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_NAMECHECK);
                pWnd->EnableWindow(TRUE);
                pWnd->SetCurSel(0);
            }
            else
            {
                CEdit *pWnd = (CEdit *)GetDlgItem(IDC_EDIT_UNQEMP + iIndex);
                if (g_bEnglish)
                {
                    pWnd->SetWindowText("yes");
                }
                else
                {
                    pWnd->SetWindowText("是");
                }
            }
        }
        else
        {
            if (iIndex == 0)
            {
                CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_NAMECHECK);
                pWnd->EnableWindow(TRUE);
                pWnd->SetCurSel(1);
            }
            else
            {
                CEdit *pWnd = (CEdit *)GetDlgItem(IDC_EDIT_UNQEMP + iIndex);
                if (g_bEnglish)
                {
                    pWnd->SetWindowText("no");
                }
                else
                {
                    pWnd->SetWindowText("否");
                }
            }
        }
    }
    else 
    {
        if (iIndex == 0)
        {
            CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_NAMECHECK);
            pWnd->EnableWindow(FALSE);
        }
        else
        {
            CEdit *pWnd = (CEdit *)GetDlgItem(IDC_EDIT_UNQEMP + iIndex);
            pWnd->SetWindowText("");
        }
    }
    cJSON *plenNode = cJSON_GetObjectItem(pList, "len");
    if (plenNode != NULL )
    {
        CEdit *pWnd = (CEdit *)GetDlgItem(IDC_EDIT_LENNAME + iIndex);
        char szBuf[128] = { 0 };
        itoa(plenNode->valueint, szBuf, 10);
        pWnd->SetWindowText(szBuf);
    }
    cJSON *pnumNode = cJSON_GetObjectItem(pList, "num");
    if (pnumNode != NULL)
    {
        if (iIndex==5)
        {
            CEdit *pWnd = (CEdit *)GetDlgItem(IDC_EDIT_NUMCARD + iIndex);
            char szBuf[128] = { 0 };
            itoa(pnumNode->valueint, szBuf, 10);
            pWnd->SetWindowText(szBuf);
        }
    }
    cJSON *pfingerprintIDsNode = cJSON_GetObjectItem(pList, "fingerprintIDs");
    if (iIndex == 6 && pfingerprintIDsNode != NULL && pfingerprintIDsNode->type == cJSON_Array)
    {
        for (int i = 0; i < 10; i++)
        {
            CButton *pWnd = (CButton *)GetDlgItem(IDC_CHECK_FINGER1 + i);
            pWnd->SetCheck(FALSE);
        }
        int iSize = cJSON_GetArraySize(pfingerprintIDsNode);
        for (int i = 0; i < iSize; i++)
        {
            cJSON *pFingerNoNode = cJSON_GetArrayItem(pfingerprintIDsNode, i);
            if (pFingerNoNode!=NULL)
            {
                if (pFingerNoNode->valueint>10 || pFingerNoNode->valueint < 0)
                {
                    return;
                }
                CButton *pWnd = (CButton *)GetDlgItem(IDC_CHECK_FINGER1 + pFingerNoNode->valueint);
                pWnd->SetCheck(TRUE);
            }
        }
    }
}

BEGIN_MESSAGE_MAP(CDlgOfflineCapture, CDialog)
    ON_BN_CLICKED(IDCANCEL, &CDlgOfflineCapture::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_BUTTON_INFOFILETEMPLATE, &CDlgOfflineCapture::OnBnClickedButtonInfofiletemplate)
    ON_BN_CLICKED(IDC_CHECK_ALLFINGERS, &CDlgOfflineCapture::OnBnClickedCheckAllfingers)
    ON_BN_CLICKED(IDC_BUTTON_RULECFG, &CDlgOfflineCapture::OnBnClickedButtonRulecfg)
    ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgOfflineCapture 消息处理程序


void CDlgOfflineCapture::OnBnClickedCancel()
{
    // TODO:  在此添加控件通知处理程序代码
    CDialog::OnCancel();
}


void CDlgOfflineCapture::OnBnClickedButtonInfofiletemplate()
{
    // TODO:  在此添加控件通知处理程序代码
    PostAccessControlOfflineCaptureInfoFileTemplateDownload();
}


void CDlgOfflineCapture::OnBnClickedCheckAllfingers()
{
    // TODO:  在此添加控件通知处理程序代码
    CButton *pWnd = (CButton *)GetDlgItem(IDC_CHECK_ALLFINGERS);
    if (pWnd->GetCheck())
    {
        for (int i = 0; i < 10; i++)
        {
            pWnd = (CButton *)GetDlgItem(IDC_CHECK_FINGER1 + i);
            pWnd->SetCheck(TRUE);
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            pWnd = (CButton *)GetDlgItem(IDC_CHECK_FINGER1 + i);
            pWnd->SetCheck(FALSE);
        }
    }
}


void CDlgOfflineCapture::OnBnClickedButtonRulecfg()
{
    // TODO:  在此添加控件通知处理程序代码

}


void CDlgOfflineCapture::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_OFFLINECAPTURE);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC2);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC3);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC4);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC5);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC6);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC7);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC8);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC9);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC10);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC11);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC120);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC130);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC140);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC150);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC160);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_STATIC170);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_BUTTON_RULECFG);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDC_BUTTON_INFOFILETEMPLATE);
    SET_CONTROL_LAN(IDD_DLG_OFFLINECAPTURE, IDCANCEL);
}
