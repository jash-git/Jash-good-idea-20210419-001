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
//默认定时器停止
Button1->Caption = "停止";
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
//由按钮次数切换定时器运作
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled = !Timer1->Enabled;
if(Button1->Caption=="停止")Button1->Caption ="开始";
else Button1->Caption="停止";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//当定时器执行时，任何程序在最前面执行，都被放大至全屏幕
::ShowWindow(::GetForegroundWindow(), SW_MAXIMIZE );
//当定时器执行时，任何程序在最前面执行，标题都改成新标题
HWND focusWindow = ::GetForegroundWindow();
if(!::IsWindow(focusWindow)) return;
::SetWindowText( focusWindow,
               " 这是改变标题的恶作剧"
               );
}
//---------------------------------------------------------------------------

