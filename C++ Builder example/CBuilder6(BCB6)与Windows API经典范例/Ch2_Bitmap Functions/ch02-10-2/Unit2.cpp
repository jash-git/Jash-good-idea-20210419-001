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
//取得Form1的DC
HDC hdc = ::GetDC(Handle);
//取得鼠标位置的位图色彩
COLORREF pcolor = ::GetPixel( hdc, X, Y );
//逐一用宏取出RGB色彩值
unsigned int r = GetRValue(pcolor);
unsigned int g = GetGValue(pcolor);
unsigned int b = GetBValue(pcolor);
//将结果实时显示在Form1标题文字中
Caption ="鼠标位置：X = "+AnsiString(X)+" ,Y ="+AnsiString(Y)+
         ",位图色彩：R:"+AnsiString(r)+"_G:"+AnsiString(g)+
         "_B:"+AnsiString(b);
//释放Form1的DC handle
ReleaseDC(0,hdc);
}
//---------------------------------------------------------------------------
