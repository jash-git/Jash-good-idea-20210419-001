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
//默认CheckBox1真伪值
CheckBox1->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除Memo1中文字
Memo1->Clear();
//先取得现程序与下一程序handle
char name[100];
HWND hWnd = ::GetTopWindow(NULL);
HWND hwndNext = ::GetNextWindow(hWnd, GW_HWNDNEXT);
//列出在桌面执行中的窗口
if(CheckBox1->Checked)//CheckBox1选取状态
  {
  while(hwndNext)
   {//若窗口执行中与独立，则取得窗口标题字符串
   if((::IsWindowVisible(hwndNext)) &&
      (!::GetWindow(hwndNext, GW_OWNER)))
      {
      ::GetWindowText(hwndNext, (LPTSTR)name, sizeof(name));
      if(name[0] != '\0')//若有标题字符串，则加入Memo1中
        Memo1->Lines->Add(name);
      }
   //再找到下一窗口
   hwndNext = ::GetNextWindow(hwndNext, GW_HWNDNEXT);
   }
  }
else //列出所有行程与窗口
  {
  while(hwndNext)
   {//若窗口具独立行程，则取得窗口标题字符串
   if(!::GetWindow(hwndNext, GW_OWNER))
     {
     GetWindowText(hwndNext, (LPTSTR)name, sizeof(name));
     if(name[0] != '\0')
       Memo1->Lines->Add(name);
     }
   //再找到下一窗口
   hwndNext = ::GetNextWindow(hwndNext, GW_HWNDNEXT);
   }
  }
}
//---------------------------------------------------------------------------
