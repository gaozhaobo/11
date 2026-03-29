#pragma once
#include "afxwin.h"


// CISAPITransConfig 对话框

class CDlgTransConfig : public CDialog
{
	DECLARE_DYNAMIC(CDlgTransConfig)

public:
	CDlgTransConfig(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgTransConfig();

    BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_DLG_TRANSCONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedButtonExit();
    afx_msg void OnBnClickedButtonOperation();

    LONG m_lUserID;
private:
    CComboBox m_ComboBoxRequestType;

    CString m_strRequestURL;
    CString m_strRequestParam;
    CString m_strOutParam;

    const unsigned int m_dwMaxBufLen = 1024 * 1024;
    char *m_pInBuf;
    char *m_pOutBuf;
    char *m_pDataBuf;
    char m_szExePath[MAX_PATH];
public:
    afx_msg void OnCbnSelchangeComboRequestType();
    afx_msg void OnBnClickedBtnSelectFile();
    CString m_strFilePath;
    BOOL m_bInputFileData;
    BOOL m_bMimeData;
    DWORD m_dwRecvTimeOut;
    CComboBox m_cmbMimeType;
    afx_msg void OnPaint();
};
