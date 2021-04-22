// TMEDIA_SERVERIMPL.H : Declaration of the TTmedia_serverImpl

#ifndef Tmedia_serverImplH
#define Tmedia_serverImplH

#include "Project7_h_TLB.h"


/////////////////////////////////////////////////////////////////////////////
// TTmedia_serverImpl     Implements ITmedia_server, default interface of Tmedia_server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Tmedia_server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTmedia_serverImpl : 
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<TTmedia_serverImpl, &CLSID_Tmedia_server>,
  public IDispatchImpl<ITmedia_server, &IID_ITmedia_server, &LIBID_Project7_h>
{
public:
  TTmedia_serverImpl()
  {
  }

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("Project7_h.Tmedia_server");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TTypedComServerRegistrarT<TTmedia_serverImpl> 
    regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    return regObj.UpdateRegistry(bRegister);
  }


BEGIN_COM_MAP(TTmedia_serverImpl)
  COM_INTERFACE_ENTRY(ITmedia_server)
  COM_INTERFACE_ENTRY2(IDispatch, ITmedia_server)
END_COM_MAP()

// ITmedia_server
public:
 
  STDMETHOD(get_FileStr(VARIANT* Value));
  STDMETHOD(OpenFile());
  STDMETHOD(PlayFile());
  STDMETHOD(set_FileStr(VARIANT Value));
  STDMETHOD(StopFile());
};

#endif //Tmedia_serverImplH
