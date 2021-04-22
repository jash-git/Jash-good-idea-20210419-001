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
for(int i=1;i<16;i++)
  {
  //取得下一顺位的窗口handle
  hWnd = ::GetNextWindow(hWnd,GW_HWNDNEXT);
  char str[256];
  //取得窗口标题字符串
  ::GetWindowText(hWnd, str,
                  ::GetWindowTextLength(hWnd)+1);
  Memo1->Lines->Add("取得第" + AnsiString(i) +
                    "顺位的窗口标题字符串：" + AnsiString(str));
  }
}
//---------------------------------------------------------------------------
