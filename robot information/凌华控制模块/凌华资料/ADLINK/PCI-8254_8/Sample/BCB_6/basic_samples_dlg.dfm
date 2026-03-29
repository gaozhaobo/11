object Form1: TForm1
  Left = 892
  Top = 357
  Width = 410
  Height = 308
  Caption = 'Basic Samples'
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
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 89
    Height = 257
    Caption = 'Start Here'
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 176
      Width = 69
      Height = 13
      Caption = 'Target 1st axis'
    end
    object Button1: TButton
      Left = 6
      Top = 16
      Width = 75
      Height = 25
      Caption = 'Initial'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 6
      Top = 48
      Width = 75
      Height = 25
      Caption = 'Close'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 6
      Top = 80
      Width = 75
      Height = 25
      Caption = 'Get Version'
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 6
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Axis Monitor'
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 6
      Top = 144
      Width = 75
      Height = 25
      Caption = 'Load Param'
      TabOrder = 4
      OnClick = Button5Click
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 200
      Width = 57
      Height = 21
      ItemHeight = 13
      TabOrder = 5
      OnChange = ComboBox1Change
    end
    object Button6: TButton
      Left = 6
      Top = 224
      Width = 75
      Height = 25
      Caption = 'Motion Done?'
      TabOrder = 6
      OnClick = Button6Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 112
    Top = 8
    Width = 89
    Height = 257
    Caption = 'Basic Move'
    TabOrder = 1
    object Button7: TButton
      Left = 6
      Top = 16
      Width = 75
      Height = 25
      Caption = 'Homing'
      TabOrder = 0
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 6
      Top = 48
      Width = 75
      Height = 25
      Caption = 'Velocity Move'
      TabOrder = 1
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 6
      Top = 80
      Width = 75
      Height = 25
      Caption = 'Jog ON'
      TabOrder = 2
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 6
      Top = 112
      Width = 75
      Height = 25
      Caption = 'Jog OFF'
      TabOrder = 3
      OnClick = Button10Click
    end
    object Button11: TButton
      Left = 6
      Top = 152
      Width = 75
      Height = 25
      Caption = 'P2P'
      TabOrder = 4
      OnClick = Button11Click
    end
    object Button12: TButton
      Left = 6
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Stop Move'
      TabOrder = 5
      OnClick = Button12Click
    end
    object Button13: TButton
      Left = 6
      Top = 224
      Width = 75
      Height = 25
      Caption = 'EMG Stop'
      TabOrder = 6
      OnClick = Button13Click
    end
  end
  object GroupBox4: TGroupBox
    Left = 304
    Top = 8
    Width = 89
    Height = 257
    Caption = 'Aux functions'
    TabOrder = 2
    object Button19: TButton
      Left = 6
      Top = 16
      Width = 75
      Height = 25
      Caption = 'Interrupt'
      TabOrder = 0
      OnClick = Button19Click
    end
    object Button20: TButton
      Left = 6
      Top = 48
      Width = 75
      Height = 25
      Caption = 'Digital I/O'
      TabOrder = 1
      OnClick = Button20Click
    end
    object Button21: TButton
      Left = 6
      Top = 80
      Width = 75
      Height = 25
      Caption = 'Analog I/O'
      TabOrder = 2
      OnClick = Button21Click
    end
    object Button22: TButton
      Left = 8
      Top = 112
      Width = 73
      Height = 25
      Caption = 'Point Table'
      TabOrder = 3
      OnClick = Button22Click
    end
    object Button23: TButton
      Left = 8
      Top = 144
      Width = 73
      Height = 25
      Caption = 'Gear / Gantry'
      TabOrder = 4
      OnClick = Button23Click
    end
    object Button24: TButton
      Left = 8
      Top = 176
      Width = 73
      Height = 25
      Caption = 'PWM / VAO'
      TabOrder = 5
      OnClick = Button24Click
    end
  end
  object Button25: TButton
    Left = 312
    Top = 216
    Width = 73
    Height = 25
    Caption = 'CMP Trigger'
    TabOrder = 3
    OnClick = Button25Click
  end
  object GroupBox3: TGroupBox
    Left = 208
    Top = 8
    Width = 89
    Height = 257
    Caption = 'Interpolation'
    TabOrder = 4
    object Button14: TButton
      Left = 6
      Top = 16
      Width = 75
      Height = 25
      Caption = '2D Line'
      TabOrder = 0
      OnClick = Button14Click
    end
    object Button15: TButton
      Left = 6
      Top = 48
      Width = 75
      Height = 25
      Caption = '2D Arc'
      TabOrder = 1
      OnClick = Button15Click
    end
    object Button16: TButton
      Left = 6
      Top = 80
      Width = 75
      Height = 25
      Caption = '3D Arc'
      TabOrder = 2
      OnClick = Button16Click
    end
    object Button17: TButton
      Left = 6
      Top = 112
      Width = 75
      Height = 25
      Caption = '3D  Spiral'
      TabOrder = 3
      OnClick = Button17Click
    end
    object Button18: TButton
      Left = 6
      Top = 144
      Width = 75
      Height = 25
      Caption = '2D Contour'
      TabOrder = 4
      OnClick = Button18Click
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.xml'
    Filter = '*.xml|*.xml'
    InitialDir = '.'
    Left = 216
    Top = 224
  end
end
