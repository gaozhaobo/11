// VC_Sample.h : main header file for the VC_SAMPLE application
//

#if !defined(AFX_VC_SAMPLE_H__86EA570E_0C15_4ED0_8066_543CA4D72416__INCLUDED_)
#define AFX_VC_SAMPLE_H__86EA570E_0C15_4ED0_8066_543CA4D72416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVC_SampleApp:
// See VC_Sample.cpp for the implementation of this class
//

class CVC_SampleApp : public CWinApp
{
public:
	CVC_SampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVC_SampleApp)
	public:
	virtual BOOL InitInstance();
	
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVC_SampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VC_SAMPLE_H__86EA570E_0C15_4ED0_8066_543CA4D72416__INCLUDED_)
