//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_8.h"
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

void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    Edit1->Text="";
    if (Shift.Contains(ssAlt)) Label1->Caption="Alt";
      else if (Shift.Contains(ssShift)) Label1->Caption="Shift";
        else if (Shift.Contains(ssCtrl)) Label1->Caption="Ctrl" ;
          else Label1->Caption="";
     Label2->Caption=Char(Key);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
     Label2->Caption=Key;
     if (Key==13) Label2->Caption="Enter";
     if (Key==27) Label2->Caption="ESC";
     if (Key==20) Label2->Caption="Space";
     Label3->Caption=IntToStr(Key);
}
//---------------------------------------------------------------------------
