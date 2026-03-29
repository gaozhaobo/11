Imports System.Windows.Forms
Public Class ApplicationEvents
    Protected Overloads Shared ReadOnly Property UseCompatibleTextRendering() As Boolean
        Get
            ' Use the GDI+ text rendering engine.  
            Return True
        End Get
    End Property
End Class