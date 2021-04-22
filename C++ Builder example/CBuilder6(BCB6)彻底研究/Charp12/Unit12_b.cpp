//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit12_b.h"
#include "Project12_a_TLB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  AnsiString s;

  TCOMITest12aServer Test12aServer=CoTest12aServer::Create();
  s=Variant(Test12aServer->GetName());
  ShowMessage(s);
}
//---------------------------------------------------------------------------
 