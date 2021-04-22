object Form1: TForm1
  Left = 134
  Top = 287
  Width = 563
  Height = 201
  Caption = '利用TFileStream来复制文件的范例'
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
    Left = 64
    Top = 32
    Width = 105
    Height = 20
    AutoSize = False
    Caption = '来源文件：'
  end
  object Label2: TLabel
    Left = 64
    Top = 72
    Width = 105
    Height = 20
    AutoSize = False
    Caption = '目的文件：'
  end
  object Edit1: TEdit
    Left = 166
    Top = 26
    Width = 283
    Height = 28
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 166
    Top = 67
    Width = 283
    Height = 28
    TabOrder = 1
  end
  object Button1: TButton
    Left = 450
    Top = 26
    Width = 33
    Height = 28
    Caption = '...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 450
    Top = 67
    Width = 33
    Height = 28
    Caption = '...'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 208
    Top = 112
    Width = 129
    Height = 41
    Caption = '开始复制'
    Default = True
    TabOrder = 4
    OnClick = Button3Click
  end
  object OpenDialog1: TOpenDialog
    Left = 32
    Top = 24
  end
end

