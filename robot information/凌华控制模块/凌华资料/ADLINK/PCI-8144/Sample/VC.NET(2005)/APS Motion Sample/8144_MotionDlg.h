// 8144_MotionDlg.h : header file
//

#if !defined(AFX_8144_MOTIONDLG_H__D76B114C_1E1D_44DE_BF24_EE46BF216B05__INCLUDED_)
#define AFX_8144_MOTIONDLG_H__D76B114C_1E1D_44DE_BF24_EE46BF216B05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy8144_MotionDlg dialog

class CMy8144_MotionDlg : public CDialog
{
// Construction
public:
	CMy8144_MotionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy8144_MotionDlg)
	enum { IDD = IDD_MY8144_MOTION_DIALOG };
	double	m_TvStr;
	double	m_TvMaxVel;
	double	m_TvTacc;
	UINT	m_TrDis;
	double	m_TrMaxVel;
	DWORD	m_TrStr;
	float	m_TrTacc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8144_MotionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy8144_MotionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnExit();
	afx_msg void OnBtnStop();
	afx_msg void OnBtnTvStart();
	afx_msg void OnBtnTrStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBtn_SetInt();
	afx_msg void OnBtn_StopInterrupt();
	afx_msg void OnBtn_WaitInterrupt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8144_MOTIONDLG_H__D76B114C_1E1D_44DE_BF24_EE46BF216B05__INCLUDED_)
