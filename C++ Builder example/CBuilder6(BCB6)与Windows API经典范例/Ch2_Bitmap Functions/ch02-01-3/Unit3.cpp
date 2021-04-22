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
//隐藏Image1
Image1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
//用Bitmap简化Image1图文件语句
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;

//建立一新暂时设置，以利图文件16位转成8位时的最适化
BITMAPINFO bmi;
//将bmi结构所在内存初始化
memset(&bmi, 0, sizeof(BITMAPINFO));
//BITMAPINFO结构包含BITMAPINFOHEADER结构+RGBQUAD结构
//设置BITMAPINFOHEADER结构成员
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//结构大小
bmi.bmiHeader.biWidth = Bitmap->Width;//位图宽度
bmi.bmiHeader.biHeight = Bitmap->Height; //位图高度
bmi.bmiHeader.biPlanes = 1;//目的装置平面数，必为1
//转换成 16 位像素
bmi.bmiHeader.biBitCount = 16; //  16位像素
//设置RGBQUAD结构成员
DWORD BitMasks[3];
BitMasks[0] = 0xFFFF;//Blue明亮度
BitMasks[1] = 0xFFFF;//Green明亮度
BitMasks[2] = 0xFFFF;//Red明亮度
//将设好的RGB结构填入RGBQUAD结构
memcpy(bmi.bmiColors, BitMasks, sizeof(BitMasks));

unsigned char *bits;
//将BITMAPINFO结构创造一新DIB图文件，并返回handle
HBITMAP HBmp = ::CreateDIBSection(0, &bmi, DIB_RGB_COLORS,
                                  reinterpret_cast<void **>(&bits),
                                  NULL, NULL);

if (HBmp)
    {
    //建立与指定DC兼容的DC
    HDC Hdc = ::CreateCompatibleDC(0);
    //选定新对象，并返回原有对象设置
    HBITMAP HOldBmp = ::SelectObject(Hdc, HBmp);
    try
      {
      //先由Image复制图像至暂时设备
      ::BitBlt(Hdc, 0, 0,
               Bitmap->Width, Bitmap->Height,
               Bitmap->Canvas->Handle, 0, 0,
               SRCCOPY);
      //再由暂时设备复制图像至Form1上
      int h = (ClientHeight/Bitmap->Height)+1;
      int w = (ClientWidth/Bitmap->Width)+1;
      for (int y = 0; y < h; y++)
          for (int x = 0; x < w; x++)
              ::BitBlt(Canvas->Handle,
                       Bitmap->Width*x,
                       Bitmap->Height*y,
                       Bitmap->Width, Bitmap->Height,
                       Hdc,
                       0, 0,
                       SRCCOPY);

      }

    catch (...)
      {
      //先恢复原设置，再释放对象
      ::DeleteObject(::SelectObject(Hdc, HOldBmp));
      //释放DC
      ::DeleteDC(Hdc);
      }
    //先恢复原设置，再释放对象
    ::DeleteObject(::SelectObject(Hdc, HOldBmp));
    //释放DC
    ::DeleteDC(Hdc);
    }
}
//---------------------------------------------------------------------------

