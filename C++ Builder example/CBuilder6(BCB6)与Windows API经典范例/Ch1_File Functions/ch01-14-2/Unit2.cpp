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
//ת��AnsiString��char�ַ���
char *filename=FileListBox1->FileName.c_str();
//ȡ���ļ�handle
HANDLE hFile = ::CreateFile(filename,
                            GENERIC_READ, 0, 0,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, 0);
//ȡ���ļ���С�פj�p
DWORD dwFileLen = ::GetFileSize(hFile, 0);
//�ͷ�handle
::CloseHandle(hFile);
//��ʾ�ļ���С�פj�p
Memo1->Clear();
Memo1->Lines->Add("�ļ�·����" + FileListBox1->FileName);
Memo1->Lines->Add("�ļ���С��" + AnsiString((long)dwFileLen) + "���ֽ���");

}
//---------------------------------------------------------------------------
