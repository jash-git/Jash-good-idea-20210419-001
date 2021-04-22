object MainForm: TMainForm
  Left = 50
  Top = -3
  Width = 710
  Height = 559
  Caption = '主控端'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 131
    Height = 13
    Caption = '要检控的计算机的IP：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 24
    Top = 136
    Width = 70
    Height = 13
    Caption = '监测图像：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 296
    Top = 8
    Width = 82
    Height = 13
    Caption = 'TimerOut值：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 120
    Top = 136
    Width = 80
    Height = 16
    Caption = '截取日期：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object LabelTime: TLabel
    Left = 216
    Top = 136
    Width = 7
    Height = 13
    Font.Charset = GB2312_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 488
    Top = 88
    Width = 80
    Height = 16
    Caption = '截取区域：'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = '宋体'
    Font.Style = []
    ParentFont = False
  end
  object EdtSpyAddress: TEdit
    Left = 168
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '127.0.0.1'
  end
  object PanelDisplay: TPanel
    Left = 16
    Top = 152
    Width = 577
    Height = 353
    BevelOuter = bvLowered
    TabOrder = 1
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 575
      Height = 351
      Align = alClient
    end
  end
  object EdtTimeOut: TEdit
    Left = 376
    Top = 8
    Width = 89
    Height = 21
    TabOrder = 2
    Text = '2000'
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 513
    Width = 702
    Height = 19
    Panels = <
      item
        Width = 200
      end
      item
        Width = 200
      end
      item
        Width = 200
      end>
    SimplePanel = False
  end
  object EdtCaptureSize: TEdit
    Left = 488
    Top = 104
    Width = 105
    Height = 21
    Enabled = False
    TabOrder = 4
    Text = '0,0,100,100'
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 32
    Width = 457
    Height = 49
    Caption = '连接测试'
    TabOrder = 5
    object BtnTestTime: TButton
      Left = 174
      Top = 16
      Width = 91
      Height = 25
      Caption = '连接时间'
      TabOrder = 0
      OnClick = BtnTestTimeClick
    end
    object BtnTestDayTime: TButton
      Left = 318
      Top = 16
      Width = 91
      Height = 25
      Caption = '连接日期和时间'
      TabOrder = 1
      OnClick = BtnTestDayTimeClick
    end
    object BtnTestEcho: TButton
      Left = 24
      Top = 16
      Width = 91
      Height = 25
      Caption = '测试连接回应'
      TabOrder = 2
      OnClick = BtnTestEchoClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 80
    Width = 457
    Height = 49
    Caption = '操作'
    TabOrder = 6
    object BtnCapture: TButton
      Left = 8
      Top = 16
      Width = 91
      Height = 25
      Caption = '截取图像'
      TabOrder = 0
      OnClick = BtnCaptureClick
    end
    object BtnCloseClient: TButton
      Left = 104
      Top = 16
      Width = 89
      Height = 25
      Caption = '关闭受控端程序'
      TabOrder = 1
      OnClick = BtnCloseClientClick
    end
    object BtnSetCaptureRec: TButton
      Left = 200
      Top = 16
      Width = 91
      Height = 25
      Caption = '设置截取区域'
      TabOrder = 2
      OnClick = BtnSetCaptureRecClick
    end
    object ChkBoxAutoCapture: TCheckBox
      Left = 320
      Top = 16
      Width = 97
      Height = 17
      Caption = '启用自动捕捉'
      TabOrder = 3
      OnClick = ChkBoxAutoCaptureClick
    end
  end
  object NMEcho1: TNMEcho
    Host = '127.0.0.1'
    Port = 7
    ReportLevel = 0
    OnConnect = NMEcho1Connect
    OnInvalidHost = NMEcho1InvalidHost
    OnConnectionFailed = NMEcho1ConnectionFailed
    Left = 528
    Top = 8
  end
  object NMDayTime1: TNMDayTime
    Host = '127.0.0.1'
    Port = 13
    TimeOut = 500
    ReportLevel = 0
    OnConnect = NMEcho1Connect
    OnInvalidHost = NMDayTime1InvalidHost
    Left = 496
    Top = 8
  end
  object NMTime1: TNMTime
    Host = '127.0.0.1'
    Port = 37
    TimeOut = 500
    ReportLevel = 0
    OnInvalidHost = NMTime1InvalidHost
    Left = 552
    Top = 8
  end
  object SUDP: TNMUDP
    RemoteHost = '202.204.49.45'
    RemotePort = 2222
    LocalPort = 1111
    ReportLevel = 1
    OnDataReceived = SUDPDataReceived
    OnBufferInvalid = SUDPBufferInvalid
    Left = 576
    Top = 8
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 2000
    OnTimer = Timer1Timer
    Left = 608
    Top = 8
  end
end
