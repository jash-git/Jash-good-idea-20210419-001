//---------------------------------------------------------------------------
//目的：取得现在线程的执行窗口
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
//取得现在线程的执行窗口，若放在dll中，较有意义
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//取得现在线程的执行窗口
HWND aWin = ::GetActiveWindow();
if(aWin)
   {
   char str[256];
   //取得现在线程的执行窗口名称
   ::GetWindowText(aWin,str,256);
   Memo1->Lines->Add("现在线程的执行窗口：" + AnsiString(str));
   //取得现在线程的执行窗口类型名称
   ::GetClassName(aWin,str,256);
   Memo1->Lines->Add("执行窗口的类型：" + AnsiString(str));
   }
else
   Memo1->Lines->Add("找不到现在线程的窗口？这是不可能的事情。");
}
//---------------------------------------------------------------------------
