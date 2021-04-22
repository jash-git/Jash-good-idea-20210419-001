//---------------------------------------------------------------------------
//目的：切换隐藏或显现不同线程指定窗口显示状态，NT多任务环境最为适宜
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
{//运用闲置属性，作为布尔值
Button1->Default = false;
}
//---------------------------------------------------------------------------
//当程序关闭时，确认恢复快捷工具列与桌面快捷方式图示原貌
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//单击按钮，切换隐藏或显示在快捷工具列上的Project1母窗口
if(Button1->Default)
   ::ShowWindowAsync(Application->Handle, SW_RESTORE);
else
   ::ShowWindowAsync(Application->Handle, SW_HIDE);
//切换布尔值
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
