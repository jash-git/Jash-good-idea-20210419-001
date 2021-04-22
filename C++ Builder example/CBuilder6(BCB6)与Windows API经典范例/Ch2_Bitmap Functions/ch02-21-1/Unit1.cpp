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
//Ĭ��Image1Ϊ24λ����������
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
//���ڴ��д���һCOLORREF�ṹ��������
//���ô�һCOLORREF����Ϊ24λɫ��
std::auto_ptr<COLORREF> clrrf(new COLORREF[width * height * 3]);
//ȡ�ô��ڴ�����λ��ָ��
COLORREF *pclrrf = clrrf.get();
int x=100;
//����COLORREF��������RGB�����
for (int index = 0; index < width * height * 3; index++)
   {
   if((index%20)==0)
      x = 255-random(155);
   pclrrf[index] = RGB(x, x-20,x-80);
   }
//�����Զ��庯��
DrawDIBuffer(Image1->Canvas->Handle,
             0, 0,
             width, height,
             pclrrf,
             width, height);
//��Image1����
Image1->Refresh();
}
//---------------------------------------------------------------------------
//�����Զ��庯��
void TForm1::DrawDIBuffer(HDC HTargetDC, int X, int Y, int dst_width,
    int dst_height, COLORREF *clrrf, int src_width, int src_height)
{
//(1)���ڴ�������һBITMAPINFO�ṹ����
std::auto_ptr<BITMAPINFO> pbmi(new BITMAPINFO());
//(2)���ô�BITMAPINFO�ṹ��Ա
pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
pbmi->bmiHeader.biWidth = src_width;
pbmi->bmiHeader.biHeight = src_height;
pbmi->bmiHeader.biPlanes = 1;
pbmi->bmiHeader.biBitCount = 24;
pbmi->bmiHeader.biCompression = BI_RGB;
//�˽ṹ��Ϊ24λͼ�ļ����ʼ���ȡ�����ֽ�
pbmi->bmiHeader.biSizeImage =
     ((((src_width * pbmi->bmiHeader.biBitCount) +
     31) & ~31) / 8) * src_height;
//(3)���ڴ��з��������Image1ʵ�ʴ�С�Ļ�������
//char��BYTE��Ϊ 8-bits���A
std::auto_ptr<unsigned char> pbits
     (new unsigned char[pbmi->bmiHeader.biSizeImage]);
//(4)����COLORREF������pbits������
int pos = 0;
int index = 0;
for (int y = 0; y < src_height; y++)
  {
  for (int x = 0; x < src_width; x++)
    {
    //�ֱ����빹��ÿ��λͼ��RGBֵ
    pbits.get()[pos] = GetBValue(clrrf[index]);
    pbits.get()[pos + 1] = GetGValue(clrrf[index]);
    pbits.get()[pos + 2] = GetRValue(clrrf[index]);
    pos += 3;
    index += 2;
    }
  }

//(5)���ڴ���pbmiͼ�ļ�������Image1��DC handle
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

