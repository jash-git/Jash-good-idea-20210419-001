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
Tag = 1;//将闲置属性作为循环变量
Timer1->Interval = 500; //半秒钟反应一次
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
AnsiString hint;
//三元运算--切换两个字符串
(Tag%2)?(hint=Edit1->Text,Tag=2):(hint=Edit2->Text,Tag=1);
//搜寻到通用提示窗口handle
HWND hWnd = ::FindWindow("THintWindow",NULL);
if(hWnd)
  {//鼠标在窗口上停留时，重设出现的提示字符串
  ::SetWindowText(hWnd, hint.c_str());
  SendMessage(hWnd,WM_SETTEXT,0,256);//送出重设字符串信息
  //送出更新字符串信息，CM_TEXTCHANGED定义于Controls.hpp中
  SendMessage(hWnd,CM_TEXTCHANGED,0,0);
  }
}
//---------------------------------------------------------------------------
