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
{//重设置Image2图文件位图数目
Image2->Picture->Bitmap->Width = 20;
Image2->Picture->Bitmap->Height = 70;
//设置Image2图文件位置与范围
Image2->Align = alRight;
Image2->Width = ClientWidth/3;
//设置Image1与Image2图文件皆为延展状态，
//以利观察函数执行效果
Image2->Stretch = true;
Image1->Stretch = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//适度的简化程序代码
Graphics::TBitmap* bmp1 = Image1->Picture->Bitmap;
Graphics::TBitmap* bmp2 = Image2->Picture->Bitmap;
//将Image1图文件的色彩信息，由Image2图文件显示出来
::SetBitmapBits(bmp2->Handle,
                bmp1->Width * bmp1->Height,
                Image1);
//指派后，更新Image2
Image2->Refresh();
}
//---------------------------------------------------------------------------
