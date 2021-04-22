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
Graphics::TBitmap* Bitmap = Image1->Picture->Bitmap;
//����RGBɫ������
RGBQUAD rgbQ[256];
memset(rgbQ, 0, 256);
//ȡ��Image1��ɫ�̣�����һ�޸���ɫ
if (::GetDIBColorTable(Bitmap->Canvas->Handle, 0, 256, rgbQ))
   {
   for (int index = 0; index < 256; index++)
      {
      // floor���� #include <math>
      //ȡ��ɫ����ÿһRGB����ƽ�������������ȫ�
      //�˷�������Ωһȡֵ��ʽ
      int gray = floor((rgbQ[index].rgbBlue +
                        rgbQ[index].rgbGreen +
                        rgbQ[index].rgbRed)/3*1.05);
      //������ɫ��Χ
      if(gray <= 0) gray = 0;
      if(gray >= 255) gray = 255;
      //��RGBͬΪһֵʱ������ʾΪ�ҽ�
      rgbQ[index].rgbBlue = (byte)gray;
      rgbQ[index].rgbGreen = (byte)gray;
      rgbQ[index].rgbRed = (byte)gray;
      }
   //�����֮ɫ�̣�ָ�ɸ�Image1ʹ��
   ::SetDIBColorTable(Bitmap->Canvas->Handle, 0, 256, rgbQ);
   //�ػ�Image1
   Image1->Repaint();
   }
}
//---------------------------------------------------------------------------
