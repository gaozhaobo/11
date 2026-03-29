// basic_samples.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cbasic_samplesApp:
// See basic_samples.cpp for the implementation of this class
//

class Cbasic_samplesApp : public CWinApp
{
public:
	Cbasic_samplesApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cbasic_samplesApp theApp;