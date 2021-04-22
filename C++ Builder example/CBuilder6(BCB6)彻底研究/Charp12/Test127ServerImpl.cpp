#include <vcl.h>
#pragma hdrstop

#include "Test127ServerImpl.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"

/////////////////////////////////////////////////////////////////////////////
// Global instance of TTest127ServerImpl
/////////////////////////////////////////////////////////////////////////////
TTest127Server *Test127Server;


/////////////////////////////////////////////////////////////////////////////
// TTest138Server::TTest127Server
/////////////////////////////////////////////////////////////////////////////
__fastcall TTest127Server::TTest127Server(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}

void __fastcall TTest127Server::Table1BeforePost(TDataSet *DataSet)
{
  ShowMessage("Table1的BeforePost 被驱动!!");
}
//---------------------------------------------------------------------------

void __fastcall TTest127Server::Table1AfterPost(TDataSet *DataSet)
{
  ShowMessage("Table1的AfterPost 被驱动!!");
}
//---------------------------------------------------------------------------
