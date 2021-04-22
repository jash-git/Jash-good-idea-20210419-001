object MainForm: TMainForm
  Left = 56
  Top = 75
  Width = 356
  Height = 436
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 296
    Width = 48
    Height = 16
    Caption = '句柄号：'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 40
    Top = 344
    Width = 91
    Height = 13
    Caption = '检察时间间隔：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object CheckBox1: TCheckBox
    Left = 48
    Top = 24
    Width = 281
    Height = 17
    Caption = '下一次运行时自动隐藏并禁止以前捕捉的窗口运行'
    TabOrder = 0
  end
  object Button1: TButton
    Left = 48
    Top = 56
    Width = 105
    Height = 25
    Caption = '清除窗口列表'
    TabOrder = 1
    OnClick = Button1Click
  end
  object ListBoxCptureInfo: TListBox
    Left = 48
    Top = 112
    Width = 233
    Height = 169
    ItemHeight = 13
    TabOrder = 2
  end
  object Button2: TButton
    Left = 176
    Top = 56
    Width = 113
    Height = 25
    Caption = '关闭后台检测程序'
    TabOrder = 3
    OnClick = Button2Click
  end
  object EdtHwn: TEdit
    Left = 128
    Top = 296
    Width = 121
    Height = 21
    Enabled = False
    TabOrder = 4
  end
  object EdtInterval: TEdit
    Left = 128
    Top = 336
    Width = 121
    Height = 21
    TabOrder = 5
  end
end
