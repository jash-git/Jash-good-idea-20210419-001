//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "uCgi0.h"
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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   char s1[10][255],*s2;

   // ȡ���������������󷽷�
   s2="REQUEST_METHOD";
   GetEnvironmentVariable(s2,s1[0],250);

   // ȡ����������������������
   s2="SERVER_NAME";
   GetEnvironmentVariable(s2,s1[1],250);

   // ȡ�������������ͻ��˼������ַ
   s2="REMOTE_ADDR";
   GetEnvironmentVariable(s2,s1[2],250);

   // ȡ�������������ͻ����û����������
   s2="QUERY_STRING";
   GetEnvironmentVariable(s2,s1[3],250);

   // ���HTTP����Ҫ�ı�ͷ
   printf("Content-type: text/html%c%c\n",10,10);

   // �����ʽ��HTML�ĵ�����
   printf("<HTML>\n");
   printf("<TITLE>C++ Builder��дCGI�ķ�������</TITLE>\n");
   printf("ʹ�÷�����<B>%s</B>.<BR>\n",s1[0]);
   printf("���������ƣ�<B>%s</B>.<BR>\n",s1[1]);
   printf("�ͻ����û���ַ��<B>%s</B>.<P>\n",s1[2]);
   printf("�û������ַ�����<B>%s</B>, <P>\n",s1[3]);
   printf("</HTML>\n");
}
//---------------------------------------------------------------------------

