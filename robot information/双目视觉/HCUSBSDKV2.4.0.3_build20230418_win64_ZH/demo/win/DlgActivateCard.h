#if !defined(AFX_DLGACTIVATECARD_H__FE6A5634_A241_469E_A13E_7BB3353FC508__INCLUDED_)
#define AFX_DLGACTIVATECARD_H__FE6A5634_A241_469E_A13E_7BB3353FC508__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgActivateCard.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgActivateCard dialog

class CDlgActivateCard : public CDialog
{
// Construction
public:
    CDlgActivateCard(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgActivateCard)
    enum { IDD = IDD_DLG_ACTIVATE_CARD };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA
    DWORD   m_dwWaitSecond;
    CString m_csCardProto;
    DWORD   m_dwSerialLen;
    CString m_csSerial;
    DWORD   m_dwSelVerifyLen;
    CString m_csSelVerify;
    HANDLE  m_handle;	//循环激活子线程句柄
    int     m_iStopButton;
    USB_WAIT_SECOND m_struWaitSecond;
    USB_ACTIVATE_CARD_RES m_struActivateRes;
    USB_CONFIG_INPUT_INFO m_struInput;
    USB_CONFIG_OUTPUT_INFO m_struOutput;

private:
    static DWORD WINAPI CircleActivateThread(LPVOID pM);	// 子线程：循环激活

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgActivateCard)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();

    // Generated message map functions
    //{{AFX_MSG(CDlgActivateCard)
    afx_msg void OnBtnActivate();
	afx_msg void OnBtnActivate2();
	afx_msg void OnBtnStopActivate();
	afx_msg void OnPaint();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGACTIVATECARD_H__FE6A5634_A241_469E_A13E_7BB3353FC508__INCLUDED_)
