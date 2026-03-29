#if !defined(AFX_DLGHEALTHCODE_H__56FD51F1_AB1B_40AC_8C62_E1DC04846EF7__INCLUDED_)
#define AFX_DLGHEALTHCODE_H__56FD51F1_AB1B_40AC_8C62_E1DC04846EF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCertificateInfo.h : header file
//
#include "Resource.h"
#include "cjson/cJSON.h"
#include <string>
#include "afxwin.h"
using std::string;

// CDlgHealthCode 对话框

class CDlgHealthCode : public CDialog
{
	DECLARE_DYNAMIC(CDlgHealthCode)

public:
	CDlgHealthCode(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgHealthCode();

// 对话框数据
	enum { IDD = IDD_DLG_4G_HEALTH_CODE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    virtual BOOL OnInitDialog();
    bool ParseResponseStatus(string &strLogInfo, bool &bResponseStatus);
    void GetAccessControlCapabilities();
    void GetAccessControlHealthCodeCfgCapabilities();
	DECLARE_MESSAGE_MAP()

    const unsigned int m_dwMaxBufLen = 10 * 1024;
    char *m_pInBuf;
    char *m_pOutBuf;
    char *m_pDataBuf1;
    char *m_pDataBuf2;

    bool m_bIsSupportCaptureHealthCode{ false };
    bool m_bIsSupportHealthCodeCfg{ false };
    bool m_bIsSupportHealthInfoResult{ false };
public:
    LONG m_lUserID;
    afx_msg void OnBnClickedBtnGetHealthCodeCfg();
    afx_msg void OnBnClickedBtnSetHealthCodeCfg();
    CEdit m_editServerAddress;
    CButton m_checkEnable;
    CEdit m_editQueryUUID;
    CEdit m_editHealthCode;
    afx_msg void OnBnClickedBtnGetHealthCode();
    CEdit m_editHealthCodeResult;
    afx_msg void OnBnClickedBtnSetHealthCodeResult();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGHEALTHCODE_H__56FD51F1_AB1B_40AC_8C62_E1DC04846EF7__INCLUDED_)
