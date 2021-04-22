#include <vcl.h>
#pragma hdrstop

#include "Test12aServerImpl.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"

/////////////////////////////////////////////////////////////////////////////
// Global instance of TTest12aServerImpl
/////////////////////////////////////////////////////////////////////////////
TTest12aServer *Test12aServer;

/////////////////////////////////////////////////////////////////////////////
// TTest12aServer::TTest12aServer
/////////////////////////////////////////////////////////////////////////////
__fastcall TTest12aServer::TTest12aServer(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}

STDMETHODIMP TTest12aServerImpl::Activate()
{
  // Retrieve ObjectContext
  //
  static TMtsDll Mts;
  HRESULT hr = E_FAIL;
  hr = Mts.Get_ObjectContext(&m_spObjectContext);

  // Fire 'OnActivate' Event
  //
  if (m_DataModule->FOnActivate)
    m_DataModule->FOnActivate(Test12aServer);

  if (SUCCEEDED(hr))
    return S_OK;
  return hr;
}

STDMETHODIMP_(BOOL) TTest12aServerImpl::CanBePooled()
{
  return FALSE;
} 


STDMETHODIMP_(void) TTest12aServerImpl::Deactivate()
{
  // Fire 'OnDeactivate' event 
  //
  if (m_DataModule->FOnDeactivate)
    m_DataModule->FOnDeactivate(Test12aServer);

  // Release Object Context
  //
  m_spObjectContext.Release();
}

STDMETHODIMP TTest12aServerImpl::GetName(VARIANT* Ret)
{
  AnsiString temp;

  temp="现在应用程序服务器(MTS Object)上的时间是："+TimeToStr(Time());
  *Ret =Variant(temp);
}


