#if !defined(AFX_DLGCPUCARDPACK_H__3BCCC1FA_B2EF_4F3E_9F67_A00CDBC166C3__INCLUDED_)
#define AFX_DLGCPUCARDPACK_H__3BCCC1FA_B2EF_4F3E_9F67_A00CDBC166C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCPUCardPack.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCPUCardPack dialog

class CDlgCPUCardPack : public CDialog
{
// Construction
public:
    CDlgCPUCardPack(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
    //{{AFX_DATA(CDlgCPUCardPack)
    enum { IDD = IDD_DLG_CPU_CARD_PACK };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    
    char m_szBuf[1024];

    DWORD m_dwDataLen;
    DWORD m_dwDelay;

    CEdit m_edtData;
    CString m_csData;
    BOOL m_bChange;
    
    void PrintData(BYTE* pBuffer, const DWORD dwSize);
    BOOL CheckIsNum(char c);

    char ConvertKey(int nKey);
    
    BOOL PreTranslateMessage(MSG* pMsg);
    
    BOOL DoNumberInput(int cKey);
    BOOL DoCtrlV();


// Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CDlgCPUCardPack)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:

    BOOL OnInitDialog();
    // Generated message map functions
    //{{AFX_MSG(CDlgCPUCardPack)
    afx_msg void OnBtnGet();
    afx_msg void OnBtnSet();
    afx_msg void OnKillfocusEdtDataLen();
	//}}AFX_MSG
    DECLARE_MESSAGE_MAP()

        
public:
    LONG m_lUserID;
    afx_msg void OnPaint();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCPUCARDPACK_H__3BCCC1FA_B2EF_4F3E_9F67_A00CDBC166C3__INCLUDED_)
