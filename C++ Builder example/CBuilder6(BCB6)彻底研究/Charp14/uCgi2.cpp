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

   // 取出环境叁数：要求方法
   s2="REQUEST_METHOD";
   GetEnvironmentVariable(s2,s1[0],250);

   // 取出环境叁数：伺服器名称
   s2="SERVER_NAME";
   GetEnvironmentVariable(s2,s1[1],250);

   // 取出环境叁数：前端电脑位址
   s2="REMOTE_ADDR";
   GetEnvironmentVariable(s2,s1[2],250);

   // 取出环境叁数：前端使用者输入的资料
   s2="QUERY_STRING";
   GetEnvironmentVariable(s2,s1[3],250);

   // 把QueryString截成一段段的section,并且把ASCII编码还原
   ItemCount=cut_string(s1[3],item);

   // 开启 BCDEMOS 的Customer资料表
   Table1->Open();
   Table1->Insert();

   // 把前端传来的QueryString新增到Customer资料表内
   for(i=0; i<ItemCount-1; i++) {
       Table1->FieldByName(item[i].name)->AsString=StrPas(item[i].value);
   }
   Table1->Post();

   // 输出HTTP所需要的表头
   printf("Content-type: text/html%c%c\n",10,10);

   // 输出正式的HTML文件资料
   printf("<HTML>\n");
   printf("<TITLE>C++ Builder撰写CGI的范例程式</TITLE>\n");
   printf("使用方法：<B>%s</B>.<BR>\n",s1[0]);
   printf("服务器名称：<B>%s</B>.<BR>\n",s1[1]);
   printf("客户端用户地址：<B>%s</B>.<P>\n",s1[2]);
   printf("用户输入字符串：<P>\n");
   for(i=0; i<ItemCount-1; i++)
     printf("  <B>%s</B>.<P>\n",item[i].value);
   printf("<HR>\n");
   printf("<H1>您刚才输入的数据已经被写入服务器端数据库内！\n");
   printf("</HTML>\n");
}
//---------------------------------------------------------------------------

