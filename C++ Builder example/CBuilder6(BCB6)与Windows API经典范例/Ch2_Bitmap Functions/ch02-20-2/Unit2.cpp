//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//Сͼ��Ӧ����ʾͼ������ͼ�� 2 ����Ա
Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
Graphics::TBitmap *BitmapMask = new Graphics::TBitmap();
//ͼʾΪ 16x16 λͼ
Bitmap->Width = 16;
Bitmap->Height = 16;
BitmapMask->Width = 16;
BitmapMask->Height = 16;
//��Image1��С&������Bitmap��ʾͼ��
::StretchBlt(Bitmap->Canvas->Handle,
             0, 0,
             Bitmap->Width, Bitmap->Height,
             Image1->Picture->Bitmap->Canvas->Handle,
             0, 0,
             Image1->Picture->Bitmap->Width,
             Image1->Picture->Bitmap->Height,
             SRCCOPY);
//������ͼ����Ϊȫ�ڣ���Ϊȫ͸��״̬
BitmapMask->Canvas->Brush->Color = clBlack;
BitmapMask->Canvas->FillRect(BitmapMask->Canvas->ClipRect);
//ICONINFO�ṹ����
ICONINFO icf;
icf.fIcon = true;
//����ͼ������ʾͼ�����AND����
icf.hbmMask = BitmapMask->Handle;
icf.hbmColor = Bitmap->Handle;
//����ICONINFO�ṹ����һ��ͼ��
HICON HIcon = ::CreateIconIndirect(&icf);
//������ͼʾָ����Form1ʹ��
Application->Icon->Handle = HIcon;
Icon->Handle = HIcon;
//ɾ����ʾͼ��������ͼ��
delete Bitmap;
delete BitmapMask;
}
//---------------------------------------------------------------------------
