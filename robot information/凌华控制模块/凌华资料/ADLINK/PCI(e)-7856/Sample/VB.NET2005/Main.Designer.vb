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
	Public WithEvents Btn_Trigger_Count As System.Windows.Forms.Button
	Public WithEvents Btn_Manual_Compare As System.Windows.Forms.Button
	Public WithEvents Btn_Table_Compare As System.Windows.Forms.Button
	Public WithEvents Btn_Linear_Compare As System.Windows.Forms.Button
	Public WithEvents _Edit_ShowTrigger_LinearCMP_LinearCMP_3 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTrigger_LinearCMP_LinearCMP_2 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTrigger_LinearCMP_LinearCMP_1 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTrigger_LinearCMP_LinearCMP_0 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerEnc_3 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerEnc_2 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerEnc_1 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerEnc_0 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerCount_3 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerCount_2 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerCount_1 As System.Windows.Forms.TextBox
	Public WithEvents _Edit_ShowTriggerCount_0 As System.Windows.Forms.TextBox
	Public WithEvents _Label15_11 As System.Windows.Forms.Label
	Public WithEvents _Label15_10 As System.Windows.Forms.Label
	Public WithEvents _Label15_9 As System.Windows.Forms.Label
	Public WithEvents _Label15_8 As System.Windows.Forms.Label
	Public WithEvents _Label15_7 As System.Windows.Forms.Label
	Public WithEvents _Label15_6 As System.Windows.Forms.Label
	Public WithEvents _Label15_5 As System.Windows.Forms.Label
	Public WithEvents _Label15_4 As System.Windows.Forms.Label
	Public WithEvents _Label15_3 As System.Windows.Forms.Label
	Public WithEvents _Label15_2 As System.Windows.Forms.Label
	Public WithEvents _Label15_1 As System.Windows.Forms.Label
	Public WithEvents _Label15_0 As System.Windows.Forms.Label
	Public WithEvents Frame17 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_PointTable_MoveALL As System.Windows.Forms.Button
	Public WithEvents Frame18 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_PointTable_Stop As System.Windows.Forms.Button
	Public WithEvents Btn_PointTable_SingleIndexMove As System.Windows.Forms.Button
	Public WithEvents Btn_SetPointTable As System.Windows.Forms.Button
	Public WithEvents Edit_SetTargetIndex_ForSinglePointMove As System.Windows.Forms.TextBox
	Public WithEvents Label14 As System.Windows.Forms.Label
	Public WithEvents Frame16 As System.Windows.Forms.GroupBox
	Public WithEvents Edit_Show_PointTable_CurrIndex As System.Windows.Forms.TextBox
	Public WithEvents Label13 As System.Windows.Forms.Label
	Public WithEvents Frame15 As System.Windows.Forms.GroupBox
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
	Public WithEvents Btn_GetModuleInfo As System.Windows.Forms.Button
	Public WithEvents Edit_SetModuleID_ForModuleInfo As System.Windows.Forms.TextBox
	Public WithEvents Label12 As System.Windows.Forms.Label
	Public WithEvents Frame5 As System.Windows.Forms.GroupBox
	Public WithEvents Btn_BusDisconnect As System.Windows.Forms.Button
	Public WithEvents Btn_BusConnect As System.Windows.Forms.Button
	Public WithEvents Frame4 As System.Windows.Forms.GroupBox
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
    Public WithEvents Edit_ShowModule_PCBTopVer As System.Windows.Forms.TextBox
    Public WithEvents Edit_ShowModule_FPGAVer As System.Windows.Forms.TextBox
    Public WithEvents Label8 As System.Windows.Forms.Label
    Public WithEvents Label7 As System.Windows.Forms.Label
    Public WithEvents Frame2 As System.Windows.Forms.GroupBox
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
        Me.Frame17 = New System.Windows.Forms.GroupBox
        Me.Btn_Trigger_Count = New System.Windows.Forms.Button
        Me.Btn_Manual_Compare = New System.Windows.Forms.Button
        Me.Btn_Table_Compare = New System.Windows.Forms.Button
        Me.Btn_Linear_Compare = New System.Windows.Forms.Button
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerEnc_3 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerEnc_2 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerEnc_1 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerEnc_0 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerCount_3 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerCount_2 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerCount_1 = New System.Windows.Forms.TextBox
        Me._Edit_ShowTriggerCount_0 = New System.Windows.Forms.TextBox
        Me._Label15_11 = New System.Windows.Forms.Label
        Me._Label15_10 = New System.Windows.Forms.Label
        Me._Label15_9 = New System.Windows.Forms.Label
        Me._Label15_8 = New System.Windows.Forms.Label
        Me._Label15_7 = New System.Windows.Forms.Label
        Me._Label15_6 = New System.Windows.Forms.Label
        Me._Label15_5 = New System.Windows.Forms.Label
        Me._Label15_4 = New System.Windows.Forms.Label
        Me._Label15_3 = New System.Windows.Forms.Label
        Me._Label15_2 = New System.Windows.Forms.Label
        Me._Label15_1 = New System.Windows.Forms.Label
        Me._Label15_0 = New System.Windows.Forms.Label
        Me.Frame15 = New System.Windows.Forms.GroupBox
        Me.Frame18 = New System.Windows.Forms.GroupBox
        Me.Btn_PointTable_MoveALL = New System.Windows.Forms.Button
        Me.Btn_PointTable_Stop = New System.Windows.Forms.Button
        Me.Frame16 = New System.Windows.Forms.GroupBox
        Me.Btn_PointTable_SingleIndexMove = New System.Windows.Forms.Button
        Me.Btn_SetPointTable = New System.Windows.Forms.Button
        Me.Edit_SetTargetIndex_ForSinglePointMove = New System.Windows.Forms.TextBox
        Me.Label14 = New System.Windows.Forms.Label
        Me.Edit_Show_PointTable_CurrIndex = New System.Windows.Forms.TextBox
        Me.Label13 = New System.Windows.Forms.Label
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
        Me.Frame5 = New System.Windows.Forms.GroupBox
        Me.Btn_GetModuleInfo = New System.Windows.Forms.Button
        Me.Edit_SetModuleID_ForModuleInfo = New System.Windows.Forms.TextBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.Frame4 = New System.Windows.Forms.GroupBox
        Me.Btn_BusDisconnect = New System.Windows.Forms.Button
        Me.Btn_BusConnect = New System.Windows.Forms.Button
        Me.Edit_ShowMaster_CPLDVer = New System.Windows.Forms.TextBox
        Me.Frame3 = New System.Windows.Forms.GroupBox
        Me.label25 = New System.Windows.Forms.Label
        Me.label24 = New System.Windows.Forms.Label
        Me.label23 = New System.Windows.Forms.Label
        Me.label22 = New System.Windows.Forms.Label
        Me.label21 = New System.Windows.Forms.Label
        Me.label20 = New System.Windows.Forms.Label
        Me.label19 = New System.Windows.Forms.Label
        Me.label18 = New System.Windows.Forms.Label
        Me.label17 = New System.Windows.Forms.Label
        Me.label16 = New System.Windows.Forms.Label
        Me.Label9 = New System.Windows.Forms.Label
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label999 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.Label26 = New System.Windows.Forms.Label
        Me.Label27 = New System.Windows.Forms.Label
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
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Frame2 = New System.Windows.Forms.GroupBox
        Me.Edit_ShowMaster_PCBBottomVer = New System.Windows.Forms.TextBox
        Me.Label6 = New System.Windows.Forms.Label
        Me.Edit_ShowModule_PCBTopVer = New System.Windows.Forms.TextBox
        Me.Edit_ShowModule_FPGAVer = New System.Windows.Forms.TextBox
        Me.Label8 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
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
        Me.GroupBox3 = New System.Windows.Forms.GroupBox
        Me.Btn_Set_DOData = New System.Windows.Forms.Button
        Me.Edit_SetDOData = New System.Windows.Forms.TextBox
        Me.Label31 = New System.Windows.Forms.Label
        Me.Edit_GetDOData = New System.Windows.Forms.TextBox
        Me.Edit_ShowDIData = New System.Windows.Forms.TextBox
        Me.Label29 = New System.Windows.Forms.Label
        Me.Label30 = New System.Windows.Forms.Label
        Me.Edit_SetModuleID_ForGeneralDIO = New System.Windows.Forms.TextBox
        Me.Label28 = New System.Windows.Forms.Label
        Me.Frame17.SuspendLayout()
        Me.Frame15.SuspendLayout()
        Me.Frame18.SuspendLayout()
        Me.Frame16.SuspendLayout()
        Me.Frame14.SuspendLayout()
        Me.Frame13.SuspendLayout()
        Me.Frame12.SuspendLayout()
        Me.Frame11.SuspendLayout()
        Me.Frame10.SuspendLayout()
        Me.Frame9.SuspendLayout()
        Me.Frame8.SuspendLayout()
        Me.Frame7.SuspendLayout()
        Me.Frame6.SuspendLayout()
        Me.Frame5.SuspendLayout()
        Me.Frame4.SuspendLayout()
        Me.Frame3.SuspendLayout()
        Me.Frame2.SuspendLayout()
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
        Me.GroupBox3.SuspendLayout()
        Me.SuspendLayout()
        '
        'Frame17
        '
        Me.Frame17.BackColor = System.Drawing.SystemColors.Control
        Me.Frame17.Controls.Add(Me.Btn_Trigger_Count)
        Me.Frame17.Controls.Add(Me.Btn_Manual_Compare)
        Me.Frame17.Controls.Add(Me.Btn_Table_Compare)
        Me.Frame17.Controls.Add(Me.Btn_Linear_Compare)
        Me.Frame17.Controls.Add(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3)
        Me.Frame17.Controls.Add(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2)
        Me.Frame17.Controls.Add(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1)
        Me.Frame17.Controls.Add(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerEnc_3)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerEnc_2)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerEnc_1)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerEnc_0)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerCount_3)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerCount_2)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerCount_1)
        Me.Frame17.Controls.Add(Me._Edit_ShowTriggerCount_0)
        Me.Frame17.Controls.Add(Me._Label15_11)
        Me.Frame17.Controls.Add(Me._Label15_10)
        Me.Frame17.Controls.Add(Me._Label15_9)
        Me.Frame17.Controls.Add(Me._Label15_8)
        Me.Frame17.Controls.Add(Me._Label15_7)
        Me.Frame17.Controls.Add(Me._Label15_6)
        Me.Frame17.Controls.Add(Me._Label15_5)
        Me.Frame17.Controls.Add(Me._Label15_4)
        Me.Frame17.Controls.Add(Me._Label15_3)
        Me.Frame17.Controls.Add(Me._Label15_2)
        Me.Frame17.Controls.Add(Me._Label15_1)
        Me.Frame17.Controls.Add(Me._Label15_0)
        Me.Frame17.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame17.Location = New System.Drawing.Point(776, 520)
        Me.Frame17.Name = "Frame17"
        Me.Frame17.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame17.Size = New System.Drawing.Size(377, 177)
        Me.Frame17.TabIndex = 55
        Me.Frame17.TabStop = False
        Me.Frame17.Text = "Compare"
        '
        'Btn_Trigger_Count
        '
        Me.Btn_Trigger_Count.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Trigger_Count.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Trigger_Count.Font = New System.Drawing.Font("新細明體", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Btn_Trigger_Count.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Trigger_Count.Location = New System.Drawing.Point(288, 136)
        Me.Btn_Trigger_Count.Name = "Btn_Trigger_Count"
        Me.Btn_Trigger_Count.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Trigger_Count.Size = New System.Drawing.Size(81, 33)
        Me.Btn_Trigger_Count.TabIndex = 120
        Me.Btn_Trigger_Count.Text = "Reset Trigger Count"
        Me.Btn_Trigger_Count.UseVisualStyleBackColor = False
        '
        'Btn_Manual_Compare
        '
        Me.Btn_Manual_Compare.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Manual_Compare.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Manual_Compare.Font = New System.Drawing.Font("新細明體", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Btn_Manual_Compare.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Manual_Compare.Location = New System.Drawing.Point(184, 136)
        Me.Btn_Manual_Compare.Name = "Btn_Manual_Compare"
        Me.Btn_Manual_Compare.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Manual_Compare.Size = New System.Drawing.Size(81, 33)
        Me.Btn_Manual_Compare.TabIndex = 119
        Me.Btn_Manual_Compare.Text = "Manual CMP"
        Me.Btn_Manual_Compare.UseVisualStyleBackColor = False
        '
        'Btn_Table_Compare
        '
        Me.Btn_Table_Compare.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Table_Compare.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Table_Compare.Font = New System.Drawing.Font("新細明體", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Btn_Table_Compare.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Table_Compare.Location = New System.Drawing.Point(96, 136)
        Me.Btn_Table_Compare.Name = "Btn_Table_Compare"
        Me.Btn_Table_Compare.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Table_Compare.Size = New System.Drawing.Size(81, 33)
        Me.Btn_Table_Compare.TabIndex = 118
        Me.Btn_Table_Compare.Text = "Table CMP"
        Me.Btn_Table_Compare.UseVisualStyleBackColor = False
        '
        'Btn_Linear_Compare
        '
        Me.Btn_Linear_Compare.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Linear_Compare.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Linear_Compare.Font = New System.Drawing.Font("新細明體", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Btn_Linear_Compare.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Linear_Compare.Location = New System.Drawing.Point(8, 136)
        Me.Btn_Linear_Compare.Name = "Btn_Linear_Compare"
        Me.Btn_Linear_Compare.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Linear_Compare.Size = New System.Drawing.Size(81, 33)
        Me.Btn_Linear_Compare.TabIndex = 117
        Me.Btn_Linear_Compare.Text = "LineCMP"
        Me.Btn_Linear_Compare.UseVisualStyleBackColor = False
        '
        '_Edit_ShowTrigger_LinearCMP_LinearCMP_3
        '
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.AcceptsReturn = True
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTrigger_LinearCMP_LinearCMP.SetIndex(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3, CType(3, Short))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.Location = New System.Drawing.Point(280, 112)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.MaxLength = 0
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.Name = "_Edit_ShowTrigger_LinearCMP_LinearCMP_3"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.TabIndex = 116
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.Text = "Text1"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTrigger_LinearCMP_LinearCMP_2
        '
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.AcceptsReturn = True
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTrigger_LinearCMP_LinearCMP.SetIndex(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2, CType(2, Short))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.Location = New System.Drawing.Point(200, 112)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.MaxLength = 0
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.Name = "_Edit_ShowTrigger_LinearCMP_LinearCMP_2"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.TabIndex = 114
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.Text = "Text1"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTrigger_LinearCMP_LinearCMP_1
        '
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.AcceptsReturn = True
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTrigger_LinearCMP_LinearCMP.SetIndex(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1, CType(1, Short))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.Location = New System.Drawing.Point(112, 112)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.MaxLength = 0
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.Name = "_Edit_ShowTrigger_LinearCMP_LinearCMP_1"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.TabIndex = 112
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.Text = "Text1"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTrigger_LinearCMP_LinearCMP_0
        '
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.AcceptsReturn = True
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTrigger_LinearCMP_LinearCMP.SetIndex(Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0, CType(0, Short))
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.Location = New System.Drawing.Point(24, 112)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.MaxLength = 0
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.Name = "_Edit_ShowTrigger_LinearCMP_LinearCMP_0"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.TabIndex = 110
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.Text = "Text1"
        Me._Edit_ShowTrigger_LinearCMP_LinearCMP_0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerEnc_3
        '
        Me._Edit_ShowTriggerEnc_3.AcceptsReturn = True
        Me._Edit_ShowTriggerEnc_3.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerEnc_3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerEnc_3.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerEnc_3.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerEnc.SetIndex(Me._Edit_ShowTriggerEnc_3, CType(3, Short))
        Me._Edit_ShowTriggerEnc_3.Location = New System.Drawing.Point(280, 72)
        Me._Edit_ShowTriggerEnc_3.MaxLength = 0
        Me._Edit_ShowTriggerEnc_3.Name = "_Edit_ShowTriggerEnc_3"
        Me._Edit_ShowTriggerEnc_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerEnc_3.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerEnc_3.TabIndex = 108
        Me._Edit_ShowTriggerEnc_3.Text = "Text1"
        Me._Edit_ShowTriggerEnc_3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerEnc_2
        '
        Me._Edit_ShowTriggerEnc_2.AcceptsReturn = True
        Me._Edit_ShowTriggerEnc_2.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerEnc_2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerEnc_2.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerEnc_2.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerEnc.SetIndex(Me._Edit_ShowTriggerEnc_2, CType(2, Short))
        Me._Edit_ShowTriggerEnc_2.Location = New System.Drawing.Point(200, 72)
        Me._Edit_ShowTriggerEnc_2.MaxLength = 0
        Me._Edit_ShowTriggerEnc_2.Name = "_Edit_ShowTriggerEnc_2"
        Me._Edit_ShowTriggerEnc_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerEnc_2.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerEnc_2.TabIndex = 106
        Me._Edit_ShowTriggerEnc_2.Text = "Text1"
        Me._Edit_ShowTriggerEnc_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerEnc_1
        '
        Me._Edit_ShowTriggerEnc_1.AcceptsReturn = True
        Me._Edit_ShowTriggerEnc_1.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerEnc_1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerEnc_1.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerEnc_1.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerEnc.SetIndex(Me._Edit_ShowTriggerEnc_1, CType(1, Short))
        Me._Edit_ShowTriggerEnc_1.Location = New System.Drawing.Point(112, 72)
        Me._Edit_ShowTriggerEnc_1.MaxLength = 0
        Me._Edit_ShowTriggerEnc_1.Name = "_Edit_ShowTriggerEnc_1"
        Me._Edit_ShowTriggerEnc_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerEnc_1.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerEnc_1.TabIndex = 104
        Me._Edit_ShowTriggerEnc_1.Text = "Text1"
        Me._Edit_ShowTriggerEnc_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerEnc_0
        '
        Me._Edit_ShowTriggerEnc_0.AcceptsReturn = True
        Me._Edit_ShowTriggerEnc_0.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerEnc_0.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerEnc_0.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerEnc_0.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerEnc.SetIndex(Me._Edit_ShowTriggerEnc_0, CType(0, Short))
        Me._Edit_ShowTriggerEnc_0.Location = New System.Drawing.Point(24, 72)
        Me._Edit_ShowTriggerEnc_0.MaxLength = 0
        Me._Edit_ShowTriggerEnc_0.Name = "_Edit_ShowTriggerEnc_0"
        Me._Edit_ShowTriggerEnc_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerEnc_0.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerEnc_0.TabIndex = 102
        Me._Edit_ShowTriggerEnc_0.Text = "Text1"
        Me._Edit_ShowTriggerEnc_0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerCount_3
        '
        Me._Edit_ShowTriggerCount_3.AcceptsReturn = True
        Me._Edit_ShowTriggerCount_3.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerCount_3.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerCount_3.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerCount_3.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerCount.SetIndex(Me._Edit_ShowTriggerCount_3, CType(3, Short))
        Me._Edit_ShowTriggerCount_3.Location = New System.Drawing.Point(280, 32)
        Me._Edit_ShowTriggerCount_3.MaxLength = 0
        Me._Edit_ShowTriggerCount_3.Name = "_Edit_ShowTriggerCount_3"
        Me._Edit_ShowTriggerCount_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerCount_3.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerCount_3.TabIndex = 100
        Me._Edit_ShowTriggerCount_3.Text = "Text1"
        Me._Edit_ShowTriggerCount_3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerCount_2
        '
        Me._Edit_ShowTriggerCount_2.AcceptsReturn = True
        Me._Edit_ShowTriggerCount_2.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerCount_2.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerCount_2.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerCount_2.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerCount.SetIndex(Me._Edit_ShowTriggerCount_2, CType(2, Short))
        Me._Edit_ShowTriggerCount_2.Location = New System.Drawing.Point(200, 32)
        Me._Edit_ShowTriggerCount_2.MaxLength = 0
        Me._Edit_ShowTriggerCount_2.Name = "_Edit_ShowTriggerCount_2"
        Me._Edit_ShowTriggerCount_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerCount_2.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerCount_2.TabIndex = 98
        Me._Edit_ShowTriggerCount_2.Text = "Text1"
        Me._Edit_ShowTriggerCount_2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerCount_1
        '
        Me._Edit_ShowTriggerCount_1.AcceptsReturn = True
        Me._Edit_ShowTriggerCount_1.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerCount_1.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerCount_1.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerCount_1.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerCount.SetIndex(Me._Edit_ShowTriggerCount_1, CType(1, Short))
        Me._Edit_ShowTriggerCount_1.Location = New System.Drawing.Point(112, 32)
        Me._Edit_ShowTriggerCount_1.MaxLength = 0
        Me._Edit_ShowTriggerCount_1.Name = "_Edit_ShowTriggerCount_1"
        Me._Edit_ShowTriggerCount_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerCount_1.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerCount_1.TabIndex = 96
        Me._Edit_ShowTriggerCount_1.Text = "Text1"
        Me._Edit_ShowTriggerCount_1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Edit_ShowTriggerCount_0
        '
        Me._Edit_ShowTriggerCount_0.AcceptsReturn = True
        Me._Edit_ShowTriggerCount_0.BackColor = System.Drawing.SystemColors.WindowFrame
        Me._Edit_ShowTriggerCount_0.Cursor = System.Windows.Forms.Cursors.IBeam
        Me._Edit_ShowTriggerCount_0.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me._Edit_ShowTriggerCount_0.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowTriggerCount.SetIndex(Me._Edit_ShowTriggerCount_0, CType(0, Short))
        Me._Edit_ShowTriggerCount_0.Location = New System.Drawing.Point(24, 32)
        Me._Edit_ShowTriggerCount_0.MaxLength = 0
        Me._Edit_ShowTriggerCount_0.Name = "_Edit_ShowTriggerCount_0"
        Me._Edit_ShowTriggerCount_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Edit_ShowTriggerCount_0.Size = New System.Drawing.Size(73, 20)
        Me._Edit_ShowTriggerCount_0.TabIndex = 94
        Me._Edit_ShowTriggerCount_0.Text = "Text1"
        Me._Edit_ShowTriggerCount_0.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        '_Label15_11
        '
        Me._Label15_11.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_11.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_11, CType(11, Short))
        Me._Label15_11.Location = New System.Drawing.Point(280, 96)
        Me._Label15_11.Name = "_Label15_11"
        Me._Label15_11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_11.Size = New System.Drawing.Size(73, 17)
        Me._Label15_11.TabIndex = 115
        Me._Label15_11.Text = "CMPVal 3"
        '
        '_Label15_10
        '
        Me._Label15_10.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_10.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_10, CType(10, Short))
        Me._Label15_10.Location = New System.Drawing.Point(200, 96)
        Me._Label15_10.Name = "_Label15_10"
        Me._Label15_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_10.Size = New System.Drawing.Size(73, 17)
        Me._Label15_10.TabIndex = 113
        Me._Label15_10.Text = "CMPVal 2"
        '
        '_Label15_9
        '
        Me._Label15_9.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_9.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_9.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_9, CType(9, Short))
        Me._Label15_9.Location = New System.Drawing.Point(112, 96)
        Me._Label15_9.Name = "_Label15_9"
        Me._Label15_9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_9.Size = New System.Drawing.Size(73, 17)
        Me._Label15_9.TabIndex = 111
        Me._Label15_9.Text = "CMPVal 1"
        '
        '_Label15_8
        '
        Me._Label15_8.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_8.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_8.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_8, CType(8, Short))
        Me._Label15_8.Location = New System.Drawing.Point(24, 96)
        Me._Label15_8.Name = "_Label15_8"
        Me._Label15_8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_8.Size = New System.Drawing.Size(73, 17)
        Me._Label15_8.TabIndex = 109
        Me._Label15_8.Text = "CMPVal 0"
        '
        '_Label15_7
        '
        Me._Label15_7.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_7.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_7, CType(7, Short))
        Me._Label15_7.Location = New System.Drawing.Point(280, 56)
        Me._Label15_7.Name = "_Label15_7"
        Me._Label15_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_7.Size = New System.Drawing.Size(73, 17)
        Me._Label15_7.TabIndex = 107
        Me._Label15_7.Text = "TriggerEnc 3"
        '
        '_Label15_6
        '
        Me._Label15_6.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_6.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_6, CType(6, Short))
        Me._Label15_6.Location = New System.Drawing.Point(200, 56)
        Me._Label15_6.Name = "_Label15_6"
        Me._Label15_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_6.Size = New System.Drawing.Size(73, 17)
        Me._Label15_6.TabIndex = 105
        Me._Label15_6.Text = "TriggerEnc 2"
        '
        '_Label15_5
        '
        Me._Label15_5.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_5.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_5, CType(5, Short))
        Me._Label15_5.Location = New System.Drawing.Point(112, 56)
        Me._Label15_5.Name = "_Label15_5"
        Me._Label15_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_5.Size = New System.Drawing.Size(73, 17)
        Me._Label15_5.TabIndex = 103
        Me._Label15_5.Text = "TriggerEnc 1"
        '
        '_Label15_4
        '
        Me._Label15_4.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_4.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_4, CType(4, Short))
        Me._Label15_4.Location = New System.Drawing.Point(24, 56)
        Me._Label15_4.Name = "_Label15_4"
        Me._Label15_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_4.Size = New System.Drawing.Size(73, 17)
        Me._Label15_4.TabIndex = 101
        Me._Label15_4.Text = "TriggerEnc 0"
        '
        '_Label15_3
        '
        Me._Label15_3.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_3.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_3, CType(3, Short))
        Me._Label15_3.Location = New System.Drawing.Point(280, 16)
        Me._Label15_3.Name = "_Label15_3"
        Me._Label15_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_3.Size = New System.Drawing.Size(73, 17)
        Me._Label15_3.TabIndex = 99
        Me._Label15_3.Text = "TriggerCnt 3"
        '
        '_Label15_2
        '
        Me._Label15_2.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_2.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_2, CType(2, Short))
        Me._Label15_2.Location = New System.Drawing.Point(200, 16)
        Me._Label15_2.Name = "_Label15_2"
        Me._Label15_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_2.Size = New System.Drawing.Size(73, 17)
        Me._Label15_2.TabIndex = 97
        Me._Label15_2.Text = "TriggerCnt 2"
        '
        '_Label15_1
        '
        Me._Label15_1.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_1.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_1, CType(1, Short))
        Me._Label15_1.Location = New System.Drawing.Point(112, 16)
        Me._Label15_1.Name = "_Label15_1"
        Me._Label15_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_1.Size = New System.Drawing.Size(73, 17)
        Me._Label15_1.TabIndex = 95
        Me._Label15_1.Text = "TriggerCnt 1"
        '
        '_Label15_0
        '
        Me._Label15_0.BackColor = System.Drawing.SystemColors.Control
        Me._Label15_0.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label15_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label15.SetIndex(Me._Label15_0, CType(0, Short))
        Me._Label15_0.Location = New System.Drawing.Point(24, 16)
        Me._Label15_0.Name = "_Label15_0"
        Me._Label15_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label15_0.Size = New System.Drawing.Size(73, 17)
        Me._Label15_0.TabIndex = 93
        Me._Label15_0.Text = "TriggerCnt 0"
        '
        'Frame15
        '
        Me.Frame15.BackColor = System.Drawing.SystemColors.Control
        Me.Frame15.Controls.Add(Me.Frame18)
        Me.Frame15.Controls.Add(Me.Btn_PointTable_Stop)
        Me.Frame15.Controls.Add(Me.Frame16)
        Me.Frame15.Controls.Add(Me.Edit_Show_PointTable_CurrIndex)
        Me.Frame15.Controls.Add(Me.Label13)
        Me.Frame15.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame15.Location = New System.Drawing.Point(392, 520)
        Me.Frame15.Name = "Frame15"
        Me.Frame15.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame15.Size = New System.Drawing.Size(377, 177)
        Me.Frame15.TabIndex = 54
        Me.Frame15.TabStop = False
        Me.Frame15.Text = "Point Table"
        '
        'Frame18
        '
        Me.Frame18.BackColor = System.Drawing.SystemColors.Control
        Me.Frame18.Controls.Add(Me.Btn_PointTable_MoveALL)
        Me.Frame18.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame18.Location = New System.Drawing.Point(192, 48)
        Me.Frame18.Name = "Frame18"
        Me.Frame18.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame18.Size = New System.Drawing.Size(169, 113)
        Me.Frame18.TabIndex = 87
        Me.Frame18.TabStop = False
        Me.Frame18.Text = "All Index Move"
        '
        'Btn_PointTable_MoveALL
        '
        Me.Btn_PointTable_MoveALL.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_PointTable_MoveALL.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_PointTable_MoveALL.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_PointTable_MoveALL.Location = New System.Drawing.Point(24, 16)
        Me.Btn_PointTable_MoveALL.Name = "Btn_PointTable_MoveALL"
        Me.Btn_PointTable_MoveALL.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_PointTable_MoveALL.Size = New System.Drawing.Size(129, 81)
        Me.Btn_PointTable_MoveALL.TabIndex = 92
        Me.Btn_PointTable_MoveALL.Text = "Set Points and Move"
        Me.Btn_PointTable_MoveALL.UseVisualStyleBackColor = False
        '
        'Btn_PointTable_Stop
        '
        Me.Btn_PointTable_Stop.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_PointTable_Stop.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_PointTable_Stop.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_PointTable_Stop.Location = New System.Drawing.Point(208, 24)
        Me.Btn_PointTable_Stop.Name = "Btn_PointTable_Stop"
        Me.Btn_PointTable_Stop.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_PointTable_Stop.Size = New System.Drawing.Size(145, 25)
        Me.Btn_PointTable_Stop.TabIndex = 86
        Me.Btn_PointTable_Stop.Text = "Stop"
        Me.Btn_PointTable_Stop.UseVisualStyleBackColor = False
        '
        'Frame16
        '
        Me.Frame16.BackColor = System.Drawing.SystemColors.Control
        Me.Frame16.Controls.Add(Me.Btn_PointTable_SingleIndexMove)
        Me.Frame16.Controls.Add(Me.Btn_SetPointTable)
        Me.Frame16.Controls.Add(Me.Edit_SetTargetIndex_ForSinglePointMove)
        Me.Frame16.Controls.Add(Me.Label14)
        Me.Frame16.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame16.Location = New System.Drawing.Point(16, 48)
        Me.Frame16.Name = "Frame16"
        Me.Frame16.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame16.Size = New System.Drawing.Size(169, 113)
        Me.Frame16.TabIndex = 85
        Me.Frame16.TabStop = False
        Me.Frame16.Text = "Single Index Move"
        '
        'Btn_PointTable_SingleIndexMove
        '
        Me.Btn_PointTable_SingleIndexMove.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_PointTable_SingleIndexMove.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_PointTable_SingleIndexMove.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_PointTable_SingleIndexMove.Location = New System.Drawing.Point(88, 56)
        Me.Btn_PointTable_SingleIndexMove.Name = "Btn_PointTable_SingleIndexMove"
        Me.Btn_PointTable_SingleIndexMove.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_PointTable_SingleIndexMove.Size = New System.Drawing.Size(73, 49)
        Me.Btn_PointTable_SingleIndexMove.TabIndex = 91
        Me.Btn_PointTable_SingleIndexMove.Text = "Step2:Move"
        Me.Btn_PointTable_SingleIndexMove.UseVisualStyleBackColor = False
        '
        'Btn_SetPointTable
        '
        Me.Btn_SetPointTable.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_SetPointTable.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_SetPointTable.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_SetPointTable.Location = New System.Drawing.Point(8, 16)
        Me.Btn_SetPointTable.Name = "Btn_SetPointTable"
        Me.Btn_SetPointTable.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_SetPointTable.Size = New System.Drawing.Size(73, 89)
        Me.Btn_SetPointTable.TabIndex = 90
        Me.Btn_SetPointTable.Text = "Step1: Set Tables"
        Me.Btn_SetPointTable.UseVisualStyleBackColor = False
        '
        'Edit_SetTargetIndex_ForSinglePointMove
        '
        Me.Edit_SetTargetIndex_ForSinglePointMove.AcceptsReturn = True
        Me.Edit_SetTargetIndex_ForSinglePointMove.BackColor = System.Drawing.SystemColors.Window
        Me.Edit_SetTargetIndex_ForSinglePointMove.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_SetTargetIndex_ForSinglePointMove.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Edit_SetTargetIndex_ForSinglePointMove.Location = New System.Drawing.Point(88, 32)
        Me.Edit_SetTargetIndex_ForSinglePointMove.MaxLength = 0
        Me.Edit_SetTargetIndex_ForSinglePointMove.Name = "Edit_SetTargetIndex_ForSinglePointMove"
        Me.Edit_SetTargetIndex_ForSinglePointMove.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_SetTargetIndex_ForSinglePointMove.Size = New System.Drawing.Size(73, 22)
        Me.Edit_SetTargetIndex_ForSinglePointMove.TabIndex = 89
        Me.Edit_SetTargetIndex_ForSinglePointMove.Text = "10"
        '
        'Label14
        '
        Me.Label14.BackColor = System.Drawing.SystemColors.Control
        Me.Label14.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label14.Location = New System.Drawing.Point(88, 16)
        Me.Label14.Name = "Label14"
        Me.Label14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label14.Size = New System.Drawing.Size(73, 17)
        Me.Label14.TabIndex = 88
        Me.Label14.Text = "Target Index"
        '
        'Edit_Show_PointTable_CurrIndex
        '
        Me.Edit_Show_PointTable_CurrIndex.AcceptsReturn = True
        Me.Edit_Show_PointTable_CurrIndex.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_Show_PointTable_CurrIndex.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_Show_PointTable_CurrIndex.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_Show_PointTable_CurrIndex.ForeColor = System.Drawing.Color.Lime
        Me.Edit_Show_PointTable_CurrIndex.Location = New System.Drawing.Point(96, 24)
        Me.Edit_Show_PointTable_CurrIndex.MaxLength = 0
        Me.Edit_Show_PointTable_CurrIndex.Name = "Edit_Show_PointTable_CurrIndex"
        Me.Edit_Show_PointTable_CurrIndex.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_Show_PointTable_CurrIndex.Size = New System.Drawing.Size(73, 20)
        Me.Edit_Show_PointTable_CurrIndex.TabIndex = 84
        Me.Edit_Show_PointTable_CurrIndex.Text = "Text1"
        Me.Edit_Show_PointTable_CurrIndex.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label13
        '
        Me.Label13.BackColor = System.Drawing.SystemColors.Control
        Me.Label13.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label13.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label13.Location = New System.Drawing.Point(16, 24)
        Me.Label13.Name = "Label13"
        Me.Label13.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label13.Size = New System.Drawing.Size(89, 17)
        Me.Label13.TabIndex = 83
        Me.Label13.Text = "Running Index"
        '
        'Frame14
        '
        Me.Frame14.BackColor = System.Drawing.SystemColors.Control
        Me.Frame14.Controls.Add(Me.Btn_Linear_4Axes_Relateive_Stop)
        Me.Frame14.Controls.Add(Me.Btn_Linear_4Axes_RelateiveForward)
        Me.Frame14.Controls.Add(Me.Btn_Linear_4Axes_RelateiveBackward)
        Me.Frame14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame14.Location = New System.Drawing.Point(8, 520)
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
        Me.Frame13.Location = New System.Drawing.Point(967, 359)
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
        Me.Frame12.Location = New System.Drawing.Point(775, 359)
        Me.Frame12.Name = "Frame12"
        Me.Frame12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame12.Size = New System.Drawing.Size(185, 161)
        Me.Frame12.TabIndex = 51
        Me.Frame12.TabStop = False
        Me.Frame12.Text = "2 Axes Linear Relative Movee"
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
        Me.Frame11.Location = New System.Drawing.Point(583, 359)
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
        Me.Frame10.Location = New System.Drawing.Point(8, 359)
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
        Me.Frame9.Location = New System.Drawing.Point(967, 192)
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
        Me.Frame8.Location = New System.Drawing.Point(776, 192)
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
        Me.Frame7.Location = New System.Drawing.Point(584, 192)
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
        Me.Frame6.Location = New System.Drawing.Point(392, 192)
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
        'Frame5
        '
        Me.Frame5.BackColor = System.Drawing.SystemColors.Control
        Me.Frame5.Controls.Add(Me.Btn_GetModuleInfo)
        Me.Frame5.Controls.Add(Me.Edit_SetModuleID_ForModuleInfo)
        Me.Frame5.Controls.Add(Me.Label12)
        Me.Frame5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame5.Location = New System.Drawing.Point(200, 192)
        Me.Frame5.Name = "Frame5"
        Me.Frame5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame5.Size = New System.Drawing.Size(185, 161)
        Me.Frame5.TabIndex = 39
        Me.Frame5.TabStop = False
        Me.Frame5.Text = "Module Info"
        '
        'Btn_GetModuleInfo
        '
        Me.Btn_GetModuleInfo.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_GetModuleInfo.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_GetModuleInfo.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_GetModuleInfo.Location = New System.Drawing.Point(32, 80)
        Me.Btn_GetModuleInfo.Name = "Btn_GetModuleInfo"
        Me.Btn_GetModuleInfo.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_GetModuleInfo.Size = New System.Drawing.Size(105, 57)
        Me.Btn_GetModuleInfo.TabIndex = 47
        Me.Btn_GetModuleInfo.Text = "Get Module Info"
        Me.Btn_GetModuleInfo.UseVisualStyleBackColor = False
        '
        'Edit_SetModuleID_ForModuleInfo
        '
        Me.Edit_SetModuleID_ForModuleInfo.AcceptsReturn = True
        Me.Edit_SetModuleID_ForModuleInfo.BackColor = System.Drawing.SystemColors.Window
        Me.Edit_SetModuleID_ForModuleInfo.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_SetModuleID_ForModuleInfo.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Edit_SetModuleID_ForModuleInfo.Location = New System.Drawing.Point(32, 48)
        Me.Edit_SetModuleID_ForModuleInfo.MaxLength = 0
        Me.Edit_SetModuleID_ForModuleInfo.Name = "Edit_SetModuleID_ForModuleInfo"
        Me.Edit_SetModuleID_ForModuleInfo.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_SetModuleID_ForModuleInfo.Size = New System.Drawing.Size(105, 22)
        Me.Edit_SetModuleID_ForModuleInfo.TabIndex = 46
        Me.Edit_SetModuleID_ForModuleInfo.Text = "0"
        '
        'Label12
        '
        Me.Label12.BackColor = System.Drawing.SystemColors.Control
        Me.Label12.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label12.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label12.Location = New System.Drawing.Point(32, 32)
        Me.Label12.Name = "Label12"
        Me.Label12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label12.Size = New System.Drawing.Size(89, 17)
        Me.Label12.TabIndex = 45
        Me.Label12.Text = "Module ID"
        '
        'Frame4
        '
        Me.Frame4.BackColor = System.Drawing.SystemColors.Control
        Me.Frame4.Controls.Add(Me.Btn_BusDisconnect)
        Me.Frame4.Controls.Add(Me.Btn_BusConnect)
        Me.Frame4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame4.Location = New System.Drawing.Point(8, 192)
        Me.Frame4.Name = "Frame4"
        Me.Frame4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame4.Size = New System.Drawing.Size(185, 161)
        Me.Frame4.TabIndex = 38
        Me.Frame4.TabStop = False
        Me.Frame4.Text = "Step1: Bus Start/Stop"
        '
        'Btn_BusDisconnect
        '
        Me.Btn_BusDisconnect.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_BusDisconnect.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_BusDisconnect.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_BusDisconnect.Location = New System.Drawing.Point(32, 88)
        Me.Btn_BusDisconnect.Name = "Btn_BusDisconnect"
        Me.Btn_BusDisconnect.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_BusDisconnect.Size = New System.Drawing.Size(121, 57)
        Me.Btn_BusDisconnect.TabIndex = 44
        Me.Btn_BusDisconnect.Text = "Disconnect"
        Me.Btn_BusDisconnect.UseVisualStyleBackColor = False
        '
        'Btn_BusConnect
        '
        Me.Btn_BusConnect.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_BusConnect.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_BusConnect.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_BusConnect.Location = New System.Drawing.Point(32, 24)
        Me.Btn_BusConnect.Name = "Btn_BusConnect"
        Me.Btn_BusConnect.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_BusConnect.Size = New System.Drawing.Size(121, 57)
        Me.Btn_BusConnect.TabIndex = 43
        Me.Btn_BusConnect.Text = "Connect"
        Me.Btn_BusConnect.UseVisualStyleBackColor = False
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
        Me.Frame3.Controls.Add(Me.label25)
        Me.Frame3.Controls.Add(Me.label24)
        Me.Frame3.Controls.Add(Me.label23)
        Me.Frame3.Controls.Add(Me.label22)
        Me.Frame3.Controls.Add(Me.label21)
        Me.Frame3.Controls.Add(Me.label20)
        Me.Frame3.Controls.Add(Me.label19)
        Me.Frame3.Controls.Add(Me.label18)
        Me.Frame3.Controls.Add(Me.label17)
        Me.Frame3.Controls.Add(Me.label16)
        Me.Frame3.Controls.Add(Me.Label9)
        Me.Frame3.Controls.Add(Me.Label10)
        Me.Frame3.Controls.Add(Me.Label999)
        Me.Frame3.Controls.Add(Me.Label11)
        Me.Frame3.Controls.Add(Me.Label26)
        Me.Frame3.Controls.Add(Me.Label27)
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
        Me.Frame3.Location = New System.Drawing.Point(428, 9)
        Me.Frame3.Name = "Frame3"
        Me.Frame3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame3.Size = New System.Drawing.Size(641, 177)
        Me.Frame3.TabIndex = 2
        Me.Frame3.TabStop = False
        Me.Frame3.Text = "Axis Info"
        '
        'label25
        '
        Me.label25.BackColor = System.Drawing.SystemColors.Control
        Me.label25.Cursor = System.Windows.Forms.Cursors.Default
        Me.label25.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label25.Location = New System.Drawing.Point(343, 136)
        Me.label25.Name = "label25"
        Me.label25.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label25.Size = New System.Drawing.Size(89, 17)
        Me.label25.TabIndex = 65
        Me.label25.Text = "Motion Ststus 3"
        '
        'label24
        '
        Me.label24.BackColor = System.Drawing.SystemColors.Control
        Me.label24.Cursor = System.Windows.Forms.Cursors.Default
        Me.label24.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label24.Location = New System.Drawing.Point(231, 136)
        Me.label24.Name = "label24"
        Me.label24.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label24.Size = New System.Drawing.Size(89, 17)
        Me.label24.TabIndex = 64
        Me.label24.Text = "Motion Ststus 2"
        '
        'label23
        '
        Me.label23.BackColor = System.Drawing.SystemColors.Control
        Me.label23.Cursor = System.Windows.Forms.Cursors.Default
        Me.label23.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label23.Location = New System.Drawing.Point(119, 136)
        Me.label23.Name = "label23"
        Me.label23.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label23.Size = New System.Drawing.Size(89, 17)
        Me.label23.TabIndex = 63
        Me.label23.Text = "Motion Ststus 1"
        '
        'label22
        '
        Me.label22.BackColor = System.Drawing.SystemColors.Control
        Me.label22.Cursor = System.Windows.Forms.Cursors.Default
        Me.label22.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label22.Location = New System.Drawing.Point(343, 96)
        Me.label22.Name = "label22"
        Me.label22.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label22.Size = New System.Drawing.Size(89, 17)
        Me.label22.TabIndex = 62
        Me.label22.Text = "IO Status 3"
        '
        'label21
        '
        Me.label21.BackColor = System.Drawing.SystemColors.Control
        Me.label21.Cursor = System.Windows.Forms.Cursors.Default
        Me.label21.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label21.Location = New System.Drawing.Point(231, 96)
        Me.label21.Name = "label21"
        Me.label21.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label21.Size = New System.Drawing.Size(89, 17)
        Me.label21.TabIndex = 61
        Me.label21.Text = "IO Status 2"
        '
        'label20
        '
        Me.label20.BackColor = System.Drawing.SystemColors.Control
        Me.label20.Cursor = System.Windows.Forms.Cursors.Default
        Me.label20.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label20.Location = New System.Drawing.Point(119, 96)
        Me.label20.Name = "label20"
        Me.label20.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label20.Size = New System.Drawing.Size(89, 17)
        Me.label20.TabIndex = 60
        Me.label20.Text = "IO Status 1"
        '
        'label19
        '
        Me.label19.BackColor = System.Drawing.SystemColors.Control
        Me.label19.Cursor = System.Windows.Forms.Cursors.Default
        Me.label19.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label19.Location = New System.Drawing.Point(343, 56)
        Me.label19.Name = "label19"
        Me.label19.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label19.Size = New System.Drawing.Size(89, 17)
        Me.label19.TabIndex = 59
        Me.label19.Text = "Feedback 3"
        '
        'label18
        '
        Me.label18.BackColor = System.Drawing.SystemColors.Control
        Me.label18.Cursor = System.Windows.Forms.Cursors.Default
        Me.label18.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label18.Location = New System.Drawing.Point(231, 56)
        Me.label18.Name = "label18"
        Me.label18.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label18.Size = New System.Drawing.Size(89, 17)
        Me.label18.TabIndex = 58
        Me.label18.Text = "Feedback 2"
        '
        'label17
        '
        Me.label17.BackColor = System.Drawing.SystemColors.Control
        Me.label17.Cursor = System.Windows.Forms.Cursors.Default
        Me.label17.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label17.Location = New System.Drawing.Point(119, 56)
        Me.label17.Name = "label17"
        Me.label17.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label17.Size = New System.Drawing.Size(89, 17)
        Me.label17.TabIndex = 57
        Me.label17.Text = "Feedback 1"
        '
        'label16
        '
        Me.label16.BackColor = System.Drawing.SystemColors.Control
        Me.label16.Cursor = System.Windows.Forms.Cursors.Default
        Me.label16.ForeColor = System.Drawing.SystemColors.ControlText
        Me.label16.Location = New System.Drawing.Point(343, 14)
        Me.label16.Name = "label16"
        Me.label16.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.label16.Size = New System.Drawing.Size(89, 17)
        Me.label16.TabIndex = 56
        Me.label16.Text = "Command 3"
        '
        'Label9
        '
        Me.Label9.BackColor = System.Drawing.SystemColors.Control
        Me.Label9.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label9.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label9.Location = New System.Drawing.Point(231, 14)
        Me.Label9.Name = "Label9"
        Me.Label9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label9.Size = New System.Drawing.Size(89, 17)
        Me.Label9.TabIndex = 55
        Me.Label9.Text = "Command 2"
        '
        'Label10
        '
        Me.Label10.BackColor = System.Drawing.SystemColors.Control
        Me.Label10.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label10.Location = New System.Drawing.Point(119, 14)
        Me.Label10.Name = "Label10"
        Me.Label10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label10.Size = New System.Drawing.Size(89, 17)
        Me.Label10.TabIndex = 54
        Me.Label10.Text = "Command 1"
        '
        'Label999
        '
        Me.Label999.BackColor = System.Drawing.SystemColors.Control
        Me.Label999.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label999.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label999.Location = New System.Drawing.Point(9, 136)
        Me.Label999.Name = "Label999"
        Me.Label999.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label999.Size = New System.Drawing.Size(89, 17)
        Me.Label999.TabIndex = 53
        Me.Label999.Text = "Motion Ststus 0"
        '
        'Label11
        '
        Me.Label11.BackColor = System.Drawing.SystemColors.Control
        Me.Label11.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label11.Location = New System.Drawing.Point(9, 96)
        Me.Label11.Name = "Label11"
        Me.Label11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label11.Size = New System.Drawing.Size(89, 17)
        Me.Label11.TabIndex = 52
        Me.Label11.Text = "IO Status 0"
        '
        'Label26
        '
        Me.Label26.BackColor = System.Drawing.SystemColors.Control
        Me.Label26.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label26.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label26.Location = New System.Drawing.Point(9, 56)
        Me.Label26.Name = "Label26"
        Me.Label26.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label26.Size = New System.Drawing.Size(89, 17)
        Me.Label26.TabIndex = 51
        Me.Label26.Text = "Feedback 0"
        '
        'Label27
        '
        Me.Label27.BackColor = System.Drawing.SystemColors.Control
        Me.Label27.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label27.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label27.Location = New System.Drawing.Point(9, 14)
        Me.Label27.Name = "Label27"
        Me.Label27.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label27.Size = New System.Drawing.Size(89, 17)
        Me.Label27.TabIndex = 50
        Me.Label27.Text = "Command 0" & Global.Microsoft.VisualBasic.ChrW(13) & Global.Microsoft.VisualBasic.ChrW(10)
        '
        'Btn_ResetCounter
        '
        Me.Btn_ResetCounter.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_ResetCounter.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_ResetCounter.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_ResetCounter.Location = New System.Drawing.Point(456, 32)
        Me.Btn_ResetCounter.Name = "Btn_ResetCounter"
        Me.Btn_ResetCounter.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_ResetCounter.Size = New System.Drawing.Size(177, 137)
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
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 50
        '
        'Frame2
        '
        Me.Frame2.BackColor = System.Drawing.SystemColors.Control
        Me.Frame2.Controls.Add(Me.Edit_ShowMaster_PCBBottomVer)
        Me.Frame2.Controls.Add(Me.Label6)
        Me.Frame2.Controls.Add(Me.Edit_ShowModule_PCBTopVer)
        Me.Frame2.Controls.Add(Me.Edit_ShowModule_FPGAVer)
        Me.Frame2.Controls.Add(Me.Label8)
        Me.Frame2.Controls.Add(Me.Label7)
        Me.Frame2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Frame2.Location = New System.Drawing.Point(268, 9)
        Me.Frame2.Name = "Frame2"
        Me.Frame2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Frame2.Size = New System.Drawing.Size(153, 177)
        Me.Frame2.TabIndex = 1
        Me.Frame2.TabStop = False
        Me.Frame2.Text = "Module Info"
        '
        'Edit_ShowMaster_PCBBottomVer
        '
        Me.Edit_ShowMaster_PCBBottomVer.AcceptsReturn = True
        Me.Edit_ShowMaster_PCBBottomVer.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_ShowMaster_PCBBottomVer.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_ShowMaster_PCBBottomVer.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_ShowMaster_PCBBottomVer.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowMaster_PCBBottomVer.Location = New System.Drawing.Point(30, 132)
        Me.Edit_ShowMaster_PCBBottomVer.MaxLength = 0
        Me.Edit_ShowMaster_PCBBottomVer.Name = "Edit_ShowMaster_PCBBottomVer"
        Me.Edit_ShowMaster_PCBBottomVer.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_ShowMaster_PCBBottomVer.Size = New System.Drawing.Size(105, 20)
        Me.Edit_ShowMaster_PCBBottomVer.TabIndex = 17
        Me.Edit_ShowMaster_PCBBottomVer.Text = "Text1"
        Me.Edit_ShowMaster_PCBBottomVer.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label6
        '
        Me.Label6.BackColor = System.Drawing.SystemColors.Control
        Me.Label6.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label6.Location = New System.Drawing.Point(28, 118)
        Me.Label6.Name = "Label6"
        Me.Label6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label6.Size = New System.Drawing.Size(89, 17)
        Me.Label6.TabIndex = 18
        Me.Label6.Text = "PCB Bottom Ver."
        '
        'Edit_ShowModule_PCBTopVer
        '
        Me.Edit_ShowModule_PCBTopVer.AcceptsReturn = True
        Me.Edit_ShowModule_PCBTopVer.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_ShowModule_PCBTopVer.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_ShowModule_PCBTopVer.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_ShowModule_PCBTopVer.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowModule_PCBTopVer.Location = New System.Drawing.Point(30, 90)
        Me.Edit_ShowModule_PCBTopVer.MaxLength = 0
        Me.Edit_ShowModule_PCBTopVer.Name = "Edit_ShowModule_PCBTopVer"
        Me.Edit_ShowModule_PCBTopVer.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_ShowModule_PCBTopVer.Size = New System.Drawing.Size(105, 20)
        Me.Edit_ShowModule_PCBTopVer.TabIndex = 16
        Me.Edit_ShowModule_PCBTopVer.Text = "No Data"
        Me.Edit_ShowModule_PCBTopVer.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Edit_ShowModule_FPGAVer
        '
        Me.Edit_ShowModule_FPGAVer.AcceptsReturn = True
        Me.Edit_ShowModule_FPGAVer.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_ShowModule_FPGAVer.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_ShowModule_FPGAVer.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_ShowModule_FPGAVer.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowModule_FPGAVer.Location = New System.Drawing.Point(30, 50)
        Me.Edit_ShowModule_FPGAVer.MaxLength = 0
        Me.Edit_ShowModule_FPGAVer.Name = "Edit_ShowModule_FPGAVer"
        Me.Edit_ShowModule_FPGAVer.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_ShowModule_FPGAVer.Size = New System.Drawing.Size(105, 20)
        Me.Edit_ShowModule_FPGAVer.TabIndex = 14
        Me.Edit_ShowModule_FPGAVer.Text = "No Data"
        Me.Edit_ShowModule_FPGAVer.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label8
        '
        Me.Label8.BackColor = System.Drawing.SystemColors.Control
        Me.Label8.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label8.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label8.Location = New System.Drawing.Point(30, 74)
        Me.Label8.Name = "Label8"
        Me.Label8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label8.Size = New System.Drawing.Size(89, 17)
        Me.Label8.TabIndex = 15
        Me.Label8.Text = "PCB TOP Ver."
        '
        'Label7
        '
        Me.Label7.BackColor = System.Drawing.SystemColors.Control
        Me.Label7.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label7.Location = New System.Drawing.Point(30, 34)
        Me.Label7.Name = "Label7"
        Me.Label7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label7.Size = New System.Drawing.Size(89, 17)
        Me.Label7.TabIndex = 13
        Me.Label7.Text = "FPGA  Version"
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
        Me.Frame1.Location = New System.Drawing.Point(116, 9)
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
        Me.Label5.Text = "CPLD Version"
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
        Me.GroupBox1.Location = New System.Drawing.Point(199, 359)
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
        Me.GroupBox2.Location = New System.Drawing.Point(390, 359)
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
        'GroupBox3
        '
        Me.GroupBox3.BackColor = System.Drawing.SystemColors.Control
        Me.GroupBox3.Controls.Add(Me.Btn_Set_DOData)
        Me.GroupBox3.Controls.Add(Me.Edit_SetDOData)
        Me.GroupBox3.Controls.Add(Me.Label31)
        Me.GroupBox3.Controls.Add(Me.Edit_GetDOData)
        Me.GroupBox3.Controls.Add(Me.Edit_ShowDIData)
        Me.GroupBox3.Controls.Add(Me.Label29)
        Me.GroupBox3.Controls.Add(Me.Label30)
        Me.GroupBox3.Controls.Add(Me.Edit_SetModuleID_ForGeneralDIO)
        Me.GroupBox3.Controls.Add(Me.Label28)
        Me.GroupBox3.ForeColor = System.Drawing.SystemColors.ControlText
        Me.GroupBox3.Location = New System.Drawing.Point(201, 521)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.GroupBox3.Size = New System.Drawing.Size(185, 176)
        Me.GroupBox3.TabIndex = 58
        Me.GroupBox3.TabStop = False
        Me.GroupBox3.Text = "General DIO"
        '
        'Btn_Set_DOData
        '
        Me.Btn_Set_DOData.BackColor = System.Drawing.SystemColors.Control
        Me.Btn_Set_DOData.Cursor = System.Windows.Forms.Cursors.Default
        Me.Btn_Set_DOData.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Btn_Set_DOData.Location = New System.Drawing.Point(100, 112)
        Me.Btn_Set_DOData.Name = "Btn_Set_DOData"
        Me.Btn_Set_DOData.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Btn_Set_DOData.Size = New System.Drawing.Size(73, 49)
        Me.Btn_Set_DOData.TabIndex = 103
        Me.Btn_Set_DOData.Text = "Set DO"
        Me.Btn_Set_DOData.UseVisualStyleBackColor = False
        '
        'Edit_SetDOData
        '
        Me.Edit_SetDOData.AcceptsReturn = True
        Me.Edit_SetDOData.BackColor = System.Drawing.SystemColors.Window
        Me.Edit_SetDOData.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_SetDOData.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Edit_SetDOData.Location = New System.Drawing.Point(12, 138)
        Me.Edit_SetDOData.MaxLength = 0
        Me.Edit_SetDOData.Name = "Edit_SetDOData"
        Me.Edit_SetDOData.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_SetDOData.Size = New System.Drawing.Size(73, 22)
        Me.Edit_SetDOData.TabIndex = 102
        Me.Edit_SetDOData.Text = "0"
        '
        'Label31
        '
        Me.Label31.BackColor = System.Drawing.SystemColors.Control
        Me.Label31.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label31.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label31.Location = New System.Drawing.Point(12, 122)
        Me.Label31.Name = "Label31"
        Me.Label31.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label31.Size = New System.Drawing.Size(73, 17)
        Me.Label31.TabIndex = 101
        Me.Label31.Text = "DO_Data"
        '
        'Edit_GetDOData
        '
        Me.Edit_GetDOData.AcceptsReturn = True
        Me.Edit_GetDOData.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_GetDOData.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_GetDOData.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_GetDOData.ForeColor = System.Drawing.Color.Lime
        Me.Edit_GetDOData.Location = New System.Drawing.Point(100, 86)
        Me.Edit_GetDOData.MaxLength = 0
        Me.Edit_GetDOData.Name = "Edit_GetDOData"
        Me.Edit_GetDOData.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_GetDOData.Size = New System.Drawing.Size(73, 20)
        Me.Edit_GetDOData.TabIndex = 100
        Me.Edit_GetDOData.Text = "Text1"
        Me.Edit_GetDOData.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Edit_ShowDIData
        '
        Me.Edit_ShowDIData.AcceptsReturn = True
        Me.Edit_ShowDIData.BackColor = System.Drawing.SystemColors.WindowFrame
        Me.Edit_ShowDIData.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_ShowDIData.Font = New System.Drawing.Font("Times New Roman", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Edit_ShowDIData.ForeColor = System.Drawing.Color.Lime
        Me.Edit_ShowDIData.Location = New System.Drawing.Point(12, 86)
        Me.Edit_ShowDIData.MaxLength = 0
        Me.Edit_ShowDIData.Name = "Edit_ShowDIData"
        Me.Edit_ShowDIData.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_ShowDIData.Size = New System.Drawing.Size(73, 20)
        Me.Edit_ShowDIData.TabIndex = 98
        Me.Edit_ShowDIData.Text = "Text1"
        Me.Edit_ShowDIData.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Label29
        '
        Me.Label29.BackColor = System.Drawing.SystemColors.Control
        Me.Label29.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label29.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label29.Location = New System.Drawing.Point(100, 70)
        Me.Label29.Name = "Label29"
        Me.Label29.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label29.Size = New System.Drawing.Size(73, 17)
        Me.Label29.TabIndex = 99
        Me.Label29.Text = "Chk_DOData"
        '
        'Label30
        '
        Me.Label30.BackColor = System.Drawing.SystemColors.Control
        Me.Label30.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label30.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label30.Location = New System.Drawing.Point(12, 70)
        Me.Label30.Name = "Label30"
        Me.Label30.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label30.Size = New System.Drawing.Size(73, 17)
        Me.Label30.TabIndex = 97
        Me.Label30.Text = "DI_Data"
        '
        'Edit_SetModuleID_ForGeneralDIO
        '
        Me.Edit_SetModuleID_ForGeneralDIO.AcceptsReturn = True
        Me.Edit_SetModuleID_ForGeneralDIO.BackColor = System.Drawing.SystemColors.Window
        Me.Edit_SetModuleID_ForGeneralDIO.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.Edit_SetModuleID_ForGeneralDIO.ForeColor = System.Drawing.SystemColors.WindowText
        Me.Edit_SetModuleID_ForGeneralDIO.Location = New System.Drawing.Point(33, 38)
        Me.Edit_SetModuleID_ForGeneralDIO.MaxLength = 0
        Me.Edit_SetModuleID_ForGeneralDIO.Name = "Edit_SetModuleID_ForGeneralDIO"
        Me.Edit_SetModuleID_ForGeneralDIO.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Edit_SetModuleID_ForGeneralDIO.Size = New System.Drawing.Size(105, 22)
        Me.Edit_SetModuleID_ForGeneralDIO.TabIndex = 48
        Me.Edit_SetModuleID_ForGeneralDIO.Text = "0"
        '
        'Label28
        '
        Me.Label28.BackColor = System.Drawing.SystemColors.Control
        Me.Label28.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label28.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label28.Location = New System.Drawing.Point(33, 22)
        Me.Label28.Name = "Label28"
        Me.Label28.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label28.Size = New System.Drawing.Size(89, 17)
        Me.Label28.TabIndex = 47
        Me.Label28.Text = "Module ID"
        '
        'MainForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.AutoSize = True
        Me.BackColor = System.Drawing.SystemColors.Control
        Me.ClientSize = New System.Drawing.Size(1028, 712)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.Frame17)
        Me.Controls.Add(Me.Frame15)
        Me.Controls.Add(Me.Frame14)
        Me.Controls.Add(Me.Frame13)
        Me.Controls.Add(Me.Frame12)
        Me.Controls.Add(Me.Frame11)
        Me.Controls.Add(Me.Frame10)
        Me.Controls.Add(Me.Frame9)
        Me.Controls.Add(Me.Frame8)
        Me.Controls.Add(Me.Frame7)
        Me.Controls.Add(Me.Frame6)
        Me.Controls.Add(Me.Frame5)
        Me.Controls.Add(Me.Frame4)
        Me.Controls.Add(Me.Frame3)
        Me.Controls.Add(Me.Frame2)
        Me.Controls.Add(Me.Frame1)
        Me.Cursor = System.Windows.Forms.Cursors.Default
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Location = New System.Drawing.Point(167, 44)
        Me.Name = "MainForm"
        Me.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
        Me.Text = "MNET-4XMO-C VB.Net 2005 Sample"
        Me.Frame17.ResumeLayout(False)
        Me.Frame17.PerformLayout()
        Me.Frame15.ResumeLayout(False)
        Me.Frame15.PerformLayout()
        Me.Frame18.ResumeLayout(False)
        Me.Frame16.ResumeLayout(False)
        Me.Frame16.PerformLayout()
        Me.Frame14.ResumeLayout(False)
        Me.Frame13.ResumeLayout(False)
        Me.Frame12.ResumeLayout(False)
        Me.Frame11.ResumeLayout(False)
        Me.Frame10.ResumeLayout(False)
        Me.Frame9.ResumeLayout(False)
        Me.Frame8.ResumeLayout(False)
        Me.Frame7.ResumeLayout(False)
        Me.Frame6.ResumeLayout(False)
        Me.Frame5.ResumeLayout(False)
        Me.Frame5.PerformLayout()
        Me.Frame4.ResumeLayout(False)
        Me.Frame3.ResumeLayout(False)
        Me.Frame3.PerformLayout()
        Me.Frame2.ResumeLayout(False)
        Me.Frame2.PerformLayout()
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
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.ResumeLayout(False)

    End Sub
    Public WithEvents label25 As System.Windows.Forms.Label
    Public WithEvents label24 As System.Windows.Forms.Label
    Public WithEvents label23 As System.Windows.Forms.Label
    Public WithEvents label22 As System.Windows.Forms.Label
    Public WithEvents label21 As System.Windows.Forms.Label
    Public WithEvents label20 As System.Windows.Forms.Label
    Public WithEvents label19 As System.Windows.Forms.Label
    Public WithEvents label18 As System.Windows.Forms.Label
    Public WithEvents label17 As System.Windows.Forms.Label
    Public WithEvents label16 As System.Windows.Forms.Label
    Public WithEvents Label9 As System.Windows.Forms.Label
    Public WithEvents Label10 As System.Windows.Forms.Label
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
    Public WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Public WithEvents Btn_Set_DOData As System.Windows.Forms.Button
    Public WithEvents Edit_SetDOData As System.Windows.Forms.TextBox
    Public WithEvents Label31 As System.Windows.Forms.Label
    Public WithEvents Edit_GetDOData As System.Windows.Forms.TextBox
    Public WithEvents Edit_ShowDIData As System.Windows.Forms.TextBox
    Public WithEvents Label29 As System.Windows.Forms.Label
    Public WithEvents Label30 As System.Windows.Forms.Label
    Public WithEvents Edit_SetModuleID_ForGeneralDIO As System.Windows.Forms.TextBox
    Public WithEvents Label28 As System.Windows.Forms.Label
    Public WithEvents Edit_ShowMaster_PCBBottomVer As System.Windows.Forms.TextBox
    Public WithEvents Label6 As System.Windows.Forms.Label
    Public WithEvents Label5 As System.Windows.Forms.Label
#End Region 
End Class