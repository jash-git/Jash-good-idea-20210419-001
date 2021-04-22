object WebModule1: TWebModule1
  OldCreateOrder = False
  Actions = <
    item
      Name = 'QueryHeadLine'
      PathInfo = '/QueryHeadLine'
      OnAction = WebModule1QueryHeadLineAction
    end>
  Left = 255
  Top = 62
  Height = 264
  Width = 392
  object HTTPRIO1: THTTPRIO
    WSDLLocation = 'http://www.ebob42.com/cgi-bin/DrBobsClinic.exe/wsdl/IHeadline'
    Service = 'IHeadLineservice'
    Port = 'IHeadLinePort'
    HTTPWebNode.Agent = 'Borland SOAP 1.1'
    HTTPWebNode.UseUTF8InHeader = False
    HTTPWebNode.InvokeOptions = [soIgnoreInvalidCerts]
    Converter.Options = [soSendMultiRefObj, soTryAllSchema, soRootRefNodesToBody]
    Left = 40
    Top = 32
  end
end
