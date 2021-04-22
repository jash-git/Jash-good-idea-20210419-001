//---------------------------------------------------------------------------
#include "Unit15_4.h"
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
  char* filename = new char[MAX_PATH- 1];
  Customer->Open();
  GetModuleFileName(HInstance, filename,MAX_PATH-1);
  ScriptName = ExtractFileName(filename);
  delete[] filename;
}
//---------------------------------------------------------------------------
void __fastcall TCInfoModule::CustomerListHTMLTag(TObject *Sender,
      TTag Tag, const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  String Customers = "";
  if (CompareText(TagString, AnsiString("CUSTLIST")) == 0)
  {
    Customers = "";
    Customer->First();
    while ( !( Customer->Eof ) )
    {
      Customers = Customers + "<A HREF=/CBuilderWeb/" + ScriptName + "/runquery?CustNo=" +
                  CustomerCustNo->AsInteger + ">" + CustomerCompany->AsString.c_str() +
                  "</A><BR>";
      Customer->Next();
    }
  }
  ReplaceText = Customers;
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleCustomerlistAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  Response->Content = CustomerList->Content();
}
//---------------------------------------------------------------------------

void __fastcall TCInfoModule::CustomerInfoModuleQueryActionAction(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  TLocateOptions SearchOptions = SearchOptions<<(TLocateOption)NULL;
  if (Customer->Locate( AnsiString("CustNo"),
                        Request->QueryFields->Values[AnsiString("CustNo")],
                        SearchOptions))
  {
    CustomerOrders->Header->Clear();
    CustomerOrders->Header->Add(AnsiString("客户订单查询结果<P>"));
    CustomerOrders->Header->Add(AnsiString("客户名称: " +
                    Customer->Fields->FieldByName("Company")->Value));
    Response->Content = CustomerOrders->Content();
  }
  else
  {
    Response->Content = "<html><body><b>找不到刚才指定的客户</b></body></html>";
  }
}
//---------------------------------------------------------------------------


