Imports System.Windows.Forms

Public Class Dialog_version
    Public v_card_id As Integer

    Private Sub Cancel_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Me.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.Close()
    End Sub

    Private Sub Dialog1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim info(5) As Integer

        get_version_info(info, v_card_id)
        tbAPS.Text = CStr(info(0))
        tbSW.Text = CStr(info(1))
        tbMW.Text = CStr(info(2))
        tbEXE.Text = CStr(info(3))
        tbLIB.Text = CStr(info(4))
    End Sub

    Private Sub Dialog_version_FormClosed(ByVal sender As System.Object, ByVal e As System.Windows.Forms.FormClosedEventArgs) Handles MyBase.FormClosed
        Me.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.Close()
    End Sub

End Class
