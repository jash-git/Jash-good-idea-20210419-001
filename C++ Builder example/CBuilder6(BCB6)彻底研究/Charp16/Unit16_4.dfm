object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'WebActionItem1'
      OnAction = WebModule1WebActionItem1Action
    end>
  Left = 256
  Top = 103
  Height = 271
  Width = 369
  object SocketConnection1: TSocketConnection
    Connected = True
    ServerGUID = '{C72E62C6-61DE-4B1E-8A01-23C26C34A42F}'
    ServerName = 'Project16_1.InterExpressSer'
    Host = 'localhost'
    Left = 80
    Top = 16
  end
  object XMLBroker1: TXMLBroker
    Params = <
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
    ProviderName = 'dspQueryDepartment'
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
    Left = 224
    Top = 160
    object QueryForm1: TQueryForm
      Action = 'http://localhost/Web/Project16_4.exe/QueryResult'
      Method = fmPost
      object QueryFieldGroup1: TQueryFieldGroup
        XMLBroker = XMLBroker1
      end
      object QueryButtons1: TQueryButtons
        object ResetQueryButton1: TResetQueryButton
          Caption = 'Reset'
          XMLComponent = QueryForm1
        end
        object SubmitQueryButton1: TSubmitQueryButton
          Caption = 'Submit'
          XMLComponent = QueryForm1
        end
      end
    end
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <
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
    ProviderName = 'dspQueryDepartment'
    RemoteServer = SocketConnection1
    Left = 88
    Top = 160
  end
end
