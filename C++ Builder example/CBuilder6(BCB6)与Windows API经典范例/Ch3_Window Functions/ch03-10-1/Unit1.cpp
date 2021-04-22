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
//单击按钮，送出WM_CLOSE信息，执行WMCloseQuery拦截信息函数
SNDMSG(Handle,WM_CLOSE,0,0);
}
//---------------------------------------------------------------------------
//拦截关闭程序信息
void __fastcall TForm1::WMCloseQuery(TMessage &Msg)
{
char str[] =
 "单击【是】按钮只是关闭窗口，并未关闭程序！\n注意：要用 Alt+F4 才能完全关闭程序！";
if(Msg.Msg == WM_CLOSE )
  {//若选取"是"按钮，仅关闭Form1窗口，Project2还存在
  if(Application->MessageBox(str,"",MB_YESNO) == IDYES )
     {
     ::DestroyWindow( this->Handle );
     }
  }
}
//---------------------------------------------------------------------------
