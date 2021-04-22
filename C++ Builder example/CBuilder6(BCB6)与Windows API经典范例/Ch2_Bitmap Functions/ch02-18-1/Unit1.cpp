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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
for (int y=0;y<Image1->Height;y++)
  for (int x=(y % 2 ? 0 : 1);x<Image1->Width;x+=2)
     {
     //取得指定位置的位图色彩
     COLORREF pcolor = ::GetPixel( Image1->Canvas->Handle, x, y );
     //逐一用宏取出RGB色彩值，并调高彩值
     unsigned int r = ((int)GetRValue(pcolor) + 40);
     unsigned int g = ((int)GetGValue(pcolor) + 40);
     unsigned int b = ((int)GetBValue(pcolor) + 40);
     //限制彩值范围
     if(r>255) r = 255; if(g>255) g = 255; if(b>255) b = 255;
     ///重设位图色彩
     ::SetPixel(Image1->Canvas->Handle, x, y, RGB(r, g, b));
     }
//更新Image1显示
Image1->Refresh();
}
//---------------------------------------------------------------------------
