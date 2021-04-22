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
//控制拖曳时的状态
FDragging = false;
//默认ImageList1图像出现的位置
DrawP = Point(ClientWidth/2, ClientHeight/3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//在Form1居中绘制显现ImageList1的第一个图像
ImageList1->Draw(Canvas, DrawP.x, DrawP.y, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
//当鼠标在ImageList1图像范围内，单击左键
if (X > DrawP.x && X < DrawP.x + ImageList1->Width &&
     Y > DrawP.y && Y < DrawP.y + ImageList1->Height)
   {
   ClickP = ClientToScreen(Point(X, Y));
   //暂时锁住窗口更新动作
   ::LockWindowUpdate(::GetDesktopWindow());
   //允许拖曳ImageList1图像
   ImageList1->SetDragImage(0, X-DrawP.x, Y-DrawP.y);
   //开始拖曳ImageList1图像
   ImageList1->BeginDrag(::GetDesktopWindow(),
                         ClickP.x, ClickP.y);
   //启动OnMouseMove事件
   FDragging = true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
if(FDragging)
  {
  //鼠标与图像相对的移动
  TPoint P = ClientToScreen(Point(X, Y));
  ImageList1->DragMove(P.x, P.y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(FDragging)
  {
  //放开鼠标左键时，即结束拖曳，并允许更新窗口
  ImageList1->EndDrag();
  ::LockWindowUpdate(NULL);

  //再更新鼠标最后移动的新位置，
  //并指派给下次拖曳时的开始位置
  TPoint P = ClientToScreen(Point(X, Y));
  DrawP.x = DrawP.x + (P.x - ClickP.x);
  DrawP.y = DrawP.y + (P.y - ClickP.y);
  Refresh();
  FDragging = false;
  }
}
//---------------------------------------------------------------------------

