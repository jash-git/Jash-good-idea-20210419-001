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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
//取得屏幕的鼠标位置
TPoint p;//等同 POINT p; 结构声明
p.x = 0; p.y = 0;//初值先归零
p = ClientToScreen(p);
//若POP菜单组件是可执行的
if(PopupMenu1)
  {//则先确认Form1在最前面出现
  ::SetForegroundWindow(Handle);
  //在指定位置显示POP菜单组件
  DWORD dwCmd = ::TrackPopupMenu(PopupMenu1->Handle,
                   TPM_LEFTALIGN | TPM_TOPALIGN |
                   TPM_NONOTIFY | TPM_RETURNCMD,
                   p.x-1, p.y+ClientHeight, 0, Handle, NULL);
  //送出NULL信息，暂时排除其余信息
  SNDMSG(Handle, WM_NULL, 0,0);
  //确定已显示POP菜单，则点选其中一选项执行功能
  TMenuItem *Item = PopupMenu1->FindItem(dwCmd, fkCommand);
  if (Item) Item->Click();//引发OnClick事件
  Caption = "Form1在屏幕中相对位置X:"+AnsiString(p.x)+",Y:"+AnsiString(p.y);
  }
}
//---------------------------------------------------------------------------
//粉红色
void __fastcall TForm1::pop011Click(TObject *Sender)
{
Color = (TColor)RGB(255,200,255);
}
//---------------------------------------------------------------------------
//粉蓝色
void __fastcall TForm1::pop021Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,255);
}
//---------------------------------------------------------------------------
//粉绿色
void __fastcall TForm1::pop031Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------

