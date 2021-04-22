object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'WebActionItem1'
      PathInfo = '/InetXPageProducer1'
      Producer = InetXPageProducer1
    end>
  Left = 313
  Top = 85
  Height = 335
  Width = 412
  object SocketConnection1: TSocketConnection
    ServerGUID = '{C72E62C6-61DE-4B1E-8A01-23C26C34A42F}'
    ServerName = 'Project16_1.InterExpressSer'
    Host = 'localhost'
    Left = 80
    Top = 16
  end
  object XMLBroker1: TXMLBroker
    Params = <>
    ProviderName = 'DataSetProvider2'
    RemoteServer = SocketConnection1
    WebDispatch.PathInfo = 'XMLBroker1'
    Left = 80
    Top = 80
  end
  object InetXPageProducer1: TInetXPageProducer
    IncludePathURL = 'http://localhost/Web/'
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEAD>'
      '</HEAD>'
      '<BODY>'
      '<#INCLUDES><#STYLES><#WARNINGS><#FORMS><#SCRIPT>'
      '</BODY>'
      '</HTML>')
    Left = 80
    Top = 160
    object DataForm1: TDataForm
      object DataGrid1: TDataGrid
        XMLBroker = XMLBroker1
      end
      object DataNavigator1: TDataNavigator
        XMLComponent = DataGrid1
      end
      object DataGrid2: TDataGrid
        XMLBroker = XMLBroker1
        XMLDataSetField = 'qEmployee'
      end
      object DataNavigator2: TDataNavigator
        XMLComponent = DataGrid2
      end
    end
  end
end
