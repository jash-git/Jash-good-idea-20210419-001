//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//先隐藏Image1
Image1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
//将Form1长宽范围列为失效范围，
//即引发WM_ERASEBKGND信息，而进行重绘
::InvalidateRect(Handle, NULL, true);
}
//---------------------------------------------------------------------------
//WM_ERASEBKGND信息
void __fastcall TForm1::WMEraseBkgnd(TMessage &Msg)
{
//将图像依照Form1长宽，变形绘制
::StretchBlt(Canvas->Handle,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Image1->Canvas->Handle, 0, 0,
             Image1->Width,
             Image1->Height, SRCCOPY);
Msg.Result = 0;
}
