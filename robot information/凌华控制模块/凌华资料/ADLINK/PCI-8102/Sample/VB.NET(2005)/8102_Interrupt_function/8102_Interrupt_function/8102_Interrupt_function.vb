
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
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents card_id As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents TimeOut_ms As System.Windows.Forms.TextBox
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents intFlag As System.Windows.Forms.TextBox
    Friend WithEvents GroupBox5 As System.Windows.Forms.GroupBox
    Friend WithEvents CMD1 As System.Windows.Forms.TextBox
    Friend WithEvents CMD0 As System.Windows.Forms.TextBox
    Friend WithEvents Label10 As System.Windows.Forms.Label
    Friend WithEvents Label11 As System.Windows.Forms.Label
    Friend WithEvents Button7 As System.Windows.Forms.Button
    Friend WithEvents Button8 As System.Windows.Forms.Button
    Friend WithEvents ARC_CMD_1 As System.Windows.Forms.TextBox
    Friend WithEvents ARC_CMD_0 As System.Windows.Forms.TextBox
    Friend WithEvents Button9 As System.Windows.Forms.Button
    Friend WithEvents LINE_CMD_1 As System.Windows.Forms.TextBox
    Friend WithEvents LINE_CMD_0 As System.Windows.Forms.TextBox
    Friend WithEvents Button10 As System.Windows.Forms.Button
    Friend WithEvents CheckBox1 As System.Windows.Forms.CheckBox
    Friend WithEvents PTP_CMD As System.Windows.Forms.TextBox
    Friend WithEvents PTP_AXIS As System.Windows.Forms.TextBox
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents Button11 As System.Windows.Forms.Button
    Friend WithEvents GroupBox4 As System.Windows.Forms.GroupBox
    Friend WithEvents MotSts1 As System.Windows.Forms.TextBox
    Friend WithEvents MotSts0 As System.Windows.Forms.TextBox
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents GroupBox3 As System.Windows.Forms.GroupBox
    Friend WithEvents Speed1 As System.Windows.Forms.TextBox
    Friend WithEvents Speed0 As System.Windows.Forms.TextBox
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents Label13 As System.Windows.Forms.Label
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents IOSts1 As System.Windows.Forms.TextBox
    Friend WithEvents IOSts0 As System.Windows.Forms.TextBox
    Friend WithEvents Label14 As System.Windows.Forms.Label
    Friend WithEvents Label15 As System.Windows.Forms.Label
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Pos1 As System.Windows.Forms.TextBox
    Friend WithEvents Pos0 As System.Windows.Forms.TextBox
    Friend WithEvents Label16 As System.Windows.Forms.Label
    Friend WithEvents Label17 As System.Windows.Forms.Label
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Public WithEvents grp_chk_int_factor As System.Windows.Forms.GroupBox
    Public WithEvents grp_chk_int_factor_0 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_1 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_2 As System.Windows.Forms.CheckBox
    Public WithEvents _Label3_0 As System.Windows.Forms.Label
    Public WithEvents _Label3_1 As System.Windows.Forms.Label
    Public WithEvents _Label3_2 As System.Windows.Forms.Label
    Public WithEvents _Label3_3 As System.Windows.Forms.Label
    Public WithEvents _Label3_4 As System.Windows.Forms.Label
    Public WithEvents _Label3_5 As System.Windows.Forms.Label
    Public WithEvents _Label3_6 As System.Windows.Forms.Label
    Public WithEvents _Label3_7 As System.Windows.Forms.Label
    Public WithEvents _Label3_8 As System.Windows.Forms.Label
    Public WithEvents _Label3_9 As System.Windows.Forms.Label
    Public WithEvents _Label3_10 As System.Windows.Forms.Label
    Public WithEvents _Label3_11 As System.Windows.Forms.Label
    Public WithEvents _Label3_12 As System.Windows.Forms.Label
    Public WithEvents grp_chk_int_factor_4 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_5 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_6 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_7 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_10 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_11 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_12 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_14 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_15 As System.Windows.Forms.CheckBox
    Public WithEvents grp_chk_int_factor_16 As System.Windows.Forms.CheckBox
    Public WithEvents INT_N_S_0 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_1 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_2 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_4 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_5 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_6 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_7 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_10 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_11 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_12 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_14 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_15 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_S_16 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_0 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_1 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_2 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_4 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_5 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_6 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_7 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_S_10 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_16 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_15 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_0 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_1 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_2 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_4 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_5 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_6 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_7 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_10 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_11 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_12 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_B_14 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_0 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_1 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_2 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_4 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_5 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_6 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_7 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_B_10 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_16 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_15 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_0 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_1 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_2 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_4 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_5 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_6 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_7 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_10 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_11 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_12 As System.Windows.Forms.PictureBox
    Public WithEvents INT_N_E_14 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_0 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_1 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_2 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_4 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_5 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_6 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_7 As System.Windows.Forms.PictureBox
    Public WithEvents INT_G_E_10 As System.Windows.Forms.PictureBox
    Friend WithEvents Button12 As System.Windows.Forms.Button
    Friend WithEvents CMP_STS As System.Windows.Forms.TextBox
    Public WithEvents Label2 As System.Windows.Forms.Label
    Public WithEvents Label5 As System.Windows.Forms.Label
    Public WithEvents Label6 As System.Windows.Forms.Label
    Public WithEvents Label18 As System.Windows.Forms.Label
    Public WithEvents Label19 As System.Windows.Forms.Label
    Public WithEvents Label20 As System.Windows.Forms.Label
    Public WithEvents Label21 As System.Windows.Forms.Label
    Public WithEvents Label22 As System.Windows.Forms.Label
    Friend WithEvents Label23 As System.Windows.Forms.Label
    Friend WithEvents Label24 As System.Windows.Forms.Label
    Friend WithEvents Label25 As System.Windows.Forms.Label
    Friend WithEvents Label26 As System.Windows.Forms.Label
    Friend WithEvents Label27 As System.Windows.Forms.Label
    Friend WithEvents Label28 As System.Windows.Forms.Label
    Friend WithEvents Button13 As System.Windows.Forms.Button
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Me.Button1 = New System.Windows.Forms.Button
        Me.card_id = New System.Windows.Forms.TextBox
        Me.Label1 = New System.Windows.Forms.Label
        Me.Button2 = New System.Windows.Forms.Button
        Me.Button3 = New System.Windows.Forms.Button
        Me.Button4 = New System.Windows.Forms.Button
        Me.Button6 = New System.Windows.Forms.Button
        Me.TimeOut_ms = New System.Windows.Forms.TextBox
        Me.Label3 = New System.Windows.Forms.Label
        Me.intFlag = New System.Windows.Forms.TextBox
        Me.Label4 = New System.Windows.Forms.Label
        Me.GroupBox5 = New System.Windows.Forms.GroupBox
        Me.CMD1 = New System.Windows.Forms.TextBox
        Me.CMD0 = New System.Windows.Forms.TextBox
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label11 = New System.Windows.Forms.Label
        Me.Button7 = New System.Windows.Forms.Button
        Me.Button8 = New System.Windows.Forms.Button
        Me.ARC_CMD_1 = New System.Windows.Forms.TextBox
        Me.ARC_CMD_0 = New System.Windows.Forms.TextBox
        Me.Button9 = New System.Windows.Forms.Button
        Me.LINE_CMD_1 = New System.Windows.Forms.TextBox
        Me.LINE_CMD_0 = New System.Windows.Forms.TextBox
        Me.Button10 = New System.Windows.Forms.Button
        Me.CheckBox1 = New System.Windows.Forms.CheckBox
        Me.PTP_CMD = New System.Windows.Forms.TextBox
        Me.PTP_AXIS = New System.Windows.Forms.TextBox
        Me.Label9 = New System.Windows.Forms.Label
        Me.Button11 = New System.Windows.Forms.Button
        Me.GroupBox4 = New System.Windows.Forms.GroupBox
        Me.MotSts1 = New System.Windows.Forms.TextBox
        Me.MotSts0 = New System.Windows.Forms.TextBox
        Me.Label7 = New System.Windows.Forms.Label
        Me.Label8 = New System.Windows.Forms.Label
        Me.GroupBox3 = New System.Windows.Forms.GroupBox
        Me.Speed1 = New System.Windows.Forms.TextBox
        Me.Speed0 = New System.Windows.Forms.TextBox
        Me.Label12 = New System.Windows.Forms.Label
        Me.Label13 = New System.Windows.Forms.Label
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.IOSts1 = New System.Windows.Forms.TextBox
        Me.IOSts0 = New System.Windows.Forms.TextBox
        Me.Label14 = New System.Windows.Forms.Label
        Me.Label15 = New System.Windows.Forms.Label
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.Pos1 = New System.Windows.Forms.TextBox
        Me.Pos0 = New System.Windows.Forms.TextBox
        Me.Label16 = New System.Windows.Forms.Label
        Me.Label17 = New System.Windows.Forms.Label
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.grp_chk_int_factor = New System.Windows.Forms.GroupBox
        Me.grp_chk_int_factor_0 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_1 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_2 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_4 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_5 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_6 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_7 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_10 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_11 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_12 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_14 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_15 = New System.Windows.Forms.CheckBox
        Me.grp_chk_int_factor_16 = New System.Windows.Forms.CheckBox
        Me._Label3_0 = New System.Windows.Forms.Label
        Me._Label3_1 = New System.Windows.Forms.Label
        Me._Label3_2 = New System.Windows.Forms.Label
        Me._Label3_3 = New System.Windows.Forms.Label
        Me._Label3_4 = New System.Windows.Forms.Label
        Me._Label3_5 = New System.Windows.Forms.Label
        Me._Label3_6 = New System.Windows.Forms.Label
        Me._Label3_7 = New System.Windows.Forms.Label
        Me._Label3_8 = New System.Windows.Forms.Label
        Me._Label3_9 = New System.Windows.Forms.Label
        Me._Label3_10 = New System.Windows.Forms.Label
        Me._Label3_11 = New System.Windows.Forms.Label
        Me._Label3_12 = New System.Windows.Forms.Label
        Me.INT_N_S_0 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_1 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_2 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_4 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_5 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_6 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_7 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_10 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_11 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_12 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_14 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_15 = New System.Windows.Forms.PictureBox
        Me.INT_N_S_16 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_16 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_15 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_0 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_1 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_2 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_4 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_5 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_6 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_7 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_10 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_11 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_12 = New System.Windows.Forms.PictureBox
        Me.INT_N_B_14 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_16 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_15 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_0 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_1 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_2 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_4 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_5 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_6 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_7 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_10 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_11 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_12 = New System.Windows.Forms.PictureBox
        Me.INT_N_E_14 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_0 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_1 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_2 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_4 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_5 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_6 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_7 = New System.Windows.Forms.PictureBox
        Me.INT_G_E_10 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_0 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_1 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_2 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_4 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_5 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_6 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_7 = New System.Windows.Forms.PictureBox
        Me.INT_G_B_10 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_0 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_1 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_2 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_4 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_5 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_6 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_7 = New System.Windows.Forms.PictureBox
        Me.INT_G_S_10 = New System.Windows.Forms.PictureBox
        Me.Button12 = New System.Windows.Forms.Button
        Me.Button13 = New System.Windows.Forms.Button
        Me.CMP_STS = New System.Windows.Forms.TextBox
        Me.Label2 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label18 = New System.Windows.Forms.Label
        Me.Label19 = New System.Windows.Forms.Label
        Me.Label20 = New System.Windows.Forms.Label
        Me.Label21 = New System.Windows.Forms.Label
        Me.Label22 = New System.Windows.Forms.Label
        Me.Label23 = New System.Windows.Forms.Label
        Me.Label24 = New System.Windows.Forms.Label
        Me.Label25 = New System.Windows.Forms.Label
        Me.Label26 = New System.Windows.Forms.Label
        Me.Label27 = New System.Windows.Forms.Label
        Me.Label28 = New System.Windows.Forms.Label
        Me.GroupBox5.SuspendLayout()
        Me.GroupBox4.SuspendLayout()
        Me.GroupBox3.SuspendLayout()
        Me.GroupBox2.SuspendLayout()
        Me.GroupBox1.SuspendLayout()
        Me.grp_chk_int_factor.SuspendLayout()
        CType(Me.INT_N_S_0, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_5, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_6, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_7, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_10, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_11, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_12, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_14, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_15, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_S_16, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_16, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_15, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_0, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_5, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_6, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_7, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_10, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_11, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_12, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_B_14, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_16, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_15, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_0, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_5, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_6, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_7, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_10, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_11, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_12, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_N_E_14, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_0, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_5, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_6, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_7, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_E_10, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_0, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_5, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_6, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_7, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_B_10, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_0, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_5, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_6, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_7, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.INT_G_S_10, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Button1
        '
        Me.Button1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button1.Location = New System.Drawing.Point(384, 16)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(88, 40)
        Me.Button1.TabIndex = 0
        Me.Button1.Text = "int_control"
        '
        'card_id
        '
        Me.card_id.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.card_id.Location = New System.Drawing.Point(128, 16)
        Me.card_id.Name = "card_id"
        Me.card_id.Size = New System.Drawing.Size(48, 27)
        Me.card_id.TabIndex = 37
        Me.card_id.Text = "0"
        '
        'Label1
        '
        Me.Label1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label1.Location = New System.Drawing.Point(72, 24)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(40, 24)
        Me.Label1.TabIndex = 36
        Me.Label1.Text = "Card:"
        '
        'Button2
        '
        Me.Button2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button2.Location = New System.Drawing.Point(384, 96)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(160, 40)
        Me.Button2.TabIndex = 38
        Me.Button2.Text = "set_gpio_int_factor"
        '
        'Button3
        '
        Me.Button3.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button3.Location = New System.Drawing.Point(373, 512)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(160, 40)
        Me.Button3.TabIndex = 39
        Me.Button3.Text = "wait_gpio_interrupt"
        '
        'Button4
        '
        Me.Button4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button4.Location = New System.Drawing.Point(384, 56)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(160, 40)
        Me.Button4.TabIndex = 40
        Me.Button4.Text = "set_motion_int_factor"
        '
        'Button6
        '
        Me.Button6.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button6.Location = New System.Drawing.Point(192, 512)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(160, 40)
        Me.Button6.TabIndex = 42
        Me.Button6.Text = "wait_normal_interrupt"
        '
        'TimeOut_ms
        '
        Me.TimeOut_ms.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.TimeOut_ms.Location = New System.Drawing.Point(128, 88)
        Me.TimeOut_ms.Name = "TimeOut_ms"
        Me.TimeOut_ms.Size = New System.Drawing.Size(48, 27)
        Me.TimeOut_ms.TabIndex = 46
        Me.TimeOut_ms.Text = "5000"
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label3.Location = New System.Drawing.Point(16, 96)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(96, 24)
        Me.Label3.TabIndex = 45
        Me.Label3.Text = "TimeOut_ms:"
        '
        'intFlag
        '
        Me.intFlag.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.intFlag.Location = New System.Drawing.Point(312, 16)
        Me.intFlag.Name = "intFlag"
        Me.intFlag.Size = New System.Drawing.Size(48, 27)
        Me.intFlag.TabIndex = 48
        Me.intFlag.Text = "1"
        '
        'Label4
        '
        Me.Label4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label4.Location = New System.Drawing.Point(240, 24)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(56, 24)
        Me.Label4.TabIndex = 47
        Me.Label4.Text = "intFlag:"
        '
        'GroupBox5
        '
        Me.GroupBox5.Controls.Add(Me.CMD1)
        Me.GroupBox5.Controls.Add(Me.CMD0)
        Me.GroupBox5.Controls.Add(Me.Label10)
        Me.GroupBox5.Controls.Add(Me.Label11)
        Me.GroupBox5.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox5.Location = New System.Drawing.Point(560, 248)
        Me.GroupBox5.Name = "GroupBox5"
        Me.GroupBox5.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox5.TabIndex = 70
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
        'Button7
        '
        Me.Button7.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button7.Location = New System.Drawing.Point(848, 504)
        Me.Button7.Name = "Button7"
        Me.Button7.Size = New System.Drawing.Size(96, 48)
        Me.Button7.TabIndex = 69
        Me.Button7.Text = "EMG Stop"
        '
        'Button8
        '
        Me.Button8.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button8.Location = New System.Drawing.Point(736, 504)
        Me.Button8.Name = "Button8"
        Me.Button8.Size = New System.Drawing.Size(96, 48)
        Me.Button8.TabIndex = 68
        Me.Button8.Text = "Reset Position"
        '
        'ARC_CMD_1
        '
        Me.ARC_CMD_1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.ARC_CMD_1.Location = New System.Drawing.Point(876, 456)
        Me.ARC_CMD_1.Name = "ARC_CMD_1"
        Me.ARC_CMD_1.Size = New System.Drawing.Size(68, 27)
        Me.ARC_CMD_1.TabIndex = 67
        Me.ARC_CMD_1.Text = "20000"
        '
        'ARC_CMD_0
        '
        Me.ARC_CMD_0.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.ARC_CMD_0.Location = New System.Drawing.Point(876, 424)
        Me.ARC_CMD_0.Name = "ARC_CMD_0"
        Me.ARC_CMD_0.Size = New System.Drawing.Size(68, 27)
        Me.ARC_CMD_0.TabIndex = 66
        Me.ARC_CMD_0.Text = "40000"
        '
        'Button9
        '
        Me.Button9.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button9.Location = New System.Drawing.Point(736, 424)
        Me.Button9.Name = "Button9"
        Me.Button9.Size = New System.Drawing.Size(56, 32)
        Me.Button9.TabIndex = 65
        Me.Button9.Text = "ARC"
        '
        'LINE_CMD_1
        '
        Me.LINE_CMD_1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.LINE_CMD_1.Location = New System.Drawing.Point(876, 376)
        Me.LINE_CMD_1.Name = "LINE_CMD_1"
        Me.LINE_CMD_1.Size = New System.Drawing.Size(68, 27)
        Me.LINE_CMD_1.TabIndex = 64
        Me.LINE_CMD_1.Text = "20000"
        '
        'LINE_CMD_0
        '
        Me.LINE_CMD_0.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.LINE_CMD_0.Location = New System.Drawing.Point(876, 344)
        Me.LINE_CMD_0.Name = "LINE_CMD_0"
        Me.LINE_CMD_0.Size = New System.Drawing.Size(68, 27)
        Me.LINE_CMD_0.TabIndex = 63
        Me.LINE_CMD_0.Text = "40000"
        '
        'Button10
        '
        Me.Button10.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button10.Location = New System.Drawing.Point(736, 344)
        Me.Button10.Name = "Button10"
        Me.Button10.Size = New System.Drawing.Size(56, 32)
        Me.Button10.TabIndex = 62
        Me.Button10.Text = "LINE"
        '
        'CheckBox1
        '
        Me.CheckBox1.Location = New System.Drawing.Point(736, 296)
        Me.CheckBox1.Name = "CheckBox1"
        Me.CheckBox1.Size = New System.Drawing.Size(88, 24)
        Me.CheckBox1.TabIndex = 61
        Me.CheckBox1.Text = "Use Trigger?"
        '
        'PTP_CMD
        '
        Me.PTP_CMD.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.PTP_CMD.Location = New System.Drawing.Point(876, 288)
        Me.PTP_CMD.Name = "PTP_CMD"
        Me.PTP_CMD.Size = New System.Drawing.Size(68, 27)
        Me.PTP_CMD.TabIndex = 60
        Me.PTP_CMD.Text = "150000"
        '
        'PTP_AXIS
        '
        Me.PTP_AXIS.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.PTP_AXIS.Location = New System.Drawing.Point(896, 256)
        Me.PTP_AXIS.Name = "PTP_AXIS"
        Me.PTP_AXIS.Size = New System.Drawing.Size(48, 27)
        Me.PTP_AXIS.TabIndex = 59
        Me.PTP_AXIS.Text = "0"
        '
        'Label9
        '
        Me.Label9.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label9.Location = New System.Drawing.Point(848, 264)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(48, 16)
        Me.Label9.TabIndex = 58
        Me.Label9.Text = "Axis :"
        '
        'Button11
        '
        Me.Button11.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button11.Location = New System.Drawing.Point(736, 256)
        Me.Button11.Name = "Button11"
        Me.Button11.Size = New System.Drawing.Size(96, 32)
        Me.Button11.TabIndex = 57
        Me.Button11.Text = "PTP"
        '
        'GroupBox4
        '
        Me.GroupBox4.Controls.Add(Me.MotSts1)
        Me.GroupBox4.Controls.Add(Me.MotSts0)
        Me.GroupBox4.Controls.Add(Me.Label7)
        Me.GroupBox4.Controls.Add(Me.Label8)
        Me.GroupBox4.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox4.Location = New System.Drawing.Point(736, 128)
        Me.GroupBox4.Name = "GroupBox4"
        Me.GroupBox4.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox4.TabIndex = 56
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
        'GroupBox3
        '
        Me.GroupBox3.Controls.Add(Me.Speed1)
        Me.GroupBox3.Controls.Add(Me.Speed0)
        Me.GroupBox3.Controls.Add(Me.Label12)
        Me.GroupBox3.Controls.Add(Me.Label13)
        Me.GroupBox3.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox3.Location = New System.Drawing.Point(560, 128)
        Me.GroupBox3.Name = "GroupBox3"
        Me.GroupBox3.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox3.TabIndex = 55
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
        'Label12
        '
        Me.Label12.Location = New System.Drawing.Point(8, 72)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(56, 23)
        Me.Label12.TabIndex = 1
        Me.Label12.Text = "Axis 1"
        '
        'Label13
        '
        Me.Label13.Location = New System.Drawing.Point(8, 38)
        Me.Label13.Name = "Label13"
        Me.Label13.Size = New System.Drawing.Size(48, 23)
        Me.Label13.TabIndex = 0
        Me.Label13.Text = "Axis 0"
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.IOSts1)
        Me.GroupBox2.Controls.Add(Me.IOSts0)
        Me.GroupBox2.Controls.Add(Me.Label14)
        Me.GroupBox2.Controls.Add(Me.Label15)
        Me.GroupBox2.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox2.Location = New System.Drawing.Point(736, 8)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox2.TabIndex = 54
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
        'Label14
        '
        Me.Label14.Location = New System.Drawing.Point(12, 72)
        Me.Label14.Name = "Label14"
        Me.Label14.Size = New System.Drawing.Size(56, 23)
        Me.Label14.TabIndex = 5
        Me.Label14.Text = "Axis 1"
        '
        'Label15
        '
        Me.Label15.Location = New System.Drawing.Point(12, 40)
        Me.Label15.Name = "Label15"
        Me.Label15.Size = New System.Drawing.Size(48, 23)
        Me.Label15.TabIndex = 4
        Me.Label15.Text = "Axis 0"
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.Pos1)
        Me.GroupBox1.Controls.Add(Me.Pos0)
        Me.GroupBox1.Controls.Add(Me.Label16)
        Me.GroupBox1.Controls.Add(Me.Label17)
        Me.GroupBox1.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.GroupBox1.Location = New System.Drawing.Point(560, 8)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(160, 112)
        Me.GroupBox1.TabIndex = 53
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
        'Label16
        '
        Me.Label16.Location = New System.Drawing.Point(8, 72)
        Me.Label16.Name = "Label16"
        Me.Label16.Size = New System.Drawing.Size(56, 23)
        Me.Label16.TabIndex = 1
        Me.Label16.Text = "Axis 1"
        '
        'Label17
        '
        Me.Label17.Location = New System.Drawing.Point(8, 38)
        Me.Label17.Name = "Label17"
        Me.Label17.Size = New System.Drawing.Size(48, 23)
        Me.Label17.TabIndex = 0
        Me.Label17.Text = "Axis 0"
        '
        'Timer1
        '
        Me.Timer1.Enabled = True
        Me.Timer1.Interval = 50
        '
        'grp_chk_int_factor
        '
        Me.grp_chk_int_factor.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_0)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_1)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_2)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_4)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_5)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_6)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_7)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_10)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_11)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_12)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_14)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_15)
        Me.grp_chk_int_factor.Controls.Add(Me.grp_chk_int_factor_16)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_0)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_1)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_2)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_3)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_4)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_5)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_6)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_7)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_8)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_9)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_10)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_11)
        Me.grp_chk_int_factor.Controls.Add(Me._Label3_12)
        Me.grp_chk_int_factor.Font = New System.Drawing.Font("Times New Roman", 14.25!, CType((System.Drawing.FontStyle.Bold Or System.Drawing.FontStyle.Italic), System.Drawing.FontStyle), System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.grp_chk_int_factor.ForeColor = System.Drawing.SystemColors.Highlight
        Me.grp_chk_int_factor.Location = New System.Drawing.Point(8, 120)
        Me.grp_chk_int_factor.Name = "grp_chk_int_factor"
        Me.grp_chk_int_factor.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor.Size = New System.Drawing.Size(224, 384)
        Me.grp_chk_int_factor.TabIndex = 71
        Me.grp_chk_int_factor.TabStop = False
        Me.grp_chk_int_factor.Text = "INT Factor"
        '
        'grp_chk_int_factor_0
        '
        Me.grp_chk_int_factor_0.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_0.Checked = True
        Me.grp_chk_int_factor_0.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_0.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_0.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_0.Location = New System.Drawing.Point(56, 32)
        Me.grp_chk_int_factor_0.Name = "grp_chk_int_factor_0"
        Me.grp_chk_int_factor_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_0.Size = New System.Drawing.Size(139, 24)
        Me.grp_chk_int_factor_0.TabIndex = 32
        Me.grp_chk_int_factor_0.Text = "Normal Stop"
        Me.grp_chk_int_factor_0.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_1
        '
        Me.grp_chk_int_factor_1.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_1.Checked = True
        Me.grp_chk_int_factor_1.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_1.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_1.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_1.Location = New System.Drawing.Point(56, 56)
        Me.grp_chk_int_factor_1.Name = "grp_chk_int_factor_1"
        Me.grp_chk_int_factor_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_1.Size = New System.Drawing.Size(160, 24)
        Me.grp_chk_int_factor_1.TabIndex = 31
        Me.grp_chk_int_factor_1.Text = "Next Command Continued"
        Me.grp_chk_int_factor_1.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_2
        '
        Me.grp_chk_int_factor_2.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_2.Checked = True
        Me.grp_chk_int_factor_2.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_2.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_2.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_2.Location = New System.Drawing.Point(56, 80)
        Me.grp_chk_int_factor_2.Name = "grp_chk_int_factor_2"
        Me.grp_chk_int_factor_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_2.Size = New System.Drawing.Size(148, 32)
        Me.grp_chk_int_factor_2.TabIndex = 30
        Me.grp_chk_int_factor_2.Text = "Continuous Pre-register is Empty "
        Me.grp_chk_int_factor_2.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_4
        '
        Me.grp_chk_int_factor_4.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_4.Checked = True
        Me.grp_chk_int_factor_4.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_4.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_4.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_4.Location = New System.Drawing.Point(56, 112)
        Me.grp_chk_int_factor_4.Name = "grp_chk_int_factor_4"
        Me.grp_chk_int_factor_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_4.Size = New System.Drawing.Size(139, 24)
        Me.grp_chk_int_factor_4.TabIndex = 29
        Me.grp_chk_int_factor_4.Text = "Acceleration Start"
        Me.grp_chk_int_factor_4.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_5
        '
        Me.grp_chk_int_factor_5.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_5.Checked = True
        Me.grp_chk_int_factor_5.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_5.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_5.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_5.Location = New System.Drawing.Point(56, 136)
        Me.grp_chk_int_factor_5.Name = "grp_chk_int_factor_5"
        Me.grp_chk_int_factor_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_5.Size = New System.Drawing.Size(142, 24)
        Me.grp_chk_int_factor_5.TabIndex = 28
        Me.grp_chk_int_factor_5.Text = "Acceleration End"
        Me.grp_chk_int_factor_5.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_6
        '
        Me.grp_chk_int_factor_6.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_6.Checked = True
        Me.grp_chk_int_factor_6.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_6.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_6.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_6.Location = New System.Drawing.Point(56, 160)
        Me.grp_chk_int_factor_6.Name = "grp_chk_int_factor_6"
        Me.grp_chk_int_factor_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_6.Size = New System.Drawing.Size(145, 24)
        Me.grp_chk_int_factor_6.TabIndex = 27
        Me.grp_chk_int_factor_6.Text = "Deceleration Start"
        Me.grp_chk_int_factor_6.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_7
        '
        Me.grp_chk_int_factor_7.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_7.Checked = True
        Me.grp_chk_int_factor_7.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_7.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_7.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_7.Location = New System.Drawing.Point(56, 184)
        Me.grp_chk_int_factor_7.Name = "grp_chk_int_factor_7"
        Me.grp_chk_int_factor_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_7.Size = New System.Drawing.Size(142, 24)
        Me.grp_chk_int_factor_7.TabIndex = 26
        Me.grp_chk_int_factor_7.Text = "Deceleration End"
        Me.grp_chk_int_factor_7.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_10
        '
        Me.grp_chk_int_factor_10.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_10.Checked = True
        Me.grp_chk_int_factor_10.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_10.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_10.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_10.Location = New System.Drawing.Point(56, 208)
        Me.grp_chk_int_factor_10.Name = "grp_chk_int_factor_10"
        Me.grp_chk_int_factor_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_10.Size = New System.Drawing.Size(143, 24)
        Me.grp_chk_int_factor_10.TabIndex = 25
        Me.grp_chk_int_factor_10.Text = "Position Error Occur"
        Me.grp_chk_int_factor_10.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_11
        '
        Me.grp_chk_int_factor_11.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_11.Checked = True
        Me.grp_chk_int_factor_11.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_11.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_11.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_11.Location = New System.Drawing.Point(56, 232)
        Me.grp_chk_int_factor_11.Name = "grp_chk_int_factor_11"
        Me.grp_chk_int_factor_11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_11.Size = New System.Drawing.Size(148, 33)
        Me.grp_chk_int_factor_11.TabIndex = 24
        Me.grp_chk_int_factor_11.Text = "General Comparator Compared"
        Me.grp_chk_int_factor_11.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_12
        '
        Me.grp_chk_int_factor_12.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_12.Checked = True
        Me.grp_chk_int_factor_12.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_12.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_12.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_12.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_12.Location = New System.Drawing.Point(56, 262)
        Me.grp_chk_int_factor_12.Name = "grp_chk_int_factor_12"
        Me.grp_chk_int_factor_12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_12.Size = New System.Drawing.Size(145, 29)
        Me.grp_chk_int_factor_12.TabIndex = 23
        Me.grp_chk_int_factor_12.Text = "Compare Trigger for Axis 0,1"
        Me.grp_chk_int_factor_12.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_14
        '
        Me.grp_chk_int_factor_14.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_14.Checked = True
        Me.grp_chk_int_factor_14.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_14.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_14.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_14.Location = New System.Drawing.Point(56, 296)
        Me.grp_chk_int_factor_14.Name = "grp_chk_int_factor_14"
        Me.grp_chk_int_factor_14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_14.Size = New System.Drawing.Size(145, 15)
        Me.grp_chk_int_factor_14.TabIndex = 22
        Me.grp_chk_int_factor_14.Text = "Latch for Axis 2,3"
        Me.grp_chk_int_factor_14.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_15
        '
        Me.grp_chk_int_factor_15.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_15.Checked = True
        Me.grp_chk_int_factor_15.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_15.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_15.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_15.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_15.Location = New System.Drawing.Point(56, 324)
        Me.grp_chk_int_factor_15.Name = "grp_chk_int_factor_15"
        Me.grp_chk_int_factor_15.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_15.Size = New System.Drawing.Size(145, 15)
        Me.grp_chk_int_factor_15.TabIndex = 21
        Me.grp_chk_int_factor_15.Text = "ORG On"
        Me.grp_chk_int_factor_15.UseVisualStyleBackColor = False
        '
        'grp_chk_int_factor_16
        '
        Me.grp_chk_int_factor_16.BackColor = System.Drawing.SystemColors.Control
        Me.grp_chk_int_factor_16.Checked = True
        Me.grp_chk_int_factor_16.CheckState = System.Windows.Forms.CheckState.Checked
        Me.grp_chk_int_factor_16.Cursor = System.Windows.Forms.Cursors.Default
        Me.grp_chk_int_factor_16.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.grp_chk_int_factor_16.ForeColor = System.Drawing.SystemColors.ControlText
        Me.grp_chk_int_factor_16.Location = New System.Drawing.Point(56, 352)
        Me.grp_chk_int_factor_16.Name = "grp_chk_int_factor_16"
        Me.grp_chk_int_factor_16.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.grp_chk_int_factor_16.Size = New System.Drawing.Size(139, 15)
        Me.grp_chk_int_factor_16.TabIndex = 20
        Me.grp_chk_int_factor_16.Text = "SD On"
        Me.grp_chk_int_factor_16.UseVisualStyleBackColor = False
        '
        '_Label3_0
        '
        Me._Label3_0.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_0.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_0.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_0.Location = New System.Drawing.Point(4, 37)
        Me._Label3_0.Name = "_Label3_0"
        Me._Label3_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_0.Size = New System.Drawing.Size(41, 24)
        Me._Label3_0.TabIndex = 45
        Me._Label3_0.Text = "Bit 0"
        '
        '_Label3_1
        '
        Me._Label3_1.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_1.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_1.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_1.Location = New System.Drawing.Point(4, 61)
        Me._Label3_1.Name = "_Label3_1"
        Me._Label3_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_1.Size = New System.Drawing.Size(41, 15)
        Me._Label3_1.TabIndex = 44
        Me._Label3_1.Text = "Bit 1"
        '
        '_Label3_2
        '
        Me._Label3_2.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_2.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_2.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_2.Location = New System.Drawing.Point(4, 88)
        Me._Label3_2.Name = "_Label3_2"
        Me._Label3_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_2.Size = New System.Drawing.Size(41, 15)
        Me._Label3_2.TabIndex = 43
        Me._Label3_2.Text = "Bit 2"
        '
        '_Label3_3
        '
        Me._Label3_3.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_3.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_3.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_3.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_3.Location = New System.Drawing.Point(4, 116)
        Me._Label3_3.Name = "_Label3_3"
        Me._Label3_3.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_3.Size = New System.Drawing.Size(41, 15)
        Me._Label3_3.TabIndex = 42
        Me._Label3_3.Text = "Bit 4"
        '
        '_Label3_4
        '
        Me._Label3_4.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_4.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_4.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_4.Location = New System.Drawing.Point(4, 141)
        Me._Label3_4.Name = "_Label3_4"
        Me._Label3_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_4.Size = New System.Drawing.Size(41, 15)
        Me._Label3_4.TabIndex = 41
        Me._Label3_4.Text = "Bit 5"
        '
        '_Label3_5
        '
        Me._Label3_5.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_5.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_5.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_5.Location = New System.Drawing.Point(4, 164)
        Me._Label3_5.Name = "_Label3_5"
        Me._Label3_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_5.Size = New System.Drawing.Size(41, 15)
        Me._Label3_5.TabIndex = 40
        Me._Label3_5.Text = "Bit 6"
        '
        '_Label3_6
        '
        Me._Label3_6.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_6.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_6.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_6.Location = New System.Drawing.Point(4, 188)
        Me._Label3_6.Name = "_Label3_6"
        Me._Label3_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_6.Size = New System.Drawing.Size(39, 15)
        Me._Label3_6.TabIndex = 39
        Me._Label3_6.Text = "Bit 7"
        '
        '_Label3_7
        '
        Me._Label3_7.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_7.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_7.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_7.Location = New System.Drawing.Point(4, 213)
        Me._Label3_7.Name = "_Label3_7"
        Me._Label3_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_7.Size = New System.Drawing.Size(49, 15)
        Me._Label3_7.TabIndex = 38
        Me._Label3_7.Text = "Bit 10"
        '
        '_Label3_8
        '
        Me._Label3_8.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_8.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_8.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_8.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_8.Location = New System.Drawing.Point(6, 240)
        Me._Label3_8.Name = "_Label3_8"
        Me._Label3_8.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_8.Size = New System.Drawing.Size(47, 15)
        Me._Label3_8.TabIndex = 37
        Me._Label3_8.Text = "Bit 11"
        '
        '_Label3_9
        '
        Me._Label3_9.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_9.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_9.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_9.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_9.Location = New System.Drawing.Point(6, 268)
        Me._Label3_9.Name = "_Label3_9"
        Me._Label3_9.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_9.Size = New System.Drawing.Size(47, 15)
        Me._Label3_9.TabIndex = 36
        Me._Label3_9.Text = "Bit 12"
        '
        '_Label3_10
        '
        Me._Label3_10.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_10.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_10.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_10.Location = New System.Drawing.Point(6, 296)
        Me._Label3_10.Name = "_Label3_10"
        Me._Label3_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_10.Size = New System.Drawing.Size(47, 15)
        Me._Label3_10.TabIndex = 35
        Me._Label3_10.Text = "Bit 14"
        '
        '_Label3_11
        '
        Me._Label3_11.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_11.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_11.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_11.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_11.Location = New System.Drawing.Point(6, 324)
        Me._Label3_11.Name = "_Label3_11"
        Me._Label3_11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_11.Size = New System.Drawing.Size(47, 15)
        Me._Label3_11.TabIndex = 34
        Me._Label3_11.Text = "Bit 15"
        '
        '_Label3_12
        '
        Me._Label3_12.BackColor = System.Drawing.SystemColors.Control
        Me._Label3_12.Cursor = System.Windows.Forms.Cursors.Default
        Me._Label3_12.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me._Label3_12.ForeColor = System.Drawing.SystemColors.ControlText
        Me._Label3_12.Location = New System.Drawing.Point(6, 352)
        Me._Label3_12.Name = "_Label3_12"
        Me._Label3_12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me._Label3_12.Size = New System.Drawing.Size(47, 15)
        Me._Label3_12.TabIndex = 33
        Me._Label3_12.Text = "Bit 16"
        '
        'INT_N_S_0
        '
        Me.INT_N_S_0.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_0.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_0.Location = New System.Drawing.Point(248, 152)
        Me.INT_N_S_0.Name = "INT_N_S_0"
        Me.INT_N_S_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_0.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_S_0.TabIndex = 82
        Me.INT_N_S_0.TabStop = False
        '
        'INT_N_S_1
        '
        Me.INT_N_S_1.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_1.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_1.Location = New System.Drawing.Point(248, 178)
        Me.INT_N_S_1.Name = "INT_N_S_1"
        Me.INT_N_S_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_1.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_S_1.TabIndex = 81
        Me.INT_N_S_1.TabStop = False
        '
        'INT_N_S_2
        '
        Me.INT_N_S_2.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_2.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_2.Location = New System.Drawing.Point(248, 205)
        Me.INT_N_S_2.Name = "INT_N_S_2"
        Me.INT_N_S_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_2.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_S_2.TabIndex = 80
        Me.INT_N_S_2.TabStop = False
        '
        'INT_N_S_4
        '
        Me.INT_N_S_4.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_4.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_4.Location = New System.Drawing.Point(248, 232)
        Me.INT_N_S_4.Name = "INT_N_S_4"
        Me.INT_N_S_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_4.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_S_4.TabIndex = 79
        Me.INT_N_S_4.TabStop = False
        '
        'INT_N_S_5
        '
        Me.INT_N_S_5.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_5.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_5.Location = New System.Drawing.Point(248, 258)
        Me.INT_N_S_5.Name = "INT_N_S_5"
        Me.INT_N_S_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_5.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_S_5.TabIndex = 78
        Me.INT_N_S_5.TabStop = False
        '
        'INT_N_S_6
        '
        Me.INT_N_S_6.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_6.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_6.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_6.Location = New System.Drawing.Point(248, 285)
        Me.INT_N_S_6.Name = "INT_N_S_6"
        Me.INT_N_S_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_6.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_S_6.TabIndex = 77
        Me.INT_N_S_6.TabStop = False
        '
        'INT_N_S_7
        '
        Me.INT_N_S_7.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_7.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_7.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_7.Location = New System.Drawing.Point(248, 312)
        Me.INT_N_S_7.Name = "INT_N_S_7"
        Me.INT_N_S_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_7.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_S_7.TabIndex = 76
        Me.INT_N_S_7.TabStop = False
        '
        'INT_N_S_10
        '
        Me.INT_N_S_10.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_10.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_10.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_10.Location = New System.Drawing.Point(248, 338)
        Me.INT_N_S_10.Name = "INT_N_S_10"
        Me.INT_N_S_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_10.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_S_10.TabIndex = 75
        Me.INT_N_S_10.TabStop = False
        '
        'INT_N_S_11
        '
        Me.INT_N_S_11.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_11.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_11.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_11.Location = New System.Drawing.Point(248, 364)
        Me.INT_N_S_11.Name = "INT_N_S_11"
        Me.INT_N_S_11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_11.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_S_11.TabIndex = 74
        Me.INT_N_S_11.TabStop = False
        '
        'INT_N_S_12
        '
        Me.INT_N_S_12.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_12.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_12.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_12.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_12.Location = New System.Drawing.Point(248, 391)
        Me.INT_N_S_12.Name = "INT_N_S_12"
        Me.INT_N_S_12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_12.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_S_12.TabIndex = 73
        Me.INT_N_S_12.TabStop = False
        '
        'INT_N_S_14
        '
        Me.INT_N_S_14.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_14.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_14.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_14.Location = New System.Drawing.Point(248, 418)
        Me.INT_N_S_14.Name = "INT_N_S_14"
        Me.INT_N_S_14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_14.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_S_14.TabIndex = 72
        Me.INT_N_S_14.TabStop = False
        '
        'INT_N_S_15
        '
        Me.INT_N_S_15.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_15.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_15.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_15.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_15.Location = New System.Drawing.Point(248, 444)
        Me.INT_N_S_15.Name = "INT_N_S_15"
        Me.INT_N_S_15.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_15.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_S_15.TabIndex = 83
        Me.INT_N_S_15.TabStop = False
        '
        'INT_N_S_16
        '
        Me.INT_N_S_16.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_N_S_16.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_S_16.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_S_16.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_S_16.Location = New System.Drawing.Point(248, 470)
        Me.INT_N_S_16.Name = "INT_N_S_16"
        Me.INT_N_S_16.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_S_16.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_S_16.TabIndex = 84
        Me.INT_N_S_16.TabStop = False
        '
        'INT_N_B_16
        '
        Me.INT_N_B_16.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_16.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_16.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_16.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_16.Location = New System.Drawing.Point(280, 470)
        Me.INT_N_B_16.Name = "INT_N_B_16"
        Me.INT_N_B_16.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_16.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_B_16.TabIndex = 97
        Me.INT_N_B_16.TabStop = False
        '
        'INT_N_B_15
        '
        Me.INT_N_B_15.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_15.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_15.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_15.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_15.Location = New System.Drawing.Point(280, 444)
        Me.INT_N_B_15.Name = "INT_N_B_15"
        Me.INT_N_B_15.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_15.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_B_15.TabIndex = 96
        Me.INT_N_B_15.TabStop = False
        '
        'INT_N_B_0
        '
        Me.INT_N_B_0.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_0.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_0.Location = New System.Drawing.Point(280, 152)
        Me.INT_N_B_0.Name = "INT_N_B_0"
        Me.INT_N_B_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_0.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_B_0.TabIndex = 95
        Me.INT_N_B_0.TabStop = False
        '
        'INT_N_B_1
        '
        Me.INT_N_B_1.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_1.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_1.Location = New System.Drawing.Point(280, 178)
        Me.INT_N_B_1.Name = "INT_N_B_1"
        Me.INT_N_B_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_1.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_B_1.TabIndex = 94
        Me.INT_N_B_1.TabStop = False
        '
        'INT_N_B_2
        '
        Me.INT_N_B_2.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_2.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_2.Location = New System.Drawing.Point(280, 205)
        Me.INT_N_B_2.Name = "INT_N_B_2"
        Me.INT_N_B_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_2.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_B_2.TabIndex = 93
        Me.INT_N_B_2.TabStop = False
        '
        'INT_N_B_4
        '
        Me.INT_N_B_4.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_4.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_4.Location = New System.Drawing.Point(280, 232)
        Me.INT_N_B_4.Name = "INT_N_B_4"
        Me.INT_N_B_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_4.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_B_4.TabIndex = 92
        Me.INT_N_B_4.TabStop = False
        '
        'INT_N_B_5
        '
        Me.INT_N_B_5.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_5.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_5.Location = New System.Drawing.Point(280, 258)
        Me.INT_N_B_5.Name = "INT_N_B_5"
        Me.INT_N_B_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_5.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_B_5.TabIndex = 91
        Me.INT_N_B_5.TabStop = False
        '
        'INT_N_B_6
        '
        Me.INT_N_B_6.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_6.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_6.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_6.Location = New System.Drawing.Point(280, 285)
        Me.INT_N_B_6.Name = "INT_N_B_6"
        Me.INT_N_B_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_6.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_B_6.TabIndex = 90
        Me.INT_N_B_6.TabStop = False
        '
        'INT_N_B_7
        '
        Me.INT_N_B_7.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_7.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_7.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_7.Location = New System.Drawing.Point(280, 312)
        Me.INT_N_B_7.Name = "INT_N_B_7"
        Me.INT_N_B_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_7.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_B_7.TabIndex = 89
        Me.INT_N_B_7.TabStop = False
        '
        'INT_N_B_10
        '
        Me.INT_N_B_10.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_10.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_10.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_10.Location = New System.Drawing.Point(280, 338)
        Me.INT_N_B_10.Name = "INT_N_B_10"
        Me.INT_N_B_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_10.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_B_10.TabIndex = 88
        Me.INT_N_B_10.TabStop = False
        '
        'INT_N_B_11
        '
        Me.INT_N_B_11.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_11.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_11.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_11.Location = New System.Drawing.Point(280, 364)
        Me.INT_N_B_11.Name = "INT_N_B_11"
        Me.INT_N_B_11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_11.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_B_11.TabIndex = 87
        Me.INT_N_B_11.TabStop = False
        '
        'INT_N_B_12
        '
        Me.INT_N_B_12.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_12.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_12.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_12.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_12.Location = New System.Drawing.Point(280, 391)
        Me.INT_N_B_12.Name = "INT_N_B_12"
        Me.INT_N_B_12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_12.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_B_12.TabIndex = 86
        Me.INT_N_B_12.TabStop = False
        '
        'INT_N_B_14
        '
        Me.INT_N_B_14.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_N_B_14.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_B_14.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_B_14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_B_14.Location = New System.Drawing.Point(280, 418)
        Me.INT_N_B_14.Name = "INT_N_B_14"
        Me.INT_N_B_14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_B_14.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_B_14.TabIndex = 85
        Me.INT_N_B_14.TabStop = False
        '
        'INT_N_E_16
        '
        Me.INT_N_E_16.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_16.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_16.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_16.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_16.Location = New System.Drawing.Point(312, 470)
        Me.INT_N_E_16.Name = "INT_N_E_16"
        Me.INT_N_E_16.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_16.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_E_16.TabIndex = 110
        Me.INT_N_E_16.TabStop = False
        '
        'INT_N_E_15
        '
        Me.INT_N_E_15.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_15.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_15.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_15.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_15.Location = New System.Drawing.Point(312, 444)
        Me.INT_N_E_15.Name = "INT_N_E_15"
        Me.INT_N_E_15.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_15.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_E_15.TabIndex = 109
        Me.INT_N_E_15.TabStop = False
        '
        'INT_N_E_0
        '
        Me.INT_N_E_0.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_0.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_0.Location = New System.Drawing.Point(312, 152)
        Me.INT_N_E_0.Name = "INT_N_E_0"
        Me.INT_N_E_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_0.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_E_0.TabIndex = 108
        Me.INT_N_E_0.TabStop = False
        '
        'INT_N_E_1
        '
        Me.INT_N_E_1.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_1.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_1.Location = New System.Drawing.Point(312, 178)
        Me.INT_N_E_1.Name = "INT_N_E_1"
        Me.INT_N_E_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_1.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_E_1.TabIndex = 107
        Me.INT_N_E_1.TabStop = False
        '
        'INT_N_E_2
        '
        Me.INT_N_E_2.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_2.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_2.Location = New System.Drawing.Point(312, 205)
        Me.INT_N_E_2.Name = "INT_N_E_2"
        Me.INT_N_E_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_2.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_E_2.TabIndex = 106
        Me.INT_N_E_2.TabStop = False
        '
        'INT_N_E_4
        '
        Me.INT_N_E_4.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_4.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_4.Location = New System.Drawing.Point(312, 232)
        Me.INT_N_E_4.Name = "INT_N_E_4"
        Me.INT_N_E_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_4.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_E_4.TabIndex = 105
        Me.INT_N_E_4.TabStop = False
        '
        'INT_N_E_5
        '
        Me.INT_N_E_5.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_5.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_5.Location = New System.Drawing.Point(312, 258)
        Me.INT_N_E_5.Name = "INT_N_E_5"
        Me.INT_N_E_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_5.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_E_5.TabIndex = 104
        Me.INT_N_E_5.TabStop = False
        '
        'INT_N_E_6
        '
        Me.INT_N_E_6.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_6.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_6.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_6.Location = New System.Drawing.Point(312, 285)
        Me.INT_N_E_6.Name = "INT_N_E_6"
        Me.INT_N_E_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_6.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_E_6.TabIndex = 103
        Me.INT_N_E_6.TabStop = False
        '
        'INT_N_E_7
        '
        Me.INT_N_E_7.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_7.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_7.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_7.Location = New System.Drawing.Point(312, 312)
        Me.INT_N_E_7.Name = "INT_N_E_7"
        Me.INT_N_E_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_7.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_E_7.TabIndex = 102
        Me.INT_N_E_7.TabStop = False
        '
        'INT_N_E_10
        '
        Me.INT_N_E_10.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_10.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_10.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_10.Location = New System.Drawing.Point(312, 338)
        Me.INT_N_E_10.Name = "INT_N_E_10"
        Me.INT_N_E_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_10.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_E_10.TabIndex = 101
        Me.INT_N_E_10.TabStop = False
        '
        'INT_N_E_11
        '
        Me.INT_N_E_11.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_11.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_11.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_11.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_11.Location = New System.Drawing.Point(312, 364)
        Me.INT_N_E_11.Name = "INT_N_E_11"
        Me.INT_N_E_11.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_11.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_E_11.TabIndex = 100
        Me.INT_N_E_11.TabStop = False
        '
        'INT_N_E_12
        '
        Me.INT_N_E_12.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_12.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_12.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_12.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_12.Location = New System.Drawing.Point(312, 391)
        Me.INT_N_E_12.Name = "INT_N_E_12"
        Me.INT_N_E_12.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_12.Size = New System.Drawing.Size(17, 20)
        Me.INT_N_E_12.TabIndex = 99
        Me.INT_N_E_12.TabStop = False
        '
        'INT_N_E_14
        '
        Me.INT_N_E_14.BackColor = System.Drawing.Color.DarkRed
        Me.INT_N_E_14.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_N_E_14.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_N_E_14.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_N_E_14.Location = New System.Drawing.Point(312, 418)
        Me.INT_N_E_14.Name = "INT_N_E_14"
        Me.INT_N_E_14.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_N_E_14.Size = New System.Drawing.Size(17, 19)
        Me.INT_N_E_14.TabIndex = 98
        Me.INT_N_E_14.TabStop = False
        '
        'INT_G_E_0
        '
        Me.INT_G_E_0.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_0.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_0.Location = New System.Drawing.Point(525, 178)
        Me.INT_G_E_0.Name = "INT_G_E_0"
        Me.INT_G_E_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_0.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_E_0.TabIndex = 152
        Me.INT_G_E_0.TabStop = False
        '
        'INT_G_E_1
        '
        Me.INT_G_E_1.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_1.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_1.Location = New System.Drawing.Point(525, 218)
        Me.INT_G_E_1.Name = "INT_G_E_1"
        Me.INT_G_E_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_1.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_E_1.TabIndex = 151
        Me.INT_G_E_1.TabStop = False
        '
        'INT_G_E_2
        '
        Me.INT_G_E_2.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_2.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_2.Location = New System.Drawing.Point(525, 259)
        Me.INT_G_E_2.Name = "INT_G_E_2"
        Me.INT_G_E_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_2.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_E_2.TabIndex = 150
        Me.INT_G_E_2.TabStop = False
        '
        'INT_G_E_4
        '
        Me.INT_G_E_4.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_4.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_4.Location = New System.Drawing.Point(525, 306)
        Me.INT_G_E_4.Name = "INT_G_E_4"
        Me.INT_G_E_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_4.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_E_4.TabIndex = 149
        Me.INT_G_E_4.TabStop = False
        '
        'INT_G_E_5
        '
        Me.INT_G_E_5.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_5.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_5.Location = New System.Drawing.Point(525, 348)
        Me.INT_G_E_5.Name = "INT_G_E_5"
        Me.INT_G_E_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_5.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_E_5.TabIndex = 148
        Me.INT_G_E_5.TabStop = False
        '
        'INT_G_E_6
        '
        Me.INT_G_E_6.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_6.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_6.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_6.Location = New System.Drawing.Point(525, 388)
        Me.INT_G_E_6.Name = "INT_G_E_6"
        Me.INT_G_E_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_6.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_E_6.TabIndex = 147
        Me.INT_G_E_6.TabStop = False
        '
        'INT_G_E_7
        '
        Me.INT_G_E_7.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_7.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_7.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_7.Location = New System.Drawing.Point(525, 429)
        Me.INT_G_E_7.Name = "INT_G_E_7"
        Me.INT_G_E_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_7.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_E_7.TabIndex = 146
        Me.INT_G_E_7.TabStop = False
        '
        'INT_G_E_10
        '
        Me.INT_G_E_10.BackColor = System.Drawing.Color.DarkRed
        Me.INT_G_E_10.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_E_10.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_E_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_E_10.Location = New System.Drawing.Point(525, 469)
        Me.INT_G_E_10.Name = "INT_G_E_10"
        Me.INT_G_E_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_E_10.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_E_10.TabIndex = 145
        Me.INT_G_E_10.TabStop = False
        '
        'INT_G_B_0
        '
        Me.INT_G_B_0.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_0.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_0.Location = New System.Drawing.Point(493, 178)
        Me.INT_G_B_0.Name = "INT_G_B_0"
        Me.INT_G_B_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_0.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_B_0.TabIndex = 139
        Me.INT_G_B_0.TabStop = False
        '
        'INT_G_B_1
        '
        Me.INT_G_B_1.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_1.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_1.Location = New System.Drawing.Point(493, 218)
        Me.INT_G_B_1.Name = "INT_G_B_1"
        Me.INT_G_B_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_1.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_B_1.TabIndex = 138
        Me.INT_G_B_1.TabStop = False
        '
        'INT_G_B_2
        '
        Me.INT_G_B_2.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_2.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_2.Location = New System.Drawing.Point(493, 259)
        Me.INT_G_B_2.Name = "INT_G_B_2"
        Me.INT_G_B_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_2.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_B_2.TabIndex = 137
        Me.INT_G_B_2.TabStop = False
        '
        'INT_G_B_4
        '
        Me.INT_G_B_4.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_4.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_4.Location = New System.Drawing.Point(493, 306)
        Me.INT_G_B_4.Name = "INT_G_B_4"
        Me.INT_G_B_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_4.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_B_4.TabIndex = 136
        Me.INT_G_B_4.TabStop = False
        '
        'INT_G_B_5
        '
        Me.INT_G_B_5.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_5.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_5.Location = New System.Drawing.Point(493, 348)
        Me.INT_G_B_5.Name = "INT_G_B_5"
        Me.INT_G_B_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_5.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_B_5.TabIndex = 135
        Me.INT_G_B_5.TabStop = False
        '
        'INT_G_B_6
        '
        Me.INT_G_B_6.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_6.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_6.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_6.Location = New System.Drawing.Point(493, 388)
        Me.INT_G_B_6.Name = "INT_G_B_6"
        Me.INT_G_B_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_6.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_B_6.TabIndex = 134
        Me.INT_G_B_6.TabStop = False
        '
        'INT_G_B_7
        '
        Me.INT_G_B_7.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_7.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_7.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_7.Location = New System.Drawing.Point(493, 429)
        Me.INT_G_B_7.Name = "INT_G_B_7"
        Me.INT_G_B_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_7.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_B_7.TabIndex = 133
        Me.INT_G_B_7.TabStop = False
        '
        'INT_G_B_10
        '
        Me.INT_G_B_10.BackColor = System.Drawing.Color.DarkGreen
        Me.INT_G_B_10.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_B_10.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_B_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_B_10.Location = New System.Drawing.Point(493, 469)
        Me.INT_G_B_10.Name = "INT_G_B_10"
        Me.INT_G_B_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_B_10.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_B_10.TabIndex = 132
        Me.INT_G_B_10.TabStop = False
        '
        'INT_G_S_0
        '
        Me.INT_G_S_0.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_0.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_0.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_0.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_0.Location = New System.Drawing.Point(461, 178)
        Me.INT_G_S_0.Name = "INT_G_S_0"
        Me.INT_G_S_0.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_0.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_S_0.TabIndex = 126
        Me.INT_G_S_0.TabStop = False
        '
        'INT_G_S_1
        '
        Me.INT_G_S_1.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_1.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_1.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_1.Location = New System.Drawing.Point(461, 218)
        Me.INT_G_S_1.Name = "INT_G_S_1"
        Me.INT_G_S_1.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_1.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_S_1.TabIndex = 125
        Me.INT_G_S_1.TabStop = False
        '
        'INT_G_S_2
        '
        Me.INT_G_S_2.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_2.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_2.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_2.Location = New System.Drawing.Point(461, 259)
        Me.INT_G_S_2.Name = "INT_G_S_2"
        Me.INT_G_S_2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_2.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_S_2.TabIndex = 124
        Me.INT_G_S_2.TabStop = False
        '
        'INT_G_S_4
        '
        Me.INT_G_S_4.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_4.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_4.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_4.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_4.Location = New System.Drawing.Point(461, 306)
        Me.INT_G_S_4.Name = "INT_G_S_4"
        Me.INT_G_S_4.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_4.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_S_4.TabIndex = 123
        Me.INT_G_S_4.TabStop = False
        '
        'INT_G_S_5
        '
        Me.INT_G_S_5.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_5.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_5.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_5.Location = New System.Drawing.Point(461, 348)
        Me.INT_G_S_5.Name = "INT_G_S_5"
        Me.INT_G_S_5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_5.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_S_5.TabIndex = 122
        Me.INT_G_S_5.TabStop = False
        '
        'INT_G_S_6
        '
        Me.INT_G_S_6.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_6.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_6.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_6.Location = New System.Drawing.Point(461, 388)
        Me.INT_G_S_6.Name = "INT_G_S_6"
        Me.INT_G_S_6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_6.Size = New System.Drawing.Size(17, 20)
        Me.INT_G_S_6.TabIndex = 121
        Me.INT_G_S_6.TabStop = False
        '
        'INT_G_S_7
        '
        Me.INT_G_S_7.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_7.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_7.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_7.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_7.Location = New System.Drawing.Point(461, 429)
        Me.INT_G_S_7.Name = "INT_G_S_7"
        Me.INT_G_S_7.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_7.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_S_7.TabIndex = 120
        Me.INT_G_S_7.TabStop = False
        '
        'INT_G_S_10
        '
        Me.INT_G_S_10.BackColor = System.Drawing.Color.SaddleBrown
        Me.INT_G_S_10.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.INT_G_S_10.Cursor = System.Windows.Forms.Cursors.Default
        Me.INT_G_S_10.ForeColor = System.Drawing.SystemColors.ControlText
        Me.INT_G_S_10.Location = New System.Drawing.Point(461, 469)
        Me.INT_G_S_10.Name = "INT_G_S_10"
        Me.INT_G_S_10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.INT_G_S_10.Size = New System.Drawing.Size(17, 19)
        Me.INT_G_S_10.TabIndex = 119
        Me.INT_G_S_10.TabStop = False
        '
        'Button12
        '
        Me.Button12.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button12.Location = New System.Drawing.Point(560, 476)
        Me.Button12.Name = "Button12"
        Me.Button12.Size = New System.Drawing.Size(120, 32)
        Me.Button12.TabIndex = 155
        Me.Button12.Text = "Continuous start"
        '
        'Button13
        '
        Me.Button13.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Button13.Location = New System.Drawing.Point(560, 516)
        Me.Button13.Name = "Button13"
        Me.Button13.Size = New System.Drawing.Size(120, 32)
        Me.Button13.TabIndex = 156
        Me.Button13.Text = "Continuous stop"
        '
        'CMP_STS
        '
        Me.CMP_STS.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.CMP_STS.Location = New System.Drawing.Point(826, 316)
        Me.CMP_STS.Name = "CMP_STS"
        Me.CMP_STS.Size = New System.Drawing.Size(48, 27)
        Me.CMP_STS.TabIndex = 157
        Me.CMP_STS.Text = "0"
        '
        'Label2
        '
        Me.Label2.BackColor = System.Drawing.SystemColors.Control
        Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label2.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label2.Location = New System.Drawing.Point(370, 158)
        Me.Label2.Name = "Label2"
        Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label2.Size = New System.Drawing.Size(172, 19)
        Me.Label2.TabIndex = 158
        Me.Label2.Text = "Bit 0: Digital Input 0 falling dege"
        '
        'Label5
        '
        Me.Label5.BackColor = System.Drawing.SystemColors.Control
        Me.Label5.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label5.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label5.Location = New System.Drawing.Point(370, 198)
        Me.Label5.Name = "Label5"
        Me.Label5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label5.Size = New System.Drawing.Size(172, 19)
        Me.Label5.TabIndex = 159
        Me.Label5.Text = "Bit 1: Digital Input 1 falling dege"
        '
        'Label6
        '
        Me.Label6.BackColor = System.Drawing.SystemColors.Control
        Me.Label6.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label6.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label6.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label6.Location = New System.Drawing.Point(370, 243)
        Me.Label6.Name = "Label6"
        Me.Label6.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label6.Size = New System.Drawing.Size(172, 14)
        Me.Label6.TabIndex = 160
        Me.Label6.Text = "Bit 2: Digital Input 2 falling dege"
        '
        'Label18
        '
        Me.Label18.BackColor = System.Drawing.SystemColors.Control
        Me.Label18.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label18.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label18.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label18.Location = New System.Drawing.Point(370, 286)
        Me.Label18.Name = "Label18"
        Me.Label18.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label18.Size = New System.Drawing.Size(172, 18)
        Me.Label18.TabIndex = 161
        Me.Label18.Text = "Bit 3: Digital Input 3 falling dege"
        '
        'Label19
        '
        Me.Label19.BackColor = System.Drawing.SystemColors.Control
        Me.Label19.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label19.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label19.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label19.Location = New System.Drawing.Point(370, 329)
        Me.Label19.Name = "Label19"
        Me.Label19.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label19.Size = New System.Drawing.Size(172, 18)
        Me.Label19.TabIndex = 162
        Me.Label19.Text = "Bit 4: Digital Input 0 rising dege"
        '
        'Label20
        '
        Me.Label20.BackColor = System.Drawing.SystemColors.Control
        Me.Label20.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label20.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label20.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label20.Location = New System.Drawing.Point(368, 370)
        Me.Label20.Name = "Label20"
        Me.Label20.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label20.Size = New System.Drawing.Size(174, 19)
        Me.Label20.TabIndex = 163
        Me.Label20.Text = "Bit 5: Digital Input 1 rising dege"
        '
        'Label21
        '
        Me.Label21.BackColor = System.Drawing.SystemColors.Control
        Me.Label21.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label21.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label21.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label21.Location = New System.Drawing.Point(370, 413)
        Me.Label21.Name = "Label21"
        Me.Label21.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label21.Size = New System.Drawing.Size(172, 16)
        Me.Label21.TabIndex = 164
        Me.Label21.Text = "Bit 6: Digital Input 2 rising dege"
        '
        'Label22
        '
        Me.Label22.BackColor = System.Drawing.SystemColors.Control
        Me.Label22.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label22.Font = New System.Drawing.Font("Times New Roman", 9.0!)
        Me.Label22.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label22.Location = New System.Drawing.Point(370, 451)
        Me.Label22.Name = "Label22"
        Me.Label22.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label22.Size = New System.Drawing.Size(172, 15)
        Me.Label22.TabIndex = 165
        Me.Label22.Text = "Bit 7: Digital Input 3 rising dege"
        '
        'Label23
        '
        Me.Label23.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label23.Location = New System.Drawing.Point(824, 352)
        Me.Label23.Name = "Label23"
        Me.Label23.Size = New System.Drawing.Size(47, 19)
        Me.Label23.TabIndex = 166
        Me.Label23.Text = "DistX"
        '
        'Label24
        '
        Me.Label24.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label24.Location = New System.Drawing.Point(824, 380)
        Me.Label24.Name = "Label24"
        Me.Label24.Size = New System.Drawing.Size(47, 23)
        Me.Label24.TabIndex = 167
        Me.Label24.Text = "DistY"
        '
        'Label25
        '
        Me.Label25.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label25.Location = New System.Drawing.Point(807, 432)
        Me.Label25.Name = "Label25"
        Me.Label25.Size = New System.Drawing.Size(60, 24)
        Me.Label25.TabIndex = 168
        Me.Label25.Text = "CenterX"
        '
        'Label26
        '
        Me.Label26.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label26.Location = New System.Drawing.Point(807, 459)
        Me.Label26.Name = "Label26"
        Me.Label26.Size = New System.Drawing.Size(60, 24)
        Me.Label26.TabIndex = 169
        Me.Label26.Text = "CenterY"
        '
        'Label27
        '
        Me.Label27.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label27.Location = New System.Drawing.Point(834, 290)
        Me.Label27.Name = "Label27"
        Me.Label27.Size = New System.Drawing.Size(37, 23)
        Me.Label27.TabIndex = 170
        Me.Label27.Text = "Dist"
        '
        'Label28
        '
        Me.Label28.Font = New System.Drawing.Font("新細明體", 12.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(136, Byte))
        Me.Label28.Location = New System.Drawing.Point(738, 319)
        Me.Label28.Name = "Label28"
        Me.Label28.Size = New System.Drawing.Size(86, 17)
        Me.Label28.TabIndex = 171
        Me.Label28.Text = "GCMP_STS"
        '
        'Form1
        '
        Me.AutoScaleBaseSize = New System.Drawing.Size(5, 15)
        Me.ClientSize = New System.Drawing.Size(992, 566)
        Me.Controls.Add(Me.Label28)
        Me.Controls.Add(Me.Label27)
        Me.Controls.Add(Me.Label26)
        Me.Controls.Add(Me.Label25)
        Me.Controls.Add(Me.Label24)
        Me.Controls.Add(Me.Label23)
        Me.Controls.Add(Me.Label22)
        Me.Controls.Add(Me.Label21)
        Me.Controls.Add(Me.Label20)
        Me.Controls.Add(Me.Label19)
        Me.Controls.Add(Me.Label18)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.CMP_STS)
        Me.Controls.Add(Me.Button13)
        Me.Controls.Add(Me.Button12)
        Me.Controls.Add(Me.INT_G_E_0)
        Me.Controls.Add(Me.INT_G_E_1)
        Me.Controls.Add(Me.INT_G_E_2)
        Me.Controls.Add(Me.INT_G_E_4)
        Me.Controls.Add(Me.INT_G_E_5)
        Me.Controls.Add(Me.INT_G_E_6)
        Me.Controls.Add(Me.INT_G_E_7)
        Me.Controls.Add(Me.INT_G_E_10)
        Me.Controls.Add(Me.INT_G_B_0)
        Me.Controls.Add(Me.INT_G_B_1)
        Me.Controls.Add(Me.INT_G_B_2)
        Me.Controls.Add(Me.INT_G_B_4)
        Me.Controls.Add(Me.INT_G_B_5)
        Me.Controls.Add(Me.INT_G_B_6)
        Me.Controls.Add(Me.INT_G_B_7)
        Me.Controls.Add(Me.INT_G_B_10)
        Me.Controls.Add(Me.INT_G_S_0)
        Me.Controls.Add(Me.INT_G_S_1)
        Me.Controls.Add(Me.INT_G_S_2)
        Me.Controls.Add(Me.INT_G_S_4)
        Me.Controls.Add(Me.INT_G_S_5)
        Me.Controls.Add(Me.INT_G_S_6)
        Me.Controls.Add(Me.INT_G_S_7)
        Me.Controls.Add(Me.INT_G_S_10)
        Me.Controls.Add(Me.INT_N_E_16)
        Me.Controls.Add(Me.INT_N_E_15)
        Me.Controls.Add(Me.INT_N_E_0)
        Me.Controls.Add(Me.INT_N_E_1)
        Me.Controls.Add(Me.INT_N_E_2)
        Me.Controls.Add(Me.INT_N_E_4)
        Me.Controls.Add(Me.INT_N_E_5)
        Me.Controls.Add(Me.INT_N_E_6)
        Me.Controls.Add(Me.INT_N_E_7)
        Me.Controls.Add(Me.INT_N_E_10)
        Me.Controls.Add(Me.INT_N_E_11)
        Me.Controls.Add(Me.INT_N_E_12)
        Me.Controls.Add(Me.INT_N_E_14)
        Me.Controls.Add(Me.INT_N_B_16)
        Me.Controls.Add(Me.INT_N_B_15)
        Me.Controls.Add(Me.INT_N_B_0)
        Me.Controls.Add(Me.INT_N_B_1)
        Me.Controls.Add(Me.INT_N_B_2)
        Me.Controls.Add(Me.INT_N_B_4)
        Me.Controls.Add(Me.INT_N_B_5)
        Me.Controls.Add(Me.INT_N_B_6)
        Me.Controls.Add(Me.INT_N_B_7)
        Me.Controls.Add(Me.INT_N_B_10)
        Me.Controls.Add(Me.INT_N_B_11)
        Me.Controls.Add(Me.INT_N_B_12)
        Me.Controls.Add(Me.INT_N_B_14)
        Me.Controls.Add(Me.INT_N_S_16)
        Me.Controls.Add(Me.INT_N_S_15)
        Me.Controls.Add(Me.INT_N_S_0)
        Me.Controls.Add(Me.INT_N_S_1)
        Me.Controls.Add(Me.INT_N_S_2)
        Me.Controls.Add(Me.INT_N_S_4)
        Me.Controls.Add(Me.INT_N_S_5)
        Me.Controls.Add(Me.INT_N_S_6)
        Me.Controls.Add(Me.INT_N_S_7)
        Me.Controls.Add(Me.INT_N_S_10)
        Me.Controls.Add(Me.INT_N_S_11)
        Me.Controls.Add(Me.INT_N_S_12)
        Me.Controls.Add(Me.INT_N_S_14)
        Me.Controls.Add(Me.grp_chk_int_factor)
        Me.Controls.Add(Me.GroupBox5)
        Me.Controls.Add(Me.Button7)
        Me.Controls.Add(Me.Button8)
        Me.Controls.Add(Me.ARC_CMD_1)
        Me.Controls.Add(Me.ARC_CMD_0)
        Me.Controls.Add(Me.Button9)
        Me.Controls.Add(Me.LINE_CMD_1)
        Me.Controls.Add(Me.LINE_CMD_0)
        Me.Controls.Add(Me.Button10)
        Me.Controls.Add(Me.CheckBox1)
        Me.Controls.Add(Me.PTP_CMD)
        Me.Controls.Add(Me.PTP_AXIS)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.Button11)
        Me.Controls.Add(Me.GroupBox4)
        Me.Controls.Add(Me.GroupBox3)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.intFlag)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.TimeOut_ms)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Button6)
        Me.Controls.Add(Me.Button4)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.card_id)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Button1)
        Me.Name = "Form1"
        Me.Text = "8102_Interrupt_function"
        Me.GroupBox5.ResumeLayout(False)
        Me.GroupBox5.PerformLayout()
        Me.GroupBox4.ResumeLayout(False)
        Me.GroupBox4.PerformLayout()
        Me.GroupBox3.ResumeLayout(False)
        Me.GroupBox3.PerformLayout()
        Me.GroupBox2.ResumeLayout(False)
        Me.GroupBox2.PerformLayout()
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        Me.grp_chk_int_factor.ResumeLayout(False)
        CType(Me.INT_N_S_0, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_5, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_6, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_7, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_10, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_11, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_12, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_14, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_15, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_S_16, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_16, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_15, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_0, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_5, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_6, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_7, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_10, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_11, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_12, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_B_14, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_16, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_15, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_0, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_5, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_6, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_7, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_10, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_11, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_12, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_N_E_14, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_0, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_5, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_6, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_7, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_E_10, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_0, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_5, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_6, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_7, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_B_10, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_0, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_5, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_6, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_7, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.INT_G_S_10, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

#End Region
    Dim CardNo As Integer
    Dim AxisNo As Integer
    Dim TotalCard As Integer


    Public MAX_CARDS_PCI_8102 As Integer = 0
    Public CARDS_PCI_8102_Status(16) As Boolean

    Dim int_factor As Integer

    'Dim bol_INT_E_0 As Boolean = False

    Dim bol_INT_N_0 As Boolean = False
    Dim bol_INT_N_1 As Boolean = False
    Dim bol_INT_N_2 As Boolean = False
    Dim bol_INT_N_4 As Boolean = False
    Dim bol_INT_N_5 As Boolean = False
    Dim bol_INT_N_6 As Boolean = False
    Dim bol_INT_N_7 As Boolean = False
    Dim bol_INT_N_10 As Boolean = False
    Dim bol_INT_N_11 As Boolean = False
    Dim bol_INT_N_12 As Boolean = False
    Dim bol_INT_N_14 As Boolean = False
    Dim bol_INT_N_15 As Boolean = False
    Dim bol_INT_N_16 As Boolean = False

    Dim bol_INT_G_0 As Boolean = False
    Dim bol_INT_G_1 As Boolean = False
    Dim bol_INT_G_2 As Boolean = False
    Dim bol_INT_G_4 As Boolean = False
    Dim bol_INT_G_5 As Boolean = False
    Dim bol_INT_G_6 As Boolean = False
    Dim bol_INT_G_7 As Boolean = False
    Dim bol_INT_G_10 As Boolean = False
    'Dim bol_INT_G_11 As Boolean = False
    'Dim bol_INT_G_12 As Boolean = False
    'Dim bol_INT_G_14 As Boolean = False
    'Dim bol_INT_G_15 As Boolean = False
    'Dim bol_INT_G_16 As Boolean = False


    'Dim ret_INT_E_0 As Integer = 1000

    Dim ret_INT_N_0 As Integer = 1000
    Dim ret_INT_N_1 As Integer = 1000
    Dim ret_INT_N_2 As Integer = 1000
    Dim ret_INT_N_4 As Integer = 1000
    Dim ret_INT_N_5 As Integer = 1000
    Dim ret_INT_N_6 As Integer = 1000
    Dim ret_INT_N_7 As Integer = 1000
    Dim ret_INT_N_10 As Integer = 1000
    Dim ret_INT_N_11 As Integer = 1000
    Dim ret_INT_N_12 As Integer = 1000
    Dim ret_INT_N_14 As Integer = 1000
    Dim ret_INT_N_15 As Integer = 1000
    Dim ret_INT_N_16 As Integer = 1000

    Dim ret_INT_G_0 As Integer = 1000
    Dim ret_INT_G_1 As Integer = 1000
    Dim ret_INT_G_2 As Integer = 1000
    Dim ret_INT_G_4 As Integer = 1000
    Dim ret_INT_G_5 As Integer = 1000
    Dim ret_INT_G_6 As Integer = 1000
    Dim ret_INT_G_7 As Integer = 1000
    Dim ret_INT_G_10 As Integer = 1000
    'Dim ret_INT_G_11 As Integer = 1000
    'Dim ret_INT_G_12 As Integer = 1000
    'Dim ret_INT_G_14 As Integer = 1000
    'Dim ret_INT_G_15 As Integer = 1000
    'Dim ret_INT_G_16 As Integer = 1000


    'Dim Trd_INT_E_0 As New System.Threading.Thread(AddressOf Thread_INT_E_0)

    Dim Trd_INT_N_0 As New System.Threading.Thread(AddressOf Thread_INT_N_0)
    Dim Trd_INT_N_1 As New System.Threading.Thread(AddressOf Thread_INT_N_1)
    Dim Trd_INT_N_2 As New System.Threading.Thread(AddressOf Thread_INT_N_2)
    Dim Trd_INT_N_4 As New System.Threading.Thread(AddressOf Thread_INT_N_4)
    Dim Trd_INT_N_5 As New System.Threading.Thread(AddressOf Thread_INT_N_5)
    Dim Trd_INT_N_6 As New System.Threading.Thread(AddressOf Thread_INT_N_6)
    Dim Trd_INT_N_7 As New System.Threading.Thread(AddressOf Thread_INT_N_7)
    Dim Trd_INT_N_10 As New System.Threading.Thread(AddressOf Thread_INT_N_10)
    Dim Trd_INT_N_11 As New System.Threading.Thread(AddressOf Thread_INT_N_11)
    Dim Trd_INT_N_12 As New System.Threading.Thread(AddressOf Thread_INT_N_12)
    Dim Trd_INT_N_14 As New System.Threading.Thread(AddressOf Thread_INT_N_14)
    Dim Trd_INT_N_15 As New System.Threading.Thread(AddressOf Thread_INT_N_15)
    Dim Trd_INT_N_16 As New System.Threading.Thread(AddressOf Thread_INT_N_16)

    Dim Trd_INT_G_0 As New System.Threading.Thread(AddressOf Thread_INT_G_0)
    Dim Trd_INT_G_1 As New System.Threading.Thread(AddressOf Thread_INT_G_1)
    Dim Trd_INT_G_2 As New System.Threading.Thread(AddressOf Thread_INT_G_2)
    Dim Trd_INT_G_4 As New System.Threading.Thread(AddressOf Thread_INT_G_4)
    Dim Trd_INT_G_5 As New System.Threading.Thread(AddressOf Thread_INT_G_5)
    Dim Trd_INT_G_6 As New System.Threading.Thread(AddressOf Thread_INT_G_6)
    Dim Trd_INT_G_7 As New System.Threading.Thread(AddressOf Thread_INT_G_7)
    Dim Trd_INT_G_10 As New System.Threading.Thread(AddressOf Thread_INT_G_10)
    'Dim Trd_INT_G_11 As New System.Threading.Thread(AddressOf Thread_INT_G_11)
    'Dim Trd_INT_G_12 As New System.Threading.Thread(AddressOf Thread_INT_G_12)
    'Dim Trd_INT_G_14 As New System.Threading.Thread(AddressOf Thread_INT_G_14)
    'Dim Trd_INT_G_15 As New System.Threading.Thread(AddressOf Thread_INT_G_15)
    'Dim Trd_INT_G_16 As New System.Threading.Thread(AddressOf Thread_INT_G_16)


    'Dim i_INT_E_0 As Integer = 0

    Dim i_INT_N_0 As Integer = 0
    Dim i_INT_N_1 As Integer = 0
    Dim i_INT_N_2 As Integer = 0
    Dim i_INT_N_4 As Integer = 0
    Dim i_INT_N_5 As Integer = 0
    Dim i_INT_N_6 As Integer = 0
    Dim i_INT_N_7 As Integer = 0
    Dim i_INT_N_10 As Integer = 0
    Dim i_INT_N_11 As Integer = 0
    Dim i_INT_N_12 As Integer = 0
    Dim i_INT_N_14 As Integer = 0
    Dim i_INT_N_15 As Integer = 0
    Dim i_INT_N_16 As Integer = 0

    Dim i_INT_G_0 As Integer = 0
    Dim i_INT_G_1 As Integer = 0
    Dim i_INT_G_2 As Integer = 0
    Dim i_INT_G_4 As Integer = 0
    Dim i_INT_G_5 As Integer = 0
    Dim i_INT_G_6 As Integer = 0
    Dim i_INT_G_7 As Integer = 0
    Dim i_INT_G_10 As Integer = 0
    'Dim i_INT_G_11 As Integer = 0
    'Dim i_INT_G_12 As Integer = 0
    'Dim i_INT_G_14 As Integer = 0
    'Dim i_INT_G_15 As Integer = 0
    'Dim i_INT_G_16 As Integer = 0



    Dim retint As Integer

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

        'Trd_INT_E_0.Start()

        Trd_INT_N_0.Start()
        Trd_INT_N_1.Start()
        Trd_INT_N_2.Start()
        Trd_INT_N_4.Start()
        Trd_INT_N_5.Start()
        Trd_INT_N_6.Start()
        Trd_INT_N_7.Start()
        Trd_INT_N_10.Start()
        Trd_INT_N_11.Start()
        Trd_INT_N_12.Start()
        Trd_INT_N_14.Start()
        Trd_INT_N_15.Start()
        Trd_INT_N_16.Start()

        Trd_INT_G_0.Start()
        Trd_INT_G_1.Start()
        Trd_INT_G_2.Start()
        Trd_INT_G_4.Start()
        Trd_INT_G_5.Start()
        Trd_INT_G_6.Start()
        Trd_INT_G_7.Start()
        Trd_INT_G_10.Start()
        'Trd_INT_G_11.Start()
        'Trd_INT_G_12.Start()
        'Trd_INT_G_14.Start()
        'Trd_INT_G_15.Start()
        'Trd_INT_G_16.Start()

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

        'Trd_INT_E_0.Abort()

        Trd_INT_N_0.Abort()
        Trd_INT_N_1.Abort()
        Trd_INT_N_2.Abort()
        Trd_INT_N_4.Abort()
        Trd_INT_N_5.Abort()
        Trd_INT_N_6.Abort()
        Trd_INT_N_7.Abort()
        Trd_INT_N_10.Abort()
        Trd_INT_N_11.Abort()
        Trd_INT_N_12.Abort()
        Trd_INT_N_14.Abort()
        Trd_INT_N_15.Abort()
        Trd_INT_N_16.Abort()

        Trd_INT_G_0.Abort()
        Trd_INT_G_1.Abort()
        Trd_INT_G_2.Abort()
        Trd_INT_G_4.Abort()
        Trd_INT_G_5.Abort()
        Trd_INT_G_6.Abort()
        Trd_INT_G_7.Abort()
        Trd_INT_G_10.Abort()
        'Trd_INT_G_11.Abort()
        'Trd_INT_G_12.Abort()
        'Trd_INT_G_14.Abort()
        'Trd_INT_G_15.Abort()
        'Trd_INT_G_16.Abort()


        'B_8102_close()
        APS_close()
    End Sub


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        'B_8102_int_control(CInt(card_id.Text), CInt(intFlag.Text))

        APS_int_enable(CInt(card_id.Text), CInt(intFlag.Text))

        'i_INT_E_0 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2, 11, 1) 'General comparator is ON


    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click


        'Dim temp As Integer

        'If grp_chk_int_factor_0.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 0)
        'ElseIf grp_chk_int_factor_0.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 0
        '    i_INT_G_0 = APS_set_int_factor(CInt(card_id.Text), 4, 0, 1)
        'End If

        'If grp_chk_int_factor_1.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 1)
        'ElseIf grp_chk_int_factor_1.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 1
        '    i_INT_G_1 = APS_set_int_factor(CInt(card_id.Text), 4, 1, 1)
        'End If

        'If grp_chk_int_factor_2.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 2)
        'ElseIf grp_chk_int_factor_2.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 2
        '    i_INT_G_2 = APS_set_int_factor(CInt(card_id.Text), 4, 2, 1)
        'End If

        'If grp_chk_int_factor_4.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 4)
        'ElseIf grp_chk_int_factor_4.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 4
        '    i_INT_G_4 = APS_set_int_factor(CInt(card_id.Text), 4, 4, 1)
        'End If

        'If grp_chk_int_factor_5.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 5)
        'ElseIf grp_chk_int_factor_5.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 5
        '    i_INT_G_5 = APS_set_int_factor(CInt(card_id.Text), 4, 5, 1)
        'End If

        'If grp_chk_int_factor_6.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 6)
        'ElseIf grp_chk_int_factor_6.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 6
        '    i_INT_G_6 = APS_set_int_factor(CInt(card_id.Text), 4, 6, 1)
        'End If

        'If grp_chk_int_factor_7.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 7)
        'ElseIf grp_chk_int_factor_7.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 7
        '    i_INT_G_7 = APS_set_int_factor(CInt(card_id.Text), 4, 7, 1)
        'End If

        'If grp_chk_int_factor_10.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 10)
        'ElseIf grp_chk_int_factor_10.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 10
        '    i_INT_G_10 = APS_set_int_factor(CInt(card_id.Text), 4, 10, 1)
        'End If

        'If grp_chk_int_factor_11.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 11)
        'ElseIf grp_chk_int_factor_11.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 11
        '    i_INT_G_11 = APS_set_int_factor(CInt(card_id.Text), 4, 11, 1)
        'End If

        'If grp_chk_int_factor_12.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 12)
        'ElseIf grp_chk_int_factor_12.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 12
        '    i_INT_G_12 = APS_set_int_factor(CInt(card_id.Text), 4, 12, 1)
        'End If

        'If grp_chk_int_factor_14.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 14)
        'ElseIf grp_chk_int_factor_14.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 14
        '    i_INT_G_14 = APS_set_int_factor(CInt(card_id.Text), 4, 14, 1)
        'End If

        'If grp_chk_int_factor_15.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 15)
        'ElseIf grp_chk_int_factor_15.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 15
        '    i_INT_G_15 = APS_set_int_factor(CInt(card_id.Text), 4, 15, 1)
        'End If

        'If grp_chk_int_factor_16.CheckState = 0 Then
        '    int_factor = int_factor - CInt(int_factor And 2 ^ 16)
        'ElseIf grp_chk_int_factor_16.CheckState = 1 Then
        '    int_factor = int_factor Or 2 ^ 16
        '    i_INT_G_16 = APS_set_int_factor(CInt(card_id.Text), 4, 16, 1)
        'End If


        i_INT_G_0 = APS_set_int_factor(CInt(card_id.Text), 4, 0, 1)
        i_INT_G_1 = APS_set_int_factor(CInt(card_id.Text), 4, 1, 1)
        i_INT_G_2 = APS_set_int_factor(CInt(card_id.Text), 4, 2, 1)
        i_INT_G_4 = APS_set_int_factor(CInt(card_id.Text), 4, 3, 1)
        i_INT_G_5 = APS_set_int_factor(CInt(card_id.Text), 4, 4, 1)
        i_INT_G_6 = APS_set_int_factor(CInt(card_id.Text), 4, 5, 1)
        i_INT_G_7 = APS_set_int_factor(CInt(card_id.Text), 4, 6, 1)
        i_INT_G_10 = APS_set_int_factor(CInt(card_id.Text), 4, 7, 1)

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click

        'retint = B_8102_wait_gpio_interrupt(CInt(card_id.Text), CInt(IntFactorBitNo.Text), CInt(TimeOut_ms.Text))
        'MsgBox("wait_gpio_interrupt=" & retint)

        'ret_INT_G_0 = 1000
        'ret_INT_G_1 = 1000
        'ret_INT_G_2 = 1000
        'ret_INT_G_4 = 1000
        'ret_INT_G_5 = 1000
        'ret_INT_G_6 = 1000
        'ret_INT_G_7 = 1000
        'ret_INT_G_10 = 1000
        'ret_INT_G_11 = 1000
        'ret_INT_G_12 = 1000
        'ret_INT_G_14 = 1000
        'ret_INT_G_15 = 1000
        'ret_INT_G_16 = 1000


        'If grp_chk_int_factor_0.CheckState = 1 Then bol_INT_G_0 = True
        'If grp_chk_int_factor_1.CheckState = 1 Then bol_INT_G_1 = True
        'If grp_chk_int_factor_2.CheckState = 1 Then bol_INT_G_2 = True
        'If grp_chk_int_factor_4.CheckState = 1 Then bol_INT_G_4 = True
        'If grp_chk_int_factor_5.CheckState = 1 Then bol_INT_G_5 = True
        'If grp_chk_int_factor_6.CheckState = 1 Then bol_INT_G_6 = True
        'If grp_chk_int_factor_7.CheckState = 1 Then bol_INT_G_7 = True
        'If grp_chk_int_factor_10.CheckState = 1 Then bol_INT_G_10 = True
        'If grp_chk_int_factor_11.CheckState = 1 Then bol_INT_G_11 = True
        'If grp_chk_int_factor_12.CheckState = 1 Then bol_INT_G_12 = True
        'If grp_chk_int_factor_14.CheckState = 1 Then bol_INT_G_14 = True
        'If grp_chk_int_factor_15.CheckState = 1 Then bol_INT_G_15 = True
        'If grp_chk_int_factor_16.CheckState = 1 Then bol_INT_G_16 = True

        bol_INT_G_0 = True
        bol_INT_G_1 = True
        bol_INT_G_2 = True
        bol_INT_G_4 = True
        bol_INT_G_5 = True
        bol_INT_G_6 = True
        bol_INT_G_7 = True
        bol_INT_G_10 = True

        Check_Color()


    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click

        'Dim temp As Integer

        If grp_chk_int_factor_0.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 0)
        ElseIf grp_chk_int_factor_0.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 0
            i_INT_N_0 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 0, 1)
        End If

        If grp_chk_int_factor_1.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 1)
        ElseIf grp_chk_int_factor_1.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 1
            i_INT_N_1 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 1, 1)
        End If

        If grp_chk_int_factor_2.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 2)
        ElseIf grp_chk_int_factor_2.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 2
            i_INT_N_2 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 2, 1)
        End If

        If grp_chk_int_factor_4.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 4)
        ElseIf grp_chk_int_factor_4.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 4
            i_INT_N_4 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 4, 1)
        End If

        If grp_chk_int_factor_5.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 5)
        ElseIf grp_chk_int_factor_5.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 5
            i_INT_N_5 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 5, 1)
        End If

        If grp_chk_int_factor_6.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 6)
        ElseIf grp_chk_int_factor_6.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 6
            i_INT_N_6 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 6, 1)
        End If

        If grp_chk_int_factor_7.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 7)
        ElseIf grp_chk_int_factor_7.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 7
            i_INT_N_7 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 7, 1)
        End If

        If grp_chk_int_factor_10.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 10)
        ElseIf grp_chk_int_factor_10.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 10
            i_INT_N_10 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 10, 1)
        End If

        If grp_chk_int_factor_11.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 11)
        ElseIf grp_chk_int_factor_11.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 11
            i_INT_N_11 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 11, 1)
        End If

        If grp_chk_int_factor_12.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 12)
        ElseIf grp_chk_int_factor_12.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 12
            i_INT_N_12 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 12, 1)
        End If

        If grp_chk_int_factor_14.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 14)
        ElseIf grp_chk_int_factor_14.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 14
            i_INT_N_14 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 14, 1)
        End If

        If grp_chk_int_factor_15.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 15)
        ElseIf grp_chk_int_factor_15.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 15
            i_INT_N_15 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 15, 1)
        End If

        If grp_chk_int_factor_16.CheckState = 0 Then
            int_factor = int_factor - CInt(int_factor And 2 ^ 16)
        ElseIf grp_chk_int_factor_16.CheckState = 1 Then
            int_factor = int_factor Or 2 ^ 16
            i_INT_N_16 = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2 + 1, 16, 1)
        End If

        'B_8102_set_motion_int_factor(CInt(PTP_AXIS.Text), int_factor)

        'Int_No = APS_set_int_factor(CInt(card_id.Text), CInt(PTP_AXIS.Text) * 2, 0, 1)

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        'retint = B_8102_wait_error_interrupt(CInt(PTP_AXIS.Text), CInt(TimeOut_ms.Text))
        'MsgBox("wait_error_interrupt=" & retint)

        'ret_INT_E_0 = 1000

        'bol_INT_E_0 = True

        Check_Color()


    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click

        'retint = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), CInt(IntFactorBitNo.Text), CInt(TimeOut_ms.Text))
        'MsgBox("wait_normal_interrupt=" & retint)

        'ret_INT_N_0 = 1000
        'ret_INT_N_1 = 1000
        'ret_INT_N_2 = 1000
        'ret_INT_N_4 = 1000
        'ret_INT_N_5 = 1000
        'ret_INT_N_6 = 1000
        'ret_INT_N_7 = 1000
        'ret_INT_N_10 = 1000
        'ret_INT_N_11 = 1000
        'ret_INT_N_12 = 1000
        'ret_INT_N_14 = 1000
        'ret_INT_N_15 = 1000
        'ret_INT_N_16 = 1000

        If grp_chk_int_factor_0.CheckState = 1 Then bol_INT_N_0 = True
        If grp_chk_int_factor_1.CheckState = 1 Then bol_INT_N_1 = True
        If grp_chk_int_factor_2.CheckState = 1 Then bol_INT_N_2 = True
        If grp_chk_int_factor_4.CheckState = 1 Then bol_INT_N_4 = True
        If grp_chk_int_factor_5.CheckState = 1 Then bol_INT_N_5 = True
        If grp_chk_int_factor_6.CheckState = 1 Then bol_INT_N_6 = True
        If grp_chk_int_factor_7.CheckState = 1 Then bol_INT_N_7 = True
        If grp_chk_int_factor_10.CheckState = 1 Then bol_INT_N_10 = True
        If grp_chk_int_factor_11.CheckState = 1 Then bol_INT_N_11 = True
        If grp_chk_int_factor_12.CheckState = 1 Then bol_INT_N_12 = True
        If grp_chk_int_factor_14.CheckState = 1 Then bol_INT_N_14 = True
        If grp_chk_int_factor_15.CheckState = 1 Then bol_INT_N_15 = True
        If grp_chk_int_factor_16.CheckState = 1 Then bol_INT_N_16 = True

        Check_Color()

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


        Check_Color()





    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
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

            APS_set_axis_param(AxisNo, 550, 5)     'PRA_GCMP_EN  0x226
            APS_set_axis_param(AxisNo, 551, 30000) 'PRA_GCMP_POS 0x227
            APS_set_axis_param(AxisNo, 552, 0)     'PRA_GCMP_SRC 0x228


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

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
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

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
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

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
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

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
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



    'Sub Thread_INT_E_0()

    '    While 1


    '        If bol_INT_E_0 = True Then
    '            ret_INT_E_0 = 1000
    '            'ret_INT_E_0 = B_8102_wait_error_interrupt(CInt(PTP_AXIS.Text), CInt(TimeOut_ms.Text))
    '            ret_INT_E_0 = APS_wait_single_int(i_INT_E_0, CInt(TimeOut_ms.Text))
    '            bol_INT_E_0 = False
    '            APS_reset_int(i_INT_E_0)
    '        End If


    '        Sleep(50)
    '    End While

    'End Sub

    Sub Thread_INT_N_0()

        While 1


            If bol_INT_N_0 = True Then
                ret_INT_N_0 = 1000
                'ret_INT_N_0 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 0, CInt(TimeOut_ms.Text))
                ret_INT_N_0 = APS_wait_single_int(i_INT_N_0, CInt(TimeOut_ms.Text))
                bol_INT_N_0 = False
                APS_reset_int(i_INT_N_0)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_1()

        While 1


            If bol_INT_N_1 = True Then
                ret_INT_N_1 = 1000
                'ret_INT_N_1 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 1, CInt(TimeOut_ms.Text))
                ret_INT_N_1 = APS_wait_single_int(i_INT_N_1, CInt(TimeOut_ms.Text))
                bol_INT_N_1 = False
                APS_reset_int(i_INT_N_1)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_2()

        While 1


            If bol_INT_N_2 = True Then
                ret_INT_N_2 = 1000
                'ret_INT_N_2 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 2, CInt(TimeOut_ms.Text))
                ret_INT_N_2 = APS_wait_single_int(i_INT_N_2, CInt(TimeOut_ms.Text))
                bol_INT_N_2 = False
                APS_reset_int(i_INT_N_2)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_4()

        While 1


            If bol_INT_N_4 = True Then
                ret_INT_N_4 = 1000
                'ret_INT_N_4 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 4, CInt(TimeOut_ms.Text))
                ret_INT_N_4 = APS_wait_single_int(i_INT_N_4, CInt(TimeOut_ms.Text))
                bol_INT_N_4 = False
                APS_reset_int(i_INT_N_4)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_5()

        While 1


            If bol_INT_N_5 = True Then
                ret_INT_N_5 = 1000
                'ret_INT_N_5 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 5, CInt(TimeOut_ms.Text))
                ret_INT_N_5 = APS_wait_single_int(i_INT_N_5, CInt(TimeOut_ms.Text))
                bol_INT_N_5 = False
                APS_reset_int(i_INT_N_5)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_6()

        While 1


            If bol_INT_N_6 = True Then
                ret_INT_N_6 = 1000
                'ret_INT_N_6 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 6, CInt(TimeOut_ms.Text))
                ret_INT_N_6 = APS_wait_single_int(i_INT_N_6, CInt(TimeOut_ms.Text))
                bol_INT_N_6 = False
                APS_reset_int(i_INT_N_6)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_7()

        While 1


            If bol_INT_N_7 = True Then
                ret_INT_N_7 = 1000
                'ret_INT_N_7 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 7, CInt(TimeOut_ms.Text))
                ret_INT_N_7 = APS_wait_single_int(i_INT_N_7, CInt(TimeOut_ms.Text))
                bol_INT_N_7 = False
                APS_reset_int(i_INT_N_7)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_10()

        While 1


            If bol_INT_N_10 = True Then
                ret_INT_N_10 = 1000
                'ret_INT_N_10 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 10, CInt(TimeOut_ms.Text))
                ret_INT_N_10 = APS_wait_single_int(i_INT_N_10, CInt(TimeOut_ms.Text))
                bol_INT_N_10 = False
                APS_reset_int(i_INT_N_10)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_11()

        While 1


            If bol_INT_N_11 = True Then
                ret_INT_N_11 = 1000
                'ret_INT_N_11 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 11, CInt(TimeOut_ms.Text))
                ret_INT_N_11 = APS_wait_single_int(i_INT_N_11, CInt(TimeOut_ms.Text))
                bol_INT_N_11 = False
                APS_reset_int(i_INT_N_11)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_12()

        While 1


            If bol_INT_N_12 = True Then
                ret_INT_N_12 = 1000
                'ret_INT_N_12 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 12, CInt(TimeOut_ms.Text))
                ret_INT_N_12 = APS_wait_single_int(i_INT_N_12, CInt(TimeOut_ms.Text))
                bol_INT_N_12 = False
                APS_reset_int(i_INT_N_12)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_14()

        While 1


            If bol_INT_N_14 = True Then
                ret_INT_N_14 = 1000
                'ret_INT_N_14 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 14, CInt(TimeOut_ms.Text))
                ret_INT_N_14 = APS_wait_single_int(i_INT_N_14, CInt(TimeOut_ms.Text))
                bol_INT_N_14 = False
                APS_reset_int(i_INT_N_14)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_15()

        While 1


            If bol_INT_N_15 = True Then
                ret_INT_N_15 = 1000
                'ret_INT_N_15 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 15, CInt(TimeOut_ms.Text))
                ret_INT_N_15 = APS_wait_single_int(i_INT_N_15, CInt(TimeOut_ms.Text))
                bol_INT_N_15 = False
                APS_reset_int(i_INT_N_15)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_N_16()

        While 1


            If bol_INT_N_16 = True Then
                ret_INT_N_16 = 1000
                'ret_INT_N_16 = B_8102_wait_motion_interrupt(CInt(PTP_AXIS.Text), 16, CInt(TimeOut_ms.Text))
                ret_INT_N_16 = APS_wait_single_int(i_INT_N_16, CInt(TimeOut_ms.Text))
                bol_INT_N_16 = False
                APS_reset_int(i_INT_N_16)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_0()

        While 1


            If bol_INT_G_0 = True Then
                ret_INT_G_0 = 1000
                'ret_INT_G_0 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 0, CInt(TimeOut_ms.Text))
                ret_INT_G_0 = APS_wait_single_int(i_INT_G_0, CInt(TimeOut_ms.Text))
                bol_INT_G_0 = False
                APS_reset_int(i_INT_G_0)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_1()

        While 1


            If bol_INT_G_1 = True Then
                ret_INT_G_1 = 1000
                'ret_INT_G_1 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 1, CInt(TimeOut_ms.Text))
                ret_INT_G_1 = APS_wait_single_int(i_INT_G_1, CInt(TimeOut_ms.Text))
                bol_INT_G_1 = False
                APS_reset_int(i_INT_G_1)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_2()

        While 1


            If bol_INT_G_2 = True Then
                ret_INT_G_2 = 1000
                'ret_INT_G_2 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 2, CInt(TimeOut_ms.Text))
                ret_INT_G_2 = APS_wait_single_int(i_INT_G_2, CInt(TimeOut_ms.Text))
                bol_INT_G_2 = False
                APS_reset_int(i_INT_G_2)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_4()

        While 1


            If bol_INT_G_4 = True Then
                ret_INT_G_4 = 1000
                'ret_INT_G_4 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 4, CInt(TimeOut_ms.Text))
                ret_INT_G_4 = APS_wait_single_int(i_INT_G_4, CInt(TimeOut_ms.Text))
                bol_INT_G_4 = False
                APS_reset_int(i_INT_G_4)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_5()

        While 1


            If bol_INT_G_5 = True Then
                ret_INT_G_5 = 1000
                'ret_INT_G_5 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 5, CInt(TimeOut_ms.Text))
                ret_INT_G_5 = APS_wait_single_int(i_INT_G_5, CInt(TimeOut_ms.Text))
                bol_INT_G_5 = False
                APS_reset_int(i_INT_G_5)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_6()

        While 1


            If bol_INT_G_6 = True Then
                ret_INT_G_6 = 1000
                'ret_INT_G_6 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 6, CInt(TimeOut_ms.Text))
                ret_INT_G_6 = APS_wait_single_int(i_INT_G_6, CInt(TimeOut_ms.Text))
                bol_INT_G_6 = False
                APS_reset_int(i_INT_G_6)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_7()

        While 1


            If bol_INT_G_7 = True Then
                ret_INT_G_7 = 1000
                'ret_INT_G_7 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 7, CInt(TimeOut_ms.Text))
                ret_INT_G_7 = APS_wait_single_int(i_INT_G_7, CInt(TimeOut_ms.Text))
                bol_INT_G_7 = False
                APS_reset_int(i_INT_G_7)
            End If


            Sleep(50)
        End While

    End Sub

    Sub Thread_INT_G_10()

        While 1


            If bol_INT_G_10 = True Then
                ret_INT_G_10 = 1000
                'ret_INT_G_10 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 10, CInt(TimeOut_ms.Text))
                ret_INT_G_10 = APS_wait_single_int(i_INT_G_10, CInt(TimeOut_ms.Text))
                bol_INT_G_10 = False
                APS_reset_int(i_INT_G_10)
            End If


            Sleep(50)
        End While

    End Sub

    'Sub Thread_INT_G_11()

    '    While 1


    '        If bol_INT_G_11 = True Then
    '            ret_INT_G_11 = 1000
    '            'ret_INT_G_11 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 11, CInt(TimeOut_ms.Text))
    '            ret_INT_G_11 = APS_wait_single_int(i_INT_G_11, CInt(TimeOut_ms.Text))
    '            bol_INT_G_11 = False
    '            APS_reset_int(i_INT_G_11)
    '        End If


    '        Sleep(50)
    '    End While

    'End Sub

    'Sub Thread_INT_G_12()

    '    While 1


    '        If bol_INT_G_12 = True Then
    '            ret_INT_G_12 = 1000
    '            'ret_INT_G_12 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 12, CInt(TimeOut_ms.Text))
    '            ret_INT_G_12 = APS_wait_single_int(i_INT_G_12, CInt(TimeOut_ms.Text))
    '            bol_INT_G_12 = False
    '            APS_reset_int(i_INT_G_12)
    '        End If


    '        Sleep(50)
    '    End While

    'End Sub

    'Sub Thread_INT_G_14()

    '    While 1


    '        If bol_INT_G_14 = True Then
    '            ret_INT_G_14 = 1000
    '            'ret_INT_G_14 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 14, CInt(TimeOut_ms.Text))
    '            ret_INT_G_14 = APS_wait_single_int(i_INT_G_14, CInt(TimeOut_ms.Text))
    '            bol_INT_G_14 = False
    '            APS_reset_int(i_INT_G_14)
    '        End If


    '        Sleep(50)
    '    End While

    'End Sub

    'Sub Thread_INT_G_15()

    '    While 1


    '        If bol_INT_G_15 = True Then
    '            ret_INT_G_15 = 1000
    '            'ret_INT_G_15 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 15, CInt(TimeOut_ms.Text))
    '            ret_INT_G_15 = APS_wait_single_int(i_INT_G_15, CInt(TimeOut_ms.Text))
    '            bol_INT_G_15 = False
    '            APS_reset_int(i_INT_G_15)
    '        End If


    '        Sleep(50)
    '    End While

    'End Sub

    'Sub Thread_INT_G_16()

    '    While 1


    '        If bol_INT_G_16 = True Then
    '            ret_INT_G_16 = 1000
    '            'ret_INT_G_16 = B_8102_wait_gpio_interrupt(CInt(card_id.Text), 16, CInt(TimeOut_ms.Text))
    '            ret_INT_G_16 = APS_wait_single_int(i_INT_G_16, CInt(TimeOut_ms.Text))
    '            bol_INT_G_16 = False
    '            APS_reset_int(i_INT_G_16)
    '        End If


    '        Sleep(50)
    '    End While

    'End Sub





    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click

        AxisNo = CInt(PTP_AXIS.Text)

        'B_8102_set_continuous_move(AxisNo, 1)
        APS_set_axis_param(AxisNo, &H250, 1) 'PRA_CONTI_MODE

        'B_8102_start_tr_move(AxisNo, CDbl(PTP_CMD.Text), 0, 200000, 0.1, 0.1)
        'B_8102_start_tr_move(AxisNo, CDbl(PTP_CMD.Text), 0, 200000, 0.1, 0.1)
        'B_8102_start_tr_move(AxisNo, CDbl(PTP_CMD.Text), 0, 200000, 0.1, 0.1)

        APS_set_axis_param(AxisNo, 35, 0) 'PRA_VS
        APS_set_axis_param(AxisNo, 33, 50000) 'PRA_ACC
        APS_set_axis_param(AxisNo, 34, 50000) 'PRA_DEC

        APS_relative_move(AxisNo, CInt(PTP_CMD.Text), 200000)
        APS_relative_move(AxisNo, CInt(PTP_CMD.Text), 200000)
        APS_relative_move(AxisNo, CInt(PTP_CMD.Text), 200000)

    End Sub


    Private Sub Check_Color()

        'If ret_INT_E_0 = 0 Then
        '    INT_E_B_0.BackColor = System.Drawing.Color.Lime
        '    INT_E_E_0.BackColor = System.Drawing.Color.DarkRed
        'ElseIf ret_INT_E_0 = 1000 Then
        '    INT_E_B_0.BackColor = System.Drawing.Color.DarkGreen
        '    INT_E_E_0.BackColor = System.Drawing.Color.DarkRed
        'Else
        '    INT_E_B_0.BackColor = System.Drawing.Color.DarkGreen
        '    INT_E_E_0.BackColor = System.Drawing.Color.Red
        'End If


        If ret_INT_N_0 = 0 Then
            INT_N_B_0.BackColor = System.Drawing.Color.Lime
            INT_N_E_0.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_0 = 1000 Then
            INT_N_B_0.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_0.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_0.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_0.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_1 = 0 Then
            INT_N_B_1.BackColor = System.Drawing.Color.Lime
            INT_N_E_1.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_1 = 1000 Then
            INT_N_B_1.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_1.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_1.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_1.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_2 = 0 Then
            INT_N_B_2.BackColor = System.Drawing.Color.Lime
            INT_N_E_2.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_2 = 1000 Then
            INT_N_B_2.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_2.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_2.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_2.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_4 = 0 Then
            INT_N_B_4.BackColor = System.Drawing.Color.Lime
            INT_N_E_4.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_4 = 1000 Then
            INT_N_B_4.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_4.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_4.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_4.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_5 = 0 Then
            INT_N_B_5.BackColor = System.Drawing.Color.Lime
            INT_N_E_5.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_5 = 1000 Then
            INT_N_B_5.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_5.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_5.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_5.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_6 = 0 Then
            INT_N_B_6.BackColor = System.Drawing.Color.Lime
            INT_N_E_6.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_6 = 1000 Then
            INT_N_B_6.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_6.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_6.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_6.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_7 = 0 Then
            INT_N_B_7.BackColor = System.Drawing.Color.Lime
            INT_N_E_7.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_7 = 1000 Then
            INT_N_B_7.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_7.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_7.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_7.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_10 = 0 Then
            INT_N_B_10.BackColor = System.Drawing.Color.Lime
            INT_N_E_10.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_10 = 1000 Then
            INT_N_B_10.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_10.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_10.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_10.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_11 = 0 Then
            INT_N_B_11.BackColor = System.Drawing.Color.Lime
            INT_N_E_11.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_11 = 1000 Then
            INT_N_B_11.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_11.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_11.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_11.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_12 = 0 Then
            INT_N_B_12.BackColor = System.Drawing.Color.Lime
            INT_N_E_12.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_12 = 1000 Then
            INT_N_B_12.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_12.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_12.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_12.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_14 = 0 Then
            INT_N_B_14.BackColor = System.Drawing.Color.Lime
            INT_N_E_14.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_14 = 1000 Then
            INT_N_B_14.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_14.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_14.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_14.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_15 = 0 Then
            INT_N_B_15.BackColor = System.Drawing.Color.Lime
            INT_N_E_15.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_15 = 1000 Then
            INT_N_B_15.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_15.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_15.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_15.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_N_16 = 0 Then
            INT_N_B_16.BackColor = System.Drawing.Color.Lime
            INT_N_E_16.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_N_16 = 1000 Then
            INT_N_B_16.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_16.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_N_B_16.BackColor = System.Drawing.Color.DarkGreen
            INT_N_E_16.BackColor = System.Drawing.Color.Red
        End If




        If ret_INT_G_0 = 0 Then
            INT_G_B_0.BackColor = System.Drawing.Color.Lime
            INT_G_E_0.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_0 = 1000 Then
            INT_G_B_0.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_0.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_0.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_0.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_G_1 = 0 Then
            INT_G_B_1.BackColor = System.Drawing.Color.Lime
            INT_G_E_1.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_1 = 1000 Then
            INT_G_B_1.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_1.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_1.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_1.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_G_2 = 0 Then
            INT_G_B_2.BackColor = System.Drawing.Color.Lime
            INT_G_E_2.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_2 = 1000 Then
            INT_G_B_2.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_2.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_2.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_2.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_G_4 = 0 Then
            INT_G_B_4.BackColor = System.Drawing.Color.Lime
            INT_G_E_4.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_4 = 1000 Then
            INT_G_B_4.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_4.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_4.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_4.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_G_5 = 0 Then
            INT_G_B_5.BackColor = System.Drawing.Color.Lime
            INT_G_E_5.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_5 = 1000 Then
            INT_G_B_5.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_5.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_5.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_5.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_G_6 = 0 Then
            INT_G_B_6.BackColor = System.Drawing.Color.Lime
            INT_G_E_6.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_6 = 1000 Then
            INT_G_B_6.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_6.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_6.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_6.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_G_7 = 0 Then
            INT_G_B_7.BackColor = System.Drawing.Color.Lime
            INT_G_E_7.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_7 = 1000 Then
            INT_G_B_7.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_7.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_7.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_7.BackColor = System.Drawing.Color.Red
        End If

        If ret_INT_G_10 = 0 Then
            INT_G_B_10.BackColor = System.Drawing.Color.Lime
            INT_G_E_10.BackColor = System.Drawing.Color.DarkRed
        ElseIf ret_INT_G_10 = 1000 Then
            INT_G_B_10.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_10.BackColor = System.Drawing.Color.DarkRed
        Else
            INT_G_B_10.BackColor = System.Drawing.Color.DarkGreen
            INT_G_E_10.BackColor = System.Drawing.Color.Red
        End If

        'If ret_INT_G_11 = 0 Then
        '    INT_G_B_11.BackColor = System.Drawing.Color.Lime
        '    INT_G_E_11.BackColor = System.Drawing.Color.DarkRed
        'ElseIf ret_INT_G_11 = 1000 Then
        '    INT_G_B_11.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_11.BackColor = System.Drawing.Color.DarkRed
        'Else
        '    INT_G_B_11.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_11.BackColor = System.Drawing.Color.Red
        'End If

        'If ret_INT_G_12 = 0 Then
        '    INT_G_B_12.BackColor = System.Drawing.Color.Lime
        '    INT_G_E_12.BackColor = System.Drawing.Color.DarkRed
        'ElseIf ret_INT_G_12 = 1000 Then
        '    INT_G_B_12.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_12.BackColor = System.Drawing.Color.DarkRed
        'Else
        '    INT_G_B_12.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_12.BackColor = System.Drawing.Color.Red
        'End If

        'If ret_INT_G_14 = 0 Then
        '    INT_G_B_14.BackColor = System.Drawing.Color.Lime
        '    INT_G_E_14.BackColor = System.Drawing.Color.DarkRed
        'ElseIf ret_INT_G_14 = 1000 Then
        '    INT_G_B_14.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_14.BackColor = System.Drawing.Color.DarkRed
        'Else
        '    INT_G_B_14.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_14.BackColor = System.Drawing.Color.Red
        'End If

        'If ret_INT_G_15 = 0 Then
        '    INT_G_B_15.BackColor = System.Drawing.Color.Lime
        '    INT_G_E_15.BackColor = System.Drawing.Color.DarkRed
        'ElseIf ret_INT_G_15 = 1000 Then
        '    INT_G_B_15.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_15.BackColor = System.Drawing.Color.DarkRed
        'Else
        '    INT_G_B_15.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_15.BackColor = System.Drawing.Color.Red
        'End If

        'If ret_INT_G_16 = 0 Then
        '    INT_G_B_16.BackColor = System.Drawing.Color.Lime
        '    INT_G_E_16.BackColor = System.Drawing.Color.DarkRed
        'ElseIf ret_INT_G_16 = 1000 Then
        '    INT_G_B_16.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_16.BackColor = System.Drawing.Color.DarkRed
        'Else
        '    INT_G_B_16.BackColor = System.Drawing.Color.DarkGreen
        '    INT_G_E_16.BackColor = System.Drawing.Color.Red
        'End If


        'If bol_INT_E_0 = True Then
        '    INT_E_S_0.BackColor = System.Drawing.Color.Yellow
        'Else
        '    INT_E_S_0.BackColor = System.Drawing.Color.SaddleBrown
        'End If


        If bol_INT_N_0 = True Then
            INT_N_S_0.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_0.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_1 = True Then
            INT_N_S_1.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_1.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_2 = True Then
            INT_N_S_2.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_2.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_4 = True Then
            INT_N_S_4.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_4.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_5 = True Then
            INT_N_S_5.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_5.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_6 = True Then
            INT_N_S_6.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_6.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_7 = True Then
            INT_N_S_7.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_7.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_10 = True Then
            INT_N_S_10.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_10.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_11 = True Then
            INT_N_S_11.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_11.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_12 = True Then
            INT_N_S_12.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_12.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_14 = True Then
            INT_N_S_14.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_14.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_15 = True Then
            INT_N_S_15.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_15.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_N_16 = True Then
            INT_N_S_16.BackColor = System.Drawing.Color.Yellow
        Else
            INT_N_S_16.BackColor = System.Drawing.Color.SaddleBrown
        End If


        If bol_INT_G_0 = True Then
            INT_G_S_0.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_0.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_G_1 = True Then
            INT_G_S_1.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_1.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_G_2 = True Then
            INT_G_S_2.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_2.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_G_4 = True Then
            INT_G_S_4.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_4.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_G_5 = True Then
            INT_G_S_5.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_5.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_G_6 = True Then
            INT_G_S_6.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_6.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_G_7 = True Then
            INT_G_S_7.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_7.BackColor = System.Drawing.Color.SaddleBrown
        End If

        If bol_INT_G_10 = True Then
            INT_G_S_10.BackColor = System.Drawing.Color.Yellow
        Else
            INT_G_S_10.BackColor = System.Drawing.Color.SaddleBrown
        End If

        'If bol_INT_G_11 = True Then
        '    INT_G_S_11.BackColor = System.Drawing.Color.Yellow
        'Else
        '    INT_G_S_11.BackColor = System.Drawing.Color.SaddleBrown
        'End If

        'If bol_INT_G_12 = True Then
        '    INT_G_S_12.BackColor = System.Drawing.Color.Yellow
        'Else
        '    INT_G_S_12.BackColor = System.Drawing.Color.SaddleBrown
        'End If

        'If bol_INT_G_14 = True Then
        '    INT_G_S_14.BackColor = System.Drawing.Color.Yellow
        'Else
        '    INT_G_S_14.BackColor = System.Drawing.Color.SaddleBrown
        'End If

        'If bol_INT_G_15 = True Then
        '    INT_G_S_15.BackColor = System.Drawing.Color.Yellow
        'Else
        '    INT_G_S_15.BackColor = System.Drawing.Color.SaddleBrown
        'End If

        'If bol_INT_G_16 = True Then
        '    INT_G_S_16.BackColor = System.Drawing.Color.Yellow
        'Else
        '    INT_G_S_16.BackColor = System.Drawing.Color.SaddleBrown
        'End If

    End Sub



    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        'B_8102_set_continuous_move(AxisNo, 0)
        APS_set_axis_param(AxisNo, &H250, 0) 'PRA_CONTI_MODE
    End Sub


 
End Class
