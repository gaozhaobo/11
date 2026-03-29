// DlgHealthCode.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgHealthCode.h"
#include "afxdialogex.h"
#include "HCUsbSDK.h"


// CDlgHealthCode 对话框

IMPLEMENT_DYNAMIC(CDlgHealthCode, CDialog)

CDlgHealthCode::CDlgHealthCode(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHealthCode::IDD, pParent)
{

}

CDlgHealthCode::~CDlgHealthCode()
{
    if (m_pInBuf != NULL)
    {
        delete[]m_pInBuf;
        m_pInBuf = NULL;
    }
    if (m_pOutBuf != NULL)
    {
        delete[]m_pOutBuf;
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

void CDlgHealthCode::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_EDIT_HEALTH_CODE_SERVER_ADDRESS, m_editServerAddress);
    DDX_Control(pDX, IDC_CHECK_HEALTH_CODE_ENABLE, m_checkEnable);
    DDX_Control(pDX, IDC_EDIT_QUERY_UUID, m_editQueryUUID);
    DDX_Control(pDX, IDC_EDIT_HEALTH_CODE, m_editHealthCode);
    DDX_Control(pDX, IDC_EDIT_HEALTH_CODE_RESULT, m_editHealthCodeResult);
}


BEGIN_MESSAGE_MAP(CDlgHealthCode, CDialog)
    ON_BN_CLICKED(IDC_BTN_GET_HEALTH_CODE_CFG, &CDlgHealthCode::OnBnClickedBtnGetHealthCodeCfg)
    ON_BN_CLICKED(IDC_BTN_SET_HEALTH_CODE_CFG, &CDlgHealthCode::OnBnClickedBtnSetHealthCodeCfg)
    ON_BN_CLICKED(IDC_BTN_GET_HEALTH_CODE, &CDlgHealthCode::OnBnClickedBtnGetHealthCode)
    ON_BN_CLICKED(IDC_BTN_SET_HEALTH_CODE_RESULT, &CDlgHealthCode::OnBnClickedBtnSetHealthCodeResult)
END_MESSAGE_MAP()


// CDlgHealthCode 消息处理程序

BOOL CDlgHealthCode::OnInitDialog()
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
    //GetModuleFileName(NULL, m_szExePath, MAX_PATH);
    //char *pTemp = strrchr(m_szExePath, '\\');
    //if (pTemp != NULL)
    //{
    //    memset(pTemp, 0, 1);
    //}
    //char szFilePath[MAX_PATH] = { 0 };
    //sprintf_s(szFilePath, "%s\\%s", m_szExePath, DATA_INFO_FILE_PATH);
    //if (!PathIsDirectory(szFilePath))  // 是否有重名文件夹
    //{
    //    if (!CreateDirectory(szFilePath, NULL))
    //    {
    //        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d],CDlgOfflineCapture::OnInitDialog Create directory failed.", GetLastError());
    //    }
    //}
    GetAccessControlCapabilities();

    UpdateData(FALSE);
    char szInput[1024] = { 0 };
    strcpy(szInput, "{\r\n"
        "\"queryUUID\": \"test\",\r\n"
        "\"checkResult\":\"success\",\r\n"
        "\"healthCode\":1,\r\n"
        "\"NADCode\":1,\r\n"
        "\"travelCode\":1,\r\n"
        "\"travelInfo\":\"test\",\r\n"
        "\"vaccineStatus\":1,\r\n"
        "\"vaccineNum\":1,\r\n"
        "\"healthMessage\":\"test\"\r\n"
        "}\r\n");
    m_editHealthCodeResult.SetWindowText(szInput);
    return TRUE;
}

void CDlgHealthCode::GetAccessControlCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/capabilities";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pInBuffer = NULL;                             //输入数据
    struPtParam.dwInSize = 0;                                 //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                       //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                    //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SDK_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("获取门禁总能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取门禁总能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取门禁总能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SDK_TransConfig() %s", strRequest.GetBuffer());
    CXmlBase xmlBase;
    xmlBase.Parse(m_pOutBuf);
    if (xmlBase.Error())
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "%s Parse fail.", strRequest.GetBuffer());
        MessageBox("获取门禁总能力失败");
        return;
    }
    if (xmlBase.FindElem("AccessControl") && xmlBase.IntoElem())
    {
        if (xmlBase.FindElem("isSupportCaptureHealthCode"))
        {
            m_bIsSupportCaptureHealthCode = true;
        }
        if (xmlBase.FindElem("isSupportHealthCodeCfg"))
        {
            m_bIsSupportHealthCodeCfg = true;
        }
        if (xmlBase.FindElem("isSupportHealthInfoResult"))
        {
            m_bIsSupportHealthInfoResult = true;
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse capabilities.", strRequest.GetBuffer());
}

bool CDlgHealthCode::ParseResponseStatus(string &strLogInfo, bool &bResponseStatus)
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


void CDlgHealthCode::OnBnClickedBtnGetHealthCodeCfg()
{
    // TODO:  在此添加控件通知处理程序代码
    GetAccessControlHealthCodeCfgCapabilities(); //字段取值范围，没啥作用，内部没有解析
    
    if (m_bIsSupportHealthCodeCfg == false)
    {
        MessageBox("不支持健康码配置");
        return;
    }

    CString strRequest = "GET /ISAPI/AccessControl/healthCodeCfg?format=json";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pOutBuffer = m_pOutBuf;                       //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                    //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SDK_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("获取健康码配置失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取健康码配置失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取健康码配置失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SDK_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "%s Parse fail.", strRequest.GetBuffer());
        MessageBox("获取健康码配置失败");
        return;
    }

    cJSON *pEnabledNode = cJSON_GetObjectItem(pRoot, "enabled");
    if (pEnabledNode != NULL && pEnabledNode->type == cJSON_True)
    {
        m_checkEnable.SetCheck(BST_CHECKED);
    }
    else
    {
        m_checkEnable.SetCheck(BST_UNCHECKED);
    }

    cJSON *pServerAddressNode = cJSON_GetObjectItem(pRoot, "serverAddress");
    if (pServerAddressNode != NULL && pEnabledNode->type == cJSON_String)
    {
        m_editServerAddress.SetWindowTextA(pEnabledNode->string);
    }
    else
    {
        m_editServerAddress.SetWindowTextA("");
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS GET /ISAPI/AccessControl/healthCodeCfg");
}

void CDlgHealthCode::OnBnClickedBtnSetHealthCodeCfg()
{
    // TODO:  在此添加控件通知处理程序代码
    GetAccessControlHealthCodeCfgCapabilities(); //字段取值范围，没啥作用，内部没有解析

    if (m_bIsSupportHealthCodeCfg == false)
    {
        MessageBox("不支持健康码配置");
        return;
    }

    CString szServerAddress;
    m_editServerAddress.GetWindowTextA(szServerAddress);

    CString strRequest = "PUT /ISAPI/AccessControl/CapturePresetParam?format=json";
    memset(m_pInBuf, 0, m_dwMaxBufLen);

    if (m_checkEnable.GetCheck())
    {
        sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "{\r\n"
            "\"enabled\": %s"
            "\"serverAddress\": \"%s\"\r\n"
            "}\r\n", "true", szServerAddress);
    }
    else
    {
        sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "{\r\n"
            "\"enabled\": %s"
            "\"serverAddress\": \"%s\"\r\n"
            "}\r\n", "false", szServerAddress);
    }

    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();       //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();   //请求URL长度
    struPtParam.pInBuffer = m_pInBuf;                        //输入数据
    struPtParam.dwInSize = strlen(m_pInBuf);                 //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (!ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return;
    }
    if (!bResponseStatus)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return;
    }
    else
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s", strLogInfo.c_str());
        return;
    }
}

void CDlgHealthCode::GetAccessControlHealthCodeCfgCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/healthCodeCfg/capabilities?format=json";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pOutBuffer = m_pOutBuf;                       //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                    //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SDK_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("获取健康码配置能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取健康码配置能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取健康码配置能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SDK_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "%s Parse fail.", strRequest.GetBuffer());
        MessageBox("获取健康码配置能力失败");
        return;
    }
    //cJSON *pOfflineCaptureCapNode = cJSON_GetObjectItem(pRoot, "OfflineCaptureCap");
    //if (pOfflineCaptureCapNode != NULL)
    //{
    //    cJSON *pisSuportDownloadOfflineCaptureInfoTemplateNode = cJSON_GetObjectItem(pRoot, "isSuportDownloadOfflineCaptureInfoTemplate");
    //    if (pisSuportDownloadOfflineCaptureInfoTemplateNode != NULL && pisSuportDownloadOfflineCaptureInfoTemplateNode->type == cJSON_True)
    //    {
    //        m_bIsSuportDownloadOfflineCaptureInfoTemplate = true;
    //    }
    //}
    //else
    //{
    //    LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
    //    return;
    //}
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse capabilities.", strRequest.GetBuffer());
}


void CDlgHealthCode::OnBnClickedBtnGetHealthCode()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_bIsSupportCaptureHealthCode == false)
    {
        MessageBox("不支持采集健康码");
        return;
    }

    CString strRequest = "GET /ISAPI/AccessControl/CaptureHealthCode?format=json";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pOutBuffer = m_pOutBuf;                       //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                    //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SDK_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("获取健康码失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取健康码失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取健康码失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SDK_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "%s Parse fail.", strRequest.GetBuffer());
        MessageBox("获取健康码失败");
        return;
    }

    cJSON *pQueryUUIDNode = cJSON_GetObjectItem(pRoot, "queryUUID");
    if (pQueryUUIDNode != NULL && pQueryUUIDNode->type == cJSON_String)
    {
        m_editQueryUUID.SetWindowTextA(pQueryUUIDNode->string);
    }
    else
    {
        m_editQueryUUID.SetWindowTextA("");
    }

    cJSON *pHealthCodeNode = cJSON_GetObjectItem(pRoot, "healthCode");
    if (pHealthCodeNode != NULL && pHealthCodeNode->type == cJSON_String)
    {
        m_editHealthCode.SetWindowTextA(pHealthCodeNode->string);
    }
    else
    {
        m_editHealthCode.SetWindowTextA("");
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS GET /ISAPI/AccessControl/CaptureHealthCode");
}


void CDlgHealthCode::OnBnClickedBtnSetHealthCodeResult()
{
    // TODO:  在此添加控件通知处理程序代码

    if (m_bIsSupportCaptureHealthCode == false)
    {
        MessageBox("不支持健康码");
        return;
    }

    CString szServerAddress;
    m_editServerAddress.GetWindowTextA(szServerAddress);

    CString strRequest = "PUT /ISAPI/AccessControl/CapturePresetParam?format=json";
    memset(m_pInBuf, 0, m_dwMaxBufLen);
    CString strResult;
    m_editHealthCodeResult.GetWindowText(strResult);
    strncpy(m_pInBuf, strResult.GetBuffer(), sizeof(m_pInBuf) - 1);

    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();       //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();   //请求URL长度
    struPtParam.pInBuffer = m_pInBuf;                        //输入数据
    struPtParam.dwInSize = strlen(m_pInBuf);                 //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (!ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return;
    }
    if (!bResponseStatus)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return;
    }
    else
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s", strLogInfo.c_str());
        return;
    }
}
