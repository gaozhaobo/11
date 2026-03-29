object Form4: TForm4
  Left = 609
  Top = 402
  Width = 478
  Height = 312
  Caption = 'PWM / VAO'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000400E80200001600000028000000200000004000
    0000010004000000000000020000000000000000000010000000100000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF009000
    0000000000000000000000000009099000000000000000000000000009900999
    0000000000000000000000009990009999000000000000000000009999000099
    9990000000000000000009999900000999999000000000000009999990000009
    9999999000000000009999999000000099999999990000099999999900000000
    9999999999999999999999990000000009999999999999999999999900000000
    0999999999999999999999900000000000000000000000999999999000000000
    0000000000000000000000000000000000000000000000999999990000000000
    0009999999999999999990000000000000099999999999999999900000000000
    0000000000000000000000000000000000000000000000000009000000000000
    0000099999999999999000000000000000000999999999999990000000000000
    0000000000000000090000000000000000000000000009999900000000000000
    0000000999999999900000000000000000000009999999999000000000000000
    0000000099999999000000000000000000000000999999990000000000000000
    0000000009999990000000000000000000000000099999900000000000000000
    0000000000999900000000000000000000000000009999000000000000000000
    0000000000099000000000000000000000000000000990000000000000007FFF
    FFFE9FFFFFF98FFFFFF1C3FFFFC3C1FFFF83E07FFE07E01FFC07F003E00FF000
    000FF800000FF800001FFFFFC01FFFFFFFFFFFFFC03FFE00007FFE00007FFFFF
    FFFFFFFFFEFFFF8001FFFF8001FFFFFFFBFFFFFF83FFFFE007FFFFE007FFFFF0
    0FFFFFF00FFFFFF81FFFFFF81FFFFFFC3FFFFFFC3FFFFFFE7FFFFFFE7FFF}
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 32
    Top = 96
    Width = 43
    Height = 13
    Caption = 'Freq [Hz]'
  end
  object Label1: TLabel
    Left = 24
    Top = 128
    Width = 50
    Height = 13
    Caption = 'Width [nS]'
  end
  object Label3: TLabel
    Left = 120
    Top = 96
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label5: TLabel
    Left = 344
    Top = 128
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label6: TLabel
    Left = 264
    Top = 128
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label7: TLabel
    Left = 192
    Top = 128
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label8: TLabel
    Left = 120
    Top = 128
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label9: TLabel
    Left = 344
    Top = 96
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label10: TLabel
    Left = 264
    Top = 96
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label11: TLabel
    Left = 192
    Top = 96
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label4: TLabel
    Left = 336
    Top = 56
    Width = 21
    Height = 13
    Caption = 'CH3'
  end
  object Label12: TLabel
    Left = 256
    Top = 56
    Width = 21
    Height = 13
    Caption = 'CH2'
  end
  object Label13: TLabel
    Left = 184
    Top = 56
    Width = 21
    Height = 13
    Caption = 'CH1'
  end
  object Label14: TLabel
    Left = 112
    Top = 56
    Width = 21
    Height = 13
    Caption = 'CH0'
  end
  object Label15: TLabel
    Left = 24
    Top = 32
    Width = 48
    Height = 13
    Caption = 'PWM Info'
  end
  object Label16: TLabel
    Left = 120
    Top = 216
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label18: TLabel
    Left = 32
    Top = 216
    Width = 55
    Height = 13
    Caption = 'VAO Status'
  end
  object Label17: TLabel
    Left = 40
    Top = 168
    Width = 37
    Height = 13
    Caption = 'Trig Cnt'
  end
  object Label19: TLabel
    Left = 120
    Top = 168
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label20: TLabel
    Left = 192
    Top = 168
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label21: TLabel
    Left = 264
    Top = 168
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label22: TLabel
    Left = 344
    Top = 168
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Button1: TButton
    Left = 384
    Top = 120
    Width = 73
    Height = 25
    Caption = 'PWM'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 176
    Top = 208
    Width = 73
    Height = 25
    Caption = 'VAO ON'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 176
    Top = 240
    Width = 73
    Height = 25
    Caption = 'VAO OFF'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 384
    Top = 88
    Width = 73
    Height = 25
    Caption = 'Reset Count'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 440
  end
end
