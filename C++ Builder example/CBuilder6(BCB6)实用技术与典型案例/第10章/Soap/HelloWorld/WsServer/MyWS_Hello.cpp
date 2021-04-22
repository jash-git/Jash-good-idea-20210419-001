// ************************************************************************ //
// Implementation class for interface IMyWS_Hello
// ************************************************************************ //
#include <vcl.h>
#pragma hdrstop

#if !defined(MyWS_HelloH)
#include "MyWS_Hello.h"
#endif

// ************************************************************************ //
//  TMyWS_HelloImpl implements interface IMyWS_Hello
// ************************************************************************ //
class TMyWS_HelloImpl : public TInvokableClass, public IMyWS_Hello
{
public:
    /* Sample methods of IMyWS_Hello */
  SampleEnum     echoEnum(SampleEnum eValue);
  TDoubleArray   echoDoubleArray(const TDoubleArray daValue);
  TSampleStruct* echoStruct(const TSampleStruct* pStruct);
  double         echoDouble(double dValue);

  String        GetAString();

  /* IUnknown */
  HRESULT STDMETHODCALLTYPE QueryInterface(const GUID& IID, void **Obj)
                        { return GetInterface(IID, Obj) ? S_OK : E_NOINTERFACE; }
  ULONG STDMETHODCALLTYPE AddRef() { return TInterfacedObject::_AddRef();  }
  ULONG STDMETHODCALLTYPE Release(){ return TInterfacedObject::_Release(); }

  /* Ensures that the class is not abstract */
  void checkValid() { delete new TMyWS_HelloImpl(); }
};


SampleEnum TMyWS_HelloImpl::echoEnum(SampleEnum eValue)
{
  /* TODO : Implement method echoEnum */
  return eValue;
}

TDoubleArray TMyWS_HelloImpl::echoDoubleArray(TDoubleArray daValue)
{
  /* TODO : Implement method echoDoubleArray */
  return daValue;
}

TSampleStruct* TMyWS_HelloImpl::echoStruct(const TSampleStruct* pEmployee)
{
  /* TODO : Implement method echoMyEmployee */
  return new TSampleStruct();
}

double TMyWS_HelloImpl::echoDouble(const double dValue)
{
  /* TODO : Implement method echoDouble */
  return dValue;
}

String TMyWS_HelloImpl::GetAString()
{
 return "Hello World!";
}


// ************************************************************************ //
//  The following routine registers the interface and implementation class.
// ************************************************************************ //
static void RegTypes()
{
  InvRegistry()->RegisterInterface(__interfaceTypeinfo(IMyWS_Hello));
  InvRegistry()->RegisterInvokableClass(__classid(TMyWS_HelloImpl));
}
#pragma startup RegTypes 32

 