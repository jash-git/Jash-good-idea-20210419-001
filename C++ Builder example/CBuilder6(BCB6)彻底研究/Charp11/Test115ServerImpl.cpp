#include <vcl.h>
#pragma hdrstop

#include "TEST115SERVERIMPL.H"
#include "Unit11_5.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"


/////////////////////////////////////////////////////////////////////////////
// Global instance of TTest115ServerImpl 
/////////////////////////////////////////////////////////////////////////////
TTest115Server *Test115Server;


/////////////////////////////////////////////////////////////////////////////
// TTest115Server::TTest115Server
/////////////////////////////////////////////////////////////////////////////
__fastcall TTest115Server::TTest115Server(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}

STDMETHODIMP TTest115ServerImpl::GetDatabaseNames(BSTR* Ret)
{
  int i;
  TStrings *DBNames;


  DBNames = new TStringList;
  try
  {

    m_DataModule->Session1->GetDatabaseNames(DBNames);

    *Ret = Variant(DBNames->Text);
    delete DBNames;
  }
  catch(Exception &e)
  {
    return Error(e.Message.c_str(), IID_ITest115Server);
  }
  return S_OK;
}

STDMETHODIMP TTest115ServerImpl::SetDatabaseName(BSTR DBName,
  BSTR Password, BSTR* Ret)
{
  AnsiString rt;
  try
  {
    m_DataModule->Database1->Close();
    m_DataModule->Database1->AliasName = DBName;

    if(::SysStringLen(Password))
      m_DataModule->Database1->Params->Values["PASSWORD"] = Password;

    m_DataModule->Database1->Open();
    rt = "Y";
  }
  catch(Exception &e)
  {

    rt = "N";
  }
  *Ret = Variant(rt);
  return S_OK;
}

void __fastcall TTest115Server::CRemoteDataModuleCreate(TObject *Sender)
{

  Form1->UpdateClientCount(1);
}
//---------------------------------------------------------------------------
void __fastcall TTest115Server::CRemoteDataModuleDestroy(TObject *Sender)
{

  Form1->UpdateClientCount(-1);
}
//---------------------------------------------------------------------------
void __fastcall TTest115Server::AdHocQueryAfterOpen(TDataSet *DataSet)
{

  Form1->IncQueryCount();
}
//---------------------------------------------------------------------------
