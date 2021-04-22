// ************************************************************************ //
// The types declared in this file were generated from data read from the
// WSDL File described below:
// WSDL     : http://www.ebob42.com/cgi-bin/DrBobsClinic.exe/wsdl/IHeadline
// Version  : 1.0
// (2002/4/22 ¤W¤È 08:08:05 - $Revision:   1.0.1.0.1.81  $)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#if !defined(__IHeadline_h__)
#include "Unit20_32.h"
#endif



namespace NS_IHeadline {

_di_IHeadLine GetIHeadLine(bool useWSDL, AnsiString addr)
{
  static const char* defWSDL= "http://www.ebob42.com/cgi-bin/DrBobsClinic.exe/wsdl/IHeadline";
  static const char* defURL = "http://www.eBob42.com/cgi-bin/DrBobsClinic.exe/soap/IHeadLine";
  static const char* defSvc = "IHeadLineservice";
  static const char* defPrt = "IHeadLinePort";
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
  _di_IHeadLine service;
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
  /* IHeadLine */
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(IHeadLine), L"urn:Headline-IHeadLine", L"");
  InvRegistry()->RegisterDefaultSOAPAction(__interfaceTypeinfo(IHeadLine), L"urn:Headline-IHeadLine#%operationName%");
}
#pragma startup RegTypes 32

};     // IHeadline

