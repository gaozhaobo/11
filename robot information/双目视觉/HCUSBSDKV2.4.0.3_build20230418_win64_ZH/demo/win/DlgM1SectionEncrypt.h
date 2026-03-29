#pragma once
#include "afxwin.h"


// CDlgM1SectionEncrypt 对话框

class CDlgM1SectionEncrypt : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgM1SectionEncrypt)

public:
	CDlgM1SectionEncrypt(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgM1SectionEncrypt();

// 对话框数据
	enum { IDD = IDD_DLG_M1_SECTION_ENCRYPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
    LONG m_lUserID;
    afx_msg void OnBnClickedBtnSend();
	afx_msg void OnPaint();
    DWORD m_dwSectionID;
    CComboBox m_comKeyType;
    CComboBox m_comNewKeyType;
    CString m_csKeyAContent;
    CString m_csNewKeyAContent;
    CString m_csCtrlBits;
    CString m_csNewKeyBContent;
    virtual BOOL OnInitDialog();
};
