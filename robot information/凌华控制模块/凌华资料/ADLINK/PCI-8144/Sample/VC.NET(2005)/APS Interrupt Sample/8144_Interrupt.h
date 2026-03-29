// 8144_Interrupt.h : main header file for the 8144_INTERRUPT application
//

#if !defined(AFX_8144_INTERRUPT_H__E15B945B_D757_4686_A322_26ED7CA4EB41__INCLUDED_)
#define AFX_8144_INTERRUPT_H__E15B945B_D757_4686_A322_26ED7CA4EB41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy8144_InterruptApp:
// See 8144_Interrupt.cpp for the implementation of this class
//

class CMy8144_InterruptApp : public CWinApp
{
public:
	CMy8144_InterruptApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy8144_InterruptApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy8144_InterruptApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_8144_INTERRUPT_H__E15B945B_D757_4686_A322_26ED7CA4EB41__INCLUDED_)
