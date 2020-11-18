Public Class Form1


    'ATMN 321 -- Saturday 1:30pm
    'Jesse Sapirstein -- N01185396 
    'Remote Monitoring & Control Station'


    Dim InputHexCharacter As String
    Dim input As String
    Dim data As String
    Dim sfilename As String
    Dim filecontents As String

    Dim count As Integer
    Dim totalcount As Integer
    Dim serialstate As String
    Dim lastserialstate As String
    Dim data2 As String





    Private Sub Label1_Click(sender As Object, e As EventArgs)

    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        SerialPort1.BaudRate = 9600
        SerialPort1.Parity = IO.Ports.Parity.None
        SerialPort1.DataBits = 8
        SerialPort1.StopBits = IO.Ports.StopBits.One
        SerialPort1.Handshake = IO.Ports.Handshake.None
        SerialPort1.PortName = "COM4"
        SerialPort1.Open()
    End Sub



    Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
        sfilename = "C:\Abyss Web Server\htdocs\Index.html"
        filecontents = "<html><head><meta http-equiv=" & Chr(34) & "refresh" & Chr(34) & " content=" & Chr(34) & "1" & Chr(34) & "><title>Jesse, Lab 9</title></head><body>" & Label1.Text & "<br>" & Label2.Text & "<br /> </body></html>"
        System.IO.File.WriteAllText(sfilename, filecontents)
        input = SerialPort1.ReadExisting
        data = Mid(input, 1, 1)
        If data = "A" Then
            Label1.Text = "Input 1 is ON"
            Label2.Text = "Input 2 is ON"
        End If
        If data = "B" Then
            Label1.Text = "Input 1 is OFF"
            Label2.Text = "Input 2 is OFF"
        End If
        If data = "C" Then
            Label1.Text = "Input 1 is ON"
            Label2.Text = "Input 2 is OFF"
        End If
        If data = "D" Then
            Label1.Text = "Input 1 is OFF"
            Label2.Text = "Input 2 is ON"
        End If

        Label5.Text = serialstate
        Label3.Text = count
        Label4.Text = count Mod 12
        serialstate = SerialPort1.ReadExisting()

        data2 = Mid(serialstate, 1, 1)

        

    End Sub
End Class









