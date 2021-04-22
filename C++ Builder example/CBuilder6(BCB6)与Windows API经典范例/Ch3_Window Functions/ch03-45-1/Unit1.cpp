//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//设置调用本程序热键信息-----------------------------------------------------
const int CALL_ME_ID = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//程序启动时，即注册Crtl+F2热键
::RegisterHotKey(Handle, CALL_ME_ID, MOD_CONTROL, VK_F2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//将在快捷工具列上的Project1隐藏
::ShowWindow(Application->Handle,SW_HIDE);
//再将Project1具有POP性质的子窗口全部隐藏起来(如Form1)
::ShowOwnedPopups(Application->Handle,false);
}
//---------------------------------------------------------------------------
//程序关闭时，即释放Crtl+F2快捷键与删除动态文字对象
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
::UnregisterHotKey(Handle, CALL_ME_ID);
}
//---------------------------------------------------------------------------
//捕捉Crtl+F2快捷键送出的自定义信息
void __fastcall TForm1::WMHotKey(TMessage &Msg)
{
//先将信息依默认处理
TForm::Dispatch(&Msg);
//运用快捷键，显示Project1与Form1
::ShowWindow(Application->Handle, SW_SHOW);
::ShowWindow(Handle, SW_SHOW);
}
//---------------------------------------------------------------------------


