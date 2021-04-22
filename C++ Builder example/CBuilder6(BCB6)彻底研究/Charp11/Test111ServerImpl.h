// TEST111SERVERIMPL.H : Declaration of the Test111Server

#ifndef Test111ServerImplH
#define Test111ServerImplH

#define ATL_FREE_THREADED
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MidConst.hpp>

#include "Project11_1_TLB.h"
#include <DB.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest111Server : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TTable *Table1;
        TDataSetProvider *DataSetProvider1;
private:      // User declarations
public:       // User declarations
  __fastcall TTest111Server(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest111Server *Test111Server;


/////////////////////////////////////////////////////////////////////////////
// TTest111ServerImpl     Implements ITest111Server, default interface of Test111Server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Test111Server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest111ServerImpl: REMOTEDATAMODULE_IMPL(TTest111ServerImpl, Test111Server, TTest111Server, ITest111Server)
{
public:

BEGIN_COM_MAP(TTest111ServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest111Server)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID(_T("Project11_1.Test111Server"));
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


// ITest111Server
protected:
};

#endif  // Test111ServerImplH

