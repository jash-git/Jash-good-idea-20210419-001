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
//�Զ��庯���������д��̾����ʾ��ListBox1��
ShowDrive();
//��Form1��Tag������Ϊ bool ʹ��
//�ж��Ƿ�ѡȡListBox1����Ŀ
Tag = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//��һ������ѡȡ�Ĵ�����Ŀ
for (int i = 0; i < ListBox1->Items->Count; i++)
  if (ListBox1->Selected[i])
    {
    AnsiString str = ListBox1->Items->Strings[i].SubString(1,3);
    //���豻ѡ���Ĵ��̾��
    if(::SetVolumeLabel(str.c_str(),Edit1->Text.c_str()))
         {
         ShowMessage("�Ѿ��� " + str + " ���̾��\n�ĳ�"+Edit1->Text);
         //�Զ��庯���������д��̾����ʾ��ListBox1��
         ShowDrive();
         }
    else
         ShowMessage("�޷����� " + str + "���̾�꣬\n���޸ĸ�Ŀ¼λ��");
    //����ѡȡListBox1����Ŀ
    Tag = false;
    }
//��ûѡȡListBox1����Ŀ���������ʾ��Ϣ
if(Tag)
   ShowMessage("����ѡ��ListBox1�еĴ��̣��ٵ�����ť���Ĵ��̾�꣡");
Tag = true;
}
//---------------------------------------------------------------------------
//�Զ��庯���������д��̾����ʾ��ListBox1��
void TForm1::ShowDrive()
{
//ɾ��ListBox1��������
ListBox1->Clear();
//ȡ���������е��߼�����
DWORD Drives = ::GetLogicalDrives();
for(int x = 0; x < 32; ++x)
    if(Drives & (1 << x))
       {
       String dr(char('A' + x));
       dr += ":\\";

       String Volume;
       Volume.SetLength(256);
       //ȡ�ø�Ŀ¼��������
       if(::GetVolumeInformation(dr.c_str(),
                                 Volume.c_str(),
                                 Volume.Length(),
                                 0,0, 0, 0, 0))
          {
          dr += " " + Volume;
          }
      //�������ʾ��ListBox1��
      ListBox1->Items->Add(dr);
      }
}
//---------------------------------------------------------------------------


