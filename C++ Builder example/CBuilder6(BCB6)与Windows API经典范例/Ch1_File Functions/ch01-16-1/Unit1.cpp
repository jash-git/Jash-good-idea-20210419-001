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
//�Ѽƫŧi
char buffer[ MAX_PATH ];
char *filePart;
char *path = FileListBox1->FileName.c_str();
//ȡ��������·��������·���ַ���Ŀ
unsigned int result = ::GetFullPathName(path,
                                        MAX_PATH,
                                        buffer,
                                        &filePart);
//��ʾ��Memo1��
Memo1->Lines->Add("�ļ�����" + AnsiString(filePart));
Memo1->Lines->Add("�ļ�����·��" + AnsiString(buffer));
Memo1->Lines->Add("�ļ�����·�����ַ���" + AnsiString(result));
}
//---------------------------------------------------------------------------
