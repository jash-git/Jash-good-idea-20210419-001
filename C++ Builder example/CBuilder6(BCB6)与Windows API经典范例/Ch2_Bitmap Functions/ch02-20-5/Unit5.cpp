//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//用Bitmap代理Image1，
//程序撰写时，较易阅读连贯
Bitmap = Image1->Picture->Bitmap;
//隐藏Image1
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
//将其它信息分流出去
TForm::Dispatch(&Msg);
//取得系统中标题高度
int CaptionHeight = ::GetSystemMetrics(SM_CYCAPTION);
//取得Form1的DC handle
HDC HWindowDC = ::GetWindowDC(Handle);
//将图像依照Form1标题长宽，变形+变色绘制至Form1标题上
::StretchBlt(HWindowDC,
             4, 2,
             Width-62, CaptionHeight+2,
             Bitmap->Canvas->Handle,
             0, 0,
             Bitmap->Width, Bitmap->Height,
             NOTSRCCOPY);
//将图像依照Form1范围长宽，变形绘制至Form1背景中
::StretchBlt(Canvas->Handle,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Bitmap->Canvas->Handle,
             0, 0,
             Bitmap->Width,
             Bitmap->Height,
             SRCCOPY);
//没使用信息中Result值
Msg.Result = 0;
//释放系统DC的handle
::ReleaseDC(Handle, HWindowDC);
}
//---------------------------------------------------------------------------

