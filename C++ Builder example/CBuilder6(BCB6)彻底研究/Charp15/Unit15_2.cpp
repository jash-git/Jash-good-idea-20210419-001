//---------------------------------------------------------------------------
#include "Unit15_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::CInfoModuleWebActionItem1Action(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
 AnsiString temp;

 Table1->Open();
 Table1->Insert();

 Table1EmpNo->AsString=Request->QueryFields->Values["EmpNo"];
 Table1FirstName->AsString=Request->QueryFields->Values["FirstName"];
 Table1LastName->AsString=Request->QueryFields->Values["LastName"];
 Table1PhoneExt->AsString=Request->QueryFields->Values["PhoneExt"];
 Table1Salary->AsString=Request->QueryFields->Values["Salary"];

 Table1->Post();

 temp="<HTML>";
 temp=temp+"��ղ�������������£�<P>";
 temp=temp+"Ա����ţ�"+Request->QueryFields->Values["EmpNo"]+"<P>";
 temp=temp+"����������"+Request->QueryFields->Values["FirstName"]+"<P>";
 temp=temp+"Ӣ��������"+Request->QueryFields->Values["LastName"]+"<P>";
 temp=temp+"�绰�ֻ���"+Request->QueryFields->Values["PhoneExt"]+"<P>";
 temp=temp+"ÿ�¹��ʣ�"+Request->QueryFields->Values["Salary"]+"<P>";
 temp=temp+"���������Ѿ���д��BCDEMOS��Employee.DB���ݱ��ڣ�<P>";
 temp=temp+"</HTML>";

 Response->Content=temp;
}
//---------------------------------------------------------------------------

