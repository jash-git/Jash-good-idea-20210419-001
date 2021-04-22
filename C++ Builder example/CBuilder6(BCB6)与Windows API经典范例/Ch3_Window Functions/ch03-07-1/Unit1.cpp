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
//由类寻找Form1，并返回其handle
HWND hWnd = ::FindWindow("TForm1",0);
//将Form1窗口最小化，缩小Form1到屏幕左下角
::CloseWindow(hWnd);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//将焦点交给下一顺位程序，Form1缩至快捷工具栏中
::CloseWindow(::GetWindow( Handle,GW_HWNDNEXT));
}
//---------------------------------------------------------------------------
