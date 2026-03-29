// PCI7856DiInterrupt.h : main header file for the PCI7856DIINTERRUPT application
//

#if !defined(AFX_PCI7856DIINTERRUPT_H__A6A24F20_8484_434A_BAAE_658E9B0F9F39__INCLUDED_)
#define AFX_PCI7856DIINTERRUPT_H__A6A24F20_8484_434A_BAAE_658E9B0F9F39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPCI7856DiInterruptApp:
// See PCI7856DiInterrupt.cpp for the implementation of this class
//

class CPCI7856DiInterruptApp : public CWinApp
{
public:
	CPCI7856DiInterruptApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCI7856DiInterruptApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPCI7856DiInterruptApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCI7856DIINTERRUPT_H__A6A24F20_8484_434A_BAAE_658E9B0F9F39__INCLUDED_)
