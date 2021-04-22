//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit21_8.h"
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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  ComboBox1->ItemIndex=BarSeries1->BarStyle;
  DBChart1->Legend->Visible=False;

  Query1->RequestLive=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  Screen->Cursor=crHourGlass;
  Query1->Close();
  BarSeries1->XLabelsSource="";
  BarSeries1->YValues->ValueSource="";

  Query1->SQL=Memo1->Lines;
  Query1->Open();

  BarSeries1->DataSource=Query1;

  BarSeries1->XLabelsSource=Query1->Fields->Fields[0]->FieldName;
  BarSeries1->YValues->ValueSource=Query1->Fields->Fields[1]->FieldName;
  Screen->Cursor=crDefault;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
  BarSeries1->BarStyle=TBarStyle(ComboBox1->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
