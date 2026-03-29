// DlgTransConfig.cpp : 实现文件
//

#include "stdafx.h"

#include "afxdialogex.h"
#include "ClientDemo.h"
#include "DlgTransConfig.h"

string GB2UTF(const char* gb2312)
{
    int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* sztr = new char[len + 1];
    memset(sztr, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, sztr, len, NULL, NULL);
    if (wstr) delete[] wstr;

    string str = sztr;
    delete[] sztr;
    sztr = NULL;
    return str;
}

string UTF2GB(const char* utf8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
    len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* sztr = new char[len + 1];
    memset(sztr, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, wstr, -1, sztr, len, NULL, NULL);
    if (wstr) delete[] wstr;

    string str = sztr;
    delete[] sztr;
    sztr = NULL;
    return str;
}

// CISAPITransConfig 对话框

IMPLEMENT_DYNAMIC(CDlgTransConfig, CDialog)

CDlgTransConfig::CDlgTransConfig(CWnd* pParent /*=NULL*/)
: CDialog(CDlgTransConfig::IDD, pParent)
, m_strRequestURL(_T(""))
, m_strRequestParam(_T(""))
, m_strOutParam(_T(""))
, m_pInBuf(NULL)
, m_pOutBuf(NULL)
, m_lUserID(USB_INVALID_USERID)
, m_strFilePath(_T(""))
, m_bInputFileData(FALSE)
, m_bMimeData(FALSE)
, m_dwRecvTimeOut(5000)
{
    m_pInBuf = new(std::nothrow)char[m_dwMaxBufLen];
    m_pDataBuf = new(std::nothrow)char[10 * m_dwMaxBufLen];
    m_pOutBuf = new(std::nothrow)char[m_dwMaxBufLen];
}

CDlgTransConfig::~CDlgTransConfig()
{
    if (m_pInBuf!=NULL)
    {
        delete[]m_pInBuf;
        m_pInBuf = NULL;
    }
    if (m_pOutBuf != NULL)
    {
        delete[]m_pOutBuf;
        m_pOutBuf = NULL;
    }
    if (m_pDataBuf != NULL)
    {
        delete[]m_pDataBuf;
        m_pDataBuf = NULL;
    }
}

BOOL CDlgTransConfig::OnInitDialog()
{
    GetModuleFileName(NULL, m_szExePath, MAX_PATH);
    char *pTemp = strrchr(m_szExePath, '\\');
    if (pTemp != NULL)
    {
        memset(pTemp, 0, 1);
    }
    char szFilePath[MAX_PATH] = { 0 };
    sprintf_s(szFilePath, "%s\\%s", m_szExePath, "dataInfo");
    if (!PathIsDirectory(szFilePath))  // 是否有重名文件夹
    {
        if (!CreateDirectory(szFilePath, NULL))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d],CDlgTransConfig::OnInitDialog Create directory failed.", GetLastError());
        }
    }

    CDialog::OnInitDialog();

    UpdateData(TRUE);

    m_cmbMimeType.SetCurSel(0);
    m_ComboBoxRequestType.SetCurSel(0);

    UpdateData(FALSE);

    return TRUE;
}

void CDlgTransConfig::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_COMMAND, m_strRequestURL);
    DDX_Text(pDX, IDC_EDIT_CFGINPUT, m_strRequestParam);
    DDX_Text(pDX, IDC_EDIT_CFGOUTPUT, m_strOutParam);
    DDX_Control(pDX, IDC_COMBO_REQUEST_TYPE, m_ComboBoxRequestType);
    DDX_Text(pDX, IDC_EDT_FILE_PATH, m_strFilePath);
    DDX_Check(pDX, IDC_CHECK2, m_bInputFileData);
    DDX_Check(pDX, IDC_CHECK1, m_bMimeData);
    DDX_Text(pDX, IDC_EDIT_TIMEOUT, m_dwRecvTimeOut);
    DDX_Control(pDX, IDC_COMBO_MIME_TYPE, m_cmbMimeType);
}


BEGIN_MESSAGE_MAP(CDlgTransConfig, CDialog)
    ON_BN_CLICKED(IDC_BUTTON_EXIT, &CDlgTransConfig::OnBnClickedButtonExit)
    ON_BN_CLICKED(IDC_BUTTON_OPERATION, &CDlgTransConfig::OnBnClickedButtonOperation)
    ON_CBN_SELCHANGE(IDC_COMBO_REQUEST_TYPE, &CDlgTransConfig::OnCbnSelchangeComboRequestType)
    ON_BN_CLICKED(IDC_BTN_SELECT_FILE, &CDlgTransConfig::OnBnClickedBtnSelectFile)
    ON_WM_PAINT()
END_MESSAGE_MAP()


// CISAPITransConfig 消息处理程序


void CDlgTransConfig::OnBnClickedButtonExit()
{
    // TODO:  在此添加控件通知处理程序代码
    CDialog::OnOK();
}

static void CurrentTimeToString(char *pTimeBuf, const int iBufLen)
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

static bool SaveData(const char *pFilePath, const char *pFileName, const void *pContent, const unsigned int dwLength)
{
    char szFileName[MAX_PATH] = { 0 };
    sprintf_s(szFileName, "%s\\%s", pFilePath, pFileName);
    HANDLE hFile = CreateFile(szFileName, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], SaveData CreateFile failed.", GetLastError());
        CloseHandle(hFile);
        return false;
    }
    DWORD dwBytesWritten = 0;
    if (!WriteFile(hFile, pContent, dwLength, &dwBytesWritten, NULL))
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], SaveData WriteFile failed.", GetLastError());
        CloseHandle(hFile);
        return false;
    }
    CloseHandle(hFile);
    return true;
}

void CDlgTransConfig::OnBnClickedButtonOperation()
{
    // TODO:  在此添加控件通知处理程序代码
    if (m_lUserID == USB_INVALID_USERID)
    {
        MessageBox("请先登录");
        return;
    }
    if (m_pInBuf == NULL || m_pOutBuf == NULL)
    {
        MessageBox("系统资源不足");
        return;
    }
    if (m_ComboBoxRequestType.GetCurSel() == CB_ERR)
    {
        MessageBox("请选择请求类型");
        return;
    }

    UpdateData(TRUE);
    if (m_strRequestURL.GetLength() == 0)
    {
        MessageBox("请输入请求URL");
        return;
    }
    CString strRequest;
    m_ComboBoxRequestType.GetLBText(m_ComboBoxRequestType.GetCurSel(), strRequest);
    strRequest = strRequest + " " + m_strRequestURL;
    strRequest.GetBuffer();
    strRequest.GetLength();

    memset(m_pInBuf, 0, m_dwMaxBufLen);
    memset(m_pOutBuf, 0, m_dwMaxBufLen);


    USB_PT_PARAM struPtParam = { 0 };
    char szLan[128] = { 0 };
    string utf_8;

    if (m_bInputFileData)
    {
        CFile cPicFile;
        if (!cPicFile.Open(m_strFilePath, CFile::modeRead))
        {
            g_StringLanType(szLan, "打开文件失败或无此文件", "Open file failed or no this file");
            AfxMessageBox(szLan);
        }
        else
        {
            struPtParam.dwInSize = (DWORD)cPicFile.GetLength();
            if (struPtParam.dwInSize == 0)
            {
                g_StringLanType(szLan, "Pic文件为空", "Pic file is empty");
                AfxMessageBox(szLan);
            }

            if (struPtParam.dwInSize > 10 * m_dwMaxBufLen)
            {
                LOGIN_INFO->WriteLog(INF_LEVEL, "File too large! over limit[%d]", 10 * m_dwMaxBufLen);
                return;
            }


            if (m_bMimeData)
            {
                if (m_strRequestParam.GetLength() != 0 && struPtParam.dwInSize != 0)
                {
                    USB_MIME_UNIT struUnit[2] = { 0 };

                    // 第一段数据
                    utf_8 = GB2UTF(m_strRequestParam.GetBuffer(0));
                    memcpy(m_pInBuf, (void*)utf_8.c_str(), utf_8.length());
                    struUnit[0].pContent = m_pInBuf;
                    struUnit[0].dwContentLen = utf_8.length();

                    if (strcmp(m_pInBuf, _T("{")))
                    {
                        memcpy(struUnit[0].szContentType, _T("application/json"), strlen(_T("application/json")));
                        memcpy(struUnit[0].szFilename, _T("\\test.json"), strlen(_T("\\test.json")));
                    }
                    else
                    {
                        memcpy(struUnit[0].szContentType, _T("application/xml"), strlen(_T("application/xml")));
                        memcpy(struUnit[0].szFilename, _T("\\test.xml"), strlen(_T("\\test.xml")));
                    }

                    memcpy(struUnit[0].szName, _T("test"), strlen(_T("test")));

                    // 第二段数据
                    cPicFile.Read(m_pDataBuf, struPtParam.dwInSize);
                    struUnit[1].pContent = m_pDataBuf;
                    struUnit[1].dwContentLen = struPtParam.dwInSize;

                    CString strChoosed;
                    m_cmbMimeType.GetLBText(m_cmbMimeType.GetCurSel(), strChoosed);
                    //m_cmbMimeType.GetWindowTextA(strChoosed);
                    memcpy(struUnit[1].szContentType, strChoosed.GetBuffer(), strChoosed.GetLength());
                    memcpy(struUnit[1].szName, _T("test"), strlen(_T("test")));
                    memcpy(struUnit[1].szFilename, m_strFilePath, m_strFilePath.GetLength());
                    struPtParam.pInBuffer = (void*)struUnit;
                    struPtParam.dwInSize = 2 * sizeof(USB_MIME_UNIT);
                    struPtParam.byNumOfMultiPart = 2;
                    LOGIN_INFO->WriteLog(INF_LEVEL, "File size[%d]", struUnit[1].dwContentLen);
                }
                else if (m_strRequestParam.GetLength() == 0)
                {
                    USB_MIME_UNIT struUnit[1] = { 0 };
                    cPicFile.Read(m_pInBuf, struPtParam.dwInSize);
                    struUnit[0].pContent = m_pInBuf;
                    struUnit[0].dwContentLen = struPtParam.dwInSize;
                    // fix：通过界面选择数据类型
                    memcpy(struUnit[0].szContentType, _T("image/jpeg"), strlen(_T("image/jpeg")));
                    memcpy(struUnit[0].szName, _T("test"), strlen(_T("test")));
                    memcpy(struUnit[0].szFilename, m_strFilePath, m_strFilePath.GetLength());
                    struPtParam.pInBuffer = (void*)struUnit;
                    struPtParam.dwInSize = 1 * sizeof(USB_MIME_UNIT);
                    struPtParam.byNumOfMultiPart = 1;
                }
            }
            else
            {
                cPicFile.Read(m_pInBuf, struPtParam.dwInSize);
                struPtParam.pInBuffer = m_pInBuf;
            }

            cPicFile.Close();
        }

    }
    else
    {
        if (m_strRequestParam.GetLength() != 0)
        {
            utf_8 = GB2UTF(m_strRequestParam.GetBuffer(0));
            memcpy(m_pInBuf, (void*)utf_8.c_str(), utf_8.length());
            struPtParam.pInBuffer = m_pInBuf;
            struPtParam.dwInSize = utf_8.length();
        }
    }

    char * pDataBuffer1 = NULL;
    bool bLong = FALSE;
    if (strstr((char*)strRequest.GetBuffer(), "POST /ISAPI/AccessControl/OfflineCapture/DataCollections/downloadTask?format=json"))
    {
        bLong = TRUE;
        pDataBuffer1 = new char[400 * 1024 * 1024];
    }
    else
    {
        pDataBuffer1 = new char[10 *1024 * 1024];
    }


    if (pDataBuffer1 == NULL)
        return;
    char * pDataBuffer2 = new char[10 * 1024 * 1024];
    if (pDataBuffer2 == NULL)
        return;

    struPtParam.pRequestUrl = strRequest.GetBuffer();        //请求URL
    struPtParam.dwRequestUrlLen = strRequest.GetLength();    //请求URL长度
    struPtParam.pOutBuffer = m_pOutBuf;                      //输出缓冲区
    struPtParam.dwOutSize = m_dwMaxBufLen;                   //输出缓冲区大小 
    struPtParam.dwRecvTimeOut = m_dwRecvTimeOut;
    struPtParam.dwSendTimeOut = m_dwRecvTimeOut;

    // DEMO注册两个BUFFER用于接收数据，目前协议最多两个二进制数据; 根据struPtParam.byNumOfData调整实际支持数量;
    // 也可根据实际协议接口确认需要多少个BUFFER; 当用户不填BUFFER时,数据将被丢弃;
    struPtParam.struData[0].pDataBuffer = pDataBuffer1;
    struPtParam.struData[0].dwDataSize = 10 * 1024 * 1024;
    if (bLong)
    {
        struPtParam.struData[0].dwDataSize = 400 * 1024 * 1024;
    }

    struPtParam.struData[1].pDataBuffer = pDataBuffer2;
    struPtParam.struData[1].dwDataSize = 10 * 1024 * 1024;

    BOOL bRet = TRUE;
    if (USB_TransConfig(m_lUserID, &struPtParam))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_TransConfig() %s", strRequest.GetBuffer());
    }
    else
    {
        bRet = FALSE;
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_TransConfig()  %s", strRequest.GetBuffer());
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }

    if (strlen(m_pOutBuf) != 0)
    {
        string str_gb2312 = UTF2GB(m_pOutBuf);
        m_strOutParam = str_gb2312.c_str();
        m_strOutParam.Replace("\n", "\r\n");
        UpdateData(FALSE);
    }

    char szCurrtenTime[128] = { 0 };
    char szFilePath[256] = { 0 };
    char szFileName[128] = { 0 };
    sprintf_s(szFilePath, "%s\\%s", m_szExePath, "dataInfo");
    CurrentTimeToString(szCurrtenTime, sizeof(szCurrtenTime));

    if (bRet)
    {   
        if (struPtParam.struData[0].pDataBuffer != NULL && struPtParam.struData[0].dwDataSize != 0)
        {
            sprintf_s(szFileName, "%s_%s.bin", struPtParam.struData[0].szName, szCurrtenTime);
            SaveData(szFilePath, szFileName, struPtParam.struData[0].pDataBuffer, struPtParam.struData[0].dwDataSize);
        }

        if (struPtParam.struData[1].pDataBuffer != NULL && struPtParam.struData[1].dwDataSize != 0)
        {
            sprintf_s(szFileName, "%s_%s.bin", struPtParam.struData[1].szName, szCurrtenTime);
            SaveData(szFilePath, szFileName, struPtParam.struData[1].pDataBuffer, struPtParam.struData[0].dwDataSize);
        }
    }

    delete pDataBuffer1;
    delete pDataBuffer2;
    return;
}


void CDlgTransConfig::OnCbnSelchangeComboRequestType()
{
    // TODO:  在此添加控件通知处理程序代码
}


void CDlgTransConfig::OnBnClickedBtnSelectFile()
{
    // TODO:  在此添加控件通知处理程序代码

    UpdateData(TRUE);

    char szLan[1024] = { 0 };
    static char szFilter[] = "All File(*.*)|*.*||";
    CFileDialog dlg(TRUE, "*.*", NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
    if (dlg.DoModal() == IDOK)
    {
        m_strFilePath = dlg.GetPathName();
        SetDlgItemText(IDC_EDT_FILE_PATH, m_strFilePath);
    }
}


void CDlgTransConfig::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_TRANSCONFIG);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_STATIC2);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_STATIC3);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_STATIC4);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_STATIC5);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_STATIC6);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_BUTTON_OPERATION);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_BUTTON_EXIT);
    SET_CONTROL_LAN(IDD_DLG_TRANSCONFIG, IDC_CHECK2);
}
