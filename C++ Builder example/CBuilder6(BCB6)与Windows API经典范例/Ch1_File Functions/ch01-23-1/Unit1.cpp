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

//ȡ��ָ���ļ�������·��
char c[MAX_PATH];
char *s = "/Ghostfaq.txt";
//����������Ŀ¼����������ַ�����C
::GetCurrentDirectory(MAX_PATH,c);
//������Ŀ¼����ָ���ļ���
strcat( c, s);

//��ָ���ļ��������ؼ��ֵ
HANDLE hfp = ::CreateFile( c,
                           GENERIC_READ | GENERIC_WRITE,
                           0,
                           0,
                           OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL,
                           0);
//���޷���ָ���ļ�
if (hfp == INVALID_HANDLE_VALUE)
   {
   Memo1->Lines->Add("�ڴ˳�����ͬĿ¼�£�δ����Ghostfaq.txt��");
   Memo1->Lines->Add("Ҫ���Ա����������Լ��±�����Ghostfaq.txt��");
   }
//��סָ���ļ������ô�orִ��
else if(::LockFile( hfp, (DWORD)100, (DWORD)0, (DWORD)200, (DWORD)0))
   Memo1->Text = "�Ѿ���סĿǰĿ¼�µ�Ghostfaq.txt";
else
   Memo1->Text = "�޷���סĿǰĿ¼�µ�Ghostfaq.txt";
//С��ʾ��
Memo1->Lines->Add("����ģ��رձ�����ʱ�������Ghostfaq.txt��������");
}
//---------------------------------------------------------------------------
