object Form1: TForm1
  Left = 225
  Top = 158
  Width = 608
  Height = 501
  Caption = 'TXMLDocument'#32452#20214#30340#24212#29992#33539#20363'('#19968')'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 20
  object Button1: TButton
    Left = 16
    Top = 16
    Width = 209
    Height = 33
    Caption = #33258#23450#20041'XML'#65292#24182#19988#21152#36733'Memo'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 232
    Top = 16
    Width = 169
    Height = 33
    Caption = #25226'XML'#20445#23384'(xml1.xml)'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 16
    Top = 64
    Width = 569
    Height = 393
    TabOrder = 2
  end
  object XMLDocument1: TXMLDocument
    Left = 440
    Top = 16
    DOMVendorDesc = 'MSXML'
  end
end
