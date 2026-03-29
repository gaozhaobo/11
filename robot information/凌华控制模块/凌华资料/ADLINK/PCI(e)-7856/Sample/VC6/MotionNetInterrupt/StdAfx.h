// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__C84CAFF2_2572_4815_9139_47049CAFE4F6__INCLUDED_)
#define AFX_STDAFX_H__C84CAFF2_2572_4815_9139_47049CAFE4F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

// ADLINK SAMPLE CODE 
#include "APS168.h"
#include "ErrorCodeDef.h"

#define _MNET_BUS_NUM   ((I32)(1))
#define _START_AXIS_ID	(1000)


//#define _VIRTUAL_FUNCTIONS
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C84CAFF2_2572_4815_9139_47049CAFE4F6__INCLUDED_)
