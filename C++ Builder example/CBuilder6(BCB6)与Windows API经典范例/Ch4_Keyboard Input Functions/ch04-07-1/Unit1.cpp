//---------------------------------------------------------------------------
//目的：取得输入法总数及列出输入法名称
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
Memo1->Text = ""; //先删除Memo1中文字
HKL hkl[10];
//清空HKL地址内存
::ZeroMemory(hkl,sizeof(HKL));
//取得输入法总数与各输入法handle
int num = ::GetKeyboardLayoutList(255, hkl);
Memo1->Lines->Add("现有输入法共" + AnsiString(num) + " 种");
//循环取出各输入法handle
while(num)
  {//使下一顺序的输入法有效
  ::ActivateKeyboardLayout((HKL)HKL_NEXT,KLF_REORDER);
  char keyb[KL_NAMELENGTH];
  //取得现在执行中输入法名称
  ::GetKeyboardLayoutName(keyb);
  //将输入法handle加入Memo1中
  Memo1->Lines->Add("第"+AnsiString(num) +
                    "个输入法Handle数值为"+AnsiString(keyb));
  num--;
  }
}
//---------------------------------------------------------------------------



