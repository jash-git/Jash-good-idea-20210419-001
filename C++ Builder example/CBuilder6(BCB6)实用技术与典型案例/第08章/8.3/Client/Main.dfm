object MainForm: TMainForm
  Left = 234
  Top = 140
  Width = 527
  Height = 444
  Caption = '客户机'
  Color = 16635861
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
    Left = 256
    Top = 40
    Width = 65
    Height = 13
    Caption = '网上用户：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 264
    Width = 65
    Height = 13
    Caption = '发送信息：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 8
    Width = 65
    Height = 13
    Caption = '接收信息：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object LabelNotice: TLabel
    Left = 256
    Top = 8
    Width = 217
    Height = 25
    AutoSize = False
    Color = 13683562
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object ListUser: TListBox
    Left = 256
    Top = 64
    Width = 217
    Height = 241
    Color = 16505542
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 0
    OnClick = ListUserClick
  end
  object MemoReceive: TMemo
    Left = 8
    Top = 32
    Width = 241
    Height = 145
    Lines.Strings = (
      '')
    TabOrder = 1
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 376
    Width = 519
    Height = 22
    Color = clSilver
    Panels = <
      item
        Width = 200
      end
      item
        Width = 150
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object EdtSend: TEdit
    Left = 8
    Top = 288
    Width = 233
    Height = 21
    TabOrder = 3
    OnKeyDown = EdtSendKeyDown
  end
  object BtnToAll: TButton
    Left = 400
    Top = 40
    Width = 65
    Height = 25
    Caption = '所有人'
    TabOrder = 4
    OnClick = BtnToAllClick
  end
  object MainMenu1: TMainMenu
    Left = 184
    object MenuSet: TMenuItem
      Caption = '设置'
      OnClick = MenuSetClick
    end
    object MenuConnect: TMenuItem
      Caption = '登录'
      OnClick = MenuConnectClick
    end
    object MenuDisconnect: TMenuItem
      Caption = '离开'
      OnClick = MenuDisconnectClick
    end
  end
  object ClientSocket1: TClientSocket
    Active = False
    ClientType = ctNonBlocking
    Port = 0
    OnConnecting = ClientSocket1Connecting
    OnConnect = ClientSocket1Connect
    OnDisconnect = ClientSocket1Disconnect
    OnRead = ClientSocket1Read
    OnError = ClientSocket1Error
    Left = 208
  end
end
