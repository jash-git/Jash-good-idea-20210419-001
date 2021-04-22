// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/MyWSRoot/HelloWorld.dll/wsdl/IMyWS_Hello
// Version  : 1.0
// (2002-6-22 11:56:48 - $Revision:   1.0.1.0.1.82  $)
// ************************************************************************ //

#ifndef   IMyWS_HelloH
#define   IMyWS_HelloH

#include <System.hpp>
#include <InvokeRegistry.hpp>
#include <XSBuiltIns.hpp>
#include <SoapHTTPClient.hpp>


namespace NS_IMyWS_Hello {

// ************************************************************************ //
// The following types, referred to in the WSDL document are not being represented
// in this file. They are either aliases[@] of other types represented or were referred
// to but never[!] declared in the document. The types from the latter category
// typically map to predefined/known XML or Borland types; however, they could also 
// indicate incorrect WSDL documents that failed to declare or import a schema type.
// ************************************************************************ //
// !:string          - "http://www.w3.org/2001/XMLSchema"
// !:double          - "http://www.w3.org/2001/XMLSchema"
// !:TDoubleDynArray - "http://www.borland.com/namespaces/Types"

class  TSampleStruct;

enum SampleEnum   /* "urn:MyWS_Hello" */
{
  etNone, 
  etAFew, 
  etSome, 
  etALot
};

class SampleEnum_TypeInfoHolder : public TObject {
  SampleEnum __instanceType;
public:
__published:
  __property SampleEnum __propType = { read=__instanceType };
};



// ************************************************************************ //
// Namespace : urn:MyWS_Hello
// ************************************************************************ //
class TSampleStruct : public TRemotable {
private:
  AnsiString      FLastName;
  AnsiString      FFirstName;
  double          FSalary;
public:
__published:
  __property AnsiString   LastName = { read=FLastName, write=FLastName };
  __property AnsiString  FirstName = { read=FFirstName, write=FFirstName };
  __property double         Salary = { read=FSalary, write=FSalary };
};



// ************************************************************************ //
// Namespace : urn:MyWS_Hello-IMyWS_Hello
// soapAction: urn:MyWS_Hello-IMyWS_Hello#%operationName%
// transport : http://schemas.xmlsoap.org/soap/http
// style     : rpc
// binding   : IMyWS_Hellobinding
// service   : IMyWS_Helloservice
// port      : IMyWS_HelloPort
// URL       : http://localhost/MyWSRoot/HelloWorld.dll/soap/IMyWS_Hello
// ************************************************************************ //
__interface INTERFACE_UUID("{8F7FDF2E-1CF3-C426-9EBD-1244730C05F3}") IMyWS_Hello : public IInvokable
{
public:
  virtual SampleEnum      echoEnum(const SampleEnum eValue) = 0; 
  virtual TDoubleDynArray echoDoubleArray(const TDoubleDynArray daValue) = 0; 
  virtual TSampleStruct*  echoStruct(const TSampleStruct* pEmployee) = 0; 
  virtual double          echoDouble(const double dValue) = 0; 
  virtual AnsiString      GetAString() = 0; 
};
typedef DelphiInterface<IMyWS_Hello> _di_IMyWS_Hello;

_di_IMyWS_Hello GetIMyWS_Hello(bool useWSDL=false, AnsiString addr="");



#endif // __IMyWS_Hello_h__

};     // NS_IMyWS_Hello

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace NS_IMyWS_Hello;
#endif

 