// 8144_InterruptDlg.h : header file
//

#if !defined(AFX_8144_INTERRUPTDLG_H__1205FBC6_EE27_4700_9512_129E3CC030A4__INCLUDED_)
#define AFX_8144_INTERRUPTDLG_H__1205FBC6_EE27_4700_9512_129E3CC030A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy8144_InterruptDlg dialog

class CMy8144_InterruptDlg : public CDialog
{
// Construction
public:
	void Check_Counter();
	CMy8144_InterruptDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy8144_InterruptDlg)
	enum { IDD = IDD_MY8144_INTERRUPT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8144_InterruptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy8144_InterruptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBtn_SetFactor();
	afx_msg void OnBtn_ResetFactor();
	afx_msg void OnBtn_ResetCounter();
	afx_msg void OnBtn_WaitInterrupt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8144_INTERRUPTDLG_H__1205FBC6_EE27_4700_9512_129E3CC030A4__INCLUDED_)
