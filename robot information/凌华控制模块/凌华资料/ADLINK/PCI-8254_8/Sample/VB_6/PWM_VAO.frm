VERSION 5.00
Begin VB.Form PWM_VAO 
   Caption         =   "PWM / VAO"
   ClientHeight    =   3885
   ClientLeft      =   8550
   ClientTop       =   6495
   ClientWidth     =   7395
   Icon            =   "PWM_VAO.frx":0000
   LinkTopic       =   "Form2"
   ScaleHeight     =   3885
   ScaleWidth      =   7395
   Begin VB.Timer Timer2 
      Interval        =   1
      Left            =   6840
      Top             =   120
   End
   Begin VB.CommandButton Command4 
      Caption         =   "VAO OFF"
      Height          =   375
      Left            =   2880
      TabIndex        =   24
      Top             =   3360
      Width           =   1215
   End
   Begin VB.CommandButton Command3 
      Caption         =   "VAO ON"
      Height          =   375
      Left            =   2880
      TabIndex        =   23
      Top             =   2880
      Width           =   1215
   End
   Begin VB.CommandButton Command2 
      Caption         =   "PWM"
      Height          =   375
      Left            =   5880
      TabIndex        =   22
      Top             =   3000
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "Reset Counter"
      Height          =   375
      Left            =   5880
      TabIndex        =   21
      Top             =   2520
      Width           =   1215
   End
   Begin VB.Label Label10 
      Caption         =   "VAO Status"
      Height          =   255
      Left            =   0
      TabIndex        =   20
      Top             =   3000
      Width           =   975
   End
   Begin VB.Label Label9 
      Caption         =   "0"
      Height          =   255
      Left            =   1320
      TabIndex        =   19
      Top             =   3000
      Width           =   1335
   End
   Begin VB.Label Label8 
      Caption         =   "Trig Count"
      Height          =   255
      Left            =   0
      TabIndex        =   18
      Top             =   1920
      Width           =   855
   End
   Begin VB.Label Label7 
      Caption         =   "Width [nS]"
      Height          =   255
      Left            =   0
      TabIndex        =   17
      Top             =   1440
      Width           =   855
   End
   Begin VB.Label Label6 
      Caption         =   "Freq [Hz] "
      Height          =   255
      Left            =   0
      TabIndex        =   16
      Top             =   840
      Width           =   735
   End
   Begin VB.Label Label5 
      Caption         =   "CH3"
      Height          =   375
      Left            =   5520
      TabIndex        =   15
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label4 
      Caption         =   "CH2"
      Height          =   375
      Left            =   4080
      TabIndex        =   14
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label3 
      Caption         =   "CH1"
      Height          =   375
      Left            =   2640
      TabIndex        =   13
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label2 
      Caption         =   "CH0"
      Height          =   375
      Left            =   1080
      TabIndex        =   12
      Top             =   360
      Width           =   495
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   11
      Left            =   5640
      TabIndex        =   11
      Top             =   1920
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   10
      Left            =   4080
      TabIndex        =   10
      Top             =   1920
      Width           =   1455
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   9
      Left            =   2640
      TabIndex        =   9
      Top             =   1920
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   8
      Left            =   1200
      TabIndex        =   8
      Top             =   1920
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   7
      Left            =   5640
      TabIndex        =   7
      Top             =   1440
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   6
      Left            =   4080
      TabIndex        =   6
      Top             =   1440
      Width           =   1335
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   5
      Left            =   2640
      TabIndex        =   5
      Top             =   1440
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   4
      Left            =   1200
      TabIndex        =   4
      Top             =   1440
      Width           =   975
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   3
      Left            =   5640
      TabIndex        =   3
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   2
      Left            =   4080
      TabIndex        =   2
      Top             =   840
      Width           =   1215
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   1
      Left            =   2640
      TabIndex        =   1
      Top             =   840
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "0"
      Height          =   255
      Index           =   0
      Left            =   1200
      TabIndex        =   0
      Top             =   840
      Width           =   975
   End
End
Attribute VB_Name = "PWM_VAO"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
    Public v_card_id As Long
    Public v_channel As Long
    
    Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
    
    
    
Private Sub Command1_Click()
 
        Dim ret As Integer
        Dim CH As Integer
        
         ret = 0
         CH = 0


        For CH = 0 To (v_channel - 1)
            ret = APS_reset_trigger_count(v_card_id, CH)
        Next
End Sub

Private Sub Command2_Click()


        Dim ret As Integer
        Dim Board_ID As Integer
        Dim CH As Integer            'Range is from 0 to 1
        Dim Frequency As Integer     'Unit: Hz. Range is from 3 to 50000000.
        Dim Width As Integer         'Unit: ns. Range is from 20 to 335544300.
        
         ret = 0
         Board_ID = v_card_id
         CH = 0                'Range is from 0 to 1
         Frequency = 1000      'Unit: Hz. Range is from 3 to 50000000.
         Width = 1000          'Unit: ns. Range is from 20 to 335544300.



        'Disable all PWM signals.
        For CH = 0 To 3
            ret = APS_set_pwm_on(Board_ID, CH, 0)
        Next

        'Set PWM parameters
        For CH = 0 To (v_channel - 1)
            ret = APS_set_pwm_frequency(Board_ID, CH, Frequency)
            ret = APS_set_pwm_width(Board_ID, CH, Width)
        Next

        'Wait for stable.
        Sleep 1

        'Note:
        'The PWM output (TG) is used by two function APIs, that are APS_set_pwm_on() and APS_start_vao().
        'Don() 't use them at the same time.
        'Be sure that only one of them is enabled, specified PWM channel could rightly work.

        'start output PWM signal.
        For CH = 0 To (v_channel - 1)
            ret = APS_set_pwm_on(Board_ID, CH, 1)
        Next

        'Wait about 1 sec to show PWM signal (about 1000 periods).
        Sleep 1000

        'Disable all PWM signals.
        For CH = 0 To (v_channel - 1)
            ret = APS_set_pwm_on(Board_ID, CH, 0)
        Next

   
End Sub

Private Sub Command3_Click()


        Dim ret As Long
        Dim Board_ID As Long

        'VAO table number. Range is 0 ~ 7.
        Dim Table_No As Long

        'Minimum linear speed
        Dim MinVelocity As Long

        'Minimum linear speed
        Dim VelInterval As Long

        'Total points. Range is 1 ~ 32
        Dim TotalPoints As Long
        
        
         ret = 0
         Board_ID = v_card_id
         Table_No = 0
         MinVelocity = 1000
         VelInterval = 1000
         TotalPoints = 2
        
        
        
        'Output data array
        ' 500  -> 25% duty
        ' 1000 -> 50% duty
        Dim MappingDataArray(1) As Long
        MappingDataArray(0) = 500
        MappingDataArray(1) = 1000

        Dim Status As Long
        Status = 0

        '****************************************************************
        ' Set output type of Table[0]
        '
        ' 0: output voltage.(reserved)
        ' 1: Fix frequency, change duty ratio.
        ' 2: Fix pulse width, change frequency.
        ' 3: Fix duty ratio, change frequency.
        '****************************************************************
        ret = APS_set_vao_param(Board_ID, 0, 1)

        '****************************************************************
        ' Set input reference of Table[0]
        '
        ' 0: feedback speed.
        ' 1: command speed.
        '****************************************************************
        ret = APS_set_vao_param(Board_ID, 1, 1)

        '****************************************************************
        ' Configure PWM according to output type in Table[0].
        '
        ' If you set output type as voltage mode.(output type = 0)
        '       This value is don't care.
        '
        ' If output type = 1 (Fix frequency, change duty ratio.  )
        '      frequency Range: 3 ~ 50M Hz
        '
        ' If output type = 2 (Fix pulse width, change frequency. )
        '       pulse width Range: 20 ~ 335544300 ns
        '
        ' If output type = 3 (Fix duty ratio, change frequency.  )
        '       duty cycle Range:   1 ~ 2000 (0%~100%)
        '
        '****************************************************************
        ret = APS_set_vao_param(Board_ID, 16, 1000)

        'Specify axisID for VAO Table[0].
        ret = APS_set_vao_param(Board_ID, 32, 1)

        'set Table[0] parameters
        ret = APS_set_vao_table(Board_ID, Table_No, MinVelocity, VelInterval, TotalPoints, MappingDataArray(0))

        'check parameters of VAO Table[0]
        ret = APS_check_vao_param(Board_ID, Table_No, Status)


        If (Status = 0) Then
        
             MsgBox "VAO Setting Ok", 0, ""
            
        Else
        
            MsgBox "VAO Setting Failed", 0, ""
            
        End If

        'Specify which table be executed
        'if Table_No = -1 that disable all tables.
        ret = APS_switch_vao_table(Board_ID, Table_No)

        'Enable outputs
        ret = APS_start_vao(Board_ID, 0, 1)
        ret = APS_start_vao(Board_ID, 1, 1)
        
        
End Sub

Private Sub Command4_Click()


        Dim Board_ID As Integer
        Dim ret As Integer

        'VAO table number. Range is 0 ~ 7.
        Dim Table_No As Integer
        
        
         Board_ID = v_card_id
         ret = 0
         Table_No = -1


        'Disable all tables.
        ret = APS_switch_vao_table(Board_ID, Table_No)

        'Disable outputs
        ret = APS_start_vao(Board_ID, 0, 0)
        ret = APS_start_vao(Board_ID, 1, 0)
        
        
        MsgBox "VAO off", 0, ""

       



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
        
        
        Timer2.Enabled = True

End Sub

Private Sub Form_Unload(Cancel As Integer)
    
     Timer2.Enabled = False
    
End Sub

Private Sub Timer2_Timer()


        Dim CH As Integer
        Dim Frequency As Long
        Dim Width As Long
        Dim TrgCnt As Long
        Dim ret As Long
        Dim Status As Long
        Dim data(3) As Long
        
        CH = 0
        Frequency = 0
        Width = 0
        TrgCnt = 0
        ret = 0
        Status = 0


        'get pwm frequency
        For CH = 0 To (v_channel - 1)
        
            ret = APS_get_pwm_frequency(v_card_id, CH, Frequency)
            data(CH) = Frequency
            
        Next
        
        Label1(0).Caption = CStr(data(0))
        Label1(1).Caption = CStr(data(1))

        If (v_channel = 4) Then
        
             Label1(2).Caption = CStr(data(2))
             Label1(3).Caption = CStr(data(3))
        
        End If
        
        
        
        'get pwm width
        For CH = 0 To (v_channel - 1)
        
            ret = APS_get_pwm_width(v_card_id, CH, Width)
            data(CH) = Width
            
        Next

        Label1(4).Caption = CStr(data(0))
        Label1(5).Caption = CStr(data(1))
        
        If (v_channel = 4) Then
        
           Label1(6).Caption = CStr(data(2))
           Label1(7).Caption = CStr(data(3))
           
        End If


        'get trigger count
        For CH = 0 To (v_channel - 1)
        
            ret = APS_get_trigger_count(v_card_id, CH, TrgCnt)
            data(CH) = TrgCnt
            
        Next

        Label1(8).Caption = CStr(data(0))
        Label1(9).Caption = CStr(data(1))

        If (v_channel = 4) Then
        
            Label1(10).Caption = CStr(data(2))
            Label1(11).Caption = CStr(data(3))
            
        End If
        
        
        ret = APS_get_vao_status(v_card_id, Status)
        Label9.Caption = CStr(Status)


End Sub
