//---------------------------------------------------------------------------
//目的：取得输入法总数及列出输入法名称
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
Memo1->Text = ""; //先删除Memo1中文字
HKL hkl[10];
//将HKL地址内存填满相同数值
::FillMemory(hkl,sizeof(hkl),0);
//取得输入法总数与各输入法handle
int num = ::GetKeyboardLayoutList(255, hkl);
Memo1->Lines->Add("现有输入法共 " + AnsiString(num) + " 种");
//璝璶陪ボ块猭嘿玥ゲ斗祘Α絏ずノ羭(switch)よΑ矪瞶
//循环取出各输入法handle
while(num>-1)
  {
  long k = (long)hkl[num--];
  if((int)k != 0) //将输入法handle加入Memo1中
    Memo1->Lines->Add("第"+AnsiString(num+2) +
                      "个输入法Handle数值为"+IntToHex((int)k,8));
  }
}
//---------------------------------------------------------------------------


