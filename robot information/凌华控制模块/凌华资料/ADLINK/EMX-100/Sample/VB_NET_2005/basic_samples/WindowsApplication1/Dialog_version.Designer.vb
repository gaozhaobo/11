<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Dialog_version
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Dialog_version))
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.tbLIB = New System.Windows.Forms.TextBox
        Me.tbEXE = New System.Windows.Forms.TextBox
        Me.tbMW = New System.Windows.Forms.TextBox
        Me.tbSW = New System.Windows.Forms.TextBox
        Me.tbAPS = New System.Windows.Forms.TextBox
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.Label8 = New System.Windows.Forms.Label
        Me.Label9 = New System.Windows.Forms.Label
        Me.Label10 = New System.Windows.Forms.Label
        Me.GroupBox1.SuspendLayout()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.tbLIB)
        Me.GroupBox1.Controls.Add(Me.tbEXE)
        Me.GroupBox1.Controls.Add(Me.tbMW)
        Me.GroupBox1.Controls.Add(Me.tbSW)
        Me.GroupBox1.Controls.Add(Me.tbAPS)
        Me.GroupBox1.Controls.Add(Me.Label6)
        Me.GroupBox1.Controls.Add(Me.Label7)
        Me.GroupBox1.Controls.Add(Me.Label8)
        Me.GroupBox1.Controls.Add(Me.Label9)
        Me.GroupBox1.Controls.Add(Me.Label10)
        Me.GroupBox1.Location = New System.Drawing.Point(12, 12)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(247, 219)
        Me.GroupBox1.TabIndex = 2
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Info"
        '
        'tbLIB
        '
        Me.tbLIB.BackColor = System.Drawing.SystemColors.WindowText
        Me.tbLIB.ForeColor = System.Drawing.SystemColors.Highlight
        Me.tbLIB.Location = New System.Drawing.Point(123, 145)
        Me.tbLIB.Name = "tbLIB"
        Me.tbLIB.Size = New System.Drawing.Size(79, 22)
        Me.tbLIB.TabIndex = 20
        '
        'tbEXE
        '
        Me.tbEXE.BackColor = System.Drawing.SystemColors.WindowText
        Me.tbEXE.ForeColor = System.Drawing.SystemColors.Highlight
        Me.tbEXE.Location = New System.Drawing.Point(123, 114)
        Me.tbEXE.Name = "tbEXE"
        Me.tbEXE.Size = New System.Drawing.Size(79, 22)
        Me.tbEXE.TabIndex = 19
        '
        'tbMW
        '
        Me.tbMW.BackColor = System.Drawing.SystemColors.WindowText
        Me.tbMW.ForeColor = System.Drawing.SystemColors.Highlight
        Me.tbMW.Location = New System.Drawing.Point(123, 83)
        Me.tbMW.Name = "tbMW"
        Me.tbMW.Size = New System.Drawing.Size(79, 22)
        Me.tbMW.TabIndex = 18
        '
        'tbSW
        '
        Me.tbSW.BackColor = System.Drawing.SystemColors.WindowText
        Me.tbSW.ForeColor = System.Drawing.SystemColors.Highlight
        Me.tbSW.Location = New System.Drawing.Point(123, 52)
        Me.tbSW.Name = "tbSW"
        Me.tbSW.Size = New System.Drawing.Size(79, 22)
        Me.tbSW.TabIndex = 17
        '
        'tbAPS
        '
        Me.tbAPS.BackColor = System.Drawing.SystemColors.WindowText
        Me.tbAPS.ForeColor = System.Drawing.SystemColors.Highlight
        Me.tbAPS.Location = New System.Drawing.Point(123, 21)
        Me.tbAPS.Name = "tbAPS"
        Me.tbAPS.Size = New System.Drawing.Size(79, 22)
        Me.tbAPS.TabIndex = 16
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Location = New System.Drawing.Point(21, 24)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(56, 12)
        Me.Label6.TabIndex = 15
        Me.Label6.Text = "APS DLL :"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(21, 55)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(63, 12)
        Me.Label7.TabIndex = 14
        Me.Label7.Text = "FAMC SW :"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Location = New System.Drawing.Point(21, 86)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(67, 12)
        Me.Label8.TabIndex = 13
        Me.Label8.Text = "FAMC MW :"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Location = New System.Drawing.Point(21, 117)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(71, 12)
        Me.Label9.TabIndex = 12
        Me.Label9.Text = "FAMC EXE : "
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Location = New System.Drawing.Point(21, 148)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(81, 12)
        Me.Label10.TabIndex = 11
        Me.Label10.Text = "FAMC Library :"
        '
        'Dialog_version
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(268, 240)
        Me.Controls.Add(Me.GroupBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "Dialog_version"
        Me.ShowInTaskbar = False
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
        Me.Text = "Version Info"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents tbLIB As System.Windows.Forms.TextBox
    Friend WithEvents tbEXE As System.Windows.Forms.TextBox
    Friend WithEvents tbMW As System.Windows.Forms.TextBox
    Friend WithEvents tbSW As System.Windows.Forms.TextBox
    Friend WithEvents tbAPS As System.Windows.Forms.TextBox

End Class
