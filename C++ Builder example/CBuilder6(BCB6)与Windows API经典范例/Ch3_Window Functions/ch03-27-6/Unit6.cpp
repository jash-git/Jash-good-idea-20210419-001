//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//������ʱ��Ƶ��
Timer1->Interval = 200;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//ȡ��Form1��Χλ��
RECT r;
::GetWindowRect(Handle, &r);
//ȡ���������λ��
TPoint p;
::GetCursorPos(&p);
//������λ���Ƿ���Form1��Χ��
if(::PtInRect(&r, p))
   StaticText2->Caption = "�����Form1��";
else
   StaticText2->Caption = "�����Form1��";
}
//---------------------------------------------------------------------------
