//---------------------------------------------------------------------------
//目的：输入法可由<现有输入法>中选取，并在Memo1中执行输入功能
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
//清空HKL地址内存
::ZeroMemory(hkl,sizeof(HKL));
//取得输入法总数与各输入法handle
int num = ::GetKeyboardLayoutList(255, hkl);
Memo1->Lines->Add("现有输入法共" + AnsiString(num) + " 种");
//癹伴块猭handle
while(num)
  {//在win95，仅使此线程执行此输入法；
  //在NT，则使在全系统所有已调用线程皆执行此输入法
  //取得下一输入法并致能
  ::ActivateKeyboardLayout((HKL)HKL_NEXT,KLF_REORDER);
  char keyb[KL_NAMELENGTH];
  //取得现在输入法名称
  ::GetKeyboardLayoutName(keyb);
  //将输入法handle加入RadioGroup1切换子项中
  RadioGroup1->Items->Add(AnsiString(keyb));
  Memo1->Lines->Add(AnsiString(keyb));
  num--;
  }
//预先选取RadioGroup1第一子项
RadioGroup1->ItemIndex = 0;
//按钮任务完成，即失效
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
//当点取<现有输入法>其中子项目，即切换输入法
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{//取得RadioGroup1的指定字符串
AnsiString skey = RadioGroup1->Items->Strings[RadioGroup1->ItemIndex];
//加载指定名称的输入法
::LoadKeyboardLayout( skey.c_str(), KLF_ACTIVATE);
//将焦点交给Memo，以便进行输入
Memo1->SetFocus();
}
//---------------------------------------------------------------------------



