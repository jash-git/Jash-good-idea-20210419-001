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
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(Shift.Contains(ssLeft))
   {
   //���޸ı�ˢɫ��
   Form1->Canvas->Brush->Color = (TColor)RGB(125,125,255);
   //��ȫ�����ָ��ɫ��
   ::ExtFloodFill(Form1->Canvas->Handle,
                  X/2,Y/2,(TColor)RGB(125,125,255),
                  FLOODFILLBORDER);
   }

if(Shift.Contains(ssRight))
   {
   //���޸ı�ˢɫ��
   Form1->Canvas->Brush->Color = (TColor)RGB(255,125,125);
   //��ȫ�����ָ��ɫ��
   ::ExtFloodFill(Form1->Canvas->Handle,
                  X/2,Y/2,(TColor)RGB(255,125,125),
                  FLOODFILLBORDER);
   }
}
//---------------------------------------------------------------------------


