// 2D_triggerDlg.h : header file
//
#include "APS168.h"


#pragma once

#define	TGR_TRG0_SRC	0x10
#define TGR_TRG1_SRC	0x11
#define TGR_TRG2_SRC	0x12
#define TGR_TRG3_SRC	0x13

#define TGR_MCMP0_SRC	0x30
#define TGR_MCMP1_SRC	0x31
#define TGR_MCMP2_SRC	0x32
#define TGR_MCMP3_SRC	0x33


// CMy2D_triggerDlg dialog
class CMy2D_triggerDlg : public CDialog
{
// Construction
public:
	CMy2D_triggerDlg(CWnd* pParent = NULL);	// standard constructor
	I32 BoardID;
	U32 dimension;

// Dialog Data
	enum { IDD = IDD_MY2D_TRIGGER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
