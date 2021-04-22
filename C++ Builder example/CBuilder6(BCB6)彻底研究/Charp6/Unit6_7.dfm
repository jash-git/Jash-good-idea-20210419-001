object Form1: TForm1
  Left = 169
  Top = 129
  Width = 600
  Height = 375
  Caption = 'TMemoryStream'
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
    Left = 88
    Top = 8
    Width = 61
    Height = 20
    Caption = 'ListBox1'
  end
  object Label2: TLabel
    Left = 440
    Top = 8
    Width = 53
    Height = 20
    Caption = 'Memo1'
  end
  object ListBox1: TListBox
    Left = 8
    Top = 32
    Width = 225
    Height = 305
    ItemHeight = 20
    Items.Strings = (
      'ListBox1'
      'ListBox2'
      'ListBox3'
      'ListBox4'
      'ListBox5'
      'ListBox6'
      'ListBox7'
      'ListBox8'
      'ListBox9')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 248
    Top = 144
    Width = 83
    Height = 33
    Caption = '-------->'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 344
    Top = 32
    Width = 241
    Height = 305
    Lines.Strings = (
      '')
    TabOrder = 2
  end
end
