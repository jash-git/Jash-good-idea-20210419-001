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

   // 取出环境叁数：前端使用者输入的资料
   s2="QUERY_STRING";
   GetEnvironmentVariable(s2,s1[3],250);

   // 把QueryString截成一段段的section,并且把ASCII编码还原
   cut_string(s1[3],item);

   // 输出HTTP所需要的表头
   printf("Content-type: text/html%c%c\n",10,10);

   // 输出正式的HTML文件数据
   printf("<HTML>\n");
   printf("<TITLE>C++ Builder编写CGI的范例程序</TITLE>\n");
   printf("<H1>查询结果</H1>\n");
   printf("<CENTER><TABLE BORDER=1 Width=400 Height=150>\n");
   printf("<TR><TH>客户代码</TH><TH>公司名称</TH><TH>联系人</TH><TH>电话</TH></TR>\n");

   // 加入查询用的 SQL 命令
   Query1->SQL->Clear();
   Query1->SQL->Add("select CustNo,Company,Contact,Phone from customer\n");
   temp=AnsiString("where ")+item[0].value+
        AnsiString(" like '")+item[1].value+
        AnsiString("%'");
   Query1->SQL->Add(temp);
   Query1->Open();

   // 把查询结果 dataset 转成 HTML 资料
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


