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
   //先修改笔刷色彩
   Form1->Canvas->Brush->Color = (TColor)RGB(125,125,255);
   //再全填入此指定色彩
   ::ExtFloodFill(Form1->Canvas->Handle,
                  X/2,Y/2,(TColor)RGB(125,125,255),
                  FLOODFILLBORDER);
   }

if(Shift.Contains(ssRight))
   {
   //先修改笔刷色彩
   Form1->Canvas->Brush->Color = (TColor)RGB(255,125,125);
   //再全填入此指定色彩
   ::ExtFloodFill(Form1->Canvas->Handle,
                  X/2,Y/2,(TColor)RGB(255,125,125),
                  FLOODFILLBORDER);
   }
}
//---------------------------------------------------------------------------


