object Test111Server: TTest111Server
  OldCreateOrder = False
  Left = 72
  Top = 78
  Height = 279
  Width = 297
  object Table1: TTable
    DatabaseName = 'BCDEMOS'
    TableName = 'customer.db'
    Left = 80
    Top = 56
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Table1
    Constraints = True
    Left = 80
    Top = 136
  end
end
