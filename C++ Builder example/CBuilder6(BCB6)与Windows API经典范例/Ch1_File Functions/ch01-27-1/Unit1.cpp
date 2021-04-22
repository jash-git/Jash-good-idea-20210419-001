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
//ɾ��Memo1����������
Memo1->Clear();

char buffer[MAX_PATH];
char *filePart;
char *path;
AnsiString temp;
//��� path = NULL
// SearchPath ������ 1. Ӧ�ó��򱻼��ص�Ŀ¼ 2.Ŀǰ��Ŀ¼
//3.����ϵͳĿ¼ 4.����Ŀ¼ 5.path ����Ŀ¼ ��������
if(CheckBox1->Checked)
    path = NULL;
else
    {
    //�ж�path�Ƿ��ڸ�Ŀ¼
    if(DirectoryListBox1->Directory.Length()<4)
        temp = DirectoryListBox1->Directory;
    else
        temp = DirectoryListBox1->Directory +"\\";
    path = temp.c_str();
    }
//����ָ���ļ�
if(::SearchPath(path,// ������Ŀ¼
                Edit1->Text.c_str(),// ���������ļ���������
                NULL,	// ���������ļ���չ��
                MAX_PATH,// �ַ�����������С�p
                buffer,// �ַ���������
                &filePart// ����·��&�ļ���
                ))
    {
    Memo1->Lines->Add("�ļ�"+String(filePart)+"������·���ҵ���");
    Memo1->Lines->Add(buffer);
    }
else
    {
    if(path)
       Memo1->Lines->Add("��"+AnsiString(path)+" û���ҵ�"+Edit1->Text+"��");
    else
       Memo1->Lines->Add("���Զ������£�û���ҵ�"+Edit1->Text+"��");
    }

}
//---------------------------------------------------------------------------

