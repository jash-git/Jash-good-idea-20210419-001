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
//删除Memo1中所有文字
Memo1->Clear();
//用Bitmap简化Image1图文件语句
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;

//取得指定文件的完整路径
char cdir[MAX_PATH];
char *bfile = "//BIT-8-256.bmp";
//将程序现在目录所在填入此字符数组
::GetCurrentDirectory( MAX_PATH, cdir);
//将现在目录加上指定文件名
strcat( cdir, bfile);
//声明图文件结构
BITMAPFILEHEADER bmfh;
BITMAPINFOHEADER bmih;
//打开指定文件
HANDLE HFile = ::CreateFile(cdir, GENERIC_READ,
                            0, NULL,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, NULL);
//
if (HFile != INVALID_HANDLE_VALUE)
   {
   DWORD dwRead;
   //取得图文件结构的相关数据
   ::ReadFile(HFile, &bmfh, sizeof(BITMAPFILEHEADER), &dwRead, NULL);
   ::ReadFile(HFile, &bmih, sizeof(BITMAPINFOHEADER), &dwRead, NULL);
   //建立一新暂时设置，以利图文件16位转成8位时的最大化
   BITMAPINFO bmi;
   //将bmi结构所在内存初始化﹍て
   memset(&bmi, 0, sizeof(BITMAPINFO));
   //BITMAPINFO结构包含BITMAPINFOHEADER结构+RGBQUAD结构
   //设置BITMAPINFOHEADER结构成员
   bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//结构大小
   bmi.bmiHeader.biWidth = Bitmap->Width;//图素宽度
   bmi.bmiHeader.biHeight = Bitmap->Height; //图素高度
   bmi.bmiHeader.biPlanes = 1;//目的装置平面数，必为1
   //转换成 16 位像素
   bmi.bmiHeader.biBitCount = 16; //16位像素
   bmi.bmiHeader = bmih;

//设置RGBQUAD结构成员
DWORD BitMasks[3];
BitMasks[0] = 0xFFFF;//Blue明亮度
BitMasks[1] = 0xFFFF;//Green明亮度
BitMasks[2] = 0xFFFF;//Red明亮度
//将设好的RGB结构填入RGBQUAD结构
memcpy(bmi.bmiColors, BitMasks, sizeof(BitMasks));
unsigned char *bits;
//将BITMAPINFO结构创造一新DIB图文件，并返回handle
//建立与指定DC兼容的DC
HDC Hdc = ::CreateCompatibleDC(0);
//将BITMAPINFO结构创造一新DIB图文件，并返回handle
HBITMAP HBmp = ::CreateDIBitmap(Hdc, &bmih, CBM_INIT,
                                (BYTE *)sizeof(bmi) + bmi.bmiHeader.biSize,
                                &bmi,
                                DIB_RGB_COLORS);

   //建立与指定DC兼容的DC
//   HDC Hdc = ::CreateCompatibleDC(0);
   //此处依照读入图文件的结构，绘出图像至Form1的Image1中
   HDC hdc = ::GetDC(Image1->Canvas->Handle);
    //选定新对象，并返回原有对象设置
//    HBITMAP HOldBmp = ::SelectObject(Hdc, hdc);
if (HBmp)
    {
   //先由Image复制图像至暂时设备
   ::BitBlt(hdc, 0, 0,
            bmih.biWidth, bmih.biHeight,//Image1->Width*5, Image1->Height*5,//
            Hdc, 0, 0,
            SRCCOPY);

   Memo1->Lines->Add("成功读取图文件！");
   }
   }
else
   Memo1->Lines->Add("读取图文件失败！");
//释放handle
::CloseHandle(HFile);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//删除Memo1中所有文字
Memo1->Clear();
//预先告知相关信息
Memo1->Lines->Add("请先在程序同一目录下制作一aaa.txt文本文件！");

char buf[MAX_PATH];
DWORD bytesread;

char dir[MAX_PATH];
char *tfile = "/aaa.txt";
//将程序现在目录所在填入此字符数组
::GetCurrentDirectory( MAX_PATH, dir);
//将现在目录加上指定文件名
strcat( dir, tfile);
//打开文本文件
HANDLE hFile = ::CreateFile(dir, GENERIC_READ,
                            FILE_SHARE_READ | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_SEQUENTIAL_SCAN, NULL);

//读取指定文件字符数组，并存于buf中
if(::ReadFile(hFile, buf, sizeof(buf), &bytesread, NULL))
   {
   Memo1->Lines->Add(buf);
   Memo1->Lines->Add("成功读取文本文件！");
   }
else
   Memo1->Lines->Add("读取文本文件失败！");
//释放handle
::CloseHandle(hFile);
}
//---------------------------------------------------------------------------





