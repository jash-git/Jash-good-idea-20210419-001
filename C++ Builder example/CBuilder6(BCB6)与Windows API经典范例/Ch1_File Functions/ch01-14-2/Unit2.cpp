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
//转换AnsiString至char字符串
char *filename=FileListBox1->FileName.c_str();
//取得文件handle
HANDLE hFile = ::CreateFile(filename,
                            GENERIC_READ, 0, 0,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, 0);
//取得文件大小
DWORD dwFileLen = ::GetFileSize(hFile, 0);
//释放handle
::CloseHandle(hFile);
//显示文件大小
Memo1->Clear();
Memo1->Lines->Add("文件路径：" + FileListBox1->FileName);
Memo1->Lines->Add("文件大小：" + AnsiString((long)dwFileLen) + "个字节组");

}
//---------------------------------------------------------------------------
