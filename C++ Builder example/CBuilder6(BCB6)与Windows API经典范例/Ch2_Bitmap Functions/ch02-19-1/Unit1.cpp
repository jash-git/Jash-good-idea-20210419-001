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
//������Image1ͼ��
Image1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//ȡ��Form1��DC handle
HDC Hdc = Canvas->Handle;
//����ͼ����չʱģʽ��HALFTONE������Ӱ��Ʒ�ʽϼ�
::SetStretchBltMode(Hdc, HALFTONE);
//���ñ�ˢ��SetStretchBltMode��ʼ&��Χ
::SetBrushOrgEx(Hdc, 0, 0, NULL);
//��Image1������Form1����
::StretchBlt(Hdc,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Image1->Canvas->Handle, 0, 0,
             Image1->Picture->Bitmap->Width,
             Image1->Picture->Bitmap->Height,
             SRCCOPY);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
//���䶯Form1��Сʱ�������ػ涯���@
Form1->Repaint();
}
//---------------------------------------------------------------------------



