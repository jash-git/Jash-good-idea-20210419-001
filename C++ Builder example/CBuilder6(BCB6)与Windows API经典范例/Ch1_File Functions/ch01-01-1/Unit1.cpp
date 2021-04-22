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
//默认按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
Button3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除Memo1中所有文字
Memo1->Text = "";
//判断现在程序是否为ANSI字符集or OEM字符集
//这项判断功能对 8 位输出入设备极为有用
if(AreFileApisANSI())
   {
   Memo1->Lines->Add("现在程序是 ANSI 字符集！");
   Memo1->Lines->Add("为 WIN32 函数使用。");
   Memo1->Lines->Add("若单击Button2按钮，则转成 OEM 字符集，");
   Memo1->Lines->Add("可以直接由 8 字节输入输出设备使用。");
   Button2->Enabled = true;
   Button3->Enabled = false;
   }
else
   {
   Memo1->Lines->Add("程序是 OEM 字符集！");
   Memo1->Lines->Add("可以直接由 8 字节输出入设备使用。");
   Memo1->Lines->Add("若单击Button3按钮，则转成 ANSI 字符集，");
   Memo1->Lines->Add("为 WIN32 函数使用。");
   Button2->Enabled = false;
   Button3->Enabled = true;
   }
Memo1->Lines->Add("以上都会影响现有函数返回的结果");
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//由 ANSI 变成 OEM
SetFileApisToOEM();
Memo1->Text = "由 ANSI 字符集转成 OEM 字符集";
//重设按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
Button3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
//由OEM 变成 ANSI
SetFileApisToANSI();
Memo1->Text = "由 OEM 字符集转成 ANSI 字符集";
//重设按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
Button3->Enabled = false;
}
//---------------------------------------------------------------------------

