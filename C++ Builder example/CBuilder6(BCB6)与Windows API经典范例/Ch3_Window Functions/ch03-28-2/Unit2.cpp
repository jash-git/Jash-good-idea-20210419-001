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
//将Form1上所有按钮，都等同于Form1的OnMouseMove事件
for(int i=0;i<ComponentCount; i++)
   {
   TButton *btn = (TButton *)Components[i];
   btn->OnMouseMove = Form1->OnMouseMove;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
POINT P;
char str[256];
//取得现在鼠标所在的位置
::GetCursorPos(&P);
//取得鼠标位置的窗口handle
HWND hWnd = ::WindowFromPoint(P);
if(hWnd)
  {//此窗口即取得焦点与显示其标题字符串
  ::SetFocus(hWnd);
  ::GetWindowText(hWnd,str,256);
  Caption = "现在是_"+AnsiString(str)+"_取得焦点";
  }
}
//---------------------------------------------------------------------------

