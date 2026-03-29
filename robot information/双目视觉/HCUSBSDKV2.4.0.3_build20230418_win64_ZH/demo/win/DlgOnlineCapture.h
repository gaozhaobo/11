#pragma once
#include "afxwin.h"
#include <vector>
using std::vector;
using std::string;
// CDlgOnlineCapture 对话框

class CDlgOnlineCapture : public CDialog
{
	DECLARE_DYNAMIC(CDlgOnlineCapture)

public:
	CDlgOnlineCapture(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgOnlineCapture();

// 对话框数据
    enum { IDD = IDD_DLG_ONLINECAPTURE };

    LONG m_lUserID;

protected:
    DECLARE_MESSAGE_MAP()

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    bool ParseResponseStatus(string &strLogInfo, bool &bResponseStatus);
    void GetAccessControlCapabilities();
    void GetAccessControlCapturePresetParamCapabilities();
    bool GetAccessControlCapturePresetParam();
    bool PutAccessControlCapturePresetParam();
    void GetAccessControlCaptureRuleCapabilities();
    bool GetAccessControlCaptureRule();
    bool PutAccessControlCaptureRule();
    void GetAccessControlCaptureCardInfoCapabilities();
    void GetAccessControlCaptureCardInfo();
    void GetAccessControlCaptureIDInfoCapabilities();
    void CurrentTimeToString(char *pTimeBuf, const int iBufLen);
    bool SaveData(const char *pFilePath, const char *pFileName, const void *pContent, const unsigned int dwLength);
    void PostAccessControlCaptureIDInfo();
    void GetAccessControlCaptureFaceDataCapabilities();
    void PostAccessControlCaptureFaceData();
    void CreateGetAccessControlCaptureFaceDataProgressThread();
    static DWORD WINAPI GetAccessControlCaptureFaceDataProgressThread(void *pParam);
    void StopGetAccessControlCaptureFaceDataProgressThread();
    void GetAccessControlCaptureFingerPrintCapabilities();
    bool PostAccessControlCaptureFingerPrint(const int iFingerNo, char *pFingerQuality, const unsigned int dwBufLen);

    void SetToolTipMessage();
    void SetControls();

    CToolTipCtrl m_toopTip;

    const unsigned int m_dwMaxBufLen = 10 * 1024;
    char *m_pInBuf;
    char *m_pOutBuf;
    char m_szExePath[MAX_PATH];

    bool m_bIsSupportCaptureCardInfo;
    bool m_bIsSupportCaptureIDInfo;
    bool m_bIsSupportCaptureRule;
    bool m_bIsSupportCapturePresetParam;

    int m_iNameLenMin;
    int m_iNameLenMax;

    bool m_bEnableCardNoLenAuto;
    vector<int> m_vCardNoLen;
    int  m_iCardTimeoutMin;
    int  m_iCardTimeoutMax;

    char m_szIDInfoDataPath[MAX_PATH];
    char m_szFaceInfoDataPath[MAX_PATH];
    char m_szFingerPrintDataPath[MAX_PATH];
    HANDLE m_hCaptureFaceDataProgressThread;
    bool m_bStopCaptureThread;
    bool m_bCaptureInfrared;
public:
    CString m_strName;
    afx_msg void OnBnClickedRadioLenautoopen();
    afx_msg void OnBnClickedRadioLenautoclose();
    CString m_strCardNo;
    CString m_strCardType;
    afx_msg void OnBnClickedButtonCapturecard();
    afx_msg void OnBnClickedButtonCaptureidinfo();
    afx_msg void OnBnClickedButtonCaptureface();
    afx_msg void OnBnClickedButtonIddatapath();
    afx_msg void OnBnClickedButtonFacedata();
    afx_msg void OnBnClickedButtonCapturefinger();
    afx_msg void OnBnClickedCheckAllfingers();
    afx_msg void OnBnClickedButtonFingerdata();
    afx_msg void OnBnClickedButtonPreset();
    afx_msg void OnBnClickedButtonCancel();
    UINT m_dwCardTimeOut;
    afx_msg void OnPaint();
};
