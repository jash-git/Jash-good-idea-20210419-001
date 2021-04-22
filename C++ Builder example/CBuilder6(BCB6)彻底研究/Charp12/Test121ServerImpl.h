// TEST121SERVERIMPL.H : Declaration of the Test121Server

#ifndef Test121ServerImplH
#define Test121ServerImplH

#define ATL_FREE_THREADED
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MidConst.hpp>

#include "Project12_1_TLB.h"
#include <DB.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest121Server : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TQuery *Query1;
        TSession *Session1;
        TDatabase *Database1;
        TDataSetProvider *DataSetProvider2;
        TTable *Customer;
        TTable *Order;
        TDataSetProvider *DataSetProvider1;
        TDataSource *DataSource1;
private:      // User declarations
public:       // User declarations
  __fastcall TTest121Server(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest121Server *Test121Server;


/////////////////////////////////////////////////////////////////////////////
// TTest121ServerImpl     Implements ITest121Server, default interface of Test121Server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Test121Server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest121ServerImpl: REMOTEDATAMODULE_IMPL(TTest121ServerImpl, Test121Server, TTest121Server, ITest121Server)
{
public:

BEGIN_COM_MAP(TTest121ServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest121Server)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID(_T("Project12_1.Test121Server"));
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


// ITest121Server
protected:
};

#endif  // Test121ServerImplH

