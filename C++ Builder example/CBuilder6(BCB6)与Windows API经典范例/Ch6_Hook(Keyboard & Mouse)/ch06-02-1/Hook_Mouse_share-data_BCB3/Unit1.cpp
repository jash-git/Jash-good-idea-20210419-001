//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCallHookForm *CallHookForm;
//---------------------------------------------------------------------------
HINSTANCE inst; //指向鼠标hook结构
//存于内存中，dll和exe共享的结构，用于传递捕捉到的hook信息
struct POD
{
char text[256];
//...user可自行扩充此结构成员
} *buf; //指向内存共享区块的指针
HANDLE MapHandle;//共享的内存区块handle
//定时取回鼠标信息
VOID CALLBACK MyTimerProc(HWND,UINT,UINT,DWORD);
//---------------------------------------------------------------------------
__fastcall TCallHookForm::TCallHookForm(TComponent* Owner)
    : TForm(Owner)
{
//创造一共享内存区域
MapHandle = ::CreateFileMapping( (HANDLE)0xffffffff, NULL,
                                 PAGE_READWRITE, 0,
                                 sizeof(POD), "MyMapName" );
//取得内存共享区块位置，转换成可擦写的对象指针
buf = (POD *)::MapViewOfFile( MapHandle, FILE_MAP_READ | FILE_MAP_WRITE,
                              0, 0, 0 );
//if ( ! buf ) return;
//将此共享内存区块（字符串）设为均值，即清理此区块信息
FillMemory(buf->text, sizeof(buf->text), '0');
//挂上和卸下Hook的按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
//将CallHookForm维持在最上面
FormStyle = fsStayOnTop;
}
//---------------------------------------------------------------------------
//挂上Hook链，并设置定时器从共享内存中取回鼠标信息
void __fastcall TCallHookForm::Button1Click(TObject *Sender)
{
//在mydll.dll中，SetHook函数是执行注册Hook进程到信息链中
//先声明有一个SetHook函数
void (*SetHook)();
//加载同一目录下的指定连接文件--mydll.dll
inst = ::LoadLibrary("mydll.dll");
//取得dll中SetHook函数地址
(FARPROC &)SetHook = ::GetProcAddress(inst,"SetHook");
//执行指向dll中的SetHook函数
SetHook();
//设置定时器，每0.5秒从共享内存中取回鼠标信息
timer = ::SetTimer(NULL, 0, 200, (TIMERPROC)MyTimerProc);
//挂上和卸下Hook的按钮状态
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//卸下Hook链，并停止定时器
void __fastcall TCallHookForm::Button2Click(TObject *Sender)
{
//停止定时器运行
::KillTimer(NULL, timer);
//在mydll.dll中，RemoveHook函数是执行从信息链中卸下Hook进程
//声明RemoveHook函数
void (*RemoveHook)();
//加载同一目录下的指定连接文件--mydll.dll
inst = ::LoadLibrary("mydll.dll");
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
//预防用户结束Hook时，未卸下Hook链
void __fastcall TCallHookForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(timer)//停止定时器运行
  ::KillTimer(NULL, timer);

//在mydll.dll中，RemoveHook函数是执行从信息链中卸下Hook进程
//声明RemoveHook函数
void (*RemoveHook)();
//载入dll
inst = ::LoadLibrary("mydll.dll");
//取得dll中RemoveHook函数地址
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//执行指向dll中的RemoveHook函数
RemoveHook();
//释放dll
::FreeLibrary(inst);
//释放内存区块
UnmapViewOfFile((void *)buf);
}
//---------------------------------------------------------------------------
//定时器CALLBACK函数，每0.5秒从共享内存中取回鼠标信息
VOID CALLBACK MyTimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
CallHookForm->Edit1->Text=AnsiString(buf->text);
}
//---------------------------------------------------------------------------
