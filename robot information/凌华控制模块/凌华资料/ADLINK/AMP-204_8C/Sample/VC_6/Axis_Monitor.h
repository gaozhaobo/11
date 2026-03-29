#if !defined(AFX_AXIS_MONITOR_H__F8042B48_F3CD_4170_9FC8_3AB1CF36398F__INCLUDED_)
#define AFX_AXIS_MONITOR_H__F8042B48_F3CD_4170_9FC8_3AB1CF36398F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Axis_Monitor.h : header file
//



//Adlink head file////////
#include "APS168.h"
#include "ErrorCodeDef.h"
#include "APS_define.h"
#include "type_def.h"
//////////////////////////
#include "Motion.h"


/////////////////////////////////////////////////////////////////////////////
// CAxis_Monitor dialog
class CAxis_Monitor : public CDialog
{
// Construction
public:
	CAxis_Monitor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAxis_Monitor)
	enum { IDD = IDD_axis_monitor };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAxis_Monitor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAxis_Monitor)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void servo_on();
	afx_msg void servo_off();
	afx_msg void reset_counter();
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

#endif // !defined(AFX_AXIS_MONITOR_H__F8042B48_F3CD_4170_9FC8_3AB1CF36398F__INCLUDED_)
