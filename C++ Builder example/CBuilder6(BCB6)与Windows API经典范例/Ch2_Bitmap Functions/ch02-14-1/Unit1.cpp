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
{//������Image2ͼ�ļ�λͼ��Ŀ
Image2->Picture->Bitmap->Width = 20;
Image2->Picture->Bitmap->Height = 70;
//����Image2ͼ�ļ�λ���뷶Χ
Image2->Align = alRight;
Image2->Width = ClientWidth/3;
//����Image1��Image2ͼ�ļ���Ϊ��չ״̬���A
//�����۲캯��ִ��Ч��
Image2->Stretch = true;
Image1->Stretch = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�ʶȵļ򻯳������
Graphics::TBitmap* bmp1 = Image1->Picture->Bitmap;
Graphics::TBitmap* bmp2 = Image2->Picture->Bitmap;
//��Image1ͼ�ļ���ɫ����Ϣ����Image2ͼ�ļ���ʾ����
::SetBitmapBits(bmp2->Handle,
                bmp1->Width * bmp1->Height,
                Image1);
//ָ�ɺ󣬸���Image2
Image2->Refresh();
}
//---------------------------------------------------------------------------
