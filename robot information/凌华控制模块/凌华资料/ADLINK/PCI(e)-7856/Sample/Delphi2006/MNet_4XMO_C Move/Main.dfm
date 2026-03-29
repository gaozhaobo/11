object Form1: TForm1
  Left = 110
  Top = 68
  Caption = 'MNet-4XMO-C-Delphi7-Sample'
  ClientHeight = 732
  ClientWidth = 1252
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
  object GroupBox3: TGroupBox
    Left = 512
    Top = 8
    Width = 657
    Height = 185
    Caption = 'Axis Info'
    TabOrder = 0
    object Label7: TLabel
      Left = 16
      Top = 16
      Width = 56
      Height = 13
      Caption = 'Command 0'
    end
    object Label8: TLabel
      Left = 16
      Top = 56
      Width = 57
      Height = 13
      Caption = 'Feedback 0'
    end
    object Label9: TLabel
      Left = 16
      Top = 96
      Width = 53
      Height = 13
      Caption = 'IO Status 0'
    end
    object Label10: TLabel
      Left = 16
      Top = 136
      Width = 74
      Height = 13
      Caption = 'Motion Status 0'
    end
    object Label11: TLabel
      Left = 144
      Top = 16
      Width = 56
      Height = 13
      Caption = 'Command 1'
    end
    object Label12: TLabel
      Left = 144
      Top = 56
      Width = 57
      Height = 13
      Caption = 'Feedback 1'
    end
    object Label13: TLabel
      Left = 144
      Top = 96
      Width = 53
      Height = 13
      Caption = 'IO Status 1'
    end
    object Label14: TLabel
      Left = 144
      Top = 136
      Width = 74
      Height = 13
      Caption = 'Motion Status 1'
    end
    object Label15: TLabel
      Left = 272
      Top = 16
      Width = 56
      Height = 13
      Caption = 'Command 2'
    end
    object Label16: TLabel
      Left = 272
      Top = 56
      Width = 57
      Height = 13
      Caption = 'Feedback 2'
    end
    object Label17: TLabel
      Left = 272
      Top = 96
      Width = 53
      Height = 13
      Caption = 'IO Status 2'
    end
    object Label18: TLabel
      Left = 272
      Top = 136
      Width = 74
      Height = 13
      Caption = 'Motion Status 2'
    end
    object Label19: TLabel
      Left = 400
      Top = 16
      Width = 56
      Height = 13
      Caption = 'Command 3'
    end
    object Label20: TLabel
      Left = 400
      Top = 56
      Width = 57
      Height = 13
      Caption = 'Feedback 3'
    end
    object Label21: TLabel
      Left = 400
      Top = 96
      Width = 53
      Height = 13
      Caption = 'IO Status 3'
    end
    object Label22: TLabel
      Left = 400
      Top = 136
      Width = 74
      Height = 13
      Caption = 'Motion Status 3'
    end
    object Edit_ShowAxis_Command_0: TEdit
      Left = 16
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
      Left = 16
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
      Left = 16
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
      Left = 16
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
      Left = 144
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
      Left = 144
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
      Left = 144
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
      Left = 144
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
      Left = 272
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
      Left = 272
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
      Left = 272
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
      Left = 272
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
      Left = 400
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
      Left = 400
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
      Left = 400
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
      Left = 400
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
      Left = 528
      Top = 24
      Width = 113
      Height = 153
      Caption = 'ResetCounter'
      TabOrder = 16
      OnClick = ResetCounterClick
    end
  end
  object GroupBox4: TGroupBox
    Left = 8
    Top = 192
    Width = 201
    Height = 169
    Caption = 'Step1: Bus Start/Stop'
    TabOrder = 1
    object Btn_BusConnect: TButton
      Left = 40
      Top = 24
      Width = 113
      Height = 49
      Caption = 'Connect'
      TabOrder = 0
      OnClick = Btn_BusConnectClick
    end
    object Btn_BusDisconnect: TButton
      Left = 40
      Top = 88
      Width = 113
      Height = 49
      Caption = 'Disconnect'
      TabOrder = 1
      OnClick = Btn_BusDisconnectClick
    end
  end
  object GroupBox5: TGroupBox
    Left = 216
    Top = 192
    Width = 201
    Height = 169
    Caption = 'Module Info'
    TabOrder = 2
    object Label23: TLabel
      Left = 40
      Top = 32
      Width = 49
      Height = 13
      Caption = 'Module ID'
    end
    object Edit_SetModuleID_ForModuleInfo: TEdit
      Left = 40
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Btn_GetModuleInfo: TButton
      Left = 40
      Top = 80
      Width = 121
      Height = 49
      Caption = 'GetModuleInfo'
      TabOrder = 1
      OnClick = Btn_GetModuleInfoClick
    end
  end
  object GroupBox6: TGroupBox
    Left = 424
    Top = 192
    Width = 201
    Height = 169
    Caption = 'Single Absolute Move'
    TabOrder = 3
    object Btn_SingleAbsoluteMove_Backward: TButton
      Left = 16
      Top = 32
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
    Left = 632
    Top = 192
    Width = 201
    Height = 169
    Caption = 'Single Relative Move'
    TabOrder = 4
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
    Left = 840
    Top = 192
    Width = 201
    Height = 169
    Caption = 'Single Home Move'
    TabOrder = 5
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
    Left = 1048
    Top = 192
    Width = 201
    Height = 169
    Caption = '2 Axes Linear Absolute Move'
    TabOrder = 6
    object Btn_Linear_2Axes_AbsoluteBackward: TButton
      Left = 16
      Top = 32
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
    Left = 16
    Top = 360
    Width = 201
    Height = 169
    Caption = '2 Axes Linear Relative Move'
    TabOrder = 7
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
    Left = 632
    Top = 360
    Width = 201
    Height = 169
    Caption = '3 Axes Linear Absolute Move'
    TabOrder = 8
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
    Left = 840
    Top = 360
    Width = 201
    Height = 169
    Caption = '3 Axes Linear Relative Move'
    TabOrder = 9
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
    Left = 1048
    Top = 360
    Width = 200
    Height = 169
    Caption = '4 Axes Linear Absolute Move'
    TabOrder = 10
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
      Top = 96
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_4Axes_AbsoluteStopClick
    end
  end
  object GroupBox14: TGroupBox
    Left = 8
    Top = 528
    Width = 201
    Height = 193
    Caption = '4 Axes Linear Relative Move'
    TabOrder = 11
    object Btn_Linear_4Axes_RelateiveBackward: TButton
      Left = 16
      Top = 48
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Linear_4Axes_RelateiveBackwardClick
    end
    object Btn_Linear_4Axes_RelateiveForward: TButton
      Left = 104
      Top = 48
      Width = 73
      Height = 57
      Caption = 'Forward'
      TabOrder = 1
      OnClick = Btn_Linear_4Axes_RelateiveForwardClick
    end
    object Btn_Linear_4Axes_Relateive_Stop: TButton
      Left = 56
      Top = 112
      Width = 73
      Height = 57
      Caption = 'Stop'
      TabOrder = 2
      OnClick = Btn_Linear_4Axes_Relateive_StopClick
    end
  end
  object GroupBox15: TGroupBox
    Left = 424
    Top = 528
    Width = 409
    Height = 193
    Caption = 'Point Table'
    TabOrder = 12
    object Label24: TLabel
      Left = 16
      Top = 32
      Width = 69
      Height = 13
      Caption = 'Running Index'
    end
    object Edit_Show_PointTable_CurrIndex: TEdit
      Left = 96
      Top = 32
      Width = 105
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
    object GroupBox17: TGroupBox
      Left = 16
      Top = 64
      Width = 201
      Height = 113
      Caption = 'Single Index Move'
      TabOrder = 1
      object Label25: TLabel
        Left = 104
        Top = 8
        Width = 60
        Height = 13
        Caption = 'Target Index'
      end
      object Btn_SetPointTable: TButton
        Left = 8
        Top = 16
        Width = 89
        Height = 89
        Caption = 'Step1:Set Table'
        TabOrder = 0
        OnClick = Btn_SetPointTableClick
      end
      object Edit_SetTargetIndex_ForSinglePointMove: TEdit
        Left = 104
        Top = 24
        Width = 89
        Height = 21
        TabOrder = 1
        Text = '10'
      end
      object Btn_PointTable_SingleIndexMove: TButton
        Left = 104
        Top = 48
        Width = 89
        Height = 57
        Caption = 'Step2: Movetop'
        TabOrder = 2
        OnClick = Btn_PointTable_SingleIndexMoveClick
      end
    end
    object GroupBox18: TGroupBox
      Left = 224
      Top = 64
      Width = 169
      Height = 113
      Caption = 'All Index Move'
      TabOrder = 2
      object Btn_PointTable_MoveALL: TButton
        Left = 8
        Top = 16
        Width = 153
        Height = 89
        Caption = 'Set Points and Move'
        TabOrder = 0
        OnClick = Btn_PointTable_MoveALLClick
      end
    end
    object Btn_PointTable_Stop: TButton
      Left = 224
      Top = 32
      Width = 169
      Height = 25
      Caption = 'Stop'
      TabOrder = 3
      OnClick = Btn_PointTable_StopClick
    end
  end
  object GroupBox16: TGroupBox
    Left = 840
    Top = 528
    Width = 409
    Height = 193
    Caption = 'Compare'
    TabOrder = 13
    object Label26: TLabel
      Left = 16
      Top = 16
      Width = 58
      Height = 13
      Caption = 'TriggerCnt 0'
    end
    object Label27: TLabel
      Left = 112
      Top = 16
      Width = 58
      Height = 13
      Caption = 'TriggerCnt 1'
    end
    object Label28: TLabel
      Left = 208
      Top = 16
      Width = 58
      Height = 13
      Caption = 'TriggerCnt 2'
    end
    object Label29: TLabel
      Left = 304
      Top = 16
      Width = 58
      Height = 13
      Caption = 'TriggerCnt 3'
    end
    object Label30: TLabel
      Left = 16
      Top = 56
      Width = 61
      Height = 13
      Caption = 'TriggerEnc 0'
    end
    object Label31: TLabel
      Left = 112
      Top = 56
      Width = 61
      Height = 13
      Caption = 'TriggerEnc 1'
    end
    object Label32: TLabel
      Left = 208
      Top = 56
      Width = 61
      Height = 13
      Caption = 'TriggerEnc 2'
    end
    object Label33: TLabel
      Left = 304
      Top = 56
      Width = 61
      Height = 13
      Caption = 'TriggerEnc 3'
    end
    object Label34: TLabel
      Left = 16
      Top = 96
      Width = 47
      Height = 13
      Caption = 'CMPVal 0'
    end
    object Label35: TLabel
      Left = 112
      Top = 96
      Width = 47
      Height = 13
      Caption = 'CMPVal 1'
    end
    object Label36: TLabel
      Left = 208
      Top = 96
      Width = 47
      Height = 13
      Caption = 'CMPVal 2'
    end
    object Label37: TLabel
      Left = 304
      Top = 96
      Width = 47
      Height = 13
      Caption = 'CMPVal 3'
    end
    object Edit_ShowTriggerCount_0: TEdit
      Left = 16
      Top = 32
      Width = 89
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
    object Edit_ShowTriggerCount_1: TEdit
      Left = 112
      Top = 32
      Width = 89
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
    object Edit_ShowTriggerCount_2: TEdit
      Left = 208
      Top = 32
      Width = 89
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
    object Edit_ShowTriggerCount_3: TEdit
      Left = 304
      Top = 32
      Width = 89
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
    object Edit_ShowTriggerEnc_0: TEdit
      Left = 16
      Top = 72
      Width = 89
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
    object Edit_ShowTriggerEnc_1: TEdit
      Left = 112
      Top = 72
      Width = 89
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
    object Edit_ShowTriggerEnc_2: TEdit
      Left = 208
      Top = 72
      Width = 89
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
    object Edit_ShowTriggerEnc_3: TEdit
      Left = 304
      Top = 72
      Width = 89
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
    object Edit_ShowTrigger_LinearCMP_LinearCMP_0: TEdit
      Left = 16
      Top = 112
      Width = 89
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
    object Edit_ShowTrigger_LinearCMP_LinearCMP_1: TEdit
      Left = 112
      Top = 112
      Width = 89
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
    object Edit_ShowTrigger_LinearCMP_LinearCMP_2: TEdit
      Left = 208
      Top = 112
      Width = 89
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
    object Edit_ShowTrigger_LinearCMP_LinearCMP_3: TEdit
      Left = 304
      Top = 112
      Width = 89
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
    object Btn_Linear_Compare: TButton
      Left = 16
      Top = 144
      Width = 89
      Height = 41
      Caption = 'LineCMP '
      TabOrder = 12
      OnClick = Btn_Linear_CompareClick
    end
    object Btn_Table_Compare: TButton
      Left = 112
      Top = 144
      Width = 89
      Height = 41
      Caption = 'Table CMP'
      TabOrder = 13
      OnClick = Btn_Table_CompareClick
    end
    object Btn_Manual_Compare: TButton
      Left = 208
      Top = 144
      Width = 89
      Height = 41
      Caption = 'Manual CMP'
      TabOrder = 14
      OnClick = Btn_Manual_CompareClick
    end
    object Btn_Trigger_Count: TButton
      Left = 304
      Top = 144
      Width = 89
      Height = 41
      Caption = 'Reset TRG Cnt.'
      TabOrder = 15
      OnClick = Btn_Trigger_CountClick
    end
  end
  object GroupBox19: TGroupBox
    Left = 216
    Top = 360
    Width = 201
    Height = 169
    Caption = '2 Axes Arc Absolute Move'
    TabOrder = 14
    object Btn_Arc_2Axes_Absolute_CCW: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Arc_2Axes_Absolute_CCWClick
    end
    object Btn_Arc_2Axes_Absolute_CW: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
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
    Left = 424
    Top = 360
    Width = 201
    Height = 169
    Caption = '2 Axes Arc Relative Move'
    TabOrder = 15
    object Btn_Arc_2Axes_Relative_CCW: TButton
      Left = 16
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Backward'
      TabOrder = 0
      OnClick = Btn_Arc_2Axes_Relative_CCWClick
    end
    object Btn_Arc_2Axes_Relative_CW: TButton
      Left = 104
      Top = 32
      Width = 73
      Height = 57
      Caption = 'Forward'
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
  object GroupBox21: TGroupBox
    Left = 216
    Top = 528
    Width = 201
    Height = 193
    Caption = 'General DIO'
    TabOrder = 16
    object Label38: TLabel
      Left = 40
      Top = 16
      Width = 49
      Height = 13
      Caption = 'Module ID'
    end
    object Label39: TLabel
      Left = 24
      Top = 64
      Width = 40
      Height = 13
      Caption = 'DI_Data'
    end
    object Label40: TLabel
      Left = 24
      Top = 128
      Width = 45
      Height = 13
      Caption = 'DO_Data'
    end
    object Label41: TLabel
      Left = 112
      Top = 64
      Width = 64
      Height = 13
      Caption = 'Chk_DOData'
    end
    object Edit_SetModuleID_ForGeneralDIO: TEdit
      Left = 40
      Top = 32
      Width = 121
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Edit_ShowDIData: TEdit
      Left = 24
      Top = 80
      Width = 73
      Height = 21
      Color = clNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '0'
    end
    object Edit_SetDOData: TEdit
      Left = 24
      Top = 144
      Width = 73
      Height = 21
      TabOrder = 2
      Text = '0'
    end
    object Btn_Set_DOData: TButton
      Left = 112
      Top = 120
      Width = 73
      Height = 49
      Caption = 'Set DO'
      TabOrder = 3
      OnClick = Btn_Set_DODataClick
    end
    object Edit_GetDOData: TEdit
      Left = 112
      Top = 80
      Width = 73
      Height = 21
      Color = clNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Text = '0'
    end
  end
  object GroupBox1: TGroupBox
    Left = 136
    Top = 8
    Width = 193
    Height = 185
    Caption = 'Master Card Info'
    TabOrder = 17
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
      Caption = 'CPLD Version'
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
  object GroupBox2: TGroupBox
    Left = 336
    Top = 8
    Width = 169
    Height = 185
    Caption = 'Module Info'
    TabOrder = 18
    object Label5: TLabel
      Left = 32
      Top = 32
      Width = 66
      Height = 13
      Caption = 'FPGA Version'
    end
    object Label6: TLabel
      Left = 32
      Top = 72
      Width = 65
      Height = 13
      Caption = 'PCB Top Ver.'
    end
    object Label4: TLabel
      Left = 32
      Top = 112
      Width = 79
      Height = 13
      Caption = 'PCB Bottom Ver.'
    end
    object Edit_ShowModule_FPGAVer: TEdit
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
      Text = 'No Data'
    end
    object Edit_ShowModule_PCBTopVer: TEdit
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
      Text = 'No Data'
    end
    object Edit_ShowMaster_PCBBottomVer: TEdit
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
      Text = 'No Data'
    end
  end
  object Timer1: TTimer
    Interval = 50
    OnTimer = Timer1Timer
    Left = 392
    Top = 16
  end
end
