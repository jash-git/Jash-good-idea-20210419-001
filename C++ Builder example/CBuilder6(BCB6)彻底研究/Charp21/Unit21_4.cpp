//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit21_4.h"
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

  Table1->Open();

  for (i=0; i<10; i++) {

    Series1->Add( Table1Salary->AsInteger,
                  Table1LastName->AsString,
                  clBlue );
    Table1->Next();
  }
  Table1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Chart1->Print();
  ShowMessage("��ӡ���!!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Chart1->Title->Text->Strings[0]="Ա������ͳ��ͼ��";
  Chart1->LeftAxis->Title->Caption="Ա������";
  Chart1->BottomAxis->Title->Caption="Ա������";
}
//---------------------------------------------------------------------------

