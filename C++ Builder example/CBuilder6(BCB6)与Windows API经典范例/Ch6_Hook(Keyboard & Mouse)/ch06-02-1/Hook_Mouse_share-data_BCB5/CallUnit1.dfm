object CallHookForm: TCallHookForm
  Left = 194
  Top = 112
  Width = 317
  Height = 97
  Caption = 'CallHookForm__'#40736#26631'Hook'#27979#35797
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 309
    Height = 28
    AutoSize = True
    Caption = 'ToolBar1'
    EdgeBorders = [ebLeft, ebTop, ebRight, ebBottom]
    TabOrder = 0
    object Button1: TButton
      Left = 0
      Top = 2
      Width = 125
      Height = 22
      Caption = 'Button1_'#25346#19978'Hook'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 125
      Top = 2
      Width = 125
      Height = 22
      Caption = 'Button2_'#21368#19979'Hook'
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object Edit1: TEdit
    Left = 0
    Top = 31
    Width = 309
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ImeName = #20013#25991' ('#31616#20307') - '#26234#33021' ABC'
    ParentFont = False
    TabOrder = 1
    Text = 'Edit1'
  end
end
