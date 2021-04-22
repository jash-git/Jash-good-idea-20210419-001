//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//自定义的WM_HOTKEY快捷键信息----------------------------------------------------
const int WM_MYID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//登录Crtl+F1快捷键，可调用Form1执行快捷键功能
::RegisterHotKey(Handle, WM_MYID, MOD_CONTROL, VK_F1);
Label1->Tag = 1;//运用闲置属性，作为递增变量
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//程序结束时，解除Crtl+F1快捷键功能
::UnregisterHotKey(Handle, WM_MYID);
}
//---------------------------------------------------------------------------
//捕捉自定义的WM_HOTKEY快捷键信息，缩小或回复窗口位置
void __fastcall TForm1::WMHotKey(TMessage &Msg)
{//将缩小窗口回复原来位置
if(::OpenIcon(Handle))
  Label1->Caption = "嗨！第"+AnsiString(++(Label1->Tag))+"次见面了。";
else
   ::ShowWindow(Handle, SW_MINIMIZE );
//将信息依默认处理
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
