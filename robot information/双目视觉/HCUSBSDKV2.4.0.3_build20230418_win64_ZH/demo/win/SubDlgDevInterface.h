#if !defined(AFX_SUBDLGDEVINTERFACE_H__D21199FA_C75F_4C3D_8F46_31696BFD1FF2__INCLUDED_)
#define AFX_SUBDLGDEVINTERFACE_H__D21199FA_C75F_4C3D_8F46_31696BFD1FF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDlgDevInterface.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SubDlgDevInterface dialog

class SubDlgDevInterface : public CDialog
{
// Construction
public:
    SubDlgDevInterface(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(SubDlgDevInterface)
    enum { IDD = IDD_SUBDLG_DEV_INTERFACE };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(SubDlgDevInterface)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(SubDlgDevInterface)
    afx_msg void OnBtnBeepAndFlicker();
    afx_msg void OnBtnGetHairpinVer();
    afx_msg void OnBtnResetRfc();
    afx_msg void OnBtnRegDevice();
	afx_msg void OnBtnSetDevKey();
	afx_msg void OnBtnUpgrade();
	afx_msg void OnPaint();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLGDEVINTERFACE_H__D21199FA_C75F_4C3D_8F46_31696BFD1FF2__INCLUDED_)
