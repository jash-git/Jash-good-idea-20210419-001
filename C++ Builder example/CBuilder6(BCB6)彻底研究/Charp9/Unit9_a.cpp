//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_a.h"
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
  Database1->LoginPrompt=false;
  Database1->Params->Add("USERNAME=SYSDBA");
  Database1->Params->Add("PASSWORD=masterkey");

  try {
    Database1->Connected=true;
  } catch (...) {
    ShowMessage("无法连上Local Interbase数据库!!");
    abort();
  }


  Table1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBLookupComboBox1Click(TObject *Sender)
{
  Query1->Close();
  Query1->SQL->Clear();
  Query1->SQL->Add("Select * from Test_Proc(:EMP_NO)");
  Query1->Params->Items[0]->AsInteger=Table1EMP_NO->AsInteger;
  if (Query1->Prepared==false) Query1->Prepare();
  Query1->Open();
}
//---------------------------------------------------------------------------
