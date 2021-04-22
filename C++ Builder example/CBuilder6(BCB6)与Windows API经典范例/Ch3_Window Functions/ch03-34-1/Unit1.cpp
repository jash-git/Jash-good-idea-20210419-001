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
{//将Form1的handle指派给首次循环
hWnd = Handle;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//清空Memo1字符串
Memo1->Text = "";
//若handle是窗口型态，则执行递圈
while(::IsWindow(hWnd))
  {
  //取得下一顺位的窗口handle
  hWnd = ::GetNextWindow(hWnd,GW_HWNDNEXT);
  //若可取得标题字符串，则通过
  if(::GetWindowTextLength(hWnd))
    {
    char str[256];
    //取得窗口标题字符串
    ::GetWindowText(hWnd, str,
                    ::GetWindowTextLength(hWnd)+1);
    //判断此窗口的字符类型
    if(::IsWindowUnicode(hWnd))
       Memo1->Lines->Add(AnsiString(str) + "_是Unicode字符类型");
    else
       Memo1->Lines->Add(AnsiString(str) + "_是ANSI-ASCII字符类型");
    }
  }
}
//---------------------------------------------------------------------------
