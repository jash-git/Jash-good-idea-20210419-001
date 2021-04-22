//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6_8.h"
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
  AnsiString as;
  TMemoryStream* pms = new TMemoryStream();
  TStringStream* pss = new TStringStream(as);
  TComponent *c;

  if (Sender==Button1) c=dynamic_cast<TComponent *>(Button1);
  if (Sender==Button2) c=dynamic_cast<TComponent *>(Memo1);
  if (Sender==Button3) c=dynamic_cast<TComponent *>(Form1);
  if (Sender==Button4) c=dynamic_cast<TComponent *>(OpenDialog1);

  try
  {
    pms->WriteComponent(c);
    pms->Seek(0, soFromBeginning);
    ObjectBinaryToText(pms, pss);
    pss->Seek(0, soFromBeginning);
    as = pss->DataString;
  }
  catch(...)
  {
    ShowMessage("Streaming error.");
  }
  delete pms;
  delete pss;
  Memo1->Lines->Text=as;
}
//---------------------------------------------------------------------------
