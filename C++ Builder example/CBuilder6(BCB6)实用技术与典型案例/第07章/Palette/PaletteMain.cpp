///////////////////////////////////////////////////////////////////////
//  PaletteMain.cpp                                                  //
//  Project: Palette                                                 //
//  Copyright (c) 1998 by Jeff Cottingham                            //
///////////////////////////////////////////////////////////////////////

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdlib.h>
#include <time.h>

#include "PaletteMain.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   pBitmap = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnLoadClick(TObject *Sender)
{
   if (!pBitmap) pBitmap = new Graphics::TBitmap;
   if (OpenDialog1->Execute())
   {

   try
   {
      pBitmap->LoadFromFile(OpenDialog1->FileName);
      ImageOrig->Canvas->Draw(0,0,pBitmap);

      Form2->Edit1->Text = pBitmap->Width;
      Form2->Edit2->Text = pBitmap->Height;
      Form2->Edit3->Text = pBitmap->PixelFormat;
   }
   catch(...)
   {
      Application->MessageBox("Could not load bitmap file",NULL,MB_OK);
      delete pBitmap;
      pBitmap = NULL;
   }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnGrayscaleClick(TObject *Sender)
{
   LOGPALETTE* pPalette;

   pPalette = (LOGPALETTE*)new char[sizeof(LOGPALETTE) + sizeof(PALETTEENTRY) * 256];
   pPalette->palVersion = 0x300;
   pPalette->palNumEntries = 256;
   randomize();
   for (int i = 0; i < 256; ++i)
   {
      pPalette->palPalEntry[i].peRed =(short)i ;
      pPalette->palPalEntry[i].peGreen = (short)i;
      pPalette->palPalEntry[i].peBlue = (short)i;
      pPalette->palPalEntry[i].peFlags = PC_RESERVED;
   }
   pBitmap->Palette = ::CreatePalette(pPalette);
   ImageGrayscale->Canvas->Draw(0,0,pBitmap);

   delete[] pPalette;

 /*  struct RGBColor
   {
        unsigned char Blue;
        unsigned char Green;
        unsigned char Red;
   };

   RGBColor* ptr;
   for (int i=0; i<pBitmap->Height; i++)
   {
      ptr = (RGBColor*)(pBitmap->ScanLine[i]);
      for (int j=0; j< pBitmap->Width; j++)
      {
         (ptr+j)->Green  += 10;
         (ptr+j)->Red  += 10;
         (ptr+j)->Blue += 10;
      }
   }

   ImageGrayscale->Canvas->Draw(0,0,pBitmap);  */
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (!pBitmap) delete pBitmap;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ImageOrigMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
   StatusBar1->SimpleText = ImageOrig->Canvas->Pixels[X][Y];// = clRed;
}
//---------------------------------------------------------------------------

