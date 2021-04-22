// TEST136SERVERIMPL.H : Declaration of the Test136Server

#ifndef Test125ServerImplH
#define Test125ServerImplH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "Project12_5_TLB.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <DB.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest125Server : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TTable *Country;
        TDataSetProvider *DataSetProvider1;
        void __fastcall CRemoteDataModuleCreate(TObject *Sender);
        void __fastcall CRemoteDataModuleDestroy(TObject *Sender);
private:      // User declarations
public:       // User declarations
  __fastcall TTest125Server(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest125Server *Test125Server;


/////////////////////////////////////////////////////////////////////////////
// TTest136ServerImpl     Implements ITest136Server, default interface of Test136Server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Test136Server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest125ServerImpl: REMOTEDATAMODULE_IMPL(TTest125ServerImpl, Test125Server, TTest125Server, ITest125Server)
{
public:

BEGIN_COM_MAP(TTest125ServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest125Server)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("Project12_5.Test125Server");
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


// ITest136Server
protected: 
  STDMETHOD(Login(BSTR Username, BSTR Password, VARIANT* Ret));
};

#endif  // Test136ServerImplH

