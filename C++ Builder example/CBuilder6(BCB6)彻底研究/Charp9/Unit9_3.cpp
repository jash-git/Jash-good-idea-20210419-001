//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_3.h"
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
  Table1->Close();
  Table1->Filtered=True;
  Table1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Table1FilterRecord(TDataSet *DataSet, bool &Accept)
{
  AnsiString temp;


  temp=(Table1->FieldByName("Company")->AsString).SubString(1,(Edit1->Text).Length());


  if ((!CompareStr(Edit1->Text,temp)) || (!(Edit1->Text).Length()))
    Accept=True;
  else
    Accept=False;
}
//---------------------------------------------------------------------------
