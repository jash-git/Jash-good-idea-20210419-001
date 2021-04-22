//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit21_6.h"
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

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
  switch(RadioGroup1->ItemIndex) {
    case 0: PieSeries1->PieValues->ValueSource="Size";
    case 1: PieSeries1->PieValues->ValueSource="Weight";
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  Close();    
}
//---------------------------------------------------------------------------
