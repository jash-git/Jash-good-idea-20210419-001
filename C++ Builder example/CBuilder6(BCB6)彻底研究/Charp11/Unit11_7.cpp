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
// �����������������ʾĿǰӦ�ó��������
// һ���ж����û����ߣ��Լ�ִ���˶��ٲ�ѯ

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


