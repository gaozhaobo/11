#if !defined(AFX_GET_VERSION_H__E148B561_4491_49DA_B314_06A93E5060E0__INCLUDED_)
#define AFX_GET_VERSION_H__E148B561_4491_49DA_B314_06A93E5060E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Get_Version.h : header file
//



//Adlink head file////////
#include "APS168.h"
#include "ErrorCodeDef.h"
#include "APS_define.h"
#include "type_def.h"
//////////////////////////
#include "Motion.h"




/////////////////////////////////////////////////////////////////////////////
// CGet_Version dialog

class CGet_Version : public CDialog
{
// Construction
public:
	CGet_Version(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGet_Version)
	enum { IDD = IDD_Get_Version };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_Version)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGet_Version)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	HICON m_hIcon;

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

#endif // !defined(AFX_GET_VERSION_H__E148B561_4491_49DA_B314_06A93E5060E0__INCLUDED_)
