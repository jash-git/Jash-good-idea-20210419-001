//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_b.h"
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
  int i;

  // 你必須先到Object Inspector把DBGrid屬性Options
  // 中的 dgRowSelect 和 dgMultiSelect 設成true
  for(i=0; i<DBGrid1->SelectedRows->Count; i++) {

    // 將資料表的指標Bookmark指向DBGrid上選擇的那一筆
    DBGrid1->DataSource->DataSet->Bookmark=DBGrid1->SelectedRows->Items[i];

    // 將DBGrid上選出的資料加到ListBox元件內
    ListBox1->Items->Add(Table1CustNo->AsString);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  ListBox1->Items->Clear();
}
//---------------------------------------------------------------------------
