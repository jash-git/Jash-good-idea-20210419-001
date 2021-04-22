//---------------------------------------------------------------------------
#include "Unit20_52.h"
#include "Unit20_51.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}

_di_IHeadLine TWebModule1::GetHeadLine()
{
  if (!FHeadLine)
  {
    HTTPRIO1->QueryInterface(FHeadLine);
  }
  return FHeadLine;
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::WebModule1QueryHeadLineAction(TObject *Sender,
      TWebRequest *Request, TWebResponse *Response, bool &Handled)
{
  AnsiString st;
  if (HeadLine) {
    st="<B>Delphi News : </B><BR><FONT COLOR=RED>"+HeadLine->DelphiNews(0)+"</FONT></P>"+
       "<B>C++ Builder News : </B><BR><FONT COLOR=RED>"+HeadLine->CBuilderNews(0)+"</FONT></P>"+
       "<B>JBuilder News : </B><BR><FONT COLOR=RED>"+HeadLine->JBuilderNews(0)+"</FONT></P>"+
       "<B>Kylix News : </B><BR><FONT COLOR=RED>"+HeadLine->KylixNews(0)+"</FONT></P>"+
       "<B>SOAP News : </B><BR><FONT COLOR=RED>"+HeadLine->SOAPNews(0)+"</FONT></P>"+
       "<B>Borland News : </B><BR><FONT COLOR=RED>"+HeadLine->BorConNews(0)+"</FONT>";
  }
  Response->Content=st;
}
//---------------------------------------------------------------------------

