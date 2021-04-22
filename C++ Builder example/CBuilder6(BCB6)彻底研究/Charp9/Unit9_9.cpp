//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_9.h"
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
    return;
  }

  Table1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DBLookupComboBox1Click(TObject *Sender)
{
  // рㄏノ翴匡场絪腹肚倒AVG_PROCStroed Procedure
  // 硂 Stroed Procedure ノㄓ璸衡琘场┮ΤキА羱戈
  StoredProc1->Close();
  StoredProc1->ParamByName("DEPT_NO")->AsString=Table1DEPT_NO->AsString;
  if (StoredProc1->Prepared==false) StoredProc1->Prepare();
  StoredProc1->ExecProc();
  Label3->Caption=StoredProc1->ParamByName("AVG_SALARY")->AsString;
}
//---------------------------------------------------------------------------
