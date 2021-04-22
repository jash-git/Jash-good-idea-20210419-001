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
//��Image1���ز�������Դͼ��
Image1->Hide();
//����һͼ����Ϊת���ɹ�
image2 = new TImage(this);
image2->Parent = Form1;
image2->Picture->Bitmap->Assign(Image1->Picture->Bitmap);
image2->Stretch = true;
image2->Align = alClient;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//�رճ���ǰ���ͷ�image2��ռס�ڴ�
delete image2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�Զ��庯��--ת��ͼ�ļ�ɫ��
BitmapCover(Image1->Picture->Bitmap,ComboBox1->Text.ToInt());
}
//---------------------------------------------------------------------------
//�Զ��庯��--ת��ͼ�ļ�ɫ��
void __fastcall TForm1::BitmapCover(Graphics::TBitmap *Bitmap,int bpp)
{
const int AWidth = Bitmap->Width;
const int AHeight = Bitmap->Height;
//ͼ��ṹ��������������ڴ�
BITMAPINFO bmi;
::ZeroMemory(&bmi, sizeof(BITMAPINFO));

//����BITMAPINFO(HEADER)�ṹ��Ա
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
bmi.bmiHeader.biWidth = AWidth;
bmi.bmiHeader.biHeight = -AHeight;
bmi.bmiHeader.biPlanes = 1;
//���û����ô�ͼ��λ��
bmi.bmiHeader.biBitCount = (WORD)bpp;
bmi.bmiHeader.biCompression = BI_RGB;

//��Ϊ8λ����ͼ��������ָ������ǰ������ɫ
//ͼ����BitBlt������ȡ����ӽ�ɫ��
RGBQUAD rgb1 = {50, 50, 50, 0};///���ɫ
RGBQUAD rgb2 = {235, 235, 235, 0};//ǳ��ɫ
RGBQUAD rgb3 = {255, 230, 140, 0};//����ɫ
bmi.bmiColors[0] = rgb1;
bmi.bmiColors[1] = rgb2;
bmi.bmiColors[2] = rgb3;

//���ڴ��д���һͼ�񣬷���handle���ͼ������ָ��
unsigned char *mapbits;
HBITMAP HBmp =
        ::CreateDIBSection(0, &bmi, DIB_RGB_COLORS,
                   reinterpret_cast<void **>(&mapbits),
                   NULL, NULL);

if (HBmp)
   {
   //��GDIͬ��ִ��
   ::GdiFlush();
   //���ڴ��д���һ����DC handle
   HDC Hdc = ::CreateCompatibleDC(0);
   //�Ƚ����úõ���ͼ��DC handle����˼���DC handle��
   HBITMAP HOldBitmap = ::SelectObject(Hdc, HBmp);
   //�ٽ�Image1 DC handle���룬�����ʻ����ת��
   ::BitBlt(Hdc, 0, 0,
            AWidth, AHeight,
            Bitmap->Canvas->Handle,
            0, 0,
            SRCCOPY);
   //�ظ�����DCԭ�нṹ����
   ::SelectObject(Hdc, HOldBitmap);
   //�ͷŴ�����DC
   ::DeleteDC(Hdc);
   //�����ʻ��������image2
   image2->Picture->Bitmap->Handle = HBmp;
   }
}
//---------------------------------------------------------------------------




