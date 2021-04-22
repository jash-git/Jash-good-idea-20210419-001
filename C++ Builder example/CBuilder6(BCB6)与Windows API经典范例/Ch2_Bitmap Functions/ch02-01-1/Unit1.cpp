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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//用Bitmap简化Image1图文件叙述
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;

//建立一新暂时设定，以利图文件16位转成8位时的最适化
BITMAPINFO bmi;
//将bmi结构所在内存初始化
memset(&bmi, 0, sizeof(BITMAPINFO));
//BITMAPINFO结构包含BITMAPINFOHEADER结构+RGBQUAD结构
//设置BITMAPINFOHEADER结构成员
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//结构大小
bmi.bmiHeader.biWidth = Bitmap->Width;//位图宽度
bmi.bmiHeader.biHeight = Bitmap->Height; //位图高度
bmi.bmiHeader.biPlanes = 1;//目的装置平面数，必为1
//转换成 8 位像素
bmi.bmiHeader.biBitCount = 8; // 8位像素
//设置RGBQUAD结构成员
DWORD BitMasks[3];
BitMasks[0] = 0xFFFF;//Blue明亮度
BitMasks[1] = 0xFFFF;//Green明亮度
BitMasks[2] = 0xFFFF;//Red明亮度
//将设好的RGB结构填入到RGBQUAD结构中
memcpy(bmi.bmiColors, BitMasks, sizeof(BitMasks));

unsigned char *bits;
//将BITMAPINFO结构创造一个新DIB图文件，并返回handle
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
      ::BitBlt(Canvas->Handle, 10, 10,
               Bitmap->Width, Bitmap->Height,
               Hdc, 0, 0,
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//在内存中配置一个新图文件
//在Unit1.h中加入 #include <memory>
std::auto_ptr<Graphics::TBitmap> Bitmap(new Graphics::TBitmap());
//设置长宽
Bitmap->Width = Image1->Picture->Bitmap->Width;
Bitmap->Height = Image1->Picture->Bitmap->Height;
//设置为8位图文件
Bitmap->PixelFormat = pf8bit;
//将Image1复制至此新图文件，并最适化
::BitBlt(Bitmap->Canvas->Handle, 0, 0,
         Bitmap->Width, Bitmap->Height,
         Image1->Canvas->Handle, 0, 0,
         SRCCOPY);
//再将此图文件指派回Image1
Image1->Picture->Bitmap->Assign(Bitmap.get());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//释放所有图文件
for(int i=0;i<ComponentCount;i++)
  if (Components[i]->ClassNameIs("TBitmap"))
      delete Components[i];

}
//---------------------------------------------------------------------------

