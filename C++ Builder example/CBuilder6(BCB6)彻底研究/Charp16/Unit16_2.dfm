object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Default = True
      Name = 'WebActionItem1'
      PathInfo = '/InetXPageProducer1'
      Producer = InetXPageProducer1
    end>
  Left = 224
  Top = 137
  Height = 242
  Width = 183
  object XMLBroker1: TXMLBroker
    Params = <>
    ProviderName = 'DataSetProvider1'
    RemoteServer = SocketConnection1
    WebDispatch.PathInfo = 'XMLBroker1'
    ReconcileProducer = InetXPageProducer1
    Left = 56
    Top = 88
  end
  object InetXPageProducer1: TInetXPageProducer
    IncludePathURL = 'http://localhost/web/'
    HTMLDoc.Strings = (
      '<HTML>'
      '<HEAD>'
      '</HEAD>'
      '<BODY>'
      '<#INCLUDES><#STYLES><#WARNINGS><#FORMS><#SCRIPT>'
      '</BODY>'
      '</HTML>')
    Left = 56
    Top = 152
    object DataForm1: TDataForm
      object FieldGroup1: TFieldGroup
        XMLBroker = XMLBroker1
      end
      object DataNavigator1: TDataNavigator
        XMLComponent = FieldGroup1
        object FirstButton1: TFirstButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object PriorPageButton1: TPriorPageButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object PriorButton1: TPriorButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object NextButton1: TNextButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object NextPageButton1: TNextPageButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object LastButton1: TLastButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object InsertButton1: TInsertButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object DeleteButton1: TDeleteButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object PostButton1: TPostButton
          XMLComponent = FieldGroup1
          XMLUseParent = False
        end
        object ApplyUpdatesButton1: TApplyUpdatesButton
          XMLBroker = XMLBroker1
          XMLUseParent = True
        end
      end
    end
  end
  object SocketConnection1: TSocketConnection
    Connected = True
    ServerGUID = '{C72E62C6-61DE-4B1E-8A01-23C26C34A42F}'
    ServerName = 'Project16_1.InterExpressSer'
    Host = 'localhost'
    Left = 64
    Top = 16
  end
end
