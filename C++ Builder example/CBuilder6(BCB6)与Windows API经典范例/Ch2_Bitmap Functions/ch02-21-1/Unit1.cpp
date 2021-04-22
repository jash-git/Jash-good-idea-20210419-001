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
//默认Image1为24位及各项属性
Image1->Picture->Bitmap->PixelFormat = pf24bit;
Image1->Picture->Bitmap->Width = 100;
Image1->Picture->Bitmap->Height = 30;
Image1->Align = alClient;
Image1->Stretch = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

const int width = Image1->Picture->Bitmap->Width,
          height = Image1->Picture->Bitmap->Height;
//在内存中创造一COLORREF结构缓冲区块
//设置此一COLORREF数组为24位色彩
std::auto_ptr<COLORREF> clrrf(new COLORREF[width * height * 3]);
//取得此内存区块位置指针
COLORREF *pclrrf = clrrf.get();
int x=100;
//将此COLORREF数组填入RGB随机数
for (int index = 0; index < width * height * 3; index++)
   {
   if((index%20)==0)
      x = 255-random(155);
   pclrrf[index] = RGB(x, x-20,x-80);
   }
//进行自定义函数
DrawDIBuffer(Image1->Canvas->Handle,
             0, 0,
             width, height,
             pclrrf,
             width, height);
//将Image1更新
Image1->Refresh();
}
//---------------------------------------------------------------------------
//进行自定义函数
void TForm1::DrawDIBuffer(HDC HTargetDC, int X, int Y, int dst_width,
    int dst_height, COLORREF *clrrf, int src_width, int src_height)
{
//(1)在内存中配置一BITMAPINFO结构区块
std::auto_ptr<BITMAPINFO> pbmi(new BITMAPINFO());
//(2)设置此BITMAPINFO结构成员
pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
pbmi->bmiHeader.biWidth = src_width;
pbmi->bmiHeader.biHeight = src_height;
pbmi->bmiHeader.biPlanes = 1;
pbmi->bmiHeader.biBitCount = 24;
pbmi->bmiHeader.biCompression = BI_RGB;
//此结构设为24位图文件，故计算取得总字节
pbmi->bmiHeader.biSizeImage =
     ((((src_width * pbmi->bmiHeader.biBitCount) +
     31) & ~31) / 8) * src_height;
//(3)在内存中分配可容纳Image1实际大小的缓冲区，
//char与BYTE皆为 8-bits，
std::auto_ptr<unsigned char> pbits
     (new unsigned char[pbmi->bmiHeader.biSizeImage]);
//(4)复制COLORREF数组至pbits数组中
int pos = 0;
int index = 0;
for (int y = 0; y < src_height; y++)
  {
  for (int x = 0; x < src_width; x++)
    {
    //分别填入构成每个位图的RGB值
    pbits.get()[pos] = GetBValue(clrrf[index]);
    pbits.get()[pos + 1] = GetGValue(clrrf[index]);
    pbits.get()[pos + 2] = GetRValue(clrrf[index]);
    pos += 3;
    index += 2;
    }
  }

//(5)将内存中pbmi图文件绘制至Image1的DC handle
::StretchDIBits(HTargetDC,
                X, Y,
                dst_width, dst_height,
                0, 0,
                src_width, src_height,
                pbits.get(),
                pbmi.get(),
                DIB_RGB_COLORS,
                SRCCOPY);
}
//---------------------------------------------------------------------------

