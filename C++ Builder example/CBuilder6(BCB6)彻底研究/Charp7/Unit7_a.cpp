//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit7_a.h"
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

void __fastcall TForm1::Delphi301Click(TObject *Sender)
{
  Application->HelpContext(0);    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
  Application->HelpContext(100);    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
  Application->HelpContext(200);    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
  Application->HelpContext(300);
}
//---------------------------------------------------------------------------

