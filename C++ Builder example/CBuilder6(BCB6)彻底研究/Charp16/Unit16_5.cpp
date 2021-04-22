//---------------------------------------------------------------------------
#include "Unit16_5.h"
#include "Project16_1_TLB.h"
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
void __fastcall TWebModule1::WebModule1WebActionItem1Action(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  Variant INPUT,temp;
  IInterExpressSerDisp ApSer;

  INPUT=Request->ContentFields->Text;
  SocketConnection1->Connected=True;
  ApSer.Bind(SocketConnection1->GetServer());
  temp=ApSer->PostCountry(INPUT);
  SocketConnection1->Connected=False;
  Response->Content=temp;
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::WebModule1WebActionItem3Action(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  Variant INPUT,temp;
  IInterExpressSerDisp ApSer;

  INPUT=Request->ContentFields->Text;
  SocketConnection1->Connected=True;
  ApSer.Bind(SocketConnection1->GetServer());
  temp=ApSer->QueryCountry();
  SocketConnection1->Connected=False;
  Response->Content=InetXPageProducer1->Content()+temp;
}
//---------------------------------------------------------------------------

