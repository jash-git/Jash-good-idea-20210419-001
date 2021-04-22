// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/MyWSRoot/HelloWorld.dll/wsdl/IMyWS_Hello
// Version  : 1.0
// (2002-6-22 11:56:48 - $Revision:   1.0.1.0.1.82  $)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if !defined(IMyWS_HelloH)
#include "IMyWS_Hello.h"
#endif



namespace NS_IMyWS_Hello {

_di_IMyWS_Hello GetIMyWS_Hello(bool useWSDL, AnsiString addr)
{
  static const char* defWSDL= "http://localhost/MyWSRoot/HelloWorld.dll/wsdl/IMyWS_Hello";
  static const char* defURL = "http://localhost/MyWSRoot/HelloWorld.dll/soap/IMyWS_Hello";
  static const char* defSvc = "IMyWS_Helloservice";
  static const char* defPrt = "IMyWS_HelloPort";
  if (addr=="")
    addr = useWSDL ? defWSDL : defURL;
  THTTPRIO* rio = new THTTPRIO(0);
  if (useWSDL) {
    rio->WSDLLocation = addr;
    rio->Service = defSvc;
    rio->Port = defPrt;
  } else {
    rio->URL = addr;
  }
  _di_IMyWS_Hello service;
  rio->QueryInterface(service);
  if (!service)
    delete rio;
  return service;
}


// ************************************************************************ //
// This routine registers the interfaces and types used by invoke the SOAP
// Service.
// ************************************************************************ //
static void RegTypes()
{
  /* IMyWS_Hello */
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(IMyWS_Hello), L"urn:MyWS_Hello-IMyWS_Hello", L"");
  InvRegistry()->RegisterDefaultSOAPAction(__interfaceTypeinfo(IMyWS_Hello), L"urn:MyWS_Hello-IMyWS_Hello#%operationName%");
  RemClassRegistry()->RegisterXSInfo(GetClsMemberTypeInfo(__typeinfo(SampleEnum_TypeInfoHolder)), L"urn:MyWS_Hello", L"SampleEnum");
  /* TSampleStruct */
  RemClassRegistry()->RegisterXSClass(__classid(TSampleStruct), L"urn:MyWS_Hello", L"TSampleStruct");
}
#pragma startup RegTypes 32

};     // NS_IMyWS_Hello

 