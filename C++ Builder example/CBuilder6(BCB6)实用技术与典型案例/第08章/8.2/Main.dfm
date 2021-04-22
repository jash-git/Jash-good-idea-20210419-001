object Form1: TForm1
  Left = 4
  Top = 0
  Width = 789
  Height = 518
  Caption = 'Form1'
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
  object Panel1: TPanel
    Left = 0
    Top = 49
    Width = 781
    Height = 423
    Align = alBottom
    BorderStyle = bsSingle
    Caption = 'Panel1'
    TabOrder = 0
    object CppWebBrowser1: TCppWebBrowser
      Left = 1
      Top = 1
      Width = 775
      Height = 417
      TabStop = True
      Align = alClient
      TabOrder = 0
      OnProgressChange = CppWebBrowser1ProgressChange
      OnDownloadBegin = CppWebBrowser1DownloadBegin
      OnDownloadComplete = CppWebBrowser1DownloadComplete
      ControlData = {
        4C00000019500000192B00000000000000000000000000000000000000000000
        000000004C000000000000000000000001000000E0D057007335CF11AE690800
        2B2E126208000000000000004C0000000114020000000000C000000000000046
        8000000000000000000000000000000000000000000000000000000000000000
        000000000000000001000000000000000000000000000000}
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 472
    Width = 781
    Height = 19
    Panels = <
      item
        Width = 200
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 781
    Height = 33
    Align = alTop
    TabOrder = 2
    object BtnForward: TSpeedButton
      Left = 8
      Top = 8
      Width = 49
      Height = 22
      Caption = '前一页'
      Flat = True
      OnClick = BtnForwardClick
    end
    object BtnBack: TSpeedButton
      Left = 64
      Top = 8
      Width = 49
      Height = 22
      Caption = '后一页'
      Flat = True
      OnClick = BtnBackClick
    end
    object BtnHome: TSpeedButton
      Left = 120
      Top = 8
      Width = 49
      Height = 22
      Caption = '主页'
      Flat = True
      OnClick = BtnHomeClick
    end
    object BtnGoto: TSpeedButton
      Left = 704
      Top = 8
      Width = 49
      Height = 22
      Caption = '转到'
      Flat = True
      OnClick = BtnGotoClick
    end
    object SpeedButton5: TSpeedButton
      Left = 176
      Top = 8
      Width = 49
      Height = 22
      Caption = '刷新'
      Flat = True
      OnClick = SpeedButton5Click
    end
    object BtnStop: TSpeedButton
      Left = 232
      Top = 8
      Width = 49
      Height = 22
      Caption = '停止'
      Flat = True
      OnClick = BtnStopClick
    end
    object CmbURL: TComboBox
      Left = 280
      Top = 8
      Width = 417
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Text = 'www.263.net'
      OnKeyDown = CmbURLKeyDown
    end
  end
end
