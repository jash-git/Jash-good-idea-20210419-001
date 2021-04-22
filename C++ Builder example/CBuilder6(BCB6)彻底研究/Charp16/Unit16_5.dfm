object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'WebActionItem1'
      PathInfo = '/InetXPageProducer1'
      Producer = InetXPageProducer1
      OnAction = WebModule1WebActionItem1Action
    end
    item
      Name = 'WebActionItem2'
      PathInfo = '/PostCountry'
    end
    item
      Name = 'WebActionItem3'
      PathInfo = '/QueryCountry'
      OnAction = WebModule1WebActionItem3Action
    end>
  Left = 4
  Top = 58
  Height = 233
  Width = 241
  object SocketConnection1: TSocketConnection
    Connected = True
    ServerGUID = '{C72E62C6-61DE-4B1E-8A01-23C26C34A42F}'
    ServerName = 'Project16_1.InterExpressSer'
    Host = 'localhost'
    Left = 80
    Top = 16
  end
  object XMLBroker1: TXMLBroker
    Params = <>
    ProviderName = 'dspCountry'
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
    Left = 88
    Top = 144
    object QueryForm1: TQueryForm
      Action = 'http://localhost/Web/Project16_5.exe/PostCountry'
      Method = fmPost
      object QueryFieldGroup1: TQueryFieldGroup
        XMLBroker = XMLBroker1
      end
      object QueryButtons1: TQueryButtons
        object ResetQueryButton1: TResetQueryButton
          Caption = 'Reset'
          XMLComponent = QueryForm1
          XMLUseParent = False
        end
        object SubmitQueryButton1: TSubmitQueryButton
          Caption = 'Submit'
          XMLComponent = QueryForm1
          XMLUseParent = False
        end
      end
    end
  end
end
