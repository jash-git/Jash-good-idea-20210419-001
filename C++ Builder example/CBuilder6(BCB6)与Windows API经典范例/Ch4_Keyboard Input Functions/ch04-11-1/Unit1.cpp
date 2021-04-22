//---------------------------------------------------------------------------
//目的：判断指定窗口是否运行中，再赋予致能或失效状态
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
{//取得Memo1的handle
HWND hWnd = Memo1->Handle;
//判断指定窗口是否运作中，再赋予致能或失效状态
(::IsWindowEnabled(hWnd))?(::EnableWindow(hWnd,false)):
                          (::EnableWindow(hWnd,true));
}
//---------------------------------------------------------------------------

