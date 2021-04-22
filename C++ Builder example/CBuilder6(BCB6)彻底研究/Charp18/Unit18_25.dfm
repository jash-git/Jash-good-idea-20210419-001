object AfterLogin: TAfterLogin
  OldCreateOrder = False
  PageProducer = AdapterPageProducer
  Left = 590
  Top = 294
  Height = 150
  Width = 215
  object AdapterPageProducer: TAdapterPageProducer
    HTMLDoc.Strings = (
      '<html>'
      '<head>'
      '</head>'
      '<body>'
      '<#STYLES><#WARNINGS><#SERVERSCRIPT>'
      '</body>'
      '</html>')
    Left = 48
    Top = 8
    object AdapterForm1: TAdapterForm
      object AdapterGrid1: TAdapterGrid
        Adapter = WebDataModule4.DataSetAdapter1
        AdapterMode = 'Browse'
      end
    end
  end
end
