// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__C0813DEB_28F1_4376_B406_18652C09B525__INCLUDED_)
#define AFX_STDAFX_H__C0813DEB_28F1_4376_B406_18652C09B525__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
#define  WINVER       0x0501 

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "HCUsbSDK.h"
#include "cjson/cJSON.h"
#include "xml/tinystr.h"
#include "xml/tinyxml.h"
#include "xml/XmlBase.h"
#include "GlobalCtrl.h"
#include <afxcontrolbars.h>

 


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__C0813DEB_28F1_4376_B406_18652C09B525__INCLUDED_)
