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
//ͼ��BITMAPINFO�ṹ����&����
BITMAPINFOHEADER bmih = {
  sizeof(BITMAPINFOHEADER), //�ṹ��С�p
  Image1->Width, //λͼ���
  Image1->Height, //λͼ�߶�
  1, // ɫ����Ŀ
  24, //ÿһλͼ��λ��Ŀ
  BI_RGB, //�Ƿ�Ϊѹ��ͼ�ļ�
  0, //���ֽڣ�����ѹ��(BI_RGB)�������Ϊ 0
  0, //X���������ֱ���
  0, //Y���������ֱ���
  0, //ʹ����ɫ��Ŀ(RGBQUAD������Ŀ)����Ϊ0����ʹ�������ɫ��Ŀ
  0 //��Ҫʹ����ɫ��Ŀ
  };
//��ͼ�ļ���8λ(256ɫ)���ϣ����ô�ɫ�ʽṹ��������
RGBQUAD rgb0 = {0,0,0,0};
//�������ṹ��
BITMAPINFO bmi;
bmi.bmiHeader = bmih;
bmi.bmiColors[0] = rgb0; //��ɫ��

//����ÿ��Ϊ�����ֽ�
int RowSize = ((((Image1->Width + 1) * 3) / 4) * 4);
//�ټ���ͼ�ļ�ȫ���ֽڣ�������ָ��
BYTE *Bits = new BYTE[RowSize * Image1->Height];
//������һ�����������ÿһλͼ��RGBֵ
BYTE *BitsPtr;
for (int y=0; y<Image1->Height; y++)
  {
  //ÿһ����ʼλͼ��λ��
  BitsPtr = Bits + (RowSize * y);
  for (int x=0; x<Image1->Width; x++)
    {//ÿһλͼΪ3�ֽڹ��ɣ��� 0x00B9��FF��DC���
    //�ʿ�����λ��
    *BitsPtr++ = (BYTE)((x>255)?255:x);//��ɫ
    *BitsPtr++ = (BYTE)random(255); //��ɫ
    *BitsPtr++ = (BYTE)255; //��ɫ
    }//random(int num)�� #include <stdlib.h>
  }
//����Image1��С
Image1->Picture->Bitmap->Width = Image1->Width;
Image1->Picture->Bitmap->Height = Image1->Height;
HBITMAP hbmp = Image1->Picture->Bitmap->Handle;
HDC hdc = Image1->Canvas->Handle;
//����DIBͼ������
::SetDIBits (hdc, //װ���豸��handle
             hbmp, //ͼ��handle
             30, //ɨ����ʼ��
             Image1->Height-60, //ɨ������
             Bits, //�ֽ�����
             &bmi, //BITMAPINFO�ṹ
             DIB_RGB_COLORS //ɫ��������
             );
//�ͷ�λ����
delete[] Bits;
//�ػ�Image1
Image1->Repaint();
Image1->Stretch = true;
}
//---------------------------------------------------------------------------

