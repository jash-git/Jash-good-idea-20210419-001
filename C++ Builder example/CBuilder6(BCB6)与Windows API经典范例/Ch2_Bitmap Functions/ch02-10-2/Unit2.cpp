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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//ȡ��Form1��DC
HDC hdc = ::GetDC(Handle);
//ȡ�����λ�õ�λͼɫ��
COLORREF pcolor = ::GetPixel( hdc, X, Y );
//��һ�ú�ȡ��RGBɫ��ֵ
unsigned int r = GetRValue(pcolor);
unsigned int g = GetGValue(pcolor);
unsigned int b = GetBValue(pcolor);
//�����ʵʱ��ʾ��Form1����������
Caption ="���λ�ã�X = "+AnsiString(X)+" ,Y ="+AnsiString(Y)+
         ",λͼɫ�ʣ�R:"+AnsiString(r)+"_G:"+AnsiString(g)+
         "_B:"+AnsiString(b);
//�ͷ�Form1��DC handle
ReleaseDC(0,hdc);
}
//---------------------------------------------------------------------------
