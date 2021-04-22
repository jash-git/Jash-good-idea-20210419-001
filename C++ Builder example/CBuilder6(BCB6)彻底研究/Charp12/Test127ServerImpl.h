// TEST138SERVERIMPL.H : Declaration of the Test138Server

#ifndef Test127ServerImplH
#define Test127ServerImplH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "Project12_7_TLB.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <DBClient.hpp>
#include <DB.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest127Server : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TTable *Table1;
        TDataSetProvider *DataSetProvider1;
        TClientDataSet *ClientDataSet1;
        TDataSetProvider *DataSetProvider2;
        void __fastcall Table1BeforePost(TDataSet *DataSet);
        void __fastcall Table1AfterPost(TDataSet *DataSet);
private:      // User declarations
public:       // User declarations
  __fastcall TTest127Server(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest127Server *Test127Server;


/////////////////////////////////////////////////////////////////////////////
// TTest138ServerImpl     Implements ITest138Server, default interface of Test138Server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Test138Server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest127ServerImpl: REMOTEDATAMODULE_IMPL(TTest127ServerImpl, Test127Server, TTest127Server, ITest127Server)
{
public:

BEGIN_COM_MAP(TTest127ServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest127Server)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID("Project12_7.Test127Server");
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


// ITest138Server
protected:
};

#endif  // Test138ServerImplH

