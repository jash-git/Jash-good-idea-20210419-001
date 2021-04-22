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
//�������ʱ��ֹͣ��ť�ٰ���
Button1->Enabled = false;
for( int i=0; i<256; i++ )
   {
   //���ж�ִ��ѭ���������кβ����¼���ִ��
   Application -> ProcessMessages ();
   //�����Զ���֮����������
   ColorChangeLoop ();
   }
//�������ʱ���ָ���ť���ܯ�
Button1->Enabled = true;
}
//---------------------------------------------------------------------------
//�Զ���֮����������
void __fastcall TForm1::ColorChangeLoop ()
{
//
int InfoHeaderSize;
int ImageSize = 0;
//ȡ��ͼ�ļ��ṹ��С--InfoHeaderSize
//ȡ��ͼ�ļ��ֽڴ�С--ImageSize
MyGetDIBSizes ( Image1->Picture->Bitmap->Handle,
                InfoHeaderSize, ImageSize);
//����ͼ�ļ��ṹ&λͼ���ֱ���������֮char����
void *BitmapInfo = new char [ InfoHeaderSize ];
unsigned long *Bits = new unsigned long [ ImageSize / 4 ];
//�Զ��庯��--ȡ��&����DIBͼ���������ڴ�������
MyGetDIB( Image1->Picture->Bitmap->Handle,
          BitmapInfo, Bits );
//��һ��ÿ��λͼ����ɫֵ
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
//�Զ��庯��--�������ڴ�������DIBͼ�����ݣ��ٸ���Image1
MySetDIB ( Image1->Picture->Bitmap->Handle,
           BitmapInfo, Bits );
//�����ػ�Image1
Image1->Repaint();
//�ͷ��ڴ��нṹ֮����
delete BitmapInfo;
delete Bits;
}
//---------------------------------------------------------------------------
//ȡ��ͼ�ļ��ṹ��С--InfoHeaderSize
//ȡ��ͼ�ļ��ֽڴ�С--ImageSize
void __fastcall TForm1::MyGetDIBSizes ( HBITMAP Bitmap, int &InfoHeaderSize,
                                        int &ImageSize )
{
//Ĭ��Ϊ32λͼ��
int Colors = 1000;
//BITMAPINFOHEADER�ṹ�����ŧi
TBitmapInfoHeader BI;
//�Զ��庯��--BITMAPINFO��ʼ��
InitializeBitmapInfoHeader ( Bitmap, BI, Colors );
//��Ϊ8λ����ͼ��
if ( BI.biBitCount > 8 )
   {
   InfoHeaderSize = sizeof ( TBitmapInfoHeader );
   //��ͼ��δѹ��&ÿһλͼ��RGB doubleword��ɣ��A
   //����12
   if ((BI.biCompression & BI_BITFIELDS ) != 0 )
      InfoHeaderSize += 12;
   }
else//ͼ��������+ɫ��������
   InfoHeaderSize = sizeof (TBitmapInfoHeader) +
                    sizeof (TRGBQuad) * (1<<BI.biBitCount);
//ͼ�ļ��ֽڴ�С
ImageSize = BI.biSizeImage;
}
//---------------------------------------------------------------------------
//ȡ��&����DIBͼ���������ڴ�������
bool __fastcall TForm1::MyGetDIB(HBITMAP Bitmap, void *BitmapInfo,
                                 void *Bits )
{
//BITMAPINFO��ʼ��--�Զ��庯��
InitializeBitmapInfoHeader (Bitmap,
                            *(( TBitmapInfoHeader *) BitmapInfo),
                            1000 );
//���ڴ��д���һ����DC handle
HDC DC = ::CreateCompatibleDC(0);
bool Result = false;
try
  {
  //ȡ��&����DIBͼ���������ڴ�������
  Result = ::GetDIBits(DC, Bitmap, 0,
                       (( TBitmapInfoHeader *) BitmapInfo)->biHeight,
                       Bits,
                       (( TBitmapInfo *) BitmapInfo ),
                       DIB_RGB_COLORS) != 0;
  }
catch (...) {}
//�ͷ��ڴ��м���DC handle
DeleteDC(DC);
return Result;
}
//---------------------------------------------------------------------------
//�������ڴ�������DIBͼ�����ݣ��ٸ���Image1
bool __fastcall TForm1::MySetDIB(HBITMAP Bitmap, void *BitmapInfo,
                                 void *Bits )
{
//BITMAPINFO��ʼ��--�Զ��庯��
InitializeBitmapInfoHeader ( Bitmap,
                             *(( TBitmapInfoHeader *) BitmapInfo),
                             1000 );
//���ڴ��д���һ����DC handle
HDC DC = CreateCompatibleDC(0);
bool Result = false;
try
  {
  //�������ڴ�������DIBͼ�����ݣ��ٸ���Image1
  Result = ::SetDIBits ( DC, Bitmap, 0,
                        (( TBitmapInfoHeader *) BitmapInfo)->biHeight,
                        Bits,
                        (( TBitmapInfo *) BitmapInfo ),
                        DIB_RGB_COLORS) != 0;
  }
catch (...) {}
//�ͷ��ڴ��м���DC handle
DeleteDC(DC);

return Result;
}
//---------------------------------------------------------------------------
//MyGetDIBSizes & MyGetDIB & MySetDIB������--BITMAPINFO��ʼ��
void __fastcall TForm1::InitializeBitmapInfoHeader ( HBITMAP Bitmap,
                             BITMAPINFOHEADER &BI, int Colors )
{
//��ͬDIBSECTION�ṹ�����i
TDIBSection DS;
int Bytes;
//��BITMAPINFOHEADER��С����
DS.dsBmih.biSize = 0;
//����Bitmap���ֽ�����
Bytes = ::GetObject(Bitmap, sizeof ( DS ), &DS);
//���޷�ȡ��Bitmap�ֽ������ǾͶ���δ֪ͼ��֮���������
if ( Bytes == 0 )
    throw new EInvalidGraphic ( "��Ч��ͼ�ļ���" );
//���ֽ�Bytes�ǳ�̬�ĳ�����С����ָ��Ĭ�ϴ�С�p
else if (( Bytes >= (sizeof(DS.dsBm) + sizeof(DS.dsBmih))) &&
         (DS.dsBmih.biSize >= sizeof(DS.dsBmih)) )
    BI = DS.dsBmih;
else
    {
    //��BI�ڴ����������0
    memset ( &BI, sizeof(BI), 0 );
    //��������BI�ṹ��Ա
    BI.biSize = sizeof ( BI );
    BI.biWidth = DS.dsBm.bmWidth;
    BI.biHeight = DS.dsBm.bmHeight;
    }
//��ɫ�ʾ���λ����
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
else//��������λͼ����
    BI.biBitCount = (WORD)(DS.dsBm.bmBitsPixel * DS.dsBm.bmPlanes);

BI.biPlanes = 1;
BI.biSizeImage = 0;
BI.biClrUsed = 0;
BI.biClrImportant = 0;
//����δ����Ӱ������ʵ�ʴ�С(�ֽ�)
if ( BI.biSizeImage == 0 )
    //�Զ��庯��--ȡ��ͼ��һ�е��ֽڳ���ͼ��߶�
    BI.biSizeImage = BytesPerScanline ( BI.biWidth, BI.biBitCount, 32 ) *
                                        abs ( BI.biHeight );
}
//---------------------------------------------------------------------------
//ȡ��ͼ��һ�е��ֽ�
long __fastcall TForm1::BytesPerScanline ( long PixelsPerScanline, long
BitsPerPixel, long Alignment )
{
Alignment --;
long Result = ((PixelsPerScanline * BitsPerPixel) + Alignment) &
              ( ~Alignment );
return Result / 8;
}
//---------------------------------------------------------------------------

