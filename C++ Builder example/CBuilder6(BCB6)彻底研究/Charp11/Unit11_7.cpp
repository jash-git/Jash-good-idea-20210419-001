#include <vcl.h>
#pragma hdrstop

#include "Unit11_7.h"
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
// 这二个函数是用来显示目前应用程序服务器
// 一共有多少用户上线，以及执行了多少查询

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


