VERSION 5.00
Begin VB.Form Dialog_version 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Version Info"
   ClientHeight    =   3195
   ClientLeft      =   7890
   ClientTop       =   6195
   ClientWidth     =   2985
   Icon            =   "Dialog_Version.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3195
   ScaleWidth      =   2985
   ShowInTaskbar   =   0   'False
   Begin VB.CommandButton OKButton 
      Caption         =   "OK"
      Height          =   375
      Left            =   840
      TabIndex        =   0
      Top             =   2760
      Width           =   1215
   End
   Begin VB.Frame Frame1 
      Height          =   2895
      Left            =   240
      TabIndex        =   1
      Top             =   120
      Width           =   2415
      Begin VB.Label Label10 
         Alignment       =   1  'Right Justify
         Caption         =   "PCB : "
         Height          =   255
         Left            =   120
         TabIndex        =   11
         Top             =   1920
         Width           =   855
      End
      Begin VB.Label Label9 
         Alignment       =   1  'Right Justify
         Caption         =   "Firmware : "
         Height          =   255
         Left            =   120
         TabIndex        =   10
         Top             =   1560
         Width           =   855
      End
      Begin VB.Label Label8 
         Alignment       =   1  'Right Justify
         Caption         =   "Kernel : "
         Height          =   255
         Left            =   360
         TabIndex        =   9
         Top             =   1200
         Width           =   615
      End
      Begin VB.Label Label7 
         Alignment       =   1  'Right Justify
         Caption         =   "Driver : "
         Height          =   255
         Left            =   360
         TabIndex        =   8
         Top             =   840
         Width           =   615
      End
      Begin VB.Label Label6 
         Alignment       =   1  'Right Justify
         Caption         =   "DLL : "
         Height          =   255
         Left            =   360
         TabIndex        =   7
         Top             =   480
         Width           =   615
      End
      Begin VB.Label Label5 
         Caption         =   "0"
         Height          =   255
         Left            =   1200
         TabIndex        =   6
         Top             =   1920
         Width           =   1095
      End
      Begin VB.Label Label4 
         Caption         =   "0"
         Height          =   255
         Left            =   1200
         TabIndex        =   5
         Top             =   1560
         Width           =   1095
      End
      Begin VB.Label Label3 
         Caption         =   "0"
         Height          =   255
         Left            =   1200
         TabIndex        =   4
         Top             =   1200
         Width           =   975
      End
      Begin VB.Label Label2 
         Caption         =   "0"
         Height          =   255
         Left            =   1200
         TabIndex        =   3
         Top             =   840
         Width           =   1095
      End
      Begin VB.Label Label1 
         Caption         =   "0"
         Height          =   255
         Left            =   1200
         TabIndex        =   2
         Top             =   480
         Width           =   975
      End
   End
End
Attribute VB_Name = "Dialog_version"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
    Public v_card_id As Long

Private Sub Form_Load()
        
        Dim info(4) As Long

        get_version_info info, v_card_id
        Label1.Caption = CStr(info(0))
        Label2.Caption = CStr(info(1))
        Label3.Caption = CStr(info(2))
        Label4.Caption = CStr(Hex(info(3)))
        Label5.Caption = CStr(info(4))

End Sub

Private Sub OKButton_Click()
    Unload Me
End Sub
