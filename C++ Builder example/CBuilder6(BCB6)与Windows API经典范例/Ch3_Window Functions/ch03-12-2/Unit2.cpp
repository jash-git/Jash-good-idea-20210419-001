//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-----取得子窗口的标准callback函数------------------------------------------
BOOL CALLBACK EnumChildProc(HWND, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除Memo1所有文字
Memo1->Clear();
//搜寻此窗口下的子窗口及对象handle
::EnumChildWindows(
      Handle,
      reinterpret_cast <WNDENUMPROC> (EnumChildProc),
      0L
      );
}
//---------------------------------------------------------------------------
//将所有次一层子窗口都扫描过为止
BOOL CALLBACK EnumChildProc(HWND HWin, LPARAM)
{
char className[256], WinText[256];
//取得现窗口handle的类别名称
::GetClassName(HWin, className, sizeof(className));
//取得现窗口的标题文字or内含文字
::GetWindowText(HWin, WinText, sizeof(WinText));
//由Memo1显示出来
Form1->Memo1->Lines->Add("类别："+AnsiString(className));
Form1->Memo1->Lines->Add("内容："+AnsiString(WinText));
Form1->Memo1->Lines->Add("--------------------");
//执行扫描正常
return TRUE;
}
//---------------------------------------------------------------------------
