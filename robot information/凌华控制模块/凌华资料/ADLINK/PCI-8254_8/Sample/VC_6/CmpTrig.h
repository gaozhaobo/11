#if !defined(AFX_CMPTRIG_H__6401DC0A_8171_4072_A461_D1B82B5ADF93__INCLUDED_)
#define AFX_CMPTRIG_H__6401DC0A_8171_4072_A461_D1B82B5ADF93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CmpTrig.h : header file
//

//Adlink head file////////
#include "APS168.h"
#include "ErrorCodeDef.h"
#include "APS_define.h"
#include "type_def.h"
//////////////////////////
#include "Motion.h"

/////////////////////////////////////////////////////////////////////////////
// CCmpTrig dialog

class CCmpTrig : public CDialog
{
// Construction
public:
	CCmpTrig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCmpTrig)
	enum { IDD = IDD_Cmp_Trig };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmpTrig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCmpTrig)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void reset();
	afx_msg void stop();
	afx_msg void clear();
	afx_msg void manual();
	afx_msg void linear();
	afx_msg void table();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    ////Main form data/////////////////////////////////////////////////////////////
    #define YES (1)
    #define NO  (0)
    #define ON  (1)
    #define OFF (0)

    I32 v_card_name;
    I32 v_board_id;         
    I32 v_channel;           
    I32 v_total_axis;        
    I32 v_is_card_initialed;
    //////////////////////////////////////////////////////////////////////////////////
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMPTRIG_H__6401DC0A_8171_4072_A461_D1B82B5ADF93__INCLUDED_)
