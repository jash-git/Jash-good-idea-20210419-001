object MainForm: TMainForm
  Left = 174
  Top = 114
  Width = 463
  Height = 215
  Caption = '受监控端'
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
  object Label1: TLabel
    Left = 64
    Top = 24
    Width = 66
    Height = 13
    Caption = '主控机IP：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object EdtRemoteAddress: TEdit
    Left = 136
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '127.0.0.1'
  end
  object ChkBoxHide: TCheckBox
    Left = 296
    Top = 16
    Width = 97
    Height = 17
    Caption = '隐藏窗口'
    TabOrder = 1
    OnClick = ChkBoxHideClick
  end
  object CUDP: TNMUDP
    RemoteHost = '202.204.49.45'
    RemotePort = 2222
    LocalPort = 1111
    ReportLevel = 1
    OnDataReceived = CUDPDataReceived
    Left = 120
    Top = 56
  end
end
