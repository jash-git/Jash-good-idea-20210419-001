//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit10_51.h"
#include "Unit10_52.h"
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
     Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
     Database1->Connected=false;
     Form2->Edit1->Text="";
     Form2->Edit2->Text="";
}
//---------------------------------------------------------------------------
