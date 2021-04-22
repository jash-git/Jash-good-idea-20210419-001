// INTEREXPRESSSERIMPL.H : Declaration of the InterExpressSer

#ifndef InterExpressSerImplH
#define InterExpressSerImplH

#define ATL_FREE_THREADED
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MidConst.hpp>

#include "Project16_1_TLB.h"
#include <DB.hpp>
#include <DBTables.hpp>
#include <Provider.hpp>
#include <DBBdeWeb.hpp>
#include <DBWeb.hpp>
#include <HTTPApp.hpp>
#include <atl/atlvcl.h>



// Forward ref. of IAppServer implementor


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
class TInterExpressSer : public TCRemoteDataModule
{
__published:  // IDE-managed Components
        TQuery *Query1;
        TDataSetProvider *DataSetProvider1;
        TDatabase *Database1;
        TQuery *qDepartment;
        TQuery *qEmployee;
        TDataSource *ds1;
        TDataSetProvider *DataSetProvider2;
        TQuery *qQueryDepartment;
        TQuery *qQueryEmployee;
        TDataSetProvider *dspQueryDepartment;
        TQueryTableProducer *qtpQueryEmployee;
        TQuery *qCountry;
        TQuery *qUpdate;
        TDataSetProvider *dspCountry;
        TQueryTableProducer *qtpCountry;
private:      // User declarations
public:       // User declarations
  __fastcall TInterExpressSer(TComponent* Owner);

__published:
};


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
extern PACKAGE TInterExpressSer *InterExpressSer;


/////////////////////////////////////////////////////////////////////////////
// TInterExpressSerImpl     Implements IInterExpressSer, default interface of InterExpressSer
// ThreadingModel : Apartment
// Dual Interface : TRUE
// Event Support  : FALSE
// Default ProgID : Project1.InterExpressSer
// Description    : 
/////////////////////////////////////////////////////////////////////////////
class ATL_NO_VTABLE TInterExpressSerImpl: REMOTEDATAMODULE_IMPL(TInterExpressSerImpl, InterExpressSer, TInterExpressSer, IInterExpressSer)
{
public:

BEGIN_COM_MAP(TInterExpressSerImpl)
  RDMOBJECT_COM_INTERFACE_ENTRIES(IInterExpressSer)
END_COM_MAP()

  // Data used when registering Object 
  //
  DECLARE_THREADING_MODEL(otApartment);
  DECLARE_PROGID(_T("Project16_1.InterExpressSer"));
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


// IInterExpressSer
protected: 
  STDMETHOD(QueryEmployee(BSTR DEPT_NO, BSTR FULL_NAME, VARIANT* ret));
  STDMETHOD(PostCountry(BSTR INPUT, VARIANT* ret));
  STDMETHOD(QueryCountry(VARIANT* ret));
};

#endif  // InterExpressSerImplH

