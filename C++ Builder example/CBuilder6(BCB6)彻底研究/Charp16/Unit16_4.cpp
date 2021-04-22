//---------------------------------------------------------------------------
#include "Unit16_4.h"
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
  Variant DEPT_NO,FULL_NAME,temp;
  IInterExpressSerDisp ApSer;

  DEPT_NO=Request->ContentFields->Values["DEPT_NO"];
  FULL_NAME=Request->ContentFields->Values["FULL_NAME"];
  SocketConnection1->Connected=True;
  ApSer.Bind(SocketConnection1->GetServer());
  temp=ApSer->QueryEmployee(DEPT_NO,FULL_NAME);
  SocketConnection1->Connected=False;
  Response->Content=InetXPageProducer1->Content()+temp;
}
//---------------------------------------------------------------------------

