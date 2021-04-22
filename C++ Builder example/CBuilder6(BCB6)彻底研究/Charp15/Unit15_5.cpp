//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "Unit15_5.h"
#include "string.h";
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TCInfoModule *CInfoModule;
String ScriptName;

//---------------------------------------------------------------------------
__fastcall TCInfoModule::TCInfoModule(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustInfoModCreate(
      TObject *Sender)
{
  Customer->Open();
}
//---------------------------------------------------------------------------
void __fastcall TCInfoModule::CustomerListHTMLTag(TObject *Sender,
      TTag Tag, const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  AnsiString Temp;

  // 获取URL的路径与文件名
  ScriptName = ExtractFileName(Request->ScriptName);
  if (CompareText(TagString,"CUSTLIST")==0) {
    Temp="<FORM METHOD='GET' ACTION='"+ScriptName+"/runquery'>";
    Temp=Temp+"选择客户查询订单：<SELECT NAME='CustNo'>";
    Customer->First();
    while (!Customer->Eof) {
       Temp=Temp+"<OPTION VALUE='"+CustomerCustNo->AsString+"'>"
              +CustomerCompany->AsString;
       Customer->Next();
    }
    Temp=Temp+"</Select><INPUT TYPE='submit' VALUE='开始查询'></Form>";
  }
  ReplaceText=Temp;
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleCustomerlistAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  // 把PageProducer产生的客户资料(HTML格式)返回Web Server
  Response->Content=CustomerList->Content();
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleQueryActionAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  TLocateOptions SearchOptions;

  // 利用前一个Action传来的客户编号来查出客户资料 
  // 当查到客户资料时，这笔客户资料所对应的订单都会透过Query1
  // 被查询出来，而且查询出来的DataSet会被丢给QueryTableProducer
  // 自动转成HTML格式的资料，最后再传给Web Server。
  SearchOptions = SearchOptions<<loPartialKey;
  if (Customer->Locate("CustNo", StrToFloat(Request->QueryFields->Values
       ["CustNo"]),SearchOptions)) {
    CustomerOrders->Header->Clear();
    CustomerOrders->Header->Add("<HTML><H2>客户名称：" +
                    CustomerCompany->AsString+"</H2><HR>");
    CustomerOrders->Header->Add("<CENTER>客户订单查询结果</CENTER> \n");
    Response->Content=CustomerOrders->Content();
  } else
  Response->Content="<html><body><b>找不到刚才指定的客户</b></body> </html>";
}
//---------------------------------------------------------------------------










