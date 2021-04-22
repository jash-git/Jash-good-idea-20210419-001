object MainForm: TMainForm
  Left = 78
  Top = 153
  Width = 625
  Height = 414
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 16
    Top = 24
    Width = 257
    Height = 297
    Caption = #37038#20214#30340#21457#36865
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 24
      Width = 108
      Height = 13
      Caption = #35201#36830#25509#37038#20214#26381#21153#22120#65306
    end
    object Label2: TLabel
      Left = 78
      Top = 56
      Width = 36
      Height = 13
      Caption = #31471#21475#65306
    end
    object Label3: TLabel
      Left = 67
      Top = 80
      Width = 48
      Height = 13
      Caption = #29992#25143#21517#65306
    end
    object Label8: TLabel
      Left = 79
      Top = 104
      Width = 36
      Height = 13
      Caption = #37038#31665#65306
    end
    object EdtSMTPServer: TEdit
      Left = 120
      Top = 24
      Width = 129
      Height = 21
      TabOrder = 0
      Text = 'smtp.sina.com.cn'
    end
    object BtnSMTPConnect: TButton
      Left = 80
      Top = 176
      Width = 75
      Height = 25
      Caption = #30331#24405
      TabOrder = 1
      OnClick = BtnSMTPConnectClick
    end
    object EdtSMTPPort: TEdit
      Left = 120
      Top = 48
      Width = 129
      Height = 21
      TabOrder = 2
      Text = '25'
    end
    object EdtSMTPUser: TEdit
      Left = 120
      Top = 72
      Width = 129
      Height = 21
      TabOrder = 3
    end
    object BtnSendMail: TButton
      Left = 80
      Top = 256
      Width = 75
      Height = 25
      Caption = #21457#36865#37038#20214
      TabOrder = 4
    end
    object BtnSMTPDisClose: TButton
      Left = 80
      Top = 208
      Width = 75
      Height = 25
      Caption = #26029#24320
      TabOrder = 5
      OnClick = BtnSMTPDisCloseClick
    end
    object EdtFromAddress: TEdit
      Left = 120
      Top = 96
      Width = 129
      Height = 21
      TabOrder = 6
    end
  end
  object GroupBox2: TGroupBox
    Left = 296
    Top = 24
    Width = 257
    Height = 297
    Caption = #37038#20214#30340#25509#25910
    TabOrder = 1
    object Label4: TLabel
      Left = 8
      Top = 24
      Width = 108
      Height = 13
      Caption = #35201#36830#25509#37038#20214#26381#21153#22120#65306
    end
    object Label5: TLabel
      Left = 72
      Top = 56
      Width = 36
      Height = 13
      Caption = #31471#21475#65306
    end
    object Label6: TLabel
      Left = 64
      Top = 80
      Width = 48
      Height = 13
      Caption = #29992#25143#21517#65306
    end
    object Label7: TLabel
      Left = 64
      Top = 104
      Width = 36
      Height = 13
      Caption = #23494#30721#65306
    end
    object EdtPop3Server: TEdit
      Left = 120
      Top = 24
      Width = 129
      Height = 21
      TabOrder = 0
      Text = '263.net'
    end
    object BtnPop3Connect: TButton
      Left = 80
      Top = 176
      Width = 75
      Height = 25
      Caption = #30331#24405
      TabOrder = 1
      OnClick = BtnPop3ConnectClick
    end
    object EdtPop3Port: TEdit
      Left = 120
      Top = 48
      Width = 129
      Height = 21
      TabOrder = 2
      Text = '110'
    end
    object EdtPop3User: TEdit
      Left = 120
      Top = 72
      Width = 129
      Height = 21
      TabOrder = 3
    end
    object BtnReciveMail: TButton
      Left = 80
      Top = 256
      Width = 75
      Height = 25
      Caption = #25509#25910#37038#20214
      TabOrder = 4
      OnClick = BtnReciveMailClick
    end
    object BtnPop3DisConnect: TButton
      Left = 80
      Top = 208
      Width = 75
      Height = 25
      Caption = #26029#24320
      TabOrder = 5
      OnClick = BtnPop3DisConnectClick
    end
    object EdtPop3Password: TEdit
      Left = 120
      Top = 96
      Width = 129
      Height = 21
      PasswordChar = '*'
      TabOrder = 6
    end
  end
  object BtnClose: TButton
    Left = 272
    Top = 336
    Width = 75
    Height = 25
    Caption = #20851#38381
    TabOrder = 2
    OnClick = BtnCloseClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 368
    Width = 617
    Height = 19
    Panels = <
      item
        Width = 250
      end
      item
        Width = 250
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object NMSMTP1: TNMSMTP
    Port = 25
    ReportLevel = 0
    OnDisconnect = NMSMTP1Disconnect
    OnConnect = NMSMTP1Connect
    EncodeType = uuMime
    ClearParams = True
    SubType = mtPlain
    Charset = 'us-ascii'
    Left = 104
  end
  object NMPOP31: TNMPOP3
    Port = 110
    ReportLevel = 0
    OnDisconnect = NMPOP31Disconnect
    OnConnect = NMPOP31Connect
    Parse = False
    DeleteOnRead = False
    OnList = NMPOP31List
    OnRetrieveStart = NMPOP31RetrieveStart
    OnRetrieveEnd = NMPOP31RetrieveEnd
    Left = 152
  end
end
