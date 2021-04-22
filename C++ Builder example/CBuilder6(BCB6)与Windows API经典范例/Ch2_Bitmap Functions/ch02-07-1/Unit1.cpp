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

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

if(Shift.Contains(ssLeft))
   {
   //���޸ı�ˢɫ��
   Image1->Picture->Bitmap->Canvas->Brush->Color = (TColor)RGB(125,125,255);
   //��ȫ�����ָ��ɫ��
   ::FloodFill( Image1->Picture->Bitmap->Canvas->Handle,
                X/2, Y/2, RGB(125,125,255));
   }
else if(Shift.Contains(ssRight))
   {
   //���޸ı�ˢɫ��
   Image1->Picture->Bitmap->Canvas->Brush->Color = (TColor)RGB(255,125,125); // OK
   //��ȫ�����ָ��ɫ��
   ::FloodFill( Image1->Picture->Bitmap->Canvas->Handle,
                X/2, Y/2, RGB(255,125,125));
   }
//������ɫ�ʺ󣬸���Image1
Image1->Repaint();
}
//---------------------------------------------------------------------------

