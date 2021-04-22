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
 temp=temp+"你刚才填入的数据如下：<P>";
 temp=temp+"员工编号："+Request->QueryFields->Values["EmpNo"]+"<P>";
 temp=temp+"中文姓名："+Request->QueryFields->Values["FirstName"]+"<P>";
 temp=temp+"英文姓名："+Request->QueryFields->Values["LastName"]+"<P>";
 temp=temp+"电话分机："+Request->QueryFields->Values["PhoneExt"]+"<P>";
 temp=temp+"每月工资："+Request->QueryFields->Values["Salary"]+"<P>";
 temp=temp+"这条数据已经被写到BCDEMOS的Employee.DB数据表内！<P>";
 temp=temp+"</HTML>";

 Response->Content=temp;
}
//---------------------------------------------------------------------------

