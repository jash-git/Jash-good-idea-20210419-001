// TEST115SERVERIMPL.H : Declaration of the Test115Server

#ifndef Test115ServerImplH
#define Test115ServerImplH

#define ATL_FREE_THREADED
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MidConst.hpp>

#include "Project11_5_TLB.h"
#include <DB.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest115Server : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TQuery *AdHocQuery;
        TSession *Session1;
        TDatabase *Database1;
        TDataSetProvider *AdHocProvider;
        void __fastcall CRemoteDataModuleCreate(TObject *Sender);
        void __fastcall CRemoteDataModuleDestroy(TObject *Sender);
        void __fastcall AdHocQueryAfterOpen(TDataSet *DataSet);
private:      // User declarations
public:       // User declarations
  __fastcall TTest115Server(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest115Server *Test115Server;


/////////////////////////////////////////////////////////////////////////////
// TTest115ServerImpl     Implements ITest115Server, default interface of Test115Server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Test115Server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest115ServerImpl: REMOTEDATAMODULE_IMPL(TTest115ServerImpl, Test115Server, TTest115Server, ITest115Server)
{
public:

BEGIN_COM_MAP(TTest115ServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest115Server)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID(_T("Project11_5.Test115Server"));
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


// ITest115Server
protected: 
  STDMETHOD(GetDatabaseNames(BSTR* Ret));
  STDMETHOD(SetDatabaseName(BSTR DBName, BSTR Password, BSTR* Ret));
};

#endif  // Test115ServerImplH

