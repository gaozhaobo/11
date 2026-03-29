// 8144_Motion.h : main header file for the 8144_MOTION application
//

#if !defined(AFX_8144_MOTION_H__CC473847_AE73_49B3_AAE8_91481C0A6E90__INCLUDED_)
#define AFX_8144_MOTION_H__CC473847_AE73_49B3_AAE8_91481C0A6E90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "APS168.h"
#include "APS_Define.h"

/////////////////////////////////////////////////////////////////////////////
// CMy8144_MotionApp:
// See 8144_Motion.cpp for the implementation of this class
//

class CMy8144_MotionApp : public CWinApp
{
public:
	CMy8144_MotionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8144_MotionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy8144_MotionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8144_MOTION_H__CC473847_AE73_49B3_AAE8_91481C0A6E90__INCLUDED_)
