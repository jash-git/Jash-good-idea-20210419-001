//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
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
//����һ��ʱͼ�ļ�
Graphics::TBitmap *Bitmap=new Graphics::TBitmap;
//��������ʱͼ�ļ�����
Bitmap->Width=Screen->Width;
Bitmap->Height=Screen->Height;
Bitmap->PixelFormat=pf16bit;

//ȡ�������DC handle
HDC NewDC=::GetWindowDC(0);

//��ȫ��Ļ���Ƶ�Bitmap��
::BitBlt(Bitmap->Canvas->Handle,0,0,
         Screen->Width,Screen->Height,
         NewDC,0,0,SRCCOPY);
//��user�������
char *str = "YES��ť=��ʾ��Form1�ϣ�\nNO��ť=����ļ�C:\\NewBitmap.BMP��\nCANCEL��ť=Do Nothing!";
int re = ::MessageBox(Handle, str, "�浵or��ʾ",MB_YESNOCANCEL);
switch(re)
   {
   case IDYES:
        Image1->Picture->Assign(Bitmap);
        break;
   case IDNO:
        Bitmap->SaveToFile("C:\\NewBitmap.BMP");
        break;
   case IDCANCEL:
        break;
   }

//�ͷ�DC
ReleaseDC(Form1->Handle,NewDC);
//ɾ��Bitmap
delete Bitmap;
}
//---------------------------------------------------------------------------

