Option Strict Off
Option Explicit On
Imports VB = Microsoft.VisualBasic
Imports System.Threading.Thread

Public Class Form1
    Inherits System.Windows.Forms.Form
    Public Const _NOT_INITIAL = 0
    Public Const _INITIALED = 1

    Dim v_is_card_initialed As Integer = 0
    Dim v_card_id As Integer
    Dim v_test_axis_id As Integer
    Dim v_first_axis_id As Integer
    Dim t As Threading.Thread
    Dim g_is_thread_created As Integer = 0
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

        'APS_register_virtual_board(0, 1)
        ret = APS_initial(boardID_InBits, mode)
        'MessageBox.Show(CStr(ret), "ok", MessageBoxButtons.OK, MessageBoxIcon.None)

        If ret = ERR_NoError Then

            For i = 0 To 15
                If (boardID_InBits And (2 ^ i)) Then

                    APS_get_card_name(i, card_name)

                    If card_name = DEVICE_NAME_PCI_825458 Then
                        board_ID = i
                        Exit For
                    End If

                    If card_name = DEVICE_NAME_AMP_20408C Then
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

            'Setup combol box
            ComboBox1.Items.Clear()
            ComboBox1.ResetText()
            ComboBox1.BeginUpdate()

            For i = 0 To total_axes - 1
                ComboBox1.Items.Add(CStr(i))
            Next

            ComboBox1.EndUpdate()
            ComboBox1.SelectedIndex = 0

            MessageBox.Show("initial ok", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)

        Else
            Dim to_show As String
            to_show = "Error Code is " + CStr(ret)
            MessageBox.Show(to_show, "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        End If

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click


        If g_is_thread_created = 1 Then
            t.Abort()
        End If

        APS_close()

        g_is_thread_created = 0
        v_is_card_initialed = _NOT_INITIAL

    End Sub

    Private Sub Form1_FormClosed(ByVal sender As System.Object, ByVal e As System.Windows.Forms.FormClosedEventArgs) Handles MyBase.FormClosed
        ' terminate the thread and timer after this
        APS_close()

    End Sub

    Public Sub _CHECK_CARD_INITIAL()

        If v_is_card_initialed = _NOT_INITIAL Then
            g_Is_APS_Initial = _NOT_INITIAL
            MessageBox.Show("Card has not been initialed.", "Error", MessageBoxButtons.OK, MessageBoxIcon.None)
            Exit Sub
        End If

        If v_is_card_initialed = _INITIALED Then
            g_Is_APS_Initial = _INITIALED
        End If

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        _CHECK_CARD_INITIAL()
        Dim version As New Dialog_version
        version.v_card_id = v_card_id
        version.ShowDialog()
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        _CHECK_CARD_INITIAL()

        If v_is_card_initialed = _INITIALED Then
            Dim version As New Axis_Monitor
            version.Show()
        End If

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click

        _CHECK_CARD_INITIAL()

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

    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        _CHECK_CARD_INITIAL()

        Dim ret As Integer
        Dim stop_code As Integer
        Dim str As String

        ret = check_motion_done_example(v_test_axis_id, stop_code)

        '// Display motion done status
        Select Case ret

            Case 0
                MessageBox.Show("In motion", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
            Case 1
                MessageBox.Show("Motion done", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
            Case -1
                str = "Error stop! stop code : " + CStr(stop_code) + "(" + CStr(stop_code_to_string(stop_code) + ")")
                MessageBox.Show(str, "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        End Select

    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        _CHECK_CARD_INITIAL()
        home_move_example(v_test_axis_id)

    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        _CHECK_CARD_INITIAL()
        velocity_move_example(v_test_axis_id)

    End Sub

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        _CHECK_CARD_INITIAL()
        jog_move_continuous_mode_example(v_test_axis_id)

        '/**** Following are another two samples *********/
        'jog_move_step_mode_example( v_test_axis_id )
        'jog_move_via_DI_example( v_test_axis_id )

    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        APS_jog_start(v_test_axis_id, 1)
        APS_jog_start(v_test_axis_id, 0)

    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        _CHECK_CARD_INITIAL()
        p2p_example(v_test_axis_id)

    End Sub

    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        _CHECK_CARD_INITIAL()
        deceleration_stop_example(v_test_axis_id)

    End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        _CHECK_CARD_INITIAL()
        emg_stop_example(v_test_axis_id)

    End Sub

    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button17.Click
        _CHECK_CARD_INITIAL()

        Dim Axis_ID_Array(2) As Integer
        Axis_ID_Array(0) = v_test_axis_id
        Axis_ID_Array(1) = v_test_axis_id + 1

        interpolation_2D_line_example(Axis_ID_Array)

    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        _CHECK_CARD_INITIAL()

        v_test_axis_id = v_first_axis_id + ComboBox1.SelectedIndex

    End Sub

    Private Sub Button16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button16.Click
        _CHECK_CARD_INITIAL()
        Dim Axis_ID_Array(2) As Integer
        Axis_ID_Array(0) = v_test_axis_id
        Axis_ID_Array(1) = v_test_axis_id + 1

        interpolation_2D_arc_example(Axis_ID_Array)

    End Sub

    Private Sub Button15_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button15.Click
        _CHECK_CARD_INITIAL()

        Dim Axis_ID_Array(3) As Integer
        Axis_ID_Array(0) = v_test_axis_id
        Axis_ID_Array(1) = v_test_axis_id + 1
        Axis_ID_Array(2) = v_test_axis_id + 2

        interpolation_3D_arc_example(Axis_ID_Array)

    End Sub

    Private Sub Button14_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button14.Click
        _CHECK_CARD_INITIAL()

        Dim Axis_ID_Array(3) As Integer
        Axis_ID_Array(0) = v_test_axis_id
        Axis_ID_Array(1) = v_test_axis_id + 1
        Axis_ID_Array(2) = v_test_axis_id + 2

        interpolation_3D_helical_example(Axis_ID_Array)

    End Sub

    Private Sub Button22_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button22.Click
        _CHECK_CARD_INITIAL()

        Dim Axis_ID_Array(2) As Integer
        Axis_ID_Array(0) = v_test_axis_id
        Axis_ID_Array(1) = v_test_axis_id + 1

        contour_2D_example(Axis_ID_Array)

    End Sub

    Private Sub Button21_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button21.Click

        _CHECK_CARD_INITIAL()

        If g_Is_APS_Initial = _INITIALED Then

            If g_is_thread_created = 0 Then

                Dim tmp As Integer
                Dim i As Integer


                t = New Threading.Thread(New Threading.ThreadStart(AddressOf Wait_Int))

                g_is_thread_created = 1

                APS_get_axis_info(v_test_axis_id, g_board_id, g_axis_num, tmp, tmp)

                t.Start()

                'Waste some times in order to start Thread
                For i = 0 To 100000 Step 1
                Next


                MessageBox.Show("Wait motion done thread is created. You can start a p2p move.", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)

            Else
                MessageBox.Show("Thread already created", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
            End If

        End If

    End Sub

    Sub Wait_Int()

        Dim ret As Integer

        ret = interrupt_example(g_board_id, g_axis_num)

        If (ret = ERR_NoError) Then

            MessageBox.Show("interrupt occur", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)

        End If

        g_is_thread_created = 0
        t.Abort()

    End Sub


    Private Sub Button20_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button20.Click
        _CHECK_CARD_INITIAL()
        DIO_sample(v_card_id)

    End Sub

    Private Sub Button19_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button19.Click

        Dim card_name As Integer

        _CHECK_CARD_INITIAL()

        APS_get_card_name(0, card_name)

        If card_name = DEVICE_NAME_PCI_825458 Then

            AIO_sample(v_card_id)

        End If




    End Sub

    Private Sub Button18_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button18.Click

        Dim E_Gear As System.Threading.Thread = New Threading.Thread(AddressOf TaskA)
        E_Gear.Start()

    End Sub

    Sub TaskA()

        _CHECK_CARD_INITIAL()

        Dim Axis_ID_Array(2) As Integer
        Axis_ID_Array(0) = 0
        Axis_ID_Array(1) = 1

        E_Gear_example(Axis_ID_Array)

    End Sub

    Private Sub Button23_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button23.Click

        _CHECK_CARD_INITIAL()

        Dim Axis_ID_Array(2) As Integer
        Axis_ID_Array(0) = v_test_axis_id
        Axis_ID_Array(1) = v_test_axis_id + 1

        point_table_2D_example(v_card_id, Axis_ID_Array)

    End Sub

    Private Sub Button24_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button24.Click

        _CHECK_CARD_INITIAL()

        If g_Is_APS_Initial = _INITIALED Then

            Dim p As New PWM_VAO

            p.v_card_id = v_card_id

            p.Show()

        End If

    End Sub

    Private Sub Button25_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button25.Click

        _CHECK_CARD_INITIAL()

        If g_Is_APS_Initial = _INITIALED Then

            Dim p As New Cmp_Trig

            p.v_card_id = v_card_id

            p.Show()

        End If

    End Sub
End Class
