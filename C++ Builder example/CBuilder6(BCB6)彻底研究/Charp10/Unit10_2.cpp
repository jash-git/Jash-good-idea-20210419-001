//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit10_2.h"
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
  AnsiString temp;
  int i,j;

  Query1->SQL=Memo1->Lines;
  Query1->Prepare();
  Query1->Open();

  for(i=0; i<Query1->RecordCount; i++) {
    temp="";
    for(j=0; j<Query1->FieldCount; j++) {
      temp+=(Query1->Fields->Fields[j]->AsString+" ");
    }
    Memo2->Lines->Add(temp);
    Query1->Next();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Query1->SQL->Clear();
  Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Memo2->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
  if( SaveDialog1->Execute() ) {
    Memo2->Lines->SaveToFile(SaveDialog1->FileName);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Close();    
}
//---------------------------------------------------------------------------
