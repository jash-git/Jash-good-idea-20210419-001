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
//�Ƚ�����·��(AnsiString)ת�� char�ַ���
int leng = FileListBox1->FileName.Length();
char str[MAX_PATH];
for(int i=0;i<=leng;i++)
    {
    if(i==leng)
       str[i] = '\0';
    else
       str[i] = FileListBox1->FileName[i+1];
    }
//ȡ��ָ���ļ�handle
HANDLE fo = ::CreateFile(str,
                         GENERIC_READ | GENERIC_WRITE,
                         0,NULL,
                         OPEN_EXISTING,
                         FILE_FLAG_WRITE_THROUGH,
                         NULL);

BY_HANDLE_FILE_INFORMATION fd;
//ȡ��ָ���ļ�����
if(::GetFileInformationByHandle(fo, &fd))
    {
    //ȡ��ָ���ļ���״̬
    AnsiString string;
    switch(fd.dwFileAttributes)
         {
         case FILE_ATTRIBUTE_ARCHIVE:
              string = "���ļ����ڱ���״̬";
              break;
         case FILE_ATTRIBUTE_COMPRESSED:
              string = "���ļ�����ѹ��״̬";
              break;
         case FILE_ATTRIBUTE_DIRECTORY:
              string = "���ļ����ڲ�����״̬";
              break;
         case FILE_ATTRIBUTE_HIDDEN:
              string = "���ļ���������״̬";
              break;
         case FILE_ATTRIBUTE_NORMAL:
              string = "���ļ���������״̬";
              break;
         case FILE_ATTRIBUTE_OFFLINE:
              string = "���ļ���������״̬";
              break;
         case FILE_ATTRIBUTE_READONLY:
              string = "���ļ�����ֻ��״̬";
              break;
         case FILE_ATTRIBUTE_SYSTEM:
              string = "���ļ�����ϵͳ״̬";
              break;
         case FILE_ATTRIBUTE_TEMPORARY:
              string = "���ļ����ڻ���״̬";
              break;
         }
    //�ֱ��ļ�ϵͳ
    AnsiString nl;
    if(((int)fd.nNumberOfLinks)== 1)
       nl = "FAT";
    else
       nl = "NTFS";
    //�г�ָ���ļ�������Ϣ
    ListBox1->Items->Add(string);
    ListBox1->Items->Add("����ʱ��(L)" + AnsiString((int)fd.ftCreationTime.dwLowDateTime));
    ListBox1->Items->Add("����ʱ��(H)" + AnsiString((int)fd.ftCreationTime.dwHighDateTime));
    ListBox1->Items->Add("����ȡʱ��(L)�G" + AnsiString((int)fd.ftLastAccessTime.dwLowDateTime));
    ListBox1->Items->Add("����ȡʱ��(H)�G" + AnsiString((int)fd.ftLastAccessTime.dwHighDateTime));
    ListBox1->Items->Add("���д��ʱ��(L)�G" + AnsiString((int)fd.ftLastWriteTime.dwLowDateTime));
    ListBox1->Items->Add("���д��ʱ��(H)�G" + AnsiString((int)fd.ftLastWriteTime.dwHighDateTime));
    ListBox1->Items->Add("�ļ����к�" + AnsiString((int)fd.dwVolumeSerialNumber));
    ListBox1->Items->Add("�ļ���С(H)�G" + AnsiString((int)fd.nFileSizeHigh));
    ListBox1->Items->Add("�ļ���С(L)�G" + AnsiString((int)fd.nFileSizeLow));
    ListBox1->Items->Add("�ļ�ϵͳ" + nl);
    ListBox1->Items->Add("�������к�(H)�G" + AnsiString((int)fd.nFileIndexHigh));
    ListBox1->Items->Add("�������к�(L)�G" + AnsiString((int)fd.nFileIndexLow));
    }
else
    {
    ListBox1->Items->Add("�޷�ȡ�������ļ�����:");
    ListBox1->Items->Add(str);
    }
}
//---------------------------------------------------------------------------
