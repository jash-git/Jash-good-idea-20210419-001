object Test113Server: TTest113Server
  OldCreateOrder = False
  Left = 192
  Top = 107
  Height = 257
  Width = 305
  object Database1: TDatabase
    AliasName = 'BCDEMOS'
    Connected = True
    DatabaseName = 'test'
    HandleShared = True
    Params.Strings = (
      'USER NAME=SYSDBA')
    SessionName = 'Default'
    TransIsolation = tiDirtyRead
    Left = 56
    Top = 16
  end
  object Table1: TTable
    DatabaseName = 'test'
    TableName = 'customer.db'
    Left = 56
    Top = 80
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Table1
    Constraints = True
    Left = 64
    Top = 152
  end
end
