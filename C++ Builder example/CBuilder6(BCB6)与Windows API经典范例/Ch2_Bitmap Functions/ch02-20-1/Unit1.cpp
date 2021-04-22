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
//����PaintBox1λ��
PaintBox1->Align = alClient;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����PaintBox1���歱
PaintBox1->Refresh();
//ȡ��Ŀ��ͼ��DC handle
HDC HDestDC = PaintBox1->Canvas->Handle;
//ȡ����Դͼ��DC handle
HDC HSourceDC = Image1->Canvas->Handle;
//�򻯳������
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;
//���ñ�����֮����
int dest_height = Bitmap->Height;
int y_pos1 = 0, y_pos2 = 0;

for (int col = 0; col < Bitmap->Width; col++)
   {
   //�Ƚ�Image1�������̱���
   ::StretchBlt(HDestDC,           //Ŀ��ͼ��
                col, y_pos1,       //X,Y
                1, dest_height,    //��.��
                HSourceDC,         //��Դͼ��
                col, 0,            //X,Y
                1, Bitmap->Height, //��.��
                SRCCOPY);
   //�ٽ�PaintBox1�����ƶ�λ��
   ::StretchBlt(HDestDC,           //Ŀ��ͼ��
                col, 0,            //X,Y
                1, Bitmap->Height, //��.��
                HDestDC,           //��Դͼ��
                col, y_pos2,       //X,Y
                1, Bitmap->Height, //��.��
                SRCCOPY);
   //Ϊ��һ��StretchBltʹ��
   //ÿ�� 1 �У��������߶�
   if (col % 2 == 0)
      {
      y_pos1++;
      dest_height--;
      }
   //Ϊ�ڶ���StretchBltʹ��
   //ÿ�� 2 �У����ƶ�λ��
   if(col%4 == 0)
      y_pos2++;
   }
}
//---------------------------------------------------------------------------

