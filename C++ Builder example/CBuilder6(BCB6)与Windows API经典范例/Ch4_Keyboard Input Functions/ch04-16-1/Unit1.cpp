//---------------------------------------------------------------------------
//目的：向系统登录自定义热键，单击Ctrl+F1 键，即可调用程序执行功能
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//默认热键信息常数值---------------------------------------------------------
const int ID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//给这个线程登录热键
//当此程序打开状态，而焦点在另一程序，
//单击Ctrl+F1 键，即可调用此程序取得焦点，并显现至最前面
::RegisterHotKey(Handle, ID, MOD_CONTROL, VK_F1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{//释放此线程登录之热键
::UnregisterHotKey(Handle, ID);
}
//---------------------------------------------------------------------------
//捕捉自定义热键信息
void __fastcall TForm1::HotKeys(TMessage &Msg)
{//将信息分流至其他处理函数
TForm::Dispatch(&Msg);
//若此程序已打开，但在后面；即提至最前面
::SetForegroundWindow(Handle);
//若此程序是缩小化状态，则恢复原来状态
if (::IsIconic(Application->Handle))
   ::ShowWindow(Application->Handle, SW_RESTORE);
else
   ::ShowWindow(Application->Handle, SW_MINIMIZE);
}
//---------------------------------------------------------------------------

