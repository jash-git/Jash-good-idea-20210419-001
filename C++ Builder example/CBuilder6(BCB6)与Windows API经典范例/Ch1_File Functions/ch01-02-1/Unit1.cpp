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
//汇集来源路径
AnsiString target = DirectoryListBox2->Directory+"\\"+FileEdit->Text;
//将指定文件复制至目的目录下
if(::CopyFile(FileListBox1->FileName.c_str(),//目的路径
             target.c_str(),// 原来源路径位置
             true) == 0)
         {
         ShowMessage("指定目录已有相同文件，\n所以无法复制文件！");
         }
//将目的区域更新
FileListBox2->Update();
}
//---------------------------------------------------------------------------


