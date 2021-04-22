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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//重复绘制之间隔位图
int GridSpace = 8;
//创造一新图像，作为拼贴来源
Grid = new Graphics::TBitmap;
Grid->Width = ClientWidth;
Grid->Height = ClientHeight;
Grid->Canvas->Brush->Color = (TColor)RGB(140,140,255);
Grid->Canvas->FillRect( Grid->Canvas->ClipRect );
//位图定距改变色彩
for ( int y = 0 ; y < Grid->Height ; y += GridSpace )
  for ( int x = 0 ; x < Grid->Width ; x += GridSpace )
     {
     ::SetPixel( Grid->Canvas->Handle , x+1, y+1, RGB(0,50,0));
     ::SetPixel( Grid->Canvas->Handle , x, y, RGB(220,255,220));
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//释放图像
delete Grid;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//当需要重绘Form1时，复制Grid图像至Form1上
Canvas->CopyRect( Canvas->ClipRect, Grid->Canvas, Canvas->ClipRect );
}
//---------------------------------------------------------------------------

