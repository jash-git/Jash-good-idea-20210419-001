//---------------------------------------------------------------------------
//挂上、卸下Keyboard hook，并运用自定义信息传递Hook数据
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKeyHookForm *KeyHookForm;
//---------------------------------------------------------------------------
__fastcall TKeyHookForm::TKeyHookForm(TComponent* Owner)
        : TForm(Owner)
{
inthook = 0;//计算按键次数变量归零
//将KeyHookForm维持在窗口最上面
FormStyle = fsStayOnTop;
//挂上和卸下Hook的按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//挂上Hook链，并设置定时器从共享内存中取回键盘信息
void __fastcall TKeyHookForm::Button1Click(TObject *Sender)
{
//计算按键次数变量归零
inthook = 0;
//在keydll.dll中，SetHook函数执行注册Hook行程到信息链中
//先声明有一SetHook函数
void (*SetHook)();
//加载同一目录下的指定连接文件--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//取得dll中SetHook函数地址
(FARPROC &)SetHook = ::GetProcAddress(inst,"SetHook");
//执行指向dll中的SetHook函数
SetHook();
//挂上和卸下Hook的按钮状态
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//卸下Hook链，解除自定义的hook
void __fastcall TKeyHookForm::Button2Click(TObject *Sender)
{
//在keydll.dll中，RemoveHook函数执行从信息链中卸下Hook进程
//声明RemoveHook函数
void (*RemoveHook)();
//加载同一目录下的指定连接文件--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//取得dll中RemoveHook函数地址
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//执行指向dll中的RemoveHook函数
RemoveHook();
//释放dll
::FreeLibrary(inst);
//挂上和卸下Hook的按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//预防用户结束Hook时未卸下Hook链
void __fastcall TKeyHookForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//在keydll.dll中，RemoveHook函数执行从信息链中卸下Hook行程
//先声明RemoveHook函数
void (*RemoveHook)();
//载入dll
inst = ::LoadLibrary("keydll.dll");
//取得dll中RemoveHook函数地址
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//执行指向dll中的RemoveHook函数
RemoveHook();
//释放dll
::FreeLibrary(inst);
}
//---------------------------------------------------------------------------
//取得拦截自键盘中的自定义信息
void __fastcall TKeyHookForm::KeyHook(TMessage &Msg)
{
//取得自定义信息中的按键名称
char keytext[80];
::GetKeyNameText(Msg.LParam, keytext, 80);
//取得自定义信息中的按键状态(检测用..意义不大...)
AnsiString keystate;
keystate = ::GetKeyState((int)Msg.WParam);
keystate = (keystate == "1")?"单击":"浮起";//C++的三元运算

//由ListBox组件显示拦截成果
ListBox1->Items->Insert(0,
                        "第 "+AnsiString(++inthook) + " 按键__" +
                        AnsiString(keytext)+ " ：状态>>" + keystate
                        );
}
//---------------------------------------------------------------------------

