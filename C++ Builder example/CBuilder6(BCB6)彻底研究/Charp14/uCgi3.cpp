//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#pragma hdrstop

#include "uCgi3.h"
#include "util.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender)
{
   ITEM item[MAX_ITEM];
   char s1[10][255],*s2;
   int i,j;
   AnsiString temp;

   // ȡ������������ǰ��ʹ�������������
   s2="QUERY_STRING";
   GetEnvironmentVariable(s2,s1[3],250);

   // ��QueryString�س�һ�ζε�section,���Ұ�ASCII���뻹ԭ
   cut_string(s1[3],item);

   // ���HTTP����Ҫ�ı�ͷ
   printf("Content-type: text/html%c%c\n",10,10);

   // �����ʽ��HTML�ļ�����
   printf("<HTML>\n");
   printf("<TITLE>C++ Builder��дCGI�ķ�������</TITLE>\n");
   printf("<H1>��ѯ���</H1>\n");
   printf("<CENTER><TABLE BORDER=1 Width=400 Height=150>\n");
   printf("<TR><TH>�ͻ�����</TH><TH>��˾����</TH><TH>��ϵ��</TH><TH>�绰</TH></TR>\n");

   // �����ѯ�õ� SQL ����
   Query1->SQL->Clear();
   Query1->SQL->Add("select CustNo,Company,Contact,Phone from customer\n");
   temp=AnsiString("where ")+item[0].value+
        AnsiString(" like '")+item[1].value+
        AnsiString("%'");
   Query1->SQL->Add(temp);
   Query1->Open();

   // �Ѳ�ѯ��� dataset ת�� HTML ����
   Query1->First();
   while(!Query1->Eof) {
       printf("<TR>");
       for(j=0; j<Query1->FieldCount-1; j++) {
         temp="<TD>"+Query1->Fields->Fields[j]->AsString+"</TD>\n";
         printf(temp.c_str());
       }
       printf("</TR>\n");
       Query1->Next();
   }
   printf("</TABLE>\n");
   printf("</CENTER></HTML>\n");
   Query1->Close();
}
//---------------------------------------------------------------------------


