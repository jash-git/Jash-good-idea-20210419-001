// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://www.ebob42.com/cgi-bin/DrBobsClinic.exe/wsdl/IHeadline
// Version  : 1.0
// (2002/4/22 ¤W¤È 08:08:05 - $Revision:   1.0.1.0.1.81  $)
// ************************************************************************ //

#ifndef   __IHeadline_h__
#define   __IHeadline_h__

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <SoapHTTPClient.hpp>


namespace NS_IHeadline {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Borland types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:int             - "http://www.w3.org/2001/XMLSchema"
// !:string          - "http://www.w3.org/2001/XMLSchema"


// ************************************************************************ //
// Namespace : urn:Headline-IHeadLine
// soapAction: urn:Headline-IHeadLine#%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// binding   : IHeadLinebinding
// service   : IHeadLineservice
// port      : IHeadLinePort
// URL       : http://www.eBob42.com/cgi-bin/DrBobsClinic.exe/soap/IHeadLine
// ************************************************************************ //
__interface INTERFACE_UUID("{F67B20B8-68C4-B0F0-A622-4C91EBA21DDE}") IHeadLine : public IInvokable
{
public:
  virtual AnsiString      DelphiNews(const int format) = 0; 
  virtual AnsiString      CBuilderNews(const int format) = 0; 
  virtual AnsiString      JBuilderNews(const int format) = 0;
  virtual AnsiString      KylixNews(const int format) = 0; 
  virtual AnsiString      SOAPNews(const int format) = 0; 
  virtual AnsiString      BorConNews(const int format) = 0; 
};
typedef DelphiInterface<IHeadLine> _di_IHeadLine;

_di_IHeadLine GetIHeadLine(bool useWSDL=false, AnsiString addr="");



#endif // __IHeadline_h__

};     // IHeadline

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_IHeadline;
#endif

 