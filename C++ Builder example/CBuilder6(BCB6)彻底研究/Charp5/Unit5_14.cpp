//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_14.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cgauges"
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
int i;

for(i=1; i<=100; i++) {
   CGauge1->Progress++;
   CGauge2->Progress++;
   CGauge3->Progress++;
   CGauge4->Progress++;
}

}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
   CGauge1->Progress=0;
   CGauge2->Progress=0;
   CGauge3->Progress=0;
   CGauge4->Progress=0;
}
//---------------------------------------------------------------------------
