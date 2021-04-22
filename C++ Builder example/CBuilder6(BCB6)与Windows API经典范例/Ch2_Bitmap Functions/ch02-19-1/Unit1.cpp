//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//先隐藏Image1图像
Image1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//取得Form1的DC handle
HDC Hdc = Canvas->Handle;
//设置图像伸展时模式，HALFTONE较慢但影像品质较佳
::SetStretchBltMode(Hdc, HALFTONE);
//设置笔刷在SetStretchBltMode起始&范围
::SetBrushOrgEx(Hdc, 0, 0, NULL);
//将Image1缩放至Form1背景
::StretchBlt(Hdc,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Image1->Canvas->Handle, 0, 0,
             Image1->Picture->Bitmap->Width,
             Image1->Picture->Bitmap->Height,
             SRCCOPY);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
//若变动Form1大小时，进行重绘动作
Form1->Repaint();
}
//---------------------------------------------------------------------------



