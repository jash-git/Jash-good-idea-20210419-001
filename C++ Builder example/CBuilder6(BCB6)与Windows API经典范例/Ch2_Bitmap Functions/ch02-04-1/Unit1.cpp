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
Button1->Tag = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����������Image1ͼ��
Image1->Picture = NULL;
Image1->Align = alNone;
Image1->Stretch = false;
//���沶׽Ӱ�����ʱͼ��
Graphics::TBitmap *tempBmp = new Graphics::TBitmap();
HDC hdc = NULL;
//��׽��Χ�ĳ���
int x, y;
if(Button1->Tag)
   {//ȡ��ȫ��Ļ��DC handle
   hdc = ::GetDC(0);
   x = Screen->Width;
   y = Screen->Height;
   Button1->Tag = false;
   }
else
   {//ȡ��Form1��DC handle
   hdc = ::GetWindowDC(Handle);
   x = Form1->Width;
   y = Form1->Height;
   Button1->Tag = true;
   }
//����һ������װ�õ���ͼ�ļ�����ָ�ɸ�tmpBmp handle
tempBmp->Handle = ::CreateCompatibleBitmap( hdc, x, y);
//��hdc��ȡ�������ݸ�����tempBmp��
::BitBlt(tempBmp->Canvas->Handle, 0, 0,
         tempBmp->Width, tempBmp->Height,
         hdc, 0, 0, SRCCOPY);
//��tempBmp����Image1��
Image1->Picture->Bitmap = tempBmp;
//ɾ����ʱ��tempBmp
delete tempBmp;
//��Image1����Form1�м�
Image1->Align = alClient;
Image1->Stretch = true;
}
//---------------------------------------------------------------------------
