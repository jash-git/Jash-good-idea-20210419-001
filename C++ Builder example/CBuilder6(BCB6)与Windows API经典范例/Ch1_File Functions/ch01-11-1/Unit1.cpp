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
AnsiString type;
//ɾ��ListBox1��������
ListBox1->Clear();

for (int i=65; i< 91; i++)
    {
    AnsiString Root = AnsiString(char(i)) + ":\\";
    //ȡ�ô���״̬
    int DriveType = ::GetDriveType(Root.c_str());
    switch(DriveType)
       {
        case 0: type = " �޷�ȷ��";break;
        case 1: type = " �޸�Ŀ¼�Ĵ��̴���";break;
        case DRIVE_REMOVABLE: type = " ��ȡʽ����(����)";break;
        case DRIVE_FIXED: type = " �̶�ʽ����(Ӳ��)";break;
        case DRIVE_REMOTE: type = " Զ��װ��(�����ϴ���)";break;
        case DRIVE_CDROM: type = " ����";break;
        case DRIVE_RAMDISK: type = " RAM���̻�";break;
       }
    //�ų�δʹ�õĴ��̴���
    if(DriveType != 1)
       ListBox1->Items->Add( Root + type);
    }
}
//---------------------------------------------------------------------------
