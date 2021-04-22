object KeyHookForm: TKeyHookForm
  Left = 192
  Top = 107
  Width = 274
  Height = 270
  Caption = 'KeyHookForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 266
    Height = 28
    AutoSize = True
    ButtonWidth = 102
    Color = 13828050
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    ParentColor = False
    TabOrder = 0
    object Button1: TButton
      Left = 0
      Top = 2
      Width = 102
      Height = 22
      Caption = 'Button1_'#25346#19978'Hook'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 102
      Top = 2
      Width = 102
      Height = 22
      Caption = 'Button2_'#21368#19979'Hook'
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object ListBox1: TListBox
    Left = 0
    Top = 28
    Width = 266
    Height = 215
    Align = alClient
    ImeName = #32043#20809#25340#38899#36755#20837#27861
    ItemHeight = 13
    TabOrder = 1
  end
end
