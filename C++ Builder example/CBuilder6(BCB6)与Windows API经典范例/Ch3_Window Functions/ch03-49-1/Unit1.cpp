//---------------------------------------------------------------------------
//目的：由定时器定时检测鼠标屏幕位置，而取得其他程序窗口标题字符串
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
{//将窗口永在桌面最上层与放置于右下角
FormStyle = fsStayOnTop;
Top = Screen->Height-Height;
Left = Screen->Width-Width;
Timer1->Interval = 100; //0.1秒定时器频率
}
//---------------------------------------------------------------------------
//由定时器定时检测鼠标屏幕位置，而取得窗口代码
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
POINT P;
::GetCursorPos(&P);//捕捉鼠标屏幕位置
//取得鼠标位置下窗口handle
HWND HWnd = ::WindowFromPoint(P);
//向此窗口送出"取得标题字符串"信息
char buffer[100];
SendMessage(HWnd, WM_GETTEXT, (WPARAM)100, (LPARAM)buffer);
//显现在Form1窗口的字符串对象上
StaticText2->Caption = buffer;
}
//---------------------------------------------------------------------------
