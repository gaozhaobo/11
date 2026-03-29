#if !defined(AFX_SUBDLGCPUPSAMCARDINTERFACE_H__445994CC_B115_4DE3_A451_8714737FF6F9__INCLUDED_)
#define AFX_SUBDLGCPUPSAMCARDINTERFACE_H__445994CC_B115_4DE3_A451_8714737FF6F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDlgCpuPsamCardInterface.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubDlgCpuPsamCardInterface dialog

class CSubDlgCpuPsamCardInterface : public CDialog
{
// Construction
public:
    CSubDlgCpuPsamCardInterface(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CSubDlgCpuPsamCardInterface)
    enum { IDD = IDD_SUBDLG_CPU_PSAM_CARD_INTERFACE };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSubDlgCpuPsamCardInterface)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CSubDlgCpuPsamCardInterface)
    afx_msg void OnBtnPsamSockSel();
    afx_msg void OnBtnCardParamCfg();
    afx_msg void OnBtnCpuCardData();
    afx_msg void OnBtnResetCpuCard();
	afx_msg void OnBtnCpuCardEncryptCfg();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:

    LONG m_lUserID;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLGCPUPSAMCARDINTERFACE_H__445994CC_B115_4DE3_A451_8714737FF6F9__INCLUDED_)
