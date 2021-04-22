//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main_c.h"
#include "time_c.hh"
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
  MyTime::Time_var tmp=MyTime::Time::_bind("TimeObject");
  MyTime::TimeOfDay tod = tmp->get_gmt();
  Edit1->Text=AnsiString(tod.hour)+":"+
             AnsiString(tod.minute)+":"+
             AnsiString(tod.second);
}
//---------------------------------------------------------------------------
