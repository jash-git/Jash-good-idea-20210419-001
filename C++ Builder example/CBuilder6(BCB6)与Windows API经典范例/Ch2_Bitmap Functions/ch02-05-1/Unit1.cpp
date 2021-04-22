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
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//取得Form1背景可见范围
const int width = ClientWidth;
const int height = ClientHeight - StaticText1->Height;
//默认256色调色盘，指派给新图文件
RGBQUAD setcolor[256];
for(int i=0; i<256; i++)
   {
   setcolor[i].rgbBlue = (byte)i;
   setcolor[i].rgbGreen = (byte)(255-i);
   setcolor[i].rgbRed = (byte)i;
   setcolor[i].rgbReserved = 0;
   }
//将第一个色彩指定给白色，即为brush默认色彩
setcolor[0].rgbBlue = (byte) 255;
setcolor[0].rgbGreen = (byte)255;
setcolor[0].rgbRed = (byte) 255;
setcolor[0].rgbReserved = 0;

//逐一设置 BITMAPINFO 结构
BITMAPINFO BitmapInfo;
::ZeroMemory(&BitmapInfo, sizeof(BITMAPINFO));

BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
BitmapInfo.bmiHeader.biWidth = width;
BitmapInfo.bmiHeader.biHeight = -height;//从左上角绘起
BitmapInfo.bmiHeader.biPlanes = 1;
BitmapInfo.bmiHeader.biBitCount = 8;//8 位 256色
BitmapInfo.bmiHeader.biCompression = BI_RGB;//未压缩状态
//设置256色调色盘
BitmapInfo.bmiColors[256] = setcolor[256];
//指向此DIB位
BYTE *Data;
//创建一DIBSection图像
HBITMAP HBitmap =
    ::CreateDIBSection(0, &BitmapInfo, DIB_RGB_COLORS,
                       (void **)&Data, NULL, NULL);
if (HBitmap)
    {
    //计算每行需多少字节
    int BytesPerLine =
         BitmapInfo.bmiHeader.biWidth * BitmapInfo.bmiHeader.biBitCount / 8;
    //bitmap是从左上角算起
    for (int y = 0; y < height; y++)
        {
        int row = BytesPerLine * y;
        for (int x = 0; x < BytesPerLine; x++)
            {
            int bit = y;
            if(bit > 255) bit = 255-y;
            *(Data + x + row) = (BYTE) bit;
            }
        }

    //创建一与Form1兼容的内存DC
    HDC Hdc = ::CreateCompatibleDC(Canvas->Handle);
    //再将新DIBSection选入此DC中
    HBITMAP HOldBitmap = ::SelectObject(Hdc, HBitmap);

    //在这内存中再绘制一方形
    ::Rectangle(Hdc,
                40, 40,
                width-40, height-40);
    //盢癘拘砰瓜酶籹Form1
    ::BitBlt(Canvas->Handle,
             0, 0, width, height,
             Hdc, 0, 0,
             SRCCOPY);

    //将内存图形绘制至Form1上
    ::SelectObject(Hdc, HOldBitmap);
    ::DeleteObject(HBitmap);
    }
}
//---------------------------------------------------------------------------
//还原&释放HDC
void __fastcall TForm1::FormResize(TObject *Sender)
{
Repaint();    
}
//---------------------------------------------------------------------------

