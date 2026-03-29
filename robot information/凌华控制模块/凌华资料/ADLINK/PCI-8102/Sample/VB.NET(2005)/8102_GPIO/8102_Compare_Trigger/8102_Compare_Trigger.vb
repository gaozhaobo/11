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
    Friend WithEvents DO0 As System.Windows.Forms.CheckBox
    Friend WithEvents DO1 As System.Windows.Forms.CheckBox
    Friend WithEvents DO2 As System.Windows.Forms.CheckBox
    Friend WithEvents DO3 As System.Windows.Forms.CheckBox
    Friend WithEvents DO4 As System.Windows.Forms.CheckBox
    Friend WithEvents DO5 As System.Windows.Forms.CheckBox
    Friend WithEvents DO11 As System.Windows.Forms.CheckBox
    Friend WithEvents DO10 As System.Windows.Forms.CheckBox
    Friend WithEvents DO9 As System.Windows.Forms.CheckBox
    Friend WithEvents DO8 As System.Windows.Forms.CheckBox
    Friend WithEvents DO7 As System.Windows.Forms.CheckBox
    Friend WithEvents DO6 As System.Windows.Forms.CheckBox
    Friend WithEvents DO12 As System.Windows.Forms.CheckBox
    Friend WithEvents DO13 As System.Windows.Forms.CheckBox
    Friend WithEvents DO14 As System.Windows.Forms.CheckBox
    Friend WithEvents DO15 As System.Windows.Forms.CheckBox
    Friend WithEvents DI15 As System.Windows.Forms.CheckBox
    Friend WithEvents DI14 As System.Windows.Forms.CheckBox
    Friend WithEvents DI13 As System.Windows.Forms.CheckBox
    Friend WithEvents DI12 As System.Windows.Forms.CheckBox
    Friend WithEvents DI11 As System.Windows.Forms.CheckBox
    Friend WithEvents DI10 As System.Windows.Forms.CheckBox
    Friend WithEvents DI9 As System.Windows.Forms.CheckBox
    Friend WithEvents DI8 As System.Windows.Forms.CheckBox
    Friend WithEvents DI7 As System.Windows.Forms.CheckBox
    Friend WithEvents DI6 As System.Windows.Forms.CheckBox
    Friend WithEvents DI5 As System.Windows.Forms.CheckBox
    Friend WithEvents DI4 As System.Windows.Forms.CheckBox
    Friend WithEvents DI3 As System.Windows.Forms.CheckBox
    Friend WithEvents DI2 As System.Windows.Forms.CheckBox
    Friend WithEvents DI1 As System.Windows.Forms.CheckBox
    Friend WithEvents DI0 As System.Windows.Forms.CheckBox
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents group_id As System.Windows.Forms.TextBox
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents card_id As System.Windows.Forms.TextBox
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.DO0 = New System.Windows.Forms.CheckBox
        Me.DO1 = New System.Windows.Forms.CheckBox
        Me.DO2 = New System.Windows.Forms.CheckBox
        Me.DO3 = New System.Windows.Forms.CheckBox
        Me.DO4 = New System.Windows.Forms.CheckBox
        Me.DO5 = New System.Windows.Forms.CheckBox
        Me.DO11 = New System.Windows.Forms.CheckBox
        Me.DO10 = New System.Windows.Forms.CheckBox
        Me.DO9 = New System.Windows.Forms.CheckBox
        Me.DO8 = New System.Windows.Forms.CheckBox
        Me.DO7 = New System.Windows.Forms.CheckBox
        Me.DO6 = New System.Windows.Forms.CheckBox
        Me.DO12 = New System.Windows.Forms.CheckBox
        Me.DO13 = New System.Windows.Forms.CheckBox
        Me.DO14 = New System.Windows.Forms.CheckBox
        Me.DO15 = New System.Windows.Forms.CheckBox
        Me.DI15 = New System.Windows.Forms.CheckBox
        Me.DI14 = New System.Windows.Forms.CheckBox
        Me.DI13 = New System.Windows.Forms.CheckBox
        Me.DI12 = New System.Windows.Forms.CheckBox
        Me.DI11 = New System.Windows.Forms.CheckBox
        Me.DI10 = New System.Windows.Forms.CheckBox
        Me.DI9 = New System.Windows.Forms.CheckBox
        Me.DI8 = New System.Windows.Forms.CheckBox
        Me.DI7 = New System.Windows.Forms.CheckBox
        Me.DI6 = New System.Windows.Forms.CheckBox
        Me.DI5 = New System.Windows.Forms.CheckBox
        Me.DI4 = New System.Windows.Forms.CheckBox
        Me.DI3 = New System.Windows.Forms.CheckBox
        Me.DI2 = New System.Windows.Forms.CheckBox
        Me.DI1 = New System.Windows.Forms.CheckBox
        Me.DI0 = New System.Windows.Forms.CheckBox
        Me.Button1 = New System.Windows.Forms.Button
        Me.Label1 = New System.Windows.Forms.Label
        Me.card_id = New System.Windows.Forms.TextBox
        Me.Button2 = New System.Windows.Forms.Button
        Me.Button3 = New System.Windows.Forms.Button
        Me.group_id = New System.Windows.Forms.TextBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.SuspendLayout()
        '
        'DO0
        '
        Me.DO0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.DO0.Location = New System.Drawing.Point(64, 24)
        Me.DO0.Name = "DO0"
        Me.DO0.Size = New System.Drawing.Size(56, 24)
        Me.DO0.TabIndex = 0
        Me.DO0.Text = "DO0"
        '
        'DO1
        '
        Me.DO1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.DO1.Location = New System.Drawing.Point(64, 48)
        Me.DO1.Name = "DO1"
        Me.DO1.Size = New System.Drawing.Size(56, 24)
        Me.DO1.TabIndex = 1
        Me.DO1.Text = "DO1"
        '
        'DO2
        '
        Me.DO2.Location = New System.Drawing.Point(64, 72)
        Me.DO2.Name = "DO2"
        Me.DO2.Size = New System.Drawing.Size(56, 24)
        Me.DO2.TabIndex = 2
        Me.DO2.Text = "DO2"
        '
        'DO3
        '
        Me.DO3.Location = New System.Drawing.Point(64, 96)
        Me.DO3.Name = "DO3"
        Me.DO3.Size = New System.Drawing.Size(56, 24)
        Me.DO3.TabIndex = 3
        Me.DO3.Text = "DO3"
        '
        'DO4
        '
        Me.DO4.Location = New System.Drawing.Point(64, 120)
        Me.DO4.Name = "DO4"
        Me.DO4.Size = New System.Drawing.Size(56, 24)
        Me.DO4.TabIndex = 4
        Me.DO4.Text = "DO4"
        '
        'DO5
        '
        Me.DO5.Location = New System.Drawing.Point(64, 144)
        Me.DO5.Name = "DO5"
        Me.DO5.Size = New System.Drawing.Size(56, 24)
        Me.DO5.TabIndex = 5
        Me.DO5.Text = "DO5"
        '
        'DO11
        '
        Me.DO11.Location = New System.Drawing.Point(64, 288)
        Me.DO11.Name = "DO11"
        Me.DO11.Size = New System.Drawing.Size(56, 24)
        Me.DO11.TabIndex = 11
        Me.DO11.Text = "DO11"
        '
        'DO10
        '
        Me.DO10.Location = New System.Drawing.Point(64, 264)
        Me.DO10.Name = "DO10"
        Me.DO10.Size = New System.Drawing.Size(56, 24)
        Me.DO10.TabIndex = 10
        Me.DO10.Text = "DO10"
        '
        'DO9
        '
        Me.DO9.Location = New System.Drawing.Point(64, 240)
        Me.DO9.Name = "DO9"
        Me.DO9.Size = New System.Drawing.Size(56, 24)
        Me.DO9.TabIndex = 9
        Me.DO9.Text = "DO9"
        '
        'DO8
        '
        Me.DO8.Location = New System.Drawing.Point(64, 216)
        Me.DO8.Name = "DO8"
        Me.DO8.Size = New System.Drawing.Size(56, 24)
        Me.DO8.TabIndex = 8
        Me.DO8.Text = "DO8"
        '
        'DO7
        '
        Me.DO7.Location = New System.Drawing.Point(64, 192)
        Me.DO7.Name = "DO7"
        Me.DO7.Size = New System.Drawing.Size(56, 24)
        Me.DO7.TabIndex = 7
        Me.DO7.Text = "DO7"
        '
        'DO6
        '
        Me.DO6.Location = New System.Drawing.Point(64, 168)
        Me.DO6.Name = "DO6"
        Me.DO6.Size = New System.Drawing.Size(56, 24)
        Me.DO6.TabIndex = 6
        Me.DO6.Text = "DO6"
        '
        'DO12
        '
        Me.DO12.Location = New System.Drawing.Point(64, 312)
        Me.DO12.Name = "DO12"
        Me.DO12.Size = New System.Drawing.Size(56, 24)
        Me.DO12.TabIndex = 13
        Me.DO12.Text = "DO12"
        '
        'DO13
        '
        Me.DO13.Location = New System.Drawing.Point(64, 336)
        Me.DO13.Name = "DO13"
        Me.DO13.Size = New System.Drawing.Size(56, 24)
        Me.DO13.TabIndex = 14
        Me.DO13.Text = "DO13"
        '
        'DO14
        '
        Me.DO14.Location = New System.Drawing.Point(64, 360)
        Me.DO14.Name = "DO14"
        Me.DO14.Size = New System.Drawing.Size(56, 24)
        Me.DO14.TabIndex = 15
        Me.DO14.Text = "DO14"
        '
        'DO15
        '
        Me.DO15.Location = New System.Drawing.Point(64, 384)
        Me.DO15.Name = "DO15"
        Me.DO15.Size = New System.Drawing.Size(56, 24)
        Me.DO15.TabIndex = 16
        Me.DO15.Text = "DO15"
        '
        'DI15
        '
        Me.DI15.Location = New System.Drawing.Point(200, 387)
        Me.DI15.Name = "DI15"
        Me.DI15.Size = New System.Drawing.Size(56, 24)
        Me.DI15.TabIndex = 32
        Me.DI15.Text = "DI15"
        '
        'DI14
        '
        Me.DI14.Location = New System.Drawing.Point(200, 363)
        Me.DI14.Name = "DI14"
        Me.DI14.Size = New System.Drawing.Size(56, 24)
        Me.DI14.TabIndex = 31
        Me.DI14.Text = "DI14"
        '
        'DI13
        '
        Me.DI13.Location = New System.Drawing.Point(200, 339)
        Me.DI13.Name = "DI13"
        Me.DI13.Size = New System.Drawing.Size(56, 24)
        Me.DI13.TabIndex = 30
        Me.DI13.Text = "DI13"
        '
        'DI12
        '
        Me.DI12.Location = New System.Drawing.Point(200, 315)
        Me.DI12.Name = "DI12"
        Me.DI12.Size = New System.Drawing.Size(56, 24)
        Me.DI12.TabIndex = 29
        Me.DI12.Text = "DI12"
        '
        'DI11
        '
        Me.DI11.Location = New System.Drawing.Point(200, 291)
        Me.DI11.Name = "DI11"
        Me.DI11.Size = New System.Drawing.Size(56, 24)
        Me.DI11.TabIndex = 28
        Me.DI11.Text = "DI11"
        '
        'DI10
        '
        Me.DI10.Location = New System.Drawing.Point(200, 267)
        Me.DI10.Name = "DI10"
        Me.DI10.Size = New System.Drawing.Size(56, 24)
        Me.DI10.TabIndex = 27
        Me.DI10.Text = "DI10"
        '
        'DI9
        '
        Me.DI9.Location = New System.Drawing.Point(200, 243)
        Me.DI9.Name = "DI9"
        Me.DI9.Size = New System.Drawing.Size(56, 24)
        Me.DI9.TabIndex = 26
        Me.DI9.Text = "DI9"
        '
        'DI8
        '
        Me.DI8.Location = New System.Drawing.Point(200, 219)
        Me.DI8.Name = "DI8"
        Me.DI8.Size = New System.Drawing.Size(56, 24)
        Me.DI8.TabIndex = 25
        Me.DI8.Text = "DI8"
        '
        'DI7
        '
        Me.DI7.Location = New System.Drawing.Point(200, 195)
        Me.DI7.Name = "DI7"
        Me.DI7.Size = New System.Drawing.Size(56, 24)
        Me.DI7.TabIndex = 24
        Me.DI7.Text = "DI7"
        '
        'DI6
        '
        Me.DI6.Location = New System.Drawing.Point(200, 171)
        Me.DI6.Name = "DI6"
        Me.DI6.Size = New System.Drawing.Size(56, 24)
        Me.DI6.TabIndex = 23
        Me.DI6.Text = "DI6"
        '
        'DI5
        '
        Me.DI5.Location = New System.Drawing.Point(200, 147)
        Me.DI5.Name = "DI5"
        Me.DI5.Size = New System.Drawing.Size(56, 24)
        Me.DI5.TabIndex = 22
        Me.DI5.Text = "DI5"
        '
        'DI4
        '
        Me.DI4.Location = New System.Drawing.Point(200, 123)
        Me.DI4.Name = "DI4"
        Me.DI4.Size = New System.Drawing.Size(56, 24)
        Me.DI4.TabIndex = 21
        Me.DI4.Text = "DI4"
        '
        'DI3
        '
        Me.DI3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.DI3.Location = New System.Drawing.Point(200, 99)
        Me.DI3.Name = "DI3"
        Me.DI3.Size = New System.Drawing.Size(56, 24)
        Me.DI3.TabIndex = 20
        Me.DI3.Text = "DI3"
        '
        'DI2
        '
        Me.DI2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.DI2.Location = New System.Drawing.Point(200, 75)
        Me.DI2.Name = "DI2"
        Me.DI2.Size = New System.Drawing.Size(56, 24)
        Me.DI2.TabIndex = 19
        Me.DI2.Text = "DI2"
        '
        'DI1
        '
        Me.DI1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.DI1.Location = New System.Drawing.Point(200, 51)
        Me.DI1.Name = "DI1"
        Me.DI1.Size = New System.Drawing.Size(56, 24)
        Me.DI1.TabIndex = 18
        Me.DI1.Text = "DI1"
        '
        'DI0
        '
        Me.DI0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.DI0.Location = New System.Drawing.Point(200, 27)
        Me.DI0.Name = "DI0"
        Me.DI0.Size = New System.Drawing.Size(56, 24)
        Me.DI0.TabIndex = 17
        Me.DI0.Text = "DI0"
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button1.Location = New System.Drawing.Point(360, 143)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(128, 40)
        Me.Button1.TabIndex = 33
        Me.Button1.Text = "set_gpio_output"
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label1.Location = New System.Drawing.Point(368, 40)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(66, 24)
        Me.Label1.TabIndex = 34
        Me.Label1.Text = "Card:"
        '
        'card_id
        '
        Me.card_id.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.card_id.Location = New System.Drawing.Point(440, 32)
        Me.card_id.Name = "card_id"
        Me.card_id.Size = New System.Drawing.Size(48, 27)
        Me.card_id.TabIndex = 35
        Me.card_id.Text = "0"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button2.Location = New System.Drawing.Point(360, 216)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(128, 40)
        Me.Button2.TabIndex = 36
        Me.Button2.Text = "get_gpio_output"
        '
        'Button3
        '
        Me.Button3.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button3.Location = New System.Drawing.Point(360, 288)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(128, 40)
        Me.Button3.TabIndex = 37
        Me.Button3.Text = "get_gpio_input"
        '
        'group_id
        '
        Me.group_id.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.group_id.Location = New System.Drawing.Point(440, 72)
        Me.group_id.Name = "group_id"
        Me.group_id.Size = New System.Drawing.Size(48, 27)
        Me.group_id.TabIndex = 39
        Me.group_id.Text = "0"
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label2.Location = New System.Drawing.Point(368, 80)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(66, 24)
        Me.Label2.TabIndex = 38
        Me.Label2.Text = "Group:"
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 15)
        Me.ClientSize = New System.Drawing.Size(568, 438)
        Me.Controls.Add(Me.group_id)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.card_id)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.DI15)
        Me.Controls.Add(Me.DI14)
        Me.Controls.Add(Me.DI13)
        Me.Controls.Add(Me.DI12)
        Me.Controls.Add(Me.DI11)
        Me.Controls.Add(Me.DI10)
        Me.Controls.Add(Me.DI9)
        Me.Controls.Add(Me.DI8)
        Me.Controls.Add(Me.DI7)
        Me.Controls.Add(Me.DI6)
        Me.Controls.Add(Me.DI5)
        Me.Controls.Add(Me.DI4)
        Me.Controls.Add(Me.DI3)
        Me.Controls.Add(Me.DI2)
        Me.Controls.Add(Me.DI1)
        Me.Controls.Add(Me.DI0)
        Me.Controls.Add(Me.DO15)
        Me.Controls.Add(Me.DO14)
        Me.Controls.Add(Me.DO13)
        Me.Controls.Add(Me.DO12)
        Me.Controls.Add(Me.DO11)
        Me.Controls.Add(Me.DO10)
        Me.Controls.Add(Me.DO9)
        Me.Controls.Add(Me.DO8)
        Me.Controls.Add(Me.DO7)
        Me.Controls.Add(Me.DO6)
        Me.Controls.Add(Me.DO5)
        Me.Controls.Add(Me.DO4)
        Me.Controls.Add(Me.DO3)
        Me.Controls.Add(Me.DO2)
        Me.Controls.Add(Me.DO1)
        Me.Controls.Add(Me.DO0)
        Me.Name = "Form1"
        Me.Text = "8102_Compare_Trigger"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

#End Region

    Dim do_value As Integer
    Dim di_value As Integer

    Dim CardNo As Integer
    Dim AxisNo As Integer
    Dim TotalCard As Integer


    Public MAX_CARDS_PCI_8102 As Integer = 0
    Public CARDS_PCI_8102_Status(16) As Boolean

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        do_value = 0

        If DO0.Checked = True Then do_value = do_value + 2 ^ 0
        If DO1.Checked = True Then do_value = do_value + 2 ^ 1
        If DO2.Checked = True Then do_value = do_value + 2 ^ 2
        If DO3.Checked = True Then do_value = do_value + 2 ^ 3
        If DO4.Checked = True Then do_value = do_value + 2 ^ 4
        If DO5.Checked = True Then do_value = do_value + 2 ^ 5
        If DO6.Checked = True Then do_value = do_value + 2 ^ 6
        If DO7.Checked = True Then do_value = do_value + 2 ^ 7
        If DO8.Checked = True Then do_value = do_value + 2 ^ 8
        If DO9.Checked = True Then do_value = do_value + 2 ^ 9
        If DO10.Checked = True Then do_value = do_value + 2 ^ 10
        If DO11.Checked = True Then do_value = do_value + 2 ^ 11
        If DO12.Checked = True Then do_value = do_value + 2 ^ 12
        If DO13.Checked = True Then do_value = do_value + 2 ^ 13
        If DO14.Checked = True Then do_value = do_value + 2 ^ 14
        If DO15.Checked = True Then do_value = do_value + 2 ^ 15

        'B_8102_set_gpio_output(CInt(card_id.Text), do_value)

        APS_write_d_output(CInt(card_id.Text), CInt(group_id.Text), do_value)

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click

        'B_8102_get_gpio_output(card_id.Text, do_value)
        APS_read_d_output(CInt(card_id.Text), CInt(group_id.Text), do_value)

        If do_value And 2 ^ 0 Then DO0.Checked = True Else DO0.Checked = False
        If do_value And 2 ^ 1 Then DO1.Checked = True Else DO1.Checked = False
        If do_value And 2 ^ 2 Then DO2.Checked = True Else DO2.Checked = False
        If do_value And 2 ^ 3 Then DO3.Checked = True Else DO3.Checked = False
        If do_value And 2 ^ 4 Then DO4.Checked = True Else DO4.Checked = False
        If do_value And 2 ^ 5 Then DO5.Checked = True Else DO5.Checked = False
        If do_value And 2 ^ 6 Then DO6.Checked = True Else DO6.Checked = False
        If do_value And 2 ^ 7 Then DO7.Checked = True Else DO7.Checked = False
        If do_value And 2 ^ 8 Then DO8.Checked = True Else DO8.Checked = False
        If do_value And 2 ^ 9 Then DO9.Checked = True Else DO9.Checked = False
        If do_value And 2 ^ 10 Then DO10.Checked = True Else DO10.Checked = False
        If do_value And 2 ^ 11 Then DO11.Checked = True Else DO11.Checked = False
        If do_value And 2 ^ 12 Then DO12.Checked = True Else DO12.Checked = False
        If do_value And 2 ^ 13 Then DO13.Checked = True Else DO13.Checked = False
        If do_value And 2 ^ 14 Then DO14.Checked = True Else DO14.Checked = False
        If do_value And 2 ^ 15 Then DO15.Checked = True Else DO15.Checked = False



    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click

        'B_8102_get_gpio_input(CInt(card_id.Text), di_value)
        APS_read_d_input(CInt(card_id.Text), CInt(group_id.Text), di_value)

        If di_value And 2 ^ 0 Then DI0.Checked = True Else DI0.Checked = False
        If di_value And 2 ^ 1 Then DI1.Checked = True Else DI1.Checked = False
        If di_value And 2 ^ 2 Then DI2.Checked = True Else DI2.Checked = False
        If di_value And 2 ^ 3 Then DI3.Checked = True Else DI3.Checked = False
        If di_value And 2 ^ 4 Then DI4.Checked = True Else DI4.Checked = False
        If di_value And 2 ^ 5 Then DI5.Checked = True Else DI5.Checked = False
        If di_value And 2 ^ 6 Then DI6.Checked = True Else DI6.Checked = False
        If di_value And 2 ^ 7 Then DI7.Checked = True Else DI7.Checked = False
        If di_value And 2 ^ 8 Then DI8.Checked = True Else DI8.Checked = False
        If di_value And 2 ^ 9 Then DI9.Checked = True Else DI9.Checked = False
        If di_value And 2 ^ 10 Then DI10.Checked = True Else DI10.Checked = False
        If di_value And 2 ^ 11 Then DI11.Checked = True Else DI11.Checked = False
        If di_value And 2 ^ 12 Then DI12.Checked = True Else DI12.Checked = False
        If di_value And 2 ^ 13 Then DI13.Checked = True Else DI13.Checked = False
        If di_value And 2 ^ 14 Then DI14.Checked = True Else DI14.Checked = False
        If di_value And 2 ^ 15 Then DI15.Checked = True Else DI15.Checked = False


    End Sub

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

        'B_8102_config_from_file()

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
    Public Function CARDS_Status(ByVal intCARDS_PCI_Status As Integer, ByRef Max_CARDS_PCI_Status As Integer, ByRef CARDS_PCI_Status() As Boolean) As Integer

        'intCARDS_PCI_Status = MAX_CARDS_PCI_8102
        'CARDS_PCI_Status = CARDS_PCI_8102_Status



        Dim Total_CARDS_PCI_Status As Integer = 0

        Dim N As Integer
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


    Private Sub Form1_Closing(ByVal sender As Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles MyBase.Closing
        'B_8102_close()
        APS_close()
    End Sub

    
End Class
