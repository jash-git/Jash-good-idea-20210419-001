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
//ɾ��ListBox1��������
ListBox1->Clear();
//ȡ���߼����̰���������
char DriveString[111];
memset(DriveString,0,111);
::GetLogicalDriveStrings(110, DriveString);
ListBox1->Items->Add("�߼����̰���������" + AnsiString(DriveString));
//��A:��Z:����һȡ�ô���״̬
for(int i = 65; i < 91; i++)
   {
   AnsiString a= String(char(i))+":\\";
   ListBox1->Items->Add(String(char(i))+":\\" + PrintDriveType(a.c_str()));
   }
}
//---------------------------------------------------------------------------
//ȡ�ô���״̬����
AnsiString TForm1::PrintDriveType(const char* fp_DriveRoot)
{
//ȡ�ô���״̬
const int result = ::GetDriveType(fp_DriveRoot);

const char* Str;
//���ݷ�����Ϣ��֪����״̬
switch (result)
     {
     case 0: Str = " �޷��϶���"; break;
     case 1: Str = " ������̴�����δʹ�á�"; break;
     case DRIVE_REMOVABLE : Str = " ����"; break;
     case DRIVE_FIXED : Str = " �̶�Ӳ��(fixed)"; break;
     case DRIVE_REMOTE : Str = " Զ���(network)"; break;
     case DRIVE_CDROM : Str = " ����"; break;
     case DRIVE_RAMDISK : Str = " RAM disk"; break;
     default: Str = " δ֪�����豸";
       }
//�����ַ���        
return  Str;
}
