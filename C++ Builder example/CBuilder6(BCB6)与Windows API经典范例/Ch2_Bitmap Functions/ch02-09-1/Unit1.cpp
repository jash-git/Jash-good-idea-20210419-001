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
//程序进行时，停止按钮再按
Button1->Enabled = false;
for( int i=0; i<256; i++ )
   {
   //先中断执行循环，看看有何插入事件需执行
   Application -> ProcessMessages ();
   //进行自定义之整合主函数
   ColorChangeLoop ();
   }
//程序结束时，恢复按钮功能
Button1->Enabled = true;
}
//---------------------------------------------------------------------------
//自定义之整合主函数
void __fastcall TForm1::ColorChangeLoop ()
{
//
int InfoHeaderSize;
int ImageSize = 0;
//取得图文件结构大小--InfoHeaderSize
//取得图文件字节大小--ImageSize
MyGetDIBSizes ( Image1->Picture->Bitmap->Handle,
                InfoHeaderSize, ImageSize);
//依照图文件结构&位图，分别配置容纳之char数组
void *BitmapInfo = new char [ InfoHeaderSize ];
unsigned long *Bits = new unsigned long [ ImageSize / 4 ];
//自定义函数--取得&复制DIB图形数据至内存区块中
MyGetDIB( Image1->Picture->Bitmap->Handle,
          BitmapInfo, Bits );
//逐一将每个位图重设色值
for ( int i = 0; i < ImageSize / 4; i ++ )
   {
   long Res = Bits [ i ];
   BYTE R = (byte)(GetRValue( Res ) + 10);
   BYTE G = (byte)(GetGValue( Res ) + 10);
   BYTE B = (byte)(GetBValue( Res ) + 10);
   Bits [ i ] = RGB ( R, G, B );

   if ( Application -> Terminated )
      return;
   }
//自定义函数--设置在内存区块中DIB图像数据，再给予Image1
MySetDIB ( Image1->Picture->Bitmap->Handle,
           BitmapInfo, Bits );
//更新重绘Image1
Image1->Repaint();
//释放内存中结构之数组
delete BitmapInfo;
delete Bits;
}
//---------------------------------------------------------------------------
//取得图文件结构大小--InfoHeaderSize
//取得图文件字节大小--ImageSize
void __fastcall TForm1::MyGetDIBSizes ( HBITMAP Bitmap, int &InfoHeaderSize,
                                        int &ImageSize )
{
//默认为32位图像
int Colors = 1000;
//BITMAPINFOHEADER结构声明
TBitmapInfoHeader BI;
//自定义函数--BITMAPINFO初始化
InitializeBitmapInfoHeader ( Bitmap, BI, Colors );
//若为8位以上图像
if ( BI.biBitCount > 8 )
   {
   InfoHeaderSize = sizeof ( TBitmapInfoHeader );
   //若图像未压缩&每一位图由RGB doubleword组成，
   //则多加12
   if ((BI.biCompression & BI_BITFIELDS ) != 0 )
      InfoHeaderSize += 12;
   }
else//图像数据数+色彩数组数
   InfoHeaderSize = sizeof (TBitmapInfoHeader) +
                    sizeof (TRGBQuad) * (1<<BI.biBitCount);
//图文件字节大小
ImageSize = BI.biSizeImage;
}
//---------------------------------------------------------------------------
//取得&复制DIB图形数据至内存区块中
bool __fastcall TForm1::MyGetDIB(HBITMAP Bitmap, void *BitmapInfo,
                                 void *Bits )
{
//BITMAPINFO初始化--自定义函数
InitializeBitmapInfoHeader (Bitmap,
                            *(( TBitmapInfoHeader *) BitmapInfo),
                            1000 );
//在内存中创建一兼容DC handle
HDC DC = ::CreateCompatibleDC(0);
bool Result = false;
try
  {
  //取得&复制DIB图形数据至内存区块中
  Result = ::GetDIBits(DC, Bitmap, 0,
                       (( TBitmapInfoHeader *) BitmapInfo)->biHeight,
                       Bits,
                       (( TBitmapInfo *) BitmapInfo ),
                       DIB_RGB_COLORS) != 0;
  }
catch (...) {}
//释放内存中兼容DC handle
DeleteDC(DC);
return Result;
}
//---------------------------------------------------------------------------
//设置在内存区块中DIB图像数据，再给予Image1
bool __fastcall TForm1::MySetDIB(HBITMAP Bitmap, void *BitmapInfo,
                                 void *Bits )
{
//BITMAPINFO初始化--自定义函数
InitializeBitmapInfoHeader ( Bitmap,
                             *(( TBitmapInfoHeader *) BitmapInfo),
                             1000 );
//在内存中创建一兼容DC handle
HDC DC = CreateCompatibleDC(0);
bool Result = false;
try
  {
  //设置在内存区块中DIB图像数据，再给予Image1
  Result = ::SetDIBits ( DC, Bitmap, 0,
                        (( TBitmapInfoHeader *) BitmapInfo)->biHeight,
                        Bits,
                        (( TBitmapInfo *) BitmapInfo ),
                        DIB_RGB_COLORS) != 0;
  }
catch (...) {}
//释放内存中兼容DC handle
DeleteDC(DC);

return Result;
}
//---------------------------------------------------------------------------
//MyGetDIBSizes & MyGetDIB & MySetDIB副函数--BITMAPINFO初始化
void __fastcall TForm1::InitializeBitmapInfoHeader ( HBITMAP Bitmap,
                             BITMAPINFOHEADER &BI, int Colors )
{
//等同DIBSECTION结构声明
TDIBSection DS;
int Bytes;
//将BITMAPINFOHEADER大小归零
DS.dsBmih.biSize = 0;
//返回Bitmap的字节数量
Bytes = ::GetObject(Bitmap, sizeof ( DS ), &DS);
//若无法取得Bitmap字节数，那就丢给未知图像之例外类别处理
if ( Bytes == 0 )
    throw new EInvalidGraphic ( "无效的图文件！" );
//若字节Bytes非常态的超过大小、则指定默认大小
else if (( Bytes >= (sizeof(DS.dsBm) + sizeof(DS.dsBmih))) &&
         (DS.dsBmih.biSize >= sizeof(DS.dsBmih)) )
    BI = DS.dsBmih;
else
    {
    //将BI内存区块皆填上0
    memset ( &BI, sizeof(BI), 0 );
    //重新设置BI结构成员
    BI.biSize = sizeof ( BI );
    BI.biWidth = DS.dsBm.bmWidth;
    BI.biHeight = DS.dsBm.bmHeight;
    }
//由色彩决定位数据
if ( Colors != 0 )
    {
    switch ( Colors )
      {
      case 2:
        BI.biBitCount = 1; break;
      case 16:
        BI.biBitCount = 4; break;
      case 256:
        BI.biBitCount = 8; break;
      case 1000:
        BI.biBitCount = 32; break;
      }
    }
else//若否，则由位图计算
    BI.biBitCount = (WORD)(DS.dsBm.bmBitsPixel * DS.dsBm.bmPlanes);

BI.biPlanes = 1;
BI.biSizeImage = 0;
BI.biClrUsed = 0;
BI.biClrImportant = 0;
//若尚未计算影像数据实际大小(字节)
if ( BI.biSizeImage == 0 )
    //自定义函数--取得图像一列的字节乘以图像高度
    BI.biSizeImage = BytesPerScanline ( BI.biWidth, BI.biBitCount, 32 ) *
                                        abs ( BI.biHeight );
}
//---------------------------------------------------------------------------
//取得图像一列的字节
long __fastcall TForm1::BytesPerScanline ( long PixelsPerScanline, long
BitsPerPixel, long Alignment )
{
Alignment --;
long Result = ((PixelsPerScanline * BitsPerPixel) + Alignment) &
              ( ~Alignment );
return Result / 8;
}
//---------------------------------------------------------------------------

