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
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox8;
        TGroupBox *GroupBox9;
        TGroupBox *GroupBox10;
        TGroupBox *GroupBox11;
        TGroupBox *GroupBox12;
        TGroupBox *GroupBox13;
        TGroupBox *GroupBox14;
        TGroupBox *GroupBox15;
        TGroupBox *GroupBox16;
        TLabel *Label1;
        TEdit *Edit_ShowMaster_DriverVer;
        TLabel *Label2;
        TEdit *Edit_ShowMaster_DLLVer;
        TLabel *Label3;
        TEdit *Edit_ShowMaster_CPLDVer;
        TLabel *Label5;
        TEdit *Edit_ShowModule_FPGAVer;
        TLabel *Label6;
        TEdit *Edit_ShowModule_PCBTopVer;
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
        TLabel *Label13;
        TEdit *Edit_ShowAxis_IOSts_1;
        TLabel *Label14;
        TEdit *Edit_ShowAxis_MSts_1;
        TLabel *Label15;
        TEdit *Edit_ShowAxis_Command_2;
        TLabel *Label16;
        TEdit *Edit_ShowAxis_Feedback_2;
        TLabel *Label17;
        TEdit *Edit_ShowAxis_IOSts_2;
        TLabel *Label18;
        TEdit *Edit_ShowAxis_MSts_2;
        TLabel *Label19;
        TEdit *Edit_ShowAxis_Command_3;
        TLabel *Label20;
        TEdit *Edit_ShowAxis_Feedback_3;
        TLabel *Label21;
        TEdit *Edit_ShowAxis_IOSts_3;
        TLabel *Label22;
        TEdit *Edit_ShowAxis_MSts_3;
        TButton *ResetCounter;
        TButton *Btn_BusConnect;
        TButton *Btn_BusDisconnect;
        TLabel *Label23;
        TEdit *Edit_SetModuleID_ForModuleInfo;
        TButton *Btn_GetModuleInfo;
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
        TLabel *Label24;
        TEdit *Edit_Show_PointTable_CurrIndex;
        TGroupBox *GroupBox17;
        TGroupBox *GroupBox18;
        TButton *Btn_SetPointTable;
        TLabel *Label25;
        TEdit *Edit_SetTargetIndex_ForSinglePointMove;
        TButton *Btn_PointTable_SingleIndexMove;
        TButton *Btn_PointTable_MoveALL;
        TButton *Btn_PointTable_Stop;
        TLabel *Label26;
        TEdit *Edit_ShowTriggerCount_0;
        TLabel *Label27;
        TEdit *Edit_ShowTriggerCount_1;
        TLabel *Label28;
        TEdit *Edit_ShowTriggerCount_2;
        TLabel *Label29;
        TEdit *Edit_ShowTriggerCount_3;
        TLabel *Label30;
        TEdit *Edit_ShowTriggerEnc_0;
        TLabel *Label31;
        TEdit *Edit_ShowTriggerEnc_1;
        TLabel *Label32;
        TEdit *Edit_ShowTriggerEnc_2;
        TLabel *Label33;
        TEdit *Edit_ShowTriggerEnc_3;
        TLabel *Label34;
        TEdit *Edit_ShowTrigger_LinearCMP_LinearCMP_0;
        TLabel *Label35;
        TEdit *Edit_ShowTrigger_LinearCMP_LinearCMP_1;
        TLabel *Label36;
        TEdit *Edit_ShowTrigger_LinearCMP_LinearCMP_2;
        TLabel *Label37;
        TEdit *Edit_ShowTrigger_LinearCMP_LinearCMP_3;
        TButton *Btn_Linear_Compare;
        TButton *Btn_Table_Compare;
        TButton *Btn_Manual_Compare;
        TButton *Btn_Trigger_Count;
        TTimer *Timer1;
        TGroupBox *GroupBox19;
        TButton *Btn_Arc_2Axes_Absolute_CCW;
        TButton *Btn_Arc_2Axes_Absolute_CW;
        TButton *Btn_Arc_2Axes_Absolute_Stop2;
        TGroupBox *GroupBox20;
        TButton *Btn_Arc_2Axes_Relative_CCW;
        TButton *Btn_Arc_2Axes_Relative_CW;
        TButton *Btn_Arc_2Axes_Relateive_Stop;
        TGroupBox *GroupBox21;
        TEdit *Edit_ShowMaster_PCBBottomVer;
        TLabel *Label4;
        TLabel *Label38;
        TEdit *Edit_SetModuleID_ForGeneralDIO;
        TLabel *Label39;
        TEdit *Edit_ShowDIData;
        TLabel *Label40;
        TEdit *Edit_SetDOData;
        TButton *Btn_Set_DOData;
        TLabel *Label41;
        TEdit *Edit_GetDOData;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Function_Result(int Ret);
        void __fastcall ResetCounterClick(TObject *Sender);
        void __fastcall Btn_BusConnectClick(TObject *Sender);
        void __fastcall Btn_BusDisconnectClick(TObject *Sender);
        void __fastcall Btn_GetModuleInfoClick(TObject *Sender);
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
        void __fastcall Btn_SetPointTableClick(TObject *Sender);
        void __fastcall Btn_PointTable_SingleIndexMoveClick(
          TObject *Sender);
        void __fastcall Btn_PointTable_StopClick(TObject *Sender);
        void __fastcall Btn_PointTable_MoveALLClick(TObject *Sender);
        void __fastcall Btn_Linear_CompareClick(TObject *Sender);
        void __fastcall Btn_Trigger_CountClick(TObject *Sender);
        void __fastcall Btn_Table_CompareClick(TObject *Sender);
        void __fastcall Btn_Manual_CompareClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Absolute_CCWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Absolute_CWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Absolute_Stop2Click(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Relative_CCWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Relative_CWClick(TObject *Sender);
        void __fastcall Btn_Arc_2Axes_Relateive_StopClick(TObject *Sender);
        void __fastcall Btn_Set_DODataClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
