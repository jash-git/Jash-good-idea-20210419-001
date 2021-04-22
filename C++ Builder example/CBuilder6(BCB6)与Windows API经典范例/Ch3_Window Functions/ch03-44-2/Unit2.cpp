//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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
char str[256];
//取得系统使用语言代码ID，并由此ID取得定义字符串
::VerLanguageName(::GetSystemDefaultLangID(), str, 256);
//将取出的字符串传至Form1标题字符串上
::SetWindowText(Handle,str);
}
//---------------------------------------------------------------------------
