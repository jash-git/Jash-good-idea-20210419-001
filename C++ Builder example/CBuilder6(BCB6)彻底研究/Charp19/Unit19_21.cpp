//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit19_21.h"
#include "Unit19_22.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
_di_IXMLstockType test;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  XMLDocument1->LoadFromFile("xml1.xml");
  XMLDocument1->Active=True;
  test=Getstock(XMLDocument1);
  Memo1->Lines->Text=FormatXMLData(XMLDocument1->XML->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  test->Set_name(Edit1->Text);
  Memo1->Lines->Text=FormatXMLData(XMLDocument1->XML->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  test->Set_price(Edit2->Text);
  Memo1->Lines->Text=FormatXMLData(XMLDocument1->XML->Text);
}
//---------------------------------------------------------------------------

