//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox8;
        TGroupBox *GroupBox9;
        TGroupBox *GroupBox10;
        TGroupBox *GroupBox11;
        TGroupBox *GroupBox12;
        TGroupBox *GroupBox13;
        TGroupBox *GroupBox14;
        TLabel *Label1;
        TEdit *Edit_ShowMaster_DriverVer;
        TLabel *Label2;
        TEdit *Edit_ShowMaster_DLLVer;
        TLabel *Label3;
        TEdit *Edit_ShowMaster_CPLDVer;
        TLabel *Label7;
        TEdit *Edit_ShowAxis_Command_0;
        TLabel *Label8;
        TEdit *Edit_ShowAxis_Feedback_0;
        TLabel *Label9;
        TEdit *Edit_ShowAxis_IOSts_0;
        TLabel *Label10;
        TEdit *Edit_ShowAxis_MSts_0;
        TLabel *Label11;
        TEdit *Edit_ShowAxis_Command_1;
        TLabel *Label12;
        TEdit *Edit_ShowAxis_Feedback_1;
        TEdit *Edit_ShowAxis_IOSts_1;
        TEdit *Edit_ShowAxis_MSts_1;
        TLabel *Label15;
        TEdit *Edit_ShowAxis_Command_2;
        TEdit *Edit_ShowAxis_Feedback_2;
        TEdit *Edit_ShowAxis_IOSts_2;
        TEdit *Edit_ShowAxis_MSts_2;
        TLabel *Label19;
        TEdit *Edit_ShowAxis_Command_3;
        TEdit *Edit_ShowAxis_Feedback_3;
        TEdit *Edit_ShowAxis_IOSts_3;
        TEdit *Edit_ShowAxis_MSts_3;
        TButton *ResetCounter;
        TButton *Btn_SingleAbsoluteMove_Backward;
        TButton *Btn_SingleAbsoluteMove_Forward;
        TButton *Btn_SingleAbsoluteMove_Stop;
        TButton *Btn_SingleRelativeMove_Backward;
        TButton *Btn_SingleRelativeMove_Forward;
        TButton *Btn_SingleRelativeMove_Stop;
        TButton *Btn_SingleHomeMove_Backward;
        TButton *Btn_SingleHomeMove_Forward;
        TButton *Btn_SingleHomeMove_Stop;
        TButton *Btn_Linear_2Axes_AbsoluteBackward;
        TButton *Btn_Linear_2Axes_AbsoluteForward;
        TButton *Btn_Linear_2Axes_AbsoluteStop;
        TButton *Btn_Linear_2Axes_RelateiveBackward;
        TButton *Btn_Linear_2Axes_RelateiveForward;
        TButton *Btn_Linear_2Axes_Relateive_Stop;
        TButton *Btn_Linear_3Axes_AbsoluteBackward;
        TButton *Btn_Linear_3Axes_AbsoluteForward;
        TButton *Btn_Linear_3Axes_AbsoluteStop;
        TButton *Btn_Linear_3Axes_RelateiveBackward;
        TButton *Btn_Linear_3Axes_RelateiveForward;
        TButton *Btn_Linear_3Axes_Relateive_Stop;
        TButton *Btn_Linear_4Axes_AbsoluteBackward;
        TButton *Btn_Linear_4Axes_AbsoluteForward;
        TButton *Btn_Linear_4Axes_AbsoluteStop;
        TButton *Btn_Linear_4Axes_RelateiveBackward;
        TButton *Btn_Linear_4Axes_RelateiveForward;
        TButton *Btn_Linear_4Axes_Relateive_Stop;
        TTimer *Timer1;
        TGroupBox *GroupBox19;
        TButton *Btn_Arc_2Axes_Absolute_CCW;
        TButton *Btn_Arc_2Axes_Absolute_CW;
        TButton *Btn_Arc_2Axes_Absolute_Stop2;
        TGroupBox *GroupBox20;
        TButton *Btn_Arc_2Axes_Relative_CCW;
        TButton *Btn_Arc_2Axes_Relative_CW;
        TButton *Btn_Arc_2Axes_Relateive_Stop;
        TButton *Button1;
        TEdit *Edit1;
        TLabel *Label4;
        TLabel *Label5;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Function_Result(int Ret);
        void __fastcall ResetCounterClick(TObject *Sender);

        void __fastcall Btn_SingleAbsoluteMove_BackwardClick(
          TObject *Sender);
        void __fastcall Btn_SingleAbsoluteMove_ForwardClick(
          TObject *Sender);
        void __fastcall Btn_SingleAbsoluteMove_StopClick(TObject *Sender);
        void __fastcall Btn_SingleRelativeMove_BackwardClick(
          TObject *Sender);
        void __fastcall Btn_SingleRelativeMove_ForwardClick(
          TObject *Sender);
        void __fastcall Btn_SingleRelativeMove_StopClick(TObject *Sender);
        void __fastcall Btn_SingleHomeMove_BackwardClick(TObject *Sender);
        void __fastcall Btn_SingleHomeMove_ForwardClick(TObject *Sender);
        void __fastcall Btn_SingleHomeMove_StopClick(TObject *Sender);
        void __fastcall Btn_Linear_2Axes_AbsoluteBackwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_2Axes_AbsoluteForwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_2Axes_AbsoluteStopClick(
          TObject *Sender);
        void __fastcall Btn_Linear_2Axes_RelateiveBackwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_2Axes_RelateiveForwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_2Axes_Relateive_StopClick(
          TObject *Sender);
        void __fastcall Btn_Linear_3Axes_AbsoluteBackwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_3Axes_AbsoluteForwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_3Axes_AbsoluteStopClick(
          TObject *Sender);
        void __fastcall Btn_Linear_3Axes_RelateiveBackwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_3Axes_RelateiveForwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_3Axes_Relateive_StopClick(
          TObject *Sender);
        void __fastcall Btn_Linear_4Axes_AbsoluteBackwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_4Axes_AbsoluteForwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_4Axes_AbsoluteStopClick(
          TObject *Sender);
        void __fastcall Btn_Linear_4Axes_RelateiveBackwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_4Axes_RelateiveForwardClick(
          TObject *Sender);
        void __fastcall Btn_Linear_4Axes_Relateive_StopClick(
          TObject *Sender);






        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Absolute_CCWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Absolute_CWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Absolute_Stop2Click(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Relative_CCWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Relative_CWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Relateive_StopClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        

        
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
