//---------------------------------------------------------------------------

#ifndef basic_samples_dlgH
#define basic_samples_dlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "..\..\..\APS Library\include\APS168.h"
#include "..\..\..\APS Library\include\ErrorCodeDef.h"
#include "..\..\..\APS Library\include\APS_define.h"
#include "..\..\..\APS Library\include\type_Def.h"
#include <Menus.hpp>
#include "dlg_version.h"
#include "dlg_axis_monitor.h"
#include "Unit4.h"
#include "Unit5.h"
#include "sample_8254_8.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
#define _NOT_INITIAL  (0)
#define _INITIALED    (1)
//---------------------------------------------------------------------------
class TWaitInt : public TThread
{
private:
protected:
        void __fastcall Execute();
public:
        __fastcall TWaitInt(bool CreateSuspended);
        I32 g_board_id;
        I32 g_axis_num;
};

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TComboBox *ComboBox1;
        TLabel *Label1;
        TButton *Button6;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox4;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TButton *Button19;
        TButton *Button20;
        TButton *Button21;
        TOpenDialog *OpenDialog1;
        TButton *Button22;
        TButton *Button23;
        TButton *Button24;
        TButton *Button25;
        TGroupBox *GroupBox3;
        TButton *Button14;
        TButton *Button15;
        TButton *Button16;
        TButton *Button17;
        TButton *Button18;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall Button20Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button24Click(TObject *Sender);
        void __fastcall Button25Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);

        int v_is_card_initialed;
	I32 v_card_id;
	I32 v_test_axis_id;
	I32 v_first_axis_id;
        I32 v_channel;
        void __fastcall TForm1::_CHECK_CARD_INITIAL();
        TWaitInt *pWaitInt;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
