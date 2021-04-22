object InterExpressSer: TInterExpressSer
  OldCreateOrder = False
  Left = 140
  Top = 108
  Height = 404
  Width = 591
  object Query1: TQuery
    DatabaseName = 'db'
    SQL.Strings = (
      'SELECT * FROM EMPLOYEE')
    Left = 56
    Top = 88
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Constraints = True
    Left = 56
    Top = 152
  end
  object Database1: TDatabase
    AliasName = 'IBLocal'
    Connected = True
    DatabaseName = 'db'
    HandleShared = True
    LoginPrompt = False
    Params.Strings = (
      'USERNAME=SYSDBA'
      'PASSWORD=masterkey')
    SessionName = 'Default'
    Left = 56
    Top = 24
  end
  object qDepartment: TQuery
    DatabaseName = 'db'
    SQL.Strings = (
      'SELECT * FROM DEPARTMENT')
    Left = 168
    Top = 88
  end
  object qEmployee: TQuery
    DatabaseName = 'db'
    DataSource = ds1
    SQL.Strings = (
      'SELECT * FROM EMPLOYEE'
      'WHERE DEPT_NO=:DEPT_NO')
    Left = 288
    Top = 88
    ParamData = <
      item
        DataType = ftFixedChar
        Name = 'DEPT_NO'
        ParamType = ptUnknown
        Size = 4
      end>
  end
  object ds1: TDataSource
    DataSet = qDepartment
    Left = 232
    Top = 88
  end
  object DataSetProvider2: TDataSetProvider
    DataSet = qDepartment
    Constraints = True
    Options = [poFetchDetailsOnDemand, poAllowMultiRecordUpdates]
    Left = 168
    Top = 152
  end
  object qQueryDepartment: TQuery
    DatabaseName = 'db'
    SQL.Strings = (
      'SELECT * FROM EMPLOYEE'
      'WHERE FULL_NAME LIKE :FULL_NAME '
      'AND DEPT_NO LIKE :DEPT_NO')
    Left = 392
    Top = 88
    ParamData = <
      item
        DataType = ftString
        Name = 'FULL_NAME'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'DEPT_NO'
        ParamType = ptUnknown
      end>
  end
  object qQueryEmployee: TQuery
    DatabaseName = 'db'
    SQL.Strings = (
      'SELECT * FROM EMPLOYEE'
      'WHERE FULL_NAME LIKE :FULL_NAME '
      'AND DEPT_NO LIKE :DEPT_NO')
    Left = 496
    Top = 88
    ParamData = <
      item
        DataType = ftString
        Name = 'FULL_NAME'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'DEPT_NO'
        ParamType = ptUnknown
      end>
  end
  object dspQueryDepartment: TDataSetProvider
    DataSet = qQueryDepartment
    Constraints = True
    Left = 392
    Top = 152
  end
  object qtpQueryEmployee: TQueryTableProducer
    Query = qQueryEmployee
    Left = 504
    Top = 152
  end
  object qCountry: TQuery
    DatabaseName = 'db'
    SQL.Strings = (
      'SELECT * FROM COUNTRY')
    Left = 264
    Top = 240
  end
  object qUpdate: TQuery
    DatabaseName = 'db'
    Left = 360
    Top = 240
  end
  object dspCountry: TDataSetProvider
    DataSet = qCountry
    Constraints = True
    Left = 264
    Top = 304
  end
  object qtpCountry: TQueryTableProducer
    Query = qCountry
    Left = 360
    Top = 304
  end
end
