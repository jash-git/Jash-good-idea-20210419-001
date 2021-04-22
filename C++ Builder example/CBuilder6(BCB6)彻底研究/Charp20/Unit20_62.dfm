object BiolifeService: TBiolifeService
  OldCreateOrder = False
  Left = 486
  Top = 106
  Height = 150
  Width = 215
  object DataSetProvider1: TDataSetProvider
    DataSet = Table1
    Constraints = True
    Left = 88
    Top = 64
  end
  object Table1: TTable
    DatabaseName = 'BCDEMOS'
    TableName = 'biolife.db'
    Left = 88
    Top = 8
  end
end
