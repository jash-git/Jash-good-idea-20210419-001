//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit12_5.h"
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  DataSource1->DataSet->Post();
  ShowMessage("已经新增一位新的使用者!!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
  DBEdit1->Enabled=RadioButton1->Checked;
  DBEdit2->Enabled=RadioButton1->Checked;
  Button1->Enabled=RadioButton1->Checked;
  if (RadioButton1->Checked)
    DataSource1->DataSet->Insert();
}
//---------------------------------------------------------------------------

