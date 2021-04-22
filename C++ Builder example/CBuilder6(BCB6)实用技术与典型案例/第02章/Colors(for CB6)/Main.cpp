///////////////////////////////////////////////////////////////////////
//  ColorMain.cpp                                                    //
//  Project: Colors                                                  //
//  Copyright (c) 1998 by Jeff Cottingham                            //
///////////////////////////////////////////////////////////////////////


//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm* MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TrackBar1Change(TObject *Sender)
{
   PaintBox1->Canvas->Brush->Color = (TColor)RGB(TrackBar1->Position,
                                                 TrackBar2->Position,
                                                 TrackBar3->Position);
   Edit1->Text = TrackBar1->Position;
   Edit2->Text = TrackBar2->Position;
   Edit3->Text = TrackBar3->Position;
   Edit4->Text = IntToHex(PaintBox1->Canvas->Brush->Color,8);

   PaintBox1->Canvas->FillRect(PaintBox1->ClientRect);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PaintBox1Paint(TObject *Sender)
{

   PaintBox1->Color = (TColor)RGB(TrackBar1->Position,
                                  TrackBar2->Position,
                                  TrackBar3->Position);
   PaintBox1->Canvas->FillRect(PaintBox1->Canvas->ClipRect); 

}
//---------------------------------------------------------------------------


