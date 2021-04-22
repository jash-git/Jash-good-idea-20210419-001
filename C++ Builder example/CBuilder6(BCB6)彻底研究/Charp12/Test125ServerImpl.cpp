#include <vcl.h>
#pragma hdrstop

#include "Test125ServerImpl.h"
#include "Unit12_5.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"


/////////////////////////////////////////////////////////////////////////////
// Global instance of TTest125ServerImpl
/////////////////////////////////////////////////////////////////////////////
TTest125Server *Test125Server;
bool FLoggedIn;
AnsiString FUserName;

/////////////////////////////////////////////////////////////////////////////
// TTest136Server::TTest125Server
/////////////////////////////////////////////////////////////////////////////
__fastcall TTest125Server::TTest125Server(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}

STDMETHODIMP TTest125ServerImpl::Login(BSTR Username, BSTR Password,
  VARIANT* Ret)
{
  TLocateOptions Opts;

  Opts.Clear();
  try
  {
    if (Form1->cdsUser->Locate("UserName",Username,Opts))
      {
        if (CompareStr(Password,Form1->cdsUser->FieldByName("Password")->AsString)==0)
          {
            Form1->ListBox1->Items->Add(Username);
            FLoggedIn = true;
            FUserName = Username;
          }
      }
    else
      FLoggedIn = False;
    *Ret = Variant(FLoggedIn);
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ITest125Server);
  }
  return S_OK;
}

void __fastcall TTest125Server::CRemoteDataModuleCreate(TObject *Sender)
{
  FLoggedIn = false;
}
//---------------------------------------------------------------------------

void __fastcall TTest125Server::CRemoteDataModuleDestroy(TObject *Sender)
{
  Form1->ListBox1->Items->Delete(Form1->ListBox1->Items->IndexOf(FUserName));
}
//---------------------------------------------------------------------------

