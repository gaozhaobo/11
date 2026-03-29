#pragma once
#include "Resource.h"
#include "afxwin.h"

// CDlgFileTransfer 对话框

class CDlgFileTransfer : public CDialog
{
	DECLARE_DYNAMIC(CDlgFileTransfer)

public:
	CDlgFileTransfer(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFileTransfer();

// 对话框数据
	enum { IDD = IDD_DLG_FILE_TRANSFER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    afx_msg void OnBnClickedBtnSelectEncryptFile();
    afx_msg void OnBnClickedBtnSelectUploadFile();
    afx_msg void OnBnClickedBtnFileTransferStart();
    CString m_szEncryptFilePath;
    CString m_szUploadFilePath;
};
