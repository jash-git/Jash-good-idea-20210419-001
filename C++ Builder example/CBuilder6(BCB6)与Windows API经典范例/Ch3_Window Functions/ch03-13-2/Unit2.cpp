//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//自定义的callback函数---------------------------------------------------------
BOOL CALLBACK HuntWinClock(HWND, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//默认2个按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//隐藏快捷工具栏上的时间显示
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//取得快捷工具栏的handle
HWND HtrayWin = ::FindWindow("Shell_TrayWnd", NULL);
//若没找到快捷工具栏，则出现告知信息&停止执行
if(!::IsWindow(HtrayWin))
  {
  Caption = "你的窗口中没有快捷工具栏？";
  return;
  }
//逐一搜寻快捷工具列下的时间显示，并通知隐藏显示计时
::EnumChildWindows(
    HtrayWin,
    reinterpret_cast <WNDENUMPROC> (HuntWinClock),
    SW_HIDE
    );
//设置2个按钮状态
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//重显快捷工具栏上的时间显示
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//取得快捷工具栏的handle
HWND HtrayWin = ::FindWindow("Shell_TrayWnd", NULL);
//若没找到快捷工具栏，则出现告知信息&停止执行
if(!::IsWindow(HtrayWin))
  {
  Caption = "你的窗口中没有快捷工具栏？";
  return;
  }
//逐一搜寻快捷工具栏下的时间显示，并通知重新显示计时
::EnumChildWindows(
    HtrayWin,
    reinterpret_cast <WNDENUMPROC> (HuntWinClock),
    SW_RESTORE
    );
//设置2个按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//自定义的callback函数
BOOL CALLBACK HuntWinClock( HWND HWin, LPARAM FlagSet)
{
//取得传入handle的类名称
char className[256];
::GetClassName(HWin, className, sizeof(className));
//若是时间显示的类别名称，则设置指定旗标
if(lstrcmp(className, "TrayClockWClass") == 0)
   {
   ::ShowWindow(HWin, static_cast <int> (FlagSet));
   return FALSE;
   }
//若非时间显示的类名称，则继续下一handle传入
return TRUE;
}
//---------------------------------------------------------------------------
