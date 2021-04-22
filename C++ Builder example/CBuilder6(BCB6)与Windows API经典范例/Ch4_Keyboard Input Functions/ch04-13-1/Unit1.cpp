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
//单击Button1按钮，才启动Timer
Timer1->Enabled = false;
//所有输入法名称的临时清单
list = new TStringList();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//先删除Memo1中文字
Memo1->Text = "";
//输入法总数归零
s = 0;
pass = 0;
//先默认指向输入法的指针数组，共30个指针位置
HKL hkl[30];

//取得输入法总数
s = ::GetKeyboardLayoutList(255, hkl);

Memo1->Lines->Add("现有输入法共 " + AnsiString(s) + " 种");
//将输入法总数传给Timer1中执行次数
pass = s;
//启动Timer1，取得所有输入法
//完成后，即关闭Timer1
Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
//运用Timer的定时功能，限次检测输入法名称
//您可用switch列举出
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if(pass > 0)
   {
   //切换到下一个输入法<Ctrl + Shift>
   //单击 Ctrl 键
   ::keybd_event(VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL,0),0,0);
   //再单击 Shift 键
   ::keybd_event(VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT,0),0,0);
   //切换输入法后，反序释放按键
   ::keybd_event(VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT,0),KEYEVENTF_KEYUP,0);
   ::keybd_event(VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);

   //取得现在输入法的名称代码
   char keyb[KL_NAMELENGTH];
   ::GetKeyboardLayoutName(keyb);
   //将输入法名称加入RadioGroup1切换子项及临时清单中
   RadioGroup1->Items->Add(AnsiString(keyb));
   list->Add(AnsiString(keyb));
   //输入法名称显示在Memo1中
   Memo1->Lines->Add(keyb);
   Button1->Enabled = false;
   }
else
   Timer1->Enabled = false;

pass--;
}
//---------------------------------------------------------------------------
//当点取其中子项目，即切换输入法
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
//取得StringList的指定字符串
AnsiString skey = list->Strings[RadioGroup1->ItemIndex];

//加载指定名称的输入法
::LoadKeyboardLayout( skey.c_str(), KLF_ACTIVATE);

//将焦点交给Memo，以便进行输入
Memo1->SetFocus();
}
//---------------------------------------------------------------------------
//释放StringList占住的内存
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete list;
}
//---------------------------------------------------------------------------


