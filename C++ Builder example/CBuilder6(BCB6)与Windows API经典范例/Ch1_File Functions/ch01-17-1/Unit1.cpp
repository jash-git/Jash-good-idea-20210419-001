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
//ɾ��Memo1��������
Memo1->Clear();
//ȡ�������е��߼�����
DWORD Drives = ::GetLogicalDrives();
//��һ�˶����еĴ���
for(int x = 0; x < 32; ++x)
if(Drives & (1 << x))
   {
   String dr(char('A' + x));
   dr += ":\\";

   String Volume;
   Volume.SetLength(256);
   //ȡ�ø�Ŀ¼��������
   if(::GetVolumeInformation(dr.c_str(),
            Volume.c_str(), Volume.Length(), 0,
            0, 0, 0, 0))
       {
       dr += " " + Volume;
       }

   Memo1->Lines->Add("���ڿ��ô���" + dr);
   }
}
//---------------------------------------------------------------------------
