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
//����ʾ��������ʾ
ListBox1->Items->Add("������ü��±��򿪴�TMP�ļ���");

char TempPath[MAX_PATH], TempFileName[MAX_PATH];
//ȡ��ϵͳĬ�ϵĻ���Ŀ¼·��
if((int)::GetTempPath( sizeof(TempPath), TempPath))
   ListBox1->Items->Add("����Ŀ¼��"+ AnsiString(TempPath));
else
   ListBox1->Items->Add("û�з��ֻ���Ŀ¼(*:\TEMP\)");
//����һ��Ωһ���ƵĻ����ļ�����"TXTXXXX.tmp"
::GetTempFileName(TempPath, "TXT", 0, TempFileName);
ListBox1->Items->Add("������ȫ·����"+ AnsiString(TempFileName));

//FileCreate(..),FileWrite(..),FileClose(..)������
//��ΪBCB SysUtils ������������ Help
//��ĳЩ���ݴ���˻����ļ���
int TxtFile = FileCreate(AnsiString(TempFileName));
//��������ListBox1�ϵ����֣�д��˻�������
for(int i = 0; i < ListBox1->Items->Count; ++i)
    {
    String str = ListBox1->Items->Strings[i] + "\r\n";
    FileWrite(TxtFile, str.c_str(), str.Length());
    }
//�رմ˻����ļ�
FileClose(TxtFile);
}
//---------------------------------------------------------------------------
