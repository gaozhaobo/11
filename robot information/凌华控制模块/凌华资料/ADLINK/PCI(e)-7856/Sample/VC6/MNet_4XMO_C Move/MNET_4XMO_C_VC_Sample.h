// MNET_4XMO_C_VC_Sample.h : main header file for the MNET_4XMO_C_VC_SAMPLE application
//

#if !defined(AFX_MNET_4XMO_C_VC_SAMPLE_H__86EA570E_0C15_4ED0_8066_543CA4D72416__INCLUDED_)
#define AFX_MNET_4XMO_C_VC_SAMPLE_H__86EA570E_0C15_4ED0_8066_543CA4D72416__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMNET_4XMO_C_VC_SampleApp:
// See MNET_4XMO_C_VC_Sample.cpp for the implementation of this class
//

class CMNET_4XMO_C_VC_SampleApp : public CWinApp
{
public:
	CMNET_4XMO_C_VC_SampleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMNET_4XMO_C_VC_SampleApp)
	public:
	virtual BOOL InitInstance();
	
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMNET_4XMO_C_VC_SampleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MNET_4XMO_C_VC_SAMPLE_H__86EA570E_0C15_4ED0_8066_543CA4D72416__INCLUDED_)
