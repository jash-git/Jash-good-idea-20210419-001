
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FadeMain.h"
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

void __fastcall TForm1::btnFadeClick(TObject *Sender)
{
   RGBCOLOR* ptr;

   if((GetDeviceCaps(Image1->Canvas->Handle,NUMCOLORS)) != -1)
   {
      ShowMessage("You must be in a color depth greater than 256 colors");
      Close();
   };

   Graphics::TBitmap* pbitmap = new Graphics::TBitmap;
   AnsiString FileName ;
   try
   {
   
      pbitmap->LoadFromFile("factory.bmp");
      pbitmap->PixelFormat = pf24bit;
      for (int k=0; k<256; k++)
      {
         for(int i = 0; i < pbitmap->Height; i++)
         {
            ptr = (RGBCOLOR*)pbitmap->ScanLine[i];
            for (int j = 0; j < pbitmap->Width; j++)
            {
               if ((ptr+j)->Red>0)      (ptr+j)->Red -= 1;
               if ((ptr+j)->Green>0)    (ptr+j)->Green -= 1;
               if ((ptr+j)->Blue>0)     (ptr+j)->Blue -= 1;
            }
         }
         Image1->Canvas->Draw(0,0,pbitmap);
         Application->ProcessMessages();
      }
   }
   catch(...){
      delete pbitmap;
      pbitmap = NULL;
      Close();
   }
   delete pbitmap;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnDisplayClick(TObject *Sender)
{
   RGBCOLOR* ptr1;
   RGBCOLOR* ptr2;

   if((GetDeviceCaps(Image1->Canvas->Handle,NUMCOLORS)) != -1)
   {
      ShowMessage("You must be in a color depth greater than 256 colors");
      Close();
   };

   Graphics::TBitmap* pbitmap1 = new Graphics::TBitmap;
   Graphics::TBitmap* pbitmap2 = new Graphics::TBitmap;
   AnsiString FileName ;
   FileName = "factory.bmp";
   try
   {
      pbitmap2->LoadFromFile(FileName);
      pbitmap2->PixelFormat = pf24bit;
      pbitmap1->Assign(pbitmap2);
      for (int k=0; k<256; k++)
      {
         for(int i = 0; i < pbitmap1->Height; i++)
         {
            ptr1 = (RGBCOLOR*)pbitmap1->ScanLine[i];
            ptr2 = (RGBCOLOR*)pbitmap2->ScanLine[i];

            for (int j = 0; j < pbitmap1->Width; j++)
            {
               if ((ptr2+j)->Red>k)      (ptr1+j)->Red = k;
               if ((ptr2+j)->Green>k)    (ptr1+j)->Green = k;
               if ((ptr2+j)->Blue>k)     (ptr1+j)->Blue = k;
            }
         }
         Image1->Canvas->Draw(0,0,pbitmap1);
         Application->ProcessMessages();
      }
   }
   catch(...){
      delete pbitmap1;
      pbitmap1 = NULL;
      delete pbitmap2;
      pbitmap2 = NULL;

      Close();
   }
   delete pbitmap1;
   delete pbitmap2;
}
//---------------------------------------------------------------------------

