//---------------------------------------------------------------------------
//目的：按钮时，检测同时是否按住Shift键，而引发不同功能
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
{//删除Memo1中文字
Memo1->Text = "";
//按钮时，检测同时是否按住Shift键，引发不同功能
if(HIBYTE(::GetKeyState(VK_SHIFT)))
  {
  Panel1->Show(); Panel2->Hide();
  Memo1->Lines->Add("单击按钮时，同时按住Shift键");
  }
else
  {
  Panel1->Hide(); Panel2->Show();
  Memo1->Lines->Add("单击按钮时，未按住Shift键");
  }
//测试&观看用
Memo1->Lines->Add("高位句柄：" +
                  AnsiString(HIBYTE(::GetKeyState(VK_SHIFT))));
Memo1->Lines->Add("低位句柄：" +
                  AnsiString(LOBYTE(::GetKeyState(VK_SHIFT))));
}
//---------------------------------------------------------------------------
