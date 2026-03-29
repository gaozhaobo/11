// Get_Version.cpp : implementation file
//

#include "stdafx.h"
#include "basic_sample.h"
#include "Get_Version.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGet_Version dialog


CGet_Version::CGet_Version(CWnd* pParent /*=NULL*/)
	: CDialog(CGet_Version::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGet_Version)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	
}


void CGet_Version::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGet_Version)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGet_Version, CDialog)
	//{{AFX_MSG_MAP(CGet_Version)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGet_Version message handlers

void CGet_Version::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	I32 Board_ID = v_board_id;
	I32 Array[5] = {0};
    CString str;


	get_version_info(  Board_ID, Array );
	
	SetDlgItemInt( IDC_EDIT1, Array[0]);
	SetDlgItemInt( IDC_EDIT2, Array[1]);
	SetDlgItemInt( IDC_EDIT3, Array[2]);

	str.Format( "0x%x", Array[3] );
    SetDlgItemText( IDC_EDIT4, (LPCTSTR)str);

	SetDlgItemInt( IDC_EDIT5, Array[4]);

	CDialog::OnTimer(nIDEvent);
}

int CGet_Version::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here

	SetTimer( 0, 1, NULL );

	return 0;
}

void CGet_Version::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	KillTimer(0);
	
	CDialog::OnClose();
}
