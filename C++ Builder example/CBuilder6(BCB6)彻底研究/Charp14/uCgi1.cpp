//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#pragma hdrstop

#include "uCgi1.h"
#include "util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
   ITEM item[MAX_ITEM];
   char s1[10][255],*s2;

   // ȡ������������Ҫ�󷽷�
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

   // ��QueryString�س�һ�ζε�section,���Ұ�ASCII���뻹ԭ
   cut_string(s1[3],item);

   // ���HTTP����Ҫ�ı�ͷ
   printf("Content-type: text/html%c%c\n",10,10);

   // �����ʽ��HTML�ĵ�����
   printf("<HTML>\n");
   printf("<TITLE>C++ Builder��дCGI�ķ�������</TITLE>\n");
   printf("ʹ�÷�����<B>%s</B>.<BR>\n",s1[0]);
   printf("���������ƣ�<B>%s</B>.<BR>\n",s1[1]);
   printf("�ͻ����û���ַ��<B>%s</B>.<P>\n",s1[2]);
   printf("�û������ַ�����\n");
   printf("%s=%s\n",item[0].name,item[0].value);
   printf("%s=%s\n",item[1].name,item[1].value);
   printf("%s=%s\n",item[2].name,item[2].value);
   printf("</HTML>\n");
}
//---------------------------------------------------------------------------

