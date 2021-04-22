//---------------------------------------------------------------------------
#include "Unit20_42.h"
#include "Unit20_41.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}

_di_IQueryCapital TWebModule1::GetQueryCapital()
{
  if (!FQueryCapital)
  {
    HTTPRIO1->QueryInterface(FQueryCapital);
  }
  return FQueryCapital;
}

AnsiString TWebModule1::fQueryCountry()
{
  int i;
  AnsiString rt;
  TStringList *st=new TStringList();

  rt="<html><form action='http://localhost/CBuilderWeb/Project20_4.exe/QueryCapital' method=POST><select name='Country'>";
  if (QueryCapital) {
    st->Text=QueryCapital->QueryCountry();
    for(i=0;i<st->Count-1;i++)
    {
      rt=rt+"<option value='"+st->Strings[i]+
         "'>"+st->Strings[i]+"</option>";
    }
  }
  rt=rt+"<input type='submit' name='Submit' value='查询对应的首都名称'>"+
     "</select></form></html>";
  delete st;
  return rt;
}

//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1QueryCountryAction(TObject *Sender,
      TWebRequest *Request, TWebResponse *Response, bool &Handled)
{
  Response->Content=fQueryCountry();
}
//---------------------------------------------------------------------------


void __fastcall TWebModule1::WebModule1QueryCapitalAction(TObject *Sender,
      TWebRequest *Request, TWebResponse *Response, bool &Handled)
{
  Response->Content=fQueryCountry();
  if (QueryCapital) {
    Response->Content=Response->Content+"国家"+Request->ContentFields->Values["Country"]+
      "的首都是"+QueryCapital->QueryCapital(Request->ContentFields->Values["Country"]);
  }
}
//---------------------------------------------------------------------------


