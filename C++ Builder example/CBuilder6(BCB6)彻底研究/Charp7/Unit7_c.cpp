//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit7_c.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool Drawing;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{

     Canvas->Pen->Width=Canvas->Pen->Width+1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{

     Canvas->Pen->Width=Canvas->Pen->Width-1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{

     N4->Checked=true;
     N5->Checked=false;
     Canvas->Pen->Color=clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{

     N4->Checked=false;
     N5->Checked=true;
     Canvas->Pen->Color=clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender)
{

     Canvas->Pen->Style=psDot;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender)
{

     Canvas->Pen->Style=psSolid;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{

      if (Drawing) Canvas->LineTo(X,Y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{

     if (Button==mbLeft) {
          Drawing=true;
          Canvas->MoveTo(X,Y);
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{

     if (Button==mbLeft) {
          Canvas->LineTo(X,Y);
          Drawing=false;
     }
}
//---------------------------------------------------------------------------
