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
//��Bitmap��Image1ͼ�ļ�����
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;

//����һ����ʱ�趨������ͼ�ļ�16λת��8λʱ�����ʻ�
BITMAPINFO bmi;
//��bmi�ṹ�����ڴ��ʼ��
memset(&bmi, 0, sizeof(BITMAPINFO));
//BITMAPINFO�ṹ����BITMAPINFOHEADER�ṹ+RGBQUAD�ṹ
//����BITMAPINFOHEADER�ṹ��Ա��
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//�ṹ��С�p
bmi.bmiHeader.biWidth = Bitmap->Width;//λͼ��ȫ�
bmi.bmiHeader.biHeight = Bitmap->Height; //λͼ�߶ȫ�
bmi.bmiHeader.biPlanes = 1;//Ŀ��װ��ƽ��������Ϊ1
//ת���� 8 λ����
bmi.bmiHeader.biBitCount = 8; // 8λ����
//����RGBQUAD�ṹ��Ա��
DWORD BitMasks[3];
BitMasks[0] = 0xFFFF;//Blue������
BitMasks[1] = 0xFFFF;//Green�����ȫ�
BitMasks[2] = 0xFFFF;//Red������
//����õ�RGB�ṹ���뵽RGBQUAD�ṹ��
memcpy(bmi.bmiColors, BitMasks, sizeof(BitMasks));

unsigned char *bits;
//��BITMAPINFO�ṹ����һ����DIBͼ�ļ���������handle
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
      ::BitBlt(Canvas->Handle, 10, 10,
               Bitmap->Width, Bitmap->Height,
               Hdc, 0, 0,
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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//���ڴ�������һ����ͼ�ļ�
//��Unit1.h�м��� #include <memory>
std::auto_ptr<Graphics::TBitmap> Bitmap(new Graphics::TBitmap());
//���ó���
Bitmap->Width = Image1->Picture->Bitmap->Width;
Bitmap->Height = Image1->Picture->Bitmap->Height;
//����Ϊ8λͼ�ļ�
Bitmap->PixelFormat = pf8bit;
//��Image1����������ͼ�ļ��������ʻ�
::BitBlt(Bitmap->Canvas->Handle, 0, 0,
         Bitmap->Width, Bitmap->Height,
         Image1->Canvas->Handle, 0, 0,
         SRCCOPY);
//�ٽ���ͼ�ļ�ָ�ɻ�Image1
Image1->Picture->Bitmap->Assign(Bitmap.get());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//�ͷ�����ͼ�ļ�
for(int i=0;i<ComponentCount;i++)
  if (Components[i]->ClassNameIs("TBitmap"))
      delete Components[i];

}
//---------------------------------------------------------------------------

