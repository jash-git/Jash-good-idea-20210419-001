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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//建立一暂时图文件
Graphics::TBitmap *Bitmap=new Graphics::TBitmap;
//设置这暂时图文件属性
Bitmap->Width=Screen->Width;
Bitmap->Height=Screen->Height;
Bitmap->PixelFormat=pf16bit;

//取得桌面的DC handle
HDC NewDC=::GetWindowDC(0);

//将全屏幕复制到Bitmap上
::BitBlt(Bitmap->Canvas->Handle,0,0,
         Screen->Width,Screen->Height,
         NewDC,0,0,SRCCOPY);
//让user决定结果
char *str = "YES按钮=显示在Form1上，\nNO按钮=存成文件C:\\NewBitmap.BMP，\nCANCEL按钮=Do Nothing!";
int re = ::MessageBox(Handle, str, "存档or显示",MB_YESNOCANCEL);
switch(re)
   {
   case IDYES:
        Image1->Picture->Assign(Bitmap);
        break;
   case IDNO:
        Bitmap->SaveToFile("C:\\NewBitmap.BMP");
        break;
   case IDCANCEL:
        break;
   }

//释放DC
ReleaseDC(Form1->Handle,NewDC);
//删除Bitmap
delete Bitmap;
}
//---------------------------------------------------------------------------

