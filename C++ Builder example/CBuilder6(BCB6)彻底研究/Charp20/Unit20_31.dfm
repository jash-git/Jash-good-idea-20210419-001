object Form1: TForm1
  Left = 330
  Top = 135
  Width = 694
  Height = 565
  Caption = #35843#29992#27880#20876#22312' http://www.xmethods.com '#30340' Web Service'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 20
  object Label1: TLabel
    Left = 26
    Top = 13
    Width = 96
    Height = 20
    Caption = 'Delphi News :'
  end
  object Label2: TLabel
    Left = 26
    Top = 101
    Width = 133
    Height = 20
    Caption = 'C++ Builder News :'
  end
  object Label3: TLabel
    Left = 26
    Top = 189
    Width = 108
    Height = 20
    Caption = 'JBuilder News :'
  end
  object Label4: TLabel
    Left = 26
    Top = 277
    Width = 81
    Height = 20
    Caption = 'Kylix News :'
  end
  object Label5: TLabel
    Left = 26
    Top = 365
    Width = 95
    Height = 20
    Caption = 'SOAP News :'
  end
  object Label6: TLabel
    Left = 26
    Top = 453
    Width = 106
    Height = 20
    Caption = 'Borland News :'
  end
  object Memo1: TMemo
    Left = 24
    Top = 38
    Width = 641
    Height = 49
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object Memo2: TMemo
    Left = 24
    Top = 126
    Width = 641
    Height = 49
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Memo3: TMemo
    Left = 24
    Top = 214
    Width = 641
    Height = 49
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Memo4: TMemo
    Left = 24
    Top = 302
    Width = 641
    Height = 49
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 3
  end
  object Memo5: TMemo
    Left = 24
    Top = 390
    Width = 641
    Height = 49
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object Memo6: TMemo
    Left = 24
    Top = 478
    Width = 641
    Height = 49
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Button1: TButton
    Left = 536
    Top = 5
    Width = 123
    Height = 28
    Caption = #26597#35810#26368#26032#26032#38395
    TabOrder = 6
    OnClick = Button1Click
  end
  object HTTPRIO1: THTTPRIO
    WSDLLocation = 'http://www.ebob42.com/cgi-bin/DrBobsClinic.exe/wsdl/IHeadline'
    Service = 'IHeadLineservice'
    Port = 'IHeadLinePort'
    HTTPWebNode.Agent = 'Borland SOAP 1.1'
    HTTPWebNode.UseUTF8InHeader = False
    HTTPWebNode.InvokeOptions = [soIgnoreInvalidCerts]
    Converter.Options = [soSendMultiRefObj, soTryAllSchema, soRootRefNodesToBody]
    Left = 496
    Top = 8
  end
end
