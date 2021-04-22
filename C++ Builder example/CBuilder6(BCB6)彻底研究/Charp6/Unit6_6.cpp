//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6_6.h"
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
  if (OpenDialog1->Execute()) Edit1->Text=OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  if (OpenDialog1->Execute()) Edit2->Text=OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  AnsiString Msg;

  Msg = Format("Copy %s to %s", ARRAYOFCONST((Edit1->Text,Edit2->Text)));
  TFileStream *OldFile = new TFileStream(Edit1->Text, fmOpenRead);
  try
  {
    TFileStream *NewFile = new TFileStream(Edit2->Text, fmCreate);

    try
    {
      NewFile->CopyFrom(OldFile, OldFile->Size);
      ShowMessage("¸´ÖÆ³É¹¦£¡");
    } __finally {
      FreeAndNil(NewFile);
    }
  } __finally {
    FreeAndNil(OldFile);
  }
}
//---------------------------------------------------------------------------
 

