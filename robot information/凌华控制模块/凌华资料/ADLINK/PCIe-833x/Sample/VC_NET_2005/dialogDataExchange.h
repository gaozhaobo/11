/***************************************************************
	Created by WT.Lin 
	History:
	2008/11/10
		1.Added comment.
***************************************************************/
#ifndef _DIALOGDATAEXCHANGE_H
#define _DIALOGDATAEXCHANGE_H

#include "type_Def.h"

#define FM_HEX_U8	(0)
#define FM_HEX_U16	(1)
#define FM_HEX_U32	(2)	


F64 GetF64( CDialog *pDlg, I32 Edit);
I32 GetI32( CDialog *pDlg, I32 Edit);
void SetI32( CDialog *pDlg, I32 Edit, I32 Data );
void SetF64( CDialog *pDlg, I32 Edit, F64 Data );

U32 GetU32Hex( CDialog *pDlg, I32 Edit);
void SetU32Hex( CDialog *pDlg, I32 Edit, U32 Data );
void SetI32Bin( CDialog *pDlg, I32 Edit, I32 Data );
void SetI32BinE( CDialog *pDlg, I32 Edit, I32 Data, I32 Length );

U32 GetU32Pro( CDialog *pDlg, I32 Edit );

void TransferToHexStr( U32 Format, U32 Num, CString &Str );

U32 CStrToU32( CString &Str );

#endif