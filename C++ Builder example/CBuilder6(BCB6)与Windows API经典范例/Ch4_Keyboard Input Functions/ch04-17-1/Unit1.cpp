//---------------------------------------------------------------------------
//目的：重设键盘中指定按键状态，此法仅适用于Win9*
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
//默认CheckBox1为未选取状态
CheckBox1->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
Memo1->Text = "";//清空Memo1所有文字
//取得现在键盘状态
::GetKeyboardState((PBYTE)key);
//三元运算--判断键盘特定按键值，并显现出来
str=((bool)key[VK_NUMLOCK])?"Num Lock执行中":"Num Lock关闭中";
Memo1->Lines->Add(str);
str=((bool)key[VK_CAPITAL])?"Caps Lock执行中":"Caps Lock关闭中";
Memo1->Lines->Add(str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//改变 NUMLOCK键的真假值
//key[VK_NUMLOCK]即是Num Lock键
key[VK_NUMLOCK] = (BYTE)Button1->Default;
//设置现在键盘状态
::SetKeyboardState((PBYTE)key);
//依指定按键状态，修改Memo1字符串
str=((bool)key[VK_NUMLOCK])?"Num Lock执行中":"Num Lock关闭中";
Memo1->Lines->Strings[0] = str;
//切换真假值
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
//改变 Caps Lock键的真假值
key[VK_CAPITAL] = CheckBox1->Checked ? (BYTE) 1 : (BYTE) 0;
//依指定按键状态，修改Memo1字符串
str=((bool)key[VK_CAPITAL])?"Caps Lock执行中":"Caps Lock关闭中";
Memo1->Lines->Strings[1] = str;
//设置现在键盘状态
::SetKeyboardState((PBYTE)key);
}
//---------------------------------------------------------------------------


