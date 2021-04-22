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
//设置一字符数组
char cd[MAX_PATH];
//取得本程序现在目录位置并填入此字符数组
::GetCurrentDirectory(MAX_PATH,cd);
//取得完整目录名称与指定的文本文件名称
AnsiString str = AnsiString(cd) + "\\" + Edit1->Text;
//打开一文本文件，并返回其handle
HANDLE hFile=::CreateFile(str.c_str(),
                          GENERIC_WRITE,0,NULL,
                          OPEN_EXISTING,
                          FILE_ATTRIBUTE_NORMAL,
                          NULL);
//若失败，则跳离程序而停止执行
if (hFile==INVALID_HANDLE_VALUE)
   {
    ShowMessage("无法打开指定文件！");
    return;
   }

DWORD dpos[2];
long pos = 1555;
*(__int64*)dpos=pos;
//重设此文件打开时的位位置
DWORD moved=::SetFilePointer(hFile,dpos[0],(PLONG)&dpos[1],FILE_BEGIN);
//若无法重设此文件打开时的位位置，则跳离此程序
if (moved!=dpos[0])
   {
    ShowMessage("打开文件时，无法在新的指定位置打开");
    ::CloseHandle(hFile);
    return;
   }
//若可，则重新将特定数据写入文件中
unsigned char c[100];
c[0]=0xB8; c[1]=0x01; c[2]=0x00; c[3]=0x00;
c[4]=0x00; c[5]=0xC3; c[6]=0x00; c[7]=0x00;
c[8]=0x00; c[9]=0x00; c[10]=0x00; c[11]=0x00;
c[12]=0x4C; c[13]=0x4A; c[14]=0x57; c[15]=0x00;
DWORD writ=0;
int res=::WriteFile(hFile,c,16,&writ,NULL);
//若无法将数据写入文件中，则跳离此程序
if (!res)
   {
   ShowMessage("无法将数据写入文件中");
   ::CloseHandle(hFile);
   return;
   }
//若无法将16位数据完全写入，则跳离此程序
if (writ!=16)
   {
   ShowMessage("无法将16位数据完全写入");
   ::CloseHandle(hFile);
   return;
   }
//完成文件指定位置的更改数据
if(::CloseHandle(hFile))
   ShowMessage("将文件指定位置，成功的更改数据！");
}
//---------------------------------------------------------------------------
