object MainForm: TMainForm
  Left = 276
  Top = 186
  BorderStyle = bsNone
  Caption = #31995#32479#28040#24687#27979#35797#31243#24207
  ClientHeight = 260
  ClientWidth = 414
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 136
    Top = 40
    Width = 114
    Height = 19
    Caption = #26080#26631#39064#23545#35805#26694
    Font.Charset = GB2312_CHARSET
    Font.Color = clMaroon
    Font.Height = -19
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object BtnOk: TBitBtn
    Left = 64
    Top = 184
    Width = 75
    Height = 25
    Cursor = crHandPoint
    TabOrder = 0
    OnClick = BtnOkClick
    Kind = bkOK
  end
  object BtnOpen: TButton
    Left = 216
    Top = 184
    Width = 75
    Height = 25
    Caption = #25171#24320#26032#31383#20307
    TabOrder = 1
    OnClick = BtnOpenClick
  end
end
