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
//取得Image1的 handle
HBITMAP Hbmp = Image1->Picture->Bitmap->Handle;
//设置BITMAP结构成员
BITMAP bmp;
//由Image1复制至BITMAP结构相关设置
::GetObject(Hbmp, sizeof(BITMAP), &bmp);
//取消每个位图的指定色彩
bmp.bmBits = NULL;
//字节数目必为 4 的倍数，每个位图字节*宽度/4
//bmp.bmWidthBytes = (bmp.bmWidth/4)*4;
bmp.bmBitsPixel = 16; //16位色彩深度位图

//依据bmp结构建立一新图文件，并取得handle
HBITMAP HBitmap = ::CreateBitmapIndirect(&bmp);
//建立一与特定DC兼容的内存DC handle
HDC HMemoryDC = ::CreateCompatibleDC(0);
//将bmp对象选取至兼容内存DC，
HBITMAP HOldBitmap = ::SelectObject(HMemoryDC, HBitmap);
//并取得Form1的DC handle
HDC hDC = ::GetDC(Form1->Handle);
//将内存的新图文件复制至Form1上
::BitBlt(hDC, 10, 40,
         bmp.bmWidth, bmp.bmHeight,
         HMemoryDC,
         0, 0,
         SRCCOPY);

//逐一释放、还原对象& DC handle
::ReleaseDC(Form1->Handle, hDC);
::SelectObject(HMemoryDC, HOldBitmap);
::DeleteDC(HMemoryDC);
::DeleteObject(HBitmap);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//设置BITMAP结构成员
BITMAP bmp;
bmp.bmType = 0;//必须为0
bmp.bmWidth =120;//位图宽度
bmp.bmHeight = 52;//位图高度
bmp.bmPlanes = 1;//设备级数，应为1
//将位数组填入递增的十六进制数值
static BYTE bit[12000];
BYTE b = 0x00;
for(int a=0;a<12000;a++)
   bit[a] = BYTE(b+(a/60));
bmp.bmBits = &bit;//指定位图色彩
//字节数目必为 4 的倍数，每个位图字节*宽度/4
bmp.bmWidthBytes = (bmp.bmWidth/4)*4;//字节宽度
bmp.bmBitsPixel =16; //16位色彩深度位图

//依据bmp结构建立一新图文件，并取得handle
HBITMAP HBitmap = ::CreateBitmapIndirect(&bmp);
//建立一与特定DC兼容的内存DC handle
HDC HMemoryDC = ::CreateCompatibleDC(0);
//将bmp对象选取至兼容内存DC，
HBITMAP HOldBitmap = ::SelectObject(HMemoryDC, HBitmap);
//并取得Form1的DC handle
HDC hDC = ::GetDC(Form1->Handle);
//将内存的新图文件复制至Form1上
::BitBlt(hDC, 20+bmp.bmWidth, 40,
         bmp.bmWidth, bmp.bmHeight,
         HMemoryDC,
         0, 0,
         SRCCOPY);

//逐一释放、还原对象& DC handle
::ReleaseDC(Form1->Handle, hDC);
::SelectObject(HMemoryDC, HOldBitmap);
::DeleteDC(HMemoryDC);
::DeleteObject(HBitmap);
}
//---------------------------------------------------------------------------


