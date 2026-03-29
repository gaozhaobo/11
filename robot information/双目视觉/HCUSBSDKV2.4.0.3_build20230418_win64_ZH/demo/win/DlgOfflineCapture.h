#pragma once

#include "cjson/cJSON.h"
#include <string>
using std::string;

// CDlgOfflineCapture 对话框

class CDlgOfflineCapture : public CDialog
{
	DECLARE_DYNAMIC(CDlgOfflineCapture)

public:
	CDlgOfflineCapture(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgOfflineCapture();

// 对话框数据
	enum { IDD = IDD_DLG_OFFLINECAPTURE };

    LONG m_lUserID;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();
    bool ParseResponseStatus(string &strLogInfo, bool &bResponseStatus);
    void GetAccessControlCapabilities();
    void GetAccessControlOfflineCaptureCapabilities();
    void CurrentTimeToString(char *pTimeBuf, const int iBufLen);
    bool SaveData(const char *pFilePath, const char *pFileName, const void *pContent, const unsigned int dwLength);
    void PostAccessControlOfflineCaptureInfoFileTemplateDownload();
    void PostAccessControlOfflineCaptureInfoFile();

    void GetAccessControlOfflineCaptureRuleInfo();
    void PutAccessControlOfflineCaptureRuleInfo();
    void ParseRuleList(cJSON *pList);

    const unsigned int m_dwMaxBufLen = 10 * 1024;
    char *m_pInBuf;
    char *m_pOutBuf;
    char *m_pDataBuf1;
    char *m_pDataBuf2;
    char m_szExePath[MAX_PATH];

    bool m_bIsSupportOfflineCapture{ false };
    bool m_bIsSuportDownloadOfflineCaptureInfoTemplate{ false };
    bool m_bIsSuportUploadOfflineCaptureInfo{ false };
    bool m_bIsSupportDownloadCaptureData{ false };
    bool m_bIsSupportDeleteAllData{ false };
    bool m_bIsSupportDeleteTheData{ false };
    bool m_bIsSupportSearchTask{ false };


	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedButtonInfofiletemplate();
    afx_msg void OnBnClickedCheckAllfingers();
    afx_msg void OnBnClickedButtonRulecfg();
    afx_msg void OnPaint();
};
