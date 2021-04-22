//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit11_2.h"
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
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  cdsCustomer->Close();
  DCOMConnection1->Connected=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PostExecute(TObject *Sender)
{
  try
  {
    cdsCustomer->ApplyUpdates(-1);
    ShowMessage("已经正确的写入数据库!!");
  }
  catch (Exception &exception)
  {
    Application->ShowException(&exception);
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton6Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

