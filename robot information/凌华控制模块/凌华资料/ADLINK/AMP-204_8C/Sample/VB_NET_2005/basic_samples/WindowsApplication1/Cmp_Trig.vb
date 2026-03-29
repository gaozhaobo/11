Public Class Cmp_Trig

    Public v_card_id As Integer
    Public channel As Integer

    Private Sub Cmp_Trig_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

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

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick


        Dim Board_ID As Integer = v_card_id
        Dim CH As Integer = 0
        Dim CH_num As Integer = channel
        Dim TrgCnt As Integer = 0
        Dim ret As Integer = 0
        Dim line_value As Integer = 0
        Dim Table_value As Integer = 0
        Dim Cnt As Integer = 0
        Dim data(channel) As Integer
        Dim data_liner(2) As Integer
        Dim data_table(2) As Integer


        'get trigger count
        For CH = 0 To (CH_num - 1)
            ret = APS_get_trigger_count(Board_ID, CH, TrgCnt)
            data(CH) = TrgCnt
        Next

        Label6.Text = CStr(data(0))
        Label7.Text = CStr(data(1))

        If (CH_num = 4) Then
            Label8.Text = CStr(data(2))
            Label9.Text = CStr(data(3))
        End If

        'get current linear comparator value
        'get current table  comparator value
        For CH = 0 To 1
            ret = APS_get_trigger_linear_cmp(Board_ID, CH, line_value)
            ret = APS_get_trigger_table_cmp(Board_ID, CH, Table_value)
            data_liner(CH) = line_value
            data_table(CH) = Table_value
        Next

        Label12.Text = CStr(data_liner(0))
        Label14.Text = CStr(data_liner(1))
        Label13.Text = CStr(data_table(0))
        Label15.Text = CStr(data_table(1))

        'get timer counter
        ret = APS_get_timer_counter(Board_ID, 0, Cnt)
        Label19.Text = CStr(Cnt)

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click

        Dim Board_ID As Integer = v_card_id
        Dim ret As Integer = 0
        Dim CH As Integer = 0


        For CH = 0 To (channel - 1)
            ret = APS_reset_trigger_count(Board_ID, CH)
        Next

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click

        Dim Board_ID As Integer = v_card_id
        Dim ret As Integer = 0
        Dim CH As Integer = 0


        ' Enable trigger output
        If (channel = 2) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 3)
        ElseIf (channel = 4) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 15)
        End If

        'Trigger output TRG0 ~ TRG3 source
        'Bit 0: Manual 
        'Bit 1: Reserved
        'Bit 2: FCMP0 
        'Bit 3: FCMP1 
        'Bit 4: LCMP0 
        'Bit 5: LCMP1
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 1)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 1)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 1)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 1)

        'Start manual trigger
        For CH = 0 To (channel - 1)
            ret = APS_set_trigger_manual(Board_ID, CH)
        Next

        'Disable TRG 0 ~ 3
        ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 0)

        'Disable all CMP
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 0)

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click

        Dim Board_ID As Integer = v_card_id
        Dim ret As Integer = 0
        Dim CH As Integer = 0
        Dim StartPoint As Integer = 0
        Dim RepeatTimes As Integer = 10
        Dim Interval As Integer = 1000


        'Stop Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 0)

        'Clear timer
        ret = APS_set_timer_counter(Board_ID, 0, 0)

        ' Disable TRG 0 ~ 3
        ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 0)

        ' Disable all CMP
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 0)
        '-----------------------------------------------------------

        If (channel = 2) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 3)
        ElseIf (channel = 4) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 15)
        End If

        'Linear compare source: Timer counter 
        ret = APS_set_trigger_param(Board_ID, TGR_LCMP0_SRC, 8)
        ret = APS_set_trigger_param(Board_ID, TGR_LCMP1_SRC, 8)

        'Trigger output TRG0 ~ TRG3 source
        'Trigger output 0 source: LCMP0 
        'Trigger output 1 source: LCMP0 
        'Trigger output 2 source: LCMP1 
        'Trigger output 3 source: LCMP1
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 16)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 16)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 32)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 32)

        'Start linear CMP
        For CH = 0 To 1
            ret = APS_set_trigger_linear(Board_ID, CH, StartPoint, RepeatTimes, Interval)
        Next

        'Timer Interval: 1ms
        ret = APS_set_trigger_param(Board_ID, TIMR_ITV, 10000)

        'TIMR DIR: Positive count
        ret = APS_set_trigger_param(Board_ID, TIMR_DIR, 0)

        'Start Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 1)

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click

        Dim Board_ID As Integer = v_card_id
        Dim ret As Integer = 0
        Dim CH As Integer = 0
        Dim i As Integer = 0
        Dim ArraySize As Integer = 10
        Dim DataArr(10) As Integer

        For i = 0 To 9
            DataArr(i) = 0
        Next


        'Stop Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 0)

        'Clear timer
        ret = APS_set_timer_counter(Board_ID, 0, 0)

        'Disable TRG 0 ~ 3
        ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 0)

        'Disable all CMP
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 0)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 0)

        '------------------------------------------------------------

        'Enable trigger output
        If (channel = 2) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 3)
        ElseIf (channel = 4) Then
            ret = APS_set_trigger_param(Board_ID, TGR_TRG_EN, 15)
        End If


        'Linear compare source: Timer counter 
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP0_SRC, 8)
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP1_SRC, 8)

        'Table compare direction: Bi-direction(No direction)
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP0_DIR, 2)
        ret = APS_set_trigger_param(Board_ID, TGR_TCMP1_DIR, 2)

        'Trigger output TRG0 ~ TRG3 source
        'Trigger output 0 source: FCMP0 
        'Trigger output 1 source: FCMP0 
        'Trigger output 2 source: FCMP1 
        'Trigger output 3 source: FCMP1
        ret = APS_set_trigger_param(Board_ID, TGR_TRG0_SRC, 4)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG1_SRC, 4)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG2_SRC, 8)
        ret = APS_set_trigger_param(Board_ID, TGR_TRG3_SRC, 8)


        For i = 0 To 9
            DataArr(i) = i * 1000
        Next

        'Start Table CMP
        For CH = 0 To 1
            ret = APS_set_trigger_table(Board_ID, CH, DataArr, ArraySize)
        Next

        'Timer Interval: 1ms
        ret = APS_set_trigger_param(Board_ID, TIMR_ITV, 10000)

        'TIMR DIR: Positive count
        ret = APS_set_trigger_param(Board_ID, TIMR_DIR, 0)

        'Start Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 1)

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click

        Dim Board_ID As Integer = v_card_id
        Dim ret As Integer = 0

        'Stop Timer
        ret = APS_set_trigger_param(Board_ID, TIMR_EN, 0)

    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click


        Dim Board_ID As Integer = v_card_id
        Dim ret As Integer = 0

        'Clear timer
        ret = APS_set_timer_counter(Board_ID, 0, 0)

    End Sub
End Class