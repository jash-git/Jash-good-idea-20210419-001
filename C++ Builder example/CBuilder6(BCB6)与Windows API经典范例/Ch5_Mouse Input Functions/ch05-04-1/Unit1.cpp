//---------------------------------------------------------------------------
//目的：设置键盘组合键，即将鼠标移至指定位置，并仿真单击鼠标左键执行功能
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//将 VK_W 定义成 W 键值------------------------------------------------------
#define VK_W 0x57
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//删除Memo1中文字
Memo1->Text = "";
//在Memo1中新建150行文字
char a[26];
for(int x=65;x<91;x++)
    a[x-65] = char(x);
for(int i=1; i<151; i++)
    Memo1->Lines->Add("第 "+AnsiString(i)+" 行_ "+AnsiString(a));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
//当组合键相等于Ctrl+W 键是单击状态
//则可进行相关功能改变
if(::GetKeyState(VK_CONTROL) && ::GetKeyState(VK_W))
  {
  //将鼠标移至Memo1的右下角ScrollBar位置
  POINT p = { Memo1->Left+Memo1->Width-10, Memo1->Top+Memo1->Height-10};
  p = ClientToScreen(p);
  ::SetCursorPos(p.x,p.y);
  //仿真单击鼠标左键一次
  ::mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );
  ::mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
  }
}
//---------------------------------------------------------------------------
