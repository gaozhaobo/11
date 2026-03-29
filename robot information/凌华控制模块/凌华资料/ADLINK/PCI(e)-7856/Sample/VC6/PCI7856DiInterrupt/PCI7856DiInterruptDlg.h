// PCI7856DiInterruptDlg.h : header file
//

#if !defined(AFX_PCI7856DIINTERRUPTDLG_H__EB347649_91D5_4110_BC8E_822BC2342162__INCLUDED_)
#define AFX_PCI7856DIINTERRUPTDLG_H__EB347649_91D5_4110_BC8E_822BC2342162__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPCI7856DiInterruptDlg dialog

class CPCI7856DiInterruptDlg : public CDialog
{
// Construction
public:
	CPCI7856DiInterruptDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPCI7856DiInterruptDlg)
	enum { IDD = IDD_PCI7856DIINTERRUPT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCI7856DiInterruptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

private:
//******************************************
#define BIT_INIT		(0)
#define BIT_CONNECT		(4)
#define BIT_ENABLE		(8)
#define BIT_CFG			(12)
#define BIT_WAIT		(16)

	//Bit 0: initial / close		(Main state)
	//BIt 4: connect / disconnect	(sub state )
	I32 mState;   // State of application.
//******************************************

	

public:
//**** State define ******************
#define STA_CLOSED		(0) //0x0000?
#define STA_INIT		(1) //0x0000?
#define STA_CONNECT		(2) //0x000?0
#define STA_DISCONNECT	(3) //0x000?0
#define STA_INTEN		(4) //0x00?00
#define STA_INTDIS		(5) //0x00?00
#define STA_CFG			(6) //0x0?000
#define STA_NOTCFG		(7) //0x0?000
#define STA_WAIT		(8) //0x?0000
#define STA_WAITDONE	(9) //0x?0000

	void mSetState( I32 mState );
//***********************************
	
	void mUIChange();

	int  mIsInitial();
	int  mIsConnect();
	int  mIsEnable();
	int  mIsConfig();
	int  mIsWait();

	I32 mCardId; // device card ID
	I32 mHslBus; // HSL bus number
	I32 mModule; // HSL module number;
	I32 mIntHandle; 
	
	HANDLE mThreadHandle;
	DWORD  mThreadId;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPCI7856DiInterruptDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCI7856DIINTERRUPTDLG_H__EB347649_91D5_4110_BC8E_822BC2342162__INCLUDED_)
