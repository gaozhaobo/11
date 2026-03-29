/***************************************************************
	Created by WT.Lin 
	History:
	2008/11/10
		1.Added comment.
***************************************************************/
#include "stdafx.h"
#include "DialogDataExchange.h"
#include "type_def.h"
#include <string>
using namespace std;

F64 GetF64( CDialog *pDlg, I32 Edit )
{
	char buff[32];
	pDlg->GetDlgItemText( Edit, buff, 32 );
	return strtod( buff, 0 );
}

I32 GetI32( CDialog *pDlg, I32 Edit)
{
	char buff[32];
	pDlg->GetDlgItemText( Edit, buff, 32 );
	return strtol( buff, 0, 10 );
}

U32 GetU32Hex( CDialog *pDlg, I32 Edit)
{
	char buff[32];
	pDlg->GetDlgItemText( Edit, buff, 32 );
	return strtoul( buff, 0, 16 );
}

void SetI32( CDialog *pDlg, I32 Edit, I32 Data )
{
	CString str;
	str.Format( "%d", Data );
	pDlg->SetDlgItemText( Edit, (LPCTSTR)str);
}

void SetU32Hex( CDialog *pDlg, I32 Edit, U32 Data )
{
	CString str;
	str.Format( "%x", Data );
	pDlg->SetDlgItemText( Edit, (LPCTSTR)str);
}

void SetI32Bin( CDialog *pDlg, I32 Edit, I32 Data )
{
	char text[64];
	_itoa( Data, text, 2 );
	pDlg->SetDlgItemText( Edit, text );
}

void SetI32BinE( CDialog *pDlg, I32 Edit, I32 Data, I32 Length )
{
	char text[64];
	_itoa( Data, text, 2 );
	
	string str(text);
	string str2("00000000000000000000000000000000"); //32 bit 

	I32 abLen = Length - str.size();
	
	if( abLen > 0 )
	{
		str = str2.substr(0, abLen) + str;
	}

	pDlg->SetDlgItemText( Edit, str.c_str() );
}

void SetF64( CDialog *pDlg, I32 Edit, F64 Data )
{
	CString str;
	str.Format( "%f", Data );
	pDlg->SetDlgItemText( Edit, (LPCTSTR)str);
}


/***************************************************************************
  Fun Name: TransferToHexStr
  Author  : WT. Lin
  Live    : 2008/11/11 - 2008/11/11
  Ref./Doc: 
  Comment : Transfer an integer(Num) to a Hex format string(Str)
			There are 3 kind of formats. 8, 16 and 32 bit format.
			Ex. The output string's format will like following examples.
				8:  0x0A
				16: 0x01F3
				32: 0x0123 4567

  Input   : U32 Format: 0: 8Bit, 1:16bit, 2:32bit
			U32 Num; A number to be transfer to.
			CString &Str: A string output transfered hex format. 
  Return  : void
***************************************************************************/
void TransferToHexStr( U32 Format, U32 Num, CString &Str )
{
	switch( Format )
	{
	case FM_HEX_U8:
		Num = Num & 0xFF;
		Str.Format( "%02xh" , Num );
		break;

	case FM_HEX_U16: //U16
		Num = Num & 0xFFFF;
		Str.Format( "%04xh" , Num );
		break;

	case FM_HEX_U32://U32
	default:
		Str.Format( "%08xh", Num );
		Str.Insert(4, " ");
		break;
	}
}

/***************************************************************************
  Fun Name: CStrToU32
  Author  : WT. Lin
  Live    : 2008/11/10 - 2008/11/10
  Ref./Doc: 
  Comment : 
  Input   : CString &Str: Input numerical string. It could be 10 Base or 16Hex base.
			if the first two characters are "0x" or "0X". It would be Hex format
			else Oct format.
			Ex. "0xF" -> 15
				0xF -> 15
				0XF -> 15
  Return  : U32 
***************************************************************************/
U32 CStrToU32( CString &Str )
{
	Str.TrimLeft();
	Str.TrimRight();
	Str.MakeLower();

	if( Str.Left(2).Compare( "0x" ) == 0 )
	{ //Hex format.
		Str.Delete( 0, 2 );
		return strtoul( (LPCTSTR)Str, 0, 16 );
	}else if( Str.Right(1).Compare( "h" ) == 0 )
	{
		Str.TrimRight( "h" );
		return strtoul( (LPCTSTR)Str, 0, 16 );
	}else
	{ //Oct format.
		return strtoul( (LPCTSTR)Str, 0, 10 );
	}
}


U32 GetU32Pro( CDialog *pDlg, I32 Edit )
{
	char buff[32];
	CString str;
	pDlg->GetDlgItemText( Edit, buff, 32 );

	str = buff;
	return CStrToU32(str);
}
