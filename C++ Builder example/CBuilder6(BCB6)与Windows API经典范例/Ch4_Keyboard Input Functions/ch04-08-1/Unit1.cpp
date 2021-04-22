//---------------------------------------------------------------------------
//目的：取得键盘中指定按键状态并加以控制，用此法仅适用于Win9*系列
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
{//将闲置属性作为bool值
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char key[256];
//取得现在键盘状态
::GetKeyboardState((PBYTE)key);
//改变 NUMLOCK键的真假值，而key[VK_CAPITAL]则是Caps Lock键
key[VK_NUMLOCK] = (BYTE)Button1->Default;
//设置现在键盘状态
::SetKeyboardState((PBYTE)key);
//三元运算--在Memo1中显示Num Lock键状态
(Button1->Default)?(Caption="键盘上Num Lock键<打开中>"):
                   (Caption="键盘上Num Lock键<关闭中>");
//ち传痷安
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------


