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
char scrt[MAX_PATH];
//从系统文件中取得特定字符串，判断屏幕保护程序是否已经设置
DWORD res = ::GetPrivateProfileString("boot",
                         "SCRNSAVE.EXE","",scrt,MAX_PATH,
                         "system.ini");
if(res==0 || strcmp(scrt,"")==0)
  ShowMessage("这个屏幕没设置\n屏幕保护画面。");
else
  {
  //由判断系统，尝试捕捉屏幕保护程序handle
  if (ScreensaverNTor95()) return;
  //取得最前面窗口handle，送出启动屏幕保护程序信息
  HWND hfw = ::GetForegroundWindow();
  if(hfw==NULL)
    DefWindowProc(Handle,WM_SYSCOMMAND,SC_SCREENSAVE,0);
  else
    PostMessage(hfw,WM_SYSCOMMAND,SC_SCREENSAVE,0);
  }
}
//---------------------------------------------------------------------------
//由判断系统，尝试捕捉屏幕保护程序handle--自定义函数
BOOL TForm1::ScreensaverNTor95()
{
BOOL isNT;
//取得窗口系统信息，判断是否为NT
OSVERSIONINFO ovi;
ovi.dwOSVersionInfoSize=sizeof(ovi);
::GetVersionEx(&ovi);
if(ovi.dwPlatformId==VER_PLATFORM_WIN32_NT) isNT=TRUE;
else isNT=FALSE;
//若非NT，则取得屏幕保护程序的信息，
//判断屏幕保护程序可否执行，返回真伪值
if(!isNT)
  {
  UINT srunning=0,dummy;
  ::SystemParametersInfo(SPI_SCREENSAVERRUNNING,0,&srunning,0);
  ::SystemParametersInfo(SPI_SCREENSAVERRUNNING,srunning,&dummy,0);
  if (srunning==0) return FALSE;
  else return TRUE;
  }
//若为NT，则因NT是多绪系统，屏幕保护程序可能正在另一绪执行中
//再尝试取得屏幕保护程序handle
HWND hfw = ::GetForegroundWindow();
if (hfw==NULL) return TRUE;
LONG style = ::GetWindowLong(hfw,GWL_STYLE);
//若式样非POP型式或显示中，则非屏幕保护程序handle，返回伪值
if ((style & 0xF0000000)!= (WS_POPUP|WS_VISIBLE)) return FALSE;
//若此handle不符合全屏幕，则非屏幕保护程序handle，返回伪值
RECT rc;
::GetWindowRect(hfw,&rc);
if (rc.right-rc.left != ::GetSystemMetrics(SM_CXSCREEN) ||
    rc.bottom-rc.top != ::GetSystemMetrics(SM_CYSCREEN))
    return FALSE;
return TRUE;
}
//---------------------------------------------------------------------------
