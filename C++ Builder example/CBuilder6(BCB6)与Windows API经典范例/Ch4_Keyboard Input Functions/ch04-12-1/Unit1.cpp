//---------------------------------------------------------------------------
//目的：打开另一程序，并仿真键盘输入多行字符串
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
//搜寻<记事本>有无打开
HWND Npad = ::FindWindow(NULL, "未命名 - 记事本");
//璝<癘ㄆセ>秨币い盿程玡
if(::ShowWindow(Npad,SW_SHOWNORMAL))
   {
   ::BringWindowToTop(Npad);
   }
else //若没打开，则打开<记事本>
   {
   //取得Window目录位置
   char WinDir[MAX_PATH];
   ::GetWindowsDirectory(WinDir, MAX_PATH);
   AnsiString sysdir = AnsiString(WinDir) + "\\Notepad.exe";
   //打开<记事本>
   ::ShellExecute(NULL,"open",sysdir.c_str(),NULL,NULL,SW_SHOWNORMAL);
   }
//完全打开<记事本>后，才送出特定文字
Sleep(100);
int x=0;
while(x<10)
   {
   for(int i = 'A'; i <= 'Z'; i++)
      {
      //从 a 至 z
      keybd_event((char)i, 0, 0, 0);
      keybd_event((char)i, 0, KEYEVENTF_KEYUP, 0);
      //从 ! 至 )
      int c = x + '0';
      keybd_event(VK_SHIFT, 0, 0, 0);
      keybd_event((char)c, 0, 0, 0);
      keybd_event((char)c, 0, KEYEVENTF_KEYUP, 0);
      keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
      }
   //每完成A至Z 一次循环，则换新一行
   keybd_event(VK_RETURN, 0, 0, 0);
   keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
   x++;
   }
}
//---------------------------------------------------------------------------
