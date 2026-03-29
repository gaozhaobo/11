// basic_sample.h : main header file for the BASIC_SAMPLE application
//

#if !defined(AFX_BASIC_SAMPLE_H__D6BCD8AA_2150_4B22_98B3_45DD2BB378B9__INCLUDED_)
#define AFX_BASIC_SAMPLE_H__D6BCD8AA_2150_4B22_98B3_45DD2BB378B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBasic_sampleApp:
// See basic_sample.cpp for the implementation of this class
//

class CBasic_sampleApp : public CWinApp
{
public:
	CBasic_sampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasic_sampleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBasic_sampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASIC_SAMPLE_H__D6BCD8AA_2150_4B22_98B3_45DD2BB378B9__INCLUDED_)
