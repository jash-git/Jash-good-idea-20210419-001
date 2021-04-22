object Test125Server: TTest125Server
  OldCreateOrder = False
  OnCreate = CRemoteDataModuleCreate
  OnDestroy = CRemoteDataModuleDestroy
  Left = 282
  Top = 228
  Height = 229
  Width = 325
  object Country: TTable
    DatabaseName = 'DBDEMOS'
    TableName = 'country'
    Left = 80
    Top = 32
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Country
    Constraints = True
    Left = 88
    Top = 96
  end
end
