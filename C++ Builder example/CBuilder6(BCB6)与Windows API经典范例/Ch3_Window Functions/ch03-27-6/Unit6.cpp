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
//调整定时器频率
Timer1->Interval = 200;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//取得Form1范围位置
RECT r;
::GetWindowRect(Handle, &r);
//取得鼠标现在位置
TPoint p;
::GetCursorPos(&p);
//检测鼠标位置是否在Form1范围中
if(::PtInRect(&r, p))
   StaticText2->Caption = "鼠标在Form1内";
else
   StaticText2->Caption = "鼠标在Form1外";
}
//---------------------------------------------------------------------------
