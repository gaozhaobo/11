#if !defined(AFX_DLGCPUCARDRESET_H__9C31113C_AEE4_4C21_8594_474FFF9E20BB__INCLUDED_)
#define AFX_DLGCPUCARDRESET_H__9C31113C_AEE4_4C21_8594_474FFF9E20BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCPUCardReset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardReset dialog

class CDlgCPUCardReset : public CDialog
{
// Construction
public:
    CDlgCPUCardReset(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgCPUCardReset)
    enum { IDD = IDD_DLG_CPU_CARD_RESET };
        // NOTE: the ClassWizard will add data members here
    CEdit m_edtData;
    CString m_csData;

    DWORD m_dwDataLen;
    //}}AFX_DATA


    void PrintData(char* pBuffer, const DWORD dwSize);

// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgCPUCardReset)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgCPUCardReset)
    afx_msg void OnBtnReset();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    LONG m_lUserID;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCPUCARDRESET_H__9C31113C_AEE4_4C21_8594_474FFF9E20BB__INCLUDED_)
