object Form1: TForm1
  Left = 695
  Top = 70
  Width = 1089
  Height = 827
  Caption = 'ADLINK Delphi 7 Sample'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
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
  object Label4: TLabel
    Left = 264
    Top = 575
    Width = 63
    Height = 13
    Caption = 'Input Card ID'
  end
  object GroupBox3: TGroupBox
    Left = 215
    Top = 8
    Width = 746
    Height = 185
    Caption = 'Axis Info'
    TabOrder = 0
    object Label7: TLabel
      Left = 16
      Top = 38
      Width = 81
      Height = 13
      Caption = 'Command Pulses'
    end
    object Label8: TLabel
      Left = 16
      Top = 78
      Width = 82
      Height = 13
      Caption = 'Feedback Pluses'
    end
    object Label9: TLabel
      Left = 16
      Top = 118
      Width = 82
      Height = 13
      Caption = 'Motion IO Status '
    end
    object Label10: TLabel
      Left = 17
      Top = 157
      Width = 68
      Height = 13
      Caption = 'Motion Status '
    end
    object Label11: TLabel
      Left = 144
      Top = 16
      Width = 28
      Height = 13
      Caption = 'Axis 0'
    end
    object Label15: TLabel
      Left = 272
      Top = 16
      Width = 28
      Height = 13
      Caption = 'Axis 1'
    end
    object Label19: TLabel
      Left = 400
      Top = 16
      Width = 28
      Height = 13
      Caption = 'Axis 2'
    end
    object Label5: TLabel
      Left = 536
      Top = 16
      Width = 28
      Height = 13
      Caption = 'Axis 3'
    end
    object Edit_ShowAxis_Command_0: TEdit
      Left = 112
      Top = 32
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = 'Edit1'
    end
    object Edit_ShowAxis_Feedback_0: TEdit
      Left = 112
      Top = 72
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = 'Edit1'
    end
    object Edit_ShowAxis_IOSts_0: TEdit
      Left = 112
      Top = 112
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = 'Edit1'
    end
    object Edit_ShowAxis_MSts_0: TEdit
      Left = 112
      Top = 152
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Text = 'Edit1'
    end
    object Edit_ShowAxis_Command_1: TEdit
      Left = 240
      Top = 32
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Text = 'Edit1'
    end
    object Edit_ShowAxis_Feedback_1: TEdit
      Left = 240
      Top = 72
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      Text = 'Edit1'
    end
    object Edit_ShowAxis_IOSts_1: TEdit
      Left = 240
      Top = 112
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      Text = 'Edit1'
    end
    object Edit_ShowAxis_MSts_1: TEdit
      Left = 240
      Top = 152
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      Text = 'Edit1'
    end
    object Edit_ShowAxis_Command_2: TEdit
      Left = 368
      Top = 32
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      Text = 'Edit1'
    end
    object Edit_ShowAxis_Feedback_2: TEdit
      Left = 368
      Top = 72
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      Text = 'Edit1'
    end
    object Edit_ShowAxis_IOSts_2: TEdit
      Left = 368
      Top = 112
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
      Text = 'Edit1'
    end
    object Edit_ShowAxis_MSts_2: TEdit
      Left = 368
      Top = 152
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 11
      Text = 'Edit1'
    end
    object Edit_ShowAxis_Command_3: TEdit
      Left = 504
      Top = 32
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 12
      Text = 'Edit1'
    end
    object Edit_ShowAxis_Feedback_3: TEdit
      Left = 504
      Top = 72
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 13
      Text = 'Edit1'
    end
    object Edit_ShowAxis_IOSts_3: TEdit
      Left = 504
      Top = 112
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 14
      Text = 'Edit1'
    end
    object Edit_ShowAxis_MSts_3: TEdit
      Left = 504
      Top = 152
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 15
      Text = 'Edit1'
    end
    object ResetCounter: TButton
      Left = 648
      Top = 59
      Width = 73
      Height = 81
      Caption = 'ResetCounter'
      TabOrder = 16
      OnClick = ResetCounterClick
    end
  end
  object GroupBox6: TGroupBox
    Left = 9
    Top = 199
    Width = 201
    Height = 169
    Caption = 'Single Absolute Move'
    TabOrder = 1
    object Btn_SingleAbsoluteMove_Backward: TButton
      Left = 25
      Top = 33
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_SingleAbsoluteMove_BackwardClick
    end
    object Btn_SingleAbsoluteMove_Forward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_SingleAbsoluteMove_ForwardClick
    end
    object Btn_SingleAbsoluteMove_Stop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_SingleAbsoluteMove_StopClick
    end
  end
  object GroupBox7: TGroupBox
    Left = 216
    Top = 199
    Width = 201
    Height = 169
    Caption = 'Single Relative Move'
    TabOrder = 2
    object Btn_SingleRelativeMove_Backward: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_SingleRelativeMove_BackwardClick
    end
    object Btn_SingleRelativeMove_Forward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_SingleRelativeMove_ForwardClick
    end
    object Btn_SingleRelativeMove_Stop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_SingleRelativeMove_StopClick
    end
  end
  object GroupBox8: TGroupBox
    Left = 425
    Top = 199
    Width = 201
    Height = 169
    Caption = 'Single Home Move'
    TabOrder = 3
    object Btn_SingleHomeMove_Backward: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_SingleHomeMove_BackwardClick
    end
    object Btn_SingleHomeMove_Forward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_SingleHomeMove_ForwardClick
    end
    object Btn_SingleHomeMove_Stop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_SingleHomeMove_StopClick
    end
  end
  object GroupBox9: TGroupBox
    Left = 633
    Top = 199
    Width = 201
    Height = 169
    Caption = '2 Axes Linear Absolute Move'
    TabOrder = 4
    object Btn_Linear_2Axes_AbsoluteBackward: TButton
      Left = 25
      Top = 33
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Linear_2Axes_AbsoluteBackwardClick
    end
    object Btn_Linear_2Axes_AbsoluteForward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_Linear_2Axes_AbsoluteForwardClick
    end
    object Btn_Linear_2Axes_AbsoluteStop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_2Axes_AbsoluteStopClick
    end
  end
  object GroupBox10: TGroupBox
    Left = 839
    Top = 199
    Width = 201
    Height = 169
    Caption = '2 Axes Linear Relative Move'
    TabOrder = 5
    object Btn_Linear_2Axes_RelateiveBackward: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Linear_2Axes_RelateiveBackwardClick
    end
    object Btn_Linear_2Axes_RelateiveForward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_Linear_2Axes_RelateiveForwardClick
    end
    object Btn_Linear_2Axes_Relateive_Stop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_2Axes_Relateive_StopClick
    end
  end
  object GroupBox11: TGroupBox
    Left = 422
    Top = 374
    Width = 201
    Height = 169
    Caption = '3 Axes Linear Absolute Move'
    TabOrder = 6
    object Btn_Linear_3Axes_AbsoluteBackward: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Linear_3Axes_AbsoluteBackwardClick
    end
    object Btn_Linear_3Axes_AbsoluteForward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_Linear_3Axes_AbsoluteForwardClick
    end
    object Btn_Linear_3Axes_AbsoluteStop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_3Axes_AbsoluteStopClick
    end
  end
  object GroupBox12: TGroupBox
    Left = 633
    Top = 374
    Width = 201
    Height = 169
    Caption = '3 Axes Linear Relative Move'
    TabOrder = 7
    object Btn_Linear_3Axes_RelateiveBackward: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Linear_3Axes_RelateiveBackwardClick
    end
    object Btn_Linear_3Axes_RelateiveForward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_Linear_3Axes_RelateiveForwardClick
    end
    object Btn_Linear_3Axes_Relateive_Stop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_3Axes_Relateive_StopClick
    end
  end
  object GroupBox13: TGroupBox
    Left = 839
    Top = 374
    Width = 200
    Height = 169
    Caption = '4 Axes Linear Absolute Move'
    TabOrder = 8
    object Btn_Linear_4Axes_AbsoluteBackward: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Linear_4Axes_AbsoluteBackwardClick
    end
    object Btn_Linear_4Axes_AbsoluteForward: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_Linear_4Axes_AbsoluteForwardClick
    end
    object Btn_Linear_4Axes_AbsoluteStop: TButton
      Left = 56
      Top = 95
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_4Axes_AbsoluteStopClick
    end
  end
  object GroupBox14: TGroupBox
    Left = 8
    Top = 549
    Width = 201
    Height = 172
    Caption = '4 Axes Linear Relative Move'
    TabOrder = 9
    object Btn_Linear_4Axes_RelateiveBackward: TButton
      Left = 17
      Top = 25
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Linear_4Axes_RelateiveBackwardClick
    end
    object Btn_Linear_4Axes_RelateiveForward: TButton
      Left = 104
      Top = 24
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_Linear_4Axes_RelateiveForwardClick
    end
    object Btn_Linear_4Axes_Relateive_Stop: TButton
      Left = 56
      Top = 96
      Width = 81
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_4Axes_Relateive_StopClick
    end
  end
  object GroupBox19: TGroupBox
    Left = 9
    Top = 374
    Width = 201
    Height = 169
    Caption = '2 Axes Arc Absolute Move'
    TabOrder = 10
    object Btn_Arc_2Axes_Absolute_CCW: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'CCW'
      TabOrder = 0
      OnClick = Btn_Arc_2Axes_Absolute_CCWClick
    end
    object Btn_Arc_2Axes_Absolute_CW: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'CW'
      TabOrder = 1
      OnClick = Btn_Arc_2Axes_Absolute_CWClick
    end
    object Btn_Arc_2Axes_Absolute_Stop2: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Arc_2Axes_Absolute_Stop2Click
    end
  end
  object GroupBox20: TGroupBox
    Left = 215
    Top = 374
    Width = 201
    Height = 169
    Caption = '2 Axes Arc Relative Move'
    TabOrder = 11
    object Btn_Arc_2Axes_Relative_CCW: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'CCW'
      TabOrder = 0
      OnClick = Btn_Arc_2Axes_Relative_CCWClick
    end
    object Btn_Arc_2Axes_Relative_CW: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'CW'
      TabOrder = 1
      OnClick = Btn_Arc_2Axes_Relative_CWClick
    end
    object Btn_Arc_2Axes_Relateive_Stop: TButton
      Left = 56
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Arc_2Axes_Relateive_StopClick
    end
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 193
    Height = 185
    Caption = 'Master Card Info'
    TabOrder = 12
    object Label1: TLabel
      Left = 32
      Top = 32
      Width = 66
      Height = 13
      Caption = 'Driver Version'
    end
    object Label2: TLabel
      Left = 32
      Top = 72
      Width = 58
      Height = 13
      Caption = 'DLL Version'
    end
    object Label3: TLabel
      Left = 32
      Top = 112
      Width = 66
      Height = 13
      Caption = 'FPGA Version'
    end
    object Edit_ShowMaster_DriverVer: TEdit
      Left = 32
      Top = 48
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Text = '0'
    end
    object Edit_ShowMaster_DLLVer: TEdit
      Left = 32
      Top = 88
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = 'Edit1'
    end
    object Edit_ShowMaster_CPLDVer: TEdit
      Left = 32
      Top = 128
      Width = 121
      Height = 23
      Color = clWindowFrame
      Font.Charset = ANSI_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Text = 'Edit1'
    end
  end
  object Edit1: TEdit
    Left = 264
    Top = 598
    Width = 97
    Height = 21
    TabOrder = 13
    Text = '0'
  end
  object Button1: TButton
    Left = 264
    Top = 625
    Width = 97
    Height = 41
    Caption = 'Set Card ID'
    TabOrder = 14
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Left = 1008
    Top = 552
  end
end
