object MessageForm: TMessageForm
  Left = 316
  Top = 319
  Width = 314
  Height = 159
  Caption = '��Ϣ����'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BtnLeft: TButton
    Left = 16
    Top = 16
    Width = 75
    Height = 25
    Caption = '��ť'
    TabOrder = 0
    OnClick = BtnLeftClick
  end
  object BtnRight: TButton
    Left = 200
    Top = 16
    Width = 75
    Height = 25
    Caption = '�Ұ�ť'
    TabOrder = 1
    OnClick = BtnRightClick
  end
  object BtnClose: TButton
    Left = 104
    Top = 88
    Width = 75
    Height = 25
    Caption = '�˳�'
    TabOrder = 2
    OnClick = BtnCloseClick
  end
end
