//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit21_5.h"
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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  int i;
  double v;
  
  Timer1->Interval=1000;
  Timer1->Enabled=false;

  Timer1->Enabled=False;
     for (i=0; i<20; i++) {
         v=random(100)*1.0;
         Series1->AddY(v,"",clRed);
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  double tmpX;
  int t;

  for (t=0; t<(Chart1->SeriesCount()); t++) {
    tmpX=(Chart1->Series[t]->XValues->Value[1])-
         (Chart1->Series[t]->XValues->Value[0]);

    Chart1->Series[t]->Delete(0);

    Chart1->Series[t]->AddXY( Chart1->Series[t]->XValues->Last()+tmpX,
        Chart1->Series[t]->YValues->Last()+random(100)-50,"",clRed);
  }
}
//---------------------------------------------------------------------------
