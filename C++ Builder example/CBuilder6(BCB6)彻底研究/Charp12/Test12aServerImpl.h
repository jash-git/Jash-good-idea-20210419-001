// TEST13BSERVERIMPL.H : Declaration of the Test13bServer

#ifndef Test12aServerImplH
#define Test12aServerImplH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "Project12_a_TLB.h"
#include <atl/atlvcl.h>


#define _MTX_NOFORCE_LIBS
#include <mtx.h>
#include <vcl\mtshlpr.h>

// Forward ref. of IAppServer/IObjectControl implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest12aServer : public TCRemoteDataModule
{
__published:  // IDE-managed Components
private:      // User declarations
public:       // User declarations
  __fastcall TTest12aServer(TComponent* Owner);

  Classes::TNotifyEvent FOnActivate;        // Expose IObjectControl.Activate as VCL event
  Classes::TNotifyEvent FOnDeactivate;      // Expose IObjectControl.Deactivate as VCL event
__published:
  __property Classes::TNotifyEvent OnActivate   = {read=FOnActivate,   write=FOnActivate};
  __property Classes::TNotifyEvent OnDeactivate = {read=FOnDeactivate, write=FOnDeactivate};
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest12aServer *Test12aServer;


/////////////////////////////////////////////////////////////////////////////
// TTest13bServerImpl     Implements ITest13bServer, default interface of Test13bServer
// ThreadingModel : tmApartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project2.Test13bServer
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest12aServerImpl: REMOTEDATAMODULE_IMPL(TTest12aServerImpl, Test12aServer, TTest12aServer, ITest12aServer),
                                  public IObjectControl
{
public:

BEGIN_COM_MAP(TTest12aServerImpl)
  COM_INTERFACE_ENTRY(IObjectControl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest12aServer)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_PROGID("Project12_a.Test12aServer");
  DECLARE_DESCRIPTION("");

  // Function invoked to (un)register object
  //
  static HRESULT WINAPI UpdateRegistry(BOOL bRegister)
  {
    TRemoteDataModuleRegistrar regObj(GetObjectCLSID(), GetProgID(), GetDescription());
    // Disable these flags in order to disable use by socket or web connections.
    // Also set other flags to configure the behavior of your application server.
    // For more information, see atlmod.h and atlvcl.cpp.
    regObj.Singleton = false;
    regObj.EnableWeb = true;
    regObj.EnableSocket = true;
    return regObj.UpdateRegistry(bRegister);
  }

  // Inline methods to facilitate access to IObjectContext interface
  //
  void    SetComplete()       { m_spObjectContext->SetComplete();   } 
  void    SetAbort()          { m_spObjectContext->SetAbort();      }
  void    EnableCommit()      { m_spObjectContext->EnableCommit();  }
  void    DisableCommit()     { m_spObjectContext->DisableCommit(); }
  bool    IsInTransaction()   { return m_spObjectContext->IsInTransaction() != 0;  }
  bool    IsSecurityEnabled() { return m_spObjectContext->IsSecurityEnabled() != 0;}
  HRESULT IsCallerInRole(BSTR str, BOOL* bVal)    
  { 
    return m_spObjectContext->IsCallerInRole(str, bVal);   
  }
  bool    IsCallerInRole(BSTR str)
  {
    BOOL bVal;
    OLECHECK(IsCallerInRole(str, &bVal));
    return bVal != VARIANT_FALSE;
  }

// IObjectControl
public:
  STDMETHOD(Activate)();
  STDMETHOD(GetName(VARIANT* Ret));
  STDMETHOD_(BOOL, CanBePooled)();
  STDMETHOD_(void, Deactivate)();


  // Data member hold IObjectContext interface
  //
  CComPtr<IObjectContext> m_spObjectContext;

// ITest13bServer
protected:
};

#endif  // Test13bServerImplH

