// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://localhost/CBuilderWeb/Project20_1.exe/wsdl/IQueryCapital
// Version  : 1.0
// (2002/4/22 ¤W¤È 10:14:05 - $Revision:   1.0.1.0.1.81  $)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if !defined(__IQueryCapital_h__)
#include "Unit20_42.h"
#endif



namespace NS_IQueryCapital {

_di_IQueryCapital GetIQueryCapital(bool useWSDL, AnsiString addr)
{
  static const char* defWSDL= "http://localhost/CBuilderWeb/Project20_1.exe/wsdl/IQueryCapital";
  static const char* defURL = "http://localhost/CBuilderWeb/Project20_1.exe/soap/IQueryCapital";
  static const char* defSvc = "IQueryCapitalservice";
  static const char* defPrt = "IQueryCapitalPort";
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
  _di_IQueryCapital service;
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
  /* IQueryCapital */
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(IQueryCapital), L"urn:Unit20_12-IQueryCapital", L"");
}
#pragma startup RegTypes 32

};     // IQueryCapital

