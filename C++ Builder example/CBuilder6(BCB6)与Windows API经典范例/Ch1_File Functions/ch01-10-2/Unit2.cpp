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
//ɾ��ListBox1��������
ListBox1->Clear();
//ȡ�ÿ�ʹ�õ��߼���������
DWORD Drives = ::GetLogicalDrives();
for (int i=0; i< 32; i++)
   if( Drives & (1 << i))
       {
       AnsiString Root = AnsiString(char('A'+ i)) + ":\\";
       //��һ�г�������Ϣ
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
//ȡ��ָ�������������
::GetDiskFreeSpace(disk.c_str(),
                   &SecPerCluster,
                   &BytesPerSector,
                   &FreeClusters,
                   &TotalClusters
                   );
//�ܼƿ�ʹ�õ�λ��Ŀ
unsigned long avail = (FreeClusters * SecPerCluster * BytesPerSector)/(1024*1024);

char FreeBytes[255];
//ת��Ϊ10��λ�󣬲����ַ�����ʾ
_i64toa (avail, FreeBytes,10);
switch(s)
   {
    case 0: disk = disk1 ; break;
    case 1: disk = "������" + IntToStr(BytesPerSector) ; break;
    case 2: disk = "�ŵ���" + IntToStr(SecPerCluster) ; break;
    case 3: disk = "�����ܿռ䣺" + IntToStr(TotalClusters) ; break;
    case 4: disk = "���ô��̿ռ�" + AnsiString(FreeBytes)+" MB" ; break;
   }
//�����ַ�������
return disk;

}


