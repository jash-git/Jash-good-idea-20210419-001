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

  // �A��������Object Inspector��DBGrid�ݩ�Options
  // ���� dgRowSelect �M dgMultiSelect �]��true
  for(i=0; i<DBGrid1->SelectedRows->Count; i++) {

    // �N��ƪ�����Bookmark���VDBGrid�W��ܪ����@��
    DBGrid1->DataSource->DataSet->Bookmark=DBGrid1->SelectedRows->Items[i];

    // �NDBGrid�W��X����ƥ[��ListBox����
    ListBox1->Items->Add(Table1CustNo->AsString);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  ListBox1->Items->Clear();
}
//---------------------------------------------------------------------------
