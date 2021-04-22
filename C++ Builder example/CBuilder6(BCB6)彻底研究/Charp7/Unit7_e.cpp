//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit7_e.h"
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
     if (RadioButton1->Checked)
     	OpenDialog1->Filter="Voice files (*.wav)|*.wav";
     if (RadioButton2->Checked)
     	OpenDialog1->Filter="Midi files (*.mid)|*.mid";
     if (RadioButton3->Checked)
     	OpenDialog1->Filter="AVI files (*.avi)|*.avi";
     if (!OpenDialog1->Execute()) Abort();

     Panel2->Caption=Panel2->Caption+OpenDialog1->FileName;

     MediaPlayer1->Display=Panel3;


     MediaPlayer1->FileName=OpenDialog1->FileName;


     MediaPlayer1->Open();
     ProgressBar1->Position=MediaPlayer1->StartPos;
     ProgressBar1->Min=MediaPlayer1->StartPos;
     ProgressBar1->Max=MediaPlayer1->TrackLength[1];


     Timer1->Enabled=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    ProgressBar1->Position=MediaPlayer1->Position;
}
//---------------------------------------------------------------------------
