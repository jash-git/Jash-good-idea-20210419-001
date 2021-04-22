#include <vcl.h>
#pragma hdrstop

#include "Unit11_5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}

void __fastcall TForm1::UpdateClientCount(int Incr)
{
  FClientCount += Incr;
  ClientCount->Caption = IntToStr(FClientCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::IncQueryCount(void)
{
  FQueryCount++;
  QueryCount->Caption = IntToStr(FQueryCount);
}


