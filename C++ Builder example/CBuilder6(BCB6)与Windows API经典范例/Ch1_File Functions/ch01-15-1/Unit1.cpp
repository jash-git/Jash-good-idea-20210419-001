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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
//Ҳ�����ڸ������ Properties ��ֱ������
/*
  DirectoryListBox1->FileList = FileListBox1;
  DriveComboBox1->DirList = DirectoryListBox1;
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1��������
Memo1->Clear();
Memo1->Lines->Add("�ļ�·����"+FileListBox1->FileName);

//ȡ��ָ���ļ�handle
HANDLE hFile = ::CreateFile(FileListBox1->FileName.c_str(),
                            GENERIC_READ, 0, 0,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, 0);
//ȡ��ָ���ļ�����
DWORD ft = ::GetFileType(hFile);
switch((int)ft)
  {
  case FILE_TYPE_PIPE:
      Memo1->Lines->Add("�ļ����ͣ���������or����pipe���ļ���");
      break;
  case FILE_TYPE_CHAR:
      Memo1->Lines->Add("�ļ����ͣ��ַ��ļ�������LPT�豸or�������ơ�");
      break;
  case FILE_TYPE_DISK:
      Memo1->Lines->Add("�ļ����ͣ������ļ���");
      break;
  case FILE_TYPE_UNKNOWN:
      Memo1->Lines->Add("�ļ����ͣ��޷����ϴ����͡�");
      break;
  default :
      Memo1->Lines->Add("�ļ����ͣ� NO ideas!?��");
  }
}
//---------------------------------------------------------------------------
