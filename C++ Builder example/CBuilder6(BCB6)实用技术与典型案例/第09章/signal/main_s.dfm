object Main_sForm: TMain_sForm
  Left = 117
  Top = 172
  Width = 487
  Height = 288
  Caption = 'Server'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 479
    Height = 222
    Align = alClient
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 222
    Width = 479
    Height = 20
    Panels = <>
    SimplePanel = True
    SimpleText = 'Server is open!'
  end
  object MainMenu1: TMainMenu
    Left = 104
    Top = 8
    object FIle1: TMenuItem
      Caption = '&Operation'
      object Exit1: TMenuItem
        Caption = 'Exit'
      end
    end
    object Setting1: TMenuItem
      Caption = '&Setting '
      object Property1: TMenuItem
        Caption = 'Property...'
        OnClick = Property1Click
      end
    end
  end
end
