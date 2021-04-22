//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6_4.h"
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  int i,j;

  
  for(i=0; i<=100; i++, ProgressBar1->Position++)
    for(j=0; j<30000; j++);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::HeaderControl1DrawSection(THeaderControl *HeaderControl,
	THeaderSection *Section, const TRect &Rect, bool Pressed)
{
  Graphics::TPicture *pic;

  
  pic=new Graphics::TPicture;

  
  pic->Icon->LoadFromFile("Chemical.ico");

  
  HeaderControl1->Canvas->Draw(Rect.Left,Rect.Top,pic->Icon);
  HeaderControl1->Canvas->TextOut(Rect.Left+pic->Icon->Width+2,Rect.Top,"Test");

  
  delete pic;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::HeaderControl1SectionTrack(
      THeaderControl *HeaderControl, THeaderSection *Section,
      int Width, TSectionTrackState State)
{
  Section->Width = Width;
  Shape1->Width = HeaderControl->Sections->Items[0]->Width;
  Shape2->Width = HeaderControl->Sections->Items[1]->Width;
  Shape2->Left = HeaderControl->Sections->Items[1]->Left;
  Button1->Width = HeaderControl->Sections->Items[1]->Width;
  Button1->Left = HeaderControl->Sections->Items[1]->Left;
  Shape3->Width = HeaderControl->Sections->Items[2]->Width;
  Shape3->Left = HeaderControl->Sections->Items[2]->Left;
  StatusBar1->Panels->Items[0]->Width=Shape1->Width;
  StatusBar1->Panels->Items[1]->Width=Shape2->Width;
  StatusBar1->Panels->Items[2]->Width=Shape3->Width;
}
//---------------------------------------------------------------------
void __fastcall TForm1::StatusBar1DrawPanel(TStatusBar *StatusBar,
	TStatusPanel *Panel, const TRect &Rect)
{
  
  ProgressBar1->Parent=StatusBar1;

  
  ProgressBar1->Left=Rect.Left;
  ProgressBar1->Top=Rect.Top;
  ProgressBar1->Width=Panel->Width;
  ProgressBar1->Height=Rect.Bottom-Rect.Top;

  
  ProgressBar1->Visible=True;
}
//-------------------------------------------------------------------------
