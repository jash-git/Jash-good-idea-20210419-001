//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit21_11.h"
#include "Unit21_12.h"
#include "Unit21_13.h"
#include "Unit21_14.h"
#include "Unit21_15.h"
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
  Form2->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  Form2->QuickRep1->Print();    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Form3->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  Form3->QuickRep1->Print();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  Form4->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  Form4->QuickRep1->Print();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
  Form5->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
  Form5->QuickRep1->Print();
}
//---------------------------------------------------------------------------

