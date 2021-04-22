#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include "Unit16_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------void __fastcall TWebModule1::AddScript(void * Data, _di_IAddScriptElements AddScriptElements)

void __fastcall TWebModule1::InetXPageProducer2HTMLTag(TObject *Sender,
      TTag Tag, const AnsiString TagString, TStrings *TagParams,
      AnsiString &ReplaceText)
{
  if (TagString=="EMPLOYEE") {
    XMLBroker1->Connected=True;
    ReplaceText=InetXPageProducer1->Content();
  }  
}
//---------------------------------------------------------------------------

