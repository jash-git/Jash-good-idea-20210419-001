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
AnsiString type;
//删除ListBox1所有文字
ListBox1->Clear();

for (int i=65; i< 91; i++)
    {
    AnsiString Root = AnsiString(char(i)) + ":\\";
    //取得磁盘状态
    int DriveType = ::GetDriveType(Root.c_str());
    switch(DriveType)
       {
        case 0: type = " 无法确认";break;
        case 1: type = " 无根目录的磁盘代号";break;
        case DRIVE_REMOVABLE: type = " 抽取式磁盘(软盘)";break;
        case DRIVE_FIXED: type = " 固定式磁盘(硬盘)";break;
        case DRIVE_REMOTE: type = " 远端装置(网络上磁盘)";break;
        case DRIVE_CDROM: type = " 光驱";break;
        case DRIVE_RAMDISK: type = " RAM磁盘机";break;
       }
    //排除未使用的磁盘代号
    if(DriveType != 1)
       ListBox1->Items->Add( Root + type);
    }
}
//---------------------------------------------------------------------------
