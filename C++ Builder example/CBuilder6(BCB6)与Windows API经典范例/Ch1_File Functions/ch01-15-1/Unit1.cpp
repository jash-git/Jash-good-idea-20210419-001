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
//删除Memo1所有数据
Memo1->Clear();
Memo1->Lines->Add("文件路径："+FileListBox1->FileName);

//取得指定文件handle
HANDLE hFile = ::CreateFile(FileListBox1->FileName.c_str(),
                            GENERIC_READ, 0, 0,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, 0);
//取得指定文件类型
DWORD ft = ::GetFileType(hFile);
switch((int)ft)
  {
  case FILE_TYPE_PIPE:
      Memo1->Lines->Add("文件类型：具有著名or隐匿pipe的文件。");
      break;
  case FILE_TYPE_CHAR:
      Memo1->Lines->Add("文件类型：字符文件，保存LPT设备or操作控制。");
      break;
  case FILE_TYPE_DISK:
      Memo1->Lines->Add("文件类型：磁盘文件。");
      break;
  case FILE_TYPE_UNKNOWN:
      Memo1->Lines->Add("文件类型：无法辨认此类型。");
      break;
  default :
      Memo1->Lines->Add("文件类型： NO ideas!?。");
  }
}
//---------------------------------------------------------------------------
