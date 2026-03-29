<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.ComboBox1 = New System.Windows.Forms.ComboBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.Button5 = New System.Windows.Forms.Button
        Me.Button4 = New System.Windows.Forms.Button
        Me.Button3 = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.Button1 = New System.Windows.Forms.Button
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.Button13 = New System.Windows.Forms.Button
        Me.Button12 = New System.Windows.Forms.Button
        Me.Button7 = New System.Windows.Forms.Button
        Me.Button8 = New System.Windows.Forms.Button
        Me.Button9 = New System.Windows.Forms.Button
        Me.Button10 = New System.Windows.Forms.Button
        Me.Button11 = New System.Windows.Forms.Button
        Me.GroupBox3 = New System.Windows.Forms.GroupBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.tbDelayTime = New System.Windows.Forms.TextBox
        Me.btnRepeatMove = New System.Windows.Forms.Button
        Me.GroupBox4 = New System.Windows.Forms.GroupBox
        Me.Button23 = New System.Windows.Forms.Button
        Me.Button20 = New System.Windows.Forms.Button
        Me.Button21 = New System.Windows.Forms.Button
        Me.OpenFileDialog1 = New System.Windows.Forms.OpenFileDialog
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.ComboBox1)
        Me.GroupBox1.Controls.Add(Me.Label1)
        Me.GroupBox1.Controls.Add(Me.Button5)
        Me.GroupBox1.Controls.Add(Me.Button4)
        Me.GroupBox1.Controls.Add(Me.Button3)
        Me.GroupBox1.Controls.Add(Me.Button2)
        Me.GroupBox1.Controls.Add(Me.Button1)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 12)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(126, 268)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Start here"
        '
        'ComboBox1
        '
        Me.ComboBox1.FormattingEnabled = True
        Me.ComboBox1.Location = New System.Drawing.Point(14, 195)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(98, 20)
        Me.ComboBox1.TabIndex = 6
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(12, 171)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(100, 12)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "Input Target 1st axis"
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(14, 137)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(98, 23)
        Me.Button5.TabIndex = 4
        Me.Button5.Text = "Load Param"
        Me.Button5.UseVisualStyleBackColor = True
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(14, 108)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(98, 23)
        Me.Button4.TabIndex = 3
        Me.Button4.Text = "Axis Monitor"
        Me.Button4.UseVisualStyleBackColor = True
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(14, 79)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(98, 23)
        Me.Button3.TabIndex = 2
        Me.Button3.Text = "Get Version"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(14, 50)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(98, 23)
        Me.Button2.TabIndex = 1
        Me.Button2.Text = "Close"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(14, 21)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(98, 23)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "Initial"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.Button13)
        Me.GroupBox2.Controls.Add(Me.Button12)
        Me.GroupBox2.Controls.Add(Me.Button7)
        Me.GroupBox2.Controls.Add(Me.Button8)
        Me.GroupBox2.Controls.Add(Me.Button9)
        Me.GroupBox2.Controls.Add(Me.Button10)
        Me.GroupBox2.Controls.Add(Me.Button11)
        Me.GroupBox2.Location = New System.Drawing.Point(143, 12)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(126, 268)
        Me.GroupBox2.TabIndex = 1
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Basic move functions"
        '
        'Button13
        '
        Me.Button13.Location = New System.Drawing.Point(14, 195)
        Me.Button13.Name = "Button13"
        Me.Button13.Size = New System.Drawing.Size(98, 23)
        Me.Button13.TabIndex = 11
        Me.Button13.Text = "EMG Stop"
        Me.Button13.UseVisualStyleBackColor = True
        '
        'Button12
        '
        Me.Button12.Location = New System.Drawing.Point(14, 166)
        Me.Button12.Name = "Button12"
        Me.Button12.Size = New System.Drawing.Size(98, 23)
        Me.Button12.TabIndex = 10
        Me.Button12.Text = "Stop Move"
        Me.Button12.UseVisualStyleBackColor = True
        '
        'Button7
        '
        Me.Button7.Location = New System.Drawing.Point(14, 137)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(98, 23)
        Me.Button7.TabIndex = 9
        Me.Button7.Text = "P2P"
        Me.Button7.UseVisualStyleBackColor = True
        '
        'Button8
        '
        Me.Button8.Location = New System.Drawing.Point(14, 108)
        Me.Button8.Name = "Button8"
        Me.Button8.Size = New System.Drawing.Size(98, 23)
        Me.Button8.TabIndex = 8
        Me.Button8.Text = "Jog OFF"
        Me.Button8.UseVisualStyleBackColor = True
        '
        'Button9
        '
        Me.Button9.Location = New System.Drawing.Point(14, 79)
        Me.Button9.Name = "Button9"
        Me.Button9.Size = New System.Drawing.Size(98, 23)
        Me.Button9.TabIndex = 7
        Me.Button9.Text = "Jog ON"
        Me.Button9.UseVisualStyleBackColor = True
        '
        'Button10
        '
        Me.Button10.Location = New System.Drawing.Point(14, 50)
        Me.Button10.Name = "Button10"
        Me.Button10.Size = New System.Drawing.Size(98, 23)
        Me.Button10.TabIndex = 6
        Me.Button10.Text = "Velocity Move"
        Me.Button10.UseVisualStyleBackColor = True
        '
        'Button11
        '
        Me.Button11.Location = New System.Drawing.Point(14, 21)
        Me.Button11.Name = "Button11"
        Me.Button11.Size = New System.Drawing.Size(98, 23)
        Me.Button11.TabIndex = 5
        Me.Button11.Text = "Homing"
        Me.Button11.UseVisualStyleBackColor = True
        '
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.Label2)
        Me.GroupBox3.Controls.Add(Me.tbDelayTime)
        Me.GroupBox3.Controls.Add(Me.btnRepeatMove)
        Me.GroupBox3.Location = New System.Drawing.Point(275, 12)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(126, 268)
        Me.GroupBox3.TabIndex = 2
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "Advanced"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(13, 54)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(85, 12)
        Me.Label2.TabIndex = 11
        Me.Label2.Text = "Delay time ( ms )"
        '
        'tbDelayTime
        '
        Me.tbDelayTime.Location = New System.Drawing.Point(12, 81)
        Me.tbDelayTime.Name = "tbDelayTime"
        Me.tbDelayTime.Size = New System.Drawing.Size(70, 22)
        Me.tbDelayTime.TabIndex = 10
        Me.tbDelayTime.Text = "1000"
        '
        'btnRepeatMove
        '
        Me.btnRepeatMove.Location = New System.Drawing.Point(12, 21)
        Me.btnRepeatMove.Name = "btnRepeatMove"
        Me.btnRepeatMove.Size = New System.Drawing.Size(98, 23)
        Me.btnRepeatMove.TabIndex = 9
        Me.btnRepeatMove.Text = "Repeat Move"
        Me.btnRepeatMove.UseVisualStyleBackColor = True
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.Button23)
        Me.GroupBox4.Controls.Add(Me.Button20)
        Me.GroupBox4.Controls.Add(Me.Button21)
        Me.GroupBox4.Location = New System.Drawing.Point(410, 12)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(126, 268)
        Me.GroupBox4.TabIndex = 3
        Me.GroupBox4.TabStop = False
        Me.GroupBox4.Text = "Aux function"
        '
        'Button23
        '
        Me.Button23.Location = New System.Drawing.Point(12, 108)
        Me.Button23.Name = "Button23"
        Me.Button23.Size = New System.Drawing.Size(98, 28)
        Me.Button23.TabIndex = 16
        Me.Button23.Text = "Point Table"
        Me.Button23.UseVisualStyleBackColor = True
        '
        'Button20
        '
        Me.Button20.Location = New System.Drawing.Point(12, 21)
        Me.Button20.Name = "Button20"
        Me.Button20.Size = New System.Drawing.Size(98, 23)
        Me.Button20.TabIndex = 14
        Me.Button20.Text = "Digital I/O"
        Me.Button20.UseVisualStyleBackColor = True
        '
        'Button21
        '
        Me.Button21.Location = New System.Drawing.Point(12, 54)
        Me.Button21.Name = "Button21"
        Me.Button21.Size = New System.Drawing.Size(98, 23)
        Me.Button21.TabIndex = 13
        Me.Button21.Text = "CMP Trigger"
        Me.Button21.UseVisualStyleBackColor = True
        '
        'OpenFileDialog1
        '
        Me.OpenFileDialog1.FileName = "OpenFileDialog1"
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(553, 294)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "Form1"
        Me.Text = "Samples"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.GroupBox4.ResumeLayout(False)
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents ComboBox1 As System.Windows.Forms.ComboBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Button13 As System.Windows.Forms.Button
    Friend WithEvents Button12 As System.Windows.Forms.Button
    Friend WithEvents Button7 As System.Windows.Forms.Button
    Friend WithEvents Button8 As System.Windows.Forms.Button
    Friend WithEvents Button9 As System.Windows.Forms.Button
    Friend WithEvents Button10 As System.Windows.Forms.Button
    Friend WithEvents Button11 As System.Windows.Forms.Button
    Friend WithEvents btnRepeatMove As System.Windows.Forms.Button
    Friend WithEvents Button20 As System.Windows.Forms.Button
    Friend WithEvents Button21 As System.Windows.Forms.Button
    Friend WithEvents OpenFileDialog1 As System.Windows.Forms.OpenFileDialog
    Friend WithEvents Button23 As System.Windows.Forms.Button
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents tbDelayTime As System.Windows.Forms.TextBox

End Class
