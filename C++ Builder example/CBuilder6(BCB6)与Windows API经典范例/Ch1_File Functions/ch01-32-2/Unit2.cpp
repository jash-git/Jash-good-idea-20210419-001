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
//Ĭ����C:\Temp\�½������ļ�
AnsiString fileName="C:\\Temp\\test.txt";
DWORD BytesWritten;
//����һ���ļ��������ش����ļ�handle
HANDLE HFile=::CreateFile(fileName.c_str(),GENERIC_WRITE,
                          FILE_SHARE_READ,NULL,
                          CREATE_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH,
                          NULL);
//���������ļ�handle���������������
if(HFile!=INVALID_HANDLE_VALUE)
    {
    //���ַ������ַ�������
    char text[4096] = "";
    int leng = 25, a = 0;
    while(leng<4096)
       {
       AnsiString str = "���ǵ� " + AnsiString(++a) + "���ַ�����\n";
       strcat(text,str.c_str());
       leng += str.Length();
       }
    //��text�ַ��������뵽ָ���ļ���
    if(::WriteFile(HFile,text,sizeof(text),&BytesWritten,NULL) ||
       sizeof( text) == BytesWritten)
          Memo1->Lines->Add("�ɹ���"+AnsiString(a)+" ���ַ������뵽ָ���ļ��С�");
       else
          Memo1->Lines->Add("�ַ����޷����뵽�ļ��С�");
    }
else
    Memo1->Lines->Add("�޷�����һ���ı��ļ���");

//�ͷ�handle
::CloseHandle(HFile);
}
//---------------------------------------------------------------------------
