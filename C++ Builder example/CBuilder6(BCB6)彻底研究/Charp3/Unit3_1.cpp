//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_1.h"
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
void __fastcall TForm2::Button1Click(TObject *Sender)
{
  Label2->Caption=MaskEdit1->Text;
  Label4->Caption=MaskEdit2->Text;
  Label7->Caption=MaskEdit3->Text;
  Label8->Caption=MaskEdit4->Text;
}
//---------------------------------------------------------------------------



