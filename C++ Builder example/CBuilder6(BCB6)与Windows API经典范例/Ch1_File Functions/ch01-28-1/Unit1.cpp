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
//删除Memo1所有文字
Memo1->Clear();

char c[MAX_PATH];
//取得目前程序目录
if(::GetCurrentDirectory(MAX_PATH,c))
    {
    Memo1->Lines->Add("取得目前程序目录：");
    Memo1->Lines->Add(AnsiString(c));
    Memo1->Lines->Add("-------------------------");
    //重新设置现在目录
    if(::SetCurrentDirectory("C:\\Temp\\"))
       {
       if(::GetCurrentDirectory(MAX_PATH,c))
           {
           //将改变的现在目录，反应在DirectoryListBox1组件上
           DirectoryListBox1->Directory = AnsiString(c);
           Memo1->Lines->Add("改设置指定目录在：");
           Memo1->Lines->Add(AnsiString(c));
           }
       }
    else
       Memo1->Lines->Add("改设置指定目录失败！");
    }
else
    Memo1->Lines->Add("取得目前目录失败！");
}
//---------------------------------------------------------------------------
