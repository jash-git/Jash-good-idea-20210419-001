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
Button1->Tag = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//先设置整理Image1图像
Image1->Picture = NULL;
Image1->Align = alNone;
Image1->Stretch = false;
//保存捕捉影像的暂时图像
Graphics::TBitmap *tempBmp = new Graphics::TBitmap();
HDC hdc = NULL;
//捕捉范围的长宽
int x, y;
if(Button1->Tag)
   {//取得全屏幕的DC handle
   hdc = ::GetDC(0);
   x = Screen->Width;
   y = Screen->Height;
   Button1->Tag = false;
   }
else
   {//取得Form1的DC handle
   hdc = ::GetWindowDC(Handle);
   x = Form1->Width;
   y = Form1->Height;
   Button1->Tag = true;
   }
//创建一兼容于装置的新图文件，并指派给tmpBmp handle
tempBmp->Handle = ::CreateCompatibleBitmap( hdc, x, y);
//将hdc获取到的内容复制至tempBmp中
::BitBlt(tempBmp->Canvas->Handle, 0, 0,
         tempBmp->Width, tempBmp->Height,
         hdc, 0, 0, SRCCOPY);
//将tempBmp传给Image1中
Image1->Picture->Bitmap = tempBmp;
//删除暂时的tempBmp
delete tempBmp;
//将Image1充满Form1中间
Image1->Align = alClient;
Image1->Stretch = true;
}
//---------------------------------------------------------------------------
