// MNET_4XMO_C_VC_SampleDlg.h : header file
//

#if !defined(AFX_MNET_4XMO_C_VC_SAMPLEDLG_H__82A92184_E37C_4F36_920E_C35596A60CEB__INCLUDED_)
#define AFX_MNET_4XMO_C_VC_SAMPLEDLG_H__82A92184_E37C_4F36_920E_C35596A60CEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMNET_4XMO_C_VC_SampleDlg dialog

class CMNET_4XMO_C_VC_SampleDlg : public CDialog
{
// Construction
public:
	CMNET_4XMO_C_VC_SampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMNET_4XMO_C_VC_SampleDlg)
	enum { IDD = IDD_MNET_4XMO_C_VC_SAMPLE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMNET_4XMO_C_VC_SampleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMNET_4XMO_C_VC_SampleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBusConnect();
	afx_msg void OnBusDisconnect();
	afx_msg void OnGetModuleInfo();
	afx_msg void OnSingleAbsoluteMoveBackward();
	afx_msg void OnSingleAbsoluteMoveForward();
	afx_msg void OnSingleAbsoluteMoveStop();
	afx_msg void OnSingleRelativeMoveBackward();
	afx_msg void OnSingleRelativeMoveForward();
	afx_msg void OnSingleRelativeMoveStop();
	afx_msg void OnSingleHomeMoveBackward();
	afx_msg void OnSingleHomeMoveForward();
	afx_msg void OnSingleHomeMoveStop();
	afx_msg void OnLinear2AxesAbsoluteBackward();
	afx_msg void OnLinear2AxesAbsoluteForward();
	afx_msg void OnLinear2AxesAbsoluteStop();
	afx_msg void OnLinear2AxesRelateiveBackward();
	afx_msg void OnLinear2AxesRelateiveForward();
	afx_msg void OnLinear2AxesRelateiveStop();
	afx_msg void OnLinear3AxesAbsoluteBackward();
	afx_msg void OnLinear3AxesAbsoluteForward();
	afx_msg void OnLinear3AxesAbsoluteStop();
	afx_msg void OnLinear3AxesRelateiveBackward();
	afx_msg void OnLinear3AxesRelateiveForward();
	afx_msg void OnLinear3AxesRelateiveStop();
	afx_msg void OnLinear4AxesAbsoluteBackward();
	afx_msg void OnLinear4AxesAbsoluteForward();
	afx_msg void OnLinear4AxesAbsoluteStop();
	afx_msg void OnLinear4AxesRelateiveBackward();
	afx_msg void OnLinear4AxesRelateiveForward();
	afx_msg void OnLinear4AxesRelateiveStop();
	afx_msg void OnSetPointTable();
	afx_msg void OnPointTableSingleIndexMove();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void Function_Result(int Ret);
	afx_msg void OnResetCounter();
	afx_msg void OnPointTableMoveALL();
	afx_msg void OnPointTableStop();
	afx_msg void OnLinearCompare();
	afx_msg void OnTriggerCount();
	afx_msg void OnTableCompare();
	afx_msg void OnManualCompare();
	afx_msg void OnArc2AxesAbsoluteCCW();
	afx_msg void OnArc2AxesAbsoluteCW();
	afx_msg void OnArc2AxesAbsoluteStop2();
	afx_msg void OnArc2AxesRelateiveStop();
	afx_msg void OnArc2AxesRelativeCCW();
	afx_msg void OnArc2AxesRelativeCW();
	afx_msg void OnSetDOData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MNET_4XMO_C_VC_SAMPLEDLG_H__82A92184_E37C_4F36_920E_C35596A60CEB__INCLUDED_)
