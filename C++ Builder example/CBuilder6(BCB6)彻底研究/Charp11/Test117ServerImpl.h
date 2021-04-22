// TEST117SERVERIMPL.H : Declaration of the Test117Server

#ifndef Test117ServerImplH
#define Test117ServerImplH

#define ATL_FREE_THREADED
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MidConst.hpp>

#include "Project11_7_TLB.h"
#include <DB.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TTest117Server : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TQuery *Events;
        TDataSetProvider *DataSetProvider1;
        void __fastcall CRemoteDataModuleCreate(TObject *Sender);
        void __fastcall CRemoteDataModuleDestroy(TObject *Sender);
        void __fastcall EventsAfterOpen(TDataSet *DataSet);
private:      // User declarations
public:       // User declarations
  __fastcall TTest117Server(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TTest117Server *Test117Server;


/////////////////////////////////////////////////////////////////////////////
// TTest117ServerImpl     Implements ITest117Server, default interface of Test117Server
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.Test117Server
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TTest117ServerImpl: REMOTEDATAMODULE_IMPL(TTest117ServerImpl, Test117Server, TTest117Server, ITest117Server)
{
public:

BEGIN_COM_MAP(TTest117ServerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(ITest117Server)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID(_T("Project11_7.Test117Server"));
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


// ITest117Server
protected:
};

#endif  // Test117ServerImplH

