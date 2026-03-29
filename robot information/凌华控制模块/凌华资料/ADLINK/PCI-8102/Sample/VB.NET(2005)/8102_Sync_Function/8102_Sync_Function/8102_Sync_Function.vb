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
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Pos0 As System.Windows.Forms.TextBox
    Friend WithEvents Pos1 As System.Windows.Forms.TextBox
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents IOSts1 As System.Windows.Forms.TextBox
    Friend WithEvents IOSts0 As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents Speed1 As System.Windows.Forms.TextBox
    Friend WithEvents Speed0 As System.Windows.Forms.TextBox
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents MotSts1 As System.Windows.Forms.TextBox
    Friend WithEvents MotSts0 As System.Windows.Forms.TextBox
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents PTP_AXIS As System.Windows.Forms.TextBox
    Friend WithEvents PTP_CMD As System.Windows.Forms.TextBox
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents LINE_CMD_0 As System.Windows.Forms.TextBox
    Friend WithEvents LINE_CMD_1 As System.Windows.Forms.TextBox
    Friend WithEvents ARC_CMD_1 As System.Windows.Forms.TextBox
    Friend WithEvents ARC_CMD_0 As System.Windows.Forms.TextBox
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents GroupBox5 As System.Windows.Forms.GroupBox
    Friend WithEvents CMD1 As System.Windows.Forms.TextBox
    Friend WithEvents CMD0 As System.Windows.Forms.TextBox
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents CMP_STS As System.Windows.Forms.TextBox
    Friend WithEvents CheckBox1 As System.Windows.Forms.CheckBox
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents Label13 As System.Windows.Forms.Label
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents Label15 As System.Windows.Forms.Label
    Friend WithEvents Label16 As System.Windows.Forms.Label
    Friend WithEvents Button7 As System.Windows.Forms.Button
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Pos1 = New System.Windows.Forms.TextBox
        Me.Pos0 = New System.Windows.Forms.TextBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label1 = New System.Windows.Forms.Label
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.IOSts1 = New System.Windows.Forms.TextBox
        Me.IOSts0 = New System.Windows.Forms.TextBox
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.GroupBox3 = New System.Windows.Forms.GroupBox
        Me.Speed1 = New System.Windows.Forms.TextBox
        Me.Speed0 = New System.Windows.Forms.TextBox
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.GroupBox4 = New System.Windows.Forms.GroupBox
        Me.MotSts1 = New System.Windows.Forms.TextBox
        Me.MotSts0 = New System.Windows.Forms.TextBox
        Me.Label7 = New System.Windows.Forms.Label
        Me.Label8 = New System.Windows.Forms.Label
        Me.Button1 = New System.Windows.Forms.Button
        Me.PTP_AXIS = New System.Windows.Forms.TextBox
        Me.Label9 = New System.Windows.Forms.Label
        Me.PTP_CMD = New System.Windows.Forms.TextBox
        Me.Button2 = New System.Windows.Forms.Button
        Me.LINE_CMD_0 = New System.Windows.Forms.TextBox
        Me.LINE_CMD_1 = New System.Windows.Forms.TextBox
        Me.ARC_CMD_1 = New System.Windows.Forms.TextBox
        Me.ARC_CMD_0 = New System.Windows.Forms.TextBox
        Me.Button3 = New System.Windows.Forms.Button
        Me.Button4 = New System.Windows.Forms.Button
        Me.Button5 = New System.Windows.Forms.Button
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.GroupBox5 = New System.Windows.Forms.GroupBox
        Me.CMD1 = New System.Windows.Forms.TextBox
        Me.CMD0 = New System.Windows.Forms.TextBox
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.Button6 = New System.Windows.Forms.Button
        Me.Button7 = New System.Windows.Forms.Button
        Me.CMP_STS = New System.Windows.Forms.TextBox
        Me.CheckBox1 = New System.Windows.Forms.CheckBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.Label13 = New System.Windows.Forms.Label
        Me.Label14 = New System.Windows.Forms.Label
        Me.Label15 = New System.Windows.Forms.Label
        Me.Label16 = New System.Windows.Forms.Label
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox5.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Pos1)
        Me.GroupBox1.Controls.Add(Me.Pos0)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(8, 16)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Position (p)"
        '
        'Pos1
        '
        Me.Pos1.Location = New System.Drawing.Point(64, 64)
        Me.Pos1.Name = "Pos1"
        Me.Pos1.Size = New System.Drawing.Size(80, 27)
        Me.Pos1.TabIndex = 3
        Me.Pos1.Text = "0"
        '
        'Pos0
        '
        Me.Pos0.Location = New System.Drawing.Point(64, 32)
        Me.Pos0.Name = "Pos0"
        Me.Pos0.Size = New System.Drawing.Size(80, 27)
        Me.Pos0.TabIndex = 2
        Me.Pos0.Text = "0"
        '
        'Label2
        '
        Me.Label2.Location = New System.Drawing.Point(8, 72)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(56, 23)
        Me.Label2.TabIndex = 1
        Me.Label2.Text = "Axis 1"
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
        Me.GroupBox2.Controls.Add(Me.IOSts1)
        Me.GroupBox2.Controls.Add(Me.IOSts0)
        Me.GroupBox2.Controls.Add(Me.Label3)
        Me.GroupBox2.Controls.Add(Me.Label4)
        Me.GroupBox2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox2.Location = New System.Drawing.Point(184, 16)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox2.TabIndex = 1
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "I/O Status (Hex)"
        '
        'IOSts1
        '
        Me.IOSts1.Location = New System.Drawing.Point(68, 64)
        Me.IOSts1.Name = "IOSts1"
        Me.IOSts1.Size = New System.Drawing.Size(80, 27)
        Me.IOSts1.TabIndex = 7
        Me.IOSts1.Text = "0"
        '
        'IOSts0
        '
        Me.IOSts0.Location = New System.Drawing.Point(68, 32)
        Me.IOSts0.Name = "IOSts0"
        Me.IOSts0.Size = New System.Drawing.Size(80, 27)
        Me.IOSts0.TabIndex = 6
        Me.IOSts0.Text = "0"
        '
        'Label3
        '
        Me.Label3.Location = New System.Drawing.Point(12, 72)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(56, 23)
        Me.Label3.TabIndex = 5
        Me.Label3.Text = "Axis 1"
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
        Me.GroupBox3.Controls.Add(Me.Speed1)
        Me.GroupBox3.Controls.Add(Me.Speed0)
        Me.GroupBox3.Controls.Add(Me.Label5)
        Me.GroupBox3.Controls.Add(Me.Label6)
        Me.GroupBox3.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox3.Location = New System.Drawing.Point(8, 139)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox3.TabIndex = 2
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Speed (pps)"
        '
        'Speed1
        '
        Me.Speed1.Location = New System.Drawing.Point(64, 64)
        Me.Speed1.Name = "Speed1"
        Me.Speed1.Size = New System.Drawing.Size(80, 27)
        Me.Speed1.TabIndex = 3
        Me.Speed1.Text = "0"
        '
        'Speed0
        '
        Me.Speed0.Location = New System.Drawing.Point(64, 32)
        Me.Speed0.Name = "Speed0"
        Me.Speed0.Size = New System.Drawing.Size(80, 27)
        Me.Speed0.TabIndex = 2
        Me.Speed0.Text = "0"
        '
        'Label5
        '
        Me.Label5.Location = New System.Drawing.Point(8, 72)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(56, 23)
        Me.Label5.TabIndex = 1
        Me.Label5.Text = "Axis 1"
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
        Me.GroupBox4.Controls.Add(Me.MotSts1)
        Me.GroupBox4.Controls.Add(Me.MotSts0)
        Me.GroupBox4.Controls.Add(Me.Label7)
        Me.GroupBox4.Controls.Add(Me.Label8)
        Me.GroupBox4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox4.Location = New System.Drawing.Point(184, 138)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox4.TabIndex = 3
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "Motion Status"
        '
        'MotSts1
        '
        Me.MotSts1.Location = New System.Drawing.Point(64, 64)
        Me.MotSts1.Name = "MotSts1"
        Me.MotSts1.Size = New System.Drawing.Size(80, 27)
        Me.MotSts1.TabIndex = 3
        Me.MotSts1.Text = "0"
        '
        'MotSts0
        '
        Me.MotSts0.Location = New System.Drawing.Point(64, 32)
        Me.MotSts0.Name = "MotSts0"
        Me.MotSts0.Size = New System.Drawing.Size(80, 27)
        Me.MotSts0.TabIndex = 2
        Me.MotSts0.Text = "0"
        '
        'Label7
        '
        Me.Label7.Location = New System.Drawing.Point(8, 72)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(56, 23)
        Me.Label7.TabIndex = 1
        Me.Label7.Text = "Axis 1"
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
        Me.Button1.Location = New System.Drawing.Point(376, 32)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(96, 32)
        Me.Button1.TabIndex = 4
        Me.Button1.Text = "PTP"
        '
        'PTP_AXIS
        '
        Me.PTP_AXIS.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.PTP_AXIS.Location = New System.Drawing.Point(600, 32)
        Me.PTP_AXIS.Name = "PTP_AXIS"
        Me.PTP_AXIS.Size = New System.Drawing.Size(48, 27)
        Me.PTP_AXIS.TabIndex = 8
        Me.PTP_AXIS.Text = "0"
        '
        'Label9
        '
        Me.Label9.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label9.Location = New System.Drawing.Point(552, 40)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(48, 23)
        Me.Label9.TabIndex = 7
        Me.Label9.Text = "Axis :"
        '
        'PTP_CMD
        '
        Me.PTP_CMD.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.PTP_CMD.Location = New System.Drawing.Point(552, 64)
        Me.PTP_CMD.Name = "PTP_CMD"
        Me.PTP_CMD.Size = New System.Drawing.Size(96, 27)
        Me.PTP_CMD.TabIndex = 9
        Me.PTP_CMD.Text = "150000"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button2.Location = New System.Drawing.Point(376, 120)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(96, 32)
        Me.Button2.TabIndex = 11
        Me.Button2.Text = "LINE X-Y"
        '
        'LINE_CMD_0
        '
        Me.LINE_CMD_0.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.LINE_CMD_0.Location = New System.Drawing.Point(552, 120)
        Me.LINE_CMD_0.Name = "LINE_CMD_0"
        Me.LINE_CMD_0.Size = New System.Drawing.Size(96, 27)
        Me.LINE_CMD_0.TabIndex = 12
        Me.LINE_CMD_0.Text = "40000"
        '
        'LINE_CMD_1
        '
        Me.LINE_CMD_1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.LINE_CMD_1.Location = New System.Drawing.Point(552, 152)
        Me.LINE_CMD_1.Name = "LINE_CMD_1"
        Me.LINE_CMD_1.Size = New System.Drawing.Size(96, 27)
        Me.LINE_CMD_1.TabIndex = 13
        Me.LINE_CMD_1.Text = "20000"
        '
        'ARC_CMD_1
        '
        Me.ARC_CMD_1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.ARC_CMD_1.Location = New System.Drawing.Point(552, 234)
        Me.ARC_CMD_1.Name = "ARC_CMD_1"
        Me.ARC_CMD_1.Size = New System.Drawing.Size(96, 27)
        Me.ARC_CMD_1.TabIndex = 16
        Me.ARC_CMD_1.Text = "20000"
        '
        'ARC_CMD_0
        '
        Me.ARC_CMD_0.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.ARC_CMD_0.Location = New System.Drawing.Point(552, 202)
        Me.ARC_CMD_0.Name = "ARC_CMD_0"
        Me.ARC_CMD_0.Size = New System.Drawing.Size(96, 27)
        Me.ARC_CMD_0.TabIndex = 15
        Me.ARC_CMD_0.Text = "40000"
        '
        'Button3
        '
        Me.Button3.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button3.Location = New System.Drawing.Point(376, 202)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(96, 32)
        Me.Button3.TabIndex = 14
        Me.Button3.Text = "ARC X-Y"
        '
        'Button4
        '
        Me.Button4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button4.Location = New System.Drawing.Point(376, 280)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(96, 96)
        Me.Button4.TabIndex = 17
        Me.Button4.Text = "Reset Position"
        '
        'Button5
        '
        Me.Button5.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button5.Location = New System.Drawing.Point(552, 280)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(96, 96)
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
        Me.GroupBox5.Controls.Add(Me.CMD1)
        Me.GroupBox5.Controls.Add(Me.CMD0)
        Me.GroupBox5.Controls.Add(Me.Label10)
        Me.GroupBox5.Controls.Add(Me.Label11)
        Me.GroupBox5.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox5.Location = New System.Drawing.Point(8, 264)
        Me.GroupBox5.Name = "GroupBox5"
        Me.GroupBox5.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox5.TabIndex = 19
        Me.GroupBox5.TabStop = False
        Me.GroupBox5.Text = "Command Output"
        '
        'CMD1
        '
        Me.CMD1.Location = New System.Drawing.Point(64, 64)
        Me.CMD1.Name = "CMD1"
        Me.CMD1.Size = New System.Drawing.Size(80, 27)
        Me.CMD1.TabIndex = 3
        Me.CMD1.Text = "0"
        '
        'CMD0
        '
        Me.CMD0.Location = New System.Drawing.Point(64, 32)
        Me.CMD0.Name = "CMD0"
        Me.CMD0.Size = New System.Drawing.Size(80, 27)
        Me.CMD0.TabIndex = 2
        Me.CMD0.Text = "0"
        '
        'Label10
        '
        Me.Label10.Location = New System.Drawing.Point(8, 72)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(56, 23)
        Me.Label10.TabIndex = 1
        Me.Label10.Text = "Axis 1"
        '
        'Label11
        '
        Me.Label11.Location = New System.Drawing.Point(8, 38)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(48, 23)
        Me.Label11.TabIndex = 0
        Me.Label11.Text = "Axis 0"
        '
        'Button6
        '
        Me.Button6.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button6.Location = New System.Drawing.Point(192, 280)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(152, 40)
        Me.Button6.TabIndex = 20
        Me.Button6.Text = "Sync Start"
        '
        'Button7
        '
        Me.Button7.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button7.Location = New System.Drawing.Point(192, 336)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(152, 40)
        Me.Button7.TabIndex = 21
        Me.Button7.Text = "Sync Stop"
        '
        'CMP_STS
        '
        Me.CMP_STS.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.CMP_STS.Location = New System.Drawing.Point(376, 87)
        Me.CMP_STS.Name = "CMP_STS"
        Me.CMP_STS.Size = New System.Drawing.Size(48, 27)
        Me.CMP_STS.TabIndex = 159
        Me.CMP_STS.Text = "0"
        '
        'CheckBox1
        '
        Me.CheckBox1.Location = New System.Drawing.Point(376, 67)
        Me.CheckBox1.Name = "CheckBox1"
        Me.CheckBox1.Size = New System.Drawing.Size(88, 24)
        Me.CheckBox1.TabIndex = 158
        Me.CheckBox1.Text = "Use Trigger?"
        '
        'Label12
        '
        Me.Label12.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label12.Location = New System.Drawing.Point(490, 125)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(56, 23)
        Me.Label12.TabIndex = 160
        Me.Label12.Text = "Dist X"
        '
        'Label13
        '
        Me.Label13.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label13.Location = New System.Drawing.Point(490, 155)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(56, 23)
        Me.Label13.TabIndex = 161
        Me.Label13.Text = "Dist Y"
        '
        'Label14
        '
        Me.Label14.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label14.Location = New System.Drawing.Point(490, 66)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(56, 23)
        Me.Label14.TabIndex = 162
        Me.Label14.Text = "Dist X"
        '
        'Label15
        '
        Me.Label15.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label15.Location = New System.Drawing.Point(478, 237)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(68, 23)
        Me.Label15.TabIndex = 164
        Me.Label15.Text = "Center Y"
        '
        'Label16
        '
        Me.Label16.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label16.Location = New System.Drawing.Point(479, 206)
        Me.Label16.Name = "Label16"
        Me.Label16.Size = New System.Drawing.Size(67, 23)
        Me.Label16.TabIndex = 163
        Me.Label16.Text = "Center X"
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 15)
        Me.ClientSize = New System.Drawing.Size(672, 406)
        Me.Controls.Add(Me.Label15)
        Me.Controls.Add(Me.Label16)
        Me.Controls.Add(Me.Label14)
        Me.Controls.Add(Me.Label13)
        Me.Controls.Add(Me.Label12)
        Me.Controls.Add(Me.CMP_STS)
        Me.Controls.Add(Me.CheckBox1)
        Me.Controls.Add(Me.Button7)
        Me.Controls.Add(Me.Button6)
        Me.Controls.Add(Me.GroupBox5)
        Me.Controls.Add(Me.Button5)
        Me.Controls.Add(Me.Button4)
        Me.Controls.Add(Me.ARC_CMD_1)
        Me.Controls.Add(Me.ARC_CMD_0)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.LINE_CMD_1)
        Me.Controls.Add(Me.LINE_CMD_0)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.PTP_CMD)
        Me.Controls.Add(Me.PTP_AXIS)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Name = "Form1"
        Me.Text = "8102_Sync_Function"
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
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

#End Region
    Dim CardNo As Integer
    Dim AxisNo As Integer
    Dim TotalCard As Integer


    Public MAX_CARDS_PCI_8102 As Short = 0
    Public CARDS_PCI_8102_Status(16) As Boolean

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

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
        APS_close()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim CompTable(4000) As Double
        Dim i As Double
        'Dim Err As Integer

        'Dim AxisNo As Integer

        For i = 0 To 1000
            CompTable(i) = 30000.0# + 100.0# * i
        Next

        AxisNo = CInt(PTP_AXIS.Text)

        If (AxisNo = 0 Or AxisNo = 1) And CheckBox1.Checked = True Then
            ' Enable Comparator Section Begin
            ' Set first axis of the card for trigger output
            ' Compare Src=0 means from command
            ' Compare Src=1 means from Feedback
            'Err = B_8102_set_trigger_comparator(AxisNo, 0, 1, 30000)

            APS_set_axis_param(AxisNo, 551, 30000) 'PRA_GCMP_POS 0x227
            APS_set_axis_param(AxisNo, 552, 0)     'PRA_GCMP_SRC 0x228
            APS_set_axis_param(AxisNo, 550, 5)     'PRA_GCMP_EN  0x226

            ' Enable Comparator Section End

            ' Auto Comparator Section Begin
            'Err = B_8102_build_compare_function(AxisNo, 30000, 110000, 20, 1)
            'Err = B_8164_build_compare_table(AxisNo, CompTable(0), 1001, 0)
            'Err = B_8102_set_auto_compare(AxisNo, 1)
            ' Auto Comparator Section End
        End If

        'B_8102_start_tr_move(AxisNo, CDbl(PTP_CMD.Text), 0, 200000, 0.1, 0.1)

        APS_set_axis_param(AxisNo, 35, 0) 'PRA_VS
        APS_set_axis_param(AxisNo, 33, 50000) 'PRA_ACC
        APS_set_axis_param(AxisNo, 34, 50000) 'PRA_DEC

        APS_relative_move(AxisNo, CInt(PTP_CMD.Text), 200000)

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim Dimension As Integer
        Dim Axis_ID_Array_For_2Axes_Move(2) As Integer
        Dim Position_Array(2) As Integer
        Dim Max_Linear_Speed As Integer
        'Dim AxisNo As Integer

        Dimension = 2
        Axis_ID_Array_For_2Axes_Move(0) = 0
        Axis_ID_Array_For_2Axes_Move(1) = 1
        Position_Array(0) = CInt(LINE_CMD_0.Text)
        Position_Array(1) = CInt(LINE_CMD_1.Text)
        Max_Linear_Speed = 50000

        'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

        APS_relative_linear_move(Dimension, Axis_ID_Array_For_2Axes_Move, Position_Array, Max_Linear_Speed)

        'B_8102_start_tr_move_xy(CardNo, CDbl(LINE_CMD_0.Text), CDbl(LINE_CMD_1.Text), 0, 200000, 0.1, 0.1)

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Dim Dimension As Integer
        Dim Axis_ID_Array_For_2Axes_ArcMove(2) As Integer
        Dim Center_Pos_Array(2) As Integer
        Dim Max_Arc_Speed As Integer
        Dim Angle As Integer
        'Dim AxisNo As Integer

        Dimension = 2
        Axis_ID_Array_For_2Axes_ArcMove(0) = 0
        Axis_ID_Array_For_2Axes_ArcMove(1) = 1
        Center_Pos_Array(0) = CInt(ARC_CMD_0.Text)
        Center_Pos_Array(1) = CInt(ARC_CMD_1.Text)
        Max_Arc_Speed = 50000
        Angle = 180
        'Others setting like ACC,Dec... are reference to master axis (smallest axisno in Axis_ID_Array)

        'Function_Result(APS_set_axis_param(1, 4, 0))  'Set PRA_ALM_LOGIC

        APS_relative_arc_move(Dimension, Axis_ID_Array_For_2Axes_ArcMove, Center_Pos_Array, Max_Arc_Speed, Angle)

        'B_8102_start_tr_arc_xy(CardNo, CDbl(ARC_CMD_0.Text), CDbl(ARC_CMD_1.Text), 0, 0, 1, 0, 200000, 0.1, 0.1)

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        Dim i, j As Integer

        For i = 0 To MAX_CARDS_PCI_8102

            If CARDS_PCI_8102_Status(i) = True Then

                Dim StartAxisID As Integer = 0
                Dim TotalAxisNum As Integer = 0


                APS_get_first_axisId(i, StartAxisID, TotalAxisNum)

                For j = StartAxisID To (StartAxisID + TotalAxisNum - 1) Step 1


                    APS_set_command(j, 0)
                    APS_set_position(j, 0)

                    'B_8102_set_position(2 * i, 0)
                    'B_8102_set_command(2 * i, 0)

                    'B_8102_set_position((2 * i) + 1, 0)
                    'B_8102_set_command((2 * i) + 1, 0)

                Next j

            End If
        Next i
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        Dim i, j As Integer
        For i = 0 To MAX_CARDS_PCI_8102


            If CARDS_PCI_8102_Status(i) = True Then

                Dim StartAxisID As Integer = 0
                Dim TotalAxisNum As Integer = 0


                APS_get_first_axisId(i, StartAxisID, TotalAxisNum)

                For j = StartAxisID To (StartAxisID + TotalAxisNum - 1) Step 1


                    'B_8102_emg_stop(2 * i)
                    'B_8102_emg_stop((2 * i) + 1)


                    APS_emg_stop(j)

                Next j

            End If

        Next i
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Dim i As Integer, CurPos As Double, CurSpeed As Double
        Dim io_sts As Integer, MOT_STS As Integer
        'Dim Ckp As Double
        Dim PCMD As Long

        'For i = 2 * CardNo To 2 * CardNo + 1
        ' Display Next Compare Data
        'B_8102_check_compare_data(i, 5, Ckp)
        'CMPP(i).Text = Str(Ckp)
        'Next

        'For i = 0 To MAX_CARDS_PCI_8102
        i = 0

        If CARDS_PCI_8102_Status(i) = True Then

            APS_get_position(2 * i, CurPos)
            Pos0.Text = Str(CurPos)
            APS_get_position((2 * i) + 1, CurPos)
            Pos1.Text = Str(CurPos)

            APS_get_command_velocity(2 * i, CurSpeed)
            Speed0.Text = Str(CurSpeed)
            APS_get_command_velocity((2 * i) + 1, CurSpeed)
            Speed1.Text = Str(CurSpeed)

            io_sts = APS_motion_io_status(2 * i)
            IOSts0.Text = Hex(io_sts)
            io_sts = APS_motion_io_status((2 * i) + 1)
            IOSts1.Text = Hex(io_sts)

            MOT_STS = APS_motion_status(2 * i)
            MotSts0.Text = Str(MOT_STS)
            MOT_STS = APS_motion_status((2 * i) + 1)
            MotSts1.Text = Str(MOT_STS)

            APS_get_command(2 * i, PCMD)
            CMD0.Text = Str(PCMD)
            APS_get_command((2 * i) + 1, PCMD)
            CMD1.Text = Str(PCMD)
        End If
        'Next i

        If (AxisNo = 0 Or AxisNo = 1) And CheckBox1.Checked = True Then

            Dim get_status As Integer
            APS_get_axis_param(AxisNo, 554, get_status)     'PRA_GCMP_STS 0x22A

            CMP_STS.Text = Str(get_status)

        End If

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


    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click

        'Dim srtmsg As Short

        'Dim intret As Integer

        Dim AxisArray() As Integer = {0, 1}
        Dim distArray() As Integer = {8000.0, 12000.0}
        'Dim strvelArray() As Double = {0.0, 0.0}
        'Dim maxvelArray() As Double = {4000, 6000}
        'Dim TaccArray() As Double = {0.04, 0.06}
        'Dim TdecArray() As Double = {0.04, 0.06}


        'srtmsg = B_8102_set_tr_move_all(2, AxisArray, distArray, strvelArray, maxvelArray, TaccArray, TdecArray)

        'srtmsg = B_8102_start_move_all(AxisArray(0))

        APS_relative_linear_move(2, AxisArray, distArray, 4000)


    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        'B_8102_stop_move_all(2 * CardNo)

        APS_emg_stop(2 * CardNo)
        APS_emg_stop((2 * CardNo) + 1)

    End Sub


    Private Sub testsub(ByVal sender() As Double)

        MsgBox(sender)

    End Sub

End Class
