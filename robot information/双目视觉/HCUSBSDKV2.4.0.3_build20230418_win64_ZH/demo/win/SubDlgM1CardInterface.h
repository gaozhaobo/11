#if !defined(AFX_SUBDLGM1CARDINTERFACE_H__B6E60E7C_0F82_4A60_BAA2_0A3799A0A531__INCLUDED_)
#define AFX_SUBDLGM1CARDINTERFACE_H__B6E60E7C_0F82_4A60_BAA2_0A3799A0A531__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDlgM1CardInterface.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SubDlgM1CardInterface dialog

class SubDlgM1CardInterface : public CDialog
{
// Construction
public:
    SubDlgM1CardInterface(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(SubDlgM1CardInterface)
    enum { IDD = IDD_SUBDLG_M1_CARD_INTERFACE };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(SubDlgM1CardInterface)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(SubDlgM1CardInterface)
    afx_msg void OnBtnM1PwdVerify();
    afx_msg void OnBtnReadBlock();
    afx_msg void OnBtnModBlock();
    afx_msg void OnBtnBlockAdd();
    afx_msg void OnBtnBlockMinus();
    afx_msg void OnBtnEepromToReg();
    afx_msg void OnBtnRegToEeprom();
    afx_msg void OnBtnMifarePack();
	afx_msg void OnBtnWriteBlock();
	afx_msg void OnPaint();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    afx_msg void OnBnClickedBtnM1SectionEncrypt();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLGM1CARDINTERFACE_H__B6E60E7C_0F82_4A60_BAA2_0A3799A0A531__INCLUDED_)
