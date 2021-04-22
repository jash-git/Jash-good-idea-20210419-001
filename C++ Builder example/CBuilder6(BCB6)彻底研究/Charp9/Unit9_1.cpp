//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_1.h"
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

void TForm1::EnterModifyMode()
{
  BitBtn1->Enabled=False;
  BitBtn2->Enabled=False;
  BitBtn3->Enabled=False;
  BitBtn4->Enabled=False;
  BitBtn5->Enabled=False;
  BitBtn6->Enabled=False;
  BitBtn7->Enabled=False;
  BitBtn8->Enabled=True;
  BitBtn9->Enabled=True;
}

//---------------------------------------------------------------------------

void TForm1::LeaveModifyMode()
{
  BitBtn1->Enabled=True;
  BitBtn2->Enabled=True;
  BitBtn3->Enabled=True;
  BitBtn4->Enabled=True;
  BitBtn5->Enabled=True;
  BitBtn6->Enabled=True;
  BitBtn7->Enabled=True;
  BitBtn8->Enabled=False;
  BitBtn9->Enabled=False;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  Table1->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  Table1->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  Table1->Next();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
  Table1->Last();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
  Table1->Insert();
  EnterModifyMode();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
  Table1->Edit();
  EnterModifyMode();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
  if (MessageDlg("È·¶¨É¾³ý£¿",mtConfirmation, (TMsgDlgButtons() << mbYes << mbNo), 0)==mrYes)
      Table1->Delete();
  Panel1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
  Table1->Post();
  LeaveModifyMode();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
  Table1->Cancel();
  LeaveModifyMode();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Table1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  Table1->Close();
}
//---------------------------------------------------------------------------
