//---------------------------------------------------------------------------
//目的：按住Image1拖曳时，实际是捕捉到Image1下的动态Panel1对象
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
{//默认背景颜色，以利显示效果
Color = (TColor)RGB(200,255,200);
//给Image1建立一可拖曳的新平台
panel = new TPanel(this);
panel->Parent = Form1;
//panel边框加强
panel->BevelInner = bvLowered;
panel->BevelOuter = bvLowered;
//将新建Panel先隐藏起来
panel->Hide();
//更替panel的 WM_ERASEBKGND 信息处理
OldPanelWP = panel->WindowProc;
panel->WindowProc = NewPanelWP;
}
//---------------------------------------------------------------------------
//当程序被摧毁时，释放panel内存
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
panel->WindowProc = OldPanelWP;
delete panel;
}
//---------------------------------------------------------------------------
//排除WM_ERASEBKGND信息
void __fastcall TForm1::NewPanelWP(TMessage &Msg)
{
if (Msg.Msg != WM_ERASEBKGND)
     OldPanelWP(Msg);
}
//---------------------------------------------------------------------------
//鼠标按住Image1时，即显现panel
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//显现panel
panel->Show();
oldX = X;
oldY = Y;
//设置panel显现状态
panel->Left = Image1->Left-2;
panel->Top = Image1->Top-2;
panel->Height = Image1->Height+4;
panel->Width = Image1->Width+4;
panel->Visible = true;

//当鼠标按住Image1时，实际上是按住panel
::SetCapture(panel->Handle);
Image1->Parent = panel;
Image1->Left = 2;
Image1->Top = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//当鼠标左键按住Image1移动时，实际上是按住panel移动
if (Shift.Contains(ssLeft))
    {
    panel->Left = panel->Left + (X - oldX);
    panel->Top = panel->Top + (Y - oldY);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
//释放panel的鼠标捕捉
::ReleaseCapture();
//隐藏panel在Image1下
panel->Visible = false;
Image1->Left = panel->Left;
Image1->Top = panel->Top;
Image1->Parent = this;
}
//---------------------------------------------------------------------------

