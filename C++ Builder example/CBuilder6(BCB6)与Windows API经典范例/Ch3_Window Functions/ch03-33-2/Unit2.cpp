//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//与Project2a.exe设置相同的自定义信息------------------------------------------
static const UINT WM_TWOWINMSG = WM_APP + 0x750;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
HWND secWin = NULL;
//找寻到打开的Project2a.exe
secWin = ::FindWindow(0, "自动捕捉Form1传送的信息");
if(secWin)
  {//若Project2a.exe缩小在快捷工具栏上，则显现
  if(!::IsWindow(secWin))
     ::ShowWindow(secWin, SW_SHOWNORMAL);
  //送出自定义信息给Project2a.exe
  PostMessage(secWin, WM_TWOWINMSG,
              (WPARAM) 1234,//此为最单纯的数字信息
              (LPARAM) 4321 //此为最单纯的数字信息
              );
  }
else
  {
  ShowMessage("请将Project2a.exe程序打开，以利两程序间的信息传递");
  }
}
//---------------------------------------------------------------------------
