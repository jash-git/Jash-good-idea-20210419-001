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
//新建Image3图文件
Image3 = new TImage(this);
Image3->Parent = Form1;
Image3->Width = Image2->Width;
Image3->Height = Image2->Height;
Image3->Picture->Bitmap->Assign(Image2->Picture->Bitmap);
Image3->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete Image3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//COLORREF结构声明
COLORREF c;
//将两图文件交错位图
for (int h=0;h<Image1->Height;h++)
  for (int w=(h % 2 ? 0 : 1);w<Image1->Width;w+=2)
    {
    c = ::GetPixel( Image1->Canvas->Handle, w, h);
    ::SetPixel( Image3->Canvas->Handle, w, h, c);
    }
//显示Image3
Image3->Show();
Image3->Refresh();
Image3->Top = Image1->Top;
Image3->Left = Image1->Left + Image1->Width + 5;
}
//---------------------------------------------------------------------------

