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
{//先隐藏Image1图像，以免干扰显示成果
Image1->Hide();
Tag = 0;//将闲置属性，作为递增变量
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{//取得Form1的DC handle
HDC hdc = Canvas->Handle;
int setMode;
switch(Tag%4)
   {
   case 0: setMode = BLACKONWHITE; break;
   case 1: setMode = WHITEONBLACK; break;
   case 2: setMode = HALFTONE; break;
   case 3: setMode = COLORONCOLOR; break;
   }
//重设置图像伸展时模式
::SetStretchBltMode(hdc, setMode);
Tag++; //递增变数
//设置笔刷在SetStretchBltMode起始&范围，
::SetBrushOrgEx(hdc, 0, 0, NULL);
//建议在内存中融合Form1与Image1的HDC <CreateCompatibleDC>，
//再显示于Form1背景上，将更形显现各色调之相异处
//将Image1缩放至Form1背景
::StretchBlt(hdc,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Image1->Canvas->Handle, 0, 0,
             Image1->Picture->Bitmap->Width,
             Image1->Picture->Bitmap->Height,
             SRCCOPY);
//取得图像伸展时色调模式
int mode = ::GetStretchBltMode(hdc);
//并在标题列上显示Form1所处的色调模式
switch(mode)
   {
   case BLACKONWHITE: Caption = "黑白模式(AND)"; break;
   case WHITEONBLACK: Caption = "黑白模式(OR)"; break;
   case HALFTONE: Caption = "半色调模式"; break;
   case COLORONCOLOR: Caption = "去除所有位图条纹模式"; break;
   }
}
//---------------------------------------------------------------------------



