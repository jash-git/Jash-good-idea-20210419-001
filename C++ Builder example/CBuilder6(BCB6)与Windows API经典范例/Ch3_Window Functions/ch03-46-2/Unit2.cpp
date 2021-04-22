//---------------------------------------------------------------------------
//目的：单击按钮，切换隐藏或显现快捷工具列与现在桌面所有快捷方式图示
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
{//运用闲置属性，作为布尔值
Button1->Default = true;
//取得快捷工具列的handle
hTaskBar = ::FindWindow("Shell_TrayWnd", NULL);
//取得现在桌面管理员的handle
hProgMan = ::FindWindowEx (0, 0, "Progman", 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//当程序关闭时，确认恢复快捷工具列与桌面快捷方式图示原貌
::ShowWindow(hTaskBar, SW_SHOW);
::ShowWindow(hProgMan, SW_SHOW);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//运用三元运算--切换隐藏或显示指定窗口
(Button1->Default)?
(::ShowWindow(hTaskBar, SW_HIDE),::ShowWindow(hProgMan, SW_HIDE)):
(::ShowWindow(hTaskBar, SW_SHOW),::ShowWindow(hProgMan, SW_SHOW));
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

