object MainForm: TMainForm
  Left = 238
  Top = 116
  Width = 343
  Height = 383
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BtnOpen: TButton
    Left = 88
    Top = 248
    Width = 75
    Height = 25
    Caption = '打开帮助'
    TabOrder = 0
    OnClick = BtnOpenClick
  end
  object RadioGroup1: TRadioGroup
    Left = 40
    Top = 24
    Width = 185
    Height = 169
    Caption = '选择调用的方法'
    Items.Strings = (
      'HelpContext'
      'HelpCommand'
      'HelpJump'
      'WinHelp')
    TabOrder = 1
  end
end
