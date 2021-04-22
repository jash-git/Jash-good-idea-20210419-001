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
//����Image1
Image1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
//��Bitmap��Image1ͼ�ļ����
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;

//����һ����ʱ���ã�����ͼ�ļ�16λת��8λʱ�����ʻ�
BITMAPINFO bmi;
//��bmi�ṹ�����ڴ��ʼ��
memset(&bmi, 0, sizeof(BITMAPINFO));
//BITMAPINFO�ṹ����BITMAPINFOHEADER�ṹ+RGBQUAD�ṹ
//����BITMAPINFOHEADER�ṹ��Ա
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//�ṹ��С�p
bmi.bmiHeader.biWidth = Bitmap->Width;//λͼ���
bmi.bmiHeader.biHeight = Bitmap->Height; //λͼ�߶�
bmi.bmiHeader.biPlanes = 1;//Ŀ��װ��ƽ��������Ϊ1
//ת���� 16 λ����
bmi.bmiHeader.biBitCount = 16; //  16λ����
//����RGBQUAD�ṹ��Ա
DWORD BitMasks[3];
BitMasks[0] = 0xFFFF;//Blue������
BitMasks[1] = 0xFFFF;//Green������
BitMasks[2] = 0xFFFF;//Red������
//����õ�RGB�ṹ����RGBQUAD�ṹ
memcpy(bmi.bmiColors, BitMasks, sizeof(BitMasks));

unsigned char *bits;
//��BITMAPINFO�ṹ����һ��DIBͼ�ļ���������handle
HBITMAP HBmp = ::CreateDIBSection(0, &bmi, DIB_RGB_COLORS,
                                  reinterpret_cast<void **>(&bits),
                                  NULL, NULL);

if (HBmp)
    {
    //������ָ��DC���ݵ�DC
    HDC Hdc = ::CreateCompatibleDC(0);
    //ѡ���¶��󣬲�����ԭ�ж�������
    HBITMAP HOldBmp = ::SelectObject(Hdc, HBmp);
    try
      {
      //����Image����ͼ������ʱ�豸
      ::BitBlt(Hdc, 0, 0,
               Bitmap->Width, Bitmap->Height,
               Bitmap->Canvas->Handle, 0, 0,
               SRCCOPY);
      //������ʱ�豸����ͼ����Form1��
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
      //�Ȼָ�ԭ���ã����ͷŶ���
      ::DeleteObject(::SelectObject(Hdc, HOldBmp));
      //�ͷ�DC
      ::DeleteDC(Hdc);
      }
    //�Ȼָ�ԭ���ã����ͷŶ���
    ::DeleteObject(::SelectObject(Hdc, HOldBmp));
    //�ͷ�DC
    ::DeleteDC(Hdc);
    }
}
//---------------------------------------------------------------------------

