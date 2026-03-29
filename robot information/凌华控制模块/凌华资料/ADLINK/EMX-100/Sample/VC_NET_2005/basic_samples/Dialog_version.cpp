// Dialog_version.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "Dialog_version.h"


// CDialog_version dialog

IMPLEMENT_DYNAMIC(CDialog_version, CDialog)

CDialog_version::CDialog_version(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_version::IDD, pParent)
{

}

CDialog_version::~CDialog_version()
{
}

void CDialog_version::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialog_version, CDialog)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDOK, &CDialog_version::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_version message handlers
#include "sample_emx100.h"
void CDialog_version::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	// TODO: Add your message handler code here
	I32 info[5];
	CString str;

	get_version_info( info, v_card_id );

	SetDlgItemInt( IDC_EDIT1, info[IDX_VER1]      );
	SetDlgItemInt( IDC_EDIT2, info[IDX_VER2]   );
	SetDlgItemInt( IDC_EDIT3, info[IDX_VER3]   );
	SetDlgItemInt( IDC_EDIT4, info[IDX_VER4] );
	SetDlgItemInt( IDC_EDIT5, info[IDX_VER5]      );
}

void CDialog_version::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
