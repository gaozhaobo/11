<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Axis_Monitor
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing AndAlso components IsNot Nothing Then
            components.Dispose()
        End If
        MyBase.Dispose(disposing)
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Axis_Monitor))
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Label1 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.Button1 = New System.Windows.Forms.Button
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.CheckBox9 = New System.Windows.Forms.CheckBox
        Me.CheckBox8 = New System.Windows.Forms.CheckBox
        Me.CheckBox7 = New System.Windows.Forms.CheckBox
        Me.CheckBox6 = New System.Windows.Forms.CheckBox
        Me.CheckBox5 = New System.Windows.Forms.CheckBox
        Me.CheckBox4 = New System.Windows.Forms.CheckBox
        Me.CheckBox3 = New System.Windows.Forms.CheckBox
        Me.CheckBox2 = New System.Windows.Forms.CheckBox
        Me.CheckBox1 = New System.Windows.Forms.CheckBox
        Me.Button3 = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.CheckBox19 = New System.Windows.Forms.CheckBox
        Me.CheckBox18 = New System.Windows.Forms.CheckBox
        Me.CheckBox17 = New System.Windows.Forms.CheckBox
        Me.CheckBox16 = New System.Windows.Forms.CheckBox
        Me.CheckBox15 = New System.Windows.Forms.CheckBox
        Me.CheckBox14 = New System.Windows.Forms.CheckBox
        Me.CheckBox13 = New System.Windows.Forms.CheckBox
        Me.CheckBox12 = New System.Windows.Forms.CheckBox
        Me.CheckBox11 = New System.Windows.Forms.CheckBox
        Me.CheckBox10 = New System.Windows.Forms.CheckBox
        Me.TextBox1 = New System.Windows.Forms.TextBox
        Me.TextBox2 = New System.Windows.Forms.TextBox
        Me.TextBox3 = New System.Windows.Forms.TextBox
        Me.TextBox4 = New System.Windows.Forms.TextBox
        Me.TextBox5 = New System.Windows.Forms.TextBox
        Me.TextBox6 = New System.Windows.Forms.TextBox
        Me.TextBox7 = New System.Windows.Forms.TextBox
        Me.TextBox8 = New System.Windows.Forms.TextBox
        Me.Label14 = New System.Windows.Forms.Label
        Me.Label15 = New System.Windows.Forms.Label
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'ComboBox1
        '
        Me.ComboBox1.FormattingEnabled = True
        Me.ComboBox1.Location = New System.Drawing.Point(130, 12)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(89, 20)
        Me.ComboBox1.TabIndex = 1
        '
        'Timer1
        '
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(24, 15)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(47, 12)
        Me.Label1.TabIndex = 2
        Me.Label1.Text = "Axis ID :"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(24, 49)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(100, 12)
        Me.Label2.TabIndex = 3
        Me.Label2.Text = "Command Position :"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(29, 80)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(95, 12)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Feedback Position :"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(43, 116)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(81, 12)
        Me.Label4.TabIndex = 5
        Me.Label4.Text = "Target Position :"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Location = New System.Drawing.Point(48, 149)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(76, 12)
        Me.Label5.TabIndex = 6
        Me.Label5.Text = "Error Position :"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(22, 179)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(102, 12)
        Me.Label6.TabIndex = 7
        Me.Label6.Text = "Command Velocity :"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(27, 213)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(97, 12)
        Me.Label7.TabIndex = 8
        Me.Label7.Text = "Feedback Velocity :"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(31, 313)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(93, 23)
        Me.Button1.TabIndex = 15
        Me.Button1.Text = "Reset Position"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.CheckBox9)
        Me.GroupBox1.Controls.Add(Me.CheckBox8)
        Me.GroupBox1.Controls.Add(Me.CheckBox7)
        Me.GroupBox1.Controls.Add(Me.CheckBox6)
        Me.GroupBox1.Controls.Add(Me.CheckBox5)
        Me.GroupBox1.Controls.Add(Me.CheckBox4)
        Me.GroupBox1.Controls.Add(Me.CheckBox3)
        Me.GroupBox1.Controls.Add(Me.CheckBox2)
        Me.GroupBox1.Controls.Add(Me.CheckBox1)
        Me.GroupBox1.Location = New System.Drawing.Point(320, 6)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(88, 330)
        Me.GroupBox1.TabIndex = 16
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Motion I/O"
        '
        'CheckBox9
        '
        Me.CheckBox9.AutoSize = True
        Me.CheckBox9.Location = New System.Drawing.Point(6, 202)
        Me.CheckBox9.Name = "CheckBox9"
        Me.CheckBox9.Size = New System.Drawing.Size(48, 16)
        Me.CheckBox9.TabIndex = 9
        Me.CheckBox9.Text = "RDY"
        Me.CheckBox9.UseVisualStyleBackColor = True
        '
        'CheckBox8
        '
        Me.CheckBox8.AutoSize = True
        Me.CheckBox8.Location = New System.Drawing.Point(6, 180)
        Me.CheckBox8.Name = "CheckBox8"
        Me.CheckBox8.Size = New System.Drawing.Size(54, 16)
        Me.CheckBox8.TabIndex = 7
        Me.CheckBox8.Text = "SVON"
        Me.CheckBox8.UseVisualStyleBackColor = True
        '
        'CheckBox7
        '
        Me.CheckBox7.AutoSize = True
        Me.CheckBox7.Location = New System.Drawing.Point(6, 158)
        Me.CheckBox7.Name = "CheckBox7"
        Me.CheckBox7.Size = New System.Drawing.Size(42, 16)
        Me.CheckBox7.TabIndex = 6
        Me.CheckBox7.Text = "INP"
        Me.CheckBox7.UseVisualStyleBackColor = True
        '
        'CheckBox6
        '
        Me.CheckBox6.AutoSize = True
        Me.CheckBox6.Location = New System.Drawing.Point(6, 136)
        Me.CheckBox6.Name = "CheckBox6"
        Me.CheckBox6.Size = New System.Drawing.Size(38, 16)
        Me.CheckBox6.TabIndex = 5
        Me.CheckBox6.Text = "EZ"
        Me.CheckBox6.UseVisualStyleBackColor = True
        '
        'CheckBox5
        '
        Me.CheckBox5.AutoSize = True
        Me.CheckBox5.Location = New System.Drawing.Point(6, 114)
        Me.CheckBox5.Name = "CheckBox5"
        Me.CheckBox5.Size = New System.Drawing.Size(49, 16)
        Me.CheckBox5.TabIndex = 4
        Me.CheckBox5.Text = "EMG"
        Me.CheckBox5.UseVisualStyleBackColor = True
        '
        'CheckBox4
        '
        Me.CheckBox4.AutoSize = True
        Me.CheckBox4.Location = New System.Drawing.Point(6, 92)
        Me.CheckBox4.Name = "CheckBox4"
        Me.CheckBox4.Size = New System.Drawing.Size(48, 16)
        Me.CheckBox4.TabIndex = 3
        Me.CheckBox4.Text = "ORG"
        Me.CheckBox4.UseVisualStyleBackColor = True
        '
        'CheckBox3
        '
        Me.CheckBox3.AutoSize = True
        Me.CheckBox3.Location = New System.Drawing.Point(6, 70)
        Me.CheckBox3.Name = "CheckBox3"
        Me.CheckBox3.Size = New System.Drawing.Size(48, 16)
        Me.CheckBox3.TabIndex = 2
        Me.CheckBox3.Text = "MEL"
        Me.CheckBox3.UseVisualStyleBackColor = True
        '
        'CheckBox2
        '
        Me.CheckBox2.AutoSize = True
        Me.CheckBox2.Location = New System.Drawing.Point(6, 48)
        Me.CheckBox2.Name = "CheckBox2"
        Me.CheckBox2.Size = New System.Drawing.Size(44, 16)
        Me.CheckBox2.TabIndex = 1
        Me.CheckBox2.Text = "PEL"
        Me.CheckBox2.UseVisualStyleBackColor = True
        '
        'CheckBox1
        '
        Me.CheckBox1.AutoSize = True
        Me.CheckBox1.Location = New System.Drawing.Point(6, 26)
        Me.CheckBox1.Name = "CheckBox1"
        Me.CheckBox1.Size = New System.Drawing.Size(49, 16)
        Me.CheckBox1.TabIndex = 0
        Me.CheckBox1.Text = "ALM"
        Me.CheckBox1.UseVisualStyleBackColor = True
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(240, 44)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(65, 23)
        Me.Button3.TabIndex = 9
        Me.Button3.Text = "SVOFF"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(240, 12)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(65, 23)
        Me.Button2.TabIndex = 8
        Me.Button2.Text = "SVON"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.CheckBox19)
        Me.GroupBox2.Controls.Add(Me.CheckBox18)
        Me.GroupBox2.Controls.Add(Me.CheckBox17)
        Me.GroupBox2.Controls.Add(Me.CheckBox16)
        Me.GroupBox2.Controls.Add(Me.CheckBox15)
        Me.GroupBox2.Controls.Add(Me.CheckBox14)
        Me.GroupBox2.Controls.Add(Me.CheckBox13)
        Me.GroupBox2.Controls.Add(Me.CheckBox12)
        Me.GroupBox2.Controls.Add(Me.CheckBox11)
        Me.GroupBox2.Controls.Add(Me.CheckBox10)
        Me.GroupBox2.Location = New System.Drawing.Point(427, 6)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(88, 330)
        Me.GroupBox2.TabIndex = 17
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Motion Status"
        '
        'CheckBox19
        '
        Me.CheckBox19.AutoSize = True
        Me.CheckBox19.Location = New System.Drawing.Point(6, 228)
        Me.CheckBox19.Name = "CheckBox19"
        Me.CheckBox19.Size = New System.Drawing.Size(44, 16)
        Me.CheckBox19.TabIndex = 18
        Me.CheckBox19.Text = "EZS"
        Me.CheckBox19.UseVisualStyleBackColor = True
        '
        'CheckBox18
        '
        Me.CheckBox18.AutoSize = True
        Me.CheckBox18.Location = New System.Drawing.Point(6, 202)
        Me.CheckBox18.Name = "CheckBox18"
        Me.CheckBox18.Size = New System.Drawing.Size(54, 16)
        Me.CheckBox18.TabIndex = 17
        Me.CheckBox18.Text = "ORGS"
        Me.CheckBox18.UseVisualStyleBackColor = True
        '
        'CheckBox17
        '
        Me.CheckBox17.AutoSize = True
        Me.CheckBox17.Location = New System.Drawing.Point(6, 180)
        Me.CheckBox17.Name = "CheckBox17"
        Me.CheckBox17.Size = New System.Drawing.Size(55, 16)
        Me.CheckBox17.TabIndex = 16
        Me.CheckBox17.Text = "HMES"
        Me.CheckBox17.UseVisualStyleBackColor = True
        '
        'CheckBox16
        '
        Me.CheckBox16.AutoSize = True
        Me.CheckBox16.Location = New System.Drawing.Point(6, 158)
        Me.CheckBox16.Name = "CheckBox16"
        Me.CheckBox16.Size = New System.Drawing.Size(60, 16)
        Me.CheckBox16.TabIndex = 15
        Me.CheckBox16.Text = "SMELS"
        Me.CheckBox16.UseVisualStyleBackColor = True
        '
        'CheckBox15
        '
        Me.CheckBox15.AutoSize = True
        Me.CheckBox15.Location = New System.Drawing.Point(6, 134)
        Me.CheckBox15.Name = "CheckBox15"
        Me.CheckBox15.Size = New System.Drawing.Size(56, 16)
        Me.CheckBox15.TabIndex = 14
        Me.CheckBox15.Text = "SPELS"
        Me.CheckBox15.UseVisualStyleBackColor = True
        '
        'CheckBox14
        '
        Me.CheckBox14.AutoSize = True
        Me.CheckBox14.Location = New System.Drawing.Point(6, 112)
        Me.CheckBox14.Name = "CheckBox14"
        Me.CheckBox14.Size = New System.Drawing.Size(54, 16)
        Me.CheckBox14.TabIndex = 13
        Me.CheckBox14.Text = "MELS"
        Me.CheckBox14.UseVisualStyleBackColor = True
        '
        'CheckBox13
        '
        Me.CheckBox13.AutoSize = True
        Me.CheckBox13.Location = New System.Drawing.Point(6, 92)
        Me.CheckBox13.Name = "CheckBox13"
        Me.CheckBox13.Size = New System.Drawing.Size(50, 16)
        Me.CheckBox13.TabIndex = 12
        Me.CheckBox13.Text = "PELS"
        Me.CheckBox13.UseVisualStyleBackColor = True
        '
        'CheckBox12
        '
        Me.CheckBox12.AutoSize = True
        Me.CheckBox12.Location = New System.Drawing.Point(6, 70)
        Me.CheckBox12.Name = "CheckBox12"
        Me.CheckBox12.Size = New System.Drawing.Size(55, 16)
        Me.CheckBox12.TabIndex = 11
        Me.CheckBox12.Text = "ALMS"
        Me.CheckBox12.UseVisualStyleBackColor = True
        '
        'CheckBox11
        '
        Me.CheckBox11.AutoSize = True
        Me.CheckBox11.Location = New System.Drawing.Point(6, 48)
        Me.CheckBox11.Name = "CheckBox11"
        Me.CheckBox11.Size = New System.Drawing.Size(55, 16)
        Me.CheckBox11.TabIndex = 10
        Me.CheckBox11.Text = "EMGS"
        Me.CheckBox11.UseVisualStyleBackColor = True
        '
        'CheckBox10
        '
        Me.CheckBox10.AutoSize = True
        Me.CheckBox10.Location = New System.Drawing.Point(6, 26)
        Me.CheckBox10.Name = "CheckBox10"
        Me.CheckBox10.Size = New System.Drawing.Size(50, 16)
        Me.CheckBox10.TabIndex = 9
        Me.CheckBox10.Text = "MDN"
        Me.CheckBox10.UseVisualStyleBackColor = True
        '
        'TextBox1
        '
        Me.TextBox1.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox1.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox1.Location = New System.Drawing.Point(130, 46)
        Me.TextBox1.Name = "TextBox1"
        Me.TextBox1.Size = New System.Drawing.Size(91, 22)
        Me.TextBox1.TabIndex = 18
        '
        'TextBox2
        '
        Me.TextBox2.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox2.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox2.Location = New System.Drawing.Point(130, 79)
        Me.TextBox2.Name = "TextBox2"
        Me.TextBox2.Size = New System.Drawing.Size(91, 22)
        Me.TextBox2.TabIndex = 19
        '
        'TextBox3
        '
        Me.TextBox3.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox3.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox3.Location = New System.Drawing.Point(130, 112)
        Me.TextBox3.Name = "TextBox3"
        Me.TextBox3.Size = New System.Drawing.Size(91, 22)
        Me.TextBox3.TabIndex = 20
        '
        'TextBox4
        '
        Me.TextBox4.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox4.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox4.Location = New System.Drawing.Point(130, 146)
        Me.TextBox4.Name = "TextBox4"
        Me.TextBox4.Size = New System.Drawing.Size(91, 22)
        Me.TextBox4.TabIndex = 21
        '
        'TextBox5
        '
        Me.TextBox5.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox5.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox5.Location = New System.Drawing.Point(130, 179)
        Me.TextBox5.Name = "TextBox5"
        Me.TextBox5.Size = New System.Drawing.Size(91, 22)
        Me.TextBox5.TabIndex = 22
        '
        'TextBox6
        '
        Me.TextBox6.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox6.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox6.Location = New System.Drawing.Point(130, 212)
        Me.TextBox6.Name = "TextBox6"
        Me.TextBox6.Size = New System.Drawing.Size(91, 22)
        Me.TextBox6.TabIndex = 23
        '
        'TextBox7
        '
        Me.TextBox7.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox7.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox7.Location = New System.Drawing.Point(130, 244)
        Me.TextBox7.Name = "TextBox7"
        Me.TextBox7.Size = New System.Drawing.Size(91, 22)
        Me.TextBox7.TabIndex = 24
        '
        'TextBox8
        '
        Me.TextBox8.BackColor = System.Drawing.SystemColors.Desktop
        Me.TextBox8.ForeColor = System.Drawing.SystemColors.GradientInactiveCaption
        Me.TextBox8.Location = New System.Drawing.Point(130, 275)
        Me.TextBox8.Name = "TextBox8"
        Me.TextBox8.Size = New System.Drawing.Size(91, 22)
        Me.TextBox8.TabIndex = 25
        '
        'Label14
        '
        Me.Label14.AutoSize = True
        Me.Label14.Location = New System.Drawing.Point(36, 247)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(88, 12)
        Me.Label14.TabIndex = 26
        Me.Label14.Text = "Motion IO status :"
        '
        'Label15
        '
        Me.Label15.AutoSize = True
        Me.Label15.Location = New System.Drawing.Point(51, 278)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(73, 12)
        Me.Label15.TabIndex = 27
        Me.Label15.Text = "Motion status :"
        '
        'Axis_Monitor
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.GradientActiveCaption
        Me.ClientSize = New System.Drawing.Size(541, 348)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.Label15)
        Me.Controls.Add(Me.Label14)
        Me.Controls.Add(Me.TextBox8)
        Me.Controls.Add(Me.TextBox7)
        Me.Controls.Add(Me.TextBox6)
        Me.Controls.Add(Me.TextBox5)
        Me.Controls.Add(Me.TextBox4)
        Me.Controls.Add(Me.TextBox3)
        Me.Controls.Add(Me.TextBox2)
        Me.Controls.Add(Me.TextBox1)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.ComboBox1)
        Me.ForeColor = System.Drawing.SystemColors.Desktop
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "Axis_Monitor"
        Me.ShowInTaskbar = False
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
        Me.Text = "Axis_Monitor"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents CheckBox8 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox7 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox6 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox5 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox4 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox3 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox2 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox1 As System.Windows.Forms.CheckBox
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents CheckBox19 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox18 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox17 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox16 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox15 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox14 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox13 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox12 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox11 As System.Windows.Forms.CheckBox
    Friend WithEvents CheckBox10 As System.Windows.Forms.CheckBox
    Friend WithEvents TextBox1 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox2 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox3 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox4 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox5 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox6 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox7 As System.Windows.Forms.TextBox
    Friend WithEvents TextBox8 As System.Windows.Forms.TextBox
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents Label15 As System.Windows.Forms.Label
    Friend WithEvents CheckBox9 As System.Windows.Forms.CheckBox

End Class
