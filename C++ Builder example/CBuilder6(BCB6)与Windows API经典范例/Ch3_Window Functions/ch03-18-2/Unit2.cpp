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
//设置旋转文字的角度范围
ScrollBar1->Max = 360;
ScrollBar1->Min = 0;
ScrollBar1->Position = 0;
//设置旋转文字背景的透明化
CheckBox1->Checked = false;
//设置旋转文字的尺寸、字型
Canvas->Font->Size = 24;
Canvas->Font->Name = "Arial";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
//简化后面程序代码的视觉复杂度
int pos = ScrollBar1->Position;
//切换旋转文字色彩与背景色彩
if(CheckBox1->Checked)
  {
  Canvas->Font->Color = (TColor)RGB(pos-255,240-pos,pos/2);
  Canvas->Brush->Style = bsClear;
  }
else
  {
  Canvas->Font->Color = (TColor)RGB(pos-255,255-pos,pos/3);
  Canvas->Brush->Color = (TColor)RGB(pos-255,pos/2,240-pos);
  Canvas->Brush->Style = bsSolid;
  }
//删除Form1上残留图像
Refresh();
//取得Form1字型数据，并重设其字型数据
LOGFONT f;
::GetObject(Canvas->Font->Handle, sizeof (LOGFONT), &f);
f.lfEscapement = ScrollBar1->Position*10;
f.lfOrientation = ScrollBar1->Position*10;
f.lfOutPrecision = OUT_TT_ONLY_PRECIS;
Canvas->Font->Handle = ::CreateFontIndirect (&f);
//取得Form1范围尺寸
RECT r;
::GetClientRect(Handle,&r);
//将旋转文字绘制到Form1上
Canvas->TextOut(r.right/5*2, r.bottom/5*2, Edit1->Text.c_str());
}
//---------------------------------------------------------------------------


