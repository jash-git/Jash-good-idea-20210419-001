object MainForm: TMainForm
  Left = 276
  Top = 186
  BorderStyle = bsNone
  Caption = 'ϵͳ��Ϣ���Գ���'
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
    Caption = '�ޱ���Ի���'
    Font.Charset = GB2312_CHARSET
    Font.Color = clMaroon
    Font.Height = -19
    Font.Name = '����'
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
    Caption = '���´���'
    TabOrder = 1
    OnClick = BtnOpenClick
  end
end
