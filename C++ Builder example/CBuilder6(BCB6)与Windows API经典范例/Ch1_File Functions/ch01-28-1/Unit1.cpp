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
//ɾ��Memo1��������
Memo1->Clear();

char c[MAX_PATH];
//ȡ��Ŀǰ����Ŀ¼
if(::GetCurrentDirectory(MAX_PATH,c))
    {
    Memo1->Lines->Add("ȡ��Ŀǰ����Ŀ¼��");
    Memo1->Lines->Add(AnsiString(c));
    Memo1->Lines->Add("-------------------------");
    //������������Ŀ¼
    if(::SetCurrentDirectory("C:\\Temp\\"))
       {
       if(::GetCurrentDirectory(MAX_PATH,c))
           {
           //���ı������Ŀ¼����Ӧ��DirectoryListBox1�����
           DirectoryListBox1->Directory = AnsiString(c);
           Memo1->Lines->Add("������ָ��Ŀ¼�ڣ�");
           Memo1->Lines->Add(AnsiString(c));
           }
       }
    else
       Memo1->Lines->Add("������ָ��Ŀ¼ʧ�ܣ�");
    }
else
    Memo1->Lines->Add("ȡ��ĿǰĿ¼ʧ�ܣ�");
}
//---------------------------------------------------------------------------
