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
AnsiString dir;
//判断是否在根目录下
if(DirectoryListBox1->Directory.Length() != 3 )
   dir = DirectoryListBox1->Directory + "\\*.*";
else
   dir = DirectoryListBox1->Directory + "\*.*";
//取得第一个文件handle
WIN32_FIND_DATA Data;
HANDLE File = ::FindFirstFile(dir.c_str(), &Data);
//若成功取得文件handle
if(File != INVALID_HANDLE_VALUE)
   {
   //删除ListBox1所有资料
   ListBox1->Clear();
   //若这个文件时文件目录，则加入到ListBox1い中
   do
      {
      if((Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
          && (String(Data.cFileName) != "..")
          && (String(Data.cFileName) != "."))
              ListBox1->Items->Add(Data.cFileName);
      } while(::FindNextFile(File, &Data)); //找下一个文件信息
   
   
   //寻找结束，释放handle
   ::FindClose(File);
   //将总数显示出来
   StaticText2->Caption = DirectoryListBox1->Directory + "共有" + AnsiString(ListBox1->Items->Count)+"个子目录";
   }
else //没有找到子目录
   StaticText2->Caption = DirectoryListBox1->Directory + "共有 0 个子目录";
}
//---------------------------------------------------------------------------

