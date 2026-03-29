Imports System.Windows.Forms

Public Class Dialog_version
    Public v_card_id As Integer

    Private Sub OK_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles OK_Button.Click
        Me.DialogResult = System.Windows.Forms.DialogResult.OK
        Me.Close()
    End Sub

    Private Sub Cancel_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Me.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.Close()
    End Sub

    Private Sub Dialog1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim info(5) As Integer
        Dim buf_0 As Integer = 0
        Dim buf_1 As String

        get_version_info(info, v_card_id)
        Label1.Text = CStr(info(0))
        Label2.Text = CStr(info(1))
        Label3.Text = CStr(info(2))

        buf_0 = info(3)
        buf_1 = buf_0.ToString("X")
        Label4.Text = buf_1

        Label5.Text = CStr(info(4))

    End Sub
End Class
