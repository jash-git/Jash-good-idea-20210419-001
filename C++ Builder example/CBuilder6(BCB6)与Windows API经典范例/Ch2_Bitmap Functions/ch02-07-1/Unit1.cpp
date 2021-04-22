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
   //先修改笔刷色彩
   Image1->Picture->Bitmap->Canvas->Brush->Color = (TColor)RGB(125,125,255);
   //再全填入此指定色彩
   ::FloodFill( Image1->Picture->Bitmap->Canvas->Handle,
                X/2, Y/2, RGB(125,125,255));
   }
else if(Shift.Contains(ssRight))
   {
   //先修改笔刷色彩
   Image1->Picture->Bitmap->Canvas->Brush->Color = (TColor)RGB(255,125,125); // OK
   //再全填入此指定色彩
   ::FloodFill( Image1->Picture->Bitmap->Canvas->Handle,
                X/2, Y/2, RGB(255,125,125));
   }
//完成填充色彩后，更新Image1
Image1->Repaint();
}
//---------------------------------------------------------------------------

