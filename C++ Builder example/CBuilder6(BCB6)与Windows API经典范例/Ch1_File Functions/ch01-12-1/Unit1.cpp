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
//���ó��ִ���ʱ��������ִ���Ի���
int PrevMode = ::SetErrorMode(SEM_FAILCRITICALERRORS);
//��һ�ּ��׼��A:���Ƿ��������
/*
if (::GetFileAttributes("A:\\")==0xFFFFFFFF)
   StaticText1->Caption = "����(A:)û�з�����!";
else
   StaticText1->Caption = "����(A:)û�з�����!";
*/

//�ڶ����������A:���Ƿ��������
AnsiString str;
//ȡ��A:\��ָ���ļ�orĿ¼������״̬
//���ɸ���GetFileAttributes���������Բ���
DWORD filedate = ::GetFileAttributes("A:\\");
switch(filedate)
   {
   case FILE_ATTRIBUTE_ARCHIVE:
          str = "���ļ�/Ŀ¼���ڱ���״̬";
          break;
   case FILE_ATTRIBUTE_COMPRESSED:
          str = "���ļ�/Ŀ¼����ѹ��״̬";
          break;
   case FILE_ATTRIBUTE_DIRECTORY:
          str = "���ļ�/Ŀ¼���ڲ�����״̬";
          break;
   case FILE_ATTRIBUTE_HIDDEN:
          str = "���ļ�/Ŀ¼��������״̬";
          break;
   case FILE_ATTRIBUTE_NORMAL:
          str = "���ļ�/Ŀ¼��������״̬";
          break;
   case FILE_ATTRIBUTE_OFFLINE:
          str = "���ļ�/Ŀ¼��������״̬";
          break;
   case FILE_ATTRIBUTE_READONLY:
          str = "���ļ�/Ŀ¼����ֻ��״̬";
          break;
   case FILE_ATTRIBUTE_SYSTEM:
          str = "���ļ�/Ŀ¼����ϵͳ״̬";
          break;
   case FILE_ATTRIBUTE_TEMPORARY:
          str = "���ļ�/Ŀ¼���ڻ���״̬";
          break;
   case 0xFFFFFFFF:
          str = "����(A:)û�з�����!";
          break;
   }
//��ʾ�����
StaticText1->Caption = str;
//�ٴ����ó��ִ���ʱ��������ִ���Ի���
::SetErrorMode(PrevMode);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//��ʱ����һ�� DriveComboBox������ٷ����Ӿ�֮�⣡or ��С��
//��������Զ�ȡ�ù����Ĵ��̴���
TDriveComboBox *DriveComboBox1 = new TDriveComboBox(Form1->Panel1);
DriveComboBox1->Parent = Panel1;
DriveComboBox1->Width = 1;
DriveComboBox1->Height = 10;

//DriveComboBox1->Top = 100;
//DriveComboBox1->Left = 100;

//���ó��ִ���ʱ��������ִ���Ի���
int PrevMode = ::SetErrorMode(SEM_FAILCRITICALERRORS);
//�϶����Ĵ������������ţ����ǹ�������
AnsiString cd = DriveComboBox1->Items->Strings[DriveComboBox1->Items->Count-1];
//������������ E:���� cd = "E: [backup1]"
cd = cd.SetLength(2) + "\\";
//�ж��Ƿ��й��̷���
if (::GetFileAttributes(cd.c_str())==0xFFFFFFFF)
   StaticText1->Caption = "������û�й���!";
else
   StaticText1->Caption = "�������й���!";
//�ٴ����ó��ִ���ʱ��������ִ���Ի���
::SetErrorMode(PrevMode);
delete DriveComboBox1;
}
//---------------------------------------------------------------------------
