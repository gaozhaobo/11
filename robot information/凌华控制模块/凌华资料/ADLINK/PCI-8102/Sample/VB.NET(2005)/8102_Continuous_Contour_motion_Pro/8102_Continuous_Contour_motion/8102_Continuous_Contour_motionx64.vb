Imports System.Threading.Thread



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
    Friend WithEvents txtStep As System.Windows.Forms.TextBox
    Public WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents GroupBox9 As System.Windows.Forms.GroupBox
    Public WithEvents Label7 As System.Windows.Forms.Label
    Public WithEvents TextBox6 As System.Windows.Forms.TextBox
    Public WithEvents TextBox7 As System.Windows.Forms.TextBox
    Public WithEvents TextBox12 As System.Windows.Forms.TextBox
    Public WithEvents TextBox15 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox10 As System.Windows.Forms.GroupBox
    Public WithEvents Label10 As System.Windows.Forms.Label
    Public WithEvents TextBox21 As System.Windows.Forms.TextBox
    Public WithEvents TextBox22 As System.Windows.Forms.TextBox
    Public WithEvents TextBox25 As System.Windows.Forms.TextBox
    Public WithEvents TextBox26 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox11 As System.Windows.Forms.GroupBox
    Public WithEvents Label13 As System.Windows.Forms.Label
    Public WithEvents TextBox30 As System.Windows.Forms.TextBox
    Public WithEvents TextBox31 As System.Windows.Forms.TextBox
    Public WithEvents TextBox34 As System.Windows.Forms.TextBox
    Public WithEvents TextBox35 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox13 As System.Windows.Forms.GroupBox
    Public WithEvents Label15 As System.Windows.Forms.Label
    Public WithEvents TextBox48 As System.Windows.Forms.TextBox
    Public WithEvents TextBox49 As System.Windows.Forms.TextBox
    Public WithEvents TextBox52 As System.Windows.Forms.TextBox
    Public WithEvents TextBox53 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox14 As System.Windows.Forms.GroupBox
    Public WithEvents Label16 As System.Windows.Forms.Label
    Public WithEvents TextBox57 As System.Windows.Forms.TextBox
    Public WithEvents TextBox58 As System.Windows.Forms.TextBox
    Public WithEvents TextBox61 As System.Windows.Forms.TextBox
    Public WithEvents TextBox62 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox12 As System.Windows.Forms.GroupBox
    Public WithEvents Label14 As System.Windows.Forms.Label
    Public WithEvents TextBox39 As System.Windows.Forms.TextBox
    Public WithEvents TextBox40 As System.Windows.Forms.TextBox
    Public WithEvents TextBox43 As System.Windows.Forms.TextBox
    Public WithEvents TextBox44 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox15 As System.Windows.Forms.GroupBox
    Public WithEvents Label17 As System.Windows.Forms.Label
    Public WithEvents TextBox66 As System.Windows.Forms.TextBox
    Public WithEvents TextBox67 As System.Windows.Forms.TextBox
    Public WithEvents TextBox70 As System.Windows.Forms.TextBox
    Public WithEvents TextBox71 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity8 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity8 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity7 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity7 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity6 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity6 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity5 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity5 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity4 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity4 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity10 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity10 As System.Windows.Forms.TextBox
    Public WithEvents Maximum_Velocity9 As System.Windows.Forms.TextBox
    Public WithEvents Start_Velocity9 As System.Windows.Forms.TextBox
    Public WithEvents Distance8 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration8 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration8 As System.Windows.Forms.TextBox
    Public WithEvents Distance7 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration7 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration7 As System.Windows.Forms.TextBox
    Public WithEvents Distance6 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration6 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration6 As System.Windows.Forms.TextBox
    Public WithEvents Distance5 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration5 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration5 As System.Windows.Forms.TextBox
    Public WithEvents Distance4 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration4 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration4 As System.Windows.Forms.TextBox
    Public WithEvents Distance10 As System.Windows.Forms.TextBox
    Public WithEvents Distance9 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration9 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration9 As System.Windows.Forms.TextBox
    Public WithEvents T_Acceleration10 As System.Windows.Forms.TextBox
    Public WithEvents T_Deceleration10 As System.Windows.Forms.TextBox
    Friend WithEvents RunStep As System.Windows.Forms.TextBox
    Public WithEvents Label18 As System.Windows.Forms.Label
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
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
        Me.txtStep = New System.Windows.Forms.TextBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.Button2 = New System.Windows.Forms.Button
        Me.GroupBox9 = New System.Windows.Forms.GroupBox
        Me.Distance8 = New System.Windows.Forms.TextBox
        Me.Label7 = New System.Windows.Forms.Label
        Me.T_Acceleration8 = New System.Windows.Forms.TextBox
        Me.T_Deceleration8 = New System.Windows.Forms.TextBox
        Me.TextBox6 = New System.Windows.Forms.TextBox
        Me.TextBox7 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity8 = New System.Windows.Forms.TextBox
        Me.Start_Velocity8 = New System.Windows.Forms.TextBox
        Me.TextBox12 = New System.Windows.Forms.TextBox
        Me.TextBox15 = New System.Windows.Forms.TextBox
        Me.GroupBox10 = New System.Windows.Forms.GroupBox
        Me.Distance7 = New System.Windows.Forms.TextBox
        Me.Label10 = New System.Windows.Forms.Label
        Me.T_Acceleration7 = New System.Windows.Forms.TextBox
        Me.T_Deceleration7 = New System.Windows.Forms.TextBox
        Me.TextBox21 = New System.Windows.Forms.TextBox
        Me.TextBox22 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity7 = New System.Windows.Forms.TextBox
        Me.Start_Velocity7 = New System.Windows.Forms.TextBox
        Me.TextBox25 = New System.Windows.Forms.TextBox
        Me.TextBox26 = New System.Windows.Forms.TextBox
        Me.GroupBox11 = New System.Windows.Forms.GroupBox
        Me.Distance6 = New System.Windows.Forms.TextBox
        Me.Label13 = New System.Windows.Forms.Label
        Me.T_Acceleration6 = New System.Windows.Forms.TextBox
        Me.T_Deceleration6 = New System.Windows.Forms.TextBox
        Me.TextBox30 = New System.Windows.Forms.TextBox
        Me.TextBox31 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity6 = New System.Windows.Forms.TextBox
        Me.Start_Velocity6 = New System.Windows.Forms.TextBox
        Me.TextBox34 = New System.Windows.Forms.TextBox
        Me.TextBox35 = New System.Windows.Forms.TextBox
        Me.GroupBox13 = New System.Windows.Forms.GroupBox
        Me.Distance5 = New System.Windows.Forms.TextBox
        Me.Label15 = New System.Windows.Forms.Label
        Me.T_Acceleration5 = New System.Windows.Forms.TextBox
        Me.T_Deceleration5 = New System.Windows.Forms.TextBox
        Me.TextBox48 = New System.Windows.Forms.TextBox
        Me.TextBox49 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity5 = New System.Windows.Forms.TextBox
        Me.Start_Velocity5 = New System.Windows.Forms.TextBox
        Me.TextBox52 = New System.Windows.Forms.TextBox
        Me.TextBox53 = New System.Windows.Forms.TextBox
        Me.GroupBox14 = New System.Windows.Forms.GroupBox
        Me.Distance4 = New System.Windows.Forms.TextBox
        Me.Label16 = New System.Windows.Forms.Label
        Me.T_Acceleration4 = New System.Windows.Forms.TextBox
        Me.T_Deceleration4 = New System.Windows.Forms.TextBox
        Me.TextBox57 = New System.Windows.Forms.TextBox
        Me.TextBox58 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity4 = New System.Windows.Forms.TextBox
        Me.Start_Velocity4 = New System.Windows.Forms.TextBox
        Me.TextBox61 = New System.Windows.Forms.TextBox
        Me.TextBox62 = New System.Windows.Forms.TextBox
        Me.GroupBox12 = New System.Windows.Forms.GroupBox
        Me.Distance10 = New System.Windows.Forms.TextBox
        Me.Label14 = New System.Windows.Forms.Label
        Me.T_Acceleration10 = New System.Windows.Forms.TextBox
        Me.T_Deceleration10 = New System.Windows.Forms.TextBox
        Me.TextBox39 = New System.Windows.Forms.TextBox
        Me.TextBox40 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity10 = New System.Windows.Forms.TextBox
        Me.Start_Velocity10 = New System.Windows.Forms.TextBox
        Me.TextBox43 = New System.Windows.Forms.TextBox
        Me.TextBox44 = New System.Windows.Forms.TextBox
        Me.GroupBox15 = New System.Windows.Forms.GroupBox
        Me.Distance9 = New System.Windows.Forms.TextBox
        Me.Label17 = New System.Windows.Forms.Label
        Me.T_Acceleration9 = New System.Windows.Forms.TextBox
        Me.T_Deceleration9 = New System.Windows.Forms.TextBox
        Me.TextBox66 = New System.Windows.Forms.TextBox
        Me.TextBox67 = New System.Windows.Forms.TextBox
        Me.Maximum_Velocity9 = New System.Windows.Forms.TextBox
        Me.Start_Velocity9 = New System.Windows.Forms.TextBox
        Me.TextBox70 = New System.Windows.Forms.TextBox
        Me.TextBox71 = New System.Windows.Forms.TextBox
        Me.RunStep = New System.Windows.Forms.TextBox
        Me.Label18 = New System.Windows.Forms.Label
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox5.SuspendLayout()
        Me.GroupBox6.SuspendLayout()
        Me.GroupBox7.SuspendLayout()
        Me.GroupBox8.SuspendLayout()
        Me.GroupBox9.SuspendLayout()
        Me.GroupBox10.SuspendLayout()
        Me.GroupBox11.SuspendLayout()
        Me.GroupBox13.SuspendLayout()
        Me.GroupBox14.SuspendLayout()
        Me.GroupBox12.SuspendLayout()
        Me.GroupBox15.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Pos0)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(640, 360)
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
        Me.GroupBox2.Location = New System.Drawing.Point(808, 360)
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
        Me.GroupBox3.Location = New System.Drawing.Point(640, 440)
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
        Me.GroupBox4.Location = New System.Drawing.Point(808, 440)
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
        Me.Button1.Location = New System.Drawing.Point(864, 280)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(96, 32)
        Me.Button1.TabIndex = 4
        Me.Button1.Text = "Start"
        '
        'PTP_AXIS
        '
        Me.PTP_AXIS.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.PTP_AXIS.Location = New System.Drawing.Point(912, 232)
        Me.PTP_AXIS.Name = "PTP_AXIS"
        Me.PTP_AXIS.Size = New System.Drawing.Size(48, 27)
        Me.PTP_AXIS.TabIndex = 8
        Me.PTP_AXIS.Text = "0"
        '
        'Label9
        '
        Me.Label9.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label9.Location = New System.Drawing.Point(864, 240)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(48, 23)
        Me.Label9.TabIndex = 7
        Me.Label9.Text = "Axis :"
        '
        'Button4
        '
        Me.Button4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button4.Location = New System.Drawing.Point(816, 536)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(72, 56)
        Me.Button4.TabIndex = 17
        Me.Button4.Text = "Reset Position"
        '
        'Button5
        '
        Me.Button5.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button5.Location = New System.Drawing.Point(896, 536)
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
        Me.GroupBox5.Location = New System.Drawing.Point(640, 520)
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
        Me.Distance1.Size = New System.Drawing.Size(48, 24)
        Me.Distance1.TabIndex = 27
        Me.Distance1.Text = "200"
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
        Me.T_Acceleration1.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration1.TabIndex = 20
        Me.T_Acceleration1.Text = "0.5"
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
        Me.T_Deceleration1.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration1.TabIndex = 19
        Me.T_Deceleration1.Text = "0"
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
        Me.Text24.Size = New System.Drawing.Size(81, 23)
        Me.Text24.TabIndex = 18
        Me.Text24.Text = "Tacc1:"
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
        Me.Text25.Size = New System.Drawing.Size(81, 23)
        Me.Text25.TabIndex = 17
        Me.Text25.Text = "Tdec1:"
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
        Me.Maximum_Velocity1.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity1.TabIndex = 16
        Me.Maximum_Velocity1.Text = "200"
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
        Me.Start_Velocity1.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity1.TabIndex = 15
        Me.Start_Velocity1.Text = "10"
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
        Me.Text21.Size = New System.Drawing.Size(81, 23)
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
        Me.Text22.Size = New System.Drawing.Size(81, 23)
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
        Me.Distance2.Size = New System.Drawing.Size(48, 24)
        Me.Distance2.TabIndex = 27
        Me.Distance2.Text = "400"
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
        Me.T_Acceleration2.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration2.TabIndex = 20
        Me.T_Acceleration2.Text = "0.5"
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
        Me.T_Deceleration2.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration2.TabIndex = 19
        Me.T_Deceleration2.Text = "0"
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
        Me.TextBox4.Size = New System.Drawing.Size(81, 23)
        Me.TextBox4.TabIndex = 18
        Me.TextBox4.Text = "Tacc2:"
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
        Me.TextBox5.Size = New System.Drawing.Size(81, 23)
        Me.TextBox5.TabIndex = 17
        Me.TextBox5.Text = "Tdec2:"
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
        Me.Maximum_Velocity2.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity2.TabIndex = 16
        Me.Maximum_Velocity2.Text = "400"
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
        Me.Start_Velocity2.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity2.TabIndex = 15
        Me.Start_Velocity2.Text = "200"
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
        Me.TextBox8.Size = New System.Drawing.Size(81, 23)
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
        Me.TextBox9.Size = New System.Drawing.Size(81, 23)
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
        Me.Distance3.Size = New System.Drawing.Size(48, 24)
        Me.Distance3.TabIndex = 27
        Me.Distance3.Text = "600"
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
        Me.T_Acceleration3.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration3.TabIndex = 20
        Me.T_Acceleration3.Text = "0.5"
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
        Me.T_Deceleration3.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration3.TabIndex = 19
        Me.T_Deceleration3.Text = "0"
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
        Me.TextBox13.Size = New System.Drawing.Size(81, 23)
        Me.TextBox13.TabIndex = 18
        Me.TextBox13.Text = "Tacc3:"
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
        Me.TextBox14.Size = New System.Drawing.Size(81, 23)
        Me.TextBox14.TabIndex = 17
        Me.TextBox14.Text = "Tdec3:"
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
        Me.Maximum_Velocity3.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity3.TabIndex = 16
        Me.Maximum_Velocity3.Text = "600"
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
        Me.Start_Velocity3.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity3.TabIndex = 15
        Me.Start_Velocity3.Text = "400"
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
        Me.TextBox17.Size = New System.Drawing.Size(81, 23)
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
        Me.TextBox18.Size = New System.Drawing.Size(81, 23)
        Me.TextBox18.TabIndex = 13
        Me.TextBox18.Text = "Max_Vel3 :"
        '
        'txtStep
        '
        Me.txtStep.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.txtStep.Location = New System.Drawing.Point(912, 192)
        Me.txtStep.Name = "txtStep"
        Me.txtStep.Size = New System.Drawing.Size(48, 27)
        Me.txtStep.TabIndex = 28
        Me.txtStep.Text = "10"
        '
        'Label12
        '
        Me.Label12.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label12.Location = New System.Drawing.Point(864, 200)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(48, 23)
        Me.Label12.TabIndex = 27
        Me.Label12.Text = "Step:"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button2.Location = New System.Drawing.Point(864, 320)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(96, 32)
        Me.Button2.TabIndex = 31
        Me.Button2.Text = "Stop"
        '
        'GroupBox9
        '
        Me.GroupBox9.Controls.Add(Me.Distance8)
        Me.GroupBox9.Controls.Add(Me.Label7)
        Me.GroupBox9.Controls.Add(Me.T_Acceleration8)
        Me.GroupBox9.Controls.Add(Me.T_Deceleration8)
        Me.GroupBox9.Controls.Add(Me.TextBox6)
        Me.GroupBox9.Controls.Add(Me.TextBox7)
        Me.GroupBox9.Controls.Add(Me.Maximum_Velocity8)
        Me.GroupBox9.Controls.Add(Me.Start_Velocity8)
        Me.GroupBox9.Controls.Add(Me.TextBox12)
        Me.GroupBox9.Controls.Add(Me.TextBox15)
        Me.GroupBox9.Location = New System.Drawing.Point(352, 192)
        Me.GroupBox9.Name = "GroupBox9"
        Me.GroupBox9.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox9.TabIndex = 34
        Me.GroupBox9.TabStop = False
        Me.GroupBox9.Text = "Motion 8"
        '
        'Distance8
        '
        Me.Distance8.AcceptsReturn = True
        Me.Distance8.BackColor = System.Drawing.SystemColors.Window
        Me.Distance8.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance8.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance8.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance8.Location = New System.Drawing.Point(96, 120)
        Me.Distance8.MaxLength = 0
        Me.Distance8.Name = "Distance8"
        Me.Distance8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance8.Size = New System.Drawing.Size(48, 24)
        Me.Distance8.TabIndex = 27
        Me.Distance8.Text = "600"
        Me.Distance8.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label7
        '
        Me.Label7.BackColor = System.Drawing.SystemColors.Control
        Me.Label7.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label7.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label7.Location = New System.Drawing.Point(8, 120)
        Me.Label7.Name = "Label7"
        Me.Label7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label7.Size = New System.Drawing.Size(88, 24)
        Me.Label7.TabIndex = 28
        Me.Label7.Text = "Distance8:"
        '
        'T_Acceleration8
        '
        Me.T_Acceleration8.AcceptsReturn = True
        Me.T_Acceleration8.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration8.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration8.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration8.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration8.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration8.MaxLength = 0
        Me.T_Acceleration8.Name = "T_Acceleration8"
        Me.T_Acceleration8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration8.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration8.TabIndex = 20
        Me.T_Acceleration8.Text = "0"
        Me.T_Acceleration8.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration8
        '
        Me.T_Deceleration8.AcceptsReturn = True
        Me.T_Deceleration8.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration8.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration8.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration8.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration8.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration8.MaxLength = 0
        Me.T_Deceleration8.Name = "T_Deceleration8"
        Me.T_Deceleration8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration8.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration8.TabIndex = 19
        Me.T_Deceleration8.Text = "0.5"
        Me.T_Deceleration8.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox6
        '
        Me.TextBox6.AcceptsReturn = True
        Me.TextBox6.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox6.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox6.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox6.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox6.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox6.Location = New System.Drawing.Point(8, 72)
        Me.TextBox6.MaxLength = 0
        Me.TextBox6.Name = "TextBox6"
        Me.TextBox6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox6.Size = New System.Drawing.Size(81, 23)
        Me.TextBox6.TabIndex = 18
        Me.TextBox6.Text = "Tacc8:"
        '
        'TextBox7
        '
        Me.TextBox7.AcceptsReturn = True
        Me.TextBox7.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox7.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox7.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox7.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox7.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox7.Location = New System.Drawing.Point(8, 96)
        Me.TextBox7.MaxLength = 0
        Me.TextBox7.Name = "TextBox7"
        Me.TextBox7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox7.Size = New System.Drawing.Size(81, 23)
        Me.TextBox7.TabIndex = 17
        Me.TextBox7.Text = "Tdec8:"
        '
        'Maximum_Velocity8
        '
        Me.Maximum_Velocity8.AcceptsReturn = True
        Me.Maximum_Velocity8.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity8.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity8.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity8.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity8.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity8.MaxLength = 0
        Me.Maximum_Velocity8.Name = "Maximum_Velocity8"
        Me.Maximum_Velocity8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity8.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity8.TabIndex = 16
        Me.Maximum_Velocity8.Text = "500"
        Me.Maximum_Velocity8.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity8
        '
        Me.Start_Velocity8.AcceptsReturn = True
        Me.Start_Velocity8.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity8.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity8.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity8.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity8.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity8.MaxLength = 0
        Me.Start_Velocity8.Name = "Start_Velocity8"
        Me.Start_Velocity8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity8.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity8.TabIndex = 15
        Me.Start_Velocity8.Text = "300"
        Me.Start_Velocity8.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox12
        '
        Me.TextBox12.AcceptsReturn = True
        Me.TextBox12.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox12.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox12.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox12.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox12.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox12.Location = New System.Drawing.Point(8, 24)
        Me.TextBox12.MaxLength = 0
        Me.TextBox12.Name = "TextBox12"
        Me.TextBox12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox12.Size = New System.Drawing.Size(81, 23)
        Me.TextBox12.TabIndex = 14
        Me.TextBox12.Text = "Min_Vel8 :"
        '
        'TextBox15
        '
        Me.TextBox15.AcceptsReturn = True
        Me.TextBox15.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox15.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox15.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox15.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox15.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox15.Location = New System.Drawing.Point(8, 48)
        Me.TextBox15.MaxLength = 0
        Me.TextBox15.Name = "TextBox15"
        Me.TextBox15.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox15.Size = New System.Drawing.Size(81, 23)
        Me.TextBox15.TabIndex = 13
        Me.TextBox15.Text = "Max_Vel8 :"
        '
        'GroupBox10
        '
        Me.GroupBox10.Controls.Add(Me.Distance7)
        Me.GroupBox10.Controls.Add(Me.Label10)
        Me.GroupBox10.Controls.Add(Me.T_Acceleration7)
        Me.GroupBox10.Controls.Add(Me.T_Deceleration7)
        Me.GroupBox10.Controls.Add(Me.TextBox21)
        Me.GroupBox10.Controls.Add(Me.TextBox22)
        Me.GroupBox10.Controls.Add(Me.Maximum_Velocity7)
        Me.GroupBox10.Controls.Add(Me.Start_Velocity7)
        Me.GroupBox10.Controls.Add(Me.TextBox25)
        Me.GroupBox10.Controls.Add(Me.TextBox26)
        Me.GroupBox10.Location = New System.Drawing.Point(184, 192)
        Me.GroupBox10.Name = "GroupBox10"
        Me.GroupBox10.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox10.TabIndex = 33
        Me.GroupBox10.TabStop = False
        Me.GroupBox10.Text = "Motion 7"
        '
        'Distance7
        '
        Me.Distance7.AcceptsReturn = True
        Me.Distance7.BackColor = System.Drawing.SystemColors.Window
        Me.Distance7.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance7.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance7.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance7.Location = New System.Drawing.Point(96, 120)
        Me.Distance7.MaxLength = 0
        Me.Distance7.Name = "Distance7"
        Me.Distance7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance7.Size = New System.Drawing.Size(48, 24)
        Me.Distance7.TabIndex = 27
        Me.Distance7.Text = "800"
        Me.Distance7.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label10
        '
        Me.Label10.BackColor = System.Drawing.SystemColors.Control
        Me.Label10.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label10.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label10.Location = New System.Drawing.Point(8, 120)
        Me.Label10.Name = "Label10"
        Me.Label10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label10.Size = New System.Drawing.Size(88, 24)
        Me.Label10.TabIndex = 28
        Me.Label10.Text = "Distance7:"
        '
        'T_Acceleration7
        '
        Me.T_Acceleration7.AcceptsReturn = True
        Me.T_Acceleration7.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration7.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration7.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration7.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration7.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration7.MaxLength = 0
        Me.T_Acceleration7.Name = "T_Acceleration7"
        Me.T_Acceleration7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration7.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration7.TabIndex = 20
        Me.T_Acceleration7.Text = "0"
        Me.T_Acceleration7.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration7
        '
        Me.T_Deceleration7.AcceptsReturn = True
        Me.T_Deceleration7.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration7.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration7.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration7.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration7.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration7.MaxLength = 0
        Me.T_Deceleration7.Name = "T_Deceleration7"
        Me.T_Deceleration7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration7.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration7.TabIndex = 19
        Me.T_Deceleration7.Text = "0.5"
        Me.T_Deceleration7.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox21
        '
        Me.TextBox21.AcceptsReturn = True
        Me.TextBox21.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox21.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox21.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox21.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox21.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox21.Location = New System.Drawing.Point(8, 72)
        Me.TextBox21.MaxLength = 0
        Me.TextBox21.Name = "TextBox21"
        Me.TextBox21.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox21.Size = New System.Drawing.Size(81, 23)
        Me.TextBox21.TabIndex = 18
        Me.TextBox21.Text = "Tacc7:"
        '
        'TextBox22
        '
        Me.TextBox22.AcceptsReturn = True
        Me.TextBox22.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox22.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox22.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox22.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox22.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox22.Location = New System.Drawing.Point(8, 96)
        Me.TextBox22.MaxLength = 0
        Me.TextBox22.Name = "TextBox22"
        Me.TextBox22.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox22.Size = New System.Drawing.Size(81, 23)
        Me.TextBox22.TabIndex = 17
        Me.TextBox22.Text = "Tdec7:"
        '
        'Maximum_Velocity7
        '
        Me.Maximum_Velocity7.AcceptsReturn = True
        Me.Maximum_Velocity7.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity7.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity7.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity7.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity7.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity7.MaxLength = 0
        Me.Maximum_Velocity7.Name = "Maximum_Velocity7"
        Me.Maximum_Velocity7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity7.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity7.TabIndex = 16
        Me.Maximum_Velocity7.Text = "700"
        Me.Maximum_Velocity7.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity7
        '
        Me.Start_Velocity7.AcceptsReturn = True
        Me.Start_Velocity7.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity7.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity7.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity7.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity7.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity7.MaxLength = 0
        Me.Start_Velocity7.Name = "Start_Velocity7"
        Me.Start_Velocity7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity7.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity7.TabIndex = 15
        Me.Start_Velocity7.Text = "500"
        Me.Start_Velocity7.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox25
        '
        Me.TextBox25.AcceptsReturn = True
        Me.TextBox25.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox25.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox25.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox25.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox25.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox25.Location = New System.Drawing.Point(8, 24)
        Me.TextBox25.MaxLength = 0
        Me.TextBox25.Name = "TextBox25"
        Me.TextBox25.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox25.Size = New System.Drawing.Size(81, 23)
        Me.TextBox25.TabIndex = 14
        Me.TextBox25.Text = "Min_Vel7 :"
        '
        'TextBox26
        '
        Me.TextBox26.AcceptsReturn = True
        Me.TextBox26.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox26.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox26.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox26.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox26.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox26.Location = New System.Drawing.Point(8, 48)
        Me.TextBox26.MaxLength = 0
        Me.TextBox26.Name = "TextBox26"
        Me.TextBox26.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox26.Size = New System.Drawing.Size(81, 23)
        Me.TextBox26.TabIndex = 13
        Me.TextBox26.Text = "Max_Vel7 :"
        '
        'GroupBox11
        '
        Me.GroupBox11.Controls.Add(Me.Distance6)
        Me.GroupBox11.Controls.Add(Me.Label13)
        Me.GroupBox11.Controls.Add(Me.T_Acceleration6)
        Me.GroupBox11.Controls.Add(Me.T_Deceleration6)
        Me.GroupBox11.Controls.Add(Me.TextBox30)
        Me.GroupBox11.Controls.Add(Me.TextBox31)
        Me.GroupBox11.Controls.Add(Me.Maximum_Velocity6)
        Me.GroupBox11.Controls.Add(Me.Start_Velocity6)
        Me.GroupBox11.Controls.Add(Me.TextBox34)
        Me.GroupBox11.Controls.Add(Me.TextBox35)
        Me.GroupBox11.Location = New System.Drawing.Point(16, 192)
        Me.GroupBox11.Name = "GroupBox11"
        Me.GroupBox11.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox11.TabIndex = 32
        Me.GroupBox11.TabStop = False
        Me.GroupBox11.Text = "Motion 6"
        '
        'Distance6
        '
        Me.Distance6.AcceptsReturn = True
        Me.Distance6.BackColor = System.Drawing.SystemColors.Window
        Me.Distance6.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance6.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance6.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance6.Location = New System.Drawing.Point(96, 120)
        Me.Distance6.MaxLength = 0
        Me.Distance6.Name = "Distance6"
        Me.Distance6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance6.Size = New System.Drawing.Size(48, 24)
        Me.Distance6.TabIndex = 27
        Me.Distance6.Text = "1000"
        Me.Distance6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label13
        '
        Me.Label13.BackColor = System.Drawing.SystemColors.Control
        Me.Label13.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label13.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label13.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label13.Location = New System.Drawing.Point(8, 120)
        Me.Label13.Name = "Label13"
        Me.Label13.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label13.Size = New System.Drawing.Size(88, 24)
        Me.Label13.TabIndex = 28
        Me.Label13.Text = "Distance6:"
        '
        'T_Acceleration6
        '
        Me.T_Acceleration6.AcceptsReturn = True
        Me.T_Acceleration6.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration6.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration6.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration6.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration6.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration6.MaxLength = 0
        Me.T_Acceleration6.Name = "T_Acceleration6"
        Me.T_Acceleration6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration6.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration6.TabIndex = 20
        Me.T_Acceleration6.Text = "0"
        Me.T_Acceleration6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration6
        '
        Me.T_Deceleration6.AcceptsReturn = True
        Me.T_Deceleration6.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration6.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration6.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration6.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration6.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration6.MaxLength = 0
        Me.T_Deceleration6.Name = "T_Deceleration6"
        Me.T_Deceleration6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration6.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration6.TabIndex = 19
        Me.T_Deceleration6.Text = "0.5"
        Me.T_Deceleration6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox30
        '
        Me.TextBox30.AcceptsReturn = True
        Me.TextBox30.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox30.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox30.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox30.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox30.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox30.Location = New System.Drawing.Point(8, 72)
        Me.TextBox30.MaxLength = 0
        Me.TextBox30.Name = "TextBox30"
        Me.TextBox30.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox30.Size = New System.Drawing.Size(81, 23)
        Me.TextBox30.TabIndex = 18
        Me.TextBox30.Text = "Tacc6:"
        '
        'TextBox31
        '
        Me.TextBox31.AcceptsReturn = True
        Me.TextBox31.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox31.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox31.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox31.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox31.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox31.Location = New System.Drawing.Point(8, 96)
        Me.TextBox31.MaxLength = 0
        Me.TextBox31.Name = "TextBox31"
        Me.TextBox31.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox31.Size = New System.Drawing.Size(81, 23)
        Me.TextBox31.TabIndex = 17
        Me.TextBox31.Text = "Tdec6:"
        '
        'Maximum_Velocity6
        '
        Me.Maximum_Velocity6.AcceptsReturn = True
        Me.Maximum_Velocity6.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity6.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity6.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity6.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity6.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity6.MaxLength = 0
        Me.Maximum_Velocity6.Name = "Maximum_Velocity6"
        Me.Maximum_Velocity6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity6.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity6.TabIndex = 16
        Me.Maximum_Velocity6.Text = "1000"
        Me.Maximum_Velocity6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity6
        '
        Me.Start_Velocity6.AcceptsReturn = True
        Me.Start_Velocity6.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity6.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity6.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity6.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity6.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity6.MaxLength = 0
        Me.Start_Velocity6.Name = "Start_Velocity6"
        Me.Start_Velocity6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity6.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity6.TabIndex = 15
        Me.Start_Velocity6.Text = "700"
        Me.Start_Velocity6.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox34
        '
        Me.TextBox34.AcceptsReturn = True
        Me.TextBox34.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox34.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox34.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox34.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox34.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox34.Location = New System.Drawing.Point(8, 24)
        Me.TextBox34.MaxLength = 0
        Me.TextBox34.Name = "TextBox34"
        Me.TextBox34.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox34.Size = New System.Drawing.Size(81, 23)
        Me.TextBox34.TabIndex = 14
        Me.TextBox34.Text = "Min_Vel6 :"
        '
        'TextBox35
        '
        Me.TextBox35.AcceptsReturn = True
        Me.TextBox35.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox35.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox35.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox35.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox35.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox35.Location = New System.Drawing.Point(8, 48)
        Me.TextBox35.MaxLength = 0
        Me.TextBox35.Name = "TextBox35"
        Me.TextBox35.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox35.Size = New System.Drawing.Size(81, 23)
        Me.TextBox35.TabIndex = 13
        Me.TextBox35.Text = "Max_Vel6 :"
        '
        'GroupBox13
        '
        Me.GroupBox13.Controls.Add(Me.Distance5)
        Me.GroupBox13.Controls.Add(Me.Label15)
        Me.GroupBox13.Controls.Add(Me.T_Acceleration5)
        Me.GroupBox13.Controls.Add(Me.T_Deceleration5)
        Me.GroupBox13.Controls.Add(Me.TextBox48)
        Me.GroupBox13.Controls.Add(Me.TextBox49)
        Me.GroupBox13.Controls.Add(Me.Maximum_Velocity5)
        Me.GroupBox13.Controls.Add(Me.Start_Velocity5)
        Me.GroupBox13.Controls.Add(Me.TextBox52)
        Me.GroupBox13.Controls.Add(Me.TextBox53)
        Me.GroupBox13.Location = New System.Drawing.Point(688, 16)
        Me.GroupBox13.Name = "GroupBox13"
        Me.GroupBox13.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox13.TabIndex = 36
        Me.GroupBox13.TabStop = False
        Me.GroupBox13.Text = "Motion 5"
        '
        'Distance5
        '
        Me.Distance5.AcceptsReturn = True
        Me.Distance5.BackColor = System.Drawing.SystemColors.Window
        Me.Distance5.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance5.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance5.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance5.Location = New System.Drawing.Point(96, 120)
        Me.Distance5.MaxLength = 0
        Me.Distance5.Name = "Distance5"
        Me.Distance5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance5.Size = New System.Drawing.Size(48, 24)
        Me.Distance5.TabIndex = 27
        Me.Distance5.Text = "1000"
        Me.Distance5.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label15
        '
        Me.Label15.BackColor = System.Drawing.SystemColors.Control
        Me.Label15.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label15.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label15.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.Location = New System.Drawing.Point(8, 120)
        Me.Label15.Name = "Label15"
        Me.Label15.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label15.Size = New System.Drawing.Size(88, 24)
        Me.Label15.TabIndex = 28
        Me.Label15.Text = "Distance5:"
        '
        'T_Acceleration5
        '
        Me.T_Acceleration5.AcceptsReturn = True
        Me.T_Acceleration5.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration5.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration5.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration5.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration5.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration5.MaxLength = 0
        Me.T_Acceleration5.Name = "T_Acceleration5"
        Me.T_Acceleration5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration5.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration5.TabIndex = 20
        Me.T_Acceleration5.Text = "0.5"
        Me.T_Acceleration5.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration5
        '
        Me.T_Deceleration5.AcceptsReturn = True
        Me.T_Deceleration5.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration5.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration5.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration5.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration5.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration5.MaxLength = 0
        Me.T_Deceleration5.Name = "T_Deceleration5"
        Me.T_Deceleration5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration5.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration5.TabIndex = 19
        Me.T_Deceleration5.Text = "0"
        Me.T_Deceleration5.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox48
        '
        Me.TextBox48.AcceptsReturn = True
        Me.TextBox48.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox48.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox48.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox48.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox48.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox48.Location = New System.Drawing.Point(8, 72)
        Me.TextBox48.MaxLength = 0
        Me.TextBox48.Name = "TextBox48"
        Me.TextBox48.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox48.Size = New System.Drawing.Size(81, 23)
        Me.TextBox48.TabIndex = 18
        Me.TextBox48.Text = "Tacc5:"
        '
        'TextBox49
        '
        Me.TextBox49.AcceptsReturn = True
        Me.TextBox49.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox49.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox49.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox49.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox49.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox49.Location = New System.Drawing.Point(8, 96)
        Me.TextBox49.MaxLength = 0
        Me.TextBox49.Name = "TextBox49"
        Me.TextBox49.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox49.Size = New System.Drawing.Size(81, 23)
        Me.TextBox49.TabIndex = 17
        Me.TextBox49.Text = "Tdec5:"
        '
        'Maximum_Velocity5
        '
        Me.Maximum_Velocity5.AcceptsReturn = True
        Me.Maximum_Velocity5.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity5.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity5.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity5.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity5.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity5.MaxLength = 0
        Me.Maximum_Velocity5.Name = "Maximum_Velocity5"
        Me.Maximum_Velocity5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity5.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity5.TabIndex = 16
        Me.Maximum_Velocity5.Text = "1000"
        Me.Maximum_Velocity5.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity5
        '
        Me.Start_Velocity5.AcceptsReturn = True
        Me.Start_Velocity5.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity5.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity5.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity5.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity5.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity5.MaxLength = 0
        Me.Start_Velocity5.Name = "Start_Velocity5"
        Me.Start_Velocity5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity5.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity5.TabIndex = 15
        Me.Start_Velocity5.Text = "800"
        Me.Start_Velocity5.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox52
        '
        Me.TextBox52.AcceptsReturn = True
        Me.TextBox52.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox52.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox52.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox52.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox52.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox52.Location = New System.Drawing.Point(8, 24)
        Me.TextBox52.MaxLength = 0
        Me.TextBox52.Name = "TextBox52"
        Me.TextBox52.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox52.Size = New System.Drawing.Size(81, 23)
        Me.TextBox52.TabIndex = 14
        Me.TextBox52.Text = "Min_Vel5 :"
        '
        'TextBox53
        '
        Me.TextBox53.AcceptsReturn = True
        Me.TextBox53.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox53.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox53.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox53.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox53.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox53.Location = New System.Drawing.Point(8, 48)
        Me.TextBox53.MaxLength = 0
        Me.TextBox53.Name = "TextBox53"
        Me.TextBox53.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox53.Size = New System.Drawing.Size(81, 23)
        Me.TextBox53.TabIndex = 13
        Me.TextBox53.Text = "Max_Vel5 :"
        '
        'GroupBox14
        '
        Me.GroupBox14.Controls.Add(Me.Distance4)
        Me.GroupBox14.Controls.Add(Me.Label16)
        Me.GroupBox14.Controls.Add(Me.T_Acceleration4)
        Me.GroupBox14.Controls.Add(Me.T_Deceleration4)
        Me.GroupBox14.Controls.Add(Me.TextBox57)
        Me.GroupBox14.Controls.Add(Me.TextBox58)
        Me.GroupBox14.Controls.Add(Me.Maximum_Velocity4)
        Me.GroupBox14.Controls.Add(Me.Start_Velocity4)
        Me.GroupBox14.Controls.Add(Me.TextBox61)
        Me.GroupBox14.Controls.Add(Me.TextBox62)
        Me.GroupBox14.Location = New System.Drawing.Point(520, 16)
        Me.GroupBox14.Name = "GroupBox14"
        Me.GroupBox14.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox14.TabIndex = 35
        Me.GroupBox14.TabStop = False
        Me.GroupBox14.Text = "Motion 4"
        '
        'Distance4
        '
        Me.Distance4.AcceptsReturn = True
        Me.Distance4.BackColor = System.Drawing.SystemColors.Window
        Me.Distance4.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance4.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance4.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance4.Location = New System.Drawing.Point(96, 120)
        Me.Distance4.MaxLength = 0
        Me.Distance4.Name = "Distance4"
        Me.Distance4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance4.Size = New System.Drawing.Size(48, 24)
        Me.Distance4.TabIndex = 27
        Me.Distance4.Text = "800"
        Me.Distance4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label16
        '
        Me.Label16.BackColor = System.Drawing.SystemColors.Control
        Me.Label16.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label16.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label16.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label16.Location = New System.Drawing.Point(8, 120)
        Me.Label16.Name = "Label16"
        Me.Label16.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label16.Size = New System.Drawing.Size(88, 24)
        Me.Label16.TabIndex = 28
        Me.Label16.Text = "Distance4:"
        '
        'T_Acceleration4
        '
        Me.T_Acceleration4.AcceptsReturn = True
        Me.T_Acceleration4.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration4.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration4.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration4.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration4.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration4.MaxLength = 0
        Me.T_Acceleration4.Name = "T_Acceleration4"
        Me.T_Acceleration4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration4.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration4.TabIndex = 20
        Me.T_Acceleration4.Text = "0.5"
        Me.T_Acceleration4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration4
        '
        Me.T_Deceleration4.AcceptsReturn = True
        Me.T_Deceleration4.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration4.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration4.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration4.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration4.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration4.MaxLength = 0
        Me.T_Deceleration4.Name = "T_Deceleration4"
        Me.T_Deceleration4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration4.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration4.TabIndex = 19
        Me.T_Deceleration4.Text = "0"
        Me.T_Deceleration4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox57
        '
        Me.TextBox57.AcceptsReturn = True
        Me.TextBox57.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox57.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox57.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox57.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox57.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox57.Location = New System.Drawing.Point(8, 72)
        Me.TextBox57.MaxLength = 0
        Me.TextBox57.Name = "TextBox57"
        Me.TextBox57.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox57.Size = New System.Drawing.Size(81, 23)
        Me.TextBox57.TabIndex = 18
        Me.TextBox57.Text = "Tacc4:"
        '
        'TextBox58
        '
        Me.TextBox58.AcceptsReturn = True
        Me.TextBox58.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox58.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox58.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox58.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox58.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox58.Location = New System.Drawing.Point(8, 96)
        Me.TextBox58.MaxLength = 0
        Me.TextBox58.Name = "TextBox58"
        Me.TextBox58.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox58.Size = New System.Drawing.Size(81, 23)
        Me.TextBox58.TabIndex = 17
        Me.TextBox58.Text = "Tdec4:"
        '
        'Maximum_Velocity4
        '
        Me.Maximum_Velocity4.AcceptsReturn = True
        Me.Maximum_Velocity4.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity4.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity4.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity4.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity4.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity4.MaxLength = 0
        Me.Maximum_Velocity4.Name = "Maximum_Velocity4"
        Me.Maximum_Velocity4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity4.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity4.TabIndex = 16
        Me.Maximum_Velocity4.Text = "800"
        Me.Maximum_Velocity4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity4
        '
        Me.Start_Velocity4.AcceptsReturn = True
        Me.Start_Velocity4.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity4.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity4.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity4.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity4.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity4.MaxLength = 0
        Me.Start_Velocity4.Name = "Start_Velocity4"
        Me.Start_Velocity4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity4.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity4.TabIndex = 15
        Me.Start_Velocity4.Text = "600"
        Me.Start_Velocity4.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox61
        '
        Me.TextBox61.AcceptsReturn = True
        Me.TextBox61.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox61.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox61.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox61.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox61.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox61.Location = New System.Drawing.Point(8, 24)
        Me.TextBox61.MaxLength = 0
        Me.TextBox61.Name = "TextBox61"
        Me.TextBox61.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox61.Size = New System.Drawing.Size(81, 23)
        Me.TextBox61.TabIndex = 14
        Me.TextBox61.Text = "Min_Vel4 :"
        '
        'TextBox62
        '
        Me.TextBox62.AcceptsReturn = True
        Me.TextBox62.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox62.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox62.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox62.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox62.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox62.Location = New System.Drawing.Point(8, 48)
        Me.TextBox62.MaxLength = 0
        Me.TextBox62.Name = "TextBox62"
        Me.TextBox62.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox62.Size = New System.Drawing.Size(81, 23)
        Me.TextBox62.TabIndex = 13
        Me.TextBox62.Text = "Max_Vel4 :"
        '
        'GroupBox12
        '
        Me.GroupBox12.Controls.Add(Me.Distance10)
        Me.GroupBox12.Controls.Add(Me.Label14)
        Me.GroupBox12.Controls.Add(Me.T_Acceleration10)
        Me.GroupBox12.Controls.Add(Me.T_Deceleration10)
        Me.GroupBox12.Controls.Add(Me.TextBox39)
        Me.GroupBox12.Controls.Add(Me.TextBox40)
        Me.GroupBox12.Controls.Add(Me.Maximum_Velocity10)
        Me.GroupBox12.Controls.Add(Me.Start_Velocity10)
        Me.GroupBox12.Controls.Add(Me.TextBox43)
        Me.GroupBox12.Controls.Add(Me.TextBox44)
        Me.GroupBox12.Location = New System.Drawing.Point(688, 192)
        Me.GroupBox12.Name = "GroupBox12"
        Me.GroupBox12.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox12.TabIndex = 38
        Me.GroupBox12.TabStop = False
        Me.GroupBox12.Text = "Motion 10"
        '
        'Distance10
        '
        Me.Distance10.AcceptsReturn = True
        Me.Distance10.BackColor = System.Drawing.SystemColors.Window
        Me.Distance10.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance10.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance10.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance10.Location = New System.Drawing.Point(96, 120)
        Me.Distance10.MaxLength = 0
        Me.Distance10.Name = "Distance10"
        Me.Distance10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance10.Size = New System.Drawing.Size(48, 24)
        Me.Distance10.TabIndex = 27
        Me.Distance10.Text = "200"
        Me.Distance10.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label14
        '
        Me.Label14.BackColor = System.Drawing.SystemColors.Control
        Me.Label14.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label14.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label14.Location = New System.Drawing.Point(8, 120)
        Me.Label14.Name = "Label14"
        Me.Label14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label14.Size = New System.Drawing.Size(88, 24)
        Me.Label14.TabIndex = 28
        Me.Label14.Text = "Distance10:"
        '
        'T_Acceleration10
        '
        Me.T_Acceleration10.AcceptsReturn = True
        Me.T_Acceleration10.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration10.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration10.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration10.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration10.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration10.MaxLength = 0
        Me.T_Acceleration10.Name = "T_Acceleration10"
        Me.T_Acceleration10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration10.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration10.TabIndex = 20
        Me.T_Acceleration10.Text = "0"
        Me.T_Acceleration10.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration10
        '
        Me.T_Deceleration10.AcceptsReturn = True
        Me.T_Deceleration10.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration10.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration10.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration10.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration10.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration10.MaxLength = 0
        Me.T_Deceleration10.Name = "T_Deceleration10"
        Me.T_Deceleration10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration10.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration10.TabIndex = 19
        Me.T_Deceleration10.Text = "0.5"
        Me.T_Deceleration10.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox39
        '
        Me.TextBox39.AcceptsReturn = True
        Me.TextBox39.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox39.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox39.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox39.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox39.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox39.Location = New System.Drawing.Point(8, 72)
        Me.TextBox39.MaxLength = 0
        Me.TextBox39.Name = "TextBox39"
        Me.TextBox39.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox39.Size = New System.Drawing.Size(81, 23)
        Me.TextBox39.TabIndex = 18
        Me.TextBox39.Text = "Tacc10:"
        '
        'TextBox40
        '
        Me.TextBox40.AcceptsReturn = True
        Me.TextBox40.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox40.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox40.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox40.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox40.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox40.Location = New System.Drawing.Point(8, 96)
        Me.TextBox40.MaxLength = 0
        Me.TextBox40.Name = "TextBox40"
        Me.TextBox40.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox40.Size = New System.Drawing.Size(81, 23)
        Me.TextBox40.TabIndex = 17
        Me.TextBox40.Text = "Tdec10:"
        '
        'Maximum_Velocity10
        '
        Me.Maximum_Velocity10.AcceptsReturn = True
        Me.Maximum_Velocity10.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity10.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity10.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity10.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity10.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity10.MaxLength = 0
        Me.Maximum_Velocity10.Name = "Maximum_Velocity10"
        Me.Maximum_Velocity10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity10.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity10.TabIndex = 16
        Me.Maximum_Velocity10.Text = "100"
        Me.Maximum_Velocity10.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity10
        '
        Me.Start_Velocity10.AcceptsReturn = True
        Me.Start_Velocity10.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity10.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity10.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity10.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity10.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity10.MaxLength = 0
        Me.Start_Velocity10.Name = "Start_Velocity10"
        Me.Start_Velocity10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity10.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity10.TabIndex = 15
        Me.Start_Velocity10.Text = "10"
        Me.Start_Velocity10.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox43
        '
        Me.TextBox43.AcceptsReturn = True
        Me.TextBox43.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox43.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox43.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox43.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox43.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox43.Location = New System.Drawing.Point(8, 24)
        Me.TextBox43.MaxLength = 0
        Me.TextBox43.Name = "TextBox43"
        Me.TextBox43.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox43.Size = New System.Drawing.Size(81, 23)
        Me.TextBox43.TabIndex = 14
        Me.TextBox43.Text = "Min_Vel10 :"
        '
        'TextBox44
        '
        Me.TextBox44.AcceptsReturn = True
        Me.TextBox44.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox44.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox44.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox44.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox44.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox44.Location = New System.Drawing.Point(8, 48)
        Me.TextBox44.MaxLength = 0
        Me.TextBox44.Name = "TextBox44"
        Me.TextBox44.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox44.Size = New System.Drawing.Size(81, 23)
        Me.TextBox44.TabIndex = 13
        Me.TextBox44.Text = "Max_Vel10 :"
        '
        'GroupBox15
        '
        Me.GroupBox15.Controls.Add(Me.Distance9)
        Me.GroupBox15.Controls.Add(Me.Label17)
        Me.GroupBox15.Controls.Add(Me.T_Acceleration9)
        Me.GroupBox15.Controls.Add(Me.T_Deceleration9)
        Me.GroupBox15.Controls.Add(Me.TextBox66)
        Me.GroupBox15.Controls.Add(Me.TextBox67)
        Me.GroupBox15.Controls.Add(Me.Maximum_Velocity9)
        Me.GroupBox15.Controls.Add(Me.Start_Velocity9)
        Me.GroupBox15.Controls.Add(Me.TextBox70)
        Me.GroupBox15.Controls.Add(Me.TextBox71)
        Me.GroupBox15.Location = New System.Drawing.Point(520, 192)
        Me.GroupBox15.Name = "GroupBox15"
        Me.GroupBox15.Size = New System.Drawing.Size(160, 160)
        Me.GroupBox15.TabIndex = 37
        Me.GroupBox15.TabStop = False
        Me.GroupBox15.Text = "Motion 9"
        '
        'Distance9
        '
        Me.Distance9.AcceptsReturn = True
        Me.Distance9.BackColor = System.Drawing.SystemColors.Window
        Me.Distance9.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Distance9.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Distance9.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Distance9.Location = New System.Drawing.Point(96, 120)
        Me.Distance9.MaxLength = 0
        Me.Distance9.Name = "Distance9"
        Me.Distance9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Distance9.Size = New System.Drawing.Size(48, 24)
        Me.Distance9.TabIndex = 27
        Me.Distance9.Text = "400"
        Me.Distance9.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Label17
        '
        Me.Label17.BackColor = System.Drawing.SystemColors.Control
        Me.Label17.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label17.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold)
        Me.Label17.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label17.Location = New System.Drawing.Point(8, 120)
        Me.Label17.Name = "Label17"
        Me.Label17.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label17.Size = New System.Drawing.Size(88, 24)
        Me.Label17.TabIndex = 28
        Me.Label17.Text = "Distance9:"
        '
        'T_Acceleration9
        '
        Me.T_Acceleration9.AcceptsReturn = True
        Me.T_Acceleration9.BackColor = System.Drawing.SystemColors.Window
        Me.T_Acceleration9.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Acceleration9.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Acceleration9.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Acceleration9.Location = New System.Drawing.Point(96, 72)
        Me.T_Acceleration9.MaxLength = 0
        Me.T_Acceleration9.Name = "T_Acceleration9"
        Me.T_Acceleration9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Acceleration9.Size = New System.Drawing.Size(49, 24)
        Me.T_Acceleration9.TabIndex = 20
        Me.T_Acceleration9.Text = "0"
        Me.T_Acceleration9.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'T_Deceleration9
        '
        Me.T_Deceleration9.AcceptsReturn = True
        Me.T_Deceleration9.BackColor = System.Drawing.SystemColors.Window
        Me.T_Deceleration9.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.T_Deceleration9.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.T_Deceleration9.ForeColor = System.Drawing.SystemColors.WindowText
        Me.T_Deceleration9.Location = New System.Drawing.Point(96, 96)
        Me.T_Deceleration9.MaxLength = 0
        Me.T_Deceleration9.Name = "T_Deceleration9"
        Me.T_Deceleration9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.T_Deceleration9.Size = New System.Drawing.Size(49, 23)
        Me.T_Deceleration9.TabIndex = 19
        Me.T_Deceleration9.Text = "0.5"
        Me.T_Deceleration9.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox66
        '
        Me.TextBox66.AcceptsReturn = True
        Me.TextBox66.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox66.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox66.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox66.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox66.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox66.Location = New System.Drawing.Point(8, 72)
        Me.TextBox66.MaxLength = 0
        Me.TextBox66.Name = "TextBox66"
        Me.TextBox66.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox66.Size = New System.Drawing.Size(81, 23)
        Me.TextBox66.TabIndex = 18
        Me.TextBox66.Text = "Tacc9:"
        '
        'TextBox67
        '
        Me.TextBox67.AcceptsReturn = True
        Me.TextBox67.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox67.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox67.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox67.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox67.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox67.Location = New System.Drawing.Point(8, 96)
        Me.TextBox67.MaxLength = 0
        Me.TextBox67.Name = "TextBox67"
        Me.TextBox67.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox67.Size = New System.Drawing.Size(81, 23)
        Me.TextBox67.TabIndex = 17
        Me.TextBox67.Text = "Tdec9:"
        '
        'Maximum_Velocity9
        '
        Me.Maximum_Velocity9.AcceptsReturn = True
        Me.Maximum_Velocity9.BackColor = System.Drawing.SystemColors.Window
        Me.Maximum_Velocity9.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Maximum_Velocity9.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Maximum_Velocity9.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Maximum_Velocity9.Location = New System.Drawing.Point(96, 48)
        Me.Maximum_Velocity9.MaxLength = 0
        Me.Maximum_Velocity9.Name = "Maximum_Velocity9"
        Me.Maximum_Velocity9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Maximum_Velocity9.Size = New System.Drawing.Size(49, 23)
        Me.Maximum_Velocity9.TabIndex = 16
        Me.Maximum_Velocity9.Text = "300"
        Me.Maximum_Velocity9.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'Start_Velocity9
        '
        Me.Start_Velocity9.AcceptsReturn = True
        Me.Start_Velocity9.BackColor = System.Drawing.SystemColors.Window
        Me.Start_Velocity9.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Start_Velocity9.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Start_Velocity9.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Start_Velocity9.Location = New System.Drawing.Point(96, 24)
        Me.Start_Velocity9.MaxLength = 0
        Me.Start_Velocity9.Name = "Start_Velocity9"
        Me.Start_Velocity9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Start_Velocity9.Size = New System.Drawing.Size(49, 23)
        Me.Start_Velocity9.TabIndex = 15
        Me.Start_Velocity9.Text = "100"
        Me.Start_Velocity9.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'TextBox70
        '
        Me.TextBox70.AcceptsReturn = True
        Me.TextBox70.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox70.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox70.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox70.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox70.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox70.Location = New System.Drawing.Point(8, 24)
        Me.TextBox70.MaxLength = 0
        Me.TextBox70.Name = "TextBox70"
        Me.TextBox70.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox70.Size = New System.Drawing.Size(81, 23)
        Me.TextBox70.TabIndex = 14
        Me.TextBox70.Text = "Min_Vel9 :"
        '
        'TextBox71
        '
        Me.TextBox71.AcceptsReturn = True
        Me.TextBox71.BackColor = System.Drawing.SystemColors.Control
        Me.TextBox71.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.TextBox71.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.TextBox71.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextBox71.ForeColor = System.Drawing.SystemColors.WindowFrame
        Me.TextBox71.Location = New System.Drawing.Point(8, 48)
        Me.TextBox71.MaxLength = 0
        Me.TextBox71.Name = "TextBox71"
        Me.TextBox71.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.TextBox71.Size = New System.Drawing.Size(81, 23)
        Me.TextBox71.TabIndex = 13
        Me.TextBox71.Text = "Max_Vel9 :"
        '
        'RunStep
        '
        Me.RunStep.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.RunStep.Location = New System.Drawing.Point(576, 376)
        Me.RunStep.Name = "RunStep"
        Me.RunStep.Size = New System.Drawing.Size(48, 27)
        Me.RunStep.TabIndex = 40
        Me.RunStep.Text = "0"
        '
        'Label18
        '
        Me.Label18.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label18.Location = New System.Drawing.Point(528, 384)
        Me.Label18.Name = "Label18"
        Me.Label18.Size = New System.Drawing.Size(48, 23)
        Me.Label18.TabIndex = 39
        Me.Label18.Text = "RunStep:"
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 15)
        Me.ClientSize = New System.Drawing.Size(992, 606)
        Me.Controls.Add(Me.RunStep)
        Me.Controls.Add(Me.Label18)
        Me.Controls.Add(Me.GroupBox12)
        Me.Controls.Add(Me.GroupBox15)
        Me.Controls.Add(Me.GroupBox13)
        Me.Controls.Add(Me.GroupBox14)
        Me.Controls.Add(Me.GroupBox9)
        Me.Controls.Add(Me.GroupBox10)
        Me.Controls.Add(Me.GroupBox11)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.txtStep)
        Me.Controls.Add(Me.Label12)
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
        Me.Text = "8102_Continuous_Contour_motion_Pro"
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
        Me.GroupBox7.ResumeLayout(False)
        Me.GroupBox8.ResumeLayout(False)
        Me.GroupBox9.ResumeLayout(False)
        Me.GroupBox10.ResumeLayout(False)
        Me.GroupBox11.ResumeLayout(False)
        Me.GroupBox13.ResumeLayout(False)
        Me.GroupBox14.ResumeLayout(False)
        Me.GroupBox12.ResumeLayout(False)
        Me.GroupBox15.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

#End Region
    Dim CardNo As Integer
    Dim AxisNo As Integer
    Dim TotalCard As Integer

    Dim Trd_INT As New System.Threading.Thread(AddressOf Thread_INT)
    Dim bolTrd_INT As Boolean = False

    Public MAX_CARDS_PCI_8102 As Short = 0
    Public CARDS_PCI_8102_Status(16) As Boolean

    Dim retmsg As Short = 1000
    Dim intStep As Integer = 0
    Dim reterr As Short
    Dim Int_No As Integer = 0

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        'Dim dblAxDChart1_YAxis_Max As Double = 0

        'If CInt(Maximum_Velocity1.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity1.Text)
        'If CInt(Maximum_Velocity2.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity2.Text)
        'If CInt(Maximum_Velocity3.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity3.Text)
        'If CInt(Maximum_Velocity4.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity4.Text)
        'If CInt(Maximum_Velocity5.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity5.Text)
        'If CInt(Maximum_Velocity6.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity6.Text)
        'If CInt(Maximum_Velocity7.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity7.Text)
        'If CInt(Maximum_Velocity8.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity8.Text)
        'If CInt(Maximum_Velocity9.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity9.Text)
        'If CInt(Maximum_Velocity10.Text) > dblAxDChart1_YAxis_Max Then dblAxDChart1_YAxis_Max = CDbl(Maximum_Velocity10.Text)

        'AxDChart1.YAxis.Maximum = System.Math.Abs(CDbl(dblAxDChart1_YAxis_Max))
        'AxDChart1.YAxis.Minimum = (-1) * System.Math.Abs(CDbl(dblAxDChart1_YAxis_Max))



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

        Trd_INT.Start()

    End Sub

    Private Sub Form1_Closing(ByVal sender As Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles MyBase.Closing
        Trd_INT.Abort()

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

        Me.Button1.Enabled = False


        AxisNo = CInt(PTP_AXIS.Text)

        'B_8102_int_control(CInt(PTP_AXIS.Text), 1)
        'B_8102_set_motion_int_factor(CInt(PTP_AXIS.Text), 4)

        Int_No = APS_set_int_factor(CInt(CInt(PTP_AXIS.Text) / 2), CInt(PTP_AXIS.Text) * 2 + 1, 2, 1)
        APS_int_enable(CInt(CInt(PTP_AXIS.Text) / 2), 1)

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


        If CInt(txtStep.Text) > 3 Then
            bolTrd_INT = True
        Else

            Me.Button1.Enabled = True
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
        Dim CurPos As Double, CurSpeed As Double
        Dim io_sts As Integer, MOT_STS As Integer
        Dim Ckp As Double
        Dim PCMD As Long

        'For i = 2 * CardNo To 2 * CardNo + 1
        ' Display Next Compare Data
        'B_8102_check_compare_data(i, 5, Ckp)
        'CMPP(i).Text = Str(Ckp)
        'Next

        AxisNo = CInt(PTP_AXIS.Text)


        RunStep.Text = CStr(intStep)

        'B_8102_get_position(AxisNo, CurPos)
        APS_get_position(AxisNo, CurPos)
        Pos0.Text = Str(CurPos)

        'B_8102_get_current_speed(AxisNo, CurSpeed)
        APS_get_command_velocity(AxisNo, CurSpeed)
        Speed0.Text = Str(CurSpeed)

        'AxDChart1.PlotChart(CurSpeed)

        'B_8102_get_io_status(AxisNo, io_sts)
        io_sts = APS_motion_io_status(AxisNo)
        IOSts0.Text = Hex(io_sts)

        'MOT_STS = B_8102_motion_done(AxisNo)
        MOT_STS = APS_motion_status(AxisNo)
        MotSts0.Text = Str(MOT_STS)

        'B_8102_get_command(AxisNo, PCMD)
        APS_get_command(AxisNo, PCMD)
        CMD0.Text = Str(PCMD)

        If bolTrd_INT = False Then Me.Button1.Enabled = True

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

        bolTrd_INT = False

        '''B_8102_set_continuous_move(AxisNo, 0)
        APS_set_axis_param(AxisNo, &H250, 0) 'PRA_CONTI_MODE

        Me.Button1.Enabled = True

    End Sub


    Sub Thread_INT()




        While 1


            If bolTrd_INT = True Then

                APS_reset_int(Int_No)

                If CInt(txtStep.Text) > 3 And bolTrd_INT = True Then

                    '''''''''''''''''''''''''''''''''''

                    retmsg = 1000

                    'While B_8102_check_continuous_buffer(AxisNo) <> 0

                    'End While

                    'retmsg = B_8102_wait_motion_interrupt(AxisNo, 2, 5000)

                    retmsg = APS_wait_single_int(Int_No, 5000)
                    APS_reset_int(Int_No)

                    If retmsg = 0 Then

                        intStep = 4

                        reterr = 0
                        'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance4.Text), CDbl(Start_Velocity4.Text), CDbl(Maximum_Velocity4.Text), CDbl(T_Acceleration4.Text), CDbl(T_Deceleration4.Text))

                        APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity4.Text)) 'PRA_VS
                        APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration4.Text)) 'PRA_ACC
                        APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration4.Text)) 'PRA_DEC

                        reterr = APS_relative_move(AxisNo, CInt(Distance4.Text), CInt(Maximum_Velocity4.Text))

                    End If


                    '''''''''''''''''''''''''''''''''''

                End If


                If CInt(txtStep.Text) > 4 And bolTrd_INT = True Then

                    '''''''''''''''''''''''''''''''''''

                    retmsg = 1000

                    'While B_8102_check_continuous_buffer(AxisNo) <> 0

                    'End While

                    'retmsg = B_8102_wait_motion_interrupt(AxisNo, 2, 5000)

                    retmsg = APS_wait_single_int(Int_No, 5000)
                    APS_reset_int(Int_No)

                    If retmsg = 0 Then

                        intStep = 5
                        reterr = 0
                        'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance5.Text), CDbl(Start_Velocity5.Text), CDbl(Maximum_Velocity5.Text), CDbl(T_Acceleration5.Text), CDbl(T_Deceleration5.Text))

                        APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity5.Text)) 'PRA_VS
                        APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration5.Text)) 'PRA_ACC
                        APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration5.Text)) 'PRA_DEC

                        reterr = APS_relative_move(AxisNo, CInt(Distance5.Text), CInt(Maximum_Velocity5.Text))

                    End If


                    '''''''''''''''''''''''''''''''''''


                End If


                If CInt(txtStep.Text) > 5 And bolTrd_INT = True Then


                    '''''''''''''''''''''''''''''''''''

                    retmsg = 1000

                    'While B_8102_check_continuous_buffer(AxisNo) <> 0

                    'End While

                    'retmsg = B_8102_wait_motion_interrupt(AxisNo, 2, 5000)

                    retmsg = APS_wait_single_int(Int_No, 5000)
                    APS_reset_int(Int_No)

                    If retmsg = 0 Then

                        intStep = 6
                        reterr = 0
                        'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance6.Text), CDbl(Start_Velocity6.Text), CDbl(Maximum_Velocity6.Text), CDbl(T_Acceleration6.Text), CDbl(T_Deceleration6.Text))

                        APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity6.Text)) 'PRA_VS
                        APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration6.Text)) 'PRA_ACC
                        APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration6.Text)) 'PRA_DEC

                        reterr = APS_relative_move(AxisNo, CInt(Distance6.Text), CInt(Maximum_Velocity6.Text))

                    End If


                    '''''''''''''''''''''''''''''''''''


                End If







                If CInt(txtStep.Text) > 6 And bolTrd_INT = True Then

                    '''''''''''''''''''''''''''''''''''

                    retmsg = 1000

                    'While B_8102_check_continuous_buffer(AxisNo) <> 0

                    'End While

                    'retmsg = B_8102_wait_motion_interrupt(AxisNo, 2, 5000)

                    retmsg = APS_wait_single_int(Int_No, 5000)
                    APS_reset_int(Int_No)

                    If retmsg = 0 Then

                        intStep = 7

                        reterr = 0
                        'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance7.Text), CDbl(Start_Velocity7.Text), CDbl(Maximum_Velocity7.Text), CDbl(T_Acceleration7.Text), CDbl(T_Deceleration7.Text))

                        APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity7.Text)) 'PRA_VS
                        APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration7.Text)) 'PRA_ACC
                        APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration7.Text)) 'PRA_DEC

                        reterr = APS_relative_move(AxisNo, CInt(Distance7.Text), CInt(Maximum_Velocity7.Text))

                    End If


                    '''''''''''''''''''''''''''''''''''




                End If


                If CInt(txtStep.Text) > 7 And bolTrd_INT = True Then

                    '''''''''''''''''''''''''''''''''''

                    retmsg = 1000

                    'While B_8102_check_continuous_buffer(AxisNo) <> 0

                    'End While

                    'retmsg = B_8102_wait_motion_interrupt(AxisNo, 2, 5000)

                    retmsg = APS_wait_single_int(Int_No, 5000)
                    APS_reset_int(Int_No)

                    If retmsg = 0 Then

                        intStep = 8
                        reterr = 0
                        'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance8.Text), CDbl(Start_Velocity8.Text), CDbl(Maximum_Velocity8.Text), CDbl(T_Acceleration8.Text), CDbl(T_Deceleration8.Text))

                        APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity8.Text)) 'PRA_VS
                        APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration8.Text)) 'PRA_ACC
                        APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration8.Text)) 'PRA_DEC

                        reterr = APS_relative_move(AxisNo, CInt(Distance8.Text), CInt(Maximum_Velocity8.Text))

                    End If


                    '''''''''''''''''''''''''''''''''''



                End If


                If CInt(txtStep.Text) > 8 And bolTrd_INT = True Then


                    '''''''''''''''''''''''''''''''''''

                    retmsg = 1000

                    'While B_8102_check_continuous_buffer(AxisNo) <> 0

                    'End While

                    'retmsg = B_8102_wait_motion_interrupt(AxisNo, 2, 5000)

                    retmsg = APS_wait_single_int(Int_No, 5000)
                    APS_reset_int(Int_No)

                    If retmsg = 0 Then

                        intStep = 9
                        reterr = 0
                        'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance9.Text), CDbl(Start_Velocity9.Text), CDbl(Maximum_Velocity9.Text), CDbl(T_Acceleration9.Text), CDbl(T_Deceleration9.Text))

                        APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity9.Text)) 'PRA_VS
                        APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration9.Text)) 'PRA_ACC
                        APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration9.Text)) 'PRA_DEC

                        reterr = APS_relative_move(AxisNo, CInt(Distance9.Text), CInt(Maximum_Velocity9.Text))

                    End If


                    '''''''''''''''''''''''''''''''''''


                End If



                If CInt(txtStep.Text) > 9 And bolTrd_INT = True Then

                    '''''''''''''''''''''''''''''''''''

                    retmsg = 1000

                    'While B_8102_check_continuous_buffer(AxisNo) <> 0

                    'End While

                    'retmsg = B_8102_wait_motion_interrupt(AxisNo, 2, 5000)

                    retmsg = APS_wait_single_int(Int_No, 5000)
                    APS_reset_int(Int_No)

                    If retmsg = 0 Then

                        intStep = 10

                        reterr = 0
                        'reterr = B_8102_start_tr_move(AxisNo, CDbl(Distance10.Text), CDbl(Start_Velocity10.Text), CDbl(Maximum_Velocity10.Text), CDbl(T_Acceleration10.Text), CDbl(T_Deceleration10.Text))

                        APS_set_axis_param(AxisNo, 35, CInt(Start_Velocity10.Text)) 'PRA_VS
                        APS_set_axis_param(AxisNo, 33, CInt(T_Acceleration10.Text)) 'PRA_ACC
                        APS_set_axis_param(AxisNo, 34, CInt(T_Deceleration10.Text)) 'PRA_DEC

                        reterr = APS_relative_move(AxisNo, CInt(Distance10.Text), CInt(Maximum_Velocity10.Text))

                    End If

                    '''''''''''''''''''''''''''''''''''
                End If

                'Me.Button1.Enabled = True
                bolTrd_INT = False
            End If

            Sleep(50)
        End While

    End Sub


End Class
