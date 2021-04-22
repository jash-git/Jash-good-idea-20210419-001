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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//先将鼠标变成漏斗图标
Screen->Cursor = crHourGlass;
//运用STARTUPINFO结构，设置将要打开程序的显示状态
STARTUPINFO start;
start.cb = sizeof(STARTUPINFO);
start.lpReserved = 0;//设为NULL，方使用CreateProcess
start.lpDesktop = 0;
start.lpTitle = 0;
start.dwX = Screen->Width/2;
start.dwY = Screen->Height/2;
start.dwXSize = Screen->Width/2;
start.dwYSize = Screen->Height/2;
//使用这结构设置的位置与大小
start.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
start.cbReserved2 = 0;//必为NULL
start.lpReserved2 = 0;//必为NULL
//先锁住桌面画面更新动作
::LockWindowUpdate(::GetDesktopWindow());
//将由CreateProcess函数填满此过程信息结构
PROCESS_INFORMATION ProcessInfo;
//创造一基本单纯的行程，打开指定程序
::CreateProcess(0, "NotePad.exe", 0, 0, false,
                CREATE_DEFAULT_ERROR_MODE, 0, 0,
                &start,
                &ProcessInfo
                );
//在行程进行中，让user在5秒中输入信息
::WaitForInputIdle(ProcessInfo.hProcess, 5000);
//完成打开程序后，寻找打开的<记事本>程序
HWND hWnd = ::FindWindow("记事本", 0);
//若存在此窗口，则带到最前面
if(::IsWindow(hWnd))
   ::SetForegroundWindow(hWnd);
//恢复桌面画面更新操作
::LockWindowUpdate(NULL);
//恢复鼠标为默认箭头图标
Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
