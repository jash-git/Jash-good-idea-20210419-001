//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
///-关闭屏幕保护程序callback函数----------------------------------------------
BOOL __stdcall CALLBACK KillScreenSaverFunc(HWND, long);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
HDESK hdesk;
//若屏幕保护程序可运行，则对之送出关闭信息
hdesk = ::OpenDesktop("Screen-Saver",
                      DF_ALLOWOTHERACCOUNTHOOK,
                      false,
                      DESKTOP_READOBJECTS | DESKTOP_WRITEOBJECTS);
if(hdesk)
  {//在另一桌面中搜寻屏幕保护程序，并由callback函数送出关闭程序信息
  ::EnumDesktopWindows(hdesk,(WNDENUMPROC)KillScreenSaverFunc, 0);
  //关闭指定桌面线程
  ::CloseDesktop(hdesk);
  Memo1->Text = "在NT多任务环境下，成功完成关闭保护屏幕程序！";
  }
else
  Memo1->Text = "在95,98单工环境下，不能跨多任务关闭保护屏幕程序！";
}
///-关闭屏幕保护程序callback函数----------------------------------------------
BOOL __stdcall CALLBACK KillScreenSaverFunc(HWND hwnd, long lParam)
{//若屏幕保护程序可运行，则对之送出关闭信息
if(::IsWindowVisible(hwnd))
   {
   PostMessage(hwnd, WM_CLOSE, 0, 0);
   return true;
   }
return false;
}
//---------------------------------------------------------------------------

