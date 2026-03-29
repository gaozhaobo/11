Imports System.Windows.Forms

Public Class Axis_Monitor
    Public v_card_id As Integer
    '// Motion I/O
    Const DLG_ALM = (0)
    Const DLG_PEL = (1)
    Const DLG_MEL = (2)
    Const DLG_ORG = (3)
    Const DLG_EMG = (4)
    Const DLG_EZ = (5)
    Const DLG_INP = (6)
    Const DLG_SVON = (7)
    Const DLG_RDY = (8)
    Const MAX_MIO_CHECK = (9)


    '// Motion status
    Const DLG_MDN = (0)
    Const DLG_EMGS = (1)
    Const DLG_ALMS = (2)
    Const DLG_PELS = (3)
    Const DLG_MELS = (4)
    Const DLG_SPELS = (5)
    Const DLG_SMELS = (6)
    Const DLG_HMES = (7)
    Const DLG_ORGS = (8)
    Const DLG_EZS = (9)
    Const MAX_MSTS_CHECK = (10)


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
        Dim i As Integer

        'start_axis_id = Form1.v_card_id

        ret = APS_get_first_axisId(v_card_id, start_axis_id, total_axes)

        ComboBox1.BeginUpdate()
        For i = 0 To total_axes - 1
            ComboBox1.Items.Add(CStr(i + start_axis_id))
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
        v_motion_io_bit_map(DLG_RDY) = MIO_RDY

        v_motion_status_bit_map(DLG_MDN) = MTS_NSTP
        v_motion_status_bit_map(DLG_EMGS) = MTS_EMGS
        v_motion_status_bit_map(DLG_ALMS) = MTS_ALMS
        v_motion_status_bit_map(DLG_PELS) = MTS_PELS
        v_motion_status_bit_map(DLG_MELS) = MTS_MELS
        v_motion_status_bit_map(DLG_SPELS) = MTS_SPELS
        v_motion_status_bit_map(DLG_SMELS) = MTS_SMELS
        v_motion_status_bit_map(DLG_HMES) = MTS_HMES
        v_motion_status_bit_map(DLG_ORGS) = MTS_ORGS
        v_motion_status_bit_map(DLG_EZS) = MTS_EZS


        Timer1.Enabled = True


    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        Dim status As AXIS_STATUS

        get_axis_status_example(v_selected_axis_id, status)

        TextBox1.Text = CStr(status.command_position)
        TextBox2.Text = CStr(status.feedback_position)
        TextBox3.Text = CStr(status.target_position)
        TextBox4.Text = CStr(status.error_position)
        TextBox5.Text = CStr(status.command_velocity)
        TextBox6.Text = CStr(status.feedback_velocity)
        TextBox7.Text = CStr(status.motion_io)
        TextBox8.Text = CStr(status.motion_status)

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
            name = "CheckBox" + CStr(i + 10)
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
        APS_set_command(v_selected_axis_id, 0.0)
        APS_set_position(v_selected_axis_id, 0.0)
    End Sub
End Class
