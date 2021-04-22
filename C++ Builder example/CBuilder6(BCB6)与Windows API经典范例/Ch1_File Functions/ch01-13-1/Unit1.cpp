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
//删除ListBox1所有文字
ListBox1->Clear();
//先将完整路径(AnsiString)转成 char字符串
int leng = FileListBox1->FileName.Length();
char str[MAX_PATH];
for(int i=0;i<=leng;i++)
    {
    if(i==leng)
       str[i] = '\0';
    else
       str[i] = FileListBox1->FileName[i+1];
    }
//取得指定文件handle
HANDLE fo = ::CreateFile(str,
                         GENERIC_READ | GENERIC_WRITE,
                         0,NULL,
                         OPEN_EXISTING,
                         FILE_FLAG_WRITE_THROUGH,
                         NULL);

BY_HANDLE_FILE_INFORMATION fd;
//取得指定文件资料
if(::GetFileInformationByHandle(fo, &fd))
    {
    //取得指定文件的状态
    AnsiString string;
    switch(fd.dwFileAttributes)
         {
         case FILE_ATTRIBUTE_ARCHIVE:
              string = "此文件处于保存状态";
              break;
         case FILE_ATTRIBUTE_COMPRESSED:
              string = "此文件处于压缩状态";
              break;
         case FILE_ATTRIBUTE_DIRECTORY:
              string = "此文件处于不存在状态";
              break;
         case FILE_ATTRIBUTE_HIDDEN:
              string = "此文件处于隐藏状态";
              break;
         case FILE_ATTRIBUTE_NORMAL:
              string = "此文件处于设置状态";
              break;
         case FILE_ATTRIBUTE_OFFLINE:
              string = "此文件处于离线状态";
              break;
         case FILE_ATTRIBUTE_READONLY:
              string = "此文件处于只读状态";
              break;
         case FILE_ATTRIBUTE_SYSTEM:
              string = "此文件处于系统状态";
              break;
         case FILE_ATTRIBUTE_TEMPORARY:
              string = "此文件处于缓冲状态";
              break;
         }
    //分辨文件系统
    AnsiString nl;
    if(((int)fd.nNumberOfLinks)== 1)
       nl = "FAT";
    else
       nl = "NTFS";
    //列出指定文件所有信息
    ListBox1->Items->Add(string);
    ListBox1->Items->Add("建立时间(L)" + AnsiString((int)fd.ftCreationTime.dwLowDateTime));
    ListBox1->Items->Add("建立时间(H)" + AnsiString((int)fd.ftCreationTime.dwHighDateTime));
    ListBox1->Items->Add("最后存取时间(L)" + AnsiString((int)fd.ftLastAccessTime.dwLowDateTime));
    ListBox1->Items->Add("最后存取时间(H)" + AnsiString((int)fd.ftLastAccessTime.dwHighDateTime));
    ListBox1->Items->Add("最后写入时间(L)" + AnsiString((int)fd.ftLastWriteTime.dwLowDateTime));
    ListBox1->Items->Add("最后写入时间(H)" + AnsiString((int)fd.ftLastWriteTime.dwHighDateTime));
    ListBox1->Items->Add("文件序列号" + AnsiString((int)fd.dwVolumeSerialNumber));
    ListBox1->Items->Add("文件大小(H)" + AnsiString((int)fd.nFileSizeHigh));
    ListBox1->Items->Add("文件大小(L)" + AnsiString((int)fd.nFileSizeLow));
    ListBox1->Items->Add("文件系统" + nl);
    ListBox1->Items->Add("特有序列号(H)" + AnsiString((int)fd.nFileIndexHigh));
    ListBox1->Items->Add("特有序列号(L)" + AnsiString((int)fd.nFileIndexLow));
    }
else
    {
    ListBox1->Items->Add("无法取得以下文件资料:");
    ListBox1->Items->Add(str);
    }
}
//---------------------------------------------------------------------------
