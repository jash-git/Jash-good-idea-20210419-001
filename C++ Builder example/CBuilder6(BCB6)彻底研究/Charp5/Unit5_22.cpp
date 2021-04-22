//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_22.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{

    Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N6Click(TObject *Sender)
{

    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N7Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
