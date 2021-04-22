//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit10_31.h"
#include "Unit10_32.h"
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
   DM->Query1->ApplyUpdates();
   DM->Query1->CommitUpdates();
   ShowMessage("Update жие\ !!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
   FormCreate(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
   DM->Query1->CancelUpdates();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
   DM->Database1->Connected=true;
   DM->Query1->Close();
   DM->Query1->CachedUpdates=true;
   DM->Query1->RequestLive=true;
   DM->Query1->Open();
}
//---------------------------------------------------------------------------
