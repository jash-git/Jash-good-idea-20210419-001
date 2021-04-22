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
//默认按钮为可执行状态
Button1->Default = true;
Button2->Default = true;
//程序开始时，先取得快捷工具栏handle
hTaskbarWnd = ::FindWindow("Shell_TrayWnd", NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(Button1->Default)//隐藏快捷工具栏
   ::ShowWindow(hTaskbarWnd, SW_HIDE);
else //显现快捷工具栏
   ShowWindow(hTaskbarWnd, SW_SHOW);
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//取得程序管理员handle，再取得第二层子窗口handle
//第二层子窗口handle，即是桌面handle
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
//运用按钮，切换隐藏或显示桌面图示
if(Button2->Default)
   ::ShowWindow(hwnd, SW_HIDE);
else
   ::ShowWindow(hwnd, SW_SHOW);
Button2->Default = !Button2->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//防范用户忘记还原原有窗口环境
//显现桌面图示
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
::ShowWindow(hwnd, SW_SHOW);
//显现快捷工具栏
::ShowWindow(hTaskbarWnd, SW_SHOW);
}
//---------------------------------------------------------------------------
