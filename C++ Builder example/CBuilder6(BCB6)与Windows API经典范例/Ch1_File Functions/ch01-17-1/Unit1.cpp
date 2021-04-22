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
//删除Memo1所有文字
Memo1->Clear();
//取得运行中的逻辑磁盘
DWORD Drives = ::GetLogicalDrives();
//逐一核对运行的磁盘
for(int x = 0; x < 32; ++x)
if(Drives & (1 << x))
   {
   String dr(char('A' + x));
   dr += ":\\";

   String Volume;
   Volume.SetLength(256);
   //取得根目录标题文字
   if(::GetVolumeInformation(dr.c_str(),
            Volume.c_str(), Volume.Length(), 0,
            0, 0, 0, 0))
       {
       dr += " " + Volume;
       }

   Memo1->Lines->Add("现在可用磁盘" + dr);
   }
}
//---------------------------------------------------------------------------
