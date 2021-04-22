object Test121Server: TTest121Server
  OldCreateOrder = False
  Left = 173
  Top = 43
  Height = 267
  Width = 367
  object Query1: TQuery
    DatabaseName = 'BCDEMO'
    SessionName = 'Session1_1'
    SQL.Strings = (
      'select * from country')
    Left = 168
    Top = 144
  end
  object Session1: TSession
    Active = True
    AutoSessionName = True
    Left = 56
    Top = 144
  end
  object Database1: TDatabase
    AliasName = 'IBLOCAL'
    DatabaseName = 'BCDEMO'
    HandleShared = True
    LoginPrompt = False
    Params.Strings = (
      'USER NAME=SYSDBA'
      'PASSWORD=masterkey')
    SessionName = 'Session1_1'
    Left = 112
    Top = 144
  end
  object DataSetProvider2: TDataSetProvider
    DataSet = Query1
    Constraints = True
    Left = 240
    Top = 144
  end
  object Customer: TTable
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_1'
    TableName = 'customer.db'
    Left = 136
    Top = 72
  end
  object Order: TTable
    DatabaseName = 'BCDEMOS'
    SessionName = 'Session1_1'
    IndexName = 'CustNo'
    MasterFields = 'CustNo'
    MasterSource = DataSource1
    TableName = 'orders.db'
    Left = 272
    Top = 72
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Customer
    Constraints = True
    Left = 152
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = Customer
    Left = 208
    Top = 72
  end
end
