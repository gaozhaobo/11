Imports System.Security.Principal
Imports System.Diagnostics
Imports System.Security.Permissions

Module Module1
    Sub Main()
        Dim identity = WindowsIdentity.GetCurrent()
        Dim principal As New WindowsPrincipal(identity)
        If Not principal.IsInRole(WindowsBuiltInRole.Administrator) Then
            Dim psi As New ProcessStartInfo
            psi.FileName = Application.ExecutablePath
            psi.Verb = "runas"
            Try
                Process.Start(psi)
                Application.Exit()
            Catch eee As Exception
                MessageBox.Show(eee.Message)
            End Try
        Else
            Application.EnableVisualStyles()
            Application.SetCompatibleTextRenderingDefault(False)
            Application.Run(New Form1())
        End If
    End Sub
End Module
