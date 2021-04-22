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
AnsiString dir;
//�ж��Ƿ��ڸ�Ŀ¼��
if(DirectoryListBox1->Directory.Length() != 3 )
   dir = DirectoryListBox1->Directory + "\\*.*";
else
   dir = DirectoryListBox1->Directory + "\*.*";
//ȡ�õ�һ���ļ�handle
WIN32_FIND_DATA Data;
HANDLE File = ::FindFirstFile(dir.c_str(), &Data);
//���ɹ�ȡ���ļ���handle
if(File != INVALID_HANDLE_VALUE)
   {
   //ɾ��ListBox1�������Ϯ�
   ListBox1->Clear();
   //������ļ�ʱ�ļ�Ŀ¼������뵽ListBox1����
   do
      {
      if((Data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
          && (String(Data.cFileName) != "..")
          && (String(Data.cFileName) != "."))
              ListBox1->Items->Add(Data.cFileName);
      } while(::FindNextFile(File, &Data)); //����һ���ļ���Ϣ
   
   
   //Ѱ�ҽ������ͷ�handle
   ::FindClose(File);
   //��������ʾ����
   StaticText2->Caption = DirectoryListBox1->Directory + "����" + AnsiString(ListBox1->Items->Count)+"����Ŀ¼";
   }
else //û���ҵ���Ŀ¼
   StaticText2->Caption = DirectoryListBox1->Directory + "���� 0 ����Ŀ¼";
}
//---------------------------------------------------------------------------

