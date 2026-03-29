//---------------------------------------------------------------------------

#ifndef dlg_axis_monitorH
#define dlg_axis_monitorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
// Motion I/O
#define DLG_ALM     (0)
#define DLG_PEL     (1)
#define DLG_MEL     (2)
#define DLG_ORG     (3)
#define DLG_EMG     (4)
#define DLG_EZ      (5)
#define DLG_INP     (6)
#define DLG_SVON    (7)
#define MAX_MIO_CHECK   (8) // ***

// Motion status
#define DLG_CSTP     (0)
#define DLG_VM       (1)
#define DLG_ACC      (2)
#define DLG_DEC      (3)
#define DLG_DIR      (4)
#define DLG_MDN      (5)
#define DLG_HMV      (6)
#define DLG_WAIT     (7)
#define DLG_PTB      (8)
#define DLG_JOG      (9)
#define DLG_ASTP     (10)
#define DLG_BLD      (11)
#define DLG_PRED     (12)
#define DLG_POSTD    (13)
#define DLG_GER      (14)
#define MAX_MSTS_CHECK  (15) // ****

class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TComboBox *ComboBox1;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TGroupBox *GroupBox1;
        TButton *Button1;
        TGroupBox *GroupBox2;
        TTimer *Timer1;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
        TCheckBox *CheckBox8;
        TCheckBox *CheckBox9;
        TCheckBox *CheckBox10;
        TCheckBox *CheckBox11;
        TCheckBox *CheckBox12;
        TCheckBox *CheckBox13;
        TCheckBox *CheckBox14;
        TCheckBox *CheckBox15;
        TCheckBox *CheckBox16;
        TCheckBox *CheckBox17;
        TCheckBox *CheckBox18;
        TCheckBox *CheckBox19;
        TCheckBox *CheckBox20;
        TCheckBox *CheckBox21;
        TCheckBox *CheckBox22;
        TCheckBox *CheckBox23;
        TButton *Button2;
        TButton *Button3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);

	int v_card_id ;
	int v_start_axis_id;
	int v_total_axes;
	int v_selected_axis_id;
        TCheckBox *v_pCheck_motion_io[MAX_MIO_CHECK];
        TCheckBox *v_pCheck_motion_status[MAX_MSTS_CHECK];
	int v_motion_io_bit_map[MAX_MIO_CHECK];
	int v_motion_status_bit_map[MAX_MSTS_CHECK];
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
