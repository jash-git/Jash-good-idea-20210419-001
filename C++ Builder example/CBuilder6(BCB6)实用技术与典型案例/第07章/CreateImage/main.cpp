//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include "main.h"
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

void __fastcall TForm1::btnCreateClick(TObject *Sender)
{
   const int ImageWidth = 512;
   const int ImageHeight = 512;
   int Amplitude;
   float Period;
   float PI = 3.1416;
   int Gray;
   TColor PxColor;

   Image1->Picture->Bitmap = new Graphics::TBitmap;
   Image1->Picture->Bitmap->PixelFormat = pf24bit;
   Image1->Picture->Bitmap->Width = ImageWidth;
   Image1->Picture->Bitmap->Height = ImageHeight;

   for ( int i=1; i<=ImageHeight; i++)
   {
      for (int j=1; j<=ImageWidth; j++)
      {
         Amplitude = 64*(255-i)/255;
         Period = 100.0*sqrt(1/(1+(exp(0.013*j)*exp(0.027*j)/400.0)));
         Gray = Amplitude*sin(2*PI/Period*j)+128;
         PxColor =TColor((Gray<<16)|(Gray<<8)|Gray);
         Image1->Canvas->Pixels[j][i] = PxColor;
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btnSaveClick(TObject *Sender)
{
   Image1->Picture->Bitmap->SaveToFile("test.bmp");
}
//---------------------------------------------------------------------------
