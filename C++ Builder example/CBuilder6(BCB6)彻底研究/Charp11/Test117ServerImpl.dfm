object Test117Server: TTest117Server
  OldCreateOrder = False
  OnCreate = CRemoteDataModuleCreate
  OnDestroy = CRemoteDataModuleDestroy
  Left = 192
  Top = 107
  Height = 240
  Width = 292
  object Events: TQuery
    AfterOpen = EventsAfterOpen
    DatabaseName = 'BCDEMOS'
    SQL.Strings = (
      'select * from events'
      'where Event_Date >= :Start_Date and'
      '                   Event_Date <= :End_Date'
      'order by Event_Date')
    Left = 66
    Top = 26
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'Start_Date'
        ParamType = ptUnknown
        Value = 29221d
      end
      item
        DataType = ftDateTime
        Name = 'End_Date'
        ParamType = ptUnknown
        Value = 36161d
      end>
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Events
    Constraints = True
    Left = 64
    Top = 88
  end
end
