VERSION 5.00
Object = "{F9043C88-F6F2-101A-A3C9-08002B2F49FB}#1.2#0"; "COMDLG32.OCX"
Begin VB.Form Form1 
   Caption         =   "Samples - PCI-8254 / PCI-8258"
   ClientHeight    =   4200
   ClientLeft      =   4800
   ClientTop       =   5100
   ClientWidth     =   6390
   Icon            =   "Samples_PCI825458.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   4200
   ScaleWidth      =   6390
   Begin VB.CommandButton Command22 
      Caption         =   "Point Table"
      Height          =   375
      Left            =   5040
      TabIndex        =   27
      Top             =   1920
      Width           =   1095
   End
   Begin VB.Timer Timer1 
      Interval        =   500
      Left            =   7080
      Top             =   120
   End
   Begin MSComDlg.CommonDialog CommonDialog1 
      Left            =   6480
      Top             =   120
      _ExtentX        =   847
      _ExtentY        =   847
      _Version        =   393216
   End
   Begin VB.Frame Frame4 
      Caption         =   "Aux Function"
      Height          =   3855
      Left            =   4920
      TabIndex        =   23
      Top             =   120
      Width           =   1335
      Begin VB.CommandButton Command25 
         Caption         =   "CMP Trigger"
         Height          =   375
         Left            =   120
         TabIndex        =   30
         Top             =   3240
         Width           =   1095
      End
      Begin VB.CommandButton Command24 
         Caption         =   "PWM / VAO"
         Height          =   375
         Left            =   120
         TabIndex        =   29
         Top             =   2760
         Width           =   1095
      End
      Begin VB.CommandButton Command23 
         Caption         =   "Gear / Gantry "
         Height          =   375
         Left            =   120
         TabIndex        =   28
         Top             =   2280
         Width           =   1095
      End
      Begin VB.CommandButton Command21 
         Caption         =   "Analog I/O"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   26
         Top             =   1320
         Width           =   1095
      End
      Begin VB.CommandButton Command20 
         Caption         =   "Digital I/O"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   25
         Top             =   840
         Width           =   1095
      End
      Begin VB.CommandButton Command19 
         Caption         =   "Interrupt"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   24
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "Interpolation"
      Height          =   3855
      Left            =   3360
      TabIndex        =   17
      Top             =   120
      Width           =   1335
      Begin VB.CommandButton Command18 
         Caption         =   "2D Contour"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   22
         Top             =   3240
         Width           =   1095
      End
      Begin VB.CommandButton Command17 
         Caption         =   "3D Spiral"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   21
         Top             =   1800
         Width           =   1095
      End
      Begin VB.CommandButton Command16 
         Caption         =   "3D Arc"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   20
         Top             =   1320
         Width           =   1095
      End
      Begin VB.CommandButton Command15 
         Caption         =   "2D Arc"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   19
         Top             =   840
         Width           =   1095
      End
      Begin VB.CommandButton Command14 
         Caption         =   "2D Line"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   18
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "Basic Move"
      Height          =   3855
      Left            =   1800
      TabIndex        =   9
      Top             =   120
      Width           =   1335
      Begin VB.CommandButton Command13 
         Caption         =   "EMG Stop"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   16
         Top             =   3240
         Width           =   1095
      End
      Begin VB.CommandButton Command12 
         Caption         =   "Stop Move"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   15
         Top             =   2760
         Width           =   1095
      End
      Begin VB.CommandButton Command11 
         Caption         =   "P2P"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   14
         Top             =   2280
         Width           =   1095
      End
      Begin VB.CommandButton Command10 
         Caption         =   "Jog Off"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   13
         Top             =   1800
         Width           =   1095
      End
      Begin VB.CommandButton Command9 
         Caption         =   "Jog ON"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   12
         Top             =   1320
         Width           =   1095
      End
      Begin VB.CommandButton Command8 
         Caption         =   "Velocity Move"
         Height          =   375
         Index           =   0
         Left            =   50
         TabIndex        =   11
         Top             =   840
         Width           =   1200
      End
      Begin VB.CommandButton Command7 
         Caption         =   "Homing"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   10
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.Frame Frame1 
      Caption         =   "Start Here"
      Height          =   3855
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   1335
      Begin VB.ComboBox Combo1 
         Height          =   315
         Left            =   240
         TabIndex        =   8
         Top             =   3000
         Width           =   855
      End
      Begin VB.CommandButton Command6 
         Caption         =   "Motion Done?"
         Height          =   375
         Index           =   0
         Left            =   60
         TabIndex        =   7
         Top             =   3360
         Width           =   1215
      End
      Begin VB.CommandButton Command5 
         Caption         =   "Load Param"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   5
         Top             =   2280
         Width           =   1095
      End
      Begin VB.CommandButton Command4 
         Caption         =   "Axis Monitor"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   4
         Top             =   1800
         Width           =   1095
      End
      Begin VB.CommandButton Command3 
         Caption         =   "Get Version"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   3
         Top             =   1320
         Width           =   1095
      End
      Begin VB.CommandButton Command2 
         Caption         =   "Close"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   2
         Top             =   840
         Width           =   1095
      End
      Begin VB.CommandButton Command1 
         Caption         =   "Initial"
         Height          =   375
         Index           =   0
         Left            =   120
         TabIndex        =   1
         Top             =   360
         Width           =   1095
      End
      Begin VB.Label Label1 
         Caption         =   "Target 1st Axis"
         Height          =   255
         Left            =   120
         TabIndex        =   6
         Top             =   2760
         Width           =   1095
      End
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit
    Const NOT_INITIAL = 0
    Const INITIALED = 1
    Public v_is_card_initialed As Long
    Public v_card_id As Long
    Public v_test_axis_id As Long
    Public v_first_axis_id As Long

    'Dim Thread_Wait_Int As New System.Threading.Thread(AddressOf Wait_Int)
    Public g_is_thread_created As Long
    Public g_board_id As Long
    Public g_axis_num As Long



Private Sub Combo1_Click()
    
    CHECK_CARD_INITIAL
    v_test_axis_id = v_first_axis_id + Combo1.ListIndex

End Sub

Private Sub Command10_Click(Index As Integer)
       
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then
        
            APS_jog_start v_test_axis_id, 1
            APS_jog_start v_test_axis_id, 0
        
        End If
        

End Sub

Private Sub Command11_Click(Index As Integer)
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then
            p2p_example v_test_axis_id
        End If
        

End Sub

Private Sub Command12_Click(Index As Integer)
        
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then
            
            deceleration_stop_example v_test_axis_id
        
        End If
End Sub

Private Sub Command13_Click(Index As Integer)
    
    CHECK_CARD_INITIAL
    
    If v_is_card_initialed <> NOT_INITIAL Then
        emg_stop_example v_test_axis_id
    End If

End Sub

Private Sub Command14_Click(Index As Integer)
        
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then

            Dim Axis_ID_Array(1) As Long
            Axis_ID_Array(0) = v_test_axis_id
            Axis_ID_Array(1) = v_test_axis_id + 1
    
            interpolation_2D_line_example Axis_ID_Array()
        
        End If
        

End Sub

Private Sub Command15_Click(Index As Integer)
        
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then
         
            Dim Axis_ID_Array(1) As Long
            Axis_ID_Array(0) = v_test_axis_id
            Axis_ID_Array(1) = v_test_axis_id + 1
    
            interpolation_2D_arc_example Axis_ID_Array()
        
        End If
        

End Sub

Private Sub Command16_Click(Index As Integer)
        
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then

            Dim Axis_ID_Array(3) As Long
            Axis_ID_Array(0) = v_test_axis_id
            Axis_ID_Array(1) = v_test_axis_id + 1
            Axis_ID_Array(2) = v_test_axis_id + 2
    
            interpolation_3D_arc_example Axis_ID_Array()
            
        End If

End Sub

Private Sub Command17_Click(Index As Integer)
        
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then

            Dim Axis_ID_Array(3) As Long
            Axis_ID_Array(0) = v_test_axis_id
            Axis_ID_Array(1) = v_test_axis_id + 1
            Axis_ID_Array(2) = v_test_axis_id + 2
    
            interpolation_3D_helical_example Axis_ID_Array()
        
        End If
        

End Sub

Private Sub Command18_Click(Index As Integer)
        
        
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then

                Dim Axis_ID_Array(2) As Long
                Axis_ID_Array(0) = v_test_axis_id
                Axis_ID_Array(1) = v_test_axis_id + 1
        
                contour_2D_example Axis_ID_Array()
        
        End If

End Sub

Private Sub Command19_Click(Index As Integer)

        Dim tmp As Long
        
        CHECK_CARD_INITIAL
        
         If v_is_card_initialed <> NOT_INITIAL Then

                If g_is_thread_created = 0 Then
            
                    'Start Timer to creat thread to wait interrupt
                    Timer1.Enabled = True
                    
                    g_is_thread_created = 1
                            
                    APS_get_axis_info v_test_axis_id, g_board_id, g_axis_num, tmp, tmp
                    
                    MsgBox "Wait motion done thread is created. You can start a p2p move.", vbOKOnly
                    
                Else
                    MsgBox "Thread already created", vbOKOnly
                End If
                
         End If

End Sub

Private Sub Command2_Click(Index As Integer)

    'Disable Timer
    Timer1.Enabled = False

    APS_close
    v_is_card_initialed = NOT_INITIAL
    
    MsgBox "close ok", 0, "Card close"
    
    Form1.Caption = "Basic Sample"

End Sub

Private Sub Command20_Click(Index As Integer)
        
        
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then
            DIO_sample v_card_id
        End If
        

End Sub

Private Sub Command21_Click(Index As Integer)

    Dim card_name As Long
    
    CHECK_CARD_INITIAL
    
     If v_is_card_initialed <> NOT_INITIAL Then
        
            APS_get_card_name 0, card_name
                        
            If card_name = DEVICE_NAME_PCI_825458 Then
                AIO_sample v_card_id
            End If
            
     End If
    
End Sub

Private Sub Command22_Click()

 CHECK_CARD_INITIAL
 
  If v_is_card_initialed <> NOT_INITIAL Then
 
       Dim Axis_ID_Array(1) As Long
       
       
       If (v_test_axis_id = 7) Then
       
            Axis_ID_Array(0) = 7
            Axis_ID_Array(1) = 0
            
       Else
       
            Axis_ID_Array(0) = v_test_axis_id
            Axis_ID_Array(1) = v_test_axis_id + 1

       End If
       
       point_table_2D_example v_card_id, Axis_ID_Array()
        
  End If

End Sub

Private Sub Command23_Click()

  CHECK_CARD_INITIAL
 
 If v_is_card_initialed <> NOT_INITIAL Then
 
       Dim Axis_ID_Array(1) As Long
       
       
       If (v_test_axis_id = 7) Then
       
            Axis_ID_Array(0) = 7
            Axis_ID_Array(1) = 0
            
       Else
       
            Axis_ID_Array(0) = v_test_axis_id
            Axis_ID_Array(1) = v_test_axis_id + 1

       End If
       
       Gear_example Axis_ID_Array()
        
  End If
  
End Sub

Private Sub Command24_Click()


    CHECK_CARD_INITIAL
    
    If v_is_card_initialed <> NOT_INITIAL Then
    
        Dim p As New PWM_VAO
        p.v_card_id = v_card_id
        p.Show 0
       
    End If


End Sub

Private Sub Command25_Click()


CHECK_CARD_INITIAL
    
    If v_is_card_initialed <> NOT_INITIAL Then
    
        Dim p As New CmpTrig
        p.v_card_id = v_card_id
        p.Show 0
       
    End If

End Sub

Private Sub Command3_Click(Index As Integer)

    CHECK_CARD_INITIAL
    
    If v_is_card_initialed <> NOT_INITIAL Then
    
    Dim version As New Dialog_version
        version.v_card_id = v_card_id
        version.Show 1
    End If
    
End Sub
Sub CHECK_CARD_INITIAL()

    If v_is_card_initialed = NOT_INITIAL Then
        MsgBox "Card has not been initialed.", 0, "Error"
    End If
    
End Sub

Private Sub Command4_Click(Index As Integer)

    CHECK_CARD_INITIAL
    
    If v_is_card_initialed <> NOT_INITIAL Then
    
       Dim version As New Dialog_axis_monitor
       version.Show 0
       
    End If
    
End Sub

Private Sub Command5_Click(Index As Integer)

    CHECK_CARD_INITIAL
    
    
     If v_is_card_initialed <> NOT_INITIAL Then
     
      'On Error GoTo cmdOpen_Click_Exit
        With CommonDialog1
            .InitDir = App.Path
            .Filter = "Programs (*.xml)|*.xml"
            .DefaultExt = ".xml"
            .FileName = ""
            .FilterIndex = 1
            .DialogTitle = "Select a xml File"
            .ShowOpen
        End With
        
        If (CommonDialog1.FileName <> "") Then
    
            MsgBox CommonDialog1.FileName, vbOKOnly
            load_parameters_from_file_sample CommonDialog1.FileName
        End If
        
cmdOpen_Click_Error:
cmdOpen_Click_Exit:
    
      
       
     End If
    

End Sub

Private Sub Command6_Click(Index As Integer)
        CHECK_CARD_INITIAL
        
         If v_is_card_initialed <> NOT_INITIAL Then
        
                Dim ret As Long
                Dim Stop_Code As Long
                Dim str As String
        
                ret = check_motion_done_example(v_test_axis_id, Stop_Code)
                
                Print Stop_Code
                ret = -1
                '// Display motion done status
                Select Case ret
        
                    Case 0
                        MsgBox "In motion", vbOKOnly
                    Case 1
                        MsgBox "Motion done", vbOKOnly
                    Case -1
                        str = "Error stop! stop code : " + CStr(Stop_Code) + " (" + CStr(stop_code_to_string(Stop_Code) + ")")
                        MsgBox str, vbOKOnly
                End Select
                
            End If
End Sub

Private Sub Command7_Click(Index As Integer)
        CHECK_CARD_INITIAL
        
         If v_is_card_initialed <> NOT_INITIAL Then
         
                home_move_example v_test_axis_id
        End If

End Sub

Private Sub Command8_Click(Index As Integer)
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then
    
            velocity_move_example v_test_axis_id
        End If
End Sub

Private Sub Command9_Click(Index As Integer)
        CHECK_CARD_INITIAL
        
        If v_is_card_initialed <> NOT_INITIAL Then
             jog_move_continuous_mode_example v_test_axis_id
        End If
             

        '/**** Following are another two samples *********/
        'jog_move_step_mode_example v_test_axis_id
        'jog_move_via_DI_example v_test_axis_id

End Sub

Private Sub Form_Load()

    'Disable Timer first
    Timer1.Enabled = False

    v_is_card_initialed = 0
    g_is_thread_created = 0
    
    Form1.Caption = "Basic Sample"
End Sub
Private Sub Form_Unload(Cancel As Integer)
    
    APS_close
    v_is_card_initialed = NOT_INITIAL
    
End Sub


Private Sub Command1_Click(Index As Integer)
    Dim BoardID_InBits As Long
    BoardID_InBits = 0
    'I32 mode           = INIT_AUTO_CARD_ID | INIT_PARAM_IGNORE;
    Dim Mode As Long
    Mode = 0
    Dim ret As Long
    ret = 0
    Dim Board_ID As Long
    Board_ID = -1
    Dim i As Integer
    Dim card_name As Long
    
    
    ' UI protection
    If v_is_card_initialed = INITIALED Then
        MsgBox "initial ok", 0, "Card initial"
        Exit Sub
    
    End If
    
    
    ' use virtual card for test
    'APS_register_virtual_board 0, 1
    ret = APS_initial(BoardID_InBits, Mode)
    
    
    If ret = ERR_NoError Then

        For i = 0 To 15
            If (BoardID_InBits And (2 ^ i)) Then
                APS_get_card_name i, card_name
                
                If card_name = DEVICE_NAME_PCI_825458 Or card_name = DEVICE_NAME_AMP_20408C Then
                    Board_ID = i
                    Exit For
                End If
            End If

        Next

        If Board_ID = -1 Then
            MsgBox "BoardId search error!", 0, "Error"
            Exit Sub
        End If

        v_is_card_initialed = INITIALED
        v_card_id = Board_ID

        Dim total_axes As Long
        APS_get_first_axisId Board_ID, v_first_axis_id, total_axes
        v_test_axis_id = v_first_axis_id
        
        
        If card_name = DEVICE_NAME_PCI_825458 And total_axes = 4 Then
            Form1.Caption = "PCI-8254 Basic Sample"
        ElseIf card_name = DEVICE_NAME_PCI_825458 And total_axes = 8 Then
            Form1.Caption = "PCI-8258 Basic Sample"
        ElseIf card_name = DEVICE_NAME_AMP_20408C And total_axes = 4 Then
           Form1.Caption = "AMP-204C Basic Sample"
        ElseIf card_name = DEVICE_NAME_AMP_20408C And total_axes = 8 Then
           Form1.Caption = "AMP-208C Basic Sample"
        End If
        
        '   // Setup combol box
        Combo1.Clear
        For i = 0 To total_axes - 1
            Combo1.AddItem (i)
        Next
        
        Combo1.ListIndex = 0

        MsgBox "initial ok", 0, "Card initial"

    Else
        Dim to_show As String
        to_show = "Error Code is " + CStr(ret)
        MsgBox to_show, 0, "Error"
    End If

End Sub

Private Sub Timer1_Timer()

        Dim ret As Long
        
        ret = interrupt_example(g_board_id, g_axis_num)

        If (ret = 0) Then
            
            MsgBox "interrupt occur", vbOKOnly
            
            'Disable Timer
            Timer1.Enabled = False
            
        End If
        
        g_is_thread_created = 0
        
End Sub
