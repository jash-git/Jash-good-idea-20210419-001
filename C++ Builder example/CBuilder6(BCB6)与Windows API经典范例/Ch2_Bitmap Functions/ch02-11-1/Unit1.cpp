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
{//������Image1ͼ�����������ʾ�ɹ�
Image1->Hide();
Tag = 0;//���������ԣ���Ϊ��������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{//ȡ��Form1��DC handle
HDC hdc = Canvas->Handle;
int setMode;
switch(Tag%4)
   {
   case 0: setMode = BLACKONWHITE; break;
   case 1: setMode = WHITEONBLACK; break;
   case 2: setMode = HALFTONE; break;
   case 3: setMode = COLORONCOLOR; break;
   }
//������ͼ����չʱģʽ
::SetStretchBltMode(hdc, setMode);
Tag++; //��������
//���ñ�ˢ��SetStretchBltMode��ʼ&��Χ���A
::SetBrushOrgEx(hdc, 0, 0, NULL);
//�������ڴ����ں�Form1��Image1��HDC <CreateCompatibleDC>��
//����ʾ��Form1�����ϣ����������ָ�ɫ��֮���촦
//��Image1������Form1����
::StretchBlt(hdc,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Image1->Canvas->Handle, 0, 0,
             Image1->Picture->Bitmap->Width,
             Image1->Picture->Bitmap->Height,
             SRCCOPY);
//ȡ��ͼ����չʱɫ��ģʽ
int mode = ::GetStretchBltMode(hdc);
//���ڱ���������ʾForm1������ɫ��ģʽ
switch(mode)
   {
   case BLACKONWHITE: Caption = "�ڰ�ģʽ(AND)"; break;
   case WHITEONBLACK: Caption = "�ڰ�ģʽ(OR)"; break;
   case HALFTONE: Caption = "��ɫ��ģʽ"; break;
   case COLORONCOLOR: Caption = "ȥ������λͼ����ģʽ"; break;
   }
}
//---------------------------------------------------------------------------



