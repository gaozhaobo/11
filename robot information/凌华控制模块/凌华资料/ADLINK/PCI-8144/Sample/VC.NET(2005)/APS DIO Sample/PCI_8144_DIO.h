// PCI_8144_DIO.h : main header file for the PCI_8144_DIO application
//

#if !defined(AFX_PCI_8144_DIO_H__E1900F0B_22AA_4FAC_96F4_A8BFD1023C4F__INCLUDED_)
#define AFX_PCI_8144_DIO_H__E1900F0B_22AA_4FAC_96F4_A8BFD1023C4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPCI_8144_DIOApp:
// See PCI_8144_DIO.cpp for the implementation of this class
//

class CPCI_8144_DIOApp : public CWinApp
{
public:
	CPCI_8144_DIOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPCI_8144_DIOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPCI_8144_DIOApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PCI_8144_DIO_H__E1900F0B_22AA_4FAC_96F4_A8BFD1023C4F__INCLUDED_)
