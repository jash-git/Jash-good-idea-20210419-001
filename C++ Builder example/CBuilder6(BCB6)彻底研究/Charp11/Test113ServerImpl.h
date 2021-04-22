// TEST113SERVERIMPL.H : Declaration of the Test113Server

#ifndef Test113ServerImplH
#define Test113ServerImplH

#define ATL_FREE_THREADED
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MidConst.hpp>

#include "Project11_3_TLB.h"
#include <DB.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest113Server : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TDatabase *Database1;
        TTable *Table1;
        TDataSetProvider *DataSetProvider1;
private:      // User declarations
public:       // User declarations
  __fastcall TTest113Server(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest113Server *Test113Server;


/////////////////////////////////////////////////////////////////////////////
// TTest113ServerImpl     Implements ITest113Server, default interface of Test113Server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Test113Server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest113ServerImpl: REMOTEDATAMODULE_IMPL(TTest113ServerImpl, Test113Server, TTest113Server, ITest113Server)
{
public:

BEGIN_COM_MAP(TTest113ServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest113Server)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID(_T("Project11_3.Test113Server"));
  DECLARE_DESCRIPTION(_T(""));

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


// ITest113Server
protected: 
  STDMETHOD(ApplyUpdates(VARIANT* CustVar));
};

#endif  // Test113ServerImplH

