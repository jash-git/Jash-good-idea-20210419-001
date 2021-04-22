#include <vcl.h>
#pragma hdrstop

#include "Unit11_8.h"
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

  StartDate->Text = DateToStr(EncodeDate(1996,6,19));
  EndDate->Text = DateToStr(EncodeDate(1996,6,21));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ShowEventsClick(TObject *Sender)
{
  Variant sDate, eDate;
  Variant Params;
  Variant tmpParams;

  Events->Close();


  Events->Params->ParamByName("Start_Date")->Value=StartDate->Text;
  Events->Params->ParamByName("End_Date")->Value=EndDate->Text;


  Events->Open();
}
//---------------------------------------------------------------------------
