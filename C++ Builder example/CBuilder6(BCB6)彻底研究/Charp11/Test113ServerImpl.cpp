#include <vcl.h>
#pragma hdrstop

#include "TEST113SERVERIMPL.H"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"


/////////////////////////////////////////////////////////////////////////////
// Global instance of TTest113ServerImpl 
/////////////////////////////////////////////////////////////////////////////
TTest113Server *Test113Server;


/////////////////////////////////////////////////////////////////////////////
// TTest113Server::TTest113Server
/////////////////////////////////////////////////////////////////////////////
__fastcall TTest113Server::TTest113Server(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}

STDMETHODIMP TTest113ServerImpl::ApplyUpdates(VARIANT* CustVar)
{
  int ErrCount = 0;


  m_DataModule->Database1->StartTransaction();
  try
  {
    OleVariant& vCustVar = *(reinterpret_cast<OleVariant*>(CustVar));

    if(!vCustVar.IsNull())
    {
      ErrCount = 0;
      m_DataModule->DataSetProvider1->ApplyUpdates(vCustVar, 0, ErrCount, vCustVar);
      if(ErrCount > 0)
        Error("Error in ApplyUpdates", IID_ITest113Server);
    }

    m_DataModule->Database1->Commit();
  }
  catch(Exception &e)
  {

    m_DataModule->Database1->Rollback();
    return Error(e.Message.c_str(), IID_ITest113Server);
  }
  return S_OK;
}
  
