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
//ɾ��ListBox1��������
ListBox1->Clear();
//ȡ���������е��߼�����
DWORD Drives = ::GetLogicalDrives();
for(int x = 0; x < 32; ++x)
    if(Drives & (1 << x))
       {
       String fs;
       String Drive = AnsiString(char('A' + x)) + ":\\";
       DWORD sn, fsf;
       char Volume[80], snb[80], fsfb[80];
       //ȡ��ָ���������к�&��ʽ
       if(::GetVolumeInformation(Drive.c_str(),
                                 Volume, sizeof(Volume),
                                 &sn, 0,
                                 &fsf,
                                 fsfb, sizeof(fsfb)))
          {
          sprintf(snb, "%X", sn);
          Drive += " " + AnsiString(Volume) + ", �������кţ�" +
                   String(snb)+ ", ���̸�ʽ��" + String(fsfb);
          }
      //�������ʾ��ListBox1��
      ListBox1->Items->Add(Drive);
      }
}
//---------------------------------------------------------------------------
