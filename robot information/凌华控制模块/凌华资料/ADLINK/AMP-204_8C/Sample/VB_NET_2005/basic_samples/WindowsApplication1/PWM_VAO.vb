

Public Class PWM_VAO

    Public v_card_id As Integer
    Public channel As Integer


    Private Sub PWM_VAO_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim start_axis_id As Integer = 0
        Dim total_axes As Integer = 0
        Dim ret As Integer = 0

        ret = APS_get_first_axisId(v_card_id, start_axis_id, total_axes)

        If (total_axes = 4) Then
            channel = 2
        ElseIf (total_axes = 8) Then
            channel = 4
        End If

        Timer1.Enabled = True

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim PWM As System.Threading.Thread = New Threading.Thread(AddressOf TaskA)
        PWM.Start()

    End Sub

    Sub TaskA()

        PWM_example(v_card_id, channel)

    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick

        Dim CH As Integer = 0
        Dim Frequency As Integer = 0
        Dim Width As Integer = 0
        Dim TrgCnt As Integer = 0
        Dim ret As Integer = 0
        Dim data(channel) As Integer
        Dim Status As Integer = 0


        'get pwm frequency
        For CH = 0 To (channel - 1)
            ret = APS_get_pwm_frequency(v_card_id, CH, Frequency)
            data(CH) = Frequency
        Next

        Label7.Text = CStr(data(0))
        Label8.Text = CStr(data(1))

        If (channel = 4) Then
            Label9.Text = CStr(data(2))
            Label10.Text = CStr(data(3))
        End If


        'get pwm width
        For CH = 0 To (channel - 1)
            ret = APS_get_pwm_width(v_card_id, CH, Width)
            data(CH) = Width
        Next

        Label11.Text = CStr(data(0))
        Label14.Text = CStr(data(1))

        If (channel = 4) Then
            Label13.Text = CStr(data(2))
            Label12.Text = CStr(data(3))
        End If

        'get trigger count
        For CH = 0 To (channel - 1)
            ret = APS_get_trigger_count(v_card_id, CH, TrgCnt)
            data(CH) = TrgCnt
        Next

        Label18.Text = CStr(data(0))
        Label19.Text = CStr(data(1))

        If (channel = 4) Then
            Label20.Text = CStr(data(2))
            Label21.Text = CStr(data(3))
        End If

        ret = APS_get_vao_status(v_card_id, Status)
        Label16.Text = CStr(Status)

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click

        Dim ret As Integer = 0
        Dim CH As Integer = 0

        For CH = 0 To (channel - 1)
            ret = APS_reset_trigger_count(v_card_id, CH)
        Next

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click

        Dim ret As Integer = 0
        Dim Board_ID As Integer = v_card_id

        'VAO table number. Range is 0 ~ 7.
        Dim Table_No As Integer = 0

        'Minimum linear speed
        Dim MinVelocity As Integer = 1000

        'Minimum linear speed
        Dim VelInterval As Integer = 1000

        'Total points. Range is 1 ~ 32
        Dim TotalPoints As Integer = 2

        'Output data array
        ' 500  -> 25% duty
        ' 1000 -> 50% duty
        Dim MappingDataArray(2) As Integer
        MappingDataArray(0) = 500
        MappingDataArray(1) = 1000

        Dim Status As Integer = 0





        '****************************************************************
        ' Set output type of Table[0]
        '
        ' 0: output voltage.(reserved)
        ' 1: Fix frequency, change duty ratio.  
        ' 2: Fix pulse width, change frequency. 
        ' 3: Fix duty ratio, change frequency.  
        '****************************************************************
        ret = APS_set_vao_param(Board_ID, 0, 1)

        '****************************************************************
        ' Set input reference of Table[0]
        '
        ' 0: feedback speed. 
        ' 1: command speed.  
        '****************************************************************
        ret = APS_set_vao_param(Board_ID, 1, 1)

        '****************************************************************
        ' Configure PWM according to output type in Table[0]. 
        '
        ' If you set output type as voltage mode.(output type = 0)
        '		This value is don't care.
        '
        ' If output type = 1 (Fix frequency, change duty ratio.  )
        '      frequency Range: 3 ~ 50M Hz
        '      
        ' If output type = 2 (Fix pulse width, change frequency. )
        '		pulse width Range: 20 ~ 335544300 ns
        '
        ' If output type = 3 (Fix duty ratio, change frequency.  )
        '		duty cycle Range:   1 ~ 2000 (0%~100%)
        '
        '****************************************************************
        ret = APS_set_vao_param(Board_ID, 16, 1000)

        'Specify axisID for VAO Table[0].
        ret = APS_set_vao_param(Board_ID, 32, 1)

        'set Table[0] parameters
        ret = APS_set_vao_table(Board_ID, Table_No, MinVelocity, VelInterval, TotalPoints, MappingDataArray)

        'check parameters of VAO Table[0]
        ret = APS_check_vao_param(Board_ID, Table_No, Status)


        If (Status = 0) Then
            MessageBox.Show("VAO Setting Ok", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        Else
            MessageBox.Show("VAO Setting Failed", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
        End If

        'Specify which table be executed
        'if Table_No = -1 that disable all tables.
        ret = APS_switch_vao_table(Board_ID, Table_No)

        'Enable outputs 
        ret = APS_start_vao(Board_ID, 0, 1)
        ret = APS_start_vao(Board_ID, 1, 1)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click

        Dim Board_ID As Integer = v_card_id
        Dim ret As Integer = 0

        'VAO table number. Range is 0 ~ 7.
        Dim Table_No As Integer = -1


        'Disable all tables.
        ret = APS_switch_vao_table(Board_ID, Table_No)

        'Disable outputs
        ret = APS_start_vao(Board_ID, 0, 0)
        ret = APS_start_vao(Board_ID, 1, 0)

        MessageBox.Show("VAO off", "ok", MessageBoxButtons.OK, MessageBoxIcon.None)
    End Sub
End Class