VERSION 5.00
Begin VB.Form MainForm 
   Caption         =   "MNET-4XMO-C VB Sample"
   ClientHeight    =   10545
   ClientLeft      =   2505
   ClientTop       =   660
   ClientWidth     =   17355
   Icon            =   "Main.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   10545
   ScaleWidth      =   17355
   Begin VB.Frame Frame3 
      Caption         =   "Axis Info"
      Height          =   2655
      Left            =   4920
      TabIndex        =   116
      Top             =   120
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
         Left            =   10320
         TabIndex        =   159
         Text            =   "Text2"
         Top             =   2280
         Width           =   1215
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
         Left            =   10320
         TabIndex        =   158
         Text            =   "Text2"
         Top             =   1920
         Width           =   1215
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
         Left            =   10320
         TabIndex        =   157
         Text            =   "Text2"
         Top             =   1560
         Width           =   1215
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
         Left            =   10320
         TabIndex        =   156
         Text            =   "Text2"
         Top             =   1200
         Width           =   1215
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
         Left            =   9000
         TabIndex        =   155
         Text            =   "Text1"
         Top             =   2280
         Width           =   1215
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
         Left            =   9000
         TabIndex        =   154
         Text            =   "Text1"
         Top             =   1920
         Width           =   1215
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
         Left            =   9000
         TabIndex        =   153
         Text            =   "Text1"
         Top             =   1560
         Width           =   1215
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
         Left            =   9000
         TabIndex        =   130
         Text            =   "Text1"
         Top             =   1200
         Width           =   1215
      End
      Begin VB.Timer Timer1 
         Interval        =   50
         Left            =   6600
         Top             =   0
      End
      Begin VB.CommandButton Btn_ResetCounter 
         Caption         =   "Reset Counter"
         Height          =   1095
         Left            =   6840
         TabIndex        =   129
         Top             =   1080
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowAxis_IOSts 
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
         Left            =   5160
         TabIndex        =   128
         Text            =   "Text1"
         Top             =   2160
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_IOSts 
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
         Left            =   3480
         TabIndex        =   127
         Text            =   "Text1"
         Top             =   2160
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_IOSts 
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
         Left            =   1800
         TabIndex        =   126
         Text            =   "Text1"
         Top             =   2160
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
         Index           =   3
         Left            =   5160
         TabIndex        =   125
         Text            =   "Text1"
         Top             =   1560
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
         Left            =   3480
         TabIndex        =   124
         Text            =   "Text1"
         Top             =   1560
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
         Left            =   1800
         TabIndex        =   123
         Text            =   "Text1"
         Top             =   1560
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
         Left            =   5160
         TabIndex        =   122
         Text            =   "Text1"
         Top             =   960
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
         Left            =   3480
         TabIndex        =   121
         Text            =   "Text1"
         Top             =   960
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
         Left            =   1800
         TabIndex        =   120
         Text            =   "Text1"
         Top             =   960
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
         Left            =   120
         TabIndex        =   119
         Text            =   "Text1"
         Top             =   1560
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
         Left            =   120
         TabIndex        =   118
         Text            =   "Text1"
         Top             =   960
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowAxis_IOSts 
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
         Left            =   120
         TabIndex        =   117
         Text            =   "Text1"
         Top             =   2160
         Width           =   1575
      End
      Begin VB.Label Label20 
         Caption         =   "Motion Status"
         Height          =   255
         Index           =   1
         Left            =   10440
         TabIndex        =   161
         Top             =   960
         Width           =   1215
      End
      Begin VB.Label Label21 
         Caption         =   "Motion IO Status"
         Height          =   255
         Left            =   0
         TabIndex        =   160
         Top             =   0
         Width           =   1215
      End
      Begin VB.Label Label18 
         BackColor       =   &H80000018&
         Caption         =   "Axis 4"
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
         Index           =   8
         Left            =   8280
         TabIndex        =   152
         Top             =   2280
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
         Index           =   7
         Left            =   8280
         TabIndex        =   151
         Top             =   1920
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
         Index           =   6
         Left            =   8280
         TabIndex        =   150
         Top             =   1560
         Width           =   615
      End
      Begin VB.Label Label20 
         Caption         =   "Motion IO Status"
         Height          =   255
         Index           =   0
         Left            =   9000
         TabIndex        =   149
         Top             =   960
         Width           =   1215
      End
      Begin VB.Label Label19 
         Height          =   255
         Left            =   8880
         TabIndex        =   148
         Top             =   600
         Width           =   855
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
         Index           =   5
         Left            =   8280
         TabIndex        =   147
         Top             =   1200
         Width           =   615
      End
      Begin VB.Label Label18 
         BackColor       =   &H80000018&
         Caption         =   "Axis 4"
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
         Left            =   5640
         TabIndex        =   146
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
         Left            =   3960
         TabIndex        =   145
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
         Left            =   2280
         TabIndex        =   144
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
         Left            =   600
         TabIndex        =   143
         Top             =   360
         Width           =   615
      End
      Begin VB.Label Label11 
         Caption         =   "Droop Pulses"
         Height          =   255
         Index           =   3
         Left            =   5160
         TabIndex        =   142
         Top             =   1920
         Width           =   1335
      End
      Begin VB.Label Label11 
         Caption         =   "Droop Pulses"
         Height          =   255
         Index           =   2
         Left            =   3480
         TabIndex        =   141
         Top             =   1920
         Width           =   1335
      End
      Begin VB.Label Label11 
         Caption         =   "Droop Pulses"
         Height          =   255
         Index           =   1
         Left            =   1800
         TabIndex        =   140
         Top             =   1920
         Width           =   1335
      End
      Begin VB.Label Label10 
         Caption         =   "Feedback Pulses"
         Height          =   255
         Index           =   5
         Left            =   5160
         TabIndex        =   139
         Top             =   1320
         Width           =   1335
      End
      Begin VB.Label Label10 
         Caption         =   "Feedback Pulses"
         Height          =   255
         Index           =   4
         Left            =   3480
         TabIndex        =   138
         Top             =   1320
         Width           =   1335
      End
      Begin VB.Label Label10 
         Caption         =   "Feedback Pulses"
         Height          =   255
         Index           =   3
         Left            =   1800
         TabIndex        =   137
         Top             =   1320
         Width           =   1335
      End
      Begin VB.Label Label9 
         Caption         =   "Command Pulses"
         Height          =   255
         Index           =   4
         Left            =   5160
         TabIndex        =   136
         Top             =   720
         Width           =   1335
      End
      Begin VB.Label Label9 
         Caption         =   "Command Pulses"
         Height          =   255
         Index           =   3
         Left            =   3480
         TabIndex        =   135
         Top             =   720
         Width           =   1335
      End
      Begin VB.Label Label9 
         Caption         =   "Command Pulses"
         Height          =   255
         Index           =   2
         Left            =   1800
         TabIndex        =   134
         Top             =   720
         Width           =   1335
      End
      Begin VB.Label Label11 
         Caption         =   "Droop Pulses"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   133
         Top             =   1920
         Width           =   1335
      End
      Begin VB.Label Label10 
         Caption         =   "Feedback Pulses"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   132
         Top             =   1320
         Width           =   1335
      End
      Begin VB.Label Label9 
         Caption         =   "Command Pulses"
         Height          =   255
         Index           =   0
         Left            =   120
         TabIndex        =   131
         Top             =   720
         Width           =   1335
      End
   End
   Begin VB.Frame Frame21 
      Caption         =   "General DIO"
      Height          =   2655
      Left            =   3000
      TabIndex        =   105
      Top             =   7800
      Width           =   2775
      Begin VB.CommandButton Btn_Set_DOData 
         Caption         =   "Set DO"
         Height          =   975
         Left            =   1320
         TabIndex        =   114
         Top             =   600
         Width           =   1335
      End
      Begin VB.TextBox Edit_SetDOData 
         Height          =   285
         Left            =   120
         TabIndex        =   112
         Text            =   "0"
         Top             =   1200
         Width           =   1095
      End
      Begin VB.TextBox Edit_GetDOData 
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
         Left            =   120
         TabIndex        =   110
         Text            =   "0"
         Top             =   1920
         Width           =   1215
      End
      Begin VB.TextBox Edit_ShowDIData 
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
         Left            =   1440
         TabIndex        =   108
         Text            =   "0"
         Top             =   1920
         Width           =   1215
      End
      Begin VB.TextBox Edit_SetModuleID_ForGeneralDIO 
         Height          =   285
         Left            =   120
         TabIndex        =   106
         Text            =   "0"
         Top             =   600
         Width           =   1095
      End
      Begin VB.Label Label17 
         Caption         =   "Set_DO_Data"
         Height          =   255
         Left            =   120
         TabIndex        =   113
         Top             =   960
         Width           =   1095
      End
      Begin VB.Label Label16 
         Caption         =   "Check_DO_Data"
         Height          =   255
         Left            =   120
         TabIndex        =   111
         Top             =   1680
         Width           =   1335
      End
      Begin VB.Label Label4 
         Caption         =   "DI_Data"
         Height          =   255
         Left            =   1680
         TabIndex        =   109
         Top             =   1680
         Width           =   735
      End
      Begin VB.Label Label3 
         Caption         =   "Set Module ID"
         Height          =   255
         Left            =   120
         TabIndex        =   107
         Top             =   360
         Width           =   1215
      End
   End
   Begin VB.Frame Frame20 
      Caption         =   "2 Axes Arc Relative Move"
      Height          =   2415
      Left            =   5880
      TabIndex        =   101
      Top             =   5400
      Width           =   2775
      Begin VB.CommandButton Btn_Arc_2Axes_Relative_CCW 
         Caption         =   "CCW"
         Height          =   855
         Left            =   240
         TabIndex        =   104
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Relative_CW 
         Caption         =   "CW"
         Height          =   855
         Left            =   1560
         TabIndex        =   103
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Relateive_Stop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   102
         Top             =   1320
         Width           =   975
      End
   End
   Begin VB.Frame Frame19 
      Caption         =   "2 Axes Arc Absolute Move"
      Height          =   2415
      Left            =   3000
      TabIndex        =   97
      Top             =   5400
      Width           =   2775
      Begin VB.CommandButton Btn_Arc_2Axes_Absolute_CCW 
         Caption         =   "CCW"
         Height          =   855
         Left            =   240
         TabIndex        =   100
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Absolute_CW 
         Caption         =   "CW"
         Height          =   855
         Left            =   1560
         TabIndex        =   99
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Arc_2Axes_Absolute_Stop2 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   98
         Top             =   1320
         Width           =   975
      End
   End
   Begin VB.Frame Frame17 
      Caption         =   "Compare"
      Height          =   2655
      Left            =   11640
      TabIndex        =   28
      Top             =   7800
      Width           =   5655
      Begin VB.CommandButton Btn_Trigger_Count 
         Caption         =   "Reset Trigger Count"
         Height          =   495
         Left            =   4320
         TabIndex        =   93
         Top             =   2040
         Width           =   1215
      End
      Begin VB.CommandButton Btn_Manual_Compare 
         Caption         =   "Manual CMP"
         Height          =   495
         Left            =   3000
         TabIndex        =   92
         Top             =   2040
         Width           =   1215
      End
      Begin VB.CommandButton Btn_Table_Compare 
         Caption         =   "Table CMP and Move"
         Height          =   495
         Left            =   1680
         TabIndex        =   91
         Top             =   2040
         Width           =   1215
      End
      Begin VB.CommandButton Btn_Linear_Compare 
         Caption         =   "Linear CMP and Move"
         Height          =   495
         Left            =   360
         TabIndex        =   90
         Top             =   2040
         Width           =   1215
      End
      Begin VB.TextBox Edit_ShowTrigger_LinearCMP_LinearCMP 
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
         Left            =   4200
         TabIndex        =   89
         Text            =   "Text1"
         Top             =   1680
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTrigger_LinearCMP_LinearCMP 
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
         Left            =   3000
         TabIndex        =   87
         Text            =   "Text1"
         Top             =   1680
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTrigger_LinearCMP_LinearCMP 
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
         Left            =   1680
         TabIndex        =   85
         Text            =   "Text1"
         Top             =   1680
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTrigger_LinearCMP_LinearCMP 
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
         Left            =   360
         TabIndex        =   83
         Text            =   "Text1"
         Top             =   1680
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerEnc 
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
         Left            =   4200
         TabIndex        =   81
         Text            =   "Text1"
         Top             =   1080
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerEnc 
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
         Left            =   3000
         TabIndex        =   79
         Text            =   "Text1"
         Top             =   1080
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerEnc 
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
         Left            =   1680
         TabIndex        =   77
         Text            =   "Text1"
         Top             =   1080
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerEnc 
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
         Left            =   360
         TabIndex        =   75
         Text            =   "Text1"
         Top             =   1080
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerCount 
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
         Left            =   4200
         TabIndex        =   73
         Text            =   "Text1"
         Top             =   480
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerCount 
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
         Left            =   3000
         TabIndex        =   71
         Text            =   "Text1"
         Top             =   480
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerCount 
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
         Left            =   1680
         TabIndex        =   69
         Text            =   "Text1"
         Top             =   480
         Width           =   1095
      End
      Begin VB.TextBox Edit_ShowTriggerCount 
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
         Left            =   360
         TabIndex        =   67
         Text            =   "Text1"
         Top             =   480
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "CMPVal 3"
         Height          =   255
         Index           =   11
         Left            =   4200
         TabIndex        =   88
         Top             =   1440
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "CMPVal 2"
         Height          =   255
         Index           =   10
         Left            =   3000
         TabIndex        =   86
         Top             =   1440
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "CMPVal 1"
         Height          =   255
         Index           =   9
         Left            =   1680
         TabIndex        =   84
         Top             =   1440
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "CMPVal 0"
         Height          =   255
         Index           =   8
         Left            =   360
         TabIndex        =   82
         Top             =   1440
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerEnc 3"
         Height          =   255
         Index           =   7
         Left            =   4200
         TabIndex        =   80
         Top             =   840
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerEnc 2"
         Height          =   255
         Index           =   6
         Left            =   3000
         TabIndex        =   78
         Top             =   840
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerEnc 1"
         Height          =   255
         Index           =   5
         Left            =   1680
         TabIndex        =   76
         Top             =   840
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerEnc 0"
         Height          =   255
         Index           =   4
         Left            =   360
         TabIndex        =   74
         Top             =   840
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerCnt 3"
         Height          =   255
         Index           =   3
         Left            =   4200
         TabIndex        =   72
         Top             =   240
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerCnt 2"
         Height          =   255
         Index           =   2
         Left            =   3000
         TabIndex        =   70
         Top             =   240
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerCnt 1"
         Height          =   255
         Index           =   1
         Left            =   1680
         TabIndex        =   68
         Top             =   240
         Width           =   1095
      End
      Begin VB.Label Label15 
         Caption         =   "TriggerCnt 0"
         Height          =   255
         Index           =   0
         Left            =   360
         TabIndex        =   66
         Top             =   240
         Width           =   1095
      End
   End
   Begin VB.Frame Frame15 
      Caption         =   "Point Table"
      Height          =   2655
      Left            =   5880
      TabIndex        =   27
      Top             =   7800
      Width           =   5655
      Begin VB.Frame Frame18 
         Caption         =   "All Index Move"
         Height          =   1695
         Left            =   2880
         TabIndex        =   60
         Top             =   720
         Width           =   2535
         Begin VB.CommandButton Btn_PointTable_MoveALL 
            Caption         =   "Set Points and Move"
            Height          =   1215
            Left            =   360
            TabIndex        =   65
            Top             =   240
            Width           =   1935
         End
      End
      Begin VB.CommandButton Btn_PointTable_Stop 
         Caption         =   "Stop"
         Height          =   375
         Left            =   3120
         TabIndex        =   59
         Top             =   360
         Width           =   2175
      End
      Begin VB.Frame Frame16 
         Caption         =   "Single Index Move"
         Height          =   1695
         Left            =   240
         TabIndex        =   58
         Top             =   720
         Width           =   2535
         Begin VB.CommandButton Btn_PointTable_SingleIndexMove 
            Caption         =   "Step2:Move"
            Height          =   735
            Left            =   1320
            TabIndex        =   64
            Top             =   840
            Width           =   1095
         End
         Begin VB.CommandButton Btn_SetPointTable 
            Caption         =   "Step1: Set Tables"
            Height          =   1335
            Left            =   120
            TabIndex        =   63
            Top             =   240
            Width           =   1095
         End
         Begin VB.TextBox Edit_SetTargetIndex_ForSinglePointMove 
            Height          =   285
            Left            =   1320
            TabIndex        =   62
            Text            =   "10"
            Top             =   480
            Width           =   1095
         End
         Begin VB.Label Label14 
            Caption         =   "Target Index"
            Height          =   255
            Left            =   1320
            TabIndex        =   61
            Top             =   240
            Width           =   1095
         End
      End
      Begin VB.TextBox Edit_Show_PointTable_CurrIndex 
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
         Left            =   1440
         TabIndex        =   57
         Text            =   "Text1"
         Top             =   360
         Width           =   1095
      End
      Begin VB.Label Label13 
         Caption         =   "Running Index"
         Height          =   255
         Left            =   240
         TabIndex        =   56
         Top             =   360
         Width           =   1335
      End
   End
   Begin VB.Frame Frame14 
      Caption         =   "4 Axes Linear Relative Move"
      Height          =   2655
      Left            =   120
      TabIndex        =   26
      Top             =   7800
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_4Axes_Relateive_Stop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   55
         Top             =   1440
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_RelateiveForward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   54
         Top             =   480
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_RelateiveBackward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   53
         Top             =   480
         Width           =   975
      End
   End
   Begin VB.Frame Frame13 
      Caption         =   "4 Axes Linear Absolute Move"
      Height          =   2415
      Left            =   14520
      TabIndex        =   25
      Top             =   5400
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_4Axes_AbsoluteStop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   52
         Top             =   1440
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_AbsoluteForward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   51
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_4Axes_AbsoluteBackward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   50
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame12 
      Caption         =   "3 Axes Linear Relative Movee"
      Height          =   2415
      Left            =   11640
      TabIndex        =   24
      Top             =   5400
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_3Axes_Relateive_Stop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   49
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_RelateiveForward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   48
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_RelateiveBackward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   47
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame11 
      Caption         =   "3 Axes Linear Absolute Move"
      Height          =   2415
      Left            =   8760
      TabIndex        =   23
      Top             =   5400
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_3Axes_AbsoluteStop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   46
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_AbsoluteForward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   45
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_3Axes_AbsoluteBackward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   44
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame10 
      Caption         =   "2 Axes Linear Relative Move"
      Height          =   2415
      Left            =   120
      TabIndex        =   22
      Top             =   5400
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_2Axes_Relateive_Stop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   43
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_RelateiveForward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   42
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_RelateiveBackward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   41
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame9 
      Caption         =   "2 Axes Linear Absolute Movee"
      Height          =   2415
      Left            =   14520
      TabIndex        =   21
      Top             =   2880
      Width           =   2775
      Begin VB.CommandButton Btn_Linear_2Axes_AbsoluteStop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   40
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_AbsoluteForward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   39
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_Linear_2Axes_AbsoluteBackward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   38
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame8 
      Caption         =   "Single Home Move"
      Height          =   2415
      Left            =   11640
      TabIndex        =   15
      Top             =   2880
      Width           =   2775
      Begin VB.CommandButton Btn_SingleHomeMove_Stop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   37
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleHomeMove_Forward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   36
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleHomeMove_Backward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   35
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame7 
      Caption         =   "Single Relative Move"
      Height          =   2415
      Left            =   8760
      TabIndex        =   14
      Top             =   2880
      Width           =   2775
      Begin VB.CommandButton Btn_SingleRelativeMove_Stop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   34
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleRelativeMove_Forward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   33
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleRelativeMove_Backward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   32
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame6 
      Caption         =   "Single Absolute Move"
      Height          =   2415
      Left            =   5880
      TabIndex        =   13
      Top             =   2880
      Width           =   2775
      Begin VB.CommandButton Btn_SingleAbsoluteMove_Stop 
         Caption         =   "Stop"
         Height          =   855
         Left            =   840
         TabIndex        =   31
         Top             =   1320
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleAbsoluteMove_Forward 
         Caption         =   "Forward"
         Height          =   855
         Left            =   1560
         TabIndex        =   30
         Top             =   360
         Width           =   975
      End
      Begin VB.CommandButton Btn_SingleAbsoluteMove_Backward 
         Caption         =   "Backward"
         Height          =   855
         Left            =   240
         TabIndex        =   29
         Top             =   360
         Width           =   975
      End
   End
   Begin VB.Frame Frame5 
      Caption         =   "Module Info"
      Height          =   2415
      Left            =   3000
      TabIndex        =   12
      Top             =   2880
      Width           =   2775
      Begin VB.CommandButton Btn_GetModuleInfo 
         Caption         =   "Get Module Info"
         Height          =   855
         Left            =   480
         TabIndex        =   20
         Top             =   1200
         Width           =   1575
      End
      Begin VB.TextBox Edit_SetModuleID_ForModuleInfo 
         Height          =   285
         Left            =   480
         TabIndex        =   19
         Text            =   "0"
         Top             =   720
         Width           =   1575
      End
      Begin VB.Label Label12 
         Caption         =   "Set Module ID"
         Height          =   255
         Left            =   480
         TabIndex        =   18
         Top             =   480
         Width           =   1335
      End
   End
   Begin VB.Frame Frame4 
      Caption         =   "Step1: Bus Start/Stop"
      Height          =   2415
      Left            =   120
      TabIndex        =   11
      Top             =   2880
      Width           =   2775
      Begin VB.CommandButton Btn_BusDisconnect 
         Caption         =   "Disconnect"
         Height          =   855
         Left            =   480
         TabIndex        =   17
         Top             =   1320
         Width           =   1815
      End
      Begin VB.CommandButton Btn_BusConnect 
         Caption         =   "Connect"
         Height          =   855
         Left            =   480
         TabIndex        =   16
         Top             =   360
         Width           =   1815
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "Module Info"
      Height          =   2655
      Left            =   2520
      TabIndex        =   1
      Top             =   120
      Width           =   2295
      Begin VB.TextBox Edit_ShowMaster_PCBBottomVer 
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
         Left            =   360
         TabIndex        =   96
         Text            =   "Text1"
         Top             =   1920
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowModule_PCBTopVer 
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
         Left            =   360
         TabIndex        =   10
         Text            =   "No Data"
         Top             =   1320
         Width           =   1575
      End
      Begin VB.TextBox Edit_ShowModule_FPGAVer 
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
         Left            =   360
         TabIndex        =   8
         Text            =   "No Data"
         Top             =   720
         Width           =   1575
      End
      Begin VB.Label Label6 
         Caption         =   "PCB Bottom Ver."
         Height          =   255
         Left            =   360
         TabIndex        =   95
         Top             =   1680
         Width           =   1335
      End
      Begin VB.Label Label8 
         Caption         =   "PCB TOP Ver."
         Height          =   255
         Left            =   360
         TabIndex        =   9
         Top             =   1080
         Width           =   1335
      End
      Begin VB.Label Label7 
         Caption         =   "FPGA  Version"
         Height          =   255
         Left            =   360
         TabIndex        =   7
         Top             =   480
         Width           =   1335
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Master Card Info"
      Height          =   2655
      Left            =   120
      TabIndex        =   0
      Top             =   120
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
         TabIndex        =   94
         Text            =   "Text1"
         Top             =   1920
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
         TabIndex        =   5
         Text            =   "Text1"
         Top             =   1320
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
         TabIndex        =   3
         Text            =   "Text1"
         Top             =   720
         Width           =   1575
      End
      Begin VB.Label Label5 
         Caption         =   "CPLD Version"
         Height          =   255
         Left            =   240
         TabIndex        =   6
         Top             =   1680
         Width           =   1335
      End
      Begin VB.Label Label2 
         Caption         =   "DLL Version"
         Height          =   255
         Left            =   240
         TabIndex        =   4
         Top             =   1080
         Width           =   1335
      End
      Begin VB.Label Label1 
         Caption         =   "Driver Version"
         Height          =   255
         Left            =   240
         TabIndex        =   2
         Top             =   480
         Width           =   1335
      End
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
      TabIndex        =   115
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
Dim Start_Axis_ID As Long  'First Axis number in Motion Net bus.





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
    Center_Pos_Array(0) = -20000
    Center_Pos_Array(1) = -20000
    Max_Arc_Speed = 50000
    Angle = 180
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC

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
    Angle = 180
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC

    Function_Result (APS_absolute_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove(0), Center_Pos_Array(0), Max_Arc_Speed, Angle))
End Sub

Private Sub Btn_Arc_2Axes_Absolute_Stop2_Click()
    Function_Result (APS_emg_stop(Start_Axis_ID))
End Sub

Private Sub Btn_Arc_2Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(Start_Axis_ID))
End Sub

Private Sub Btn_Arc_2Axes_Relative_CCW_Click()
    Dim Dimension As Long
    Dim Center_Pos_Array(2) As Long
    Dim Max_Arc_Speed As Long
    Dim Angle As Long

    Dimension = 2
    Center_Pos_Array(0) = -20000
    Center_Pos_Array(1) = -20000
    Max_Arc_Speed = 50000
    Angle = 180
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC

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
    Angle = 180
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC

    Function_Result (APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove(0), Center_Pos_Array(0), Max_Arc_Speed, Angle))
End Sub

Private Sub Btn_BusConnect_Click()
    
    Dim AxisNo As Long
    

    
    Function_Result (APS_start_field_bus(CardID, BusNo, Start_Axis_ID))

    If FunctionFail = False Then
    
       '****************************************************************************************************************************
         For AxisNo = Start_Axis_ID To 1003 Step 1
        
            Function_Result (APS_set_servo_on(AxisNo, 1))                  'servo ON
            
            Function_Result (APS_set_axis_param(AxisNo, 0, 0))             'PEL/MEL input logic
            Function_Result (APS_set_axis_param(AxisNo, 4, 1))             'Set PRA_ALM_LOGIC
            Function_Result (APS_set_axis_param(AxisNo, 128, 2))           'Set PRA_PLS_IPT_MODE
            Function_Result (APS_set_axis_param(AxisNo, 129, 4))           'Set PRA_PLS_OPT_MODE
            
            
            'Set Single Move Parameter
            Function_Result (APS_set_axis_param(AxisNo, 33, 1000000))      'Set Acceleration rate
            Function_Result (APS_set_axis_param(AxisNo, 34, 1000000))      'Set Deceleration rate
            Function_Result (APS_set_axis_param(AxisNo, 35, 0))            'Set Start velocity
            Function_Result (APS_set_axis_param(AxisNo, 32, 1))            'Set S-Curve
'------------------------------------------------------------------------------------------------------------------

            'Set Home Move Parameter
            Function_Result (APS_set_axis_param(AxisNo, 16, 0))             'Set Home mode (Home search 1st mode)
           
            Function_Result (APS_set_axis_param(AxisNo, 21, 10000))         'Set Homing maximum Velocity (Unit:pulse/sec)
            
            Function_Result (APS_set_axis_param(AxisNo, 25, 152))           'Set Homing leave home Velocity (Unit:pulse/sec)
            
            Function_Result (APS_set_axis_param(AxisNo, 24, 0))             'Set Specify the EZ count up Value
            
            Function_Result (APS_set_axis_param(AxisNo, 26, 100))           'Set Homing leave home distance.Specify ORG Offset (Unit:pulse)
          
      
        Next AxisNo
        
        '*******************************************************************************************************************************
            



        





        MsgBox "Bus Connected!!"

    Else
        MsgBox "Connect Fail!!"
    End If
End Sub

Private Sub Btn_BusDisconnect_Click()

    Function_Result (APS_set_servo_on(Start_Axis_ID + 0, 0)) 'servo OFF
    
    Function_Result (APS_stop_field_bus(CardID, BusNo))   'Stop field bus
    
End Sub

Private Sub Btn_GetModuleInfo_Click()

    Dim Info As Long
    
    Function_Result (APS_get_field_bus_device_info(CardID, BusNo, CLng(Edit_SetModuleID_ForModuleInfo.Text), &H21, Info))  'Get FPGA Version
    Edit_ShowModule_FPGAVer.Text = Info
    

    Function_Result (APS_get_field_bus_device_info(CardID, BusNo, CLng(Edit_SetModuleID_ForModuleInfo.Text), &H30, Info))    'Get PCB Top Version
    Edit_ShowModule_PCBTopVer.Text = Hex(Info)
    
    
 
    Function_Result (APS_get_field_bus_device_info(CardID, BusNo, CLng(Edit_SetModuleID_ForModuleInfo.Text), &H31, Info))     'Get PCB Bottom Version
    Edit_ShowMaster_PCBBottomVer.Text = Hex(Info)
    
    
    
End Sub

Private Sub Btn_Linear_2Axes_AbsoluteBackward_Click()

    Dim Dimension As Long
    Dim Position_Array(2) As Long
    Dim Max_Linear_Speed As Long
    
    Dimension = 2
    Position_Array(0) = -500000
    Position_Array(1) = -500000
    Max_Linear_Speed = 666666
    
    'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    
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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    
    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move(0), Position_Array(0), Max_Linear_Speed))
    
    
End Sub

Private Sub Btn_Linear_2Axes_AbsoluteStop_Click()
    Function_Result ((APS_emg_stop(Start_Axis_ID)))
End Sub

Private Sub Btn_Linear_2Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(Start_Axis_ID))
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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    
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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC

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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC

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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC

    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_3Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_3Axes_AbsoluteStop_Click()
    Function_Result (APS_emg_stop(Start_Axis_ID))
End Sub

Private Sub Btn_Linear_3Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(Start_Axis_ID))
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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC

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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC

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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1003, 4, 0))  'Set PRA_ALM_LOGIC
   
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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1003, 4, 0))  'Set PRA_ALM_LOGIC
   
    Function_Result (APS_absolute_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_4Axes_AbsoluteStop_Click()
    Function_Result (APS_emg_stop(Start_Axis_ID))
End Sub

Private Sub Btn_Linear_4Axes_Relateive_Stop_Click()
    Function_Result (APS_emg_stop(Start_Axis_ID))
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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1003, 4, 0))  'Set PRA_ALM_LOGIC
   
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
    
    Function_Result (APS_set_axis_param(1001, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1002, 4, 0))  'Set PRA_ALM_LOGIC
    Function_Result (APS_set_axis_param(1003, 4, 0))  'Set PRA_ALM_LOGIC
   
    Function_Result (APS_relative_linear_move(Dimension, Axis_ID_Array_For_4Axes_Move(0), Position_Array(0), Max_Linear_Speed))
End Sub

Private Sub Btn_Linear_Compare_Click()

    Dim StartPoint As Long
    Dim RepeatTimes As Long
    Dim Interval As Long
    Dim LastIndex As Long
    Dim Index As Long

    StartPoint = 5000
    
    RepeatTimes = 100
    
    
    Interval = 100
   
    
    LastIndex = 4

    For Index = 0 To LastIndex - 1
    
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 0 + Index, 0))           'Compare source is from command counter.
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 8 + Index, 1))          'Compare type is Linear.
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 20 + Index, 5))          'Trigger Width is 100nS
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 4 + Index, 1))            'Enable Linear compare
        Function_Result (APS_set_field_bus_trigger_linear(CardID, BusNo, MOD_No, Index, StartPoint, RepeatTimes, Interval))     'Set Linear Data
        
        
        If (FunctionFail) Then
            Exit For
        End If
        

    Next Index
'
    Btn_Trigger_Count_Click      'Reset Trigger Counter, it's not nerssery.
    Btn_ResetCounter_Click       'Reset Axis Counter Counter, it's not nerssery.
    Btn_Linear_4Axes_RelateiveForward_Click
    
    
End Sub

Private Sub Btn_Manual_Compare_Click()
    Dim LastIndex As Long
    Dim TrgCh As Long
    LastIndex = 4
    For TrgCh = 0 To LastIndex - 1
        Function_Result (APS_set_field_bus_trigger_manual(CardID, BusNo, MOD_No, TrgCh))
        If (FunctionFail) Then
            Exit For
        End If
    Next TrgCh

End Sub

Private Sub Btn_PointTable_MoveALL_Click()

     Dim Index As Long
     Dim LastIndex As Long
     Dim PointData As POINT_DATA2
     Dim AxisNo As Long
     
     Index = 0
     LastIndex = 20

     Function_Result (APS_set_point_table_mode2(Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable), 1))    '0:Single 1:continue

     For Index = 0 To LastIndex
     
     
     
        For AxisNo = 0 To 3
                PointData.i32_pos(AxisNo) = (Index + 1) * 2000 'Position data = Index * 10000;
        Next AxisNo



        If (Index = 0) Then         'If Index be first or last index, initSpeed be 0.
            PointData.i32_initSpeed = 0                      ' Start velocity   ( pulse / s )
            PointData.i32_maxSpeed = 50000                   ' Maximum velocity  ( pulse / s )
            PointData.i32_angle = 0
        Else                                                 'Others index iniSpeed and maxSpeed are the same.
            PointData.i32_initSpeed = PointData.i32_maxSpeed ' Start velocity   ( pulse / s )
            PointData.i32_maxSpeed = 50000                   ' Maximum velocity  ( pulse / s )
        End If
        
        
        
        If (Index = LastIndex) Then
            PointData.i32_opt = &H21           'Option 0xABCD , D:0 absolute, 1:relative
        Else
            PointData.i32_opt = &H1            'Option 0xABCD , D:0 absolute, 1:relative
        End If
        
        
        
        

        Function_Result (APS_set_point_table2(Dimension_For_PointTable, Axis_ID_Array_For_PointTable(0), Index, PointData))
        
        
        If (FunctionFail) Then
           Exit For
        End If
        
        
     Next Index


     Function_Result (APS_point_table_continuous_move2(Dimension_For_PointTable, Axis_ID_Array_For_PointTable(0)))
     
     
     
End Sub

Private Sub Btn_PointTable_SingleIndexMove_Click()

    Function_Result (APS_point_table_single_move2(Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable), CLng(Edit_SetTargetIndex_ForSinglePointMove.Text)))
    
End Sub

Private Sub Btn_PointTable_Stop_Click()
    Function_Result (APS_emg_stop(Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable)))
End Sub

Private Sub Btn_ResetCounter_Click()

    Dim LastIndex As Long
    Dim AxisNo As Long
    
    LastIndex = 4
    
    For AxisNo = Start_Axis_ID To 1003 Step 1
    
    
        Function_Result (APS_set_command(AxisNo, 0))
        Function_Result (APS_set_position(AxisNo, 0))
        
       ' If FunctionFail Then
        
         '   AxisNo = LastIndex + 1
            
          '  FunctionFail = False
            
        ' End If
         
         
    Next AxisNo

End Sub

Private Sub Btn_Set_DOData_Click()
    Function_Result (APS_set_field_bus_d_output(CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), CLng(Edit_SetDOData.Text)))
End Sub

Private Sub Btn_SetPointTable_Click()
     
     Dim Index As Long
     Dim LastIndex As Long
     Dim PointData As POINT_DATA2
     Dim AxisNo As Long
     
     
     Index = 0
     LastIndex = 20
     

     Function_Result (APS_set_point_table_mode2(Start_Axis_ID, 0))   'Set Single Mode (Fast Index Move)


     For Index = 0 To LastIndex
     
     

        For AxisNo = 0 To 3

               PointData.i32_pos(AxisNo) = (Index + 1) * 1000   '設定各軸在各點所跑的距離

        Next AxisNo

        

        If (Index = 0) Then         'If Index be first or last index, initSpeed be 0.
            PointData.i32_initSpeed = 0                      ' Start velocity   ( pulse / s )
            PointData.i32_maxSpeed = 50000                   ' Maximum velocity  ( pulse / s )
            PointData.i32_angle = 0
        Else                                                 'Others index iniSpeed and maxSpeed are the same.
            PointData.i32_initSpeed = PointData.i32_maxSpeed ' Start velocity   ( pulse / s )
            PointData.i32_maxSpeed = 50000                   ' Maximum velocity  ( pulse / s )
        End If
        
        
        
        If (Index = LastIndex) Then
            PointData.i32_opt = &H21   'Set Relative; Linear; CSTP ON; Last point index
        Else
            PointData.i32_opt = &H1    'Set Relative; Linear; CSTP ON; Not Last point index
        End If
        
        
        PointData.u32_dwell = 0                              ' Dwell times       ( unit: ms )
        

        Function_Result (APS_set_point_table2(Dimension_For_PointTable, Axis_ID_Array_For_PointTable(0), Index, PointData))
        
        
        If (FunctionFail) Then
            Exit For
        End If
        
        
     Next Index

End Sub

Private Sub Btn_SingleAbsoluteMove_Backward_Click()
     Dim Position As Long
     Dim Max_Speed As Long
    
     Position = -500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_absolute_move(Start_Axis_ID + 0, Position, Max_Speed)))
End Sub

Private Sub Btn_SingleAbsoluteMove_Forward_Click()
     Dim Position As Long
     Dim Max_Speed As Long
    
     Position = 500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_absolute_move(Start_Axis_ID + 0, Position, Max_Speed)))
End Sub

Private Sub Btn_SingleAbsoluteMove_Stop_Click()

    Function_Result (APS_emg_stop(Start_Axis_ID + 0))
    
End Sub

Private Sub Btn_SingleHomeMove_Backward_Click()


    'Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 1))   'Set PRA_HOME_DIR   0:Positive 1:Negative
    'Others setting like ACC,Dec... are in the initial segmant.
    'Function_Result (APS_home_move(AxisID_SingleAxis_ForHome))
    
    
    
    Function_Result (APS_set_axis_param(Start_Axis_ID, 17, 1))  'Set Home Move Negative Direction
    
    'Others setting like ACC,Dec... are in the initial segmant.
    
    Function_Result (APS_home_move(Start_Axis_ID))
    

End Sub

Private Sub Btn_SingleHomeMove_Forward_Click()


    'Function_Result (APS_set_axis_param(AxisID_SingleAxis_ForHome, PRA_HOME_DIR, 0))  'Set PRA_HOME_DIR   0:Positive 1:Negative
    'Others setting like ACC,Dec... are in the initial segmant.
    'Function_Result (APS_home_move(AxisID_SingleAxis_ForHome))
    
    
    Function_Result (APS_set_axis_param(Start_Axis_ID, 17, 0))   'Set Home Move Positive Direction
    
    'Others setting like ACC,Dec... are in the initial segmant.
    
    Function_Result (APS_home_move(Start_Axis_ID))
    
    
End Sub

Private Sub Btn_SingleHomeMove_Stop_Click()

    Function_Result (APS_emg_stop(Start_Axis_ID))
    
End Sub

Private Sub Btn_SingleRelativeMove_Backward_Click()
     Dim Distance As Long
     Dim Max_Speed As Long
    
     Distance = -500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_relative_move(Start_Axis_ID, Distance, Max_Speed)))
End Sub

Private Sub Btn_SingleRelativeMove_Forward_Click()
     Dim Distance As Long
     Dim Max_Speed As Long
    
     Distance = 500000
     Max_Speed = 666666
    'Others setting like ACC,Dec... are in the initial segmant.

     Function_Result ((APS_relative_move(Start_Axis_ID, Distance, Max_Speed)))
End Sub

Private Sub Btn_SingleRelativeMove_Stop_Click()

    Function_Result (APS_emg_stop(Start_Axis_ID))
    
End Sub



Private Sub Btn_Table_Compare_Click()
     Dim ArraySize As Long
     Dim LastIndex As Long
     Dim Index As Long
     Dim TableIndex As Long
     ArraySize = 100
     LastIndex = 4
     
     'Dim DataArray(0 To ArraySize) As Long
     ReDim DataArray(0 To ArraySize) As Long


    For Index = 0 To LastIndex - 1
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 0 + Index, 0))           'Compare source is from command counter.
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 8 + Index, 0))          'Compare type is Table.
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 20 + Index, 5))           'Trigger Width is 60nS

        For TableIndex = 0 To 99                                                                                  'Create Table Data
            DataArray(TableIndex) = 5000 + (TableIndex * 100)
        Next TableIndex

        Function_Result (APS_set_field_bus_trigger_table(CardID, BusNo, MOD_No, Index, DataArray(0), ArraySize))   'Set Table Data
        Function_Result (APS_set_field_bus_trigger_param(CardID, BusNo, MOD_No, 4 + Index, 1))            'Enable Linear compare
        If (FunctionFail) Then
           Exit For
        End If
    Next Index

    Erase DataArray

    Btn_Trigger_Count_Click      'Reset Trigger Counter, it's not nerssery.
    Btn_ResetCounter_Click       'Reset Axis Counter Counter, it's not nerssery.
    Btn_Linear_4Axes_RelateiveForward_Click
End Sub

Private Sub Btn_Trigger_Count_Click()
    Dim LastIndex As Long
    Dim TrgCh As Long
    LastIndex = 4
    For TrgCh = 0 To LastIndex - 1
        Function_Result (APS_reset_field_bus_trigger_count(CardID, BusNo, MOD_No, TrgCh))
        If (FunctionFail) Then
           Exit For
        End If
    Next TrgCh
End Sub

Private Sub Edit_ShowMaster_PCBVer_Change()

End Sub








Private Sub Form_Load()

   '--------------------------------------------------------------------------------
    CardID = 0            'Card number for setting.
    
    BusNo = 1             'Bus number for setting,  Motion Net BusNo is 1.
    
    Start_Axis_ID = 1000  'First Axis number in Motion Net bus.
    
    MOD_No = 0
   '--------------------------------------------------------------------------------
    
    AxisID_SingleAxis_ForAbsolute = 0
    AxisID_SingleAxis_ForRelative = 1
    AxisID_SingleAxis_ForHome = 2
    AxisID_FirstAxis_For_PointTable = 0
    
    'Dimension_For_PointTable = 4
    Dimension_For_PointTable = 1
    
    
    Axis_ID_Array_For_2Axes_Move(0) = Start_Axis_ID
    Axis_ID_Array_For_2Axes_Move(1) = Start_Axis_ID + 1
    
    
    
    Axis_ID_Array_For_2Axes_ArcMove(0) = Start_Axis_ID
    Axis_ID_Array_For_2Axes_ArcMove(1) = Start_Axis_ID + 1

    Axis_ID_Array_For_3Axes_Move(0) = Start_Axis_ID
    Axis_ID_Array_For_3Axes_Move(1) = Start_Axis_ID + 1
    Axis_ID_Array_For_3Axes_Move(2) = Start_Axis_ID + 2
    
    Axis_ID_Array_For_4Axes_Move(0) = Start_Axis_ID
    Axis_ID_Array_For_4Axes_Move(1) = Start_Axis_ID + 1
    Axis_ID_Array_For_4Axes_Move(2) = Start_Axis_ID + 2
    Axis_ID_Array_For_4Axes_Move(3) = Start_Axis_ID + 3
    
    Axis_ID_Array_For_PointTable(0) = Start_Axis_ID
    Axis_ID_Array_For_PointTable(1) = Start_Axis_ID + 1
    Axis_ID_Array_For_PointTable(2) = Start_Axis_ID + 2
    Axis_ID_Array_For_PointTable(3) = Start_Axis_ID + 3
    
    FunctionFail = False
    
    'Initial+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    Dim DPAC_ID_Bits As Long
    
    Dim Info As Long
    
    If (APS_initial(DPAC_ID_Bits, 0) = 0) Then   'Initial Card, CardID is assigned by system.
        
        
        
        'Get Card information
         Function_Result (APS_get_device_info(CardID, 16, Info))          'Get Driver Version
         Edit_ShowMaster_DriverVer.Text = Info
        
         Edit_ShowMaster_DLLVer.Text = APS_version                        'Get DLL Version

         Function_Result (APS_get_device_info(CardID, 32, Info))          'Get CPLD Version
         Edit_ShowMaster_CPLDVer.Text = Info
        
        'Set Motion Net Parameter
         Function_Result (APS_set_field_bus_param(CardID, BusNo, 1, 3))     'Set Network transfer rate = 20 Mbps
        
        
     Else
     
        MsgBox "Initial Fail, sample close!!", vbOKOnly
        
        APS_close
        
     End If
    '++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
End Sub





Private Sub Timer1_Timer()


    Dim Command As Long
    Dim Position As Long
    Dim Error As Long
    
    
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
    
    

    For Index = 0 To 3
    
    
    'Motion Segment
    
        APS_get_command Start_Axis_ID + Index, Command
        Edit_ShowAxis_Command(Index).Text = Command

        APS_get_position Start_Axis_ID + Index, Position
        Edit_ShowAxis_Feedback(Index).Text = Position * 40
        
        Error = Command - Position * 40
        Edit_ShowAxis_IOSts(Index) = Error
        
        IoSts = APS_motion_io_status(Start_Axis_ID + Index)
        Text1(Index) = IoSts
        

        MotionSts = APS_motion_status(Start_Axis_ID + Index)
        Text2(Index) = MotionSts
        
   '------------------------------------------------------------------------
        

        APS_get_running_point_index2 Axis_ID_Array_For_PointTable(AxisID_FirstAxis_For_PointTable), RunningPoint
        Edit_Show_PointTable_CurrIndex.Text = RunningPoint
   
    'Compare Segment
    
        APS_get_field_bus_trigger_count CardID, BusNo, MOD_No, Index, TrgCnt
        Edit_ShowTriggerCount(Index) = TrgCnt

        APS_get_field_bus_encoder CardID, BusNo, MOD_No, Index, EncCnt
        Edit_ShowTriggerEnc(Index).Text = EncCnt

        APS_get_field_bus_trigger_linear_cmp CardID, BusNo, MOD_No, Index, CmpVal
        Edit_ShowTrigger_LinearCMP_LinearCMP(Index).Text = CmpVal
        
    'General DIO
    
        APS_get_field_bus_d_input CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), DI_Value
        Edit_ShowDIData.Text = Hex(DI_Value)

        APS_get_field_bus_d_output CardID, BusNo, CLng(Edit_SetModuleID_ForGeneralDIO.Text), DOdata
        Edit_GetDOData.Text = Hex(DOdata)
        
        
    Next Index

End Sub
