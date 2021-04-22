//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
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
//Form1背景变成淡紫色
Color = (TColor)RGB(230,140,255);
//自定义函数--移动鼠标到特定位置
CursorPos(Handle);
}
//---------------------------------------------------------------------------
void TForm1::CursorPos(HWND hwnd)
{
RECT r;
//取得按钮范围数据
::GetWindowRect(::GetWindow(hwnd,GW_CHILD), &r);
//移动鼠标到特定位置
::SetCursorPos(r.left+4,(r.bottom+r.top)/2);
}
//---------------------------------------------------------------------------
