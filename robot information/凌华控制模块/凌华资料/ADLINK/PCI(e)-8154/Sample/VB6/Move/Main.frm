VERSION 5.00
Begin VB.Form MainForm 
   Caption         =   "ADLINK VB6  Sample"
   ClientHeight    =   10980
   ClientLeft      =   2505
   ClientTop       =   660
   ClientWidth     =   15345
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   10980
   ScaleWidth      =   15345
   Begin VB.CommandButton Command2 
      Caption         =   "Set Card ID"
      Height          =   615
      Left            =   3120
      TabIndex        =   81
      Top             =   9240
      Width           =   1455
   End
   Begin VB.TextBox Text3 
      Height          =   285
      Left            =   3120
      TabIndex        =   80
      Text            =   "0"
      Top             =   8760
      Width           =   1455
   End
   Begin VB.Frame Frame3 
      Caption         =   "Axis Info"
      Height          =   3015
      Left            =   2400
      TabIndex        =   52
      Top             =   360
      Width           =   12375
      Begin VB.TextBox Text2 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   285
         Index           =   3
         Left            =   7200
         TabIndex        =   77
         Text            =   "Text2"
         Top             =   2520
         Width           =   1575
      End
      Begin VB.TextBox Text2 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   285
         Index           =   2
         Left            =   5400
         TabIndex        =   76
         Text            =   "Text2"
         Top             =   2520
         Width           =   1575
      End
      Begin VB.TextBox Text2 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   285
         Index           =   1
         Left            =   3600
         TabIndex        =   75
         Text            =   "Text2"
         Top             =   2520
         Width           =   1575
      End
      Begin VB.TextBox Text2 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FFFF&
         Height          =   285
         Index           =   0
         Left            =   1800
         TabIndex        =   74
         Text            =   "Text2"
         Top             =   2520
         Width           =   1575
      End
      Begin VB.TextBox Text1 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H008080FF&
         Height          =   285
         Index           =   3
         Left            =   7200
         TabIndex        =   73
         Text            =   "Text1"
         Top             =   1920
         Width           =   1575
      End
      Begin VB.TextBox Text1 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H008080FF&
         Height          =   285
         Index           =   2
         Left            =   5400
         TabIndex        =   72
         Text            =   "Text1"
         Top             =   1920
         Width           =   1575
      End
      Begin VB.TextBox Text1 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H008080FF&
         Height          =   285
         Index           =   1
         Left            =   3600
         TabIndex        =   71
         Text            =   "Text1"
         Top             =   1920
         Width           =   1575
      End
      Begin VB.TextBox Text1 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H008080FF&
         Height          =   285
         Index           =   0
         Left            =   1800
         TabIndex        =   62
         Text            =   "Text1"
         Top             =   1920
         Width           =   1575
      End
      Begin VB.Timer Timer1 
         Interval        =   50
         Left            =   11760
         Top             =   240
      End
      Begin VB.CommandButton Btn_ResetCounter 
         Caption         =   "Reset Counter"
         Height          =   1095
         Left            =   9240
         TabIndex        =   61
         Top             =   1200
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowAxis_Feedback 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   3
         Left            =   7200
         TabIndex        =   60
         Text            =   "Text1"
         Top             =   1320
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_Feedback 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   2
         Left            =   5400
         TabIndex        =   59
         Text            =   "Text1"
         Top             =   1320
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_Feedback 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   1
         Left            =   3600
         TabIndex        =   58
         Text            =   "Text1"
         Top             =   1320
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_Command 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   3
         Left            =   7200
         TabIndex        =   57
         Text            =   "Text1"
         Top             =   720
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_Command 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   2
         Left            =   5400
         TabIndex        =   56
         Text            =   "Text1"
         Top             =   720
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_Command 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   1
         Left            =   3600
         TabIndex        =   55
         Text            =   "Text1"
         Top             =   720
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_Feedback 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   0
         Left            =   1800
         TabIndex        =   54
         Text            =   "Text1"
         Top             =   1320
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_Command 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Index           =   0
         Left            =   1800
         TabIndex        =   53
         Text            =   "Text1"
         Top             =   720
         Width           =   1575
      End
      Begin VB.Label Label20 
         Caption         =   "Motion Status"
         Height          =   255
         Index           =   1
         Left            =   240
         TabIndex        =   79
         Top             =   2520
         Width           =   1215
      End
      Begin VB.Label Label21 
         Caption         =   "Motion Status"
         Height          =   255
         Left            =   0
         TabIndex        =   78
         Top             =   0
         Width           =   1215
      End
      Begin VB.Label Label20 
         Caption         =   "Motion IO Status"
         Height          =   255
         Index           =   0
         Left            =   240
         TabIndex        =   70
         Top             =   1920
         Width           =   1215
      End
      Begin VB.Label Label19 
         Height          =   255
         Left            =   8880
         TabIndex        =   69
         Top             =   600
         Width           =   855
      End
      Begin VB.Label Label18 
         BackColor       =   &H80000018&
         Caption         =   "Axis 0"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   3
         Left            =   2280
         TabIndex        =   68
         Top             =   360
         Width           =   615
      End
      Begin VB.Label Label18 
         BackColor       =   &H80000018&
         Caption         =   "Axis 3"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   2
         Left            =   7680
         TabIndex        =   67
         Top             =   360
         Width           =   615
      End
      Begin VB.Label Label18 
         BackColor       =   &H80000018&
         Caption         =   "Axis 2"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   1
         Left            =   5880
         TabIndex        =   66
         Top             =   360
         Width           =   615
      End
      Begin VB.Label Label18 
         BackColor       =   &H80000018&
         Caption         =   "Axis 1"
         BeginProperty Font 
            Name            =   "MS Sans Serif"
            Size            =   9.75
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   0
         Left            =   4080
         TabIndex        =   65
         Top             =   360
         Width           =   615
      End
      Begin VB.Label Label10 
         Caption         =   "Feedback Pulses"
         Height          =   255
         Index           =   0
         Left            =   240
         TabIndex        =   64
         Top             =   1320
         Width           =   1335
      End
      Begin VB.Label Label9 
         Caption         =   "Command Pulses"
         Height          =   255
         Index           =   0
         Left            =   240
         TabIndex        =   63
         Top             =   720
         Width           =   1335
      End
   End
   Begin VB.Frame Frame20 
      Caption         =   "2 Axes Arc Relative Move"
      Height          =   2175
      Left            =   3120
      TabIndex        =   47
      Top             =   6120
      Width           =   2775
      Begin VB.CommandButton Btn_Arc_2Axes_Relative_CCW 
         Caption         =   "CCW"
         Height          =   735
         Left            =   240
         TabIndex        =   50
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Relative_CW 
         Caption         =   "CW"
         Height          =   735
         Left            =   1560
         TabIndex        =   49
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Relateive_Stop 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   48
         Top             =   1320
         Width           =   975
      End
   End
   Begin VB.Frame Frame19 
      Caption         =   "2 Axes Arc Absolute Move"
      Height          =   2175
      Left            =   120
      TabIndex        =   43
      Top             =   6120
      Width           =   2775
      Begin VB.CommandButton Btn_Arc_2Axes_Absolute_CCW 
         Caption         =   "CCW"
         Height          =   735
         Left            =   240
         TabIndex        =   46
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Absolute_CW 
         Caption         =   "CW"
         Height          =   735
         Left            =   1560
         TabIndex        =   45
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Absolute_Stop2 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   44
         Top             =   1320
         Width           =   975
      End
   End
   Begin VB.Frame Frame14 
      Caption         =   "4 Axes Linear Relative Move"
      Height          =   2295
      Left            =   120
      TabIndex        =   14
      Top             =   8520
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_4Axes_Relateive_Stop 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   41
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_RelateiveForward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   40
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_RelateiveBackward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   39
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame13 
      Caption         =   "4 Axes Linear Absolute Move"
      Height          =   2175
      Left            =   12000
      TabIndex        =   13
      Top             =   6120
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_4Axes_AbsoluteStop 
         Caption         =   "EMG Stop"
         Height          =   615
         Left            =   840
         TabIndex        =   38
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_AbsoluteForward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   37
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_AbsoluteBackward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   36
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame12 
      Caption         =   "3 Axes Linear Relative Movee"
      Height          =   2175
      Left            =   9120
      TabIndex        =   12
      Top             =   6120
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_3Axes_Relateive_Stop 
         Caption         =   "EMG Stop"
         Height          =   615
         Left            =   840
         TabIndex        =   35
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_RelateiveForward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   34
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_RelateiveBackward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   33
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame11 
      Caption         =   "3 Axes Linear Absolute Move"
      Height          =   2175
      Left            =   6120
      TabIndex        =   11
      Top             =   6120
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_3Axes_AbsoluteStop 
         Caption         =   "EMG Stop"
         Height          =   615
         Left            =   840
         TabIndex        =   32
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_AbsoluteForward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   31
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_AbsoluteBackward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   30
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame10 
      Caption         =   "2 Axes Linear Relative Move"
      Height          =   2175
      Left            =   12000
      TabIndex        =   10
      Top             =   3720
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_2Axes_Relateive_Stop 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   29
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_RelateiveForward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   28
         Top             =   480
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_RelateiveBackward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   27
         Top             =   480
         Width           =   975
      End
   End
   Begin VB.Frame Frame9 
      Caption         =   "2 Axes Linear Absolute Movee"
      Height          =   2175
      Left            =   9120
      TabIndex        =   9
      Top             =   3720
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_2Axes_AbsoluteStop 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   26
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_AbsoluteForward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   25
         Top             =   480
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_AbsoluteBackward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   24
         Top             =   480
         Width           =   975
      End
   End
   Begin VB.Frame Frame8 
      Caption         =   "Single Home Move"
      Height          =   2175
      Left            =   6120
      TabIndex        =   8
      Top             =   3720
      Width           =   2775
      Begin VB.CommandButton Btn_SingleHomeMove_Stop 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   23
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleHomeMove_Forward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   22
         Top             =   480
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleHomeMove_Backward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   21
         Top             =   480
         Width           =   975
      End
   End
   Begin VB.Frame Frame7 
      Caption         =   "Single Relative Move"
      Height          =   2175
      Left            =   3120
      TabIndex        =   7
      Top             =   3720
      Width           =   2775
      Begin VB.CommandButton Btn_SingleRelativeMove_Stop 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   20
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleRelativeMove_Forward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   19
         Top             =   480
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleRelativeMove_Backward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   18
         Top             =   480
         Width           =   975
      End
   End
   Begin VB.Frame Frame6 
      Caption         =   "Single Absolute Move"
      Height          =   2175
      Left            =   120
      TabIndex        =   6
      Top             =   3720
      Width           =   2775
      Begin VB.CommandButton Btn_SingleAbsoluteMove_Stop 
         Caption         =   "EMG Stop"
         Height          =   735
         Left            =   840
         TabIndex        =   17
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleAbsoluteMove_Forward 
         Caption         =   "Forward"
         Height          =   735
         Left            =   1560
         TabIndex        =   16
         Top             =   480
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleAbsoluteMove_Backward 
         Caption         =   "Backward"
         Height          =   735
         Left            =   240
         TabIndex        =   15
         Top             =   480
         Width           =   975
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Card Info"
      Height          =   2895
      Left            =   120
      TabIndex        =   0
      Top             =   480
      Width           =   2175
      Begin VB.TextBox Edit_ShowMaster_CPLDVer 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Left            =   240
         TabIndex        =   42
         Text            =   "Text1"
         Top             =   2160
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowMaster_DLLVer 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Left            =   240
         TabIndex        =   4
         Text            =   "Text1"
         Top             =   1560
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowMaster_DriverVer 
         Alignment       =   2  'Center
         BackColor       =   &H80000006&
         BeginProperty Font 
            Name            =   "Times New Roman"
            Size            =   8.25
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H0000FF00&
         Height          =   285
         Left            =   240
         TabIndex        =   2
         Text            =   "Text1"
         Top             =   960
         Width           =   1575
      End
      Begin VB.Label Label5 
         Caption         =   "FPGA Version"
         Height          =   255
         Left            =   240
         TabIndex        =   5
         Top             =   1920
         Width           =   1335
      End
      Begin VB.Label Label2 
         Caption         =   "DLL Version"
         Height          =   255
         Left            =   240
         TabIndex        =   3
         Top             =   1320
         Width           =   1335
      End
      Begin VB.Label Label1 
         Caption         =   "Driver Version"
         Height          =   255
         Left            =   240
         TabIndex        =   1
         Top             =   720
         Width           =   1335
      End
   End
   Begin VB.Label Label20 
      Caption         =   "Select EMG Logic"
      Height          =   255
      Index           =   4
      Left            =   6960
      TabIndex        =   83
      Top             =   6120
      Width           =   1455
   End
   Begin VB.Label Label20 
      Caption         =   "Input Card ID"
      Height          =   255
      Index           =   2
      Left            =   3120
      TabIndex        =   82
      Top             =   8520
      Width           =   1455
   End
   Begin VB.Label Label18 
      BackColor       =   &H80000018&
      Caption         =   "Axis 1"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Index           =   4
      Left            =   12840
      TabIndex        =   51
      Top             =   720
      Width           =   615
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim CardID As Long        'Card number for setting.
Dim BusNo  As Long        'Bus number for setting,  Motion Net BusNo is 1.
Dim MOD_No As Long        'Arrcoding switch On Module.
Dim start_axis_id As Long  'First Axis number in Motion Net bus.
Dim TotalCard As Long




Dim AxisID_SingleAxis_ForAbsolute As Long
Dim AxisID_SingleAxis_ForRelative As Long
Dim AxisID_SingleAxis_ForHome As Long
Dim AxisID_FirstAxis_For_PointTable As Long
Dim Dimension_For_PointTable As Long


Dim Axis_ID_Array_For_2Axes_Move(2) As Long
Dim Axis_ID_Array_For_2Axes_ArcMove(2) As Long
Dim Axis_ID_Array_For_3Axes_Move(3) As Long
Dim Axis_ID_Array_For_4Axes_Move(4) As Long
Dim Axis_ID_Array_For_PointTable(4) As Long


Dim FunctionFail As Boolean
Dim CurrectSelAxis As Long
Private Sub Function_Result(Ret As Long)
    If (Ret <> 0) Then
        MsgBox "Function Fail, ErrorCode  " + CStr(Ret)
        FunctionFail = True
    Else
        FunctionFail = False
    End If
End Sub


Private Sub Btn_Arc_2Axes_Absolute_CCW_Click()
    Dim Dimension As Long
    Dim Center_Pos_Array(2) As Long
    Dim Max_Arc_Speed As Long
    Dim Angle As Long

    Dimension = 2
    Center_Pos_Array(0) = 20000
    Center_Pos_Array(1) = 20000
    Max_Arc_Speed = 50000
    Angle = 180
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    Function_Result (APS_set_axis_param(1, 4, 0))  'Set PRA_ALM_LOGIC

    Function_Result (APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove(0), Center_Pos_Array(0), Max_Arc_Speed, Angle))
End Sub

Private Sub Btn_Arc_2Axes_Absolute_CW_Click()
    Dim Dimension As Long
    Dim Center_Pos_Array(2) As Long
    Dim Max_Arc_Speed As Long
    Dim Angle As Long

    Dimension = 2
    Center_Pos_Array(0) = 20000
    Center_Pos_Array(1) = 20000
    Max_Arc_Speed = 50000
    Angle = (-180)
    
    
    Function_Result (APS_set_axis_param(1, 4, 0))  'Set PRA_ALM_LOGIC

    Function_Result (APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove(0), Center_Pos_Array(0), Max_Arc_Speed, Angle))
End Sub

Private Sub Btn_Arc_2Axes_Absolute_Stop2_Click()
    Function_Result (APS_emg_stop(start_axis_id))
End Sub

Private Sub Btn_Arc_2Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(start_axis_id))
End Sub

Private Sub Btn_Arc_2Axes_Relative_CCW_Click()
    Dim Dimension As Long
    Dim Center_Pos_Array(2) As Long
    Dim Max_Arc_Speed As Long
    Dim Angle As Long

    Dimension = 2
    Center_Pos_Array(0) = 20000
    Center_Pos_Array(1) = 20000
    Max_Arc_Speed = 50000
    Angle = 180
    
    
    Function_Result (APS_set_axis_param(1, 4, 0))  'Set PRA_ALM_LOGIC

    Function_Result (APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove(0), Center_Pos_Array(0), Max_Arc_Speed, Angle))
End Sub

Private Sub Btn_Arc_2Axes_Relative_CW_Click()
    Dim Dimension As Long
    Dim Center_Pos_Array(2) As Long
    Dim Max_Arc_Speed As Long
    Dim Angle As Long

    Dimension = 2
    Center_Pos_Array(0) = 20000
    Center_Pos_Array(1) = 20000
    Max_Arc_Speed = 50000
    Angle = (-180)
      
    Function_Result (APS_set_axis_param(1, 4, 0))  'Set PRA_ALM_LOGIC

    Function_Result (APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove(0), Center_Pos_Array(0), Max_Arc_Speed, Angle))
End Sub



Private Sub Btn_BusDisconnect_Click()

    Function_Result (APS_set_servo_on(start_axis_id + 0, 0)) 'servo OFF
    
    Function_Result (APS_stop_field_bus(CardID, BusNo))   'Stop field bus
    
End Sub



Private Sub Btn_Linear_2Axes_AbsoluteBackward_Click()

    Dim Dimension As Long
    Dim Position_Array(2) As Long
    Dim Max_Linear_Speed As Long
    
    Dimension = 2
    Position_Array(0) = -500000
    Position_Array(1) = -500000
    Max_Linear_Speed = 666666
   
    
    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move(0), Position_Array(0), Max_Linear_Speed))
    
    
End Sub

Private Sub Btn_Linear_2Axes_AbsoluteForward_Click()

    Dim Dimension As Long
    Dim Position_Array(2) As Long
    Dim Max_Linear_Speed As Long
    
    Dimension = 2
    Position_Array(0) = 500000
    Position_Array(1) = 500000
    Max_Linear_Speed = 666666
    
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    
    
    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move(0), Position_Array(0), Max_Linear_Speed))
    
    
End Sub

Private Sub Btn_Linear_2Axes_AbsoluteStop_Click()
    Function_Result ((APS_emg_stop(start_axis_id)))
End Sub

Private Sub Btn_Linear_2Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(start_axis_id))
End Sub

Private Sub Btn_Linear_2Axes_RelateiveBackward_Click()
    
    Dim Dimension As Long
    Dim Position_Array(2) As Long
    Dim Max_Linear_Speed As Long
    
    Dimension = 2
    Position_Array(0) = -10000
    Position_Array(1) = -20000
    Max_Linear_Speed = 50000
    
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    
    
    Function_Result (APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move(0), Position_Array(0), Max_Linear_Speed))
    
End Sub

Private Sub Btn_Linear_2Axes_RelateiveForward_Click()
    Dim Dimension As Long
    Dim Position_Array(2) As Long
    Dim Max_Linear_Speed As Long
    
    Dimension = 2
    Position_Array(0) = 10000
    Position_Array(1) = 20000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    

    Function_Result (APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_3Axes_AbsoluteBackward_Click()
    Dim Dimension As Long
    Dim Position_Array(3) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 3
    Position_Array(0) = -10000
    Position_Array(1) = -20000
    Position_Array(2) = -30000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    

    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_3Axes_AbsoluteForward_Click()
    Dim Dimension As Long
    Dim Position_Array(3) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 3
    Position_Array(0) = 10000
    Position_Array(1) = 20000
    Position_Array(2) = 30000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
   
    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_3Axes_AbsoluteStop_Click()
    Function_Result (APS_emg_stop(start_axis_id))
End Sub

Private Sub Btn_Linear_3Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(start_axis_id))
End Sub

Private Sub Btn_Linear_3Axes_RelateiveBackward_Click()
    Dim Dimension As Long
    Dim Position_Array(3) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 3
    Position_Array(0) = -10000
    Position_Array(1) = -20000
    Position_Array(2) = -30000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    

    Function_Result (APS_relative_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_3Axes_RelateiveForward_Click()
    Dim Dimension As Long
    Dim Position_Array(3) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 3
    Position_Array(0) = 10000
    Position_Array(1) = 20000
    Position_Array(2) = 30000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
   

    Function_Result (APS_relative_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_4Axes_AbsoluteBackward_Click()
    Dim Dimension As Long
    Dim Position_Array(4) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 4
    Position_Array(0) = -10000
    Position_Array(1) = -20000
    Position_Array(2) = -30000
    Position_Array(3) = -40000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    
   
    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_4Axes_AbsoluteForward_Click()
    Dim Dimension As Long
    Dim Position_Array(4) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 4
    Position_Array(0) = 10000
    Position_Array(1) = 20000
    Position_Array(2) = 30000
    Position_Array(3) = 40000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    
   
    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_4Axes_AbsoluteStop_Click()
    Function_Result (APS_emg_stop(start_axis_id))
End Sub

Private Sub Btn_Linear_4Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(start_axis_id))
End Sub

Private Sub Btn_Linear_4Axes_RelateiveBackward_Click()
    Dim Dimension As Long
    Dim Position_Array(4) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 4
    Position_Array(0) = -10000
    Position_Array(1) = -20000
    Position_Array(2) = -30000
    Position_Array(3) = -40000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    
   
    Function_Result (APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_4Axes_RelateiveForward_Click()
    Dim Dimension As Long
    Dim Position_Array(4) As Long
    Dim Max_Linear_Speed As Long

    Dimension = 4
    Position_Array(0) = 10000
    Position_Array(1) = 20000
    Position_Array(2) = 30000
    Position_Array(3) = 40000
    Max_Linear_Speed = 50000
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    
   
    Function_Result (APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_ResetCounter_Click()

    Dim LastIndex As Long
    Dim AxisNo As Long
    
    LastIndex = 4
    
    For AxisNo = (start_axis_id + 0) To (start_axis_id + 3) Step 1
    
    
        Function_Result (APS_set_command(AxisNo, 0))
        Function_Result (APS_set_position(AxisNo, 0))
        
       ' If FunctionFail Then
        
         '   AxisNo = LastIndex + 1
            
          '  FunctionFail = False
            
        ' End If
         
         
    Next AxisNo

End Sub




Private Sub Btn_SingleAbsoluteMove_Backward_Click()
     Dim Position As Long
     Dim Max_Speed As Long
    
     Position = -500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_absolute_move(start_axis_id, Position, Max_Speed)))
End Sub

Private Sub Btn_SingleAbsoluteMove_Forward_Click()
     Dim Position As Long
     Dim Max_Speed As Long
    
     Position = 500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_absolute_move(start_axis_id, Position, Max_Speed)))
End Sub

Private Sub Btn_SingleAbsoluteMove_Stop_Click()

    Function_Result (APS_emg_stop(start_axis_id))
    
End Sub

Private Sub Btn_SingleHomeMove_Backward_Click()


    'Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1))   'Set PRA_HOME_DIR   0:Positive 1:Negative
    'Others setting like ACC,Dec... are in the initial segmant.
    'Function_Result (APS_home_move(AxisID_SingleAxis_ForHome))
    
    
    
    Function_Result (APS_set_axis_param(start_axis_id, 17, 1))  'Set Home Move Negative Direction
    
    'Others setting like ACC,Dec... are in the initial segmant.
    
    Function_Result (APS_home_move(start_axis_id))
    

End Sub

Private Sub Btn_SingleHomeMove_Forward_Click()


    'Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0))  'Set PRA_HOME_DIR   0:Positive 1:Negative
    'Others setting like ACC,Dec... are in the initial segmant.
    'Function_Result (APS_home_move(AxisID_SingleAxis_ForHome))
    
    
    Function_Result (APS_set_axis_param(start_axis_id, 17, 0))   'Set Home Move Positive Direction
    
    'Others setting like ACC,Dec... are in the initial segmant.
    
    Function_Result (APS_home_move(start_axis_id))
    
    
End Sub

Private Sub Btn_SingleHomeMove_Stop_Click()

    Function_Result (APS_emg_stop(start_axis_id))
    
End Sub

Private Sub Btn_SingleRelativeMove_Backward_Click()
     Dim Distance As Long
     Dim Max_Speed As Long
    
     Distance = -500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_relative_move(start_axis_id, Distance, Max_Speed)))
End Sub

Private Sub Btn_SingleRelativeMove_Forward_Click()
     Dim Distance As Long
     Dim Max_Speed As Long
    
     Distance = 500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_relative_move(start_axis_id, Distance, Max_Speed)))
End Sub

Private Sub Btn_SingleRelativeMove_Stop_Click()

    Function_Result (APS_emg_stop(start_axis_id))
    
End Sub



Private Sub Command2_Click()

   CardID = CLng(Text3.Text)

   start_axis_id = CardID * 4

 
   Axis_ID_Array_For_2Axes_Move(0) = start_axis_id
   Axis_ID_Array_For_2Axes_Move(1) = start_axis_id + 1
    
    
    
    Axis_ID_Array_For_2Axes_ArcMove(0) = start_axis_id
    Axis_ID_Array_For_2Axes_ArcMove(1) = start_axis_id + 1

    Axis_ID_Array_For_3Axes_Move(0) = start_axis_id
    Axis_ID_Array_For_3Axes_Move(1) = start_axis_id + 1
    Axis_ID_Array_For_3Axes_Move(2) = start_axis_id + 2
    
    Axis_ID_Array_For_4Axes_Move(0) = start_axis_id
    Axis_ID_Array_For_4Axes_Move(1) = start_axis_id + 1
    Axis_ID_Array_For_4Axes_Move(2) = start_axis_id + 2
    Axis_ID_Array_For_4Axes_Move(3) = start_axis_id + 3
    
    Axis_ID_Array_For_PointTable(0) = start_axis_id
    Axis_ID_Array_For_PointTable(1) = start_axis_id + 1
    Axis_ID_Array_For_PointTable(2) = start_axis_id + 2
    Axis_ID_Array_For_PointTable(3) = start_axis_id + 3


End Sub



Private Sub Command3_Click()

  Dim AxisNo As Long
  
  

  If (Combo1.ListIndex = 0) Then

      For AxisNo = 0 To (4 * TotalCard - 1) Step 1
        Function_Result (APS_set_axis_param(AxisNo, 562, 0))  'Set EMG Logic Active Low
      Next AxisNo
      
      If (FunctionFail = False) Then
      MsgBox "Selected EMG Logic Active Low !!"
      End If
  
  ElseIf (Combo1.ListIndex = 1) Then
      
      For AxisNo = 0 To (4 * TotalCard - 1) Step 1
      Function_Result (APS_set_axis_param(AxisNo, 562, 1))  'Set EMG Logic Active High
      Next AxisNo
      
      If (FunctionFail = False) Then
      MsgBox "Selected EMG Logic Active High !!"
      End If
      
  Else
      
      MsgBox "Please select EMG Logic first !!"
  
  End If



End Sub

Private Sub Command4_Click()


  Dim AxisNo As Long
  
  

  If (Combo2.ListIndex = 0) Then

      For AxisNo = 0 To (4 * TotalCard - 1) Step 1
       Function_Result (APS_set_axis_param(AxisNo, 0, 0))  'Set PEL/MEL input logic Positive
      Next AxisNo
      
      If (FunctionFail = False) Then
      MsgBox "Selected PEL/MEL input logic Positive !!"
      End If
  
  ElseIf (Combo2.ListIndex = 1) Then
      
      For AxisNo = 0 To (4 * TotalCard - 1) Step 1
      Function_Result (APS_set_axis_param(AxisNo, 0, 1))  'Set PEL/MEL input logic Negative
      Next AxisNo
      
      If (FunctionFail = False) Then
      MsgBox "Selected PEL/MEL input logic Negative !!"
      End If
      
  Else
      
      MsgBox "Please select PEL/MEL input logic first !!"
  
  End If


End Sub

Private Sub Command5_Click()


  Dim AxisNo As Long
  
  

  If (Combo3.ListIndex = 0) Then

      For AxisNo = 0 To (4 * TotalCard - 1) Step 1
        Function_Result (APS_set_axis_param(AxisNo, 4, 0))   'Set ALM Logic Active Low
      Next AxisNo
      
      If (FunctionFail = False) Then
      MsgBox "Selected ALM Logic Active Low !!"
      End If
  
  ElseIf (Combo3.ListIndex = 1) Then
      
      For AxisNo = 0 To (4 * TotalCard - 1) Step 1
        Function_Result (APS_set_axis_param(AxisNo, 4, 1))   'Set ALM Logic Active High
      Next AxisNo
      
      If (FunctionFail = False) Then
      MsgBox "Selected ALM Logic Active High !!"
      End If
      
  Else
      
      MsgBox "Please select ALM Logic first !!"
  
  End If












End Sub

Private Sub Form_Load()

   '--------------------------------------------------------------------------------
    CardID = 0            'Card number for setting.
    start_axis_id = 0  'First Axis number in Motion Net bus.
   '--------------------------------------------------------------------------------
    
    AxisID_SingleAxis_ForAbsolute = 0
    AxisID_SingleAxis_ForRelative = 1
    AxisID_SingleAxis_ForHome = 2
    AxisID_FirstAxis_For_PointTable = 0
    
    'Dimension_For_PointTable = 4
    Dimension_For_PointTable = 1
    
    
    Axis_ID_Array_For_2Axes_Move(0) = start_axis_id
    Axis_ID_Array_For_2Axes_Move(1) = start_axis_id + 1
    
    
    
    Axis_ID_Array_For_2Axes_ArcMove(0) = start_axis_id
    Axis_ID_Array_For_2Axes_ArcMove(1) = start_axis_id + 1

    Axis_ID_Array_For_3Axes_Move(0) = start_axis_id
    Axis_ID_Array_For_3Axes_Move(1) = start_axis_id + 1
    Axis_ID_Array_For_3Axes_Move(2) = start_axis_id + 2
    
    Axis_ID_Array_For_4Axes_Move(0) = start_axis_id
    Axis_ID_Array_For_4Axes_Move(1) = start_axis_id + 1
    Axis_ID_Array_For_4Axes_Move(2) = start_axis_id + 2
    Axis_ID_Array_For_4Axes_Move(3) = start_axis_id + 3
    
    Axis_ID_Array_For_PointTable(0) = start_axis_id
    Axis_ID_Array_For_PointTable(1) = start_axis_id + 1
    Axis_ID_Array_For_PointTable(2) = start_axis_id + 2
    Axis_ID_Array_For_PointTable(3) = start_axis_id + 3
    
    FunctionFail = False
    
    'Initial+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Dim DPAC_ID_Bits As Long
    Dim AxisNo As Long
    Dim info As Long
    
    TotalCard = 0
    
    If (APS_initial(DPAC_ID_Bits, 0) = 0) Then   'Initial Card, CardID is assigned by system.
    
        For i = 0 To 15 Step 1
            If (DPAC_ID_Bits And (2 ^ i)) Then
                TotalCard = TotalCard + 1
            End If
        Next i
        
        'Get Card information
         Function_Result (APS_get_device_info(CardID, 16, info))          'Get Driver Version
         Edit_ShowMaster_DriverVer.Text = info
        
         Edit_ShowMaster_DLLVer.Text = APS_version                        'Get DLL Version

         Function_Result (APS_get_device_info(CardID, 32, info))          'Get CPLD Version
         Edit_ShowMaster_CPLDVer.Text = info
              
        
        '****************************************************************************************************************************
         For AxisNo = 0 To (4 * TotalCard - 1) Step 1
        
            Function_Result (APS_set_servo_on(AxisNo, 1))                  'servo ON
            
            Function_Result (APS_set_axis_param(AxisNo, 0, 0))             'PEL/MEL input logic
            Function_Result (APS_set_axis_param(AxisNo, 4, 0))             'Set PRA_ALM_LOGIC
           
            Function_Result (APS_set_axis_param(AxisNo, 128, 3))           'Set PRA_PLS_IPT_MODE(The user must make change based on actual conditions)
            Function_Result (APS_set_axis_param(AxisNo, 129, 4))           'Set PRA_PLS_OPT_MODE(The user must make change based on actual conditions)
            
            
            'Set Single Move Parameter
            Function_Result (APS_set_axis_param(AxisNo, 33, 1000000))      'Set Acceleration rate
            Function_Result (APS_set_axis_param(AxisNo, 34, 1000000))      'Set Deceleration rate
            Function_Result (APS_set_axis_param(AxisNo, 35, 0))            'Set Start velocity
            Function_Result (APS_set_axis_param(AxisNo, 32, 1))            'Set S-Curve
            
            
            'Set Home Move Parameter
            Function_Result (APS_set_axis_param(AxisNo, 16, 0))             'Set Home mode (Home search 1st mode)
           
            Function_Result (APS_set_axis_param(AxisNo, 21, 10000))         'Set Homing maximum Velocity (Unit:pulse/sec)
            
            Function_Result (APS_set_axis_param(AxisNo, 25, 152))           'Set Homing leave home Velocity (Unit:pulse/sec)
            
            Function_Result (APS_set_axis_param(AxisNo, 24, 0))             'Set Specify the EZ count up Value
            
            Function_Result (APS_set_axis_param(AxisNo, 26, 100))           'Set Homing leave home distance.Specify ORG Offset (Unit:pulse)
          
            
            'Set EMG logic
            Function_Result (APS_set_axis_param(AxisNo, 561, 0))  'Select gpio input
           'Function_Result (APS_set_axis_param(AxisNo, 562, 1))  'Set EMG logic (0:Active Low /1:Active High)
                  
        Next AxisNo
        
        '*******************************************************************************************************************************
        MsgBox "Initial Success!!"
        
     Else
     
        MsgBox "Initial Fail, Sample Close!!", vbOKOnly
        
        APS_close
        
     End If
    '++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
End Sub



Private Sub Timer1_Timer()


    Dim Command As Long
    Dim Position As Long
    Dim Error As Long
    
    Dim Dec2Bin As String
    Dim Dec2Bin_ As String
    
    Dim MotionSts As Long
    Dim IoSts As Long
    Dim Index As Long
    Dim TrgCnt As Long
    Dim Ret As Long
    Dim CmpVal As Long
    Dim EncCnt As Long
    Dim AxisNo As Long
    Dim RunningPoint As Long
    Dim DI_Value, DOdata As Long
    Dim Index_1 As Long
    
    

    For Index = start_axis_id To start_axis_id + 3
    
        Index_1 = Index Mod 4
    'Motion Segment
    
        APS_get_command Index, Command
        Edit_ShowAxis_Command(Index_1).Text = Command

        APS_get_position Index, Position
        Edit_ShowAxis_Feedback(Index_1).Text = Position
        
        
        
        
        
    '-------Get Motion IO status------------------------------------------------------------
        IoSts = APS_motion_io_status(Index)
        
        Text1(Index_1) = Hex(IoSts)
        
        
    '------Convert Decimal to Binary--------
    '    Do Until IoSts = 0
        
    '        If (IoSts Mod 2) Then
    '            Dec2Bin = "1" & Dec2Bin
    '        Else
    '            Dec2Bin = "0" & Dec2Bin
    '        End If
            
    '        IoSts = IoSts \ 2
    '    Loop
        
    '    Text1(Index_1) = Dec2Bin
    '    Dec2Bin = ""
    '----------------------------------------
        
        
        
    '-------Get Motion status------------------------------------------------------------
        MotionSts = APS_motion_status(Index)
        
         Text2(Index_1) = Hex(MotionSts)
         
         
    '------Convert Decimal to Binary--------
    '    Do Until MotionSts = 0
        
    '        If (MotionSts Mod 2) Then
    '            Dec2Bin_ = "1" & Dec2Bin_
    '        Else
    '            Dec2Bin_ = "0" & Dec2Bin_
    '        End If
            
    '        MotionSts = MotionSts \ 2
    '    Loop
        
    '    Text2(Index_1) = Dec2Bin_
    '    Dec2Bin_ = ""
    '----------------------------------------
        
        
        
        
        
   '------------------------------------------------------------------------
        

        'APS_get_running_point_index2 Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable), RunningPoint
        'Edit_Show_PointTable_CurrIndex.Text = RunningPoint
   
     'Compare Segment
    
        'APS_get_field_bus_trigger_count CardID, BusNo, MOD_No, Index, TrgCnt
        'Edit_ShowTriggerCount(Index) = TrgCnt

       ' APS_get_field_bus_encoder CardID, BusNo, MOD_No, Index, EncCnt
        'Edit_ShowTriggerEnc(Index).Text = EncCnt

      '  APS_get_field_bus_trigger_linear_cmp CardID, BusNo, MOD_No, Index, CmpVal
        'Edit_ShowTrigger_LinearCMP_LinearCMP(Index).Text = CmpVal
        
    'General DIO
    
        'APS_get_field_bus_d_input CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), DI_Value
        'Function_Result (APS_read_d_input(CardID, 0, DI_Value))
        'Edit_ShowDIData.Text = Hex(DI_Value)

        'APS_get_field_bus_d_output CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), DOdata
        
       
        
        
    Next Index

End Sub
