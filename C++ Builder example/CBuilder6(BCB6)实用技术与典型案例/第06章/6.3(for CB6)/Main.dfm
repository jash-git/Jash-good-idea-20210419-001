object MainForm: TMainForm
  Left = 166
  Top = 178
  Width = 634
  Height = 394
  Caption = 'API'#27979#35797#31383#21475
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  PixelsPerInch = 96
  TextHeight = 13
  object LabelCapture: TLabel
    Left = 32
    Top = 16
    Width = 78
    Height = 13
    Caption = #24744#25429#25417#30340#31383#21475
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object LabelHasCapture: TLabel
    Left = 32
    Top = 40
    Width = 104
    Height = 13
    Caption = #24050#32463#25429#25417#21040#30340#31383#21475
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label2: TLabel
    Left = 368
    Top = 40
    Width = 65
    Height = 13
    Caption = #31383#21475#30340#20449#24687
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 329
    Width = 626
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object ListBoxCapture: TListBox
    Left = 24
    Top = 64
    Width = 257
    Height = 249
    ItemHeight = 13
    TabOrder = 1
  end
  object PanelInfo: TPanel
    Left = 368
    Top = 64
    Width = 185
    Height = 249
    BorderStyle = bsSingle
    TabOrder = 2
    object Label3: TLabel
      Left = 12
      Top = 16
      Width = 65
      Height = 13
      Caption = #31383#21475#23485#24230#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Label4: TLabel
      Left = 12
      Top = 40
      Width = 65
      Height = 13
      Caption = #31383#21475#39640#24230#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Label5: TLabel
      Left = 12
      Top = 88
      Width = 78
      Height = 13
      Caption = #23458#25143#21306#39640#24230#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Label6: TLabel
      Left = 12
      Top = 64
      Width = 78
      Height = 13
      Caption = #23458#25143#21306#23485#24230#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
  end
  object CheckBoxHide: TCheckBox
    Left = 320
    Top = 8
    Width = 297
    Height = 17
    Caption = #19979#19968#27425#36816#34892#26102#33258#21160#38544#34255#24182#31105#27490#20197#21069#25429#25417#30340#31383#21475#36816#34892
    TabOrder = 3
  end
  object BtnClearSelect: TButton
    Left = 280
    Top = 72
    Width = 75
    Height = 25
    Caption = #28165#38500#36873#25321
    TabOrder = 4
    OnClick = BtnClearSelectClick
  end
  object MainMenu: TMainMenu
    Left = 168
    Top = 8
    object MenuHide: TMenuItem
      Caption = #38544#34255
      OnClick = MenuHideClick
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = Timer1Timer
    Left = 208
    Top = 8
  end
end
