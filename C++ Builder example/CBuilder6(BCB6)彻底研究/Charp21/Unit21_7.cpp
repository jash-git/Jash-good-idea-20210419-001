//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit21_7.h"
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


void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DataSource1DataChange(TObject *Sender,
      TField *Field)
{
  DBChart1->RefreshData();
}
//---------------------------------------------------------------------------
