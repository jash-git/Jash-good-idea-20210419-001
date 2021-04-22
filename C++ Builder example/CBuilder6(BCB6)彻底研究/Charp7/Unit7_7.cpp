//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit7_7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


extern "C" __declspec(dllimport) void __stdcall CustomerForm(char *st);

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

  CustomerForm(Edit1->Text.c_str());
}
//---------------------------------------------------------------------------

