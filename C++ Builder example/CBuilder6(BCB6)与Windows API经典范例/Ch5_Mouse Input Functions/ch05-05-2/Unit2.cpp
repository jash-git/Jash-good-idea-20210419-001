//---------------------------------------------------------------------------
//目的：由鼠标右键移动按钮的简易做法
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
{//默认绘制线条宽度与背景颜色
Canvas->Pen->Width = 10;
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//将鼠标锁住指定窗口
::SetCapture(Handle);
//确定线条起始点
pLineHead.x = X; pLineHead.y = Y;
//确认鼠标单击按键，开始绘制线条
bDrawing = true;
//控制鼠标首次绘制线条与后续绘制
bFirstLine = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
if(bDrawing)
  {//设置线条位置改变时，反转先前位置线条痕迹
  Canvas->Pen->Mode = pmNot;
  if(!bFirstLine)//第一次移动后，绘制线条
    {
    Canvas->MoveTo(pLineHead.x, pLineHead.y);
    Canvas->LineTo(pLineTail.x, pLineTail.y);
    }
  //取得鼠标移动时的实时坐标
  pLineTail.x = X; pLineTail.y = Y;
  bFirstLine = false;
  //再绘制移动时线条
  Canvas->MoveTo(pLineHead.x, pLineHead.y);
  Canvas->LineTo(pLineTail.x, pLineTail.y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//当鼠标按键放开时，再绘制最后停住时线条
bDrawing = false;
Canvas->MoveTo(pLineHead.x, pLineHead.y);
Canvas->LineTo(X, Y);
//释放被捕捉到的窗口，则重绘窗口，删除窗口上线条
::ReleaseCapture();
}
//---------------------------------------------------------------------------

