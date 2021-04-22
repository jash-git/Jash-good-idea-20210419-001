//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit10_1.h"
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
  int i,j;
  Currency amount;

  Query1->Close();
  Query1->DatabaseName="BCDEMOS";
  Query1->SQL->Add("Select * From Orders");
  Query1->Prepare();
  Query1->Open();

  StringGrid1->RowCount=Query1->RecordCount;
  StringGrid1->ColCount=Query1->FieldCount;

  for (i=0; i<Query1->RecordCount; i++)
  {
    for (j=0; j<Query1->FieldCount; j++)
    {

      if (i==0)
        StringGrid1->Cells[j+1][0] = Query1->Fields->Fields[j]->FieldName;


      StringGrid1->Cells[j+1][i+1] = Query1->Fields->Fields[j]->AsString;

      amount += Query1->FieldByName("AmountPaid")->AsCurrency;
    }
    StringGrid1->Cells[0][i+1] = IntToStr(i+1);
    Query1->Next();
  }
  Edit1->Text=CurrToStr(amount);
}
//---------------------------------------------------------------------------
 