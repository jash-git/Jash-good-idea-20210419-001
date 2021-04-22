object ActiveFormX2: TActiveFormX2
  Left = 136
  Top = 128
  Width = 599
  Height = 402
  Caption = 'ActiveFormX2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = ActiveFormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 8
    Top = 40
    Width = 577
    Height = 329
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    Left = 311
    Top = 8
    Width = 216
    Height = 25
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete]
    TabOrder = 1
  end
  object Button1: TButton
    Left = 527
    Top = 8
    Width = 57
    Height = 25
    Caption = 'Apply'
    TabOrder = 2
  end
  object SocketConnection1: TSocketConnection
    ServerGUID = '{C72E62C6-61DE-4B1E-8A01-23C26C34A42F}'
    ServerName = 'Project16_1.InterExpressSer'
    Host = 'localhost'
    Left = 8
    Top = 8
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    RemoteServer = SocketConnection1
    Left = 40
    Top = 8
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 72
    Top = 8
  end
end
