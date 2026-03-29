object Form5: TForm5
  Left = 1448
  Top = 252
  Width = 414
  Height = 279
  Caption = 'Comparator Trigger'
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
  object Label1: TLabel
    Left = 8
    Top = 32
    Width = 73
    Height = 13
    Caption = 'Trigger Counter'
  end
  object Label2: TLabel
    Left = 128
    Top = 40
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label3: TLabel
    Left = 200
    Top = 40
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label4: TLabel
    Left = 272
    Top = 40
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label5: TLabel
    Left = 336
    Top = 40
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label6: TLabel
    Left = 120
    Top = 16
    Width = 21
    Height = 13
    Caption = 'CH0'
  end
  object Label7: TLabel
    Left = 144
    Top = 112
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label8: TLabel
    Left = 208
    Top = 112
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label9: TLabel
    Left = 208
    Top = 136
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label10: TLabel
    Left = 192
    Top = 16
    Width = 21
    Height = 13
    Caption = 'CH1'
  end
  object Label11: TLabel
    Left = 264
    Top = 16
    Width = 21
    Height = 13
    Caption = 'CH2'
  end
  object Label12: TLabel
    Left = 328
    Top = 16
    Width = 21
    Height = 13
    Caption = 'CH3'
  end
  object Label13: TLabel
    Left = 144
    Top = 136
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label14: TLabel
    Left = 208
    Top = 88
    Width = 13
    Height = 13
    Caption = '#2'
  end
  object Label15: TLabel
    Left = 144
    Top = 88
    Width = 13
    Height = 13
    Caption = '#1'
  end
  object Label16: TLabel
    Left = 8
    Top = 112
    Width = 91
    Height = 13
    Caption = 'CMP Value (Linear)'
  end
  object Label17: TLabel
    Left = 8
    Top = 136
    Width = 89
    Height = 13
    Caption = 'CMP Value (Table)'
  end
  object Label18: TLabel
    Left = 8
    Top = 184
    Width = 59
    Height = 13
    Caption = 'Timer Value.'
  end
  object Label19: TLabel
    Left = 104
    Top = 184
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Button1: TButton
    Left = 272
    Top = 96
    Width = 73
    Height = 25
    Caption = 'Reset Count'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 208
    Width = 49
    Height = 25
    Caption = 'Stop'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 64
    Top = 208
    Width = 49
    Height = 25
    Caption = 'Clear'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 272
    Top = 128
    Width = 73
    Height = 25
    Caption = 'Manual'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 272
    Top = 160
    Width = 73
    Height = 25
    Caption = 'Linear'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 272
    Top = 192
    Width = 73
    Height = 25
    Caption = 'Table'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    Left = 848
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer2Timer
    Left = 376
  end
end
