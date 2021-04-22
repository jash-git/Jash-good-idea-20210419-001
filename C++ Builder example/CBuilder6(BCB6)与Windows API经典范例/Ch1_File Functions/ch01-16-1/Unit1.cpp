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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//也可以在各组件的 Properties 中直接设置
/*
  DirectoryListBox1->FileList = FileListBox1;
  DriveComboBox1->DirList = DirectoryListBox1;
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除Memo1所有文字
Memo1->Clear();
//把计
char buffer[ MAX_PATH ];
char *filePart;
char *path = FileListBox1->FileName.c_str();
//取得完整长路径，返回路径字符数目
unsigned int result = ::GetFullPathName(path,
                                        MAX_PATH,
                                        buffer,
                                        &filePart);
//显示在Memo1上
Memo1->Lines->Add("文件名称" + AnsiString(filePart));
Memo1->Lines->Add("文件完整路径" + AnsiString(buffer));
Memo1->Lines->Add("文件完整路径的字符数" + AnsiString(result));
}
//---------------------------------------------------------------------------
