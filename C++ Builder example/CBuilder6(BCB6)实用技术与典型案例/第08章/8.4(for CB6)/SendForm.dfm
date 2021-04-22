object SMTPForm: TSMTPForm
  Left = 158
  Top = 100
  Width = 571
  Height = 447
  Caption = 'SMTPForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label5: TLabel
    Left = 33
    Top = 136
    Width = 36
    Height = 13
    Caption = #20027#39064#65306
  end
  object Label6: TLabel
    Left = 33
    Top = 152
    Width = 36
    Height = 13
    Caption = #20869#23481#65306
  end
  object GroupBox1: TGroupBox
    Left = 32
    Top = 32
    Width = 473
    Height = 89
    Caption = #21457#36865#20449#24687
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 20
      Width = 48
      Height = 13
      Caption = #25910#20214#20154#65306
    end
    object Label2: TLabel
      Left = 35
      Top = 40
      Width = 36
      Height = 13
      Caption = #25220#36865#65306
    end
    object Label3: TLabel
      Left = 208
      Top = 12
      Width = 36
      Height = 13
      Caption = #38468#20214#65306
    end
    object Label4: TLabel
      Left = 11
      Top = 64
      Width = 60
      Height = 13
      Caption = #23494#20214#25220#36865#65306
    end
    object EdtToAddress: TEdit
      Left = 72
      Top = 12
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object EdtCarbonCopy: TEdit
      Left = 72
      Top = 36
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object BtnAddAttach: TButton
      Left = 200
      Top = 64
      Width = 75
      Height = 19
      Caption = #28155#21152#38468#20214
      TabOrder = 2
      OnClick = BtnAddAttachClick
    end
    object EdtBlindCopy: TEdit
      Left = 72
      Top = 60
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object BtnDeleteAttach: TButton
      Left = 280
      Top = 64
      Width = 75
      Height = 19
      Caption = #21024#38500#38468#20214
      TabOrder = 4
      OnClick = BtnDeleteAttachClick
    end
    object RadioGroup1: TRadioGroup
      Left = 368
      Top = 8
      Width = 101
      Height = 74
      Caption = #32534#30721#26041#24335
      ItemIndex = 0
      Items.Strings = (
        'Mime'
        'Code')
      TabOrder = 5
    end
    object ListBoxAttach: TListBox
      Left = 199
      Top = 23
      Width = 154
      Height = 39
      ItemHeight = 13
      TabOrder = 6
    end
  end
  object EdtSubject: TEdit
    Left = 70
    Top = 130
    Width = 142
    Height = 21
    TabOrder = 1
  end
  object MemoContent: TMemo
    Left = 32
    Top = 168
    Width = 481
    Height = 209
    Lines.Strings = (
      '')
    TabOrder = 2
  end
  object BtnSend: TButton
    Left = 240
    Top = 392
    Width = 75
    Height = 25
    Caption = #21457'  '#36865
    TabOrder = 3
    OnClick = BtnSendClick
  end
  object OpenDialog1: TOpenDialog
    Left = 312
    Top = 8
  end
end
