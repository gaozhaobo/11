// DlgOnlineCollection.cpp : 实现文件
//

#include "stdafx.h"
#include "HCUsbSDK.h"
#include "ClientDemo.h"
#include "DlgOnlineCapture.h"
#include "afxdialogex.h"
#include "xml/XmlBase.h"
#include "cjson/cJSON.h"

#define DATA_INFO_FILE_PATH "dataInfo"

// CDlgOnlineCapture 对话框

IMPLEMENT_DYNAMIC(CDlgOnlineCapture, CDialog)

CDlgOnlineCapture::CDlgOnlineCapture(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOnlineCapture::IDD, pParent)
    , m_lUserID(USB_INVALID_USERID)
    , m_pInBuf(NULL)
    , m_pOutBuf(NULL)
    , m_bIsSupportCaptureCardInfo(false)
    , m_bIsSupportCaptureIDInfo(false)
    , m_bIsSupportCaptureRule(false)
    , m_bIsSupportCapturePresetParam(false)
    , m_iNameLenMin(-1)
    , m_iNameLenMax(-1)
    , m_strName((""))
    , m_bEnableCardNoLenAuto(false)
    , m_iCardTimeoutMin(-1)
    , m_iCardTimeoutMax(-1)
    , m_strCardNo(_T(""))
    , m_strCardType(_T(""))
    , m_hCaptureFaceDataProgressThread(INVALID_HANDLE_VALUE)
    , m_bCaptureInfrared(false)
    , m_dwCardTimeOut(2000)
    , m_bStopCaptureThread(false)
{
    memset(m_szExePath, 0, MAX_PATH);
    memset(m_szIDInfoDataPath, 0, MAX_PATH);
    memset(m_szFaceInfoDataPath, 0, MAX_PATH); 
    memset(m_szFingerPrintDataPath, 0, MAX_PATH);
}

CDlgOnlineCapture::~CDlgOnlineCapture()
{
    if (m_pInBuf!=NULL)
    {
        delete[]m_pInBuf;
        m_pInBuf = NULL;
    }
    if (m_pOutBuf!=NULL)
    {
        delete[]m_pOutBuf;
        m_pOutBuf = NULL;
    }
}

void CDlgOnlineCapture::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);

    DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
    DDX_Text(pDX, IDC_EDIT_CARDNO, m_strCardNo);
    DDX_Text(pDX, IDC_EDIT_CARDTYPE, m_strCardType);
    DDX_Text(pDX, IDC_EDIT_TIMEOUT, m_dwCardTimeOut);
}


BOOL CDlgOnlineCapture::OnInitDialog()
{
    if (m_lUserID == USB_INVALID_USERID)
    {
        MessageBox("请先登录");
        return TRUE;
    }
    m_pInBuf = new(std::nothrow) char[m_dwMaxBufLen];
    m_pOutBuf = new(std::nothrow) char[m_dwMaxBufLen];
    if (m_pOutBuf==NULL || m_pInBuf == NULL)
    {
        MessageBox("系统资源不足");
        return FALSE;
    }
    GetModuleFileName(NULL, m_szExePath, MAX_PATH);
    char *pTemp = strrchr(m_szExePath, '\\');
    if (pTemp!=NULL)
    {
        memset(pTemp, 0, 1);
    }
    char szFilePath[MAX_PATH] = { 0 };
    sprintf_s(szFilePath, "%s\\%s", m_szExePath, DATA_INFO_FILE_PATH);
    if (!PathIsDirectory(szFilePath))  // 是否有重名文件夹
    {
        if (!CreateDirectory(szFilePath, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d],CDlgOnlineCapture::OnInitDialog Create directory failed.", GetLastError());
        }
    }
    GetAccessControlCapabilities();
    if (m_bIsSupportCapturePresetParam)
    {
        GetAccessControlCapturePresetParamCapabilities();
        GetAccessControlCapturePresetParam();
    }
    if (m_bIsSupportCaptureRule)
    {
        GetAccessControlCaptureRuleCapabilities();
        GetAccessControlCaptureRule();
    }
    if (m_bIsSupportCaptureCardInfo)
    {
        GetAccessControlCaptureCardInfoCapabilities();
    }
    if (m_bIsSupportCaptureIDInfo)
    {
        GetAccessControlCaptureIDInfoCapabilities();
    }

    SetControls();
    SetToolTipMessage();
    UpdateData(FALSE);
    return TRUE;
}

void CDlgOnlineCapture::GetAccessControlCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/capabilities";
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
    if (ParseResponseStatus(strLogInfo,bResponseStatus))
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
    if (xmlBase.FindElem("AccessControl")&&xmlBase.IntoElem())
    {
        if (xmlBase.FindElem("isSupportCaptureCardInfo"))
        {
            m_bIsSupportCaptureCardInfo = true;
        }
        if (xmlBase.FindElem("isSupportCaptureIDInfo"))
        {
            m_bIsSupportCaptureIDInfo = true;
        }
        if (xmlBase.FindElem("isSupportCaptureRule"))
        {
            m_bIsSupportCaptureRule = true;
        }
        if (xmlBase.FindElem("isSupportCapturePresetParam"))
        {
            m_bIsSupportCapturePresetParam = true;
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse capabilities.", strRequest.GetBuffer());
}

void CDlgOnlineCapture::GetAccessControlCapturePresetParamCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/CapturePresetParam/capabilities?format=json";
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
        MessageBox("获取在线采集参数预置能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取在线采集参数预置能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取在线采集参数预置能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot==NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("获取在线采集参数预置能力失败");
        return;
    }
    cJSON *pCapturePresetCapNode = cJSON_GetObjectItem(pRoot, "CapturePresetCap");
    if (pCapturePresetCapNode!=NULL)
    {
        cJSON *pNameNode = cJSON_GetObjectItem(pCapturePresetCapNode, "name");
        if (pNameNode!=NULL)
        {
            cJSON *pMinNode = cJSON_GetObjectItem(pNameNode, "@min");
            if (pMinNode!=NULL)
            {
                m_iNameLenMin = pMinNode->valueint;
            }
            cJSON *pMaxNode = cJSON_GetObjectItem(pNameNode, "@max");
            if (pMaxNode != NULL)
            {
                m_iNameLenMax = pMaxNode->valueint;
            }
        }
    }
    cJSON_Delete(pRoot);
    if (m_iNameLenMax > m_iNameLenMin && m_iNameLenMin != -1)
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
    }
    return;
}

void CDlgOnlineCapture::GetAccessControlCaptureRuleCapabilities()
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
        MessageBox("获取在线采集规则配置能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取在线采集规则配置能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取在线采集规则配置能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("获取在线采集规则配置能力失败");
        return;
    }
    cJSON *pCaptureRuleCapNode = cJSON_GetObjectItem(pRoot, "CaptureRuleCap");
    if (pCaptureRuleCapNode != NULL)
    {
        cJSON *pEnableCardNoLenAutoNode = cJSON_GetObjectItem(pCaptureRuleCapNode, "enableCardNoLenAuto");
        if (pEnableCardNoLenAutoNode!=NULL)
        {
            m_bEnableCardNoLenAuto = true;
        }
        cJSON *pCardNoLenNode = cJSON_GetObjectItem(pCaptureRuleCapNode, "cardNoLen");
        if (pCardNoLenNode!=NULL && pCardNoLenNode->type==cJSON_Object)
        {
            cJSON *pOpt = cJSON_GetObjectItem(pCardNoLenNode, "@opt");
            if (pOpt != NULL && pOpt->type == cJSON_Array)
            {
                for (int i = 0; i < cJSON_GetArraySize(pOpt); i++)
                {
                    cJSON *pItem = cJSON_GetArrayItem(pOpt, i);
                    if (pItem != NULL)
                    {
                        m_vCardNoLen.push_back(pItem->valueint);
                    }
                }
            }
        }
        cJSON *pCardTimeoutNode = cJSON_GetObjectItem(pCaptureRuleCapNode, "cardTimeout");
        if (pCardTimeoutNode != NULL)
        {
            cJSON *pMinNode = cJSON_GetObjectItem(pCardTimeoutNode, "@min");
            if (pMinNode != NULL)
            {
                m_iCardTimeoutMin = pMinNode->valueint;
            }
            cJSON *pMaxNode = cJSON_GetObjectItem(pCardTimeoutNode, "@max");
            if (pMaxNode != NULL)
            {
                m_iCardTimeoutMax = pMaxNode->valueint;
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

void CDlgOnlineCapture::GetAccessControlCaptureCardInfoCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/CaptureCardInfo/capabilities?format=json";
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
        MessageBox("获取采集卡信息能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取采集卡信息能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取采集卡信息能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("获取采集卡信息能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    cJSON_Delete(pRoot);
    return;
}

bool CDlgOnlineCapture::GetAccessControlCapturePresetParam()
{
    CString strRequest = "GET /ISAPI/AccessControl/CapturePresetParam?format=json";
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
        MessageBox("在线采集参数获取失败");
        return false;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("在线采集参数获取失败");
        return false;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("在线采集参数获取失败");
        return false;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    //解析获取的数据
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("在线采集参数获取失败");
        return false;
    }
    cJSON *pCapturePresetNode = cJSON_GetObjectItem(pRoot, "CapturePreset");
    if (pCapturePresetNode!=NULL)
    {
        cJSON *pNameNode = cJSON_GetObjectItem(pCapturePresetNode, "name");
        if (pNameNode != NULL && pNameNode->valuestring != NULL)
        {
            m_strName = pNameNode->valuestring;
            UpdateData(FALSE);
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        cJSON_Delete(pRoot);
        MessageBox("在线采集参数获取失败");
        return false;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    cJSON_Delete(pRoot);
    return true;
}

bool CDlgOnlineCapture::PutAccessControlCapturePresetParam()
{
    CString strRequest = "PUT /ISAPI/AccessControl/CapturePresetParam?format=json";
    memset(m_pInBuf, 0, m_dwMaxBufLen);
    sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "{\r\n"
        "\"CapturePreset\": {\r\n"
        "\"name\": \"%s\"\r\n"
        "}\r\n"
        "}\r\n", m_strName.GetBuffer());

    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pInBuffer = m_pInBuf;                        //输入数据
    struPtParam.dwInSize = strlen(m_pInBuf);                    //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return false;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        return false;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (!ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return false;
    }
    if (!bResponseStatus)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return false;
    }
    else
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s", strLogInfo.c_str());
        return true;
    }
}

bool CDlgOnlineCapture::GetAccessControlCaptureRule()
{
    CString strRequest = "GET /ISAPI/AccessControl/CaptureRule?format=json";
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
        MessageBox("在线采集规则获取失败");
        return false;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("在线采集规则获取失败");
        return false;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("在线采集规则获取失败");
        return false;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    //解析获取的数据
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("在线采集规则获取失败");
        return false;
    }
    cJSON *pCaptureRule = cJSON_GetObjectItem(pRoot, "CaptureRule");
    if (pCaptureRule != NULL)
    {
        cJSON *pEnableCardNoLenAutoNode = cJSON_GetObjectItem(pCaptureRule, "enableCardNoLenAuto");

        if (pEnableCardNoLenAutoNode != NULL && pEnableCardNoLenAutoNode->type == cJSON_True)
        {
            m_bEnableCardNoLenAuto = true;
        }
        else if (pEnableCardNoLenAutoNode != NULL && pEnableCardNoLenAutoNode->type == cJSON_False)
        {
            m_bEnableCardNoLenAuto = false;
            cJSON *pCardNoLenNode = cJSON_GetObjectItem(pCaptureRule, "cardNoLen");
            if (pCardNoLenNode!=NULL)
            {
                char szBuf[128] = { 0 };
                itoa(pCardNoLenNode->valueint, szBuf, 10);
                CString strCardNoLen;
                CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_CARDNOLEN);
                for (int i = 0; i < pWnd->GetCount(); i++)
                {
                    pWnd->GetLBText(i, strCardNoLen);
                    if (strCardNoLen==szBuf)
                    {
                        pWnd->SetCurSel(i);
                        break;
                    }
                }
            }
        }
        else
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        }
        CButton *pWnd = NULL;
        if (m_bEnableCardNoLenAuto)
        {
            pWnd = (CButton *)GetDlgItem(IDC_RADIO_LENAUTOOPEN);
            pWnd->SetCheck(TRUE);
            pWnd = (CButton *)GetDlgItem(IDC_RADIO_LENAUTOCLOSE);
            pWnd->SetCheck(FALSE);
            OnBnClickedRadioLenautoopen();
        }
        else
        {
            pWnd = (CButton *)GetDlgItem(IDC_RADIO_LENAUTOOPEN);
            pWnd->SetCheck(FALSE);
            pWnd = (CButton *)GetDlgItem(IDC_RADIO_LENAUTOCLOSE);
            pWnd->SetCheck(TRUE);
            OnBnClickedRadioLenautoclose();
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        cJSON_Delete(pRoot);
        MessageBox("在线采集规则获取失败");
        return false;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    cJSON_Delete(pRoot);
    return true;
}

bool CDlgOnlineCapture::PutAccessControlCaptureRule()
{
    CString strRequest = "PUT /ISAPI/AccessControl/CaptureRule?format=json";
    memset(m_pInBuf, 0, m_dwMaxBufLen);
    if (m_bEnableCardNoLenAuto)
    {
        sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "{\r\n"
            "\"CaptureRule\": {\r\n"
            "\"enableCardNoLenAuto\": true,\r\n"
            "\"cardTimeout\": %d\r\n"
            "}\r\n"
            "}\r\n", m_dwCardTimeOut);
    }
    else
    {
        CString strCardNoLen;
        CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_CARDNOLEN);
        pWnd->GetLBText(pWnd->GetCurSel(), strCardNoLen);
        int iCardNoLen = atoi(strCardNoLen.GetBuffer());
        sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "{\r\n"
            "\"CaptureRule\": {\r\n"
            "\"enableCardNoLenAuto\": false,\r\n"
            "\"cardNoLen\": %d,"
            "\"cardTimeout\": %d\r\n"
            "}\r\n"
            "}\r\n", iCardNoLen, m_dwCardTimeOut);
    }

    memset(m_pOutBuf, 0, m_dwMaxBufLen);

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
        return false;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        return false;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (!ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return false;
    }
    if (!bResponseStatus)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return false;
    }
    else
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s", strLogInfo.c_str());
        return true;
    }
}

void CDlgOnlineCapture::GetAccessControlCaptureCardInfo()
{
    CString strRequest = "GET /ISAPI/AccessControl/CaptureCardInfo?format=json";
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
        MessageBox("采集卡信息失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("采集卡信息失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("采集卡信息失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("采集卡信息失败");
        return;
    }
    cJSON *pCardInfoNode = cJSON_GetObjectItem(pRoot, "CardInfo");
    if (pCardInfoNode!=NULL)
    {
        cJSON *pCardNoNode = cJSON_GetObjectItem(pCardInfoNode, "cardNo");
        if (pCardNoNode != NULL && pCardNoNode->valuestring != NULL)
        {
            m_strCardNo = pCardNoNode->valuestring;
        }
        cJSON *pCardTypeNode = cJSON_GetObjectItem(pCardInfoNode, "cardType");
        if (pCardTypeNode != NULL && pCardTypeNode->valuestring != NULL)
        {
            m_strCardType = pCardTypeNode->valuestring;
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

void CDlgOnlineCapture::GetAccessControlCaptureIDInfoCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/CaptureIDInfo/capabilities?format=json";
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
        MessageBox("获取采集身份证信息能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取采集身份证信息能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取采集身份证信息能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("获取采集身份证信息能力失败");
        return;
    }
    cJSON_Delete(pRoot);
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    return;
}

void CDlgOnlineCapture::CurrentTimeToString(char *pTimeBuf, const int iBufLen)
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

bool CDlgOnlineCapture::SaveData(const char *pFilePath, const char *pFileName, const void *pContent, const unsigned int dwLength)
{
    char szFileName[MAX_PATH] = { 0 };
    sprintf_s(szFileName, "%s\\%s", pFilePath, pFileName);
    HANDLE hFile = CreateFile(szFileName, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile==INVALID_HANDLE_VALUE)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOnlineCapture::SaveData CreateFile failed.", GetLastError());
        CloseHandle(hFile);
        return false;
    }
    DWORD dwBytesWritten = 0;
    if (!WriteFile(hFile, pContent, dwLength, &dwBytesWritten, NULL))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOnlineCapture::SaveData WriteFile failed.", GetLastError());
        CloseHandle(hFile);
        return false;
    }
    CloseHandle(hFile);
    return true;
}

void CDlgOnlineCapture::PostAccessControlCaptureIDInfo()
{
    CString strRequest = "POST /ISAPI/AccessControl/CaptureIDInfo?format=json";
    memset(m_pOutBuf, 0, m_dwMaxBufLen);
	memset(m_pInBuf, 0, m_dwMaxBufLen);
	sprintf_s(m_pInBuf, m_dwMaxBufLen -1, "{\"IdentityInfoCond\":{}}\r\n");

    memset(m_pInBuf, 0, m_dwMaxBufLen);
    sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "{\"IdentityInfoCond\":{}}\r\n");

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pInBuffer = m_pInBuf;                        //输入数据
    struPtParam.dwInSize = strlen(m_pInBuf);                    //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("采集身份证信息失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("采集身份证信息失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("采集身份证信息失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    //创建文件夹
    char szCurrtenTime[128] = { 0 };
    CurrentTimeToString(szCurrtenTime,sizeof(szCurrtenTime));
    sprintf_s(m_szIDInfoDataPath, "%s\\%s\\IDInfoData[%s]", m_szExePath, DATA_INFO_FILE_PATH, szCurrtenTime);
    if (!PathIsDirectory(m_szIDInfoDataPath))  // 是否有重名文件夹
    {
        if (!CreateDirectory(m_szIDInfoDataPath, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOnlineCapture::PostAccessControlCaptureIDInfo Create directory failed.", GetLastError());
            CButton *pWnd = (CButton *)GetDlgItem(IDC_BUTTON_IDDATAPATH);
            pWnd->EnableWindow(FALSE);
        }
        else
        {
            CButton *pWnd = (CButton *)GetDlgItem(IDC_BUTTON_IDDATAPATH);
            pWnd->EnableWindow(TRUE);
        }
    }
    //解析获取的数据
    cJSON *pRoot = cJSON_Parse(m_pOutBuf);
    if (pRoot == NULL)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("采集身份证信息失败");
        return;
    }
    cJSON *pIdentityInfoNode = cJSON_GetObjectItem(pRoot, "IdentityInfo");
    if (pIdentityInfoNode != NULL)
    {
        cJSON *pchnNameNode = cJSON_GetObjectItem(pIdentityInfoNode, "chnName");
        if (pchnNameNode != NULL && pchnNameNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_CHNAME);
            pWnd->SetWindowText(pchnNameNode->valuestring);
        }
        cJSON *penNameNode = cJSON_GetObjectItem(pIdentityInfoNode, "enName");
        if (penNameNode != NULL && penNameNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_ENNAME);
            pWnd->SetWindowText(penNameNode->valuestring);
        }
        cJSON *psexNode = cJSON_GetObjectItem(pIdentityInfoNode, "sex");
        if (psexNode != NULL && psexNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_SEX);
            pWnd->SetWindowText(psexNode->valuestring);
        }
        cJSON *pbirthNode = cJSON_GetObjectItem(pIdentityInfoNode, "birth");
        if (pbirthNode != NULL && pbirthNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_SEX);
            pWnd->SetWindowText(pbirthNode->valuestring);
        }
        cJSON *paddrNode = cJSON_GetObjectItem(pIdentityInfoNode, "addr");
        if (paddrNode != NULL && paddrNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_ADDR);
            pWnd->SetWindowText(paddrNode->valuestring);
        }
        cJSON *pIDCardNoNode = cJSON_GetObjectItem(pIdentityInfoNode, "IDCardNo");
        if (pIDCardNoNode != NULL && pIDCardNoNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_ID);
            pWnd->SetWindowText(pIDCardNoNode->valuestring);
        }
        cJSON *pissuingAuthorityNode = cJSON_GetObjectItem(pIdentityInfoNode, "issuingAuthority");
        if (pissuingAuthorityNode != NULL && pissuingAuthorityNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_ISSUAUTH);
            pWnd->SetWindowText(pissuingAuthorityNode->valuestring);
        }
        cJSON *pstartDateNode = cJSON_GetObjectItem(pIdentityInfoNode, "startDate");
        if (pstartDateNode != NULL && pstartDateNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_STARTDATE);
            pWnd->SetWindowText(pstartDateNode->valuestring);
        }
        cJSON *pendDateNode = cJSON_GetObjectItem(pIdentityInfoNode, "endDate");
        if (pendDateNode != NULL && pendDateNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_ENDDATE);
            pWnd->SetWindowText(pendDateNode->valuestring);
        }
        cJSON *pnationNode = cJSON_GetObjectItem(pIdentityInfoNode, "nation");//////////////民族，后续需要再做转换
        if (pnationNode != NULL)
        {
            char szBuf[128] = { 0 };
            itoa(pnationNode->valueint, szBuf, 10);
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_NATION);
            pWnd->SetWindowText(szBuf);
        }
        cJSON *ppassNoNode = cJSON_GetObjectItem(pIdentityInfoNode, "passNo");
        if (ppassNoNode != NULL && ppassNoNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_PASSNO);
            pWnd->SetWindowText(ppassNoNode->valuestring);
        }
        cJSON *pissueNumberNode = cJSON_GetObjectItem(pIdentityInfoNode, "issueNumber");
        if (pissueNumberNode != NULL && pissueNumberNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_ISSUNUM);
            pWnd->SetWindowText(pissueNumberNode->valuestring);
        }
        cJSON *pcertificateTypeNode = cJSON_GetObjectItem(pIdentityInfoNode, "certificateType");
        if (pcertificateTypeNode != NULL && pcertificateTypeNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_CERTITYPE);
            pWnd->SetWindowText(pcertificateTypeNode->valuestring);
        }
        cJSON *ppermanentResidenceCardNoNode = cJSON_GetObjectItem(pIdentityInfoNode, "permanentResidenceCardNo");
        if (ppermanentResidenceCardNoNode != NULL && ppermanentResidenceCardNoNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_PRCN);
            pWnd->SetWindowText(ppermanentResidenceCardNoNode->valuestring);
        }
        cJSON *pnationalityOrAreaCodeNode = cJSON_GetObjectItem(pIdentityInfoNode, "nationalityOrAreaCode");
        if (pnationalityOrAreaCodeNode != NULL && pnationalityOrAreaCodeNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_NOACODE);
            pWnd->SetWindowText(pnationalityOrAreaCodeNode->valuestring);
        }
        cJSON *pversionNode = cJSON_GetObjectItem(pIdentityInfoNode, "version");
        if (pversionNode != NULL && pversionNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_VERSION);
            pWnd->SetWindowText(pversionNode->valuestring);
        }
        cJSON *preceivingAuthorityCodeNode = cJSON_GetObjectItem(pIdentityInfoNode, "receivingAuthorityCode");
        if (preceivingAuthorityCodeNode != NULL && preceivingAuthorityCodeNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_RACODE);
            pWnd->SetWindowText(preceivingAuthorityCodeNode->valuestring);
        }
        cJSON *pFingerprintListNode = cJSON_GetObjectItem(pIdentityInfoNode, "FingerprintList");
        if (pFingerprintListNode != NULL && pFingerprintListNode->type == cJSON_Array)
        {
            int iArraySize = cJSON_GetArraySize(pFingerprintListNode);
            char szBuf[128] = { 0 };
            itoa(iArraySize, szBuf, 10);
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_PRINTINFO);
            pWnd->SetWindowText(szBuf);
            for (int i = 0; i < iArraySize; i++)
            {
                cJSON *pFingerPrintNode = cJSON_GetArrayItem(pFingerprintListNode, i);
                if (pFingerPrintNode != NULL && pFingerPrintNode->valuestring != NULL)
                {
                    sprintf_s(szBuf, "IdentityInfo_fingerprint_%d", i);
                    SaveData(m_szIDInfoDataPath, szBuf, pFingerPrintNode->valuestring, strlen(pFingerPrintNode->valuestring));
                }
            }
        }
        cJSON *ppicNode = cJSON_GetObjectItem(pIdentityInfoNode, "pic");
        if (ppicNode != NULL && ppicNode->valuestring != NULL)
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_PIC);
            pWnd->SetWindowText("有");
            SaveData(m_szIDInfoDataPath, "IdentityInfo_pic", ppicNode->valuestring, strlen(ppicNode->valuestring));
        }
        else
        {
            CEdit* pWnd = (CEdit*)GetDlgItem(IDC_EDIT_PIC);
            pWnd->SetWindowText("无");
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

void CDlgOnlineCapture::GetAccessControlCaptureFaceDataCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/CaptureFaceData/capabilities";
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
        MessageBox("获取采集人脸信息能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取采集人脸信息能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取采集人脸信息能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    CXmlBase xmlBase;
    xmlBase.Parse(m_pOutBuf);
    if (xmlBase.Error())
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("获取采集人脸信息能力失败");
        return;
    }
    if (xmlBase.FindElem("CaptureFaceData")&&xmlBase.IntoElem())
    {
        if (xmlBase.FindElem("CaptureFaceDataCond")&&xmlBase.IntoElem())
        {
            CComboBox *pWnd = NULL;
            if (xmlBase.FindElem("captureInfrared"))
            {
                pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_CAPTUREINF);
                string strCaptureInfrared = xmlBase.GetAttributeValue("opt");
                if (strCaptureInfrared.find("true")!=string::npos)
                {
                    if (g_bEnglish)
                    {
                        pWnd->AddString("yes");
                    }
                    else
                    {
                        pWnd->AddString("是");
                    }
                }
            }
            if (xmlBase.FindElem("dataType"))
            {
                string strdataType = xmlBase.GetAttributeValue("opt");
                if (strdataType.find("binary") != string::npos)
                {
                    pWnd->AddString("Binary");
                }
            }
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    return;
}

void CDlgOnlineCapture::PostAccessControlCaptureFaceData()
{
    CString strRequest = "POST /ISAPI/AccessControl/CaptureFaceData";
    memset(m_pInBuf, 0, m_dwMaxBufLen);

    string strDataType;
    string strCaptureInfrared;
    CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_CAPTUREINF);
    if (pWnd->GetCurSel()==0)
    {
        strCaptureInfrared = "false";
        m_bCaptureInfrared = false;
        CEdit *pWnd = (CEdit *)GetDlgItem(IDC_EDIT_INFRAREDFACEDATA);
        pWnd->SetWindowText("未采集");
    }
    else
    {
        strCaptureInfrared = "true";
        m_bCaptureInfrared = true;
    }
    pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_DATATYPE);
    if (pWnd->GetCurSel() == 0) //只支持二进制
    {
        strDataType = "binary";
    }
    sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "<CaptureFaceDataCond version=\"2.0\" xmlns=\"http://www.isapi.org/ver20/XMLSchema\">\r\n"
        "<captureInfrared>%s</captureInfrared>\r\n"
        "<dataType>%s</dataType>\r\n"
        "</CaptureFaceDataCond>\r\n", strCaptureInfrared.c_str(), strDataType.c_str());

    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    char * pDataBuffer1 = new char[200 * 1024];
    if (pDataBuffer1 == NULL)
        return;
    char * pDataBuffer2 = new char[200 * 1024];
    if (pDataBuffer2 == NULL)
        return;

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pInBuffer = m_pInBuf;                        //输入数据
    struPtParam.dwInSize = strlen(m_pInBuf);                 //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    struPtParam.dwRecvTimeOut = 20000;

    // DEMO注册两个BUFFER用于接收数据，目前协议最多两个二进制数据; 根据struPtParam.byNumOfData调整实际支持数量;
    // 也可根据实际协议接口确认需要多少个BUFFER; 当用户不填BUFFER时,数据将被丢弃;
    struPtParam.struData[0].pDataBuffer = pDataBuffer1;
    struPtParam.struData[0].dwDataSize = 200 * 1024;
    struPtParam.struData[1].pDataBuffer = pDataBuffer2;
    struPtParam.struData[1].dwDataSize = 200 * 1024;

    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        MessageBox("采集人脸失败");

        delete pDataBuffer1;
        delete pDataBuffer2;
        return;
    }

    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("采集人脸失败");
        delete pDataBuffer1;
        delete pDataBuffer2;
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("采集人脸失败");
        delete pDataBuffer1;
        delete pDataBuffer2;
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    //创建文件夹
    char szCurrtenTime[128] = { 0 };
    CurrentTimeToString(szCurrtenTime, sizeof(szCurrtenTime));
    sprintf_s(m_szFaceInfoDataPath, "%s\\%s\\FaceInfoData", m_szExePath, DATA_INFO_FILE_PATH);
    if (!PathIsDirectory(m_szFaceInfoDataPath))  // 是否有重名文件夹
    {
        if (!CreateDirectory(m_szFaceInfoDataPath, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOnlineCapture::PostAccessControlCaptureIDInfo Create directory failed.", GetLastError());
            CButton *pWnd = (CButton *)GetDlgItem(IDC_BUTTON_FACEDATA);
            pWnd->EnableWindow(FALSE);
        }
        else
        {
            CButton *pWnd = (CButton *)GetDlgItem(IDC_BUTTON_FACEDATA);
            pWnd->EnableWindow(TRUE);
        }
    }
    //解析获取的数据
    CXmlBase xmlBase;
    xmlBase.Parse(m_pOutBuf);
    if (xmlBase.Error())
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("采集人脸失败");
        delete pDataBuffer1;
        delete pDataBuffer2;
        return;
    }

    char szFileName[128] = { 0 };
    if (struPtParam.struData[0].dwDataSize != 0)
    {
        sprintf_s(szFileName, "FACE_%s_%s", struPtParam.struData[0].szName, szCurrtenTime);
        SaveData(m_szFaceInfoDataPath, szFileName, struPtParam.struData[0].pDataBuffer, struPtParam.struData[0].dwDataSize);
    }

    if (struPtParam.struData[1].dwDataSize != 0)
    {
        sprintf_s(szFileName, "FACE_%s_%s", struPtParam.struData[1].szName, szCurrtenTime);
        SaveData(m_szFaceInfoDataPath, szFileName, struPtParam.struData[1].pDataBuffer, struPtParam.struData[0].dwDataSize);
    }

    if (xmlBase.FindElem("CaptureFaceData") && xmlBase.IntoElem())
    {
        if (xmlBase.FindElem("captureProgress"))
        {
            CEdit *pWnd = NULL;
            if (xmlBase.GetData()=="100")
            {
                CProgressCtrl *pProgWnd = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS_CAPTUREPROGRESS);
                pProgWnd->SetPos(100);
                if (struPtParam.struData[0].dwDataSize != 0 && !strcmp(struPtParam.struData[0].szName,"FaceData"))
                {
                    pWnd = (CEdit *)GetDlgItem(IDC_EDIT_FACEDATA);
                    pWnd->SetWindowText("采集完成");
                }
                else
                {
                    pWnd = (CEdit *)GetDlgItem(IDC_EDIT_FACEDATA);
                    pWnd->SetWindowText("采集失败");
                }

                if (m_bCaptureInfrared)
                {
                    if (struPtParam.struData[1].dwDataSize != 0 && !strcmp(struPtParam.struData[1].szName, "InfraredFaceData"))
                    {
                        pWnd = (CEdit *)GetDlgItem(IDC_EDIT_INFRAREDFACEDATA);
                        pWnd->SetWindowText("采集完成");
                    }
                }
            }
            else
            {
                CreateGetAccessControlCaptureFaceDataProgressThread();
            }
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    delete pDataBuffer1;
    delete pDataBuffer2;
    return;
}

void CDlgOnlineCapture::CreateGetAccessControlCaptureFaceDataProgressThread()
{
    CButton *pButtonWnd = (CButton *)GetDlgItem(IDC_BUTTON_CAPTUREFACE);
    pButtonWnd->SetWindowText("采集中");
    pButtonWnd->EnableWindow(FALSE);

    CProgressCtrl *pProgWnd = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS_CAPTUREPROGRESS);
    pProgWnd->SetPos(0);

    CEdit *pWnd = (CEdit *)GetDlgItem(IDC_EDIT_FACEDATA);
    pWnd->SetWindowText("处理中");
    if (m_bCaptureInfrared)
    {
        pWnd = (CEdit *)GetDlgItem(IDC_EDIT_INFRAREDFACEDATA);
        pWnd->SetWindowText("处理中");
    }
    UpdateData(FALSE);
    HANDLE m_hCaptureFaceDataProgressThread = CreateThread(NULL, 0, GetAccessControlCaptureFaceDataProgressThread, this, 0, NULL);
    if (m_hCaptureFaceDataProgressThread == INVALID_HANDLE_VALUE)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CreateGetAccessControlCaptureFaceDataProgressThread failed.");
        return;
    }
}

DWORD WINAPI CDlgOnlineCapture::GetAccessControlCaptureFaceDataProgressThread(void *pParam)
{
    CDlgOnlineCapture *pThis = (CDlgOnlineCapture *)pParam;
    string strRequest = "GET /ISAPI/AccessControl/CaptureFaceData/Progress";
    char szResponseBuf[2048] = { 0 };
    char *pInParam = NULL;
    char *pOutParam = NULL;

    char * pDataBuffer1 = new char[200 * 1024];
    char * pDataBuffer2 = new char[200 * 1024];

    int i = 0;
    for (; i < 100; i++)
    {
        memset(szResponseBuf, 0, sizeof(szResponseBuf));

        USB_PT_PARAM struPtParam = { 0 };
        struPtParam.pRequestUrl = (void *)strRequest.c_str();           //请求URL
        struPtParam.dwRequestUrlLen = strRequest.length();              //请求URL长度
        struPtParam.pOutBuffer = pThis->m_pOutBuf;                      //输出缓冲区
        struPtParam.dwOutSize = pThis->m_dwMaxBufLen;                   //输出缓冲区大小 
        struPtParam.dwRecvTimeOut = 20000;
        // DEMO注册两个BUFFER用于接收数据，目前协议最多两个二进制数据; 根据struPtParam.byNumOfData调整实际支持数量;
        // 也可根据实际协议接口确认需要多少个BUFFER; 当用户不填BUFFER时,数据将被丢弃;
        struPtParam.struData[0].pDataBuffer = pDataBuffer1;
        struPtParam.struData[0].dwDataSize = 200 * 1024;
        struPtParam.struData[1].pDataBuffer = pDataBuffer2;
        struPtParam.struData[1].dwDataSize = 200 * 1024;

        if (!USB_TransConfig(pThis->m_lUserID, &struPtParam))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.c_str());
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            pThis->MessageBox("获取人脸采集进度失败");
            break;
        }
        if (strlen(szResponseBuf)==0)
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.c_str());
            pThis->MessageBox("获取人脸采集进度失败");
            break;
        }
        CXmlBase xmlBase;
        xmlBase.Parse(szResponseBuf);
        if (xmlBase.Error())
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.c_str());
            pThis->MessageBox("获取人脸采集进度失败");
            break;
        }
        if (xmlBase.FindElem("CaptureFaceData") && xmlBase.IntoElem())
        {
            if (xmlBase.FindElem("captureProgress"))
            {
                CProgressCtrl *pProgWnd = (CProgressCtrl *)pThis->GetDlgItem(IDC_PROGRESS_CAPTUREPROGRESS);
                int iPos = atoi(xmlBase.GetData().c_str());
                pProgWnd->SetPos(iPos);
                CEdit *pWnd = NULL;
                if (xmlBase.GetData() == "100")
                {
                    //TODO是否采集成功的判断
                    pWnd = (CEdit *)pThis->GetDlgItem(IDC_EDIT_FACEDATA);
                    pWnd->SetWindowText("采集完成");
                    if (pThis->m_bCaptureInfrared)
                    {
                        pWnd = (CEdit *)pThis->GetDlgItem(IDC_EDIT_INFRAREDFACEDATA);
                        pWnd->SetWindowText("采集完成");
                    }

                    char szCurrtenTime[128] = { 0 };
                    pThis->CurrentTimeToString(szCurrtenTime, sizeof(szCurrtenTime));
                    char szFileName[128] = { 0 };
                    if (struPtParam.struData[0].dwDataSize != 0)
                    {
                        sprintf_s(szFileName, "FACE_%s_%s", struPtParam.struData[0].szName, szCurrtenTime);
                        pThis->SaveData(pThis->m_szFaceInfoDataPath, szFileName, struPtParam.struData[0].pDataBuffer, struPtParam.struData[0].dwDataSize);
                    }

                    if (struPtParam.struData[1].dwDataSize != 0)
                    {
                        sprintf_s(szFileName, "FACE_%s_%s", struPtParam.struData[1].szName, szCurrtenTime);
                        pThis->SaveData(pThis->m_szFaceInfoDataPath, szFileName, struPtParam.struData[1].pDataBuffer, struPtParam.struData[0].dwDataSize);
                    }

                    break;
                }
            }
        }
        else
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.c_str());
            pThis->MessageBox("获取人脸采集进度失败");
            break;
        }

        if (!pThis->m_bStopCaptureThread)
        {
            Sleep(500);
        }
        else
        {
            break;
        }
    }

    CButton *pWnd = (CButton *)pThis->GetDlgItem(IDC_BUTTON_CAPTUREFACE);
    pWnd->SetWindowText("结束采集");
    pWnd->EnableWindow(true);
    pThis->UpdateData(FALSE);
    if (pThis->m_hCaptureFaceDataProgressThread != INVALID_HANDLE_VALUE)
    {
        CloseHandle(pThis->m_hCaptureFaceDataProgressThread);
        pThis->m_hCaptureFaceDataProgressThread = INVALID_HANDLE_VALUE;
    }

    delete pDataBuffer1;
    delete pDataBuffer2;
    return 0;
}

void CDlgOnlineCapture::StopGetAccessControlCaptureFaceDataProgressThread()
{
    m_bStopCaptureThread = true;
    if (m_hCaptureFaceDataProgressThread!=INVALID_HANDLE_VALUE)
    {
        WaitForSingleObject(m_hCaptureFaceDataProgressThread, INFINITE);
        CloseHandle(m_hCaptureFaceDataProgressThread);
        m_hCaptureFaceDataProgressThread = INVALID_HANDLE_VALUE;
    }
}

void CDlgOnlineCapture::GetAccessControlCaptureFingerPrintCapabilities()
{
    CString strRequest = "GET /ISAPI/AccessControl/CaptureFingerPrint/capabilities";
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
        MessageBox("获取采集指纹信息能力失败");
        return;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        MessageBox("获取采集指纹信息能力失败");
        return;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        MessageBox("获取采集指纹信息能力失败");
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    CXmlBase xmlBase;
    xmlBase.Parse(m_pOutBuf);
    if (xmlBase.Error())
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        MessageBox("获取采集指纹信息能力失败");
        return;
    }
    if (xmlBase.FindElem("CaptureFingerPrint") && xmlBase.IntoElem())
    {
        //
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    return;
}

bool CDlgOnlineCapture::PostAccessControlCaptureFingerPrint(const int iFingerNo, char *pFingerQuality, const unsigned int dwBufLen)
{
    CString strRequest = "POST /ISAPI/AccessControl/CaptureFingerPrint";
    memset(m_pInBuf, 0, m_dwMaxBufLen);
    sprintf_s(m_pInBuf, m_dwMaxBufLen - 1, "<CaptureFingerPrintCond version=\"2.0\" xmlns=\"http://www.isapi.org/ver20/XMLSchema\">\r\n"
        "<fingerNo>%d</fingerNo>\r\n"
        "</CaptureFingerPrintCond>\r\n", iFingerNo);

    memset(m_pOutBuf, 0, m_dwMaxBufLen);

    USB_PT_PARAM struPtParam = { 0 };
    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pInBuffer = m_pInBuf;                        //输入数据
    struPtParam.dwInSize = strlen(m_pInBuf);                    //输入数据大小
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    struPtParam.dwRecvTimeOut = 20000;
    if (!USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        return false;
    }
    if (strlen(m_pOutBuf) == 0)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Message len = 0", strRequest.GetBuffer());
        return false;
    }
    string strLogInfo;
    bool bResponseStatus = false;
    if (ParseResponseStatus(strLogInfo, bResponseStatus))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s", strLogInfo.c_str());
        return false;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    //解析获取的数据
    CXmlBase xmlBase;
    xmlBase.Parse(m_pOutBuf);
    if (xmlBase.Error())
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid format.", strRequest.GetBuffer());
        return false;
    }
    if (xmlBase.FindElem("CaptureFingerPrint") && xmlBase.IntoElem())
    {
        if (xmlBase.FindElem("fingerData"))
        {
            char szBuf[128] = { 0 };
            sprintf_s(szBuf, sizeof(szBuf) - 1, "finger%d", iFingerNo);
            string strFingerData = xmlBase.GetData();
            SaveData(m_szFingerPrintDataPath, szBuf, strFingerData.c_str(), strFingerData.length());
        }
        if (xmlBase.FindElem("fingerPrintQuality"));
        {
            sprintf_s(pFingerQuality, dwBufLen - 1, xmlBase.GetData().c_str());
        }
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED %s Invalid content.", strRequest.GetBuffer());
        return false;
    }
    LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS %s Parse success.", strRequest.GetBuffer());
    return true;
}

void CDlgOnlineCapture::SetToolTipMessage()
{
    EnableToolTips(TRUE);
    m_toopTip.Create(this);
    m_toopTip.Activate(TRUE);
    m_toopTip.SetDelayTime(150);

    CString strTip;
    char szBuf[128] = { 0 };
    //debug
    m_iNameLenMin = 2; 
    m_iNameLenMax = 64;
    //
    if (m_iNameLenMax>m_iNameLenMin && m_iNameLenMin>-1)
    {
        itoa(m_iNameLenMin, szBuf, 10);
        strTip = szBuf;
        strTip += "-";
        memset(szBuf, 0, sizeof(szBuf));
        itoa(m_iNameLenMax, szBuf, 10);
        strTip = strTip + szBuf + "个字符";
        CWnd* pWnd = GetDlgItem(IDC_EDIT_NAME);
        m_toopTip.AddTool(pWnd, strTip);
    }

    //debug
    m_iCardTimeoutMin = 10;
    m_iCardTimeoutMax = 100;
    //
    if (m_iCardTimeoutMax > m_iCardTimeoutMin && m_iCardTimeoutMin > -1)
    {
        memset(szBuf, 0, sizeof(szBuf));
        itoa(m_iCardTimeoutMin, szBuf, 10);
        strTip = szBuf;
        strTip += "-";
        memset(szBuf, 0, sizeof(szBuf));
        itoa(m_iCardTimeoutMax, szBuf, 10);
        strTip = strTip + szBuf + "ms";
        CWnd* pWnd = GetDlgItem(IDC_EDIT_TIMEOUT);
        m_toopTip.AddTool(pWnd, strTip);
    }

}

void CDlgOnlineCapture::SetControls()
{
    //if (!m_bIsSupportCapturePresetParam)
    if (0)
    {
        CWnd* pWnd = GetDlgItem(IDC_EDIT_NAME);
        pWnd->EnableWindow(FALSE);
        pWnd = GetDlgItem(IDC_EDIT_TIMEOUT);
        pWnd->EnableWindow(FALSE);
        pWnd = GetDlgItem(IDC_RADIO_LENAUTOOPEN);
        pWnd->EnableWindow(FALSE);
        pWnd = GetDlgItem(IDC_RADIO_LENAUTOCLOSE);
        pWnd->EnableWindow(FALSE);
        pWnd = GetDlgItem(IDC_COMBO_CARDNOLEN);
        pWnd->EnableWindow(FALSE);
    }
    else
    {
        CWnd *pWnd = (CButton *)GetDlgItem(IDC_RADIO_LENAUTOOPEN);
        ((CButton *)pWnd)->SetCheck(TRUE);
        pWnd = GetDlgItem(IDC_COMBO_CARDNOLEN);
        //pWnd->EnableWindow(FALSE);
        for (int i = 0; i < m_vCardNoLen.size(); i++)
        {
            char szBuf[128] = { 0 };
            itoa(m_vCardNoLen[i], szBuf, 10);
            pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_CARDNOLEN);
            ((CComboBox*)pWnd)->AddString(szBuf);
        }
    }
    //debug
    m_bIsSupportCaptureCardInfo = true;
    if (!m_bIsSupportCaptureCardInfo)
    {
        CWnd* pWnd = GetDlgItem(IDC_BUTTON_CAPTURECARD);
        pWnd->EnableWindow(FALSE);
    }
    //debug
    m_bIsSupportCaptureIDInfo = true;
    if (m_bIsSupportCaptureIDInfo)
    {
        CComboBox *pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_CAPTUREINF);
        if (g_bEnglish)
        {
            pWnd->AddString("no");
        }
        else
        {
            pWnd->AddString("否");
        }
        pWnd->SetCurSel(0);
        pWnd = (CComboBox *)GetDlgItem(IDC_COMBO_DATATYPE);
        pWnd->AddString("Binary");
        pWnd->SetCurSel(0);
    }
    //debug
    //人脸
    //debug
    //指纹
}

BOOL CDlgOnlineCapture::PreTranslateMessage(MSG* pMsg)
{
    // TODO:  在此添加命令处理程序代码
    if (pMsg->message == WM_MOUSEMOVE)
        m_toopTip.RelayEvent(pMsg);
    return CDialog::PreTranslateMessage(pMsg);
}

//解析通用返回状态，成功打印日志
bool CDlgOnlineCapture::ParseResponseStatus(string &strLogInfo, bool &bResponseStatus)
{
    if (strlen(m_pOutBuf)==0)
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
    if (pRoot==NULL)
    {
        return false;
    }
    cJSON *pstatusCode = cJSON_GetObjectItem(pRoot, "statusCode");
    if (pstatusCode!=NULL)
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
    if (pstatusString != NULL && pstatusString->valuestring!=NULL)
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

BEGIN_MESSAGE_MAP(CDlgOnlineCapture, CDialog)
    ON_BN_CLICKED(IDC_RADIO_LENAUTOOPEN, &CDlgOnlineCapture::OnBnClickedRadioLenautoopen)
    ON_BN_CLICKED(IDC_RADIO_LENAUTOCLOSE, &CDlgOnlineCapture::OnBnClickedRadioLenautoclose)
    ON_BN_CLICKED(IDC_BUTTON_CAPTURECARD, &CDlgOnlineCapture::OnBnClickedButtonCapturecard)
    ON_BN_CLICKED(IDC_BUTTON_CAPTURECARD, &CDlgOnlineCapture::OnBnClickedButtonCapturecard)
    ON_BN_CLICKED(IDC_BUTTON_CAPTUREIDINFO, &CDlgOnlineCapture::OnBnClickedButtonCaptureidinfo)
    ON_BN_CLICKED(IDC_BUTTON_CAPTUREFACE, &CDlgOnlineCapture::OnBnClickedButtonCaptureface)
    ON_BN_CLICKED(IDC_BUTTON_IDDATAPATH, &CDlgOnlineCapture::OnBnClickedButtonIddatapath)
    ON_BN_CLICKED(IDC_BUTTON_FACEDATA, &CDlgOnlineCapture::OnBnClickedButtonFacedata)
    ON_BN_CLICKED(IDC_BUTTON_CAPTUREFINGER, &CDlgOnlineCapture::OnBnClickedButtonCapturefinger)
    ON_BN_CLICKED(IDC_CHECK_ALLFINGERS, &CDlgOnlineCapture::OnBnClickedCheckAllfingers)
    ON_BN_CLICKED(IDC_BUTTON_FINGERDATA, &CDlgOnlineCapture::OnBnClickedButtonFingerdata)
    ON_BN_CLICKED(IDC_BUTTON_PRESET, &CDlgOnlineCapture::OnBnClickedButtonPreset)
    ON_BN_CLICKED(IDCANCEL, &CDlgOnlineCapture::OnBnClickedButtonCancel)
    ON_WM_PAINT()
END_MESSAGE_MAP()
// CDlgOnlineCapture 消息处理程序


void CDlgOnlineCapture::OnBnClickedRadioLenautoopen()
{
    // TODO:  在此添加控件通知处理程序代码
    CWnd* pWnd = GetDlgItem(IDC_COMBO_CARDNOLEN);
    pWnd->EnableWindow(FALSE);
}


void CDlgOnlineCapture::OnBnClickedRadioLenautoclose()
{
    // TODO:  在此添加控件通知处理程序代码
    CWnd* pWnd = GetDlgItem(IDC_COMBO_CARDNOLEN);
    pWnd->EnableWindow(TRUE);
}


void CDlgOnlineCapture::OnBnClickedButtonCapturecard()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_hCaptureFaceDataProgressThread != INVALID_HANDLE_VALUE)
    {
        MessageBox("人脸采集进行中，请稍候");
        return;
    }
    GetAccessControlCaptureCardInfo();
    UpdateData(FALSE);
}


void CDlgOnlineCapture::OnBnClickedButtonCaptureidinfo()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_hCaptureFaceDataProgressThread != INVALID_HANDLE_VALUE)
    {
        MessageBox("人脸采集进行中，请稍候");
        return;
    }
    PostAccessControlCaptureIDInfo();
    UpdateData(FALSE);
}


void CDlgOnlineCapture::OnBnClickedButtonCaptureface()
{
    // TODO:  在此添加控件通知处理程序代码
    PostAccessControlCaptureFaceData();
    UpdateData(FALSE);
}


void CDlgOnlineCapture::OnBnClickedButtonIddatapath()
{
    // TODO:  在此添加控件通知处理程序代码
    ShellExecute(NULL, _T("open"), _T(m_szIDInfoDataPath), NULL, NULL, SW_SHOWNORMAL);
}


void CDlgOnlineCapture::OnBnClickedButtonFacedata()
{
    // TODO:  在此添加控件通知处理程序代码
    ShellExecute(NULL, _T("open"), _T(m_szFaceInfoDataPath), NULL, NULL, SW_SHOWNORMAL);
}


void CDlgOnlineCapture::OnBnClickedButtonCapturefinger()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_hCaptureFaceDataProgressThread != INVALID_HANDLE_VALUE)
    {
        MessageBox("人脸采集进行中，请稍候");
        return;
    }
    //创建文件夹
    char szCurrtenTime[128] = { 0 };
    CurrentTimeToString(szCurrtenTime, sizeof(szCurrtenTime));
    sprintf_s(m_szFingerPrintDataPath, "%s\\%s\\FingerPrintData[%s]", m_szExePath, DATA_INFO_FILE_PATH, szCurrtenTime);
    CEdit *pWnd = NULL;
    for (int i = 0; i < 10; i++)
    {
        if (IsDlgButtonChecked(IDC_CHECK_FINGER1 + i))
        {
            //有选中指纹才创建文件夹
            if (!PathIsDirectory(m_szFingerPrintDataPath))  // 是否有重名文件夹
            {
                if (!CreateDirectory(m_szFingerPrintDataPath, NULL))
                {
                    LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], CDlgOnlineCapture::PostAccessControlCaptureIDInfo Create directory failed.", GetLastError());
                }
                else
                {
                    CButton *pWnd = (CButton *)GetDlgItem(IDC_BUTTON_FINGERDATA);
                    pWnd->EnableWindow(TRUE);
                }
            }
            char szFingerPrintQuality[128] = { 0 };
            if (PostAccessControlCaptureFingerPrint(i + 1, szFingerPrintQuality, sizeof(szFingerPrintQuality)))
            {
                pWnd = (CEdit *)GetDlgItem(IDC_EDITFPRESULT1 + i);
                pWnd->SetWindowText("采集完成");
                pWnd = (CEdit *)GetDlgItem(IDC_EDITFPRESULT11 + i);
                pWnd->SetWindowText(szFingerPrintQuality);
            }
            else
            {
                pWnd = (CEdit *)GetDlgItem(IDC_EDITFPRESULT1 + i);
                pWnd->SetWindowText("采集失败");
                pWnd = (CEdit *)GetDlgItem(IDC_EDITFPRESULT11 + i);
                pWnd->SetWindowText("");
            }
        }
        else
        {
            pWnd = (CEdit *)GetDlgItem(IDC_EDITFPRESULT1 + i);
            pWnd->SetWindowText("");
            pWnd = (CEdit *)GetDlgItem(IDC_EDITFPRESULT11 + i);
            pWnd->SetWindowText("");
        }
    }
    if (!PathIsDirectory(m_szFingerPrintDataPath))  // 是否创建文件夹
    {
        CButton *pWnd = (CButton *)GetDlgItem(IDC_BUTTON_FINGERDATA);
        pWnd->EnableWindow(FALSE);
    }
    UpdateData(FALSE);
}


void CDlgOnlineCapture::OnBnClickedCheckAllfingers()
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
    UpdateData(FALSE);
}


void CDlgOnlineCapture::OnBnClickedButtonFingerdata()
{
    // TODO:  在此添加控件通知处理程序代码
    ShellExecute(NULL, _T("open"), _T(m_szFingerPrintDataPath), NULL, NULL, SW_SHOWNORMAL);
}


void CDlgOnlineCapture::OnBnClickedButtonPreset()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_hCaptureFaceDataProgressThread!=INVALID_HANDLE_VALUE)
    {
        MessageBox("人脸采集进行中，请稍候");
        return;
    }
    UpdateData(TRUE);
    if (m_strName.GetLength() > m_iNameLenMax || m_strName.GetLength() < m_iNameLenMin)
    {
        MessageBox("姓名长度超出范围");
        return;
    }
    if (m_dwCardTimeOut > m_iCardTimeoutMax || m_dwCardTimeOut < m_iNameLenMin)
    {
        MessageBox("采集卡超时参数超出范围");
        return;
    }
    if (!PutAccessControlCapturePresetParam())
    {
        MessageBox("在线采集参数设置失败");
        return;
    }
    if (!PutAccessControlCaptureRule())
    {
        MessageBox("在线采集规则设置失败");
        return;
    }
    MessageBox("设置成功");
    return;
}

void CDlgOnlineCapture::OnBnClickedButtonCancel()
{
    if (m_hCaptureFaceDataProgressThread!=INVALID_HANDLE_VALUE)
    {
        int iRet = MessageBox("人脸采集正在进行中，确认要退出吗？", "警告", MB_OKCANCEL | MB_ICONASTERISK);
        if (iRet == IDCANCEL)
        {
            return;
        }
    }
    StopGetAccessControlCaptureFaceDataProgressThread();
    CDialog::OnCancel();
}


void CDlgOnlineCapture::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_ONLINECAPTURE);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC200);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC300);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC400);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC500);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_RADIO_LENAUTOOPEN);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_RADIO_LENAUTOCLOSE);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_PRESET);

    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC600);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC700);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC800);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_CAPTURECARD);

    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC900);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1000);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1100);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1200);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1300);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1400);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1500);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1600);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1700);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1800);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC1900);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2000);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2100);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2200);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2300);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2400);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2500);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2600);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2700);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2800);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_IDDATAPATH);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_CAPTUREIDINFO);

    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC2900);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3000);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3100);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3200);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3300);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3400);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_FACEDATA);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_CAPTUREFACE);

    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3500);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3600);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3700);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3800);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC3900);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC4000);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_STATIC4100);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_FINGERDATA);
    SET_CONTROL_LAN(IDD_DLG_ONLINECAPTURE, IDC_BUTTON_CAPTUREFINGER);
}
