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

   // 取出环境参数：要求方法
   s2="REQUEST_METHOD";
   GetEnvironmentVariable(s2,s1[0],250);

   // 取出环境参数：服务器名称
   s2="SERVER_NAME";
   GetEnvironmentVariable(s2,s1[1],250);

   // 取出环境参数：客户端计算机地址
   s2="REMOTE_ADDR";
   GetEnvironmentVariable(s2,s1[2],250);

   // 取出环境参数：客户端用户输入的数据
   s2="QUERY_STRING";
   GetEnvironmentVariable(s2,s1[3],250);

   // 把QueryString截成一段段的section,并且把ASCII编码还原
   cut_string(s1[3],item);

   // 输出HTTP所需要的表头
   printf("Content-type: text/html%c%c\n",10,10);

   // 输出正式的HTML文档数据
   printf("<HTML>\n");
   printf("<TITLE>C++ Builder编写CGI的范例程序</TITLE>\n");
   printf("使用方法：<B>%s</B>.<BR>\n",s1[0]);
   printf("服务器名称：<B>%s</B>.<BR>\n",s1[1]);
   printf("客户端用户地址：<B>%s</B>.<P>\n",s1[2]);
   printf("用户输入字符串：\n");
   printf("%s=%s\n",item[0].name,item[0].value);
   printf("%s=%s\n",item[1].name,item[1].value);
   printf("%s=%s\n",item[2].name,item[2].value);
   printf("</HTML>\n");
}
//---------------------------------------------------------------------------

