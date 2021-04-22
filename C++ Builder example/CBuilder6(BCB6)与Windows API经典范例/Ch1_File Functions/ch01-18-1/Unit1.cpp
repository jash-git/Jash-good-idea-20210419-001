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
//取得逻辑磁盘包含的文字
char DriveString[111];
memset(DriveString,0,111);
::GetLogicalDriveStrings(110, DriveString);
ListBox1->Items->Add("逻辑磁盘包含的文字" + AnsiString(DriveString));
//由A:至Z:，逐一取得磁盘状态
for(int i = 65; i < 91; i++)
   {
   AnsiString a= String(char(i))+":\\";
   ListBox1->Items->Add(String(char(i))+":\\" + PrintDriveType(a.c_str()));
   }
}
//---------------------------------------------------------------------------
//取得磁盘状态函数
AnsiString TForm1::PrintDriveType(const char* fp_DriveRoot)
{
//取得磁盘状态
const int result = ::GetDriveType(fp_DriveRoot);

const char* Str;
//依据返回信息得知磁盘状态
switch (result)
     {
     case 0: Str = " 无法认定！"; break;
     case 1: Str = " 这个磁盘代号尚未使用。"; break;
     case DRIVE_REMOVABLE : Str = " 软驱"; break;
     case DRIVE_FIXED : Str = " 固定硬盘(fixed)"; break;
     case DRIVE_REMOTE : Str = " 远距的(network)"; break;
     case DRIVE_CDROM : Str = " 光驱"; break;
     case DRIVE_RAMDISK : Str = " RAM disk"; break;
     default: Str = " 未知的新设备";
       }
//返回字符串        
return  Str;
}
