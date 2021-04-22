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
//删除Memo1中所有文字
Memo1->Clear();

char buffer[MAX_PATH];
char *filePart;
char *path;
AnsiString temp;
//如果 path = NULL
// SearchPath 会依照 1. 应用程序被加载的目录 2.目前的目录
//3.窗口系统目录 4.窗口目录 5.path 设置目录 依序搜索
if(CheckBox1->Checked)
    path = NULL;
else
    {
    //判断path是否在根目录
    if(DirectoryListBox1->Directory.Length()<4)
        temp = DirectoryListBox1->Directory;
    else
        temp = DirectoryListBox1->Directory +"\\";
    path = temp.c_str();
    }
//搜索指定文件
if(::SearchPath(path,// 搜索的目录
                Edit1->Text.c_str(),// 被搜索的文件完整名称
                NULL,	// 被搜索的文件扩展名
                MAX_PATH,// 字符串缓冲区大小
                buffer,// 字符串缓冲区
                &filePart// 完整路径&文件名
                ))
    {
    Memo1->Lines->Add("文件"+String(filePart)+"在以下路径找到：");
    Memo1->Lines->Add(buffer);
    }
else
    {
    if(path)
       Memo1->Lines->Add("在"+AnsiString(path)+" 没有找到"+Edit1->Text+"！");
    else
       Memo1->Lines->Add("在自动搜索下，没有找到"+Edit1->Text+"！");
    }

}
//---------------------------------------------------------------------------

