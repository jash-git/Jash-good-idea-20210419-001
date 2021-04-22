//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//将Image1隐藏并当作来源图像
Image1->Hide();
//创建一图像，作为转换成果
image2 = new TImage(this);
image2->Parent = Form1;
image2->Picture->Bitmap->Assign(Image1->Picture->Bitmap);
image2->Stretch = true;
image2->Align = alClient;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//关闭程序前，释放image2所占住内存
delete image2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//自定义函数--转换图文件色彩
BitmapCover(Image1->Picture->Bitmap,ComboBox1->Text.ToInt());
}
//---------------------------------------------------------------------------
//自定义函数--转换图文件色彩
void __fastcall TForm1::BitmapCover(Graphics::TBitmap *Bitmap,int bpp)
{
const int AWidth = Bitmap->Width;
const int AHeight = Bitmap->Height;
//图像结构声明，并清理此内存
BITMAPINFO bmi;
::ZeroMemory(&bmi, sizeof(BITMAPINFO));

//设置BITMAPINFO(HEADER)结构成员
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
bmi.bmiHeader.biWidth = AWidth;
bmi.bmiHeader.biHeight = -AHeight;
bmi.bmiHeader.biPlanes = 1;
//由用户设置此图像位数
bmi.bmiHeader.biBitCount = (WORD)bpp;
bmi.bmiHeader.biCompression = BI_RGB;

//若为8位以下图像，则自行指定设置前三代替色
//图像经由BitBlt函数，取代最接近色彩
RGBQUAD rgb1 = {50, 50, 50, 0};///深灰色
RGBQUAD rgb2 = {235, 235, 235, 0};//浅灰色
RGBQUAD rgb3 = {255, 230, 140, 0};//铭黄色
bmi.bmiColors[0] = rgb1;
bmi.bmiColors[1] = rgb2;
bmi.bmiColors[2] = rgb3;

//在内存中创建一图像，返回handle与此图像区块指针
unsigned char *mapbits;
HBITMAP HBmp =
        ::CreateDIBSection(0, &bmi, DIB_RGB_COLORS,
                   reinterpret_cast<void **>(&mapbits),
                   NULL, NULL);

if (HBmp)
   {
   //与GDI同步执行
   ::GdiFlush();
   //在内存中创建一兼容DC handle
   HDC Hdc = ::CreateCompatibleDC(0);
   //先将设置好的新图像DC handle传入此兼容DC handle中
   HBITMAP HOldBitmap = ::SelectObject(Hdc, HBmp);
   //再将Image1 DC handle传入，作最适化结合转换
   ::BitBlt(Hdc, 0, 0,
            AWidth, AHeight,
            Bitmap->Canvas->Handle,
            0, 0,
            SRCCOPY);
   //回复兼容DC原有结构设置
   ::SelectObject(Hdc, HOldBitmap);
   //释放此相容DC
   ::DeleteDC(Hdc);
   //将最适化结果返回image2
   image2->Picture->Bitmap->Handle = HBmp;
   }
}
//---------------------------------------------------------------------------




