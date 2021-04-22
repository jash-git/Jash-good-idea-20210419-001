object MainForm: TMainForm
  Left = 124
  Top = 178
  Width = 634
  Height = 394
  Caption = 'API测试窗口'
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
    Caption = '您捕捉的窗口'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object LabelHasCapture: TLabel
    Left = 32
    Top = 40
    Width = 104
    Height = 13
    Caption = '已经捕捉到的窗口'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label2: TLabel
    Left = 368
    Top = 40
    Width = 65
    Height = 13
    Caption = '窗口的信息'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
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
      Caption = '窗口宽度：'
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Label4: TLabel
      Left = 12
      Top = 40
      Width = 65
      Height = 13
      Caption = '窗口高度：'
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Label5: TLabel
      Left = 12
      Top = 88
      Width = 78
      Height = 13
      Caption = '客户区高度：'
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = '宋体'
      Font.Style = []
      ParentFont = False
      Transparent = True
    end
    object Label6: TLabel
      Left = 12
      Top = 64
      Width = 78
      Height = 13
      Caption = '客户区宽度：'
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = '宋体'
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
    Caption = '下一次运行时自动隐藏并禁止以前捕捉的窗口运行'
    TabOrder = 3
  end
  object BtnClearSelect: TButton
    Left = 280
    Top = 72
    Width = 75
    Height = 25
    Caption = '清除选择'
    TabOrder = 4
    OnClick = BtnClearSelectClick
  end
  object MainMenu: TMainMenu
    Left = 168
    Top = 8
    object MenuHide: TMenuItem
      Caption = '隐藏'
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
