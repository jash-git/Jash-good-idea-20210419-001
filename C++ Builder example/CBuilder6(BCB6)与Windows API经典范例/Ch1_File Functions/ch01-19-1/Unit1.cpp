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
//��������
char longfilename[MAX_PATH];
char shortfilename[MAX_PATH];
TSearchRec SearchRecord;
AnsiString sfn,sfd;
//�ж��Ƿ��ڸ�Ŀ¼��
if(DirectoryListBox1->Directory.Length() < 4 )
   {
   sfn = String(DriveComboBox1->Drive) +":\\*.*";
   sfd = String(DriveComboBox1->Drive) +":\\";
   }
else
   {
   sfn = DirectoryListBox1->Directory + "\\*.*";
   sfd = DirectoryListBox1->Directory + "\\" ;
   }
//ɾ��ListBox1����������
ListBox1->Clear();
//��ʼѰ�ҵ�һ�������������ļ�
if (::FindFirst(sfn.c_str(), faAnyFile, SearchRecord) == 0)
     {
     strcpy(longfilename, sfd.c_str());
     strcat(longfilename, SearchRecord.Name.c_str());
     //ת���� 8.3 ��ʽ
     ::GetShortPathName(longfilename, shortfilename, MAX_PATH);
     //��ʾ��ListBox1��
     ListBox1->Items->Add(ExtractFileName(shortfilename));
     //��ʼѰ����һ���ļ���ѭ��
     while (::FindNext(SearchRecord) == 0)
          {
          strcpy(longfilename,  sfd.c_str());
          strcat(longfilename, SearchRecord.Name.c_str());
          //ת���� 8.3 ��ʽ
          ::GetShortPathName(longfilename, shortfilename, MAX_PATH);
          //��ʾ��ListBox1��
          ListBox1->Items->Add(ExtractFileName(shortfilename));
          }
     }
}
//---------------------------------------------------------------------------
