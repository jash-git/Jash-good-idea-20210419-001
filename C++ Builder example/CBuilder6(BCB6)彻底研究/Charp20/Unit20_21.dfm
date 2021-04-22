object Form1: TForm1
  Left = 298
  Top = 166
  Width = 580
  Height = 210
  Caption = 'Web Service '#23458#25143#31471#31243#24207
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
    Left = 264
    Top = 96
    Width = 273
    Height = 33
    AutoSize = False
  end
  object Button1: TButton
    Left = 48
    Top = 32
    Width = 177
    Height = 41
    Caption = #33719#21462#22269#23478#21517#31216
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 48
    Top = 88
    Width = 177
    Height = 41
    Caption = #33719#21462#23545#24212#30340#39318#37117#21517#31216
    TabOrder = 1
    OnClick = Button2Click
  end
  object ComboBox1: TComboBox
    Left = 264
    Top = 40
    Width = 273
    Height = 28
    ItemHeight = 20
    TabOrder = 2
  end
  object HTTPRIO1: THTTPRIO
    WSDLLocation = 'http://localhost/CBuilderWeb/Project20_1.exe/wsdl/IQueryCapital'
    Service = 'IQueryCapitalservice'
    Port = 'IQueryCapitalPort'
    HTTPWebNode.Agent = 'Borland SOAP 1.1'
    HTTPWebNode.UseUTF8InHeader = False
    HTTPWebNode.InvokeOptions = [soIgnoreInvalidCerts]
    Converter.Options = [soSendMultiRefObj, soTryAllSchema, soRootRefNodesToBody]
    Left = 8
    Top = 16
  end
end
