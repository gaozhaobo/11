// 2D_trigger.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMy2D_triggerApp:
// See 2D_trigger.cpp for the implementation of this class
//

class CMy2D_triggerApp : public CWinApp
{
public:
	CMy2D_triggerApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMy2D_triggerApp theApp;