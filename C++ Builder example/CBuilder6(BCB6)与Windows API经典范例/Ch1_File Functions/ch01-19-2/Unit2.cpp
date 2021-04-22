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
//ɾ��Memo1����������
Memo1->Clear();
//��ʾָ��Ŀ¼��������·��
Memo1->Lines->Add("������������·����");
Memo1->Lines->Add(GetAppNamePath(false));
Memo1->Lines->Add(" ");
//��ʾָ��Ŀ¼��DOS(8.3)·��
Memo1->Lines->Add("������DOS(8.3)·����");
Memo1->Lines->Add(GetAppNamePath(true));
}
//---------------------------------------------------------------------------
AnsiString TForm1::GetAppNamePath(bool bName)
{
AnsiString dire;
//�ж��Ƿ��ڸ�Ŀ¼�¤U
if(DirectoryListBox1->Directory.Length() < 4 )
   dire = DirectoryListBox1->Directory;
else
   dire = DirectoryListBox1->Directory + "\\";

char Buffer[MAX_PATH];
AnsiString path = "";
if (bName)
    {
    //·��ת���� 8.3 ��ʽ
    ::GetShortPathName(dire.c_str(), Buffer, sizeof(Buffer));
    //����Ƿ�Ϊ��Ŀ¼orĿ¼or�ļ�or��չ��
    path = GetThisPath((AnsiString)Buffer,false);
    }
  else
    path = GetThisPath(dire.c_str(), false);
  return path;
}
//---------------------------------------------------------------------------
//�жϸ�Ŀ¼orĿ¼or�ļ�or��չ�����������ַ���
AnsiString TForm1::GetThisPath(AnsiString path, bool bFileName)
{
AnsiString result = "";
try
  {
  char drive[MAXDRIVE];
  char dir[MAXDIR];
  char file[MAXFILE];
  char ext[MAXEXT];
  //�жϸ�Ŀ¼orĿ¼or�ļ�or��չ�����������ַ���
  int flags = fnsplit(path.c_str(),drive,dir,file,ext);
  if(flags & DRIVE) result += drive;
  if(flags & DIRECTORY) result += dir;
  //�ж��Ƿ�Ҫ�����ļ�or��չ���W
  if (bFileName)
     {
     if(flags & FILENAME) result += file;
     if(flags & EXTENSION) result += ext;
     }
  }
catch(...)
  {
  result = "";
  }
return result;
}
