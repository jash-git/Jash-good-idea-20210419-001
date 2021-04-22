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

  // ��ȡURL��·�����ļ���
  ScriptName = ExtractFileName(Request->ScriptName);
  if (CompareText(TagString,"CUSTLIST")==0) {
    Temp="<FORM METHOD='GET' ACTION='"+ScriptName+"/runquery'>";
    Temp=Temp+"ѡ��ͻ���ѯ������<SELECT NAME='CustNo'>";
    Customer->First();
    while (!Customer->Eof) {
       Temp=Temp+"<OPTION VALUE='"+CustomerCustNo->AsString+"'>"
              +CustomerCompany->AsString;
       Customer->Next();
    }
    Temp=Temp+"</Select><INPUT TYPE='submit' VALUE='��ʼ��ѯ'></Form>";
  }
  ReplaceText=Temp;
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleCustomerlistAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  // ��PageProducer�����Ŀͻ�����(HTML��ʽ)����Web Server
  Response->Content=CustomerList->Content();
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleQueryActionAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  TLocateOptions SearchOptions;

  // ����ǰһ��Action�����Ŀͻ����������ͻ����� 
  // ���鵽�ͻ�����ʱ����ʿͻ���������Ӧ�Ķ�������͸��Query1
  // ����ѯ���������Ҳ�ѯ������DataSet�ᱻ����QueryTableProducer
  // �Զ�ת��HTML��ʽ�����ϣ�����ٴ���Web Server��
  SearchOptions = SearchOptions<<loPartialKey;
  if (Customer->Locate("CustNo", StrToFloat(Request->QueryFields->Values
       ["CustNo"]),SearchOptions)) {
    CustomerOrders->Header->Clear();
    CustomerOrders->Header->Add("<HTML><H2>�ͻ����ƣ�" +
                    CustomerCompany->AsString+"</H2><HR>");
    CustomerOrders->Header->Add("<CENTER>�ͻ�������ѯ���</CENTER> \n");
    Response->Content=CustomerOrders->Content();
  } else
  Response->Content="<html><body><b>�Ҳ����ղ�ָ���Ŀͻ�</b></body> </html>";
}
//---------------------------------------------------------------------------










