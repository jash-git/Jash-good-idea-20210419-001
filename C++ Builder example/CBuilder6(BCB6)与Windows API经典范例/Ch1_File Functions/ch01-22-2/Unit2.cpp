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
//删除ListBox1所有文字
ListBox1->Clear();
//取得现在运行的逻辑磁盘
DWORD Drives = ::GetLogicalDrives();
for(int x = 0; x < 32; ++x)
    if(Drives & (1 << x))
       {
       String fs;
       String Drive = AnsiString(char('A' + x)) + ":\\";
       DWORD sn, fsf;
       char Volume[80], snb[80], fsfb[80];
       //取得指定磁盘序列号&格式
       if(::GetVolumeInformation(Drive.c_str(),
                                 Volume, sizeof(Volume),
                                 &sn, 0,
                                 &fsf,
                                 fsfb, sizeof(fsfb)))
          {
          sprintf(snb, "%X", sn);
          Drive += " " + AnsiString(Volume) + ", 磁盘序列号：" +
                   String(snb)+ ", 磁盘格式：" + String(fsfb);
          }
      //将结果显示在ListBox1上
      ListBox1->Items->Add(Drive);
      }
}
//---------------------------------------------------------------------------
