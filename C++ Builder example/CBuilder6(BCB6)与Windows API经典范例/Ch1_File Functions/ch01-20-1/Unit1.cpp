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
//先显示此文字提示
ListBox1->Items->Add("你可以用记事本打开此TMP文件！");

char TempPath[MAX_PATH], TempFileName[MAX_PATH];
//取得系统默认的缓冲目录路径
if((int)::GetTempPath( sizeof(TempPath), TempPath))
   ListBox1->Items->Add("缓冲目录："+ AnsiString(TempPath));
else
   ListBox1->Items->Add("没有发现缓冲目录(*:\TEMP\)");
//创造一个惟一名称的缓冲文件，如"TXTXXXX.tmp"
::GetTempFileName(TempPath, "TXT", 0, TempFileName);
ListBox1->Items->Add("缓冲盘全路径："+ AnsiString(TempFileName));

//FileCreate(..),FileWrite(..),FileClose(..)三函数
//都为BCB SysUtils 基本函数，见 Help
//将某些内容存入此缓冲文件中
int TxtFile = FileCreate(AnsiString(TempFileName));
//将出现在ListBox1上的文字，写入此缓冲盘中
for(int i = 0; i < ListBox1->Items->Count; ++i)
    {
    String str = ListBox1->Items->Strings[i] + "\r\n";
    FileWrite(TxtFile, str.c_str(), str.Length());
    }
//关闭此缓冲文件
FileClose(TxtFile);
}
//---------------------------------------------------------------------------
