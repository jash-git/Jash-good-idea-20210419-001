//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4_3.h"
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

void __fastcall TForm1::CoolBar1DockOver(TObject *Sender,
      TDragDockObject *Source, int X, int Y, TDragState State,
      bool &Accept)
{
  TRect *ARect;

  ARect = new TRect;
  if (dynamic_cast<TToolBar *> (Source->Control))
      	Accept = True;

  if (Accept==True)
  {
    POINT Apoint;
    Apoint.y = CoolBar1->ClientRect.Top;
    Apoint.x = CoolBar1->ClientRect.Left;
    POINT Bpoint= CoolBar1->ClientToScreen(Apoint);
    ARect->top = Bpoint.y;
    ARect->left = Bpoint.x;
    Apoint.y = CoolBar1->ClientRect.Bottom;
    Apoint.x = CoolBar1->ClientRect.Right;
    Bpoint= CoolBar1->ClientToScreen(Apoint);
    ARect->bottom = Bpoint.y;
    ARect->right = Bpoint.x;
  }
}
//---------------------------------------------------------------------------
