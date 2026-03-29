// MotionNetInterruptDlg.h : header file
//

#if !defined(AFX_MOTIONNETINTERRUPTDLG_H__F9FD81D0_D852_4C52_A107_F354BD401D67__INCLUDED_)
#define AFX_MOTIONNETINTERRUPTDLG_H__F9FD81D0_D852_4C52_A107_F354BD401D67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMotionNetInterruptDlg dialog

class CMotionNetInterruptDlg : public CDialog
{
// Construction
public:
	CMotionNetInterruptDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMotionNetInterruptDlg)
	enum { IDD = IDD_MOTIONNETINTERRUPT_DIALOG };
	long	m_edit_cmd;
	long	m_edit_pos;
	long	m_edit_sts;
	long	m_edit_io;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMotionNetInterruptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMotionNetInterruptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton5();
	afx_msg void OnButton4();
	afx_msg void OnButton8();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton9();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// ADLINK SAMPLE CODE 
public:
	void m_InterfaceCtrl();
	int  m_leave(){ return m_isLeaveThread; }//leave thread, return __YES else return __NO;
	void f_resetText();
	void f_addText( CString &Str );
	I32  m_intNum;

private:
	I32 m_cardId;
	I32 m_axisId; // fieldbus axis ID (also the meaning of interrupt factor item number)
	
	HANDLE m_threadHandle;
	DWORD  m_threadId;
	

	// The following variable will be update when scan
	// Reset at disconnect.
	I32 m_totalSlave;
	I32 m_totalMotionAxes;

#define __NO    (0)
#define __YES   (1)
	int m_isInitial;     // Is device initialed? (Yes or No)
	int m_isConnect;     // Is fieldbus connected? (Yes or No)
	int m_isIntEnable;   // Is interrupt main switch enable? (Yes or No)
	int m_isLeaveThread; // Is user want to leave thread? (Yes or No)
	int m_isSetFactor;   // Is user set interrupt factor? (Yes or No)
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOTIONNETINTERRUPTDLG_H__F9FD81D0_D852_4C52_A107_F354BD401D67__INCLUDED_)
