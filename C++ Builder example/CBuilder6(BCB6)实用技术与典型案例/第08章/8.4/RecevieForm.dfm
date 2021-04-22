object POP3Form: TPOP3Form
  Left = 25
  Top = 28
  Width = 755
  Height = 487
  Caption = 'POP3Form'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 184
    Width = 84
    Height = 12
    Caption = '邮件中的内容：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 16
    Top = 32
    Width = 60
    Height = 12
    Caption = '邮件列表：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 16
    Top = 8
    Width = 60
    Height = 12
    Caption = '邮件总数：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 232
    Top = 184
    Width = 36
    Height = 12
    Caption = '邮件头'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 224
    Top = 272
    Width = 48
    Height = 12
    Caption = '邮件主体'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label11: TLabel
    Left = 552
    Top = 184
    Width = 24
    Height = 12
    Caption = '附件'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object MemoContent: TMemo
    Left = 16
    Top = 288
    Width = 521
    Height = 169
    Lines.Strings = (
      '')
    TabOrder = 0
  end
  object GroupBox1: TGroupBox
    Left = 272
    Top = 48
    Width = 269
    Height = 129
    Caption = '邮件属性'
    TabOrder = 1
    object Label4: TLabel
      Left = 16
      Top = 16
      Width = 72
      Height = 13
      Caption = '读取的邮件：'
    end
    object Label5: TLabel
      Left = 48
      Top = 48
      Width = 36
      Height = 13
      Caption = '来源：'
    end
    object Label6: TLabel
      Left = 48
      Top = 64
      Width = 36
      Height = 13
      Caption = '大小：'
    end
    object Label7: TLabel
      Left = 48
      Top = 32
      Width = 36
      Height = 13
      Caption = '主题：'
    end
    object Label8: TLabel
      Left = 37
      Top = 84
      Width = 48
      Height = 13
      Caption = '邮件号：'
    end
    object EdtMailName: TEdit
      Left = 88
      Top = 8
      Width = 177
      Height = 21
      TabOrder = 0
    end
    object EdtSubject: TEdit
      Left = 88
      Top = 24
      Width = 177
      Height = 21
      TabOrder = 1
    end
    object EdtFrom: TEdit
      Left = 88
      Top = 43
      Width = 177
      Height = 21
      TabOrder = 2
    end
    object EdtSize: TEdit
      Left = 88
      Top = 61
      Width = 177
      Height = 21
      TabOrder = 3
    end
    object EdtMailID: TEdit
      Left = 88
      Top = 79
      Width = 177
      Height = 21
      TabOrder = 4
    end
  end
  object EdtMailCount: TEdit
    Left = 80
    Top = 5
    Width = 65
    Height = 21
    TabOrder = 2
  end
  object ListBoxMail: TListBox
    Left = 16
    Top = 51
    Width = 209
    Height = 129
    ItemHeight = 13
    TabOrder = 3
    OnClick = ListBoxMailClick
  end
  object MemoHead: TMemo
    Left = 16
    Top = 200
    Width = 521
    Height = 73
    Lines.Strings = (
      '')
    TabOrder = 4
  end
  object MemoAttach: TMemo
    Left = 544
    Top = 200
    Width = 185
    Height = 257
    TabOrder = 5
  end
end
