Public Class Form1
    Inherits System.Windows.Forms.Form

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
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Pos0 As System.Windows.Forms.TextBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents IOSts0 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents Speed0 As System.Windows.Forms.TextBox
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents MotSts0 As System.Windows.Forms.TextBox
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents PTP_AXIS As System.Windows.Forms.TextBox
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents GroupBox5 As System.Windows.Forms.GroupBox
    Friend WithEvents CMD0 As System.Windows.Forms.TextBox
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents GroupBox6 As System.Windows.Forms.GroupBox
    Public WithEvents Maximum_Velocity1 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity1 As System.Windows.Forms.TextBox
    Public WithEvents Text21 As System.Windows.Forms.TextBox
    Public WithEvents Text22 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration1 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration1 As System.Windows.Forms.TextBox
    Public WithEvents Text24 As System.Windows.Forms.TextBox
    Public WithEvents Text25 As System.Windows.Forms.TextBox
    Public WithEvents Label9 As System.Windows.Forms.Label
    Public WithEvents Distance1 As System.Windows.Forms.TextBox
    Public WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents GroupBox7 As System.Windows.Forms.GroupBox
    Public WithEvents Label3 As System.Windows.Forms.Label
    Public WithEvents TextBox4 As System.Windows.Forms.TextBox
    Public WithEvents TextBox5 As System.Windows.Forms.TextBox
    Public WithEvents TextBox8 As System.Windows.Forms.TextBox
    Public WithEvents TextBox9 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox8 As System.Windows.Forms.GroupBox
    Public WithEvents Label5 As System.Windows.Forms.Label
    Public WithEvents TextBox13 As System.Windows.Forms.TextBox
    Public WithEvents TextBox14 As System.Windows.Forms.TextBox
    Public WithEvents TextBox17 As System.Windows.Forms.TextBox
    Public WithEvents TextBox18 As System.Windows.Forms.TextBox
    Public WithEvents Distance2 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration2 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration2 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity2 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity2 As System.Windows.Forms.TextBox
    Public WithEvents Distance3 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration3 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration3 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity3 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity3 As System.Windows.Forms.TextBox
    Friend WithEvents AxDChart1 As AxDBGRAPHLib.AxDChart
    Friend WithEvents txtStep As System.Windows.Forms.TextBox
    Public WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents Button2 As System.Windows.Forms.Button
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Pos0 = New System.Windows.Forms.TextBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.IOSts0 = New System.Windows.Forms.TextBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.GroupBox3 = New System.Windows.Forms.GroupBox
        Me.Speed0 = New System.Windows.Forms.TextBox
        Me.Label6 = New System.Windows.Forms.Label
        Me.GroupBox4 = New System.Windows.Forms.GroupBox
        Me.MotSts0 = New System.Windows.Forms.TextBox
        Me.Label8 = New System.Windows.Forms.Label
        Me.Button1 = New System.Windows.Forms.Button
        Me.PTP_AXIS = New System.Windows.Forms.TextBox
        Me.Label9 = New System.Windows.Forms.Label
        Me.Button4 = New System.Windows.Forms.Button
        Me.Button5 = New System.Windows.Forms.Button
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.GroupBox5 = New System.Windows.Forms.GroupBox
        Me.CMD0 = New System.Windows.Forms.TextBox
        Me.Label11 = New System.Windows.Forms.Label
        Me.GroupBox6 = New System.Windows.Forms.GroupBox
        Me.Distance1 = New System.Windows.Forms.TextBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.T_Acceleration1 = New System.Windows.Forms.TextBox
        Me.T_Deceleration1 = New System.Windows.Forms.TextBox
        Me.Text24 = New System.Windows.Forms.TextBox
        Me.Text25 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity1 = New System.Windows.Forms.TextBox
        Me.Start_Velocity1 = New System.Windows.Forms.TextBox
        Me.Text21 = New System.Windows.Forms.TextBox
        Me.Text22 = New System.Windows.Forms.TextBox
        Me.GroupBox7 = New System.Windows.Forms.GroupBox
        Me.Distance2 = New System.Windows.Forms.TextBox
        Me.Label3 = New System.Windows.Forms.Label
        Me.T_Acceleration2 = New System.Windows.Forms.TextBox
        Me.T_Deceleration2 = New System.Windows.Forms.TextBox
        Me.TextBox4 = New System.Windows.Forms.TextBox
        Me.TextBox5 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity2 = New System.Windows.Forms.TextBox
        Me.Start_Velocity2 = New System.Windows.Forms.TextBox
        Me.TextBox8 = New System.Windows.Forms.TextBox
        Me.TextBox9 = New System.Windows.Forms.TextBox
        Me.GroupBox8 = New System.Windows.Forms.GroupBox
        Me.Distance3 = New System.Windows.Forms.TextBox
        Me.Label5 = New System.Windows.Forms.Label
        Me.T_Acceleration3 = New System.Windows.Forms.TextBox
        Me.T_Deceleration3 = New System.Windows.Forms.TextBox
        Me.TextBox13 = New System.Windows.Forms.TextBox
        Me.TextBox14 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity3 = New System.Windows.Forms.TextBox
        Me.Start_Velocity3 = New System.Windows.Forms.TextBox
        Me.TextBox17 = New System.Windows.Forms.TextBox
        Me.TextBox18 = New System.Windows.Forms.TextBox
        Me.AxDChart1 = New AxDBGRAPHLib.AxDChart
        Me.txtStep = New System.Windows.Forms.TextBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.Button2 = New System.Windows.Forms.Button
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox5.SuspendLayout()
        Me.GroupBox6.SuspendLayout()
        Me.GroupBox7.SuspendLayout()
        Me.GroupBox8.SuspendLayout()
        CType(Me.AxDChart1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Pos0)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(352, 192)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(160, 72)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Position (p)"
        '
        'Pos0
        '
        Me.Pos0.Location = New System.Drawing.Point(64, 32)
        Me.Pos0.Name = "Pos0"
        Me.Pos0.Size = New System.Drawing.Size(80, 27)
        Me.Pos0.TabIndex = 2
        Me.Pos0.Text = "0"
        '
        'Label1
        '
        Me.Label1.Location = New System.Drawing.Point(8, 38)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(48, 23)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Axis 0"
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.IOSts0)
        Me.GroupBox2.Controls.Add(Me.Label4)
        Me.GroupBox2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox2.Location = New System.Drawing.Point(520, 192)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(160, 72)
        Me.GroupBox2.TabIndex = 1
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "I/O Status (Hex)"
        '
        'IOSts0
        '
        Me.IOSts0.Location = New System.Drawing.Point(68, 32)
        Me.IOSts0.Name = "IOSts0"
        Me.IOSts0.Size = New System.Drawing.Size(80, 27)
        Me.IOSts0.TabIndex = 6
        Me.IOSts0.Text = "0"
        '
        'Label4
        '
        Me.Label4.Location = New System.Drawing.Point(12, 40)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(48, 23)
        Me.Label4.TabIndex = 4
        Me.Label4.Text = "Axis 0"
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.Speed0)
        Me.GroupBox3.Controls.Add(Me.Label6)
        Me.GroupBox3.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox3.Location = New System.Drawing.Point(352, 272)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(160, 72)
        Me.GroupBox3.TabIndex = 2
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Speed (pps)"
        '
        'Speed0
        '
        Me.Speed0.Location = New System.Drawing.Point(64, 32)
        Me.Speed0.Name = "Speed0"
        Me.Speed0.Size = New System.Drawing.Size(80, 27)
        Me.Speed0.TabIndex = 2
        Me.Speed0.Text = "0"
        '
        'Label6
        '
        Me.Label6.Location = New System.Drawing.Point(8, 38)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(48, 23)
        Me.Label6.TabIndex = 0
        Me.Label6.Text = "Axis 0"
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.MotSts0)
        Me.GroupBox4.Controls.Add(Me.Label8)
        Me.GroupBox4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox4.Location = New System.Drawing.Point(520, 272)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(160, 72)
        Me.GroupBox4.TabIndex = 3
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "Motion Status"
        '
        'MotSts0
        '
        Me.MotSts0.Location = New System.Drawing.Point(64, 32)
        Me.MotSts0.Name = "MotSts0"
        Me.MotSts0.Size = New System.Drawing.Size(80, 27)
        Me.MotSts0.TabIndex = 2
        Me.MotSts0.Text = "0"
        '
        'Label8
        '
        Me.Label8.Location = New System.Drawing.Point(8, 38)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(48, 23)
        Me.Label8.TabIndex = 0
        Me.Label8.Text = "Axis 0"
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button1.Location = New System.Drawing.Point(576, 96)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(96, 32)
        Me.Button1.TabIndex = 4
        Me.Button1.Text = "Start"
        '
        'PTP_AXIS
        '
        Me.PTP_AXIS.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.PTP_AXIS.Location = New System.Drawing.Point(624, 56)
        Me.PTP_AXIS.Name = "PTP_AXIS"
        Me.PTP_AXIS.Size = New System.Drawing.Size(48, 27)
        Me.PTP_AXIS.TabIndex = 8
        Me.PTP_AXIS.Text = "0"
        '
        'Label9
        '
        Me.Label9.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label9.Location = New System.Drawing.Point(576, 64)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(48, 23)
        Me.Label9.TabIndex = 7
        Me.Label9.Text = "Axis :"
        '
        'Button4
        '
        Me.Button4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button4.Location = New System.Drawing.Point(528, 368)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(72, 56)
        Me.Button4.TabIndex = 17
        Me.Button4.Text = "Reset Position"
        '
        'Button5
        '
        Me.Button5.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button5.Location = New System.Drawing.Point(608, 368)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(72, 56)
        Me.Button5.TabIndex = 18
        Me.Button5.Text = "EMG Stop"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 50
        '
        'GroupBox5
        '
        Me.GroupBox5.Controls.Add(Me.CMD0)
        Me.GroupBox5.Controls.Add(Me.Label11)
        Me.GroupBox5.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox5.Location = New System.Drawing.Point(352, 352)
        Me.GroupBox5.Name = "GroupBox5"
        Me.GroupBox5.Size = New System.Drawing.Size(160, 72)
        Me.GroupBox5.TabIndex = 19
        Me.GroupBox5.TabStop = False
        Me.GroupBox5.Text = "Command Output"
        '
        'CMD0
        '
        Me.CMD0.Location = New System.Drawing.Point(64, 32)
        Me.CMD0.Name = "CMD0"
        Me.CMD0.Size = New System.Drawing.Size(80, 27)
        Me.CMD0.TabIndex = 2
        Me.CMD0.Text = "0"
        '
        'Label11
        '
        Me.Label11.Location = New System.Drawing.Point(8, 38)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(48, 23)
        Me.Label11.TabIndex = 0
        Me.Label11.Text = "Axis 0"
        '
        'GroupBox6
        '
        Me.GroupBox6.Controls.Add(Me.Distance1)
        Me.GroupBox6.Controls.Add(Me.Label2)
        Me.GroupBox6.Controls.Add(Me.T_Acceleration1)
        Me.GroupBox6.Controls.Add(Me.T_Deceleration1)
        Me.GroupBox6.Controls.Add(Me.Text24)
        Me.GroupBox6.Controls.Add(Me.Text25)
        Me.GroupBox6.Controls.Add(Me.Maximum_Velocity1)
        Me.GroupBox6.Controls.Add(Me.Start_Velocity1)
        Me.GroupBox6.Controls.Add(Me.Text21)
        Me.GroupBox6.Controls.Add(Me.Text22)
        Me.GroupBox6.Location = New System.Drawing.Point(16, 16)
        Me.GroupBox6.Name = "GroupBox6"
        Me.GroupBox6.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox6.TabIndex = 20
        Me.GroupBox6.TabStop = False
        Me.GroupBox6.Text = "Motion 1"
        '
        'Distance1
        '
        Me.Distance1.AcceptsReturn = True
        Me.Distance1.BackColor = System.Drawing.SystemColors.Window
        Me.Distance1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance1.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance1.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance1.Location = New System.Drawing.Point(96, 120)
        Me.Distance1.MaxLength = 0
        Me.Distance1.Name = "Distance1"
        Me.Distance1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance1.Size = New System.Drawing.Size(48, 21)
        Me.Distance1.TabIndex = 27
        Me.Distance1.Text = "100000"
        Me.Distance1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label2
        '
        Me.Label2.BackColor = System.Drawing.SystemColors.Control
        Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label2.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label2.Location = New System.Drawing.Point(8, 120)
        Me.Label2.Name = "Label2"
        Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label2.Size = New System.Drawing.Size(88, 24)
        Me.Label2.TabIndex = 28
        Me.Label2.Text = "Distance1:"
        '
        'T_Acceleration1
        '
        Me.T_Acceleration1.AcceptsReturn = True
        Me.T_Acceleration1.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration1.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration1.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration1.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration1.MaxLength = 0
        Me.T_Acceleration1.Name = "T_Acceleration1"
        Me.T_Acceleration1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration1.Size = New System.Drawing.Size(49, 21)
        Me.T_Acceleration1.TabIndex = 20
        Me.T_Acceleration1.Text = "50000"
        Me.T_Acceleration1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration1
        '
        Me.T_Deceleration1.AcceptsReturn = True
        Me.T_Deceleration1.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration1.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration1.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration1.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration1.MaxLength = 0
        Me.T_Deceleration1.Name = "T_Deceleration1"
        Me.T_Deceleration1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration1.Size = New System.Drawing.Size(49, 21)
        Me.T_Deceleration1.TabIndex = 19
        Me.T_Deceleration1.Text = "10000000"
        Me.T_Deceleration1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Text24
        '
        Me.Text24.AcceptsReturn = True
        Me.Text24.BackColor = System.Drawing.SystemColors.Control
        Me.Text24.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.Text24.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Text24.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Text24.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.Text24.Location = New System.Drawing.Point(8, 72)
        Me.Text24.MaxLength = 0
        Me.Text24.Name = "Text24"
        Me.Text24.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Text24.Size = New System.Drawing.Size(81, 14)
        Me.Text24.TabIndex = 18
        Me.Text24.Text = "Acc1:"
        '
        'Text25
        '
        Me.Text25.AcceptsReturn = True
        Me.Text25.BackColor = System.Drawing.SystemColors.Control
        Me.Text25.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.Text25.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Text25.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Text25.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.Text25.Location = New System.Drawing.Point(8, 96)
        Me.Text25.MaxLength = 0
        Me.Text25.Name = "Text25"
        Me.Text25.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Text25.Size = New System.Drawing.Size(81, 14)
        Me.Text25.TabIndex = 17
        Me.Text25.Text = "Dec1:"
        '
        'Maximum_Velocity1
        '
        Me.Maximum_Velocity1.AcceptsReturn = True
        Me.Maximum_Velocity1.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity1.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity1.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity1.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity1.MaxLength = 0
        Me.Maximum_Velocity1.Name = "Maximum_Velocity1"
        Me.Maximum_Velocity1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity1.Size = New System.Drawing.Size(49, 21)
        Me.Maximum_Velocity1.TabIndex = 16
        Me.Maximum_Velocity1.Text = "50000"
        Me.Maximum_Velocity1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity1
        '
        Me.Start_Velocity1.AcceptsReturn = True
        Me.Start_Velocity1.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity1.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity1.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity1.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity1.MaxLength = 0
        Me.Start_Velocity1.Name = "Start_Velocity1"
        Me.Start_Velocity1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity1.Size = New System.Drawing.Size(49, 21)
        Me.Start_Velocity1.TabIndex = 15
        Me.Start_Velocity1.Text = "1000"
        Me.Start_Velocity1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Text21
        '
        Me.Text21.AcceptsReturn = True
        Me.Text21.BackColor = System.Drawing.SystemColors.Control
        Me.Text21.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.Text21.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Text21.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Text21.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.Text21.Location = New System.Drawing.Point(8, 24)
        Me.Text21.MaxLength = 0
        Me.Text21.Name = "Text21"
        Me.Text21.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Text21.Size = New System.Drawing.Size(81, 14)
        Me.Text21.TabIndex = 14
        Me.Text21.Text = "Min_Vel1 :"
        '
        'Text22
        '
        Me.Text22.AcceptsReturn = True
        Me.Text22.BackColor = System.Drawing.SystemColors.Control
        Me.Text22.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.Text22.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Text22.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Text22.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.Text22.Location = New System.Drawing.Point(8, 48)
        Me.Text22.MaxLength = 0
        Me.Text22.Name = "Text22"
        Me.Text22.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Text22.Size = New System.Drawing.Size(81, 14)
        Me.Text22.TabIndex = 13
        Me.Text22.Text = "Max_Vel1 :"
        '
        'GroupBox7
        '
        Me.GroupBox7.Controls.Add(Me.Distance2)
        Me.GroupBox7.Controls.Add(Me.Label3)
        Me.GroupBox7.Controls.Add(Me.T_Acceleration2)
        Me.GroupBox7.Controls.Add(Me.T_Deceleration2)
        Me.GroupBox7.Controls.Add(Me.TextBox4)
        Me.GroupBox7.Controls.Add(Me.TextBox5)
        Me.GroupBox7.Controls.Add(Me.Maximum_Velocity2)
        Me.GroupBox7.Controls.Add(Me.Start_Velocity2)
        Me.GroupBox7.Controls.Add(Me.TextBox8)
        Me.GroupBox7.Controls.Add(Me.TextBox9)
        Me.GroupBox7.Location = New System.Drawing.Point(184, 16)
        Me.GroupBox7.Name = "GroupBox7"
        Me.GroupBox7.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox7.TabIndex = 21
        Me.GroupBox7.TabStop = False
        Me.GroupBox7.Text = "Motion 2"
        '
        'Distance2
        '
        Me.Distance2.AcceptsReturn = True
        Me.Distance2.BackColor = System.Drawing.SystemColors.Window
        Me.Distance2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance2.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance2.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance2.Location = New System.Drawing.Point(96, 120)
        Me.Distance2.MaxLength = 0
        Me.Distance2.Name = "Distance2"
        Me.Distance2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance2.Size = New System.Drawing.Size(48, 21)
        Me.Distance2.TabIndex = 27
        Me.Distance2.Text = "200000"
        Me.Distance2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label3
        '
        Me.Label3.BackColor = System.Drawing.SystemColors.Control
        Me.Label3.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label3.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label3.Location = New System.Drawing.Point(8, 120)
        Me.Label3.Name = "Label3"
        Me.Label3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label3.Size = New System.Drawing.Size(88, 24)
        Me.Label3.TabIndex = 28
        Me.Label3.Text = "Distance2:"
        '
        'T_Acceleration2
        '
        Me.T_Acceleration2.AcceptsReturn = True
        Me.T_Acceleration2.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration2.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration2.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration2.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration2.MaxLength = 0
        Me.T_Acceleration2.Name = "T_Acceleration2"
        Me.T_Acceleration2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration2.Size = New System.Drawing.Size(49, 21)
        Me.T_Acceleration2.TabIndex = 20
        Me.T_Acceleration2.Text = "50000"
        Me.T_Acceleration2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration2
        '
        Me.T_Deceleration2.AcceptsReturn = True
        Me.T_Deceleration2.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration2.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration2.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration2.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration2.MaxLength = 0
        Me.T_Deceleration2.Name = "T_Deceleration2"
        Me.T_Deceleration2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration2.Size = New System.Drawing.Size(49, 21)
        Me.T_Deceleration2.TabIndex = 19
        Me.T_Deceleration2.Text = "50000"
        Me.T_Deceleration2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox4
        '
        Me.TextBox4.AcceptsReturn = True
        Me.TextBox4.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox4.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox4.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox4.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox4.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox4.Location = New System.Drawing.Point(8, 72)
        Me.TextBox4.MaxLength = 0
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox4.Size = New System.Drawing.Size(81, 14)
        Me.TextBox4.TabIndex = 18
        Me.TextBox4.Text = "Acc2:"
        '
        'TextBox5
        '
        Me.TextBox5.AcceptsReturn = True
        Me.TextBox5.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox5.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox5.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox5.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox5.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox5.Location = New System.Drawing.Point(8, 96)
        Me.TextBox5.MaxLength = 0
        Me.TextBox5.Name = "TextBox5"
        Me.TextBox5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox5.Size = New System.Drawing.Size(81, 14)
        Me.TextBox5.TabIndex = 17
        Me.TextBox5.Text = "Dec2:"
        '
        'Maximum_Velocity2
        '
        Me.Maximum_Velocity2.AcceptsReturn = True
        Me.Maximum_Velocity2.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity2.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity2.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity2.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity2.MaxLength = 0
        Me.Maximum_Velocity2.Name = "Maximum_Velocity2"
        Me.Maximum_Velocity2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity2.Size = New System.Drawing.Size(49, 21)
        Me.Maximum_Velocity2.TabIndex = 16
        Me.Maximum_Velocity2.Text = "100000"
        Me.Maximum_Velocity2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity2
        '
        Me.Start_Velocity2.AcceptsReturn = True
        Me.Start_Velocity2.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity2.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity2.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity2.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity2.MaxLength = 0
        Me.Start_Velocity2.Name = "Start_Velocity2"
        Me.Start_Velocity2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity2.Size = New System.Drawing.Size(49, 21)
        Me.Start_Velocity2.TabIndex = 15
        Me.Start_Velocity2.Text = "50000"
        Me.Start_Velocity2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox8
        '
        Me.TextBox8.AcceptsReturn = True
        Me.TextBox8.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox8.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox8.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox8.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox8.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox8.Location = New System.Drawing.Point(8, 24)
        Me.TextBox8.MaxLength = 0
        Me.TextBox8.Name = "TextBox8"
        Me.TextBox8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox8.Size = New System.Drawing.Size(81, 14)
        Me.TextBox8.TabIndex = 14
        Me.TextBox8.Text = "Min_Vel2 :"
        '
        'TextBox9
        '
        Me.TextBox9.AcceptsReturn = True
        Me.TextBox9.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox9.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox9.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox9.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox9.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox9.Location = New System.Drawing.Point(8, 48)
        Me.TextBox9.MaxLength = 0
        Me.TextBox9.Name = "TextBox9"
        Me.TextBox9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox9.Size = New System.Drawing.Size(81, 14)
        Me.TextBox9.TabIndex = 13
        Me.TextBox9.Text = "Max_Vel2 :"
        '
        'GroupBox8
        '
        Me.GroupBox8.Controls.Add(Me.Distance3)
        Me.GroupBox8.Controls.Add(Me.Label5)
        Me.GroupBox8.Controls.Add(Me.T_Acceleration3)
        Me.GroupBox8.Controls.Add(Me.T_Deceleration3)
        Me.GroupBox8.Controls.Add(Me.TextBox13)
        Me.GroupBox8.Controls.Add(Me.TextBox14)
        Me.GroupBox8.Controls.Add(Me.Maximum_Velocity3)
        Me.GroupBox8.Controls.Add(Me.Start_Velocity3)
        Me.GroupBox8.Controls.Add(Me.TextBox17)
        Me.GroupBox8.Controls.Add(Me.TextBox18)
        Me.GroupBox8.Location = New System.Drawing.Point(352, 16)
        Me.GroupBox8.Name = "GroupBox8"
        Me.GroupBox8.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox8.TabIndex = 22
        Me.GroupBox8.TabStop = False
        Me.GroupBox8.Text = "Motion 3"
        '
        'Distance3
        '
        Me.Distance3.AcceptsReturn = True
        Me.Distance3.BackColor = System.Drawing.SystemColors.Window
        Me.Distance3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance3.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance3.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance3.Location = New System.Drawing.Point(96, 120)
        Me.Distance3.MaxLength = 0
        Me.Distance3.Name = "Distance3"
        Me.Distance3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance3.Size = New System.Drawing.Size(48, 21)
        Me.Distance3.TabIndex = 27
        Me.Distance3.Text = "100000"
        Me.Distance3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label5
        '
        Me.Label5.BackColor = System.Drawing.SystemColors.Control
        Me.Label5.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label5.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label5.Location = New System.Drawing.Point(8, 120)
        Me.Label5.Name = "Label5"
        Me.Label5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label5.Size = New System.Drawing.Size(88, 24)
        Me.Label5.TabIndex = 28
        Me.Label5.Text = "Distance3:"
        '
        'T_Acceleration3
        '
        Me.T_Acceleration3.AcceptsReturn = True
        Me.T_Acceleration3.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration3.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration3.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration3.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration3.MaxLength = 0
        Me.T_Acceleration3.Name = "T_Acceleration3"
        Me.T_Acceleration3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration3.Size = New System.Drawing.Size(49, 21)
        Me.T_Acceleration3.TabIndex = 20
        Me.T_Acceleration3.Text = "10000000"
        Me.T_Acceleration3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration3
        '
        Me.T_Deceleration3.AcceptsReturn = True
        Me.T_Deceleration3.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration3.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration3.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration3.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration3.MaxLength = 0
        Me.T_Deceleration3.Name = "T_Deceleration3"
        Me.T_Deceleration3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration3.Size = New System.Drawing.Size(49, 21)
        Me.T_Deceleration3.TabIndex = 19
        Me.T_Deceleration3.Text = "50000"
        Me.T_Deceleration3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox13
        '
        Me.TextBox13.AcceptsReturn = True
        Me.TextBox13.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox13.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox13.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox13.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox13.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox13.Location = New System.Drawing.Point(8, 72)
        Me.TextBox13.MaxLength = 0
        Me.TextBox13.Name = "TextBox13"
        Me.TextBox13.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox13.Size = New System.Drawing.Size(81, 14)
        Me.TextBox13.TabIndex = 18
        Me.TextBox13.Text = "Acc3:"
        '
        'TextBox14
        '
        Me.TextBox14.AcceptsReturn = True
        Me.TextBox14.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox14.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox14.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox14.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox14.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox14.Location = New System.Drawing.Point(8, 96)
        Me.TextBox14.MaxLength = 0
        Me.TextBox14.Name = "TextBox14"
        Me.TextBox14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox14.Size = New System.Drawing.Size(81, 14)
        Me.TextBox14.TabIndex = 17
        Me.TextBox14.Text = "Dec3:"
        '
        'Maximum_Velocity3
        '
        Me.Maximum_Velocity3.AcceptsReturn = True
        Me.Maximum_Velocity3.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity3.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity3.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity3.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity3.MaxLength = 0
        Me.Maximum_Velocity3.Name = "Maximum_Velocity3"
        Me.Maximum_Velocity3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity3.Size = New System.Drawing.Size(49, 21)
        Me.Maximum_Velocity3.TabIndex = 16
        Me.Maximum_Velocity3.Text = "50000"
        Me.Maximum_Velocity3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity3
        '
        Me.Start_Velocity3.AcceptsReturn = True
        Me.Start_Velocity3.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity3.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity3.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity3.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity3.MaxLength = 0
        Me.Start_Velocity3.Name = "Start_Velocity3"
        Me.Start_Velocity3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity3.Size = New System.Drawing.Size(49, 21)
        Me.Start_Velocity3.TabIndex = 15
        Me.Start_Velocity3.Text = "1000"
        Me.Start_Velocity3.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox17
        '
        Me.TextBox17.AcceptsReturn = True
        Me.TextBox17.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox17.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox17.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox17.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox17.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox17.Location = New System.Drawing.Point(8, 24)
        Me.TextBox17.MaxLength = 0
        Me.TextBox17.Name = "TextBox17"
        Me.TextBox17.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox17.Size = New System.Drawing.Size(81, 14)
        Me.TextBox17.TabIndex = 14
        Me.TextBox17.Text = "Min_Vel3 :"
        '
        'TextBox18
        '
        Me.TextBox18.AcceptsReturn = True
        Me.TextBox18.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox18.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox18.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox18.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox18.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox18.Location = New System.Drawing.Point(8, 48)
        Me.TextBox18.MaxLength = 0
        Me.TextBox18.Name = "TextBox18"
        Me.TextBox18.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox18.Size = New System.Drawing.Size(81, 14)
        Me.TextBox18.TabIndex = 13
        Me.TextBox18.Text = "Max_Vel3 :"
        '
        'AxDChart1
        '
        Me.AxDChart1.Enabled = True
        Me.AxDChart1.Location = New System.Drawing.Point(16, 200)
        Me.AxDChart1.Name = "AxDChart1"
        Me.AxDChart1.OcxState = CType(resources.GetObject("AxDChart1.OcxState"), System.Windows.Forms.AxHost.State)
        Me.AxDChart1.Size = New System.Drawing.Size(328, 224)
        Me.AxDChart1.TabIndex = 23
        '
        'txtStep
        '
        Me.txtStep.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.txtStep.Location = New System.Drawing.Point(624, 16)
        Me.txtStep.Name = "txtStep"
        Me.txtStep.Size = New System.Drawing.Size(48, 27)
        Me.txtStep.TabIndex = 28
        Me.txtStep.Text = "3"
        '
        'Label12
        '
        Me.Label12.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label12.Location = New System.Drawing.Point(576, 24)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(48, 23)
        Me.Label12.TabIndex = 27
        Me.Label12.Text = "Step:"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button2.Location = New System.Drawing.Point(576, 136)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(96, 32)
        Me.Button2.TabIndex = 31
        Me.Button2.Text = "Stop"
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 15)
        Me.ClientSize = New System.Drawing.Size(704, 446)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.txtStep)
        Me.Controls.Add(Me.Label12)
        Me.Controls.Add(Me.AxDChart1)
        Me.Controls.Add(Me.GroupBox8)
        Me.Controls.Add(Me.GroupBox7)
        Me.Controls.Add(Me.GroupBox6)
        Me.Controls.Add(Me.GroupBox5)
        Me.Controls.Add(Me.Button5)
        Me.Controls.Add(Me.Button4)
        Me.Controls.Add(Me.PTP_AXIS)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Name = "Form1"
        Me.Text = "8102_Continuous_Contour_motion"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.GroupBox4.ResumeLayout(False)
        Me.GroupBox4.PerformLayout()
        Me.GroupBox5.ResumeLayout(False)
        Me.GroupBox5.PerformLayout()
        Me.GroupBox6.ResumeLayout(False)
        Me.GroupBox6.PerformLayout()
        Me.GroupBox7.ResumeLayout(False)
        Me.GroupBox7.PerformLayout()
        Me.GroupBox8.ResumeLayout(False)
        Me.GroupBox8.PerformLayout()
        CType(Me.AxDChart1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

#End Region
    Dim CardNo As Integer
    Dim AxisNo As Integer
    Dim TotalCard As Integer

    Dim intStep As Integer = 0
    Dim reterr As Short

    Public MAX_CARDS_PCI_8102 As Short = 0
    Public CARDS_PCI_8102_Status(16) As Boolean

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim dblAxDChart1_YAxis_Max As Double = 0

        If CInt(Maximum_Velocity1.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity1.Text)
        If CInt(Maximum_Velocity2.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity2.Text)
        If CInt(Maximum_Velocity3.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity3.Text)
        
        AxDChart1.YAxis.Maximum = System.Math.Abs(CDbl(dblAxDChart1_YAxis_Max))
        AxDChart1.YAxis.Minimum = (-1) * System.Math.Abs(CDbl(dblAxDChart1_YAxis_Max))



        Dim i, j As Integer
        'B_8102_initial(TotalCard, 0)
        APS_initial(TotalCard, 0)

        TotalCard = CARDS_Status(TotalCard, MAX_CARDS_PCI_8102, CARDS_PCI_8102_Status)



        If TotalCard = 0 Then
            MsgBox("No PCI-8102 Found!")
            'B_8102_close()
            APS_close()
            End
        End If

        CardNo = 0

        'The config file is generated by Motion Creator
        'B_8102_config_from_file "8102.ini"

        For i = 0 To MAX_CARDS_PCI_8102

            If CARDS_PCI_8102_Status(i) = True Then


                Dim StartAxisID As Integer = 0
                Dim TotalAxisNum As Integer = 0


                APS_get_first_axisId(i, StartAxisID, TotalAxisNum)

                For j = StartAxisID To (StartAxisID + TotalAxisNum - 1) Step 1



                    APS_set_servo_on(j, 1)                  'servo ON

                    APS_set_axis_param(j, 0, 0)             'PEL/MEL input logic
                    APS_set_axis_param(j, 4, 0)             'Set PRA_ALM_LOGIC
                    APS_set_axis_param(j, 128, 3)           'Set PRA_PLS_IPT_MODE
                    APS_set_axis_param(j, 129, 5)           'Set PRA_PLS_OPT_MODE

                    APS_set_axis_param(j, 513, 1)           'Set PRA_FEEDBACK_SRC

                    'Set Single Move Parameter
                    APS_set_axis_param(j, 33, 1000000)      'Set Acceleration rate
                    APS_set_axis_param(j, 34, 1000000)      'Set Deceleration rate
                    APS_set_axis_param(j, 35, 0)            'Set Start velocity
                    APS_set_axis_param(j, 32, 1)            'Set S-Curve


                    'Set Home Move Parameter
                    APS_set_axis_param(j, 16, 0)             'Set Home mode (Home search 1st mode)

                    APS_set_axis_param(j, 21, 10000)         'Set Homing maximum Velocity (Unit:pulse/sec)

                    APS_set_axis_param(j, 25, 152)           'Set Homing leave home Velocity (Unit:pulse/sec)

                    APS_set_axis_param(j, 24, 0)             'Set Specify the EZ count up Value

                    APS_set_axis_param(j, 26, 100)           'Set Homing leave home distance.Specify ORG Offset (Unit:pulse)


                    'Set EMG logic
                    APS_set_axis_param(j, 561, 5)  'Set EMG input
                    APS_set_axis_param(j, 562, 0)  'Set EMG logic (0: Active high / 1: Active-Low)

                Next j

                'B_8102_set_pls_outmode(2 * i, 4)
                'B_8102_set_pls_iptmode(2 * i, 3, 0)
                'B_8102_set_feedback_src(2 * i, 1)

                'B_8102_set_pls_outmode((2 * i) + 1, 4)
                'B_8102_set_pls_iptmode((2 * i) + 1, 3, 0)
                'B_8102_set_feedback_src((2 * i) + 1, 1)

            End If

        Next i
    End Sub

    Private Sub Form1_Closing(ByVal sender As Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles MyBase.Closing
        'B_8102_close()

        APS_int_enable(CInt(CInt(PTP_AXIS.Text) / 2), 0)
        APS_close()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Dim CompTable(4000) As Double
        Dim i As Double
        Dim Err As Integer

        
        'For i = 0 To 1000
        'CompTable(i) = 30000.0# + 100.0# * i
        'Next

        AxisNo = CInt(PTP_AXIS.Text)


        '''B_8102_set_continuous_move(AxisNo, 1)
        APS_set_axis_param(AxisNo, &H250, 1) 'PRA_CONTI_MODE

        If CInt(txtStep.Text) > 0 Then
            intStep = 1

            reterr = 0
            'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance1.Text), CDbl(Start_Velocity1.Text), CDbl(Maximum_Velocity1.Text), CDbl(T_Acceleration1.Text), CDbl(T_Deceleration1.Text))

            APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity1.Text)) 'PRA_VS
            APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration1.Text)) 'PRA_ACC
            APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration1.Text)) 'PRA_DEC

            reterr = APS_relative_move(AxisNo, CInt(Distance1.Text), CInt(Maximum_Velocity1.Text))


            'MsgBox(reterr)

        End If


        If CInt(txtStep.Text) > 1 Then
            intStep = 2
            reterr = 0

            'reterr = B_8102_dwell_move(AxisNo, 2000)
            'MsgBox(reterr)

            'B_8102_start_tr_move(AxisNo, CDbl(Distance2.Text), CDbl(Start_Velocity2.Text), CDbl(Maximum_Velocity2.Text), CDbl(T_Acceleration2.Text), CDbl(T_Deceleration2.Text))

            APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity2.Text)) 'PRA_VS
            APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration2.Text)) 'PRA_ACC
            APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration2.Text)) 'PRA_DEC

            reterr = APS_relative_move(AxisNo, CInt(Distance2.Text), CInt(Maximum_Velocity2.Text))

        End If


        If CInt(txtStep.Text) > 2 Then
            intStep = 3
            'B_8102_start_tr_move(AxisNo, CDbl(Distance3.Text), CDbl(Start_Velocity3.Text), CDbl(Maximum_Velocity3.Text), CDbl(T_Acceleration3.Text), CDbl(T_Deceleration3.Text))

            APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity3.Text)) 'PRA_VS
            APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration3.Text)) 'PRA_ACC
            APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration3.Text)) 'PRA_DEC

            reterr = APS_relative_move(AxisNo, CInt(Distance3.Text), CInt(Maximum_Velocity3.Text))

        End If
        





    End Sub



    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click

        AxisNo = CInt(PTP_AXIS.Text)

        'B_8102_set_position(AxisNo, 0)
        'B_8102_set_command(AxisNo, 0)

        APS_set_command(AxisNo, 0)
        APS_set_position(AxisNo, 0)

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click

        AxisNo = CInt(PTP_AXIS.Text)

        'B_8102_emg_stop(AxisNo)

        APS_emg_stop(AxisNo)

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Dim i As Integer, CurPos As Double, CurSpeed As Double
        Dim io_sts As Integer, MOT_STS As Integer
        Dim Ckp As Double
        Dim PCMD As Long

        'For i = 2 * CardNo To 2 * CardNo + 1
        ' Display Next Compare Data
        'B_8102_check_compare_data(i, 5, Ckp)
        'CMPP(i).Text = Str(Ckp)
        'Next

        AxisNo = CInt(PTP_AXIS.Text)

        'B_8102_get_position(AxisNo, CurPos)
        APS_get_position(AxisNo, CurPos)
        Pos0.Text = Str(CurPos)

        'B_8102_get_current_speed(AxisNo, CurSpeed)
        APS_get_command_velocity(AxisNo, CurSpeed)
        Speed0.Text = Str(CurSpeed)

        AxDChart1.PlotChart(CurSpeed)

        'B_8102_get_io_status(AxisNo, io_sts)
        io_sts = APS_motion_io_status(AxisNo)
        IOSts0.Text = Hex(io_sts)

        'MOT_STS = B_8102_motion_done(AxisNo)
        MOT_STS = APS_motion_status(AxisNo)
        MotSts0.Text = Str(MOT_STS)

        'B_8102_get_command(AxisNo, PCMD)
        APS_get_command(AxisNo, PCMD)
        CMD0.Text = Str(PCMD)
                
            
    End Sub

    Public Function CARDS_Status(ByVal intCARDS_PCI_Status As Short, ByRef Max_CARDS_PCI_Status As Short, ByRef CARDS_PCI_Status() As Boolean) As Short

        'intCARDS_PCI_Status = MAX_CARDS_PCI_8102
        'CARDS_PCI_Status = CARDS_PCI_8102_Status



        Dim Total_CARDS_PCI_Status As Short = 0

        Dim N As Short
        'Dim y As String

        For N = 0 To 15
            If intCARDS_PCI_Status And 2 ^ N Then
                'y = "1" & y
                CARDS_PCI_Status(N) = True
                Total_CARDS_PCI_Status = Total_CARDS_PCI_Status + 1
                Max_CARDS_PCI_Status = N + 1
            Else
                'y = "0" & y
                CARDS_PCI_Status(N) = False
            End If

        Next


        Return Total_CARDS_PCI_Status


        ''''''''''''''''''''''''''''''''''''''''''''''''''''
    End Function



    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        '''B_8102_set_continuous_move(AxisNo, 0)
        APS_set_axis_param(AxisNo, &H250, 0) 'PRA_CONTI_MODE
    End Sub
End Class
