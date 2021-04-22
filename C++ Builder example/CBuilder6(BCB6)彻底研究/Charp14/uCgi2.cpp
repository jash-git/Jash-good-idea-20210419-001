//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#pragma hdrstop

#include "uCgi2.h"
#include "util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormCreate(TObject *Sender)
{
   ITEM item[MAX_ITEM];
   char s1[10][255],*s2;
   int i,ItemCount;

   // ȡ������������Ҫ�󷽷�
   s2="REQUEST_METHOD";
   GetEnvironmentVariable(s2,s1[0],250);

   // ȡ�������������ŷ�������
   s2="SERVER_NAME";
   GetEnvironmentVariable(s2,s1[1],250);

   // ȡ������������ǰ�˵���λַ
   s2="REMOTE_ADDR";
   GetEnvironmentVariable(s2,s1[2],250);

   // ȡ������������ǰ��ʹ�������������
   s2="QUERY_STRING";
   GetEnvironmentVariable(s2,s1[3],250);

   // ��QueryString�س�һ�ζε�section,���Ұ�ASCII���뻹ԭ
   ItemCount=cut_string(s1[3],item);

   // ���� BCDEMOS ��Customer���ϱ�
   Table1->Open();
   Table1->Insert();

   // ��ǰ�˴�����QueryString������Customer���ϱ���
   for(i=0; i<ItemCount-1; i++) {
       Table1->FieldByName(item[i].name)->AsString=StrPas(item[i].value);
   }
   Table1->Post();

   // ���HTTP����Ҫ�ı�ͷ
   printf("Content-type: text/html%c%c\n",10,10);

   // �����ʽ��HTML�ļ�����
   printf("<HTML>\n");
   printf("<TITLE>C++ Builder׫дCGI�ķ�����ʽ</TITLE>\n");
   printf("ʹ�÷�����<B>%s</B>.<BR>\n",s1[0]);
   printf("���������ƣ�<B>%s</B>.<BR>\n",s1[1]);
   printf("�ͻ����û���ַ��<B>%s</B>.<P>\n",s1[2]);
   printf("�û������ַ�����<P>\n");
   for(i=0; i<ItemCount-1; i++)
     printf("  <B>%s</B>.<P>\n",item[i].value);
   printf("<HR>\n");
   printf("<H1>���ղ�����������Ѿ���д������������ݿ��ڣ�\n");
   printf("</HTML>\n");
}
//---------------------------------------------------------------------------

