object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Name = 'QueryCountry'
      PathInfo = '/QueryCountry'
      OnAction = WebModule1QueryCountryAction
    end
    item
      Name = 'QueryCapital'
      PathInfo = '/QueryCapital'
      OnAction = WebModule1QueryCapitalAction
    end>
  Left = 362
  Top = 104
  Height = 208
  Width = 267
  object HTTPRIO1: THTTPRIO
    WSDLLocation = 'http://localhost/CBuilderWeb/Project20_1.exe/wsdl/IQueryCapital'
    Service = 'IQueryCapitalservice'
    Port = 'IQueryCapitalPort'
    HTTPWebNode.Agent = 'Borland SOAP 1.1'
    HTTPWebNode.UseUTF8InHeader = False
    HTTPWebNode.InvokeOptions = [soIgnoreInvalidCerts]
    Converter.Options = [soSendMultiRefObj, soTryAllSchema, soRootRefNodesToBody]
    Left = 48
    Top = 24
  end
end
