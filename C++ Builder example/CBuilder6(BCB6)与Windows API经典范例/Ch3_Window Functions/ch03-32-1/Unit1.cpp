//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//默认快捷键信息常数值---------------------------------------------------------
const int WM_SELFHOTKEY = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//给这个线程登录快捷键
::RegisterHotKey(Handle, WM_SELFHOTKEY, MOD_CONTROL, VK_F2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//释放此线程登录之快捷键
::UnregisterHotKey(Handle, WM_SELFHOTKEY);
}
//---------------------------------------------------------------------------
//捕捉自定义快捷键信息
void __fastcall TForm1::HotKeys(TWMHotKey &Msg)
{
//将信息分流到其它处理函数
TForm::Dispatch(&Msg);
//捕捉到自定义快捷键信息Crtl+F2键
if(Msg.HotKey == WM_SELFHOTKEY)
  {//判断是否为最小化窗口，则显示或缩小窗口
  if(::IsIconic(Application->Handle))
     ::ShowWindow(Application->Handle, SW_RESTORE);
  else
     ::ShowWindow(Application->Handle, SW_MINIMIZE);
  }
}
//---------------------------------------------------------------------------
