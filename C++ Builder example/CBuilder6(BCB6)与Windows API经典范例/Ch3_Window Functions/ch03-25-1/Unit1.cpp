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
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//寻找到快捷工具栏与程序管理员的handle
HWND HTaskBar = ::FindWindow("Shell_TrayWnd", NULL);
HWND HDeskLV = ::FindWindow("ProgMan",NULL);
//取得handle的子窗口handle
HTaskBar = ::GetWindow(HTaskBar, GW_CHILD);
HDeskLV = ::GetWindow(HDeskLV, GW_CHILD);
HDeskLV = ::GetWindow(HDeskLV, GW_CHILD);
//将快捷工具栏隐藏与显示，达到重绘更新目的
::ShowWindow(HTaskBar, SW_HIDE);
::ShowWindow(HTaskBar, SW_SHOW);
//取得程序管理员范围与送出更新信息，达到重绘更新目的
::InvalidateRect(HDeskLV, NULL, true);
//仍由Form1取得焦点
::SetFocus(Handle);
}
//---------------------------------------------------------------------------
