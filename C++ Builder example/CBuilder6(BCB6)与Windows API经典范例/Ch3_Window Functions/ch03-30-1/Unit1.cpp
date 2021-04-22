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
//搜寻<记事本>是否打开
HWND hNpad = ::FindWindow(NULL, "未命名 - 记事本");
//若<记事本>在打开中，即带到最前面
if(::ShowWindow(hNpad,SW_SHOWNORMAL))
   {
   ::BringWindowToTop(hNpad);
   }
else //若没打开，则打开<记事本>
   {
   //取得Window目录位置
   char WinDir[MAX_PATH];
   ::GetWindowsDirectory(WinDir, MAX_PATH);
   AnsiString sysdir = AnsiString(WinDir) + "\\Notepad.exe";
   //打开<记事本>
   ::ShellExecute(NULL,"open",sysdir.c_str(),NULL,NULL,SW_SHOWNORMAL);
   //再次找到<记事本>窗口
   hNpad = ::FindWindow(NULL, "未命名 - 记事本");
   }
//进行自定义函数
if(VaultWindowThreadID(hNpad))
  Memo1->Text = "完成在不同线程行程间的窗口取得焦点。";
else
  Memo1->Text = "请在打开<记事本>后，再执行本程序。";
}
//---------------------------------------------------------------------------
//在不同线程行程间的窗口取得焦点
bool TForm1::VaultWindowThreadID(HWND hWnd)
{
bool Result;
DWORD fWinThreadID;
DWORD winThreadID;
//若传入的窗口handle等同于现在最前面窗口handle
if(hWnd == ::GetForegroundWindow())
   Result = true;
else
   {//取得现在最前面窗口的线程代码ID
   fWinThreadID =
      ::GetWindowThreadProcessId(::GetForegroundWindow(), NULL);
   //取得现在窗口的线程ID
   winThreadID = ::GetWindowThreadProcessId(hWnd, NULL);
   if(fWinThreadID != winThreadID)
      {//若两者不同，则跳至现在线程的窗口，并移动至最前面
      ::AttachThreadInput(fWinThreadID, winThreadID, true);
      Result = ::SetForegroundWindow(hWnd);//true
      //再解开此二者不同线程的关联
      ::AttachThreadInput(fWinThreadID, winThreadID, false);
      }
   else//若相同，则直接将此窗口提至最前面
      Result = ::SetForegroundWindow(hWnd);
   //显现窗口到桌面上
   ::ShowWindow(hWnd, SW_RESTORE);
   return Result;
   }
return Result;
}
//---------------------------------------------------------------------------
