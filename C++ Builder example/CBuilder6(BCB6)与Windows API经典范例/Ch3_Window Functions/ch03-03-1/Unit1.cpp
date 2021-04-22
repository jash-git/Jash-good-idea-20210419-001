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
//在已打开程序中寻找<记事本>程序
HWND Notepad = ::FindWindow("NotePad", NULL);
//若<记事本>在打开中，即带到最前面
if(::ShowWindow(Notepad,SW_SHOWNORMAL))
   {
   //确认<记事本>被调用至最前面&取得焦点
   ::BringWindowToTop(Notepad);
   //仿真键盘键入，将一串字符串送到<记事本>中
   String Text("WELCOME TO NOTEPAD");
   for(int x = 1; x <= Text.Length(); x++)
      {
      keybd_event(Text[x], 0, 0, 0);
      keybd_event(Text[x], 0, KEYEVENTF_KEYUP, 0);
      }
   //在<记事本>中，跳到下一行
   keybd_event(VK_RETURN, 0, 0, 0);
   keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
   }
else
   ShowMessage("抱歉！请先打开<记事本>，\n这只是个功能简单的小程序。");
}
//---------------------------------------------------------------------------

