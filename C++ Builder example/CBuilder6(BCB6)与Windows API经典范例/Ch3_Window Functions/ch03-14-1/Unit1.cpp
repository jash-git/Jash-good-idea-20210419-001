//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
//取得子窗口的callback函数---------------------------------------------------
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除Memo1所有文字
Memo1->Clear();
//逐一搜寻经过所有窗口handle
::EnumWindows(
  reinterpret_cast <WNDENUMPROC> (EnumWindowsProc),
  reinterpret_cast <LPARAM> (Memo1)
  );
}
//---------------------------------------------------------------------------
//设置此扫描子窗口调用自己，将所有次一层子窗口都扫描过为止
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
//取得现窗口的内含文字
char buf[256];
::GetWindowText(hwnd, buf, sizeof(buf));

if(TMemo* memo = reinterpret_cast <TMemo*> (lParam))
if (strlen(buf) > 0)
      memo->Lines->Add(buf);
//返回真值，告知执行下次handle扫描    
return TRUE;
}
//---------------------------------------------------------------------------

