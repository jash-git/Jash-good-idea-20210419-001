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
AnsiString type;
//删除ListBox1所有文字
ListBox1->Clear();
//取得可使用的逻辑磁盘总数
DWORD Drives = ::GetLogicalDrives();
for (int i=0; i< 32; i++)
   if( Drives & (1 << i))
       {
       AnsiString Root = AnsiString(char('A'+ i)) + ":\\";
       //逐一列出磁盘信息
       for(int k=0;k<5;k++)
          ListBox1->Items->Add(diskfree(Root,k));
       }

}
//---------------------------------------------------------------------------
//
AnsiString TForm1::diskfree(AnsiString disk,int s)
{
AnsiString disk1 = disk;
DWORD SecPerCluster;
DWORD BytesPerSector;
DWORD FreeClusters;
DWORD TotalClusters;
//取得指定磁盘相关数据
::GetDiskFreeSpace(disk.c_str(),
                   &SecPerCluster,
                   &BytesPerSector,
                   &FreeClusters,
                   &TotalClusters
                   );
//总计可使用的位数目
unsigned long avail = (FreeClusters * SecPerCluster * BytesPerSector)/(1024*1024);

char FreeBytes[255];
//转换为10进位后，并以字符串显示
_i64toa (avail, FreeBytes,10);
switch(s)
   {
    case 0: disk = disk1 ; break;
    case 1: disk = "扇区：" + IntToStr(BytesPerSector) ; break;
    case 2: disk = "磁道：" + IntToStr(SecPerCluster) ; break;
    case 3: disk = "磁盘总空间：" + IntToStr(TotalClusters) ; break;
    case 4: disk = "可用磁盘空间" + AnsiString(FreeBytes)+" MB" ; break;
   }
//将此字符串返回
return disk;

}


