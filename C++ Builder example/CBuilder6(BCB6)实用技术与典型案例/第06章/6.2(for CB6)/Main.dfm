object MainForm: TMainForm
  Left = 261
  Top = 183
  Width = 482
  Height = 285
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 474
    Height = 239
    Align = alClient
    Lines.Strings = (
      '')
    TabOrder = 0
  end
  object MainMenu: TMainMenu
    Left = 136
    Top = 8
    object MenuFile: TMenuItem
      Caption = #25991#20214
      object MenuOpen: TMenuItem
        Caption = #25171#24320#25991#20214
        OnClick = MenuOpenClick
      end
      object MenuSave: TMenuItem
        Caption = #20445#23384#25991#20214
        OnClick = MenuSaveClick
      end
    end
    object MenuExit: TMenuItem
      Caption = #36864#20986
      OnClick = MenuExitClick
    end
  end
  object OpenDialog: TOpenDialog
    Left = 176
    Top = 8
  end
  object SaveDialog: TSaveDialog
    Left = 208
    Top = 8
  end
end
