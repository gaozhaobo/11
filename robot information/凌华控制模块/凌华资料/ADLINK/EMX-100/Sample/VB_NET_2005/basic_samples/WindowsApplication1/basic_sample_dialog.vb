Option Strict Off
Option Explicit On
Imports VB = Microsoft.VisualBasic
Imports System.Threading.Thread
Imports System.Security.Principal
Imports System.Diagnostics
Imports System.Security.Permissions

Public Class Form1
    Inherits System.Windows.Forms.Form
    Public Const _NOT_INITIAL = 0
    Public Const _INITIALED = 1

    Dim v_is_card_initialed As Integer = 0
    Dim v_card_id As Integer
    Dim v_test_axis_id As Integer
    Dim v_first_axis_id As Integer
    Dim t As Threading.Thread
    Dim g_is_thread_close As Boolean = True
    Dim g_board_id As Integer
    Dim g_axis_num As Integer
    Dim g_Is_APS_Initial As Integer = _NOT_INITIAL

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
       
    End Sub


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim boardID_InBits As Integer = 0
        'I32 mode           = INIT_AUTO_CARD_ID | INIT_PARAM_IGNORE;
        'Dim mode As Integer = (INIT_AUTO_CARD_ID Or INIT_PARAM_LOAD_FLASH)
        Dim mode As Integer = 0
        Dim ret As Integer = 0
        Dim board_ID As Integer = -1
        Dim i As Integer
        Dim card_name As Integer

        '    ' UI protection
        If v_is_card_initialed = _INITIALED Then
            MessageBox.Show("initial ok", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
            Exit Sub
        End If

        ret = APS_register_emx(1, 0)
        ret = APS_initial(boardID_InBits, mode)


        If ret = ERR_NoError Then

            For i = 0 To 15
                If (boardID_InBits And (2 ^ i)) Then

                    APS_get_card_name(i, card_name)

                    If card_name = DEVICE_NAME_ENET_EMX100 Then
                        board_ID = i
                        Exit For
                    End If
                End If

            Next

            If board_ID = -1 Then
                MessageBox.Show("BoardId search error!", "Error", MessageBoxButtons.OK, MessageBoxIcon.None)
                Exit Sub
            End If

            v_is_card_initialed = _INITIALED
            v_card_id = board_ID

            Dim total_axes As Integer
            APS_get_first_axisId(board_ID, v_first_axis_id, total_axes)
            v_test_axis_id = v_first_axis_id

            For i = 0 To 3
                ret = APS_set_axis_param(v_first_axis_id + i, PRA_EL_LOGIC, 1)
                ret = APS_set_axis_param(v_first_axis_id + i, PRA_ORG_LOGIC, 1)
                ret = APS_set_axis_param(v_first_axis_id + i, PRA_EL_MODE, 1)
                ret = APS_set_axis_param(v_first_axis_id + i, PRA_ALM_LOGIC, 1)
            Next

            'Setup combol box
            ComboBox1.Items.Clear()
            ComboBox1.ResetText()
            ComboBox1.BeginUpdate()

            For i = 0 To total_axes - 1
                ComboBox1.Items.Add(CStr(i + v_first_axis_id))
            Next

            ComboBox1.EndUpdate()
            ComboBox1.SelectedIndex = 0

            MessageBox.Show("Initial ok", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
            If card_name = DEVICE_NAME_ENET_EMX100 Then
                Me.Text = "EMX-100 Basic Sample"
            End If

        Else
            Dim to_show As String
            to_show = "Error Code is " + CStr(ret)
            MessageBox.Show(to_show, "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        End If

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim ret As Integer = 0
        Dim to_show As String
        

        ret = APS_close()
        If ret <> 0 Then
            to_show = "Error Code is " + CStr(ret)
            MessageBox.Show(to_show, "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        End If

        If ret = 0 Then
            MessageBox.Show("APS close ok", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        End If
        btnRepeatMove.Enabled = True
        g_is_thread_close = False

        v_is_card_initialed = _NOT_INITIAL
        ComboBox1.Items.Clear()
    End Sub

    Private Sub Form1_FormClosed(ByVal sender As System.Object, ByVal e As System.Windows.Forms.FormClosedEventArgs) Handles MyBase.FormClosed
        ' terminate the thread and timer after this
        APS_close()

    End Sub

    Public Function _CHECK_CARD_INITIAL()

        If v_is_card_initialed = _NOT_INITIAL Then
            g_Is_APS_Initial = _NOT_INITIAL
            MessageBox.Show("Card has not been initialed.", "Error", MessageBoxButtons.OK, MessageBoxIcon.None)
            Return False
        Else
            Return True
        End If
    End Function

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click

        If _CHECK_CARD_INITIAL() = True Then
            Dim version As New Dialog_version
            version.v_card_id = v_card_id
            version.ShowDialog()
        End If
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        If _CHECK_CARD_INITIAL() = True Then
            Dim AxisMonitor As New Axis_Monitor
            AxisMonitor.v_card_id = v_card_id
            AxisMonitor.Show()
        End If

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click

        If _CHECK_CARD_INITIAL() = True Then
            Dim myStream As System.IO.Stream

            OpenFileDialog1.Filter = "xml files (*.xml)|*.xml|All files (*.*)|*.*"
            OpenFileDialog1.FilterIndex = 1
            OpenFileDialog1.RestoreDirectory = True

            If OpenFileDialog1.ShowDialog() = DialogResult.OK Then

                MsgBox(OpenFileDialog1.FileName)
                myStream = OpenFileDialog1.OpenFile()

                If Not (myStream Is Nothing) Then

                    load_parameters_from_file_sample(OpenFileDialog1.FileName)
                    myStream.Close()

                End If

            End If
        End If

    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        If _CHECK_CARD_INITIAL() = True Then
            p2p_example(v_test_axis_id)
        End If
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        If _CHECK_CARD_INITIAL() = True Then
            APS_jog_start(v_test_axis_id, 1)
            APS_jog_start(v_test_axis_id, 0)
        End If
    End Sub


    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        If _CHECK_CARD_INITIAL() = True Then
            jog_move_continuous_mode_example(v_test_axis_id)
        End If
    End Sub
    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        If _CHECK_CARD_INITIAL() = True Then
            velocity_move_example(v_test_axis_id)
        End If
    End Sub
    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        If _CHECK_CARD_INITIAL() = True Then
            home_move_example(v_test_axis_id)
        End If

    End Sub


    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        If _CHECK_CARD_INITIAL() = True Then
            g_is_thread_close = True
            btnRepeatMove.Enabled = True
            deceleration_stop_example(v_test_axis_id)
        End If
    End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        If _CHECK_CARD_INITIAL() = True Then
            btnRepeatMove.Enabled = True
            g_is_thread_close = True
            emg_stop_example(v_test_axis_id)
        End If
    End Sub

    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnRepeatMove.Click
        If _CHECK_CARD_INITIAL() = True Then
            If CInt(tbDelayTime.Text) < 1 Then
                MessageBox.Show("Delay time must be >= 1 ms", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
                Exit Sub
            End If
            Dim RepeatMove As System.Threading.Thread = New Threading.Thread(AddressOf Repeat_Task)
            btnRepeatMove.Enabled = False
            RepeatMove.Start()
            g_is_thread_close = False

        End If

    End Sub
    Sub Repeat_Task()
        Dim ret As Integer = 0
        Dim bEven As Boolean = False
        Dim delayTime As Integer = 0
        delayTime = CInt(tbDelayTime.Text)
        While True
            If g_is_thread_close Then
                Exit While
            End If
            ret = APS_motion_status(v_test_axis_id)
            If ret < 0 Then
                Dim error_show As String
                error_show = "Error Code is " + CStr(ret)
                MessageBox.Show(error_show, "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
                btnRepeatMove.Enabled = True
                Exit While
            ElseIf ((ret >> MTS_NSTP) And 1) = 1 Then
                bEven = Not bEven
                If bEven = True Then
                    ret = APS_relative_move(v_test_axis_id, 10000, 20000)
                Else
                    ret = APS_relative_move(v_test_axis_id, -10000, 20000)
                End If
                Sleep(delayTime)
                If ret < 0 Then
                    MessageBox.Show("APS_relative_Move -912 ", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
                    Exit While
                End If

            End If
        End While
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        _CHECK_CARD_INITIAL()

        v_test_axis_id = v_first_axis_id + ComboBox1.SelectedIndex

    End Sub
    Private Sub Button21_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button21.Click
        If _CHECK_CARD_INITIAL() = True Then
            CMP_Trigger(v_card_id)
        End If
    End Sub

    Private Sub Button20_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button20.Click
        If _CHECK_CARD_INITIAL() = True Then
            DIO_sample(v_card_id)
        End If
    End Sub

End Class
