//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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
void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int Col,
      int Row, TRect &Rect, TGridDrawState State)
{
//设置上方&左方标题栏状态
if (State.Contains(gdFixed))
   {
   //设置底色&字色
   StringGrid1->Canvas->Brush->Color = (TColor)RGB(255,200,230);//clBtnFace;
   StringGrid1->Canvas->Font->Color = clWindowText;
   StringGrid1->Canvas->FillRect(Rect);
   //设置三维效果
   Frame3D(StringGrid1->Canvas, Rect, clBtnHighlight, clBtnShadow, 1);
   }

//设置被选取内容栏状态
else if (State.Contains(gdSelected))
   {
   //设置底色&字色
   StringGrid1->Canvas->Brush->Color = (TColor)RGB(210,255,210);
   StringGrid1->Canvas->Font->Color = clHighlightText;
   StringGrid1->Canvas->FillRect(Rect);
   }

//设置非选取内容栏状态
else
   {
   //先设置StringGrid1之DC性质
   StringGrid1->Canvas->Brush->Color = StringGrid1->Color;
   StringGrid1->Canvas->Font->Color = StringGrid1->Font->Color;
   //将Image1变形复制至StringGrid1中
   ::StretchBlt(StringGrid1->Canvas->Handle,
                Rect.Left,
                Rect.Top,
                Rect.Right - Rect.Left,
                Rect.Bottom - Rect.Top,
                Image1->Picture->Bitmap->Canvas->Handle,
                0, 0,
                Image1->Width, Image1->Height,
                SRCCOPY);
   }
//设置StringGrid1文字内容不干扰背景
::SetBkMode(StringGrid1->Canvas->Handle, TRANSPARENT);
//将文字内容绘制至指定栏中
AnsiString text = StringGrid1->Cells[Col][Row];
RECT R = RECT(Rect);
::DrawText(StringGrid1->Canvas->Handle, text.c_str(),
           text.Length(), &R, DT_LEFT);

}
//---------------------------------------------------------------------------
