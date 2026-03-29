// SDO_TEST.cpp : implementation file
//

#include "stdafx.h"
#include "basic_samples.h"
#include "SDO_TEST.h"


// SDO_TEST dialog

IMPLEMENT_DYNAMIC(SDO_TEST, CDialog)

SDO_TEST::SDO_TEST(CWnd* pParent /*=NULL*/)
	: CDialog(SDO_TEST::IDD, pParent)
{

}

SDO_TEST::~SDO_TEST()
{
}

void SDO_TEST::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SDO_TEST, CDialog)
	ON_BN_CLICKED(IDC_BUTTON22, &SDO_TEST::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON29, &SDO_TEST::OnBnClickedButton29)
	
	ON_WM_CREATE()
END_MESSAGE_MAP()


// SDO_TEST message handlers

void SDO_TEST::OnBnClickedButton22()
{
	I32 ret = 0;
	I32 Board_ID = 0; 
    I32 BUS_No = 0; 
    U32 SlaveId = 0; 
    U16 ODIndex = 0; 
    U8  ODSubIndex = 0; 
    U8  Data = 0; 
    U32 DataLen = 0; 
    U32 Timeout = 0; 
    U32 Flags = 0; 
    CString str;





	if( v_is_card_initialed == _NOT_INITIAL || v_is_FieldBus_Start == _NOT_START_FIELD_BUS )
    {
		MessageBox( "Function can't use" );
		return;
	}
	

	GetDlgItemText( IDC_EDIT1, str );
	Board_ID = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT7, str );
	BUS_No = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT8, str );
	SlaveId = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT9, str );
	ODIndex = _tcstol( str, NULL, 16 );

	GetDlgItemText( IDC_EDIT10, str );
	ODSubIndex = _tcstol( str, NULL, 16 );

	GetDlgItemText( IDC_EDIT11, str );
	DataLen = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT12, str );
	Timeout = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT13, str );
	Flags = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT21, str );
	Data = _tcstol( str, NULL, 10 );


	ret = APS_set_field_bus_sdo( Board_ID, 
								 BUS_No, 
								 SlaveId,
								 ODIndex,
								 ODSubIndex,
								 &Data,
							     DataLen,
								 Timeout,
								 Flags  
								);

	if( ret == 0 )
	{
		MessageBox( "OK" );
	}
	else
	{
		MessageBox( "error" );
	}
}

void SDO_TEST::OnBnClickedButton29()
{
	CString str;
	I32 ret = 0;
	I32 Board_ID = 0; 
	I32 BUS_No = 0; 
	U32 SlaveId = 0; 
	U16 ODIndex = 0; 
	U8  ODSubIndex = 0; 
	U8  Data = 0; 
	U32 DataLen = 0; 
	U32 OutDatalen = 0; 
	U32 Timeout = 0; 
	U32 Flags = 0;




	if( v_is_card_initialed == _NOT_INITIAL || v_is_FieldBus_Start == _NOT_START_FIELD_BUS )
    {
		MessageBox( "Function can't use" );
		return;
	}



	GetDlgItemText( IDC_EDIT4, str );
	Board_ID = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT5, str );
	BUS_No = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT6, str );
	SlaveId = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT14, str );
	ODIndex = _tcstol( str, NULL, 16 );

	GetDlgItemText( IDC_EDIT15, str );
	ODSubIndex = _tcstol( str, NULL, 16 );

	GetDlgItemText( IDC_EDIT16, str );
	DataLen = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT17, str );
	Timeout = _tcstol( str, NULL, 10 );

	GetDlgItemText( IDC_EDIT18, str );
	Flags = _tcstol( str, NULL, 10 );



	ret = APS_get_field_bus_sdo( Board_ID, 
								 BUS_No,
								 SlaveId,
								 ODIndex,
								 ODSubIndex,
								 &Data,
								 DataLen,
								 &OutDatalen,
								 Timeout,
								 Flags
								);

	if( ret == 0 )
	{
		MessageBox( "OK" );
	}
	else
	{
		MessageBox( "error" );
	}


	str.Format( "0x%x", Data );
	SetDlgItemText( IDC_EDIT19, str );

    str.Format( "0x%x", OutDatalen );
	SetDlgItemText( IDC_EDIT20, str );
}



int SDO_TEST::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	

	return 0;
}
