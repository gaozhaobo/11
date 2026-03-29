Imports System.Windows.Forms

Public Class Axis_Monitor
    '// Motion I/O
    Const DLG_ALM = (0)
    Const DLG_PEL = (1)
    Const DLG_MEL = (2)
    Const DLG_ORG = (3)
    Const DLG_EMG = (4)
    Const DLG_EZ = (5)
    Const DLG_INP = (6)
    Const DLG_SVON = (7)
    Const MAX_MIO_CHECK = (8)

    '// Motion status
    Const DLG_CSTP = (0)
    Const DLG_VM = (1)
    Const DLG_ACC = (2)
    Const DLG_DEC = (3)
    Const DLG_DIR = (4)
    Const DLG_MDN = (5)
    Const DLG_HMV = (6)
    Const DLG_WAIT = (7)
    Const DLG_PTB = (8)
    Const DLG_JOG = (9)
    Const DLG_ASTP = (10)
    Const DLG_BLD = (11)
    Const DLG_PRED = (12)
    Const DLG_POSTD = (13)
    Const DLG_GER = (14)
    Const MAX_MSTS_CHECK = (15)

    Dim v_card_id As Integer
    Dim v_start_axis_id As Integer
    Dim v_total_axes As Integer
    Dim v_selected_axis_id As Integer
    'Dim pCombo_select_axis As ComboBox
    'CButton *v_pCheck_motion_io[MAX_MIO_CHECK];
    'CButton *v_pCheck_motion_status[MAX_MSTS_CHECK];
    Dim v_motion_io_bit_map(MAX_MIO_CHECK) As Integer
    Dim v_motion_status_bit_map(MAX_MSTS_CHECK) As Integer


    Private Sub OK_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Me.DialogResult = System.Windows.Forms.DialogResult.OK
        Me.Close()
    End Sub

    Private Sub Cancel_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Me.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.Close()
    End Sub

    Private Sub Axis_Monitor_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        ComboBox1.ResetText()

        Dim start_axis_id As Integer = 0
        Dim total_axes As Integer = 0
        Dim ret As Integer
        Dim str As String
        Dim i As Integer

        ret = APS_get_first_axisId(v_card_id, start_axis_id, total_axes)

        ComboBox1.BeginUpdate()
        For i = 0 To total_axes - 1
            ComboBox1.Items.Add(CStr(i))
        Next
        ComboBox1.EndUpdate()
        ComboBox1.SelectedIndex = 0

        v_start_axis_id = start_axis_id
        v_total_axes = total_axes
        v_selected_axis_id = start_axis_id

        '// Bit map initial
        v_motion_io_bit_map(DLG_ALM) = MIO_ALM
        v_motion_io_bit_map(DLG_PEL) = MIO_PEL
        v_motion_io_bit_map(DLG_MEL) = MIO_MEL
        v_motion_io_bit_map(DLG_ORG) = MIO_ORG
        v_motion_io_bit_map(DLG_EMG) = MIO_EMG
        v_motion_io_bit_map(DLG_EZ) = MIO_EZ
        v_motion_io_bit_map(DLG_INP) = MIO_INP
        v_motion_io_bit_map(DLG_SVON) = MIO_SVON

        v_motion_status_bit_map(DLG_CSTP) = MTS_CSTP
        v_motion_status_bit_map(DLG_VM) = MTS_VM
        v_motion_status_bit_map(DLG_ACC) = MTS_ACC
        v_motion_status_bit_map(DLG_DEC) = MTS_DEC
        v_motion_status_bit_map(DLG_DIR) = MTS_DIR
        v_motion_status_bit_map(DLG_MDN) = MTS_NSTP
        v_motion_status_bit_map(DLG_HMV) = MTS_HMV
        v_motion_status_bit_map(DLG_WAIT) = 10
        v_motion_status_bit_map(DLG_PTB) = 11
        v_motion_status_bit_map(DLG_JOG) = MTS_JOG
        v_motion_status_bit_map(DLG_ASTP) = MTS_ASTP
        v_motion_status_bit_map(DLG_BLD) = 17
        v_motion_status_bit_map(DLG_PRED) = 18
        v_motion_status_bit_map(DLG_POSTD) = 19
        v_motion_status_bit_map(DLG_GER) = 28

        Timer1.Enabled = True


    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Dim status As AXIS_STATUS

        get_axis_status_example(v_selected_axis_id, status)

        Label8.Text = CStr(status.command_position)
        Label9.Text = CStr(status.feedback_position)
        Label10.Text = CStr(status.target_position)
        Label11.Text = CStr(status.error_position)
        Label12.Text = CStr(status.command_velocity)
        Label13.Text = CStr(status.feedback_velocity)

        'Label8.Text = CStr(status.motion_io >> 3)

        Dim i As Integer
        Dim name As String

        For i = 0 To MAX_MIO_CHECK - 1
            name = "CheckBox" + CStr(i + 1)
            Dim OBJCHECKBOX As CheckBox
            For Each CHKBOX As Object In Me.GroupBox1.Controls
                If TypeOf CHKBOX Is CheckBox Then
                    OBJCHECKBOX = CType(CHKBOX, CheckBox)
                    If OBJCHECKBOX.Name = name Then
                        Exit For
                    End If
                End If
            Next

            If (status.motion_io >> v_motion_io_bit_map(i)) And 1 Then
                OBJCHECKBOX.Checked = True
            Else
                OBJCHECKBOX.Checked = False
            End If
        Next

        For i = 0 To MAX_MSTS_CHECK - 1
            name = "CheckBox" + CStr(i + 9)
            Dim OBJCHECKBOX As CheckBox
            For Each CHKBOX As Object In Me.GroupBox2.Controls
                If TypeOf CHKBOX Is CheckBox Then
                    OBJCHECKBOX = CType(CHKBOX, CheckBox)
                    If OBJCHECKBOX.Name = name Then
                        Exit For
                    End If
                End If
            Next

            If (status.motion_status >> v_motion_status_bit_map(i)) And 1 Then
                OBJCHECKBOX.Checked = True
            Else
                OBJCHECKBOX.Checked = False
            End If
        Next

    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged

        If ComboBox1.SelectedIndex = -1 Then
            MessageBox.Show("", "ComboBox init err", MessageBoxButtons.OK, MessageBoxIcon.None)
            Exit Sub
        End If

        v_selected_axis_id = v_start_axis_id + ComboBox1.SelectedIndex

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        APS_set_servo_on(v_selected_axis_id, 1)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        APS_set_servo_on(v_selected_axis_id, 0)
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        APS_set_command_f(v_selected_axis_id, 0.0)
        APS_set_position_f(v_selected_axis_id, 0.0)
    End Sub
End Class
