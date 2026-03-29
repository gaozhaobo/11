//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlg_version.h"
#include "basic_samples_dlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
	I32 info[5];
        int buf_0;
        String buf_1;

	get_version_info( info, v_card_id );
        Label6->Caption = IntToStr(info[0]);
        Label7->Caption = IntToStr(info[1]);
        Label8->Caption = IntToStr(info[2]);

        buf_0 = info[3];
        buf_1 = IntToHex(buf_0, 0);
        Label9->Caption = buf_1;

        Label10->Caption = IntToStr(info[4]);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
