//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit19_1.h"
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
  XMLDocument1->Active=False;
  XMLDocument1->XML->Text="";
  XMLDocument1->Active=True;

  _di_IXMLNode NewStock = XMLDocument1->AddChild(WideString("stock"));
  NewStock->Attributes[WideString("exchange")] = "NASDAQ";
  _di_IXMLNode ValueNode = NewStock->AddChild(WideString("name"));
  ValueNode->Text = WideString("Cisco Systems");
  ValueNode = NewStock->AddChild(WideString("price"));
  ValueNode->Text = WideString("62.375");
  ValueNode = NewStock->AddChild(WideString("symbol"));
  ValueNode->Text = WideString("CSCO");
  ValueNode = NewStock->AddChild(WideString("shares"));
  ValueNode->Text = WideString("25");
  Memo1->Lines->Text=FormatXMLData(XMLDocument1->XML->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  try
  {
    XMLDocument1->SaveToFile("xml1.xml");
    ShowMessage("保存成功!");
  }
  catch ( ... )
  {
    ShowMessage("保存失败!");
  }
}
//---------------------------------------------------------------------------


