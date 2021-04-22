object Form1: TForm1
  Left = 352
  Top = 99
  Width = 426
  Height = 510
  Caption = 'TStringStream ·¶Àý³ÌÐò'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 20
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 401
    Height = 385
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object Button1: TButton
    Left = 8
    Top = 400
    Width = 193
    Height = 33
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 216
    Top = 400
    Width = 193
    Height = 33
    Caption = 'Memo1'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 8
    Top = 440
    Width = 193
    Height = 33
    Caption = 'Form1'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button4: TButton
    Left = 216
    Top = 440
    Width = 193
    Height = 33
    Caption = 'OpenDialog1'
    TabOrder = 4
    OnClick = Button1Click
  end
  object OpenDialog1: TOpenDialog
    Left = 368
    Top = 8
  end
end

