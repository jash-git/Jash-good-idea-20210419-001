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

DWORD fa;
//依据ComboBox1指定属性，更改指定文件属性
switch(ComboBox1->ItemIndex)
  {
   case 0: fa = FILE_ATTRIBUTE_ARCHIVE;break;
   case 1: fa = FILE_ATTRIBUTE_HIDDEN ;break;
   case 2: fa = FILE_ATTRIBUTE_NORMAL ;break;
   case 3: fa = FILE_ATTRIBUTE_OFFLINE ;break;
   case 4: fa = FILE_ATTRIBUTE_READONLY ;break;
   case 5: fa = FILE_ATTRIBUTE_SYSTEM ;break;
   case 6: fa = FILE_ATTRIBUTE_TEMPORARY ;break;
  }
//重新设置指定文件的属性
if(::SetFileAttributes( FileListBox1->FileName.c_str(), fa ))
   Memo1->Lines->Add("更改<" + ComboBox1->Text + ">属性成功！");
else
   Memo1->Lines->Add("无法设置！请再确认此文件路径及名称。");
//补充指定文件数据
Memo1->Lines->Add("文件完整路径：" + FileListBox1->FileName);
}
//---------------------------------------------------------------------------

