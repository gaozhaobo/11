object Form3: TForm3
  Left = 1337
  Top = 226
  Width = 419
  Height = 321
  Caption = 'Axis Monitor'
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 42
    Height = 13
    Caption = 'Axis ID : '
  end
  object Label2: TLabel
    Left = 16
    Top = 48
    Width = 96
    Height = 13
    Caption = 'Command Position : '
  end
  object Label3: TLabel
    Left = 15
    Top = 78
    Width = 97
    Height = 13
    Caption = 'Feedback Position : '
  end
  object Label4: TLabel
    Left = 32
    Top = 108
    Width = 80
    Height = 13
    Caption = 'Target Position : '
  end
  object Label5: TLabel
    Left = 41
    Top = 139
    Width = 71
    Height = 13
    Caption = 'Error Position : '
  end
  object Label6: TLabel
    Left = 17
    Top = 169
    Width = 95
    Height = 13
    Caption = 'Command velocity : '
  end
  object Label7: TLabel
    Left = 16
    Top = 200
    Width = 96
    Height = 13
    Caption = 'Feedback velocity : '
  end
  object Label8: TLabel
    Left = 112
    Top = 48
    Width = 97
    Height = 13
    AutoSize = False
    Caption = '0'
  end
  object Label9: TLabel
    Left = 112
    Top = 78
    Width = 97
    Height = 13
    AutoSize = False
    Caption = '0'
  end
  object Label10: TLabel
    Left = 112
    Top = 108
    Width = 97
    Height = 13
    AutoSize = False
    Caption = '0'
  end
  object Label11: TLabel
    Left = 112
    Top = 139
    Width = 97
    Height = 13
    AutoSize = False
    Caption = '0'
  end
  object Label12: TLabel
    Left = 112
    Top = 169
    Width = 97
    Height = 13
    AutoSize = False
    Caption = '0'
  end
  object Label13: TLabel
    Left = 112
    Top = 200
    Width = 97
    Height = 13
    AutoSize = False
    Caption = '0'
  end
  object ComboBox1: TComboBox
    Left = 64
    Top = 16
    Width = 89
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    OnChange = ComboBox1Change
  end
  object GroupBox1: TGroupBox
    Left = 224
    Top = 8
    Width = 81
    Height = 265
    Caption = 'Motion I/O'
    TabOrder = 1
    object CheckBox1: TCheckBox
      Left = 8
      Top = 16
      Width = 65
      Height = 17
      Caption = 'ALM'
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 8
      Top = 32
      Width = 65
      Height = 17
      Caption = 'PEL'
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 8
      Top = 48
      Width = 65
      Height = 17
      Caption = 'MEL'
      TabOrder = 2
    end
    object CheckBox4: TCheckBox
      Left = 8
      Top = 64
      Width = 65
      Height = 17
      Caption = 'ORG'
      TabOrder = 3
    end
    object CheckBox5: TCheckBox
      Left = 8
      Top = 80
      Width = 65
      Height = 17
      Caption = 'EMG'
      TabOrder = 4
    end
    object CheckBox6: TCheckBox
      Left = 8
      Top = 96
      Width = 65
      Height = 17
      Caption = 'EZ'
      TabOrder = 5
    end
    object CheckBox7: TCheckBox
      Left = 8
      Top = 112
      Width = 65
      Height = 17
      Caption = 'INP'
      TabOrder = 6
    end
    object CheckBox8: TCheckBox
      Left = 8
      Top = 128
      Width = 65
      Height = 17
      Caption = 'SVON'
      TabOrder = 7
    end
    object Button2: TButton
      Left = 8
      Top = 192
      Width = 67
      Height = 25
      Caption = 'SVON'
      TabOrder = 8
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 8
      Top = 224
      Width = 67
      Height = 25
      Caption = 'SVOFF'
      TabOrder = 9
      OnClick = Button3Click
    end
  end
  object Button1: TButton
    Left = 16
    Top = 248
    Width = 75
    Height = 25
    Caption = 'Reset position'
    TabOrder = 2
    OnClick = Button1Click
  end
  object GroupBox2: TGroupBox
    Left = 312
    Top = 8
    Width = 81
    Height = 265
    Caption = 'Motion Status'
    TabOrder = 3
    object CheckBox9: TCheckBox
      Left = 8
      Top = 16
      Width = 65
      Height = 17
      Caption = 'CSTP'
      TabOrder = 0
    end
    object CheckBox10: TCheckBox
      Left = 8
      Top = 32
      Width = 65
      Height = 17
      Caption = 'VM'
      TabOrder = 1
    end
    object CheckBox11: TCheckBox
      Left = 8
      Top = 48
      Width = 65
      Height = 17
      Caption = 'ACC'
      TabOrder = 2
    end
    object CheckBox12: TCheckBox
      Left = 8
      Top = 64
      Width = 65
      Height = 17
      Caption = 'DEC'
      TabOrder = 3
    end
    object CheckBox13: TCheckBox
      Left = 8
      Top = 80
      Width = 65
      Height = 17
      Caption = 'DIR'
      TabOrder = 4
    end
    object CheckBox14: TCheckBox
      Left = 8
      Top = 96
      Width = 65
      Height = 17
      Caption = 'MDN'
      TabOrder = 5
    end
    object CheckBox15: TCheckBox
      Left = 8
      Top = 112
      Width = 65
      Height = 17
      Caption = 'HMV'
      TabOrder = 6
    end
    object CheckBox16: TCheckBox
      Left = 8
      Top = 128
      Width = 65
      Height = 17
      Caption = 'WAIT'
      TabOrder = 7
    end
    object CheckBox17: TCheckBox
      Left = 8
      Top = 144
      Width = 65
      Height = 17
      Caption = 'PTB'
      TabOrder = 8
    end
    object CheckBox18: TCheckBox
      Left = 8
      Top = 160
      Width = 65
      Height = 17
      Caption = 'JOG'
      TabOrder = 9
    end
    object CheckBox19: TCheckBox
      Left = 8
      Top = 176
      Width = 65
      Height = 17
      Caption = 'ASTP'
      TabOrder = 10
    end
    object CheckBox20: TCheckBox
      Left = 8
      Top = 192
      Width = 65
      Height = 17
      Caption = 'BLD'
      TabOrder = 11
    end
    object CheckBox21: TCheckBox
      Left = 8
      Top = 208
      Width = 65
      Height = 17
      Caption = 'PRED'
      TabOrder = 12
    end
    object CheckBox22: TCheckBox
      Left = 8
      Top = 224
      Width = 65
      Height = 17
      Caption = 'POSTD'
      TabOrder = 13
    end
    object CheckBox23: TCheckBox
      Left = 8
      Top = 240
      Width = 65
      Height = 17
      Caption = 'GER'
      TabOrder = 14
    end
  end
  object Timer1: TTimer
    Interval = 500
    OnTimer = Timer1Timer
    Left = 144
    Top = 240
  end
end
