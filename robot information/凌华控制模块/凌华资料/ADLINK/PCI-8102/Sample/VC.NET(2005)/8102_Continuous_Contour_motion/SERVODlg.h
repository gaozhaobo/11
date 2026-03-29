// SERVODlg.h : header file
//

#if !defined(AFX_SERVODLG_H__9F819BE7_8E96_11D4_8707_9D7D7EA60644__INCLUDED_)
#define AFX_SERVODLG_H__9F819BE7_8E96_11D4_8707_9D7D7EA60644__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CSERVODlg dialog

class CSERVODlg : public CDialog
{
// Construction
public:
	CSERVODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSERVODlg)
	enum { IDD = IDD_SERVO_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSERVODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSERVODlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSvon();
	afx_msg void OnSvoff();
	afx_msg void OnPrmove();
	afx_msg void OnMrmove();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnOK();
	afx_msg void OnHome();
	afx_msg void OnStop();
	afx_msg void OnCut();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVODLG_H__9F819BE7_8E96_11D4_8707_9D7D7EA60644__INCLUDED_)
