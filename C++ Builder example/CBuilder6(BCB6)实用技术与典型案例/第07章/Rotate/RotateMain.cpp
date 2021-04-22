///////////////////////////////////////////////////////////////////////
//  RotateMain.cpp                                                   //
//  Project: Rotate                                                  //
//  Copyright (c) 1998 by Jeff Cottingham                            //
///////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RotateMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   pBitmap1 = NULL;
   pBitmap2 = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (pBitmap1) delete pBitmap1;
   if (pBitmap2) delete pBitmap2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnLoadClick(TObject *Sender)
{
   if (!pBitmap1) pBitmap1 = new Graphics::TBitmap;
   if (!pBitmap2) pBitmap2 = new Graphics::TBitmap;

   AnsiString FileName;
   FileName= "factory.bmp";

   try
   {
      pBitmap1->LoadFromFile(FileName);
      pBitmap1->PixelFormat = pf8bit;
      pBitmap2->PixelFormat = pf8bit;
      pBitmap2->Palette = pBitmap1->Palette;
   }
   catch(...)
   {
      ShowMessage("Could not load or alter bitmap");
   };

   Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
   Image1->Canvas->Draw(0,0,pBitmap1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnR180Click(TObject *Sender)
{
   Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
   pBitmap2->Height = pBitmap1->Height;
   pBitmap2->Width = pBitmap1->Width;

   for (int y = 0; y < pBitmap2->Height; y++){
      ptr1 = (Byte*)(pBitmap1->ScanLine[y]);
      ptr2 = (Byte*)(pBitmap2->ScanLine[((pBitmap1->Height - 1) - y)]);
      for (int x = 0; x < pBitmap1->Width; x++)
         ptr2[x] = ptr1[x];
   };

   Image1->Canvas->Draw(0,0,pBitmap2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnR90Click(TObject *Sender)
{
   Image1->Canvas->FillRect(Image1->Canvas->ClipRect);
   pBitmap2->Height = pBitmap1->Width;
   pBitmap2->Width = pBitmap1->Height;

   for (int y = 0; y < pBitmap1->Width; y++){
      ptr2 = (Byte*)(pBitmap2->ScanLine[y]);
      for (int x = 0; x < pBitmap1->Height; x++){
         ptr1 = (Byte*)(pBitmap1->ScanLine[x]);
         ptr2[x] = ptr1[y];
      };
   };

   Image1->Canvas->Draw(0,0,pBitmap2);

}
//---------------------------------------------------------------------------
