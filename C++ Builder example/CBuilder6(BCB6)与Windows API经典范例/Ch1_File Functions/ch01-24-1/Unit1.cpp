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

//MoveFile函数两个参数都要完整路径&文件名
//当Edit1 & Edit2 的路径是同一路径且文件名不同时，就是更改文件名
if(::MoveFile(Edit1->Text.c_str(), Edit2->Text.c_str()))
   Memo1->Lines->Add("成功移动文件！");
else
   Memo1->Lines->Add("移动文件失败！请先在<来源>制作一个文本文件(aaa.txt)！");
//小提示！
Memo1->Lines->Add("当Edit1 & Edit2 的路径是同一路径，");
Memo1->Lines->Add("且文件名不同时，即是<更改文件名>。");
}
//---------------------------------------------------------------------------
