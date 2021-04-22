//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit6_7.h"
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
  TMemoryStream *TempStream=new TMemoryStream();

  // write list box contents to the stream
  ListBox1->Items->SaveToStream(TempStream);

  // reset to the beginning of the stream
  TempStream->Position=0;

  // load stream contents into memo
  Memo1->Lines->LoadFromStream(TempStream);

  delete(TempStream);
}
//---------------------------------------------------------------------------
 