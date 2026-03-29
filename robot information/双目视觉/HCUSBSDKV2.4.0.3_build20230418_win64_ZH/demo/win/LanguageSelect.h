#pragma once

#include "resource.h"
// CLanguageSelect 对话框

class CLanguageSelect : public CDialog
{
	DECLARE_DYNAMIC(CLanguageSelect)

public:
	CLanguageSelect(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLanguageSelect();

// 对话框数据
	enum { IDD = IDD_DIG_SELECT_LANGUAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLanguageOk();
	afx_msg void OnBnClickedRadioCh();
	afx_msg void OnBnClickedRadioEn();
	afx_msg void OnPaint();
};
