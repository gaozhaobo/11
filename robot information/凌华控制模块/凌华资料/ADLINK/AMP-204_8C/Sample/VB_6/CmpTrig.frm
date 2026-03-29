VERSION 5.00
Begin VB.Form CmpTrig 
   Caption         =   "Comparator Trigger"
   ClientHeight    =   4125
   ClientLeft      =   6330
   ClientTop       =   5925
   ClientWidth     =   7770
   Icon            =   "CmpTrig.frx":0000
   LinkTopic       =   "Form2"
   ScaleHeight     =   4125
   ScaleWidth      =   7770
   Begin VB.CommandButton Command6 
      Caption         =   "Clear"
      Height          =   315
      Left            =   3120
      TabIndex        =   24
      Top             =   3600
      Width           =   1095
   End
   Begin VB.CommandButton Command5 
      Caption         =   "Stop"
      Height          =   315
      Left            =   3120
      TabIndex        =   23
      Top             =   3240
      Width           =   1095
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Manual"
      Height          =   315
      Left            =   6120
      TabIndex        =   22
      Top             =   2040
      Width           =   1455
   End
   Begin VB.CommandButton Command3 
      Caption         =   "Linear"
      Height          =   315
      Left            =   6120
      TabIndex        =   21
      Top             =   2520
      Width           =   1455
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Table"
      Height          =   315
      Left            =   6120
      TabIndex        =   20
      Top             =   3000
      Width           =   1455
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Reset Count"
      Height          =   315
      Left            =   6120
      TabIndex        =   19
      Top             =   1560
      Width           =   1455
   End
   Begin VB.Timer Timer1 
      Interval        =   1
      Left            =   120
      Top             =   -120
   End
   Begin VB.Label Label16 
      Caption         =   "Timer Value"
      Height          =   255
      Left            =   0
      TabIndex        =   18
      Top             =   3240
      Width           =   1455
   End
   Begin VB.Label Label15 
      Caption         =   "0"
      Height          =   255
      Left            =   1680
      TabIndex        =   17
      Top             =   3240
      Width           =   1215
   End
   Begin VB.Label Label14 
      Caption         =   "#2"
      Height          =   255
      Left            =   3120
      TabIndex        =   16
      Top             =   1440
      Width           =   615
   End
   Begin VB.Label Label13 
      Caption         =   "#1"
      Height          =   255
      Left            =   1680
      TabIndex        =   15
      Top             =   1440
      Width           =   735
   End
   Begin VB.Label Label12 
      Caption         =   "CMP Value (Table)"
      Height          =   255
      Left            =   0
      TabIndex        =   14
      Top             =   2400
      Width           =   1455
   End
   Begin VB.Label Label11 
      Caption         =   "CMP Value (linear)"
      Height          =   255
      Left            =   0
      TabIndex        =   13
      Top             =   1920
      Width           =   1455
   End
   Begin VB.Label Label10 
      Caption         =   "0"
      Height          =   255
      Left            =   3240
      TabIndex        =   12
      Top             =   2400
      Width           =   1335
   End
   Begin VB.Label Label9 
      Caption         =   "0"
      Height          =   255
      Left            =   1800
      TabIndex        =   11
      Top             =   2400
      Width           =   1335
   End
   Begin VB.Label Label8 
      Caption         =   "0"
      Height          =   255
      Left            =   3240
      TabIndex        =   10
      Top             =   1920
      Width           =   1335
   End
   Begin VB.Label Label7 
      Caption         =   "0"
      Height          =   255
      Left            =   1800
      TabIndex        =   9
      Top             =   1920
      Width           =   1335
   End
   Begin VB.Label Label6 
      Caption         =   "Trigger Counter"
      Height          =   255
      Left            =   0
      TabIndex        =   8
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label5 
      Caption         =   "CH3"
      Height          =   255
      Left            =   6000
      TabIndex        =   7
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label4 
      Caption         =   "CH2"
      Height          =   255
      Left            =   4560
      TabIndex        =   6
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label3 
      Caption         =   "CH1"
      Height          =   255
      Left            =   3000
      TabIndex        =   5
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label2 
      Caption         =   "CH0"
      Height          =   255
      Left            =   1320
      TabIndex        =   4
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   3
      Left            =   6120
      TabIndex        =   3
      Top             =   840
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   2
      Left            =   4680
      TabIndex        =   2
      Top             =   840
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   1
      Left            =   3120
      TabIndex        =   1
      Top             =   840
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   0
      Left            =   1560
      TabIndex        =   0
      Top             =   840
      Width           =   1335
   End
End
Attribute VB_Name = "CmpTrig"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
 Option Explicit
    Public v_card_id As Long
    Public v_channel As Long
    
    Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
 
Private Sub Command1_Click()

        Dim Board_ID As Long
        Dim ret As Long
        Dim CH As Long
        
        Board_ID = v_card_id
        ret = 0
        CH = 0

        For CH = 0 To (v_channel - 1)
            ret = APS_reset_trigger_count(Board_ID, CH)
        Next
End Sub

Private Sub Command2_Click()


        Dim Board_ID As Long
        Dim ret As Long
        Dim CH As Long
        Dim i As Long
        Dim ArraySize As Long
        Dim DataArr(9) As Long
        
        
        Board_ID = v_card_id
        ret = 0
        CH = 0
        i = 0
        ArraySize = 10
        
        For i = 0 To 9
            DataArr(i) = 0
        Next


        'Stop Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 0)

        'Clear timer
        ret = APS_set_timer_counter(Board_ID, 0, 0)

        'Disable TRG 0 ~ 3
        ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 0)

        'Disable all CMP
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 0)

        '------------------------------------------------------------

        'Enable trigger output
        If (v_channel = 2) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 3)
        ElseIf (v_channel = 4) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 15)
        End If


        'Linear compare source: Timer counter
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP0_SRC, 8)
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP1_SRC, 8)

        'Table compare direction: Bi-direction(No direction)
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP0_DIR, 2)
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP1_DIR, 2)

        'Trigger output TRG0 ~ TRG3 source
        'Trigger output 0 source: FCMP0
        'Trigger output 1 source: FCMP0
        'Trigger output 2 source: FCMP1
        'Trigger output 3 source: FCMP1
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 4)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 4)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 8)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 8)


        For i = 0 To 9
            DataArr(i) = i * 1000
        Next

        'Start Table CMP
        For CH = 0 To 1
            ret = APS_set_trigger_table(Board_ID, CH, DataArr(0), ArraySize)
        Next

        'Timer Interval: 1ms
        ret = APS_set_trigger_param(Board_ID, TIMR_ITV, 10000)

        'TIMR DIR: Positive count
        ret = APS_set_trigger_param(Board_ID, TIMR_DIR, 0)

        'Start Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 1)
End Sub

Private Sub Command3_Click()


        Dim Board_ID As Long
        Dim ret As Long
        Dim CH As Long
        Dim StartPoint As Long
        Dim RepeatTimes As Long
        Dim Interval As Long
        
        Board_ID = v_card_id
        ret = 0
        CH = 0
        StartPoint = 0
        RepeatTimes = 10
        Interval = 1000


        'Stop Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 0)

        'Clear timer
        ret = APS_set_timer_counter(Board_ID, 0, 0)

        ' Disable TRG 0 ~ 3
        ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 0)

        ' Disable all CMP
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 0)
        '-----------------------------------------------------------

        If (v_channel = 2) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 3)
        ElseIf (v_channel = 4) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 15)
        End If

        'Linear compare source: Timer counter
        ret = APS_set_trigger_param(Board_ID, TGR_LCMP0_SRC, 8)
        ret = APS_set_trigger_param(Board_ID, TGR_LCMP1_SRC, 8)

        'Trigger output TRG0 ~ TRG3 source
        'Trigger output 0 source: LCMP0
        'Trigger output 1 source: LCMP0
        'Trigger output 2 source: LCMP1
        'Trigger output 3 source: LCMP1
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 16)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 16)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 32)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 32)

        'Start linear CMP
        For CH = 0 To 1
            ret = APS_set_trigger_linear(Board_ID, CH, StartPoint, RepeatTimes, Interval)
        Next

        'Timer Interval: 1ms
        ret = APS_set_trigger_param(Board_ID, TIMR_ITV, 10000)

        'TIMR DIR: Positive count
        ret = APS_set_trigger_param(Board_ID, TIMR_DIR, 0)

        'Start Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 1)
End Sub

Private Sub Command4_Click()

        Dim Board_ID As Long
        Dim ret As Long
        Dim CH As Long
        Board_ID = v_card_id
        ret = 0
        CH = 0


        ' Enable trigger output
        If (v_channel = 2) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 3)
        ElseIf (v_channel = 4) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 15)
        End If

        'Trigger output TRG0 ~ TRG3 source
        'Bit 0: Manual
        'Bit 1: Reserved
        'Bit 2: FCMP0
        'Bit 3: FCMP1
        'Bit 4: LCMP0
        'Bit 5: LCMP1
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 1)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 1)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 1)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 1)

        'Start manual trigger
        For CH = 0 To (v_channel - 1)
            ret = APS_set_trigger_manual(Board_ID, CH)
        Next

        'Disable TRG 0 ~ 3
        ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 0)

        'Disable all CMP
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 0)
End Sub

Private Sub Command5_Click()


        Dim Board_ID As Long
        Dim ret As Long
        
         Board_ID = v_card_id
         ret = 0

        'Stop Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 0)
End Sub

Private Sub Command6_Click()


        Dim Board_ID As Long
        Dim ret As Long
        
        Board_ID = v_card_id
        ret = 0

        'Clear timer
        ret = APS_set_timer_counter(Board_ID, 0, 0)
End Sub

Private Sub Form_Load()

        Dim start_axis_id As Long
        Dim total_axes As Long
        Dim ret As Long
        
        start_axis_id = 0
        total_axes = 0
        ret = 0
        
        
        ret = APS_get_first_axisId(v_card_id, start_axis_id, total_axes)

        If (total_axes = 4) Then
            v_channel = 2
        ElseIf (total_axes = 8) Then
            v_channel = 4
        End If
        
        
        Timer1.Enabled = True
End Sub

Private Sub Form_Unload(Cancel As Integer)
    
     Timer1.Enabled = False
    
End Sub

Private Sub Timer1_Timer()


        Dim Board_ID As Long
        Dim CH As Long
        Dim CH_num As Long
        Dim TrgCnt As Long
        Dim ret As Long
        Dim line_value As Long
        Dim Table_value As Long
        Dim Cnt As Long
        Dim data(3) As Long
        Dim data_liner(1) As Long
        Dim data_table(1) As Long
        
        Board_ID = v_card_id
        CH = 0
        CH_num = v_channel
        TrgCnt = 0
        ret = 0
        line_value = 0
        Table_value = 0
        Cnt = 0
        
        
        
        'get trigger count
        For CH = 0 To (CH_num - 1)
            ret = APS_get_trigger_count(Board_ID, CH, TrgCnt)
            data(CH) = TrgCnt
        Next
        
        Label1(0).Caption = CStr(data(0))
        Label1(1).Caption = CStr(data(1))

        If (v_channel = 4) Then
        
             Label1(2).Caption = CStr(data(2))
             Label1(3).Caption = CStr(data(3))
        
        End If
        
        
        'get current linear comparator value
        'get current table  comparator value
        For CH = 0 To 1
            ret = APS_get_trigger_linear_cmp(Board_ID, CH, line_value)
            ret = APS_get_trigger_table_cmp(Board_ID, CH, Table_value)
            data_liner(CH) = line_value
            data_table(CH) = Table_value
        Next

        Label7.Caption = CStr(data_liner(0))
        Label8.Caption = CStr(data_liner(1))
        
        Label9.Caption = CStr(data_table(0))
        Label10.Caption = CStr(data_table(1))
        
        'get timer counter
        ret = APS_get_timer_counter(Board_ID, 0, Cnt)
        Label15.Caption = CStr(Cnt)
End Sub






