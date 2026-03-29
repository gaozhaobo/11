// VCNET_SampleDlg.h : header file
//

#pragma once


// CVCNET_SampleDlg dialog
class CVCNET_SampleDlg : public CDialog
{
// Construction
public:
	CVCNET_SampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_VCNET_SAMPLE_DIALOG };

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
	afx_msg void Function_Result(int Ret);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedResetcounter();
	afx_msg void OnBnClickedSingleAbsoluteMove_Backward();	
	afx_msg void OnSingleAbsoluteMoveForward();
	afx_msg void OnSingleAbsoluteMoveStop();
	afx_msg void OnBnClickedSinglerelativemoveBackward();
	afx_msg void OnBnClickedSinglerelativemoveForward();
	afx_msg void OnBnClickedSinglerelativemoveStop();
	afx_msg void OnBnClickedSingleabsolutemoveBackward();
	afx_msg void OnBnClickedSinglehomemoveBackward();
	afx_msg void OnBnClickedSinglehomemoveForward();
	afx_msg void OnBnClickedSinglehomemoveStop();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedLinear2axesAbsoluteforward();
	afx_msg void OnBnClickedLinear2axesAbsolutebackward();
	afx_msg void OnBnClickedLinear2axesAbsolutestop();
	afx_msg void OnBnClickedArc2axesAbsoluteCcw();
	afx_msg void OnBnClickedArc2axesAbsoluteCw();
	afx_msg void OnBnClickedArc2axesAbsoluteStop2();
	afx_msg void OnBnClickedArc2axesRelativeCcw();
	afx_msg void OnBnClickedArc2axesRelativeCw();	
	
	afx_msg void OnBnClickedArc2axesRelateiveStop();
	afx_msg void OnBnClickedLinear3axesAbsolutebackward();
	afx_msg void OnBnClickedLinear3axesAbsoluteforward();
	afx_msg void OnBnClickedLinear3axesAbsolutestop();
	afx_msg void OnBnClickedLinear3axesRelateivebackward();
	afx_msg void OnBnClickedLinear3axesRelateiveforward();
	afx_msg void OnBnClickedLinear3axesRelateiveStop();
	afx_msg void OnBnClickedLinear4axesAbsolutebackward();
	afx_msg void OnBnClickedLinear4axesAbsoluteforward();
	afx_msg void OnBnClickedLinear4axesAbsolutestop();
	afx_msg void OnBnClickedLinear4axesRelateivebackward();
	afx_msg void OnBnClickedLinear4axesRelateiveforward();
	afx_msg void OnBnClickedLinear4axesRelateiveStop();
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnBnClickedLinear2axesRelateivebackward();	
	afx_msg void OnBnClickedLinear2axesRelateiveforward();
	afx_msg void OnBnClickedLinear2axesRelateiveStop();
public:
	afx_msg void OnBnClickedPulsereaebenble();
public:
	afx_msg void OnBnClickedPulserrelativemove();
public:
	afx_msg void OnBnClickedPulservelocitymove();
public:
	afx_msg void OnBnClickedPulserhomemove();
};
