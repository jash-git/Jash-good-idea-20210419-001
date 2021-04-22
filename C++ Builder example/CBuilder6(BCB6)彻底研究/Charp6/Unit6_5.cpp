//---------------------------------------------------------------------------

#include <vcl.h>
#include <Clipbrd.hpp>
#pragma hdrstop

#include "Unit6_5.h"
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
void __fastcall TForm1::CutBtnClick(TObject *Sender)
{
  TRect ARect;

  Clipboard()->Assign(Image1->Picture);
  Image1->Canvas->CopyMode = cmWhiteness;
  ARect = Rect(0, 0, Image1->Width, Image1->Height);
  Image1->Canvas->CopyRect(ARect, Image1->Canvas, ARect);
  Image1->Canvas->CopyMode = cmSrcCopy;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PasteBtnClick(TObject *Sender)
{
  if (Clipboard()->HasFormat(CF_BITMAP))
  {
    Image2->Picture->Assign(Clipboard());
  }
}
//---------------------------------------------------------------------------
