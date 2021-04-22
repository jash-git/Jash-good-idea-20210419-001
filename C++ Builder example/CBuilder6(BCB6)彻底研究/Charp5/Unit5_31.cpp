//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_31.h"
#include "Unit5_32.h"
#include "Unit5_33.h"
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

void __fastcall TForm1::A2Click(TObject *Sender)
{
    Form3->ShowModal();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Logo1Click(TObject *Sender)
{
    Form2->ShowModal();
}
//---------------------------------------------------------------------------


