#if !defined(AFX_DlgM1RegToBlock_H__E028B0F8_7DBC_4B76_9295_C8C9E2EEB483__INCLUDED_)
#define AFX_DlgM1RegToBlock_H__E028B0F8_7DBC_4B76_9295_C8C9E2EEB483__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgM1RegToBlock.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgM1RegToBlock dialog

class CDlgM1RegToBlock : public CDialog
{
// Construction
public:
    CDlgM1RegToBlock(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgM1RegToBlock)
    enum { IDD = IDD_DLG_M1_REG_2_EEPROM };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    DWORD       m_dwBlockAddr;


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgM1RegToBlock)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgM1BlockMinus)
    afx_msg void OnBtnOk();
	afx_msg void OnPaint();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
        
        
public:
    LONG m_lUserID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgM1RegToBlock_H__E028B0F8_7DBC_4B76_9295_C8C9E2EEB483__INCLUDED_)
