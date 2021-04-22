object Form1: TForm1
  Left = 107
  Top = 82
  Width = 642
  Height = 444
  Caption = 'XML Data Binding wizard 范例'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 20
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 137
    Height = 28
    TabOrder = 0
  end
  object Button1: TButton
    Left = 152
    Top = 8
    Width = 153
    Height = 28
    Caption = '改变Stock中的Name值'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 320
    Top = 8
    Width = 153
    Height = 28
    TabOrder = 2
  end
  object Button2: TButton
    Left = 480
    Top = 8
    Width = 145
    Height = 28
    Caption = '改变Stock中的Price值'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 48
    Width = 617
    Height = 361
    TabOrder = 4
  end
  object XMLDocument1: TXMLDocument
    Left = 560
    Top = 48
    DOMVendorDesc = 'MSXML'
  end
end

