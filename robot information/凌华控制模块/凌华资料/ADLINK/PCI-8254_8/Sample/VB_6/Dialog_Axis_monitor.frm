VERSION 5.00
Begin VB.Form Dialog_axis_monitor 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Axis Monitor"
   ClientHeight    =   4260
   ClientLeft      =   6600
   ClientTop       =   5955
   ClientWidth     =   6510
   Icon            =   "Dialog_Axis_monitor.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4260
   ScaleWidth      =   6510
   ShowInTaskbar   =   0   'False
   Begin VB.Frame Frame2 
      Caption         =   "Motion Status"
      Height          =   3975
      Left            =   4920
      TabIndex        =   17
      Top             =   120
      Width           =   1335
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   14
         Left            =   120
         TabIndex        =   50
         Top             =   3600
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   13
         Left            =   120
         TabIndex        =   49
         Top             =   3360
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   12
         Left            =   120
         TabIndex        =   48
         Top             =   3120
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   11
         Left            =   120
         TabIndex        =   47
         Top             =   2880
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   10
         Left            =   120
         TabIndex        =   46
         Top             =   2640
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   9
         Left            =   120
         TabIndex        =   45
         Top             =   2400
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   8
         Left            =   120
         TabIndex        =   44
         Top             =   2160
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   7
         Left            =   120
         TabIndex        =   43
         Top             =   1920
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   6
         Left            =   120
         TabIndex        =   42
         Top             =   1680
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   5
         Left            =   120
         TabIndex        =   41
         Top             =   1440
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   4
         Left            =   120
         TabIndex        =   40
         Top             =   1200
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   3
         Left            =   120
         TabIndex        =   39
         Top             =   960
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   2
         Left            =   120
         TabIndex        =   38
         Top             =   720
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   1
         Left            =   120
         TabIndex        =   37
         Top             =   480
         Width           =   255
      End
      Begin VB.CheckBox Check2 
         Caption         =   "Check1"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   36
         Top             =   240
         Width           =   255
      End
      Begin VB.Label Label36 
         Caption         =   "PTB"
         Height          =   255
         Left            =   480
         TabIndex        =   65
         Top             =   2160
         Width           =   495
      End
      Begin VB.Label Label35 
         Caption         =   "JOG"
         Height          =   255
         Left            =   480
         TabIndex        =   64
         Top             =   2385
         Width           =   495
      End
      Begin VB.Label Label34 
         Caption         =   "ASTP"
         Height          =   255
         Left            =   480
         TabIndex        =   63
         Top             =   2625
         Width           =   495
      End
      Begin VB.Label Label33 
         Caption         =   "BLD"
         Height          =   255
         Left            =   480
         TabIndex        =   62
         Top             =   2865
         Width           =   495
      End
      Begin VB.Label Label32 
         Caption         =   "PRED"
         Height          =   255
         Left            =   480
         TabIndex        =   61
         Top             =   3105
         Width           =   495
      End
      Begin VB.Label Label31 
         Caption         =   "POSTD"
         Height          =   255
         Left            =   480
         TabIndex        =   60
         Top             =   3345
         Width           =   735
      End
      Begin VB.Label Label30 
         Caption         =   "GER"
         Height          =   255
         Left            =   480
         TabIndex        =   59
         Top             =   3585
         Width           =   495
      End
      Begin VB.Label Label29 
         Caption         =   "CSTP"
         Height          =   255
         Left            =   480
         TabIndex        =   58
         Top             =   240
         Width           =   495
      End
      Begin VB.Label Label28 
         Caption         =   "VM"
         Height          =   255
         Left            =   480
         TabIndex        =   57
         Top             =   465
         Width           =   495
      End
      Begin VB.Label Label27 
         Caption         =   "ACC"
         Height          =   255
         Left            =   480
         TabIndex        =   56
         Top             =   705
         Width           =   495
      End
      Begin VB.Label Label26 
         Caption         =   "DEC"
         Height          =   255
         Left            =   480
         TabIndex        =   55
         Top             =   945
         Width           =   495
      End
      Begin VB.Label Label25 
         Caption         =   "DIR"
         Height          =   255
         Left            =   480
         TabIndex        =   54
         Top             =   1185
         Width           =   495
      End
      Begin VB.Label Label24 
         Caption         =   "MDN"
         Height          =   255
         Left            =   480
         TabIndex        =   53
         Top             =   1425
         Width           =   495
      End
      Begin VB.Label Label23 
         Caption         =   "HMV"
         Height          =   255
         Left            =   480
         TabIndex        =   52
         Top             =   1665
         Width           =   495
      End
      Begin VB.Label Label22 
         Caption         =   "WAIT"
         Height          =   255
         Left            =   480
         TabIndex        =   51
         Top             =   1905
         Width           =   495
      End
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Reset Position"
      Height          =   375
      Left            =   240
      TabIndex        =   15
      Top             =   3720
      Width           =   1215
   End
   Begin VB.Timer Timer1 
      Interval        =   500
      Left            =   120
      Top             =   120
   End
   Begin VB.ComboBox Combo1 
      Height          =   315
      Left            =   1680
      TabIndex        =   1
      Top             =   240
      Width           =   975
   End
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   1680
      TabIndex        =   0
      Top             =   3720
      Width           =   1215
   End
   Begin VB.Frame Frame1 
      Caption         =   "Motion I/O"
      Height          =   3975
      Left            =   3360
      TabIndex        =   16
      Top             =   120
      Width           =   1335
      Begin VB.CommandButton Command3 
         Caption         =   "SVOFF"
         Height          =   375
         Left            =   120
         TabIndex        =   35
         Top             =   3480
         Width           =   1095
      End
      Begin VB.CommandButton Command2 
         Caption         =   "SVON"
         Height          =   375
         Left            =   120
         TabIndex        =   34
         Top             =   3000
         Width           =   1095
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   7
         Left            =   240
         TabIndex        =   25
         Top             =   1920
         Width           =   255
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   6
         Left            =   240
         TabIndex        =   24
         Top             =   1680
         Width           =   255
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   5
         Left            =   240
         TabIndex        =   23
         Top             =   1440
         Width           =   255
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   4
         Left            =   240
         TabIndex        =   22
         Top             =   1200
         Width           =   255
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   3
         Left            =   240
         TabIndex        =   21
         Top             =   960
         Width           =   255
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   2
         Left            =   240
         TabIndex        =   20
         Top             =   720
         Width           =   255
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   1
         Left            =   240
         TabIndex        =   19
         Top             =   480
         Width           =   255
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Check1"
         Height          =   255
         Index           =   0
         Left            =   240
         TabIndex        =   18
         Top             =   255
         Width           =   255
      End
      Begin VB.Label Label21 
         Caption         =   "SVON"
         Height          =   255
         Left            =   600
         TabIndex        =   33
         Top             =   1920
         Width           =   495
      End
      Begin VB.Label Label20 
         Caption         =   "INP"
         Height          =   255
         Left            =   600
         TabIndex        =   32
         Top             =   1680
         Width           =   495
      End
      Begin VB.Label Label19 
         Caption         =   "EZ"
         Height          =   255
         Left            =   600
         TabIndex        =   31
         Top             =   1440
         Width           =   495
      End
      Begin VB.Label Label18 
         Caption         =   "EMG"
         Height          =   255
         Left            =   600
         TabIndex        =   30
         Top             =   1200
         Width           =   495
      End
      Begin VB.Label Label17 
         Caption         =   "ORG"
         Height          =   255
         Left            =   600
         TabIndex        =   29
         Top             =   960
         Width           =   495
      End
      Begin VB.Label Label16 
         Caption         =   "MEL"
         Height          =   255
         Left            =   600
         TabIndex        =   28
         Top             =   720
         Width           =   495
      End
      Begin VB.Label Label15 
         Caption         =   "PEL"
         Height          =   255
         Left            =   600
         TabIndex        =   27
         Top             =   480
         Width           =   495
      End
      Begin VB.Label Label14 
         Caption         =   "ALM"
         Height          =   255
         Left            =   600
         TabIndex        =   26
         Top             =   255
         Width           =   495
      End
   End
   Begin VB.Label Label13 
      Caption         =   "0"
      Height          =   255
      Left            =   1820
      TabIndex        =   14
      Top             =   2520
      Width           =   1500
   End
   Begin VB.Label Label12 
      Caption         =   "0"
      Height          =   255
      Left            =   1820
      TabIndex        =   13
      Top             =   2160
      Width           =   1500
   End
   Begin VB.Label Label11 
      Caption         =   "0"
      Height          =   255
      Left            =   1820
      TabIndex        =   12
      Top             =   1800
      Width           =   1500
   End
   Begin VB.Label Label10 
      Caption         =   "0"
      Height          =   255
      Left            =   1820
      TabIndex        =   11
      Top             =   1440
      Width           =   1500
   End
   Begin VB.Label Label9 
      Caption         =   "0"
      Height          =   255
      Left            =   1820
      TabIndex        =   10
      Top             =   1080
      Width           =   1500
   End
   Begin VB.Label Label8 
      Caption         =   "0"
      Height          =   255
      Left            =   1820
      TabIndex        =   9
      Top             =   720
      Width           =   1500
   End
   Begin VB.Label Label7 
      Caption         =   "Feedback Velocity :"
      Height          =   255
      Left            =   120
      TabIndex        =   8
      Top             =   2520
      Width           =   1455
   End
   Begin VB.Label Label6 
      Caption         =   "Command Velocity : "
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   2160
      Width           =   1455
   End
   Begin VB.Label Label5 
      Caption         =   "Error Position : "
      Height          =   255
      Left            =   480
      TabIndex        =   6
      Top             =   1800
      Width           =   1095
   End
   Begin VB.Label Label4 
      Caption         =   "Target Position : "
      Height          =   255
      Left            =   360
      TabIndex        =   5
      Top             =   1440
      Width           =   1215
   End
   Begin VB.Label Label3 
      Caption         =   "Feedback Position :"
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   1080
      Width           =   1455
   End
   Begin VB.Label Label2 
      Caption         =   "Command Position : "
      Height          =   255
      Left            =   120
      TabIndex        =   3
      Top             =   720
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "Axis ID : "
      Height          =   255
      Left            =   600
      TabIndex        =   2
      Top             =   300
      Width           =   975
   End
End
Attribute VB_Name = "Dialog_axis_monitor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
    '// Motion I/O
    Const DLG_ALM = (0)
    Const DLG_PEL = (1)
    Const DLG_MEL = (2)
    Const DLG_ORG = (3)
    Const DLG_EMG = (4)
    Const DLG_EZ = (5)
    Const DLG_INP = (6)
    Const DLG_SVON = (7)
    Const MAX_MIO_CHECK = (8)

    '// Motion status
    Const DLG_CSTP = (0)
    Const DLG_VM = (1)
    Const DLG_ACC = (2)
    Const DLG_DEC = (3)
    Const DLG_DIR = (4)
    Const DLG_MDN = (5)
    Const DLG_HMV = (6)
    Const DLG_WAIT = (7)
    Const DLG_PTB = (8)
    Const DLG_JOG = (9)
    Const DLG_ASTP = (10)
    Const DLG_BLD = (11)
    Const DLG_PRED = (12)
    Const DLG_POSTD = (13)
    Const DLG_GER = (14)
    Const MAX_MSTS_CHECK = (15)

    Dim v_card_id As Long
    Dim v_start_axis_id As Long
    Dim v_total_axes As Long
    Dim v_selected_axis_id As Long
    'Dim pCombo_select_axis As ComboBox
    'CButton *v_pCheck_motion_io[MAX_MIO_CHECK];
    'CButton *v_pCheck_motion_status[MAX_MSTS_CHECK];
    Dim v_motion_io_bit_map(MAX_MIO_CHECK - 1) As Long
    Dim v_motion_status_bit_map(MAX_MSTS_CHECK - 1) As Long


Private Sub Combo1_Click()

    'MsgBox "combo1 is changed", 0
    If Combo1.ListIndex = -1 Then
        MsgBox "ComboBox init err", 0
        Exit Sub
    End If
    
    v_selected_axis_id = v_start_axis_id + Combo1.ListIndex
    
End Sub

Private Sub Command1_Click()

    APS_set_command_f v_selected_axis_id, 0#
    APS_set_position_f v_selected_axis_id, 0#

End Sub

Private Sub Command2_Click()

    APS_set_servo_on v_selected_axis_id, 1
    
End Sub

Private Sub Command3_Click()

    APS_set_servo_on v_selected_axis_id, 0
End Sub


Private Sub Form_Unload(Cancel As Integer)

    Timer1.Enabled = False
    
End Sub

Private Sub Form_Load()

    Dim start_axis_id As Long
    start_axis_id = 0
    Dim total_axes As Long
    total_axes = 0
    Dim ret As Long
    Dim str As String
    Dim i As Long

    ret = APS_get_first_axisId(v_card_id, start_axis_id, total_axes)
    
    Combo1.Clear
    For i = 0 To total_axes - 1
        Combo1.AddItem (i)
    Next
    Combo1.ListIndex = 0
    
    v_start_axis_id = start_axis_id
    v_total_axes = total_axes
    v_selected_axis_id = start_axis_id

    v_motion_io_bit_map(DLG_ALM) = MIO_ALM
    v_motion_io_bit_map(DLG_PEL) = MIO_PEL
    v_motion_io_bit_map(DLG_MEL) = MIO_MEL
    v_motion_io_bit_map(DLG_ORG) = MIO_ORG
    v_motion_io_bit_map(DLG_EMG) = MIO_EMG
    v_motion_io_bit_map(DLG_EZ) = MIO_EZ
    v_motion_io_bit_map(DLG_INP) = MIO_INP
    v_motion_io_bit_map(DLG_SVON) = MIO_SVON

    v_motion_status_bit_map(DLG_CSTP) = MTS_CSTP
    v_motion_status_bit_map(DLG_VM) = MTS_VM
    v_motion_status_bit_map(DLG_ACC) = MTS_ACC
    v_motion_status_bit_map(DLG_DEC) = MTS_DEC
    v_motion_status_bit_map(DLG_DIR) = MTS_DIR
    v_motion_status_bit_map(DLG_MDN) = MTS_NSTP
    v_motion_status_bit_map(DLG_HMV) = MTS_HMV
    v_motion_status_bit_map(DLG_WAIT) = 10
    v_motion_status_bit_map(DLG_PTB) = 11
    v_motion_status_bit_map(DLG_JOG) = MTS_JOG
    v_motion_status_bit_map(DLG_ASTP) = MTS_ASTP
    v_motion_status_bit_map(DLG_BLD) = 17
    v_motion_status_bit_map(DLG_PRED) = 18
    v_motion_status_bit_map(DLG_POSTD) = 19
    v_motion_status_bit_map(DLG_GER) = 28

    Timer1.Enabled = True

End Sub

Private Sub OKButton_Click()

    Timer1.Enabled = False
    Unload Me
    
End Sub

Private Sub Timer1_Timer()

    Dim Status As AXIS_STATUS

    get_axis_status_example v_selected_axis_id, Status

    Label8.Caption = CStr(Status.command_position)
    Label9.Caption = CStr(Status.feedback_position)
    Label10.Caption = CStr(Status.target_position)
    Label11.Caption = CStr(Status.error_position)
    Label12.Caption = CStr(Status.command_velocity)
    Label13.Caption = CStr(Status.feedback_velocity)

    Dim i As Long
    Dim j, k As Long
        
    For i = 0 To MAX_MIO_CHECK - 1
        j = Status.motion_io And (2 ^ v_motion_io_bit_map(i))
        If (j > 0) Then
            Check1(i).Value = 1
        Else
            Check1(i).Value = 0
        End If
    Next

    For i = 0 To MAX_MSTS_CHECK - 1
        j = Status.motion_status And (2 ^ v_motion_status_bit_map(i))
        If (j > 0) Then
            Check2(i).Value = 1
        Else
            Check2(i).Value = 0
        End If
    Next


End Sub
