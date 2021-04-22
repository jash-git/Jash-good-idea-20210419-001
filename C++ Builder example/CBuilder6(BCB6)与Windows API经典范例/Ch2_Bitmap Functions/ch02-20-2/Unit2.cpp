//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//小图标应有显示图像及屏蔽图像 2 个成员
Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
Graphics::TBitmap *BitmapMask = new Graphics::TBitmap();
//图示为 16x16 位图
Bitmap->Width = 16;
Bitmap->Height = 16;
BitmapMask->Width = 16;
BitmapMask->Height = 16;
//将Image1缩小&复制至Bitmap显示图像
::StretchBlt(Bitmap->Canvas->Handle,
             0, 0,
             Bitmap->Width, Bitmap->Height,
             Image1->Picture->Bitmap->Canvas->Handle,
             0, 0,
             Image1->Picture->Bitmap->Width,
             Image1->Picture->Bitmap->Height,
             SRCCOPY);
//将屏蔽图像设为全黑，即为全透明状态
BitmapMask->Canvas->Brush->Color = clBlack;
BitmapMask->Canvas->FillRect(BitmapMask->Canvas->ClipRect);
//ICONINFO结构声明
ICONINFO icf;
icf.fIcon = true;
//屏蔽图像与显示图像进行AND运算
icf.hbmMask = BitmapMask->Handle;
icf.hbmColor = Bitmap->Handle;
//依照ICONINFO结构创造一新图标
HICON HIcon = ::CreateIconIndirect(&icf);
//将此新图示指定给Form1使用
Application->Icon->Handle = HIcon;
Icon->Handle = HIcon;
//删除显示图像与屏蔽图像
delete Bitmap;
delete BitmapMask;
}
//---------------------------------------------------------------------------
