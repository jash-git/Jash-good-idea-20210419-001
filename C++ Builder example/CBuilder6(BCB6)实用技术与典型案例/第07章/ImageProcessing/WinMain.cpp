//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "WinMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent* Owner)
   : TForm(Owner)
{
   m_AllocFlag = false;
   m_pBitmap   = new Graphics::TBitmap;
   m_pBitmap->PixelFormat = pf24bit;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OpenClick(TObject *Sender)
{
   if (OpenPictureDialog1->Execute())
   {
      if (m_AllocFlag)
      {
         for (int i=0; i<m_Height; ++i)
         {   
             delete[] m_RedData[i];
             delete[] m_GreenData[i];
             delete[] m_BlueData[i];

             delete[] m_TempRedData[i];
             delete[] m_TempGreenData[i];
             delete[] m_TempBlueData[i];
         }
         
         delete[] m_RedData;
         delete[] m_GreenData;
         delete[] m_BlueData;

         delete[] m_TempRedData;
         delete[] m_TempGreenData;
         delete[] m_TempBlueData;
      }

      m_pBitmap->LoadFromFile(OpenPictureDialog1->FileName);

      Image1->Picture->Bitmap = m_pBitmap;

      m_Width = m_pBitmap->Width;
      m_Height = m_pBitmap->Height;

      Image1->Canvas->Draw(0, 0, m_pBitmap);

      try
      {
         m_RedData   = new Byte*[m_Height];
         m_GreenData = new Byte*[m_Height];
         m_BlueData  = new Byte*[m_Height];

         m_TempRedData   = new Byte*[m_Height];
         m_TempGreenData = new Byte*[m_Height];
         m_TempBlueData  = new Byte*[m_Height];

         for (int i=0; i<m_Height; ++i)
         {
             m_RedData[i]   = new Byte[m_Width];
             m_GreenData[i] = new Byte[m_Width];
             m_BlueData[i]  = new Byte[m_Width];

             m_TempRedData[i]   = new Byte[m_Width];
             m_TempGreenData[i] = new Byte[m_Width];
             m_TempBlueData[i]  = new Byte[m_Width];
         }

         m_AllocFlag = true;
      }
      catch (...)
      {
         ShowMessage("Memory Allocation Errors!");
      }

      RGBColor* lpColor;

      for (int i=0; i<m_Height; ++i)
      {
          lpColor = (RGBColor*)m_pBitmap->ScanLine[i];

          for (int j=0; j<m_Width; ++j)
          {
              m_RedData[i][j]   = (lpColor+j)->Red;
              m_GreenData[i][j] = (lpColor+j)->Green;
              m_BlueData[i][j]  = (lpColor+j)->Blue;

              m_TempRedData[i][j]   = (lpColor+j)->Red;
              m_TempGreenData[i][j] = (lpColor+j)->Green;
              m_TempBlueData[i][j]  = (lpColor+j)->Blue;
          }
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
   delete m_pBitmap;

   if (m_AllocFlag)
   {
      for (int i=0; i<m_Height; ++i)
      {
         delete[] m_RedData[i];
         delete[] m_GreenData[i];
         delete[] m_BlueData[i];

         delete[] m_TempRedData[i];
         delete[] m_TempGreenData[i];
         delete[] m_TempBlueData[i];
      }

      delete[] m_RedData;
      delete[] m_GreenData;
      delete[] m_BlueData;

      delete[] m_TempRedData;
      delete[] m_TempGreenData;
      delete[] m_TempBlueData;
   }
}
//---------------------------------------------------------------------------

void TMainForm::ImageFilter(FilterType enFilter)
{
   int Element[9];
   int Divisor;

   switch (enFilter)
   {
      case HIGHPASS1:
        Element[0] = -1;   Element[1] = -1;   Element[2] = -1;
        Element[3] = -1;   Element[4] =  9;   Element[5] = -1;
        Element[6] = -1;   Element[7] = -1;   Element[8] = -1;

        Divisor = 1;
      break;

      case HIGHPASS2:
        Element[0] =  0;   Element[1] = -1;   Element[2] =  0;
        Element[3] = -1;   Element[4] =  5;   Element[5] = -1;
        Element[6] =  0;   Element[7] = -1;   Element[8] =  0;

        Divisor = 1;
      break;

      case HIGHPASS3:
        Element[0] =  1;   Element[1] = -2;   Element[2] =  1;
        Element[3] = -2;   Element[4] =  5;   Element[5] = -2;
        Element[6] =  1;   Element[7] = -2;   Element[8] =  1;

        Divisor = 1;
      break;

      case LOWPASS1:
        Element[0] = 1;   Element[1] = 1;   Element[2] = 1;
        Element[3] = 1;   Element[4] = 1;   Element[5] = 1;
        Element[6] = 1;   Element[7] = 1;   Element[8] = 1;

        Divisor = 9;
      break;

      case LOWPASS2:
        Element[0] = 1;   Element[1] = 1;   Element[2] = 1;
        Element[3] = 1;   Element[4] = 2;   Element[5] = 1;
        Element[6] = 1;   Element[7] = 1;   Element[8] = 1;

        Divisor = 10;
      break;

      case LOWPASS3:
        Element[0] = 1;   Element[1] = 2;   Element[2] = 1;
        Element[3] = 2;   Element[4] = 4;   Element[5] = 2;
        Element[6] = 1;   Element[7] = 2;   Element[8] = 1;

        Divisor = 16;
      break;

      case VERTICAL:
        Element[0] =  0;   Element[1] =  0;   Element[2] =  0;
        Element[3] = -1;   Element[4] =  1;   Element[5] =  0;
        Element[6] =  0;   Element[7] =  0;   Element[8] =  0;

        Divisor = 1;
      break;

      case HORIZONTAL:
        Element[0] =  0;   Element[1] = -1;   Element[2] =  0;
        Element[3] =  0;   Element[4] =  1;   Element[5] =  0;
        Element[6] =  0;   Element[7] =  0;   Element[8] =  0;

        Divisor = 1;
      break;

      case HORIZONTALVERTICAL:
        Element[0] = -1;   Element[1] =  0;   Element[2] =  0;
        Element[3] =  0;   Element[4] =  1;   Element[5] =  0;
        Element[6] =  0;   Element[7] =  0;   Element[8] =  0;

        Divisor = 1;
      break;

      case LAPLACE1:
        Element[0] =  0;   Element[1] =  1;   Element[2] =  0;
        Element[3] =  1;   Element[4] = -4;   Element[5] =  1;
        Element[6] =  0;   Element[7] =  1;   Element[8] =  0;

        Divisor = 1;
      break;

      case LAPLACE2:
        Element[0] = -1;   Element[1] = -1;   Element[2] = -1;
        Element[3] = -1;   Element[4] =  8;   Element[5] = -1;
        Element[6] = -1;   Element[7] = -1;   Element[8] = -1;

        Divisor = 1;
      break;

      case LAPLACE3:
        Element[0] = -1;   Element[1] = -1;   Element[2] = -1;
        Element[3] = -1;   Element[4] =  9;   Element[5] = -1;
        Element[6] = -1;   Element[7] = -1;   Element[8] = -1;

        Divisor = 1;
      break;

      case LAPLACE4:
        Element[0] =  1;   Element[1] = -2;   Element[2] =  1;
        Element[3] = -2;   Element[4] =  4;   Element[5] = -2;
        Element[6] =  1;   Element[7] = -2;   Element[8] =  1;

        Divisor = 1;
      break;

      case EAST:
        Element[0] = -1;   Element[1] =  1;   Element[2] =  1;
        Element[3] = -1;   Element[4] = -2;   Element[5] =  1;
        Element[6] = -1;   Element[7] =  1;   Element[8] =  1;

        Divisor = 1;
      break;

      case NORTH:
        Element[0] =  1;   Element[1] =  1;   Element[2] =  1;
        Element[3] =  1;   Element[4] = -2;   Element[5] =  1;
        Element[6] = -1;   Element[7] = -1;   Element[8] = -1;

        Divisor = 1;
      break;

      case NORTHEAST:
        Element[0] =  1;   Element[1] =  1;   Element[2] =  1;
        Element[3] = -1;   Element[4] = -2;   Element[5] =  1;
        Element[6] = -1;   Element[7] = -1;   Element[8] =  1;

        Divisor = 1;
      break;

      case WEST:
        Element[0] =  1;   Element[1] =  1;   Element[2] = -1;
        Element[3] =  1;   Element[4] = -2;   Element[5] = -1;
        Element[6] =  1;   Element[7] =  1;   Element[8] = -1;

        Divisor = 1;
      break;

      case SOUTH:
        Element[0] = -1;   Element[1] = -1;   Element[2] = -1;
        Element[3] =  1;   Element[4] = -2;   Element[5] =  1;
        Element[6] =  1;   Element[7] =  1;   Element[8] =  1;

        Divisor = 1;
      break;

      case SOUTHWEST:
        Element[0] =  1;   Element[1] = -1;   Element[2] = -1;
        Element[3] =  1;   Element[4] = -2;   Element[5] = -1;
        Element[6] =  1;   Element[7] =  1;   Element[8] =  1;

        Divisor = 1;
      break;

      case NORTHWEST:
        Element[0] =  1;   Element[1] =  1;   Element[2] =  1;
        Element[3] =  1;   Element[4] = -2;   Element[5] = -1;
        Element[6] =  1;   Element[7] = -1;   Element[8] = -1;

        Divisor = 1;
      break;

      case SOUTHEAST:
        Element[0] = -1;   Element[1] = -1;   Element[2] =  1;
        Element[3] = -1;   Element[4] = -2;   Element[5] =  1;
        Element[6] =  1;   Element[7] =  1;   Element[8] =  1;

        Divisor = 1;
      break;
   }

   Byte red[9], green[9], blue[9];
   int redtemp, greentemp, bluetemp;

   for (int i=1; i<m_Height-1; ++i)
   {
       for (int j=1; j<m_Width-1; ++j)
       {
           red[0] = m_RedData[i-1][j-1];        red[1] = m_RedData[i-1][j];
           red[2] = m_RedData[i-1][j+1];        red[3] = m_RedData[i][j-1];
           red[4] = m_RedData[i][j];            red[5] = m_RedData[i][j+1];
           red[6] = m_RedData[i+1][j-1];        red[7] = m_RedData[i+1][j];
           red[8] = m_RedData[i+1][j+1];

           green[0] = m_GreenData[i-1][j-1];    green[1] = m_GreenData[i-1][j];
           green[2] = m_GreenData[i-1][j+1];    green[3] = m_GreenData[i][j-1];
           green[4] = m_GreenData[i][j];        green[5] = m_GreenData[i][j+1];
           green[6] = m_GreenData[i+1][j-1];    green[7] = m_GreenData[i+1][j];
           green[8] = m_GreenData[i+1][j+1];

           blue[0] = m_BlueData[i-1][j-1];      blue[1] = m_BlueData[i-1][j];
           blue[2] = m_BlueData[i-1][j+1];      blue[3] = m_BlueData[i][j-1];
           blue[4] = m_BlueData[i][j];          blue[5] = m_BlueData[i][j+1];
           blue[6] = m_BlueData[i+1][j-1];      blue[7] = m_BlueData[i+1][j];
           blue[8] = m_BlueData[i+1][j+1];

           redtemp   = 0;
           greentemp = 0;
           bluetemp  = 0;

           for (int k=0; k<9; ++k)
           {
               redtemp   += Element[k] * red[k];
               greentemp += Element[k] * green[k];
               bluetemp  += Element[k] * blue[k];
           }

           if (Divisor != 1)
           {
              redtemp   /= Divisor;
              greentemp /= Divisor;
              bluetemp  /= Divisor;
           }

           m_TempRedData[i][j]   = abs(redtemp);
           m_TempGreenData[i][j] = abs(greentemp);
           m_TempBlueData[i][j]  = abs(bluetemp);
       }
   }

   RGBColor* lpColor;

   for (int i=0; i<m_Height; ++i)
   {
       lpColor = (RGBColor*)m_pBitmap->ScanLine[i];

       for (int j=0; j<m_Width; ++j)
       {
           (lpColor+j)->Red   = m_TempRedData[i][j];
           (lpColor+j)->Green = m_TempGreenData[i][j];
           (lpColor+j)->Blue  = m_TempBlueData[i][j];
       }
   }
   /*
   Byte* lpLine;

   for (int i=0; i<m_Height; ++i)
   {
       lpLine = (Byte*)m_pBitmap->ScanLine[i];

       for (int j=0; j<m_Width; ++j)
       {
           lpLine[j*3] = m_TempRedData[i][j];
           lpLine[j*3+1] = m_TempGreenData[i][j];
           lpLine[j*3+2] = m_TempBlueData[i][j];
       }
   }
   */
   Image1->Canvas->Draw(0, 0, m_pBitmap);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExitClick(TObject *Sender)
{
   MainForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveClick(TObject *Sender)
{
   if (SavePictureDialog1->Execute())
   {
      Image1->Picture->SaveToFile(SavePictureDialog1->FileName);
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Smooth1Click(TObject *Sender)
{
   MainForm->ImageFilter(LOWPASS1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Smooth2Click(TObject *Sender)
{
   MainForm->ImageFilter(LOWPASS2);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Smooth3Click(TObject *Sender)
{
   MainForm->ImageFilter(LOWPASS3);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sharpen1Click(TObject *Sender)
{
   MainForm->ImageFilter(HIGHPASS1);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sharpen2Click(TObject *Sender)
{
   MainForm->ImageFilter(HIGHPASS2);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Sharpen3Click(TObject *Sender)
{
   MainForm->ImageFilter(HIGHPASS3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LAP1Click(TObject *Sender)
{
   MainForm->ImageFilter(LAPLACE1);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LAP2Click(TObject *Sender)
{
   MainForm->ImageFilter(LAPLACE2);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LAP3Click(TObject *Sender)
{
   MainForm->ImageFilter(LAPLACE3);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LAP4Click(TObject *Sender)
{
   MainForm->ImageFilter(LAPLACE4);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::VerticalClick(TObject *Sender)
{
   MainForm->ImageFilter(VERTICAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HorizontalClick(TObject *Sender)
{
   MainForm->ImageFilter(HORIZONTAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HorizontalVerticalClick(TObject *Sender)
{
   MainForm->ImageFilter(HORIZONTALVERTICAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EastClick(TObject *Sender)
{
   MainForm->ImageFilter(EAST);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SouthClick(TObject *Sender)
{
   MainForm->ImageFilter(SOUTH);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WestClick(TObject *Sender)
{
   MainForm->ImageFilter(WEST);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NorthClick(TObject *Sender)
{
   MainForm->ImageFilter(NORTH);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NorthEastClick(TObject *Sender)
{
   MainForm->ImageFilter(NORTHEAST);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SouthEastClick(TObject *Sender)
{
   MainForm->ImageFilter(SOUTHEAST);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NorthWestClick(TObject *Sender)
{
   MainForm->ImageFilter(NORTHWEST);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SouthWestClick(TObject *Sender)
{
   MainForm->ImageFilter(SOUTHWEST);   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HoughClick(TObject *Sender)
{
   int Houth1[9] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};
   int Houth2[9] = {-1, -1,  0, -1,  0,  1,  0,  1,  1};
   int Houth3[9] = {-1,  0,  1, -1,  0,  1, -1,  0,  1};
   int Houth4[9] = {0,  -1, -1,  1,  0, -1,  1,  1,  0};

   Byte red[9], green[9], blue[9];
   int redtemp, greentemp, bluetemp;

   for (int i=1; i<m_Height-1; ++i)
   {
       for (int j=1; j<m_Width-1; ++j)
       {
           red[0] = m_RedData[i-1][j-1];        red[1] = m_RedData[i-1][j];
           red[2] = m_RedData[i-1][j+1];        red[3] = m_RedData[i][j-1];
           red[4] = m_RedData[i][j];            red[5] = m_RedData[i][j+1];
           red[6] = m_RedData[i+1][j-1];        red[7] = m_RedData[i+1][j];
           red[8] = m_RedData[i+1][j+1];

           green[0] = m_GreenData[i-1][j-1];    green[1] = m_GreenData[i-1][j];
           green[2] = m_GreenData[i-1][j+1];    green[3] = m_GreenData[i][j-1];
           green[4] = m_GreenData[i][j];        green[5] = m_GreenData[i][j+1];
           green[6] = m_GreenData[i+1][j-1];    green[7] = m_GreenData[i+1][j];
           green[8] = m_GreenData[i+1][j+1];

           blue[0] = m_BlueData[i-1][j-1];      blue[1] = m_BlueData[i-1][j];
           blue[2] = m_BlueData[i-1][j+1];      blue[3] = m_BlueData[i][j-1];
           blue[4] = m_BlueData[i][j];          blue[5] = m_BlueData[i][j+1];
           blue[6] = m_BlueData[i+1][j-1];      blue[7] = m_BlueData[i+1][j];
           blue[8] = m_BlueData[i+1][j+1];

           redtemp   = 0;
           greentemp = 0;
           bluetemp  = 0;

           for (int k=0; k<9; ++k)
           {
               redtemp   += Houth1[k] * red[k];
               greentemp += Houth1[k] * green[k];
               bluetemp  += Houth1[k] * blue[k];
           }

           for (int k=0; k<9; ++k)
           {
               redtemp   += Houth2[k] * red[k];
               greentemp += Houth2[k] * green[k];
               bluetemp  += Houth2[k] * blue[k];
           }

           for (int k=0; k<9; ++k)
           {
               redtemp   += Houth3[k] * red[k];
               greentemp += Houth3[k] * green[k];
               bluetemp  += Houth3[k] * blue[k];
           }

           for (int k=0; k<9; ++k)
           {
               redtemp   += Houth4[k] * red[k];
               greentemp += Houth4[k] * green[k];
               bluetemp  += Houth4[k] * blue[k];
           }

           m_TempRedData[i][j]   = abs(redtemp);
           m_TempGreenData[i][j] = abs(greentemp);
           m_TempBlueData[i][j]  = abs(bluetemp);
       }
   }

   RGBColor* lpColor;

   for (int i=0; i<m_Height; ++i)
   {
       lpColor = (RGBColor*)m_pBitmap->ScanLine[i];

       for (int j=0; j<m_Width; ++j)
       {
           (lpColor+j)->Red   = m_TempRedData[i][j];
           (lpColor+j)->Green = m_TempGreenData[i][j];
           (lpColor+j)->Blue  = m_TempBlueData[i][j];
       }
   }

   Image1->Canvas->Draw(0, 0, m_pBitmap);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SobelClick(TObject *Sender)
{
   int Sobel1[9] = {-1,  0,  1, -2,  0,  2, -1,  0,  1};
   int Sobel2[9] = {-1, -2, -1,  0,  0,  0,  1,  2,  1};
   int Sobel3[9] = {-2, -1,  0, -1,  0,  1,  0,  1,  2};
   int Sobel4[9] = { 0, -1, -2,  1,  0, -1,  2,  1,  0};

   Byte red[9], green[9], blue[9];
   int redtemp, greentemp, bluetemp;

   for (int i=1; i<m_Height-1; ++i)
   {
       for (int j=1; j<m_Width-1; ++j)
       {
           red[0] = m_RedData[i-1][j-1];        red[1] = m_RedData[i-1][j];
           red[2] = m_RedData[i-1][j+1];        red[3] = m_RedData[i][j-1];
           red[4] = m_RedData[i][j];            red[5] = m_RedData[i][j+1];
           red[6] = m_RedData[i+1][j-1];        red[7] = m_RedData[i+1][j];
           red[8] = m_RedData[i+1][j+1];

           green[0] = m_GreenData[i-1][j-1];    green[1] = m_GreenData[i-1][j];
           green[2] = m_GreenData[i-1][j+1];    green[3] = m_GreenData[i][j-1];
           green[4] = m_GreenData[i][j];        green[5] = m_GreenData[i][j+1];
           green[6] = m_GreenData[i+1][j-1];    green[7] = m_GreenData[i+1][j];
           green[8] = m_GreenData[i+1][j+1];

           blue[0] = m_BlueData[i-1][j-1];      blue[1] = m_BlueData[i-1][j];
           blue[2] = m_BlueData[i-1][j+1];      blue[3] = m_BlueData[i][j-1];
           blue[4] = m_BlueData[i][j];          blue[5] = m_BlueData[i][j+1];
           blue[6] = m_BlueData[i+1][j-1];      blue[7] = m_BlueData[i+1][j];
           blue[8] = m_BlueData[i+1][j+1];

           redtemp   = 0;
           greentemp = 0;
           bluetemp  = 0;

           for (int k=0; k<9; ++k)
           {
               redtemp   += Sobel1[k] * red[k];
               greentemp += Sobel1[k] * green[k];
               bluetemp  += Sobel1[k] * blue[k];
           }

           for (int k=0; k<9; ++k)
           {
               redtemp   += Sobel2[k] * red[k];
               greentemp += Sobel2[k] * green[k];
               bluetemp  += Sobel2[k] * blue[k];
           }

           for (int k=0; k<9; ++k)
           {
               redtemp   += Sobel3[k] * red[k];
               greentemp += Sobel3[k] * green[k];
               bluetemp  += Sobel3[k] * blue[k];
           }

           for (int k=0; k<9; ++k)
           {
               redtemp   += Sobel4[k] * red[k];
               greentemp += Sobel4[k] * green[k];
               bluetemp  += Sobel4[k] * blue[k];
           }

           m_TempRedData[i][j]   = abs(redtemp);
           m_TempGreenData[i][j] = abs(greentemp);
           m_TempBlueData[i][j]  = abs(bluetemp);
       }
   }

   RGBColor* lpColor;

   for (int i=0; i<m_Height; ++i)
   {
       lpColor = (RGBColor*)m_pBitmap->ScanLine[i];

       for (int j=0; j<m_Width; ++j)
       {
           (lpColor+j)->Red   = m_TempRedData[i][j];
           (lpColor+j)->Green = m_TempGreenData[i][j];
           (lpColor+j)->Blue  = m_TempBlueData[i][j];
       }
   }

   Image1->Canvas->Draw(0, 0, m_pBitmap);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PrewittClick(TObject *Sender)
{
   int Prewitt1[9] = {-1, -1, -1,  0,  0,  0,  1,  1,  1};
   int Prewitt2[9] = {1,  0,  -1,  1,  0, -1,  1,  0, -1};

   Byte red[9], green[9], blue[9];
   int redtemp1, greentemp1, bluetemp1, redtemp2, greentemp2, bluetemp2;

   for (int i=1; i<m_Height-1; ++i)
   {
       for (int j=1; j<m_Width-1; ++j)
       {
           red[0] = m_RedData[i-1][j-1];        red[1] = m_RedData[i-1][j];
           red[2] = m_RedData[i-1][j+1];        red[3] = m_RedData[i][j-1];
           red[4] = m_RedData[i][j];            red[5] = m_RedData[i][j+1];
           red[6] = m_RedData[i+1][j-1];        red[7] = m_RedData[i+1][j];
           red[8] = m_RedData[i+1][j+1];

           green[0] = m_GreenData[i-1][j-1];    green[1] = m_GreenData[i-1][j];
           green[2] = m_GreenData[i-1][j+1];    green[3] = m_GreenData[i][j-1];
           green[4] = m_GreenData[i][j];        green[5] = m_GreenData[i][j+1];
           green[6] = m_GreenData[i+1][j-1];    green[7] = m_GreenData[i+1][j];
           green[8] = m_GreenData[i+1][j+1];

           blue[0] = m_BlueData[i-1][j-1];      blue[1] = m_BlueData[i-1][j];
           blue[2] = m_BlueData[i-1][j+1];      blue[3] = m_BlueData[i][j-1];
           blue[4] = m_BlueData[i][j];          blue[5] = m_BlueData[i][j+1];
           blue[6] = m_BlueData[i+1][j-1];      blue[7] = m_BlueData[i+1][j];
           blue[8] = m_BlueData[i+1][j+1];

           redtemp1   = 0;
           greentemp1 = 0;
           bluetemp1  = 0;
           redtemp2   = 0;
           greentemp2 = 0;
           bluetemp2  = 0;

           for (int k=0; k<9; ++k)
           {
               redtemp1   += Prewitt1[k] * red[k];
               greentemp1 += Prewitt1[k] * green[k];
               bluetemp1  += Prewitt1[k] * blue[k];
           }

           for (int k=0; k<9; ++k)
           {
               redtemp2   += Prewitt2[k] * red[k];
               greentemp2 += Prewitt2[k] * green[k];
               bluetemp2  += Prewitt2[k] * blue[k];
           }

           if (redtemp2   > redtemp1)        redtemp1   = redtemp2;
           if (greentemp2 > greentemp1)      greentemp1 = greentemp2;
           if (bluetemp2  > bluetemp1)       bluetemp1  = bluetemp2;

           m_TempRedData[i][j]   = abs(redtemp1);
           m_TempGreenData[i][j] = abs(greentemp1);
           m_TempBlueData[i][j]  = abs(bluetemp1);
       }
   }

   RGBColor* lpColor;

   for (int i=0; i<m_Height; ++i)
   {
       lpColor = (RGBColor*)m_pBitmap->ScanLine[i];

       for (int j=0; j<m_Width; ++j)
       {
           (lpColor+j)->Red   = m_TempRedData[i][j];
           (lpColor+j)->Green = m_TempGreenData[i][j];
           (lpColor+j)->Blue  = m_TempBlueData[i][j];
       }
   }

   Image1->Canvas->Draw(0, 0, m_pBitmap);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Detect1Click(TObject *Sender)
{
   int D[25] = {-2, -4, -4, -4, -2,
                -4,  0,  8,  0, -4,
                -4,  8, 24,  8, -4,
                -4,  0,  8,  0, -4,
                -2, -4, -4, -4, -2};

   Byte red[25], green[25], blue[25];
   int redtemp, greentemp, bluetemp;

   for (int i=2; i<m_Height-2; ++i)
   {
       for (int j=2; j<m_Width-2; ++j)
       {
           red[0]  = m_RedData[i-2][j-2];     red[1]  = m_RedData[i-2][j-1];
           red[2]  = m_RedData[i-2][j];       red[3]  = m_RedData[i-2][j+1];
           red[4]  = m_RedData[i-2][j+2];     red[5]  = m_RedData[i-1][j-2];
           red[6]  = m_RedData[i-1][j-1];     red[7]  = m_RedData[i-1][j];
           red[8]  = m_RedData[i-1][j+1];     red[9]  = m_RedData[i-1][j+2];
           red[10] = m_RedData[i][j-2];       red[11] = m_RedData[i][j-1];
           red[12] = m_RedData[i][j];         red[13] = m_RedData[i][j+1];
           red[14] = m_RedData[i][j+2];       red[15] = m_RedData[i+1][j-2];
           red[16] = m_RedData[i+1][j-1];     red[17] = m_RedData[i+1][j];
           red[18] = m_RedData[i+1][j+1];     red[19] = m_RedData[i+1][j+2];
           red[20] = m_RedData[i+2][j-2];     red[21] = m_RedData[i+2][j-1];
           red[22] = m_RedData[i+2][j];       red[23] = m_RedData[i+2][j+1];
           red[24] = m_RedData[i+2][j+2];

           green[0]  = m_GreenData[i-2][j-2]; green[1]  = m_GreenData[i-2][j-1];
           green[2]  = m_GreenData[i-2][j];   green[3]  = m_GreenData[i-2][j+1];
           green[4]  = m_GreenData[i-2][j+2]; green[5]  = m_GreenData[i-1][j-2];
           green[6]  = m_GreenData[i-1][j-1]; green[7]  = m_GreenData[i-1][j];
           green[8]  = m_GreenData[i-1][j+1]; green[9]  = m_GreenData[i-1][j+2];
           green[10] = m_GreenData[i][j-2];   green[11] = m_GreenData[i][j-1];
           green[12] = m_GreenData[i][j];     green[13] = m_GreenData[i][j+1];
           green[14] = m_GreenData[i][j+2];   green[15] = m_GreenData[i+1][j-2];
           green[16] = m_GreenData[i+1][j-1]; green[17] = m_GreenData[i+1][j];
           green[18] = m_GreenData[i+1][j+1]; green[19] = m_GreenData[i+1][j+2];
           green[20] = m_GreenData[i+2][j-2]; green[21] = m_GreenData[i+2][j-1];
           green[22] = m_GreenData[i+2][j];   green[23] = m_GreenData[i+2][j+1];
           green[24] = m_GreenData[i+2][j+2];

           blue[0]  = m_BlueData[i-2][j-2];   blue[1]  = m_BlueData[i-2][j-1];
           blue[2]  = m_BlueData[i-2][j];     blue[3]  = m_BlueData[i-2][j+1];
           blue[4]  = m_BlueData[i-2][j+2];   blue[5]  = m_BlueData[i-1][j-2];
           blue[6]  = m_BlueData[i-1][j-1];   blue[7]  = m_BlueData[i-1][j];
           blue[8]  = m_BlueData[i-1][j+1];   blue[9]  = m_BlueData[i-1][j+2];
           blue[10] = m_BlueData[i][j-2];     blue[11] = m_BlueData[i][j-1];
           blue[12] = m_BlueData[i][j];       blue[13] = m_BlueData[i][j+1];
           blue[14] = m_BlueData[i][j+2];     blue[15] = m_BlueData[i+1][j-2];
           blue[16] = m_BlueData[i+1][j-1];   blue[17] = m_BlueData[i+1][j];
           blue[18] = m_BlueData[i+1][j+1];   blue[19] = m_BlueData[i+1][j+2];
           blue[20] = m_BlueData[i+2][j-2];   blue[21] = m_BlueData[i+2][j-1];
           blue[22] = m_BlueData[i+2][j];     blue[23] = m_BlueData[i+2][j+1];
           blue[24] = m_BlueData[i+2][j+2];

           redtemp   = 0;
           greentemp = 0;
           bluetemp  = 0;

           for (int k=0; k<25; ++k)
           {
               redtemp   += D[k] * red[k];
               greentemp += D[k] * green[k];
               bluetemp  += D[k] * blue[k];
           }

           m_TempRedData[i][j]   = abs(redtemp);
           m_TempGreenData[i][j] = abs(greentemp);
           m_TempBlueData[i][j]  = abs(bluetemp);
       }
   }

   RGBColor* lpColor;

   for (int i=0; i<m_Height; ++i)
   {
       lpColor = (RGBColor*)m_pBitmap->ScanLine[i];

       for (int j=0; j<m_Width; ++j)
       {
           (lpColor+j)->Red   = m_TempRedData[i][j];
           (lpColor+j)->Green = m_TempGreenData[i][j];
           (lpColor+j)->Blue  = m_TempBlueData[i][j];
       }
   }

   Image1->Canvas->Draw(0, 0, m_pBitmap);
}
//---------------------------------------------------------------------------

int Compare(const void* x, const void* y)
{
   if (*(Byte*)x < *(Byte*)y)     return  -1;
   if (*(Byte*)x > *(Byte*)y)     return   1;

   return  0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MediaClick(TObject *Sender)
{
   Screen->Cursor = crHourGlass;

   Byte red[9], green[9], blue[9];

   for (int i=1; i<m_Height-1; ++i)
   {
       for (int j=1; j<m_Width-1; ++j)
       {
           red[0] = m_RedData[i-1][j-1];        red[1] = m_RedData[i-1][j];
           red[2] = m_RedData[i-1][j+1];        red[3] = m_RedData[i][j-1];
           red[4] = m_RedData[i][j];            red[5] = m_RedData[i][j+1];
           red[6] = m_RedData[i+1][j-1];        red[7] = m_RedData[i+1][j];
           red[8] = m_RedData[i+1][j+1];

           green[0] = m_GreenData[i-1][j-1];    green[1] = m_GreenData[i-1][j];
           green[2] = m_GreenData[i-1][j+1];    green[3] = m_GreenData[i][j-1];
           green[4] = m_GreenData[i][j];        green[5] = m_GreenData[i][j+1];
           green[6] = m_GreenData[i+1][j-1];    green[7] = m_GreenData[i+1][j];
           green[8] = m_GreenData[i+1][j+1];

           blue[0] = m_BlueData[i-1][j-1];      blue[1] = m_BlueData[i-1][j];
           blue[2] = m_BlueData[i-1][j+1];      blue[3] = m_BlueData[i][j-1];
           blue[4] = m_BlueData[i][j];          blue[5] = m_BlueData[i][j+1];
           blue[6] = m_BlueData[i+1][j-1];      blue[7] = m_BlueData[i+1][j];
           blue[8] = m_BlueData[i+1][j+1];

           qsort(red,   9, 1, Compare);
           qsort(green, 9, 1, Compare);
           qsort(blue,  9, 1, Compare);

           m_TempRedData[i][j]   = abs(red[0]);
           m_TempGreenData[i][j] = abs(green[0]);
           m_TempBlueData[i][j]  = abs(blue[0]);
       }
   }

   RGBColor* lpColor;

   for (int i=0; i<m_Height; ++i)
   {
       lpColor = (RGBColor*)m_pBitmap->ScanLine[i];

       for (int j=0; j<m_Width; ++j)
       {
           (lpColor+j)->Red   = m_TempRedData[i][j];
           (lpColor+j)->Green = m_TempGreenData[i][j];
           (lpColor+j)->Blue  = m_TempBlueData[i][j];
       }
   }

   Image1->Canvas->Draw(0, 0, m_pBitmap);

   Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------

