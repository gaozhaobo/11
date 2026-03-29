//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H

#include "basic_samples_dlg.h"
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TWaitInt_pwm : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        __fastcall TWaitInt_pwm(bool CreateSuspended);
        I32 v_card_id;
        I32 v_channel;
};

class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label4;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label18;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TLabel *Label17;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TTimer *Timer1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

	I32 v_card_id;
        I32 v_channel;
        TWaitInt_pwm *pWaitInt;

        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
 