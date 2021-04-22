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
//确定此窗口在最前面与设置定时器频率
FormStyle = fsStayOnTop;
Timer1->Interval = 200;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
POINT P;
char text[256];
//取得现在鼠标位置
::GetCursorPos(&P);
//取得现在鼠标位置的窗口handle
HWND HWnd = ::WindowFromPoint(P);
//由窗口handle取得标题字符串
::GetWindowText(HWnd, text, 256);
//显示于Memo1上
Memo1->Text = "鼠标所在位置的标题是：" + AnsiString(text);
}
//---------------------------------------------------------------------------
