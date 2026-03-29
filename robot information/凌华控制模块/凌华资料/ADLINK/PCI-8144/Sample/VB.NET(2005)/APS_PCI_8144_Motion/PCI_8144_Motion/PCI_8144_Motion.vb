Option Strict Off
Option Explicit On 
Imports VB = Microsoft.VisualBasic
Imports System.Threading.Thread

Public Class Form1
    Inherits System.Windows.Forms.Form

    Dim AxisNo, Motion_InBit As Short

    Dim ExistCards As Short = 0

    Dim Status As Integer

    Dim CARDS_PCI_8144_Status(16) As Boolean

    Dim Thread_Int_Motion As New System.Threading.Thread(AddressOf Int_Motion)

    Dim Rtn_Msg_Motion As Short

    Dim Motion_Counter As Integer = 0

    Dim Int_Flag As Short = 0

    Dim Int_No As Integer = 0

#Region " Windows Form 設計工具產生的程式碼 "

    Public Sub New()
        MyBase.New()

        '此為 Windows Form 設計工具所需的呼叫。
        InitializeComponent()

        '在 InitializeComponent() 呼叫之後加入所有的初始設定

    End Sub

    'Form 覆寫 Dispose 以清除元件清單。
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

    '為 Windows Form 設計工具的必要項
    Private components As System.ComponentModel.IContainer

    '注意: 以下為 Windows Form 設計工具所需的程序
    '您可以使用 Windows Form 設計工具進行修改。
    '請勿使用程式碼編輯器來修改這些程序。
    Friend WithEvents PEL_light As System.Windows.Forms.PictureBox
    Friend WithEvents NEL_light As System.Windows.Forms.PictureBox
    Friend WithEvents STA_light As System.Windows.Forms.PictureBox
    Friend WithEvents NSD_light As System.Windows.Forms.PictureBox
    Friend WithEvents ORG_light As System.Windows.Forms.PictureBox
    Friend WithEvents STP_light As System.Windows.Forms.PictureBox
    Friend WithEvents PSD_light As System.Windows.Forms.PictureBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents tbox_tv_strvel As System.Windows.Forms.TextBox
    Friend WithEvents tbox_tv_maxvel As System.Windows.Forms.TextBox
    Friend WithEvents tbox_tv_Tacc As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents btn_tv_start As System.Windows.Forms.Button
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents tbox_tr_maxvel As System.Windows.Forms.TextBox
    Friend WithEvents tbox_tr_strvel As System.Windows.Forms.TextBox
    Friend WithEvents tbox_tr_distance As System.Windows.Forms.TextBox
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents Label13 As System.Windows.Forms.Label
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents btn_tr_start As System.Windows.Forms.Button
    Friend WithEvents tbox_AxisNumber As System.Windows.Forms.TextBox
    Friend WithEvents Label15 As System.Windows.Forms.Label
    Friend WithEvents btn_stop As System.Windows.Forms.Button
    Friend WithEvents tbox_tr_tacc As System.Windows.Forms.TextBox
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents btn_exit As System.Windows.Forms.Button
    Friend WithEvents GroupBox5 As System.Windows.Forms.GroupBox
    Friend WithEvents tbox_AxisNo_start As System.Windows.Forms.TextBox
    Friend WithEvents tbox_AxisNo_end As System.Windows.Forms.TextBox
    Friend WithEvents Label17 As System.Windows.Forms.Label
    Friend WithEvents Label18 As System.Windows.Forms.Label
    Friend WithEvents Motion_light1 As System.Windows.Forms.PictureBox
    Friend WithEvents Motion_light4 As System.Windows.Forms.PictureBox
    Friend WithEvents Motion_light3 As System.Windows.Forms.PictureBox
    Friend WithEvents Motion_light0 As System.Windows.Forms.PictureBox
    Friend WithEvents Motion_light2 As System.Windows.Forms.PictureBox
    Friend WithEvents Label19 As System.Windows.Forms.Label
    Friend WithEvents Label20 As System.Windows.Forms.Label
    Friend WithEvents Label21 As System.Windows.Forms.Label
    Friend WithEvents Label22 As System.Windows.Forms.Label
    Friend WithEvents Label23 As System.Windows.Forms.Label
    Friend WithEvents GroupBox6 As System.Windows.Forms.GroupBox
    Friend WithEvents Label25 As System.Windows.Forms.Label
    Friend WithEvents Tbox_MotionInt As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox7 As System.Windows.Forms.GroupBox
    Friend WithEvents Btn_WaitInt As System.Windows.Forms.Button
    Friend WithEvents Btn_SetFactor As System.Windows.Forms.Button
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents GroupBox8 As System.Windows.Forms.GroupBox
    Friend WithEvents Tbox_RemainPs As System.Windows.Forms.TextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.PEL_light = New System.Windows.Forms.PictureBox
        Me.NEL_light = New System.Windows.Forms.PictureBox
        Me.STA_light = New System.Windows.Forms.PictureBox
        Me.NSD_light = New System.Windows.Forms.PictureBox
        Me.ORG_light = New System.Windows.Forms.PictureBox
        Me.STP_light = New System.Windows.Forms.PictureBox
        Me.PSD_light = New System.Windows.Forms.PictureBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.tbox_tv_strvel = New System.Windows.Forms.TextBox
        Me.tbox_tv_maxvel = New System.Windows.Forms.TextBox
        Me.tbox_tv_Tacc = New System.Windows.Forms.TextBox
        Me.Label8 = New System.Windows.Forms.Label
        Me.Label9 = New System.Windows.Forms.Label
        Me.Label10 = New System.Windows.Forms.Label
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.btn_tv_start = New System.Windows.Forms.Button
        Me.GroupBox3 = New System.Windows.Forms.GroupBox
        Me.GroupBox7 = New System.Windows.Forms.GroupBox
        Me.Button1 = New System.Windows.Forms.Button
        Me.Btn_SetFactor = New System.Windows.Forms.Button
        Me.Btn_WaitInt = New System.Windows.Forms.Button
        Me.btn_stop = New System.Windows.Forms.Button
        Me.Label15 = New System.Windows.Forms.Label
        Me.tbox_AxisNumber = New System.Windows.Forms.TextBox
        Me.GroupBox4 = New System.Windows.Forms.GroupBox
        Me.btn_tr_start = New System.Windows.Forms.Button
        Me.Label14 = New System.Windows.Forms.Label
        Me.Label13 = New System.Windows.Forms.Label
        Me.Label12 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.tbox_tr_distance = New System.Windows.Forms.TextBox
        Me.tbox_tr_strvel = New System.Windows.Forms.TextBox
        Me.tbox_tr_tacc = New System.Windows.Forms.TextBox
        Me.tbox_tr_maxvel = New System.Windows.Forms.TextBox
        Me.tbox_AxisNo_start = New System.Windows.Forms.TextBox
        Me.tbox_AxisNo_end = New System.Windows.Forms.TextBox
        Me.Label17 = New System.Windows.Forms.Label
        Me.Label18 = New System.Windows.Forms.Label
        Me.btn_exit = New System.Windows.Forms.Button
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.GroupBox5 = New System.Windows.Forms.GroupBox
        Me.Label23 = New System.Windows.Forms.Label
        Me.Label22 = New System.Windows.Forms.Label
        Me.Label21 = New System.Windows.Forms.Label
        Me.Label20 = New System.Windows.Forms.Label
        Me.Label19 = New System.Windows.Forms.Label
        Me.Motion_light1 = New System.Windows.Forms.PictureBox
        Me.Motion_light4 = New System.Windows.Forms.PictureBox
        Me.Motion_light3 = New System.Windows.Forms.PictureBox
        Me.Motion_light0 = New System.Windows.Forms.PictureBox
        Me.Motion_light2 = New System.Windows.Forms.PictureBox
        Me.GroupBox6 = New System.Windows.Forms.GroupBox
        Me.Tbox_MotionInt = New System.Windows.Forms.TextBox
        Me.Label25 = New System.Windows.Forms.Label
        Me.GroupBox8 = New System.Windows.Forms.GroupBox
        Me.Tbox_RemainPs = New System.Windows.Forms.TextBox
        CType(Me.PEL_light, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.NEL_light, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.STA_light, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.NSD_light, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.ORG_light, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.STP_light, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PSD_light, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox7.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox5.SuspendLayout()
        CType(Me.Motion_light1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Motion_light4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Motion_light3, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Motion_light0, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Motion_light2, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox6.SuspendLayout()
        Me.GroupBox8.SuspendLayout()
        Me.SuspendLayout()
        '
        'PEL_light
        '
        Me.PEL_light.BackColor = System.Drawing.Color.DimGray
        Me.PEL_light.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.PEL_light.Location = New System.Drawing.Point(64, 72)
        Me.PEL_light.Name = "PEL_light"
        Me.PEL_light.Size = New System.Drawing.Size(24, 24)
        Me.PEL_light.TabIndex = 0
        Me.PEL_light.TabStop = False
        '
        'NEL_light
        '
        Me.NEL_light.BackColor = System.Drawing.Color.DimGray
        Me.NEL_light.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.NEL_light.Location = New System.Drawing.Point(64, 32)
        Me.NEL_light.Name = "NEL_light"
        Me.NEL_light.Size = New System.Drawing.Size(24, 24)
        Me.NEL_light.TabIndex = 1
        Me.NEL_light.TabStop = False
        '
        'STA_light
        '
        Me.STA_light.BackColor = System.Drawing.Color.DimGray
        Me.STA_light.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.STA_light.Location = New System.Drawing.Point(144, 32)
        Me.STA_light.Name = "STA_light"
        Me.STA_light.Size = New System.Drawing.Size(24, 24)
        Me.STA_light.TabIndex = 2
        Me.STA_light.TabStop = False
        '
        'NSD_light
        '
        Me.NSD_light.BackColor = System.Drawing.Color.DimGray
        Me.NSD_light.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.NSD_light.Location = New System.Drawing.Point(144, 112)
        Me.NSD_light.Name = "NSD_light"
        Me.NSD_light.Size = New System.Drawing.Size(24, 24)
        Me.NSD_light.TabIndex = 3
        Me.NSD_light.TabStop = False
        '
        'ORG_light
        '
        Me.ORG_light.BackColor = System.Drawing.Color.DimGray
        Me.ORG_light.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.ORG_light.Location = New System.Drawing.Point(64, 112)
        Me.ORG_light.Name = "ORG_light"
        Me.ORG_light.Size = New System.Drawing.Size(24, 24)
        Me.ORG_light.TabIndex = 4
        Me.ORG_light.TabStop = False
        '
        'STP_light
        '
        Me.STP_light.BackColor = System.Drawing.Color.DimGray
        Me.STP_light.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.STP_light.Location = New System.Drawing.Point(64, 152)
        Me.STP_light.Name = "STP_light"
        Me.STP_light.Size = New System.Drawing.Size(24, 24)
        Me.STP_light.TabIndex = 5
        Me.STP_light.TabStop = False
        '
        'PSD_light
        '
        Me.PSD_light.BackColor = System.Drawing.Color.DimGray
        Me.PSD_light.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.PSD_light.Location = New System.Drawing.Point(144, 72)
        Me.PSD_light.Name = "PSD_light"
        Me.PSD_light.Size = New System.Drawing.Size(24, 24)
        Me.PSD_light.TabIndex = 6
        Me.PSD_light.TabStop = False
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label1.Location = New System.Drawing.Point(16, 32)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(40, 24)
        Me.Label1.TabIndex = 7
        Me.Label1.Text = "- EL"
        Me.Label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.Location = New System.Drawing.Point(104, 112)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(40, 24)
        Me.Label2.TabIndex = 8
        Me.Label2.Text = "- SD"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.Location = New System.Drawing.Point(94, 72)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(50, 24)
        Me.Label3.TabIndex = 9
        Me.Label3.Text = "+ SD"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label4
        '
        Me.Label4.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.Location = New System.Drawing.Point(104, 32)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(40, 24)
        Me.Label4.TabIndex = 10
        Me.Label4.Text = "STA"
        Me.Label4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label5
        '
        Me.Label5.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label5.Location = New System.Drawing.Point(16, 152)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(40, 24)
        Me.Label5.TabIndex = 11
        Me.Label5.Text = "STP"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label6
        '
        Me.Label6.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label6.Location = New System.Drawing.Point(8, 112)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(48, 24)
        Me.Label6.TabIndex = 12
        Me.Label6.Text = "ORG"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label7
        '
        Me.Label7.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label7.Location = New System.Drawing.Point(16, 72)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(40, 24)
        Me.Label7.TabIndex = 13
        Me.Label7.Text = "+ EL"
        Me.Label7.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.PEL_light)
        Me.GroupBox1.Controls.Add(Me.Label3)
        Me.GroupBox1.Controls.Add(Me.STP_light)
        Me.GroupBox1.Controls.Add(Me.STA_light)
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.NEL_light)
        Me.GroupBox1.Controls.Add(Me.ORG_light)
        Me.GroupBox1.Controls.Add(Me.PSD_light)
        Me.GroupBox1.Controls.Add(Me.NSD_light)
        Me.GroupBox1.Controls.Add(Me.Label6)
        Me.GroupBox1.Controls.Add(Me.Label7)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Controls.Add(Me.Label5)
        Me.GroupBox1.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(16, 8)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(184, 184)
        Me.GroupBox1.TabIndex = 14
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Motion I/O Status"
        '
        'tbox_tv_strvel
        '
        Me.tbox_tv_strvel.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_tv_strvel.Location = New System.Drawing.Point(120, 32)
        Me.tbox_tv_strvel.Name = "tbox_tv_strvel"
        Me.tbox_tv_strvel.Size = New System.Drawing.Size(96, 21)
        Me.tbox_tv_strvel.TabIndex = 15
        Me.tbox_tv_strvel.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'tbox_tv_maxvel
        '
        Me.tbox_tv_maxvel.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_tv_maxvel.Location = New System.Drawing.Point(120, 64)
        Me.tbox_tv_maxvel.Name = "tbox_tv_maxvel"
        Me.tbox_tv_maxvel.Size = New System.Drawing.Size(96, 21)
        Me.tbox_tv_maxvel.TabIndex = 16
        Me.tbox_tv_maxvel.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'tbox_tv_Tacc
        '
        Me.tbox_tv_Tacc.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_tv_Tacc.Location = New System.Drawing.Point(120, 96)
        Me.tbox_tv_Tacc.Name = "tbox_tv_Tacc"
        Me.tbox_tv_Tacc.Size = New System.Drawing.Size(96, 21)
        Me.tbox_tv_Tacc.TabIndex = 17
        Me.tbox_tv_Tacc.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label8
        '
        Me.Label8.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label8.Location = New System.Drawing.Point(8, 32)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(104, 24)
        Me.Label8.TabIndex = 18
        Me.Label8.Text = "Start velocity"
        Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label9
        '
        Me.Label9.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label9.Location = New System.Drawing.Point(16, 64)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(96, 24)
        Me.Label9.TabIndex = 19
        Me.Label9.Text = "Max velocity"
        Me.Label9.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label10
        '
        Me.Label10.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label10.Location = New System.Drawing.Point(64, 96)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(48, 24)
        Me.Label10.TabIndex = 20
        Me.Label10.Text = "Acc"
        Me.Label10.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.btn_tv_start)
        Me.GroupBox2.Controls.Add(Me.tbox_tv_Tacc)
        Me.GroupBox2.Controls.Add(Me.tbox_tv_strvel)
        Me.GroupBox2.Controls.Add(Me.Label8)
        Me.GroupBox2.Controls.Add(Me.Label9)
        Me.GroupBox2.Controls.Add(Me.Label10)
        Me.GroupBox2.Controls.Add(Me.tbox_tv_maxvel)
        Me.GroupBox2.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox2.Location = New System.Drawing.Point(24, 24)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(336, 136)
        Me.GroupBox2.TabIndex = 21
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Velocity Mode Motion"
        '
        'btn_tv_start
        '
        Me.btn_tv_start.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btn_tv_start.Location = New System.Drawing.Point(232, 56)
        Me.btn_tv_start.Name = "btn_tv_start"
        Me.btn_tv_start.Size = New System.Drawing.Size(88, 40)
        Me.btn_tv_start.TabIndex = 21
        Me.btn_tv_start.Text = "START"
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.GroupBox7)
        Me.GroupBox3.Controls.Add(Me.btn_stop)
        Me.GroupBox3.Controls.Add(Me.Label15)
        Me.GroupBox3.Controls.Add(Me.tbox_AxisNumber)
        Me.GroupBox3.Controls.Add(Me.GroupBox4)
        Me.GroupBox3.Controls.Add(Me.GroupBox2)
        Me.GroupBox3.Controls.Add(Me.tbox_AxisNo_start)
        Me.GroupBox3.Controls.Add(Me.tbox_AxisNo_end)
        Me.GroupBox3.Controls.Add(Me.Label17)
        Me.GroupBox3.Controls.Add(Me.Label18)
        Me.GroupBox3.Controls.Add(Me.btn_exit)
        Me.GroupBox3.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox3.Location = New System.Drawing.Point(216, 8)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(384, 584)
        Me.GroupBox3.TabIndex = 22
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Control Panel"
        '
        'GroupBox7
        '
        Me.GroupBox7.Controls.Add(Me.Button1)
        Me.GroupBox7.Controls.Add(Me.Btn_SetFactor)
        Me.GroupBox7.Controls.Add(Me.Btn_WaitInt)
        Me.GroupBox7.Location = New System.Drawing.Point(24, 336)
        Me.GroupBox7.Name = "GroupBox7"
        Me.GroupBox7.Size = New System.Drawing.Size(336, 120)
        Me.GroupBox7.TabIndex = 30
        Me.GroupBox7.TabStop = False
        Me.GroupBox7.Text = "Motion Interrupt  Set"
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Button1.Location = New System.Drawing.Point(32, 72)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(128, 40)
        Me.Button1.TabIndex = 3
        Me.Button1.Text = "Stop Interrupt"
        '
        'Btn_SetFactor
        '
        Me.Btn_SetFactor.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Btn_SetFactor.Location = New System.Drawing.Point(32, 24)
        Me.Btn_SetFactor.Name = "Btn_SetFactor"
        Me.Btn_SetFactor.Size = New System.Drawing.Size(128, 40)
        Me.Btn_SetFactor.TabIndex = 2
        Me.Btn_SetFactor.Text = "Set Factor (Only Bit 0)"
        '
        'Btn_WaitInt
        '
        Me.Btn_WaitInt.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Btn_WaitInt.Location = New System.Drawing.Point(192, 32)
        Me.Btn_WaitInt.Name = "Btn_WaitInt"
        Me.Btn_WaitInt.Size = New System.Drawing.Size(128, 64)
        Me.Btn_WaitInt.TabIndex = 1
        Me.Btn_WaitInt.Text = "Wait Interrupt"
        '
        'btn_stop
        '
        Me.btn_stop.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btn_stop.Location = New System.Drawing.Point(272, 472)
        Me.btn_stop.Name = "btn_stop"
        Me.btn_stop.Size = New System.Drawing.Size(88, 40)
        Me.btn_stop.TabIndex = 25
        Me.btn_stop.Text = "STOP"
        '
        'Label15
        '
        Me.Label15.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label15.Location = New System.Drawing.Point(8, 496)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(200, 32)
        Me.Label15.TabIndex = 24
        Me.Label15.Text = "Key in axis number first"
        Me.Label15.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'tbox_AxisNumber
        '
        Me.tbox_AxisNumber.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_AxisNumber.Location = New System.Drawing.Point(208, 500)
        Me.tbox_AxisNumber.Name = "tbox_AxisNumber"
        Me.tbox_AxisNumber.Size = New System.Drawing.Size(40, 22)
        Me.tbox_AxisNumber.TabIndex = 23
        Me.tbox_AxisNumber.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.btn_tr_start)
        Me.GroupBox4.Controls.Add(Me.Label14)
        Me.GroupBox4.Controls.Add(Me.Label13)
        Me.GroupBox4.Controls.Add(Me.Label12)
        Me.GroupBox4.Controls.Add(Me.Label11)
        Me.GroupBox4.Controls.Add(Me.tbox_tr_distance)
        Me.GroupBox4.Controls.Add(Me.tbox_tr_strvel)
        Me.GroupBox4.Controls.Add(Me.tbox_tr_tacc)
        Me.GroupBox4.Controls.Add(Me.tbox_tr_maxvel)
        Me.GroupBox4.Location = New System.Drawing.Point(24, 168)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(336, 160)
        Me.GroupBox4.TabIndex = 22
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "Single Axis Position Mode"
        '
        'btn_tr_start
        '
        Me.btn_tr_start.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btn_tr_start.Location = New System.Drawing.Point(232, 64)
        Me.btn_tr_start.Name = "btn_tr_start"
        Me.btn_tr_start.Size = New System.Drawing.Size(88, 40)
        Me.btn_tr_start.TabIndex = 24
        Me.btn_tr_start.Text = "START"
        '
        'Label14
        '
        Me.Label14.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label14.Location = New System.Drawing.Point(40, 32)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(72, 24)
        Me.Label14.TabIndex = 23
        Me.Label14.Text = "Distance"
        '
        'Label13
        '
        Me.Label13.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label13.Location = New System.Drawing.Point(56, 128)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(48, 24)
        Me.Label13.TabIndex = 22
        Me.Label13.Text = "Acc"
        Me.Label13.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label12
        '
        Me.Label12.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label12.Location = New System.Drawing.Point(16, 64)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(104, 24)
        Me.Label12.TabIndex = 21
        Me.Label12.Text = "Start velocity"
        '
        'Label11
        '
        Me.Label11.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label11.Location = New System.Drawing.Point(24, 96)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(96, 24)
        Me.Label11.TabIndex = 20
        Me.Label11.Text = "Max velocity"
        '
        'tbox_tr_distance
        '
        Me.tbox_tr_distance.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_tr_distance.Location = New System.Drawing.Point(120, 32)
        Me.tbox_tr_distance.Name = "tbox_tr_distance"
        Me.tbox_tr_distance.Size = New System.Drawing.Size(96, 21)
        Me.tbox_tr_distance.TabIndex = 19
        Me.tbox_tr_distance.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'tbox_tr_strvel
        '
        Me.tbox_tr_strvel.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_tr_strvel.Location = New System.Drawing.Point(120, 64)
        Me.tbox_tr_strvel.Name = "tbox_tr_strvel"
        Me.tbox_tr_strvel.Size = New System.Drawing.Size(96, 21)
        Me.tbox_tr_strvel.TabIndex = 18
        Me.tbox_tr_strvel.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'tbox_tr_tacc
        '
        Me.tbox_tr_tacc.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_tr_tacc.Location = New System.Drawing.Point(120, 128)
        Me.tbox_tr_tacc.Name = "tbox_tr_tacc"
        Me.tbox_tr_tacc.Size = New System.Drawing.Size(96, 21)
        Me.tbox_tr_tacc.TabIndex = 17
        Me.tbox_tr_tacc.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'tbox_tr_maxvel
        '
        Me.tbox_tr_maxvel.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.tbox_tr_maxvel.Location = New System.Drawing.Point(120, 96)
        Me.tbox_tr_maxvel.Name = "tbox_tr_maxvel"
        Me.tbox_tr_maxvel.Size = New System.Drawing.Size(96, 21)
        Me.tbox_tr_maxvel.TabIndex = 16
        Me.tbox_tr_maxvel.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'tbox_AxisNo_start
        '
        Me.tbox_AxisNo_start.Enabled = False
        Me.tbox_AxisNo_start.Location = New System.Drawing.Point(104, 544)
        Me.tbox_AxisNo_start.Name = "tbox_AxisNo_start"
        Me.tbox_AxisNo_start.Size = New System.Drawing.Size(32, 22)
        Me.tbox_AxisNo_start.TabIndex = 27
        Me.tbox_AxisNo_start.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'tbox_AxisNo_end
        '
        Me.tbox_AxisNo_end.Enabled = False
        Me.tbox_AxisNo_end.Location = New System.Drawing.Point(168, 544)
        Me.tbox_AxisNo_end.Name = "tbox_AxisNo_end"
        Me.tbox_AxisNo_end.Size = New System.Drawing.Size(32, 22)
        Me.tbox_AxisNo_end.TabIndex = 28
        Me.tbox_AxisNo_end.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label17
        '
        Me.Label17.Font = New System.Drawing.Font("Arial", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label17.Location = New System.Drawing.Point(144, 544)
        Me.Label17.Name = "Label17"
        Me.Label17.Size = New System.Drawing.Size(16, 16)
        Me.Label17.TabIndex = 29
        Me.Label17.Text = "~"
        '
        'Label18
        '
        Me.Label18.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label18.Location = New System.Drawing.Point(24, 544)
        Me.Label18.Name = "Label18"
        Me.Label18.Size = New System.Drawing.Size(72, 24)
        Me.Label18.TabIndex = 22
        Me.Label18.Text = "Axis NO"
        Me.Label18.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'btn_exit
        '
        Me.btn_exit.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.btn_exit.Location = New System.Drawing.Point(272, 528)
        Me.btn_exit.Name = "btn_exit"
        Me.btn_exit.Size = New System.Drawing.Size(88, 40)
        Me.btn_exit.TabIndex = 25
        Me.btn_exit.Text = "EXIT"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 50
        '
        'GroupBox5
        '
        Me.GroupBox5.Controls.Add(Me.Label23)
        Me.GroupBox5.Controls.Add(Me.Label22)
        Me.GroupBox5.Controls.Add(Me.Label21)
        Me.GroupBox5.Controls.Add(Me.Label20)
        Me.GroupBox5.Controls.Add(Me.Label19)
        Me.GroupBox5.Controls.Add(Me.Motion_light1)
        Me.GroupBox5.Controls.Add(Me.Motion_light4)
        Me.GroupBox5.Controls.Add(Me.Motion_light3)
        Me.GroupBox5.Controls.Add(Me.Motion_light0)
        Me.GroupBox5.Controls.Add(Me.Motion_light2)
        Me.GroupBox5.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox5.Location = New System.Drawing.Point(16, 208)
        Me.GroupBox5.Name = "GroupBox5"
        Me.GroupBox5.Size = New System.Drawing.Size(184, 152)
        Me.GroupBox5.TabIndex = 26
        Me.GroupBox5.TabStop = False
        Me.GroupBox5.Text = "Motion Status"
        '
        'Label23
        '
        Me.Label23.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label23.Location = New System.Drawing.Point(96, 72)
        Me.Label23.Name = "Label23"
        Me.Label23.Size = New System.Drawing.Size(48, 24)
        Me.Label23.TabIndex = 12
        Me.Label23.Text = "DEC"
        Me.Label23.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label22
        '
        Me.Label22.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label22.Location = New System.Drawing.Point(96, 32)
        Me.Label22.Name = "Label22"
        Me.Label22.Size = New System.Drawing.Size(48, 24)
        Me.Label22.TabIndex = 11
        Me.Label22.Text = "ACC"
        Me.Label22.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label21
        '
        Me.Label21.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label21.Location = New System.Drawing.Point(8, 72)
        Me.Label21.Name = "Label21"
        Me.Label21.Size = New System.Drawing.Size(48, 24)
        Me.Label21.TabIndex = 10
        Me.Label21.Text = "DIR"
        Me.Label21.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label20
        '
        Me.Label20.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label20.Location = New System.Drawing.Point(64, 112)
        Me.Label20.Name = "Label20"
        Me.Label20.Size = New System.Drawing.Size(72, 24)
        Me.Label20.TabIndex = 9
        Me.Label20.Text = "HMV"
        Me.Label20.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label19
        '
        Me.Label19.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label19.Location = New System.Drawing.Point(0, 32)
        Me.Label19.Name = "Label19"
        Me.Label19.Size = New System.Drawing.Size(56, 24)
        Me.Label19.TabIndex = 8
        Me.Label19.Text = "STOP"
        Me.Label19.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Motion_light1
        '
        Me.Motion_light1.BackColor = System.Drawing.Color.DimGray
        Me.Motion_light1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Motion_light1.Location = New System.Drawing.Point(64, 72)
        Me.Motion_light1.Name = "Motion_light1"
        Me.Motion_light1.Size = New System.Drawing.Size(24, 24)
        Me.Motion_light1.TabIndex = 0
        Me.Motion_light1.TabStop = False
        '
        'Motion_light4
        '
        Me.Motion_light4.BackColor = System.Drawing.Color.DimGray
        Me.Motion_light4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Motion_light4.Location = New System.Drawing.Point(144, 72)
        Me.Motion_light4.Name = "Motion_light4"
        Me.Motion_light4.Size = New System.Drawing.Size(24, 24)
        Me.Motion_light4.TabIndex = 5
        Me.Motion_light4.TabStop = False
        '
        'Motion_light3
        '
        Me.Motion_light3.BackColor = System.Drawing.Color.DimGray
        Me.Motion_light3.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Motion_light3.Location = New System.Drawing.Point(144, 32)
        Me.Motion_light3.Name = "Motion_light3"
        Me.Motion_light3.Size = New System.Drawing.Size(24, 24)
        Me.Motion_light3.TabIndex = 2
        Me.Motion_light3.TabStop = False
        '
        'Motion_light0
        '
        Me.Motion_light0.BackColor = System.Drawing.Color.DimGray
        Me.Motion_light0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Motion_light0.Location = New System.Drawing.Point(64, 32)
        Me.Motion_light0.Name = "Motion_light0"
        Me.Motion_light0.Size = New System.Drawing.Size(24, 24)
        Me.Motion_light0.TabIndex = 1
        Me.Motion_light0.TabStop = False
        '
        'Motion_light2
        '
        Me.Motion_light2.BackColor = System.Drawing.Color.DimGray
        Me.Motion_light2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.Motion_light2.Location = New System.Drawing.Point(144, 112)
        Me.Motion_light2.Name = "Motion_light2"
        Me.Motion_light2.Size = New System.Drawing.Size(24, 24)
        Me.Motion_light2.TabIndex = 4
        Me.Motion_light2.TabStop = False
        '
        'GroupBox6
        '
        Me.GroupBox6.Controls.Add(Me.Tbox_MotionInt)
        Me.GroupBox6.Controls.Add(Me.Label25)
        Me.GroupBox6.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox6.Location = New System.Drawing.Point(16, 368)
        Me.GroupBox6.Name = "GroupBox6"
        Me.GroupBox6.Size = New System.Drawing.Size(184, 104)
        Me.GroupBox6.TabIndex = 27
        Me.GroupBox6.TabStop = False
        Me.GroupBox6.Text = "Motion Interrupt Counter"
        '
        'Tbox_MotionInt
        '
        Me.Tbox_MotionInt.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Tbox_MotionInt.Location = New System.Drawing.Point(48, 56)
        Me.Tbox_MotionInt.Name = "Tbox_MotionInt"
        Me.Tbox_MotionInt.ReadOnly = True
        Me.Tbox_MotionInt.Size = New System.Drawing.Size(80, 22)
        Me.Tbox_MotionInt.TabIndex = 11
        Me.Tbox_MotionInt.Text = "0"
        Me.Tbox_MotionInt.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label25
        '
        Me.Label25.Font = New System.Drawing.Font("Arial", 11.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label25.Location = New System.Drawing.Point(40, 24)
        Me.Label25.Name = "Label25"
        Me.Label25.Size = New System.Drawing.Size(88, 24)
        Me.Label25.TabIndex = 10
        Me.Label25.Text = "Bit 0 : Stop"
        Me.Label25.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'GroupBox8
        '
        Me.GroupBox8.Controls.Add(Me.Tbox_RemainPs)
        Me.GroupBox8.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBox8.Location = New System.Drawing.Point(16, 488)
        Me.GroupBox8.Name = "GroupBox8"
        Me.GroupBox8.Size = New System.Drawing.Size(184, 104)
        Me.GroupBox8.TabIndex = 28
        Me.GroupBox8.TabStop = False
        Me.GroupBox8.Text = "Command"
        '
        'Tbox_RemainPs
        '
        Me.Tbox_RemainPs.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Tbox_RemainPs.Location = New System.Drawing.Point(40, 48)
        Me.Tbox_RemainPs.Name = "Tbox_RemainPs"
        Me.Tbox_RemainPs.ReadOnly = True
        Me.Tbox_RemainPs.Size = New System.Drawing.Size(96, 22)
        Me.Tbox_RemainPs.TabIndex = 11
        Me.Tbox_RemainPs.Text = "0"
        Me.Tbox_RemainPs.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(6, 14)
        Me.ClientSize = New System.Drawing.Size(608, 638)
        Me.Controls.Add(Me.GroupBox8)
        Me.Controls.Add(Me.GroupBox6)
        Me.Controls.Add(Me.GroupBox5)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox1)
        Me.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.Name = "Form1"
        Me.Text = "PCI-8144 Motion"
        CType(Me.PEL_light, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.NEL_light, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.STA_light, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.NSD_light, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.ORG_light, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.STP_light, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PSD_light, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.GroupBox7.ResumeLayout(False)
        Me.GroupBox4.ResumeLayout(False)
        Me.GroupBox4.PerformLayout()
        Me.GroupBox5.ResumeLayout(False)
        CType(Me.Motion_light1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Motion_light4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Motion_light3, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Motion_light0, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Motion_light2, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox6.ResumeLayout(False)
        Me.GroupBox6.PerformLayout()
        Me.GroupBox8.ResumeLayout(False)
        Me.GroupBox8.PerformLayout()
        Me.ResumeLayout(False)

    End Sub

#End Region

    ' Win32 API
    Declare Function GetSystemDirectory Lib "kernel32" Alias "GetSystemDirectoryA" (ByVal lpBuffer As String, ByVal nSize As Integer) As Integer

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim CardID_Bit, CardID, AxisNO_start As Short

        Dim i, AxisNO_end As Short

        Dim WinDir As String

        Dim Size_Renamed As Short

        Dim DesFile As String

        Dim MSG1 As String = ""
        Dim MSG2 As String = ""

        Timer1.Enabled = False

        GroupBox2.Enabled = False

        GroupBox4.Enabled = False

        GroupBox7.Enabled = False

        btn_stop.Enabled = False

        'B_8144_initial(CardID_Bit, 0)
        APS_initial(CardID_Bit, 0)

        For i = 0 To 15

            If (CardID_Bit And (2 ^ i)) Then

                CARDS_PCI_8144_Status(i) = True

                ExistCards = ExistCards + 1

            Else

                CARDS_PCI_8144_Status(i) = False

            End If

        Next

        If ExistCards = 0 Then

            MessageBox.Show("No PCI-8144 card exist", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)

            'B_8144_close()
            APS_close()

        End If

        WinDir = Space(64)

        GetSystemDirectory(WinDir, 64)

        Size_Renamed = InStr(WinDir, Chr(0)) - 1

        WinDir = VB.Left(WinDir, Size_Renamed)

        DesFile = VB.Left(WinDir, Size_Renamed) & "\APS168.DLL"

        MSG1 = Dir(DesFile)

        DesFile = VB.Left(WinDir, Size_Renamed) & "\APS168x64.DLL"

        MSG2 = Dir(DesFile)

        If MSG1 = "" And MSG2 = "" Then
            MessageBox.Show("Please check your file <<APS168.DLL>>", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error)
        End If

        For i = 0 To 15

            If CARDS_PCI_8144_Status(i) = True Then
                CardID = i
                AxisNO_start = 4 * i
                AxisNO_end = AxisNO_start + 3
            End If

        Next

        tbox_AxisNo_start.Text = Str(AxisNO_start)

        tbox_AxisNo_end.Text = Str(AxisNO_end)

        Thread_Int_Motion.Start()

    End Sub


    Public Function Motion_Status() As Short

        'B_8144_motion_status(tbox_AxisNumber.Text, Motion_InBit)
        Motion_InBit = APS_motion_status(tbox_AxisNumber.Text)

        If (Motion_InBit And &H1) Then
            'Motion_light0.BackColor = Color.DimGray
            Motion_light0.BackColor = Color.Lime
        Else
            'Motion_light0.BackColor = Color.Lime
            Motion_light0.BackColor = Color.DimGray
        End If

        If (Motion_InBit And &H10) Then
            Motion_light1.BackColor = Color.Lime
        Else
            Motion_light1.BackColor = Color.DimGray
        End If

        If (Motion_InBit And &H40) Then
            Motion_light2.BackColor = Color.Lime
        Else
            Motion_light2.BackColor = Color.DimGray
        End If

        If (Motion_InBit And &H4) Then
            Motion_light3.BackColor = Color.Lime
        Else
            Motion_light3.BackColor = Color.DimGray
        End If

        If (Motion_InBit And &H8) Then
            Motion_light4.BackColor = Color.Lime
        Else
            Motion_light4.BackColor = Color.DimGray
        End If

    End Function

    Private Sub tbox_AxisNumber_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_AxisNumber.Click

        GroupBox2.Enabled = True

        GroupBox4.Enabled = True

        GroupBox7.Enabled = True

        btn_stop.Enabled = True

    End Sub

    Private Sub tbox_AxisNumber_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_AxisNumber.TextChanged

        Dim GetData As Integer = 0

        If Not IsNumeric(tbox_AxisNumber.Text) Then
            tbox_AxisNumber.Text = "0"
        End If

        APS_get_axis_param(CInt(tbox_AxisNumber.Text), PRA_VS, GetData)
        tbox_tv_strvel.Text = CStr(GetData)
        tbox_tr_strvel.Text = CStr(GetData)

        APS_get_axis_param(CInt(tbox_AxisNumber.Text), PRA_ACC, GetData)
        tbox_tv_Tacc.Text = CStr(GetData)
        tbox_tr_tacc.Text = CStr(GetData)

    End Sub

    Private Sub tbox_tr_distance_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tr_distance.TextChanged

        If Not IsNumeric(tbox_tr_distance.Text) Then
            tbox_tr_distance.Text = "0"
        End If

    End Sub

    Private Sub tbox_tr_distance_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tr_distance.Click

        tbox_tr_distance.Text = "0"

    End Sub

    Private Sub tbox_tr_maxvel_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tr_maxvel.TextChanged

        If Not IsNumeric(tbox_tr_maxvel.Text) Then
            tbox_tr_maxvel.Text = "0"
        End If

    End Sub

    Private Sub tbox_tr_maxvel_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tr_maxvel.Click

        tbox_tr_maxvel.Text = "0"

    End Sub

    Private Sub tbox_tr_strvel_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tr_strvel.TextChanged

        If Not IsNumeric(tbox_tr_strvel.Text) Then
            tbox_tr_strvel.Text = "0"
        End If

    End Sub

    Private Sub tbox_tr_strvel_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tr_strvel.Click

        tbox_tr_strvel.Text = "0"

    End Sub

    Private Sub tbox_tv_maxvel_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tv_maxvel.TextChanged

        If Not IsNumeric(tbox_tv_maxvel.Text) Then
            tbox_tv_maxvel.Text = "0"
        End If

    End Sub

    Private Sub tbox_tv_maxvel_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tv_maxvel.Click

        tbox_tv_maxvel.Text = "0"

    End Sub


    Private Sub tbox_tv_strvel_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tv_strvel.TextChanged

        If Not IsNumeric(tbox_tv_strvel.Text) Then
            tbox_tv_strvel.Text = "0"
        End If

    End Sub

    Private Sub tbox_tv_strvel_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tv_strvel.Click

        tbox_tv_strvel.Text = "0"

    End Sub

    Private Sub tbox_tv_Tacc_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tv_Tacc.TextChanged

        If Not IsNumeric(tbox_tv_Tacc.Text) Then
            tbox_tv_Tacc.Text = "0"
        End If

    End Sub

    Private Sub tbox_tv_Tacc_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tv_Tacc.Click

        tbox_tv_Tacc.Text = "0"

    End Sub

    Private Sub tbox_tr_tacc_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles tbox_tr_tacc.TextChanged

        If Not IsNumeric(tbox_tr_tacc.Text) Then
            tbox_tr_tacc.Text = "0"
        End If

    End Sub

    Private Sub tbox_tr_tacc_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles tbox_tr_tacc.Click

        tbox_tr_tacc.Text = "0"

    End Sub

    Private Sub btn_tv_start_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_tv_start.Click

        Timer1.Enabled = True

        'B_8144_set_gpio_output(0, 9)
        'B_8144_set_limit_logic(CInt(tbox_AxisNumber.Text), 1)
        'B_8144_tv_move(CShort(tbox_AxisNumber.Text), CDbl(tbox_tv_strvel.Text), CDbl(tbox_tv_maxvel.Text), CDbl(tbox_tv_Tacc.Text))

        APS_set_axis_param(CInt(tbox_AxisNumber.Text), PRA_EL_LOGIC, 1)
        APS_set_axis_param(CInt(tbox_AxisNumber.Text), PRA_VS, CInt(tbox_tv_strvel.Text))
        APS_set_axis_param(CInt(tbox_AxisNumber.Text), PRA_ACC, CInt(tbox_tv_Tacc.Text))

        APS_velocity_move(CInt(tbox_AxisNumber.Text), CInt(tbox_tv_maxvel.Text))

    End Sub


    Private Sub btn_tr_start_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_tr_start.Click

        Timer1.Enabled = True

        'B_8144_set_limit_logic(CInt(tbox_AxisNumber.Text), 1)
        'B_8144_set_gpio_output(0, 9)
        'B_8144_start_tr_move(CShort(tbox_AxisNumber.Text), CDbl(tbox_tr_distance.Text), CDbl(tbox_tr_strvel.Text), CDbl(tbox_tr_maxvel.Text), CDbl(tbox_tr_tacc.Text))

        APS_set_axis_param(CInt(tbox_AxisNumber.Text), PRA_EL_LOGIC, 1)
        APS_set_axis_param(CInt(tbox_AxisNumber.Text), PRA_VS, CInt(tbox_tr_strvel.Text))
        APS_set_axis_param(CInt(tbox_AxisNumber.Text), PRA_ACC, CInt(tbox_tr_tacc.Text))

        APS_relative_move(CInt(tbox_AxisNumber.Text), CInt(tbox_tr_distance.Text), CInt(tbox_tr_maxvel.Text))

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick

        Dim i As Integer

        Dim Remain_pulse As Double

        'B_8144_get_mio_status(CShort(tbox_AxisNumber.Text), Status)
        Status = APS_motion_io_status(CInt(tbox_AxisNumber.Text))

        'If Status And &H80 = 128 Then
        '    Status = Status - 128
        'End If

        ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

        If (Status And &H4) Then
            NEL_light.BackColor = Color.Lime
        Else
            NEL_light.BackColor = Color.DimGray
        End If

        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

        If (Status And &H2) Then
            PEL_light.BackColor = Color.Lime
        Else
            PEL_light.BackColor = Color.DimGray
        End If

        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

        If (Status And &H8) Then
            ORG_light.BackColor = Color.Lime
        Else
            ORG_light.BackColor = Color.DimGray
        End If

        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

        If (Status And &H10) Then
            STP_light.BackColor = Color.Lime
        Else
            STP_light.BackColor = Color.DimGray
        End If

        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

        If (Status And &H8000) Then
            STA_light.BackColor = Color.Lime
        Else
            STA_light.BackColor = Color.DimGray
        End If

        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

        If (Status And &H10000) Then
            PSD_light.BackColor = Color.Lime
        Else
            PSD_light.BackColor = Color.DimGray
        End If

        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''

        If (Status And &H20000) Then
            NSD_light.BackColor = Color.Lime
        Else
            NSD_light.BackColor = Color.DimGray
        End If

        Motion_Status()

        'B_8144_get_remaining_pulse(tbox_AxisNumber.Text, Remain_pulse)
        APS_get_command(CInt(tbox_AxisNumber.Text), Remain_pulse)


        Tbox_RemainPs.Text = Str(Remain_pulse)

        Tbox_MotionInt.Text = Str(Motion_Counter)

    End Sub

    Private Sub btn_stop_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_stop.Click

        'B_8144_set_gpio_output(0, 0)

        'B_8144_emg_stop(CShort(tbox_AxisNumber.Text))

        APS_emg_stop(CInt(tbox_AxisNumber.Text))

    End Sub

    Private Sub tbox_AxisNumber_KeyDown(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles tbox_AxisNumber.KeyDown

        GroupBox2.Enabled = True

        GroupBox4.Enabled = True

        GroupBox7.Enabled = True

        btn_stop.Enabled = True

    End Sub

    Private Sub btn_exit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btn_exit.Click

        Thread_Int_Motion.Abort()

        'B_8144_close()
        APS_close()

        Me.Close()

    End Sub

    Private Sub Form1_Closed(ByVal sender As Object, ByVal e As System.EventArgs) Handles MyBase.Closed

        Thread_Int_Motion.Abort()

        'B_8144_close()
        APS_close()

    End Sub

    Sub Int_Motion()

        While 1

            If Int_Flag = 1 Then

                'Rtn_Msg_Motion = B_8144_wait_single_motion_interrupt(CInt(tbox_AxisNumber.Text), 0, 10000)
                Rtn_Msg_Motion = APS_wait_single_int(Int_No, 10000)

                If Rtn_Msg_Motion = 0 Then
                    Motion_Counter = Motion_Counter + 1
                End If

                APS_reset_int(Int_No)

                Int_Flag = 0

            End If

            Sleep(50)

        End While

    End Sub


    Private Sub Btn_WaitInt_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_WaitInt.Click

        Int_Flag = 1

    End Sub

    Private Sub Btn_SetFactor_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Btn_SetFactor.Click

        'B_8144_set_motion_interrupt_factor(tbox_AxisNumber.Text, 1)

        Int_No = APS_set_int_factor(CInt(tbox_AxisNumber.Text / 4), CInt(tbox_AxisNumber.Text), 0, 1)
        APS_int_enable(CInt(tbox_AxisNumber.Text / 4), 1)

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        Int_Flag = 0
        'B_8144_set_motion_interrupt_factor(tbox_AxisNumber.Text, 0)

        APS_set_int_factor(CInt(tbox_AxisNumber.Text / 4), CInt(tbox_AxisNumber.Text), 0, 0)
        APS_int_enable(CInt(tbox_AxisNumber.Text / 4), 0)

    End Sub

    Private Sub GroupBox3_Enter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles GroupBox3.Enter

    End Sub
End Class
