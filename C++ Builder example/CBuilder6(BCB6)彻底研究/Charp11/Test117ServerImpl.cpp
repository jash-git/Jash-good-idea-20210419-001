#include <vcl.h>
#pragma hdrstop

#include "TEST117SERVERIMPL.H"
#include "Unit11_7.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"


/////////////////////////////////////////////////////////////////////////////
// Global instance of TTest117ServerImpl 
/////////////////////////////////////////////////////////////////////////////
TTest117Server *Test117Server;


/////////////////////////////////////////////////////////////////////////////
// TTest117Server::TTest117Server
/////////////////////////////////////////////////////////////////////////////
__fastcall TTest117Server::TTest117Server(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}





void __fastcall TTest117Server::CRemoteDataModuleCreate(TObject *Sender)
{
  // �W�[�@��e�ݪ��W�u�̡]�I�sForm1�W���{�ǡ^
  Form1->UpdateClientCount(1);        
}
//---------------------------------------------------------------------------
void __fastcall TTest117Server::CRemoteDataModuleDestroy(TObject *Sender)
{
  // ��֤@��e�ݪ��W�u�̡]�I�sForm1�W���{�ǡ^
  Form1->UpdateClientCount(-1);        
}
//---------------------------------------------------------------------------
void __fastcall TTest117Server::EventsAfterOpen(TDataSet *DataSet)
{
  // �s�}�Ҥ@��TQuery�d�ߡ]�I�sForm1�W���{�ǡ^
  Form1->IncQueryCount();          
}
//---------------------------------------------------------------------------
