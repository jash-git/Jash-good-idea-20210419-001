//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_11.h"
#include "Unit5_12.h"
#include "Unit5_13.h"
#include "Unit5_14.h"
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

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  Form2->Show();
  Label1->Caption=Form2->Edit1->Text;
  Label2->Caption=Form2->Edit2->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  Form3->Show();
  Label3->Caption=Form3->DirectoryListBox1->Directory;
  Label4->Caption=Form3->Edit1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  Form4->ShowModal();
}
//---------------------------------------------------------------------------
