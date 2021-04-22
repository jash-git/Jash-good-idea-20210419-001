//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit12_3.h"
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
void __fastcall TForm1::Action1Update(TObject *Sender)
{
  Action1->Checked = DCOMConnection1->Connected;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Action2Update(TObject *Sender)
{
  Action2->Enabled = (ClientDataSet1->ChangeCount > 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Action2Execute(TObject *Sender)
{
  try
  {
    ClientDataSet1->ApplyUpdates(-1);
    ShowMessage("已经正确写入数据库!!");
  }
  catch (Exception &exception)
  {
    Application->ShowException(&exception);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  DCOMConnection2->Connected=true;
  ClientDataSet2->Close();
  ClientDataSet2->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
  if (CheckBox1->Checked) {
    ClientDataSet1->Close();
    ClientDataSet1->Open();
  }

}
//---------------------------------------------------------------------------


