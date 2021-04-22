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
//设置出现错误时，不会出现错误对话框
int PrevMode = ::SetErrorMode(SEM_FAILCRITICALERRORS);
//第一种简易检测A:盘是否放入软盘
/*
if (::GetFileAttributes("A:\\")==0xFFFFFFFF)
   StaticText1->Caption = "软驱(A:)没有放软盘!";
else
   StaticText1->Caption = "软驱(A:)没有放软盘!";
*/

//第二种完整检测A:盘是否放入软盘
AnsiString str;
//取得A:\盘指定文件or目录的性质状态
//您可更改GetFileAttributes参数，加以测试
DWORD filedate = ::GetFileAttributes("A:\\");
switch(filedate)
   {
   case FILE_ATTRIBUTE_ARCHIVE:
          str = "此文件/目录处于保存状态";
          break;
   case FILE_ATTRIBUTE_COMPRESSED:
          str = "此文件/目录处于压缩状态";
          break;
   case FILE_ATTRIBUTE_DIRECTORY:
          str = "此文件/目录处于不存在状态";
          break;
   case FILE_ATTRIBUTE_HIDDEN:
          str = "此文件/目录处于隐藏状态";
          break;
   case FILE_ATTRIBUTE_NORMAL:
          str = "此文件/目录处于设置状态";
          break;
   case FILE_ATTRIBUTE_OFFLINE:
          str = "此文件/目录处于离线状态";
          break;
   case FILE_ATTRIBUTE_READONLY:
          str = "此文件/目录处于只读状态";
          break;
   case FILE_ATTRIBUTE_SYSTEM:
          str = "此文件/目录处于系统状态";
          break;
   case FILE_ATTRIBUTE_TEMPORARY:
          str = "此文件/目录处于缓冲状态";
          break;
   case 0xFFFFFFFF:
          str = "软驱(A:)没有放软盘!";
          break;
   }
//显示检测结果
StaticText1->Caption = str;
//再次设置出现错误时，不会出现错误对话框
::SetErrorMode(PrevMode);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//即时生成一个 DriveComboBox组件，再放至视觉之外！or 缩小化
//此组件即自动取得光驱的磁盘代号
TDriveComboBox *DriveComboBox1 = new TDriveComboBox(Form1->Panel1);
DriveComboBox1->Parent = Panel1;
DriveComboBox1->Width = 1;
DriveComboBox1->Height = 10;

//DriveComboBox1->Top = 100;
//DriveComboBox1->Left = 100;

//设置出现错误时，不会出现错误对话框
int PrevMode = ::SetErrorMode(SEM_FAILCRITICALERRORS);
//认定最后的磁盘驱动器代号，即是光驱代号
AnsiString cd = DriveComboBox1->Items->Strings[DriveComboBox1->Items->Count-1];
//若光驱代号是 E:，则 cd = "E: [backup1]"
cd = cd.SetLength(2) + "\\";
//判断是否有光盘放入
if (::GetFileAttributes(cd.c_str())==0xFFFFFFFF)
   StaticText1->Caption = "光驱中没有光盘!";
else
   StaticText1->Caption = "光驱中有光盘!";
//再次设置出现错误时，不会出现错误对话框
::SetErrorMode(PrevMode);
delete DriveComboBox1;
}
//---------------------------------------------------------------------------
