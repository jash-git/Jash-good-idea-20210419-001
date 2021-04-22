object Form1: TForm1
  Left = 207
  Top = 166
  Width = 444
  Height = 223
  Caption = 'Delphi '#35843#29992' Word '#33539#20363#31243#24207
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 18
  object Label1: TLabel
    Left = 40
    Top = 56
    Width = 135
    Height = 18
    Caption = 'MS-Word '#25991#20214#21517#65306
  end
  object Button1: TButton
    Left = 40
    Top = 112
    Width = 353
    Height = 49
    Caption = #23558#25968#25454#24211#25968#25454#36716#23384#25104'Word'#25991#20214
    Default = True
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 160
    Top = 50
    Width = 233
    Height = 26
    TabOrder = 1
  end
  object Query1: TQuery
    DatabaseName = 'BCDEMOS'
    Left = 16
    Top = 16
  end
end
