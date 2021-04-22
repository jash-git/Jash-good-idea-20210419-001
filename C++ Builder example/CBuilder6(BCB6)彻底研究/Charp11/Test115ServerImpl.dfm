object Test115Server: TTest115Server
  OldCreateOrder = False
  OnCreate = CRemoteDataModuleCreate
  OnDestroy = CRemoteDataModuleDestroy
  Left = 192
  Top = 107
  Height = 298
  Width = 419
  object AdHocQuery: TQuery
    AfterOpen = AdHocQueryAfterOpen
    DatabaseName = 'ADHOC'
    SessionName = 'Session1_1'
    Left = 40
    Top = 16
  end
  object Session1: TSession
    AutoSessionName = True
    SQLHourGlass = False
    Left = 128
    Top = 64
  end
  object Database1: TDatabase
    DatabaseName = 'ADHOC'
    LoginPrompt = False
    SessionName = 'Session1_1'
    Left = 38
    Top = 66
  end
  object AdHocProvider: TDataSetProvider
    DataSet = AdHocQuery
    Constraints = True
    Options = [poAllowCommandText]
    Left = 128
    Top = 16
  end
end
