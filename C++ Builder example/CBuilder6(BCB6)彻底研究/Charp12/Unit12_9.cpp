//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit12_9.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  DCOMConnection1->Connected=true;
  cdsCustomer->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CloseActionExecute(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplyUpdateExecute(TObject *Sender)
{
  try
  {
    cdsCustomer->ApplyUpdates(-1);
    ShowMessage("已经正确地写入数据库中!!");
  }
  catch (Exception &exception)
  {
    Application->ShowException(&exception);
  }
}
//---------------------------------------------------------------------------

