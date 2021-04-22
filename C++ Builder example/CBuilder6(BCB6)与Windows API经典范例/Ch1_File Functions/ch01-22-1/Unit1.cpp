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
/*
char VolumeNameBuffer[256];
char FileSystemNameBuffer[256];

DWORD MaximumComponentLength;
DWORD FileSystemFlags;
GetVolumeInformation(
  "c:\\",
  VolumeNameBuffer,
  sizeof(VolumeNameBuffer),
  0,
  &MaximumComponentLength,
  &FileSystemFlags,
  FileSystemNameBuffer,
  sizeof(FileSystemNameBuffer)
);
*/
char path[] ="C:\\";
char volume[80],number[80];
DWORD serialNumber;
if(GetVolumeInformation(path,volume,sizeof(volume),
                        &serialNumber,0,0,NULL,0))
   {
   sprintf(number, "%X", serialNumber);
   StaticText2->Caption = "C:硬盘名称是"+
                          AnsiString(volume)+
                          ",出厂序列号："+
                          AnsiString(number);
   }
else
   StaticText2->Caption = "无法得知C:硬盘名称及出厂序列号！";

}
//---------------------------------------------------------------------------
 