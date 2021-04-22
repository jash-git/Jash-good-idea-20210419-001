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
//修改此单字符串窗口组件性质，可自由缩放大小
DWORD dwStyle = ::GetWindowLong(Edit1->Handle, GWL_STYLE);
::SetWindowLong(Edit1->Handle, GWL_STYLE, dwStyle | WS_SIZEBOX);
//修正此单字符串窗口组件在Form1上的实际尺寸与范围
//以便USER直接调整单字符串窗口组件边沿
::MoveWindow(Edit1->Handle, Edit1->Left, Edit1->Top,
             Edit1->Width, Edit1->Height + 1, true);
}
//---------------------------------------------------------------------------
//当鼠标保持箭头图标时，Edit1即可被拖曳
void __fastcall TForm1::Edit1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(Edit1->Cursor == crArrow )
  {//释放原有鼠标捕捉状态，
  //并同时送出鼠标单击位置等同于窗口标题栏可拖曳窗口的属性
  ::ReleaseCapture();
  SNDMSG(Edit1->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{//鼠标在Edit1上移动时，仍保持箭头图标
Edit1->Cursor = crArrow;
}
//---------------------------------------------------------------------------
