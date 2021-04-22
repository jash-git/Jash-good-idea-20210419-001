//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//由CheckBox1控制
CheckBox1->Checked = false;

//这是自定义等距小黑点的新图文件
//先制作一新图文件，20x20位图的固定长宽
gridBitmap = new Graphics::TBitmap();
gridBitmap->Width = 20;
gridBitmap->Height = 20;
gridBitmap->Canvas->Brush->Color = (TColor)RGB(220,255,220);
gridBitmap->Canvas->Pen->Color = (TColor)RGB(0,170,90);
gridBitmap->Canvas->FillRect(gridBitmap->Canvas->ClipRect);
//将此图文件上面布满等距小点
const int spacing = 10;
for (y = 0; y < 20; y = y + spacing)
    {
    for (x = 0; x < 20; x = x + spacing)
        {
        gridBitmap->Canvas->Ellipse(x, y, x + 2, y + 2);
        }
    }
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
//结束程序时，释放新图文件
delete gridBitmap;
}
//---------------------------------------------------------------------------
//若每次重绘Form1时，便将新图文件等距绘到Form1上，
//填满整个Form1背景
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//取得Form1长宽
const int width = ClientWidth;
const int height = ClientHeight;
//
if(CheckBox1->Checked)
  {
  //将新图文件连续复制到Form1背景上
  HDC HdcDest = Canvas->Handle;
  HDC HdcSource = gridBitmap->Canvas->Handle;
  for (y = 0; y < height; y = y + 20)
     {
     for (x = 0; x < width; x = x + 20)
        {
        ::BitBlt(HdcDest, x, y, 20, 20,
                 HdcSource, 0, 0,
                 SRCCOPY);
        }
     }
  }
else
  {
  //在内存中配置一新图文件
  //Unit6.hい #include <memory>
  std::auto_ptr<Graphics::TBitmap> BackGr(new Graphics::TBitmap());
  BackGr->Width = ClientWidth;
  BackGr->Height = ClientHeight;
  //设置新图文件属性
  BackGr->Canvas->Brush->Color = (TColor)RGB(255,230,255);
  BackGr->Canvas->Brush->Style = bsDiagCross;
  BackGr->Canvas->FillRect(BackGr->Canvas->ClipRect);
  //将新图文件复制到Form1背景上
  ::BitBlt(Canvas->Handle, 0, 0,
           BackGr->Width, BackGr->Height,
           BackGr->Canvas->Handle, 0, 0,
           SRCINVERT);
  }
}
//---------------------------------------------------------------------------
//当点按CheckBox时，重绘Form1背景
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
Form1->Refresh();
Form1->OnPaint;
}
//---------------------------------------------------------------------------

