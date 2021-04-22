//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_51.h"
#include "Unit5_52.h"
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

void __fastcall TForm1::E2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
// 此函數是用來搜尋相同的字串
void __fastcall TForm1::FindDialog1Find(TObject *Sender)
{
  int FoundAt, StartPos, ToEnd;

  if (RichEdit1->SelLength)
    StartPos = RichEdit1->SelStart + RichEdit1->SelLength;
  else
  StartPos = 0;

  ToEnd = RichEdit1->Text.Length() - StartPos;

  FoundAt = RichEdit1->FindText(FindDialog1->FindText, StartPos, ToEnd, TSearchTypes()<< stMatchCase);

  if (FoundAt != -1)
  {
    RichEdit1->SetFocus();
    RichEdit1->SelStart = FoundAt;
    RichEdit1->SelLength = FindDialog1->FindText.Length();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
  PrinterSetupDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
  if (ColorDialog1->Execute()==true)
 	RichEdit1->Font->Color=ColorDialog1->Color;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::O2Click(TObject *Sender)
{
  if (OpenDialog1->Execute()==true)
	RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::P1Click(TObject *Sender)
{
  if ( PrintDialog1->Execute()==true )
	RichEdit1->Print( "Test" );
}
//---------------------------------------------------------------------------
void __fastcall TForm1::R1Click(TObject *Sender)
{
  ReplaceDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::S1Click(TObject *Sender)
{
  FindDialog1->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::S2Click(TObject *Sender)
{
  if (SaveDialog1->Execute()==true)
	RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::U1Click(TObject *Sender)
{
  if (FontDialog1->Execute()==true)
	RichEdit1->Font=FontDialog1->Font;
}
//-------------------------------------------------------------------------


void __fastcall TForm1::ReplaceDialog1Replace(TObject *Sender)
{
  TReplaceDialog *dlg = (TReplaceDialog *)Sender;
  int SelPos = RichEdit1->Lines->Text.Pos(dlg->FindText);
 
  if (SelPos > 0)
  {
    RichEdit1->SelStart = SelPos - 1;
    RichEdit1->SelLength = dlg->FindText.Length();
    RichEdit1->SelText = dlg->ReplaceText;
  }
  else
    MessageBeep(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
  Form2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::U2Click(TObject *Sender)
{
  RichEdit1->CutToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::P2Click(TObject *Sender)
{
  RichEdit1->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::P3Click(TObject *Sender)
{
  RichEdit1->PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::L1Click(TObject *Sender)
{
  RichEdit1->ClearSelection();
}
//---------------------------------------------------------------------------
