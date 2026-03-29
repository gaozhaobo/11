#if !defined(AFX_PWM_VAO_H__8F89E439_FC55_45C6_82BF_EBB2D663DE48__INCLUDED_)
#define AFX_PWM_VAO_H__8F89E439_FC55_45C6_82BF_EBB2D663DE48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PWM_VAO.h : header file
//


//Adlink head file////////
#include "APS168.h"
#include "ErrorCodeDef.h"
#include "APS_define.h"
#include "type_def.h"
//////////////////////////
#include "Motion.h"


/////////////////////////////////////////////////////////////////////////////
// CPWM_VAO dialog

class CPWM_VAO : public CDialog
{
// Construction
public:
	CPWM_VAO(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPWM_VAO)
	enum { IDD = IDD_PWM_VAO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPWM_VAO)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPWM_VAO)
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void pwm();
	afx_msg void VAO_ON();
	afx_msg void VAO_OFF();
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
	I32 Is_thread_ON;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PWM_VAO_H__8F89E439_FC55_45C6_82BF_EBB2D663DE48__INCLUDED_)
