object MainForm: TMainForm
  Left = 109
  Top = 110
  Width = 534
  Height = 381
  Caption = '������'
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
  object Label1: TLabel
    Left = 0
    Top = 8
    Width = 65
    Height = 13
    Caption = '���ӵ��û�'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object LabelNotice: TLabel
    Left = 8
    Top = 176
    Width = 117
    Height = 13
    Caption = '�������˷��͵���Ϣ'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 32
    Width = 14
    Height = 13
    Caption = 'IP'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 232
    Top = 32
    Width = 39
    Height = 13
    Caption = '�û���'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '����'
    Font.Style = []
    ParentFont = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 316
    Width = 526
    Height = 19
    Panels = <
      item
        Width = 100
      end
      item
        Width = 250
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object ListUserAddr: TListBox
    Left = 8
    Top = 48
    Width = 217
    Height = 121
    ItemHeight = 13
    TabOrder = 1
  end
  object ListUserName: TListBox
    Left = 296
    Top = 48
    Width = 185
    Height = 121
    ItemHeight = 13
    TabOrder = 2
    OnClick = ListUserNameClick
  end
  object EdtSend: TEdit
    Left = 16
    Top = 216
    Width = 417
    Height = 41
    TabOrder = 3
    OnKeyDown = EdtSendKeyDown
  end
  object BtnToAll: TButton
    Left = 184
    Top = 176
    Width = 75
    Height = 25
    Caption = '������'
    TabOrder = 4
    OnClick = BtnToAllClick
  end
  object ServerSocket1: TServerSocket
    Active = False
    Port = 0
    ServerType = stNonBlocking
    OnAccept = ServerSocket1Accept
    OnClientDisconnect = ServerSocket1ClientDisconnect
    OnClientRead = ServerSocket1ClientRead
    OnClientError = ServerSocket1ClientError
    Left = 360
    Top = 8
  end
  object MainMenu1: TMainMenu
    Left = 120
    Top = 8
    object MenuListen: TMenuItem
      Caption = '����'
      OnClick = MenuListenClick
    end
    object MenuClose: TMenuItem
      Caption = '�Ͽ�'
      OnClick = MenuCloseClick
    end
    object MenuDisConnect: TMenuItem
      Caption = '��ֹ�û�'
      OnClick = MenuDisConnectClick
    end
  end
end
