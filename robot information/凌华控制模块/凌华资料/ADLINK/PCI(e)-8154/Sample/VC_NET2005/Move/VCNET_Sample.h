// VCNET_Sample.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CVCNET_SampleApp:
// See VCNET_Sample.cpp for the implementation of this class
//

class CVCNET_SampleApp : public CWinApp
{
public:
	CVCNET_SampleApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CVCNET_SampleApp theApp;