// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/CBuilderWeb/Project20_1.exe/wsdl/IQueryCapital
// Version  : 1.0
// (2002/4/21 ¤U¤È 11:25:51 - $Revision:   1.0.1.0.1.81  $)
// ************************************************************************ //

#ifndef   __IQueryCapital_h__
#define   __IQueryCapital_h__

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <SoapHTTPClient.hpp>


namespace NS_IQueryCapital {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Borland types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:string          - "http://www.w3.org/2001/XMLSchema"


// ************************************************************************ //
// Namespace : urn:Unit20_12-IQueryCapital
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// binding   : IQueryCapitalbinding
// service   : IQueryCapitalservice
// port      : IQueryCapitalPort
// URL       : http://localhost/CBuilderWeb/Project20_1.exe/soap/IQueryCapital
// ************************************************************************ //
__interface INTERFACE_UUID("{D4C8AA35-7F70-358C-846B-99794965B304}") IQueryCapital : public IInvokable
{
public:
  virtual AnsiString      QueryCountry() = 0; 
  virtual AnsiString      QueryCapital(const AnsiString Country) = 0; 
};
typedef DelphiInterface<IQueryCapital> _di_IQueryCapital;

_di_IQueryCapital GetIQueryCapital(bool useWSDL=false, AnsiString addr="");



#endif // __IQueryCapital_h__

};     // IQueryCapital

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_IQueryCapital;
#endif

 