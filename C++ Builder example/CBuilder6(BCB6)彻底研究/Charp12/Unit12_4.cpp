//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit12_4.h"
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
   CustOrders->Active = true;
   OrderDS->Active = true;
}
//---------------------------------------------------------------------------
