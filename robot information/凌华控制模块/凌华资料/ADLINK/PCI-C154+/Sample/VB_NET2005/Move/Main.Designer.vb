<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> Partial Class MainForm
#Region "Windows Form 設計工具產生的程式碼 "
	<System.Diagnostics.DebuggerNonUserCode()> Public Sub New()
		MyBase.New()
		'此為 Windows Form 設計工具所需的呼叫。
		InitializeComponent()
	End Sub
	'Form 覆寫 Dispose 以清除元件清單。
	<System.Diagnostics.DebuggerNonUserCode()> Protected Overloads Overrides Sub Dispose(ByVal Disposing As Boolean)
		If Disposing Then
			If Not components Is Nothing Then
				components.Dispose()
			End If
		End If
		MyBase.Dispose(Disposing)
	End Sub
	'為 Windows Form 設計工具的必要項
	Private components As System.ComponentModel.IContainer
	Public ToolTip1 As System.Windows.Forms.ToolTip
    Public WithEvents Btn_Linear_4Axes_Relateive_Stop As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_4Axes_RelateiveForward As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_4Axes_RelateiveBackward As System.Windows.Forms.Button
	Public WithEvents Frame14 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_Linear_4Axes_AbsoluteStop As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_4Axes_AbsoluteForward As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_4Axes_AbsoluteBackward As System.Windows.Forms.Button
	Public WithEvents Frame13 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_Linear_3Axes_Relateive_Stop As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_3Axes_RelateiveForward As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_3Axes_RelateiveBackward As System.Windows.Forms.Button
	Public WithEvents Frame12 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_Linear_3Axes_AbsoluteStop As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_3Axes_AbsoluteForward As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_3Axes_AbsoluteBackward As System.Windows.Forms.Button
	Public WithEvents Frame11 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_Linear_2Axes_Relateive_Stop As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_2Axes_RelateiveForward As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_2Axes_RelateiveBackward As System.Windows.Forms.Button
	Public WithEvents Frame10 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_Linear_2Axes_AbsoluteStop As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_2Axes_AbsoluteForward As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_2Axes_AbsoluteBackward As System.Windows.Forms.Button
	Public WithEvents Frame9 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_SingleHomeMove_Stop As System.Windows.Forms.Button
	Public WithEvents Btn_SingleHomeMove_Forward As System.Windows.Forms.Button
	Public WithEvents Btn_SingleHomeMove_Backward As System.Windows.Forms.Button
	Public WithEvents Frame8 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_SingleRelativeMove_Stop As System.Windows.Forms.Button
	Public WithEvents Btn_SingleRelativeMove_Forward As System.Windows.Forms.Button
	Public WithEvents Btn_SingleRelativeMove_Backward As System.Windows.Forms.Button
	Public WithEvents Frame7 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_SingleAbsoluteMove_Stop As System.Windows.Forms.Button
	Public WithEvents Btn_SingleAbsoluteMove_Forward As System.Windows.Forms.Button
	Public WithEvents Btn_SingleAbsoluteMove_Backward As System.Windows.Forms.Button
	Public WithEvents Frame6 As System.Windows.Forms.GroupBox
    Public WithEvents Edit_ShowMaster_CPLDVer As System.Windows.Forms.TextBox
	Public WithEvents Timer1 As System.Windows.Forms.Timer
	Public WithEvents Btn_ResetCounter As System.Windows.Forms.Button
	Public WithEvents _Edit_ShowAxis_MSts_3 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_MSts_2 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_MSts_1 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_IOSts_3 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_IOSts_2 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_IOSts_1 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Feedback_3 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Feedback_2 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Feedback_1 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Command_3 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Command_2 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Command_1 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Feedback_0 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_Command_0 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_MSts_0 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowAxis_IOSts_0 As System.Windows.Forms.TextBox
    Public WithEvents Frame3 As System.Windows.Forms.GroupBox
    Public WithEvents Edit_ShowMaster_DLLVer As System.Windows.Forms.TextBox
    Public WithEvents Edit_ShowMaster_DriverVer As System.Windows.Forms.TextBox
    Public WithEvents Label2 As System.Windows.Forms.Label
    Public WithEvents Label1 As System.Windows.Forms.Label
    Public WithEvents Frame1 As System.Windows.Forms.GroupBox
    Public WithEvents Edit_ShowAxis_Command As Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray
    Public WithEvents Edit_ShowAxis_Feedback As Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray
    Public WithEvents Edit_ShowAxis_IOSts As Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray
    Public WithEvents Edit_ShowAxis_MSts As Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray
    Public WithEvents Edit_ShowTriggerCount As Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray
    Public WithEvents Edit_ShowTriggerEnc As Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray
    Public WithEvents Edit_ShowTrigger_LinearCMP_LinearCMP As Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray
    Public WithEvents Label15 As Microsoft.VisualBasic.Compatibility.VB6.LabelArray
    '注意: 以下為 Windows Form 設計工具所需的程序
    '可以使用 Windows Form 設計工具進行修改。
    '請不要使用程式碼編輯器進行修改。
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(MainForm))
        Me.ToolTip1 = New System.Windows.Forms.ToolTip(Me.components)
        Me.Frame14 = New System.Windows.Forms.GroupBox
        Me.Btn_Linear_4Axes_Relateive_Stop = New System.Windows.Forms.Button
        Me.Btn_Linear_4Axes_RelateiveForward = New System.Windows.Forms.Button
        Me.Btn_Linear_4Axes_RelateiveBackward = New System.Windows.Forms.Button
        Me.Frame13 = New System.Windows.Forms.GroupBox
        Me.Btn_Linear_4Axes_AbsoluteStop = New System.Windows.Forms.Button
        Me.Btn_Linear_4Axes_AbsoluteForward = New System.Windows.Forms.Button
        Me.Btn_Linear_4Axes_AbsoluteBackward = New System.Windows.Forms.Button
        Me.Frame12 = New System.Windows.Forms.GroupBox
        Me.Btn_Linear_3Axes_Relateive_Stop = New System.Windows.Forms.Button
        Me.Btn_Linear_3Axes_RelateiveForward = New System.Windows.Forms.Button
        Me.Btn_Linear_3Axes_RelateiveBackward = New System.Windows.Forms.Button
        Me.Frame11 = New System.Windows.Forms.GroupBox
        Me.Btn_Linear_3Axes_AbsoluteStop = New System.Windows.Forms.Button
        Me.Btn_Linear_3Axes_AbsoluteForward = New System.Windows.Forms.Button
        Me.Btn_Linear_3Axes_AbsoluteBackward = New System.Windows.Forms.Button
        Me.Frame10 = New System.Windows.Forms.GroupBox
        Me.Btn_Linear_2Axes_Relateive_Stop = New System.Windows.Forms.Button
        Me.Btn_Linear_2Axes_RelateiveForward = New System.Windows.Forms.Button
        Me.Btn_Linear_2Axes_RelateiveBackward = New System.Windows.Forms.Button
        Me.Frame9 = New System.Windows.Forms.GroupBox
        Me.Btn_Linear_2Axes_AbsoluteStop = New System.Windows.Forms.Button
        Me.Btn_Linear_2Axes_AbsoluteForward = New System.Windows.Forms.Button
        Me.Btn_Linear_2Axes_AbsoluteBackward = New System.Windows.Forms.Button
        Me.Frame8 = New System.Windows.Forms.GroupBox
        Me.Btn_SingleHomeMove_Stop = New System.Windows.Forms.Button
        Me.Btn_SingleHomeMove_Forward = New System.Windows.Forms.Button
        Me.Btn_SingleHomeMove_Backward = New System.Windows.Forms.Button
        Me.Frame7 = New System.Windows.Forms.GroupBox
        Me.Btn_SingleRelativeMove_Stop = New System.Windows.Forms.Button
        Me.Btn_SingleRelativeMove_Forward = New System.Windows.Forms.Button
        Me.Btn_SingleRelativeMove_Backward = New System.Windows.Forms.Button
        Me.Frame6 = New System.Windows.Forms.GroupBox
        Me.Btn_SingleAbsoluteMove_Stop = New System.Windows.Forms.Button
        Me.Btn_SingleAbsoluteMove_Forward = New System.Windows.Forms.Button
        Me.Btn_SingleAbsoluteMove_Backward = New System.Windows.Forms.Button
        Me.Edit_ShowMaster_CPLDVer = New System.Windows.Forms.TextBox
        Me.Frame3 = New System.Windows.Forms.GroupBox
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label9 = New System.Windows.Forms.Label
        Me.Btn_ResetCounter = New System.Windows.Forms.Button
        Me._Edit_ShowAxis_MSts_3 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_MSts_2 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_MSts_1 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_IOSts_3 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_IOSts_2 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_IOSts_1 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Feedback_3 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Feedback_2 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Feedback_1 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Command_3 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Command_2 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Command_1 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Feedback_0 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_Command_0 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_MSts_0 = New System.Windows.Forms.TextBox
        Me._Edit_ShowAxis_IOSts_0 = New System.Windows.Forms.TextBox
        Me.Label999 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.Label26 = New System.Windows.Forms.Label
        Me.Label27 = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Frame1 = New System.Windows.Forms.GroupBox
        Me.Edit_ShowMaster_DLLVer = New System.Windows.Forms.TextBox
        Me.Edit_ShowMaster_DriverVer = New System.Windows.Forms.TextBox
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label1 = New System.Windows.Forms.Label
        Me.Edit_ShowAxis_Command = New Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray(Me.components)
        Me.Edit_ShowAxis_Feedback = New Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray(Me.components)
        Me.Edit_ShowAxis_IOSts = New Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray(Me.components)
        Me.Edit_ShowAxis_MSts = New Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray(Me.components)
        Me.Edit_ShowTriggerCount = New Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray(Me.components)
        Me.Edit_ShowTriggerEnc = New Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray(Me.components)
        Me.Edit_ShowTrigger_LinearCMP_LinearCMP = New Microsoft.VisualBasic.Compatibility.VB6.TextBoxArray(Me.components)
        Me.Label15 = New Microsoft.VisualBasic.Compatibility.VB6.LabelArray(Me.components)
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Btn_Arc_2Axes_Absolute_Stop2 = New System.Windows.Forms.Button
        Me.Btn_Arc_2Axes_Absolute_CW = New System.Windows.Forms.Button
        Me.Btn_Arc_2Axes_Absolute_CCW = New System.Windows.Forms.Button
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.Btn_Arc_2Axes_Relateive_Stop = New System.Windows.Forms.Button
        Me.Btn_Arc_2Axes_Relative_CW = New System.Windows.Forms.Button
        Me.Btn_Arc_2Axes_Relative_CCW = New System.Windows.Forms.Button
        Me.Button2 = New System.Windows.Forms.Button
        Me.Label7 = New System.Windows.Forms.Label
        Me.MaskedTextBox1 = New System.Windows.Forms.MaskedTextBox
        Me.Frame14.SuspendLayout()
        Me.Frame13.SuspendLayout()
        Me.Frame12.SuspendLayout()
        Me.Frame11.SuspendLayout()
        Me.Frame10.SuspendLayout()
        Me.Frame9.SuspendLayout()
        Me.Frame8.SuspendLayout()
        Me.Frame7.SuspendLayout()
        Me.Frame6.SuspendLayout()
        Me.Frame3.SuspendLayout()
        Me.Frame1.SuspendLayout()
        CType(Me.Edit_ShowAxis_Command, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Edit_ShowAxis_Feedback, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Edit_ShowAxis_IOSts, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Edit_ShowAxis_MSts, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Edit_ShowTriggerCount, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Edit_ShowTriggerEnc, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Edit_ShowTrigger_LinearCMP_LinearCMP, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Label15, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox1.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.SuspendLayout()
        '
        'Frame14
        '
        Me.Frame14.BackColor = System.Drawing.SystemColors.Control
        Me.Frame14.Controls.Add(Me.Btn_Linear_4Axes_Relateive_Stop)
        Me.Frame14.Controls.Add(Me.Btn_Linear_4Axes_RelateiveForward)
        Me.Frame14.Controls.Add(Me.Btn_Linear_4Axes_RelateiveBackward)
        Me.Frame14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame14.Location = New System.Drawing.Point(24, 526)
        Me.Frame14.Name = "Frame14"
        Me.Frame14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame14.Size = New System.Drawing.Size(185, 177)
        Me.Frame14.TabIndex = 53
        Me.Frame14.TabStop = False
        Me.Frame14.Text = "4 Axes Linear Relative Move"
        '
        'Btn_Linear_4Axes_Relateive_Stop
        '
        Me.Btn_Linear_4Axes_Relateive_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_4Axes_Relateive_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_4Axes_Relateive_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_4Axes_Relateive_Stop.Location = New System.Drawing.Point(56, 96)
        Me.Btn_Linear_4Axes_Relateive_Stop.Name = "Btn_Linear_4Axes_Relateive_Stop"
        Me.Btn_Linear_4Axes_Relateive_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_4Axes_Relateive_Stop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_4Axes_Relateive_Stop.TabIndex = 82
        Me.Btn_Linear_4Axes_Relateive_Stop.Text = "Stop"
        Me.Btn_Linear_4Axes_Relateive_Stop.UseVisualStyleBackColor = False
        '
        'Btn_Linear_4Axes_RelateiveForward
        '
        Me.Btn_Linear_4Axes_RelateiveForward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_4Axes_RelateiveForward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_4Axes_RelateiveForward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_4Axes_RelateiveForward.Location = New System.Drawing.Point(104, 32)
        Me.Btn_Linear_4Axes_RelateiveForward.Name = "Btn_Linear_4Axes_RelateiveForward"
        Me.Btn_Linear_4Axes_RelateiveForward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_4Axes_RelateiveForward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_4Axes_RelateiveForward.TabIndex = 81
        Me.Btn_Linear_4Axes_RelateiveForward.Text = "Forward"
        Me.Btn_Linear_4Axes_RelateiveForward.UseVisualStyleBackColor = False
        '
        'Btn_Linear_4Axes_RelateiveBackward
        '
        Me.Btn_Linear_4Axes_RelateiveBackward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_4Axes_RelateiveBackward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_4Axes_RelateiveBackward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_4Axes_RelateiveBackward.Location = New System.Drawing.Point(16, 32)
        Me.Btn_Linear_4Axes_RelateiveBackward.Name = "Btn_Linear_4Axes_RelateiveBackward"
        Me.Btn_Linear_4Axes_RelateiveBackward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_4Axes_RelateiveBackward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_4Axes_RelateiveBackward.TabIndex = 80
        Me.Btn_Linear_4Axes_RelateiveBackward.Text = "Backward"
        Me.Btn_Linear_4Axes_RelateiveBackward.UseVisualStyleBackColor = False
        '
        'Frame13
        '
        Me.Frame13.BackColor = System.Drawing.SystemColors.Control
        Me.Frame13.Controls.Add(Me.Btn_Linear_4Axes_AbsoluteStop)
        Me.Frame13.Controls.Add(Me.Btn_Linear_4Axes_AbsoluteForward)
        Me.Frame13.Controls.Add(Me.Btn_Linear_4Axes_AbsoluteBackward)
        Me.Frame13.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame13.Location = New System.Drawing.Point(788, 359)
        Me.Frame13.Name = "Frame13"
        Me.Frame13.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame13.Size = New System.Drawing.Size(185, 161)
        Me.Frame13.TabIndex = 52
        Me.Frame13.TabStop = False
        Me.Frame13.Text = "4 Axes Linear Absolute Move"
        '
        'Btn_Linear_4Axes_AbsoluteStop
        '
        Me.Btn_Linear_4Axes_AbsoluteStop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_4Axes_AbsoluteStop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_4Axes_AbsoluteStop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_4Axes_AbsoluteStop.Location = New System.Drawing.Point(56, 96)
        Me.Btn_Linear_4Axes_AbsoluteStop.Name = "Btn_Linear_4Axes_AbsoluteStop"
        Me.Btn_Linear_4Axes_AbsoluteStop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_4Axes_AbsoluteStop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_4Axes_AbsoluteStop.TabIndex = 79
        Me.Btn_Linear_4Axes_AbsoluteStop.Text = "Stop"
        Me.Btn_Linear_4Axes_AbsoluteStop.UseVisualStyleBackColor = False
        '
        'Btn_Linear_4Axes_AbsoluteForward
        '
        Me.Btn_Linear_4Axes_AbsoluteForward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_4Axes_AbsoluteForward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_4Axes_AbsoluteForward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_4Axes_AbsoluteForward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_Linear_4Axes_AbsoluteForward.Name = "Btn_Linear_4Axes_AbsoluteForward"
        Me.Btn_Linear_4Axes_AbsoluteForward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_4Axes_AbsoluteForward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_4Axes_AbsoluteForward.TabIndex = 78
        Me.Btn_Linear_4Axes_AbsoluteForward.Text = "Forward"
        Me.Btn_Linear_4Axes_AbsoluteForward.UseVisualStyleBackColor = False
        '
        'Btn_Linear_4Axes_AbsoluteBackward
        '
        Me.Btn_Linear_4Axes_AbsoluteBackward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_4Axes_AbsoluteBackward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_4Axes_AbsoluteBackward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_4Axes_AbsoluteBackward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_Linear_4Axes_AbsoluteBackward.Name = "Btn_Linear_4Axes_AbsoluteBackward"
        Me.Btn_Linear_4Axes_AbsoluteBackward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_4Axes_AbsoluteBackward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_4Axes_AbsoluteBackward.TabIndex = 77
        Me.Btn_Linear_4Axes_AbsoluteBackward.Text = "Backward"
        Me.Btn_Linear_4Axes_AbsoluteBackward.UseVisualStyleBackColor = False
        '
        'Frame12
        '
        Me.Frame12.BackColor = System.Drawing.SystemColors.Control
        Me.Frame12.Controls.Add(Me.Btn_Linear_3Axes_Relateive_Stop)
        Me.Frame12.Controls.Add(Me.Btn_Linear_3Axes_RelateiveForward)
        Me.Frame12.Controls.Add(Me.Btn_Linear_3Axes_RelateiveBackward)
        Me.Frame12.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame12.Location = New System.Drawing.Point(597, 359)
        Me.Frame12.Name = "Frame12"
        Me.Frame12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame12.Size = New System.Drawing.Size(185, 161)
        Me.Frame12.TabIndex = 51
        Me.Frame12.TabStop = False
        Me.Frame12.Text = "3 Axes Linear Relative Movee"
        '
        'Btn_Linear_3Axes_Relateive_Stop
        '
        Me.Btn_Linear_3Axes_Relateive_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_3Axes_Relateive_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_3Axes_Relateive_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_3Axes_Relateive_Stop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_Linear_3Axes_Relateive_Stop.Name = "Btn_Linear_3Axes_Relateive_Stop"
        Me.Btn_Linear_3Axes_Relateive_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_3Axes_Relateive_Stop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_3Axes_Relateive_Stop.TabIndex = 76
        Me.Btn_Linear_3Axes_Relateive_Stop.Text = "Stop"
        Me.Btn_Linear_3Axes_Relateive_Stop.UseVisualStyleBackColor = False
        '
        'Btn_Linear_3Axes_RelateiveForward
        '
        Me.Btn_Linear_3Axes_RelateiveForward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_3Axes_RelateiveForward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_3Axes_RelateiveForward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_3Axes_RelateiveForward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_Linear_3Axes_RelateiveForward.Name = "Btn_Linear_3Axes_RelateiveForward"
        Me.Btn_Linear_3Axes_RelateiveForward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_3Axes_RelateiveForward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_3Axes_RelateiveForward.TabIndex = 75
        Me.Btn_Linear_3Axes_RelateiveForward.Text = "Forward"
        Me.Btn_Linear_3Axes_RelateiveForward.UseVisualStyleBackColor = False
        '
        'Btn_Linear_3Axes_RelateiveBackward
        '
        Me.Btn_Linear_3Axes_RelateiveBackward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_3Axes_RelateiveBackward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_3Axes_RelateiveBackward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_3Axes_RelateiveBackward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_Linear_3Axes_RelateiveBackward.Name = "Btn_Linear_3Axes_RelateiveBackward"
        Me.Btn_Linear_3Axes_RelateiveBackward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_3Axes_RelateiveBackward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_3Axes_RelateiveBackward.TabIndex = 74
        Me.Btn_Linear_3Axes_RelateiveBackward.Text = "Backward"
        Me.Btn_Linear_3Axes_RelateiveBackward.UseVisualStyleBackColor = False
        '
        'Frame11
        '
        Me.Frame11.BackColor = System.Drawing.SystemColors.Control
        Me.Frame11.Controls.Add(Me.Btn_Linear_3Axes_AbsoluteStop)
        Me.Frame11.Controls.Add(Me.Btn_Linear_3Axes_AbsoluteForward)
        Me.Frame11.Controls.Add(Me.Btn_Linear_3Axes_AbsoluteBackward)
        Me.Frame11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame11.Location = New System.Drawing.Point(406, 359)
        Me.Frame11.Name = "Frame11"
        Me.Frame11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame11.Size = New System.Drawing.Size(185, 161)
        Me.Frame11.TabIndex = 50
        Me.Frame11.TabStop = False
        Me.Frame11.Text = "3 Axes Linear Absolute Move"
        '
        'Btn_Linear_3Axes_AbsoluteStop
        '
        Me.Btn_Linear_3Axes_AbsoluteStop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_3Axes_AbsoluteStop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_3Axes_AbsoluteStop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_3Axes_AbsoluteStop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_Linear_3Axes_AbsoluteStop.Name = "Btn_Linear_3Axes_AbsoluteStop"
        Me.Btn_Linear_3Axes_AbsoluteStop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_3Axes_AbsoluteStop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_3Axes_AbsoluteStop.TabIndex = 73
        Me.Btn_Linear_3Axes_AbsoluteStop.Text = "Stop"
        Me.Btn_Linear_3Axes_AbsoluteStop.UseVisualStyleBackColor = False
        '
        'Btn_Linear_3Axes_AbsoluteForward
        '
        Me.Btn_Linear_3Axes_AbsoluteForward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_3Axes_AbsoluteForward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_3Axes_AbsoluteForward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_3Axes_AbsoluteForward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_Linear_3Axes_AbsoluteForward.Name = "Btn_Linear_3Axes_AbsoluteForward"
        Me.Btn_Linear_3Axes_AbsoluteForward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_3Axes_AbsoluteForward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_3Axes_AbsoluteForward.TabIndex = 72
        Me.Btn_Linear_3Axes_AbsoluteForward.Text = "Forward"
        Me.Btn_Linear_3Axes_AbsoluteForward.UseVisualStyleBackColor = False
        '
        'Btn_Linear_3Axes_AbsoluteBackward
        '
        Me.Btn_Linear_3Axes_AbsoluteBackward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_3Axes_AbsoluteBackward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_3Axes_AbsoluteBackward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_3Axes_AbsoluteBackward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_Linear_3Axes_AbsoluteBackward.Name = "Btn_Linear_3Axes_AbsoluteBackward"
        Me.Btn_Linear_3Axes_AbsoluteBackward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_3Axes_AbsoluteBackward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_3Axes_AbsoluteBackward.TabIndex = 71
        Me.Btn_Linear_3Axes_AbsoluteBackward.Text = "Backward"
        Me.Btn_Linear_3Axes_AbsoluteBackward.UseVisualStyleBackColor = False
        '
        'Frame10
        '
        Me.Frame10.BackColor = System.Drawing.SystemColors.Control
        Me.Frame10.Controls.Add(Me.Btn_Linear_2Axes_Relateive_Stop)
        Me.Frame10.Controls.Add(Me.Btn_Linear_2Axes_RelateiveForward)
        Me.Frame10.Controls.Add(Me.Btn_Linear_2Axes_RelateiveBackward)
        Me.Frame10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame10.Location = New System.Drawing.Point(788, 192)
        Me.Frame10.Name = "Frame10"
        Me.Frame10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame10.Size = New System.Drawing.Size(185, 161)
        Me.Frame10.TabIndex = 49
        Me.Frame10.TabStop = False
        Me.Frame10.Text = "2 Axes Linear Relative Move"
        '
        'Btn_Linear_2Axes_Relateive_Stop
        '
        Me.Btn_Linear_2Axes_Relateive_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_2Axes_Relateive_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_2Axes_Relateive_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_2Axes_Relateive_Stop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_Linear_2Axes_Relateive_Stop.Name = "Btn_Linear_2Axes_Relateive_Stop"
        Me.Btn_Linear_2Axes_Relateive_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_2Axes_Relateive_Stop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_2Axes_Relateive_Stop.TabIndex = 70
        Me.Btn_Linear_2Axes_Relateive_Stop.Text = "Stop"
        Me.Btn_Linear_2Axes_Relateive_Stop.UseVisualStyleBackColor = False
        '
        'Btn_Linear_2Axes_RelateiveForward
        '
        Me.Btn_Linear_2Axes_RelateiveForward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_2Axes_RelateiveForward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_2Axes_RelateiveForward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_2Axes_RelateiveForward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_Linear_2Axes_RelateiveForward.Name = "Btn_Linear_2Axes_RelateiveForward"
        Me.Btn_Linear_2Axes_RelateiveForward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_2Axes_RelateiveForward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_2Axes_RelateiveForward.TabIndex = 69
        Me.Btn_Linear_2Axes_RelateiveForward.Text = "Forward"
        Me.Btn_Linear_2Axes_RelateiveForward.UseVisualStyleBackColor = False
        '
        'Btn_Linear_2Axes_RelateiveBackward
        '
        Me.Btn_Linear_2Axes_RelateiveBackward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_2Axes_RelateiveBackward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_2Axes_RelateiveBackward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_2Axes_RelateiveBackward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_Linear_2Axes_RelateiveBackward.Name = "Btn_Linear_2Axes_RelateiveBackward"
        Me.Btn_Linear_2Axes_RelateiveBackward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_2Axes_RelateiveBackward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_2Axes_RelateiveBackward.TabIndex = 68
        Me.Btn_Linear_2Axes_RelateiveBackward.Text = "Backward"
        Me.Btn_Linear_2Axes_RelateiveBackward.UseVisualStyleBackColor = False
        '
        'Frame9
        '
        Me.Frame9.BackColor = System.Drawing.SystemColors.Control
        Me.Frame9.Controls.Add(Me.Btn_Linear_2Axes_AbsoluteStop)
        Me.Frame9.Controls.Add(Me.Btn_Linear_2Axes_AbsoluteForward)
        Me.Frame9.Controls.Add(Me.Btn_Linear_2Axes_AbsoluteBackward)
        Me.Frame9.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame9.Location = New System.Drawing.Point(597, 192)
        Me.Frame9.Name = "Frame9"
        Me.Frame9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame9.Size = New System.Drawing.Size(185, 161)
        Me.Frame9.TabIndex = 48
        Me.Frame9.TabStop = False
        Me.Frame9.Text = "2 Axes Linear Absolute Movee"
        '
        'Btn_Linear_2Axes_AbsoluteStop
        '
        Me.Btn_Linear_2Axes_AbsoluteStop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_2Axes_AbsoluteStop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_2Axes_AbsoluteStop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_2Axes_AbsoluteStop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_Linear_2Axes_AbsoluteStop.Name = "Btn_Linear_2Axes_AbsoluteStop"
        Me.Btn_Linear_2Axes_AbsoluteStop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_2Axes_AbsoluteStop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_2Axes_AbsoluteStop.TabIndex = 67
        Me.Btn_Linear_2Axes_AbsoluteStop.Text = "Stop"
        Me.Btn_Linear_2Axes_AbsoluteStop.UseVisualStyleBackColor = False
        '
        'Btn_Linear_2Axes_AbsoluteForward
        '
        Me.Btn_Linear_2Axes_AbsoluteForward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_2Axes_AbsoluteForward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_2Axes_AbsoluteForward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_2Axes_AbsoluteForward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_Linear_2Axes_AbsoluteForward.Name = "Btn_Linear_2Axes_AbsoluteForward"
        Me.Btn_Linear_2Axes_AbsoluteForward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_2Axes_AbsoluteForward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_2Axes_AbsoluteForward.TabIndex = 66
        Me.Btn_Linear_2Axes_AbsoluteForward.Text = "Forward"
        Me.Btn_Linear_2Axes_AbsoluteForward.UseVisualStyleBackColor = False
        '
        'Btn_Linear_2Axes_AbsoluteBackward
        '
        Me.Btn_Linear_2Axes_AbsoluteBackward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_2Axes_AbsoluteBackward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_2Axes_AbsoluteBackward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_2Axes_AbsoluteBackward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_Linear_2Axes_AbsoluteBackward.Name = "Btn_Linear_2Axes_AbsoluteBackward"
        Me.Btn_Linear_2Axes_AbsoluteBackward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_2Axes_AbsoluteBackward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Linear_2Axes_AbsoluteBackward.TabIndex = 65
        Me.Btn_Linear_2Axes_AbsoluteBackward.Text = "Backward"
        Me.Btn_Linear_2Axes_AbsoluteBackward.UseVisualStyleBackColor = False
        '
        'Frame8
        '
        Me.Frame8.BackColor = System.Drawing.SystemColors.Control
        Me.Frame8.Controls.Add(Me.Btn_SingleHomeMove_Stop)
        Me.Frame8.Controls.Add(Me.Btn_SingleHomeMove_Forward)
        Me.Frame8.Controls.Add(Me.Btn_SingleHomeMove_Backward)
        Me.Frame8.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame8.Location = New System.Drawing.Point(406, 192)
        Me.Frame8.Name = "Frame8"
        Me.Frame8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame8.Size = New System.Drawing.Size(185, 161)
        Me.Frame8.TabIndex = 42
        Me.Frame8.TabStop = False
        Me.Frame8.Text = "Single Home Move"
        '
        'Btn_SingleHomeMove_Stop
        '
        Me.Btn_SingleHomeMove_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleHomeMove_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleHomeMove_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleHomeMove_Stop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_SingleHomeMove_Stop.Name = "Btn_SingleHomeMove_Stop"
        Me.Btn_SingleHomeMove_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleHomeMove_Stop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleHomeMove_Stop.TabIndex = 64
        Me.Btn_SingleHomeMove_Stop.Text = "Stop"
        Me.Btn_SingleHomeMove_Stop.UseVisualStyleBackColor = False
        '
        'Btn_SingleHomeMove_Forward
        '
        Me.Btn_SingleHomeMove_Forward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleHomeMove_Forward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleHomeMove_Forward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleHomeMove_Forward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_SingleHomeMove_Forward.Name = "Btn_SingleHomeMove_Forward"
        Me.Btn_SingleHomeMove_Forward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleHomeMove_Forward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleHomeMove_Forward.TabIndex = 63
        Me.Btn_SingleHomeMove_Forward.Text = "Forward"
        Me.Btn_SingleHomeMove_Forward.UseVisualStyleBackColor = False
        '
        'Btn_SingleHomeMove_Backward
        '
        Me.Btn_SingleHomeMove_Backward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleHomeMove_Backward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleHomeMove_Backward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleHomeMove_Backward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_SingleHomeMove_Backward.Name = "Btn_SingleHomeMove_Backward"
        Me.Btn_SingleHomeMove_Backward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleHomeMove_Backward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleHomeMove_Backward.TabIndex = 62
        Me.Btn_SingleHomeMove_Backward.Text = "Backward"
        Me.Btn_SingleHomeMove_Backward.UseVisualStyleBackColor = False
        '
        'Frame7
        '
        Me.Frame7.BackColor = System.Drawing.SystemColors.Control
        Me.Frame7.Controls.Add(Me.Btn_SingleRelativeMove_Stop)
        Me.Frame7.Controls.Add(Me.Btn_SingleRelativeMove_Forward)
        Me.Frame7.Controls.Add(Me.Btn_SingleRelativeMove_Backward)
        Me.Frame7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame7.Location = New System.Drawing.Point(215, 192)
        Me.Frame7.Name = "Frame7"
        Me.Frame7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame7.Size = New System.Drawing.Size(185, 161)
        Me.Frame7.TabIndex = 41
        Me.Frame7.TabStop = False
        Me.Frame7.Text = "Single Relative Move"
        '
        'Btn_SingleRelativeMove_Stop
        '
        Me.Btn_SingleRelativeMove_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleRelativeMove_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleRelativeMove_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleRelativeMove_Stop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_SingleRelativeMove_Stop.Name = "Btn_SingleRelativeMove_Stop"
        Me.Btn_SingleRelativeMove_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleRelativeMove_Stop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleRelativeMove_Stop.TabIndex = 61
        Me.Btn_SingleRelativeMove_Stop.Text = "Stop"
        Me.Btn_SingleRelativeMove_Stop.UseVisualStyleBackColor = False
        '
        'Btn_SingleRelativeMove_Forward
        '
        Me.Btn_SingleRelativeMove_Forward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleRelativeMove_Forward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleRelativeMove_Forward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleRelativeMove_Forward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_SingleRelativeMove_Forward.Name = "Btn_SingleRelativeMove_Forward"
        Me.Btn_SingleRelativeMove_Forward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleRelativeMove_Forward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleRelativeMove_Forward.TabIndex = 60
        Me.Btn_SingleRelativeMove_Forward.Text = "Forward"
        Me.Btn_SingleRelativeMove_Forward.UseVisualStyleBackColor = False
        '
        'Btn_SingleRelativeMove_Backward
        '
        Me.Btn_SingleRelativeMove_Backward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleRelativeMove_Backward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleRelativeMove_Backward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleRelativeMove_Backward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_SingleRelativeMove_Backward.Name = "Btn_SingleRelativeMove_Backward"
        Me.Btn_SingleRelativeMove_Backward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleRelativeMove_Backward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleRelativeMove_Backward.TabIndex = 59
        Me.Btn_SingleRelativeMove_Backward.Text = "Backward"
        Me.Btn_SingleRelativeMove_Backward.UseVisualStyleBackColor = False
        '
        'Frame6
        '
        Me.Frame6.BackColor = System.Drawing.SystemColors.Control
        Me.Frame6.Controls.Add(Me.Btn_SingleAbsoluteMove_Stop)
        Me.Frame6.Controls.Add(Me.Btn_SingleAbsoluteMove_Forward)
        Me.Frame6.Controls.Add(Me.Btn_SingleAbsoluteMove_Backward)
        Me.Frame6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame6.Location = New System.Drawing.Point(24, 192)
        Me.Frame6.Name = "Frame6"
        Me.Frame6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame6.Size = New System.Drawing.Size(185, 161)
        Me.Frame6.TabIndex = 40
        Me.Frame6.TabStop = False
        Me.Frame6.Text = "Single Absolute Move"
        '
        'Btn_SingleAbsoluteMove_Stop
        '
        Me.Btn_SingleAbsoluteMove_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleAbsoluteMove_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleAbsoluteMove_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleAbsoluteMove_Stop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_SingleAbsoluteMove_Stop.Name = "Btn_SingleAbsoluteMove_Stop"
        Me.Btn_SingleAbsoluteMove_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleAbsoluteMove_Stop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleAbsoluteMove_Stop.TabIndex = 58
        Me.Btn_SingleAbsoluteMove_Stop.Text = "Stop"
        Me.Btn_SingleAbsoluteMove_Stop.UseVisualStyleBackColor = False
        '
        'Btn_SingleAbsoluteMove_Forward
        '
        Me.Btn_SingleAbsoluteMove_Forward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleAbsoluteMove_Forward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleAbsoluteMove_Forward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleAbsoluteMove_Forward.Location = New System.Drawing.Point(104, 24)
        Me.Btn_SingleAbsoluteMove_Forward.Name = "Btn_SingleAbsoluteMove_Forward"
        Me.Btn_SingleAbsoluteMove_Forward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleAbsoluteMove_Forward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleAbsoluteMove_Forward.TabIndex = 57
        Me.Btn_SingleAbsoluteMove_Forward.Text = "Forward"
        Me.Btn_SingleAbsoluteMove_Forward.UseVisualStyleBackColor = False
        '
        'Btn_SingleAbsoluteMove_Backward
        '
        Me.Btn_SingleAbsoluteMove_Backward.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SingleAbsoluteMove_Backward.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SingleAbsoluteMove_Backward.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SingleAbsoluteMove_Backward.Location = New System.Drawing.Point(16, 24)
        Me.Btn_SingleAbsoluteMove_Backward.Name = "Btn_SingleAbsoluteMove_Backward"
        Me.Btn_SingleAbsoluteMove_Backward.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SingleAbsoluteMove_Backward.Size = New System.Drawing.Size(65, 57)
        Me.Btn_SingleAbsoluteMove_Backward.TabIndex = 56
        Me.Btn_SingleAbsoluteMove_Backward.Text = "Backward"
        Me.Btn_SingleAbsoluteMove_Backward.UseVisualStyleBackColor = False
        '
        'Edit_ShowMaster_CPLDVer
        '
        Me.Edit_ShowMaster_CPLDVer.AcceptsReturn = True
        Me.Edit_ShowMaster_CPLDVer.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_ShowMaster_CPLDVer.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_ShowMaster_CPLDVer.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_ShowMaster_CPLDVer.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowMaster_CPLDVer.Location = New System.Drawing.Point(18, 132)
        Me.Edit_ShowMaster_CPLDVer.MaxLength = 0
        Me.Edit_ShowMaster_CPLDVer.Name = "Edit_ShowMaster_CPLDVer"
        Me.Edit_ShowMaster_CPLDVer.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_ShowMaster_CPLDVer.Size = New System.Drawing.Size(105, 20)
        Me.Edit_ShowMaster_CPLDVer.TabIndex = 8
        Me.Edit_ShowMaster_CPLDVer.Text = "Text1"
        Me.Edit_ShowMaster_CPLDVer.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Frame3
        '
        Me.Frame3.BackColor = System.Drawing.SystemColors.Control
        Me.Frame3.Controls.Add(Me.Label6)
        Me.Frame3.Controls.Add(Me.Label4)
        Me.Frame3.Controls.Add(Me.Label3)
        Me.Frame3.Controls.Add(Me.Label9)
        Me.Frame3.Controls.Add(Me.Btn_ResetCounter)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_MSts_3)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_MSts_2)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_MSts_1)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_IOSts_3)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_IOSts_2)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_IOSts_1)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Feedback_3)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Feedback_2)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Feedback_1)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Command_3)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Command_2)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Command_1)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Feedback_0)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_Command_0)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_MSts_0)
        Me.Frame3.Controls.Add(Me._Edit_ShowAxis_IOSts_0)
        Me.Frame3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame3.Location = New System.Drawing.Point(327, 9)
        Me.Frame3.Name = "Frame3"
        Me.Frame3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame3.Size = New System.Drawing.Size(641, 177)
        Me.Frame3.TabIndex = 2
        Me.Frame3.TabStop = False
        Me.Frame3.Text = "Motion Status"
        '
        'Label6
        '
        Me.Label6.BackColor = System.Drawing.SystemColors.Control
        Me.Label6.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label6.Location = New System.Drawing.Point(157, 18)
        Me.Label6.Name = "Label6"
        Me.Label6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label6.Size = New System.Drawing.Size(43, 15)
        Me.Label6.TabIndex = 58
        Me.Label6.Text = "Axis 1"
        '
        'Label4
        '
        Me.Label4.BackColor = System.Drawing.SystemColors.Control
        Me.Label4.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label4.Location = New System.Drawing.Point(381, 18)
        Me.Label4.Name = "Label4"
        Me.Label4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label4.Size = New System.Drawing.Size(43, 15)
        Me.Label4.TabIndex = 57
        Me.Label4.Text = "Axis 3"
        '
        'Label3
        '
        Me.Label3.BackColor = System.Drawing.SystemColors.Control
        Me.Label3.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label3.Location = New System.Drawing.Point(268, 18)
        Me.Label3.Name = "Label3"
        Me.Label3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label3.Size = New System.Drawing.Size(41, 15)
        Me.Label3.TabIndex = 56
        Me.Label3.Text = "Axis 2"
        '
        'Label9
        '
        Me.Label9.BackColor = System.Drawing.SystemColors.Control
        Me.Label9.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label9.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label9.Location = New System.Drawing.Point(40, 18)
        Me.Label9.Name = "Label9"
        Me.Label9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label9.Size = New System.Drawing.Size(43, 15)
        Me.Label9.TabIndex = 55
        Me.Label9.Text = "Axis 0"
        '
        'Btn_ResetCounter
        '
        Me.Btn_ResetCounter.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_ResetCounter.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_ResetCounter.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_ResetCounter.Location = New System.Drawing.Point(469, 48)
        Me.Btn_ResetCounter.Name = "Btn_ResetCounter"
        Me.Btn_ResetCounter.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_ResetCounter.Size = New System.Drawing.Size(92, 89)
        Me.Btn_ResetCounter.TabIndex = 37
        Me.Btn_ResetCounter.Text = "Reset Counter"
        Me.Btn_ResetCounter.UseVisualStyleBackColor = False
        '
        '_Edit_ShowAxis_MSts_3
        '
        Me._Edit_ShowAxis_MSts_3.AcceptsReturn = True
        Me._Edit_ShowAxis_MSts_3.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_MSts_3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_MSts_3.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_MSts_3.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_MSts.SetIndex(Me._Edit_ShowAxis_MSts_3, CType(3, Short))
        Me._Edit_ShowAxis_MSts_3.Location = New System.Drawing.Point(344, 152)
        Me._Edit_ShowAxis_MSts_3.MaxLength = 0
        Me._Edit_ShowAxis_MSts_3.Name = "_Edit_ShowAxis_MSts_3"
        Me._Edit_ShowAxis_MSts_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_MSts_3.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_MSts_3.TabIndex = 36
        Me._Edit_ShowAxis_MSts_3.Text = "Text1"
        Me._Edit_ShowAxis_MSts_3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_MSts_2
        '
        Me._Edit_ShowAxis_MSts_2.AcceptsReturn = True
        Me._Edit_ShowAxis_MSts_2.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_MSts_2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_MSts_2.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_MSts_2.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_MSts.SetIndex(Me._Edit_ShowAxis_MSts_2, CType(2, Short))
        Me._Edit_ShowAxis_MSts_2.Location = New System.Drawing.Point(232, 152)
        Me._Edit_ShowAxis_MSts_2.MaxLength = 0
        Me._Edit_ShowAxis_MSts_2.Name = "_Edit_ShowAxis_MSts_2"
        Me._Edit_ShowAxis_MSts_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_MSts_2.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_MSts_2.TabIndex = 35
        Me._Edit_ShowAxis_MSts_2.Text = "Text1"
        Me._Edit_ShowAxis_MSts_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_MSts_1
        '
        Me._Edit_ShowAxis_MSts_1.AcceptsReturn = True
        Me._Edit_ShowAxis_MSts_1.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_MSts_1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_MSts_1.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_MSts_1.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_MSts.SetIndex(Me._Edit_ShowAxis_MSts_1, CType(1, Short))
        Me._Edit_ShowAxis_MSts_1.Location = New System.Drawing.Point(120, 152)
        Me._Edit_ShowAxis_MSts_1.MaxLength = 0
        Me._Edit_ShowAxis_MSts_1.Name = "_Edit_ShowAxis_MSts_1"
        Me._Edit_ShowAxis_MSts_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_MSts_1.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_MSts_1.TabIndex = 34
        Me._Edit_ShowAxis_MSts_1.Text = "Text1"
        Me._Edit_ShowAxis_MSts_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_IOSts_3
        '
        Me._Edit_ShowAxis_IOSts_3.AcceptsReturn = True
        Me._Edit_ShowAxis_IOSts_3.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_IOSts_3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_IOSts_3.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_IOSts_3.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_IOSts.SetIndex(Me._Edit_ShowAxis_IOSts_3, CType(3, Short))
        Me._Edit_ShowAxis_IOSts_3.Location = New System.Drawing.Point(344, 112)
        Me._Edit_ShowAxis_IOSts_3.MaxLength = 0
        Me._Edit_ShowAxis_IOSts_3.Name = "_Edit_ShowAxis_IOSts_3"
        Me._Edit_ShowAxis_IOSts_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_IOSts_3.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_IOSts_3.TabIndex = 33
        Me._Edit_ShowAxis_IOSts_3.Text = "Text1"
        Me._Edit_ShowAxis_IOSts_3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_IOSts_2
        '
        Me._Edit_ShowAxis_IOSts_2.AcceptsReturn = True
        Me._Edit_ShowAxis_IOSts_2.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_IOSts_2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_IOSts_2.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_IOSts_2.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_IOSts.SetIndex(Me._Edit_ShowAxis_IOSts_2, CType(2, Short))
        Me._Edit_ShowAxis_IOSts_2.Location = New System.Drawing.Point(232, 112)
        Me._Edit_ShowAxis_IOSts_2.MaxLength = 0
        Me._Edit_ShowAxis_IOSts_2.Name = "_Edit_ShowAxis_IOSts_2"
        Me._Edit_ShowAxis_IOSts_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_IOSts_2.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_IOSts_2.TabIndex = 32
        Me._Edit_ShowAxis_IOSts_2.Text = "Text1"
        Me._Edit_ShowAxis_IOSts_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_IOSts_1
        '
        Me._Edit_ShowAxis_IOSts_1.AcceptsReturn = True
        Me._Edit_ShowAxis_IOSts_1.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_IOSts_1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_IOSts_1.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_IOSts_1.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_IOSts.SetIndex(Me._Edit_ShowAxis_IOSts_1, CType(1, Short))
        Me._Edit_ShowAxis_IOSts_1.Location = New System.Drawing.Point(120, 112)
        Me._Edit_ShowAxis_IOSts_1.MaxLength = 0
        Me._Edit_ShowAxis_IOSts_1.Name = "_Edit_ShowAxis_IOSts_1"
        Me._Edit_ShowAxis_IOSts_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_IOSts_1.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_IOSts_1.TabIndex = 31
        Me._Edit_ShowAxis_IOSts_1.Text = "Text1"
        Me._Edit_ShowAxis_IOSts_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Feedback_3
        '
        Me._Edit_ShowAxis_Feedback_3.AcceptsReturn = True
        Me._Edit_ShowAxis_Feedback_3.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Feedback_3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Feedback_3.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Feedback_3.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Feedback.SetIndex(Me._Edit_ShowAxis_Feedback_3, CType(3, Short))
        Me._Edit_ShowAxis_Feedback_3.Location = New System.Drawing.Point(344, 72)
        Me._Edit_ShowAxis_Feedback_3.MaxLength = 0
        Me._Edit_ShowAxis_Feedback_3.Name = "_Edit_ShowAxis_Feedback_3"
        Me._Edit_ShowAxis_Feedback_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Feedback_3.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Feedback_3.TabIndex = 30
        Me._Edit_ShowAxis_Feedback_3.Text = "Text1"
        Me._Edit_ShowAxis_Feedback_3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Feedback_2
        '
        Me._Edit_ShowAxis_Feedback_2.AcceptsReturn = True
        Me._Edit_ShowAxis_Feedback_2.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Feedback_2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Feedback_2.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Feedback_2.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Feedback.SetIndex(Me._Edit_ShowAxis_Feedback_2, CType(2, Short))
        Me._Edit_ShowAxis_Feedback_2.Location = New System.Drawing.Point(232, 72)
        Me._Edit_ShowAxis_Feedback_2.MaxLength = 0
        Me._Edit_ShowAxis_Feedback_2.Name = "_Edit_ShowAxis_Feedback_2"
        Me._Edit_ShowAxis_Feedback_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Feedback_2.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Feedback_2.TabIndex = 29
        Me._Edit_ShowAxis_Feedback_2.Text = "Text1"
        Me._Edit_ShowAxis_Feedback_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Feedback_1
        '
        Me._Edit_ShowAxis_Feedback_1.AcceptsReturn = True
        Me._Edit_ShowAxis_Feedback_1.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Feedback_1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Feedback_1.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Feedback_1.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Feedback.SetIndex(Me._Edit_ShowAxis_Feedback_1, CType(1, Short))
        Me._Edit_ShowAxis_Feedback_1.Location = New System.Drawing.Point(120, 72)
        Me._Edit_ShowAxis_Feedback_1.MaxLength = 0
        Me._Edit_ShowAxis_Feedback_1.Name = "_Edit_ShowAxis_Feedback_1"
        Me._Edit_ShowAxis_Feedback_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Feedback_1.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Feedback_1.TabIndex = 28
        Me._Edit_ShowAxis_Feedback_1.Text = "Text1"
        Me._Edit_ShowAxis_Feedback_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Command_3
        '
        Me._Edit_ShowAxis_Command_3.AcceptsReturn = True
        Me._Edit_ShowAxis_Command_3.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Command_3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Command_3.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Command_3.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Command.SetIndex(Me._Edit_ShowAxis_Command_3, CType(3, Short))
        Me._Edit_ShowAxis_Command_3.Location = New System.Drawing.Point(344, 32)
        Me._Edit_ShowAxis_Command_3.MaxLength = 0
        Me._Edit_ShowAxis_Command_3.Name = "_Edit_ShowAxis_Command_3"
        Me._Edit_ShowAxis_Command_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Command_3.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Command_3.TabIndex = 27
        Me._Edit_ShowAxis_Command_3.Text = "Text1"
        Me._Edit_ShowAxis_Command_3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Command_2
        '
        Me._Edit_ShowAxis_Command_2.AcceptsReturn = True
        Me._Edit_ShowAxis_Command_2.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Command_2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Command_2.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Command_2.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Command.SetIndex(Me._Edit_ShowAxis_Command_2, CType(2, Short))
        Me._Edit_ShowAxis_Command_2.Location = New System.Drawing.Point(232, 32)
        Me._Edit_ShowAxis_Command_2.MaxLength = 0
        Me._Edit_ShowAxis_Command_2.Name = "_Edit_ShowAxis_Command_2"
        Me._Edit_ShowAxis_Command_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Command_2.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Command_2.TabIndex = 26
        Me._Edit_ShowAxis_Command_2.Text = "Text1"
        Me._Edit_ShowAxis_Command_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Command_1
        '
        Me._Edit_ShowAxis_Command_1.AcceptsReturn = True
        Me._Edit_ShowAxis_Command_1.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Command_1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Command_1.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Command_1.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Command.SetIndex(Me._Edit_ShowAxis_Command_1, CType(1, Short))
        Me._Edit_ShowAxis_Command_1.Location = New System.Drawing.Point(120, 32)
        Me._Edit_ShowAxis_Command_1.MaxLength = 0
        Me._Edit_ShowAxis_Command_1.Name = "_Edit_ShowAxis_Command_1"
        Me._Edit_ShowAxis_Command_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Command_1.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Command_1.TabIndex = 25
        Me._Edit_ShowAxis_Command_1.Text = "Text1"
        Me._Edit_ShowAxis_Command_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Feedback_0
        '
        Me._Edit_ShowAxis_Feedback_0.AcceptsReturn = True
        Me._Edit_ShowAxis_Feedback_0.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Feedback_0.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Feedback_0.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Feedback_0.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Feedback.SetIndex(Me._Edit_ShowAxis_Feedback_0, CType(0, Short))
        Me._Edit_ShowAxis_Feedback_0.Location = New System.Drawing.Point(8, 72)
        Me._Edit_ShowAxis_Feedback_0.MaxLength = 0
        Me._Edit_ShowAxis_Feedback_0.Name = "_Edit_ShowAxis_Feedback_0"
        Me._Edit_ShowAxis_Feedback_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Feedback_0.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Feedback_0.TabIndex = 20
        Me._Edit_ShowAxis_Feedback_0.Text = "Text1"
        Me._Edit_ShowAxis_Feedback_0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_Command_0
        '
        Me._Edit_ShowAxis_Command_0.AcceptsReturn = True
        Me._Edit_ShowAxis_Command_0.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_Command_0.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_Command_0.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_Command_0.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_Command.SetIndex(Me._Edit_ShowAxis_Command_0, CType(0, Short))
        Me._Edit_ShowAxis_Command_0.Location = New System.Drawing.Point(8, 32)
        Me._Edit_ShowAxis_Command_0.MaxLength = 0
        Me._Edit_ShowAxis_Command_0.Name = "_Edit_ShowAxis_Command_0"
        Me._Edit_ShowAxis_Command_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_Command_0.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_Command_0.TabIndex = 19
        Me._Edit_ShowAxis_Command_0.Text = "Text1"
        Me._Edit_ShowAxis_Command_0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_MSts_0
        '
        Me._Edit_ShowAxis_MSts_0.AcceptsReturn = True
        Me._Edit_ShowAxis_MSts_0.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_MSts_0.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_MSts_0.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_MSts_0.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_MSts.SetIndex(Me._Edit_ShowAxis_MSts_0, CType(0, Short))
        Me._Edit_ShowAxis_MSts_0.Location = New System.Drawing.Point(8, 152)
        Me._Edit_ShowAxis_MSts_0.MaxLength = 0
        Me._Edit_ShowAxis_MSts_0.Name = "_Edit_ShowAxis_MSts_0"
        Me._Edit_ShowAxis_MSts_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_MSts_0.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_MSts_0.TabIndex = 18
        Me._Edit_ShowAxis_MSts_0.Text = "Text1"
        Me._Edit_ShowAxis_MSts_0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowAxis_IOSts_0
        '
        Me._Edit_ShowAxis_IOSts_0.AcceptsReturn = True
        Me._Edit_ShowAxis_IOSts_0.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowAxis_IOSts_0.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowAxis_IOSts_0.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowAxis_IOSts_0.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowAxis_IOSts.SetIndex(Me._Edit_ShowAxis_IOSts_0, CType(0, Short))
        Me._Edit_ShowAxis_IOSts_0.Location = New System.Drawing.Point(8, 112)
        Me._Edit_ShowAxis_IOSts_0.MaxLength = 0
        Me._Edit_ShowAxis_IOSts_0.Name = "_Edit_ShowAxis_IOSts_0"
        Me._Edit_ShowAxis_IOSts_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowAxis_IOSts_0.Size = New System.Drawing.Size(105, 20)
        Me._Edit_ShowAxis_IOSts_0.TabIndex = 17
        Me._Edit_ShowAxis_IOSts_0.Text = "Text1"
        Me._Edit_ShowAxis_IOSts_0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label999
        '
        Me.Label999.BackColor = System.Drawing.SystemColors.Control
        Me.Label999.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label999.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label999.Location = New System.Drawing.Point(246, 161)
        Me.Label999.Name = "Label999"
        Me.Label999.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label999.Size = New System.Drawing.Size(75, 20)
        Me.Label999.TabIndex = 53
        Me.Label999.Text = "Motion Status" & Global.Microsoft.VisualBasic.ChrW(10)
        '
        'Label11
        '
        Me.Label11.BackColor = System.Drawing.SystemColors.Control
        Me.Label11.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label11.Location = New System.Drawing.Point(236, 125)
        Me.Label11.Name = "Label11"
        Me.Label11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label11.Size = New System.Drawing.Size(86, 16)
        Me.Label11.TabIndex = 52
        Me.Label11.Text = "Motion IO Status "
        '
        'Label26
        '
        Me.Label26.BackColor = System.Drawing.SystemColors.Control
        Me.Label26.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label26.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label26.Location = New System.Drawing.Point(238, 85)
        Me.Label26.Name = "Label26"
        Me.Label26.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label26.Size = New System.Drawing.Size(84, 17)
        Me.Label26.TabIndex = 51
        Me.Label26.Text = "Feedback Pulses" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10)
        '
        'Label27
        '
        Me.Label27.BackColor = System.Drawing.SystemColors.Control
        Me.Label27.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label27.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label27.Location = New System.Drawing.Point(235, 45)
        Me.Label27.Name = "Label27"
        Me.Label27.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label27.Size = New System.Drawing.Size(86, 17)
        Me.Label27.TabIndex = 50
        Me.Label27.Text = "Command Pulses"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 50
        '
        'Frame1
        '
        Me.Frame1.BackColor = System.Drawing.SystemColors.Control
        Me.Frame1.Controls.Add(Me.Edit_ShowMaster_CPLDVer)
        Me.Frame1.Controls.Add(Me.Edit_ShowMaster_DLLVer)
        Me.Frame1.Controls.Add(Me.Edit_ShowMaster_DriverVer)
        Me.Frame1.Controls.Add(Me.Label5)
        Me.Frame1.Controls.Add(Me.Label2)
        Me.Frame1.Controls.Add(Me.Label1)
        Me.Frame1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame1.Location = New System.Drawing.Point(24, 9)
        Me.Frame1.Name = "Frame1"
        Me.Frame1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame1.Size = New System.Drawing.Size(145, 177)
        Me.Frame1.TabIndex = 0
        Me.Frame1.TabStop = False
        Me.Frame1.Text = "Master Card Info"
        '
        'Edit_ShowMaster_DLLVer
        '
        Me.Edit_ShowMaster_DLLVer.AcceptsReturn = True
        Me.Edit_ShowMaster_DLLVer.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_ShowMaster_DLLVer.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_ShowMaster_DLLVer.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_ShowMaster_DLLVer.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowMaster_DLLVer.Location = New System.Drawing.Point(16, 88)
        Me.Edit_ShowMaster_DLLVer.MaxLength = 0
        Me.Edit_ShowMaster_DLLVer.Name = "Edit_ShowMaster_DLLVer"
        Me.Edit_ShowMaster_DLLVer.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_ShowMaster_DLLVer.Size = New System.Drawing.Size(105, 20)
        Me.Edit_ShowMaster_DLLVer.TabIndex = 6
        Me.Edit_ShowMaster_DLLVer.Text = "Text1"
        Me.Edit_ShowMaster_DLLVer.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Edit_ShowMaster_DriverVer
        '
        Me.Edit_ShowMaster_DriverVer.AcceptsReturn = True
        Me.Edit_ShowMaster_DriverVer.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_ShowMaster_DriverVer.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_ShowMaster_DriverVer.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_ShowMaster_DriverVer.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowMaster_DriverVer.Location = New System.Drawing.Point(16, 48)
        Me.Edit_ShowMaster_DriverVer.MaxLength = 0
        Me.Edit_ShowMaster_DriverVer.Name = "Edit_ShowMaster_DriverVer"
        Me.Edit_ShowMaster_DriverVer.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_ShowMaster_DriverVer.Size = New System.Drawing.Size(105, 20)
        Me.Edit_ShowMaster_DriverVer.TabIndex = 4
        Me.Edit_ShowMaster_DriverVer.Text = "Text1"
        Me.Edit_ShowMaster_DriverVer.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label5
        '
        Me.Label5.BackColor = System.Drawing.SystemColors.Control
        Me.Label5.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label5.Location = New System.Drawing.Point(16, 118)
        Me.Label5.Name = "Label5"
        Me.Label5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label5.Size = New System.Drawing.Size(89, 17)
        Me.Label5.TabIndex = 11
        Me.Label5.Text = "FPGA Version"
        '
        'Label2
        '
        Me.Label2.BackColor = System.Drawing.SystemColors.Control
        Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label2.Location = New System.Drawing.Point(16, 72)
        Me.Label2.Name = "Label2"
        Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label2.Size = New System.Drawing.Size(89, 17)
        Me.Label2.TabIndex = 5
        Me.Label2.Text = "DLL Version"
        '
        'Label1
        '
        Me.Label1.BackColor = System.Drawing.SystemColors.Control
        Me.Label1.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label1.Location = New System.Drawing.Point(16, 32)
        Me.Label1.Name = "Label1"
        Me.Label1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label1.Size = New System.Drawing.Size(89, 17)
        Me.Label1.TabIndex = 3
        Me.Label1.Text = "Driver Version"
        '
        'GroupBox1
        '
        Me.GroupBox1.BackColor = System.Drawing.SystemColors.Control
        Me.GroupBox1.Controls.Add(Me.Btn_Arc_2Axes_Absolute_Stop2)
        Me.GroupBox1.Controls.Add(Me.Btn_Arc_2Axes_Absolute_CW)
        Me.GroupBox1.Controls.Add(Me.Btn_Arc_2Axes_Absolute_CCW)
        Me.GroupBox1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.GroupBox1.Location = New System.Drawing.Point(24, 359)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.GroupBox1.Size = New System.Drawing.Size(185, 161)
        Me.GroupBox1.TabIndex = 56
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "2 Axes Arc Absolute Move"
        '
        'Btn_Arc_2Axes_Absolute_Stop2
        '
        Me.Btn_Arc_2Axes_Absolute_Stop2.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Arc_2Axes_Absolute_Stop2.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Arc_2Axes_Absolute_Stop2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Arc_2Axes_Absolute_Stop2.Location = New System.Drawing.Point(56, 88)
        Me.Btn_Arc_2Axes_Absolute_Stop2.Name = "Btn_Arc_2Axes_Absolute_Stop2"
        Me.Btn_Arc_2Axes_Absolute_Stop2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Arc_2Axes_Absolute_Stop2.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Arc_2Axes_Absolute_Stop2.TabIndex = 70
        Me.Btn_Arc_2Axes_Absolute_Stop2.Text = "Stop"
        Me.Btn_Arc_2Axes_Absolute_Stop2.UseVisualStyleBackColor = False
        '
        'Btn_Arc_2Axes_Absolute_CW
        '
        Me.Btn_Arc_2Axes_Absolute_CW.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Arc_2Axes_Absolute_CW.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Arc_2Axes_Absolute_CW.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Arc_2Axes_Absolute_CW.Location = New System.Drawing.Point(104, 24)
        Me.Btn_Arc_2Axes_Absolute_CW.Name = "Btn_Arc_2Axes_Absolute_CW"
        Me.Btn_Arc_2Axes_Absolute_CW.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Arc_2Axes_Absolute_CW.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Arc_2Axes_Absolute_CW.TabIndex = 69
        Me.Btn_Arc_2Axes_Absolute_CW.Text = "CW"
        Me.Btn_Arc_2Axes_Absolute_CW.UseVisualStyleBackColor = False
        '
        'Btn_Arc_2Axes_Absolute_CCW
        '
        Me.Btn_Arc_2Axes_Absolute_CCW.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Arc_2Axes_Absolute_CCW.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Arc_2Axes_Absolute_CCW.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Arc_2Axes_Absolute_CCW.Location = New System.Drawing.Point(16, 24)
        Me.Btn_Arc_2Axes_Absolute_CCW.Name = "Btn_Arc_2Axes_Absolute_CCW"
        Me.Btn_Arc_2Axes_Absolute_CCW.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Arc_2Axes_Absolute_CCW.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Arc_2Axes_Absolute_CCW.TabIndex = 68
        Me.Btn_Arc_2Axes_Absolute_CCW.Text = "CCW"
        Me.Btn_Arc_2Axes_Absolute_CCW.UseVisualStyleBackColor = False
        '
        'GroupBox2
        '
        Me.GroupBox2.BackColor = System.Drawing.SystemColors.Control
        Me.GroupBox2.Controls.Add(Me.Btn_Arc_2Axes_Relateive_Stop)
        Me.GroupBox2.Controls.Add(Me.Btn_Arc_2Axes_Relative_CW)
        Me.GroupBox2.Controls.Add(Me.Btn_Arc_2Axes_Relative_CCW)
        Me.GroupBox2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.GroupBox2.Location = New System.Drawing.Point(215, 359)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.GroupBox2.Size = New System.Drawing.Size(185, 161)
        Me.GroupBox2.TabIndex = 57
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "2 Axes Arc Relative Move"
        '
        'Btn_Arc_2Axes_Relateive_Stop
        '
        Me.Btn_Arc_2Axes_Relateive_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Arc_2Axes_Relateive_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Arc_2Axes_Relateive_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Arc_2Axes_Relateive_Stop.Location = New System.Drawing.Point(56, 88)
        Me.Btn_Arc_2Axes_Relateive_Stop.Name = "Btn_Arc_2Axes_Relateive_Stop"
        Me.Btn_Arc_2Axes_Relateive_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Arc_2Axes_Relateive_Stop.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Arc_2Axes_Relateive_Stop.TabIndex = 70
        Me.Btn_Arc_2Axes_Relateive_Stop.Text = "Stop"
        Me.Btn_Arc_2Axes_Relateive_Stop.UseVisualStyleBackColor = False
        '
        'Btn_Arc_2Axes_Relative_CW
        '
        Me.Btn_Arc_2Axes_Relative_CW.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Arc_2Axes_Relative_CW.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Arc_2Axes_Relative_CW.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Arc_2Axes_Relative_CW.Location = New System.Drawing.Point(104, 24)
        Me.Btn_Arc_2Axes_Relative_CW.Name = "Btn_Arc_2Axes_Relative_CW"
        Me.Btn_Arc_2Axes_Relative_CW.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Arc_2Axes_Relative_CW.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Arc_2Axes_Relative_CW.TabIndex = 69
        Me.Btn_Arc_2Axes_Relative_CW.Text = "CW"
        Me.Btn_Arc_2Axes_Relative_CW.UseVisualStyleBackColor = False
        '
        'Btn_Arc_2Axes_Relative_CCW
        '
        Me.Btn_Arc_2Axes_Relative_CCW.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Arc_2Axes_Relative_CCW.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Arc_2Axes_Relative_CCW.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Arc_2Axes_Relative_CCW.Location = New System.Drawing.Point(16, 24)
        Me.Btn_Arc_2Axes_Relative_CCW.Name = "Btn_Arc_2Axes_Relative_CCW"
        Me.Btn_Arc_2Axes_Relative_CCW.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Arc_2Axes_Relative_CCW.Size = New System.Drawing.Size(65, 57)
        Me.Btn_Arc_2Axes_Relative_CCW.TabIndex = 68
        Me.Btn_Arc_2Axes_Relative_CCW.Text = "CCW"
        Me.Btn_Arc_2Axes_Relative_CCW.UseVisualStyleBackColor = False
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(265, 591)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(101, 47)
        Me.Button2.TabIndex = 60
        Me.Button2.Text = "Set Card ID"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Location = New System.Drawing.Point(263, 548)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(71, 12)
        Me.Label7.TabIndex = 61
        Me.Label7.Text = "Input Card ID"
        '
        'MaskedTextBox1
        '
        Me.MaskedTextBox1.Location = New System.Drawing.Point(265, 563)
        Me.MaskedTextBox1.Name = "MaskedTextBox1"
        Me.MaskedTextBox1.Size = New System.Drawing.Size(99, 22)
        Me.MaskedTextBox1.TabIndex = 62
        Me.MaskedTextBox1.Text = "0"
        '
        'MainForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.AutoSize = True
        Me.BackColor = System.Drawing.SystemColors.Control
        Me.ClientSize = New System.Drawing.Size(1028, 712)
        Me.Controls.Add(Me.MaskedTextBox1)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.Frame12)
        Me.Controls.Add(Me.Frame14)
        Me.Controls.Add(Me.Frame13)
        Me.Controls.Add(Me.Frame11)
        Me.Controls.Add(Me.Frame10)
        Me.Controls.Add(Me.Frame9)
        Me.Controls.Add(Me.Frame8)
        Me.Controls.Add(Me.Label999)
        Me.Controls.Add(Me.Frame7)
        Me.Controls.Add(Me.Label11)
        Me.Controls.Add(Me.Frame6)
        Me.Controls.Add(Me.Label26)
        Me.Controls.Add(Me.Label27)
        Me.Controls.Add(Me.Frame3)
        Me.Controls.Add(Me.Frame1)
        Me.Cursor = System.Windows.Forms.Cursors.Default
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Location = New System.Drawing.Point(167, 44)
        Me.Name = "MainForm"
        Me.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
        Me.Text = "ADLINK VBNET Sample"
        Me.Frame14.ResumeLayout(False)
        Me.Frame13.ResumeLayout(False)
        Me.Frame12.ResumeLayout(False)
        Me.Frame11.ResumeLayout(False)
        Me.Frame10.ResumeLayout(False)
        Me.Frame9.ResumeLayout(False)
        Me.Frame8.ResumeLayout(False)
        Me.Frame7.ResumeLayout(False)
        Me.Frame6.ResumeLayout(False)
        Me.Frame3.ResumeLayout(False)
        Me.Frame3.PerformLayout()
        Me.Frame1.ResumeLayout(False)
        Me.Frame1.PerformLayout()
        CType(Me.Edit_ShowAxis_Command, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Edit_ShowAxis_Feedback, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Edit_ShowAxis_IOSts, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Edit_ShowAxis_MSts, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Edit_ShowTriggerCount, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Edit_ShowTriggerEnc, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Edit_ShowTrigger_LinearCMP_LinearCMP, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Label15, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox2.ResumeLayout(False)
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Public WithEvents Label9 As System.Windows.Forms.Label
    Public WithEvents Label999 As System.Windows.Forms.Label
    Public WithEvents Label11 As System.Windows.Forms.Label
    Public WithEvents Label26 As System.Windows.Forms.Label
    Public WithEvents Label27 As System.Windows.Forms.Label
    Public WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Public WithEvents Btn_Arc_2Axes_Absolute_Stop2 As System.Windows.Forms.Button
    Public WithEvents Btn_Arc_2Axes_Absolute_CW As System.Windows.Forms.Button
    Public WithEvents Btn_Arc_2Axes_Absolute_CCW As System.Windows.Forms.Button
    Public WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Public WithEvents Btn_Arc_2Axes_Relateive_Stop As System.Windows.Forms.Button
    Public WithEvents Btn_Arc_2Axes_Relative_CW As System.Windows.Forms.Button
    Public WithEvents Btn_Arc_2Axes_Relative_CCW As System.Windows.Forms.Button
    Public WithEvents Label5 As System.Windows.Forms.Label
    Public WithEvents Label6 As System.Windows.Forms.Label
    Public WithEvents Label4 As System.Windows.Forms.Label
    Public WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents MaskedTextBox1 As System.Windows.Forms.MaskedTextBox
#End Region
End Class