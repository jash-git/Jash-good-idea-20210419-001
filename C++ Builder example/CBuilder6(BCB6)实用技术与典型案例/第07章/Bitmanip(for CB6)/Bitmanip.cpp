//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Bitmanip.h"
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
   pBitmap3 = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnLoadClick(TObject *Sender)
{
   if (!pBitmap1) pBitmap1 = new Graphics::TBitmap();
   if (!pBitmap2) pBitmap2 = new Graphics::TBitmap();
   if (!pBitmap3) pBitmap3 = new Graphics::TBitmap();
   pBitmap1->PixelFormat = pf8bit;
   pBitmap2->PixelFormat = pf8bit;
   pBitmap3->PixelFormat = pf8bit;

   AnsiString FileName ;
   FileName = "factory.bmp";
   pBitmap1->LoadFromFile(FileName);

   FileName = "handshak.bmp";
   pBitmap2->LoadFromFile(FileName);


   pBitmap3->Palette = pBitmap1->Palette;
   pBitmap3->Height = pBitmap1->Height;
   pBitmap3->Width = pBitmap1->Width;

   btnSlideLeft->Enabled = true;
   btnSlideRight->Enabled = true;
   btnHShutter->Enabled = true;
   btnVShutter->Enabled = true;
   btnUnroll->Enabled = true;

   Image1->Canvas->Draw(0,0,pBitmap1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnSlideLeftClick(TObject *Sender)
{
   Byte *Current;
   Byte *Next;
   Byte *ToDisplay;

   for(int i = 0; i < pBitmap1->Width;i++)
   {
      for(int y = 0; y < pBitmap1->Height; y++)
      {
         Current = (Byte*)pBitmap1->ScanLine[y];
         Next = (Byte*)pBitmap2->ScanLine[y];
         ToDisplay = (Byte*)pBitmap3->ScanLine[y];

         for(int z = 0; z < i; z++)
               ToDisplay[z] = Next[z];

         for(int j = i; j < (pBitmap1->Width);j++)
               ToDisplay[j] = Current[j];
      }
      Sleep(40);
      Image1->Canvas->Draw(0,0,pBitmap3);
      Application->ProcessMessages();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnSlideRightClick(TObject *Sender)
{
   Byte *Current;
   Byte *Next;
   Byte *ToDisplay;

   for(int i = 0; i < (pBitmap1->Width);i++)
   {
      for(int y = 0; y < pBitmap1->Height; y++)
      {
         Current = (Byte*)pBitmap1->ScanLine[y];
         Next = (Byte*)pBitmap2->ScanLine[y];
         ToDisplay = (Byte*)pBitmap3->ScanLine[y];

         for(int z = 0; z < (pBitmap1->Width - i); z++)
               ToDisplay[z] = Current[z];

         for(int j = (pBitmap1->Width - i); j < pBitmap1->Width;j++)
                   ToDisplay[j] = Next[j];
      }
      Sleep(40);
      Image1->Canvas->Draw(0,0,pBitmap3);
      Application->ProcessMessages();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnHShutterClick(TObject *Sender)
{
   Byte *Next;
   Byte *ToDisplay;

   pBitmap3->Canvas->CopyRect(Rect(0,0,pBitmap3->Width,pBitmap3->Height),
                                pBitmap1->Canvas,Rect(0,0,pBitmap1->Width,
                                pBitmap1->Height));
   for(int i = 0;i < 30; i++)
   {
      for (int y = 0; y < pBitmap1->Height; y += 30)
      {
         Next = (Byte*)(pBitmap2->ScanLine[y + i]);
         ToDisplay = (Byte*)(pBitmap3->ScanLine[y + i]);
         for(int x = 0; x < pBitmap3->Width; x++)
               ToDisplay[x] = Next[x];
      }
      Image1->Canvas->Draw(0,0,pBitmap3);
      Application->ProcessMessages();
      Sleep(40);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnVShutterClick(TObject *Sender)
{
   Byte *Next;
   Byte *ToDisplay;

   pBitmap3->Assign(pBitmap1);
   for(int i = 0;i < 30; i++)
   {
      for (int y = 0; y < pBitmap1->Height; y++)
      {
         ToDisplay = (Byte*)(pBitmap3->ScanLine[y]);
         for(int x = 0; x < pBitmap3->Width; x+=30)
         {
            Next = (Byte*)(pBitmap2->ScanLine[y]);
            ToDisplay[x + i] = Next[x + i];
         }
      }
      Image1->Canvas->Draw(0,0,pBitmap3);
      Application->ProcessMessages();
      Sleep(50);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnUnrollClick(TObject *Sender)
{
   Byte *Next;
   Byte *ToDisplay;

   pBitmap3->Assign(pBitmap1);
   for(int i = 0;i < pBitmap1->Width +1; i++)
   {
      for (int y = 0; y < pBitmap1->Height; y ++)
      {
         Next = (Byte*)(pBitmap2->ScanLine[y]);
         ToDisplay = (Byte*)(pBitmap3->ScanLine[y]);
         if(i < pBitmap1->Width - 15)
         {
            for(int j = 1; j < 15;j++)
            {
               if((y == 0) || (y == pBitmap1->Height - 1))
                  ToDisplay[i+j] = clBlack;
               else
                  ToDisplay[i+j] = Next[i+10-j];
            }
         }
         ToDisplay[i] = Next[i];
      }
      Sleep(10);
      Image1->Canvas->Draw(0,0,pBitmap3);
      Application->ProcessMessages();
      Sleep(50);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (pBitmap1) delete pBitmap1;
   if (pBitmap2) delete pBitmap2;
   if (pBitmap3) delete pBitmap3;
}
//---------------------------------------------------------------------------

