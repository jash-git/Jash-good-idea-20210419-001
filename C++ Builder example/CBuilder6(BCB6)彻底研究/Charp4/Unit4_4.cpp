//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4_4.h"
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
void __fastcall TForm1::NewFileExecute(TObject *Sender)
{
     RichEdit1->Lines->Clear();
     Form1->Caption="Noname.txt";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OldFileExecute(TObject *Sender)
{
     if (OpenDialog1->Execute()==True) {
           try
           {
              RichEdit1->Lines->LoadFromFile(OpenDialog1->FileName);
              Form1->Caption=OpenDialog1->FileName;
           }
           catch (Exception &exception)
           {
              ShowMessage("找不到指定的檔案，"+OpenDialog1->FileName+"!!");
           }
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveFileExecute(TObject *Sender)
{
    RichEdit1->Lines->SaveToFile(Form1->Caption);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SaveAsFileExecute(TObject *Sender)
{
     if (SaveDialog1->Execute()==True) {
           try
           {
              RichEdit1->Lines->SaveToFile(SaveDialog1->FileName);
           }
           catch (Exception &exception)
           {
              ShowMessage("存檔有問題，"+SaveDialog1->FileName+"!!");
           }
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrinterSetupExecute(TObject *Sender)
{
    PrinterSetupDialog1->Execute();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrintExecute(TObject *Sender)
{
     if (PrintDialog1->Execute()==True)
        RichEdit1->Print(Form1->Caption);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ExitExecute(TObject *Sender)
{
    Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CutExecute(TObject *Sender)
{
    RichEdit1->CutToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CopyExecute(TObject *Sender)
{
    RichEdit1->CopyToClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PasteExecute(TObject *Sender)
{
    RichEdit1->PasteFromClipboard();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DeleteExecute(TObject *Sender)
{
    RichEdit1->ClearSelection();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FindExecute(TObject *Sender)
{
    FindDialog1->Execute();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NextExecute(TObject *Sender)
{
    FindDialog1->Execute();        
}
//---------------------------------------------------------------------------
