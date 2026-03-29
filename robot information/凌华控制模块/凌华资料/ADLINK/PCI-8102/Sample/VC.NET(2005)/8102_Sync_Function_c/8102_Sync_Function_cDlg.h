// 8102_Sync_Function_cDlg.h : header file
//

#if !defined(AFX_8102_SYNC_FUNCTION_CDLG_H__3065D7E7_120F_4E1F_96DA_FD82F6D1961A__INCLUDED_)
#define AFX_8102_SYNC_FUNCTION_CDLG_H__3065D7E7_120F_4E1F_96DA_FD82F6D1961A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy8102_Sync_Function_cDlg dialog

class CMy8102_Sync_Function_cDlg : public CDialog
{
// Construction
public:
	CMy8102_Sync_Function_cDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy8102_Sync_Function_cDlg)
	enum { IDD = IDD_MY8102_SYNC_FUNCTION_C_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8102_Sync_Function_cDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy8102_Sync_Function_cDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnOk7();
	afx_msg void OnOk8();
	afx_msg void OnOk2();
	afx_msg void OnOk3();
	afx_msg void OnOk4();
	afx_msg void OnOk5();
	afx_msg void OnOk6();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8102_SYNC_FUNCTION_CDLG_H__3065D7E7_120F_4E1F_96DA_FD82F6D1961A__INCLUDED_)
